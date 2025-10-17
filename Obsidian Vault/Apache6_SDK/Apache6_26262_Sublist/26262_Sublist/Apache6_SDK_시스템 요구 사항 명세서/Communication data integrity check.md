
| **SM ID**          | SM-35                                    |
| ------------------ | ---------------------------------------- |
| **구현 파트**          | HW/SW                                    |
| **Failure Mode**   | Communication Failure, Data Error        |
| **D.C(%)**         | 99(High)                                 |
| **D.C** **산출의 근거** | 26262-5:2018 Table D.6 Communication bus |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                       |
### 1. 상세 구현 방안(Implementation approach in detail)
Communication bus는 checksum 혹은 ECC를 이용하여 data error를 검출하는 information redundancy 기능과 frame counter 혹은 frame ID등으로 packet 혹은 data frame의 loss 오류를 검출할 수 있는 기능, 그리고 약속된 시간 안에 data 전달이 되지 않으면 오류로 검출하는 timeout기능을 제공한다. Information redundancy, frame counter, timeout의 동작은 각 communication bus 표준에 따라 구현하여야 한다. 에러가 검출되면 각 communication bus 표준에서 정의한 절차에 따라 에러를 복구하여 동작을 수행하도록 한다. 그러나, 복구할 수 없는 오류가 발생하면 SE에 전달한다.