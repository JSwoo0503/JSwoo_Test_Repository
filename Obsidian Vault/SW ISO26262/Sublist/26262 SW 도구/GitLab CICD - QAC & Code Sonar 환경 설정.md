### QAC, Codesonar, VectorCast의 실행 파일을 어디서든 실행하기 위해 환경 변수의 Path에 실행 파일 위치를 등록해야 한다.
1. GitLab Runner은 Window 용으로 설정한다.
2. GitLab Runner이 Powershell을 사용한다. pwsh를 사용하기 위해 Power Sherll 7버전을 설치한다.
	1. https://github.com/PowerShell/PowerShell/releases/tag/v7.5.3
	2. 
3. GitLab Runner 환경 구축(Ruunner를 GitLab에 연결)
	1. https://velog.io/@tlatjdgh3778/Gitlab-CI-%EA%B5%AC%EC%B6%95%EC%9D%84-%EC%9C%84%ED%95%9C-Gitlab-Runner-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0Windows
![[GitLab Runner_1.png]]
![[GitLab Runner_2.png]]
![[GitLab Runner_3.png]]
**Teg 이름에 필요한 만큼 써준다. 지금은 QAC와 CodeSonar 두 개를 등록함**
**yml 파일의 tags란에 등록한 Tag를 적어주면 된다**
![[GitLab Runner_4.png]]
![[GitLab Runner_5.png]]

![[GitLab Runner_7.png]]
![[GitLab Runner_8.png]]
파이선 스크립트 사용을 위해서 GitLab Runner 서버에 설치
![[GitLab Runner_9.png]]

**<C:\python\Lib\site-packages에 직접 모듈 복사 명령어>**
C:\python\python.exe -m pip install --target="C:\python\Lib\site-packages" typing_extensions --upgrade
![[GitLab Runner_10.png]]


![[GitLab Runner_6.png]]
14. 시스템 환경 변수에 pwsh의 경로가 있는지 확인한다. (시스템 변수의 Path에 편집으로 넣으면 된다. C:\Program Files\PowerShell\7\)
15. 윈도우 시작에서 서비스를 실행하여 gitlab-runner을 다시 시작하여 위에서 설정한 환경 변수가 적용되도록 한다.
16. ----- GitLabRunner가 pwsh를 사용하여 PowerShell을 켜고 .yml의 명령을 수행할 사 있다.
17. prqaproject.xml 파일에서 검사하려는 파일들의 path를 설정해야함. ([[Prqaproject.xml Include와 Define 설정 예제]])
18. prqa\configs\Initial\config\project.acf 파일에서 Include 파일들의 Path를 설정해 줘야함.
19. 코드소나의 Preset을 사용 하기.
![[CodeSonar Preset_1.png]]
![[CodeSonar Preset_2.png]]
20. .yml 파일에 명시를 하고 Code Sonar이 설치된 폴더의 presets 폴더에 .conf 파일을 넣는다.
21. Code Sonar의 결과는 Artifacts에서 codesonar-analyze를 다운로드 하여 warnings.csv에서 확인 가능.

### GitRunner Linux 설치 (Ubuntu 기준)
### (1) GitLab 공식 패키지 저장소 추가
curl -L https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh | sudo bash
### (2) GitLab Runner 설치
sudo apt-get install gitlab-runner -y
### (3) GitLab Runner 등록
sudo gitlab-runner register
- **GitLab URL**: 예) `https://gitlab.com/` 또는 사내 GitLab 서버 URL
- **Registration Token**: GitLab 프로젝트/그룹 > Settings > CI/CD > Runners > Registration token
- **Description**: Runner 이름 (ex. `linux-runner`)
- **Tags**: 원하는 태그 (ex. `linux`)
- **Executor**: `shell`, `docker`, `virtualbox`, `kubernetes` 등 중 선택
### (4) Runner 서비스 시작
sudo systemctl enable gitlab-runner
sudo systemctl start gitlab-runner

### .Runner 서비스 재시작
sudo systemctl restart gitlab-runner


