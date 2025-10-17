
| **SM ID**          | SM-18                                   |
| ------------------ | --------------------------------------- |
| **구현 파트**          | SW                                      |
| **Failure Mode**   | 내부 로직 고장                                |
| **D.C(%)**         | 90(Medium)                              |
| **D.C** **산출의 근거** | ISO26262-5, Table D.6 Communication bus |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                      |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 Redundant Timer를 이용하여 인터럽트를 발생시켜 설정된 주기로 인터럽트가 발생하는지 확인하고, 오류 발생시 fault 신호를 SE에 전달해야 한다. 해당 테스트는 normal operation mode 동작에는 영향을 주지 않아야 한다.
![[SM-18 Interrupt Monitor.png]]