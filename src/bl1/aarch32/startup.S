;/**
;********************************************************************************
;*
;*  Copyright (C) 2019 NEXTCHIP Inc. All rights reserved.
;*
;*  file    :
;*
;*  brief   :
;*
;*  author  :
;*
;*  date    :
;*
;*  version :
;*
;********************************************************************************
;*  note    :
;*
;*		APACHE6 Execution Vector Code
;*              Start-up and initialisation code
;********************************************************************************
;*/

        PRESERVE8

        AREA    Startup, CODE, READONLY



;/*
;********************************************************************************
;*               ASM DEFINES
;********************************************************************************
;*/

APACHE6_BL2_IRQ             EQU     0x01000018
APACHE6_BL2_FIQ             EQU     0x0100001C

#ifdef BL2_
APACHE6_ATCM_BASE           EQU     0x03000000
APACHE6_ATCM_SIZE           EQU     0x00002000
APACHE6_BTCM_BASE           EQU     0x03800000
APACHE6_BTCM_SIZE           EQU     0x00002000
#endif

ARM_MODE_FIQ                EQU     0x11
ARM_MODE_IRQ                EQU     0x12
ARM_MODE_SVC                EQU     0x13
ARM_MODE_ABT                EQU     0x17
ARM_MODE_UNDEF              EQU     0x1B
ARM_MODE_SYS                EQU     0x1F
ARM_MODE_MASK               EQU     0x1F

DEBUG_DATA_SECTION_REGION_NUM                         EQU     8
DEBUG_DATA_SECTION_REGION_SIZE_AND_ENABLE_ON          EQU     0xD /* 128Byte Enable  */
DEBUG_DATA_SECTION_REGION_SIZE_AND_ENABLE_OFF         EQU     0xC /* 128Byte Disable */

DEBUG_SECTION_REGION_NUM                         EQU     9
DEBUG_SECTION_REGION_SIZE_AND_ENABLE_ON          EQU     0x1B /* 16KB Enable  */
DEBUG_SECTION_REGION_SIZE_AND_ENABLE_OFF         EQU     0x1A /* 16KB Disable */

SAFETY_ENGINE_TXT_REGION_NUM                    EQU     10
SAFETY_ENGINE_TXT_REGION_SIZE_AND_ENABLE_ON     EQU     0x17 /* 4KB Enable  */
SAFETY_ENGINE_TXT_REGION_SIZE_AND_ENABLE_OFF    EQU     0x16 /* 4KB Disable */

UNKOWN_AREA                                     EQU     0xff /* Error Case */
;/*
;********************************************************************************
;*               MACRO
;********************************************************************************
;*/

        MACRO
$label      MPU_ATTRIBUTE $num, $addr, $offset, $attr, $size

            MOV     r4, $num
            MOV     r5 ,$addr
            ADD     r5, r5, $offset
            MOV     r6, $attr
            MOV     r7, $size

            MCR     p15, 0, r4, c6, c2, 0       ; MPU region selection
            MCR     p15, 0, r5, c6, c1, 0       ; Region address
            MCR     p15, 0, r6, c6, c1, 4       ; Access control
            MCR     p15, 0, r7, c6, c1, 2       ; Size and region enable
        MEND



;/*
;********************************************************************************
;*               INPORT
;********************************************************************************
;*/

    IMPORT  main
    IMPORT  ||Image$$USER_STACK$$ZI$$Limit||
    IMPORT  ||Image$$FAULT_STACK$$ZI$$Limit||
    IMPORT  ||Image$$SAFETY_ENGINE_TXT$$Base||
    IMPORT  ||Image$$DEBUG_SECTION$$Base||
    IMPORT  ||Image$$DEBUG_DATA_SECTION$$Base||

    #ifdef BL1_
        IMPORT  NC_Undefined_Handler
        IMPORT  NC_Prefetch_Handler
        IMPORT  NC_Abort_Handler
    #else
        ; BL2_
        IMPORT  ||Image$$IRQ_STACK$$ZI$$Limit||
        IMPORT  ||Image$$FIQ_STACK$$ZI$$Limit||
        IMPORT  ncDrv_INTC_IRQHandler
        IMPORT  ncDrv_INTC_FIQHandler
    #endif



