
| **SM ID**          | SM-02                                                                     |
| ------------------ | ------------------------------------------------------------------------- |
| **구현파트**           | HW                                                                        |
| **Failure Mode**   | Data/Address 오류                                                           |
| **D.C(%)**         | 99(High)                                                                  |
| **D.C** **산출의 근거** | ISO26262-11, 5-1 Digital components and memories 표 32 Non-volatile memory |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                                        |
### 1. 상세 구현 방안(Implementation approach in detail)
BL1는 Boot Code가 IROM에 저장되어 있기 때문에 무결성 오류 체크를 ECC를 통해 HW가 수행하고 있다. BL1의 수행 과정에서 CRC, Hash, Signing Authentication 등의 알고리즘을 사용하여 Application의 무결성을 확인해야 한다.