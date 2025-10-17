[[SW SDK에 적용 할 시스템 문서 검토]]
1. Communication Controller (**SM-35[[Communication data integrity check]]**)
2. Clock Monitoring (**SM-14 [[Clock Monitoring]]**)
3. Fault Monitoring
4. H264SM
5. Read Back Check (**SM-07 [[Read-back Test]]**)
6. Time Out Check (**SM-35[[Communication data integrity check]]**)
7. Memory Integrity Check (**SM-35[[Communication data integrity check]]**)
8. NPU 동작 Check
9. OIC Bus Check
10. Redundant Timer Check (**SM-16 [[Timer 이중화 설계]]**)
11. Safety Engine
12. Safety Mechanism
13. Temperature Monitoring (**SM-19 [[SW Input Range Checker]]**), (**SM-23 [[Internal Temperature Monitoring]]**)
14. Voltage Monitoring (**SM-19 [[SW Input Range Checker]]**), (**SM-21 [[Internal Voltage Monitoring]]**)
15. WDT (**SM-15 [[Watdog Timer]]**)
16. 

---------- SDK에서 구현이 필요할까?? -------------------------
1. Program Flow Monitoring(PFM) (**SM-20 [[SW Flow Monitoring]]**)
2. SW Task Time Monitoring (**SM-41 [[SW Task Time Monitoring]]**)
3. Flash Memory Signature (**SM-27 [[Flash memory signature]]**)
4. Memory Protection (**SM-37 [[Memory Protection]]**)
5. DDR Memory Access Protection (**SM-39 [[DDR Memory Access Protection]]**)
6. Alive Check (**SM-12 [[Alive Check]]**)
------------------------------------------------
**SM-03 [[IRAM ECC]]**
 -> 상세 구현 방안을 보면 BL1에서 IRAM으로부터 Image를 읽어 올 때 Data의 ECC 검사를 하라고 되어있다.
 SDK에서도 Data File Loading 과정이 있으면 상세 구현 방안을 수정하고, 코드 상에서도 RAM ECC 검사를 추가해야 하지 않을까?
 
**SM-04 [[Boot Sequence Monitoring]]**
 -> SDK에서도 부팅 과정이 있으면 기능을 구현하고 상세 구현 방안을 수정해야 한다.

**SM-10, [[External Device Read-back Test]],  SM-11, [[External Device Time-Out check]]**
 -> Fault Monitoring의 fault_receive_from_user_task() 함수를 구현하면 될듯하다.

**SM-13 [[Fault 출력 이중화]]**
 -> SW로 구현 가능? Nomal State와 Safe State 전환 가능한지??? (FAULT_P와 FAULT_N핀이 있는지?)

**SM-16 [[Timer 이중화 설계]]**
 -> SW에서 구현이 가능한지 확인하고 가능하면 'SW'를 할당해야 함.

**SM-17 [[Secure Boot]]**
 -> Secure Mode가 가능한지 확인하고 가능하다면 구현해야 함. 상세 구현 방안에서 BL1에서 Application Image에 대한 Secure 모드만 명시되어 있지만 SDK에서도 가능하다면 구현하고 상세 구현 방안 수정해야 함.

**SM-18 [[Interrupt Monitor]]**
 -> 상세 구현 방안에 "Redundant Timer를 이용하여 Interrupt를 발생시켜 Interrupt가 발생하는지 확인하고 오류 발생 시 Fault 신호를 SE에 전달한다"라고 되어있는데 설명을 좀 더 명확하게 해야 할 필요성이 보인다. ex) Interrupt 발생 시 오류의 경우가 어떤 것이 있는지? Interrupt가 안 발생했을 때 확인할 Status가 있는지?

**SM-19 [[SW Input Range Checker]]**
 -> Parameter를 입력받는 모든 기능에서 입력값의 min/max를 검사하고 Error를 Return 하도록 구현하면 해당 SM을 필요 없지 않을까?

**SM-23 [[Internal Temperature Monitoring]]**
 -> HW 할당만 되어 있는데 SW 할당도 추가해야 한다.

**SM-24 [[External Watchdog Timer]]**
 -> 외부 WDT이기에 할당을 App에서 구현(AoU(Assumption of Use))로 해야 한다.