;/*
;********************************************************************************
;*               EXPORT
;********************************************************************************
;*/

    ; Used Linker
    EXPORT  VECTOR_TABLE

    ; Used C-Function
    EXPORT  ASM_INT_ENABLE
    EXPORT  ASM_INT_DISABLE
    EXPORT  ASM_DCACHE_FLUSH
    EXPORT  ASM_PC_JUMP
    EXPORT  NC_MPU_GET_REGION_AREA
    EXPORT  NC_MPU_SET_REGION_SAFETY_ENGINE_TXT
    EXPORT  NC_MPU_SET_REGION_DEBUG_SECTION
    EXPORT  NC_MPU_SET_REGION_DEBUG_DATA_SECTION
    EXPORT  _sys_exit



;/*
;********************************************************************************
;*               ASM FUNCTION
;********************************************************************************
;*/

    ;----------------------------------------------------------------------------
    ; Entry point for the application (for Linker)
    ;----------------------------------------------------------------------------
        ENTRY




    ;----------------------------------------------------------------------------
    ; ARM Vector Table
    ;----------------------------------------------------------------------------
VECTOR_TABLE
    #ifdef BL1_
        B       Reset_Handler                   ; [1] 0x0000_0000 - SVC Mode (The world is start here)
        B       Undefined_Handler               ; [6] 0x0000_0004 - UNDF Mode
        B       Abort_Handler                   ; [6] 0x0000_0008 - SVC Mode(SWI)
        B       Prefetch_Handler                ; [5] 0x0000_000C - ABT Mode
        B       Abort_Handler                   ; [2] 0x0000_0010 - ABT Mode
        NOP                                     ; [x] 0x0000_0014 - Reserved
        B       Abort_Handler                   ; [4] 0x0100_0018 - IRQ Mode
        B       Abort_Handler                   ; [4] 0x0100_001C - FIQ Mode
    #else
        ; BL2_
        B       Reset_Handler                   ; [x] 0x0100_0000 - BL1->BL2 Jump Point
        NOP                                     ; [x] 0x0100_0004 - Reserved
        NOP                                     ; [x] 0x0100_0008 - Reserved
        NOP                                     ; [x] 0x0100_000C - Reserved
        NOP                                     ; [x] 0x0100_0010 - Reserved
        NOP                                     ; [x] 0x0100_0014 - Reserved
        B       IRQ_Handler                     ; [4] 0x0100_0018 - IRQ Mode
        B       FIQ_Handler                     ; [3] 0x0100_001C - FIQ Mode
    #endif




    ;----------------------------------------------------------------------------
    ; Rest Vactor Handler
    ;----------------------------------------------------------------------------
Reset_Handler
    BL      ASM_INT_DISABLE
    BL      ASM_CACHE_DISABLE
    BL      ASM_SET_STACK
    BL      ASM_CNT_ENABLE
    BL      ASM_MPU_INIT

    #ifdef BL2_
        BL  ASM_TCM_INIT
        BL  ASM_FPU_INIT
        BL  ASM_CACHE_ENABLE
    #endif

    #ifdef BL1_
        BL  TM_AHB_MODE_CHECK
    #endif

    BL      main
    B       .



    ;----------------------------------------------------------------------------
    ; Booting Failure - Wait for FW Download (for Nextune)
    ;----------------------------------------------------------------------------
Loop_Handler
    B       Loop_Handler




    ;----------------------------------------------------------------------------
    ;  Core Mode Register Control Functions
    ;----------------------------------------------------------------------------
