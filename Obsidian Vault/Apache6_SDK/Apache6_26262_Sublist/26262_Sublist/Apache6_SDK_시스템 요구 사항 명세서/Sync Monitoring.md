
| **SM ID**          | SM-01                                          |
| ------------------ | ---------------------------------------------- |
| **구현 파트**          | HW / SW                                        |
| **Failure Mode**   | Video Sync 오류                                  |
| **D.C(%)**         | 99(High)                                       |
| **D.C** **산출의 근거** | ISO26262-5, Table D.5 Analogue and digital I/O |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                             |
### 1.상세 구현 방안(Implementation approach in detail)

APACHE6 시스템은 주기적으로 입력되는 영상을 처리하는 HW의 정상 동작을 보장하기 위해, 해당 HW에 입력되는 혹은 출력되는 Video Sync의 무결성을 확인한다. Video Sync의 주기, 발생 유무 등이 미리 설정한 값과 다르다면 Video Sync 오류를 SE에 전달한다.
![[SM-01 Sync Monitoring.png]]