
| **SM ID**          | SM-36                                  |
| ------------------ | -------------------------------------- |
| **구현 파트**          | HW                                     |
| **Failure Mode**   | Address/Data 오류                        |
| **D.C(%)**         | 99(High)                               |
| **D.C** **산출의 근거** | 26262-11:2018 Table 33 volatile memory |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                     |
### 1. 상세 구현 방안(Implementation approach in detail)
Safety와 관련된 SW code와 데이터를 저장하는 영역에 저장된 데이터 ECC 검사를 한다. 데이터를 저장할 때 ECC를 만들어 DDR 메모리에 저장하고 데이터를 읽을 때 저장된 ECC데이터를 함께 읽은 후 읽은 데이터의 ECC와 저장된 ECC를 비교 검사하여 에러를 검출한다. SECDED ECC를 수행하여 1bit error는 복구하여 정상동작이 가능하나 에러 발생은 SE에 전달한다.
![[SM-36 DDR Memory Safety Region ECC Check.png]]