ASM_SET_STACK
    MSR     SPSR_cxsf,#ARM_MODE_SVC             ; Set SVC Mode

    MOV     r0,  #0
    MOV     r1,  #0
    MOV     r2,  #0
    MOV     r3,  #0
    MOV     r4,  #0
    MOV     r5,  #0
    MOV     r6,  #0
    MOV     r7,  #0
    MOV     r8,  #0
    MOV     r9,  #0
    MOV     r10, #0
    MOV     r11, #0
    MOV     r12, #0

    MOV     r0, #ARM_MODE_FIQ
    MSR     CPSR_c, r0
    MOV     r8,  #0
    MOV     r9,  #0
    MOV     r10, #0
    MOV     r11, #0
    MOV     r12, #0
    MOV     r13, r1                             ;the use of the SP in an ARM instruction, in any way that is not possible in the corresponding Thumb instruction, is deprecated.
    MOV     r14, #0
    #ifdef BL2_
        LDR sp, =||Image$$FIQ_STACK$$ZI$$Limit||
    #endif

    MOV     r0, #ARM_MODE_IRQ
    MSR     CPSR_c, r0
    MOV     r13, r1
    MOV     r14, #0
    #ifdef BL2_
        LDR sp, =||Image$$IRQ_STACK$$ZI$$Limit||
    #endif

    MOV     r0, #ARM_MODE_ABT
    MSR     CPSR_c, r0
    MOV     r13, r1
    MOV     r14, #0
    LDR     sp, =||Image$$FAULT_STACK$$ZI$$Limit||

    MOV     r0, #ARM_MODE_UNDEF
    MSR     CPSR_c, r0
    MOV     r13, r1
    MOV     r14, #0
    LDR     sp, =||Image$$FAULT_STACK$$ZI$$Limit||

    MOV     r0, #ARM_MODE_SVC
    MSR     CPSR_c, r0
    LDR     sp, =||Image$$USER_STACK$$ZI$$Limit||
    CPSID   i
    CPSID   f

    BX      lr


    ;----------------------------------------------------------------------------
    ;  Jump
    ;----------------------------------------------------------------------------
    ; void ASM_PC_JUMP(void);
ASM_PC_JUMP
    BX r0


    ;----------------------------------------------------------------------------
    ;  Exit
    ;----------------------------------------------------------------------------
    ; void _sys_exit(void);
_sys_exit   PROC
    NOP
    B       .
    ENDP


    ;----------------------------------------------------------------------------
    ;  Cache Control Functions
    ;----------------------------------------------------------------------------
ASM_DCACHE_FLUSH
    ; void ASM_DCACHE_FLUSH(UINT32 Addr, UINT32 Size);
    ; param : r0(Start Address), r1(Size)
    ; clean and invalidate data cache
    ADD     r1, r1, r0                          ; r1 - End Address (Start + Size)
    ADD     r1, r1, #0x20                       ; Consider a non-aligned buffer, giving a dummy.
dcache_next_line
    MCR     p15, 0, r0, c7, c14, 1              ; DCCIMVAC - Clean and invalidate data cache line by MVA to PoC
    ADDCC   r0, r0, #0x20                       ; Cache Flush Line Unit - 0x20
    CMP     r0, r1                              ; Compare
    BCC     dcache_next_line                    ; if not End -> Next Line
    MOV     r0, #0
    MCR     p15, 0, r0, c7, c10, 4              ; CP15DSB - Data Synchronization Barrier operation
    BX      lr


ASM_CACHE_DISABLE
    ; Disable caches, this code is harmless if no cache support.
    MRC     p15, 0, r1, c1, c0, 0               ; Read SCTLR configuration data
    BIC     r1, r1, #0x1 <<12                   ; instruction cache disable
    BIC     r1, r1, #0x1 <<2                    ; data cache disable
    BIC     r1, r1, #0x1 <<0                    ; MPU Disable
    DSB
    MCR     p15, 0, r1, c1, c0, 0               ; disabled cache RAMs
    ISB

    MOV     r1, #0
    DSB
    MCR     p15, 0, r1,  c7, c5, 0              ; Invalidate all I-Cache
    MCR     p15, 0, r1, c15, c5, 0              ; Invalidate all D-Cache
    ISB
    BX      lr


