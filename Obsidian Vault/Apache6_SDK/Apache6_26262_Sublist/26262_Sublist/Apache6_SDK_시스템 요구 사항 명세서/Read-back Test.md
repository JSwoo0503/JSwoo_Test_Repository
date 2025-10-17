
| **SM ID**          | SM-07                                      |
| ------------------ | ------------------------------------------ |
| **구현 파트**          | SW                                         |
| **Failure Mode**   | Register 설정 오류                             |
| **D.C(%)**         | 99(High)                                   |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.4 Processing Units |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                         |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6 시스템은 주요 IP의 레지스터를 설정 할 때 설정 값을 다시 읽고 비교하여 의도한 레지스터 값이 설정되었는지 확인한다. 만약 설정한 레지스값이 다르다면 레지스터 설정 오류를 SE에 전달한다.

![[SM-07 Read-back Test.png]]