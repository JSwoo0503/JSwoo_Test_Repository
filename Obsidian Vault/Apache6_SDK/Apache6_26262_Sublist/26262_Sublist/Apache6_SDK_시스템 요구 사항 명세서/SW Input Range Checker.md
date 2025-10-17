
| **SM ID**          | SM-19                                             |
| ------------------ | ------------------------------------------------- |
| **구현 파트**          | SW                                                |
| **Failure Mode**   | SW 입력 범위 오류                                       |
| **D.C(%)**         | 90(Medium)                                        |
| **D.C** **산출의 근거** | ISO26262-5, Table D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                |
### 1. 상세 구현 방안(Implementation approach in detail)
SW 기반의 Input Range Checker는 온도 등 중요 입력 값에 대한 입력 상태를 모니터링 하여 의도하지 않은 오류로 인한 입력 값 변화를 감지한다. 정상적인 입력 값의 진행 방향성을 모니터링 하고, 갑자기 변화하는 값에 대한 이상 동작 발생시 그 값은 무시한다. 영상 출력에 영향을 주는 SW parameter의 의 경우, 입력 값이 Min값 보다 작으면 min 값으로 대체하고, 입력 값이 max 값보다 크면 max 값으로 대체한다.

![[SM-19 Input Range Checker.png]]