ASM_CACHE_ENABLE
    ; Enable caches, this code is harmless if no cache support.
    MRC     p15, 0, r1, c1, c0, 0               ; Read SCTLR configuration data
    ORR     r1, r1, #0x1 <<12                   ; instruction cache enable
    ORR     r1, r1, #0x1 <<2                    ; data cache enable
    DSB
    MOV     r0, #0
    MCR     p15, 0, r0, c15, c5, 0              ; Invalidate all D-Cache
    MCR     p15, 0, r0,  c7, c5, 0              ; Invalidate all I-Cache
    MCR     p15, 0, r1,  c1, c0, 0              ; enabled cache RAMs
    ISB
    BX      lr



    ;----------------------------------------------------------------------------
    ;  MPU Control Functions
    ;----------------------------------------------------------------------------
ASM_MPU_INIT
    MPU_ATTRIBUTE #0,  #0x00000000, #0x00000000, #0x30B,  #0x1F     ;  64K, Mem  : cacheable     : Memory - IROM(64K)
    MPU_ATTRIBUTE #1,  #0x01000000, #0x00000000, #0x30B,  #0x27     ;   1M, Mem  : cacheable     : Memory - IRAM(896K) : Used HEAP/STACK
    MPU_ATTRIBUTE #2,  #0x03000000, #0x00000000, #0x310,  #0x2F     ;  16M, Mem  : non-cacheable : Memory - CPU0(LC)  : ATCM(8K),BTCM(8K)
    MPU_ATTRIBUTE #3,  #0x04000000, #0x00000000, #0x300,  #0x33     ;  64M, Peri : non-cacheable : IP Control ... etc
    MPU_ATTRIBUTE #4,  #0x08000000, #0x00000000, #0x300,  #0x35     ; 128M, Peri : non-cacheable : IP Control ... etc
    MPU_ATTRIBUTE #5,  #0x10000000, #0x00000000, #0x300,  #0x37     ; 256M, Peri : non-cacheable : IP Control ... etc
    MPU_ATTRIBUTE #6,  #0x20000000, #0x00000000, #0x300,  #0x37     ; 256M, Peri : non-cacheable : IP Control ... etc
    MPU_ATTRIBUTE #7,  #0x30000000, #0x00000000, #0x300,  #0x37     ; 256M, Peri : non-cacheable : IP Control ... etc
    LDR     r0, =||Image$$DEBUG_DATA_SECTION$$Base||
    MPU_ATTRIBUTE #DEBUG_DATA_SECTION_REGION_NUM,        r0, #0x00000000, #0xB, #DEBUG_DATA_SECTION_REGION_SIZE_AND_ENABLE_ON     ; 128Byte, Mem : cacheable : uart, usb variable
    LDR     r0, =||Image$$DEBUG_SECTION$$Base||
    MPU_ATTRIBUTE #DEBUG_SECTION_REGION_NUM,        r0, #0x00000000, #0xB, #DEBUG_SECTION_REGION_SIZE_AND_ENABLE_ON               ; 16K,     Mem : cacheable : uart, usb code
    LDR     r0, =||Image$$SAFETY_ENGINE_TXT$$Base||
    MPU_ATTRIBUTE #SAFETY_ENGINE_TXT_REGION_NUM,    r0, #0x00000000, #0xB, #SAFETY_ENGINE_TXT_REGION_SIZE_AND_ENABLE_ON           ; 4K,      Mem : cacheable : Memory - IROM(64K)

    DSB
    MRC     p15, 0, r1, c1, c0, 0               ; Read CP15 Control Register
    ORR     r1, r1, #(0x1 << 0)                 ; MPU Enable
    DSB
    MCR     p15, 0, r1, c1, c0, 0               ; Write CP15 Control Register
    ISB
    BX      lr

GET_SAFETY_ENGINE_TXT_REGION_BASE_ADDR
    LDR     r0, =||Image$$SAFETY_ENGINE_TXT$$Base||
    BX      lr
    
GET_DEBUG_SECTION_REGION_BASE_ADDR
    LDR     r0, =||Image$$DEBUG_SECTION$$Base||
    BX      lr

GET_DEBUG_DATA_SECTION_REGION_BASE_ADDR
    LDR     r0, =||Image$$DEBUG_SECTION$$Base||
    BX      lr

