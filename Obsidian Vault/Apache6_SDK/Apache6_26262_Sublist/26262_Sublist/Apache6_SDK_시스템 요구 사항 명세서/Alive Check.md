
| **SM ID**          | SM-12                                      |
| ------------------ | ------------------------------------------ |
| **구현 파트**          | SW, External ECU                           |
| **Failure Mode**   | CPU Logic 오류 검출                            |
| **D.C(%)**         | 99(High)                                   |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.4 Processing Units |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                         |
### 1. 상세 구현 방안(Implementation approach in detail)
CPU는 66-ms 이하의 상위 시스템 레벨에서 정의한 시간 간격으로 자체 생성한 시작값으로 Instruction set test를 수행하여 시작값과 결과값을 External Interface(I2C, UART, SPI등)를 통해 HOST ECU에 전달한다. HOST ECU에서는 전달받은 시작값으로 Instruction set test를 수행하여 CPU에서 전달된 결과값과 동일한지 검사하여 오류를 검출한다.
![[SM-12 Alive Check.png]]