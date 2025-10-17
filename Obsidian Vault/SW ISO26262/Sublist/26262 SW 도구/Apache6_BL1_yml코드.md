`stages:`

  - `analyze`

  

`qac_analysis:`

  `stage: analyze`

  `tags:`

    `- qac_gitlab_cidi`

  `rules:`

    `- if: '$CI_PIPELINE_SOURCE == "merge_request_event"'`

  `variables:`

    `QACLI_EXE: "C:/Perforce/Helix-QAC-2019.1/common/bin/qacli.exe"`

  

  `script:`

    `- 'Write-Host "현재 경로 = $pwd"'`

    `- 'Write-Host "QAC 실행 파일 = $env:QACLI_EXE"'`

  

    `# QAC 프로젝트 확인`

    `- '$ProjectXml = Join-Path $pwd "prqaproject.xml"'`

    `- 'if (!(Test-Path $ProjectXml)) { Write-Error "prqaproject.xml을 찾을 수 없습니다: $ProjectXml"; exit 2 }'`

    `- 'Write-Host "QAC 프로젝트 파일 = $ProjectXml"'`

  

    `# PROJECT_ROOT 환경변수`

    `- '$env:PROJECT_ROOT = $pwd'`

    `- 'Write-Host "PROJECT_ROOT = $env:PROJECT_ROOT"'`

  

    `# 리포트 폴더 생성`

    `- '$RULE_REPORT_DIR    = Join-Path $pwd ("QAC_Reports\" + $env:CI_COMMIT_SHORT_SHA + "\Coding_Rules")'`

    `- '$METRICS_REPORT_DIR = Join-Path $pwd ("QAC_Reports\" + $env:CI_COMMIT_SHORT_SHA + "\Coding_metrics")'`

    `- 'mkdir $RULE_REPORT_DIR -Force    | Out-Null'`

    `- 'mkdir $METRICS_REPORT_DIR -Force | Out-Null'`

  

    `# 라이선스 서버 지정`

    `- '& $env:QACLI_EXE admin --set-license-server 5055@192.168.20.90'`

  

    `# QAC Analyze 실행`

    `- '& $env:QACLI_EXE analyze -cfs -P $pwd -T'`

    `- '$ret = $LASTEXITCODE'`

    `- 'if ($ret -ne 0) { Write-Error "QAC Analyze failed with code $ret"; exit $ret }'`

  

    `# 리포트 생성`

    `- '& $env:QACLI_EXE report -t CRR -P $pwd -o $RULE_REPORT_DIR'`

    `- '& $env:QACLI_EXE report -t MDR -P $pwd -o $RULE_REPORT_DIR'`

    `- '& $env:QACLI_EXE report -t RCR -P $pwd -o $RULE_REPORT_DIR'`

    `- '& $env:QACLI_EXE report -t SUR -P $pwd -o $RULE_REPORT_DIR'`

    `- '& $env:QACLI_EXE report -t HMR -P $pwd -o $METRICS_REPORT_DIR'`

    `- '& $env:QACLI_EXE report -t EMR -P $pwd -o $METRICS_REPORT_DIR'`

  

    `# results_data.xml 찾기`

    `- '$xmlFile = (Get-ChildItem $RULE_REPORT_DIR -Filter "results_data*.xml" | Select-Object -First 1).FullName'`

    `- 'if (-not $xmlFile) { Write-Error "results_data.xml 파일을 찾을 수 없습니다"; exit 2 }'`

    `- 'Write-Host "선택된 XML 파일 = $xmlFile"'`

  

    `# 파이썬 파서 실행`

    `- 'python parse_qac_reports.py "$xmlFile" "$pwd/warnings_qac.csv"'`

  

  `artifacts:`

    `when: always`

    `paths:`

      `- QAC_Reports/`

      `- warnings_qac.csv`

    `expire_in: 1 week`

  
  

`codesonar-analyze:`

  `stage: analyze`

  `tags:`

    `- CodeSonarWindows`

  `rules:`

    `- if: '$CI_PIPELINE_SOURCE == "merge_request_event"'`

  `variables:`

    `CODESONAR_EXE: "C:/Program Files/CodeSecure/CodeSonar/codesonar/bin/codesonar.exe"`

    `CSPYTHON: "C:/Program Files/CodeSecure/CodeSonar/codesonar/bin/cspython.exe"`

    `SARIF2SAST: "C:/Program Files/CodeSonarTools/codesonar-gitlab-integration/distro-image/codesonar-sarif2sast"`

    `CODESONAR_PROJECT_NAME: "GitLabCI"`

    `CODESONAR_HUBUSER: "codesonar1"`

    `CODESONAR_HUBPWFILE: "pw.txt"`

    `CODESONAR_HUB_URL: "http://192.168.20.94:7340"`

    `CODESONAR_WARNING_THRESHOLD: 50`

    `CODESONAR_MAX_WARNINGS: 9`

    `CODESONAR_VISIBILITY_FILTER: "all"`

  

  `script:`

    `# 1. CodeSonar 분석 실행`

    `- '& "$env:CODESONAR_EXE" analyze $env:CODESONAR_PROJECT_NAME ``

        `-clean -foreground ``

        `-preset 02_CS9.0_NextChip_ver2 ``

        `-auth password -hubuser $env:CODESONAR_HUBUSER -hubpwfile $env:CODESONAR_HUBPWFILE ``

        `$env:CODESONAR_HUB_URL ``

        `make -C src'`

  

    `# 2. 분석 ID 추출`

    `- '$CODESONAR_ANALYSIS_ID = & "$env:CSPYTHON" "$env:SARIF2SAST/analysis_id.py" "$env:CODESONAR_PROJECT_NAME"'`

  

    `# 3. SARIF 파일 생성`

    `- '& "$env:CODESONAR_EXE" get ``

        `-auth password -hubuser $env:CODESONAR_HUBUSER -hubpwfile $env:CODESONAR_HUBPWFILE ``

        `-o ./allwarnings.sarif ``

        `"$env:CODESONAR_HUB_URL/analysis/$CODESONAR_ANALYSIS_ID-allwarnings.sarif?filter=%22$env:CODESONAR_VISIBILITY_FILTER%22"'`

  

    `# 4. SARIF → GitLab SAST 변환`

    `- '& "$env:CSPYTHON" "$env:SARIF2SAST/sarif2sast.py" ``

        `--sarif ./allwarnings.sarif ``

        `--output ./gl-sast-report.json ``

        `--summary-report ./sast-summary-report.md ``

        `--codesonar-url "$env:CODESONAR_HUB_URL" ``

        `--analysis-id $CODESONAR_ANALYSIS_ID ``

        `--max $env:CODESONAR_MAX_WARNINGS ``

        `--threshold $env:CODESONAR_WARNING_THRESHOLD'`

  

    `# 5. SARIF → CSV 변환 (루트에 있는 parse_codesonar_reports.py 실행)`

    `- 'python parse_codesonar_reports.py allwarnings.sarif "$pwd/warnings_codesonar.csv"'`

  

  `artifacts:`

    `when: always`

    `paths:`

      `- GitLabCI.prj_files/`

      `- allwarnings.sarif`

      `- sast-summary-report.md`

      `- gl-sast-report.json`

      `- warnings_codesonar.csv`

    `expire_in: 1 week`

    `reports:`

      `sast: gl-sast-report.json`