RET_UNKOWN_AREA
    LDR     r0, =UNKOWN_AREA
    BX      lr
    
NEXT_CHECK_AREA_2
    CMP     r0, #3
    BEQ     GET_DEBUG_DATA_SECTION_REGION_BASE_ADDR
    BNE     RET_UNKOWN_AREA

NEXT_CHECK_AREA_1
    CMP     r0, #2
    BEQ     GET_DEBUG_SECTION_REGION_BASE_ADDR
    BNE     NEXT_CHECK_AREA_2

NC_MPU_GET_REGION_AREA
    CMP     r0, #1
    BEQ     GET_SAFETY_ENGINE_TXT_REGION_BASE_ADDR
    BNE     NEXT_CHECK_AREA_1
    BX      lr

;R5 TRM 4.1.2 MPU control and configuration
;MCR    p15(cp15), 0(fixed), rN(input value), cN, cM, Num ; [cN, cM, Num is (register mapping)]

NC_MPU_SET_REGION_SAFETY_ENGINE_TXT
    PUSH    {r2-r3,lr}
    LDR     r2, =SAFETY_ENGINE_TXT_REGION_SIZE_AND_ENABLE_ON
    LDR     r3, =SAFETY_ENGINE_TXT_REGION_NUM
    DSB
    MCR     p15, 0, r3,  c6,  c2, 0 ; Memory Region Number Register
    ISB     ; fetch
    MCR     p15, 0, r0,  c6,  c1, 0 ; Region Base Register
    MCR     p15, 0, r1,  c6,  c1, 4 ; Region Access Control Register (4-57 page MPU Region Access Control REgister bit assignments 표 참조)
    MCR     p15, 0, r2,  c6,  c1, 2 ; Region Size and Enable Regitser
    DSB
    ISB
    POP     {r2-r3,lr}
    BX      lr

;R5 TRM 4.1.2 MPU control and configuration
;MCR    p15(cp15), 0(fixed), rN(input value), cN, cM, Num ; [cN, cM, Num is (register mapping)]
NC_MPU_SET_REGION_DEBUG_SECTION
    PUSH    {r2-r3,lr}
    LDR     r2, =DEBUG_SECTION_REGION_SIZE_AND_ENABLE_ON
    LDR     r3, =DEBUG_SECTION_REGION_NUM
    DSB
    MCR     p15, 0, r3,  c6,  c2, 0 ; Memory Region Number Register
    ISB     ; fetch
    MCR     p15, 0, r0,  c6,  c1, 0 ; Region Base Register
    MCR     p15, 0, r1,  c6,  c1, 4 ; Region Access Control Register (4-57 page MPU Region Access Control REgister bit assignments 표 참조)
    MCR     p15, 0, r2,  c6,  c1, 2 ; Region Size and Enable Regitser
    DSB
    ISB
    POP     {r2-r3,lr}
    BX      lr

NC_MPU_SET_REGION_DEBUG_DATA_SECTION
    PUSH    {r2-r3,lr}
    LDR     r2, =DEBUG_DATA_SECTION_REGION_SIZE_AND_ENABLE_ON
    LDR     r3, =DEBUG_DATA_SECTION_REGION_NUM
    DSB
    MCR     p15, 0, r3,  c6,  c2, 0 ; Memory Region Number Register
    ISB     ; fetch
    MCR     p15, 0, r0,  c6,  c1, 0 ; Region Base Register
    MCR     p15, 0, r1,  c6,  c1, 4 ; Region Access Control Register (4-57 page MPU Region Access Control REgister bit assignments 표 참조)
    MCR     p15, 0, r2,  c6,  c1, 2 ; Region Size and Enable Regitser
    DSB
    ISB
    POP     {r2-r3,lr}
    BX      lr
    ;----------------------------------------------------------------------------
    ;  INT Control Functions
    ;----------------------------------------------------------------------------
ASM_INT_ENABLE
    CPSIE   i                               	; IRQ Enable
    CPSIE   f                               	; FIQ Enable
    BX      lr

