
| **SM ID**          | SM-31                                    |
| ------------------ | ---------------------------------------- |
| **구현 파트**          | HW                                       |
| **Failure Mode**   | Address/Data 오류                          |
| **D.C(%)**         | 90(Medium)                               |
| **D.C** **산출의 근거** | 26262-5:2018 Table D.6 communication bus |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                       |
### 1. 상세 구현 방안(Implementation approach in detail)
Bus의 오류이나 Bus에 연결된 Slave block의 오류로 인하여 bus transaction이 설정된 시간 안에 완료되지 않으면 Bus error response를 주어 Master와 Bus의 동작 불능을 방지하고 timeout error 발생을 SE에 전달한다.
![[SM-31 Bus Interface Timeout.png]]