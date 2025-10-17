
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Platform   : APACHE6
*   File       : DRV_A6_OTP2K_Register.h
*   Date       : 2022-07-27 11:55
*
*   THIS CODE WAS GENERATED FROM THE APACHE6 HSI DOCUMENTATION. PLEASE DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_OTP2K_H__
#define DRV_REGISTER_A6_OTP2K_H__

#define APACHE_A6_OTP2K_BASE_ADDR        0x05C2C000

/* PRQA S 828 ++ */
typedef struct
{

    UINT8 EMPTY1[512]; /* 0x200 */

    union { /* 0x200 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 CHIP_ID_0                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }CHIP_ID_0;
    union { /* 0x204 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 CHIP_ID_1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }CHIP_ID_1;
    union { /* 0x208 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 CHIP_ID_2                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }CHIP_ID_2;
    union { /* 0x20C [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 IDS                                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }IDS;
    union { /* 0x210 [Excel Line :0012]  */
        UINT32 Reg;
        struct {
            UINT32 VLD_CAL_0                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }VLD_CAL_0;
    union { /* 0x214 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_0                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_0;
    union { /* 0x218 [Excel Line :0014]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_1;
    union { /* 0x21C [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_2                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_2;
    union { /* 0x220 [Excel Line :0016]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_3                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_3;
    union { /* 0x224 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_4                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_4;
    union { /* 0x228 [Excel Line :0018]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_5                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_5;
    union { /* 0x22C [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_6                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_6;
    union { /* 0x230 [Excel Line :0020]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_7                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_7;
    union { /* 0x234 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 PVT_CAL_8                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }PVT_CAL_8;
    union { /* 0x238 [Excel Line :0022]  */
        UINT32 Reg;
        struct {
            UINT32 PROC_CAL                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }PROC_CAL;

    UINT8 EMPTY2[4]; /* 0x4 */

    union { /* 0x240 [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 BOOT_CFG                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }BOOT_CFG;
    union { /* 0x244 [Excel Line :0024]  */
        UINT32 Reg;
        struct {
            UINT32 UDF                                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }UDF;

    UINT8 EMPTY3[16]; /* 0x10 */

    union { /* 0x258 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 FWL_FRL                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }FWL_FRL;
    union { /* 0x25C [Excel Line :0026]  */
        UINT32 Reg;
        struct {
            UINT32 SJTAG                                                                  : 32;     /* [ 31:0]  */
        }Bit;
    }SJTAG;
    union { /* 0x260 [Excel Line :0027]  */
        UINT32 Reg;
        struct {
            UINT32 SJTAG_KEY_NS_0                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }SJTAG_KEY_NS_0;
    union { /* 0x264 [Excel Line :0028]  */
        UINT32 Reg;
        struct {
            UINT32 SJTAG_KEY_NS_1                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }SJTAG_KEY_NS_1;
    union { /* 0x268 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 SJTAG_KEY_S_0                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }SJTAG_KEY_S_0;
    union { /* 0x26C [Excel Line :0030]  */
        UINT32 Reg;
        struct {
            UINT32 SJTAG_KEY_S_1                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }SJTAG_KEY_S_1;

    UINT8 EMPTY4[144]; /* 0x90 */

    union { /* 0x300 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_0;
    union { /* 0x304 [Excel Line :0032]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_1;
    union { /* 0x308 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_2;
    union { /* 0x30C [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_3;
    union { /* 0x310 [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_4;
    union { /* 0x314 [Excel Line :0036]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_5;
    union { /* 0x318 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_6;
    union { /* 0x31C [Excel Line :0038]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY0_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY0_7;
    union { /* 0x320 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_0;
    union { /* 0x324 [Excel Line :0040]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_1;
    union { /* 0x328 [Excel Line :0041]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_2;
    union { /* 0x32C [Excel Line :0042]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_3;
    union { /* 0x330 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_4;
    union { /* 0x334 [Excel Line :0044]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_5;
    union { /* 0x338 [Excel Line :0045]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_6;
    union { /* 0x33C [Excel Line :0046]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY1_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY1_7;
    union { /* 0x340 [Excel Line :0047]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_0;
    union { /* 0x344 [Excel Line :0048]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_1;
    union { /* 0x348 [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_2;
    union { /* 0x34C [Excel Line :0050]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_3;
    union { /* 0x350 [Excel Line :0051]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_4;
    union { /* 0x354 [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_5;
    union { /* 0x358 [Excel Line :0053]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_6;
    union { /* 0x35C [Excel Line :0054]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY2_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY2_7;
    union { /* 0x360 [Excel Line :0055]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_0;
    union { /* 0x364 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_1;
    union { /* 0x368 [Excel Line :0057]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_2;
    union { /* 0x36C [Excel Line :0058]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_3;
    union { /* 0x370 [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_4;
    union { /* 0x374 [Excel Line :0060]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_5;
    union { /* 0x378 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_6;
    union { /* 0x37C [Excel Line :0062]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_KEY3_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_KEY3_7;

    UINT8 EMPTY5[3200]; /* 0xC80 */

    union { /* 0x1000 [Excel Line :0063]  */
        UINT32 Reg;
        struct {
            UINT32 INIT_CMD                                                               : 1;      /* [    0]  */
            UINT32 READ_CMD                                                               : 1;      /* [    1]  */
            UINT32 PROGRAM_CMD                                                            : 1;      /* [    2]  */
            UINT32 STANDBY_CMD                                                            : 1;      /* [    3]  */
            UINT32 LOCK_PROGRAM_CMD                                                       : 1;      /* [    4]  */
            UINT32 HDCP_CMD                                                               : 1;      /* [    5]  */
            UINT32 SOFTWARE_RESET                                                         : 1;      /* [    6]  */
            UINT32 RESERVED1                                                              : 25;     /* [ 31:7]  */
        }Bit;
    }OTP_CON_CONTROL;
    union { /* 0x1004 [Excel Line :0071]  */
        UINT32 Reg;
        struct {
            UINT32 NP2                                                                    : 5;      /* [  4:0]  */
            UINT32 MICRO_EN_CNT                                                           : 6;      /* [ 10:5]  */
            UINT32 RESPONSE_CON                                                           : 2;      /* [12:11]  */
            UINT32 PRE_READING_START                                                      : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }OTP_CON_CONFIG;
    union { /* 0x1008 [Excel Line :0076]  */
        UINT32 Reg;
        struct {
            UINT32 INIT_STATUS                                                            : 4;      /* [  3:0]  */
            UINT32 READ_STATUS                                                            : 4;      /* [  7:4]  */
            UINT32 PROGRAM_STATUS                                                         : 5;      /* [ 12:8]  */
            UINT32 RESERVED2                                                              : 3;      /* [15:13]  */
            UINT32 LOCK_PROGRAM_STATUS                                                    : 4;      /* [19:16]  */
            UINT32 RESERVED1                                                              : 12;     /* [31:20]  */
        }Bit;
    }OTP_CON_STATUS;
    union { /* 0x100C [Excel Line :0082]  */
        UINT32 Reg;
        struct {
            UINT32 ADDRESS                                                                : 11;     /* [ 10:0]  */
            UINT32 RESERVED1                                                              : 20;     /* [30:11]  */
            UINT32 PROGRAM_DATA                                                           : 1;      /* [   31]  */
        }Bit;
    }OTP_IF;
    union { /* 0x1010 [Excel Line :0085]  */
        UINT32 Reg;
        struct {
            UINT32 INIT_DONE                                                              : 1;      /* [    0]  */
            UINT32 READ_DONE                                                              : 1;      /* [    1]  */
            UINT32 PROGRAM_DONE                                                           : 1;      /* [    2]  */
            UINT32 STANDBY_DONE                                                           : 1;      /* [    3]  */
            UINT32 LOCK_PROGRAM_DONE                                                      : 1;      /* [    4]  */
            UINT32 PROGRAM_FAIL                                                           : 1;      /* [    5]  */
            UINT32 LOCK_PROGRAM_FAIL                                                      : 1;      /* [    6]  */
            UINT32 SECURE_FAIL                                                            : 1;      /* [    7]  */
            UINT32 PROGRAM_LOCK                                                           : 1;      /* [    8]  */
            UINT32 RESERVED2                                                              : 1;      /* [    9]  */
            UINT32 PRE_READING_DONE                                                       : 1;      /* [   10]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }OTP_INT_STATUS;
    union { /* 0x1014 [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 INIT_DONE_INT                                                          : 1;      /* [    0]  */
            UINT32 READ_DONE_INT                                                          : 1;      /* [    1]  */
            UINT32 PROGRAM_DONE_INT                                                       : 1;      /* [    2]  */
            UINT32 STANBY_DONE_INT                                                        : 1;      /* [    3]  */
            UINT32 LOCK_PROGRAM_DONE_INT                                                  : 1;      /* [    4]  */
            UINT32 PROGRAM_FAIL_INT                                                       : 1;      /* [    5]  */
            UINT32 LOCK_PROGRAM_FAIL_INT                                                  : 1;      /* [    6]  */
            UINT32 SECURE_FAIL_INT                                                        : 1;      /* [    7]  */
            UINT32 PROGRAM_LOCK_INT                                                       : 1;      /* [    8]  */
            UINT32 RESERVED2                                                              : 1;      /* [    9]  */
            UINT32 PRE_READING_DONE_INT                                                   : 1;      /* [   10]  */
            UINT32 RESERVED1                                                              : 21;     /* [31:11]  */
        }Bit;
    }OTP_INT_EN;
    union { /* 0x1018 [Excel Line :0109]  */
        UINT32 Reg;
        struct {
            UINT32 TCRST                                                                  : 16;     /* [ 15:0]  */
            UINT32 TRW                                                                    : 16;     /* [31:16]  */
        }Bit;
    }OTP_CON_TIME_PARA_0;
    union { /* 0x101C [Excel Line :0111]  */
        UINT32 Reg;
        struct {
            UINT32 TPW                                                                    : 16;     /* [ 15:0]  */
            UINT32 TCWL                                                                   : 16;     /* [31:16]  */
        }Bit;
    }OTP_CON_TIME_PARA_1;
    union { /* 0x1020 [Excel Line :0113]  */
        UINT32 Reg;
        struct {
            UINT32 TDH                                                                    : 8;      /* [  7:0]  */
            UINT32 TWWH                                                                   : 8;      /* [ 15:8]  */
            UINT32 TWWL                                                                   : 8;      /* [23:16]  */
            UINT32 TAS                                                                    : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_2;
    union { /* 0x1024 [Excel Line :0117]  */
        UINT32 Reg;
        struct {
            UINT32 TCPH                                                                   : 8;      /* [  7:0]  */
            UINT32 TCWH                                                                   : 8;      /* [ 15:8]  */
            UINT32 TCPS                                                                   : 8;      /* [23:16]  */
            UINT32 TPES                                                                   : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_3;
    union { /* 0x1028 [Excel Line :0121]  */
        UINT32 Reg;
        struct {
            UINT32 TPGRST                                                                 : 8;      /* [  7:0]  */
            UINT32 TAH                                                                    : 8;      /* [ 15:8]  */
            UINT32 TPGML                                                                  : 8;      /* [23:16]  */
            UINT32 TPEH                                                                   : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_4;
    union { /* 0x102C [Excel Line :0125]  */
        UINT32 Reg;
        struct {
            UINT32 TPGVFY                                                                 : 8;      /* [  7:0]  */
            UINT32 TREW                                                                   : 8;      /* [ 15:8]  */
            UINT32 TRD                                                                    : 8;      /* [23:16]  */
            UINT32 TPGRD                                                                  : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_5;
    union { /* 0x1030 [Excel Line :0129]  */
        UINT32 Reg;
        struct {
            UINT32 TCLEH                                                                  : 8;      /* [  7:0]  */
            UINT32 TCLES                                                                  : 8;      /* [ 15:8]  */
            UINT32 TTWS                                                                   : 8;      /* [23:16]  */
            UINT32 TPGMAS                                                                 : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_6;
    union { /* 0x1034 [Excel Line :0133]  */
        UINT32 Reg;
        struct {
            UINT32 TLBV                                                                   : 16;     /* [ 15:0]  */
            UINT32 TPGL                                                                   : 8;      /* [23:16]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_7;
    union { /* 0x1038 [Excel Line :0136]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE_READ_DATA                                                       : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_IF_SECURE_READ_DATA;
    union { /* 0x103C [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 NONSECURE_READ_DATA                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_IF_NONSECURE_READ_DATA;
    union { /* 0x1040 [Excel Line :0138]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN0                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN0;
    union { /* 0x1044 [Excel Line :0140]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN1                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN1;
    union { /* 0x1048 [Excel Line :0142]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN2                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN2;
    union { /* 0x104C [Excel Line :0144]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN3                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN3;
    union { /* 0x1050 [Excel Line :0146]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN4                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN4;
    union { /* 0x1054 [Excel Line :0148]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN5                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN5;
    union { /* 0x1058 [Excel Line :0150]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN6                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN6;
    union { /* 0x105C [Excel Line :0152]  */
        UINT32 Reg;
        struct {
            UINT32 OTP_READ_LOCK_BIT_EN7                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }OTP_READ_LOCK_BIT_EN7;
}DRV_A6_OTP2K_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_A6_OTP2K_REGISTER* const RegA6_OTP2K = (DRV_A6_OTP2K_REGISTER*)APACHE_A6_OTP2K_BASE_ADDR;
 */



#endif /* end of  DRV_REGISTER_A6_OTP2K__ */