ASM_INT_DISABLE
    CPSID   i                                   ; IRQ Disable
    CPSID   f                                   ; FIQ Disable
    BX      lr


    #ifdef BL2_
    ;----------------------------------------------------------------------------
    ;  TCM Control Functions
    ;----------------------------------------------------------------------------
TCM_ZERO_INIT
    MOV     r0, r3                              ; r3 address
    MOV     r1, #0x0                            ; r1 counter
    B       Lable1


Lable2
    MOV     r2, #0x0
    STR     r2, [r0]
    ADD     r0, r0, #0x4
    ADD     r1, r1, #0x4


Lable1
    CMP     r1, r4                              ; r4 size
    BCC     Lable2
    BX      lr


BTCM_RMW_DISABLE
    MRC     p15, 0, r0, c15, c0, 0
    BIC     r0, r0, #1<<1
    MCR     p15, 0, r0, c15, c0, 0
    BX      lr


BTCM_RMW_ENABLE
    MRC     p15, 0, r0, c15, c0, 0
    ORR     r0, r0, #1<<1
    MCR     p15, 0, r0, c15, c0, 0
    BX      lr


BTCM_ECC_DISABLE
    MRC     p15, 0, r0, c1, c0, 1
    BIC     r0, r0, #3<<1
    BIC     r0, r0, #3<<26
    MCR     p15, 0, r0, c1, c0, 1
    BX      lr


BTCM_ECC_ENABLE
    MRC     p15, 0, r0, c1, c0, 1
    ORR     r0, r0, #3<<1
    ORR     r0, r0, #3<<26
    MCR     p15, 0, r0, c1, c0, 1
    BX      lr


BTCM_DISABLE
    MRC     p15, 0, r0, c9, c1, 0
    BIC     r0, r0, #0x1
    MCR     p15, 0, r0, c9, c1, 0
    BX      lr


BTCM_ENABLE
    LDR     r0, =APACHE6_BTCM_BASE
    ORR     r0, r0, #0x4<<2
    ORR     r0, r0, #0x1<<0
    MCR     p15, 0, r0, c9, c1, 0
    BX      lr


BTCM_INIT
    MOV     r5, lr
    BL      BTCM_ENABLE

    #if defined(SIM_TCM_NO_INIT_) || (defined(BL2_) && defined(SIM_BL2_TCM_NO_INIT_))
        BL  BTCM_ECC_DISABLE
        BL  BTCM_RMW_DISABLE
    #else
        BL  BTCM_ECC_DISABLE
        BL  BTCM_RMW_ENABLE

        LDR r3, =APACHE6_BTCM_BASE
        MOV r4, #APACHE6_BTCM_SIZE
        BL  TCM_ZERO_INIT

        BL  BTCM_RMW_DISABLE
        BL  BTCM_ECC_ENABLE
    #endif

    MOV     lr, r5
    BX      lr


ATCM_RMW_DISABLE
    MRC     p15, 0, r0, c15, c0, 0
    BIC     r0, r0, #0x1
    MCR     p15, 0, r0, c15, c0, 0
    BX      lr


ATCM_RMW_ENABLE
    MRC     p15, 0, r0, c15, c0, 0
    ORR     r0, r0, #0x1
    MCR     p15, 0, r0, c15, c0, 0
    BX      lr


ATCM_ECC_DISABLE
    MRC     p15, 0, r0, c1, c0, 1
    BIC     r0, r0, #1<<0
    BIC     r0, r0, #1<<25
    MCR     p15, 0, r0, c1, c0, 1
    BX      lr


ATCM_ECC_ENABLE
    MRC     p15, 0, r0, c1, c0, 1
    ORR     r0, r0, #1<<0
    ORR     r0, r0, #1<<25
    MCR     p15, 0, r0, c1, c0, 1
    BX      lr


ATCM_DISABLE
    MRC     p15, 0, r0, c9, c1, 1
    BIC     r0, r0, #0x1
    MCR     p15, 0, r0, c9, c1, 1
    BX      lr


