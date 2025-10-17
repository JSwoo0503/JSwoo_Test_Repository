| **SM ID**          | SM-09                                                                       |
| ------------------ | --------------------------------------------------------------------------- |
| **구현 파트**          | HW                                                                          |
| **Failure Mode**   | MIPI 출력 오류                                                                  |
| **D.C(%)**         | 99(High)                                                                    |
| **D.C** **산출의 근거** | ISO26262-11, 5-1 Digital components and memories 표 35 On-chip communication |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                                          |
### 1. 상세 구현 방안(Implementation approach in detail)
외부 HOST ECU는 APACHE6 시스템에서 출력되는 MIPI Data가 MIPI CSI2 interface spec.에 따라 출력되는지 모니터링하여 MIPI 출력 데이터의 오류를 검출해야 한다.