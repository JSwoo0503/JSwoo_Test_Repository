
| **SM ID**          | SM-17                                                 |
| ------------------ | ----------------------------------------------------- |
| **구현 파트**          | SW                                                    |
| **Failure Mode**   | key authentication failed                             |
| **D.C(%)**         | 90(Medium)                                            |
| **D.C** **산출의 근거** | ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring |
| **S.M Type**       | 단일점 결함을 막는 안전 메커니즘                                    |
### 1. 상세 구현 방안(Implementation approach in detail)
Secure Boot는 HMAC / Public / AES Key를 생성 및 조합하여 생성하여 필요한 단계에서 사용하여 Encryption한다. 해당 Key는 OTP에 저장하여 부팅 시에만 읽어 사용하고 다 사용한 후에는 iRAM에서 지우고, OTP도 Read되지 않도록 한다. 부팅 시 BL1은 Encrypted Application Image의 Integrity를 검사하여 Image가 오염되지 않았는지 확인한다. 만약 오염되었다면 Application을 실행하지 않고 Boot Fail을 SE에 전달하여 외부에 알리도록 한다.
![[SM-17 Secure Boot.png]]