ATCM_ENABLE
    LDR     r0, =APACHE6_ATCM_BASE
    ORR     r0, r0, #0x4<<2
    ORR     r0, r0, #0x1<<0
    MCR     p15, 0, r0, c9, c1, 1
    BX      lr


ATCM_INIT
    MOV     r5, lr
    BL      ATCM_ENABLE

    #if defined(SIM_TCM_NO_INIT_) || (defined(BL2_) && defined(SIM_BL2_TCM_NO_INIT_))
        BL  ATCM_ECC_DISABLE
        BL  ATCM_RMW_DISABLE
    #else
        BL  ATCM_ECC_DISABLE
        BL  ATCM_RMW_ENABLE

        LDR r3, =APACHE6_ATCM_BASE
        MOV r4, #APACHE6_ATCM_SIZE
        BL  TCM_ZERO_INIT

        BL  ATCM_RMW_DISABLE
        BL  ATCM_ECC_ENABLE
    #endif

    MOV     lr, r5
    BX      lr


ASM_TCM_INIT
    MOV     r6, lr
    DSB
    BL      ATCM_INIT
    BL      BTCM_INIT
    ISB
    MOV     lr, r6
    BX      lr

    #endif


    ;----------------------------------------------------------------------------
    ;  FPU Control Functions
    ;----------------------------------------------------------------------------

    #ifdef BL2_
FPU_Enable
    MOV     r5, lr
    MOV     r0, #0x00F00000
    MCR     p15, 0, r0, c1, c0, 2
    MOV     r3, #0x40000000
    MCR     p10, #7, r3, c8, c0, 0          ; enable FPU by writing FPEXC
    MOV     r3, #0
    MCR     p10, #7, r3, c1, c0, 0          ; init FPSR
    MOV     lr, r5
    BX      lr


ASM_FPU_INIT
    MOV     r6, lr
    MRC     p15, 0, r1, c15, c2, 1          ; Read Build OptionsReg2
    TST     r1, #1<<22                      ; bit[22]= FP absent
    BEQ     FPU_Enable
    MOV     lr, r6
    BX      lr
    #endif



    ;----------------------------------------------------------------------------
    ;  APB Count Enable
    ;----------------------------------------------------------------------------
ASM_CNT_ENABLE
        LDR     r0, =0x0C01F044
        MOV     r1, #0x00000000
        STR     r1, [r0]
        LDR     r0, =0x0501EF00
        MOV     r1, #0x00000001
        STR     r1, [r0]
        BX      lr


    ;----------------------------------------------------------------------------
    ; ETC Vector Handler
    ;----------------------------------------------------------------------------

    #ifdef BL1_
Undefined_Handler
        STMFD   sp!, {r0-r12, r14}
        SUB     sp, sp, #12
        MOV     r0, sp
        MRS     r1, SPSR
        MOV     r2, r13
        MOV     r3, r14
        STMIA   r0, {r1, r2-r3}^                ; A1786W : STMIA   r0, {r1, r13-r14}^
        BL      NC_Undefined_Handler
        B       Loop_Handler

Prefetch_Handler
        STMFD   sp!, {r0-r12, r14}
        SUB     sp, sp, #12
        MOV     r0, sp
        MRS     r1, SPSR
        MOV     r2, r13
        MOV     r3, r14
        STMIA   r0, {r1, r2-r3}^                ; A1786W : STMIA   r0, {r1, r13-r14}^
        BL      NC_Prefetch_Handler
        B       Loop_Handler

Abort_Handler
        STMFD   sp!, {r0-r12, r14}
        SUB     sp, sp, #12
        MOV     r0, sp
        MRS     r1, SPSR
        MOV     r2, r13
        MOV     r3, r14
        STMIA   r0, {r1, r2-r3}^                ; A1786W : STMIA   r0, {r1, r13-r14}^
        BL      NC_Abort_Handler
        B       Loop_Handler

    #else
    ; BL2_
