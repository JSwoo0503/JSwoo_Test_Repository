
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_SE_Register.h
*   Date       : 2022-06-20 15:08
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_SE_H__
#define DRV_REGISTER_A6_SE_H__

#define APACHE_A6_SE_BASE_ADDR        0x05060000U

/* PRQA S 0791 ++ */
/* PRQA S 0779 ++ */
typedef struct
{

    UINT8 EMPTY1[256]; /*  0x100 */

    union { /* 0x0100 [Excel Line :0006]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_APB                                                       : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SECLK__FT__MASK;
    union { /* 0x0104 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__FT__IRQ                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SECLK__FT__IRQ;
    union { /* 0x0108 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__FT__CLR                                                         : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SECLK__FT__CLR;
    union { /* 0x010C [Excel Line :0012]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__FT__STAT                                                        : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SECLK__FT__STAT;

    UINT8 EMPTY2[240]; /* 0xF0 */

    /* GROUP Start : SECLK__CLKMONI__CTRL */
    /* struct {  0x0200 [Excel Line :0014]  */
    union { /* 0x0200 [Excel Line :0014]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }SECLK__CLKMONI__CTRL;
    union { /* 0x0204 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__CLKMONI__CAP_CNT_MIN                                            : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SECLK__CLKMONI__CAP_CNT_MIN;
    union { /* 0x0208 [Excel Line :0022]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__CLKMONI__CAP_CNT_MAX                                            : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SECLK__CLKMONI__CAP_CNT_MAX;
    union { /* 0x020C [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 SECLK__CLKMONI__CAP_CNT_VAL                                            : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }SECLK__CLKMONI__CAP_CNT_VAL;
    /* }SECLK__CLKMONI__CTRL__GROUP; */

    UINT8 EMPTY3[3568]; /* 0xDF */

    union { /* 0x1000 [Excel Line :0024]  */
        UINT32 Reg;
        struct {
            UINT32 USR0_ERR                                                               : 1;      /* [    0] user custom SM1 err */
            UINT32 USR1_ERR                                                               : 1;      /* [    1] user custom SM1 err */
            UINT32 USR0_ITS_ERR                                                           : 1;      /* [    2] user custom SM0 its err */
            UINT32 USR1_ITS_ERR                                                           : 1;      /* [    3] user custom SM1 its err */
            UINT32 USR0_PPI_ERR                                                           : 1;      /* [    4] user custom SM0 ppi err */
            UINT32 USR1_PPI_ERR                                                           : 1;      /* [    5] user custom SM1 ppi err */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }GIC__A65_USR_ERR;
    union { /* 0x1004 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__DEBUG1                                                            : 32;     /* [ 31:0] Debug Register 1 */
        }Bit;
    }GIC__DEBUG1;
    union { /* 0x1008 [Excel Line :0032]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__DEBUG2                                                            : 32;     /* [ 31:0] Debug Register 2 */
        }Bit;
    }GIC__DEBUG2;
    union { /* 0x100C [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__DEBUG3                                                            : 32;     /* [ 31:0] Debug Register 3 */
        }Bit;
    }GIC__DEBUG3;

    UINT8 EMPTY4[240]; /* 0xF0 */

    union { /* 0x1100 [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_GIC_R5_AXI                                                : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_GIC_A65                                                   : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_GIC_A65_FDC                                               : 1;      /* [    2]  */
            UINT32 GIC_A65_FAULT_INT                                                      : 1;      /* [    3]  */
            UINT32 GIC_A65_ERR_INT                                                        : 1;      /* [    4]  */
            UINT32 GIC_A65_PMU_INT                                                        : 1;      /* [    5]  */
            UINT32 GIC_A65_FMU_FAULT_INT                                                  : 1;      /* [    6]  */
            UINT32 GIC_A65_FMU_ERR_INT                                                    : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GIC__FT__MASK;
    union { /* 0x1104 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__FT__IRQ                                                           : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GIC__FT__IRQ;
    union { /* 0x1108 [Excel Line :0045]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__FT__CLR                                                           : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GIC__FT__CLR;
    union { /* 0x110C [Excel Line :0047]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__FT__STAT                                                          : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GIC__FT__STAT;

    UINT8 EMPTY5[240]; /* 0xF0 */

    /* GROUP Start : SE_GIC__CLKMONI__CTRL */
    struct { /* 0x1200 [Excel Line :0049]  */
        union { /* 0x1200 [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }GIC__CLKMONI__CTRL;
    union { /* 0x1204 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }GIC__CLKMONI__CAP_CNT_MIN;
    union { /* 0x1208 [Excel Line :0057]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }GIC__CLKMONI__CAP_CNT_MAX;
    union { /* 0x120C [Excel Line :0058]  */
        UINT32 Reg;
        struct {
            UINT32 GIC__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }GIC__CLKMONI__CAP_CNT_VAL;
    }SE_GIC__CLKMONI__CTRL__GROUP[3];

    UINT8 EMPTY6[3536]; /* 0xDD0 */

    union { /* 0x2000 [Excel Line :0079]  */
        UINT32 Reg;
        struct {
            UINT32 RT640_RAM0_EN                                                          : 1;      /* [    0] RT640 RAM0 ECC check enable */
            UINT32 RT640_RAM1_EN                                                          : 1;      /* [    1] RT640 RAM1 ECC check enable */
            UINT32 RT640_RAM2_EN                                                          : 1;      /* [    2] RT640 RAM2 ECC check enable */
            UINT32 RT640_RAM3_EN                                                          : 1;      /* [    3] RT640 RAM3 ECC check enable */
            UINT32 EIP97_DESC_EN                                                          : 1;      /* [    4] EIP97 descriptor ram ECC check enable */
            UINT32 EIP97_IPKT_EN                                                          : 1;      /* [    5] EIP97 in packet ram ECC check enable */
            UINT32 EIP97_ITOK_EN                                                          : 1;      /* [    6] EIP97 in token ram ECC check enable */
            UINT32 EIP97_OPKT_EN                                                          : 1;      /* [    7] EIP97 out packet ram ECC check enable */
            UINT32 EIP97_OTOK_EN                                                          : 1;      /* [    8] EIP97 out token ram ECC check enable */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }SECURE__ECC_EN;

    UINT8 EMPTY7[12]; /* 0xC */

    union { /* 0x2010 [Excel Line :0089]  */
        UINT32 Reg;
        struct {
            UINT32 RAM0_BYTE0                                                             : 2;      /* [  1:0] RAM0 Byte0 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE1                                                             : 2;      /* [  3:2] RAM0 Byte1 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE2                                                             : 2;      /* [  5:4] RAM0 Byte2 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE3                                                             : 2;      /* [  7:6] RAM0 Byte3 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE4                                                             : 2;      /* [  9:8] RAM0 Byte4 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE5                                                             : 2;      /* [11:10] RAM0 Byte5 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE6                                                             : 2;      /* [13:12] RAM0 Byte6 ECC sec warning0 ded error1 */
            UINT32 RAM0_BYTE7                                                             : 2;      /* [15:14] RAM0 Byte7 ECC sec warning0 ded error1 */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SECURE__RT640_RAM0_STAT;
    union { /* 0x2014 [Excel Line :0098]  */
        UINT32 Reg;
        struct {
            UINT32 RAM1_BYTE0                                                             : 2;      /* [  1:0] RAM1 Byte0 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE1                                                             : 2;      /* [  3:2] RAM1 Byte1 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE2                                                             : 2;      /* [  5:4] RAM1 Byte2 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE3                                                             : 2;      /* [  7:6] RAM1 Byte3 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE4                                                             : 2;      /* [  9:8] RAM1 Byte4 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE5                                                             : 2;      /* [11:10] RAM1 Byte5 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE6                                                             : 2;      /* [13:12] RAM1 Byte6 ECC sec warning0 ded error1 */
            UINT32 RAM1_BYTE7                                                             : 2;      /* [15:14] RAM1 Byte7 ECC sec warning0 ded error1 */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SECURE__RT640_RAM1_STAT;
    union { /* 0x2018 [Excel Line :0107]  */
        UINT32 Reg;
        struct {
            UINT32 RAM2_BYTE0                                                             : 2;      /* [  1:0] RAM2 Byte0 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE1                                                             : 2;      /* [  3:2] RAM2 Byte1 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE2                                                             : 2;      /* [  5:4] RAM2 Byte2 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE3                                                             : 2;      /* [  7:6] RAM2 Byte3 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE4                                                             : 2;      /* [  9:8] RAM2 Byte4 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE5                                                             : 2;      /* [11:10] RAM2 Byte5 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE6                                                             : 2;      /* [13:12] RAM2 Byte6 ECC sec warning0 ded error1 */
            UINT32 RAM2_BYTE7                                                             : 2;      /* [15:14] RAM2 Byte7 ECC sec warning0 ded error1 */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SECURE__RT640_RAM2_STAT;
    union { /* 0x201C [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 RAM3_BYTE0                                                             : 2;      /* [  1:0] RAM3 Byte0 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE1                                                             : 2;      /* [  3:2] RAM3 Byte1 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE2                                                             : 2;      /* [  5:4] RAM3 Byte2 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE3                                                             : 2;      /* [  7:6] RAM3 Byte3 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE4                                                             : 2;      /* [  9:8] RAM3 Byte4 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE5                                                             : 2;      /* [11:10] RAM3 Byte5 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE6                                                             : 2;      /* [13:12] RAM3 Byte6 ECC sec warning0 ded error1 */
            UINT32 RAM3_BYTE7                                                             : 2;      /* [15:14] RAM3 Byte7 ECC sec warning0 ded error1 */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SECURE__RT640_RAM3_STAT;

    UINT8 EMPTY8[224]; /* 0xE0 */

    union { /* 0x2100 [Excel Line :0125]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_RT640                                                     : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_EIP97                                                     : 1;      /* [    1]  */
            UINT32 RT640_RAM0_SEC_WARN                                                    : 1;      /* [    2]  */
            UINT32 RT640_RAM0_DED_ERROR                                                   : 1;      /* [    3]  */
            UINT32 RT640_RAM1_SEC_WARN                                                    : 1;      /* [    4]  */
            UINT32 RT640_RAM1_DED_ERROR                                                   : 1;      /* [    5]  */
            UINT32 RT640_RAM2_SEC_WARN                                                    : 1;      /* [    6]  */
            UINT32 RT640_RAM2_DED_ERROR                                                   : 1;      /* [    7]  */
            UINT32 RT640_RAM3_SEC_WARN                                                    : 1;      /* [    8]  */
            UINT32 RT640_RAM3_DED_ERROR                                                   : 1;      /* [    9]  */
            UINT32 EIP97_DESC_SEC_WARN                                                    : 1;      /* [   10]  */
            UINT32 EIP97_DESC_DED_ERROR                                                   : 1;      /* [   11]  */
            UINT32 EIP97_IPKT_SEC_WARN                                                    : 1;      /* [   12]  */
            UINT32 EIP97_IPKT_DED_ERROR                                                   : 1;      /* [   13]  */
            UINT32 EIP97_ITOK_SEC_WARN                                                    : 1;      /* [   14]  */
            UINT32 EIP97_ITOK_DED_ERROR                                                   : 1;      /* [   15]  */
            UINT32 EIP97_OPKT_SEC_WARN                                                    : 1;      /* [   16]  */
            UINT32 EIP97_OPKT_DED_ERROR                                                   : 1;      /* [   17]  */
            UINT32 EIP97_OTOK_SEC_WARN                                                    : 1;      /* [   18]  */
            UINT32 EIP97_OTOK_DED_ERROR                                                   : 1;      /* [   19]  */
            UINT32 RT640_SAFETY_ALARM0                                                    : 1;      /* [   20]  */
            UINT32 RT640_SAFETY_ALARM1                                                    : 1;      /* [   21]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }SECURE__FT__MASK;
    union { /* 0x2104 [Excel Line :0148]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__FT__IRQ                                                        : 22;     /* [ 21:0]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }SECURE__FT__IRQ;
    union { /* 0x2108 [Excel Line :0150]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__FT__CLR                                                        : 22;     /* [ 21:0]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }SECURE__FT__CLR;
    union { /* 0x210C [Excel Line :0152]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__FT__STAT                                                       : 22;     /* [ 21:0]  */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }SECURE__FT__STAT;

    UINT8 EMPTY9[240]; /* 0xF0 */

    /* GROUP Start : SECURE__CLKMONI__CTRL */
    struct { /* 0x2200 [Excel Line :0154]  */
        union { /* 0x2200 [Excel Line :0154]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }SECURE__CLKMONI__CTRL;
    union { /* 0x2204 [Excel Line :0161]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__CLKMONI__CAP_CNT_MIN                                           : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SECURE__CLKMONI__CAP_CNT_MIN;
    union { /* 0x2208 [Excel Line :0162]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__CLKMONI__CAP_CNT_MAX                                           : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SECURE__CLKMONI__CAP_CNT_MAX;
    union { /* 0x220C [Excel Line :0163]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE__CLKMONI__CAP_CNT_VAL                                           : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }SECURE__CLKMONI__CAP_CNT_VAL;
    }SECURE__CLKMONI__CTRL__GROUP[2];

    UINT8 EMPTY10[224]; /* 0xE0 */

    union { /* 0x2300 [Excel Line :0174]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__RT640_RAM0_INJECT;

    UINT8 EMPTY11[12]; /* 0xC */

    union { /* 0x2310 [Excel Line :0182]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__RT640_RAM1_INJECT;

    UINT8 EMPTY12[12]; /* 0xC */

    union { /* 0x2320 [Excel Line :0190]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__RT640_RAM2_INJECT;

    UINT8 EMPTY13[12]; /* 0xC */

    union { /* 0x2330 [Excel Line :0198]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__RT640_RAM3_INJECT;

    UINT8 EMPTY14[12]; /* 0xC */

    union { /* 0x2340 [Excel Line :0206]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__EIP97_DESC_INJECT;

    UINT8 EMPTY15[12]; /* 0xC */

    union { /* 0x2350 [Excel Line :0214]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__EIP97_IPKT_INJECT;

    UINT8 EMPTY16[12]; /* 0xC */

    union { /* 0x2360 [Excel Line :0222]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__EIP97_ITOK_INJECT;

    UINT8 EMPTY17[12]; /* 0xC */

    union { /* 0x2370 [Excel Line :0230]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__EIP97_OPKT_INJECT;

    UINT8 EMPTY18[12]; /* 0xC */

    union { /* 0x2380 [Excel Line :0238]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SECURE__EIP97_OTOK_INJECT;

    UINT8 EMPTY19[3196]; /* 0xC7C */

    union { /* 0x3000 [Excel Line :0246]  */
        UINT32 Reg;
        struct {
            UINT32 SDC                                                                    : 1;      /* [    0] ECC Check enabled for SRAMs */
            UINT32 EMMC                                                                   : 1;      /* [    1] ECC Check enabled for SRAMs */
            UINT32 ETHERNET                                                               : 1;      /* [    2] ECC Check enabled for SRAMs */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }HSP__ECC_EN;
    union { /* 0x3004 [Excel Line :0250]  */
        UINT32 Reg;
        struct {
            UINT32 SDC                                                                    : 1;      /* [    0]  */
            UINT32 EMMC                                                                   : 1;      /* [    1]  */
            UINT32 ETH_DCI                                                                : 1;      /* [    2]  */
            UINT32 ETH_TSO                                                                : 1;      /* [    3]  */
            UINT32 ETH_EST                                                                : 1;      /* [    4]  */
            UINT32 ETH_TX_ODD                                                             : 1;      /* [    5]  */
            UINT32 ETH_TX_EVEN                                                            : 1;      /* [    6]  */
            UINT32 ETH_RX_ODD                                                             : 1;      /* [    7]  */
            UINT32 ETH_RX_EVEN                                                            : 1;      /* [    8]  */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }HSP__ECC_WARNING;

    UINT8 EMPTY20[248]; /* 0xF8 */

    union { /* 0x3100 [Excel Line :0260]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_EMMC_CORE                                                 : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_EMMC_CARD                                                 : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_SDC_CORE                                                  : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_SDC_CARD                                                  : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_EQOS_RGMII                                                : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_EQOS_RMII                                                 : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_EQOS_PTP                                                  : 1;      /* [    6]  */
            UINT32 EMMC_ECC                                                               : 1;      /* [    7]  */
            UINT32 SDC_ECC                                                                : 1;      /* [    8]  */
            UINT32 ETH_DCI_ECC                                                            : 1;      /* [    9]  */
            UINT32 ETH_TSO_ECC                                                            : 1;      /* [   10]  */
            UINT32 ETH_EST_ECC                                                            : 1;      /* [   11]  */
            UINT32 ETH_TX_ODD_ECC                                                         : 1;      /* [   12]  */
            UINT32 ETH_TX_EVEN_ECC                                                        : 1;      /* [   13]  */
            UINT32 ETH_RX_ODD_ECC                                                         : 1;      /* [   14]  */
            UINT32 ETH_RX_EVEN_ECC                                                        : 1;      /* [   15]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }HSP__FT__MASK;
    union { /* 0x3104 [Excel Line :0277]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__FT__IRQ                                                           : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }HSP__FT__IRQ;
    union { /* 0x3108 [Excel Line :0279]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__FT__CLR                                                           : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }HSP__FT__CLR;
    union { /* 0x310C [Excel Line :0281]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__FT__STAT                                                          : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }HSP__FT__STAT;

    UINT8 EMPTY21[240]; /* 0xF0 */

    /* GROUP Start : SE_HSP__CLKMONI__CTRL */
    struct { /* 0x3200 [Excel Line :0283]  */
        union { /* 0x3200 [Excel Line :0283]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }HSP__CLKMONI__CTRL;
    union { /* 0x3204 [Excel Line :0290]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }HSP__CLKMONI__CAP_CNT_MIN;
    union { /* 0x3208 [Excel Line :0291]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }HSP__CLKMONI__CAP_CNT_MAX;
    union { /* 0x320C [Excel Line :0292]  */
        UINT32 Reg;
        struct {
            UINT32 HSP__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }HSP__CLKMONI__CAP_CNT_VAL;
    }SE_HSP__CLKMONI__CTRL__GROUP[7];

    UINT8 EMPTY22[144]; /* 0x90 */

    union { /* 0x3300 [Excel Line :0353]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_EMMC_RAM;

    UINT8 EMPTY23[12]; /* 0xC */

    union { /* 0x3310 [Excel Line :0361]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_SDC_RAM;

    UINT8 EMPTY24[12]; /* 0xC */

    union { /* 0x3320 [Excel Line :0369]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_DCI_RAM;

    UINT8 EMPTY25[12]; /* 0xC */

    union { /* 0x3330 [Excel Line :0377]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_TSO_RAM;

    UINT8 EMPTY26[12]; /* 0xC */

    union { /* 0x3340 [Excel Line :0385]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_EST_RAM;

    UINT8 EMPTY27[12]; /* 0xC */

    union { /* 0x3350 [Excel Line :0393]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_TX_ODD_RAM;

    UINT8 EMPTY28[12]; /* 0xC */

    union { /* 0x3360 [Excel Line :0401]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_TX_EVEN_RAM;

    UINT8 EMPTY29[12]; /* 0xC */

    union { /* 0x3370 [Excel Line :0409]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_RX_ODD_RAM;

    UINT8 EMPTY30[12]; /* 0xC */

    union { /* 0x3380 [Excel Line :0417]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HSP__ECC_ETH_RX_EVEN_RAM;

    UINT8 EMPTY31[3196]; /* 0xC7C */

    /* GROUP Start : SE_PERI__ECC_CTRL */
    struct { /* 0x4000 [Excel Line :0425]  */
        union { /* 0x4000 [Excel Line :0425]  */
        UINT32 Reg;
        struct {
            UINT32 EN                                                                     : 1;      /* [    0] enable fault injection for PERI CAN 0 */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PERI__ECC_CTRL;
    union { /* 0x4004 [Excel Line :0427]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__ECC_INJECT_0                                                     : 32;     /* [ 31:0]  */
        }Bit;
    }PERI__ECC_INJECT_0;
    union { /* 0x4008 [Excel Line :0428]  */
        UINT32 Reg;
        struct {
            UINT32 SYNDROME                                                               : 7;      /* [  6:0]  */
            UINT32 RESERVED1                                                              : 25;     /* [ 31:7]  */
        }Bit;
    }PERI__ECC_INJECT_1;
    union { /* 0x400C [Excel Line :0430]  */
        UINT32 Reg;
        struct {
            UINT32 STATUS                                                                 : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PERI__ECC_INJECT_WARM;
    }SE_PERI__ECC_CTRL__GROUP[2];

    union { /* 0x4020 [Excel Line :0439]  */
        UINT32 Reg;
        struct {
            UINT32 RAM0_ECC_EN                                                            : 1;      /* [    0] ECC enable for PERI DMA330 0 and 1 */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }PERI__DMA330__ECC_CTRL;

    UINT8 EMPTY32[220]; /* 0xDC */

    /* GROUP Start : SE_PERI__FT__MASK */
    struct { /* 0x4100 [Excel Line :0441]  */
        union { /* 0x4100 [Excel Line :0441]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_SPI_CORE                                                  : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_I2C_CORE                                                  : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_UART_CORE                                                 : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_PWM_CORE                                                  : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_LIN_CORE                                                  : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_CAN_CORE                                                  : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_DMA_AXI                                                   : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_PWM_APB                                                   : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_QSPI_CORE                                                 : 1;      /* [    8]  */
            UINT32 CAN0_ECC_WARN                                                          : 1;      /* [    9]  */
            UINT32 CAN0_ECC_ERR                                                           : 1;      /* [   10]  */
            UINT32 CAN1_ECC_WARN                                                          : 1;      /* [   11]  */
            UINT32 CAN1_ECC_ERR                                                           : 1;      /* [   12]  */
            UINT32 TIMER0_ERR0                                                            : 1;      /* [   13]  */
            UINT32 TIMER0_ERR1                                                            : 1;      /* [   14]  */
            UINT32 TIMER0_ERR2                                                            : 1;      /* [   15]  */
            UINT32 TIMER0_ERR3                                                            : 1;      /* [   16]  */
            UINT32 TIMER1_ERR0                                                            : 1;      /* [   17]  */
            UINT32 TIMER1_ERR1                                                            : 1;      /* [   18]  */
            UINT32 TIMER1_ERR2                                                            : 1;      /* [   19]  */
            UINT32 TIMER1_ERR3                                                            : 1;      /* [   20]  */
            UINT32 TIMER2_ERR0                                                            : 1;      /* [   21]  */
            UINT32 TIMER2_ERR1                                                            : 1;      /* [   22]  */
            UINT32 TIMER2_ERR2                                                            : 1;      /* [   23]  */
            UINT32 TIMER2_ERR3                                                            : 1;      /* [   24]  */
            UINT32 DMA0_ECC_WARN                                                          : 1;      /* [   25]  */
            UINT32 DMA0_ECC_ERR                                                           : 1;      /* [   26]  */
            UINT32 DMA1_ECC_WARN                                                          : 1;      /* [   27]  */
            UINT32 DMA1_ECC_ERR                                                           : 1;      /* [   28]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PERI__FT__MASK;
    union { /* 0x4104 [Excel Line :0471]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__FT__IRQ                                                          : 29;     /* [ 28:0]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PERI__FT__IRQ;
    union { /* 0x4108 [Excel Line :0473]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__FT__CLR                                                          : 29;     /* [ 28:0]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PERI__FT__CLR;
    union { /* 0x410C [Excel Line :0475]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__FT__STAT                                                         : 29;     /* [ 28:0]  */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }PERI__FT__STAT;
    }SE_PERI__FT__MASK;

    UINT8 EMPTY33[240]; /* 0xF0 */

    /* GROUP Start : SE_PERI__CLKMONI__CTRL */
    struct { /* 0x4200 [Excel Line :0477]  */
        union { /* 0x4200 [Excel Line :0477]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }PERI__CLKMONI__CTRL;
    union { /* 0x4204 [Excel Line :0484]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__CLKMONI__CAP_CNT_MIN                                             : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }PERI__CLKMONI__CAP_CNT_MIN;
    union { /* 0x4208 [Excel Line :0485]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__CLKMONI__CAP_CNT_MAX                                             : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }PERI__CLKMONI__CAP_CNT_MAX;
    union { /* 0x420C [Excel Line :0486]  */
        UINT32 Reg;
        struct {
            UINT32 PERI__CLKMONI__CAP_CNT_VAL                                             : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }PERI__CLKMONI__CAP_CNT_VAL;
    }SE_PERI__CLKMONI__CTRL__GROUP[9];

    UINT8 EMPTY34[112]; /* 0x70 */

    union { /* 0x4300 [Excel Line :0567]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] DMA330 RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2Double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PERI__DAM330__ECC_RAM0;

    UINT8 EMPTY35[12]; /* 0xC */

    union { /* 0x4310 [Excel Line :0575]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] DMA330 RAM1 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2Double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PERI__DMA330__ECC_RAM1;

    UINT8 EMPTY36[3308]; /* 0xCEC */

    union { /* 0x5000 [Excel Line :0583]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__DEBUG0                                                         : 32;     /* [ 31:0] Debug Register 0 */
        }Bit;
    }ANALOG__DEBUG0;
    union { /* 0x5004 [Excel Line :0584]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__DEBUG1                                                         : 32;     /* [ 31:0] Debug Register 1 */
        }Bit;
    }ANALOG__DEBUG1;
    union { /* 0x5008 [Excel Line :0585]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__DEBUG2                                                         : 32;     /* [ 31:0] Debug Register 2 */
        }Bit;
    }ANALOG__DEBUG2;
    union { /* 0x500C [Excel Line :0586]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__DEBUG3                                                         : 32;     /* [ 31:0] Debug Register 3 */
        }Bit;
    }ANALOG__DEBUG3;

    UINT8 EMPTY37[240]; /* 0xF0 */

    union { /* 0x5100 [Excel Line :0587]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_OTP_SEC                                                   : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_ANALOG_APB                                                : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_ADC_CORE                                                  : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_PVT_CORE                                                  : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_VLD_CORE                                                  : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_OTP_CORE                                                  : 1;      /* [    5]  */
            UINT32 DVLD_UP                                                                : 1;      /* [    6]  */
            UINT32 DVLD_DN                                                                : 1;      /* [    7]  */
            UINT32 AVLD_UP                                                                : 1;      /* [    8]  */
            UINT32 AVLD_DN                                                                : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }ANALOG__FT__MASK;
    union { /* 0x5104 [Excel Line :0598]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__FT__IRQ                                                        : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }ANALOG__FT__IRQ;
    union { /* 0x5108 [Excel Line :0600]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__FT__CLR                                                        : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }ANALOG__FT__CLR;
    union { /* 0x510C [Excel Line :0602]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__FT__STAT                                                       : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }ANALOG__FT__STAT;

    UINT8 EMPTY38[240]; /* 0xF0 */

    /* GROUP Start : SE_ANALOG__CLKMONI__CTRL */
    struct { /* 0x5200 [Excel Line :0604]  */
        union { /* 0x5200 [Excel Line :0604]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }ANALOG__CLKMONI__CTRL;
    union { /* 0x5204 [Excel Line :0611]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__CLKMONI__CAP_CNT_MIN                                           : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }ANALOG__CLKMONI__CAP_CNT_MIN;
    union { /* 0x5208 [Excel Line :0612]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__CLKMONI__CAP_CNT_MAX                                           : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }ANALOG__CLKMONI__CAP_CNT_MAX;
    union { /* 0x520C [Excel Line :0613]  */
        UINT32 Reg;
        struct {
            UINT32 ANALOG__CLKMONI__CAP_CNT_VAL                                           : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }ANALOG__CLKMONI__CAP_CNT_VAL;
    }SE_ANALOG__CLKMONI__CTRL__GROUP[6];

    UINT8 EMPTY39[3488]; /* 0xDA0 */

    union { /* 0x6000 [Excel Line :0664]  */
        UINT32 Reg;
        struct {
            UINT32 IDI_TX_SYNC_ERR                                                        : 1;      /* [    0]  */
            UINT32 IDI_RX_MEM_ERR                                                         : 1;      /* [    1]  */
            UINT32 IDI_TX_MEM_ERR                                                         : 1;      /* [    2]  */
            UINT32 IDI_EM_MEM_ERR                                                         : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }VISION00__IDI_STAT;
    union { /* 0x6004 [Excel Line :0669]  */
        UINT32 Reg;
        struct {
            UINT32 MDMAW_IMG_CH0_ERR                                                      : 1;      /* [    0]  */
            UINT32 MDMAW_EMB_CH0_ERR                                                      : 1;      /* [    1]  */
            UINT32 MDMAW_IMG_CH1_ERR                                                      : 1;      /* [    2]  */
            UINT32 MDMAW_EMB_CH1_ERR                                                      : 1;      /* [    3]  */
            UINT32 MDMAW_IMG_CH2_ERR                                                      : 1;      /* [    4]  */
            UINT32 MDMAW_EMB_CH2_ERR                                                      : 1;      /* [    5]  */
            UINT32 MDMAW_IMG_CH3_ERR                                                      : 1;      /* [    6]  */
            UINT32 MDMAW_EMB_CH3_ERR                                                      : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VISION00__MDMAW_STAT;
    union { /* 0x6008 [Excel Line :0678]  */
        UINT32 Reg;
        struct {
            UINT32 MDMAR_ERR                                                              : 1;      /* [    0]  */
            UINT32 MDMA_AFIFO_L_ERR                                                       : 1;      /* [    1]  */
            UINT32 MDMA_AFIFO_M_ERR                                                       : 1;      /* [    2]  */
            UINT32 MDMA_AFIFO_S_ERR                                                       : 1;      /* [    3]  */
            UINT32 MDMA_AFIFO_V_ERR                                                       : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }VISION00__MDMAR_STAT;
    union { /* 0x600C [Excel Line :0684]  */
        UINT32 Reg;
        struct {
            UINT32 ISP_AFIFO_MT0_ERR                                                      : 1;      /* [    0]  */
            UINT32 ISP_AFIFO_MT0_S0_ERR                                                   : 1;      /* [    1]  */
            UINT32 ISP_AFIFO_MT0_S1_ERR                                                   : 1;      /* [    2]  */
            UINT32 ISP_AFIFO_MT0_S2_ERR                                                   : 1;      /* [    3]  */
            UINT32 ISP_AFIFO_MT1_ERR                                                      : 1;      /* [    4]  */
            UINT32 ISP_AFIFO_MT1_S0_ERR                                                   : 1;      /* [    5]  */
            UINT32 ISP_AFIFO_MT1_S1_ERR                                                   : 1;      /* [    6]  */
            UINT32 ISP_AFIFO_MT1_S2_ERR                                                   : 1;      /* [    7]  */
            UINT32 ISP_AFIFO_MT2_ERR                                                      : 1;      /* [    8]  */
            UINT32 ISP_AFIFO_MT2_S0_ERR                                                   : 1;      /* [    9]  */
            UINT32 ISP_AFIFO_MT2_S1_ERR                                                   : 1;      /* [   10]  */
            UINT32 ISP_AFIFO_MT2_S2_ERR                                                   : 1;      /* [   11]  */
            UINT32 ISP_AFIFO_MT3_ERR                                                      : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ISP_AFIFO_STAT;
    union { /* 0x6010 [Excel Line :0698]  */
        UINT32 Reg;
        struct {
            UINT32 ISP_LOGIC_ERR                                                          : 1;      /* [    0]  */
            UINT32 ISP_MEM_ERR                                                            : 1;      /* [    1]  */
            UINT32 ISP_SYNC_ERR                                                           : 1;      /* [    2]  */
            UINT32 ISP_TPI_BU_ERR                                                         : 2;      /* [  4:3]  */
            UINT32 ISP_TPI_BU_DONE                                                        : 1;      /* [    5]  */
            UINT32 ISP_TPI_BU_S0_ERR                                                      : 2;      /* [  7:6]  */
            UINT32 ISP_TPI_BU_S0_DONE                                                     : 1;      /* [    8]  */
            UINT32 ISP_TPI_BU_S1_ERR                                                      : 2;      /* [ 10:9]  */
            UINT32 ISP_TPI_BU_S1_DONE                                                     : 1;      /* [   11]  */
            UINT32 ISP_TPI_BU_S2_ERR                                                      : 2;      /* [13:12]  */
            UINT32 ISP_TPI_BU_S2_DONE                                                     : 1;      /* [   14]  */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_STAT;
    union { /* 0x6014 [Excel Line :0710]  */
        UINT32 Reg;
        struct {
            UINT32 VDMA_CNN_0_ERR                                                         : 1;      /* [    0]  */
            UINT32 VDMA_CNN_1_ERR                                                         : 1;      /* [    1]  */
            UINT32 VDMA_CNN_2_ERR                                                         : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }VISION00__VDMA_CNN_STAT;
    union { /* 0x6018 [Excel Line :0714]  */
        UINT32 Reg;
        struct {
            UINT32 VDMA_CODA_0_ERR                                                        : 1;      /* [    0]  */
            UINT32 VDMA_CODA_1_ERR                                                        : 1;      /* [    1]  */
            UINT32 VDMA_CODA_2_ERR                                                        : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }VISION00__VDMA_CODA_STAT;
    union { /* 0x601C [Excel Line :0718]  */
        UINT32 Reg;
        struct {
            UINT32 ADAS_AFIFO0_ERR                                                        : 1;      /* [    0]  */
            UINT32 ADAS_AFIFO1_ERR                                                        : 1;      /* [    1]  */
            UINT32 ADAS_AFIFO2_ERR                                                        : 1;      /* [    2]  */
            UINT32 ADAS_AFIFO3_ERR                                                        : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }VISION00__ADAS_AFIFO_STAT;
    union { /* 0x6020 [Excel Line :0723]  */
        UINT32 Reg;
        struct {
            UINT32 ADAS_PRE_TOP_ERR                                                       : 1;      /* [    0]  */
            UINT32 ADAS_MS_IMG_GEN_ERR                                                    : 1;      /* [    1]  */
            UINT32 ADAS_MOD_ERR                                                           : 1;      /* [    2]  */
            UINT32 ADAS_LD_ERR                                                            : 1;      /* [    3]  */
            UINT32 ADAS_IMGR_ERR                                                          : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }VISION00__ADAS_STAT;

    UINT8 EMPTY40[220]; /* 0xDC */

    union { /* 0x6100 [Excel Line :0729]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_VISION0_MIPI_DMA_SEN                                      : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_VISION0_MIPI_RX_IDI_IN                                    : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_VISION0_MIPI_RX_IDI_OUT                                   : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_VISION0_MIPI_TX_IDI_IN                                    : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_VISION0_MIPI_TX_IDI_OUT                                   : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_CODEC                                        : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_DIG                                          : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_FRC                                          : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_ISP                                          : 1;      /* [    8]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_NPU                                          : 1;      /* [    9]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_NXLDC                                        : 1;      /* [   10]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S0_FRC                                       : 1;      /* [   11]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S0_ISP                                       : 1;      /* [   12]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S0_NXLDC                                     : 1;      /* [   13]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S1_FRC                                       : 1;      /* [   14]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S1_ISP                                       : 1;      /* [   15]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S1_NXLDC                                     : 1;      /* [   16]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S2_FRC                                       : 1;      /* [   17]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S2_ISP                                       : 1;      /* [   18]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_S2_NXLDC                                     : 1;      /* [   19]  */
            UINT32 CLKMONI__CLK_VISION0_VCLK_ADAS                                         : 1;      /* [   20]  */
            UINT32 VISION0_CSI2_RX_MEM_ERR                                                : 1;      /* [   21]  */
            UINT32 VISION0_CSI2_TX_MEM_ERR                                                : 1;      /* [   22]  */
            UINT32 VISION0_IDI_MEM_ERR                                                    : 1;      /* [   23]  */
            UINT32 VISION0_MIPI_DMAW_MEM_ERR                                              : 1;      /* [   24]  */
            UINT32 VISION0_MIPI_DMAR_MEM_ERR                                              : 1;      /* [   25]  */
            UINT32 VISION0_ISP_AFIFO_ERR                                                  : 1;      /* [   26]  */
            UINT32 VISION0_ISP_ERR                                                        : 1;      /* [   27]  */
            UINT32 VISION0_VDMA_CNN_ERR                                                   : 1;      /* [   28]  */
            UINT32 VISION0_VDMA_CODA_ERR                                                  : 1;      /* [   29]  */
            UINT32 VISION0_ADAS_AFIFO_ERR                                                 : 1;      /* [   30]  */
            UINT32 VISION0_ADAS_ERR                                                       : 1;      /* [   31]  */
        }Bit;
    }VISION00__FT__MASK;
    union { /* 0x6104 [Excel Line :0761]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__FT__IRQ                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }VISION00__FT__IRQ;
    union { /* 0x6108 [Excel Line :0762]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__FT__CLR                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }VISION00__FT__CLR;
    union { /* 0x610C [Excel Line :0763]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__FT__STAT                                                     : 32;     /* [ 31:0]  */
        }Bit;
    }VISION00__FT__STAT;

    UINT8 EMPTY41[240]; /* 0xF0 */

    /* GROUP Start : SE_VISION00__CLKMONI__CTRL */
    struct { /* 0x6200 [Excel Line :0764]  */
        union { /* 0x6200 [Excel Line :0764]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }VISION00__CLKMONI__CTRL;
    union { /* 0x6204 [Excel Line :0771]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__CLKMONI__CAP_CNT_MIN                                         : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION00__CLKMONI__CAP_CNT_MIN;
    union { /* 0x6208 [Excel Line :0772]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__CLKMONI__CAP_CNT_MAX                                         : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION00__CLKMONI__CAP_CNT_MAX;
    union { /* 0x620C [Excel Line :0773]  */
        UINT32 Reg;
        struct {
            UINT32 VISION00__CLKMONI__CAP_CNT_VAL                                         : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }VISION00__CLKMONI__CAP_CNT_VAL;
    }SE_VISION00__CLKMONI__CTRL__GROUP[21];

    UINT8 EMPTY42[176]; /* 0xB0 */

    union { /* 0x6400 [Excel Line :0974]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__CSI2_RX_RAM;

    UINT8 EMPTY43[12]; /* 0xC */

    union { /* 0x6410 [Excel Line :0979]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__CSI2_TX_RAM;

    UINT8 EMPTY44[12]; /* 0xC */

    union { /* 0x6420 [Excel Line :0984]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED3                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED2                                                              : 1;      /* [   13]  */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__IDI_TX_SYNC;

    UINT8 EMPTY45[12]; /* 0xC */

    union { /* 0x6430 [Excel Line :0989]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__IDI_RX_RAM;

    UINT8 EMPTY46[12]; /* 0xC */

    union { /* 0x6440 [Excel Line :0994]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__IDI_TX_RAM;

    UINT8 EMPTY47[12]; /* 0xC */

    union { /* 0x6450 [Excel Line :0999]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__IDI_EM_RAM;

    UINT8 EMPTY48[12]; /* 0xC */

    union { /* 0x6460 [Excel Line :1004]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_IMG_CH0_RAM;

    UINT8 EMPTY49[12]; /* 0xC */

    union { /* 0x6470 [Excel Line :1009]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_EMB_CH0_RAM;

    UINT8 EMPTY50[12]; /* 0xC */

    union { /* 0x6480 [Excel Line :1014]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_IMG_CH1_RAM;

    UINT8 EMPTY51[12]; /* 0xC */

    union { /* 0x6490 [Excel Line :1019]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_EMB_CH1_RAM;

    UINT8 EMPTY52[12]; /* 0xC */

    union { /* 0x64A0 [Excel Line :1024]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_IMG_CH2_RAM;

    UINT8 EMPTY53[12]; /* 0xC */

    union { /* 0x64B0 [Excel Line :1029]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_EMB_CH2_RAM;

    UINT8 EMPTY54[12]; /* 0xC */

    union { /* 0x64C0 [Excel Line :1034]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_IMG_CH3_RAM;

    UINT8 EMPTY55[12]; /* 0xC */

    union { /* 0x64D0 [Excel Line :1039]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAW_EMB_CH3_RAM;

    UINT8 EMPTY56[12]; /* 0xC */

    union { /* 0x64E0 [Excel Line :1044]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MDMAR_RAM;

    UINT8 EMPTY57[12]; /* 0xC */

    union { /* 0x64F0 [Excel Line :1049]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MIPI_AFIFO_L;

    UINT8 EMPTY58[12]; /* 0xC */

    union { /* 0x6500 [Excel Line :1054]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MIPI_AFIFO_M;

    UINT8 EMPTY59[12]; /* 0xC */

    union { /* 0x6510 [Excel Line :1059]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MIPI_AFIFO_S;

    UINT8 EMPTY60[12]; /* 0xC */

    union { /* 0x6520 [Excel Line :1064]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__MIPI_AFIFO_V;

    UINT8 EMPTY61[12]; /* 0xC */

    union { /* 0x6530 [Excel Line :1069]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT0;

    UINT8 EMPTY62[12]; /* 0xC */

    union { /* 0x6540 [Excel Line :1074]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT0_S0;

    UINT8 EMPTY63[12]; /* 0xC */

    union { /* 0x6550 [Excel Line :1079]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT0_S1;

    UINT8 EMPTY64[12]; /* 0xC */

    union { /* 0x6560 [Excel Line :1084]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT0_S2;

    UINT8 EMPTY65[12]; /* 0xC */

    union { /* 0x6570 [Excel Line :1089]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT1;

    UINT8 EMPTY66[12]; /* 0xC */

    union { /* 0x6580 [Excel Line :1094]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT1_S0;

    UINT8 EMPTY67[12]; /* 0xC */

    union { /* 0x6590 [Excel Line :1099]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT1_S1;

    UINT8 EMPTY68[12]; /* 0xC */

    union { /* 0x65A0 [Excel Line :1104]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT1_S2;

    UINT8 EMPTY69[12]; /* 0xC */

    union { /* 0x65B0 [Excel Line :1109]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT2;

    UINT8 EMPTY70[12]; /* 0xC */

    union { /* 0x65C0 [Excel Line :1114]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT2_S0;

    UINT8 EMPTY71[12]; /* 0xC */

    union { /* 0x65D0 [Excel Line :1119]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT2_S1;

    UINT8 EMPTY72[12]; /* 0xC */

    union { /* 0x65E0 [Excel Line :1124]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT2_S2;

    UINT8 EMPTY73[12]; /* 0xC */

    union { /* 0x65F0 [Excel Line :1129]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ISP_AFIFO_MT3;

    UINT8 EMPTY74[12]; /* 0xC */

    union { /* 0x6600 [Excel Line :1134]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ISP_LOGIC;

    UINT8 EMPTY75[12]; /* 0xC */

    union { /* 0x6610 [Excel Line :1137]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED3                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 RESERVED2                                                              : 1;      /* [   14]  */
            UINT32 FAULT_CLR                                                              : 1;      /* [   15] Fault Clear */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }VISION00__ISP_MEM;

    UINT8 EMPTY76[12]; /* 0xC */

    union { /* 0x6620 [Excel Line :1149]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ISP_SYNC;

    UINT8 EMPTY77[12]; /* 0xC */

    union { /* 0x6630 [Excel Line :1152]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CNN_RAM0;

    UINT8 EMPTY78[12]; /* 0xC */

    union { /* 0x6640 [Excel Line :1157]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CNN_RAM1;

    UINT8 EMPTY79[12]; /* 0xC */

    union { /* 0x6650 [Excel Line :1162]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CNN_RAM2;

    UINT8 EMPTY80[12]; /* 0xC */

    union { /* 0x6660 [Excel Line :1167]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CODA_RAM0;

    UINT8 EMPTY81[12]; /* 0xC */

    union { /* 0x6670 [Excel Line :1172]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CODA_RAM1;

    UINT8 EMPTY82[12]; /* 0xC */

    union { /* 0x6680 [Excel Line :1177]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__VDMA_CODA_RAM2;

    UINT8 EMPTY83[12]; /* 0xC */

    union { /* 0x6690 [Excel Line :1182]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ADAS_AFIFO0;

    UINT8 EMPTY84[12]; /* 0xC */

    union { /* 0x66A0 [Excel Line :1187]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ADAS_AFIFO1;

    UINT8 EMPTY85[12]; /* 0xC */

    union { /* 0x66B0 [Excel Line :1192]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ADAS_AFIFO2;

    UINT8 EMPTY86[12]; /* 0xC */

    union { /* 0x66C0 [Excel Line :1197]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION00__ADAS_AFIFO3;

    UINT8 EMPTY87[12]; /* 0xC */

    union { /* 0x66D0 [Excel Line :1202]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ADAS_PRE_ISP;

    UINT8 EMPTY88[12]; /* 0xC */

    union { /* 0x66E0 [Excel Line :1205]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ADAS_MS_IMG_GEN;

    UINT8 EMPTY89[12]; /* 0xC */

    union { /* 0x66F0 [Excel Line :1208]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ADAS_MOD;

    UINT8 EMPTY90[12]; /* 0xC */

    union { /* 0x6700 [Excel Line :1211]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ADAS_LD;

    UINT8 EMPTY91[12]; /* 0xC */

    union { /* 0x6710 [Excel Line :1214]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION00__ADAS_IMGR;

    UINT8 EMPTY92[2540]; /* 0x9EC */

    union { /* 0x7100 [Excel Line :1217]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_VISION0_APB                                               : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_MIPI_DMA0_APB                                             : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_MIPI_DMA0_AXI                                             : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_MIPI_IDI0_APB                                             : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_MIPI_CSI0_RX_APB                                          : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_MIPI_CSI0_TX_APB                                          : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_VDMA0_BUS_AXI                                             : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_VDMA0_CODEC_APB                                           : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_VDMA0_CODEC_AXI                                           : 1;      /* [    8]  */
            UINT32 CLKMONI__CLK_VDMA0_NPU_APB                                             : 1;      /* [    9]  */
            UINT32 CLKMONI__CLK_VDMA0_NPU_AXI                                             : 1;      /* [   10]  */
            UINT32 CLKMONI__CLK_ISP0_APB                                                  : 1;      /* [   11]  */
            UINT32 CLKMONI__CLK_ISP0_AXI                                                  : 1;      /* [   12]  */
            UINT32 CLKMONI__CLK_ISP0_BUS_AXI                                              : 1;      /* [   13]  */
            UINT32 CLKMONI__CLK_ISP0_NXLDC_AXI                                            : 1;      /* [   14]  */
            UINT32 CLKMONI__CLK_ISP0_OSG_AXI                                              : 1;      /* [   15]  */
            UINT32 CLKMONI__CLK_ISP0_S0_AXI                                               : 1;      /* [   16]  */
            UINT32 CLKMONI__CLK_ISP0_S1_AXI                                               : 1;      /* [   17]  */
            UINT32 CLKMONI__CLK_ISP0_S2_AXI                                               : 1;      /* [   18]  */
            UINT32 CLKMONI__CLK_ADAS_APB                                                  : 1;      /* [   19]  */
            UINT32 CLKMONI__CLK_ADAS_AXI                                                  : 1;      /* [   20]  */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }VISION01__FT__MASK;
    union { /* 0x7104 [Excel Line :1239]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__FT__IRQ                                                      : 21;     /* [ 20:0]  */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }VISION01__FT__IRQ;
    union { /* 0x7108 [Excel Line :1241]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__FT__CLR                                                      : 21;     /* [ 20:0]  */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }VISION01__FT__CLR;
    union { /* 0x710C [Excel Line :1243]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__FT__STAT                                                     : 21;     /* [ 20:0]  */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }VISION01__FT__STAT;

    UINT8 EMPTY93[240]; /* 0xF0 */

    /* GROUP Start : SE_VISION01__CLKMONI__CTRL */
    struct { /* 0x7200 [Excel Line :1245]  */
        union { /* 0x7200 [Excel Line :1245]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }VISION01__CLKMONI__CTRL;
    union { /* 0x7204 [Excel Line :1252]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__CLKMONI__CAP_CNT_MIN                                         : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION01__CLKMONI__CAP_CNT_MIN;
    union { /* 0x7208 [Excel Line :1253]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__CLKMONI__CAP_CNT_MAX                                         : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION01__CLKMONI__CAP_CNT_MAX;
    union { /* 0x720C [Excel Line :1254]  */
        UINT32 Reg;
        struct {
            UINT32 VISION01__CLKMONI__CAP_CNT_VAL                                         : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }VISION01__CLKMONI__CAP_CNT_VAL;
    }SE_VISION01__CLKMONI__CTRL__GROUP[21];

    UINT8 EMPTY94[3248]; /* 0xCB0 */

    union { /* 0x8000 [Excel Line :1455]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__DEBUG0                                                            : 32;     /* [ 31:0] Debug Register 0 */
        }Bit;
    }BUS__DEBUG0;
    union { /* 0x8004 [Excel Line :1456]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__DEBUG1                                                            : 32;     /* [ 31:0] Debug Register 1 */
        }Bit;
    }BUS__DEBUG1;
    union { /* 0x8008 [Excel Line :1457]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__DEBUG2                                                            : 32;     /* [ 31:0] Debug Register 2 */
        }Bit;
    }BUS__DEBUG2;
    union { /* 0x800C [Excel Line :1458]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__DEBUG3                                                            : 32;     /* [ 31:0] Debug Register 3 */
        }Bit;
    }BUS__DEBUG3;

    UINT8 EMPTY95[240]; /* 0xF0 */

    union { /* 0x8100 [Excel Line :1459]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__LDA_TX_CLK_TO_AIW                                             : 1;      /* [    0]  */
            UINT32 CLKMONI__LDA_TX_CLK_TO_CODA                                            : 1;      /* [    1]  */
            UINT32 CLKMONI__LDA_TX_CLK_TO_ISP                                             : 1;      /* [    2]  */
            UINT32 CLKMONI__LDA_TX_CLK_TO_DDR                                             : 1;      /* [    3]  */
            UINT32 CLKMONI__LDA_RX_CLK_FROM_AIW                                           : 1;      /* [    4]  */
            UINT32 CLKMONI__LDA_RX_CLK_FROM_CODA                                          : 1;      /* [    5]  */
            UINT32 CLKMONI__LDA_RX_CLK_FROM_ISP                                           : 1;      /* [    6]  */
            UINT32 CLKMONI__LDA_RX_CLK_FROM_CPU                                           : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_OIC                                                       : 1;      /* [    8]  */
            UINT32 CLKMONI__CLK_OIC_CR                                                    : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }BUS__FT__MASK;
    union { /* 0x8104 [Excel Line :1470]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__FT__IRQ                                                           : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }BUS__FT__IRQ;
    union { /* 0x8108 [Excel Line :1472]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__FT__CLR                                                           : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }BUS__FT__CLR;
    union { /* 0x810C [Excel Line :1474]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__FT__STAT                                                          : 10;     /* [  9:0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }BUS__FT__STAT;

    UINT8 EMPTY96[240]; /* 0xF0 */

    /* GROUP Start : SE_BUS__CLKMONI__CTRL */
    struct { /* 0x8200 [Excel Line :1476]  */
        union { /* 0x8200 [Excel Line :1476]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }BUS__CLKMONI__CTRL;
    union { /* 0x8204 [Excel Line :1483]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }BUS__CLKMONI__CAP_CNT_MIN;
    union { /* 0x8208 [Excel Line :1484]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }BUS__CLKMONI__CAP_CNT_MAX;
    union { /* 0x820C [Excel Line :1485]  */
        UINT32 Reg;
        struct {
            UINT32 BUS__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }BUS__CLKMONI__CAP_CNT_VAL;
    }SE_BUS__CLKMONI__CTRL__GROUP[10];

    UINT8 EMPTY97[3424]; /* 0xD60 */

    union { /* 0x9000 [Excel Line :1576]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__PMUEVENT0                                                         : 30;     /* [ 29:0] CPU Core 0 PMU event */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CPU__PMUEVENT0;
    union { /* 0x9004 [Excel Line :1578]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__PMUEVENT1                                                         : 30;     /* [ 29:0] CPU Core 1 PMU event */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CPU__PMUEVENT1;
    union { /* 0x9008 [Excel Line :1580]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__PMUEVENT2                                                         : 30;     /* [ 29:0] CPU Core 2 PMU event */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CPU__PMUEVENT2;
    union { /* 0x900C [Excel Line :1582]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__PMUEVENT3                                                         : 30;     /* [ 29:0] CPU Core 3 PMU event */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CPU__PMUEVENT3;
    union { /* 0x9010 [Excel Line :1584]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG0                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG0;
    union { /* 0x9014 [Excel Line :1585]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG1                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG1;
    union { /* 0x9018 [Excel Line :1586]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG2                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG2;
    union { /* 0x901C [Excel Line :1587]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG3                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG3;
    union { /* 0x9020 [Excel Line :1588]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG4                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG4;
    union { /* 0x9024 [Excel Line :1589]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG5                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG5;
    union { /* 0x9028 [Excel Line :1590]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG6                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG6;
    union { /* 0x902C [Excel Line :1591]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__DEBUG7                                                            : 32;     /* [ 31:0] Safety Debug Register */
        }Bit;
    }CPU__DEBUG7;
    union { /* 0x9030 [Excel Line :1592]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTER_IFP_CMP_DISABLE                                                : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU__A65_CLUSTER_IFP_COMPARE_DISABLE;
    union { /* 0x9034 [Excel Line :1594]  */
        UINT32 Reg;
        struct {
            UINT32 DCLS_CMP_DISABLE                                                       : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }CPU__A65_DCLS_COMPARE_DISABLE;

    UINT8 EMPTY98[8]; /* 0x8 */

    union { /* 0x9040 [Excel Line :1596]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERIFPFORCER                                                       : 10;     /* [  9:0]  */
            UINT32 RESERVED2                                                              : 6;      /* [15:10]  */
            UINT32 CLUSTERIFPFORCEP                                                       : 10;     /* [25:16]  */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }CPU__A65_CLUSTER_IFP_FAULT_FORCE;
    union { /* 0x9044 [Excel Line :1600]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERDCLSFORCEP                                                      : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CLUSTER_DCLS_FAULT_FORCE_P;
    union { /* 0x9048 [Excel Line :1602]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERDCLSFORCER                                                      : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CLUSTER_DCLS_FAULT_FORCE_R;
    union { /* 0x904C [Excel Line :1604]  */
        UINT32 Reg;
        struct {
            UINT32 COREDCLSFORCECP1R                                                      : 8;      /* [  7:0]  */
            UINT32 COREDCLSFORCECP1P                                                      : 8;      /* [ 15:8]  */
            UINT32 COREDCLSFORCECP0R                                                      : 8;      /* [23:16]  */
            UINT32 COREDCLSFORCECP0P                                                      : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CORE_DCLS_FAULT_FORCE;
    union { /* 0x9050 [Excel Line :1608]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERIFPFAULTR                                                       : 10;     /* [  9:0]  */
            UINT32 RESERVED2                                                              : 6;      /* [15:10]  */
            UINT32 CLUSTERIFPFAULTP                                                       : 10;     /* [25:16]  */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }CPU__A65_CLUSTER_IFP_FAULT_STATUS;
    union { /* 0x9054 [Excel Line :1612]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERDCLSFAULTP                                                      : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CLUSTER_DCLS_FAULT_P_STATUS;
    union { /* 0x9058 [Excel Line :1614]  */
        UINT32 Reg;
        struct {
            UINT32 CLUSTERDCLSFAULTR                                                      : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CLUSTER_DCLS_FAULT_R_STATUS;
    union { /* 0x905C [Excel Line :1616]  */
        UINT32 Reg;
        struct {
            UINT32 COREDCLSFAULTCP1R                                                      : 8;      /* [  7:0]  */
            UINT32 COREDCLSFAULTCP1P                                                      : 8;      /* [ 15:8]  */
            UINT32 COREDCLSFAULTCP0R                                                      : 8;      /* [23:16]  */
            UINT32 COREDCLSFAULTCP0P                                                      : 8;      /* [31:24]  */
        }Bit;
    }CPU__A65_CORE_DCLS_FAULT_STATUS;
    union { /* 0x9060 [Excel Line :1620]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP0P_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP0_P_0;
    union { /* 0x9064 [Excel Line :1621]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP0P_1                                                      : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP0_P_1;
    union { /* 0x9068 [Excel Line :1623]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP0R_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP0_R_0;
    union { /* 0x906C [Excel Line :1624]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP0R_1                                                      : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP0_R_1;
    union { /* 0x9070 [Excel Line :1626]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP1P_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP1_P_0;
    union { /* 0x9074 [Excel Line :1627]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP1P_1                                                      : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP1_P_1;
    union { /* 0x9078 [Excel Line :1629]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP1R_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP1_R_0;
    union { /* 0x907C [Excel Line :1630]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRMISCCP1R_1                                                      : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CPU__A65_CORE_ERR_MISC_CP1_R_1;
    union { /* 0x9080 [Excel Line :1632]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRUECP1R                                                          : 1;      /* [    0]  */
            UINT32 COREERRUECP1P                                                          : 1;      /* [    1]  */
            UINT32 COREERRUECP0R                                                          : 1;      /* [    2]  */
            UINT32 COREERRUECP0P                                                          : 1;      /* [    3]  */
            UINT32 COREERRDECP1R                                                          : 1;      /* [    4]  */
            UINT32 COREERRDECP1P                                                          : 1;      /* [    5]  */
            UINT32 COREERRDECP0R                                                          : 1;      /* [    6]  */
            UINT32 COREERRDECP0P                                                          : 1;      /* [    7]  */
            UINT32 COREERRCECP1R                                                          : 2;      /* [  9:8]  */
            UINT32 COREERRCECP1P                                                          : 2;      /* [11:10]  */
            UINT32 COREERRCECP0R                                                          : 2;      /* [13:12]  */
            UINT32 COREERRCECP0P                                                          : 2;      /* [15:14]  */
            UINT32 COREERROFCP1R                                                          : 1;      /* [   16]  */
            UINT32 COREERROFCP1P                                                          : 1;      /* [   17]  */
            UINT32 COREERROFCP0R                                                          : 1;      /* [   18]  */
            UINT32 COREERROFCP0P                                                          : 1;      /* [   19]  */
            UINT32 COREERRVCP1R                                                           : 1;      /* [   20]  */
            UINT32 COREERRVCP1P                                                           : 1;      /* [   21]  */
            UINT32 COREERRVCP0R                                                           : 1;      /* [   22]  */
            UINT32 COREERRVCP0P                                                           : 1;      /* [   23]  */
            UINT32 COREERRAVCP1R                                                          : 1;      /* [   24]  */
            UINT32 COREERRAVCP1P                                                          : 1;      /* [   25]  */
            UINT32 COREERRAVCP0R                                                          : 1;      /* [   26]  */
            UINT32 COREERRAVCP0P                                                          : 1;      /* [   27]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }CPU__A65_CORE_ERR_OTHERS;
    union { /* 0x9084 [Excel Line :1657]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP0P_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP0_P_0;
    union { /* 0x9088 [Excel Line :1658]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP0P_1                                                      : 13;     /* [ 12:0]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP0_P_1;
    union { /* 0x908C [Excel Line :1660]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP0R_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP0_R_0;
    union { /* 0x9090 [Excel Line :1661]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP0R_1                                                      : 13;     /* [ 12:0]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP0_R_1;
    union { /* 0x9094 [Excel Line :1663]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP1P_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP1_P_0;
    union { /* 0x9098 [Excel Line :1664]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP1P_1                                                      : 13;     /* [ 12:0]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP1_P_1;
    union { /* 0x909C [Excel Line :1666]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP1R_0                                                      : 32;     /* [ 31:0]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP1_R_0;
    union { /* 0x90A0 [Excel Line :1667]  */
        UINT32 Reg;
        struct {
            UINT32 COREERRADDRCP1R_1                                                      : 13;     /* [ 12:0]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CPU__A65_CORE_ERR_ADDR_CP1_R_1;

    UINT8 EMPTY99[92]; /* 0x5C */

    union { /* 0x9100 [Excel Line :1669]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_CPU_A65_SCLK                                              : 1;      /* [    0] A65 Core clock monitor */
            UINT32 CLKMONI__CLK_CPU_A65_ATB                                               : 1;      /* [    1] A65 CoreSight ATB clock monitor */
            UINT32 CLKMONI__CLK_CPU_R5_CLKIN                                              : 1;      /* [    2] R5 Core clock monitor */
            UINT32 CLKMONI__CLK_CPU_A65_GIC                                               : 1;      /* [    3] A65 GIC clock monitor */
            UINT32 ERRIRQ_0                                                               : 1;      /* [    4] ECC error in L3 or snoop filter RAMs or ACE or CHI write transactions with a write response condition */
            UINT32 ERRIRQ_1                                                               : 1;      /* [    5] ECC error in L1 and L2 RAMs in each core */
            UINT32 ERRIRQ_2                                                               : 1;      /* [    6] ECC error in L1 and L2 RAMs in each core */
            UINT32 ERRIRQ_3                                                               : 1;      /* [    7] ECC error in L1 and L2 RAMs in each core */
            UINT32 ERRIRQ_4                                                               : 1;      /* [    8] ECC error in L1 and L2 RAMs in each core */
            UINT32 FAULTIRQ_0                                                             : 1;      /* [    9] ECC detected in L3 or snoop filter RAMs or ACE or CHI write transactions with a write response condition */
            UINT32 FAULTIRQ_1                                                             : 1;      /* [   10] ECC detected in L1 and L2 RAMs in each core */
            UINT32 FAULTIRQ_2                                                             : 1;      /* [   11] ECC detected in L1 and L2 RAMs in each core */
            UINT32 FAULTIRQ_3                                                             : 1;      /* [   12] ECC detected in L1 and L2 RAMs in each core */
            UINT32 FAULTIRQ_4                                                             : 1;      /* [   13] ECC detected in L1 and L2 RAMs in each core */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU__FT__MASK;
    union { /* 0x9104 [Excel Line :1684]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__FT__IRQ                                                           : 14;     /* [ 13:0] HW fault interrupt enable */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU__FT__IRQ;
    union { /* 0x9108 [Excel Line :1686]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__FT__CLR                                                           : 14;     /* [ 13:0] HW fault clear */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU__FT__CLR;
    union { /* 0x910C [Excel Line :1688]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__FT__STAT                                                          : 14;     /* [ 13:0] HW fault status */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }CPU__FT__STAT;

    UINT8 EMPTY100[240]; /* 0xF0 */

    /* GROUP Start : SE_CPU__CLKMONI__CTRL */
    struct { /* 0x9200 [Excel Line :1690]  */
        union { /* 0x9200 [Excel Line :1690]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }CPU__CLKMONI__CTRL;
    union { /* 0x9204 [Excel Line :1697]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }CPU__CLKMONI__CAP_CNT_MIN;
    union { /* 0x9208 [Excel Line :1698]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }CPU__CLKMONI__CAP_CNT_MAX;
    union { /* 0x920C [Excel Line :1699]  */
        UINT32 Reg;
        struct {
            UINT32 CPU__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }CPU__CLKMONI__CAP_CNT_VAL;
    }SE_CPU__CLKMONI__CTRL__GROUP[4];

    UINT8 EMPTY101[3520]; /* 0xDC0 */

    union { /* 0xA000 [Excel Line :1730]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }NPU__REGBANK;

    UINT8 EMPTY102[252]; /* 0xFC */

    union { /* 0xA100 [Excel Line :1731]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_NPU_AXI                                                   : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_NPU_CORE                                                  : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_NPU_NNU_0                                                 : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_NPU_NNU_1                                                 : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_NPU_NNU_2                                                 : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_NPU_WFRAM_0                                               : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_NPU_WFRAM_1                                               : 1;      /* [    6]  */
            UINT32 NPU__FT_0                                                              : 1;      /* [    7] blk_npu aiWare fault 0 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }NPU__FT__MASK;
    union { /* 0xA104 [Excel Line :1740]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__FT__IRQ                                                           : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }NPU__FT__IRQ;
    union { /* 0xA108 [Excel Line :1742]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__FT__CLR                                                           : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }NPU__FT__CLR;
    union { /* 0xA10C [Excel Line :1744]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__FT__STAT                                                          : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }NPU__FT__STAT;

    UINT8 EMPTY103[240]; /* 0xF0 */

    /* GROUP Start : SE_NPU__CLKMONI__CTRL */
    struct { /* 0xA200 [Excel Line :1746]  */
        union { /* 0xA200 [Excel Line :1746]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }SE_NPU__CLKMONI__CTRL;
    union { /* 0xA204 [Excel Line :1753]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }NPU__CLKMONI__CAP_CNT_MIN;
    union { /* 0xA208 [Excel Line :1754]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }NPU__CLKMONI__CAP_CNT_MAX;
    union { /* 0xA20C [Excel Line :1755]  */
        UINT32 Reg;
        struct {
            UINT32 NPU__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }NPU__CLKMONI__CAP_CNT_VAL;
    }SE_NPU__CLKMONI__CTRL[7];

    UINT8 EMPTY104[3472]; /* 0xD90 */

    union { /* 0xB000 [Excel Line :1816]  */
        UINT32 Reg;
        struct {
            UINT32 MG_TBPU_EN                                                             : 1;      /* [    0] ECC Check enabled for SRAMs for mg_tbu */
            UINT32 MG_DCI_EN                                                              : 1;      /* [    1] ECC Check enabled for SRAMs for mg_dci */
            UINT32 MG_ME_EN                                                               : 1;      /* [    2] ECC Check enabled for SRAMs for mg_me */
            UINT32 MG_IMD_EN                                                              : 1;      /* [    3] ECC Check enabled for SRAMs for mg_imd */
            UINT32 MG_RDO_EN                                                              : 1;      /* [    4] ECC Check enabled for SRAMs for mg_rdo */
            UINT32 MG_BINGEN_EN                                                           : 1;      /* [    5] ECC Check enabled for SRAMs for mg_bingen */
            UINT32 MG_IP_EN                                                               : 1;      /* [    6] ECC Check enabled for SRAMs for mg_ip */
            UINT32 MG_MC_EN                                                               : 1;      /* [    7] ECC Check enabled for SRAMs for mg_mc */
            UINT32 MG_SHARE_SPREG_0_EN                                                    : 1;      /* [    8] ECC Check enabled for SRAMs for mg_share_spreg_0 */
            UINT32 MG_SHARE_DPREG_0_EN                                                    : 1;      /* [    9] ECC Check enabled for SRAMs for mg_share_dpreg_0 */
            UINT32 MG_SHARE_DPREG_1_EN                                                    : 1;      /* [   10] ECC Check enabled for SRAMs for mg_share_dpreg_1 */
            UINT32 MG_FBD_16K_Y_EN                                                        : 1;      /* [   11] ECC Check enabled for SRAMs for mg_fbd_16k_y */
            UINT32 MG_FBD_8K_C_EN                                                         : 1;      /* [   12] ECC Check enabled for SRAMs for mg_fbd_8k_c */
            UINT32 MG_LOOPFILTER_EN                                                       : 1;      /* [   13] ECC Check enabled for SRAMs for mg_loopfilter */
            UINT32 MG_OUTBUF_EN                                                           : 1;      /* [   14] ECC Check enabled for SRAMs for mg_outbuf */
            UINT32 MG_SCALER_EN                                                           : 1;      /* [   15] ECC Check enabled for SRAMs for mg_scaler */
            UINT32 MG_VCPU_EN                                                             : 1;      /* [   16] ECC Check enabled for SRAMs for mg_vcpu */
            UINT32 DS_ECC_EN                                                              : 1;      /* [   17] ECC Check enabled for SRAMs for DOWNSCALER */
            UINT32 ROT_ECC_EN                                                             : 1;      /* [   18] ECC Check enabled for SRAMs for ROTATOR */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }HWA__MEM_ECC_CTRL;
    union { /* 0xB004 [Excel Line :1836]  */
        UINT32 Reg;
        struct {
            UINT32 MEM_ECC_WARNING                                                        : 19;     /* [ 18:0] ECC Warning for SRAMs for BLK_HWA */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }HWA__MEM_ECC_WARNING;

    UINT8 EMPTY105[248]; /* 0xF8 */

    union { /* 0xB100 [Excel Line :1838]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_H265_BPU                                                  : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_H265_AXI                                                  : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_H265_CORE                                                 : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_DS_AXI                                                    : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_DS_APB                                                    : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_ROT_AXI                                                   : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_ROT_APB                                                   : 1;      /* [    6]  */
            UINT32 MG_TBPU_ERROR                                                          : 1;      /* [    7] ECC Error for SRAMs for mg_tbu */
            UINT32 MG_DCI_ERROR                                                           : 1;      /* [    8] ECC Error for SRAMs for mg_dci */
            UINT32 MG_ME_ERROR                                                            : 1;      /* [    9] ECC Error for SRAMs for mg_me */
            UINT32 MG_IMD_ERROR                                                           : 1;      /* [   10] ECC Error for SRAMs for mg_imd */
            UINT32 MG_RDO_ERROR                                                           : 1;      /* [   11] ECC Error for SRAMs for mg_rdo */
            UINT32 MG_BINGEN_ERROR                                                        : 1;      /* [   12] ECC Error for SRAMs for mg_bingen */
            UINT32 MG_IP_ERROR                                                            : 1;      /* [   13] ECC Error for SRAMs for mg_ip */
            UINT32 MG_MC_ERROR                                                            : 1;      /* [   14] ECC Error for SRAMs for mg_mc */
            UINT32 MG_SHARE_SPREG_0_ERROR                                                 : 1;      /* [   15] ECC Error for SRAMs for mg_share_spreg_0 */
            UINT32 MG_SHARE_DPREG_0_ERROR                                                 : 1;      /* [   16] ECC Error for SRAMs for mg_share_dpreg_0 */
            UINT32 MG_SHARE_DPREG_1_ERROR                                                 : 1;      /* [   17] ECC Error for SRAMs for mg_share_dpreg_1 */
            UINT32 MG_FBD_16K_Y_ERROR                                                     : 1;      /* [   18] ECC Error for SRAMs for mg_fbd_16k_y */
            UINT32 MG_FBD_8K_C_ERROR                                                      : 1;      /* [   19] ECC Error for SRAMs for mg_fbd_8k_c */
            UINT32 MG_LOOPFILTER_ERROR                                                    : 1;      /* [   20] ECC Error for SRAMs for mg_loopfilter */
            UINT32 MG_OUTBUF_ERROR                                                        : 1;      /* [   21] ECC Error for SRAMs for mg_outbuf */
            UINT32 MG_SCALER_ERROR                                                        : 1;      /* [   22] ECC Error for SRAMs for mg_scaler */
            UINT32 MG_VCPU_ERROR                                                          : 1;      /* [   23] ECC Error for SRAMs for mg_vcpu */
            UINT32 DS_ERROR                                                               : 1;      /* [   24] ECC Error for SRAMs for DOWNSCALER */
            UINT32 ROT_ERROR                                                              : 1;      /* [   25] ECC Error for SRAMs for ROTATOR */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }HWA__FT__MASK;
    union { /* 0xB104 [Excel Line :1865]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__FT__IRQ                                                           : 26;     /* [ 25:0]  */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }HWA__FT__IRQ;
    union { /* 0xB108 [Excel Line :1867]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__FT__CLR                                                           : 26;     /* [ 25:0]  */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }HWA__FT__CLR;
    union { /* 0xB10C [Excel Line :1869]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__FT__STAT                                                          : 26;     /* [ 25:0]  */
            UINT32 RESERVED1                                                              : 6;      /* [31:26]  */
        }Bit;
    }HWA__FT__STAT;

    UINT8 EMPTY106[240]; /* 0xF0 */

    /* GROUP Start : SE_HWA__CLKMONI__CTRL */
    struct { /* 0xB200 [Excel Line :1871]  */
        union { /* 0xB200 [Excel Line :1871]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }HWA__CLKMONI__CTRL;
    union { /* 0xB204 [Excel Line :1878]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }HWA__CLKMONI__CAP_CNT_MIN;
    union { /* 0xB208 [Excel Line :1879]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }HWA__CLKMONI__CAP_CNT_MAX;
    union { /* 0xB20C [Excel Line :1880]  */
        UINT32 Reg;
        struct {
            UINT32 HWA__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }HWA__CLKMONI__CAP_CNT_VAL;
    }SE_HWA__CLKMONI__CTRL__GROUP[7];

    UINT8 EMPTY107[400]; /* 0x190 */

    union { /* 0xB400 [Excel Line :1941]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HWA__ECC_DS_RAM;

    UINT8 EMPTY108[12]; /* 0xC */

    union { /* 0xB410 [Excel Line :1949]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single warning clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }HWA__ECC_ROT_RAM;

    UINT8 EMPTY109[3052]; /* 0xBEC */

    union { /* 0xC000 [Excel Line :1957]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }DDR0__REGBANK;

    UINT8 EMPTY110[252]; /* 0xFC */

    union { /* 0xC100 [Excel Line :1958]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_DDR0_PHY_DFI                                              : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_DDR0_PHY_OSC                                              : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_DDRC0_APB                                                 : 1;      /* [    2]  */
            UINT32 DDR0_ECC_SEC_INT                                                       : 1;      /* [    3]  */
            UINT32 DDR0_ECC_DED_INT                                                       : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }DDR0__FT__MASK;
    union { /* 0xC104 [Excel Line :1964]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__FT__IRQ                                                          : 5;      /* [  4:0]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }DDR0__FT__IRQ;
    union { /* 0xC108 [Excel Line :1966]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__FT__CLR                                                          : 5;      /* [  4:0]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }DDR0__FT__CLR;
    union { /* 0xC10C [Excel Line :1968]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__FT__STAT                                                         : 5;      /* [  4:0]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }DDR0__FT__STAT;

    UINT8 EMPTY111[240]; /* 0xF0 */

    /* GROUP Start : SE_DDR0__CLKMONI__CTRL */
    struct { /* 0xC200 [Excel Line :1970]  */
        union { /* 0xC200 [Excel Line :1970]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }DDR0__CLKMONI__CTRL;
    union { /* 0xC204 [Excel Line :1977]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__CLKMONI__CAP_CNT_MIN                                             : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }DDR0__CLKMONI__CAP_CNT_MIN;
    union { /* 0xC208 [Excel Line :1978]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__CLKMONI__CAP_CNT_MAX                                             : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }DDR0__CLKMONI__CAP_CNT_MAX;
    union { /* 0xC20C [Excel Line :1979]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0__CLKMONI__CAP_CNT_VAL                                             : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }DDR0__CLKMONI__CAP_CNT_VAL;
    }SE_DDR0__CLKMONI__CTRL__GROUP[3];

    UINT8 EMPTY112[3536]; /* 0xDD0 */

    union { /* 0xD000 [Excel Line :2000]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }DDR1__REGBANK;

    UINT8 EMPTY113[252]; /* 0xFC */

    union { /* 0xD100 [Excel Line :2001]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_DDR1_PHY_DFI                                              : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_DDR1_PHY_OSC                                              : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_DDRC1_APB                                                 : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_DDRC1_LDA                                                 : 1;      /* [    3]  */
            UINT32 DDR1_ECC_SEC_INT                                                       : 1;      /* [    4]  */
            UINT32 DDR1_ECC_DED_INT                                                       : 1;      /* [    5]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }DDR1__FT__MASK;
    union { /* 0xD104 [Excel Line :2008]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__FT__IRQ                                                          : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }DDR1__FT__IRQ;
    union { /* 0xD108 [Excel Line :2010]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__FT__CLR                                                          : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }DDR1__FT__CLR;
    union { /* 0xD10C [Excel Line :2012]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__FT__STAT                                                         : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }DDR1__FT__STAT;

    UINT8 EMPTY114[240]; /* 0xF0 */

    /* GROUP Start : SE_DDR1__CLKMONI__CTRL */
    struct { /* 0xD200 [Excel Line :2014]  */
        union { /* 0xD200 [Excel Line :2014]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }DDR1__CLKMONI__CTRL;
    union { /* 0xD204 [Excel Line :2021]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__CLKMONI__CAP_CNT_MIN                                             : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }DDR1__CLKMONI__CAP_CNT_MIN;
    union { /* 0xD208 [Excel Line :2022]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__CLKMONI__CAP_CNT_MAX                                             : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }DDR1__CLKMONI__CAP_CNT_MAX;
    union { /* 0xD20C [Excel Line :2023]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1__CLKMONI__CAP_CNT_VAL                                             : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }DDR1__CLKMONI__CAP_CNT_VAL;
    }SE_DDR1__CLKMONI__CTRL__GROUP[4];

    UINT8 EMPTY115[3520]; /* 0xDC0 */

    union { /* 0xE000 [Excel Line :2054]  */
        UINT32 Reg;
        struct {
            UINT32 EN                                                                     : 1;      /* [    0] enable fault injection for SYS_ROM */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }MEM__ECC_ROM_CTRL;

    UINT8 EMPTY116[12]; /* 0xC */

    union { /* 0xE010 [Excel Line :2056]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_ROM_INJECT_0                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_ROM_INJECT_0;
    union { /* 0xE014 [Excel Line :2057]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_ROM_INJECT_1                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_ROM_INJECT_1;

    UINT8 EMPTY117[8]; /* 0x8 */

    union { /* 0xE020 [Excel Line :2058]  */
        UINT32 Reg;
        struct {
            UINT32 SYNDROME                                                               : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }MEM__ECC_ROM_INJECT_2;

    UINT8 EMPTY118[12]; /* 0xC */

    union { /* 0xE030 [Excel Line :2060]  */
        UINT32 Reg;
        struct {
            UINT32 STATUS                                                                 : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }MEM__ECC_ROM_INJECT_WARN;

    UINT8 EMPTY119[12]; /* 0xC */

    union { /* 0xE040 [Excel Line :2062]  */
        UINT32 Reg;
        struct {
            UINT32 EN                                                                     : 1;      /* [    0] enable fault injection for SYS_RAM */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }MEM__ECC_RAM_CTRL;

    UINT8 EMPTY120[12]; /* 0xC */

    union { /* 0xE050 [Excel Line :2064]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_RAM_INJECT_0                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_0;
    union { /* 0xE054 [Excel Line :2065]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_RAM_INJECT_1                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_1;
    union { /* 0xE058 [Excel Line :2066]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_RAM_INJECT_2                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_2;
    union { /* 0xE05C [Excel Line :2067]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__ECC_RAM_INJECT_3                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_3;
    union { /* 0xE060 [Excel Line :2068]  */
        UINT32 Reg;
        struct {
            UINT32 SYNDROME                                                               : 28;     /* [ 27:0]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_4;

    UINT8 EMPTY121[12]; /* 0xC */

    union { /* 0xE070 [Excel Line :2070]  */
        UINT32 Reg;
        struct {
            UINT32 STATUS                                                                 : 28;     /* [ 27:0]  */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }MEM__ECC_RAM_INJECT_WARN;

    UINT8 EMPTY122[140]; /* 0x8C */

    union { /* 0xE100 [Excel Line :2072]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_RAM                                                       : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_ROM                                                       : 1;      /* [    1]  */
            UINT32 ROM_ERR                                                                : 1;      /* [    2] Internal rom ecc error */
            UINT32 RAM_CH_0_LO                                                            : 1;      /* [    3] Internal ram ecc error */
            UINT32 RAM_CH_0_ML                                                            : 1;      /* [    4]  */
            UINT32 RAM_CH_0_MH                                                            : 1;      /* [    5]  */
            UINT32 RAM_CH_0_HI                                                            : 1;      /* [    6]  */
            UINT32 RAM_CH_1_LO                                                            : 1;      /* [    7]  */
            UINT32 RAM_CH_1_ML                                                            : 1;      /* [    8]  */
            UINT32 RAM_CH_1_MH                                                            : 1;      /* [    9]  */
            UINT32 RAM_CH_1_HI                                                            : 1;      /* [   10]  */
            UINT32 RAM_CH_2_LO                                                            : 1;      /* [   11]  */
            UINT32 RAM_CH_2_ML                                                            : 1;      /* [   12]  */
            UINT32 RAM_CH_2_MH                                                            : 1;      /* [   13]  */
            UINT32 RAM_CH_2_HI                                                            : 1;      /* [   14]  */
            UINT32 RAM_CH_3_LO                                                            : 1;      /* [   15]  */
            UINT32 RAM_CH_3_ML                                                            : 1;      /* [   16]  */
            UINT32 RAM_CH_3_MH                                                            : 1;      /* [   17]  */
            UINT32 RAM_CH_3_HI                                                            : 1;      /* [   18]  */
            UINT32 RAM_CH_4_LO                                                            : 1;      /* [   19]  */
            UINT32 RAM_CH_4_ML                                                            : 1;      /* [   20]  */
            UINT32 RAM_CH_4_MH                                                            : 1;      /* [   21]  */
            UINT32 RAM_CH_4_HI                                                            : 1;      /* [   22]  */
            UINT32 RAM_CH_5_LO                                                            : 1;      /* [   23]  */
            UINT32 RAM_CH_5_ML                                                            : 1;      /* [   24]  */
            UINT32 RAM_CH_5_MH                                                            : 1;      /* [   25]  */
            UINT32 RAM_CH_5_HI                                                            : 1;      /* [   26]  */
            UINT32 RAM_CH_6_LO                                                            : 1;      /* [   27]  */
            UINT32 RAM_CH_6_ML                                                            : 1;      /* [   28]  */
            UINT32 RAM_CH_6_MH                                                            : 1;      /* [   29]  */
            UINT32 RAM_CH_6_HI                                                            : 1;      /* [   30]  */
            UINT32 RESERVED1                                                              : 1;      /* [   31]  */
        }Bit;
    }MEM__FT__MASK;
    union { /* 0xE104 [Excel Line :2104]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__FT__IRQ                                                           : 31;     /* [ 30:0]  */
            UINT32 RESERVED1                                                              : 1;      /* [   31]  */
        }Bit;
    }MEM__FT__IRQ;
    union { /* 0xE108 [Excel Line :2106]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__FT__CLR                                                           : 31;     /* [ 30:0]  */
            UINT32 RESERVED1                                                              : 1;      /* [   31]  */
        }Bit;
    }MEM__FT__CLR;
    union { /* 0xE10C [Excel Line :2108]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__FT__STAT                                                          : 31;     /* [ 30:0]  */
            UINT32 RESERVED1                                                              : 1;      /* [   31]  */
        }Bit;
    }MEM__FT__STAT;

    UINT8 EMPTY123[240]; /* 0xF0 */

    /* GROUP Start : SE_MEM__CLKMONI__CTRL */
    struct { /* 0xE200 [Excel Line :2110]  */
        union { /* 0xE200 [Excel Line :2110]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }MEM__CLKMONI__CTRL;
    union { /* 0xE204 [Excel Line :2117]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }MEM__CLKMONI__CAP_CNT_MIN;
    union { /* 0xE208 [Excel Line :2118]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }MEM__CLKMONI__CAP_CNT_MAX;
    union { /* 0xE20C [Excel Line :2119]  */
        UINT32 Reg;
        struct {
            UINT32 MEM__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }MEM__CLKMONI__CAP_CNT_VAL;
    }SE_MEM__CLKMONI__CTRL__GROUP[2];

    UINT8 EMPTY124[3552]; /* 0xDE0 */

    union { /* 0xF000 [Excel Line :2130]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__DEBUG                                                            : 32;     /* [ 31:0] Debug Register */
        }Bit;
    }PCIE__DEBUG;

    UINT8 EMPTY125[252]; /* 0xFC */

    union { /* 0xF100 [Excel Line :2131]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_PCIE0_AXI                                                 : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_PCIE0_DBI                                                 : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_PCIE0_AUX                                                 : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_PCIE0_CORE                                                : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_PCIE1_AXI                                                 : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_PCIE1_DBI                                                 : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_PCIE1_AUX                                                 : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_PCIE1_CORE                                                : 1;      /* [    7]  */
            UINT32 PCIE0_MSTR_RASDP_ERR                                                   : 1;      /* [    8] controller has entered the RASDP error mode */
            UINT32 PCIE0_SLV_RASDP_ERR                                                    : 1;      /* [    9] controller has entered the RASDP error mode */
            UINT32 PCIE1_MSTR_RASDP_ERR                                                   : 1;      /* [   10] controller has entered the RASDP error mode */
            UINT32 PCIE1_SLV_RASDP_ERR                                                    : 1;      /* [   11] controller has entered the RASDP error mode */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PCIE__FT__MASK;
    union { /* 0xF104 [Excel Line :2144]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__FT__IRQ                                                          : 12;     /* [ 11:0]  */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PCIE__FT__IRQ;
    union { /* 0xF108 [Excel Line :2146]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__FT__CLR                                                          : 12;     /* [ 11:0]  */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PCIE__FT__CLR;
    union { /* 0xF10C [Excel Line :2148]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__FT__STAT                                                         : 12;     /* [ 11:0]  */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }PCIE__FT__STAT;

    UINT8 EMPTY126[240]; /* 0xF0 */

    /* GROUP Start : SE_PCIE__CLKMONI__CTRL */
    struct { /* 0xF200 [Excel Line :2150]  */
        union { /* 0xF200 [Excel Line :2150]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }PCIE__CLKMONI__CTRL;
    union { /* 0xF204 [Excel Line :2157]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__CLKMONI__CAP_CNT_MIN                                             : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }PCIE__CLKMONI__CAP_CNT_MIN;
    union { /* 0xF208 [Excel Line :2158]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__CLKMONI__CAP_CNT_MAX                                             : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }PCIE__CLKMONI__CAP_CNT_MAX;
    union { /* 0xF20C [Excel Line :2159]  */
        UINT32 Reg;
        struct {
            UINT32 PCIE__CLKMONI__CAP_CNT_VAL                                             : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }PCIE__CLKMONI__CAP_CNT_VAL;
    }SE_PCIE__CLKMONI__CTRL__GROUP[8];

    UINT8 EMPTY127[3456]; /* 0xD80 */

    union { /* 0x10000 [Excel Line :2230]  */
        UINT32 Reg;
        struct {
            UINT32 RAM0_ECC_EN                                                            : 1;      /* [    0] ECC enable for USB RAM0 */
            UINT32 RAM1_ECC_EN                                                            : 1;      /* [    1] ECC enable for USB RAM1 */
            UINT32 RAM2_ECC_EN                                                            : 1;      /* [    2] ECC enable for USB RAM2 */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }USB__ECC_USB_CTRL;

    UINT8 EMPTY128[252]; /* 0xFC */

    union { /* 0x10100 [Excel Line :2234]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_USB_APB                                                   : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_USB_CORE                                                  : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_USB_SAFETY                                                : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_USB_SUSPEND                                               : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_USB_REFCLK                                                : 1;      /* [    4]  */
            UINT32 USB_RAM0_DED_ERROR                                                     : 1;      /* [    5] USB RAM0 DED error */
            UINT32 USB_RAM0_SEC_WARNING                                                   : 1;      /* [    6] USB RAM0 SEC warning */
            UINT32 USB_RAM1_DED_ERROR                                                     : 1;      /* [    7] USB RAM1 DED error */
            UINT32 USB_RAM1_SEC_WARNING                                                   : 1;      /* [    8] USB RAM1 SEC warning */
            UINT32 USB_RAM2_DED_ERROR                                                     : 1;      /* [    9] USB RAM2 DED error */
            UINT32 USB_RAM2_SEC_WARNING                                                   : 1;      /* [   10] USB RAM2 SEC warning */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }USB__FT__MASK;
    union { /* 0x10104 [Excel Line :2246]  */
        UINT32 Reg;
        struct {
            UINT32 USB__FT__IRQ                                                           : 11;     /* [ 10:0]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }USB__FT__IRQ;
    union { /* 0x10108 [Excel Line :2248]  */
        UINT32 Reg;
        struct {
            UINT32 USB__FT__CLR                                                           : 11;     /* [ 10:0]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }USB__FT__CLR;
    union { /* 0x1010C [Excel Line :2250]  */
        UINT32 Reg;
        struct {
            UINT32 USB__FT__STAT                                                          : 11;     /* [ 10:0]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }USB__FT__STAT;

    UINT8 EMPTY129[240]; /* 0xF0 */

    /* GROUP Start : SE_USB__CLKMONI__CTRL */
    struct { /* 0x10200 [Excel Line :2252]  */
        union { /* 0x10200 [Excel Line :2252]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }USB__CLKMONI__CTRL;
    union { /* 0x10204 [Excel Line :2259]  */
        UINT32 Reg;
        struct {
            UINT32 USB__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }USB__CLKMONI__CAP_CNT_MIN;
    union { /* 0x10208 [Excel Line :2260]  */
        UINT32 Reg;
        struct {
            UINT32 USB__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }USB__CLKMONI__CAP_CNT_MAX;
    union { /* 0x1020C [Excel Line :2261]  */
        UINT32 Reg;
        struct {
            UINT32 USB__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }USB__CLKMONI__CAP_CNT_VAL;
    }SE_USB__CLKMONI__CTRL__GROUP[5];

    UINT8 EMPTY130[176]; /* 0xB0 */

    union { /* 0x10300 [Excel Line :2302]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM0 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }USB__ECC_RAM0;

    UINT8 EMPTY131[12]; /* 0xC */

    union { /* 0x10310 [Excel Line :2310]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM1 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }USB__ECC_RAM1;

    UINT8 EMPTY132[12]; /* 0xC */

    union { /* 0x10320 [Excel Line :2318]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] USB RAM2 Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }USB__ECC_RAM2;

    UINT8 EMPTY133[3292]; /* 0xCDC */

    union { /* 0x11000 [Excel Line :2326]  */
        UINT32 Reg;
        struct {
            UINT32 EN                                                                     : 1;      /* [    0] ECC enable for BLK_GPU */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GPU__ECC_GPU_CTRL;

    UINT8 EMPTY134[12]; /* 0xC */

    union { /* 0x11010 [Excel Line :2328]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_0_RD                                                       : 16;     /* [ 15:0] blk_gpu HW fault 0 read */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__ECC_GPU_RD_0;
    union { /* 0x11014 [Excel Line :2330]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_1_RD                                                       : 10;     /* [  9:0] blk_gpu HW fault 1 read */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }GPU__ECC_GPU_RD_1;
    union { /* 0x11018 [Excel Line :2332]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_2_RD                                                       : 28;     /* [ 27:0] blk_gpu HW fault 2 read */
            UINT32 RESERVED1                                                              : 4;      /* [31:28]  */
        }Bit;
    }GPU__ECC_GPU_RD_2;
    union { /* 0x1101C [Excel Line :2334]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_3_RD                                                       : 16;     /* [ 15:0] blk_gpu HW fault 3 read */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__ECC_GPU_RD_3;
    union { /* 0x11020 [Excel Line :2336]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_4_RD                                                       : 22;     /* [ 21:0] blk_gpu HW fault 4 read */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }GPU__ECC_GPU_RD_4;
    union { /* 0x11024 [Excel Line :2338]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_5_RD                                                       : 24;     /* [ 23:0] blk_gpu HW fault 5 read */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GPU__ECC_GPU_RD_5;
    union { /* 0x11028 [Excel Line :2340]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_6_RD                                                       : 16;     /* [ 15:0] blk_gpu HW fault 6 read */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__ECC_GPU_RD_6;
    union { /* 0x1102C [Excel Line :2342]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_7_RD                                                       : 22;     /* [ 21:0] blk_gpu HW fault 7 read */
            UINT32 RESERVED1                                                              : 10;     /* [31:22]  */
        }Bit;
    }GPU__ECC_GPU_RD_7;
    union { /* 0x11030 [Excel Line :2344]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_GPU__FT_8_RD                                                       : 24;     /* [ 23:0] blk_gpu HW fault 8 read */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GPU__ECC_GPU_RD_8;

    UINT8 EMPTY135[204]; /* 0xCC */

    union { /* 0x11100 [Excel Line :2346]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_GPU_AXI                                                   : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_GPU_AXI_FDC                                               : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_GPU_MMU_AXI                                               : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_GPU_MMU_AXI_FDC                                           : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_GPU_SCU_APB                                               : 1;      /* [    4]  */
            UINT32 BLK_GPU__FT_0                                                          : 1;      /* [    5] blk_gpu HW fault 0 */
            UINT32 BLK_GPU__FT_1                                                          : 1;      /* [    6] blk_gpu HW fault 1 */
            UINT32 BLK_GPU__FT_2                                                          : 1;      /* [    7] blk_gpu HW fault 2 */
            UINT32 BLK_GPU__FT_3                                                          : 1;      /* [    8] blk_gpu HW fault 3 */
            UINT32 BLK_GPU__FT_4                                                          : 1;      /* [    9] blk_gpu HW fault 4 */
            UINT32 BLK_GPU__FT_5                                                          : 1;      /* [   10] blk_gpu HW fault 5 */
            UINT32 BLK_GPU__FT_6                                                          : 1;      /* [   11] blk_gpu HW fault 6 */
            UINT32 BLK_GPU__FT_7                                                          : 1;      /* [   12] blk_gpu HW fault 7 */
            UINT32 BLK_GPU__FT_8                                                          : 1;      /* [   13] blk_gpu HW fault 8 */
            UINT32 BLK_GPU__FT_9                                                          : 1;      /* [   14] blk_gpu HW fault 9 */
            UINT32 BLK_GPU__FT_10                                                         : 1;      /* [   15] blk_gpu HW fault 10 */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__FT__MASK;
    union { /* 0x11104 [Excel Line :2363]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__FT__IRQ                                                           : 16;     /* [ 15:0] blk_gpu HW fault irq */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__FT__IRQ;
    union { /* 0x11108 [Excel Line :2365]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__FT__CLR                                                           : 16;     /* [ 15:0] blk_gpu HW fault clear */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__FT__CLR;
    union { /* 0x1110C [Excel Line :2367]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__FT__STAT                                                          : 16;     /* [ 15:0] blk_gpu HW fault status */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }GPU__FT__STAT;

    UINT8 EMPTY136[240]; /* 0xF0 */

    /* GROUP Start : SE_GPU__CLKMONI__CTRL */
    struct { /* 0x11200 [Excel Line :2369]  */
        union { /* 0x11200 [Excel Line :2369]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }GPU__CLKMONI__CTRL;
    union { /* 0x11204 [Excel Line :2376]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__CLKMONI__CAP_CNT_MIN                                              : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }GPU__CLKMONI__CAP_CNT_MIN;
    union { /* 0x11208 [Excel Line :2377]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__CLKMONI__CAP_CNT_MAX                                              : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }GPU__CLKMONI__CAP_CNT_MAX;
    union { /* 0x1120C [Excel Line :2378]  */
        UINT32 Reg;
        struct {
            UINT32 GPU__CLKMONI__CAP_CNT_VAL                                              : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }GPU__CLKMONI__CAP_CNT_VAL;
    }SE_GPU__CLKMONI__CTRL__GROUP[5];

    UINT8 EMPTY137[176]; /* 0xB0 */

    union { /* 0x11300 [Excel Line :2419]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] blk_gpu Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED2                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single error clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2single error clear */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }GPU__ECC_RAM0;

    UINT8 EMPTY138[3324]; /* 0xCFC */

    union { /* 0x12000 [Excel Line :2427]  */
        UINT32 Reg;
        struct {
            UINT32 IDI_TX_SYNC_ERR                                                        : 1;      /* [    0]  */
            UINT32 IDI_RX_MEM_ERR                                                         : 1;      /* [    1]  */
            UINT32 IDI_TX_MEM_ERR                                                         : 1;      /* [    2]  */
            UINT32 IDI_EM_MEM_ERR                                                         : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }VISION10__IDI_STAT;
    union { /* 0x12004 [Excel Line :2432]  */
        UINT32 Reg;
        struct {
            UINT32 MDMAW_IMG_CH0_ERR                                                      : 1;      /* [    0]  */
            UINT32 MDMAW_EMB_CH0_ERR                                                      : 1;      /* [    1]  */
            UINT32 MDMAW_IMG_CH1_ERR                                                      : 1;      /* [    2]  */
            UINT32 MDMAW_EMB_CH1_ERR                                                      : 1;      /* [    3]  */
            UINT32 MDMAW_IMG_CH2_ERR                                                      : 1;      /* [    4]  */
            UINT32 MDMAW_EMB_CH2_ERR                                                      : 1;      /* [    5]  */
            UINT32 MDMAW_IMG_CH3_ERR                                                      : 1;      /* [    6]  */
            UINT32 MDMAW_EMB_CH3_ERR                                                      : 1;      /* [    7]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }VISION10__MDMAW_STAT;
    union { /* 0x12008 [Excel Line :2441]  */
        UINT32 Reg;
        struct {
            UINT32 MDMAR_ERR                                                              : 1;      /* [    0]  */
            UINT32 MDMA_AFIFO_L_ERR                                                       : 1;      /* [    1]  */
            UINT32 MDMA_AFIFO_M_ERR                                                       : 1;      /* [    2]  */
            UINT32 MDMA_AFIFO_S_ERR                                                       : 1;      /* [    3]  */
            UINT32 MDMA_AFIFO_V_ERR                                                       : 1;      /* [    4]  */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }VISION10__MDMAR_STAT;
    union { /* 0x1200C [Excel Line :2447]  */
        UINT32 Reg;
        struct {
            UINT32 ISP_AFIFO_MT0_ERR                                                      : 1;      /* [    0]  */
            UINT32 ISP_AFIFO_MT0_S0_ERR                                                   : 1;      /* [    1]  */
            UINT32 ISP_AFIFO_MT0_S1_ERR                                                   : 1;      /* [    2]  */
            UINT32 ISP_AFIFO_MT0_S2_ERR                                                   : 1;      /* [    3]  */
            UINT32 ISP_AFIFO_MT1_ERR                                                      : 1;      /* [    4]  */
            UINT32 ISP_AFIFO_MT1_S0_ERR                                                   : 1;      /* [    5]  */
            UINT32 ISP_AFIFO_MT1_S1_ERR                                                   : 1;      /* [    6]  */
            UINT32 ISP_AFIFO_MT1_S2_ERR                                                   : 1;      /* [    7]  */
            UINT32 ISP_AFIFO_MT2_ERR                                                      : 1;      /* [    8]  */
            UINT32 ISP_AFIFO_MT2_S0_ERR                                                   : 1;      /* [    9]  */
            UINT32 ISP_AFIFO_MT2_S1_ERR                                                   : 1;      /* [   10]  */
            UINT32 ISP_AFIFO_MT2_S2_ERR                                                   : 1;      /* [   11]  */
            UINT32 ISP_AFIFO_MT3_ERR                                                      : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION10__ISP_AFIFO_STAT;
    union { /* 0x12010 [Excel Line :2461]  */
        UINT32 Reg;
        struct {
            UINT32 ISP_LOGIC_ERR                                                          : 1;      /* [    0]  */
            UINT32 ISP_MEM_ERR                                                            : 1;      /* [    1]  */
            UINT32 ISP_SYNC_ERR                                                           : 1;      /* [    2]  */
            UINT32 ISP_TPI_BU_ERR                                                         : 2;      /* [  4:3]  */
            UINT32 ISP_TPI_BU_DONE                                                        : 1;      /* [    5]  */
            UINT32 ISP_TPI_BU_S0_ERR                                                      : 2;      /* [  7:6]  */
            UINT32 ISP_TPI_BU_S0_DONE                                                     : 1;      /* [    8]  */
            UINT32 ISP_TPI_BU_S1_ERR                                                      : 2;      /* [ 10:9]  */
            UINT32 ISP_TPI_BU_S1_DONE                                                     : 1;      /* [   11]  */
            UINT32 ISP_TPI_BU_S2_ERR                                                      : 2;      /* [13:12]  */
            UINT32 ISP_TPI_BU_S2_DONE                                                     : 1;      /* [   14]  */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_STAT;
    union { /* 0x12014 [Excel Line :2473]  */
        UINT32 Reg;
        struct {
            UINT32 VDMA_CNN_0_ERR                                                         : 1;      /* [    0]  */
            UINT32 VDMA_CNN_1_ERR                                                         : 1;      /* [    1]  */
            UINT32 VDMA_CNN_2_ERR                                                         : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }VISION10__VDMA_CNN_STAT;
    union { /* 0x12018 [Excel Line :2477]  */
        UINT32 Reg;
        struct {
            UINT32 VDMA_CODA_0_ERR                                                        : 1;      /* [    0]  */
            UINT32 VDMA_CODA_1_ERR                                                        : 1;      /* [    1]  */
            UINT32 VDMA_CODA_2_ERR                                                        : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }VISION10__VDMA_CODA_STAT;

    UINT8 EMPTY139[228]; /* 0xE4 */

    union { /* 0x12100 [Excel Line :2481]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_VISION1_MIPI_DMA_SEN                                      : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_VISION1_MIPI_RX_IDI_IN                                    : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_VISION1_MIPI_RX_IDI_OUT                                   : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_VISION1_MIPI_TX_IDI_IN                                    : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_VISION1_MIPI_TX_IDI_OUT                                   : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_CODEC                                        : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_DIG                                          : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_FRC                                          : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_ISP                                          : 1;      /* [    8]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_NPU                                          : 1;      /* [    9]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_NXLDC                                        : 1;      /* [   10]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S0_FRC                                       : 1;      /* [   11]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S0_ISP                                       : 1;      /* [   12]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S0_NXLDC                                     : 1;      /* [   13]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S1_FRC                                       : 1;      /* [   14]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S1_ISP                                       : 1;      /* [   15]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S1_NXLDC                                     : 1;      /* [   16]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S2_FRC                                       : 1;      /* [   17]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S2_ISP                                       : 1;      /* [   18]  */
            UINT32 CLKMONI__CLK_VISION1_VCLK_S2_NXLDC                                     : 1;      /* [   19]  */
            UINT32 RESERVED2                                                              : 1;      /* [   20]  */
            UINT32 VISION1_CSI2_RX_MEM_ERR                                                : 1;      /* [   21]  */
            UINT32 VISION1_CSI2_TX_MEM_ERR                                                : 1;      /* [   22]  */
            UINT32 VISION1_IDI_MEM_ERR                                                    : 1;      /* [   23]  */
            UINT32 VISION1_MIPI_DMAW_MEM_ERR                                              : 1;      /* [   24]  */
            UINT32 VISION1_MIPI_DMAR_MEM_ERR                                              : 1;      /* [   25]  */
            UINT32 VISION1_ISP_AFIFO_ERR                                                  : 1;      /* [   26]  */
            UINT32 VISION1_ISP_ERR                                                        : 1;      /* [   27]  */
            UINT32 VISION1_VDMA_CNN_ERR                                                   : 1;      /* [   28]  */
            UINT32 VISION1_VDMA_CODA_ERR                                                  : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VISION10__FT__MASK;
    union { /* 0x12104 [Excel Line :2512]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__FT__IRQ                                                      : 30;     /* [ 29:0]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VISION10__FT__IRQ;
    union { /* 0x12108 [Excel Line :2514]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__FT__CLR                                                      : 30;     /* [ 29:0]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VISION10__FT__CLR;
    union { /* 0x1210C [Excel Line :2516]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__FT__STAT                                                     : 30;     /* [ 29:0]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }VISION10__FT__STAT;

    UINT8 EMPTY140[240]; /* 0xF0 */

    /* GROUP Start : SE_VISION10__CLKMONI__CTRL */
    struct { /* 0x12200 [Excel Line :2518]  */
        union { /* 0x12200 [Excel Line :2518]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }VISION10__CLKMONI__CTRL;
    union { /* 0x12204 [Excel Line :2525]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__CLKMONI__CAP_CNT_MIN                                         : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION10__CLKMONI__CAP_CNT_MIN;
    union { /* 0x12208 [Excel Line :2526]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__CLKMONI__CAP_CNT_MAX                                         : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION10__CLKMONI__CAP_CNT_MAX;
    union { /* 0x1220C [Excel Line :2527]  */
        UINT32 Reg;
        struct {
            UINT32 VISION10__CLKMONI__CAP_CNT_VAL                                         : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }VISION10__CLKMONI__CAP_CNT_VAL;
    }SE_VISION10__CLKMONI__CTRL__GROUP[20];

    UINT8 EMPTY141[192]; /* 0xC0 */

    union { /* 0x12400 [Excel Line :2718]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__CSI2_RX_RAM;

    UINT8 EMPTY142[12]; /* 0xC */

    union { /* 0x12410 [Excel Line :2723]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__CSI2_TX_RAM;

    UINT8 EMPTY143[12]; /* 0xC */

    union { /* 0x12420 [Excel Line :2728]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED3                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED2                                                              : 1;      /* [   13]  */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__IDI_TX_SYNC;

    UINT8 EMPTY144[12]; /* 0xC */

    union { /* 0x12430 [Excel Line :2733]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__IDI_RX_RAM;

    UINT8 EMPTY145[12]; /* 0xC */

    union { /* 0x12440 [Excel Line :2738]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__IDI_TX_RAM;

    UINT8 EMPTY146[12]; /* 0xC */

    union { /* 0x12450 [Excel Line :2743]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__IDI_EM_RAM;

    UINT8 EMPTY147[12]; /* 0xC */

    union { /* 0x12460 [Excel Line :2748]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_IMG_CH0_RAM;

    UINT8 EMPTY148[12]; /* 0xC */

    union { /* 0x12470 [Excel Line :2753]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_EMB_CH0_RAM;

    UINT8 EMPTY149[12]; /* 0xC */

    union { /* 0x12480 [Excel Line :2758]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_IMG_CH1_RAM;

    UINT8 EMPTY150[12]; /* 0xC */

    union { /* 0x12490 [Excel Line :2763]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_EMB_CH1_RAM;

    UINT8 EMPTY151[12]; /* 0xC */

    union { /* 0x124A0 [Excel Line :2768]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_IMG_CH2_RAM;

    UINT8 EMPTY152[12]; /* 0xC */

    union { /* 0x124B0 [Excel Line :2773]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_EMB_CH2_RAM;

    UINT8 EMPTY153[12]; /* 0xC */

    union { /* 0x124C0 [Excel Line :2778]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_IMG_CH3_RAM;

    UINT8 EMPTY154[12]; /* 0xC */

    union { /* 0x124D0 [Excel Line :2783]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAW_EMB_CH3_RAM;

    UINT8 EMPTY155[12]; /* 0xC */

    union { /* 0x124E0 [Excel Line :2788]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MDMAR_RAM;

    UINT8 EMPTY156[12]; /* 0xC */

    union { /* 0x124F0 [Excel Line :2793]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MIPI_AFIFO_L;

    UINT8 EMPTY157[12]; /* 0xC */

    union { /* 0x12500 [Excel Line :2798]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MIPI_AFIFO_M;

    UINT8 EMPTY158[12]; /* 0xC */

    union { /* 0x12510 [Excel Line :2803]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MIPI_AFIFO_S;

    UINT8 EMPTY159[12]; /* 0xC */

    union { /* 0x12520 [Excel Line :2808]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__MIPI_AFIFO_V;

    UINT8 EMPTY160[12]; /* 0xC */

    union { /* 0x12530 [Excel Line :2813]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT0;

    UINT8 EMPTY161[12]; /* 0xC */

    union { /* 0x12540 [Excel Line :2818]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT0_S0;

    UINT8 EMPTY162[12]; /* 0xC */

    union { /* 0x12550 [Excel Line :2823]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT0_S1;

    UINT8 EMPTY163[12]; /* 0xC */

    union { /* 0x12560 [Excel Line :2828]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT0_S2;

    UINT8 EMPTY164[12]; /* 0xC */

    union { /* 0x12570 [Excel Line :2833]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT1;

    UINT8 EMPTY165[12]; /* 0xC */

    union { /* 0x12580 [Excel Line :2838]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT1_S0;

    UINT8 EMPTY166[12]; /* 0xC */

    union { /* 0x12590 [Excel Line :2843]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT1_S1;

    UINT8 EMPTY167[12]; /* 0xC */

    union { /* 0x125A0 [Excel Line :2848]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT1_S2;

    UINT8 EMPTY168[12]; /* 0xC */

    union { /* 0x125B0 [Excel Line :2853]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT2;

    UINT8 EMPTY169[12]; /* 0xC */

    union { /* 0x125C0 [Excel Line :2858]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT2_S0;

    UINT8 EMPTY170[12]; /* 0xC */

    union { /* 0x125D0 [Excel Line :2863]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT2_S1;

    UINT8 EMPTY171[12]; /* 0xC */

    union { /* 0x125E0 [Excel Line :2868]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT2_S2;

    UINT8 EMPTY172[12]; /* 0xC */

    union { /* 0x125F0 [Excel Line :2873]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__ISP_AFIFO_MT3;

    UINT8 EMPTY173[12]; /* 0xC */

    union { /* 0x12600 [Excel Line :2878]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION10__ISP_LOGIC;

    UINT8 EMPTY174[12]; /* 0xC */

    union { /* 0x12610 [Excel Line :2881]  */
        UINT32 Reg;
        struct {
            UINT32 INJECT_MODE_ON                                                         : 1;      /* [    0] Fault inject mode on */
            UINT32 BIT_FLIP_SEL                                                           : 2;      /* [  2:1] Inject bit select */
            UINT32 _1TIME_WR_GO                                                            : 1;      /* [    3] ram write once */
            UINT32 _1TIME_RD_GO                                                            : 1;      /* [    4] ram read once */
            UINT32 RESERVED3                                                              : 5;      /* [  9:5]  */
            UINT32 ECC_ERR1_CLEAR                                                         : 1;      /* [   10] ECC error1single waring clear */
            UINT32 ECC_ERR2_CLEAR                                                         : 1;      /* [   11] ECC error2double error clear */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 RESERVED2                                                              : 1;      /* [   14]  */
            UINT32 FAULT_CLR                                                              : 1;      /* [   15] Fault Clear */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }VISION10__ISP_MEM;

    UINT8 EMPTY175[12]; /* 0xC */

    union { /* 0x12620 [Excel Line :2893]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }VISION10__ISP_SYNC;

    UINT8 EMPTY176[12]; /* 0xC */

    union { /* 0x12630 [Excel Line :2896]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CNN_RAM0;

    UINT8 EMPTY177[12]; /* 0xC */

    union { /* 0x12640 [Excel Line :2901]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CNN_RAM1;

    UINT8 EMPTY178[12]; /* 0xC */

    union { /* 0x12650 [Excel Line :2906]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CNN_RAM2;

    UINT8 EMPTY179[12]; /* 0xC */

    union { /* 0x12660 [Excel Line :2911]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CODA_RAM0;

    UINT8 EMPTY180[12]; /* 0xC */

    union { /* 0x12670 [Excel Line :2916]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CODA_RAM1;

    UINT8 EMPTY181[12]; /* 0xC */

    union { /* 0x12680 [Excel Line :2921]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 12;     /* [ 11:0]  */
            UINT32 I_ER_CLR                                                               : 1;      /* [   12] CRC Error Clear */
            UINT32 I_FR_EN                                                                : 1;      /* [   13] Fault injection enable */
            UINT32 CRC_EN                                                                 : 1;      /* [   14] CRC check enable */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }VISION10__VDMA_CODA_RAM2;

    UINT8 EMPTY182[2684]; /* 0xA7C */

    union { /* 0x13100 [Excel Line :2926]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_VISION1_APB                                               : 1;      /* [    0]  */
            UINT32 CLKMONI__CLK_MIPI_DMA1_APB                                             : 1;      /* [    1]  */
            UINT32 CLKMONI__CLK_MIPI_DMA1_AXI                                             : 1;      /* [    2]  */
            UINT32 CLKMONI__CLK_MIPI_IDI1_APB                                             : 1;      /* [    3]  */
            UINT32 CLKMONI__CLK_MIPI_CSI1_RX_APB                                          : 1;      /* [    4]  */
            UINT32 CLKMONI__CLK_MIPI_CSI1_TX_APB                                          : 1;      /* [    5]  */
            UINT32 CLKMONI__CLK_VDMA1_BUS_AXI                                             : 1;      /* [    6]  */
            UINT32 CLKMONI__CLK_VDMA1_CODEC_APB                                           : 1;      /* [    7]  */
            UINT32 CLKMONI__CLK_VDMA1_CODEC_AXI                                           : 1;      /* [    8]  */
            UINT32 CLKMONI__CLK_VDMA1_NPU_APB                                             : 1;      /* [    9]  */
            UINT32 CLKMONI__CLK_VDMA1_NPU_AXI                                             : 1;      /* [   10]  */
            UINT32 CLKMONI__CLK_ISP1_APB                                                  : 1;      /* [   11]  */
            UINT32 CLKMONI__CLK_ISP1_AXI                                                  : 1;      /* [   12]  */
            UINT32 CLKMONI__CLK_ISP1_BUS_AXI                                              : 1;      /* [   13]  */
            UINT32 CLKMONI__CLK_ISP1_NXLDC_AXI                                            : 1;      /* [   14]  */
            UINT32 CLKMONI__CLK_ISP1_OSG_AXI                                              : 1;      /* [   15]  */
            UINT32 CLKMONI__CLK_ISP1_S0_AXI                                               : 1;      /* [   16]  */
            UINT32 CLKMONI__CLK_ISP1_S1_AXI                                               : 1;      /* [   17]  */
            UINT32 CLKMONI__CLK_ISP1_S2_AXI                                               : 1;      /* [   18]  */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }VISION11__FT__MASK;
    union { /* 0x13104 [Excel Line :2946]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__FT__IRQ                                                      : 19;     /* [ 18:0]  */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }VISION11__FT__IRQ;
    union { /* 0x13108 [Excel Line :2948]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__FT__CLR                                                      : 19;     /* [ 18:0]  */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }VISION11__FT__CLR;
    union { /* 0x1310C [Excel Line :2950]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__FT__STAT                                                     : 19;     /* [ 18:0]  */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }VISION11__FT__STAT;

    UINT8 EMPTY183[240]; /* 0xF0 */

    /* GROUP Start : SE_VISION11__CLKMONI__CTRL */
    struct { /* 0x13200 [Excel Line :2952]  */
        union { /* 0x13200 [Excel Line :2952]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }VISION11__CLKMONI__CTRL;
    union { /* 0x13204 [Excel Line :2959]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__CLKMONI__CAP_CNT_MIN                                         : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION11__CLKMONI__CAP_CNT_MIN;
    union { /* 0x13208 [Excel Line :2960]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__CLKMONI__CAP_CNT_MAX                                         : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }VISION11__CLKMONI__CAP_CNT_MAX;
    union { /* 0x1320C [Excel Line :2961]  */
        UINT32 Reg;
        struct {
            UINT32 VISION11__CLKMONI__CAP_CNT_VAL                                         : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }VISION11__CLKMONI__CAP_CNT_VAL;
    }SE_VISION11__CLKMONI__CTRL__GROUP[19];

    UINT8 EMPTY184[3536]; /* 0xDD0 */

    union { /* 0x14100 [Excel Line :3142]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMONI__CLK_SCU_PLL0                                                  : 1;      /* [    0] SYS_PLL fout4 */
            UINT32 CLKMONI__CLK_SCU_PLL1                                                  : 1;      /* [    1] CPU_PLL fout4 */
            UINT32 CLKMONI__CLK_SCU_PLL2                                                  : 1;      /* [    2] NPU_PLL fout4 */
            UINT32 CLKMONI__CLK_SCU_PLL3                                                  : 1;      /* [    3] COM_PLL fout4 */
            UINT32 CLKMONI__CLK_SCU_PLL4                                                  : 1;      /* [    4] VISION0_PLL fout4 */
            UINT32 CLKMONI__CLK_SCU_PLL5                                                  : 1;      /* [    5] VISION1_PLL fout4 */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }SYSSCU__FT__MASK;
    union { /* 0x14104 [Excel Line :3149]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__FT__IRQ                                                        : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }SYSSCU__FT__IRQ;
    union { /* 0x14108 [Excel Line :3151]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__FT__CLR                                                        : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }SYSSCU__FT__CLR;
    union { /* 0x1410C [Excel Line :3153]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__FT__STAT                                                       : 6;      /* [  5:0]  */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }SYSSCU__FT__STAT;

    UINT8 EMPTY185[240]; /* 0xF0 */

    /* GROUP Start : SE_SYSSCU__CLKMONI__CTRL */
    struct { /* 0x14200 [Excel Line :3155]  */
        union { /* 0x14200 [Excel Line :3155]  */
        UINT32 Reg;
        struct {
            UINT32 CAP_EN                                                                 : 1;      /* [    0] Clock monitor enable */
            UINT32 RESERVED2                                                              : 1;      /* [    1]  */
            UINT32 FT_IN                                                                  : 1;      /* [    2] Fault injection enable */
            UINT32 RESERVED1                                                              : 1;      /* [    3]  */
            UINT32 CNT_MODE                                                               : 1;      /* [    4] Clock Freq Counter type
                                                                                                               0  real time count value
                                                                                                               1  Count value when error occurs */
            UINT32 CNT_STATE                                                              : 3;      /* [  7:5] Monitor State
                                                                                                               0  IDLE
                                                                                                               1  Reset
                                                                                                               2  Monitor Clock Enable
                                                                                                               3  Run
                                                                                                               4  Compare
                                                                                                               5  Wait */
            UINT32 CAP_TIME                                                               : 24;     /* [ 31:8] External Clock nsCAPTURE TIME unit time ns */
        }Bit;
    }SYSSCU__CLKMONI__CTRL;
    union { /* 0x14204 [Excel Line :3162]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__CLKMONI__CAP_CNT_MIN                                           : 32;     /* [ 31:0] subtraction monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SYSSCU__CLKMONI__CAP_CNT_MIN;
    union { /* 0x14208 [Excel Line :3163]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__CLKMONI__CAP_CNT_MAX                                           : 32;     /* [ 31:0] Add monitoring clock  CAPTURE_TIME  01 */
        }Bit;
    }SYSSCU__CLKMONI__CAP_CNT_MAX;
    union { /* 0x1420C [Excel Line :3164]  */
        UINT32 Reg;
        struct {
            UINT32 SYSSCU__CLKMONI__CAP_CNT_VAL                                           : 32;     /* [ 31:0] Clock Freq Counter value */
        }Bit;
    }SYSSCU__CLKMONI__CAP_CNT_VAL;
    }SE_SYSSCU__CLKMONI__CTRL__GROUP[6];

    UINT8 EMPTY186[3488]; /* 0xDA0 */

    union { /* 0x15000 [Excel Line :3215]  */
        UINT32 Reg;
        struct {
            UINT32 EN                                                                     : 1;      /* [    0] Safe engine enable */
            UINT32 SAFE_OE                                                                : 1;      /* [    1] safe state outup enable */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }SE__MODE;
    union { /* 0x15004 [Excel Line :3218]  */
        UINT32 Reg;
        struct {
            UINT32 ENDOFBOOTUP                                                            : 1;      /* [    0] start-up mode to standard operation mode */
            UINT32 POTENTIAL_FAILURE                                                      : 1;      /* [    1] potential failure mode to standard operation mode */
            UINT32 STANDARD_OP                                                            : 1;      /* [    2] standard operation mode to potential failure mode */
            UINT32 SAFE_MODE_STARTUP                                                      : 1;      /* [    3] TODO hidden funciton */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }SE__OP_CTRL;
    union { /* 0x15008 [Excel Line :3223]  */
        UINT32 Reg;
        struct {
            UINT32 OP_CURR                                                                : 3;      /* [  2:0] current operation status
                                                                                                               000 RESET MODE
                                                                                                               001 STARTUP MODE
                                                                                                               010 STANDARD OPERATION MODE
                                                                                                               100 POTENTIAL MODE
                                                                                                               101 SAFE MODE */
            UINT32 RESERVED4                                                              : 1;      /* [    3]  */
            UINT32 OP_HIST0                                                               : 3;      /* [  6:4] operation history 0 */
            UINT32 RESERVED3                                                              : 1;      /* [    7]  */
            UINT32 OP_HIST1                                                               : 3;      /* [ 10:8] operation history 1 */
            UINT32 RESERVED2                                                              : 1;      /* [   11]  */
            UINT32 OP_HIST2                                                               : 3;      /* [14:12] operation history 2 */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }SE__OP_STAT;
    union { /* 0x1500C [Excel Line :3231]  */
        UINT32 Reg;
        struct {
            UINT32 IRQ                                                                    : 1;      /* [    0] Interrupt Mask active low */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 VSEI                                                                   : 4;      /* [  7:4] System Error Interrupt Mask active high */
            UINT32 SEI                                                                    : 4;      /* [ 11:8] Virtural System Error Interrupt Mask active high */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }SE__IRQ_MASK;
    union { /* 0x15010 [Excel Line :3236]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 1;      /* [    0]  */
            UINT32 SLV_ID                                                                 : 7;      /* [  7:1] Slave I2C Device ID */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SE__I2C;
    union { /* 0x15014 [Excel Line :3239]  */
        UINT32 Reg;
        struct {
            UINT32 I2C_SLAVE_RESET                                                        : 1;      /* [    0] I2C slave reset */
            UINT32 I2C_SLAVE_AUTO_RESET                                                   : 1;      /* [    1] I2C slave auto-reset enable */
            UINT32 RESERVED1                                                              : 6;      /* [  7:2]  */
            UINT32 I2C_RESET_CNT                                                          : 24;     /* [ 31:8] I2C slave auto-reset counter */
        }Bit;
    }SE__I2C_MODE;

    UINT8 EMPTY187[8]; /* 0x8 */

    union { /* 0x15020 [Excel Line :3243]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG00                                                              : 32;     /* [ 31:0] debug register 00 */
        }Bit;
    }SE__DBG00;
    union { /* 0x15024 [Excel Line :3244]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG01                                                              : 32;     /* [ 31:0] debug register 01 */
        }Bit;
    }SE__DBG01;
    union { /* 0x15028 [Excel Line :3245]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG02                                                              : 32;     /* [ 31:0] debug register 02 */
        }Bit;
    }SE__DBG02;
    union { /* 0x1502C [Excel Line :3246]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG03                                                              : 32;     /* [ 31:0] debug register 03 */
        }Bit;
    }SE__DBG03;
    union { /* 0x15030 [Excel Line :3247]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG04                                                              : 32;     /* [ 31:0] debug register 04 */
        }Bit;
    }SE__DBG04;
    union { /* 0x15034 [Excel Line :3248]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG05                                                              : 32;     /* [ 31:0] debug register 05 */
        }Bit;
    }SE__DBG05;
    union { /* 0x15038 [Excel Line :3249]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG06                                                              : 32;     /* [ 31:0] debug register 06 */
        }Bit;
    }SE__DBG06;
    union { /* 0x1503C [Excel Line :3250]  */
        UINT32 Reg;
        struct {
            UINT32 SE__DBG07                                                              : 32;     /* [ 31:0] debug register 07 */
        }Bit;
    }SE__DBG07;
    union { /* 0x15040 [Excel Line :3251]  */
        UINT32 Reg;
        struct {
            UINT32 CNT                                                                    : 4;      /* [  3:0] when unintend reset re-try reset sequence  */
            UINT32 CURR_CNT                                                               : 4;      /* [  7:4] unintend re-try count */
            UINT32 CLR                                                                    : 1;      /* [    8] unintend re-try count clear */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }SE__UNINTEND_RST;

    UINT8 EMPTY188[172]; /* 0xAC */

    union { /* 0x150F0 [Excel Line :3255]  */
        UINT32 Reg;
        struct {
            UINT32 ERR                                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }SE__SW__SAFETY;

    UINT8 EMPTY189[12]; /* 0xC */

    /* GROUP Start : SE__FT__MASK */
    union { /* 0x15100 [Excel Line :3256]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_SECLK                                                              : 1;      /* [    0] safety apb clock monitor  SW fault mask enable */
            UINT32 BLK_GIC                                                                : 1;      /* [    1] BLK_GIC HW fault mask enable */
            UINT32 BLK_SECURE                                                             : 1;      /* [    2] BLK_SECURE HW fault mask enable */
            UINT32 BLK_HSP                                                                : 1;      /* [    3] BLK_HSP HW fault mask enable */
            UINT32 BLK_PERI                                                               : 1;      /* [    4] BLK_PERI HW fault mask enable */
            UINT32 BLK_ANALOG                                                             : 1;      /* [    5] BLK_ANALOG HW fault mask enable */
            UINT32 BLK_VISION00                                                           : 1;      /* [    6] BLK_VISION00 HW fault mask enable */
            UINT32 BLK_VISION01                                                           : 1;      /* [    7] BLK_VISION01 HW fault mask enable */
            UINT32 BLK_BUS                                                                : 1;      /* [    8] BLK_BUS HW fault mask enable */
            UINT32 BLK_CPU                                                                : 1;      /* [    9] BLK_CPU HW fault mask enable */
            UINT32 BLK_NPU                                                                : 1;      /* [   10] BLK_NPU HW fault mask enable */
            UINT32 BLK_HWA                                                                : 1;      /* [   11] BLK_HWA HW fault mask enable */
            UINT32 BLK_DDR0                                                               : 1;      /* [   12] BLK_DDR0 HW fault mask enable */
            UINT32 BLK_DDR1                                                               : 1;      /* [   13] BLK_DDR1 HW fault mask enable */
            UINT32 BLK_MEM                                                                : 1;      /* [   14] BLK_MEM HW fault mask enable */
            UINT32 BLK_PCIE                                                               : 1;      /* [   15] BLK_PCIE HW fault mask enable */
            UINT32 BLK_USB                                                                : 1;      /* [   16] BLK_USB HW fault mask enable */
            UINT32 BLK_GPU                                                                : 1;      /* [   17] BLK_GPU HW fault mask enable */
            UINT32 BLK_VISION10                                                           : 1;      /* [   18] BLK_VISION10 HW fault mask enable */
            UINT32 BLK_VISION11                                                           : 1;      /* [   19] BLK_VISION11 HW fault mask enable */
            UINT32 BLK_SYS_SCU                                                            : 1;      /* [   20] BLK_SYS_SCU HW fault mask enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__MASK;
    union { /* 0x15104 [Excel Line :3278]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__IRQ                                                            : 21;     /* [ 20:0] HW fault interrupt enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__IRQ;
    union { /* 0x15108 [Excel Line :3280]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__CLR                                                            : 21;     /* [ 20:0] HW fault clear */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__CLR;
    union { /* 0x1510C [Excel Line :3282]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__STAT                                                           : 21;     /* [ 20:0] HW fault status */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__STAT;

    UINT8 EMPTY190[4080]; /* 0xFF0 */
/*------------------------------------------- */
    union { /* 0x16100 [Excel Line :3256]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__MASK                                                           : 32;     /* [ 31:0] SW fault interrupt enable */
        }Bit;
    }SE__SW__FT__MASK;
    union { /* 0x16104 [Excel Line :3278]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__IRQ                                                            : 32;     /* [ 31:0] SW fault interrupt enable */
        }Bit;
    }SE__SW__FT__IRQ;
    union { /* 0x16108 [Excel Line :3280]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__CLR                                                            : 32;     /* [ 31:0] SW fault clear */
        }Bit;
    }SE__SW__FT__CLR;
    union { /* 0x1610C [Excel Line :3282]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__STAT                                                           : 32;     /* [ 31:0] SW fault status */
        }Bit;

    }SE__SW__FT__STAT;
}DRV_A6_SE_REGISTER;
/*PRQA S 828 -- */


#if 0  /* start */
    /* GROUP Start : SE__FT__MASK */
    union { /* 0x15100 [Excel Line :3256]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_SECLK                                                              : 1;      /* [    0] safety apb clock monitor  SW fault mask enable */
            UINT32 BLK_GIC                                                                : 1;      /* [    1] BLK_GIC HW fault mask enable */
            UINT32 BLK_SECURE                                                             : 1;      /* [    2] BLK_SECURE HW fault mask enable */
            UINT32 BLK_HSP                                                                : 1;      /* [    3] BLK_HSP HW fault mask enable */
            UINT32 BLK_PERI                                                               : 1;      /* [    4] BLK_PERI HW fault mask enable */
            UINT32 BLK_ANALOG                                                             : 1;      /* [    5] BLK_ANALOG HW fault mask enable */
            UINT32 BLK_VISION00                                                           : 1;      /* [    6] BLK_VISION00 HW fault mask enable */
            UINT32 BLK_VISION01                                                           : 1;      /* [    7] BLK_VISION01 HW fault mask enable */
            UINT32 BLK_BUS                                                                : 1;      /* [    8] BLK_BUS HW fault mask enable */
            UINT32 BLK_CPU                                                                : 1;      /* [    9] BLK_CPU HW fault mask enable */
            UINT32 BLK_NPU                                                                : 1;      /* [   10] BLK_NPU HW fault mask enable */
            UINT32 BLK_HWA                                                                : 1;      /* [   11] BLK_HWA HW fault mask enable */
            UINT32 BLK_DDR0                                                               : 1;      /* [   12] BLK_DDR0 HW fault mask enable */
            UINT32 BLK_DDR1                                                               : 1;      /* [   13] BLK_DDR1 HW fault mask enable */
            UINT32 BLK_MEM                                                                : 1;      /* [   14] BLK_MEM HW fault mask enable */
            UINT32 BLK_PCIE                                                               : 1;      /* [   15] BLK_PCIE HW fault mask enable */
            UINT32 BLK_USB                                                                : 1;      /* [   16] BLK_USB HW fault mask enable */
            UINT32 BLK_GPU                                                                : 1;      /* [   17] BLK_GPU HW fault mask enable */
            UINT32 BLK_VISION10                                                           : 1;      /* [   18] BLK_VISION10 HW fault mask enable */
            UINT32 BLK_VISION11                                                           : 1;      /* [   19] BLK_VISION11 HW fault mask enable */
            UINT32 BLK_SYS_SCU                                                            : 1;      /* [   20] BLK_SYS_SCU HW fault mask enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__MASK;
    union { /* 0x15104 [Excel Line :3278]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__IRQ                                                            : 21;     /* [ 20:0] HW fault interrupt enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__IRQ;
    union { /* 0x15108 [Excel Line :3280]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__CLR                                                            : 21;     /* [ 20:0] HW fault clear */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__CLR;
    union { /* 0x1510C [Excel Line :3282]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__STAT                                                           : 21;     /* [ 20:0] HW fault status */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__HW__FT__STAT;

-------------------------------------------
    union { /* 0x15100 [Excel Line :3256]  */
        UINT32 Reg;
        struct {
            UINT32 BLK_SECLK                                                              : 1;      /* [    0] safety apb clock monitor  SW fault mask enable */
            UINT32 BLK_GIC                                                                : 1;      /* [    1] BLK_GIC HW fault mask enable */
            UINT32 BLK_SECURE                                                             : 1;      /* [    2] BLK_SECURE HW fault mask enable */
            UINT32 BLK_HSP                                                                : 1;      /* [    3] BLK_HSP HW fault mask enable */
            UINT32 BLK_PERI                                                               : 1;      /* [    4] BLK_PERI HW fault mask enable */
            UINT32 BLK_ANALOG                                                             : 1;      /* [    5] BLK_ANALOG HW fault mask enable */
            UINT32 BLK_VISION00                                                           : 1;      /* [    6] BLK_VISION00 HW fault mask enable */
            UINT32 BLK_VISION01                                                           : 1;      /* [    7] BLK_VISION01 HW fault mask enable */
            UINT32 BLK_BUS                                                                : 1;      /* [    8] BLK_BUS HW fault mask enable */
            UINT32 BLK_CPU                                                                : 1;      /* [    9] BLK_CPU HW fault mask enable */
            UINT32 BLK_NPU                                                                : 1;      /* [   10] BLK_NPU HW fault mask enable */
            UINT32 BLK_HWA                                                                : 1;      /* [   11] BLK_HWA HW fault mask enable */
            UINT32 BLK_DDR0                                                               : 1;      /* [   12] BLK_DDR0 HW fault mask enable */
            UINT32 BLK_DDR1                                                               : 1;      /* [   13] BLK_DDR1 HW fault mask enable */
            UINT32 BLK_MEM                                                                : 1;      /* [   14] BLK_MEM HW fault mask enable */
            UINT32 BLK_PCIE                                                               : 1;      /* [   15] BLK_PCIE HW fault mask enable */
            UINT32 BLK_USB                                                                : 1;      /* [   16] BLK_USB HW fault mask enable */
            UINT32 BLK_GPU                                                                : 1;      /* [   17] BLK_GPU HW fault mask enable */
            UINT32 BLK_VISION10                                                           : 1;      /* [   18] BLK_VISION10 HW fault mask enable */
            UINT32 BLK_VISION11                                                           : 1;      /* [   19] BLK_VISION11 HW fault mask enable */
            UINT32 BLK_SYS_SCU                                                            : 1;      /* [   20] BLK_SYS_SCU HW fault mask enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__SW__FT__MASK;
    union { /* 0x15104 [Excel Line :3278]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__IRQ                                                            : 21;     /* [ 20:0] HW fault interrupt enable */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__SW__FT__IRQ;
    union { /* 0x15108 [Excel Line :3280]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__CLR                                                            : 21;     /* [ 20:0] HW fault clear */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;
    }SE__SW__FT__CLR;
    union { /* 0x1510C [Excel Line :3282]  */
        UINT32 Reg;
        struct {
            UINT32 SE__FT__STAT                                                           : 21;     /* [ 20:0] HW fault status */
            UINT32 RESERVED1                                                              : 11;     /* [31:21]  */
        }Bit;

    }SE__SW__FT__STAT;
}DRV_A6_SE_REGISTER;
#endif /* end */



/*__________________ REGISTER GROUP DEFINE SET_____________________*/

 /* GROUP IDX : SECLK__CLKMONI__CTRL */
#define SECLK__CLKMONI__CTRL_CLK_APB                                                    0
#define SECLK__CLKMONI__CTRL_MAX                1

 /* GROUP IDX : SE_GIC__CLKMONI__CTRL */
#define SE_GIC__CLKMONI__CTRL_CLK_GIC_R5_AXI                                            0
#define SE_GIC__CLKMONI__CTRL_CLK_GIC_A65                                               1
#define SE_GIC__CLKMONI__CTRL_CLK_GIC_A65_FDC                                           2
#define SE_GIC__CLKMONI__CTRL_MAX               3

 /* GROUP IDX : SECURE__CLKMONI__CTRL */
#define SECURE__CLKMONI__CTRL_CLK_RT640                                                 0
#define SECURE__CLKMONI__CTRL_CLK_EIP97                                                 1
#define SECURE__CLKMONI__CTRL_MAX               2

 /* GROUP IDX : SE_HSP__CLKMONI__CTRL */
#define SE_HSP__CLKMONI__CTRL_CLK_EQOS_PTP                                              0
#define SE_HSP__CLKMONI__CTRL_CLK_EQOS_RMII                                             1
#define SE_HSP__CLKMONI__CTRL_CLK_EQOS_RGMII                                            2
#define SE_HSP__CLKMONI__CTRL_CLK_SDC_CARD                                              3
#define SE_HSP__CLKMONI__CTRL_CLK_SDC_CORE                                              4
#define SE_HSP__CLKMONI__CTRL_CLK_EMMC_CARD                                             5
#define SE_HSP__CLKMONI__CTRL_CLK_EMMC_CORE                                             6
#define SE_HSP__CLKMONI__CTRL_MAX               7

 /* GROUP IDX : SE_PERI__ECC_CTRL */
#define SE_PERI__ECC_CTRL_CAN0                                                          0
#define SE_PERI__ECC_CTRL_CAN1                                                          1
#define SE_PERI__ECC_CTRL_MAX                   2

 /* GROUP IDX : SE_PERI__FT__MASK */
#define SE_PERI__FT__MASK_PERI0                                                         0
#define SE_PERI__FT__MASK_MAX                   1

 /* GROUP IDX : SE_PERI__CLKMONI__CTRL */
#define SE_PERI__CLKMONI__CTRL_CLK_SPI_CORE                                             0
#define SE_PERI__CLKMONI__CTRL_CLK_I2C_CORE                                             1
#define SE_PERI__CLKMONI__CTRL_CLK_UART_CORE                                            2
#define SE_PERI__CLKMONI__CTRL_CLK_PWM_CORE                                             3
#define SE_PERI__CLKMONI__CTRL_CLK_LIN_CORE                                             4
#define SE_PERI__CLKMONI__CTRL_CLK_CAN_CORE                                             5
#define SE_PERI__CLKMONI__CTRL_CLK_DMA_AXI                                              6
#define SE_PERI__CLKMONI__CTRL_CLK_PWM_APB                                              7
#define SE_PERI__CLKMONI__CTRL_CLK_QSPI_CORE                                            8
#define SE_PERI__CLKMONI__CTRL_MAX              9

 /* GROUP IDX : SE_ANALOG__CLKMONI__CTRL */
#define SE_ANALOG__CLKMONI__CTRL_CLK_ANALOG_APB                                         0
#define SE_ANALOG__CLKMONI__CTRL_CLK_ADC_CORE                                           1
#define SE_ANALOG__CLKMONI__CTRL_CLK_PVT_CORE                                           2
#define SE_ANALOG__CLKMONI__CTRL_CLK_VLD_CORE                                           3
#define SE_ANALOG__CLKMONI__CTRL_CLK_OTP_CORE                                           4
#define SE_ANALOG__CLKMONI__CTRL_CLK_OTP_SEC                                            5
#define SE_ANALOG__CLKMONI__CTRL_MAX            6

 /* GROUP IDX : SE_VISION00__CLKMONI__CTRL */
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_MIPI_DMA_SEN                             0
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_MIPI_RX_IDI_IN                           1
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_MIPI_RX_IDI_OUT                          2
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_MIPI_TX_IDI_IN                           3
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_MIPI_TX_IDI_OUT                          4
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_CODEC                               5
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_DIG                                 6
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_FRC                                 7
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_ISP                                 8
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_NPU                                 9
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_NXLDC                               10
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S0_FRC                              11
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S0_ISP                              12
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S0_NXLDC                            13
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S1_FRC                              14
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S1_ISP                              15
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S1_NXLDC                            16
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S2_FRC                              17
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S2_ISP                              18
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_S2_NXLDC                            19
#define SE_VISION00__CLKMONI__CTRL_CLK_VISION0_VCLK_ADAS                                20
#define SE_VISION00__CLKMONI__CTRL_MAX          21

 /* GROUP IDX : SE_VISION01__CLKMONI__CTRL */
#define SE_VISION01__CLKMONI__CTRL_CLK_VISION0_APB                                      0
#define SE_VISION01__CLKMONI__CTRL_CLK_MIPI_DMA0_APB                                    1
#define SE_VISION01__CLKMONI__CTRL_CLK_MIPI_DMA0_AXI                                    2
#define SE_VISION01__CLKMONI__CTRL_CLK_MIPI_IDI0_APB                                    3
#define SE_VISION01__CLKMONI__CTRL_CLK_MIPI_CSI0_RX_APB                                 4
#define SE_VISION01__CLKMONI__CTRL_CLK_MIPI_CSI0_TX_APB                                 5
#define SE_VISION01__CLKMONI__CTRL_CLK_VDMA0_BUS_AXI                                    6
#define SE_VISION01__CLKMONI__CTRL_CLK_VDMA0_CODEC_APB                                  7
#define SE_VISION01__CLKMONI__CTRL_CLK_VDMA0_CODEC_AXI                                  8
#define SE_VISION01__CLKMONI__CTRL_CLK_VDMA0_NPU_APB                                    9
#define SE_VISION01__CLKMONI__CTRL_CLK_VDMA0_NPU_AXI                                    10
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_APB                                         11
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_AXI                                         12
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_BUS_AXI                                     13
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_NXLDC_AXI                                   14
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_OSG_AXI                                     15
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_S0_AXI                                      16
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_S1_AXI                                      17
#define SE_VISION01__CLKMONI__CTRL_CLK_ISP0_S2_AXI                                      18
#define SE_VISION01__CLKMONI__CTRL_CLK_ADAS_APB                                         19
#define SE_VISION01__CLKMONI__CTRL_CLK_ADAS_AXI                                         20
#define SE_VISION01__CLKMONI__CTRL_MAX          21

 /* GROUP IDX : SE_BUS__CLKMONI__CTRL */
#define SE_BUS__CLKMONI__CTRL_LDA_TX_CLK_TO_AIW                                         0
#define SE_BUS__CLKMONI__CTRL_LDA_TX_CLK_TO_CODA                                        1
#define SE_BUS__CLKMONI__CTRL_LDA_TX_CLK_TO_ISP                                         2
#define SE_BUS__CLKMONI__CTRL_LDA_TX_CLK_TO_DDR                                         3
#define SE_BUS__CLKMONI__CTRL_LDA_RX_CLK_FROM_AIW                                       4
#define SE_BUS__CLKMONI__CTRL_LDA_RX_CLK_FROM_CODA                                      5
#define SE_BUS__CLKMONI__CTRL_LDA_RX_CLK_FROM_ISP                                       6
#define SE_BUS__CLKMONI__CTRL_LDA_RX_CLK_FROM_CPU                                       7
#define SE_BUS__CLKMONI__CTRL_CLK_OIC                                                   8
#define SE_BUS__CLKMONI__CTRL_CLK_OIC_CR                                                9
#define SE_BUS__CLKMONI__CTRL_MAX               10

 /* GROUP IDX : SE_CPU__CLKMONI__CTRL */
#define SE_CPU__CLKMONI__CTRL_CLK_CPU_A65_SCLK                                          0
#define SE_CPU__CLKMONI__CTRL_CLK_CPU_A65_ATB                                           1
#define SE_CPU__CLKMONI__CTRL_CLK_CPU_R5_CLKIN                                          2
#define SE_CPU__CLKMONI__CTRL_CLK_CPU_A65_GIC                                           3
#define SE_CPU__CLKMONI__CTRL_MAX               4

 /* GROUP IDX : SE_NPU__CLKMONI__CTRL */
#define SE_NPU__CLKMONI__CTRL_CLK_NPU_AXI                                               0
#define SE_NPU__CLKMONI__CTRL_CLK_NPU_CORE                                              1
#define SE_NPU__CLKMONI__CTRL_CKL_NPU_NNU_0                                             2
#define SE_NPU__CLKMONI__CTRL_CKL_NPU_NNU_1                                             3
#define SE_NPU__CLKMONI__CTRL_CKL_NPU_NNU_2                                             4
#define SE_NPU__CLKMONI__CTRL_CKL_NPU_WFRAM_0                                           5
#define SE_NPU__CLKMONI__CTRL_CKL_NPU_WFRAM_1                                           6
#define SE_NPU__CLKMONI__CTRL_MAX               7

 /* GROUP IDX : SE_HWA__CLKMONI__CTRL */
#define SE_HWA__CLKMONI__CTRL_CLK_H265_CORE                                             0
#define SE_HWA__CLKMONI__CTRL_CLK_H265_AXI                                              1
#define SE_HWA__CLKMONI__CTRL_CLK_H265_BPU                                              2
#define SE_HWA__CLKMONI__CTRL_CLK_DS_AXI                                                3
#define SE_HWA__CLKMONI__CTRL_CLK_DS_APB                                                4
#define SE_HWA__CLKMONI__CTRL_CLK_ROT_AXI                                               5
#define SE_HWA__CLKMONI__CTRL_CLK_ROT_APB                                               6
#define SE_HWA__CLKMONI__CTRL_MAX               7

 /* GROUP IDX : SE_DDR0__CLKMONI__CTRL */
#define SE_DDR0__CLKMONI__CTRL_CLK_DDR0_PHY_DFI                                         0
#define SE_DDR0__CLKMONI__CTRL_CLK_DDR0_PHY_OSC                                         1
#define SE_DDR0__CLKMONI__CTRL_CLK_DDRC0_APB                                            2
#define SE_DDR0__CLKMONI__CTRL_MAX              3

 /* GROUP IDX : SE_DDR1__CLKMONI__CTRL */
#define SE_DDR1__CLKMONI__CTRL_CLK_DDR1_PHY_DFI                                         0
#define SE_DDR1__CLKMONI__CTRL_CLK_DDR1_PHY_OSC                                         1
#define SE_DDR1__CLKMONI__CTRL_CLK_DDRC1_APB                                            2
#define SE_DDR1__CLKMONI__CTRL_CLK_DDRC1_LDA                                            3
#define SE_DDR1__CLKMONI__CTRL_MAX              4

 /* GROUP IDX : SE_MEM__CLKMONI__CTRL */
#define SE_MEM__CLKMONI__CTRL_CLK_RAM                                                   0
#define SE_MEM__CLKMONI__CTRL_CLK_ROM                                                   1
#define SE_MEM__CLKMONI__CTRL_MAX               2

 /* GROUP IDX : SE_PCIE__CLKMONI__CTRL */
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE0_AXI                                            0
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE0_DBI                                            1
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE0_AUX                                            2
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE0_CORE                                           3
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE1_AXI                                            4
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE1_DBI                                            5
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE1_AUX                                            6
#define SE_PCIE__CLKMONI__CTRL_CLK_PCIE1_CORE                                           7
#define SE_PCIE__CLKMONI__CTRL_MAX              8

 /* GROUP IDX : SE_USB__CLKMONI__CTRL */
#define SE_USB__CLKMONI__CTRL_CLK_USB_CORE                                              0
#define SE_USB__CLKMONI__CTRL_CLK_USB_APB                                               1
#define SE_USB__CLKMONI__CTRL_CLK_USB_SAFETY                                            2
#define SE_USB__CLKMONI__CTRL_CLK_USB_SUSPEND                                           3
#define SE_USB__CLKMONI__CTRL_CLK_USB_REFCLK                                            4
#define SE_USB__CLKMONI__CTRL_MAX               5

 /* GROUP IDX : SE_GPU__CLKMONI__CTRL */
#define SE_GPU__CLKMONI__CTRL_CLK_GPU_AXI                                               0
#define SE_GPU__CLKMONI__CTRL_CLK_GPU_AXI_FDC                                           1
#define SE_GPU__CLKMONI__CTRL_CLK_GPU_MMU_AXI                                           2
#define SE_GPU__CLKMONI__CTRL_CLK_GPU_MMU_AXI_FDC                                       3
#define SE_GPU__CLKMONI__CTRL_CLK_GPU_SCU_APB                                           4
#define SE_GPU__CLKMONI__CTRL_MAX               5

 /* GROUP IDX : SE_VISION10__CLKMONI__CTRL */
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_MIPI_DMA_SEN                             0
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_MIPI_RX_IDI_IN                           1
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_MIPI_RX_IDI_OUT                          2
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_MIPI_TX_IDI_IN                           3
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_MIPI_TX_IDI_OUT                          4
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_CODEC                               5
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_DIG                                 6
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_FRC                                 7
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_ISP                                 8
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_NPU                                 9
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_NXLDC                               10
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S0_FRC                              11
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S0_ISP                              12
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S0_NXLDC                            13
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S1_FRC                              14
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S1_ISP                              15
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S1_NXLDC                            16
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S2_FRC                              17
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S2_ISP                              18
#define SE_VISION10__CLKMONI__CTRL_CLK_VISION1_VCLK_S2_NXLDC                            19
#define SE_VISION10__CLKMONI__CTRL_MAX          20

 /* GROUP IDX : SE_VISION11__CLKMONI__CTRL */
#define SE_VISION11__CLKMONI__CTRL_CLK_VISION1_APB                                      0
#define SE_VISION11__CLKMONI__CTRL_CLK_MIPI_DMA1_APB                                    1
#define SE_VISION11__CLKMONI__CTRL_CLK_MIPI_DMA1_AXI                                    2
#define SE_VISION11__CLKMONI__CTRL_CLK_MIPI_IDI1_APB                                    3
#define SE_VISION11__CLKMONI__CTRL_CLK_MIPI_CSI1_RX_APB                                 4
#define SE_VISION11__CLKMONI__CTRL_CLK_MIPI_CSI1_TX_APB                                 5
#define SE_VISION11__CLKMONI__CTRL_CLK_VDMA1_BUS_AXI                                    6
#define SE_VISION11__CLKMONI__CTRL_CLK_VDMA1_CODEC_APB                                  7
#define SE_VISION11__CLKMONI__CTRL_CLK_VDMA1_CODEC_AXI                                  8
#define SE_VISION11__CLKMONI__CTRL_CLK_VDMA1_NPU_APB                                    9
#define SE_VISION11__CLKMONI__CTRL_CLK_VDMA1_NPU_AXI                                    10
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_APB                                         11
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_AXI                                         12
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_BUS_AXI                                     13
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_NXLDC_AXI                                   14
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_OSG_AXI                                     15
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_S0_AXI                                      16
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_S1_AXI                                      17
#define SE_VISION11__CLKMONI__CTRL_CLK_ISP1_S2_AXI                                      18
#define SE_VISION11__CLKMONI__CTRL_MAX          19

 /* GROUP IDX : SE_SYSSCU__CLKMONI__CTRL */
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL0                                           0
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL1                                           1
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL2                                           2
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL3                                           3
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL4                                           4
#define SE_SYSSCU__CLKMONI__CTRL_CLK_SCU_PLL5                                           5
#define SE_SYSSCU__CLKMONI__CTRL_MAX            6

 /* GROUP IDX : SE__FT__MASK */
#define SE__FT__MASK_HW                                                                 0
#define SE__FT__MASK_SW                                                                 1
#define SE__FT__MASK_MAX                        2

/*
 static volatile DRV_A6_SE_REGISTER* const RegA6_SE = (DRV_A6_SE_REGISTER*)APACHE_A6_SE_BASE_ADDR;
 */

/* PRQA S 0791 -- */
/* PRQA S 0779 -- */


#endif /* end of  DRV_REGISTER_A6_SE__ */

