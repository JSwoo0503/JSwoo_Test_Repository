/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_ANALOG_Register.h
*   Date       : 2022-08-03 15:20
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_ANALOG_H__
#define DRV_REGISTER_A6_ANALOG_H__

#define APACHE_A6_ANALOG_BASE_ADDR        0x05C20000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 4;      /* [  3:0]  */
            UINT32 SEL_SJTAG                                                              : 1;      /* [    4] SEL_SJTAG_OUTPUT_PATH
                                                                                                               1 EFUSE
                                                                                                               0 OTP DEFAULT */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }ANALOG_CONFIG;
    union { /* 0x0004 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 START                                                                  : 1;      /* [    0] OTP Presesing Start
                                                                                                               1  Start PreSensing
                                                                                                               0  After PreSensing Done need to 0 */
            UINT32 READY                                                                  : 1;      /* [    1] OTP Presesing ready
                                                                                                               1 Ready to presensing
                                                                                                               0 Not-Ready */
            UINT32 DONE                                                                   : 1;      /* [    2] OTP Presesing done
                                                                                                               1  DONE
                                                                                                               0  If START 1 Presesing running Else IDLE */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }OTP_PRE_SENSING_STATE;

    UINT8 EMPTY1[8]; /* 0x8 */

    union { /* 0x0010 [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 VLD_PD                                                                 : 1;      /* [    0] Power-down signal 1 Power down mode */
            UINT32 EN_CHOP                                                                : 1;      /* [    1] Enable signal port for Chopping
                                                                                                               1 Chopping on default
                                                                                                               0 Chopping off */
            UINT32 RESERVED3                                                              : 2;      /* [  3:2]  */
            UINT32 DVLD_OK                                                                : 1;      /* [    4] Digital power detection output flag
                                                                                                               1 Digital power is within normal voltage range
                                                                                                               0 Digital power is out of normal voltage range */
            UINT32 DVLD_DN                                                                : 1;      /* [    5] Digital power low level detection output flag
                                                                                                               1 Digital power is lower than low level detection voltage
                                                                                                               0 Digital power is higher than low level detection voltage */
            UINT32 DVLD_UP                                                                : 1;      /* [    6] Digital power high level detection output flag
                                                                                                               1 Digital power is higher than high level detection voltage
                                                                                                               0 Digital power is lower than high level detection voltage */
            UINT32 RESERVED2                                                              : 1;      /* [    7]  */
            UINT32 AVLD_OK                                                                : 1;      /* [    8] Analog power detection output flag
                                                                                                               1 Analog power is within normal voltage range
                                                                                                               0 Analog power is out of nommal voltage range */
            UINT32 AVLD_DN                                                                : 1;      /* [    9] Analog power low level detection output flag
                                                                                                               1 Analog power is lower than low level detection voltage
                                                                                                               0 Analog power is higher than low level detection voltage */
            UINT32 AVLD_UP                                                                : 1;      /* [   10] Analog power high level detection output flag
                                                                                                               1 Analog power is higher than high level detection voltage
                                                                                                               0 Analog power is lower than high level detection voltage */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }VLD_STATE;
    union { /* 0x0014 [Excel Line :0026]  */
        UINT32 Reg;
        struct {
            UINT32 DVLD_VREF_TRIM                                                         : 4;      /* [  3:0] Reference trimming bits for digital supply voltage level detection
                                                                                                               It improves the accuracy of VLD by trimming the reference voltage
                                                                                                               level for comparator which is used for digital supply voltage level
                                                                                                               detection
                                                                                                               Default value 4b1101 */
            UINT32 AVLD_DN_VREF_TRIM                                                      : 4;      /* [  7:4] Reference trimming bits for analog supply voltage low level
                                                                                                               detection
                                                                                                               It improves the accuracy of VLD by trimming the reference voltage
                                                                                                               level for comparator which is used for analog supply voltage low
                                                                                                               level detection
                                                                                                               Default value 4b1110 */
            UINT32 AVLD_UP_VREF_TRIM                                                      : 4;      /* [ 11:8] Reference trimming bits for analog supply voltage high level
                                                                                                               detection It improves the accuracy of VLD by trimming the
                                                                                                               reference voltage level for comparator which is used for analog
                                                                                                               supply voltage high level detection
                                                                                                               Default value 4b1110 */
            UINT32 VREF_TRIM                                                              : 4;      /* [15:12] Reference trimming bits for band gap reference voltage
                                                                                                               It improves the accuracy of VLD by trimming the BGR voltage level
                                                                                                               Default value 4b1110 */
            UINT32 DVLD_DN_CTRL                                                           : 4;      /* [19:16] Digital supply voltage low level detection control bits
                                                                                                               Default value 4b1011 */
            UINT32 DVLD_UP_CTRL                                                           : 4;      /* [23:20] Digital supply voltage high level detection control bits
                                                                                                               Default value 4b0011 */
            UINT32 AVLD_DN_CTRL                                                           : 4;      /* [27:24] Analog supply voltage low level detection control bits
                                                                                                               Default value 4b1011 */
            UINT32 AVLD_UP_CTRL                                                           : 4;      /* [31:28] Analog supply voltage high level detection control bits
                                                                                                               Default value 4b0100 */
        }Bit;
    }VLD_CONFIG;
    union { /* 0x0018 [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 26;     /* [ 25:0]  */
            UINT32 VLD_DVLD_DW_INT_EN                                                     : 1;      /* [   26] Vld dvld dw interrupt enable bit
                                                                                                               Default value 1b0 */
            UINT32 VLD_DVLD_OK_INT_EN                                                     : 1;      /* [   27] Vld dvld ok interrupt enable bit
                                                                                                               Default value 1b0 */
            UINT32 VLD_DVLD_UP_INT_EN                                                     : 1;      /* [   28] Vld dvld up interrupt enable bit
                                                                                                               Default value 1b0 */
            UINT32 VLD_AVLD_DW_INT_EN                                                     : 1;      /* [   29] Vld avld dw interrupt enable bit
                                                                                                               Default value 1b0 */
            UINT32 VLD_AVLD_OK_INT_EN                                                     : 1;      /* [   30] Vld avld ok interrupt enable bit
                                                                                                               Default value 1b0 */
            UINT32 VLD_AVLD_UP_INT_EN                                                     : 1;      /* [   31] Vld avld up interrupt enable bit
                                                                                                               Default value 1b0 */
        }Bit;
    }VLD_INT_EN;
}DRV_A6_ANALOG_REGISTER;
/* PRQA S 828 -- */

#endif /* end of  DRV_REGISTER_A6_ANALOG__ */

