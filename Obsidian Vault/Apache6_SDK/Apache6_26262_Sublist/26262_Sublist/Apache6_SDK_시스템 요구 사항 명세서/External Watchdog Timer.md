
| **SM ID**          | SM-24                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | HW/SW/External                                        |
| **Failure Mode**   | 주파수 오류 검출                                             |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 상위 시스템 레벨에서 정의된 주기로 신호를 출력하고 외부 HOST ECU는 신호의 오류를 감지할 수 있어야 한다.
![[SM-24 External Watchdog Timer.png]]