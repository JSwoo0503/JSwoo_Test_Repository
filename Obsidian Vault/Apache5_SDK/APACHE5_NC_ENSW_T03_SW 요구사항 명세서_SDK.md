**APACHE5**

|   |
|---|
|SW 요구사항 명세서 SDK|
|SW Requirements Specification|

|   |   |   |   |
|---|---|---|---|
|Release V 1.0|   |   |   |
|작성|   |승인|   |
|SoCSW|서승범|연구소|천이우|
|![APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK](<APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK.png>)|   |![APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK](<APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK 1.png>)|   |

![APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK](<APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK.jpeg>)

**수정이력(Revision History)**

|   |   |   |   |
|---|---|---|---|
|날짜|버전|작성자|수정내용|
|2021.07.21|V0.1|서승범|요구사항 명세서 작성|
|2021.08.10|V1.0|서승범|검증 검토 결과 반영|
|||||
|||||
|||||
|||||
|||||

목차(Index)

[1. 개요(Overview) 6](#_Toc207200203)

[1.1. 목적(Purpose) 6](#_Toc207200204)

[1.2. 적용 범위(Scope) 6](#_Toc207200205)

[2. 시스템 설명(System Description) 7](#_Toc207200206)

[2.1. 시스템 목적(System Purpose) 7](#_Toc207200207)

[2.2. 시스템 구조(System Structure) 7](#_Toc207200208)

[2.3. 시스템 주요 기능(System Main Functions) 7](#_Toc207200209)

[3. SW 개요(Software Overview) 7](#_Toc207200210)

[3.1. SW 구조도(Software Structure) 7](#_Toc207200211)

[4. 요구사항 개요(Requirements Overview) 9](#_Toc207200212)

[4.1. 요구사항 식별자(Requirements Identification) 9](#_Toc207200213)

[4.2. 요구사항 중요도(Requirements Priority) 10](#_Toc207200214)

[4.3. 요구사항 요약(Requirements List) 10](#_Toc207200215)

[5. 기능 요구사항(Functional Requirements) 12](#_Toc207200216)

[5.1. [SR-SoC-CNN-001] CNN 동작 설정 12](#_Toc207200217)

[5.2. [SR-SoC-CNN-002] CNN Inference 수행 13](#_Toc207200218)

[5.3. [SR-SoC-VDMA_CNN-001] VDMA CNN 설정 13](#_Toc207200219)

[5.4. [SR-SoC-VDMA_CNN-002] VDMA CNN 동작 시작 13](#_Toc207200220)

[5.5. [SR-SoC-VDMA_CNN-003] VDMA CNN 동작 중지 14](#_Toc207200221)

[5.6. [SR-SoC-VDMA_H264-001] VDMA H264 설정 14](#_Toc207200222)

[5.7. [SR-SoC-VDMA_H264-002] VDMA H264 동작 시작 15](#_Toc207200223)

[5.8. [SR-SoC-VDMA_H264-003] VDMA H264 동작 중지 15](#_Toc207200224)

[5.9. [SR-SoC-I2C-001] I2C 설정 16](#_Toc207200225)

[5.10. [SR-SoC-I2C-002] I2C Master 모드의 Data Read/Write 16](#_Toc207200226)

[5.11. [SR-SoC-LIN-001] LIN 설정 17](#_Toc207200227)

[5.12. [SR-SoC-LIN-002] LIN Data의 송/수신 17](#_Toc207200228)

[5.13. [SR-SoC-PWM-001] PWM 설정 17](#_Toc207200229)

[5.14. [SR-SoC-PWM-002] PWM 동작 시작 18](#_Toc207200230)

[5.15. [SR-SoC-PWM-003] PWM 동작 중지 18](#_Toc207200231)

[5.16. [SR-SoC-SPI-001] SPI 설정 19](#_Toc207200232)

[5.17. [SR-SoC-SPI-002] SPI Master 모드 Data Read/Write 19](#_Toc207200233)

[5.18. [SR-SoC-SF-001] SF 초기화 20](#_Toc207200234)

[5.19. [SR-SoC-SF-002] SF Data Read/Write 20](#_Toc207200235)

[5.20. [SR-SoC-SF-003] SF Data Erase 21](#_Toc207200236)

[5.21. [SR-SoC-ADC-001] ADC 초기화 21](#_Toc207200237)

[5.22. [SR-SoC-ADC-002] ADC Data Read 21](#_Toc207200238)

[5.23. [SR-SoC-CAN-001] CAN 설정 22](#_Toc207200239)

[5.24. [SR-SoC-CAN-002] CAN Data 송/수신 22](#_Toc207200240)

[5.25. [SR-SoC-TS-001] Read TS Data 23](#_Toc207200241)

[5.26. [SR-SoC-SYS-001] PLL 설정 23](#_Toc207200242)

[5.27. [SR-SoC-SYS-002] CMA Buffer 설정 24](#_Toc207200243)

[5.28. [SR-SoC-SYS-003] System Reset 24](#_Toc207200244)

[5.29. [SR-SoC-NCLD-001] 압축 이미지 로딩 24](#_Toc207200245)

[5.30. [SR-SoC-DMA-001] DMA Data 전송 25](#_Toc207200246)

[5.31. [SR-SoC-H264ENC-001] H264 Encoder 설정 25](#_Toc207200247)

[5.32. [SR-SoC-H264ENC-002] H264 Encoder 동작 26](#_Toc207200248)

[5.33. [SR-SoC-MMC-001] MMC 초기화 26](#_Toc207200249)

[5.34. [SR-SoC-MMC-002] MMC Data Read/Write 27](#_Toc207200250)

[5.35. [SR-SoC-INI-001] Configuration Load 27](#_Toc207200251)

[5.36. [SR-SoC-OSAL-001] Create Message Queue 28](#_Toc207200252)

[5.37. [SR-SoC-OSAL-002] Create Thread 28](#_Toc207200253)

[5.38. [SR-SoC-GRAPHICS-001] 포멧 변환 28](#_Toc207200254)

[5.39. [SR-SoC-GRAPHICS-002] 해상도 변환 29](#_Toc207200255)

[5.40. [SR-SoC-GRAPHICS-003] Rotation 29](#_Toc207200256)

[5.41. [SR-SoC-GRAPHICS-004] Overlay Mix 30](#_Toc207200257)

[5.42. [SR-SoC-UART-001] UART 설정 30](#_Toc207200258)

[5.43. [SR-SoC-UART-002] UART Data 송/수신 31](#_Toc207200259)

[5.44. [SR-SoC-BUFF-001] Data Buffer의 생성과 제어 31](#_Toc207200260)

[5.45. [SR-SoC-NCLDH-001] NC Loader의 File 제어 32](#_Toc207200261)

[5.46. [SR-SoC-PVT-001] PVT 센서의 제어 32](#_Toc207200262)

[6. 기능안전 요구사항(Functional Safety Requirement) 33](#_Toc207200263)

[6.1. [SSR-SoC-NPUM-001] NPU 설정 33](#_Toc207200264)

[6.2. [SSR-SoC-NPUM-002] NPU 오류 검출 33](#_Toc207200265)

[6.3. [SSR-SoC-WDT-001] CPU Monitoring 설정 34](#_Toc207200266)

[6.4. [SSR-SoC-WDT-002] CPU Monitoring 오류 검출 34](#_Toc207200267)

[6.5. [SSR-SoC-STM-001] Safety Mechanism 설정 35](#_Toc207200268)

[6.6. [SSR-SoC-STM-002] Safety Task 동작 확인 35](#_Toc207200269)

[6.7. [SSR-SoC-SE-001] SE 설정 36](#_Toc207200270)

[6.8. [SSR-SoC-SE-002] Check Fault Signal 36](#_Toc207200271)

[6.9. [SSR-SoC-CC-001] Communication Control 오류 검출 37](#_Toc207200272)

[6.10. [SSR-SoC-CM-001] Clock Monitoring 설정 38](#_Toc207200273)

[6.11. [SSR-SoC-CM-002] Clock Monitoring 오류 검출 38](#_Toc207200274)

[6.12. [SSR-SoC-IFRB-001] Read Back 오류 검출 39](#_Toc207200275)

[6.13. [SSR-SoC-IFTO-001] Time Out 오류 검출 39](#_Toc207200276)

[6.14. [SSR-SoC-MI-001] Memory Integrity Check 설정 40](#_Toc207200277)

[6.15. [SSR-SoC-MI-002] Memory Integrity Check 오류 검출 40](#_Toc207200278)

[6.16. [SSR-SoC-RDT-001] RDT 설정 41](#_Toc207200279)

[6.17. [SSR-SoC-RDT-002] RDT 오류 검출 41](#_Toc207200280)

[6.18. [SSR-SoC-VM-001] Voltage Monitoring 설정 42](#_Toc207200281)

[6.19. [SSR-SoC-VM-002] Voltage Monitoring 오류 검출 42](#_Toc207200282)

[6.20. [SSR-SoC-TM-001] Temperature Monitoring 설정 43](#_Toc207200283)

[6.21. [SSR-SoC-TM-002] Temperature Monitoring 오류 검출 43](#_Toc207200284)

[6.22. [SSR-SoC-FM-001] Fault Monitoring 설정 44](#_Toc207200285)

[6.23. [SSR-SoC-FM-002] Fault Monitoring 오류 검출 45](#_Toc207200286)

[6.24. [SSR-SoC-OIC-001] OIC CPU 오류 검출 45](#_Toc207200287)

[6.25. [SSR-SoC-OIC-002] OIC CNN 오류 검출 46](#_Toc207200288)

[6.26. [SSR-SoC-OIC-003] OIC H264 오류 검출 46](#_Toc207200289)

[6.27. [SSR-SoC-OIC-004] OIC DDR 오류 검출 47](#_Toc207200290)

[6.28. [SSR-SoC-H264SM-001] H264 Encoder Monitoring 오류 검출 47](#_Toc207200291)

[7. 성능 요구사항(Performance Requirements) 48](#_Toc207200292)

[7.1. [SNR-SoC-SDK-001] Boot UP Time 48](#_Toc207200293)

[8. 자원 요구사항(Resource Requirements) 48](#_Toc207200294)

[8.1. [SNR-SoC-SDK-002] Memory Usage 48](#_Toc207200295)

[8.2. [SNR-SoC-SDK-003] CPU Usage 49](#_Toc207200296)

[9. 개발 제약 사항(Development Constraints) 49](#_Toc207200297)

표(Table)

[[표 1] 소프트웨어 주요 기능 9](#_Toc207200298)

[[표 2] 요구사항 식별자 규칙 10](#_Toc207200299)

[[표 3] 요구사항 중요도 기준 10](#_Toc207200300)

[[표 4] 요구사항 개요 12](#_Toc207200301)

그림(Figure)

[[그림 1] APACHE5 시스템 7](#_Toc207200302)

[[그림 2] APACHE5 SDK Package Diagram 8](#_Toc207200303)

# 개요(Overview)

## 목적(Purpose)

SW 요구사항 명세서는 시스템 및 이해관계자 요구사항을 SW 요구사항으로 변환하여 SW 설계를 위한 요구사항 명세를 제공하고, SW 검증 기준을 제공하기 위함이다.

## 적용 범위(Scope)

SW 요구사항 명세서는 당사의 SW 개발 프로젝트의 SW 요구사항 명세에 적용하도록 한다_._

# 시스템 설명(System Description)

## 시스템 목적(System Purpose)

APACHE5 시스템은 ADAS 시스템에서 Multi-channel 고화질 영상을 입력받아 이미지 데이터를 가공하고 처리하며 Deep learning 기반의 영상 인식과 자동 발렛 주차용 영상 처리 역할을 수행한다. 그리고, 가공처리된 이미지 데이터나 인식 결과를 다른 ECU로 송출하는 역할을 수행한다.

## 시스템 구조(System Structure)

APACHE5 시스템은 CMOS 이미지 센서로부터 입력된 디지털 이미지 데이터를 입력 받아 ISP Pipeline을 거친 영상 데이터 및 Deep learning 기반의 영상 인식 데이터를 ECU에 송출하는 것을 범위로 한다.

![APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK](<APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK 2.png>)

[그림 1] APACHE5 시스템

## 시스템 주요 기능(System Main Functions)

APACHE5는 시스템은 화질 개선 등의 목적으로 이미지 데이터를 가공하는 ISP(Image Signal Processor), 외부에서 입력되는 clock, reset, power를 가공 및 분배하는 SCU(System Control Unit), 그리고 시스템 내부 기능 제어, 외부 제어 인터페이스, 시스템 내/외부 메모리 데이터 입출력 등의 기능을 하는 SoC Platform으로 구성된다.

# SW 개요(Software Overview)

## SW 구조도(Software Structure)

APACHE5 운용을 위한 SDK는 다음과 같은 구조로 구성한다.

![APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK](<APACHE5_NC_ENSW_T03_SW 요구사항 명세서_SDK 3.png>)

[그림 2] APACHE5 SDK Package Diagram

APACHE5 SDK의 소프트웨어 주요 기능(Software Features)은 하기와 같다.

|   |   |
|---|---|
|**구분**|**주요기능**|
|SDK|CAN 송/수신<br><br>DMA 송/수신 (M2M, M2P)<br><br>Video H.264 Encoding<br><br>I2C Read/Write<br><br>딥러닝(CNN) 네트워크 구동<br><br>LIN 송/수신<br><br>Temperature 측정<br><br>Voltage 측정<br><br>PMW 출력<br><br>Sandbox 지원<br><br>IOCTL 구조 지원<br><br>SPI Read/Write<br><br>TIMER<br><br>UART 송/수신<br><br>MMC Read/Write<br><br>VDMA_CNN/H264 Video Data Memory Dump<br><br>Ethernet PHY 지원<br><br>Time Stamp 지원<br><br>I2C Monitoring<br><br>Clock Monitoring<br><br>Watch Dog Timer 지원<br><br>External Watch Dog Timer 지원<br><br>CNN Monitoring<br><br>Video Codec Monitoring<br><br>External Temperature Monitoring<br><br>Internal Temperature Monitoring<br><br>External Voltage Monitoring<br><br>Internal Voltage Monitoring<br><br>Ethernet Monitoring<br><br>Boot Sequence Monitoring<br><br>Fault Monitoring|

[표 1] 소프트웨어 주요 기능

# 요구사항 개요(Requirements Overview)

## 요구사항 식별자(Requirements Identification)

|   |   |   |   |
|---|---|---|---|
|**구분**|**식별자**|   |**예제**|
|SW 기능 요구사항|SR-XXX|Software Function Requirement – Middle Identifier|SR-XXX-001|
|SW 기능 안전 요구사항|SSR-XXX|Software Safety-Function Requirement – Middle Identifier|SSR-XXX-001|
|SW 비기능 요구사항|SNR-XXX|Software Non-Function Requirement – Middle Identifier|SNR-XXX-001|

[표 2] 요구사항 식별자 규칙

## 요구사항 중요도(Requirements Priority)

|   |   |
|---|---|
|**중요도**|**중요도 기준**|
|상|기본 기능이 되는 반드시 필요한 요구사항<br><br>본 프로젝트에서 반드시 개발 해야 하는 요구사항|
|중|기본 기능에 일부 포함되어 있는 요구사항<br><br>일반적인 요구 사항|
|하|기본 기능의 보조 기능 역할을 하는 요구사항<br><br>상황(기간, 개발 비 등)에 따라 개발 보류가 가능한 기능|

[표 3] 요구사항 중요도 기준

## 요구사항 요약(Requirements List)

본 SW를 통해 구현되는 SDK의 기능은 다음과 같다.

|   |   |   |   |   |
|---|---|---|---|---|
|**요구 사항 분류**|**구분**|**식별자**|**SW 기능**|**비고**|
|기능 요구 사항|CNN|SR-SoC-CNN-001|CNN 동작 설정||
|SR-SoC-CNN-002|CNN Inference 수행||
|VDMA_CNN|SR-SoC-VDMA_CNN-001|VDMA CNN 설정||
|SR-SoC-VDMA_CNN-002|VDMA CNN 동작||
|VDMA_H264|SR-SoC-VDMA_H264-001|VDMA_H264 설정||
|SR-SoC-VDMA_H264-002|VDMA_H264 동작||
|I2C|SR-SoC-I2C-001|I2C 설정||
|SR-SoC-I2C-002|I2C Master 모드의 Data Read/Write||
|LIN|SR-SoC-LIN-001|LIN 설정||
|SR-SoC-LIN-002|LIN Data의 송/수신||
|PWM|SR-SoC-PWM-001|PWM 설정||
|SR-SoC-PWM-002|PWM 동작||
|SPI|SR-SoC-SPI-001|SPI 설정||
|SR-SoC-SPI-002|SPI Master 모드 Data Read/Write||
|SF|SR-SoC-SF-001|SF 초기화||
|SR-SoC-SF-002|SF Data Read/Write||
|SR-SoC-SF-003|SF Data Erase||
|ADC|SR-SoC-ADC-001|ADC 초기화||
|SR-SoC-ADC-002|ADC Data Read||
|CAN|SR-SoC-CAN-001|CAN 설정||
|SR-SoC-CAN-002|CAN Data 송/수신||
|TS|SR-SoC-TS-001|Read TS Data||
|SYS|SR-SoC-SYS-001|PLL 설정||
|SR-SoC-SYS-002|CMA 버퍼 설정||
|SR-SoC-SYS-003|System Reset||
|NCLD|SR-SoC-NCLD-001|압축 이미지 로딩||
|DMA|SR-SoC-DMA-001|DMA Data 전송||
|H264ENC|SR-SoC-H264ENC-001|H264 Encoder 설정||
|SR-SoC-H264ENC-002|H264 Encoder 동작||
|MMC|SR-SoC-MMC-001|MMC 초기화||
|SR-SoC-MMC-002|MMC Data Read/Write||
|INI|SR-SoC-INI-001|Config Load||
|OSAL|SR-SoC-OSAL-001|Create Message Queue||
|SR-SoC-OSAL-002|Create Thread||
|BUFF|SR-SoC-BUFF-001|Data Buffer의 생성과 제어||
|GRAPHICS|SR-SoC-GRAPHICS-001|포멧 변환||
|SR-SoC-GRAPHICS-002|해상도 변환||
|SR-SoC-GRAPHICS-003|Rotation||
|SR-SoC-GRAPHICS-004|Overlay Mix||
|UART|SR-SoC-UART-001|UART 설정||
|SR-SoC-UART-002|UART Data 송/수신||
|NCLDH|SR-SoC-NCLDH-001|NC Loader의 File 제어||
|PVT|SR-SoC-PVT-001|PVT 센서 제어||
|기능 안전 요구 사항|NPUM|SSR-SoC-NPUSM-001|NPUSM 설정||
|SSR-SoC-NPUSM-002|NPUSM 오류 검출||
|WDT|SSR-SoC-WDT-001|CPU Monitoring 설정||
|SSR-SoC-WDT-002|CPU Monitoring 오류 검출||
|STM|SSR-SoC-STM-001|Safety Mechanism 설정||
|SSR-SoC-STM-002|Safety Mechanism 동작 확인||
|SE|SSR-SoC-SE-001|SE 설정||
|SSR-SoC-SE-002|Check Fault Signal||
|CC|SSR-SoC-CC-001|Communication Control 오류 검출||
|CM|SSR-SoC-CM-001|Clock Monitoring 설정||
|SSR-SoC-CM-002|Clock Monitoring 오류 검출||
|IFRB|SSR-SoC-IFRB-001|Read Back 오류 검출||
|IFTO|SSR-SoC-IFTO-001|Time Out 오류 검출||
|MI|SSR-SoC-MI-001|Memory Integrity Clock 설정||
|SSR-SoC-MI-002|Memory Integrity 오류 검출||
|RDT|SSR-SoC-RDT-001|RDT 설정||
|SSR-SoC-RDT-002|RDT 오류 검출||
|VM|SSR-SoC-VM-001|Voltage Monitoring 설정||
|SSR-SoC-VM-002|Voltage Monitoring 오류 검출||
|TM|SSR-SoC-TM-001|Temperature Monitoring 설정||
|SSR-SoC-TM-002|Temperature Monitoring 오류 검출||
|FM|SSR-SoC-FM-001|Fault Monitoring 설정||
|SSR-SoC-FM-002|Fault Monitoring 오류 검출||
|OIC|SSR-SoC-OIC-001|OIC CPU 오류 검출||
|SSR-SoC-OIC-002|OIC CNN 오류 검출||
|SSR-SoC-OIC-003|OIC H264 오류 검출||
|SSR-SoC-OIC-004|OIC DDR 오류 검출||
|H264SM|SSR-SoC-H264SM-001|H264 Encoder Monitoring 오류 검출||
|성능 요구 사항|N/A|SNR-SoC-SDK-001|Boot Up Time||
|자원 요구 사항|N/A|SNR-SoC-SDK-002|Memory Usage||
|SNR-SoC-SDK-003|CPU Usage||

[표 4] 요구사항 개요

# 기능 요구사항(Functional Requirements)

## [SR-SoC-CNN-001] CNN 동작 설정

|                 |                                                                                              |
| --------------- | -------------------------------------------------------------------------------------------- |
| **항목**          | **설명**                                                                                       |
| **요구사항 식별자**    | SR-SoC-CNN-001                                                                               |
| **요구사항 제목**     | CNN 동작 설정                                                                                    |
| **요구사항 설명**     | CNN SW는 입력 값에 따라 CNN 동작을 설정할 수 있어야 한다.                                                       |
| **ASIL**        | B                                                                                            |
| **요구사항 검증방법**   | 1. CNN을 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 CNN에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다. |
| **입력**          | 인식 네트워크 정보                                                                                   |
| **출력**          | 설정에 대한 반환 값                                                                                  |
| **중요도**         | 상                                                                                            |
| **요구사항 재사용**    | 신규                                                                                           |
| **관련 시스템 엘리먼트** | [[PDE-011]]                                                                                  |
| **관련 시스템 요구사항** | TR-009                                                                                       |

## [SR-SoC-CNN-002] CNN Inference 수행

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-CNN-002|
|**요구사항 제목**|CNN Inference 수행|
|**요구사항 설명**|CNN SW는 입력 값에 따라 Inference 동작을 수행할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. CNN Inference Test Application을 실행한다.<br><br>2. CNN Inference 동작을 시작한다.<br><br>3. 수행한 Inference 동작 결과가 의도한 결과와 동일 한지 확인한다.|
|**입력**|인식 Data|
|**출력**|인식 결과 확인|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-011|
|**관련 시스템 요구사항**|TR-009|

## [SR-SoC-VDMA_CNN-001] VDMA CNN 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-VDMA_CNN-001|
|**요구사항 제목**|VDMA CNN 설정|
|**요구사항 설명**|VDMA CNN SW는 입력 값에 따라 VDMA CNN을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. VDMA CNN을 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 VDMA CNN에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|Buffer Information, Resolution|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-011, PDE-014|
|**관련 시스템 요구사항**|TR-009, TR-015|

## [SR-SoC-VDMA_CNN-002] VDMA CNN 동작

|                 |                                                                                                                     |
| --------------- | ------------------------------------------------------------------------------------------------------------------- |
| **항목**          | **설명**                                                                                                              |
| **요구사항 식별자**    | SR-SoC-VDMA_CNN-002                                                                                                 |
| **요구사항 제목**     | VDMA CNN 동작 시작                                                                                                      |
| **요구사항 설명**     | VDMA CNN SW는 CNN에서 사용할 영상 Data를 DDR 메모리에 적재할 수 있어야 한다.                                                              |
| **ASIL**        | B                                                                                                                   |
| **요구사항 검증방법**   | 1. VDMA CNN Test Application을 실행한다.<br><br>2. DDR 메모리에 Data를 적재하는 동작을 수행한다.<br><br>3. DDR에 Data가 정상적으로 적재되었는지 확인한다. |
| **입력**          | Buffer Information, Resolution                                                                                      |
| **출력**          | Video Image                                                                                                         |
| **중요도**         | 상                                                                                                                   |
| **요구사항 재사용**    | 신규                                                                                                                  |
| **관련 시스템 엘리먼트** | PDE-011, PDE-014                                                                                                    |
| **관련 시스템 요구사항** | TR-009, TR-015                                                                                                      |

## [SR-SoC-VDMA_H264-001] VDMA H264 설정

|                 |                                                                                                          |
| --------------- | -------------------------------------------------------------------------------------------------------- |
| **항목**          | **설명**                                                                                                   |
| **요구사항 식별자**    | SR-SoC-VDMA_H264-001                                                                                     |
| **요구사항 제목**     | VDMA H264 설정                                                                                             |
| **요구사항 설명**     | VDMA H264 SW는 입력 값에 따라 VDMA H264을 설정할 수 있어야 한다.                                                          |
| **ASIL**        | B                                                                                                        |
| **요구사항 검증방법**   | 1. VDMA H264를 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 VDMA H264에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다. |
| **입력**          | Buffer Information, Resolution                                                                           |
| **출력**          | 설정에 대한 반환 값                                                                                              |
| **중요도**         | 상                                                                                                        |
| **요구사항 재사용**    | 신규                                                                                                       |
| **관련 시스템 엘리먼트** | PDE-013, PDE-014                                                                                         |
| **관련 시스템 요구사항** | TR-015, TR-019                                                                                           |

## [SR-SoC-VDMA_H264-002] VDMA H264 동작

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-VDMA_H264-002|
|**요구사항 제목**|VDMA_H264 동작 시작|
|**요구사항 설명**|VDMA H264 SW는 H264영상 Data를 DDR 메모리에 적재할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. VDMA H264 Test Application을 실행한다.<br><br>2. DDR 메모리에 Data를 적재하는 동작을 수행한다.<br><br>3. DDR에 Data가 정상적으로 적재되었는지 확인한다.|
|**입력**|Buffer Information, Resolution|
|**출력**|Video Image|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-013, PDE-014|
|**관련 시스템 요구사항**|TR-015, TR-019|

## [SR-SoC-I2C-001] I2C 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-I2C-001|
|**요구사항 제목**|I2C 설정|
|**요구사항 설명**|I2C SW는 입력 값에 따라 I2C를 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. I2C를 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 I2C에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|I2C Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-012, TR-014|

## [SR-SoC-I2C-002] I2C Master 모드의 Data Read/Write

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-I2C-002|
|**요구사항 제목**|I2C Master 모드의 Data Read/Write.|
|**요구사항 설명**|I2C SW는 Master 모드로 Data를 Read/Write 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. I2C의 Test Application을 실행한다.<br><br>2. Test Application I2C를 Master 모드로 설정하고 Slave Device에 Data를 Write 한다.<br><br>3. Data가 Write된 Slave Device에서 Data를 Read 한다.<br><br>4. Write 한 Data와 Read 한 Data를 비교하여 같은지 확인한다.|
|**입력**|I2C Parameter|
|**출력**|I2C Read/Write 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-012, TR-014|

## [SR-SoC-LIN-001] LIN 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-LIN-001|
|**요구사항 제목**|LIN 설정|
|**요구사항 설명**|LIN SW는 입력 값에 따라 LIN을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. LIN을 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 LIN에 설정한다.<br><br>2. 설정에 대한 반환 값을 확인한다.|
|**입력**|LIN Parameter|
|**출력**|설정 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-012, TR-013|

## [SR-SoC-LIN-002] LIN Data의 송/수신

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-LIN-002|
|**요구사항 제목**|LIN Data의 송/수신|
|**요구사항 설명**|LIN SW는 Master 모드로 데이터를 송/수신할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. LIN Test Application을 실행한다.<br><br>2. Test Application을 Master 모드로 설정하고 LIN Data를 PC로 송신한다.<br><br>3. PC의 LIN Program에 수신되는지 확인한다.<br><br>4. PC의 LIN Program에서 Data를 송신한다.<br><br>5. Test Application에서 LIN Data가 수신되는지 확인한다.|
|**입력**|LIN Parameter|
|**출력**|송/수신 Data|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-012, TR-013|

## [SR-SoC-PWM-001] PWM 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-PWM-001|
|**요구사항 제목**|PWM 설정.|
|**요구사항 설명**|PWM SW는 입력 값에 따라 PWM을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. PWM을 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 PWM에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|PWM Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007, PDE-008|
|**관련 시스템 요구사항**|TR-012|

## [SR-SoC-PWM-002] PWM 동작

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-PWM-002|
|**요구사항 제목**|PWM 동작 시작|
|**요구사항 설명**|PWM SW는 PWM의 설정에 따라 출력 파형을 Control 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. PWM Test Application을 실행한다.<br><br>2. PWM을 설정하고 파형 출력을 시작한다.<br><br>3. Oscilloscope로 Output Pin을 측정하여 설정된 파형이 출력 되는지 확인한다.<br><br>4. PWM 파형 출력을 중지한다.<br><br>5. Oscilloscope로 Output Pin을 측정하여 파형이 멈췄는지 확인한다.|
|**입력**|Duty, Frequency|
|**출력**|출력 신호|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007, PDE-008|
|**관련 시스템 요구사항**|TR-012|

## [SR-SoC-SPI-001] SPI 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SPI-001|
|**요구사항 제목**|SPI 설정|
|**요구사항 설명**|SPI SW는 입력 값에 따라 SPI를 설정할 수 있어야 한다..|
|**ASIL**|B|
|**요구사항 검증방법**|1. SPI를 설정하는 Test Application을 실행한다.<br><br>2. 입력 값에 따라 SPI or QSPI 모드 선택과 모드에 맞는 설정을 한다.<br><br>3. 설정에 대한 반환 값 확인한다.|
|**입력**|SPI Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-016|

## [SR-SoC-SPI-002] SPI Master 모드 Data Read/Write

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SPI-002|
|**요구사항 제목**|SPI Master 모드 Data Read/Write|
|**요구사항 설명**|SPI SW는 Master 모드로 데이터를 Read/Write할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SPI의 Test Application을 실행한다.<br><br>2. SPI를 Single SPI Master 모드로 설정하고 Destination Address에 Data를 Write한다.<br><br>3. SPI를 Single SPI Master 모드로 설정하고 Destination Address에서 Data를 Read한다.<br><br>4. Write 했던 Data와 Read 한 Data가 동일한지 확인한다|
|**입력**|SPI Parameter|
|**출력**|Data Read/Write 결과 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-002, PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-016|

## [SR-SoC-SF-001] SF 초기화

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SF-001|
|**요구사항 제목**|SF 초기화|
|**요구사항 설명**|SF SW는 입력 값에 따라 SPI와 Serial Flash를 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SF를 초기화 하는 Test Application을 실행한다.<br><br>2. 초기화에 대한 SF 결과값을 확인한다.|
|**입력**|N/A|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-016|

## [SR-SoC-SF-002] SF Data Read/Write

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SF-002|
|**요구사항 제목**|SF Data Read/Write|
|**요구사항 설명**|SF SW는 SPI로 Serial Flash에 데이터를 Read/Write 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SF Test Application을 실행한다.<br><br>2. Serial Flash의 Offset에 Data를 Write 한다.<br><br>3. 같은 Offset에서 Data를 Read를 한다.<br><br>4. Write 했던 Data와 Read 한 Data가 동일한지 확인한다.|
|**입력**|Address, Data, Size|
|**출력**|Data Read/Write에 대한 SF Status|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-016|

## [SR-SoC-SF-003] SF Data Erase

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SF-003|
|**요구사항 제목**|SF Data Erase|
|**요구사항 설명**|SF SW는 Serial Flash의 데이터를 삭제할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. Serial Flash 메모리의 데이터를 삭제하는 Test Application을 실행한다.<br><br>2. Serial Flash에 Address와 Erase Command를 전송한다.<br><br>3. 삭제된 영역을 Read 하여 Data가 0xFF인지 확인한다.|
|**입력**|Address, Size|
|**출력**|Erase 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-016|

## [SR-SoC-ADC-001] ADC 초기화

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-ADC-001|
|**요구사항 제목**|ADC 초기화|
|**요구사항 설명**|ADC SW는 입력 값에 따라 ADC를 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. ADC를 초기화하는 Test Application을 실행한다.<br><br>2. 초기화에 대한 ADC 결과값을 확인한다.|
|**입력**|N/A|
|**출력**|초기화 결과 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007|
|**관련 시스템 요구사항**|TR-012|

## [SR-SoC-ADC-002] ADC Data Read

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-ADC-002|
|**요구사항 제목**|ADC Data Read|
|**요구사항 설명**|ADC SW는 ADC 장치로부터 Data를 Read할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. ADC Test Application을 실행한다.<br><br>2. ADC에서 Data를 Read 한다.<br><br>3. Read 한 Data를 확인한다.|
|**입력**|N/A|
|**출력**|ADC Data|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007|
|**관련 시스템 요구사항**|TR-012|

## [SR-SoC-CAN-001] CAN 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-CAN-001|
|**요구사항 제목**|CAN 설정|
|**요구사항 설명**|CAN SW는 입력 값에 따라 CAN을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. CAN을 설정하는 Test Application을 실행한다.  <br>2. 입력 값을 CAN에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|CAN Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-013, TR-014|

## [SR-SoC-CAN-002] CAN Data 송/수신

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-CAN-002|
|**요구사항 제목**|CAN Data 송/수신|
|**요구사항 설명**|CAN SW는 Data를 송/수신할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. CAN Test Application을 실행한다.<br><br>2. Test Application에서 외부 CAN 장비로 CAN Data를 송신한다.<br><br>3. 외부 CAN 장비에서 CAN Data가 수신되는지 확인한다<br><br>4. 외부 CAN 장비에서 Test Application으로 CAN Data를 송신한다.<br><br>5. Test Application에서 CAN Data가 수신되는지 확인한다.|
|**입력**|CAN 송/수신 Parameter|
|**출력**|CAN Data|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-013, TR-014|

## [SR-SoC-TS-001] Read TS Data

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-TS-001|
|**요구사항 제목**|Read TS Data|
|**요구사항 설명**|TS SW는 Time Stamp Data를 읽어올 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. TS Test Application을 실행한다.<br><br>2. Time Stamp 값을 읽어온다.<br><br>2. 읽어온 Time Stamp 값을 확인한다.|
|**입력**|N/A|
|**출력**|Time Stamp|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007, PDE-008|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-SYS-001] PLL 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SYS-001|
|**요구사항 제목**|PLL 설정|
|**요구사항 설명**|SYS SW는 입력 값에 따라 PLL을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SYS Test Application을 실행 한다.<br><br>2. PLL 값을 SYS에 설정한다.<br><br>2. 설정에 대한 반환 값을 확인한다.|
|**입력**|PLL Ratio|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-003|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-SYS-002] CMA Buffer 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SYS-002|
|**요구사항 제목**|CMA 버퍼 설정|
|**요구사항 설명**|SYS SW는 물리적으로 연속된 Memory를 할당할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SYS Test Application을 실행한다.<br><br>2. CMA Buffer를 할당한다.<br><br>3. DMA를 이용하여 할당된 Buffer Memory A에서 Memory B로 Data를 복사한다.<br><br>4. Memory Copy를 수행한 결과값을 확인한다.|
|**입력**|Address Size|
|**출력**|결과에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-003|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-SYS-003] System Reset

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-SYS-003|
|**요구사항 제목**|System Reset|
|**요구사항 설명**|System Reset을 Release를 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. SYS Test Application을 수행한다.<br><br>2. System Reset의 Release를 실행한다.<br><br>3. Release된 결과를 Register로 확인한다.|
|**입력**|N/A|
|**출력**|N/A|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-003|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-NCLD-001] 압축 이미지 로딩

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-NCLD-001|
|**요구사항 제목**|압축 이미지 로딩|
|**요구사항 설명**|NCLD SW는 저장 장치에서 압축 이미지를 읽어 File System에 Load할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. NCLD Test Application을 실행한다.<br><br>2. 압축 Image를 저장 장치에 저장한다.<br><br>3. Test Application은 저장 장치에서 압축 Image를 읽어와 File System에 Load 한다.<br><br>4. File System에 Load된 Data를 확인한다.|
|**입력**|압축된 Image|
|**출력**|압축 해제된 Data|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010, TR-012|

## [SR-SoC-DMA-001] DMA Data 전송

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-DMA-001|
|**요구사항 제목**|DMA Data 전송|
|**요구사항 설명**|DMA SW는 DMA로 Data를 전송할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. DMA Test Application을 실행한다.<br><br>2. DMA를 이용하여 Source Memory에 있는 Data를 Destination Memory로 Data를 복사합니다.<br><br>3. Source Memory의 Data와 Destination Memory의 Data를 비교하여 동일한지 확인한다.|
|**입력**|DMA Parameter|
|**출력**|결과에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-012|

## [SR-SoC-H264ENC-001] H264 Encoder 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-H264ENC-001|
|**요구사항 제목**|H264 Encoder 설정|
|**요구사항 설명**|H264ENC SW는 입력 값에 따라 H264ENC 동작을 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. H264ENC를 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 H264ENC에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|Encoder Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-013|
|**관련 시스템 요구사항**|TR-019|

## [SR-SoC-H264ENC-002] H264 Encoder 동작

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-H264ENC-002|
|**요구사항 제목**|H264 Encoder 동작|
|**요구사항 설명**|H264ENC SW는 입력 값에 따라 H264 Encoding을 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. H264ENC Test Application을 실행한다.<br><br>2. Data를 H264로 Encoding 한다.<br><br>3. Encoding된 결과값을 PC Player로 확인한다.|
|**입력**|영상 입력(YUV420)|
|**출력**|H.264 NAL Data|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-013|
|**관련 시스템 요구사항**|TR-019|

## [SR-SoC-MMC-001] MMC 초기화

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-MMC-001|
|**요구사항 제목**|MMC 초기화|
|**요구사항 설명**|MMC SW는 입력 값에 따라 MMC를 초기화할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. MMC를 초기화하는 Test Application을 실행한다.<br><br>2. 초기화에 대한 MMC 상태 값을 확인한다.|
|**입력**|N/A|
|**출력**|MMC 상태 값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-012|
|**관련 시스템 요구사항**|TR-017|

## [SR-SoC-MMC-002] MMC Data Read/Write

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-MMC-002|
|**요구사항 제목**|MMC Data Read/Write|
|**요구사항 설명**|MMC에 Data를 Read/Write할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. MMC Test Application을 실행한다.<br><br>2. 입력된 Address에 Data를 Write 한다.<br><br>3. MMC에서 Data를 Read 하여 Write 했던 Data와 동일한지 확인한다.<br><br>4. 반환된 결과값을 확인한다.|
|**입력**|Address, Data Size|
|**출력**|Data Read/Write에 대한 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-012|
|**관련 시스템 요구사항**|TR-017|

## [SR-SoC-INI-001] Configuration Load

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-INI-001|
|**요구사항 제목**|Configuration Load|
|**요구사항 설명**|File System에 저장된 설정 파일을 읽을 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. INI Test Application을 실행한다.<br><br>2. File System에서 설정 파일을 읽어 온다.<br><br>3. 읽어온 Configuration Data를 확인한다.<br><br>4. 확인된 결과값을 반환한다.|
|**입력**|Configuration File|
|**출력**|반환된 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-OSAL-001] Create Message Queue

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-OSAL-001|
|**요구사항 제목**|Create Message Queue|
|**요구사항 설명**|OSAL SW는 입력 값에 따라 Message Queue를 만들 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. OSAL Test Application을 실행한다.<br><br>2. Message Queue를 Creation 한다.<br><br>3. Creation 한 결과에 대한 반환 값을 확인한다.|
|**입력**|OSAL Parameter|
|**출력**|반환된 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-OSAL-002] Create Thread

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-OSAL-002|
|**요구사항 제목**|Create Thread|
|**요구사항 설명**|OSAL SW는 입력 값에 따라 Thread를 만들 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. OSAL Test Application을 실행한다.<br><br>2. Thread를 Creation 한다.<br><br>3. Creation 한 결과에 대한 반환 값을 확인한다.|
|**입력**|OSAL Parameter|
|**출력**|반환된 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-GRAPHICS-001] 포멧 변환

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-GRAPHICS-001|
|**요구사항 제목**|포멧 변환|
|**요구사항 설명**|GRAPHICS SW는 Data의 포맷을 변환할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. GRAPHICS Test Application을 실행한다.<br><br>2. YUV Data를 RGB Data로 변환한다.<br><br>3. Data 변환의 결과를 확인한다.|
|**입력**|Graphic Parameter|
|**출력**|Data Convert 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-009|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-GRAPHICS-002] 해상도 변환

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-GRAPHICS-002|
|**요구사항 제목**|해상도 변환|
|**요구사항 설명**|GRAPHICS SW는 Data의 해상도를 변환할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. GRAPHICS Test Application을 실행한다.<br><br>2. Data의 해상도를 1920x1080에서 1280x720으로 변환한다.<br><br>3. Data 변환의 결과를 확인한다.|
|**입력**|Graphic Parameter|
|**출력**|Data Convert 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-009|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-GRAPHICS-003] Rotation

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-GRAPHICS-003|
|**요구사항 제목**|Rotation|
|**요구사항 설명**|GRAPHICS SW는 Data를 Rotation을 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. GRAPHICS Test Application을 실행한다.<br><br>2. Data를 90도 Rotation 한다.<br><br>3. Data의 변환 결과를 확인한다.|
|**입력**|Graphic Parameter|
|**출력**|Data Convert 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-009|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-GRAPHICS-004] Overlay Mix

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-GRAPHICS-004|
|**요구사항 제목**|Overlay Mix|
|**요구사항 설명**|GRAPHICS SW는 Data에 Overlay Mix를 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. GRAPHICS Test Application을 실행한다.<br><br>2. Data에 Overlay Mix를 실행한다.<br><br>3. Data의 변환 결과를 확인한다.|
|**입력**|Graphic Parameter|
|**출력**|Data Convert 결과값|
|**중요도**|상|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-009|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-UART-001] UART 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-UART-001|
|**요구사항 제목**|UART 설정|
|**요구사항 설명**|UART SW는 입력 값에 따라 UART를 설정할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. UART를 설정하는 Test Application을 실행한다.<br><br>2. 입력 값을 UART에 설정한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**입력**|UART Parameter|
|**출력**|설정에 대한 반환 값|
|**중요도**|하|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-018|

## [SR-SoC-UART-002] UART Data 송/수신

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-UART-002|
|**요구사항 제목**|UART Data 송/수신|
|**요구사항 설명**|UART SW는 UART Data를 송/수신 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. UART Test Application을 실행한다.<br><br>2. Test Application에서 Serial Terminal로 Data를 송신한다.<br><br>3. Serial Terminal에서 송신된 Data를 확인한다.<br><br>4. Serial Terminal에서 Test Application으로 Data를 송신한다.<br><br>5. Test Application에서 Data를 수신하여 확인한다.|
|**입력**|UART Parameter|
|**출력**|UART Data|
|**중요도**|하|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-008|
|**관련 시스템 요구사항**|TR-018|

## [SR-SoC-BUFF-001] Data Buffer의 생성과 제어

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-BUFF-001|
|**요구사항 제목**|Data Buffer의 생성과 제어|
|**요구사항 설명**|Data Buffer를 생성하고 제어를 할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. Buffer를 생성하고 제어하는 Test Application을 실행한다.<br><br>2. Flipflop Buffer를 생성한다.<br><br>3. Buffer에 Data를 Write 한다.<br><br>4. Buffer의 Data를 Read 하여 Write 한 Data와 비교하여 Data의 Write/Read가 정상 동작하는지 확인한다.<br><br>5. Circular Buffer를 생성한다.<br><br>6. Enqueue를 수행한다.<br><br>7. Dequeue를 하여 Data가 정상적으로 읽히는지 확인한다.|
|**입력**|Buffer Parameter|
|**출력**|Success or Failure|
|**중요도**|하|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010|

## [SR-SoC-NCLDH-001] NC Loader의 File 제어

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-NCLDH-001|
|**요구사항 제목**|NC Loader의 File 제어|
|**요구사항 설명**|NC Loader의 File을 제어 할 수 있다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. NC Loader Application을 실행한다.<br><br>2. File Open을 실행한다.<br><br>3. File Open에 대한 결과를 확인한다.|
|**입력**|File Path|
|**출력**|File Pointer|
|**중요도**|하|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 시스템 요구사항**|TR-010, TR-012|

## [SR-SoC-PVT-001] PVT 센서의 제어

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SR-SoC-PVT-001|
|**요구사항 제목**|PVT 센서의 제어|
|**요구사항 설명**|Voltage 및 Temperature 센서에서 값을 읽어와 사용자에게 보정된 값을 제공할 수 있어야 한다.|
|**ASIL**|B|
|**요구사항 검증방법**|1. PVT Test Application을 실행한다.<br><br>2. Voltage 및 Temperature 센서의 값이 정상적으로 읽히는지 확인한다.<br><br>3. 읽어온 값을 Calibration 한다.<br><br>4. 보정된 결과값을 확인한다.|
|**입력**|File Path|
|**출력**|File Pointer|
|**중요도**|하|
|**요구사항 재사용**|신규|
|**관련 시스템 엘리먼트**|PDE-004, PDE-007, PDE-008|
|**관련 시스템 요구사항**|TR-012|

# 기능안전 요구사항(Functional Safety Requirement)

## [SSR-SoC-NPUM-001] NPU 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-NPUM-001|
|**요구사항 제목**|NPU 설정|
|**Variants**|ALL|
|**요구사항 설명**|NPUM SW는 NPU가 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. NPU Test Application을 실행한다.<br><br>2. NPU의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-008|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 TSC**|TSC-008|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-NPUM-002] NPU 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-NPUM-002|
|**요구사항 제목**|NPU 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|NPUM SW는 NPU에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. NPUM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-008|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 TSC**|TSC-008|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-WDT-001] CPU Monitoring 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-WDT-001|
|**요구사항 제목**|CPU Monitoring 설정|
|**Variants**|ALL|
|**요구사항 설명**|WDT SW는 Refresh 주기를 입력으로 받아 CPU가 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. WDT Test Application을 실행한다.<br><br>2. WDT의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-013|
|**관련 시스템 엘리먼트**|PDE-001, PDE-004|
|**관련 TSC**|TSC-012|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-WDT-002] CPU Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-WDT-002|
|**요구사항 제목**|CPU Monitoring 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|WDT SW는 지정된 Refresh 주기 이내에 Refresh 되지 않는 상태를 검출하여 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. WDT Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. Refresh Count를 멈춘다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-013|
|**관련 시스템 엘리먼트**|PDE-001, PDE-004|
|**관련 TSC**|TSC-012|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-STM-001] Safety Mechanism 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-STM-001|
|**요구사항 제목**|Safety Mechanism 설정|
|**Variants**|ALL|
|**요구사항 설명**|Safety Mechanism SW는 기능 안전 설정을 정상적으로 할 수 있어야 한다.|
|**요구사항 검증방법**|1. Safety Mechanism Test Application을 실행한다.<br><br>2. Safety Mechanism의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-022|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 TSC**|TSC-003|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-STM-002] Safety Mechanism 동작 확인

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-STM-002|
|**요구사항 제목**|Safety Mechanism 동작 확인|
|**Variants**|ALL|
|**요구사항 설명**|Safety Mechanism SW은 정상 적으로 동작하는지 확인할 수 있어야 한다.|
|**요구사항 검증방법**|1. Safety Mechanism Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-022|
|**관련 시스템 엘리먼트**|PDE-001|
|**관련 TSC**|TSC-003|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-SE-001] SE 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-SE-001|
|**요구사항 제목**|Safety Engine 설정|
|**Variants**|ALL|
|**요구사항 설명**|SE SW는 Fault 발생 시 Fault를 전달받아 외부로 Fault 신호를 전달할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. SE Test Application을 실행한다.<br><br>2. SE의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-010|
|**관련 시스템 엘리먼트**|PDE-004, PDE-005|
|**관련 TSC**|TSC-016|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-SE-002] Check Fault Signal

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-SE-002|
|**요구사항 제목**|Check Fault Signal|
|**Variants**|ALL|
|**요구사항 설명**|SE SW는 Fault를 감지 하면 Fault 신호를 외부로 전달하여야 한다.|
|**요구사항 검증방법**|1. SE Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에서 Fault를 전달받아 외부로 Fault 신호를 전달하는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-010|
|**관련 시스템 엘리먼트**|PDE-004, PDE-005|
|**관련 TSC**|TSC-016|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-CC-001] Communication Control 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-CC-001|
|**요구사항 제목**|Communication Control 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|CC SW는 Communication Control에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. CC Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-025|
|**관련 시스템 엘리먼트**|PDE-005, PDE-008, PDE-012|
|**관련 TSC**|TSC-006|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-CM-001] Clock Monitoring 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-CM-001|
|**요구사항 제목**|Clock Monitoring 설정|
|**Variants**|ALL|
|**요구사항 설명**|CM SW는 Clock Monitoring이 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. CM Test Application을 실행한다.<br><br>2. CM의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-011|
|**관련 시스템 엘리먼트**|PDE-001, PDE-003, PDE-005|
|**관련 TSC**|TSC-010|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-CM-002] Clock Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-CM-002|
|**요구사항 제목**|Clock Monitoring 오류 검춣|
|**Variants**|ALL|
|**요구사항 설명**|CM SW는 Clock Monitoring에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. CM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-011|
|**관련 시스템 엘리먼트**|PDE-001, PDE-003, PDE-005|
|**관련 TSC**|TSC-010|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-IFRB-001] Read Back 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-IFRB-001|
|**요구사항 제목**|Read Back 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|IFRB SW는 Read Back 동작에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. IFRB Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-008, TSR-021|
|**관련 시스템 엘리먼트**|PDE-001, PDE-002, PDE-004, PDE-005, PDE-008|
|**관련 TSC**|TSC-002, TSC-008|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-IFTO-001] Time Out 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-IFTO-001|
|**요구사항 제목**|Time Out 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|IFTO SW는 Time Out 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. IFTO Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-002|
|**관련 시스템 엘리먼트**|PDE-001, PDE-004, PDE-005, PDE-008, PDE-012|
|**관련 TSC**|TSC-002|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-MI-001] Memory Integrity Check 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-MI-001|
|**요구사항 제목**|Memory Intergrity Check 설정|
|**Variants**|ALL|
|**요구사항 설명**|MI SW는 Memory Integrity Check가 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. MI Test Application을 실행한다.<br><br>2. MI의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-003|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-006|
|**관련 TSC**|TSC-007|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-MI-002] Memory Integrity Check 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-MI-002|
|**요구사항 제목**|Memory Integrity Check 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|MI SW는 Memory Integrity Check에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. MI Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-003|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-006|
|**관련 TSC**|TSC-007|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-RDT-001] RDT 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-RDT-001|
|**요구사항 제목**|RDT 설정|
|**Variants**|ALL|
|**요구사항 설명**|RDT SW는 RDT가 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. RDT Test Application을 실행한다.<br><br>2. RDT의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-014|
|**관련 시스템 엘리먼트**|PDE-001, PDE-003, PDE-005|
|**관련 TSC**|TSC-013|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-RDT-002] RDT 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-RDT-002|
|**요구사항 제목**|RDT 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|RDT SW는 RDT에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. RDT Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-014|
|**관련 시스템 엘리먼트**|PDE-001, PDE-003, PDE-005|
|**관련 TSC**|TSC-013|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-VM-001] Voltage Monitoring 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-VM-001|
|**요구사항 제목**|Voltage Monitoring 설정|
|**Variants**|ALL|
|**요구사항 설명**|VM SW는 Voltage Monitoring이 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. VM Test Application을 실행한다.<br><br>2. VM의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-019|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-007|
|**관련 TSC**|TSC-014|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-VM-002] Voltage Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-VM-002|
|**요구사항 제목**|VM 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|VM SW는 Voltage Monitoring에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. VM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-019|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-007|
|**관련 TSC**|TSC-014|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-TM-001] Temperature Monitoring 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-TM-001|
|**요구사항 제목**|Temperature Monitoring 설정|
|**Variants**|ALL|
|**요구사항 설명**|TM SW는 Temperature Monitoring이 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. TM Test Application을 실행한다.<br><br>2. TM의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-017|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-007|
|**관련 TSC**|TSC-014|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-TM-002] Temperature Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-TM-002|
|**요구사항 제목**|TM 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|TM SW는 Temperature Monitoring에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. TM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-017|
|**관련 시스템 엘리먼트**|PDE-001, PDE-005, PDE-007|
|**관련 TSC**|TSC-014|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-FM-001] Fault Monitoring 설정

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-FM-001|
|**요구사항 제목**|Fault Monitoring 설정|
|**Variants**|ALL|
|**요구사항 설명**|FM SW는 Fault Monitoring이 정상 동작되고 있는지를 검사할 수 있는 상태로 설정하여야 한다.|
|**요구사항 검증방법**|1. FM Test Application을 실행한다.<br><br>2. FM의 설정을 수행한다.<br><br>3. 설정에 대한 반환 값을 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-010|
|**관련 시스템 엘리먼트**|PDE-004, PDE-005|
|**관련 TSC**|TSC-016|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-FM-002] Fault Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-FM-002|
|**요구사항 제목**|TM 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|FM SW는 Fault Monitoring에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. FM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-010|
|**관련 시스템 엘리먼트**|PDE-004, PDE-005|
|**관련 TSC**|TSC-016|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-OIC-001] OIC CPU 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-OIC-001|
|**요구사항 제목**|OIC CPU 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|OIC SW는 OIC CPU 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. OIC Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. CPU에 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-013, TSR-024|
|**관련 시스템 엘리먼트**|PDE-001, PDE-002, PDE-005|
|**관련 TSC**|TSC-009, TSC-012|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-OIC-002] OIC CNN 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-OIC-002|
|**요구사항 제목**|OIC CNN 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|OIC SW는 OIC CNN 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. OIC Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. CNN에 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-003, TSR-024|
|**관련 시스템 엘리먼트**|PDE-002, PDE-005, PDE-011|
|**관련 TSC**|TSC-007, TSC-009|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-OIC-003] OIC H264 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-OIC-003|
|**요구사항 제목**|OIC H264 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|OIC SW는 OIC H264 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. OIC Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. H264에 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-005, TSR-024|
|**관련 시스템 엘리먼트**|PDE-002, PDE-005, PDE-013|
|**관련 TSC**|TSC-005, TSC-009|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-OIC-004] OIC DDR 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-OIC-004|
|**요구사항 제목**|OIC DDR 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|OIC SW는 OIC DDR 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. OIC Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. DDR에 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-005, TSR-024|
|**관련 시스템 엘리먼트**|PDE-002, PDE-005, PDE-014|
|**관련 TSC**|TSC-005, TSC-009|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

## [SSR-SoC-H264SM-001] H264 Encoder Monitoring 오류 검출

|   |   |
|---|---|
|**항목**|**설명**|
|**요구사항 식별자**|SSR-SoC-H264SM-001|
|**요구사항 제목**|H264 Encoder Monitoring 오류 검출|
|**Variants**|ALL|
|**요구사항 설명**|H264SM SW는 H264SM에서 오류가 발생하면 오류 상태를 SE에 전달하여야 한다.|
|**요구사항 검증방법**|1. H264SM Test Application을 실행한다.<br><br>2. 오류 없이 Test Application이 실행되는 것을 확인한다.<br><br>3. 오류가 발생 되도록 Fault Injection을 실행한다.<br><br>4. Fault가 발생하면 SE에 Fault가 전달되었는지 확인한다.|
|**FHTI**|66ms|
|**ASIL**|ASIL B|
|**관련 요구사항**|TSR-003|
|**관련 시스템 엘리먼트**|PDE-005, PDE-013|
|**관련 TSC**|TSC-007|
|**우선순위**|상|
|**요구사항 근거**|시스템 요구 사항 명세서, 시스템 설계서|
|**요구사항 재사용**|신규|
|**요구사항 상태**|Reviewed|

# 성능 요구사항(Performance Requirements)

## [SNR-SoC-SDK-001] Boot UP Time

|   |   |
|---|---|
|**항목**|**설명**|
|요구사항 식별자|SNR-SoC-SDK-001|
|요구사항 제목|Boot UP Time|
|요구사항 설명|Apache5 SW는 Power-On이 된 이후 영상의 첫 Vsync가 출력 될 때까지의 시간이 3초 이내여야 한다.|
|요구사항 검증방법|1. Image 센서의 영상이 출력 되는 기능이 적용된 Camera Application을 실행한다.<br><br>2. 영상 출력의 Power-On Reset의 상승 Edge부터 첫 영상 출력까지의 시간을 측정한다.|
|입력|SW Code (릴리즈 버전)|
|출력|Map파일|
|중요도|하|
|요구사항 재사용|신규|
|관련 시스템 요구사항|TR-010|

# 자원 요구사항(Resource Requirements)

## [SNR-SoC-SDK-002] Memory Usage

|   |   |
|---|---|
|**항목**|**설명**|
|요구사항 식별자|SNR-SoC-SDK-002|
|요구사항 제목|Memory Usage|
|요구사항 설명|SDK SW의 메모리 사용량은 전체 메모리의 80% 이하여야 한다.|
|요구사항 검증방법|1. 빌드하여 생성된 Map 파일을 준비한다.<br><br>2. 생성된 Map 파일의 Code, RO Data, RW Data와 ZI Data 영역의 크기를 확인한다.<br><br>3. SRAM 영역의 크기를 계산한다.<br><br>4. 메모리 사용량이 SRAM 용량의 80% 이하임을 확인한다.|
|입력|SW Code (릴리즈 버전)|
|출력|Map파일|
|중요도|하|
|요구사항 재사용|신규|
|관련 시스템 요구사항|TR-010|

## [SNR-SoC-SDK-003] CPU Usage

|   |   |
|---|---|
|**항목**|**설명**|
|요구사항 식별자|SNR-SoC-SDK-003|
|요구사항 제목|CPU Usage|
|요구사항 설명|SDK이 사용하는 CPU의 점유율이 80% 이하여야 한다.|
|요구사항 검증방법|1. Application을 실행 한다.<br><br>2. CPU의 Utilization의 결과값을 확인한다.|
|입력|N/A|
|출력|CPU Utilization의 결과값|
|중요도|하|
|요구사항 재사용|신규|
|관련 시스템 요구사항|TR-010|

# 개발 제약 사항(Development Constraints)

- 해당 GHS RTOS(INTIGRITY)만 고려 한다.