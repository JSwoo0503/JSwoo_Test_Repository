
| **SM ID**          | SM-39                                            |
| ------------------ | ------------------------------------------------ |
| **구현 파트**          | HW/SW                                            |
| **Failure Mode**   | Address/Data 오류                                  |
| **D.C(%)**         | 99(High)                                         |
| **D.C** **산출의 근거** | ISO26262-5, Table D.4 Processing Units (D.2.3.9) |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                               |
### 1. 상세 구현 방안(Implementation approach in detail)
DDR Memory의 영역을 나누고 영역별로 Secure Level에 따라 Access를 제어할 수 있다. Secure 모드로 설정하면 Secure Level의 Master만 Read/Write가 가능하다. Non-Secure 모드로 설정하면 모든 Master가 Read/Write할 수 있다.


APACHE6는 Secure와 Non-Secure, 두 단계로 Secure Level을 나눠 접근 권한을 관리하는 Memory Protection 기능을 제공한다. BUS Block을 통하여 다른 HW Block과 DDR Memory등에 Access할 수 있는 기능을 갖는 Block(HW 엘리먼트)들을 Master Block이라고 하며 각 Master Block은 Access할 때 Secure Level을 구별할 수 있는 Protection 신호를 함께 출력한다. 특히, CPU는 동작하는 여러 개의 SW에 개별적으로 Secure Level를 할당할 수 있다.