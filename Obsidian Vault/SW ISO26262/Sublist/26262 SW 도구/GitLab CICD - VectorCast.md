# 1) cli로 Vectorcast Execute 시킬 때
1. tst 파일 안에 있는 각각의 test 케이스마다 따로 실행시켜줘야 한다.
2. 환경 파일(.vce) 안에 uut(Vectorcast 수행할 파일)은 하나의 파일만 기입되므로 파일마다 만들어 줘야 한다.
3. 2번 내용에 이어서 .vce 파일이 분석하려는 파일마다 만들어지기 때문에 tst 파일로 파일마다 만들어 줘야 한다. window Vectorcas처럼 하나의 tst에 여러 파일 내용을 넣으려면 tst 파일을 parsing 해서 파일별로 tst를 나누는 코드가 필요하다(py로 만들어서  parsing을 수행하는 것이 편해 보임)
# 2) Vectorcast cli 사용을 위해 설정
1. *.vce 파일 -> 파일 별로 반들어야함.
	1. ENVIRO.NAME
	2. ENVIRO.UUT
	3. ENVIRO.STUB_BY_FUNCTION 를 수정해야함.
	4. ENVIRO.LIBRARY_STUBS: 가 있어야 같은 파일에 있는 함수의 stub이 가능해짐. (원칙적으로 같은 파일안에 있는 함수는 stub가 안됨. stub 처리해서 return 받으려면 함수를 외부로 빼야함.)

2. *.tst 파일을 파일마다 각각 만들어야 함.
3. CCAST_User.CFG 파일에 'VCAST_TI_IGNORE_QUALIFIERS: TRUE' 커맨드가 있어야 volatile DRV_UART_REGISTER* const 가 인식됨
4.  extends:를 사용할 때 jobs의 앞에 "." 을 붙여 줘야 한다. 안 그러면 각각의 jobs로 인식이 된다.
	1. unit-drv-uart:
		 extends: .vectorcast-unittest
	2. .vectorcast-unittest:
	3. 이렇게 있을 때 "." 이 빠지면 unit-drv-uart 와 vectorcast-unittest 가 병렬로 수행된다.
	4. "." 이 있으면 jobs에 unit-drv-uart 로 수행된다.
# 3) 하나의 파일에 여러 `.tst`를 병렬로 돌릴 때 (matrix에 유닛도 같이 주입)
여러 테스트 세트를 **한 job 이름으로 유지**하면서 병렬 실행한다면, 각 행마다 다른 유닛명을 넘겨줄 수도 있어:

unit-drv-uart:
  stage: Unit_Test
  parallel:
    matrix:
      - TST: "Test_Verification/TST/APACHE6_BL1_UNIT_UART.tst"
        VCAST_DEFAULT_UNIT: "Drv_Uart"
      - TST: "Test_Verification/TST/PUTCHAR_ONLY.tst"
        VCAST_DEFAULT_UNIT: "Drv_Uart"
      - TST: "Test_Verification/TST/GETLINESTAT_ONLY.tst"
        VCAST_DEFAULT_UNIT: "nc_uart"   # 예: 다른 유닛
  variables:
    CLICAST: "C:/VCAST/clicast.exe"
    VCAST_ENV: "APACHE6_BL1_UNIT_UART"

# 4) yml 파일에 tst 추가
1. 맨아래에 jobs 추가.
unit-drv-uart:  -> jobs명 수정
  extends: .vectorcast-unittest -> Vectorcast가 수행되는 jobs명 기입
  variables:
    VCAST_ENV: "APACHE6_BL1_UNIT_UART" -> .vce 파일의 ENVIRO.NAME 와 동일하게 수정
    VCAST_ENVBUILD: "Test/Test_Verification/ENV_DRV_UART.vce" -> 경로와 파일명 수정
    VCAST_TST: "Test/Test_Verification/TST/APACHE6_BL1_UNIT_UART.tst" -> 경로와 파일명 수정
    VCAST_DEFAULT_UNIT: "Drv_Uart"   # ← 여기서 기본 유닛명 주입

# 5) CFG 파일 내용을 GitLab Jobs에 출력
# ── 복사 후 검증·보강 블록 ──
     - |
       $cfgPath = "CCAST_.CFG"
       if (!(Test-Path $cfgPath)) { Write-Error "CCAST_.CFG not found"; exit 2 }

       $cfg = Get-Content -Raw $cfgPath
       # 멀티라인 검사로 해당 옵션이 이미 있는지 확인
       if ($cfg -notmatch '(?m)^\s*VCAST_TI_IGNORE_QUALIFIERS\s*:') {
         Add-Content -LiteralPath $cfgPath 'VCAST_TI_IGNORE_QUALIFIERS: TRUE'
         Write-Host "[CCAST] Added: VCAST_TI_IGNORE_QUALIFIERS: TRUE"
       } else {
         Write-Host "[CCAST] Option already present: VCAST_TI_IGNORE_QUALIFIERS"
       }

       Write-Host "----- tail CCAST_.CFG -----"
       Get-Content -Tail 20 $cfgPath | Write-Host

# 6) Merge Request에 다운로드 링크
1. post-report-links jobs에 Vectorcast가 수행된 파일 링크를 사용자가 만들어 줘야한다.
2. # 여러 .tst를 병렬(matrix)로 돌려 리포트가 여러 개인 경우

리포트 파일명이 각각 다르다면(예: `*_Report_Full.html`) **여러 링크를 나열**하면 돼요. 예시:

`REPORT_URL_VC_UART="$CI_PROJECT_URL/-/jobs/artifacts/$CI_COMMIT_REF_NAME/raw/Test/Test_Verification/APACHE6_BL1_UNIT_UART_Report_Full.html?job=unit-drv-uart"`
`REPORT_URL_VC_PUTCHAR="$CI_PROJECT_URL/-/jobs/artifacts/$CI_COMMIT_REF_NAME/raw/Test/Test_Verification/PUTCHAR_ONLY_Report_Full.html?job=unit-drv-uart"`
`REPORT_URL_VC_GETLINE="$CI_PROJECT_URL/-/jobs/artifacts/$CI_COMMIT_REF_NAME/raw/Test/Test_Verification/GETLINESTAT_ONLY_Report_Full.html?job=unit-drv-uart"`

`curl --header "PRIVATE-TOKEN: $ACCESS_TOKEN" \`
     `--data-urlencode "body=QAC Report: [Download HTML]($REPORT_URL_QAC)`
`CodeSonar Report: [Download HTML]($REPORT_URL_CS)`
`VectorCAST Reports:`
- `[UART]($REPORT_URL_VC_UART)`
- `[PutChar]($REPORT_URL_VC_PUTCHAR)`
- `[GetLineStat]($REPORT_URL_VC_GETLINE)" \`
     `"$CI_API_V4_URL/projects/$CI_PROJECT_ID/merge_requests/$CI_MERGE_REQUEST_IID/notes"`