
| **SM ID**          | SM-06                                                     |
| ------------------ | --------------------------------------------------------- |
| **구현 파트**          | HW / SW                                                   |
| **Failure Mode**   | Logic 오류                                                  |
| **D.C(%)**         | 90(Medium)                                                |
| **D.C** **산출의 근거** | 26262-11:2018 Table 34 combinatorial and sequential logic |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                        |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6 시스템은 주기적으로 입력되는 영상을 처리하는 HW기능에 대해 blank(no-active state)구간동안, 테스트 패턴을 입력으로 한 동작을 수행함으로써 로직의 무결성을 확인한다. 테스트 패턴을 수행한 결과 값이 만약 미리 설정한 결과값(golden value)과 다르다면 로직 오류를 SE에 전달한다.

![[SM-06 Test Pattern Injection and Monitoring(TPIM).png]]

Test Pattern Injection and Monitor (TPIM)은 동작 중 Logic의 오류를 검출하기 위해,

1.     Test Pattern Injection은 입력 data (Input Data)가 아닌 Test Pattern 입력 data (TPIM Input Data)를 생성하고,

2.     Normal operation에 영향을 미치지 않는 Test Pattern injection 영역에 Logic의 입력으로 출력한다.

3.     그리고 TPIM Enable 신호를 기준으로 Logic의 입력, Logic의 register 설정, Logic의 출력이 선택된다.

4.     Compare Golden Vector는 Test Pattern Injection 영역의 Test Pattern 입력 data (TPIM Input Data)가 Logic을 거쳐 출력 된 TPIM Output Data를 입력 받는다.

5.     Compare CRC는 입력 된 TPIM Output Data의 CRC 값을 계산하여 예상 출력 CRC 값 (Golden CRC)과 비교하여 (값이 동일하지 않으면 오류) 오류를 검출한다.

오류가 검출되면 TPIM_fault 신호를 출력한다.