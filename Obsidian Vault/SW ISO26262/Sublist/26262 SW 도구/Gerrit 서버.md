1. Gerrit 공식 가이드 : https://gerrit-documentation.storage.googleapis.com/Documentation/3.12.2/index.html
2. Linux 설치(https://gerrit-documentation.storage.googleapis.com/Documentation/3.5.1/linux-quickstart.html)
	1. Gerrit 서버 설치 : https://silzzang.tistory.com/entry/Gerrit-%EC%84%A4%EC%B9%98
	2. Gerrit을 이용한 코드 리뷰 시스템 : https://d2.naver.com/helloworld/6236097
3. window 설치
	1. Gerrit을 윈도우에 설치하려면 Java 8 이상과 Git을 먼저 설치한 후, Gerrit 공식 웹사이트에서 Gerrit WAR 파일을 다운로드 받아, 커맨드 창에서 `java -jar gerrit.war init -d <설치 디렉토리>` 명령어로 초기 설정을 진행합니다.
		1. JAVA설치 : JDK 21 -**Adoptium Temurin JDK 21**: **완전히 무료 (오픈소스, 상업용 포함)**
			1. https://adoptium.net/temurin/releases/?version=21
	2. 사전 준비
		1.  **Java 설치**: Gerrit를 실행하기 위해 Java Development Kit (JDK)을 설치합니다.
		2. **Git 설치**: Git을 설치합니다. [Git 웹사이트](https://git-scm.com/downloads)에서 Windows 버전을 다운로드하여 설치할 수 있습니다.
	3. Gerrit 설치 절차
		1. **Gerrit WAR 파일 다운로드**:  Gerrit 공식 릴리스 페이지에 접속하여 설치할 Gerrit 버전에 해당하는 `.war` 파일을 다운로드합니다.
		2. **설치 디렉토리 설정**: Gerrit를 설치할 디렉토리를 하나 지정합니다 (예: `C:\gerrit`).
	    3. **초기 설정**: 다운로드 받은 WAR 파일이 있는 폴더로 커맨드 창(CMD)에서 이동한 뒤, 다음과 같은 명령어를 실행합니다.
	    4.  java -jar gerrit.war init -d <설치 디렉토리 경로>
		    1. - `<설치 디렉토리 경로>`에는 위에서 지정한 디렉토리 경로를 입력합니다. 예를 들어 `java -jar gerrit.war init -d C:\gerrit`과 같이 입력할 수 있습니다.
		5. **설정 확인**: 명령을 실행하면 Gerrit 데이터베이스를 설정하고 초기화하는 과정이 진행됩니다. H2 데이터베이스는 임베디드 데이터베이스로, 대부분의 배포에 적합합니다.
		6. **실행**: 설치가 완료되면, 지정한 설치 디렉토리 내에서 Gerrit를 실행하여 코드 리뷰 시스템을 사용할 수 있습니다.
	4. 참고 : 
		- 이 절차는 [Standalone Daemon Installation](https://www.google.com/search?sca_esv=b9a65900b830afa2&rlz=1C1GCEU_koKR904KR905&cs=0&q=Standalone+Daemon+Installation&sa=X&ved=2ahUKEwjUvMHP1vKPAxVGZ_UHHckSJeQQxccNegQIQhAB&mstk=AUtExfCVposSWsyP-Y53MMfg_QMub4AAngBKbHyiDg91ZgmYeYNRVVnNo66t_9yrJosN_ewYxJF_aoxNjZFa81WdCgW4bzxPO4W-A4m7iQ70Jx_SsdGlywA610vd41iSpFZYbjY&csui=3) 방식으로, Gerrit를 독립 실행형 데몬으로 설치하는 정식 방법입니다.
		- Gerrit은 Git 서버 기능과 코드 리뷰 기능을 함께 제공합니다.
	5. 
		1. 
		2. 