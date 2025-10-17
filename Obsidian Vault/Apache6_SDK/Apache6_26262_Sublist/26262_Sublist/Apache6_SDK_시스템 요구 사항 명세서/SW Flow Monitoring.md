
| **SM ID**          | SM-20                                             |
| ------------------ | ------------------------------------------------- |
| **구현 파트**          | SW                                                |
| **Failure Mode**   | Wrong Execution                                   |
| **D.C(%)**         | 90(Medium)                                        |
| **D.C** **산출의 근거** | ISO26262-5, Table D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 SW의 동작 순서에 대한 모니터링이 필요한 중요 TASK 또는 Function에 대해 Program Flow Monitor를 적용할 수 있다. APACHE6는 각 TASK 또는 Function에서 수행되는 순서에 따라 Program Step에 따른 Status값을 갱신 하고, 최종적으로 그 결과를 확인하여 중간에 누락된 단계가 있는지 Golden Data와 비교하여 오류가 발생하면 fault 신호를 SE에 전달해야 한다.
![[SM-20 SW Flow Monitoring.png]]