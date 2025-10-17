
| **SM ID**          | SM-16                                                                           |
| ------------------ | ------------------------------------------------------------------------------- |
| **구현 파트**          | HW                                                                              |
| **Failure Mode**   | Timer 동작 지연 오류                                                                  |
| **D.C(%)**         | 99(High)                                                                        |
| **D.C** **산출의 근거** | ISO26262-11, 5-1 Digital components and memories Table 35 On-chip communication |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                                              |
### 1. 상세 구현 방안(Implementation approach in detail)
Timer 카운터는 1-cycle 차이의 Redundancy 카운터를 비교하여 Timer 오류를 검출한다. 만약 Timer의 증가/감소 할 때 Timer는 Redundancy 카운터값과 1-Cycle 차이가 나지 않으면 오류를 출력한다.

![[SM-16 Timer 이중화 설계.png]]