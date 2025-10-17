
| **SM ID**          | SM-11                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | SW                                                    |
| **Failure Mode**   | I2C의 통신 고장 검출                                         |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
External Device와 통신시 정상적인 response 신호 혹은 response data가 오는 지 검사한다. 정해진 시간 동안 정상적인 response가 오지 않을 경우 time-out 에러로 판단한다. Device 특성을 고려하여 재수행 횟수를 0~16회 이내에서 정할 수 있고 정해진 재수행 횟수를 넘어가면 오류를 SE에 전달한다.
![[SM-11 External Device Time-Out check.png]]