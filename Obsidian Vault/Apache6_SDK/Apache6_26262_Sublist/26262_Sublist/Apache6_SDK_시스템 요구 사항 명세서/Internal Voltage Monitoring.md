
| **SM ID**          | SM-21                                  |
| ------------------ | -------------------------------------- |
| **구현 파트**          | HW / SW                                |
| **Failure Mode**   | 내부 전압 오류                               |
| **D.C(%)**         | 99(High)                               |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.7 Power supply |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                     |
### 1. 상세 구현 방안(Implementation approach in detail)
APACHE6은 Die 내 5개 이상의 분산된 위치에 대한 전압 모니터링 기능을 제공한다. Safety SW는 Safety manager task를 통해 66-ms 이내의 주기로 각 위치들의 전압 값을 확인한다. Safety manager는 각 위치들의 전압 값이 0.8V의 ±8% 범위를 만족하는지를 확인하고 범위를 벗어나면 voltage error를 SE에 전달한다.

![[SM-21 Internal Voltage Monitoring.png]]