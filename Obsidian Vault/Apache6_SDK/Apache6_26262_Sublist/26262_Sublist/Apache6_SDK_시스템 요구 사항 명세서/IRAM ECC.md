
| **SM ID**          | SM-03                                                                 |
| ------------------ | --------------------------------------------------------------------- |
| **구현파트**           | HW/SW                                                                 |
| **Failure Mode**   | Data/Address 오류                                                       |
| **D.C(%)**         | 99(High)                                                              |
| **D.C** **산출의 근거** | ISO26262-11, 5-1 Digital components and memories 표 33 volatile memory |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
Application의 경우 외부 저장 장치에 저장되어 있기 때문에 BL1에서 IRAM로 로딩하는 과정에 무결성 오류를 확인해야 한다. Application의 무결성 정보는 파일이 생성될 때 함께 생성 되어 파일에 포함되어야 한다. BL1의 수행 과정에서 CRC, Hash, Signing Authentication 등의 알고리즘을 사용하여 Application의 무결성을 확인해야 한다.