
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_SYS_SCU_Register.h
*   Date       : 2022-07-08 13:58
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_SYS_SCU_H__
#define DRV_REGISTER_A6_SYS_SCU_H__

#define APACHE_A6_SYS_SCU_BASE_ADDR        0x05010000U

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_DATE                                                           : 32;     /* [ 31:0] Indicates the DATE when this SCU register set was generated
                                                                                                               3116 is Year 158 is Month 70 is Day */
        }Bit;
    }SFR_GEN_DATE;
    union { /* 0x0004 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_TIME                                                           : 32;     /* [ 31:0] Indicates the TIME when this SCU register set was generated
                                                                                                               2316 is Hour 158 is Minute 70 is Second */
        }Bit;
    }SFR_GEN_TIME;
    union { /* 0x0008 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_CHKSUM                                                         : 32;     /* [ 31:0] Indicates the CHECKSUM of scu_regreg_config file */
        }Bit;
    }SFR_GEN_CHKSUM;

    UINT8 EMPTY1[244]; /* 0xF4 */

    union { /* 0x0100 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 SOC_FSM_STATE                                                          : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }SOC_FSM_STATE;
    union { /* 0x0104 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_FSM_STATE                                                      : 4;      /* [  3:0]  */
            UINT32 CPU_PLL_FSM_STATE                                                      : 4;      /* [  7:4]  */
            UINT32 NPU_PLL_FSM_STATE                                                      : 4;      /* [ 11:8]  */
            UINT32 COM_PLL_FSM_STATE                                                      : 4;      /* [15:12]  */
            UINT32 VIDEO0_PLL_FSM_STATE                                                   : 4;      /* [19:16]  */
            UINT32 VIDEO1_PLL_FSM_STATE                                                   : 4;      /* [23:20]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }PLL_FSM_STATE;

    UINT8 EMPTY2[8]; /* 0x8 */

    union { /* 0x0110 [Excel Line :0020]  */
        UINT32 Reg;
        struct {
            UINT32 SOC_TEST_MODE_SEL                                                      : 5;      /* [  4:0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  7:5]  */
            UINT32 SOC_TEST_MODE                                                          : 1;      /* [    8]  */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }SOC_TEST_MODE;

    UINT8 EMPTY3[236]; /* 0xEC */

    union { /* 0x0200 [Excel Line :0024]  */
        UINT32 Reg;
        struct {
            UINT32 STRAP_USER_VAL                                                         : 8;      /* [  7:0]  */
            UINT32 RESERVED3                                                              : 7;      /* [ 14:8]  */
            UINT32 STRAP_USER_UPDATE                                                      : 1;      /* [   15]  */
            UINT32 RESERVED2                                                              : 4;      /* [19:16]  */
            UINT32 STRAP_LATCH_UNLOCK                                                     : 1;      /* [   20]  */
            UINT32 STRAP_LATCH_LOCK                                                       : 1;      /* [   21]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }STRAP_CONTROL;
    union { /* 0x0204 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 STRAP_STATE                                                            : 8;      /* [  7:0]  */
            UINT32 RESERVED2                                                              : 7;      /* [ 14:8]  */
            UINT32 STRAP_LATCH_LOCK_STATE                                                 : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }STRAP_STATE;

    UINT8 EMPTY4[1528]; /* 0x5F8 */

    union { /* 0x0800 [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_ADDR_REMAP                                                         : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }BUS_ADDR_REMAP;

    UINT8 EMPTY5[252]; /* 0xFC */

    union { /* 0x0900 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 JTAG_EXCLUDE_SECURE_CPU                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }JTAG_CHAIN;

    UINT8 EMPTY6[1788]; /* 0x6FC */

    union { /* 0x1000 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SYS_PLL_OUT                                                 : 1;      /* [    0]  */
            UINT32 CLKMUX_SEL_CPU_PLL_OUT                                                 : 1;      /* [    1]  */
            UINT32 CLKMUX_SEL_NPU_PLL_OUT                                                 : 1;      /* [    2]  */
            UINT32 CLKMUX_SEL_COM_PLL_OUT                                                 : 1;      /* [    3]  */
            UINT32 CLKMUX_SEL_VIDEO0_PLL_OUT                                              : 1;      /* [    4]  */
            UINT32 CLKMUX_SEL_VIDEO1_PLL_OUT                                              : 1;      /* [    5]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }PLL_OUT_CLKMUX;

    UINT8 EMPTY7[252]; /* 0xFC */

    union { /* 0x1100 [Excel Line :0046]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SAFETY_PRE1                                                 : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SAFETY_PRE1_CLKMUX;

    UINT8 EMPTY8[28]; /* 0x1C */

    union { /* 0x1120 [Excel Line :0048]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SEN_CK0_PRE1                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK0_PRE1_CLKMUX;
    union { /* 0x1124 [Excel Line :0050]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SEN_CK0                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK0_CLKMUX;
    union { /* 0x1128 [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SEN_CK1_PRE1                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK1_PRE1_CLKMUX;
    union { /* 0x112C [Excel Line :0054]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SEN_CK1                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK1_CLKMUX;

    UINT8 EMPTY9[16]; /* 0x10 */

    union { /* 0x1140 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_ANALOG_PRE1                                                 : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }ANALOG_PRE1_CLKMUX;
    union { /* 0x1144 [Excel Line :0058]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_BUS_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }BUS_PRE1_CLKMUX;
    union { /* 0x1148 [Excel Line :0060]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_BUS_PRE2                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }BUS_PRE2_CLKMUX;

    UINT8 EMPTY10[8]; /* 0x8 */

    union { /* 0x1154 [Excel Line :0062]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_GIC_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GIC_PRE1_CLKMUX;
    union { /* 0x1158 [Excel Line :0064]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_SEC_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEC_PRE1_CLKMUX;
    union { /* 0x115C [Excel Line :0066]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_MEM_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }MEM_PRE1_CLKMUX;

    UINT8 EMPTY11[28]; /* 0x1C */

    union { /* 0x117C [Excel Line :0068]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_PERI_PRE1                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PERI_PRE1_CLKMUX;
    union { /* 0x1180 [Excel Line :0070]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_PERI_PRE2                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PERI_PRE2_CLKMUX;
    union { /* 0x1184 [Excel Line :0072]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_QSPI_PRE1                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }QSPI_PRE1_CLKMUX;
    union { /* 0x1188 [Excel Line :0074]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_CAN_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CAN_PRE1_CLKMUX;
    union { /* 0x118C [Excel Line :0076]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_LIN_PRE1                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }LIN_PRE1_CLKMUX;

    UINT8 EMPTY12[148]; /* 0x94 */

    union { /* 0x1224 [Excel Line :0078]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_SEN_CK0                                                          : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK0_CLKEN;

    UINT8 EMPTY13[4]; /* 0x4 */

    union { /* 0x122C [Excel Line :0080]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_SEN_CK1                                                          : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SEN_CK1_CLKEN;

    UINT8 EMPTY14[3568]; /* 0xDF0 */

    union { /* 0x2020 [Excel Line :0082]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SEN_CK0                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_SEN_CK0_CLKDIV;

    UINT8 EMPTY15[4]; /* 0x4 */

    union { /* 0x2028 [Excel Line :0084]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SEN_CK1                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_SEN_CK1_CLKDIV;

    UINT8 EMPTY16[20]; /* 0x14 */

    union { /* 0x2040 [Excel Line :0086]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_ANALOG_APB                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_ANALOG_APB_CLKDIV;
    union { /* 0x2044 [Excel Line :0088]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_ADC_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_ADC_CORE_CLKDIV;
    union { /* 0x2048 [Excel Line :0090]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_PVT_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_PVT_CORE_CLKDIV;
    union { /* 0x204C [Excel Line :0092]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_VLD_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_VLD_CORE_CLKDIV;
    union { /* 0x2050 [Excel Line :0094]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_BUS_MAIN                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_BUS_MAIN_CLKDIV;

    UINT8 EMPTY17[12]; /* 0xC */

    union { /* 0x2060 [Excel Line :0096]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_BUS_APB                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_BUS_APB_CLKDIV;
    union { /* 0x2064 [Excel Line :0098]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_ACC_APB                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_ACC_APB_CLKDIV;
    union { /* 0x2068 [Excel Line :0100]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_HSP_APB                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_HSP_APB_CLKDIV;
    union { /* 0x206C [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SYS_APB                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_SYS_APB_CLKDIV;

    UINT8 EMPTY18[32]; /* 0x20 */

    union { /* 0x2090 [Excel Line :0104]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GIC                                                         : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_GIC_CLKDIV;

    UINT8 EMPTY19[12]; /* 0xC */

    union { /* 0x20A0 [Excel Line :0106]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CMRT                                                        : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_CMRT_CLKDIV;
    union { /* 0x20A4 [Excel Line :0108]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EIP                                                         : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_EIP_CLKDIV;

    UINT8 EMPTY20[8]; /* 0x8 */

    union { /* 0x20B0 [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_IRAM                                                        : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_IRAM_CLKDIV;
    union { /* 0x20B4 [Excel Line :0112]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_IROM                                                        : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_IROM_CLKDIV;

    UINT8 EMPTY21[136]; /* 0x88 */

    union { /* 0x2140 [Excel Line :0114]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_PERI_AXI                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_PERI_AXI_CLKDIV;
    union { /* 0x2144 [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_PERI_APB                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_PERI_APB_CLKDIV;
    union { /* 0x2148 [Excel Line :0118]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CHANGE_PERI                                                 : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VAL_PERI_APB_CLKDIV_CHANGE;

    UINT8 EMPTY22[4]; /* 0x4 */

    union { /* 0x2150 [Excel Line :0120]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SPI_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_SPI_CORE_CLKDIV;
    union { /* 0x2154 [Excel Line :0122]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_I2C_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_I2C_CORE_CLKDIV;
    union { /* 0x2158 [Excel Line :0124]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_UART_CORE                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_UART_CORE_CLKDIV;
    union { /* 0x215C [Excel Line :0126]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_PWM_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_PWM_CORE_CLKDIV;
    union { /* 0x2160 [Excel Line :0128]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_QSPI_CORE                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_QSPI_CORE_CLKDIV;

    UINT8 EMPTY23[12]; /* 0xC */

    union { /* 0x2170 [Excel Line :0130]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_LIN_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_LIN_CORE_CLKDIV;

    UINT8 EMPTY24[12]; /* 0xC */

    union { /* 0x2180 [Excel Line :0132]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CAN_CORE                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_CAN_CORE_CLKDIV;

    UINT8 EMPTY25[3724]; /* 0xE8C */

    union { /* 0x3010 [Excel Line :0134]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_SYS_SAFETY_CORE                                                  : 1;      /* [    0]  */
            UINT32 CLKEN_MEM_SAFETY_CORE                                                  : 1;      /* [    1]  */
            UINT32 CLKEN_CPU_SAFETY_CORE                                                  : 1;      /* [    2]  */
            UINT32 CLKEN_GIC_SAFETY_CORE                                                  : 1;      /* [    3]  */
            UINT32 CLKEN_BUS_SAFETY_CORE                                                  : 1;      /* [    4]  */
            UINT32 CLKEN_DDR0_SAFETY_CORE                                                 : 1;      /* [    5]  */
            UINT32 CLKEN_DDR1_SAFETY_CORE                                                 : 1;      /* [    6]  */
            UINT32 CLKEN_SECURITY_SAFETY_CORE                                             : 1;      /* [    7]  */
            UINT32 CLKEN_PERI_SAFETY_CORE                                                 : 1;      /* [    8]  */
            UINT32 CLKEN_ANALOG_SAFETY_CORE                                               : 1;      /* [    9]  */
            UINT32 CLKEN_NPU_SAFETY_CORE                                                  : 1;      /* [   10]  */
            UINT32 CLKEN_HWA_SAFETY_CORE                                                  : 1;      /* [   11]  */
            UINT32 CLKEN_GPU_SAFETY_CORE                                                  : 1;      /* [   12]  */
            UINT32 CLKEN_ACC_SAFETY_CORE                                                  : 1;      /* [   13]  */
            UINT32 CLKEN_HSP_SAFETY_CORE                                                  : 1;      /* [   14]  */
            UINT32 RESERVED3                                                              : 1;      /* [   15]  */
            UINT32 CLKEN_VISION0_SAFETY_CORE                                              : 1;      /* [   16]  */
            UINT32 CLKEN_VISION1_SAFETY_CORE                                              : 1;      /* [   17]  */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 CLKEN_USB_SAFETY_CORE                                                  : 1;      /* [   20]  */
            UINT32 CLKEN_PCIE_SAFETY_CORE                                                 : 1;      /* [   21]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }SAFETY_CORE_CLKEN;

    UINT8 EMPTY26[44]; /* 0x2C */

    union { /* 0x3040 [Excel Line :0156]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED7                                                              : 1;      /* [    0]  */
            UINT32 CLKEN_BUS_APB                                                          : 1;      /* [    1]  */
            UINT32 RESERVED6                                                              : 6;      /* [  7:2]  */
            UINT32 CLKEN_BLK_MEM                                                          : 1;      /* [    8]  */
            UINT32 CLKEN_IROM                                                             : 1;      /* [    9]  */
            UINT32 CLKEN_IRAM                                                             : 1;      /* [   10]  */
            UINT32 RESERVED5                                                              : 1;      /* [   11]  */
            UINT32 CLKEN_ANALOG_APB                                                       : 1;      /* [   12]  */
            UINT32 RESERVED4                                                              : 1;      /* [   13]  */
            UINT32 CLKEN_BLK_SYS_SCU                                                      : 1;      /* [   14]  */
            UINT32 CLKEN_BLK_PMU                                                          : 1;      /* [   15]  */
            UINT32 CLKEN_BLK_ICU                                                          : 1;      /* [   16]  */
            UINT32 RESERVED3                                                              : 3;      /* [19:17]  */
            UINT32 CLKEN_GIC_APB                                                          : 1;      /* [   20]  */
            UINT32 CLKEN_GIC_R5                                                           : 1;      /* [   21]  */
            UINT32 CLKEN_GIC_A65_FDC                                                      : 1;      /* [   22]  */
            UINT32 CLKEN_GIC_A65                                                          : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 CLKEN_BLK_SAFETY                                                       : 1;      /* [   28]  */
            UINT32 CLKEN_TEST_MST                                                         : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }SYS_CLKEN_0;
    union { /* 0x3044 [Excel Line :0177]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_PERI0_APB                                                        : 1;      /* [    0]  */
            UINT32 CLKEN_PERI1_APB                                                        : 1;      /* [    1]  */
            UINT32 CLKEN_DMAC0_AXI                                                        : 1;      /* [    2]  */
            UINT32 CLKEN_DMAC1_AXI                                                        : 1;      /* [    3]  */
            UINT32 CLKEN_UART0_CORE                                                       : 1;      /* [    4]  */
            UINT32 CLKEN_UART1_CORE                                                       : 1;      /* [    5]  */
            UINT32 CLKEN_UART2_CORE                                                       : 1;      /* [    6]  */
            UINT32 CLKEN_UART3_CORE                                                       : 1;      /* [    7]  */
            UINT32 CLKEN_UART0_APB                                                        : 1;      /* [    8]  */
            UINT32 CLKEN_UART1_APB                                                        : 1;      /* [    9]  */
            UINT32 CLKEN_UART2_APB                                                        : 1;      /* [   10]  */
            UINT32 CLKEN_UART3_APB                                                        : 1;      /* [   11]  */
            UINT32 CLKEN_TIMER0_APB                                                       : 1;      /* [   12]  */
            UINT32 CLKEN_TIMER1_APB                                                       : 1;      /* [   13]  */
            UINT32 CLKEN_TIMER2_APB                                                       : 1;      /* [   14]  */
            UINT32 RESERVED4                                                              : 1;      /* [   15]  */
            UINT32 CLKEN_QSPI_CORE                                                        : 1;      /* [   16]  */
            UINT32 CLKEN_QSPI_APB                                                         : 1;      /* [   17]  */
            UINT32 RESERVED3                                                              : 2;      /* [19:18]  */
            UINT32 CLKEN_SPI0_CORE                                                        : 1;      /* [   20]  */
            UINT32 CLKEN_SPI1_CORE                                                        : 1;      /* [   21]  */
            UINT32 CLKEN_SPI2_CORE                                                        : 1;      /* [   22]  */
            UINT32 CLKEN_SPI0_APB                                                         : 1;      /* [   23]  */
            UINT32 CLKEN_SPI1_APB                                                         : 1;      /* [   24]  */
            UINT32 CLKEN_SPI2_APB                                                         : 1;      /* [   25]  */
            UINT32 RESERVED2                                                              : 2;      /* [27:26]  */
            UINT32 CLKEN_PWM_CORE                                                         : 1;      /* [   28]  */
            UINT32 CLKEN_PWM_APB                                                          : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }SYS_CLKEN_1;
    union { /* 0x3048 [Excel Line :0206]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_I2C0_CORE                                                        : 1;      /* [    0]  */
            UINT32 CLKEN_I2C1_CORE                                                        : 1;      /* [    1]  */
            UINT32 CLKEN_I2C2_CORE                                                        : 1;      /* [    2]  */
            UINT32 CLKEN_I2C3_CORE                                                        : 1;      /* [    3]  */
            UINT32 CLKEN_I2C4_CORE                                                        : 1;      /* [    4]  */
            UINT32 CLKEN_I2C5_CORE                                                        : 1;      /* [    5]  */
            UINT32 CLKEN_I2C6_CORE                                                        : 1;      /* [    6]  */
            UINT32 CLKEN_I2C7_CORE                                                        : 1;      /* [    7]  */
            UINT32 CLKEN_I2C0_APB                                                         : 1;      /* [    8]  */
            UINT32 CLKEN_I2C1_APB                                                         : 1;      /* [    9]  */
            UINT32 CLKEN_I2C2_APB                                                         : 1;      /* [   10]  */
            UINT32 CLKEN_I2C3_APB                                                         : 1;      /* [   11]  */
            UINT32 CLKEN_I2C4_APB                                                         : 1;      /* [   12]  */
            UINT32 CLKEN_I2C5_APB                                                         : 1;      /* [   13]  */
            UINT32 CLKEN_I2C6_APB                                                         : 1;      /* [   14]  */
            UINT32 CLKEN_I2C7_APB                                                         : 1;      /* [   15]  */
            UINT32 CLKEN_CAN0_CORE                                                        : 1;      /* [   16]  */
            UINT32 CLKEN_CAN1_CORE                                                        : 1;      /* [   17]  */
            UINT32 CLKEN_CAN0_APB                                                         : 1;      /* [   18]  */
            UINT32 CLKEN_CAN1_APB                                                         : 1;      /* [   19]  */
            UINT32 CLKEN_LIN0_CORE                                                        : 1;      /* [   20]  */
            UINT32 CLKEN_LIN1_CORE                                                        : 1;      /* [   21]  */
            UINT32 CLKEN_LIN0_APB                                                         : 1;      /* [   22]  */
            UINT32 CLKEN_LIN1_APB                                                         : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 CLKEN_I2S_APB                                                          : 1;      /* [   28]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }SYS_CLKEN_2;

    UINT8 EMPTY27[4]; /* 0x4 */

    union { /* 0x3050 [Excel Line :0233]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_ACC_APB                                                          : 1;      /* [    0]  */
            UINT32 CLKEN_BLK_NPU_APB                                                      : 1;      /* [    1]  */
            UINT32 RESERVED2                                                              : 6;      /* [  7:2]  */
            UINT32 CLKEN_BLK_SEC_APB                                                      : 1;      /* [    8]  */
            UINT32 CLKEN_EIP                                                              : 1;      /* [    9]  */
            UINT32 CLKEN_CMRT                                                             : 1;      /* [   10]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }SYS_CLKEN_4;
    union { /* 0x3054 [Excel Line :0240]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_HSP_APB                                                          : 1;      /* [    0]  */
            UINT32 CLKEN_ETH_APB                                                          : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }SYS_CLKEN_5;
    union { /* 0x3058 [Excel Line :0243]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_BLK_USB_APB                                                      : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 CLKEN_BLK_PCIE_APB                                                     : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }SYS_CLKEN_6;

    UINT8 EMPTY28[228]; /* 0xE4 */

    union { /* 0x3140 [Excel Line :0247]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_PVT_CORE                                                         : 1;      /* [    0]  */
            UINT32 CLKEN_ADC_CORE                                                         : 1;      /* [    1]  */
            UINT32 CLKEN_VLD_CORE                                                         : 1;      /* [    2]  */
            UINT32 CLKEN_OTP_CORE                                                         : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }SYS_CLKEN_7;

    UINT8 EMPTY29[3772]; /* 0xEBC */

    union { /* 0x4000 [Excel Line :0252]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_BUS_MAIN                                                  : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_BUS_APB                                                   : 1;      /* [    1]  */
            UINT32 RESERVED5                                                              : 6;      /* [  7:2]  */
            UINT32 ONGO_RST_ACT_BLK_MEM                                                   : 1;      /* [    8]  */
            UINT32 ONGO_RST_ACT_IROM                                                      : 1;      /* [    9]  */
            UINT32 ONGO_RST_ACT_IRAM                                                      : 1;      /* [   10]  */
            UINT32 RESERVED4                                                              : 1;      /* [   11]  */
            UINT32 ONGO_RST_ACT_ANALOG_APB                                                : 1;      /* [   12]  */
            UINT32 ONGO_RST_ACT_SYS_APB                                                   : 1;      /* [   13]  */
            UINT32 ONGO_RST_ACT_BLK_SYS_SCU                                               : 1;      /* [   14]  */
            UINT32 ONGO_RST_ACT_BLK_PMU                                                   : 1;      /* [   15]  */
            UINT32 ONGO_RST_ACT_BLK_ICU                                                   : 1;      /* [   16]  */
            UINT32 RESERVED3                                                              : 3;      /* [19:17]  */
            UINT32 ONGO_RST_ACT_GIC_APB                                                   : 1;      /* [   20]  */
            UINT32 ONGO_RST_ACT_GIC_R5                                                    : 1;      /* [   21]  */
            UINT32 ONGO_RST_ACT_GIC_A65_FDC                                               : 1;      /* [   22]  */
            UINT32 ONGO_RST_ACT_GIC_A65                                                   : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 ONGO_RST_ACT_BLK_SAFETY                                                : 1;      /* [   28]  */
            UINT32 ONGO_RST_ACT_TEST_MST                                                  : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }ONGO_RST_ACT_0;
    union { /* 0x4004 [Excel Line :0273]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_PERI0_APB                                                 : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_PERI1_APB                                                 : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_DMAC0_AXI                                                 : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_DMAC1_AXI                                                 : 1;      /* [    3]  */
            UINT32 ONGO_RST_ACT_UART0_CORE                                                : 1;      /* [    4]  */
            UINT32 ONGO_RST_ACT_UART1_CORE                                                : 1;      /* [    5]  */
            UINT32 ONGO_RST_ACT_UART2_CORE                                                : 1;      /* [    6]  */
            UINT32 ONGO_RST_ACT_UART3_CORE                                                : 1;      /* [    7]  */
            UINT32 ONGO_RST_ACT_UART0_APB                                                 : 1;      /* [    8]  */
            UINT32 ONGO_RST_ACT_UART1_APB                                                 : 1;      /* [    9]  */
            UINT32 ONGO_RST_ACT_UART2_APB                                                 : 1;      /* [   10]  */
            UINT32 ONGO_RST_ACT_UART3_APB                                                 : 1;      /* [   11]  */
            UINT32 ONGO_RST_ACT_TIMER0_APB                                                : 1;      /* [   12]  */
            UINT32 ONGO_RST_ACT_TIMER1_APB                                                : 1;      /* [   13]  */
            UINT32 ONGO_RST_ACT_TIMER2_APB                                                : 1;      /* [   14]  */
            UINT32 RESERVED4                                                              : 1;      /* [   15]  */
            UINT32 ONGO_RST_ACT_QSPI_CORE                                                 : 1;      /* [   16]  */
            UINT32 ONGO_RST_ACT_QSPI_APB                                                  : 1;      /* [   17]  */
            UINT32 RESERVED3                                                              : 2;      /* [19:18]  */
            UINT32 ONGO_RST_ACT_SPI0_CORE                                                 : 1;      /* [   20]  */
            UINT32 ONGO_RST_ACT_SPI1_CORE                                                 : 1;      /* [   21]  */
            UINT32 ONGO_RST_ACT_SPI2_CORE                                                 : 1;      /* [   22]  */
            UINT32 ONGO_RST_ACT_SPI0_APB                                                  : 1;      /* [   23]  */
            UINT32 ONGO_RST_ACT_SPI1_APB                                                  : 1;      /* [   24]  */
            UINT32 ONGO_RST_ACT_SPI2_APB                                                  : 1;      /* [   25]  */
            UINT32 RESERVED2                                                              : 2;      /* [27:26]  */
            UINT32 ONGO_RST_ACT_PWM_CORE                                                  : 1;      /* [   28]  */
            UINT32 ONGO_RST_ACT_PWM_APB                                                   : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }ONGO_RST_ACT_1;
    union { /* 0x4008 [Excel Line :0302]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_I2C0_CORE                                                 : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_I2C1_CORE                                                 : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_I2C2_CORE                                                 : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_I2C3_CORE                                                 : 1;      /* [    3]  */
            UINT32 ONGO_RST_ACT_I2C4_CORE                                                 : 1;      /* [    4]  */
            UINT32 ONGO_RST_ACT_I2C5_CORE                                                 : 1;      /* [    5]  */
            UINT32 ONGO_RST_ACT_I2C6_CORE                                                 : 1;      /* [    6]  */
            UINT32 ONGO_RST_ACT_I2C7_CORE                                                 : 1;      /* [    7]  */
            UINT32 ONGO_RST_ACT_I2C0_APB                                                  : 1;      /* [    8]  */
            UINT32 ONGO_RST_ACT_I2C1_APB                                                  : 1;      /* [    9]  */
            UINT32 ONGO_RST_ACT_I2C2_APB                                                  : 1;      /* [   10]  */
            UINT32 ONGO_RST_ACT_I2C3_APB                                                  : 1;      /* [   11]  */
            UINT32 ONGO_RST_ACT_I2C4_APB                                                  : 1;      /* [   12]  */
            UINT32 ONGO_RST_ACT_I2C5_APB                                                  : 1;      /* [   13]  */
            UINT32 ONGO_RST_ACT_I2C6_APB                                                  : 1;      /* [   14]  */
            UINT32 ONGO_RST_ACT_I2C7_APB                                                  : 1;      /* [   15]  */
            UINT32 ONGO_RST_ACT_CAN0_CORE                                                 : 1;      /* [   16]  */
            UINT32 ONGO_RST_ACT_CAN1_CORE                                                 : 1;      /* [   17]  */
            UINT32 ONGO_RST_ACT_CAN0_APB                                                  : 1;      /* [   18]  */
            UINT32 ONGO_RST_ACT_CAN1_APB                                                  : 1;      /* [   19]  */
            UINT32 ONGO_RST_ACT_LIN0_CORE                                                 : 1;      /* [   20]  */
            UINT32 ONGO_RST_ACT_LIN1_CORE                                                 : 1;      /* [   21]  */
            UINT32 ONGO_RST_ACT_LIN0_APB                                                  : 1;      /* [   22]  */
            UINT32 ONGO_RST_ACT_LIN1_APB                                                  : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 ONGO_RST_ACT_I2S_APB                                                   : 1;      /* [   28]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }ONGO_RST_ACT_2;

    UINT8 EMPTY30[4]; /* 0x4 */

    union { /* 0x4010 [Excel Line :0329]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_ACC_APB                                                   : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_BLK_NPU_APB                                               : 1;      /* [    1]  */
            UINT32 RESERVED3                                                              : 6;      /* [  7:2]  */
            UINT32 ONGO_RST_ACT_BLK_SEC_APB                                               : 1;      /* [    8]  */
            UINT32 ONGO_RST_ACT_EIP                                                       : 1;      /* [    9]  */
            UINT32 RESERVED2                                                              : 2;      /* [11:10]  */
            UINT32 ONGO_RST_ACT_CMRT_HRESET                                               : 1;      /* [   12]  */
            UINT32 ONGO_RST_ACT_CMRT_PRESET                                               : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }ONGO_RST_ACT_4;
    union { /* 0x4014 [Excel Line :0338]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_HSP_APB                                                   : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_ETH_APB                                                   : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }ONGO_RST_ACT_5;
    union { /* 0x4018 [Excel Line :0341]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_BLK_USB_APB                                               : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 ONGO_RST_ACT_BLK_PCIE_APB                                              : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }ONGO_RST_ACT_6;
    union { /* 0x401C [Excel Line :0345]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_PVT_CORE                                                  : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_ADC_CORE                                                  : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_VLD_CORE                                                  : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_OTP_CORE                                                  : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }ONGO_RST_ACT_7;
    union { /* 0x4020 [Excel Line :0350]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SEN0_RSTN                                                 : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 ONGO_RST_ACT_SEN1_RSTN                                                 : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }ONGO_RST_ACT_8;

    UINT8 EMPTY31[220]; /* 0xDC */

    union { /* 0x4100 [Excel Line :0354]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_BUS_MAIN                                                   : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_BUS_APB                                                    : 1;      /* [    1]  */
            UINT32 RESERVED5                                                              : 6;      /* [  7:2]  */
            UINT32 PUL_RST_ACT_BLK_MEM                                                    : 1;      /* [    8]  */
            UINT32 PUL_RST_ACT_IROM                                                       : 1;      /* [    9]  */
            UINT32 PUL_RST_ACT_IRAM                                                       : 1;      /* [   10]  */
            UINT32 RESERVED4                                                              : 1;      /* [   11]  */
            UINT32 PUL_RST_ACT_ANALOG_APB                                                 : 1;      /* [   12]  */
            UINT32 PUL_RST_ACT_SYS_APB                                                    : 1;      /* [   13]  */
            UINT32 PUL_RST_ACT_BLK_SYS_SCU                                                : 1;      /* [   14]  */
            UINT32 PUL_RST_ACT_BLK_PMU                                                    : 1;      /* [   15]  */
            UINT32 PUL_RST_ACT_BLK_ICU                                                    : 1;      /* [   16]  */
            UINT32 RESERVED3                                                              : 3;      /* [19:17]  */
            UINT32 PUL_RST_ACT_GIC_APB                                                    : 1;      /* [   20]  */
            UINT32 PUL_RST_ACT_GIC_R5                                                     : 1;      /* [   21]  */
            UINT32 PUL_RST_ACT_GIC_A65_FDC                                                : 1;      /* [   22]  */
            UINT32 PUL_RST_ACT_GIC_A65                                                    : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 PUL_RST_ACT_BLK_SAFETY                                                 : 1;      /* [   28]  */
            UINT32 PUL_RST_ACT_TEST_MST                                                   : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }PUL_RST_ACT_0;
    union { /* 0x4104 [Excel Line :0375]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_PERI0_APB                                                  : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_PERI1_APB                                                  : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_DMAC0_AXI                                                  : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_DMAC1_AXI                                                  : 1;      /* [    3]  */
            UINT32 PUL_RST_ACT_UART0_CORE                                                 : 1;      /* [    4]  */
            UINT32 PUL_RST_ACT_UART1_CORE                                                 : 1;      /* [    5]  */
            UINT32 PUL_RST_ACT_UART2_CORE                                                 : 1;      /* [    6]  */
            UINT32 PUL_RST_ACT_UART3_CORE                                                 : 1;      /* [    7]  */
            UINT32 PUL_RST_ACT_UART0_APB                                                  : 1;      /* [    8]  */
            UINT32 PUL_RST_ACT_UART1_APB                                                  : 1;      /* [    9]  */
            UINT32 PUL_RST_ACT_UART2_APB                                                  : 1;      /* [   10]  */
            UINT32 PUL_RST_ACT_UART3_APB                                                  : 1;      /* [   11]  */
            UINT32 PUL_RST_ACT_TIMER0_APB                                                 : 1;      /* [   12]  */
            UINT32 PUL_RST_ACT_TIMER1_APB                                                 : 1;      /* [   13]  */
            UINT32 PUL_RST_ACT_TIMER2_APB                                                 : 1;      /* [   14]  */
            UINT32 RESERVED4                                                              : 1;      /* [   15]  */
            UINT32 PUL_RST_ACT_QSPI_CORE                                                  : 1;      /* [   16]  */
            UINT32 PUL_RST_ACT_QSPI_APB                                                   : 1;      /* [   17]  */
            UINT32 RESERVED3                                                              : 2;      /* [19:18]  */
            UINT32 PUL_RST_ACT_SPI0_CORE                                                  : 1;      /* [   20]  */
            UINT32 PUL_RST_ACT_SPI1_CORE                                                  : 1;      /* [   21]  */
            UINT32 PUL_RST_ACT_SPI2_CORE                                                  : 1;      /* [   22]  */
            UINT32 PUL_RST_ACT_SPI0_APB                                                   : 1;      /* [   23]  */
            UINT32 PUL_RST_ACT_SPI1_APB                                                   : 1;      /* [   24]  */
            UINT32 PUL_RST_ACT_SPI2_APB                                                   : 1;      /* [   25]  */
            UINT32 RESERVED2                                                              : 2;      /* [27:26]  */
            UINT32 PUL_RST_ACT_PWM_CORE                                                   : 1;      /* [   28]  */
            UINT32 PUL_RST_ACT_PWM_APB                                                    : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }PUL_RST_ACT_1;
    union { /* 0x4108 [Excel Line :0404]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_I2C0_CORE                                                  : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_I2C1_CORE                                                  : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_I2C2_CORE                                                  : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_I2C3_CORE                                                  : 1;      /* [    3]  */
            UINT32 PUL_RST_ACT_I2C4_CORE                                                  : 1;      /* [    4]  */
            UINT32 PUL_RST_ACT_I2C5_CORE                                                  : 1;      /* [    5]  */
            UINT32 PUL_RST_ACT_I2C6_CORE                                                  : 1;      /* [    6]  */
            UINT32 PUL_RST_ACT_I2C7_CORE                                                  : 1;      /* [    7]  */
            UINT32 PUL_RST_ACT_I2C0_APB                                                   : 1;      /* [    8]  */
            UINT32 PUL_RST_ACT_I2C1_APB                                                   : 1;      /* [    9]  */
            UINT32 PUL_RST_ACT_I2C2_APB                                                   : 1;      /* [   10]  */
            UINT32 PUL_RST_ACT_I2C3_APB                                                   : 1;      /* [   11]  */
            UINT32 PUL_RST_ACT_I2C4_APB                                                   : 1;      /* [   12]  */
            UINT32 PUL_RST_ACT_I2C5_APB                                                   : 1;      /* [   13]  */
            UINT32 PUL_RST_ACT_I2C6_APB                                                   : 1;      /* [   14]  */
            UINT32 PUL_RST_ACT_I2C7_APB                                                   : 1;      /* [   15]  */
            UINT32 PUL_RST_ACT_CAN0_CORE                                                  : 1;      /* [   16]  */
            UINT32 PUL_RST_ACT_CAN1_CORE                                                  : 1;      /* [   17]  */
            UINT32 PUL_RST_ACT_CAN0_APB                                                   : 1;      /* [   18]  */
            UINT32 PUL_RST_ACT_CAN1_APB                                                   : 1;      /* [   19]  */
            UINT32 PUL_RST_ACT_LIN0_CORE                                                  : 1;      /* [   20]  */
            UINT32 PUL_RST_ACT_LIN1_CORE                                                  : 1;      /* [   21]  */
            UINT32 PUL_RST_ACT_LIN0_APB                                                   : 1;      /* [   22]  */
            UINT32 PUL_RST_ACT_LIN1_APB                                                   : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 PUL_RST_ACT_I2S_APB                                                    : 1;      /* [   28]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PUL_RST_ACT_2;

    UINT8 EMPTY32[4]; /* 0x4 */

    union { /* 0x4110 [Excel Line :0431]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_ACC_APB                                                    : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_BLK_NPU_APB                                                : 1;      /* [    1]  */
            UINT32 RESERVED3                                                              : 6;      /* [  7:2]  */
            UINT32 PUL_RST_ACT_BLK_SEC_APB                                                : 1;      /* [    8]  */
            UINT32 PUL_RST_ACT_EIP                                                        : 1;      /* [    9]  */
            UINT32 RESERVED2                                                              : 2;      /* [11:10]  */
            UINT32 PUL_RST_ACT_CMRT_HRESET                                                : 1;      /* [   12]  */
            UINT32 PUL_RST_ACT_CMRT_PRESET                                                : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }PUL_RST_ACT_4;
    union { /* 0x4114 [Excel Line :0440]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_HSP_APB                                                    : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_ETH_APB                                                    : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }PUL_RST_ACT_5;
    union { /* 0x4118 [Excel Line :0443]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_BLK_USB_APB                                                : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 PUL_RST_ACT_BLK_PCIE_APB                                               : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }PUL_RST_ACT_6;
    union { /* 0x411C [Excel Line :0447]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_PVT_CORE                                                   : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_ADC_CORE                                                   : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_VLD_CORE                                                   : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_OTP_CORE                                                   : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }PUL_RST_ACT_7;
    union { /* 0x4120 [Excel Line :0452]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SEN0_RSTN                                                  : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 PUL_RST_ACT_SEN1_RSTN                                                  : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }PUL_RST_ACT_8;

    UINT8 EMPTY33[1756]; /* 0x6DC */

    union { /* 0x4800 [Excel Line :0456]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_SAFETY                                               : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_SAFETY_RST_WIDTH;

    UINT8 EMPTY34[8]; /* 0x8 */

    union { /* 0x480C [Excel Line :0458]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_GIC_A65_FDC                                              : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_GIC_A65                                                  : 16;     /* [31:16]  */
        }Bit;
    }GIC_A65_RST_WIDTH;
    union { /* 0x4810 [Excel Line :0460]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_GIC_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_GIC_R5                                                   : 16;     /* [31:16]  */
        }Bit;
    }GIC_RST_WIDTH;
    union { /* 0x4814 [Excel Line :0462]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_ICU                                                  : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_TEST_MST                                                 : 16;     /* [31:16]  */
        }Bit;
    }BLK_ICU_RST_WIDTH;
    union { /* 0x4818 [Excel Line :0464]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_PMU                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_PMU_RST_WIDTH;
    union { /* 0x481C [Excel Line :0466]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_SYS_SCU                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_SYS_SCU_RST_WIDTH;
    union { /* 0x4820 [Excel Line :0468]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_IROM                                                     : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_IRAM                                                     : 16;     /* [31:16]  */
        }Bit;
    }BLK_MEM_RST_WIDTH_1;
    union { /* 0x4824 [Excel Line :0470]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_MEM                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_MEM_RST_WIDTH_2;

    UINT8 EMPTY35[24]; /* 0x18 */

    union { /* 0x4840 [Excel Line :0472]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BUS_MAIN                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_BUS_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }BUS_RST_WIDTH;
    union { /* 0x4844 [Excel Line :0474]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SYS_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SYS_APB_RST_WIDTH;
    union { /* 0x4848 [Excel Line :0476]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ANALOG_APB                                               : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ANALOG_APB_RST_WIDTH;

    UINT8 EMPTY36[4]; /* 0x4 */

    union { /* 0x4850 [Excel Line :0478]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_PWM_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_PWM_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }PWM_APB_RST_WIDTH;
    union { /* 0x4854 [Excel Line :0480]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SPI_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_SPI_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }SPI_RST_WIDTH;
    union { /* 0x4858 [Excel Line :0482]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_QSPI_CORE                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_QSPI_APB                                                 : 16;     /* [31:16]  */
        }Bit;
    }QSPI_RST_WIDTH;
    union { /* 0x485C [Excel Line :0484]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_TIMER_APB                                                : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }TIMER_RST_WIDTH;
    union { /* 0x4860 [Excel Line :0486]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_UART_CORE                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_UART_APB                                                 : 16;     /* [31:16]  */
        }Bit;
    }UART_RST_WIDTH;
    union { /* 0x4864 [Excel Line :0488]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_DMAC0_AXI                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_DMAC1_AXI                                                : 16;     /* [31:16]  */
        }Bit;
    }DMAC_AXI_RST_WIDTH;
    union { /* 0x4868 [Excel Line :0490]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_PERI0_APB                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_PERI1_APB                                                : 16;     /* [31:16]  */
        }Bit;
    }PERI1_APB_RST_WIDTH;
    union { /* 0x486C [Excel Line :0492]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_I2S_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }I2S_APB_RST_WIDTH;
    union { /* 0x4870 [Excel Line :0494]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_LIN_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_LIN_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }LIN_RST_WIDTH;
    union { /* 0x4874 [Excel Line :0496]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CAN_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CAN_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }CAN_RST_WIDTH;
    union { /* 0x4878 [Excel Line :0498]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_I2C_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_I2C_APB                                                  : 16;     /* [31:16]  */
        }Bit;
    }I2C_RST_WIDTH;

    UINT8 EMPTY37[52]; /* 0x34 */

    union { /* 0x48B0 [Excel Line :0500]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CMRT_HRESET                                              : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CMRT_PRESET                                              : 16;     /* [31:16]  */
        }Bit;
    }CMRT_RST_WIDTH;
    union { /* 0x48B4 [Excel Line :0502]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EIP                                                      : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EIP_RST_WIDTH;
    union { /* 0x48B8 [Excel Line :0504]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_SEC_APB                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_SEC_APB_RST_WIDTH;

    UINT8 EMPTY38[8]; /* 0x8 */

    union { /* 0x48C4 [Excel Line :0506]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_NPU_APB                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_NPU_APB_RST_WIDTH;
    union { /* 0x48C8 [Excel Line :0508]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ACC_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ACC_APB_RST_WIDTH;

    UINT8 EMPTY39[20]; /* 0x14 */

    union { /* 0x48E0 [Excel Line :0510]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ETH_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ETH_RST_WIDTH;

    UINT8 EMPTY40[4]; /* 0x4 */

    union { /* 0x48E8 [Excel Line :0512]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_HSP_APB                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }HSP_APB_RST_WIDTH;

    UINT8 EMPTY41[36]; /* 0x24 */

    union { /* 0x4910 [Excel Line :0514]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_PCIE_APB                                             : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_PCIE_APB_RST_WIDTH;

    UINT8 EMPTY42[8]; /* 0x8 */

    union { /* 0x491C [Excel Line :0516]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_BLK_USB_APB                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BLK_USB_APB_RST_WIDTH;

    UINT8 EMPTY43[96]; /* 0x60 */

    union { /* 0x4980 [Excel Line :0518]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_OTP_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }OTP_CORE_RST_WIDTH;
    union { /* 0x4984 [Excel Line :0520]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_VLD_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }VLD_CORE_RST_WIDTH;
    union { /* 0x4988 [Excel Line :0522]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ADC_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ADC_CORE_RST_WIDTH;
    union { /* 0x498C [Excel Line :0524]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_PVT_CORE                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }PVT_CORE_RST_WIDTH;
    union { /* 0x4990 [Excel Line :0526]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SEN0_RSTN                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_SEN1_RSTN                                                : 16;     /* [31:16]  */
        }Bit;
    }SEN_RST_WIDTH;

    UINT8 EMPTY44[1388]; /* 0x56C */

    union { /* 0x4F00 [Excel Line :0528]  */
        UINT32 Reg;
        struct {
            UINT32 GLOBAL_POR_RST_ACT_0                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GLOBAL_POR_RST_ACT_0;
    union { /* 0x4F04 [Excel Line :0530]  */
        UINT32 Reg;
        struct {
            UINT32 GLOBAL_POR_RST_ACT_1                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GLOBAL_POR_RST_ACT_1;
    union { /* 0x4F08 [Excel Line :0532]  */
        UINT32 Reg;
        struct {
            UINT32 GLOBAL_POR_RST_ACT_2                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GLOBAL_POR_RST_ACT_2;

    UINT8 EMPTY45[4]; /* 0x4 */

    union { /* 0x4F10 [Excel Line :0534]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0_POR_RST_ACT_0                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR0_POR_RST_ACT_0;
    union { /* 0x4F14 [Excel Line :0536]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0_POR_RST_ACT_1                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR0_POR_RST_ACT_1;
    union { /* 0x4F18 [Excel Line :0538]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0_POR_RST_ACT_2                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR0_POR_RST_ACT_2;

    UINT8 EMPTY46[4]; /* 0x4 */

    union { /* 0x4F20 [Excel Line :0540]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1_POR_RST_ACT_0                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR1_POR_RST_ACT_0;
    union { /* 0x4F24 [Excel Line :0542]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1_POR_RST_ACT_1                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR1_POR_RST_ACT_1;
    union { /* 0x4F28 [Excel Line :0544]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1_POR_RST_ACT_2                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }DDR1_POR_RST_ACT_2;

    UINT8 EMPTY47[4]; /* 0x4 */

    union { /* 0x4F30 [Excel Line :0546]  */
        UINT32 Reg;
        struct {
            UINT32 HSP_POR_RST_ACT_0                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HSP_POR_RST_ACT_0;
    union { /* 0x4F34 [Excel Line :0548]  */
        UINT32 Reg;
        struct {
            UINT32 HSP_POR_RST_ACT_1                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HSP_POR_RST_ACT_1;
    union { /* 0x4F38 [Excel Line :0550]  */
        UINT32 Reg;
        struct {
            UINT32 HSP_POR_RST_ACT_2                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HSP_POR_RST_ACT_2;

    UINT8 EMPTY48[4]; /* 0x4 */

    union { /* 0x4F40 [Excel Line :0552]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_POR_RST_ACT_0                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }NPU_POR_RST_ACT_0;
    union { /* 0x4F44 [Excel Line :0554]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_POR_RST_ACT_1                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }NPU_POR_RST_ACT_1;
    union { /* 0x4F48 [Excel Line :0556]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_POR_RST_ACT_2                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }NPU_POR_RST_ACT_2;

    UINT8 EMPTY49[4]; /* 0x4 */

    union { /* 0x4F50 [Excel Line :0558]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_POR_RST_ACT_0                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GPU_POR_RST_ACT_0;
    union { /* 0x4F54 [Excel Line :0560]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_POR_RST_ACT_1                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GPU_POR_RST_ACT_1;
    union { /* 0x4F58 [Excel Line :0562]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_POR_RST_ACT_2                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GPU_POR_RST_ACT_2;

    UINT8 EMPTY50[4]; /* 0x4 */

    union { /* 0x4F60 [Excel Line :0564]  */
        UINT32 Reg;
        struct {
            UINT32 HWA_POR_RST_ACT_0                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HWA_POR_RST_ACT_0;
    union { /* 0x4F64 [Excel Line :0566]  */
        UINT32 Reg;
        struct {
            UINT32 HWA_POR_RST_ACT_1                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HWA_POR_RST_ACT_1;
    union { /* 0x4F68 [Excel Line :0568]  */
        UINT32 Reg;
        struct {
            UINT32 HWA_POR_RST_ACT_2                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HWA_POR_RST_ACT_2;

    UINT8 EMPTY51[4]; /* 0x4 */

    union { /* 0x4F70 [Excel Line :0570]  */
        UINT32 Reg;
        struct {
            UINT32 VISION0_POR_RST_ACT_0                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION0_POR_RST_ACT_0;
    union { /* 0x4F74 [Excel Line :0572]  */
        UINT32 Reg;
        struct {
            UINT32 VISION0_POR_RST_ACT_1                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION0_POR_RST_ACT_1;
    union { /* 0x4F78 [Excel Line :0574]  */
        UINT32 Reg;
        struct {
            UINT32 VISION0_POR_RST_ACT_2                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION0_POR_RST_ACT_2;

    UINT8 EMPTY52[4]; /* 0x4 */

    union { /* 0x4F80 [Excel Line :0576]  */
        UINT32 Reg;
        struct {
            UINT32 VISION1_POR_RST_ACT_0                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION1_POR_RST_ACT_0;
    union { /* 0x4F84 [Excel Line :0578]  */
        UINT32 Reg;
        struct {
            UINT32 VISION1_POR_RST_ACT_1                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION1_POR_RST_ACT_1;
    union { /* 0x4F88 [Excel Line :0580]  */
        UINT32 Reg;
        struct {
            UINT32 VISION1_POR_RST_ACT_2                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }VISION1_POR_RST_ACT_2;

    UINT8 EMPTY53[4]; /* 0x4 */

    union { /* 0x4F90 [Excel Line :0582]  */
        UINT32 Reg;
        struct {
            UINT32 USB_POR_RST_ACT_0                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }USB_POR_RST_ACT_0;
    union { /* 0x4F94 [Excel Line :0584]  */
        UINT32 Reg;
        struct {
            UINT32 USB_POR_RST_ACT_1                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }USB_POR_RST_ACT_1;
    union { /* 0x4F98 [Excel Line :0586]  */
        UINT32 Reg;
        struct {
            UINT32 USB_POR_RST_ACT_2                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }USB_POR_RST_ACT_2;

    UINT8 EMPTY54[4]; /* 0x4 */

    union { /* 0x4FA0 [Excel Line :0588]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE_POR_RST_ACT_0                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PCIE_POR_RST_ACT_0;
    union { /* 0x4FA4 [Excel Line :0590]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE_POR_RST_ACT_1                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PCIE_POR_RST_ACT_1;
    union { /* 0x4FA8 [Excel Line :0592]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE_POR_RST_ACT_2                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PCIE_POR_RST_ACT_2;

    UINT8 EMPTY55[84]; /* 0x54 */

    union { /* 0x5000 [Excel Line :0594]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_RST_GEN_EN_G1                                                 : 1;      /* [    0]  */
            UINT32 RST_READ_RST_GEN_EN_G2                                                 : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }RST_READ_RST_GEN_EN;
    union { /* 0x5004 [Excel Line :0597]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_POR_STABLE_DDR0                                               : 1;      /* [    0]  */
            UINT32 RST_READ_POR_STABLE_DDR1                                               : 1;      /* [    1]  */
            UINT32 RST_READ_POR_STABLE_HSP                                                : 1;      /* [    2]  */
            UINT32 RST_READ_POR_STABLE_NPU                                                : 1;      /* [    3]  */
            UINT32 RST_READ_POR_STABLE_GPU                                                : 1;      /* [    4]  */
            UINT32 RST_READ_POR_STABLE_HWA                                                : 1;      /* [    5]  */
            UINT32 RST_READ_POR_STABLE_VISION0                                            : 1;      /* [    6]  */
            UINT32 RST_READ_POR_STABLE_VISION1                                            : 1;      /* [    7]  */
            UINT32 RST_READ_POR_STABLE_USB                                                : 1;      /* [    8]  */
            UINT32 RST_READ_POR_STABLE_PCIE                                               : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }RST_READ_POR_STABLE;

    UINT8 EMPTY56[8]; /* 0x8 */

    union { /* 0x5010 [Excel Line :0608]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_BUS_MAIN                                                      : 1;      /* [    0]  */
            UINT32 RST_READ_BUS_APB                                                       : 1;      /* [    1]  */
            UINT32 RESERVED5                                                              : 6;      /* [  7:2]  */
            UINT32 RST_READ_BLK_MEM                                                       : 1;      /* [    8]  */
            UINT32 RST_READ_IROM                                                          : 1;      /* [    9]  */
            UINT32 RST_READ_IRAM                                                          : 1;      /* [   10]  */
            UINT32 RESERVED4                                                              : 1;      /* [   11]  */
            UINT32 RST_READ_ANALOG_APB                                                    : 1;      /* [   12]  */
            UINT32 RST_READ_SYS_APB                                                       : 1;      /* [   13]  */
            UINT32 RST_READ_BLK_SYS_SCU                                                   : 1;      /* [   14]  */
            UINT32 RST_READ_BLK_PMU                                                       : 1;      /* [   15]  */
            UINT32 RST_READ_BLK_ICU                                                       : 1;      /* [   16]  */
            UINT32 RESERVED3                                                              : 3;      /* [19:17]  */
            UINT32 RST_READ_GIC_APB                                                       : 1;      /* [   20]  */
            UINT32 RST_READ_GIC_R5                                                        : 1;      /* [   21]  */
            UINT32 RST_READ_GIC_A65_FDC                                                   : 1;      /* [   22]  */
            UINT32 RST_READ_GIC_A65                                                       : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 RST_READ_BLK_SAFETY                                                    : 1;      /* [   28]  */
            UINT32 RST_READ_TEST_MST                                                      : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }RST_READ_0;
    union { /* 0x5014 [Excel Line :0629]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_PERI0_APB                                                     : 1;      /* [    0]  */
            UINT32 RST_READ_PERI1_APB                                                     : 1;      /* [    1]  */
            UINT32 RST_READ_DMAC0_AXI                                                     : 1;      /* [    2]  */
            UINT32 RST_READ_DMAC1_AXI                                                     : 1;      /* [    3]  */
            UINT32 RST_READ_UART0_CORE                                                    : 1;      /* [    4]  */
            UINT32 RST_READ_UART1_CORE                                                    : 1;      /* [    5]  */
            UINT32 RST_READ_UART2_CORE                                                    : 1;      /* [    6]  */
            UINT32 RST_READ_UART3_CORE                                                    : 1;      /* [    7]  */
            UINT32 RST_READ_UART0_APB                                                     : 1;      /* [    8]  */
            UINT32 RST_READ_UART1_APB                                                     : 1;      /* [    9]  */
            UINT32 RST_READ_UART2_APB                                                     : 1;      /* [   10]  */
            UINT32 RST_READ_UART3_APB                                                     : 1;      /* [   11]  */
            UINT32 RST_READ_TIMER0_APB                                                    : 1;      /* [   12]  */
            UINT32 RST_READ_TIMER1_APB                                                    : 1;      /* [   13]  */
            UINT32 RST_READ_TIMER2_APB                                                    : 1;      /* [   14]  */
            UINT32 RESERVED4                                                              : 1;      /* [   15]  */
            UINT32 RST_READ_QSPI_CORE                                                     : 1;      /* [   16]  */
            UINT32 RST_READ_QSPI_APB                                                      : 1;      /* [   17]  */
            UINT32 RESERVED3                                                              : 2;      /* [19:18]  */
            UINT32 RST_READ_SPI0_CORE                                                     : 1;      /* [   20]  */
            UINT32 RST_READ_SPI1_CORE                                                     : 1;      /* [   21]  */
            UINT32 RST_READ_SPI2_CORE                                                     : 1;      /* [   22]  */
            UINT32 RST_READ_SPI0_APB                                                      : 1;      /* [   23]  */
            UINT32 RST_READ_SPI1_APB                                                      : 1;      /* [   24]  */
            UINT32 RST_READ_SPI2_APB                                                      : 1;      /* [   25]  */
            UINT32 RESERVED2                                                              : 2;      /* [27:26]  */
            UINT32 RST_READ_PWM_CORE                                                      : 1;      /* [   28]  */
            UINT32 RST_READ_PWM_APB                                                       : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }RST_READ_1;
    union { /* 0x5018 [Excel Line :0658]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_I2C0_CORE                                                     : 1;      /* [    0]  */
            UINT32 RST_READ_I2C1_CORE                                                     : 1;      /* [    1]  */
            UINT32 RST_READ_I2C2_CORE                                                     : 1;      /* [    2]  */
            UINT32 RST_READ_I2C3_CORE                                                     : 1;      /* [    3]  */
            UINT32 RST_READ_I2C4_CORE                                                     : 1;      /* [    4]  */
            UINT32 RST_READ_I2C5_CORE                                                     : 1;      /* [    5]  */
            UINT32 RST_READ_I2C6_CORE                                                     : 1;      /* [    6]  */
            UINT32 RST_READ_I2C7_CORE                                                     : 1;      /* [    7]  */
            UINT32 RST_READ_I2C0_APB                                                      : 1;      /* [    8]  */
            UINT32 RST_READ_I2C1_APB                                                      : 1;      /* [    9]  */
            UINT32 RST_READ_I2C2_APB                                                      : 1;      /* [   10]  */
            UINT32 RST_READ_I2C3_APB                                                      : 1;      /* [   11]  */
            UINT32 RST_READ_I2C4_APB                                                      : 1;      /* [   12]  */
            UINT32 RST_READ_I2C5_APB                                                      : 1;      /* [   13]  */
            UINT32 RST_READ_I2C6_APB                                                      : 1;      /* [   14]  */
            UINT32 RST_READ_I2C7_APB                                                      : 1;      /* [   15]  */
            UINT32 RST_READ_CAN0_CORE                                                     : 1;      /* [   16]  */
            UINT32 RST_READ_CAN1_CORE                                                     : 1;      /* [   17]  */
            UINT32 RST_READ_CAN0_APB                                                      : 1;      /* [   18]  */
            UINT32 RST_READ_CAN1_APB                                                      : 1;      /* [   19]  */
            UINT32 RST_READ_LIN0_CORE                                                     : 1;      /* [   20]  */
            UINT32 RST_READ_LIN1_CORE                                                     : 1;      /* [   21]  */
            UINT32 RST_READ_LIN0_APB                                                      : 1;      /* [   22]  */
            UINT32 RST_READ_LIN1_APB                                                      : 1;      /* [   23]  */
            UINT32 RESERVED2                                                              : 4;      /* [27:24]  */
            UINT32 RST_READ_I2S_APB                                                       : 1;      /* [   28]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }RST_READ_2;

    UINT8 EMPTY57[4]; /* 0x4 */

    union { /* 0x5020 [Excel Line :0685]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_ACC_APB                                                       : 1;      /* [    0]  */
            UINT32 RST_READ_BLK_NPU_APB                                                   : 1;      /* [    1]  */
            UINT32 RESERVED3                                                              : 6;      /* [  7:2]  */
            UINT32 RST_READ_BLK_SEC_APB                                                   : 1;      /* [    8]  */
            UINT32 RST_READ_EIP                                                           : 1;      /* [    9]  */
            UINT32 RESERVED2                                                              : 2;      /* [11:10]  */
            UINT32 RST_READ_CMRT_HRESET                                                   : 1;      /* [   12]  */
            UINT32 RST_READ_CMRT_PRESET                                                   : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }RST_READ_4;
    union { /* 0x5024 [Excel Line :0694]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_HSP_APB                                                       : 1;      /* [    0]  */
            UINT32 RST_READ_ETH_APB                                                       : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }RST_READ_5;
    union { /* 0x5028 [Excel Line :0697]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_BLK_USB_APB                                                   : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 RST_READ_BLK_PCIE_APB                                                  : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }RST_READ_6;
    union { /* 0x502C [Excel Line :0701]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_PVT_CORE                                                      : 1;      /* [    0]  */
            UINT32 RST_READ_ADC_CORE                                                      : 1;      /* [    1]  */
            UINT32 RST_READ_VLD_CORE                                                      : 1;      /* [    2]  */
            UINT32 RST_READ_OTP_CORE                                                      : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }RST_READ_7;
    union { /* 0x5030 [Excel Line :0706]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_SEN0_RSTN                                                     : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 RST_READ_SEN1_RSTN                                                     : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }RST_READ_8;

    UINT8 EMPTY58[12752]; /* 0x31D0 */

    union { /* 0x8204 [Excel Line :0710]  */
        UINT32 Reg;
        struct {
            UINT32 IRAM_RMW_EN                                                            : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }IRAM_RMW_EN;
    union { /* 0x8208 [Excel Line :0712]  */
        UINT32 Reg;
        struct {
            UINT32 IRAM_INIT_START                                                        : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }IRAM_INIT_START;

    UINT8 EMPTY59[20]; /* 0x14 */

    union { /* 0x8220 [Excel Line :0714]  */
        UINT32 Reg;
        struct {
            UINT32 IRAM_INIT_DONE                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }IRAM_INIT_DONE;

    UINT8 EMPTY60[220]; /* 0xDC */

    union { /* 0x8300 [Excel Line :0716]  */
        UINT32 Reg;
        struct {
            UINT32 PWM_USE_OSCCLK0                                                        : 1;      /* [    0]  */
            UINT32 PWM_USE_OSCCLK1                                                        : 1;      /* [    1]  */
            UINT32 PWM_USE_OSCCLK2                                                        : 1;      /* [    2]  */
            UINT32 PWM_USE_OSCCLK3                                                        : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }PWM_CLOCK_SELECT;

    UINT8 EMPTY61[19708]; /* 0x4CFC */

    union { /* 0xD000 [Excel Line :0721]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_IGNORE_MODIFIABLE_0                                                : 1;      /* [    0]  */
            UINT32 BUS_IGNORE_MODIFIABLE_1                                                : 1;      /* [    1]  */
            UINT32 BUS_IGNORE_MODIFIABLE_2                                                : 1;      /* [    2]  */
            UINT32 BUS_IGNORE_MODIFIABLE_3                                                : 1;      /* [    3]  */
            UINT32 BUS_IGNORE_MODIFIABLE_4                                                : 1;      /* [    4]  */
            UINT32 BUS_IGNORE_MODIFIABLE_5                                                : 1;      /* [    5]  */
            UINT32 BUS_IGNORE_MODIFIABLE_6                                                : 1;      /* [    6]  */
            UINT32 BUS_IGNORE_MODIFIABLE_7                                                : 1;      /* [    7]  */
            UINT32 BUS_IGNORE_MODIFIABLE_8                                                : 1;      /* [    8]  */
            UINT32 BUS_IGNORE_MODIFIABLE_9                                                : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }BUS_IGNORE_MODI;

    UINT8 EMPTY62[12]; /* 0xC */

    union { /* 0xD010 [Excel Line :0732]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_EVEMON_0_START                                                     : 1;      /* [    0]  */
            UINT32 BUS_EVEMON_1_START                                                     : 1;      /* [    1]  */
            UINT32 BUS_EVEMON_2_START                                                     : 1;      /* [    2]  */
            UINT32 BUS_EVEMON_3_START                                                     : 1;      /* [    3]  */
            UINT32 BUS_EVEMON_4_START                                                     : 1;      /* [    4]  */
            UINT32 BUS_EVEMON_5_START                                                     : 1;      /* [    5]  */
            UINT32 BUS_EVEMON_6_START                                                     : 1;      /* [    6]  */
            UINT32 BUS_EVEMON_7_START                                                     : 1;      /* [    7]  */
            UINT32 BUS_EVEMON_8_START                                                     : 1;      /* [    8]  */
            UINT32 BUS_EVEMON_9_START                                                     : 1;      /* [    9]  */
            UINT32 BUS_EVEMON_10_START                                                    : 1;      /* [   10]  */
            UINT32 BUS_EVEMON_11_START                                                    : 1;      /* [   11]  */
            UINT32 BUS_EVEMON_12_START                                                    : 1;      /* [   12]  */
            UINT32 BUS_EVEMON_13_START                                                    : 1;      /* [   13]  */
            UINT32 BUS_EVEMON_14_START                                                    : 1;      /* [   14]  */
            UINT32 BUS_EVEMON_15_START                                                    : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BUS_EVEMON_START;

    UINT8 EMPTY63[12]; /* 0xC */

    union { /* 0xD020 [Excel Line :0749]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_EVEMON_0_TRIGGER                                                   : 1;      /* [    0]  */
            UINT32 BUS_EVEMON_1_TRIGGER                                                   : 1;      /* [    1]  */
            UINT32 BUS_EVEMON_2_TRIGGER                                                   : 1;      /* [    2]  */
            UINT32 BUS_EVEMON_3_TRIGGER                                                   : 1;      /* [    3]  */
            UINT32 BUS_EVEMON_4_TRIGGER                                                   : 1;      /* [    4]  */
            UINT32 BUS_EVEMON_5_TRIGGER                                                   : 1;      /* [    5]  */
            UINT32 BUS_EVEMON_6_TRIGGER                                                   : 1;      /* [    6]  */
            UINT32 BUS_EVEMON_7_TRIGGER                                                   : 1;      /* [    7]  */
            UINT32 BUS_EVEMON_8_TRIGGER                                                   : 1;      /* [    8]  */
            UINT32 BUS_EVEMON_9_TRIGGER                                                   : 1;      /* [    9]  */
            UINT32 BUS_EVEMON_10_TRIGGER                                                  : 1;      /* [   10]  */
            UINT32 BUS_EVEMON_11_TRIGGER                                                  : 1;      /* [   11]  */
            UINT32 BUS_EVEMON_12_TRIGGER                                                  : 1;      /* [   12]  */
            UINT32 BUS_EVEMON_13_TRIGGER                                                  : 1;      /* [   13]  */
            UINT32 BUS_EVEMON_14_TRIGGER                                                  : 1;      /* [   14]  */
            UINT32 BUS_EVEMON_15_TRIGGER                                                  : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BUS_EVEMON_TRIGGER;

    UINT8 EMPTY64[12]; /* 0xC */

    union { /* 0xD030 [Excel Line :0766]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_CLOCK_GATING_OFF_DDR1                                              : 1;      /* [    0]  */
            UINT32 BUS_CLOCK_GATING_OFF_GPU                                               : 1;      /* [    1]  */
            UINT32 BUS_CLOCK_GATING_OFF_HSP                                               : 1;      /* [    2]  */
            UINT32 BUS_CLOCK_GATING_OFF_BUS                                               : 1;      /* [    3]  */
            UINT32 BUS_CLOCK_GATING_OFF_NPU                                               : 1;      /* [    4]  */
            UINT32 BUS_CLOCK_GATING_OFF_PCIE                                              : 1;      /* [    5]  */
            UINT32 BUS_CLOCK_GATING_OFF_USB                                               : 1;      /* [    6]  */
            UINT32 BUS_CLOCK_GATING_OFF_VISION0                                           : 1;      /* [    7]  */
            UINT32 BUS_CLOCK_GATING_OFF_VISION1                                           : 1;      /* [    8]  */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }BUS_CLOCK_GATING_OFF;

    UINT8 EMPTY65[12]; /* 0xC */

    union { /* 0xD040 [Excel Line :0776]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_TEST_MST_HS_HNONSEC                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }BUS_TEST_MST_CONTROL;

    UINT8 EMPTY66[188]; /* 0xBC */

    union { /* 0xD100 [Excel Line :0778]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_0_DDR1                                             : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_0;
    union { /* 0xD104 [Excel Line :0779]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_1_GPU                                              : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_1;
    union { /* 0xD108 [Excel Line :0780]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_2_HSP                                              : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_2;
    union { /* 0xD10C [Excel Line :0781]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_3_BUS                                              : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_3;

    UINT8 EMPTY67[16]; /* 0x10 */

    union { /* 0xD120 [Excel Line :0782]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_4_NPU                                              : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_4;
    union { /* 0xD124 [Excel Line :0783]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_5_PCIE                                             : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_5;
    union { /* 0xD128 [Excel Line :0784]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_6_USB                                              : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_6;
    union { /* 0xD12C [Excel Line :0785]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_7_VISION0                                          : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_7;
    union { /* 0xD130 [Excel Line :0786]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_QCH_CLK_STOP_TH_8_VISION1                                          : 32;     /* [ 31:0]  */
        }Bit;
    }BUS_CLK_STOP_TH_8;

    UINT8 EMPTY68[204]; /* 0xCC */

    union { /* 0xD200 [Excel Line :0787]  */
        UINT32 Reg;
        struct {
            UINT32 BUS_S_TZPROT_0                                                         : 1;      /* [    0]  */
            UINT32 BUS_S_TZPROT_1                                                         : 1;      /* [    1]  */
            UINT32 BUS_S_TZPROT_2                                                         : 1;      /* [    2]  */
            UINT32 BUS_S_TZPROT_3                                                         : 1;      /* [    3]  */
            UINT32 BUS_S_TZPROT_4                                                         : 1;      /* [    4]  */
            UINT32 BUS_S_TZPROT_5                                                         : 1;      /* [    5]  */
            UINT32 BUS_S_TZPROT_6                                                         : 1;      /* [    6]  */
            UINT32 BUS_S_TZPROT_7                                                         : 1;      /* [    7]  */
            UINT32 BUS_S_TZPROT_8                                                         : 1;      /* [    8]  */
            UINT32 BUS_S_TZPROT_9                                                         : 1;      /* [    9]  */
            UINT32 BUS_S_TZPROT_10                                                        : 1;      /* [   10]  */
            UINT32 BUS_S_TZPROT_11                                                        : 1;      /* [   11]  */
            UINT32 BUS_S_TZPROT_12                                                        : 1;      /* [   12]  */
            UINT32 BUS_S_TZPROT_13                                                        : 1;      /* [   13]  */
            UINT32 BUS_S_TZPROT_14                                                        : 1;      /* [   14]  */
            UINT32 BUS_S_TZPROT_15                                                        : 1;      /* [   15]  */
            UINT32 BUS_S_TZPROT_16                                                        : 1;      /* [   16]  */
            UINT32 RESERVED1                                                              : 15;     /* [31:17]  */
        }Bit;
    }BUS_S_TZPROT;

    UINT8 EMPTY69[3580]; /* 0xDFC */

    union { /* 0xE000 [Excel Line :0805]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_CPU                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_CPU                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU_MCONFIG;
    union { /* 0xE004 [Excel Line :0808]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_A65                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_A65                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }A65_MCONFIG;

    UINT8 EMPTY70[8]; /* 0x8 */

    union { /* 0xE010 [Excel Line :0811]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_HWA                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_HWA                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }HWA_MCONFIG;

    UINT8 EMPTY71[12]; /* 0xC */

    union { /* 0xE020 [Excel Line :0814]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_NPU                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_NPU                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }NPU_MCONFIG;

    UINT8 EMPTY72[12]; /* 0xC */

    union { /* 0xE030 [Excel Line :0817]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_HSP                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_HSP                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }HSP_MCONFIG;

    UINT8 EMPTY73[12]; /* 0xC */

    union { /* 0xE040 [Excel Line :0820]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_MEM                                                         : 12;     /* [ 11:0]  */
            UINT32 RESERVED2                                                              : 12;     /* [23:12]  */
            UINT32 ROM_MCONFIG_MEM                                                        : 4;      /* [27:24]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }MEM_MCONFIG;

    UINT8 EMPTY74[12]; /* 0xC */

    union { /* 0xE050 [Excel Line :0824]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_PERI                                                        : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_PERI                                                        : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }PERI_MCONFIG;

    UINT8 EMPTY75[12]; /* 0xC */

    union { /* 0xE060 [Excel Line :0827]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_SECURE                                                      : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_SECURE                                                      : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }SECURE_MCONFIG;

    UINT8 EMPTY76[12]; /* 0xC */

    union { /* 0xE070 [Excel Line :0830]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_BUS                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_BUS                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }BUS_MCONFIG;

    UINT8 EMPTY77[12]; /* 0xC */

    union { /* 0xE080 [Excel Line :0833]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_VISION0                                                     : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_VISION0                                                     : 12;     /* [23:12]  */
            UINT32 ROM_MCONFIG_VISION0                                                    : 4;      /* [27:24]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }VISION0_MCONFIG;

    UINT8 EMPTY78[12]; /* 0xC */

    union { /* 0xE090 [Excel Line :0837]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_VISION1                                                     : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_VISION1                                                     : 12;     /* [23:12]  */
            UINT32 ROM_MCONFIG_VISION1                                                    : 4;      /* [27:24]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }VISION1_MCONFIG;

    UINT8 EMPTY79[12]; /* 0xC */

    union { /* 0xE0A0 [Excel Line :0841]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_GPU                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_GPU                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GPU_MCONFIG;

    UINT8 EMPTY80[12]; /* 0xC */

    union { /* 0xE0B0 [Excel Line :0844]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_GIC                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_GIC                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GIC_MCONFIG;

    UINT8 EMPTY81[12]; /* 0xC */

    union { /* 0xE0C0 [Excel Line :0847]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_ACC                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_ACC                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }ACC_MCONFIG;

    UINT8 EMPTY82[12]; /* 0xC */

    union { /* 0xE0D0 [Excel Line :0850]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_DDR0                                                        : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_DDR0                                                        : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }DDR0_MCONFIG;

    UINT8 EMPTY83[12]; /* 0xC */

    union { /* 0xE0E0 [Excel Line :0853]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_DDR1                                                        : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_DDR1                                                        : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }DDR1_MCONFIG;

    UINT8 EMPTY84[12]; /* 0xC */

    union { /* 0xE0F0 [Excel Line :0856]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_USB                                                         : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_USB                                                         : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }USB_MCONFIG;

    UINT8 EMPTY85[12]; /* 0xC */

    union { /* 0xE100 [Excel Line :0859]  */
        UINT32 Reg;
        struct {
            UINT32 SP_MCONFIG_PCIE                                                        : 12;     /* [ 11:0]  */
            UINT32 TP_MCONFIG_PCIE                                                        : 12;     /* [23:12]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }PCIE_MCONFIG;

    UINT8 EMPTY86[1276]; /* 0x4FC */

    union { /* 0xE600 [Excel Line :0862]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_RESTART                                                        : 1;      /* [    0] SYS_PLL_RESTART bit will be 1d0 automatically after you
                                                                                                               set this bit as 1d1 */
            UINT32 SYS_PLL_PWR_DOWN                                                       : 1;      /* [    1] If you want PLL enters power-down mode set this bit as 1d1 */
            UINT32 SYS_PLL_BYPASS                                                         : 1;      /* [    2] If BYPASS0 PLL operated normally
                                                                                                               If BYPASS1 bypass mode is enabled FOUTFIN */
            UINT32 RESERVED6                                                              : 1;      /* [    3]  */
            UINT32 CPU_PLL_RESTART                                                        : 1;      /* [    4]  */
            UINT32 CPU_PLL_PWR_DOWN                                                       : 1;      /* [    5]  */
            UINT32 CPU_PLL_BYPASS                                                         : 1;      /* [    6]  */
            UINT32 RESERVED5                                                              : 1;      /* [    7]  */
            UINT32 NPU_PLL_RESTART                                                        : 1;      /* [    8]  */
            UINT32 NPU_PLL_PWR_DOWN                                                       : 1;      /* [    9]  */
            UINT32 NPU_PLL_BYPASS                                                         : 1;      /* [   10]  */
            UINT32 RESERVED4                                                              : 1;      /* [   11]  */
            UINT32 COM_PLL_RESTART                                                        : 1;      /* [   12]  */
            UINT32 COM_PLL_PWR_DOWN                                                       : 1;      /* [   13]  */
            UINT32 COM_PLL_BYPASS                                                         : 1;      /* [   14]  */
            UINT32 RESERVED3                                                              : 1;      /* [   15]  */
            UINT32 VIDEO0_PLL_RESTART                                                     : 1;      /* [   16]  */
            UINT32 VIDEO0_PLL_PWR_DOWN                                                    : 1;      /* [   17]  */
            UINT32 VIDEO0_PLL_BYPASS                                                      : 1;      /* [   18]  */
            UINT32 RESERVED2                                                              : 1;      /* [   19]  */
            UINT32 VIDEO1_PLL_RESTART                                                     : 1;      /* [   20]  */
            UINT32 VIDEO1_PLL_PWR_DOWN                                                    : 1;      /* [   21]  */
            UINT32 VIDEO1_PLL_BYPASS                                                      : 1;      /* [   22]  */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }PLL_ONOFF_CONTROL;

    UINT8 EMPTY87[252]; /* 0xFC */

    union { /* 0xE700 [Excel Line :0886]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_M                                                              : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 SYS_PLL_P                                                              : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 SYS_PLL_S                                                              : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }SYS_PLL_PMS_CONTROL;
    union { /* 0xE704 [Excel Line :0892]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_EXTAFC                                                         : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 SYS_PLL_AFCINIT_SEL                                                    : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 SYS_PLL_AFC_ENB                                                        : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }SYS_PLL_AFC_CONTROL;
    union { /* 0xE708 [Excel Line :0898]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 SYS_PLL_PBIAS_CTRL                                                     : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 SYS_PLL_PBIAS_CTRL_EN                                                  : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 SYS_PLL_FEED_EN                                                        : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 SYS_PLL_FSEL                                                           : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 SYS_PLL_ICP                                                            : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 SYS_PLL_AFC_SEL                                                        : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 SYS_PLL_SEL_PF                                                         : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 SYS_PLL_SSCG_EN                                                        : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }SYS_PLL_OTHERS_CONTROL;
    union { /* 0xE70C [Excel Line :0910]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_K                                                              : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 SYS_PLL_MFR                                                            : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 SYS_PLL_MRR                                                            : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }SYS_PLL_MOD_CONTROL;

    UINT8 EMPTY88[240]; /* 0xF0 */

    union { /* 0xE800 [Excel Line :0914]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PLL_M                                                              : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 CPU_PLL_P                                                              : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 CPU_PLL_S                                                              : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }CPU_PLL_PMS_CONTROL;
    union { /* 0xE804 [Excel Line :0920]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PLL_EXTAFC                                                         : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 CPU_PLL_AFCINIT_SEL                                                    : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 CPU_PLL_AFC_ENB                                                        : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CPU_PLL_AFC_CONTROL;
    union { /* 0xE808 [Excel Line :0926]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 CPU_PLL_PBIAS_CTRL                                                     : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 CPU_PLL_PBIAS_CTRL_EN                                                  : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 CPU_PLL_FEED_EN                                                        : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 CPU_PLL_FSEL                                                           : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 CPU_PLL_ICP                                                            : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 CPU_PLL_AFC_SEL                                                        : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 CPU_PLL_SEL_PF                                                         : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 CPU_PLL_SSCG_EN                                                        : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }CPU_PLL_OTHERS_CONTROL;
    union { /* 0xE80C [Excel Line :0938]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PLL_K                                                              : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 CPU_PLL_MFR                                                            : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 CPU_PLL_MRR                                                            : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CPU_PLL_MOD_CONTROL;

    UINT8 EMPTY89[240]; /* 0xF0 */

    union { /* 0xE900 [Excel Line :0942]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_PLL_M                                                              : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 NPU_PLL_P                                                              : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 NPU_PLL_S                                                              : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }NPU_PLL_PMS_CONTROL;
    union { /* 0xE904 [Excel Line :0948]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_PLL_EXTAFC                                                         : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 NPU_PLL_AFCINIT_SEL                                                    : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 NPU_PLL_AFC_ENB                                                        : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }NPU_PLL_AFC_CONTROL;
    union { /* 0xE908 [Excel Line :0954]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 NPU_PLL_PBIAS_CTRL                                                     : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 NPU_PLL_PBIAS_CTRL_EN                                                  : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 NPU_PLL_FEED_EN                                                        : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 NPU_PLL_FSEL                                                           : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 NPU_PLL_ICP                                                            : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 NPU_PLL_AFC_SEL                                                        : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 NPU_PLL_SEL_PF                                                         : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 NPU_PLL_SSCG_EN                                                        : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }NPU_PLL_OTHERS_CONTROL;
    union { /* 0xE90C [Excel Line :0966]  */
        UINT32 Reg;
        struct {
            UINT32 NPU_PLL_K                                                              : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 NPU_PLL_MFR                                                            : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 NPU_PLL_MRR                                                            : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }NPU_PLL_MOD_CONTROL;

    UINT8 EMPTY90[240]; /* 0xF0 */

    union { /* 0xEA00 [Excel Line :0970]  */
        UINT32 Reg;
        struct {
            UINT32 COM_PLL_M                                                              : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 COM_PLL_P                                                              : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 COM_PLL_S                                                              : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }COM_PLL_PMS_CONTROL;
    union { /* 0xEA04 [Excel Line :0976]  */
        UINT32 Reg;
        struct {
            UINT32 COM_PLL_EXTAFC                                                         : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 COM_PLL_AFCINIT_SEL                                                    : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 COM_PLL_AFC_ENB                                                        : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }COM_PLL_AFC_CONTROL;
    union { /* 0xEA08 [Excel Line :0982]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 COM_PLL_PBIAS_CTRL                                                     : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 COM_PLL_PBIAS_CTRL_EN                                                  : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 COM_PLL_FEED_EN                                                        : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 COM_PLL_FSEL                                                           : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 COM_PLL_ICP                                                            : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 COM_PLL_AFC_SEL                                                        : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 COM_PLL_SEL_PF                                                         : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 COM_PLL_SSCG_EN                                                        : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }COM_PLL_OTHERS_CONTROL;
    union { /* 0xEA0C [Excel Line :0994]  */
        UINT32 Reg;
        struct {
            UINT32 COM_PLL_K                                                              : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 COM_PLL_MFR                                                            : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 COM_PLL_MRR                                                            : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }COM_PLL_MOD_CONTROL;

    UINT8 EMPTY91[240]; /* 0xF0 */

    union { /* 0xEB00 [Excel Line :0998]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO0_PLL_M                                                           : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 VIDEO0_PLL_P                                                           : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 VIDEO0_PLL_S                                                           : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }VIDEO0_PLL_PMS_CONTROL;
    union { /* 0xEB04 [Excel Line :1004]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO0_PLL_EXTAFC                                                      : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 VIDEO0_PLL_AFCINIT_SEL                                                 : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 VIDEO0_PLL_AFC_ENB                                                     : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VIDEO0_PLL_AFC_CONTROL;
    union { /* 0xEB08 [Excel Line :1010]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 VIDEO0_PLL_PBIAS_CTRL                                                  : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 VIDEO0_PLL_PBIAS_CTRL_EN                                               : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 VIDEO0_PLL_FEED_EN                                                     : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 VIDEO0_PLL_FSEL                                                        : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 VIDEO0_PLL_ICP                                                         : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 VIDEO0_PLL_AFC_SEL                                                     : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 VIDEO0_PLL_SEL_PF                                                      : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 VIDEO0_PLL_SSCG_EN                                                     : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }VIDEO0_PLL_OTHERS_CONTROL;
    union { /* 0xEB0C [Excel Line :1022]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO0_PLL_K                                                           : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 VIDEO0_PLL_MFR                                                         : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 VIDEO0_PLL_MRR                                                         : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VIDEO0_PLL_MOD_CONTROL;

    UINT8 EMPTY92[240]; /* 0xF0 */

    union { /* 0xEC00 [Excel Line :1026]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO1_PLL_M                                                           : 10;     /* [  9:0] - Value of the 10-bit programmable main-divider
                                                                                                                 10d64M9010d1023
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000
                                                                                                               - FVCO  MFINP
                                                                                                                 FOUT  FVCO2S  MFINP2S */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 VIDEO1_PLL_P                                                           : 6;      /* [17:12] - Value of the 6-bit programmable pre-divider
                                                                                                                 6d1P506d63
                                                                                                               - Do not set P50 or M90 to all zeros6b00_0000  10b00_0000_0000 */
            UINT32 RESERVED2                                                              : 2;      /* [19:18]  */
            UINT32 VIDEO1_PLL_S                                                           : 3;      /* [22:20] - Value of the 3-bit programmable Scaler
                                                                                                                 3d0S203d6
                                                                                                               - Do not use S203b111
                                                                                                               - 4MHzFINP12MHz */
            UINT32 RESERVED1                                                              : 9;      /* [31:23]  */
        }Bit;
    }VIDEO1_PLL_PMS_CONTROL;
    union { /* 0xEC04 [Excel Line :1032]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO1_PLL_EXTAFC                                                      : 5;      /* [  4:0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  7:5]  */
            UINT32 VIDEO1_PLL_AFCINIT_SEL                                                 : 1;      /* [    8] AFC initial select
                                                                                                               If ACFINI_SEL0 nominal delay time
                                                                                                               If ACFINI_SEL1 twice of nominal delay time
                                                                                                               should be 2d1 for normal operation mode */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 VIDEO1_PLL_AFC_ENB                                                     : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VIDEO1_PLL_AFC_CONTROL;
    union { /* 0xEC08 [Excel Line :1038]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 5;      /* [  4:0]  */
            UINT32 VIDEO1_PLL_PBIAS_CTRL                                                  : 1;      /* [    5] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 VIDEO1_PLL_PBIAS_CTRL_EN                                               : 1;      /* [    6] PBIAS control for test
                                                                                                               should be 1d0 for normal operation mode */
            UINT32 RESERVED3                                                              : 14;     /* [ 20:7]  */
            UINT32 VIDEO1_PLL_FEED_EN                                                     : 1;      /* [   21] FEED_OUT monitoring pin output enable
                                                                                                               If FEED_EN0 FEED_OUT output is disabled
                                                                                                               If FEED_EN1 FEED_OUT output is enabled */
            UINT32 VIDEO1_PLL_FSEL                                                        : 1;      /* [   22] Select monitoring pin output
                                                                                                               If FSEL0 FEED_OUT  FREF
                                                                                                               If FSEL1 FEED_OUT  FEED */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 VIDEO1_PLL_ICP                                                         : 3;      /* [26:24] Controls the charge-pump current */
            UINT32 VIDEO1_PLL_AFC_SEL                                                     : 1;      /* [   27] Selection of AFC mode
                                                                                                               default value is 3 */
            UINT32 VIDEO1_PLL_SEL_PF                                                      : 2;      /* [29:28] Modulation method control
                                                                                                               00 down spread 01 up spread 1x center spread */
            UINT32 RESERVED1                                                              : 1;      /* [   30]  */
            UINT32 VIDEO1_PLL_SSCG_EN                                                     : 1;      /* [   31] Dithered mode enable
                                                                                                               1 enable 0 disable */
        }Bit;
    }VIDEO1_PLL_OTHERS_CONTROL;
    union { /* 0xEC0C [Excel Line :1050]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO1_PLL_K                                                           : 16;     /* [ 15:0] - Value of the 16-bit DSM
                                                                                                               - twos complement integer
                                                                                                                 -327680x8000 K150 327670x0FFF */
            UINT32 VIDEO1_PLL_MFR                                                         : 8;      /* [23:16] - Value of the 8-bit modulation frequency control
                                                                                                               MF  FFIN  p  mfr  25 Hz pP50 mfrMFR70 */
            UINT32 VIDEO1_PLL_MRR                                                         : 6;      /* [29:24] - Value of the 6-bit modulation rate control
                                                                                                               MR  mfr  mrr  m  26  100  mm90 mrrMRR50 */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VIDEO1_PLL_MOD_CONTROL;

    UINT8 EMPTY93[240]; /* 0xF0 */

    union { /* 0xED00 [Excel Line :1054]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED3                                                              : 8;      /* [  7:0]  */
            UINT32 SYS_PLL_STABLE_OSC                                                     : 1;      /* [    8]  */
            UINT32 CPU_PLL_STABLE_OSC                                                     : 1;      /* [    9]  */
            UINT32 NPU_PLL_STABLE_OSC                                                     : 1;      /* [   10]  */
            UINT32 COM_PLL_STABLE_OSC                                                     : 1;      /* [   11]  */
            UINT32 VIDEO0_PLL_STABLE_OSC                                                  : 1;      /* [   12]  */
            UINT32 VIDEO1_PLL_STABLE_OSC                                                  : 1;      /* [   13]  */
            UINT32 RESERVED2                                                              : 2;      /* [15:14]  */
            UINT32 SYS_PLL_STABLE_FOUT                                                    : 1;      /* [   16]  */
            UINT32 CPU_PLL_STABLE_FOUT                                                    : 1;      /* [   17]  */
            UINT32 NPU_PLL_STABLE_FOUT                                                    : 1;      /* [   18]  */
            UINT32 COM_PLL_STABLE_FOUT                                                    : 1;      /* [   19]  */
            UINT32 VIDEO0_PLL_STABLE_FOUT                                                 : 1;      /* [   20]  */
            UINT32 VIDEO1_PLL_STABLE_FOUT                                                 : 1;      /* [   21]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }PLL_STABLE_STATUS0;

    UINT8 EMPTY94[4]; /* 0x4 */

    union { /* 0xED08 [Excel Line :1069]  */
        UINT32 Reg;
        struct {
            UINT32 SYS_PLL_AFC_CODE                                                       : 5;      /* [  4:0]  */
            UINT32 RESERVED4                                                              : 3;      /* [  7:5]  */
            UINT32 CPU_PLL_AFC_CODE                                                       : 5;      /* [ 12:8]  */
            UINT32 RESERVED3                                                              : 3;      /* [15:13]  */
            UINT32 NPU_PLL_AFC_CODE                                                       : 5;      /* [20:16]  */
            UINT32 RESERVED2                                                              : 3;      /* [23:21]  */
            UINT32 COM_PLL_AFC_CODE                                                       : 5;      /* [28:24]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PLL_AFC_STATUS0;
    union { /* 0xED0C [Excel Line :1077]  */
        UINT32 Reg;
        struct {
            UINT32 VIDEO0_PLL_AFC_CODE                                                    : 5;      /* [  4:0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  7:5]  */
            UINT32 VIDEO1_PLL_AFC_CODE                                                    : 5;      /* [ 12:8]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }PLL_AFC_STATUS1;

    UINT8 EMPTY95[496]; /* 0x1F0 */

    union { /* 0xEF00 [Excel Line :1081]  */
        UINT32 Reg;
        struct {
            UINT32 TICK_CNT1_RUN                                                          : 1;      /* [    0]  */
            UINT32 TICK_CNT1_CLEAR                                                        : 1;      /* [    1]  */
            UINT32 RESERVED2                                                              : 2;      /* [  3:2]  */
            UINT32 TICK_CNT2_RUN                                                          : 1;      /* [    4]  */
            UINT32 TICK_CNT2_CLEAR                                                        : 1;      /* [    5]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }TICK_CNT_CONTROL;

    UINT8 EMPTY96[12]; /* 0xC */

    union { /* 0xEF10 [Excel Line :1087]  */
        UINT32 Reg;
        struct {
            UINT32 TICK_CNT1_L                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }TICK_CNT1_L;
    union { /* 0xEF14 [Excel Line :1088]  */
        UINT32 Reg;
        struct {
            UINT32 TICK_CNT1_H                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }TICK_CNT1_H;
    union { /* 0xEF18 [Excel Line :1089]  */
        UINT32 Reg;
        struct {
            UINT32 TICK_CNT2_L                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }TICK_CNT2_L;
    union { /* 0xEF1C [Excel Line :1090]  */
        UINT32 Reg;
        struct {
            UINT32 TICK_CNT2_H                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }TICK_CNT2_H;
    union { /* 0xEF20 [Excel Line :1091]  */
        UINT32 Reg;
        struct {
            UINT32 RD_CLR_CNT1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }RD_CLR_CNT1;
    union { /* 0xEF24 [Excel Line :1092]  */
        UINT32 Reg;
        struct {
            UINT32 RD_CLR_CNT2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }RD_CLR_CNT2;

    UINT8 EMPTY97[216]; /* 0xD8 */

    union { /* 0xF000 [Excel Line :1093]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG0                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG0;
    union { /* 0xF004 [Excel Line :1094]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG1                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG1;
    union { /* 0xF008 [Excel Line :1095]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG2                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG2;
    union { /* 0xF00C [Excel Line :1096]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG3                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG3;
    union { /* 0xF010 [Excel Line :1097]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG4                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG4;
    union { /* 0xF014 [Excel Line :1098]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG5                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG5;
    union { /* 0xF018 [Excel Line :1099]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG6                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG6;
    union { /* 0xF01C [Excel Line :1100]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG7                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG7;
    union { /* 0xF020 [Excel Line :1101]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG8                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG8;
    union { /* 0xF024 [Excel Line :1102]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG9                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG9;
    union { /* 0xF028 [Excel Line :1103]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG10                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG10;
    union { /* 0xF02C [Excel Line :1104]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG11                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG11;
    union { /* 0xF030 [Excel Line :1105]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG12                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG12;
    union { /* 0xF034 [Excel Line :1106]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG13                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG13;
    union { /* 0xF038 [Excel Line :1107]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG14                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG14;
    union { /* 0xF03C [Excel Line :1108]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG15                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG15;
    union { /* 0xF040 [Excel Line :1109]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG16                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG16;
    union { /* 0xF044 [Excel Line :1110]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG17                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG17;
    union { /* 0xF048 [Excel Line :1111]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG18                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG18;
    union { /* 0xF04C [Excel Line :1112]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG19                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }DEBUG19;

    UINT8 EMPTY98[944]; /* 0x3B0 */

    union { /* 0xF400 [Excel Line :1113]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC0_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC0_BACKUP;
    union { /* 0xF404 [Excel Line :1115]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC1_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC1_BACKUP;
    union { /* 0xF408 [Excel Line :1117]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC2_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC2_BACKUP;

    UINT8 EMPTY99[244]; /* 0xF4 */

    union { /* 0xF500 [Excel Line :1119]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC0_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC0_RELOAD;
    union { /* 0xF504 [Excel Line :1121]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC1_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC1_RELOAD;
    union { /* 0xF508 [Excel Line :1123]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC2_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }HW_DTC2_RELOAD;

    UINT8 EMPTY100[244]; /* 0xF4 */

    union { /* 0xF600 [Excel Line :1125]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC0                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }HW_DTC0;
    union { /* 0xF604 [Excel Line :1126]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC1                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }HW_DTC1;
    union { /* 0xF608 [Excel Line :1127]  */
        UINT32 Reg;
        struct {
            UINT32 HW_DTC2                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }HW_DTC2;

    UINT8 EMPTY101[244]; /* 0xF4 */

    union { /* 0xF700 [Excel Line :1128]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC0_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC0_BACKUP;
    union { /* 0xF704 [Excel Line :1130]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC1_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC1_BACKUP;
    union { /* 0xF708 [Excel Line :1132]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC2_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC2_BACKUP;
    union { /* 0xF70C [Excel Line :1134]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC3_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC3_BACKUP;
    union { /* 0xF710 [Excel Line :1136]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC4_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC4_BACKUP;
    union { /* 0xF714 [Excel Line :1138]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC5_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC5_BACKUP;
    union { /* 0xF718 [Excel Line :1140]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC6_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC6_BACKUP;
    union { /* 0xF71C [Excel Line :1142]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC7_BACKUP                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC7_BACKUP;

    UINT8 EMPTY102[224]; /* 0xE0 */

    union { /* 0xF800 [Excel Line :1144]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC0_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC0_RELOAD;
    union { /* 0xF804 [Excel Line :1146]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC1_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC1_RELOAD;
    union { /* 0xF808 [Excel Line :1148]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC2_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC2_RELOAD;
    union { /* 0xF80C [Excel Line :1150]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC3_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC3_RELOAD;
    union { /* 0xF810 [Excel Line :1152]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC4_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC4_RELOAD;
    union { /* 0xF814 [Excel Line :1154]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC5_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC5_RELOAD;
    union { /* 0xF818 [Excel Line :1156]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC6_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC6_RELOAD;
    union { /* 0xF81C [Excel Line :1158]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC7_RELOAD                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SW_DTC7_RELOAD;

    UINT8 EMPTY103[224]; /* 0xE0 */

    union { /* 0xF900 [Excel Line :1160]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC0                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC0;
    union { /* 0xF904 [Excel Line :1161]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC1                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC1;
    union { /* 0xF908 [Excel Line :1162]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC2                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC2;
    union { /* 0xF90C [Excel Line :1163]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC3                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC3;
    union { /* 0xF910 [Excel Line :1164]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC4                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC4;
    union { /* 0xF914 [Excel Line :1165]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC5                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC5;
    union { /* 0xF918 [Excel Line :1166]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC6                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC6;
    union { /* 0xF91C [Excel Line :1167]  */
        UINT32 Reg;
        struct {
            UINT32 SW_DTC7                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }SW_DTC7;
}DRV_A6_SYS_SCU_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_A6_SYS_SCU_REGISTER* const RegA6_SYS_SCU = (DRV_A6_SYS_SCU_REGISTER*)APACHE_A6_SYS_SCU_BASE_ADDR;
 */



#endif /* end of  DRV_REGISTER_A6_SYS_SCU__ */