IRQ_Handler
        SUB     lr, lr, #4                      ; IRQ PC(-4)
        STMFD   sp!, {lr}                       ; save adjusted LR_IRQ
        MRS     r14, SPSR
        STMFD   sp!, {r12, r14}                 ; save workreg & SPSR_IRQ
        STMFD   sp!, {r0-r3, lr}                ; save LR_USR and non-callee saved registers
        BL      ncDrv_INTC_IRQHandler           ; call C Level IRQ Handler
        LDMFD   sp!, {r0-r3, lr}                ; restore
        LDMFD   sp!, {r12, r14}                 ; restore workreg & SPSR_IRQ
        MSR     SPSR_cf, r14
        LDMFD   sp!, {PC}^                      ; and return

FIQ_Handler
        SUB     lr, lr, #4                      ; FIQ PC(-4)
        STMFD   sp!, {r0-r3, r12, lr}           ; store registers
        BL      ncDrv_INTC_FIQHandler           ; call C Level FIQ Handler
        LDMFD   sp!, {r0-r3, r12, pc}^          ; restore registers and return
    #endif


    ;----------------------------------------------------------------------------
    ; TM_MODE_AHB Control Functions
    ;----------------------------------------------------------------------------
TM_AHB_MODE_CHECK
    LDR r0, =0x0000a5a5         ; 0xa5a5 means this chip will operates test vector function
    LDR r3, =0x0005a5a5         ; 0x5a5a5 means this chip will operates test vector function
    LDR r1, =0x0501F000         ; BLK_SYS_SCU DEBUG0 register address
    LDR r2, [r1, #0x00]         ; Read DEBUG0 register
    CMP r0, r2                  ; Compare DEBUG0 register value with r0 (0xa5a5)
    BEQ TM_AHB_MODE_PLL_MUX_SEL ; If compare result is ture then branch to TM_AHB_MODE_PLL_MUX_SEL
    CMP r3, r2                  ; Compare DEBUG0 register value with r3 (0x5a5a5)
    BEQ TM_AHB_MODE_DUMP_START  ; If compare result is ture then branch to TM_AHB_MODE_DUMP_START
    BX      lr                  ; Branch to linker register point

TM_AHB_MODE_DUMP_START
    LDR r0, =0x00a5a5a5         ; CORE0 write 0xa5a5a5 data to DEBUG0 register to AHB DUMP START
    LDR r1, =0x0501F000         ; BLK_SYS_SCU DEBUG0 register address
    STR r0, [r1, #0x00]         ; Write r0 (0xa5a5a5) data to r1 (0x0501F000) address
    B   TM_AHB_MODE_DUMP_WAIT   ; Branch to TM_AHB_MODE_DUMP_WAIT

TM_AHB_MODE_DUMP_WAIT
    LDR r0, =0xa5a5a5a5         ; AHB_TEST ROM DATA DUMP DONE Condition
    LDR r1, =0x0501F000         ; BLK_SYS_SCU DEBUG0 register address
    LDR r2, [r1, #0x00]         ; Read DEBUG0 register
    CMP r0, r2                  ; Compare DEBUG0 register value with r0 (0xa5a5a5a5)
    BNE TM_AHB_MODE_DUMP_WAIT   ; Jump to DUMP_WAIT to wait AHB DUMP DONE
    B   ASM_PC_JUMP             ; Branch to ASM_PC_JUMP

TM_AHB_MODE_PLL_MUX_SEL
    LDR r0, =0x05010000         ; BLK_SYS_SCU PLL_AWAY_CLKMUX Address
    ADD r0, #0x1000             ; BLK_SYS_SCU PLL_AWAY_CLKMUX Address load to r0
    MOV r1, #0x7                ; The value to write at PLL_AWAY_CLKMUX register
    STR r1, [r0, #0x00]         ; Write 0x7 to PLL_AWAY_CLKMUX (Use PLL AWAY Clock in system)
    B   TM_AHB_MODE_DUMP_START  ; Branch to TM_AHB_MODE_DUMP_START


    ;----------------------------------------------------------------------------
    ; File End
    ;----------------------------------------------------------------------------
__ARM_use_no_argv PROC
    NOP
    ENDP

        END

