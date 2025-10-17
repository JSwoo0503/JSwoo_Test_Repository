
| **SM ID**        | SM-41                                             |
| ---------------- | ------------------------------------------------- |
| **구현 파트**        | SW                                                |
| **Failure Mode** | Wrong Execution                                   |
| **D.C(%)**       | 90(Medium)                                        |
| **D.C 산출의 근거**   | ISO26262-5, Table D.8 Program Sequence Monitoring |
| **S.M Type**     | 단일점 결함을 막는 안전 메커니즘                                |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 주요 Task에 대해서특정 주기로 정해진 동작을 수행하게 된다. Safety Service 등과 같이 주기적으로 중요 동작을 수행하는 TASK는 정확한 Timing에 TASK가 동작해야 한다. TASK Timing Monitor는 TASK가 이전 시작 시점에서부터 정해진 시간 이후에 다시 동작 하지 못하는 오류를 검출한다.