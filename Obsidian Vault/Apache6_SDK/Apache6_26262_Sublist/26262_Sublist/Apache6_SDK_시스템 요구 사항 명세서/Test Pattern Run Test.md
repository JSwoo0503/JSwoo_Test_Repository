
| **SM ID**          | SM-29                                                     |
| ------------------ | --------------------------------------------------------- |
| **구현 파트**          | SW                                                        |
| **Failure Mode**   | Logic 오류                                                  |
| **D.C(%)**         | 90(Medium)                                                |
| **D.C** **산출의 근거** | 26262-11:2018 Table 34 combinatorial and sequential logic |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                        |
### 1. 상세 구현 방안(Implementation approach in detail)
테스트 패턴을 입력으로 Block을 동작시키고 결과를 확인하여 로직의 무결성을 확인한다. 테스트 패턴을 수행한 결과 데이터와 예측 데이터를 비교하고 차이가 있으면 오류 발생을 SE에 전달한다.
![[SM-29 Test Pattern Run Test.png]]