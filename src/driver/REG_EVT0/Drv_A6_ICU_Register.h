
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_ICU_Register.h
*   Date       : 2022-06-29 14:06
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_ICU_H__
#define DRV_REGISTER_A6_ICU_H__

#define APACHE_A6_ICU_BASE_ADDR        0x05030000

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

    UINT8 EMPTY1[4084]; /* 0xFF4 */

    union { /* 0x1000 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_NTRST                                                         : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_TCK                                                           : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_TMS                                                           : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_TDO                                                           : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1000;
    union { /* 0x1004 [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_TDI                                                           : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_PCIE0_WAKE_N                                                  : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_PCIE0_CLKREQ_N                                                : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_PCIE1_WAKE_N                                                  : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1004;
    union { /* 0x1008 [Excel Line :0027]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_PCIE1_CLKREQ_N                                                : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_USB_OVRCUR_N                                                  : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_USB_PORT_PWR                                                  : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_I2C1_SDA                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1008;
    union { /* 0x100C [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_I2C1_SCL                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SEN0_CK_O                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SEN0_RSTN_O                                                   : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SEN1_CK_O                                                     : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_100C;
    union { /* 0x1010 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SEN1_RSTN_O                                                   : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_I2C0_SCL                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_I2C0_SDA                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_I2C2_SCL                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1010;
    union { /* 0x1014 [Excel Line :0051]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_I2C2_SDA                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_I2C3_SCL                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_I2C3_SDA                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_I2C4_SCL                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1014;
    union { /* 0x1018 [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_I2C4_SDA                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_I2C5_SCL                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_I2C5_SDA                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_I2C6_SCL                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1018;
    union { /* 0x101C [Excel Line :0067]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_I2C6_SDA                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_I2C7_SCL                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_I2C7_SDA                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_PWM_0                                                         : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_101C;
    union { /* 0x1020 [Excel Line :0075]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_PWM_1                                                         : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_PWM_2                                                         : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_PWM_3                                                         : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SPI0_CK                                                       : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1020;
    union { /* 0x1024 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SPI0_SSN                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SPI0_MOSI                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SPI0_MISO                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SPI1_CK                                                       : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1024;
    union { /* 0x1028 [Excel Line :0091]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SPI1_SSN                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SPI1_MOSI                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SPI1_MISO                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SPI2_CK                                                       : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1028;
    union { /* 0x102C [Excel Line :0099]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SPI2_SSN                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SPI2_MOSI                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SPI2_MISO                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_I2S_DIN                                                       : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_102C;
    union { /* 0x1030 [Excel Line :0107]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_I2S_DOUT                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_I2S_WCLK                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_I2S_SCLK                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_CAN0_RX                                                       : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1030;
    union { /* 0x1034 [Excel Line :0115]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_CAN0_TX                                                       : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_CAN1_RX                                                       : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_CAN1_TX                                                       : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_UART0_RX                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1034;
    union { /* 0x1038 [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_UART0_TX                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_UART1_RX                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_UART1_TX                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_UART2_RX                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1038;
    union { /* 0x103C [Excel Line :0131]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_UART2_TX                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_UART3_RX                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_UART3_TX                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_QSPI_SCK                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_103C;
    union { /* 0x1040 [Excel Line :0139]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_QSPI_CSN                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_QSPI_DQ0                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_QSPI_DQ1                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_QSPI_DQ2                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1040;
    union { /* 0x1044 [Excel Line :0147]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_QSPI_DQ3                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SD_VOL_SEL                                                    : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EMMC_VOL_SEL                                                  : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SD_CLK                                                        : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1044;
    union { /* 0x1048 [Excel Line :0155]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SD_CMD                                                        : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SD_DQ0                                                        : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SD_DQ1                                                        : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_SD_DQ2                                                        : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1048;
    union { /* 0x104C [Excel Line :0163]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_SD_DQ3                                                        : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_SD_DETECT_N                                                   : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_SD_WRITE_PROT                                                 : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EMMC_CLK                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_104C;
    union { /* 0x1050 [Excel Line :0171]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EMMC_RSTN                                                     : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EMMC_CMD                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EMMC_DQ0                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EMMC_DQ1                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1050;
    union { /* 0x1054 [Excel Line :0179]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EMMC_DQ2                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EMMC_DQ3                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EMMC_DQ4                                                      : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EMMC_DQ5                                                      : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1054;
    union { /* 0x1058 [Excel Line :0187]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EMMC_DQ6                                                      : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EMMC_DQ7                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EQOS_TXCLK                                                    : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EQOS_RXCLK                                                    : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1058;
    union { /* 0x105C [Excel Line :0195]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EQOS_RMII_CLK                                                 : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EQOS_MDC                                                      : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EQOS_MDIO                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EQOS_TXEN                                                     : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_105C;
    union { /* 0x1060 [Excel Line :0203]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EQOS_TXD0                                                     : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EQOS_TXD1                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EQOS_TXD2                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EQOS_TXD3                                                     : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1060;
    union { /* 0x1064 [Excel Line :0211]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EQOS_RXDV                                                     : 3;      /* [  2:0] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED4                                                              : 5;      /* [  7:3]  */
            UINT32 REG_TMUX_EQOS_RXD0                                                     : 3;      /* [ 10:8] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED3                                                              : 5;      /* [15:11]  */
            UINT32 REG_TMUX_EQOS_RXD1                                                     : 3;      /* [18:16] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED2                                                              : 5;      /* [23:19]  */
            UINT32 REG_TMUX_EQOS_RXD2                                                     : 3;      /* [26:24] REG_SEL is selection signal for choosing Function Mode
                                                                                                               0x0  FM0
                                                                                                               0x1  FM1
                                                                                                               0x2  FM2
                                                                                                               0x3  FM3
                                                                                                               0x4  FM4
                                                                                                               0x5  FM5
                                                                                                               0x6  FM6
                                                                                                               0x7  FM7
                                                                                                               Detail Information is written in 3IOmux sheet */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }REG_TMUX_1064;
    union { /* 0x1068 [Excel Line :0219]  */
        UINT32 Reg;
        struct {
            UINT32 REG_TMUX_EQOS_RXD3                                                     : 3;      /* [  2:0] GPIO_D pad output level control 310 */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }REG_TMUX_1068;

    UINT8 EMPTY2[3988]; /* 0xF94 */
#if 1
    /* GROUP Start : ICU_GPIO */
    struct {
         union { /* 0x2000 [Excel Line :0221]  */
             UINT32 Reg;
             struct {
                 UINT32 GPIO_IN                                                 : 32;     /* [ 31:0] GPIO_A Input value */
             }Bit;
         }GPIO_IN;
         union { /* 0x2004 [Excel Line :0222]  */
             UINT32 Reg;
             struct {
                 UINT32 GPIO_OE                                                 : 32;     /* [ 31:0] GPIO_A direction
                                                                                                     1 output direction
                                                                                                     0 input direction */
             }Bit;
         }GPIO_OE;
         union { /* 0x2008 [Excel Line :0223]  */
             UINT32 Reg;
             struct {
                 UINT32 GPIO_OUT                                                : 32;     /* [ 31:0] GPIO_A Output value */
             }Bit;
         }GPIO_OUT;
         union { /* 0x200C [Excel Line :0224]  */
             UINT32 Reg;
             struct {
                 UINT32 RESERVED1                                               : 32;     /* [ 31:0]  */
             }Bit;
         }REVERVED;
    }ICU_GPIO[4];

    UINT8 EMPTY6[192]; /* 0xC0 */
#else
    union { /* 0x2000 [Excel Line :0221]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_A_IN                                                              : 32;     /* [ 31:0] GPIO_A pad input level read 310 */
        }Bit;
    }REG_GPIO_A_IN;
    union { /* 0x2004 [Excel Line :0222]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_A_OE                                                              : 32;     /* [ 31:0] GPIO_A pad out enable control 310 1 out  0 in */
        }Bit;
    }REG_GPIO_A_OE;
    union { /* 0x2008 [Excel Line :0223]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_A_OUT                                                             : 32;     /* [ 31:0] GPIO_A pad output level control 310 */
        }Bit;
    }REG_GPIO_A_OUT;

    UINT8 EMPTY3[4]; /* 0x4 */

    union { /* 0x2010 [Excel Line :0224]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_B_IN                                                              : 32;     /* [ 31:0] GPIO_B pad input level read 310 */
        }Bit;
    }REG_GPIO_B_IN;
    union { /* 0x2014 [Excel Line :0225]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_B_OE                                                              : 32;     /* [ 31:0] GPIO_B pad out enable control 310 1 out  0 in */
        }Bit;
    }REG_GPIO_B_OE;
    union { /* 0x2018 [Excel Line :0226]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_B_OUT                                                             : 32;     /* [ 31:0] GPIO_B pad output level control 310 */
        }Bit;
    }REG_GPIO_B_OUT;

    UINT8 EMPTY4[4]; /* 0x4 */

    union { /* 0x2020 [Excel Line :0227]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_C_IN                                                              : 32;     /* [ 31:0] GPIO_C pad input level read 310 */
        }Bit;
    }REG_GPIO_C_IN;
    union { /* 0x2024 [Excel Line :0228]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_C_OE                                                              : 32;     /* [ 31:0] GPIO_C pad out enable control 310 1 out  0 in */
        }Bit;
    }REG_GPIO_C_OE;
    union { /* 0x2028 [Excel Line :0229]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_C_OUT                                                             : 32;     /* [ 31:0] GPIO_C pad output level control 310 */
        }Bit;
    }REG_GPIO_C_OUT;

    UINT8 EMPTY5[4]; /* 0x4 */

    union { /* 0x2030 [Excel Line :0230]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_D_IN                                                              : 32;     /* [ 31:0] GPIO_D pad input level read 310 */
        }Bit;
    }REG_GPIO_D_IN;
    union { /* 0x2034 [Excel Line :0231]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_D_OE                                                              : 32;     /* [ 31:0] GPIO_D pad out enable control 310 1 out  0 in */
        }Bit;
    }REG_GPIO_D_OE;
    union { /* 0x2038 [Excel Line :0232]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_D_OUT                                                             : 32;     /* [ 31:0] GPIO_D pad output level control 310 */
        }Bit;
    }REG_GPIO_D_OUT;

    UINT8 EMPTY6[196]; /* 0xC4 */
