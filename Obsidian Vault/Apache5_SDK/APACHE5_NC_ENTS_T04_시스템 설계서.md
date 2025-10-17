**APACHE5**

|   |
|---|
|시스템 설계서|
|System Design Specification|

|   |   |   |   |
|---|---|---|---|
|Release V 1.1|   |   |   |
|작성|   |승인|   |
|SOC설계팀|방수석|SOC그룹|변형주|
|![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서.png>)|   |![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서.jpeg>)|   |

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 1.jpeg>)

수정이력(Revision History)

|   |   |   |   |
|---|---|---|---|
|날짜|버전|작성자|수정내용|
|2020.01.17|V0.1|방수석|최초 작성|
|2020.01.18|V0.2|방수석|3.2 시스템의 논리적 설계 업데이트|
|2020.01.19|V0.3|방수석|4. 기술 안전 컨셉 업데이트|
|2020.01.20|V0.4|서승범|4. 기술 안전 컨셉 업데이트|
|2020.01.20|V0.5|성민영|4. 기술 안전 컨셉 업데이트|
|2020.01.22|V1.0|방수석|검증 검토 결과 반영|
|2020.01.31|V1.1|방수석|기능 안전 심사 1차 결과 반영|
|||||
|||||
|||||

목차(Index)

[1. 개요(Overview) 10](#_Toc206430388)

[1.1. 목적(Purpose) 10](#_Toc206430389)

[1.2. 적용 범위(Scope) 10](#_Toc206430390)

[1.3. 참조 문서(Reference) 10](#_Toc206430391)

[2. 식별자 규칙(Identification Rule) 10](#_Toc206430392)

[3. 시스템 아키텍처 정의 (System Architecture Definition) 11](#_Toc206430393)

[3.1. 시스템의 동작 모드와 상태 (System operation mode & state) 11](#_Toc206430394)

[3.1.1. Reset state 11](#_Toc206430395)

[3.1.2. Start-up mode 11](#_Toc206430396)

[3.1.3. Standard Operation Mode 11](#_Toc206430397)

[3.1.4. Safe State 11](#_Toc206430398)

[3.2. 시스템의 물리적 설계 (System Physical Design) 12](#_Toc206430399)

[3.2.1. 시스템 Internal Block Diagram (System Internal Block Diagram) 12](#_Toc206430400)

[3.2.2. 시스템 엘리먼트 명세 (System Element Specification) 13](#_Toc206430401)

[3.2.2.1. [PDE-001] BLK_CPU 13](#_Toc206430402)

[3.2.2.2. [PDE-002] BLK_BUS 13](#_Toc206430403)

[3.2.2.3. [PDE-003] BLK_SCU 13](#_Toc206430404)

[3.2.2.4. [PDE-004] BLK_ICU 13](#_Toc206430405)

[3.2.2.5. [PDE-005] BLK_SAFETY 14](#_Toc206430406)

[3.2.2.6. [PDE-006] BLK_SECURE 14](#_Toc206430407)

[3.2.2.7. [PDE-007] BLK_ANALOG 14](#_Toc206430408)

[3.2.2.8. [PDE-008] BLK_PERI 14](#_Toc206430409)

[3.2.2.9. [PDE-009] BLK_VISION 14](#_Toc206430410)

[3.2.2.10. [PDE-010] BLK_GIC 15](#_Toc206430411)

[3.2.2.11. [PDE-011] BLK_CNN 15](#_Toc206430412)

[3.2.2.12. [PDE-012] BLK_HSP 15](#_Toc206430413)

[3.2.2.13. [PDE-013] BLK_H264 15](#_Toc206430414)

[3.2.2.14. [PDE-014] BLK_DDR 16](#_Toc206430415)

[3.2.3. 시스템 내부 인터페이스 (System Internal Interface) 16](#_Toc206430416)

[3.2.3.1. [PDI-001] AXI 16](#_Toc206430417)

[3.2.3.2. [PDI-002] AHB 16](#_Toc206430418)

[3.2.3.3. [PDI-001] APB 16](#_Toc206430419)

[3.3. 시스템의 논리적 설계 (System Logical Design) 17](#_Toc206430420)

[3.3.1. 기능 개요 (Functionalities Overview) 17](#_Toc206430421)

[3.3.2. SECURE IP 지원 (SECURE Boot 포함) 18](#_Toc206430422)

[3.3.2.1. Allocation requirement 19](#_Toc206430423)

[3.3.2.2. Internal block diagram 19](#_Toc206430424)

[3.3.2.3. Sequence diagram 20](#_Toc206430425)

[3.3.3. MIPI RX 데이터 오류 검출 21](#_Toc206430426)

[3.3.3.1. Allocation requirement 21](#_Toc206430427)

[3.3.3.2. Internal block diagram 21](#_Toc206430428)

[3.3.4. ISP Data 처리 및 오류 검출 22](#_Toc206430429)

[3.3.4.1. Allocation requirement 22](#_Toc206430430)

[3.3.4.2. Internal block diagram 22](#_Toc206430431)

[3.3.5. LDC (Lens Distortion Correction) 동작 및 오류 검출 23](#_Toc206430432)

[3.3.5.1. Allocation requirement 23](#_Toc206430433)

[3.3.5.2. Internal block diagram 23](#_Toc206430434)

[3.3.6. FRC 지원 및 오류 검출 24](#_Toc206430435)

[3.3.6.1. Allocation requirement 24](#_Toc206430436)

[3.3.6.2. Internal block diagram 24](#_Toc206430437)

[3.3.7. OF (Output Formatter) 동작 및 오류 검출 25](#_Toc206430438)

[3.3.7.1. Allocation requirement 25](#_Toc206430439)

[3.3.7.2. Internal block diagram 25](#_Toc206430440)

[3.3.8. MIPI TX 동작 및 오류 검출 26](#_Toc206430441)

[3.3.8.1. Allocation requirement 26](#_Toc206430442)

[3.3.8.2. Internal block diagram 26](#_Toc206430443)

[3.3.9. Ethernet 동작 및 오류 검출 27](#_Toc206430444)

[3.3.9.1. Allocation requirement 27](#_Toc206430445)

[3.3.9.2. Internal block diagram 27](#_Toc206430446)

[3.3.10. NPU 동작 및 오류 검출 28](#_Toc206430447)

[3.3.10.1. Allocation requirement 28](#_Toc206430448)

[3.3.10.2. Internal block diagram 28](#_Toc206430449)

[3.3.11. CPU 동작 및 오류 검출 29](#_Toc206430450)

[3.3.11.1. Allocation requirement 29](#_Toc206430451)

[3.3.11.2. Internal block diagram 30](#_Toc206430452)

[3.3.12. Interrupt 동작 31](#_Toc206430453)

[3.3.12.1. Allocation requirement 31](#_Toc206430454)

[3.3.12.2. Internal block diagram 31](#_Toc206430455)

[3.3.13. IO 제어 32](#_Toc206430456)

[3.3.13.1. Allocation requirement 32](#_Toc206430457)

[3.3.13.2. Internal block diagram 32](#_Toc206430458)

[3.3.14. CAN(LIN) Interface 33](#_Toc206430459)

[3.3.14.1. Allocation requirement 33](#_Toc206430460)

[3.3.14.2. Internal block diagram 33](#_Toc206430461)

[3.3.15. External Interface 34](#_Toc206430462)

[3.3.15.1. Allocation requirement 34](#_Toc206430463)

[3.3.15.2. Internal block diagram 34](#_Toc206430464)

[3.3.16. DDR Controller 35](#_Toc206430465)

[3.3.16.1. Allocation requirement 35](#_Toc206430466)

[3.3.16.2. Internal block diagram 35](#_Toc206430467)

[3.3.17. Flash Memory Interface 지원 36](#_Toc206430468)

[3.3.17.1. Allocation requirement 36](#_Toc206430469)

[3.3.17.2. Internal block diagram 36](#_Toc206430470)

[3.3.18. SD/eMMC 지원 37](#_Toc206430471)

[3.3.18.1. Allocation requirement 37](#_Toc206430472)

[3.3.18.2. Internal block diagram 37](#_Toc206430473)

[3.3.19. UART Interface 지원 38](#_Toc206430474)

[3.3.19.1. Allocation requirement 38](#_Toc206430475)

[3.3.19.2. Internal block diagram 38](#_Toc206430476)

[3.3.20. H.264 Encoder 39](#_Toc206430477)

[3.3.20.1. Allocation requirement 39](#_Toc206430478)

[3.3.20.2. Internal block diagram 39](#_Toc206430479)

[4. 기술안전 컨셉 (Technical Safety Concept) 40](#_Toc206430480)

[4.1. [TSC-001] Video Sync 오류 검출 40](#_Toc206430481)

[4.1.1. [SM-12] Video sync counter 40](#_Toc206430482)

[4.1.1.1. 상세 구현 방안(Implementation approach in detail) 40](#_Toc206430483)

[4.2. [TSC-002] 외부 Device Interface 오류 검출 41](#_Toc206430484)

[4.2.1. [SM-18] External Interface timeout 41](#_Toc206430485)

[4.2.1.1. 상세 구현 방안(Implementation approach in detail) 41](#_Toc206430486)

[4.2.2. [SM-19] External interface readback 42](#_Toc206430487)

[4.2.2.1. 상세 구현 방안(Implementation approach in detail) 42](#_Toc206430488)

[4.3. [TSC-003] Boot-up 오류 검출 및 대응 43](#_Toc206430489)

[4.3.1. [SM-01] IROM/IRAM ECC 43](#_Toc206430490)

[4.3.1.1. 상세 구현 방안(Implementation approach in detail) 43](#_Toc206430491)

[4.3.2. [SM-02] Secure Boot 44](#_Toc206430492)

[4.3.2.1. 상세 구현 방안(Implementation approach in detail) 44](#_Toc206430493)

[4.3.3. [SM-03] Boot Sequence monitor 45](#_Toc206430494)

[4.3.3.1. 상세 구현 방안(Implementation approach in detail) 45](#_Toc206430495)

[4.3.4. [SM-04] Backup Boot 46](#_Toc206430496)

[4.3.4.1. 상세 구현 방안(Implementation approach in detail) 46](#_Toc206430497)

[4.4. [TSC-004] Register 오 동작 방지 47](#_Toc206430498)

[4.4.1. [SM-07] Mirror register 47](#_Toc206430499)

[4.4.1.1. 상세 구현 방안(Implementation approach in detail) 47](#_Toc206430500)

[4.5. [TSC-005] IP Logic 오류 검출 48](#_Toc206430501)

[4.5.1. [SM-16] Test pattern injection 48](#_Toc206430502)

[4.5.1.1. 상세 구현 방안(Implementation approach in detail) 48](#_Toc206430503)

[4.5.2. [SM-09] IP Fault control 49](#_Toc206430504)

[4.5.2.1. 상세 구현 방안(Implementation approach in detail) 49](#_Toc206430505)

[4.5.3. [SM-11] MIPI RX monitor 50](#_Toc206430506)

[4.5.3.1. 상세 구현 방안(Implementation approach in detail) 50](#_Toc206430507)

[4.6. [TSC-006] Standard Communication Protocol 51](#_Toc206430508)

[4.6.1. [SM-20] Communication controllers 51](#_Toc206430509)

[4.6.1.1. 상세 구현 방안(Implementation approach in detail) 51](#_Toc206430510)

[4.7. [TSC-007] Memory 오류 검출 및 보정 53](#_Toc206430511)

[4.7.1. [SM-10] SRAM integrity (ECC, CRC) 53](#_Toc206430512)

[4.7.1.1. 상세 구현 방안(Implementation approach in detail) 53](#_Toc206430513)

[4.8. [TSC-008] Data 무결성 검사 54](#_Toc206430514)

[4.8.1. [SM-14] Data integrity check 54](#_Toc206430515)

[4.8.1.1. 상세 구현 방안(Implementation approach in detail) 54](#_Toc206430516)

[4.9. [TSC-009] Bus 오류 검출 55](#_Toc206430517)

[4.9.1. [SM-17] OIC 55](#_Toc206430518)

[4.9.1.1. 상세 구현 방안(Implementation approach in detail) 55](#_Toc206430519)

[4.10. [TSC-010] 클럭 주파수 오류 검출 56](#_Toc206430520)

[4.10.1. [SM-08] Clock monitor (구. Clock Monitoring) 56](#_Toc206430521)

[4.10.1.1. 상세 구현 방안(Implementation approach in detail) 56](#_Toc206430522)

[4.11. [TSC-011] Reset 오류 검출 57](#_Toc206430523)

[4.11.1. [SM-05] Reset sequence monitor (구. Reset Sequence Monitoring) 57](#_Toc206430524)

[4.11.1.1. 상세 구현 방안(Implementation approach in detail) 57](#_Toc206430525)

[4.12. [TSC-012] CPU 동작 오류 검출 58](#_Toc206430526)

[4.12.1. [SM-15] Watchdog Timer 58](#_Toc206430527)

[4.12.1.1. 상세 구현 방안(Implementation approach in detail) 58](#_Toc206430528)

[4.13. [TSC-013] Timer 오류 검출 59](#_Toc206430529)

[4.13.1. [SM-06] Redundant timer 59](#_Toc206430530)

[4.13.1.1. 상세 구현 방안(Implementation approach in detail) 59](#_Toc206430531)

[4.14. [TSC-014] Voltage/Temperature 안정성 확인 60](#_Toc206430532)

[4.14.1. [SM-21] Internal voltage monitor 60](#_Toc206430533)

[4.14.1.1. 상세 구현 방안(Implementation approach in detail) 60](#_Toc206430534)

[4.14.2. [SM-22] Internal Temperature monitor 61](#_Toc206430535)

[4.14.2.1. 상세 구현 방안(Implementation approach in detail) 61](#_Toc206430536)

[4.15. [TSC-015] Interrupt 오류 검출 62](#_Toc206430537)

[4.15.1. [SM-13] Interrupt monitor 62](#_Toc206430538)

[4.15.1.1. 상세 구현 방안(Implementation approach in detail) 62](#_Toc206430539)

[4.16. [TSC-016] System 안정성 확인 63](#_Toc206430540)

[4.16.1. [SM-91] State monitor 63](#_Toc206430541)

[4.16.1.1. 상세 구현 방안(Implementation approach in detail) 63](#_Toc206430542)

[4.16.2. [SM-92] External Watchdog 64](#_Toc206430543)

[4.16.2.1. 상세 구현 방안(Implementation approach in detail) 64](#_Toc206430544)

[4.16.3. [SM-93] Voltage Monitor 65](#_Toc206430545)

[4.16.3.1. 상세 구현 방안(Implementation approach in detail) 65](#_Toc206430546)

[4.16.4. [SM-94] Board temperature monitor 66](#_Toc206430547)

[4.16.4.1. 상세 구현 방안(Implementation approach in detail) 66](#_Toc206430548)

[4.16.5. [SM-95] MIPI output monitor (구. MIPI TX Output Monitoring) 67](#_Toc206430549)

[4.16.5.1. 상세 구현 방안(Implementation approach in detail) 67](#_Toc206430550)

[4.16.6. [SM-96] Alive check 67](#_Toc206430551)

[4.16.6.1. 상세 구현 방안(Implementation approach in detail) 68](#_Toc206430552)

[5. 할당된 정량적 목표(Quantitative Goal) 69](#_Toc206430553)

[5.1. 하드웨어 아키텍처 메트릭 (HW Architecture Metric) 69](#_Toc206430554)

[5.2. PMHF 69](#_Toc206430555)

[6. 설계 제약 사항 (Design Constraint) 70](#_Toc206430556)

[6.1. [const-001] Use Case 70](#_Toc206430557)

[6.2. [const-002] Frame rate 70](#_Toc206430558)

[6.3. [const-003] Power 70](#_Toc206430559)

[6.4. [const-004] Temperature 70](#_Toc206430560)

[6.5. [const-005] Clock 및 Reset 조건 70](#_Toc206430561)

[6.6. [const-006] J-TAG Debugger 70](#_Toc206430562)

**표(Table)**

[[표 1] 참조 문서 10](#_Toc206430563)

[[표 2] 식별자 규칙 10](#_Toc206430564)

[[표 3] SYSTEM COMPONENT 16](#_Toc206430565)

[[표 4] AXI Interface 16](#_Toc206430566)

[[표 5] AHB Interface 16](#_Toc206430567)

[[표 6] APB Interface 16](#_Toc206430568)

[[표 7] SYSTEM FUNCTION 18](#_Toc206430569)

[[표 8] Allocation requirement 19](#_Toc206430570)

[[표 9] Allocation requirement 21](#_Toc206430571)

[[표 10] Allocation requirement 22](#_Toc206430572)

[[표 11] Allocation requirement 23](#_Toc206430573)

[[표 12] Allocation requirement 24](#_Toc206430574)

[[표 13] Allocation requirement 25](#_Toc206430575)

[[표 14] Allocation requirement 26](#_Toc206430576)

[[표 15] Allocation requirement 27](#_Toc206430577)

[[표 16] Allocation requirement 28](#_Toc206430578)

[[표 17] Allocation requirement 29](#_Toc206430579)

[[표 18] Allocation requirement 31](#_Toc206430580)

[[표 19] Allocation requirement 32](#_Toc206430581)

[[표 20] Allocation requirement 33](#_Toc206430582)

[[표 21] Allocation requirement 34](#_Toc206430583)

[[표 22] Allocation requirement 35](#_Toc206430584)

[[표 23] Allocation requirement 36](#_Toc206430585)

[[표 24] Allocation requirement 37](#_Toc206430586)

[[표 25] Allocation requirement 38](#_Toc206430587)

[[표 26] Allocation requirement 39](#_Toc206430588)

[[표 27] GPIO Fault P/N mode 63](#_Toc206430589)

[[표 28] 외부 전원 65](#_Toc206430590)

그림(Figure)

[[그림 1] System operation mode & state 11](#_Toc206430591)

[[그림 2] System Internal Block Diagram 12](#_Toc206430592)

[[그림 3] Security IP 19](#_Toc206430593)

[[그림 4] ROM/RAM Block Diagram 19](#_Toc206430594)

[[그림 5] Secure Boot Sequence Diagram 20](#_Toc206430595)

[[그림 6] MIPI Data 21](#_Toc206430596)

[[그림 7] ISP Pipeline 22](#_Toc206430597)

[[그림 8] LDC Block Diagram 23](#_Toc206430598)

[[그림 9] FRC location 24](#_Toc206430599)

[[그림 10] Output Formatter 25](#_Toc206430600)

[[그림 11] MIPI TX output 26](#_Toc206430601)

[[그림 12] Ethernet Block Diagram 27](#_Toc206430602)

[[그림 13] NPU Block Diagram 28](#_Toc206430603)

[[그림 14] CPU Block Diagram 30](#_Toc206430604)

[[그림 15] Interrupt Block Diagram 31](#_Toc206430605)

[[그림 16] Interface between Sensor and APACHE5 32](#_Toc206430606)

[[그림 17] CAN Block Diagram 33](#_Toc206430607)

[[그림 18] External Interface 34](#_Toc206430608)

[[그림 19] DDRC Block Diagram 35](#_Toc206430609)

[[그림 20] Flash Memory Interface 36](#_Toc206430610)

[[그림 21] SD/eMMC Block Diagram 37](#_Toc206430611)

[[그림 22] UART Interface 38](#_Toc206430612)

[[그림 23] VPU Block Diagram 39](#_Toc206430613)

[[그림 24] Sync monitoring flow 40](#_Toc206430614)

[[그림 25] Peripheral interface timeout 41](#_Toc206430615)

[[그림 26] External interface readback 42](#_Toc206430616)

[[그림 27] Example of boot sequence monitor 45](#_Toc206430617)

[[그림 28] Backup boot flow 46](#_Toc206430618)

[[그림 29] Mirror register 47](#_Toc206430619)

[[그림 30] Test pattern injection (ISP) 48](#_Toc206430620)

[[그림 31] Test pattern injection (VCODEC / NPU) 49](#_Toc206430621)

[[그림 32] MIPI RX monitor 50](#_Toc206430622)

[[그림 33] CAN frame format 51](#_Toc206430623)

[[그림 34] LIN frame format 51](#_Toc206430624)

[[그림 35] Ethernet frame format 52](#_Toc206430625)

[[그림 36] SRAM ECC 53](#_Toc206430626)

[[그림 37] SRAM CRC 53](#_Toc206430627)

[[그림 38] Data integrity check 54](#_Toc206430628)

[[그림 39] OIC 55](#_Toc206430629)

[[그림 40] Clock monitoring flow 56](#_Toc206430630)

[[그림 41] Reset sequence 57](#_Toc206430631)

[[그림 42] Watchdog Timer 58](#_Toc206430632)

[[그림 43] Redundancy Timer flow 59](#_Toc206430633)

[[그림 44] Internal Voltage Sensor flow 60](#_Toc206430634)

[[그림 45] Temperature Sensor flow 61](#_Toc206430635)

[[그림 46] Interrupt monitor 62](#_Toc206430636)

[[그림 47] GPIO Fault P/N signal 63](#_Toc206430637)

[[그림 48] External Watchdog 64](#_Toc206430638)

[[그림 49] Temperature sensor flow (Host ECU) 66](#_Toc206430639)

[[그림 50] MIPI output monitor 67](#_Toc206430640)

[[그림 51] External Watchdog 68](#_Toc206430641)

# 개요(Overview)

## 목적(Purpose)

본 명세서는 시스템 수준의 아키텍처를 정의하고 시스템 수준에서의 설계 사양을 명세 하는 것을 그 목적으로 한다.

## 적용 범위(Scope)

본 명세서는 반도체 시스템 설계 업무에 활용하며 시스템 요구사항과 시스템 기술 안전 요구사항을 반영한다.

## 참조 문서(Reference)

|   |   |   |
|---|---|---|
|No.|문서명|버전|
|1|APACHE5_NC_ENTS_T02_기술안전 요구사항 정의 및 분석 결과서|V1.0|
|2|APACHE5_NC_ENTS_T03_시스템 요구사항 명세서|V1.0|

[표 1] 참조 문서

# 식별자 규칙(Identification Rule)

|   |   |   |   |
|---|---|---|---|
|**구분**|**식별자**|   |**예제**|
|시스템 엘리먼트|PDE|Product Design Element|PDE-001|
|시스템 설계 인터페이스|PDI|Product Design Interface|PDI-001|

[표 2] 식별자 규칙

# 시스템 아키텍처 정의 (System Architecture Definition)

## 시스템의 동작 모드와 상태 (System operation mode & state)

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 1.png>)

[그림 1] System operation mode & state

### Reset state

외부의 reset 신호가 low가 되면 Reset state로 진입해야 한다. 외부 reset 신호가 high가 되면 Reset state에서 Start-up 모드로 전환한다.

### Start-up mode

boot-up sequence를 수행해야 한다. boot-up 시 필요한 Self-test를 수행하고 boot-up sequence 가 정상적으로 종료되면 Standard Operation mode로 전환 한다. Self-test에 오류가 나거나 boot-up sequence 가 비정상적으로 수행될 경우에는 Safe state 로 진입해야 한다.

### Standard Operation Mode

시스템의 보편적인 기능을 수행한다. 안전 메커니즘에 결함이 발생하거나 CPU가 특정 시간 안에 Watch-dog을 초기화 하는데 실패할 경우에는 Safe state 로 전환한다.

### Safe State

Global reset 상태를 유지하고 외부에서 내부 상태 정보에 접근할 수 있도록 external Interface를 제공해야 한다.

## 시스템의 물리적 설계 (System Physical Design)

### 시스템 Internal Block Diagram (System Internal Block Diagram)

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 2.png>)

[그림 2] System Internal Block Diagram

### 시스템 엘리먼트 명세 (System Element Specification)

#### [PDE-001] BLK_CPU

|   |   |
|---|---|
|**Function**|System reset 이후 Boot-up 시퀀스를 수행한다.<br><br>System SW를 수행하여 Platform을 제어한다.<br><br>Safety SW를 수행하여 SYS, ISP 안전 메커니즘을 제어한다.<br><br>ISP SW를 수행하여 ISP를 제어한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-010|
|**관련 TSR**|TSR-001, TSR-002, TSR-003, TSR-004, TSR-005, TSR-006, TSR-007, TSR-008, TSR-011, TSR-012, TSR-013, TSR-015, TSR-016, TSR-017, TSR-019, TSR-021, TSR-022, TSR-023, TSR-024|
|**관련 SIR**|N.A|

#### [PDE-002] BLK_BUS

|   |   |
|---|---|
|**Function**|Master 엘리먼트에서 Slave 영역(Address)의 Data에 대한 Read/Write 요청을 할 수 있게 한다. (AXI, AHB, APB Interface)|
|**Allocation**|HW|
|**관련 TR**|TR-010|
|**관련 TSR**|TSR-021, TSR-024|
|**관련 SIR**|N.A|

#### [PDE-003] BLK_SCU

|   |   |
|---|---|
|**Function**|System Clock으로 PLL Clock 출력 주파수를 제어한다.<br><br>PLL 출력 clock으로 내부 clock을 생성한다. (Sensor Reference Clock 출력 포함)<br><br>Global Reset을 생성한다.<br><br>Clock Domain별 Local Reset을 생성한다.<br><br>Booting을 위한 ROM 및 Internal SRAM을 포함해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-010|
|**관련 TSR**|TSR-003, TSR-011, TSR-012|
|**관련 SIR**|SIR-005, SIR-008, SIR-009|

#### [PDE-004] BLK_ICU

|   |   |
|---|---|
|**Function**|엘리먼트는핀을 통해 신호를 입력 받거나 출력 할 수 있다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-012|
|**관련 TSR**|TSR-002, TSR-006, TSR-010, TSR-012, TSR-013, TSR-021|
|**관련 SIR**|SIR-003, SIR-004, SIR-006, SIR-007|

#### [PDE-005] BLK_SAFETY

|   |   |
|---|---|
|**Function**|각 엘리먼트에서 출력하는 에러 신호를 취합하여 시스템의 state를 천이 시킨다.<br><br>오류가 발생하면 FAULT GPIO PIN을 Different 출력한다.|
|**Allocation**|HW / SW|
|**관련 TR**|N.A|
|**관련 TSR**|TSR-010, TSR-011|
|**관련 SIR**|SIR-010|

#### [PDE-006] BLK_SECURE

|   |   |
|---|---|
|**Function**|암호화된 Boot code를 복호화한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-001|
|**관련 TSR**|TSR-003, TSR-015|
|**관련 SIR**|N.A|

#### [PDE-007] BLK_ANALOG

|   |   |
|---|---|
|**Function**|ADC, Temperature Sensor, Voltage Sensor, eFuse/OTP를 포함시켜야 한다.<br><br>ADC는 User Specific Analog 입력을 Digital 값으로 변경한다.<br><br>Temperature Sensor는 APACHE5 내부 온도를 측정할 수 있어야 한다.<br><br>Voltage Sensor는 APACHE5 내부의 전압을 측정할 수 있어야 한다.<br><br>eFuse/OTP는 Fusing된 값을 읽어 데이터를 전달할 수 있어야 한다.|
|**Allocation**|HW|
|**관련 TR**|N.A|
|**관련 TSR**|TSR-015, TSR-017, TSR-019|
|**관련 SIR**|N.A|

#### [PDE-008] BLK_PERI

|   |   |
|---|---|
|**Function**|CIS와 통신할 수 있는 I2C, Serial Flash와 통신할 수 있는 SPI, QSPI, HOST ECU와 통신할 수 있는 CAN/LIN, debugging을 위한 UART통신, PWM, Timer를 내장해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-013, TR-014, TR-016, TR-018|
|**관련 TSR**|TSR-002, TSR-005, TSR-006, TSR-013, TSR-014, TSR-016, TSR-021, TSR-025|
|**관련 SIR**|SIR-006, SIR-007, SIR-012|

#### [PDE-009] BLK_VISION

|   |   |
|---|---|
|**Function**|Image Sensor로부터 입력된 MIPI 규격의 Serial Data를 Parallel Image Data로 변경한다.<br><br>ISP 처리된 데이터를 MIPI TX를 통해 외부 ECU에 전달할 수 있어야 한다.<br><br>ISP는 입력 영상의 화질을 개선시킬 수 있어야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-002, TR-003, TR-004, TR-005, TR-006, TR-007|
|**관련 TSR**|TSR-001, TSR-003, TSR-004, TSR-005, TSR-007, TSR-024|
|**관련 SIR**|SIR-001, SIR-002|

#### [PDE-010] BLK_GIC

|   |   |
|---|---|
|**Function**|GIC는 Edge 혹은 Level triggered를 감지할 수 있어야 한다.<br><br>또한, 우선 순위를 정할 수 있어야 하며, CPU와 연결하여 IRQ/FIQ를 지원할 수 있어야 한다.|
|**Allocation**|HW|
|**관련 TR**|TR-011|
|**관련 TSR**|TSR-016|
|**관련 SIR**|N.A|

#### [[PDE-011]] BLK_CNN

|   |   |
|---|---|
|**Function**|BLK_CNN은 인식을 위한 NPU 기능을 제공해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-009|
|**관련 TSR**|TSR-003, TSR-005, TSR-024|
|**관련 SIR**|N.A|

#### [PDE-012] BLK_HSP

|   |   |
|---|---|
|**Function**|APACHE5는 Ethernet 통신을 위한 Controller를 내장해야 한다.<br><br>BLK_HSP는 SD/eMMC를 통해 외부 메모리에 저장할 수 있는 기능을 제공해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-008, TR-017|
|**관련 TSR**|TSR-002, TSR-005, TSR-025|
|**관련 SIR**|SIR-011, SIR-014|

#### [PDE-013] BLK_H264

|   |   |
|---|---|
|**Function**|영상 압축을 위한 H.264 포맷을 지원해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-019|
|**관련 TSR**|TSR-005, TSR-024|
|**관련 SIR**|N.A|

#### [PDE-014] BLK_DDR

|   |   |
|---|---|
|**Function**|APACHE5는 외부 DDR Memory Access를 위한 Controller를 내장해야 한다.|
|**Allocation**|HW / SW|
|**관련 TR**|TR-015|
|**관련 TSR**|TSR-002, TSR-005, TSR-024|
|**관련 SIR**|SIR-013|

[표 3] SYSTEM COMPONENT

### 시스템 내부 인터페이스 (System Internal Interface)

#### [PDI-001] AXI

|   |   |
|---|---|
|**구분**|**내용**|
|설명(Description)|이미지 데이터, 내부 엘리먼트 설정 값|
|From|BLK_BUS 내부 엘리먼트|
|To|내부 엘리먼트 BLK_BUS|

[표 4] AXI Interface

#### [PDI-002] AHB

|   |   |
|---|---|
|**구분**|**내용**|
|설명(Description)|내부 엘리먼트 설정 값|
|From|BLK_BUS 내부 엘리먼트|
|To|내부 엘리먼트 BLK_BUS|

[표 5] AHB Interface

#### [PDI-003] APB

|   |   |
|---|---|
|**구분**|**내용**|
|설명(Description)|내부 엘리먼트 설정 값|
|From|BLK_BUS 내부 엘리먼트|
|To|내부 엘리먼트 BLK_BUS|

[표 6] APB Interface

## 시스템의 논리적 설계 (System Logical Design)

### 기능 개요 (Functionalities Overview)

|   |   |   |   |
|---|---|---|---|
|ID|구분|System Functionalities|Remark|
|TR-001|Secure|TRNG, AES, HMAC, PKA||
|TR-002|MIPI_RX|MIPI RX||
|TR-003|ISP|ISP||
|TR-004|LDC|Lens Distortion Correction||
|TR-005|FRC|Frame Rate Control||
|TR-006|OF|Output Formatter||
|TR-007|MIPI_TX|MIPI TX||
|TR-008|Ethernet|Ethernet Encoder||
|TR-009|CNN|NPU||
|TR-010|CPU Platform|CPU||
|TR-011|Interrupt|Interrupt||
|TR-012|IO 제어|IO 제어||
|TR-013|CAN Vehicle Interface|CAN Protocol||
|TR-014|External Interface|Peripheral Interface||
|TR-015|DDRC|DDR Controller||
|TR-016|sFlash Memory IF|SPI, QSPI||
|TR-017|SD/eMMC|SD/eMMC||
|TR-018|UART|Debugger IP||
|TR-019|H.264 ENC|H.264 Encoder||
|TSR-001|ISP|Sync Monitoring||
|TSR-002|CPU Platform|Time-Out Check||
|TSR-003|CPU Platform|Plausibility Check||
|TSR-004|ISP|Redundant Enable Register||
|TSR-005|CPU Platform|Logic Error Monitoring||
|TSR-006|CPU Platform|Alive Check||
|TSR-007|MIPI|MIPI RX/TX Monitoring||
|TSR-008|CPU Platform|Data Plausibility check||
|TSR-009|External|External MIPI Data Monitoring||
|TSR-010|External|External Monitoring Pin||
|TSR-011|CPU Platform|Clock Monitoring||
|TSR-012|CPU Platform|Reset Monitoring||
|TSR-013|CPU Platform|Watch Dog Timer||
|TSR-014|CPU Platform|Redundant Timer||
|TSR-015|Secure|Secure Boot||
|TSR-016|CPU Platform|Interrupt Monitoring||
|TSR-017|CPU Platform|Internal Temp Monitoring||
|TSR-018|External|External Temp Monitoring||
|TSR-019|CPU Platform|Internal Volt Monitoring||
|TSR-020|External|External Volt Monitoring||
|TSR-021|CPU Platform|External Interface Readback||
|TSR-022|CPU Platform|Boot Sequence Monitoring||
|TSR-023|CPU Platform|Boot Retry||
|TSR-024|OIC|Bus Interface Monitoring||
|TSR-025|CPU Platform|Communication protocol||

[표 7] SYSTEM FUNCTION

### SECURE IP 지원 (SECURE Boot 포함)

키 암호화에는 매우 큰 숫자(ECC 연산의 경우 160~521비트, RSA 연산의 경우 1024~4096비트 이상)에 대한 복잡한 수학 연산이 필요하며, CPU는 32비트 및 64비트 값에 대한 작업으로 제한되므로 키 관련 알고리즘을 구현할 때 상당한 양의 계산 리소스가 필요하므로 가속기 역할을 하는 PKE-A를 지원해야 한다.

또한, 해시 값을 생성하기 위한 HMAC, 대칭형 암호화 알고리즘 지원을 위한 AES, 난수 값을 추측할 수 없게 하기 위한 TRNG도 지원해야 한다.

Boot은 Global Reset release 이후 CPU는 Instruction ROM 의 Boot code를 read하여 Secure boot 시퀀스를 수행한다.

Secure Boot Sequence

- Read key data in OTP
- Secure Initialization
- Read encryption SW code by SPI Controller
- Write SW code to RAM of Internal Memory Block
- Decryption by secure element

Internal Memory Blocks의 IROM은 read 되는 Boot code의 ECC를 체크하여 오류를 검출한다. CPU는 SPI를 설정하고 read-back test를 통해 SPI 설정 오류를 검출한다. CPU는 SPI를 통해 Serial NOR Flash의 암호화된 SW code를 Internal Memory Blocks의 IRAM에 ECC를 포함 시켜 write한다. CPU는 IRAM의 암호화된 SW code를 읽고 Secure에 전달한다. 이 때 IRAM은 Read되는 data의 ECC를 확인하고 RAM data에 대한 오류를 검출한다. Secure는 암호화된 SW code를 복호화하고 CPU는 복호화된 SW code를 IRAM에 저장한다. CPU는 Boot sequence flow을 모니터링하여 의도하지 않는 Boot sequence가 발생할 경우 오류를 발생한다. CPU는 오류가 발생하면 오류를 Safety Engine에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-001|BLK_SECURE|TRNG, AES, HMAC, PKA|PDE-006|
|TSR-015|BLK_SECURE|Secure Boot||
|TSR-003|BLK_SECURE|Plausibility Check||

[표 8] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 3.png>)

[그림 3] Security IP

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 4.png>)

[그림 4] ROM/RAM Block Diagram

#### Sequence diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 5.png>)

[그림 5] Secure Boot Sequence Diagram

### MIPI RX 데이터 오류 검출

외부 Image Sensor로부터 MIPI Interface를 통해 Bayer 데이터를 입력 받아 ISP Pipeline을 거쳐 가공된 영상을 MIPI TX로 출력해야 한다. 또한 오류 검출을 위해 Sync signal을 이용하여 Sync check를 수행, 약속된 시간 내에 sync가 검출되는 지를 검토하여 Sync check 오류 시 오류를 SE에 전달한다. 그리고 MIPI_RX 에서 발생하는 error register를 monitoring하여 error register가 발생 시 오류를 SE에 전달한다. 또한, Plausibility check 기능을 사용하여 내부 SRAM의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-002|BLK_VISION|MIPI_RX||
|SIR-001|BLK_VISION|MIPI CSI-2||
|TSR-007|BLK_VISION|MIPI RX/TX Monitoring||
|TSR-005|BLK_VISION|Logic Error Monitoring||

[표 9] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 6.png>)

[그림 6] MIPI Data

### ISP Data 처리 및 오류 검출

외부 Image Sensor로부터 MIPI Interface를 통해 Bayer 데이터를 입력 받아 Color Interpolation을 수행하여 RGB 데이터로 변환한다. RGB 데이터는 Color Space Conversion을 통해 YUV 데이터로 Conversion 가능해야 하고, Output Formatter를 통해 YC 데이터로 출력해야 한다. 또한 Mirror register를 사용하여 ISP Function enable register의 의도하지 않은 동작을 예방한다. 그리고 내부 test pattern 동작 check 기능을 사용하여 내부 로직의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-003|ISP|ISP||
|TSR-001|BLK_VISION|Sync Monitoring||
|TSR-003|BLK_VISION|Plausibility Check||
|TSR-004|BLK_VISION|Redundant Enable Register||
|TSR-005|BLK_VISION|Logic Error Monitoring||
|TSR-011|BLK_SCU|Clock Monitoring||

[표 10] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 7.png>)

[그림 7] ISP Pipeline

### LDC (Lens Distortion Correction) 동작 및 오류 검출

LDC (Lens Distortion Correction) element는 렌즈 왜곡 (Lens Distortion) 된 YC Data를 Look-Up Table (LUT)를 기반으로 왜곡을 보정한다. 오류 검출을 위해 LDC로부터 출력되는 sync signal을 이용하여 sync check를 수행, 약속된 시간 내에 sync가 검출되는 지를 검토하여 sync check 오류 시 오류를 SE에 전달한다. 그리고 내부 test pattern 동작 및 Plausibility check 기능을 사용하여 내부 로직과 SRAM의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-004|ISP|LDC||
|TSR-008|BLK_CPU|Data Plausibility Check||

[표 11] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 8.png>)

[그림 8] LDC Block Diagram

### FRC 지원 및 오류 검출

FRC (Frame Rate Control)는 NR로부터 받은 Bayer Data 혹은 LDC로부터 받은 YC Data를 Memory에 전달한다. 또한, FRC는 Bayer Data의 Frame Rate를 조절하거나 인식 결과와 YC Data의 동기를 맞추는 동작을 한다. 오류 검출을 위해 FRC로부터 출력되는 sync signal을 이용하여 sync check를 수행, 약속된 시간 내에 sync가 검출되는 지를 검토하여 sync check 오류 시 오류를 SE에 전달한다. 그리고 내부 test pattern 동작 및 Plausibility check 기능을 사용하여 내부 로직과 SRAM의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-005|FRC|Frame Rate Control||
|SIR-013|DDR|DDR Interface||
|TSR-001|BLK_VISION|Sync Monitoring||
|TSR-003|BLK_VISION|Plausibility Check||

[표 12] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 9.png>)

[그림 9] FRC location

### OF (Output Formatter) 동작 및 오류 검출

ISP는 Color Interpolation이후 YUV 영상을 만들기 위해 CSC(Color Space Conversion)를 수행해야 한다.

YUV로 변환한 데이터는 휘도(Y) 성분과 컬러(C)를 구분하여 영상을 처리해야 한다. 또한 데이터 손실을 없애기 위해 YUV444 Format을 사용해야 한다. 앞서 가공된 영상 데이터를 출력 형태에 맞춰 RGB888, BT1120, BT656 포맷 변환이 가능해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-006|ISP|Output Formatter||
|TSR-001|BLK_VISION|Sync Monitoring||

[표 13] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 10.png>)

[그림 10] Output Formatter

### MIPI TX 동작 및 오류 검출

MIPI TX는 ISP로부터 받은 YC 데이터, MIPI RX에서 ISP를 Bypass한 데이터를 HOST ECU가 인식 할 수 있는 형태인 MIPI 규격의 Serial Data로 변경하여 전달한다. 각각의 MIPI TX에서 발생하는 error register를 monitoring하여 error register가 발생 시 오류를 SE에 전달한다. 또한, Plausibility check 기능을 사용하여 내부 SRAM의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-007|MIPI TX|MIPI TX||
|SIR-002|MIPI TX|MIPI CSI-2 출력||
|TSR-007|BLK_VISION|MIPI RX/TX Monitoring||
|TSR-009|BLK_ICU, Host ECU|External MIPI Data Monitoring||
|TSR-005|BLK_VISION|Logic Error Monitoring||

[표 14] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 11.png>)

[그림 11] MIPI TX output

### Ethernet 동작 및 오류 검출

APACHE5는 Ethernet 인터페이스를 지원한다. 송수신 경로에 따라 big-endian, little-endian mode를 지원해야 하며, 10, 100 그리고 1000Mbps의 데이터 전송 속도도 지원한다. 또한, Plausibility check 기능을 사용하여 내부 SRAM의 데이터 오류를 검사하고, Logic Test를 수행하여 Logic 오류를 검출한다. 오류가 검출되면 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-008|Ethernet|Ethernet||
|SIR-011|Ethernet|Ethernet||
|TSR-025|BLK_PERI, BLK_HSP|Communication protocol||
|TSR-005|BLK_VISION, BLK_CNN, BLK_H264|Logic Error Monitoring||
|TSR-011|BLK_SCU|Clock Monitoring||
|TSR-002|BLK_PERI|Time-Out Check||

[표 15] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 12.png>)

[그림 12] Ethernet Block Diagram

### NPU 동작 및 오류 검출

APACHE5는 Neural Network Processing을 위한 NPU(Neural Network Processor Unit)를 제공한다. NPU는 Bus를 통하여 DDR에 있는 Neural Network Processing용 데이터와 이미지 데이터를 읽어와 처리하고 결과를 DDR에 저장한다. Plausibility check 기능을 사용하여 내부 SRAM의 데이터 오류를 검사하고, Logic Test를 수행하여 Logic 오류를 검출한다. 오류가 검출되면 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-009|NPU|NPU(Neural Network Processor Unit)||
|TSR-003|BLK_VISION|Plausibility Check||
|TSR-005|BLK_VISION, BLK_CNN, BLK_H264|Logic Error Monitoring||
|TSR-024|BLK_BUS, BLK_VISION, BLK_CNN, BLK_H264, BLK_DDR|Bus Interface Monitoring||
|TSR-011|BLK_SCU|Clock Monitoring||

[표 16] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 13.png>)

[그림 13] NPU Block Diagram

### CPU 동작 및 오류 검출

APACHE5는 내/외부 System을 Control 하기 위한 CPU를 제공해야 하며, Debugging을 위한 JTAG을 포함해야 한다. CPU는 AXI, AHB, APB Interface를 통해 모든 IP에 접근 가능해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-010|CPU Platform|CPU||
|TSR-003|BLK_SECURE, BLK_VISION|Plausibility Check||
|TSR-005|BLK_VISION, BLK_CNN, BLK_H264|Logic Error Monitoring||
|TSR-006|BLK_CPU, BLK_PERI|Alive Check||
|TSR-011|BLK_SCU, BLK_SAFETY|Clock Monitoring||
|TSR-013|BLK_CPU, BLK_PERI|Watch Dog Timer||
|TSR-022|BLK_CPU|Boot Sequence Monitoring||
|TSR-024|BLK_BUS, BLK_VISION, BLK_CNN, BLK_H264, BLK_DDR|Bus Interface Monitoring||
|TSR-001|BLK_VISION|Sync Monitoring||
|TSR-002|BLK_PERI|Time-Out Check||
|TSR-004|BLK_VISION|Redundant Enable Register||
|TSR-008|BLK_CPU|Data Plausibility check||
|TSR-016|BLK_PERI, BLK_GIC|Interrupt Monitoring||
|TSR-021|BLK_BUS, BLK_PERI, BLK_ICU|External Interface Readback||
|TSR-023|BLK_CPU|Boot Retry||
|TSR-015|BLK_SECURE|Secure Boot||
|TSR-017|BLK_ANALOG|Internal Temp Monitoring||
|TSR-019|BLK_ANALOG|Internal Volt Monitoring||

[표 17] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 14.png>)

[그림 14] CPU Block Diagram

### Interrupt 동작

APACHE5는 IP에서 전달되는 인터럽트에 대해 우선순위에 기반한 인터럽트 서비스를 처리 할 수 있어야 한다. Distributor 블록은 인터럽트 우선 순위 지정 및 시스템의 프로세서에 연결되는 CPU 인터페이스 블록에 대한 분배 동작을 수행해야 한다. CPU는 Interrupt Controller와 Timer를 설정하여 주기적인 Interrupt를 발생시키고 Timer 카운터와 비교하여 interrupt 오류를 검출한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-011|Interrupt|Interrupt||
|TSR-016|BLK_PERI, BLK_GIC|Interrupt Monitoring||

[표 18] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 15.png>)

[그림 15] Interrupt Block Diagram

### IO 제어

APACHE5는 Sensor를 Control하기 위해 GPIO를 이용한 Fsync Interface를 제공해야 한다. 또한 Sensor에 기본적으로 Reference Clock과 Reset을 제공할 수 있어야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-012|IO 제어|IO Control||
|SIR-004|SENSOR|SENSOR Reset||
|SIR-005|SENSOR|SENSOR Reference Clock||
|TSR-021|BLK_BUS, BLK_PERI, BLK_ICU|External Interface Readback||

[표 19] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 16.png>)

[그림 16] Interface between Sensor and APACHE5

### CAN(LIN) Interface

APACHE5는 ECU와 통신을 하기 위한 CAN Interface를 제공해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|Element|System Functionalities|Remark|
|TR-013|CAN|CAN Vehicle Interface||
|SIR-012|APACHE5|CAN/LIN Interface||
|TSR-025|BLK_PERI, BLK_HSP|Communication protocol||
|TSR-011|BLK_SCU|Clock Monitoring||

[표 20] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 17.png>)

[그림 17] CAN Block Diagram

### External Interface

APACHE5는 외부 CMOS Image Sensor를 포함한 외부 Device와의 Interface를 제공하여야 하며, Debugging을 위한 Interface도 포함시켜야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-014|APACHE5|External Interface||
|SIR-003|APACHE5|Communication Interface||
|SIR-006|APACHE5|Sensor I2C Interface||
|TSR-021|BLK_BUS, BLK_PERI, BLK_ICU|External Interface Readback||
|TSR-002|BLK_PERI|Time-Out Check||

[표 21] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 18.png>)

[그림 18] External Interface

### DDR Controller

APACHE5는 외부 LPDDR을 Control 하기 위한 DDR Controller를 제공해야 한다. 또한, Plausibility check 기능을 사용하여 내부 SRAM의 정상 여부를 주기적으로 판단, 오류 검출 시 오류를 SE에 전달한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-015|DDRC|DDR Controller||
|TSR-002|BLK_PERI|Time-Out Check||
|TSR-005|BLK_VISION, BLK_CNN, BLK_H264|Logic Error Monitoring||
|TSR-024|BLK_BUS, BLK_VISION, BLK_CNN, BLK_H264, BLK_DDR|Bus Interface Monitoring||
|TSR-011|BLK_SCU, BLK_SAFETY|Clock Monitoring||

[표 22] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 19.png>)

[그림 19] DDRC Block Diagram

### Flash Memory Interface 지원

APACHE5 시스템은 User Specific data를 Flash memory에 저장할 수 있다. Flash Memory와 통신하기 위해 Peripheral Interface에서는 SPI 혹은 QSPI를 지원해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-016|Flash|Flash Memory Interface||
|SIR-007|SPI|SPI Interface||
|TSR-002|BLK_PERI|Time-Out Check||
|TSR-011|BLK_SCU, BLK_SAFETY|Clock Monitoring||
|TSR-021|BLK_BUS, BLK_PERI, BLK_ICU|External Interface Readback||
|TSR-023|BLK_CPU|Boot Retry||
|TSR-008|BLK_CPU|Data Plausibility Check||

[표 23] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 20.png>)

[그림 20] Flash Memory Interface

### SD/eMMC 지원

APACHE5 시스템은 SD/eMMC 장치와 인터페이스하기 위한 SD Controller를 지원해야 하며, SDC는 SDIO 디지털 인터페이스/eMMC 5.1 프로토콜 및 SD-HCI Host 버전4 이하 모드를 모두 지원해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-017|SD/eMMC|SD/eMMC||
|SIR-014|SD/eMMC|SD/eMMC Interface||
|TSR-025|BLK_PERI, BLK_HSP|Communication protocol||
|TSR-002|BLK_PERI|Time-Out Check||
|TSR-005|BLK_VISION, BLK_CNN, BLK_H264|Logic Error Monitoring||
|TSR-008|BLK_CPU|Data Plausibility check||
|TSR-011|BLK_SCU, BLK_SAFETY|Clock Monitoring||

[표 24] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 21.png>)

[그림 21] SD/eMMC Block Diagram

### UART Interface 지원

APACHE5는 외부 ECU와 통신 및 Debugging을 하기 위한 Interface를 제공한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-018|UART|UART debugger||
|SIR-003|APACHE5|Communication Interface||

[표 25] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 22.png>)

[그림 22] UART Interface

### H.264 Encoder

APACHE5 시스템은 영상 처리된 데이터에 대한 H.264 형식의 비트스트림으로 인코딩을 지원해야 한다.

#### Allocation requirement

|   |   |   |   |
|---|---|---|---|
|ID|element|System Functionalities|Remark|
|TR-019|H264|H.264 Encoder||
|TSR-005|BLK_H264|Logic Error Monitoring||
|TSR-024|BLK_H264|Bus Interface Monitoring||
|TSR-011|BLK_SCU, BLK_SAFETY|Clock Monitoring||

[표 26] Allocation requirement

#### Internal block diagram

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 23.png>)

[그림 23] VPU Block Diagram

# 기술안전 컨셉 (Technical Safety Concept)

## [TSC-001] Video Sync 오류 검출

|   |   |
|---|---|
|목적|이미지 처리에 필요한 video sync에 대한 오류를 검출한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-001|
|관련 System Element|PDE-001(SW), PDE-009|

### [SM-12] Video sync counter

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|Video Sync 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.5 Analogue and digital I/O<br><br>* frame loss에 대한 mechanism coverage는 Medium 이나,  <br>Sync monitoring 은 Frame 포함 각 sync (H/V, Blank)도 검출하기 때문에  <br>coverage를 High로 산정함.|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 주기적으로 입력되는 영상을 처리하는 HW의 정상 동작을 보장하기 위해, 해당 HW에 입력혹은 출력되는 Video Sync의 무결성을 확인한다. Video Sync의 주기, 발생 유무 등이 미리 설정한 범위와 다를 경우, Video Sync 오류를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 24.png>)

[그림 24] Sync monitoring flow

## [TSC-002] 외부 Device Interface 오류 검출

|   |   |
|---|---|
|목적|APACHE5와 외부 device 간 interface의 오류를 검출한다.|
|Allocation|SW|
|관련 TSR|TSR-002, TSR-021|
|관련 System Element|PDE-001(SW), PDE-002, PDE-004, PDE-008, PDE-012, PDE-014|

### [SM-18] External Interface timeout

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|통신 인터페이스 오류 (timeout return 발생)|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.6 Communication bus (serial, parallel)|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 외부 device와의 통신 시, ACK 신호에 대한 return을 받는다. 일정 시간동안 외부 device의 ACK response가 없을 경우 time-out 에러로 판단하여, fault 신호를 SE에 전달한다. 필요에 따라 외부 device와의 통신을 재시도할 수 있다.

외부 device와의 interface 오류를 확인하기 위한 timeout flow는 다음과 같다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 25.png>)

[그림 25] Peripheral interface timeout

### [SM-19] External interface readback

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|통신 인터페이스 오류 (결과값 오류)|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.6 Communication bus (serial, parallel)|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 external device interface를 통해 외부 디바이스의 레지스터와 데이터를 제어한다. 외부 디바이스 제어 시 write한 address 값을 다시 read하여, 의도한 값이 레지스터 및 메모리에 올바르게 적용되었는지 확인한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 26.png>)

[그림 26] External interface readback

## [TSC-003] Boot-up 오류 검출 및 대응

|   |   |
|---|---|
|목적|Boot-up 중에 발생한 오류를 검출하여, 정상적인 boot-up을 보장한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-003, TSR-015, TSR-022, TSR-023|
|관련 System Element|PDE-001(SW), PDE-003, PDE-006|

### [SM-01] IROM/IRAM ECC

|   |   |
|---|---|
|**구현파트**|HW/SW|
|**Failure Mode**|Memory, Data 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-11, 5-1 Digital components and memories 표 32 Non-volatile memory|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

- **IROM**

IROM에 저장되어 있는 boot code의 무결성을 확인하기 위하여 HW에서 ECC 기능을 수행한다.

- **IRAM**

외부 저장장치에 저장되어 있는 application image가 IRAM으로 load되는 과정에서 데이터 무결성을 확인해야 한다. Application image 생성 시, 무결성 정보는 파일에 함께 포함되어야 한다. BL의 수행 과정에서 CRC, Hash 등의 알고리즘을 사용하여 ATF, RTOS Kernel, Application의 무결성을 확인해야 한다.

### [SM-02] Secure Boot

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|key authentication failed|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

암호화 알고리즘을 이용한 binary의 암호화와 binary 내용에 대한 HASH 값을 이용하여 무결성 검증을 수행한다. BL 및 application source의 build 과정에서 Encrypted image가 생성되도록 한다.

부팅 시 BL은 Encrypted Application Image의 Integrity를 검사하여 Image가 오염되지 않았는지 확인한다.만약 오염되었다면 Application을 실행하지 않고 Boot Fail을 SE에 전달한다.

### [SM-03] Boot Sequence monitor

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|Wrong Execution|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 BL1(IROM) → BL2(IRAM) → Application 순으로 동작한다. BL은 boot-up sequence 주요 시점마다 실행되는 함수의 상태를 저장하여, 각 함수가 정해진 순서에 맞게 정상적으로 수행되었는지 최종 단계에서 확인한다.

Boot sequence에 대한 예시는 다음과 같다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 27.png>)

[그림 27] Example of boot sequence monitor

### [SM-04] Backup Boot

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|Wrong Execution, Application image load 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-11, 5-1.12 Table 32 — Non-volatile memory|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5의 BL2 image와 application image는 외부저장장치(eMMC/Serial Flash Memory)의 서로 다른 영역에 이중으로 저장되어야 한다. 1st 영역에 저장된 image를 load하여 boot-up 도중 오류 발생 시, backup(2nd) 영역에 있는 image로 boot-up을 재시도한다. 2nd boot-up도 fail일 경우, safe state로 진입한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 28.png>)

[그림 28] Backup boot flow

## [TSC-004] Register 오 동작 방지

|   |   |
|---|---|
|목적|특정 기능을 enable 하는 register의 오 동작을 방지한다.|
|Allocation|HW|
|관련 TSR|TSR-004|
|관련 System Element|PDE-001(SW), PDE-009|

### [SM-07] Mirror register

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|Register 오 동작|
|**상태 천이**|N/A|
|**FHTI**|Detection SM이 아님|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5의 ISP block 내, video output format 및 튜닝 레지스터들은 영상 출력에 큰 영향을 미칠 수 있다. 이러한 레지스터들의 오동작 방지를 위해 mirror register를 적용하여야 한다.

Mirror register가 적용된 레지스터는 mirror register와 enable register를 동일하게 제어할 경우에만 레지스터 값이 영상에 반영된다. Enable register만 제어할 경우, 레지스터 값은 변경되지만 영상에는 반영되지 않는다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 29.png>)

[그림 29] Mirror register

## [TSC-005] IP Logic 오류 검출

|   |   |
|---|---|
|목적|IP의 logic 오류를 검출한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-005, TSR-007|
|관련 System Element|PDE-001(SW), PDE-008, PDE-009, PDE-011, PDE-012, PDE-013, PDE-014|

### [SM-16] Test pattern injection

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|Logic 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.4 Processing Units|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5 내부 block들의 logic이 정상적으로 동작하는지 확인하기 위해, Test Pattern Injection을 수행한다.

- **ISP**

영상이 실려있지 않은 idle time (vertical blanking)에 test pattern을 입력하여 CRC 값을 계산하고, 미리 설정한 CRC 값(golden value)과 비교하여 logic의 정상 동작을 확인한다. CRC 값이 서로 다를 경우 fault를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 30.png>)

[그림 30] Test pattern injection (ISP)

- **VCODEC / NPU**

SW에서 의도된 입력 영상을 주입하고, 출력된 압축 데이터를 골든 데이터와 비교하여 logic의 정상 동작을 확인한다. 데이터가 서로 다를 경우 fault를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 31.png>)

[그림 31] Test pattern injection (VCODEC / NPU)

### [SM-09] IP Fault control

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|Integrated HW IP 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.4 Processing Units|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

기본적인 기능들을 수행하는 logic IP 들은 해당 기능을 수행하면서 수행 과정에 발행하는 에러들에 대해서 configuration register 에 에러 상태를 업데이트 한다. IP 마다 다양한 형태의 failure mode 들이 있으며 기능 안전에 영향을 미치는지 여부는 user application 에 따라 달라질 수 있다. SW 는 configuration error register 를 모니터링하여 safety goal 에 영향을 미치는 에러 감지시 이를 SE에 전달한다.

### [SM-11] MIPI RX monitor

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|MIPI RX HW IP 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.4 Processing Units|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

MIPI RX block 내부의 error state register와 interrupt mask register를 이용하여, MIPI RX block 오류를 감지한다. 필요 시 인터럽트를 발생시키고 fault를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 32.png>)

[그림 32] MIPI RX monitor

## [TSC-006] Standard Communication Protocol

|   |   |
|---|---|
|목적|표준화된 통신 프로토콜을 사용하여 통신의 안정성을 보장한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-025|
|관련 System Element|PDE-008, PDE-012|

### [SM-20] Communication controllers

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|통신 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.6 Communication bus (serial, parallel)|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

대역폭이 큰 통신 컨트롤러의 경우, 통신 프로토콜 frame 안에 통신의 안정성과 데이터의 무결성 확보를 위해 checksum, CRC와 같은 에러 검출 패킷이 포함되어 있다. APACHE5는 이러한 에러 검출 패킷을 모니터링하여, 에러 발생 시 fault를 SE에 전달한다.

대표적으로 사용되는 외부 통신 별 에러 검출 패킷에 대한 정보는 다음과 같다. (CAN, LIN, Ethernet, QSPI)

Application Level에서는 추가적으로 강화된 E2E Protocol을 적용하여 Data의 무결성을 보장한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 33.png>)

[그림 33] CAN frame format

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 34.png>)

[그림 34] LIN frame format

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 35.png>)

[그림 35] Ethernet frame format

## [TSC-007] Memory 오류 검출 및 보정

|   |   |
|---|---|
|목적|Memory의 오류를 검출하고, 저장된 data의 무결성을 확보한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-003|
|관련 System Element|PDE-009, PDE-011|

### [SM-10] SRAM integrity (ECC, CRC)

|   |   |
|---|---|
|**구현파트**|HW/SW|
|**Failure Mode**|Memory, Data 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-11, 5-1 Digital components and memories 표 33 volatile memory|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

시스템 내부 SRAM의 데이터 무결성을 확보하기 위하여 ECC, CRC 검사를 수행하여 데이터의 의도치 않은 bit flip을 보정하거나 검출한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 36.png>)

[그림 36] SRAM ECC

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 37.png>)

[그림 37] SRAM CRC

## [TSC-008] Data 무결성 검사

|   |   |
|---|---|
|목적|외부 저장장치 또는 외부에서 입력되는 data에 대한 무결성을 확보한다.|
|Allocation|SW|
|관련 TSR|TSR-008|
|관련 System Element|PDE-001(SW), PDE-Ext(Host ECU)|

### [SM-14] Data integrity check

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|Data 오류|
|**상태 천이**|Safe State|
|**FHTI**|N/A|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.6 Communication bus (serial, parallel)|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

외부 저장소에 저장된 binary data를 load할 때, 데이터에 포함되어 있는 check data(CRC, checksum)를 통해 load된 데이터의 무결성을 확인한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 38.png>)

[그림 38] Data integrity check

## [TSC-009] Bus 오류 검출

|   |   |
|---|---|
|목적|Bus를 통해 내부 IP의 오류를 전달한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-024|
|관련 System Element|PDE-001(SW), PDE-002, PDE-009, PDE-011, PDE-013, PDE-014|

### [SM-17] OIC

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|HW IP 및 내부 인터페이스 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.4 Processing Units|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

OIC(Orbit Interconnect)를 통해 연결된 IP들의 동작 상태를 HW 레벨에서 실시간으로 확인할 수 있다. 연결된 IP에 error 발생 시 인터럽트를 발생시킨다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 39.png>)

[그림 39] OIC

## [TSC-010] 안정적인 클럭 생성 및 오류 검출

|   |   |
|---|---|
|목적|클럭이 안정적으로 생성되어야 하며, 생성된 클럭이 정의된 주파수와 일치하지 않을 경우 클럭 오류를 검출한다.<br><br>필요할 경우 클럭 변경시 발생할 수 있는 주파수 오류를 방지할 수 있는 방안을 강구한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-011|
|관련 System Element|PDE-001(SW), PDE-003, PDE-005|

### [SM-08] Clock monitor (구. Clock Monitoring)

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|PLL, clock 오류|
|**상태 천이**|Safe State|
|**FHTI**|Immediately|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

CPU의 SYS SW가 PLL Clock, 내부 Clock을 설정한다. Safety SW는 설정된 PLL Clock, 내부 Clock을 모니터링하기 위해 Clock monitor를 설정한 후 Clock monitor를 enable한다. Clock monitor는 설정된 clock 주파수를 모니터링하고 의도하지 않는 주파수가 검출되면 fault 신호를 SE에게 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 40.png>)

[그림 40] Clock monitoring flow

## [TSC-011] Reset 오류 검출

|   |   |
|---|---|
|목적|리셋 신호의 릴리즈 상태가 정해진 순서와 일치하지 않을 경우 오류를 검출한다.|
|Allocation|HW|
|관련 TSR|TSR-012|
|관련 System Element|PDE-003, PDE-004|

### [SM-05] Reset sequence monitor (구. Reset Sequence Monitoring)

|   |   |
|---|---|
|**구현 파트**|HW|
|**Failure Mode**|Wrong Execution|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Program Sequence Monitoring|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

Reset Gen.은 System reset이 release되면 APB, AXI,CPU reset을 순차적으로 release한다. System reset 과정에서 APB, AXI, CPU가 의도된 순서로 release 되었는지 확인하여, 의도되지 않은 순서로 release될 경우 fault 신호를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 41.png>)

[그림 41] Reset sequence

## [TSC-012] CPU 동작 오류 검출

|   |   |
|---|---|
|목적|SW가 정상 동작하는지 WDT를 이용하여 오류를 검출한다.|
|Allocation|HW, SW|
|관련 TSR|TSR-013|
|관련 System Element|PDE-001(SW), PDE-008|

### [SM-15] Watchdog Timer

|   |   |
|---|---|
|**구현 파트**|HW, SW|
|**Failure Mode**|CPU 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|90(Medium)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.8 Programme sequence monitoring/Clock|
|**S.M Type**|다중점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

Watchdog 기능을 활성화하여 WDT count 값을 주기적으로 업데이트한다. 만약 WDT count refresh가 수행되지 않을 경우, fault를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 42.png>)

[그림 42] Watchdog Timer

## [TSC-013] Timer 오류 검출

|   |   |
|---|---|
|목적|Timer의 오류를 검출한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-014|
|관련 System Element|PDE-008|

### [SM-06] Redundant timer

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|Timer 동작 오류|
|**상태 천이**|Safe State|
|**FHTI**|Immediately|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.4 Processing Units|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

Redundant timer는 original timer와 1-cycle 차이 나는 count 값을 가진다. 만약 redundant timer와 original timer의 차이가 1-cycle이 아닐 경우 fault 신호를 SE에 전달한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 43.png>)

[그림 43] Redundancy Timer flow

## [TSC-014] Voltage/Temperature 안정성 확인

|   |   |
|---|---|
|목적|전압 및 온도가 정상 범위 내에 있는지 주기적으로 확인하여 APACHE5 운용환경의 안정성을 보장한다.|
|Allocation|HW/SW|
|관련 TSR|TSR-017, TSR-019|
|관련 System Element|PDE-001(SW), PDE-007|

### [SM-21] Internal voltage monitor

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|내부 전압 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|60(Low)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.7 Power supply|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 core의 전압을 sensing하여 전압 값을 register에 업데이트한다. SW는 해당 레지스터를 통해 내부 전압이 안정적인지 확인한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 44.png>)

[그림 44] Internal Voltage Sensor flow

### [SM-22] Internal Temperature monitor

|   |   |
|---|---|
|**구현 파트**|HW/SW|
|**Failure Mode**|내부 온도 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|60(Low)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.7 Power supply<br><br>* Temperature 관련 reference가 없어서, Voltage monitor와 동일하게 적용.|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 chip의 온도를 sensing하여 온도 값을 register에 업데이트한다. SW는 해당 레지스터를 통해 내부 온도가 operation range(-40℃ ~ +120℃)를 벗어나는지 모니터링한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 45.png>)

[그림 45] Temperature Sensor flow

## [TSC-015] Interrupt 오류 검출

|   |   |
|---|---|
|목적|Interrupt의 오류를 검출한다|
|Allocation|SW|
|관련 TSR|TSR-016|
|관련 System Element|PDE-001(SW), PDE-008, PDE-010|

### [SM-13] Interrupt monitor

|   |   |
|---|---|
|**구현 파트**|SW|
|**Failure Mode**|내부 로직 고장|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.5 Analogue and digital I/O|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

입력 받은 영상의 vertical sync와 timer를 이용하여, interrupt controller의 정상 동작을 확인해야 한다.

- **Timer**

1ms마다 값을 count한다.

- **Vsync**

GIC에서 생성된 vsync interrupt를 통해 timer count 값을 0으로 reset 한다. 만약 count 값이 Vsync 주기(33.3ms)를 초과할 경우, interrupt controller의 고장으로 간주한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 46.png>)

[그림 46] Interrupt monitor

## [TSC-016] System 안정성 확인

|   |   |
|---|---|
|목적|APACHE5 시스템의 입/출력 및 환경을 모니터링하여 application system의 안정성을 확보한다.|
|Allocation|HW/SW/External|
|관련 TSR|TSR-006, TSR-009, TSR-010, TSR-018, TSR-020|
|관련 System Element|PDE-001(SW), PDE-004, PDE-005, PDE-008, PDE-Ext(Host ECU)|

### [SM-91] State monitor

|   |   |
|---|---|
|**구현 파트**|HW/SW/External|
|**Failure Mode**|APACHE5 상태 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.3 Electrical elements|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

- **APACHE5**

APACHE5는 2개의 GPIO 핀을 이용하여 시스템 내부의 상태를 출력한다. System reset, normal operation, safe state 3가지 상태에 대해 FAULT_P, FAULT_N 핀으로 differential level 출력을 표시하며, 3가지 상태에 따른 pin의 출력 mode 및 signal은 다음과 같다.

|   |   |   |   |
|---|---|---|---|
||**system reset**|**normal operation**|**safe state**|
|FAULT_P|LOW|LOW|HIGH|
|FAULT_N|LOW|HIGH|LOW|

[표 27] GPIO Fault P/N mode

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 47.png>)

[그림 47] GPIO Fault P/N signal

또한, 외부 ECU가 APACHE5 operation status를 확인할 수 있도록, APACHE5는 I2C slave mode를 지원하여야 한다.

- **외부 ECU**

외부 ECU는 APACHE5에서 출력되는 differential signal(Fault_P/N pin)을 통해 APACHE5의 operation status를 확인할 수 있다. 또한 I2C(master)를 통해 APACHE5의 safe state register에 접근하여 APACHE5 내부 상태를 확인할 수 있다.

### [SM-92] External Watchdog

|   |   |
|---|---|
|**구현 파트**|SW/External (App 구현으로써 AoU에 할당함)|
|**Failure Mode**|APACHE5 내부 상태 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.3 Electrical elements|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

APACHE5는 내부 timer를 이용하여 일정 주기마다 GPIO port의 출력을 toggling하여 PWM 신호를 출력한다. 외부 ECU는 APACHE5의 출력 신호를 캡처하여 주기가 일정한지 모니터링하여 APACHE5의 정상 동작 여부를 확인한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 48.png>)

[그림 48] External Watchdog

### [SM-93] Voltage Monitor

|   |   |
|---|---|
|**구현 파트**|External|
|**Failure Mode**|APACHE5 입력 전압 오류|
|**상태 천이**|N/A|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.7 Power supply|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

외부 ECU는 APACHE5에 공급되는 외부 전압이 정상 동작 범위 내에서 동일한 레벨을 유지하고 있는지 모니터링해야 한다.

### [SM-94] Board temperature monitor

|   |   |
|---|---|
|**구현 파트**|External|
|**Failure Mode**|APACHE5 보드 온도 오류|
|**상태 천이**|N/A|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.7 Power supply|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

외부 ECU는 board의 온도가 정상 동작 범위를 유지하고 있는지 모니터링해야 한다. APACHE5의 동작 온도는 -40℃ ~ +105℃ 이다. (AEC-Q100 Grade 2 기준)

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 49.png>)

[그림 49] Temperature sensor flow (Host ECU)

### [SM-95] MIPI output monitor (구. MIPI TX Output Monitoring)

|   |   |
|---|---|
|**구현 파트**|External|
|**Failure Mode**|MIPI output data 오류|
|**상태 천이**|N/A|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.3 Electrical elements|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

외부 ECU는 APACHE5에서 출력되는 MIPI data가 MIPI CSI2 interface spec.에 따라 출력되는지 모니터링하여 MIPI output data의 무결성을 확인해야 한다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 50.png>)

[그림 50] MIPI output monitor

### [SM-96] Alive check

|   |   |
|---|---|
|**구현 파트**|SW/External (App 구현으로써 AoU에 할당함)|
|**Failure Mode**|APACHE5 내부 상태 오류|
|**상태 천이**|Safe State|
|**FHTI**|66-ms|
|**D.C(%)**|99(High)|
|**D.C 산출의 근거**|ISO26262-5, Annex D 표 D.3 Electrical elements|
|**S.M Type**|단일점 결함을 막는 안전 메커니즘|

#### 상세 구현 방안(Implementation approach in detail)

호스트 ECU는 주기적으로 외부 인터페이스(예: I2C, SPI)를 통해 APACHE5에 쿼리합니다. 쿼리를 받으면 APACHE5는 쿼리를 실행하고 결과를 호스트 ECU에 반환합니다. 그러면 호스트 ECU는 APACHE5에서 받은 결과를 내부적으로 계산한 자체 결과와 비교합니다. 이 비교를 통해 호스트 ECU는 APACHE5의 CPU가 제대로 작동하는지 확인할 수 있습니다.

![APACHE5_NC_ENTS_T04_시스템 설계서](<APACHE5_NC_ENTS_T04_시스템 설계서 51.png>)

[그림 51] External Watchdog

# 할당된 정량적 목표(Quantitative Goal)

## 하드웨어 아키텍처 메트릭 (HW Architecture Metric)

APACHE5 시스템은 ASIL B 로 개발되고 SPFM: 90%, LFM: 60%을 목표로 한다.

## PMHF

APACHE5 시스템은 ASIL B 로 개발되고 ITEM 목표 값 PMHF 100FIT의 10%인 PMHF 10FIT를 목표로 한다.

# 설계 제약 사항 (Design Constraint)

## [const-001] Use Case

APACHE5 는 SEooC에 가정을 기반으로 개발되었기 때문에 APACHE5를 사용하는 User는 해당 시스템의 Application에 맞게 다시 분석하여야 한다.

## [const-002] Frame rate

APACHE5 는 ISP가 최소 30 fps 이상으로 동작하는 시스템을 가정하여 Malfunction을 분석하였기 때문에 다른 시스템으로 활용 시 FHTI를 만족하지 못할 수 있다. 따라서 사용하는 User 는 시스템의 frame rate에 맞게 Safety mechanism 을 분석해야 한다.

## [const-003] Power

APACHE5 에 공급되는 외부 전압은 전압 모니터링과 같은 외부 수단에 의해 오류를 검출할 수 있어야 한다.

## [const-004] Temperature

APACHE5 는 정해진 온도 조건에서만 정상 동작을 보장하며, APACHE5의 동작 온도 조건은 외부 수단에 의해 모니터링되어야 한다.

## [const-005] Clock 및 Reset 조건

APACHE5 로 공급되는 reset 은 안정된 clock 이 최소 한번 이상 toggle 된 이후 release 되어야 한다.

Reset 이 release 되어 있는 상태에서 안정된 clock 이 지속적으로 공급되어야 하며, 만약 clock 이 변경되는 경우 reset 상태에서 이루어져야 한다. 동작 중에 clock 이 변경되는 경우 의도치 않은 영상 혹은 sync 가 1 frame 이상 출력될 수 있다. 이 경우 APACHE5 의 외부 시스템에서는 APACHE5 에 공급되는 clock을 monitoring 하여 APACHE5 의 interrupt 혹은 safety 관련 Register 값을 clear 해 주어야 한다.

## [const-006] J-TAG Debugger

user의 Debug 편의성을 제공하기 위한 용도임. (Not safety related)

## [const-007] ADC

user의 Application 구현을 위한 Option 기능을 제공하기 위한 용도임. (Not safety related)

## [const-008] UART

user의 Debug 편의성을 제공하기 위한 용도임. (Not safety related)