23. **EULA 동의를 해야함(Linux code sonar)**
24. Llinux 에서 `Do you accept the terms of this license agreement? [y/n]` 라는 질문이 나옵니다 를 묻는다.
25. `codesonar activate` 를 서버에서 실행해서 `y` 입력하시고, 다시 CI 파이프라인 돌려보실래요?
26. cd /home/woojaesung/codesonar/codesonar-9.0p0/codesonar/bin
27. ./codesonar activate
28. You must accept the terms of this license agreement to install and use this product.  This agreement in part prohibits you from furnishing the program output to third parties.  The text of this agreement can be found at: /home/woojaesung/codesonar/codesonar-9.0p0/EULA.txt
	Do you accept the terms of this license agreement?
	[y/n] y
	Send anonymous usage statistics to CodeSecure?
	[y/n] y
	Activation complete
29. GitLab CICD Variable Setting 하면 특정 project만 실행 가능하게 할 수 있다.

30. **Linux와 Window는 Tag로만 나눠지는 듯**
31. rules: 조건은 파이프라인 생성 시점에 평가됨
$RUN_ENV 는 Runner 실행 시 주입되는 환경변수
하지만 GitLab은 파이프라인을 만들 때 .gitlab-ci.yml 의 rules 조건을 먼저 해석합니다.
이 시점에는 Runner가 아직 실행되지 않았으므로 $RUN_ENV 값이 비어 있음 → 조건 실패 → 잡이 전부 skip → 파이프라인이 "상태 없음" 으로 보임.
그래서 사실상 Runner 환경변수는 rules if 조건에서 쓸 수 없음 → GitLab 공식 문서에도 이 제약이 명시돼 있습니다.
**아래 방법 안됨 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 이유는 위에 **
![[GitLab Runner_11.png]]
![[GitLab Runner_12.png]]

### VactorCast CLI 사용.
1. clicast 명령어를 어디서든 사용하기 위해 시스템 환경 변수의 Path에 clicast.exe 폴더 위치 등록

### CLI로 MR에 댓글 남기기 위해 API 권한이 필요할때
1. ![[GitLab Runner_13.png]]  API로 Access Tokens을 발행한다. (보안을 위해 가급적 Expires at를 설정 할 것)
2. ![[GitLab Runner_14.png]] 발생한 Access Token을 Setting>CI/CD>Variables에 등록한다.
   Key = 토큰 이름, Value = 발급 받은 PAT 값


⚠️ 그래서 MR 시나리오에서 **소스 브랜치 이름**이 필요하다면,

- `CI_MERGE_REQUEST_SOURCE_BRANCH_NAME` 변수를 사용해야 합니다.
`- echo "Source branch: $CI_MERGE_REQUEST_SOURCE_BRANCH_NAME" - echo "Target branch: $CI_MERGE_REQUEST_TARGET_BRANCH_NAME"`

### Runner의 SSH 설정 (git push를 위한)
ssh-keyscan -p 22 gitlab.nextchip.com >> ~/.ssh/known_hosts
gitlab.nextchip.com:22 SSH-2.0-OpenSSH_7.4
gitlab.nextchip.com:22 SSH-2.0-OpenSSH_7.4
gitlab.nextchip.com:22 SSH-2.0-OpenSSH_7.4
gitlab.nextchip.com:22 SSH-2.0-OpenSSH_7.4
gitlab.nextchip.com:22 SSH-2.0-OpenSSH_7.4

- ssh 접속 테스트
ssh -T git@gitlab.nextchip.comgit@gitlab.nextchip.com's password: 


### GitLab 에 SSH 키 등록
GitLab -> Setting -> CI/CD -> Variables에 등록 (`SSH_PRIVATE_KEY`)
![[GitLab Runner_15.png]]
id_rsa.pub` 내용은 GitLab → 해당 프로젝트 → **Settings → Repository → Deploy Keys** 에 등록해야 합니다.
![[GitLab Runner_16.png]]


      - **CRR**: 코드 리뷰 보고서
      - **MDR**: 메트릭스 데이터 보고서
      - **RCR**: 규칙 준수 보고서
      - **SUR**: Suppressions 보고서
      - **HMR**: HIS 메트릭스 보고서
      - **EMR**: 엑셀 메트릭스 보고서