#endif
    union { /* 0x2100 [Excel Line :0233]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_INT_EN_0                                                          : 1;      /* [    0] GPIO_INT_0 enable */
            UINT32 GPIO_INT_EN_1                                                          : 1;      /* [    1] GPIO_INT_1 enable */
            UINT32 GPIO_INT_EN_2                                                          : 1;      /* [    2] GPIO_INT_2 enable */
            UINT32 GPIO_INT_EN_3                                                          : 1;      /* [    3] GPIO_INT_3 enable */
            UINT32 GPIO_INT_LEVEL_0                                                       : 1;      /* [    4] GPIO_INT_0 active level select 0 HIGH  1 LOW */
            UINT32 GPIO_INT_LEVEL_1                                                       : 1;      /* [    5] GPIO_INT_1 active level select 0 HIGH  1 LOW */
            UINT32 GPIO_INT_LEVEL_2                                                       : 1;      /* [    6] GPIO_INT_2 active level select 0 HIGH  1 LOW */
            UINT32 GPIO_INT_LEVEL_3                                                       : 1;      /* [    7] GPIO_INT_3 active level select 0 HIGH  1 LOW */
            UINT32 GPIO_INT_CLR_0                                                         : 1;      /* [    8] Force LOW on GPIO_INT_0 signal */
            UINT32 GPIO_INT_CLR_1                                                         : 1;      /* [    9] Force LOW on GPIO_INT_1 signal */
            UINT32 GPIO_INT_CLR_2                                                         : 1;      /* [   10] Force LOW on GPIO_INT_2 signal */
            UINT32 GPIO_INT_CLR_3                                                         : 1;      /* [   11] Force LOW on GPIO_INT_3 signal */
            UINT32 GPIO_DEBUG_INT_OUT_0                                                   : 1;      /* [   12] GPIO_INT_0 status read */
            UINT32 GPIO_DEBUG_INT_OUT_1                                                   : 1;      /* [   13] GPIO_INT_1 status read */
            UINT32 GPIO_DEBUG_INT_OUT_2                                                   : 1;      /* [   14] GPIO_INT_2 status read */
            UINT32 GPIO_DEBUG_INT_OUT_3                                                   : 1;      /* [   15] GPIO_INT_3 status read */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }REG_GPIO_INT;

    UINT8 EMPTY7[12]; /* 0xC */

    union { /* 0x2110 [Excel Line :0250]  */
        UINT32 Reg;
        struct {
            UINT32 GPIO_INT_PAD_ID_0                                                      : 8;      /* [  7:0] Select GPIO_ABCD pad to operate gpio intrrupt 0GPIO_INT_0
                                                                                                               12796          9564           6332           310
                                                                                                               GPIO_D310 GPIO_C310 GPIO_B310 GPIO_A310 */
            UINT32 GPIO_INT_PAD_ID_1                                                      : 8;      /* [ 15:8] Select GPIO_ABCD pad to operate gpio intrrupt 1GPIO_INT_1
                                                                                                               12796          9564           6332           310
                                                                                                               GPIO_D310 GPIO_C310 GPIO_B310 GPIO_A310 */
            UINT32 GPIO_INT_PAD_ID_2                                                      : 8;      /* [23:16] Select GPIO_ABCD pad to operate gpio intrrupt 2GPIO_INT_2
                                                                                                               12796          9564           6332           310
                                                                                                               GPIO_D310 GPIO_C310 GPIO_B310 GPIO_A310 */
            UINT32 GPIO_INT_PAD_ID_3                                                      : 8;      /* [31:24] Select GPIO_ABCD pad to operate gpio intrrupt 3GPIO_INT_3
                                                                                                               12796          9564           6332           310
                                                                                                               GPIO_D310 GPIO_C310 GPIO_B310 GPIO_A310 */
        }Bit;
    }REG_GPIO_INT_PAD_ID;

    UINT8 EMPTY8[3820]; /* 0xEEC */
