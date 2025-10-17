
| **SM ID**          | SM-25                                              |
| ------------------ | -------------------------------------------------- |
| **구현 파트**          | HW                                                 |
| **Failure Mode**   | No global reset                                    |
| **D.C(%)**         | 99(High)                                           |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.5 Analogue and digital I/O |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                 |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6 시스템은 External Reset(Power-on reset, System reset) 이 Low이면 Global reset 과 Safe reset 상태 인 System Reset state가 된다. APACHE6 시스템은 System Reset 상태를 HOST ECU에 전달하기 위해 GPIO ERROR (FAULT_P, FAULT_N) Pin을 Low 인 상태를 출력한다. External Reset 이 high 이면 System reset state가 release되고 GPIO ERROR (FAULT_P, FAULT_N) Pin 은 다음과 같은 상태가 출력된다.

| **PIN**     | **System reset state**<br>**(Global reset + Safe reset)** | **Normal state** | **Safe state** |
| ----------- | --------------------------------------------------------- | ---------------- | -------------- |
| **FAULT_P** | Low                                                       | Low              | High           |
| **FAULT_N** | Low                                                       | High             | Low            |
![[SM-25 External Reset Monitoring.png]]