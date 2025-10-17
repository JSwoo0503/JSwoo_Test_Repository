
| **SM ID**          | SM-34                                   |
| ------------------ | --------------------------------------- |
| **구현 파트**          | HW                                      |
| **Failure Mode**   | Process unit 오동작                        |
| **D.C(%)**         | 99(High)                                |
| **D.C** **산출의 근거** | 26262-5:2018 Table D.4 Processing units |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                      |
### 1. 상세 구현 방안(Implementation approach in detail)
두 개의 동일한 Processing unit이 동일한 동작을 수행하고 두 개의 결과를 비교한다. 결과에 차이가 있으면 둘 중 하나의 Processing unit에서 의도하지 않은 동작이 발생한 것이므로 오류로 검출하여 SE에 전달한다.
![[SM-34 Dual Core Lock Step.png]]