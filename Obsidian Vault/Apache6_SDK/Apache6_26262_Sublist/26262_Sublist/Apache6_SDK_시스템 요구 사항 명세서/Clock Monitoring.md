
| **SM ID**          | SM-14                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | HW / SW                                               |
| **Failure Mode**   | Clock 주파수 오류                                          |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
CPU의 SYS SW가 PLL Clock, 내부 Clock을 설정한다. Safety SW는 설정된 PLL Clock, 내부 Clock을 모니터링하기 위해 Clock monitor를 설정 후 Clock monitor를 enable한다. Clock monitor는 설정된 clock 주파수를 모니터링하고 의도하지 않는 주파수가 검출되면 fault 신호를 SE에게 전달한다.
![[SM-14 Clock Monitoring.png]]