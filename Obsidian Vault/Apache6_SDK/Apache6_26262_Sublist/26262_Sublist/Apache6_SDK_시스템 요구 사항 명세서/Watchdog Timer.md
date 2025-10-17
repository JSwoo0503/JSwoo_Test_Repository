
| **SM ID**          | SM-15                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | HW / SW                                               |
| **Failure Mode**   | CPU 동작 지연 오류                                          |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 다중점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
CPU의 Safety SW는 Watchdog timer에 Watchdog Timer 초기값과 Update 구간값을 설정한다. Time Out 발생시 SE에 fault 신호를 출력한다.
![[SM-15 Watchdog Timer.png]]