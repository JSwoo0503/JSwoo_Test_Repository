
| **SM ID**          | SM-40                                   |
| ------------------ | --------------------------------------- |
| **구현 파트**          | SW                                      |
| **Failure Mode**   | 내부 로직 고장                                |
| **D.C(%)**         | 90(Medium)                              |
| **D.C** **산출의 근거** | ISO26262-5, Table D.6 Communication bus |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                      |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6는 Vector Processing IP(VPU)의 내부 로직이 정상적인 flow로 동작하는지를 확인하기 위해 VPU의 interrrupts를 monitoring하여 발생시켜 66ms 이내에 오류를 검출하여 SE에 전달할 수 있어야 한다.

![[SM-40 Operating Monitor.png]]