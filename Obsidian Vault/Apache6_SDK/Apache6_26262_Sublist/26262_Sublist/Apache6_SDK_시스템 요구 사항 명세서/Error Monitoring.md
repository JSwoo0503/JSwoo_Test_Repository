| **SM ID**          | SM-08                                                                       |
| ------------------ | --------------------------------------------------------------------------- |
| **구현 파트**          | HW/SW                                                                       |
| **Failure Mode**   | Error register 오류 검출                                                        |
| **D.C(%)**         | 99(High)                                                                    |
| **D.C** **산출의 근거** | ISO26262-11, 5-1 Digital components and memories 표 35 On-chip communication |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                                          |
### 1. 상세 구현 방안(Implementation approach in detail)
Error Monitor는 n개의 Error register의 값이 ‘1’이 되는 경우를 각각 monitoring하여 어느 하나의 register 값이 ‘1’ 되면, 오류가 발생한 것을 간주하고 오류를 SE에 전달한다.
![[SM-08 Error Monitoring.png]]