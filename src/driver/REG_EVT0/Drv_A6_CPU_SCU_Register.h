/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_CPU_SCU_Register.h
*   Date       : 2022-07-04 18:38
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_CPU_SCU_H__
#define DRV_REGISTER_A6_CPU_SCU_H__

#define APACHE_A6_CPU_SCU_BASE_ADDR        0x0C010000

/* PRQA S 0779 ++ */
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

    UINT8 EMPTY1[1012]; /* 0x3F4 */

    union { /* 0x0400 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_CPU_PRE1                                                    : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_PRE1_CLKMUX;
    union { /* 0x0404 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_CPU_PRE2                                                    : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_PRE2_CLKMUX;

    UINT8 EMPTY2[248]; /* 0xF8 */

    union { /* 0x0500 [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_A65_CORE                                                     : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CORE_CLKEN;
    union { /* 0x0504 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_A65_SYSTEM                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_SYSTEM_CLKEN;
    union { /* 0x0508 [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_R5_CORE                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_CORE_CLKEN;

    UINT8 EMPTY3[244]; /* 0xF4 */

    union { /* 0x0600 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_CORE                                                : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_A65_CORE_CLKDIV;
    union { /* 0x0604 [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_SYSTEM                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_A65_SYSTEM_CLKDIV;
    union { /* 0x0608 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_R5_CORE                                                 : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_R5_CORE_CLKDIV;

    UINT8 EMPTY4[2548]; /* 0x9F4 */

    union { /* 0x1000 [Excel Line :0027]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_AXI                                                 : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_AXI_CLKDIV;
    union { /* 0x1004 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_CS                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CS_CLKDIV;
    union { /* 0x1008 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_PERI                                                : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_PERI_CLKDIV;
    union { /* 0x100C [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_A65_TRACE                                               : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_TRACE_CLKDIV;
    union { /* 0x1010 [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_R5_AXI                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_AXI_CLKDIV;
    union { /* 0x1014 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_R5_CS                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_CS_CLKDIV;
    union { /* 0x1018 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_R5_APB                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_APB_CLKDIV;
    union { /* 0x101C [Excel Line :0041]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_CPU_R5_TRACE                                                : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_TRACE_CLKDIV;

    UINT8 EMPTY5[4064]; /* 0xFE0 */

    union { /* 0x2000 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_A65_SCLK                                                     : 1;      /* [    0]  */
            UINT32 CLKEN_CPU_A65_AXI                                                      : 1;      /* [    1]  */
            UINT32 CLKEN_CPU_A65_APB                                                      : 1;      /* [    2]  */
            UINT32 CLKEN_CPU_A65_PERI                                                     : 1;      /* [    3]  */
            UINT32 CLKEN_CPU_A65_GIC                                                      : 1;      /* [    4]  */
            UINT32 RESERVED2                                                              : 7;      /* [ 11:5]  */
            UINT32 CLKEN_CPU_A65_CS                                                       : 1;      /* [   12]  */
            UINT32 CLKEN_CPU_A65_TRACE                                                    : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU_A65_CLKEN;
    union { /* 0x2004 [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_R5_CLKIN                                                     : 1;      /* [    0]  */
            UINT32 CLKEN_CPU_R5_AXI                                                       : 1;      /* [    1]  */
            UINT32 CLKEN_CPU_R5_APB                                                       : 1;      /* [    2]  */
            UINT32 RESERVED2                                                              : 9;      /* [ 11:3]  */
            UINT32 CLKEN_CPU_R5_CS                                                        : 1;      /* [   12]  */
            UINT32 CLKEN_CPU_R5_TRACE                                                     : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU_R5_CLKEN;
    union { /* 0x2008 [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_CPU_SCU_APB                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_SCU_CLKEN;

    UINT8 EMPTY6[4084]; /* 0xFF4 */

    union { /* 0x3000 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_WARM_0                                       : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_WARM_1                                       : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_WARM_2                                       : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_WARM_3                                       : 1;      /* [    3]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_COLD_0                                       : 1;      /* [    4]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_COLD_1                                       : 1;      /* [    5]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_COLD_2                                       : 1;      /* [    6]  */
            UINT32 ONGO_RST_ACT_CPU_A65_CORE_COLD_3                                       : 1;      /* [    7]  */
            UINT32 ONGO_RST_ACT_CPU_A65_SCLK_WARM                                         : 1;      /* [    8]  */
            UINT32 ONGO_RST_ACT_CPU_A65_SCLK_COLD                                         : 1;      /* [    9]  */
            UINT32 ONGO_RST_ACT_CPU_A65_AXIM                                              : 1;      /* [   10]  */
            UINT32 ONGO_RST_ACT_CPU_A65_AXIP                                              : 1;      /* [   11]  */
            UINT32 ONGO_RST_ACT_CPU_A65_APB                                               : 1;      /* [   12]  */
            UINT32 ONGO_RST_ACT_CPU_A65_ATB                                               : 1;      /* [   13]  */
            UINT32 ONGO_RST_ACT_CPU_A65_GIC                                               : 1;      /* [   14]  */
            UINT32 ONGO_RST_ACT_CPU_A65_PERIPH                                            : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_ONGO_RST_ACT;
    union { /* 0x3004 [Excel Line :0078]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_A65_CS_ATB                                                : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_A65_CS_APB                                                : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_A65_CS_AXI                                                : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_A65_CS_TRACE                                              : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }A65_CS_ONGO_RST_ACT;
    union { /* 0x3008 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_CPU_R5_CORE_WARM                                          : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_CPU_R5_CORE_COLD                                          : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_CPU_R5_AXIM                                               : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_CPU_R5_AXIP                                               : 1;      /* [    3]  */
            UINT32 ONGO_RST_ACT_CPU_R5_AXIS0                                              : 1;      /* [    4]  */
            UINT32 ONGO_RST_ACT_CPU_R5_APBDBG                                             : 1;      /* [    5]  */
            UINT32 ONGO_RST_ACT_CPU_R5_CTI                                                : 1;      /* [    6]  */
            UINT32 ONGO_RST_ACT_CPU_R5_ATB                                                : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_ONGO_RST_ACT;
    union { /* 0x300C [Excel Line :0092]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_R5_CS_ATB                                                 : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_R5_CS_APBSYS                                              : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_R5_CS_CTM                                                 : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_R5_CS_TRACE                                               : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }R5_CS_ONGO_RST_ACT;
    union { /* 0x3010 [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_CPU_A65_CORE_WARM_0                                        : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_WARM_1                                        : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_WARM_2                                        : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_WARM_3                                        : 1;      /* [    3]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_COLD_0                                        : 1;      /* [    4]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_COLD_1                                        : 1;      /* [    5]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_COLD_2                                        : 1;      /* [    6]  */
            UINT32 PUL_RST_ACT_CPU_A65_CORE_COLD_3                                        : 1;      /* [    7]  */
            UINT32 PUL_RST_ACT_CPU_A65_SCLK_WARM                                          : 1;      /* [    8]  */
            UINT32 PUL_RST_ACT_CPU_A65_SCLK_COLD                                          : 1;      /* [    9]  */
            UINT32 PUL_RST_ACT_CPU_A65_AXIM                                               : 1;      /* [   10]  */
            UINT32 PUL_RST_ACT_CPU_A65_AXIP                                               : 1;      /* [   11]  */
            UINT32 PUL_RST_ACT_CPU_A65_APB                                                : 1;      /* [   12]  */
            UINT32 PUL_RST_ACT_CPU_A65_ATB                                                : 1;      /* [   13]  */
            UINT32 PUL_RST_ACT_CPU_A65_GIC                                                : 1;      /* [   14]  */
            UINT32 PUL_RST_ACT_CPU_A65_PERIPH                                             : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_ACT;
    union { /* 0x3014 [Excel Line :0114]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_A65_CS_ATB                                                 : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_A65_CS_APB                                                 : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_A65_CS_AXI                                                 : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_A65_CS_TRACE                                               : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }A65_CS_PUL_RST_ACT;
    union { /* 0x3018 [Excel Line :0119]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_CPU_R5_CORE_WARM                                           : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_CPU_R5_CORE_COLD                                           : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_CPU_R5_AXIM                                                : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_CPU_R5_AXIP                                                : 1;      /* [    3]  */
            UINT32 PUL_RST_ACT_CPU_R5_AXIS0                                               : 1;      /* [    4]  */
            UINT32 PUL_RST_ACT_CPU_R5_APBDBG                                              : 1;      /* [    5]  */
            UINT32 PUL_RST_ACT_CPU_R5_CTI                                                 : 1;      /* [    6]  */
            UINT32 PUL_RST_ACT_CPU_R5_ATB                                                 : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_PUL_RST_ACT;
    union { /* 0x301C [Excel Line :0128]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_R5_CS_ATB                                                  : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_R5_CS_APBSYS                                               : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_R5_CS_CTM                                                  : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_R5_CS_TRACE                                                : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }R5_CS_PUL_RST_ACT;
    union { /* 0x3020 [Excel Line :0133]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_WARM_0                                      : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_WARM_1                                      : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH0;
    union { /* 0x3024 [Excel Line :0135]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_WARM_2                                      : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_WARM_3                                      : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH1;
    union { /* 0x3028 [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_COLD_0                                      : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_COLD_1                                      : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH2;
    union { /* 0x302C [Excel Line :0139]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_COLD_2                                      : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_CORE_COLD_3                                      : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH3;
    union { /* 0x3030 [Excel Line :0141]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_SCLK_WARM                                        : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_SCLK_COLD                                        : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH4;
    union { /* 0x3034 [Excel Line :0143]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_AXIM                                             : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_AXIP                                             : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH5;
    union { /* 0x3038 [Excel Line :0145]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_APB                                              : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_ATB                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH6;
    union { /* 0x303C [Excel Line :0147]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_A65_GIC                                              : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_A65_PERIPH                                           : 16;     /* [31:16]  */
        }Bit;
    }CPU_A65_PUL_RST_WIDTH7;
    union { /* 0x3040 [Excel Line :0149]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_A65_CS_ATB                                               : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_A65_CS_APB                                               : 16;     /* [31:16]  */
        }Bit;
    }A65_CS_PUL_RST_WIDTH0;
    union { /* 0x3044 [Excel Line :0151]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_A65_CS_AXI                                               : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_A65_CS_TRACE                                             : 16;     /* [31:16]  */
        }Bit;
    }A65_CS_PUL_RST_WIDTH1;
    union { /* 0x3048 [Excel Line :0153]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_R5_CORE_WARM                                         : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_R5_CORE_COLD                                         : 16;     /* [31:16]  */
        }Bit;
    }CPU_R5_PUL_RST_WIDTH0;
    union { /* 0x304C [Excel Line :0155]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_R5_AXIM                                              : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_R5_AXIP                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU_R5_PUL_RST_WIDTH1;
    union { /* 0x3050 [Excel Line :0157]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_R5_AXIS0                                             : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_R5_APBDBG                                            : 16;     /* [31:16]  */
        }Bit;
    }CPU_R5_PUL_RST_WIDTH2;
    union { /* 0x3054 [Excel Line :0159]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_R5_CTI                                               : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_CPU_R5_ATB                                               : 16;     /* [31:16]  */
        }Bit;
    }CPU_R5_PUL_RST_WIDTH3;
    union { /* 0x3058 [Excel Line :0161]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_R5_CS_ATB                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_R5_CS_APBSYS                                             : 16;     /* [31:16]  */
        }Bit;
    }R5_CS_PUL_RST_WIDTH0;
    union { /* 0x305C [Excel Line :0163]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_R5_CS_CTM                                                : 16;     /* [ 15:0]  */
            UINT32 PUL_RST_WIDTH_R5_CS_TRACE                                              : 16;     /* [31:16]  */
        }Bit;
    }R5_CS_PUL_RST_WIDTH1;
    union { /* 0x3060 [Excel Line :0165]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_CPU_SCU_APB                                               : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_SCU_ONGO_RST_ACT;
    union { /* 0x3064 [Excel Line :0167]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_CPU_SCU_APB                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_SCU_PUL_RST_ACT;
    union { /* 0x3068 [Excel Line :0169]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_CPU_SCU_APB                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU_SCU_PUL_RST_WIDTH0;

    UINT8 EMPTY7[3988]; /* 0xF94 */

    union { /* 0x4000 [Excel Line :0171]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_CPU_A65_CORE_COLD                                             : 4;      /* [  3:0]  */
            UINT32 RST_READ_CPU_A65_CORE_WARM                                             : 4;      /* [  7:4]  */
            UINT32 RST_READ_CPU_A65_SCLK_COLD                                             : 1;      /* [    8]  */
            UINT32 RST_READ_CPU_A65_SCLK_WARM                                             : 1;      /* [    9]  */
            UINT32 RST_READ_CPU_A65_AXIM                                                  : 1;      /* [   10]  */
            UINT32 RST_READ_CPU_A65_AXIP                                                  : 1;      /* [   11]  */
            UINT32 RST_READ_CPU_A65_APB                                                   : 1;      /* [   12]  */
            UINT32 RST_READ_CPU_A65_ATB                                                   : 1;      /* [   13]  */
            UINT32 RST_READ_CPU_A65_GIC                                                   : 1;      /* [   14]  */
            UINT32 RST_READ_CPU_A65_PERI                                                  : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }RST_READ_CPU_A65;
    union { /* 0x4004 [Excel Line :0182]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_A65_CS_ATB                                                    : 1;      /* [    0]  */
            UINT32 RST_READ_A65_CS_APB                                                    : 1;      /* [    1]  */
            UINT32 RST_READ_A65_CS_AXI                                                    : 1;      /* [    2]  */
            UINT32 RST_READ_A65_CS_TRACE                                                  : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }RST_READ_A65_CS;
    union { /* 0x4008 [Excel Line :0187]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_CPU_R5_CORE_COLD                                              : 1;      /* [    0]  */
            UINT32 RST_READ_CPU_R5_CORE_WARM                                              : 1;      /* [    1]  */
            UINT32 RST_READ_CPU_R5_AXIM                                                   : 1;      /* [    2]  */
            UINT32 RST_READ_CPU_R5_AXIP                                                   : 1;      /* [    3]  */
            UINT32 RST_READ_CPU_R5_AXIS0                                                  : 1;      /* [    4]  */
            UINT32 RST_READ_CPU_R5_APBDBG                                                 : 1;      /* [    5]  */
            UINT32 RST_READ_CPU_R5_CTI                                                    : 1;      /* [    6]  */
            UINT32 RST_READ_CPU_R5_ATB                                                    : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }RST_READ_CPU_R5;
    union { /* 0x400C [Excel Line :0196]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_R5_CS_APBSYS                                                  : 1;      /* [    0]  */
            UINT32 RST_READ_R5_CS_CTM                                                     : 1;      /* [    1]  */
            UINT32 RST_READ_R5_CS_ATB                                                     : 1;      /* [    2]  */
            UINT32 RST_READ_R5_CS_TRACE                                                   : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }RST_READ_R5_CS;
    union { /* 0x4010 [Excel Line :0201]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_CPU_SCU_APB                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }RST_READ_CPU_SCU;

    UINT8 EMPTY8[4076]; /* 0xFEC */

    union { /* 0x5000 [Excel Line :0203]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CEMODE                                                         : 2;      /* [  1:0] 1 SPLIT  2 HYBRID  3 LOCKSTEP MODE */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_A65_CEMODE;
    union { /* 0x5004 [Excel Line :0205]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CFGEND                                                         : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CFGEND;
    union { /* 0x5008 [Excel Line :0207]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CLUSTERIDAFF2                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CLUSTERIDAFF2;
    union { /* 0x500C [Excel Line :0209]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CLUSTERIDAFF3                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CLUSTERIDAFF3;
    union { /* 0x5010 [Excel Line :0211]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR0_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE0_L;
    union { /* 0x5014 [Excel Line :0212]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR1_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE1_L;
    union { /* 0x5018 [Excel Line :0213]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR2_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE2_L;
    union { /* 0x501C [Excel Line :0214]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR3_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE3_L;
    union { /* 0x5020 [Excel Line :0215]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR4_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE4_L;
    union { /* 0x5024 [Excel Line :0216]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR5_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE5_L;
    union { /* 0x5028 [Excel Line :0217]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR6_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE6_L;
    union { /* 0x502C [Excel Line :0218]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR7_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_RVBAR_CORE7_L;
    union { /* 0x5030 [Excel Line :0219]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR0_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE0_H;
    union { /* 0x5034 [Excel Line :0221]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR1_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE1_H;
    union { /* 0x5038 [Excel Line :0223]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR2_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE2_H;
    union { /* 0x503C [Excel Line :0225]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR3_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE3_H;
    union { /* 0x5040 [Excel Line :0227]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR4_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE4_H;
    union { /* 0x5044 [Excel Line :0229]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR5_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE5_H;
    union { /* 0x5048 [Excel Line :0231]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR6_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE6_H;
    union { /* 0x504C [Excel Line :0233]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RVBARADDR7_H                                                   : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_A65_RVBAR_CORE7_H;
    union { /* 0x5050 [Excel Line :0235]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_GICCDISABLE                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_GICCDISABLE;
    union { /* 0x5054 [Excel Line :0237]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_RDSRCATTRM0                                                    : 12;     /* [ 11:0]  */
            UINT32 RESERVED2                                                              : 4;      /* [15:12]  */
            UINT32 CPU_A65_WRSRCATTRM0                                                    : 12;     /* [27:16]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }CPU_A65_SRCATTRM0;

    UINT8 EMPTY9[8]; /* 0x8 */

    union { /* 0x5060 [Excel Line :0241]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_ASTARTMP                                                       : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU_A65_MP_ADDR_START;
    union { /* 0x5064 [Excel Line :0243]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_AENDMP                                                         : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU_A65_MP_ADDR_END;

    UINT8 EMPTY10[152]; /* 0x98 */

    union { /* 0x5100 [Excel Line :0245]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SJTAG_EN                                                           : 1;      /* [    0]  */
            UINT32 RESERVED3                                                              : 3;      /* [  3:1]  */
            UINT32 CPU_JTAG_DBGEN                                                         : 1;      /* [    4]  */
            UINT32 CPU_JTAG_SPIDEN                                                        : 1;      /* [    5]  */
            UINT32 RESERVED2                                                              : 2;      /* [  7:6]  */
            UINT32 CPU_TRACE_SEL_A65                                                      : 1;      /* [    8]  */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }CPU_SJTAG_CONFIG;
    union { /* 0x5104 [Excel Line :0252]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_DBGRSTREQ                                                      : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_DBG_RSTREQ;
    union { /* 0x5108 [Excel Line :0254]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_DBGCONNECTED                                                   : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_DBG_CONNECTED;

    UINT8 EMPTY11[4]; /* 0x4 */

    union { /* 0x5110 [Excel Line :0256]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREINSTRRUN                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_COREINSTRRUN;
    union { /* 0x5114 [Excel Line :0258]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREINSTRRET                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_COREINSTRRET;
    union { /* 0x5118 [Excel Line :0260]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CIHSBYPASS                                                     : 4;      /* [  3:0]  */
            UINT32 CPU_A65_CISBYPASS                                                      : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }CPU_A65_CISBYPASS;

    UINT8 EMPTY12[4]; /* 0x4 */

    union { /* 0x5120 [Excel Line :0263]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREPACTIVE0                                                   : 18;     /* [ 17:0]  */
            UINT32 RESERVED1                                                              : 14;     /* [31:18]  */
        }Bit;
    }CPU_A65_COREPACTIVE0;
    union { /* 0x5124 [Excel Line :0265]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREPACTIVE1                                                   : 18;     /* [ 17:0]  */
            UINT32 RESERVED1                                                              : 14;     /* [31:18]  */
        }Bit;
    }CPU_A65_COREPACTIVE1;
    union { /* 0x5128 [Excel Line :0267]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREPACTIVE2                                                   : 18;     /* [ 17:0]  */
            UINT32 RESERVED1                                                              : 14;     /* [31:18]  */
        }Bit;
    }CPU_A65_COREPACTIVE2;
    union { /* 0x512C [Excel Line :0269]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREPACTIVE3                                                   : 18;     /* [ 17:0]  */
            UINT32 RESERVED1                                                              : 14;     /* [31:18]  */
        }Bit;
    }CPU_A65_COREPACTIVE3;
    union { /* 0x5130 [Excel Line :0271]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CLUSTERPACTIVE                                                 : 20;     /* [ 19:0]  */
            UINT32 RESERVED2                                                              : 4;      /* [23:20]  */
            UINT32 CPU_A65_CLUSTERP_IDLE                                                  : 1;      /* [   24]  */
            UINT32 RESERVED1                                                              : 7;      /* [31:25]  */
        }Bit;
    }CPU_A65_CLUSTERPCH;
    union { /* 0x5134 [Excel Line :0275]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CNTSTATUS                                                      : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_A65_CNTSTATUS;

    UINT8 EMPTY13[3784]; /* 0xEC8 */

    union { /* 0x6000 [Excel Line :0277]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_SET                                                       : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_REMAP_SET;
    union { /* 0x6004 [Excel Line :0279]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_NEW_ADDR0_L                                               : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_R5_REMAP_NEW_ADR0_L;
    union { /* 0x6008 [Excel Line :0280]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_NEW_ADDR0_H                                               : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }CPU_R5_REMAP_NEW_ADR0_H;
    union { /* 0x600C [Excel Line :0282]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_RNG_ADDR0                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_R5_REMAP_RNG_ADR0;
    union { /* 0x6010 [Excel Line :0283]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_NEW_ADDR1_L                                               : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_R5_REMAP_NEW_ADR1_L;
    union { /* 0x6014 [Excel Line :0284]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_NEW_ADDR1_H                                               : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }CPU_R5_REMAP_NEW_ADR1_H;
    union { /* 0x6018 [Excel Line :0286]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_REMAP_RNG_ADDR1                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_R5_REMAP_RNG_ADR1;

    UINT8 EMPTY14[4]; /* 0x4 */

    union { /* 0x6020 [Excel Line :0287]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_DBGACK0                                                         : 1;      /* [    0]  */
            UINT32 CPU_R5_DBGNOPWRDWN                                                     : 1;      /* [    1]  */
            UINT32 RESERVED3                                                              : 2;      /* [  3:2]  */
            UINT32 CPU_R5_DBGRSTREQ0                                                      : 1;      /* [    4]  */
            UINT32 RESERVED2                                                              : 3;      /* [  7:5]  */
            UINT32 CPU_R5_COMMRX0                                                         : 1;      /* [    8]  */
            UINT32 CPU_R5_COMMTX0                                                         : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }CPU_R5_DBG_STATUS;
    union { /* 0x6024 [Excel Line :0295]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_NWFIPIPESTOPPED0                                                : 1;      /* [    0]  */
            UINT32 CPU_R5_NWFEPIPESTOPPED0                                                : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_R5_CORE_STATUS;
    union { /* 0x6028 [Excel Line :0298]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_AXI_PP_BASE                                                     : 20;     /* [ 19:0]  */
            UINT32 RESERVED2                                                              : 4;      /* [23:20]  */
            UINT32 CPU_R5_AXI_PP_SIZE                                                     : 5;      /* [28:24]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }CPU_R5_AXI_PP_ADDR;
    union { /* 0x602C [Excel Line :0302]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_AXI_VP_BASE                                                     : 20;     /* [ 19:0]  */
            UINT32 RESERVED2                                                              : 4;      /* [23:20]  */
            UINT32 CPU_R5_AXI_VP_SIZE                                                     : 5;      /* [28:24]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }CPU_R5_AXI_VP_ADDR;
    union { /* 0x6030 [Excel Line :0306]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_CFGNMFI0                                                        : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_INTR_CONFIG;
    union { /* 0x6034 [Excel Line :0308]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_TCM_RMW_EN                                                      : 2;      /* [  1:0]  */
            UINT32 RESERVED3                                                              : 2;      /* [  3:2]  */
            UINT32 CPU_R5_TCM_EXT_ERR_EN                                                  : 3;      /* [  6:4]  */
            UINT32 RESERVED2                                                              : 1;      /* [    7]  */
            UINT32 CPU_R5_TCM_INT_ERR_EN                                                  : 3;      /* [ 10:8]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }CPU_R5_TCM_CONFIG;
    union { /* 0x6038 [Excel Line :0314]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_JTAGNSW                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_JTAGNSW;

    UINT8 EMPTY15[4]; /* 0x4 */

    union { /* 0x6040 [Excel Line :0316]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_DBGROMADDR                                                      : 20;     /* [ 19:0]  */
            UINT32 RESERVED1                                                              : 12;     /* [31:20]  */
        }Bit;
    }CPU_R5_CS_CONFIG0;
    union { /* 0x6044 [Excel Line :0318]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_DBGSELFADDR                                                     : 20;     /* [ 19:0]  */
            UINT32 RESERVED1                                                              : 12;     /* [31:20]  */
        }Bit;
    }CPU_R5_CS_CONFIG1;
    union { /* 0x6048 [Excel Line :0320]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_DBGROMADDRV                                                     : 1;      /* [    0]  */
            UINT32 CPU_R5_DBGSELFADDRV                                                    : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_R5_CS_CONFIG2;

    UINT8 EMPTY16[4]; /* 0x4 */

    union { /* 0x6050 [Excel Line :0323]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_CS_CDBGRSTREQ                                                   : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 CPU_R5_CS_CDBGRSTACK                                                   : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }CPU_R5_CS_DBGRST_STATUS;

    UINT8 EMPTY17[44]; /* 0x2C */

    union { /* 0x6080 [Excel Line :0327]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTI0                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_POWER_CONFIG;
    union { /* 0x6084 [Excel Line :0329]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTO0                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_POWER_STATUS;
    union { /* 0x6088 [Excel Line :0331]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_GROUPID                                                         : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }CPU_R5_GENERAL_CONFIG0;
    union { /* 0x608C [Excel Line :0333]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_TEINIT                                                          : 1;      /* [    0]  */
            UINT32 CPU_R5_CFGIE                                                           : 1;      /* [    1]  */
            UINT32 CPU_R5_CFGEE                                                           : 1;      /* [    2]  */
            UINT32 CPU_R5_VINITHI0                                                        : 1;      /* [    3]  */
            UINT32 CPU_R5_PARITYLEVEL                                                     : 1;      /* [    4]  */
            UINT32 CPU_R5_LOCZRAMA0                                                       : 1;      /* [    5]  */
            UINT32 CPU_R5_INITRAMB0                                                       : 1;      /* [    6]  */
            UINT32 CPU_R5_INITRAMA0                                                       : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_R5_GENERAL_CONFIG1;

    UINT8 EMPTY18[112]; /* 0x70 */

    union { /* 0x6100 [Excel Line :0342]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_APBAP_DEVICEEN                                              : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CS_APBAP_DEVEN;
    union { /* 0x6104 [Excel Line :0344]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_TPIU_TPCTL                                                  : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 CPU_A65_CS_TPIU_TPMAXDATASIZE                                          : 5;      /* [  8:4]  */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }CPU_A65_CS_TPIU_CTRL;
    union { /* 0x6108 [Excel Line :0348]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CTI_TISBYPASSIN                                             : 8;      /* [  7:0]  */
            UINT32 CPU_A65_CS_CTI_TISBYPASSACK                                            : 8;      /* [ 15:8]  */
            UINT32 CPU_A65_CS_CTI_TIHSBYPASS                                              : 8;      /* [23:16]  */
            UINT32 CPU_A65_CS_CTI_CTIAPBSBYPASS                                           : 1;      /* [   24]  */
            UINT32 CPU_A65_CS_CTI_CISBYPASS                                               : 1;      /* [   25]  */
            UINT32 RESERVED1                                                              : 2;      /* [27:26]  */
            UINT32 CPU_A65_CS_CTI_CIHSBYPASS                                              : 4;      /* [31:28]  */
        }Bit;
    }CPU_A65_CS_CTI_BYPASS;
    union { /* 0x610C [Excel Line :0355]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CTI_TODBGENSEL                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED2                                                              : 8;      /* [ 15:8]  */
            UINT32 CPU_A65_CS_CTI_TINIDENSEL                                              : 8;      /* [23:16]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU_A65_CS_CTI_ENSEL;
    union { /* 0x6110 [Excel Line :0359]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_TARGETID                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_CS_TARGETID;
    union { /* 0x6114 [Excel Line :0360]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_SWJDP_INSTANCEID                                            : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }CPU_A65_CS_SWJDP_INSTID;
    union { /* 0x6118 [Excel Line :0362]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_IC_ROMBASEADDR                                              : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_CS_IC_ROMBASEADDR;
    union { /* 0x611C [Excel Line :0363]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_IC_ROMBASEADDRU                                             : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_CS_IC_ROMBASEADDRU;
    union { /* 0x6120 [Excel Line :0364]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_IC_ROMBASEADDRL                                             : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_A65_CS_IC_ROMBASEADDRL;
    union { /* 0x6124 [Excel Line :0365]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_SWJDP_JTAGNSW                                               : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CS_SWJDP_JTAGNSW;
    union { /* 0x6128 [Excel Line :0367]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_SWJDP_JTAGTOP                                               : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CS_SWJDP_JTAGTOP;
    union { /* 0x612C [Excel Line :0369]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CTI_ASICCTL                                                 : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CS_CTI_ASICCTL;
    union { /* 0x6130 [Excel Line :0371]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CTI_CTITRIGINACK                                            : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_CS_CTI_CTITRIGINACK;

    UINT8 EMPTY19[12]; /* 0xC */

    union { /* 0x6140 [Excel Line :0373]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CDBGRSTREQ                                                  : 1;      /* [    0]  */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 CPU_A65_CS_CDBGRSTACK                                                  : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }CPU_A65_CS_DBGRST_STATUS;
    union { /* 0x6144 [Excel Line :0377]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CS_CDBGRST_SEL                                                 : 5;      /* [  4:0]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }CPU_A65_CS_DBGRST_SEL;

    UINT8 EMPTY20[36536]; /* 0x8EB8 */

    union { /* 0xF000 [Excel Line :0379]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG0                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG0;
    union { /* 0xF004 [Excel Line :0380]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG1                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG1;
    union { /* 0xF008 [Excel Line :0381]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG2                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG2;
    union { /* 0xF00C [Excel Line :0382]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG3                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG3;
    union { /* 0xF010 [Excel Line :0383]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG4                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG4;
    union { /* 0xF014 [Excel Line :0384]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG5                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG5;
    union { /* 0xF018 [Excel Line :0385]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG6                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG6;
    union { /* 0xF01C [Excel Line :0386]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG7                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG7;
    union { /* 0xF020 [Excel Line :0387]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG8                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG8;
    union { /* 0xF024 [Excel Line :0388]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG9                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG9;
    union { /* 0xF028 [Excel Line :0389]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG10                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG10;
    union { /* 0xF02C [Excel Line :0390]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG11                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG11;
    union { /* 0xF030 [Excel Line :0391]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG12                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG12;
    union { /* 0xF034 [Excel Line :0392]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG13                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG13;
    union { /* 0xF038 [Excel Line :0393]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG14                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG14;
    union { /* 0xF03C [Excel Line :0394]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG15                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG15;
    union { /* 0xF040 [Excel Line :0395]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG16                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG16;
    union { /* 0xF044 [Excel Line :0396]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG17                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG17;
    union { /* 0xF048 [Excel Line :0397]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG18                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG18;
    union { /* 0xF04C [Excel Line :0398]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCU_DEBUG19                                                        : 32;     /* [ 31:0]  */
        }Bit;
    }CPU_SCU_DEBUG19;

    UINT8 EMPTY21[432]; /* 0x1B0 */

    union { /* 0xF200 [Excel Line :0399]  */
        UINT32 Reg;
        struct {
            UINT32 BL_CTRL0                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_CTRL0;
    union { /* 0xF204 [Excel Line :0400]  */
        UINT32 Reg;
        struct {
            UINT32 BL_CTRL1                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_CTRL1;
    union { /* 0xF208 [Excel Line :0401]  */
        UINT32 Reg;
        struct {
            UINT32 BL_CTRL2                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_CTRL2;
    union { /* 0xF20C [Excel Line :0402]  */
        UINT32 Reg;
        struct {
            UINT32 BL_CTRL3                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_CTRL3;
    union { /* 0xF210 [Excel Line :0403]  */
        UINT32 Reg;
        struct {
            UINT32 BL_MODE0                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_MODE0;
    union { /* 0xF214 [Excel Line :0404]  */
        UINT32 Reg;
        struct {
            UINT32 BL_MODE1                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_MODE1;
    union { /* 0xF218 [Excel Line :0405]  */
        UINT32 Reg;
        struct {
            UINT32 BL_MODE2                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_MODE2;
    union { /* 0xF21C [Excel Line :0406]  */
        UINT32 Reg;
        struct {
            UINT32 BL_MODE3                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BL_MODE3;
}DRV_A6_CPU_SCU_REGISTER;
/* PRQA S 0779 -- */

/*
 static volatile DRV_A6_CPU_SCU_REGISTER* const RegA6_CPU_SCU = (DRV_A6_CPU_SCU_REGISTER*)APACHE_A6_CPU_SCU_BASE_ADDR;
 */



#endif /* end of DRV_REGISTER_A6_CPU_SCU__ */

