
| **SM ID**          | SM-13                                              |
| ------------------ | -------------------------------------------------- |
| **구현 파트**          | HW/External/SW                                     |
| **Failure Mode**   | Fault 출력 오류 검출                                     |
| **D.C(%)**         | 99(High)                                           |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.5 Analogue and digital I/O |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                 |
### 1. 상세 구현 방안(Implementation approach in detail)
-	CPU는 SE의 Fault Manager를 설정한다.
	> HW/SW 안전메커니즘에서 발생되는 Fault 신호에 대한 enable/disable
-	Fault Manager는 설정된 fault 신호를 취합하여 fault interrupt 신호 출력한다.
-	State Machine은 fault interrupt, CPU의 operation control 신호에 의해 Operation state를 제어한다.
	> Operation state : reset mode, start-up mode, standard operation mode, safe state mode 구성됨.
-	State Machine은 Operation state가 Safe state mode 일 때 fault state신호를 출력한다.
-	Reset Gen.은 fault state가 입력될 때 Global reset state가 된다.
-	Fault 출력 이중화
	> fault state를 HOST ECU에게 전달하기 위해 Multi-bit의 FAULT_P, FAULT_N 신호를 출력한다.

| **PIN**     | **Normal state** | **Safe state** |
| ----------- | ---------------- | -------------- |
| **FAULT_P** | High             | Low            |
| **FAULT_N** | Low              | High           |
![[SM-13 Fault 출력 이중화.png]]