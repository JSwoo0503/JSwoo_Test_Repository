
| **SM ID**          | SM-26                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | HW                                                    |
| **Failure Mode**   | Wrong Execution                                       |
| **D.C(%)**         | 99(High)                                              |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
System Reset입력이 release되면 Reset controller는 SAFETY_RESET, RESET_G0, RESET_G1, RESET_G2를 순차적으로 release한다. Reset Monitor는 RESET_G0, RESET_G1, RESET_G2의 release 순서를 확인하고 의도되지 않는 순서가 감지되면 fault 신호를 SE에 전달한다.
![[SM-26 Reset Sequence Monitoring.png]]