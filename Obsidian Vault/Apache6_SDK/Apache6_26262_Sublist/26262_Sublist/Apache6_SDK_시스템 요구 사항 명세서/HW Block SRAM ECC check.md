
| **SM ID**          | SM-32                                  |
| ------------------ | -------------------------------------- |
| **구현 파트**          | HW                                     |
| **Failure Mode**   | Address/Data 오류                        |
| **D.C(%)**         | 99(High)                               |
| **D.C** **산출의 근거** | 26262-11:2018 Table 33 Volatile memory |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                     |
### 1. 상세 구현 방안(Implementation approach in detail)
HW Block 내부에서 사용하는 SRAM에 저장한 데이터의 ECC 검사를 한다. 데이터를 저장할 때 데이터의 ECC를 함께 저장한다. 데이터를 읽을 때 읽은 데이터로 생성한 ECC와 저장된 ECC가 다르면 에러 발생을 SE에 전달한다.
![[SM-32 HW Block SRAM ECC Check.png]]