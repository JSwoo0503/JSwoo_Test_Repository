1. [[시스템 설계서 TSC - SM List]]

- '시스템 설계서 TSC - SM List 문서'를 참고하여 SW SDK에 넣을 SM을 검토한다.
- (SW)는 SW에 할당됐다는 뜻으로 SDK or ISP의 SW에서 구현해야 한다는 뜻이다.
- SDK SW에서 구현이 불가능한 것은 검토하여 FSM 팀과 논의하여 (SW) 할당을 수정해야 한다.
	- 삭제, External 등등
- SDK SW에서 구현해야 하는데 (SW) 할당이 없는 것은 FSM 팀과 논의하여 할당을 추가해야 한다.

1. SM-03(HW, SW) - [[IRAM ECC]] 
2. SM-04(SW) - [[Boot Sequence Monitoring]]
	- SDK에서도 Binary Loading 과정이 있으면 구현 해야 할 것 같음.
3. SM-05(HW, SW) - [[Register Lock Mechanism]]
4. SM-07(SW) - [[Read-back Test]]
5. SM-10(SW) - [[External Device Read-back Test]] , SM-11(SW) - [[External Device Time-Out check]]
	- 외부 Device에서 주는 신호를 받아서 SE로 Fault를 전달하는 SW를 구현 필요 할까?
6. SM-12(SW, External ECU) - [[Alive Check]].
7. SM-13(HW, SW, External) - [[Fault 출력 이중화]]
8. SM-14(HW, SW) - [[Clock Monitoring]]
9. SM-15(HW, SW) - [[Watchdog Timer]]
10. SM-16(HW) - [[Timer 이중화 설계]]
	- Redundant Timer는 SW 할당을 하여 SW 구현을 해야 함.
11. SM-17(SW) - [[Secure Boot]]
12. SM-18(SW) - [[Interrupt Monitor]]
13. SM-19(SW) - [[SW Input Range Checker]]
14. SM-20(SW) - [[SW Flow Monitoring]]
15. SM-41(SW) - [[SW Task Time Monitoring]]
16. SM-21(HW, SW) - [[Internal Voltage Monitoring]]
17. SM-23(HW) - [[Internal Temperature Monitoring]]
	- Internal Temperature Monitoring은 SW 할당을 하여 SW 구현을 해야 함.
18. SM-24(HW, SW, External) - [[External Watchdog Timer]]
	- 외부로 신호를 보낼 수 있으면 되기에 PWM으로 신호를 보내면 된다.
	- 신호가 안 왔을 때 Watchdog이 걸리는 것은 External에서 구현해야 한다.
19. SM-27(SW) - [[Flash memory signature]]
20. SM-35(HW, SW) - [[Communication data integrity check]]
21. SM-37(HW, SW) - [[Memory Protection]]
22. SM-39(HW, SW) - [[DDR Memory Access Protection]]