#if 1
    /* GROUP Start : ICU_PAD_CTRL */
    struct {
         union { /* 0x3000 [Excel Line :0254]  */
             UINT32 Reg;
             struct {
                 UINT32 RESERVED5                                               : 1;      /* [    0]  */
                 UINT32 DS0                                                     : 1;      /* [    1] Used to select output drive strength
                                                                                                     DS0,DS1,DS2
                                                                                                     000  x1 100ohm Output PAD Driving Capability
                                                                                                     001  x2  66ohm Output PAD Driving Capability
                                                                                                     010  x3  50ohm Output PAD Driving Capability
                                                                                                     011  x4  40ohm Output PAD Driving Capability
                                                                                                     100  x5  33ohm Output PAD Driving Capability
                                                                                                     101  x6  25ohm Output PAD Driving Capability */
                 UINT32 DS1                                                     : 1;      /* [    2] Used to select output drive strength
                                                                                                     DS0,DS1,DS2
                                                                                                     000  x1 100ohm Output PAD Driving Capability
                                                                                                     001  x2  66ohm Output PAD Driving Capability
                                                                                                     010  x3  50ohm Output PAD Driving Capability
                                                                                                     011  x4  40ohm Output PAD Driving Capability
                                                                                                     100  x5  33ohm Output PAD Driving Capability
                                                                                                     101  x6  25ohm Output PAD Driving Capability */
                 UINT32 IE                                                      : 1;      /* [    3] Logic HIGH enables the input buffer */
                 UINT32 IS                                                      : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
                 UINT32 PE                                                      : 1;      /* [    5] Logic HIGH enables weak pull device */
                 UINT32 RESERVED4                                               : 1;      /* [    6]  */
                 UINT32 PS                                                      : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down  */
                 UINT32 RESERVED3                                               : 1;      /* [    8]  */
                 UINT32 RESERVED2                                               : 1;      /* [    9]  */
                 UINT32 DS2                                                     : 1;      /* [   10] Used to select output drive strength */
                 UINT32 RESERVED1                                               : 21;     /* [31:11]  */
             }Bit;
         }PAD_CTRL;
    }ICU_PAD_CTRL[105];
