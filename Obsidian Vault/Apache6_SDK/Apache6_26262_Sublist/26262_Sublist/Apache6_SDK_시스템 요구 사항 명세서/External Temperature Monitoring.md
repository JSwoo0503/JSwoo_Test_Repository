
| **SM ID**          | SM-28                               |
| ------------------ | ----------------------------------- |
| **구현 파트**          | HW                                  |
| **Failure Mode**   | 온도 오류                               |
| **D.C(%)**         | 99(High)                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.10 Actuator |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                  |
### 1. 상세 구현 방안(Implementation approach in detail)
HOST ECU 는 APACHE6가 장착된 Board의 온도를 모니터링 하여 온도 오류를 검출해야 한다. 온도가 APACHE6의 Ambient 온도 설계 범위(-40˚C ~ 105˚C)를 벗어나면 temperature error 를 SE에 전달한다.
![[SM-28 External Temperature Monitoring.png]]