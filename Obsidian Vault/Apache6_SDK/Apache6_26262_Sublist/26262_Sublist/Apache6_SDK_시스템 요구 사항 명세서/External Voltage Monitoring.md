
| **SM ID**          | SM-22                                  |
| ------------------ | -------------------------------------- |
| **구현 파트**          | External                               |
| **Failure Mode**   | 외부 전압 오류                               |
| **D.C(%)**         | 99(High)                               |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.7 Power supply |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                     |
### 1. 상세 구현 방안(Implementation approach in detail)
ADAS ECU 는 APACHE6 시스템에 공급되는 외부 전압을 모니터링 하여 외부 전압 오류를 검출해야 한다.

| **외부 전원**           | **내용**                                                                 |
| ------------------- | ---------------------------------------------------------------------- |
| Digital 3.3 Voltage | Digital IO 3.3V 전원                                                     |
| Digital 1.8 Voltage | Digital IO 1.8V 전원                                                     |
| Digital 1.2 Voltage | MIPI PHY 1.2V 전원                                                       |
| LPDDR IO Voltage    | LPDDR4 IO 1.1V 전원 (LPDDR4X 1.1V와 0.6V)                                 |
| Digital 0.9 Voltage | Digital Core 0.9V 전원                                                   |
| Digital 0.8 Voltage | Digital Core 0.8V 전원                                                   |
| Analog 1.8 Voltage  | Analog IP 1.8V 전원<br>(ADC, PLL, Temperature sensor, voltage sensor 전원) |