#else
    union { /* 0x3000 [Excel Line :0254]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 NTRST_DS0                                                              : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 NTRST_DS1                                                              : 1;      /* [    2] Used to select output drive strength */
            UINT32 NTRST_IE                                                               : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 NTRST_IS                                                               : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 NTRST_PE                                                               : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 NTRST_PS                                                               : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 NTRST_DS2                                                              : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_NTRST;
    union { /* 0x3004 [Excel Line :0265]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 TCK_DS0                                                                : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 TCK_DS1                                                                : 1;      /* [    2] Used to select output drive strength */
            UINT32 TCK_IE                                                                 : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 TCK_IS                                                                 : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 TCK_PE                                                                 : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 TCK_PS                                                                 : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 TCK_DS2                                                                : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_TCK;
    union { /* 0x3008 [Excel Line :0276]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 TMS_DS0                                                                : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 TMS_DS1                                                                : 1;      /* [    2] Used to select output drive strength */
            UINT32 TMS_IE                                                                 : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 TMS_IS                                                                 : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 TMS_PE                                                                 : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 TMS_PS                                                                 : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 TMS_DS2                                                                : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_TMS;
    union { /* 0x300C [Excel Line :0287]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 TDO_DS0                                                                : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 TDO_DS1                                                                : 1;      /* [    2] Used to select output drive strength */
            UINT32 TDO_IE                                                                 : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 TDO_IS                                                                 : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 TDO_PE                                                                 : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 TDO_PS                                                                 : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 TDO_DS2                                                                : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_TDO;
    union { /* 0x3010 [Excel Line :0298]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 TDI_DS0                                                                : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 TDI_DS1                                                                : 1;      /* [    2] Used to select output drive strength */
            UINT32 TDI_IE                                                                 : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 TDI_IS                                                                 : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 TDI_PE                                                                 : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 TDI_PS                                                                 : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 TDI_DS2                                                                : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_TDI;
    union { /* 0x3014 [Excel Line :0309]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PCIE0_WAKE_N_DS0                                                       : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PCIE0_WAKE_N_DS1                                                       : 1;      /* [    2] Used to select output drive strength */
            UINT32 PCIE0_WAKE_N_IE                                                        : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PCIE0_WAKE_N_IS                                                        : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PCIE0_WAKE_N_PE                                                        : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PCIE0_WAKE_N_PS                                                        : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PCIE0_WAKE_N_DS2                                                       : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PCIE0_WAKE_N;
    union { /* 0x3018 [Excel Line :0320]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PCIE0_CLKREQ_N_DS0                                                     : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PCIE0_CLKREQ_N_DS1                                                     : 1;      /* [    2] Used to select output drive strength */
            UINT32 PCIE0_CLKREQ_N_IE                                                      : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PCIE0_CLKREQ_N_IS                                                      : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PCIE0_CLKREQ_N_PE                                                      : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PCIE0_CLKREQ_N_PS                                                      : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PCIE0_CLKREQ_N_DS2                                                     : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PCIE0_CLKREQ_N;
    union { /* 0x301C [Excel Line :0331]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PCIE1_WAKE_N_DS0                                                       : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PCIE1_WAKE_N_DS1                                                       : 1;      /* [    2] Used to select output drive strength */
            UINT32 PCIE1_WAKE_N_IE                                                        : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PCIE1_WAKE_N_IS                                                        : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PCIE1_WAKE_N_PE                                                        : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PCIE1_WAKE_N_PS                                                        : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PCIE1_WAKE_N_DS2                                                       : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PCIE1_WAKE_N;
    union { /* 0x3020 [Excel Line :0342]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PCIE1_CLKREQ_N_DS0                                                     : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PCIE1_CLKREQ_N_DS1                                                     : 1;      /* [    2] Used to select output drive strength */
            UINT32 PCIE1_CLKREQ_N_IE                                                      : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PCIE1_CLKREQ_N_IS                                                      : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PCIE1_CLKREQ_N_PE                                                      : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PCIE1_CLKREQ_N_PS                                                      : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PCIE1_CLKREQ_N_DS2                                                     : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PCIE1_CLKREQ_N;
    union { /* 0x3024 [Excel Line :0353]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 USB_OVRCUR_N_DS0                                                       : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 USB_OVRCUR_N_DS1                                                       : 1;      /* [    2] Used to select output drive strength */
            UINT32 USB_OVRCUR_N_IE                                                        : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 USB_OVRCUR_N_IS                                                        : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 USB_OVRCUR_N_PE                                                        : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 USB_OVRCUR_N_PS                                                        : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 USB_OVRCUR_N_DS2                                                       : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_USB_OVRCUR_N;
    union { /* 0x3028 [Excel Line :0364]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 USB_PORT_PWR_DS0                                                       : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 USB_PORT_PWR_DS1                                                       : 1;      /* [    2] Used to select output drive strength */
            UINT32 USB_PORT_PWR_IE                                                        : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 USB_PORT_PWR_IS                                                        : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 USB_PORT_PWR_PE                                                        : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 USB_PORT_PWR_PS                                                        : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 USB_PORT_PWR_DS2                                                       : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_USB_PORT_PWR;
    union { /* 0x302C [Excel Line :0375]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C1_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C1_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C1_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C1_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C1_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C1_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C1_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C1_SDA;
    union { /* 0x3030 [Excel Line :0386]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C1_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C1_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C1_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C1_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C1_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C1_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C1_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C1_SCL;
    union { /* 0x3034 [Excel Line :0397]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SEN0_CK_O_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SEN0_CK_O_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SEN0_CK_O_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SEN0_CK_O_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SEN0_CK_O_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SEN0_CK_O_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SEN0_CK_O_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SEN0_CK_O;
    union { /* 0x3038 [Excel Line :0408]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SEN0_RSTN_O_DS0                                                        : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SEN0_RSTN_O_DS1                                                        : 1;      /* [    2] Used to select output drive strength */
            UINT32 SEN0_RSTN_O_IE                                                         : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SEN0_RSTN_O_IS                                                         : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SEN0_RSTN_O_PE                                                         : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SEN0_RSTN_O_PS                                                         : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SEN0_RSTN_O_DS2                                                        : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SEN0_RSTN_O;
    union { /* 0x303C [Excel Line :0419]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SEN1_CK_O_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SEN1_CK_O_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SEN1_CK_O_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SEN1_CK_O_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SEN1_CK_O_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SEN1_CK_O_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SEN1_CK_O_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SEN1_CK_O;
    union { /* 0x3040 [Excel Line :0430]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SEN1_RSTN_O_DS0                                                        : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SEN1_RSTN_O_DS1                                                        : 1;      /* [    2] Used to select output drive strength */
            UINT32 SEN1_RSTN_O_IE                                                         : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SEN1_RSTN_O_IS                                                         : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SEN1_RSTN_O_PE                                                         : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SEN1_RSTN_O_PS                                                         : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SEN1_RSTN_O_DS2                                                        : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SEN1_RSTN_O;
    union { /* 0x3044 [Excel Line :0441]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C0_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C0_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C0_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C0_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C0_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C0_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C0_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C0_SCL;
    union { /* 0x3048 [Excel Line :0452]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C0_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C0_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C0_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C0_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C0_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C0_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C0_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C0_SDA;
    union { /* 0x304C [Excel Line :0463]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C2_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C2_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C2_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C2_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C2_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C2_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C2_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C2_SCL;
    union { /* 0x3050 [Excel Line :0474]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C2_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C2_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C2_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C2_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C2_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C2_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C2_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C2_SDA;
    union { /* 0x3054 [Excel Line :0485]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C3_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C3_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C3_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C3_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C3_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C3_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C3_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C3_SCL;
    union { /* 0x3058 [Excel Line :0496]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C3_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C3_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C3_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C3_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C3_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C3_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C3_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C3_SDA;
    union { /* 0x305C [Excel Line :0507]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C4_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C4_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C4_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C4_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C4_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C4_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C4_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C4_SCL;
    union { /* 0x3060 [Excel Line :0518]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C4_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C4_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C4_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C4_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C4_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C4_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C4_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C4_SDA;
    union { /* 0x3064 [Excel Line :0529]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C5_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C5_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C5_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C5_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C5_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C5_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C5_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C5_SCL;
    union { /* 0x3068 [Excel Line :0540]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C5_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C5_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C5_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C5_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C5_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C5_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C5_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C5_SDA;
    union { /* 0x306C [Excel Line :0551]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C6_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C6_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C6_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C6_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C6_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C6_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C6_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C6_SCL;
    union { /* 0x3070 [Excel Line :0562]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C6_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C6_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C6_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C6_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C6_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C6_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C6_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C6_SDA;
    union { /* 0x3074 [Excel Line :0573]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C7_SCL_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C7_SCL_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C7_SCL_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C7_SCL_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C7_SCL_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C7_SCL_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C7_SCL_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C7_SCL;
    union { /* 0x3078 [Excel Line :0584]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2C7_SDA_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2C7_SDA_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2C7_SDA_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2C7_SDA_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2C7_SDA_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2C7_SDA_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2C7_SDA_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2C7_SDA;
    union { /* 0x307C [Excel Line :0595]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PWM_0_DS0                                                              : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PWM_0_DS1                                                              : 1;      /* [    2] Used to select output drive strength */
            UINT32 PWM_0_IE                                                               : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PWM_0_IS                                                               : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PWM_0_PE                                                               : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PWM_0_PS                                                               : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PWM_0_DS2                                                              : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PWM_0;
    union { /* 0x3080 [Excel Line :0606]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PWM_1_DS0                                                              : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PWM_1_DS1                                                              : 1;      /* [    2] Used to select output drive strength */
            UINT32 PWM_1_IE                                                               : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PWM_1_IS                                                               : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PWM_1_PE                                                               : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PWM_1_PS                                                               : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PWM_1_DS2                                                              : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PWM_1;
    union { /* 0x3084 [Excel Line :0617]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PWM_2_DS0                                                              : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PWM_2_DS1                                                              : 1;      /* [    2] Used to select output drive strength */
            UINT32 PWM_2_IE                                                               : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PWM_2_IS                                                               : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PWM_2_PE                                                               : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PWM_2_PS                                                               : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PWM_2_DS2                                                              : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PWM_2;
    union { /* 0x3088 [Excel Line :0628]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 PWM_3_DS0                                                              : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 PWM_3_DS1                                                              : 1;      /* [    2] Used to select output drive strength */
            UINT32 PWM_3_IE                                                               : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 PWM_3_IS                                                               : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 PWM_3_PE                                                               : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 PWM_3_PS                                                               : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 PWM_3_DS2                                                              : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_PWM_3;
    union { /* 0x308C [Excel Line :0639]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI0_CK_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI0_CK_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI0_CK_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI0_CK_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI0_CK_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI0_CK_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI0_CK_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI0_CK;
    union { /* 0x3090 [Excel Line :0650]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI0_SSN_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI0_SSN_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI0_SSN_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI0_SSN_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI0_SSN_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI0_SSN_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI0_SSN_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI0_SSN;
    union { /* 0x3094 [Excel Line :0661]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI0_MOSI_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI0_MOSI_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI0_MOSI_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI0_MOSI_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI0_MOSI_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI0_MOSI_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI0_MOSI_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI0_MOSI;
    union { /* 0x3098 [Excel Line :0672]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI0_MISO_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI0_MISO_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI0_MISO_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI0_MISO_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI0_MISO_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI0_MISO_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI0_MISO_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI0_MISO;
    union { /* 0x309C [Excel Line :0683]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI1_CK_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI1_CK_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI1_CK_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI1_CK_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI1_CK_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI1_CK_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI1_CK_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI1_CK;
    union { /* 0x30A0 [Excel Line :0694]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI1_SSN_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI1_SSN_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI1_SSN_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI1_SSN_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI1_SSN_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI1_SSN_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI1_SSN_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI1_SSN;
    union { /* 0x30A4 [Excel Line :0705]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI1_MOSI_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI1_MOSI_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI1_MOSI_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI1_MOSI_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI1_MOSI_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI1_MOSI_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI1_MOSI_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI1_MOSI;
    union { /* 0x30A8 [Excel Line :0716]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI1_MISO_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI1_MISO_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI1_MISO_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI1_MISO_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI1_MISO_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI1_MISO_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI1_MISO_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI1_MISO;
    union { /* 0x30AC [Excel Line :0727]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI2_CK_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI2_CK_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI2_CK_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI2_CK_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI2_CK_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI2_CK_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI2_CK_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI2_CK;
    union { /* 0x30B0 [Excel Line :0738]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI2_SSN_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI2_SSN_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI2_SSN_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI2_SSN_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI2_SSN_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI2_SSN_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI2_SSN_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI2_SSN;
    union { /* 0x30B4 [Excel Line :0749]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI2_MOSI_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI2_MOSI_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI2_MOSI_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI2_MOSI_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI2_MOSI_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI2_MOSI_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI2_MOSI_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI2_MOSI;
    union { /* 0x30B8 [Excel Line :0760]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SPI2_MISO_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SPI2_MISO_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 SPI2_MISO_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SPI2_MISO_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SPI2_MISO_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SPI2_MISO_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SPI2_MISO_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SPI2_MISO;
    union { /* 0x30BC [Excel Line :0771]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2S_DIN_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2S_DIN_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2S_DIN_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2S_DIN_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2S_DIN_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2S_DIN_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2S_DIN_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2S_DIN;
    union { /* 0x30C0 [Excel Line :0782]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2S_DOUT_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2S_DOUT_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2S_DOUT_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2S_DOUT_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2S_DOUT_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2S_DOUT_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2S_DOUT_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2S_DOUT;
    union { /* 0x30C4 [Excel Line :0793]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2S_WCLK_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2S_WCLK_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2S_WCLK_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2S_WCLK_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2S_WCLK_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2S_WCLK_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2S_WCLK_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2S_WCLK;
    union { /* 0x30C8 [Excel Line :0804]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 I2S_SCLK_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 I2S_SCLK_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 I2S_SCLK_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 I2S_SCLK_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 I2S_SCLK_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 I2S_SCLK_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 I2S_SCLK_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_I2S_SCLK;
    union { /* 0x30CC [Excel Line :0815]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 CAN0_RX_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 CAN0_RX_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 CAN0_RX_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 CAN0_RX_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 CAN0_RX_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 CAN0_RX_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 CAN0_RX_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_CAN0_RX;
    union { /* 0x30D0 [Excel Line :0826]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 CAN0_TX_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 CAN0_TX_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 CAN0_TX_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 CAN0_TX_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 CAN0_TX_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 CAN0_TX_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 CAN0_TX_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_CAN0_TX;
    union { /* 0x30D4 [Excel Line :0837]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 CAN1_RX_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 CAN1_RX_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 CAN1_RX_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 CAN1_RX_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 CAN1_RX_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 CAN1_RX_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 CAN1_RX_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_CAN1_RX;
    union { /* 0x30D8 [Excel Line :0848]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 CAN1_TX_DS0                                                            : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 CAN1_TX_DS1                                                            : 1;      /* [    2] Used to select output drive strength */
            UINT32 CAN1_TX_IE                                                             : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 CAN1_TX_IS                                                             : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 CAN1_TX_PE                                                             : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 CAN1_TX_PS                                                             : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 CAN1_TX_DS2                                                            : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_CAN1_TX;
    union { /* 0x30DC [Excel Line :0859]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART0_RX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART0_RX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART0_RX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART0_RX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART0_RX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART0_RX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART0_RX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART0_RX;
    union { /* 0x30E0 [Excel Line :0870]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART0_TX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART0_TX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART0_TX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART0_TX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART0_TX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART0_TX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART0_TX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART0_TX;
    union { /* 0x30E4 [Excel Line :0881]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART1_RX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART1_RX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART1_RX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART1_RX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART1_RX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART1_RX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART1_RX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART1_RX;
    union { /* 0x30E8 [Excel Line :0892]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART1_TX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART1_TX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART1_TX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART1_TX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART1_TX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART1_TX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART1_TX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART1_TX;
    union { /* 0x30EC [Excel Line :0903]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART2_RX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART2_RX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART2_RX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART2_RX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART2_RX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART2_RX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART2_RX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART2_RX;
    union { /* 0x30F0 [Excel Line :0914]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART2_TX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART2_TX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART2_TX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART2_TX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART2_TX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART2_TX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART2_TX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART2_TX;
    union { /* 0x30F4 [Excel Line :0925]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART3_RX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART3_RX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART3_RX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART3_RX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART3_RX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART3_RX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART3_RX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART3_RX;
    union { /* 0x30F8 [Excel Line :0936]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 UART3_TX_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 UART3_TX_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 UART3_TX_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 UART3_TX_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 UART3_TX_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 UART3_TX_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 UART3_TX_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_UART3_TX;
    union { /* 0x30FC [Excel Line :0947]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_SCK_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_SCK_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_SCK_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_SCK_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_SCK_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_SCK_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_SCK_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_SCK;
    union { /* 0x3100 [Excel Line :0958]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_CSN_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_CSN_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_CSN_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_CSN_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_CSN_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_CSN_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_CSN_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_CSN;
    union { /* 0x3104 [Excel Line :0969]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_DQ0_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_DQ0_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_DQ0_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_DQ0_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_DQ0_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_DQ0_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_DQ0_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_DQ0;
    union { /* 0x3108 [Excel Line :0980]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_DQ1_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_DQ1_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_DQ1_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_DQ1_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_DQ1_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_DQ1_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_DQ1_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_DQ1;
    union { /* 0x310C [Excel Line :0991]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_DQ2_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_DQ2_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_DQ2_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_DQ2_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_DQ2_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_DQ2_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_DQ2_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_DQ2;
    union { /* 0x3110 [Excel Line :1002]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 QSPI_DQ3_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 QSPI_DQ3_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 QSPI_DQ3_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 QSPI_DQ3_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 QSPI_DQ3_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 QSPI_DQ3_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 QSPI_DQ3_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_QSPI_DQ3;
    union { /* 0x3114 [Excel Line :1013]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_VOL_SEL_DS0                                                         : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_VOL_SEL_DS1                                                         : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_VOL_SEL_IE                                                          : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_VOL_SEL_IS                                                          : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_VOL_SEL_PE                                                          : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_VOL_SEL_PS                                                          : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_VOL_SEL_DS2                                                         : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_VOL_SEL;
    union { /* 0x3118 [Excel Line :1024]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_VOL_SEL_DS0                                                       : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_VOL_SEL_DS1                                                       : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_VOL_SEL_IE                                                        : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_VOL_SEL_IS                                                        : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_VOL_SEL_PE                                                        : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_VOL_SEL_PS                                                        : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_VOL_SEL_DS2                                                       : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_VOL_SEL;
    union { /* 0x311C [Excel Line :1035]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_CLK_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_CLK_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_CLK_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_CLK_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_CLK_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_CLK_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_CLK_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_CLK;
    union { /* 0x3120 [Excel Line :1046]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_CMD_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_CMD_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_CMD_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_CMD_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_CMD_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_CMD_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_CMD_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_CMD;
    union { /* 0x3124 [Excel Line :1057]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_DQ0_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_DQ0_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_DQ0_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_DQ0_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_DQ0_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_DQ0_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_DQ0_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_DQ0;
    union { /* 0x3128 [Excel Line :1068]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_DQ1_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_DQ1_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_DQ1_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_DQ1_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_DQ1_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_DQ1_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_DQ1_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_DQ1;
    union { /* 0x312C [Excel Line :1079]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_DQ2_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_DQ2_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_DQ2_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_DQ2_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_DQ2_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_DQ2_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_DQ2_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_DQ2;
    union { /* 0x3130 [Excel Line :1090]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_DQ3_DS0                                                             : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_DQ3_DS1                                                             : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_DQ3_IE                                                              : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_DQ3_IS                                                              : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_DQ3_PE                                                              : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_DQ3_PS                                                              : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_DQ3_DS2                                                             : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_DQ3;
    union { /* 0x3134 [Excel Line :1101]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_DETECT_N_DS0                                                        : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_DETECT_N_DS1                                                        : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_DETECT_N_IE                                                         : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_DETECT_N_IS                                                         : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_DETECT_N_PE                                                         : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_DETECT_N_PS                                                         : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_DETECT_N_DS2                                                        : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_DETECT_N;
    union { /* 0x3138 [Excel Line :1112]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 SD_WRITE_PROT_DS0                                                      : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 SD_WRITE_PROT_DS1                                                      : 1;      /* [    2] Used to select output drive strength */
            UINT32 SD_WRITE_PROT_IE                                                       : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 SD_WRITE_PROT_IS                                                       : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 SD_WRITE_PROT_PE                                                       : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 SD_WRITE_PROT_PS                                                       : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 SD_WRITE_PROT_DS2                                                      : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_SD_WRITE_PROT;
    union { /* 0x313C [Excel Line :1123]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_CLK_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_CLK_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_CLK_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_CLK_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_CLK_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_CLK_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_CLK_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_CLK;
    union { /* 0x3140 [Excel Line :1134]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_RSTN_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_RSTN_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_RSTN_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_RSTN_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_RSTN_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_RSTN_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_RSTN_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_RSTN;
    union { /* 0x3144 [Excel Line :1145]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_CMD_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_CMD_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_CMD_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_CMD_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_CMD_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_CMD_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_CMD_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_CMD;
    union { /* 0x3148 [Excel Line :1156]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ0_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ0_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ0_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ0_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ0_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ0_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ0_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ0;
    union { /* 0x314C [Excel Line :1167]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ1_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ1_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ1_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ1_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ1_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ1_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ1_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ1;
    union { /* 0x3150 [Excel Line :1178]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ2_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ2_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ2_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ2_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ2_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ2_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ2_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ2;
    union { /* 0x3154 [Excel Line :1189]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ3_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ3_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ3_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ3_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ3_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ3_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ3_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ3;
    union { /* 0x3158 [Excel Line :1200]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ4_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ4_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ4_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ4_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ4_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ4_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ4_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ4;
    union { /* 0x315C [Excel Line :1211]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ5_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ5_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ5_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ5_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ5_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ5_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ5_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ5;
    union { /* 0x3160 [Excel Line :1222]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ6_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ6_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ6_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ6_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ6_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ6_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ6_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ6;
    union { /* 0x3164 [Excel Line :1233]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EMMC_DQ7_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EMMC_DQ7_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EMMC_DQ7_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EMMC_DQ7_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EMMC_DQ7_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EMMC_DQ7_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EMMC_DQ7_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EMMC_DQ7;
    union { /* 0x3168 [Excel Line :1244]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXCLK_DS0                                                         : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXCLK_DS1                                                         : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXCLK_IE                                                          : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXCLK_IS                                                          : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXCLK_PE                                                          : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXCLK_PS                                                          : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXCLK_DS2                                                         : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXCLK;
    union { /* 0x316C [Excel Line :1255]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXCLK_DS0                                                         : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXCLK_DS1                                                         : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXCLK_IE                                                          : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXCLK_IS                                                          : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXCLK_PE                                                          : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXCLK_PS                                                          : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXCLK_DS2                                                         : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXCLK;
    union { /* 0x3170 [Excel Line :1266]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RMII_CLK_DS0                                                      : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RMII_CLK_DS1                                                      : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RMII_CLK_IE                                                       : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RMII_CLK_IS                                                       : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RMII_CLK_PE                                                       : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RMII_CLK_PS                                                       : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RMII_CLK_DS2                                                      : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RMII_CLK;
    union { /* 0x3174 [Excel Line :1277]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_MDC_DS0                                                           : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_MDC_DS1                                                           : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_MDC_IE                                                            : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_MDC_IS                                                            : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_MDC_PE                                                            : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_MDC_PS                                                            : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_MDC_DS2                                                           : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_MDC;
    union { /* 0x3178 [Excel Line :1288]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_MDIO_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_MDIO_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_MDIO_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_MDIO_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_MDIO_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_MDIO_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_MDIO_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_MDIO;
    union { /* 0x317C [Excel Line :1299]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXEN_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXEN_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXEN_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXEN_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXEN_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXEN_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXEN_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXEN;
    union { /* 0x3180 [Excel Line :1310]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXD0_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXD0_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXD0_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXD0_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXD0_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXD0_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXD0_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXD0;
    union { /* 0x3184 [Excel Line :1321]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXD1_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXD1_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXD1_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXD1_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXD1_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXD1_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXD1_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXD1;
    union { /* 0x3188 [Excel Line :1332]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXD2_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXD2_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXD2_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXD2_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXD2_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXD2_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXD2_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXD2;
    union { /* 0x318C [Excel Line :1343]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_TXD3_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_TXD3_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_TXD3_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_TXD3_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_TXD3_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_TXD3_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_TXD3_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_TXD3;
    union { /* 0x3190 [Excel Line :1354]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXDV_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXDV_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXDV_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXDV_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXDV_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXDV_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXDV_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXDV;
    union { /* 0x3194 [Excel Line :1365]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXD0_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXD0_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXD0_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXD0_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXD0_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXD0_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXD0_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXD0;
    union { /* 0x3198 [Excel Line :1376]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXD1_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXD1_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXD1_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXD1_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXD1_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXD1_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXD1_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXD1;
    union { /* 0x319C [Excel Line :1387]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXD2_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXD2_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXD2_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXD2_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXD2_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXD2_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXD2_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXD2;
    union { /* 0x31A0 [Excel Line :1398]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                              : 1;      /* [    0]  */
            UINT32 EQOS_RXD3_DS0                                                          : 1;      /* [    1] Used to select output drive strength
                                                                                                               DS0DS1DS2
                                                                                                                000  x1100ohm Output PAD Driving Capability
                                                                                                                001  x266ohm Output PAD Driving Capability
                                                                                                                010  x350ohm Output PAD Driving Capability
                                                                                                                011  x440ohm Output PAD Driving Capability
                                                                                                                100  x533ohm Output PAD Driving Capability
                                                                                                                101  x625ohm Output PAD Driving Capability */
            UINT32 EQOS_RXD3_DS1                                                          : 1;      /* [    2] Used to select output drive strength */
            UINT32 EQOS_RXD3_IE                                                           : 1;      /* [    3] Logic HIGH enables the input buffer */
            UINT32 EQOS_RXD3_IS                                                           : 1;      /* [    4] Logic LOW selects CMOS input and logic HIGH selects Schmitt input */
            UINT32 EQOS_RXD3_PE                                                           : 1;      /* [    5] Logic HIGH enables weak pull device */
            UINT32 RESERVED3                                                              : 1;      /* [    6]  */
            UINT32 EQOS_RXD3_PS                                                           : 1;      /* [    7] Logic HIGH selects Pull Up logic LOW selected Pull Down */
            UINT32 RESERVED2                                                              : 2;      /* [  9:8]  */
            UINT32 EQOS_RXD3_DS2                                                          : 1;      /* [   10] Used to select output drive strength */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }REG_PAD_CTRL_EQOS_RXD3;
#endif
    UINT8 EMPTY9[348]; /* 0x15C */

    union { /* 0x3300 [Excel Line :1409]  */
        UINT32 Reg;
        struct {
            UINT32 IO_PD_PSW_SEN                                                          : 1;      /* [    0] SEN Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED7                                                              : 3;      /* [  3:1]  */
            UINT32 IO_PD_PSW_PERI                                                         : 1;      /* [    4] PERI Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED6                                                              : 3;      /* [  7:5]  */
            UINT32 IO_PD_PSW_QSPI                                                         : 1;      /* [    8] QSPI Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED5                                                              : 3;      /* [ 11:9]  */
            UINT32 IO_PD_PSW_EMMC                                                         : 1;      /* [   12] EMMC Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED4                                                              : 3;      /* [15:13]  */
            UINT32 IO_PD_PSW_SDIO                                                         : 1;      /* [   16] SDIO Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED3                                                              : 3;      /* [19:17]  */
            UINT32 IO_PD_PSW_GMAC                                                         : 1;      /* [   20] GMAC Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED2                                                              : 3;      /* [23:21]  */
            UINT32 IO_PD_PSW_SYS                                                          : 1;      /* [   24] SYS Group pad operate voltage select 1 18V  0 33V */
            UINT32 RESERVED1                                                              : 7;      /* [31:25]  */
        }Bit;
    }REG_IO_PD_PSW;

    UINT8 EMPTY10[48380]; /* 0xBCFC */

    union { /* 0xF000 [Excel Line :1423]  */
        UINT32 Reg;
        struct {
            UINT32 PARALLEL_OUT_MUX_SEL                                                   : 1;      /* [    0] Logic HIGH selects parallel_vision1 logic LOW selected parallel_vision0 */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }REG_PARALLEL_OUT_MUX_SEL;

    UINT8 EMPTY11[3836]; /* 0xEFC */

    union { /* 0xFF00 [Excel Line :1425]  */
        UINT32 Reg;
        struct {
            UINT32 RSVD0                                                                  : 32;     /* [ 31:0] Reseved Value for ECC 310 */
        }Bit;
    }REG_RSVD0;
    union { /* 0xFF04 [Excel Line :1426]  */
        UINT32 Reg;
        struct {
            UINT32 RSVD1                                                                  : 32;     /* [ 31:0] Reseved Value for ECC 310 */
        }Bit;
    }REG_RSVD1;
}DRV_A6_ICU_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_A6_ICU_REGISTER* const RegA6_ICU = (DRV_A6_ICU_REGISTER*)APACHE_A6_ICU_BASE_ADDR;
 */



#endif /*  end of  DRV_REGISTER_A6_ICU__ */

