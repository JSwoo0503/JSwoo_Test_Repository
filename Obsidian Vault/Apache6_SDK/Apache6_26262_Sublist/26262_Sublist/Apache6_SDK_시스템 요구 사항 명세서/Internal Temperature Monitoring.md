
| **SM ID**          | SM-23                               |
| ------------------ | ----------------------------------- |
| **구현 파트**          | HW                                  |
| **Failure Mode**   | 온도 오류                               |
| **D.C(%)**         | 99(High)                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.10 Actuator |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                  |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 Die 내 5개 이상의 분산된 위치에 대한 Junction 온도 모니터링 기능을 제공한다. Safety SW는 Safety manager task를 통해 66-ms 이내의 주기로 Temperature sensor 값을 읽는다. Safety manager는 APACHE6 설계 Junction 온도 범위(-40℃~125℃)를 벗어나면 temperature error 를 SE에 전달한다.
![[SM-23 Internal Temperature Monitoring.png]]