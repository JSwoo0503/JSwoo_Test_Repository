
| **SM ID**          | SM-30                                        |
| ------------------ | -------------------------------------------- |
| **구현 파트**          | HW                                           |
| **Failure Mode**   | Address/Data 오류                              |
| **D.C(%)**         | 90(Medium)                                   |
| **D.C** **산출의 근거** | 26262-11:2018 Table 35 on-chip communication |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                           |
### 1. 상세 구현 방안(Implementation approach in detail)
Bus 내부에서 데이터 전송시 ECC 검사를 한다. 데이터 송신 port에서 ECC를 만들어 데이터와 함께 보내고 수신 port에서 ECC 검사한다. SECDED ECC를 수행하여 1bit error는 복구하여 정상동작이 가능하나 에러 발생은 SE에 전달한다.
![[SM-30 Bus Transaction ECC Check.png]]