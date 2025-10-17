
| **SM ID**          | SM-05                                  |
| ------------------ | -------------------------------------- |
| **구현 파트**          | HW / SW                                |
| **Failure Mode**   | Register 오동작 방지                        |
| **D.C(%)**         | 99(High)                               |
| **D.C** **산출의 근거** | ISO26262-5, Table D.4 Processing Units |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                     |
### 1. 상세 구현 방안(Implementation approach in detail)
Register Lock Mechanism (이하 RLM)은 APACHE6의 Safety Mechanism 관련 register 설정 및 APACHE6 IP의 특정 기능을 enable하는 enable register의 오동작을 방지하기 위한 Safety Mechanism이다.
![[SM-05 Register Lock Mechanism.png]]
KEY Lock은 특정 Address bank를 접근하기 위해 KEY 값을 setting하여 Lock을 해제하고 register 값을 설정 (write)한다. Register Lock에 상관없이 register bank의 register 값을 읽어볼 수 있다.

RLM은 APACHE6 IP의 특정 기능을 enable 하는 register의 오동작을 방지하기 위해 특정 기능을 enable 하는 IP enable register와 오동작을 방지하기 위한 다른 Unlocked register를 AND Combination 하여 기능을 enable 하는 IP enable register가 오동작하더라도 IP의 기능이 enable 되지 않도록 한다.