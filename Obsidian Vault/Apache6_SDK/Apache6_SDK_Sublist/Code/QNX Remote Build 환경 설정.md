APACHE6 QNX REMOTE build Server 구성이 완료되어 설정과 사용방법을 전달해드립니다.

연결되는 계정은 관리자 계정이 아닌 일반 계정입니다. sudo 권한이 없는 부분 참고 부탁드립니다.

1. ssh key 등록.(최초 1회)

 > ssh-copy-id -i /home/**xxxxxx**/.ssh/id_rsa.pub qnxwizard@192.168.13.99

  xxxx: 사용하는 user명 확인

  pw : nextchip

2. .remote_server_info.env 파일 수정

QNX_REMOTE_USER_HOST="qnxwizard@192.168.13.99"  
QNX_REMOTE_LOCATION_PATH="/home/qnxwizard/nc_qnx/"  
QNX_REMOTE_ENV_INIT="/home/qnxwizard/qnx800/qnxsdp-env.sh"

3. build 확인.

 ./nc_remote_build.sh