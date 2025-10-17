
| **SM ID**          | SM-04                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현파트**           | SW                                                    |
| **Failure Mode**   | Wrong Execution                                       |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |

### 1. 상세 구현 방안(Implementation approach in detail)
Bootloader의 동작 시퀀스 오류는 외부에서의 전기적 충격, 코드 영역 오류, 메모리 오류, 실행 중 CPU의 오동작 등으로 발생 가능하다. APACHE6 시스템은 BL1(IROM) → Application 순으로 동작하게 된다. BL1의 정상적인 Boot 과정을 수행하는 경우 각 주요 시점에서 진행 상태를 저장한다. 최종 단계에서는 이전 상태들의 결과를 확인하고, 정상적인 진행 상태가 아닌 경우 오류로 판단하여 SE에 Fault를 전달한다.
![[SM-04 Boot Sequence Monitoring.png]]