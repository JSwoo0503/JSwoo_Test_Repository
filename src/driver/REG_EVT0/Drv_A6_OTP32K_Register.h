
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Platform   : APACHE6
*   File       : DRV_A6_OTP32K_Register.h
*   Date       : 2022-07-27 20:41
*
*   THIS CODE WAS GENERATED FROM THE APACHE6 HSI DOCUMENTATION. PLEASE DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_OTP32K_H__
#define DRV_REGISTER_A6_OTP32K_H__

#define APACHE_A6_OTP32K_BASE_ADDR        0x05C30000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 LIFE_CYCLE                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }LIFE_CYCLE;
    union { /* 0x004 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 TEST_DBG_VEC_0                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }TEST_DBG_VEC_0;
    union { /* 0x008 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 TEST_DBG_VEC_1                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }TEST_DBG_VEC_1;
    union { /* 0x00c [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 TEST_DBG_VEC_2                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }TEST_DBG_VEC_2;
    union { /* 0x010 [Excel Line :0012]  */
        UINT32 Reg;
        struct {
            UINT32 TEST_DBG_VEC_3                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }TEST_DBG_VEC_3;
    union { /* 0x014 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 ST_WORD                                                                : 32;     /* [ 31:0]  */
        }Bit;
    }ST_WORD;
    union { /* 0x018 [Excel Line :0014]  */
        UINT32 Reg;
        struct {
            UINT32 OBLI_ST_WORD                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }OBLI_ST_WORD;
    union { /* 0x01c [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 DEVICE_ID_0                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }DEVICE_ID_0;
    union { /* 0x020 [Excel Line :0016]  */
        UINT32 Reg;
        struct {
            UINT32 DEVICE_ID_1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }DEVICE_ID_1;
    union { /* 0x024 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 DEVICE_ID_2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }DEVICE_ID_2;
    union { /* 0x028 [Excel Line :0018]  */
        UINT32 Reg;
        struct {
            UINT32 OEM_ID_0                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }OEM_ID_0;
    union { /* 0x02c [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 OEM_ID_1                                                               : 32;     /* [ 31:0]  */
        }Bit;
    }OEM_ID_1;
    union { /* 0x030 [Excel Line :0020]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_0                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_0;
    union { /* 0x034 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_1                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_1;
    union { /* 0x038 [Excel Line :0022]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_2                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_2;
    union { /* 0x03c [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_3                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_3;
    union { /* 0x040 [Excel Line :0024]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_4                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_4;
    union { /* 0x044 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_5                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_5;
    union { /* 0x048 [Excel Line :0026]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_6                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_6;
    union { /* 0x04c [Excel Line :0027]  */
        UINT32 Reg;
        struct {
            UINT32 DGOK_7                                                                 : 32;     /* [ 31:0]  */
        }Bit;
    }DGOK_7;
    union { /* 0x050 [Excel Line :0028]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_0;
    union { /* 0x054 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_1;
    union { /* 0x058 [Excel Line :0030]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_2;
    union { /* 0x05c [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_3;
    union { /* 0x060 [Excel Line :0032]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_4;
    union { /* 0x064 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_5;
    union { /* 0x068 [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_6;
    union { /* 0x06c [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL1_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL1_7;
    union { /* 0x070 [Excel Line :0036]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_0;
    union { /* 0x074 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_1;
    union { /* 0x078 [Excel Line :0038]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_2;
    union { /* 0x07c [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_3;
    union { /* 0x080 [Excel Line :0040]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_4;
    union { /* 0x084 [Excel Line :0041]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_5;
    union { /* 0x088 [Excel Line :0042]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_6;
    union { /* 0x08c [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL2_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL2_7;
    union { /* 0x090 [Excel Line :0044]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_0;
    union { /* 0x094 [Excel Line :0045]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_1;
    union { /* 0x098 [Excel Line :0046]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_2;
    union { /* 0x09c [Excel Line :0047]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_3;
    union { /* 0x0a0 [Excel Line :0048]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_4;
    union { /* 0x0a4 [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_5;
    union { /* 0x0a8 [Excel Line :0050]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_6;
    union { /* 0x0ac [Excel Line :0051]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL3_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL3_7;
    union { /* 0x0b0 [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_0;
    union { /* 0x0b4 [Excel Line :0053]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_1;
    union { /* 0x0b8 [Excel Line :0054]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_2;
    union { /* 0x0bc [Excel Line :0055]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_3;
    union { /* 0x0c0 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_4;
    union { /* 0x0c4 [Excel Line :0057]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_5;
    union { /* 0x0c8 [Excel Line :0058]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_6;
    union { /* 0x0cc [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL4_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL4_7;
    union { /* 0x0d0 [Excel Line :0060]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_0;
    union { /* 0x0d4 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_1;
    union { /* 0x0d8 [Excel Line :0062]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_2;
    union { /* 0x0dc [Excel Line :0063]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_3;
    union { /* 0x0e0 [Excel Line :0064]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_4;
    union { /* 0x0e4 [Excel Line :0065]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_5;
    union { /* 0xe8 [Excel Line :0066]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_6;
    union { /* 0xec [Excel Line :0067]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL5_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL5_7;
    union { /* 0xf0 [Excel Line :0068]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_0;
    union { /* 0xf4 [Excel Line :0069]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_1;
    union { /* 0xf8 [Excel Line :0070]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_2;
    union { /* 0xfc [Excel Line :0071]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_3;
    union { /* 0x100 [Excel Line :0072]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_4;
    union { /* 0x104 [Excel Line :0073]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_5;
    union { /* 0x108 [Excel Line :0074]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_6;
    union { /* 0x10c [Excel Line :0075]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL6_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL6_7;
    union { /* 0x110 [Excel Line :0076]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_0                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_0;
    union { /* 0x114 [Excel Line :0077]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_1                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_1;
    union { /* 0x118 [Excel Line :0078]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_2                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_2;
    union { /* 0x11c [Excel Line :0079]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_3                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_3;
    union { /* 0x120 [Excel Line :0080]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_4                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_4;
    union { /* 0x124 [Excel Line :0081]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_5                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_5;
    union { /* 0x128 [Excel Line :0082]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_6                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_6;
    union { /* 0x12c [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 KEY_SPL7_7                                                             : 32;     /* [ 31:0]  */
        }Bit;
    }KEY_SPL7_7;
    union { /* 0x130 [Excel Line :0084]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_0                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_0;
    union { /* 0x134 [Excel Line :0085]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_1;
    union { /* 0x138 [Excel Line :0086]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_2;
    union { /* 0x13c [Excel Line :0087]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_3                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_3;
    union { /* 0x140 [Excel Line :0088]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_4                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_4;
    union { /* 0x144 [Excel Line :0089]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_5                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_5;
    union { /* 0x148 [Excel Line :0090]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_6                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_6;
    union { /* 0x14c [Excel Line :0091]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_ID_7                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_ID_7;
    union { /* 0x150 [Excel Line :0092]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_0                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_0;
    union { /* 0x154 [Excel Line :0093]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_1                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_1;
    union { /* 0x158 [Excel Line :0094]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_2                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_2;
    union { /* 0x15c [Excel Line :0095]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_3                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_3;
    union { /* 0x160 [Excel Line :0096]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_4                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_4;
    union { /* 0x164 [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_0_PMS_5                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_0_PMS_5;
    union { /* 0x168 [Excel Line :0098]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_0                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_0;
    union { /* 0x16c [Excel Line :0099]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_1;
    union { /* 0x170 [Excel Line :0100]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_2;
    union { /* 0x174 [Excel Line :0101]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_3                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_3;
    union { /* 0x178 [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_4                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_4;
    union { /* 0x17c [Excel Line :0103]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_5                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_5;
    union { /* 0x180 [Excel Line :0104]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_6                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_6;
    union { /* 0x184 [Excel Line :0105]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_ID_7                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_ID_7;
    union { /* 0x188 [Excel Line :0106]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_0                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_0;
    union { /* 0x18c [Excel Line :0107]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_1                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_1;
    union { /* 0x190 [Excel Line :0108]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_2                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_2;
    union { /* 0x194 [Excel Line :0109]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_3                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_3;
    union { /* 0x198 [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_4                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_4;
    union { /* 0x19c [Excel Line :0111]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_1_PMS_5                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_1_PMS_5;
    union { /* 0x1a0 [Excel Line :0112]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_0                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_0;
    union { /* 0x1a4 [Excel Line :0113]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_1;
    union { /* 0x1a8 [Excel Line :0114]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_2;
    union { /* 0x1ac [Excel Line :0115]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_3                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_3;
    union { /* 0x1b0 [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_4                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_4;
    union { /* 0x1b4 [Excel Line :0117]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_5                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_5;
    union { /* 0x1b8 [Excel Line :0118]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_6                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_6;
    union { /* 0x1bc [Excel Line :0119]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_ID_7                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_ID_7;
    union { /* 0x1c0 [Excel Line :0120]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_0                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_0;
    union { /* 0x1c4 [Excel Line :0121]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_1                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_1;
    union { /* 0x1c8 [Excel Line :0122]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_2                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_2;
    union { /* 0x1cc [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_3                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_3;
    union { /* 0x1d0 [Excel Line :0124]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_4                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_4;
    union { /* 0x1d4 [Excel Line :0125]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_2_PMS_5                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_2_PMS_5;
    union { /* 0x1d8 [Excel Line :0126]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_0                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_0;
    union { /* 0x1dc [Excel Line :0127]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_1                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_1;
    union { /* 0x1e0 [Excel Line :0128]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_2                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_2;
    union { /* 0x1e4 [Excel Line :0129]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_3                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_3;
    union { /* 0x1e8 [Excel Line :0130]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_4                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_4;
    union { /* 0x1ec [Excel Line :0131]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_5                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_5;
    union { /* 0x1f0 [Excel Line :0132]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_6                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_6;
    union { /* 0x1f4 [Excel Line :0133]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_ID_7                                                            : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_ID_7;
    union { /* 0x1f8 [Excel Line :0134]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_0                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_0;
    union { /* 0x1fc [Excel Line :0135]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_1                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_1;
    union { /* 0x200 [Excel Line :0136]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_2                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_2;
    union { /* 0x204 [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_3                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_3;
    union { /* 0x208 [Excel Line :0138]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_4                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_4;
    union { /* 0x20c [Excel Line :0139]  */
        UINT32 Reg;
        struct {
            UINT32 ROOT_3_PMS_5                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ROOT_3_PMS_5;
    union { /* 0x210 [Excel Line :0140]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_0                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_0;
    union { /* 0x214 [Excel Line :0141]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_1                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_1;
    union { /* 0x218 [Excel Line :0142]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_2                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_2;
    union { /* 0x21c [Excel Line :0143]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_3                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_3;
    union { /* 0x220 [Excel Line :0144]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_4                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_4;
    union { /* 0x224 [Excel Line :0145]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_5                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_5;
    union { /* 0x228 [Excel Line :0146]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_6                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_6;
    union { /* 0x22c [Excel Line :0147]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_7                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_7;
    union { /* 0x230 [Excel Line :0148]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_8                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_8;
    union { /* 0x234 [Excel Line :0149]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_9                                                           : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_9;
    union { /* 0x238 [Excel Line :0150]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_10                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_10;
    union { /* 0x23c [Excel Line :0151]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_11                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_11;
    union { /* 0x240 [Excel Line :0152]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_12                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_12;
    union { /* 0x244 [Excel Line :0153]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_13                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_13;
    union { /* 0x248 [Excel Line :0154]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_14                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_14;
    union { /* 0x24c [Excel Line :0155]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_15                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_15;
    union { /* 0x250 [Excel Line :0156]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_16                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_16;
    union { /* 0x254 [Excel Line :0157]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_17                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_17;
    union { /* 0x258 [Excel Line :0158]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_18                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_18;
    union { /* 0x25c [Excel Line :0159]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_19                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_19;
    union { /* 0x260 [Excel Line :0160]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_20                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_20;
    union { /* 0x264 [Excel Line :0161]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_21                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_21;
    union { /* 0x268 [Excel Line :0162]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_22                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_22;
    union { /* 0x26c [Excel Line :0163]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_23                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_23;
    union { /* 0x270 [Excel Line :0164]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_24                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_24;
    union { /* 0x274 [Excel Line :0165]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_25                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_25;
    union { /* 0x278 [Excel Line :0166]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_26                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_26;
    union { /* 0x27c [Excel Line :0167]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_27                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_27;
    union { /* 0x280 [Excel Line :0168]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_28                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_28;
    union { /* 0x284 [Excel Line :0169]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_29                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_29;
    union { /* 0x288 [Excel Line :0170]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_30                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_30;
    union { /* 0x28c [Excel Line :0171]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_31                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_31;
    union { /* 0x290 [Excel Line :0172]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_32                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_32;
    union { /* 0x294 [Excel Line :0173]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_33                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_33;
    union { /* 0x298 [Excel Line :0174]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_34                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_34;
    union { /* 0x29c [Excel Line :0175]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_35                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_35;
    union { /* 0x2a0 [Excel Line :0176]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_36                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_36;
    union { /* 0x2a4 [Excel Line :0177]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_37                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_37;
    union { /* 0x2a8 [Excel Line :0178]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_38                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_38;
    union { /* 0x2ac [Excel Line :0179]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_39                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_39;
    union { /* 0x2b0 [Excel Line :0180]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_40                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_40;
    union { /* 0x2b4 [Excel Line :0181]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_41                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_41;
    union { /* 0x2b8 [Excel Line :0182]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_42                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_42;
    union { /* 0x2bc [Excel Line :0183]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_43                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_43;
    union { /* 0x2c0 [Excel Line :0184]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_44                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_44;
    union { /* 0x2c4 [Excel Line :0185]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_45                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_45;
    union { /* 0x2c8 [Excel Line :0186]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_46                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_46;
    union { /* 0x2cc [Excel Line :0187]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_47                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_47;
    union { /* 0x2d0 [Excel Line :0188]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_48                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_48;
    union { /* 0x2d4 [Excel Line :0189]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_49                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_49;
    union { /* 0x2d8 [Excel Line :0190]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_50                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_50;
    union { /* 0x2dc [Excel Line :0191]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_51                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_51;
    union { /* 0x2e0 [Excel Line :0192]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_52                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_52;
    union { /* 0x2e4 [Excel Line :0193]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_53                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_53;
    union { /* 0x2e8 [Excel Line :0194]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_54                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_54;
    union { /* 0x2ec [Excel Line :0195]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_55                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_55;
    union { /* 0x2f0 [Excel Line :0196]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_56                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_56;
    union { /* 0x2f4 [Excel Line :0197]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_57                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_57;
    union { /* 0x2f8 [Excel Line :0198]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_58                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_58;
    union { /* 0x2fc [Excel Line :0199]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_59                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_59;
    union { /* 0x300 [Excel Line :0200]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_60                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_60;
    union { /* 0x304 [Excel Line :0201]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_61                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_61;
    union { /* 0x308 [Excel Line :0202]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_62                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_62;
    union { /* 0x30c [Excel Line :0203]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_63                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_63;
    union { /* 0x310 [Excel Line :0204]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_64                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_64;
    union { /* 0x314 [Excel Line :0205]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_65                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_65;
    union { /* 0x318 [Excel Line :0206]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_66                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_66;
    union { /* 0x31c [Excel Line :0207]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_67                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_67;
    union { /* 0x320 [Excel Line :0208]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_68                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_68;
    union { /* 0x324 [Excel Line :0209]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_69                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_69;
    union { /* 0x328 [Excel Line :0210]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_70                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_70;
    union { /* 0x32c [Excel Line :0211]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_71                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_71;
    union { /* 0x330 [Excel Line :0212]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_72                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_72;
    union { /* 0x334 [Excel Line :0213]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_73                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_73;
    union { /* 0x338 [Excel Line :0214]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_74                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_74;
    union { /* 0x33c [Excel Line :0215]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_75                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_75;
    union { /* 0x340 [Excel Line :0216]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_76                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_76;
    union { /* 0x344 [Excel Line :0217]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_77                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_77;
    union { /* 0x348 [Excel Line :0218]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_78                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_78;
    union { /* 0x34c [Excel Line :0219]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_79                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_79;
    union { /* 0x350 [Excel Line :0220]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_80                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_80;
    union { /* 0x354 [Excel Line :0221]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_81                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_81;
    union { /* 0x358 [Excel Line :0222]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_82                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_82;
    union { /* 0x35c [Excel Line :0223]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_83                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_83;
    union { /* 0x360 [Excel Line :0224]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_84                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_84;
    union { /* 0x364 [Excel Line :0225]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_85                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_85;
    union { /* 0x368 [Excel Line :0226]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_86                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_86;
    union { /* 0x36c [Excel Line :0227]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_87                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_87;
    union { /* 0x370 [Excel Line :0228]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_88                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_88;
    union { /* 0x374 [Excel Line :0229]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_89                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_89;
    union { /* 0x378 [Excel Line :0230]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_90                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_90;
    union { /* 0x37c [Excel Line :0231]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_91                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_91;
    union { /* 0x380 [Excel Line :0232]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_92                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_92;
    union { /* 0x384 [Excel Line :0233]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_93                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_93;
    union { /* 0x388 [Excel Line :0234]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_94                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_94;
    union { /* 0x38c [Excel Line :0235]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_95                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_95;
    union { /* 0x390 [Excel Line :0236]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_96                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_96;
    union { /* 0x394 [Excel Line :0237]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_97                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_97;
    union { /* 0x398 [Excel Line :0238]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_98                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_98;
    union { /* 0x39c [Excel Line :0239]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_99                                                          : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_99;
    union { /* 0x3a0 [Excel Line :0240]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_100                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_100;
    union { /* 0x3a4 [Excel Line :0241]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_101                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_101;
    union { /* 0x3a8 [Excel Line :0242]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_102                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_102;
    union { /* 0x3ac [Excel Line :0243]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_103                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_103;
    union { /* 0x3b0 [Excel Line :0244]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_104                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_104;
    union { /* 0x3b4 [Excel Line :0245]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_105                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_105;
    union { /* 0x3b8 [Excel Line :0246]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_106                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_106;
    union { /* 0x3bc [Excel Line :0247]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_107                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_107;
    union { /* 0x3c0 [Excel Line :0248]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_108                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_108;
    union { /* 0x3c4 [Excel Line :0249]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_109                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_109;
    union { /* 0x3c8 [Excel Line :0250]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_110                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_110;
    union { /* 0x3cc [Excel Line :0251]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_111                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_111;
    union { /* 0x3d0 [Excel Line :0252]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_112                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_112;
    union { /* 0x3d4 [Excel Line :0253]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_113                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_113;
    union { /* 0x3d8 [Excel Line :0254]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_114                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_114;
    union { /* 0x3dc [Excel Line :0255]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_115                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_115;
    union { /* 0x3e0 [Excel Line :0256]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_116                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_116;
    union { /* 0x3e4 [Excel Line :0257]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_117                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_117;
    union { /* 0x3e8 [Excel Line :0258]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_118                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_118;
    union { /* 0x3ec [Excel Line :0259]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_119                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_119;
    union { /* 0x3f0 [Excel Line :0260]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_120                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_120;
    union { /* 0x3f4 [Excel Line :0261]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_121                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_121;
    union { /* 0x3f8 [Excel Line :0262]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_122                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_122;
    union { /* 0x3fc [Excel Line :0263]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_123                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_123;
    union { /* 0x400 [Excel Line :0264]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_124                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_124;
    union { /* 0x404 [Excel Line :0265]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_125                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_125;
    union { /* 0x408 [Excel Line :0266]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_126                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_126;
    union { /* 0x40c [Excel Line :0267]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_127                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_127;
    union { /* 0x410 [Excel Line :0268]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_128                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_128;
    union { /* 0x414 [Excel Line :0269]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_129                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_129;
    union { /* 0x418 [Excel Line :0270]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_130                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_130;
    union { /* 0x41c [Excel Line :0271]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_131                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_131;
    union { /* 0x420 [Excel Line :0272]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_132                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_132;
    union { /* 0x424 [Excel Line :0273]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_133                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_133;
    union { /* 0x428 [Excel Line :0274]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_134                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_134;
    union { /* 0x42c [Excel Line :0275]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_135                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_135;
    union { /* 0x430 [Excel Line :0276]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_136                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_136;
    union { /* 0x434 [Excel Line :0277]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_137                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_137;
    union { /* 0x438 [Excel Line :0278]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_138                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_138;
    union { /* 0x43c [Excel Line :0279]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_139                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_139;
    union { /* 0x440 [Excel Line :0280]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_140                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_140;
    union { /* 0x444 [Excel Line :0281]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_141                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_141;
    union { /* 0x448 [Excel Line :0282]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_142                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_142;
    union { /* 0x44c [Excel Line :0283]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_143                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_143;
    union { /* 0x450 [Excel Line :0284]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_144                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_144;
    union { /* 0x454 [Excel Line :0285]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_145                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_145;
    union { /* 0x458 [Excel Line :0286]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_146                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_146;
    union { /* 0x45c [Excel Line :0287]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_147                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_147;
    union { /* 0x460 [Excel Line :0288]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_148                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_148;
    union { /* 0x464 [Excel Line :0289]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_149                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_149;
    union { /* 0x468 [Excel Line :0290]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_150                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_150;
    union { /* 0x46c [Excel Line :0291]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_151                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_151;
    union { /* 0x470 [Excel Line :0292]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_152                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_152;
    union { /* 0x474 [Excel Line :0293]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_153                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_153;
    union { /* 0x478 [Excel Line :0294]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_154                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_154;
    union { /* 0x47c [Excel Line :0295]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_155                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_155;
    union { /* 0x480 [Excel Line :0296]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_156                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_156;
    union { /* 0x484 [Excel Line :0297]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_157                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_157;
    union { /* 0x488 [Excel Line :0298]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_158                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_158;
    union { /* 0x48c [Excel Line :0299]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_159                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_159;
    union { /* 0x490 [Excel Line :0300]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_160                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_160;
    union { /* 0x494 [Excel Line :0301]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_161                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_161;
    union { /* 0x498 [Excel Line :0302]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_162                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_162;
    union { /* 0x49c [Excel Line :0303]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_163                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_163;
    union { /* 0x4a0 [Excel Line :0304]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_164                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_164;
    union { /* 0x4a4 [Excel Line :0305]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_165                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_165;
    union { /* 0x4a8 [Excel Line :0306]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_166                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_166;
    union { /* 0x4ac [Excel Line :0307]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_167                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_167;
    union { /* 0x4b0 [Excel Line :0308]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_168                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_168;
    union { /* 0x4b4 [Excel Line :0309]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_169                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_169;
    union { /* 0x4b8 [Excel Line :0310]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_170                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_170;
    union { /* 0x4bc [Excel Line :0311]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_171                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_171;
    union { /* 0x4c0 [Excel Line :0312]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_172                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_172;
    union { /* 0x4c4 [Excel Line :0313]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_173                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_173;
    union { /* 0x4c8 [Excel Line :0314]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_174                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_174;
    union { /* 0x4cc [Excel Line :0315]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_175                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_175;
    union { /* 0x4d0 [Excel Line :0316]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_176                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_176;
    union { /* 0x4d4 [Excel Line :0317]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_177                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_177;
    union { /* 0x4d8 [Excel Line :0318]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_178                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_178;
    union { /* 0x4dc [Excel Line :0319]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_179                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_179;
    union { /* 0x4e0 [Excel Line :0320]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_180                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_180;
    union { /* 0x4e4 [Excel Line :0321]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_181                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_181;
    union { /* 0x4e8 [Excel Line :0322]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_182                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_182;
    union { /* 0x4ec [Excel Line :0323]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_183                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_183;
    union { /* 0x4f0 [Excel Line :0324]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_184                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_184;
    union { /* 0x4f4 [Excel Line :0325]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_185                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_185;
    union { /* 0x4f8 [Excel Line :0326]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_186                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_186;
    union { /* 0x4fc [Excel Line :0327]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_187                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_187;
    union { /* 0x500 [Excel Line :0328]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_188                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_188;
    union { /* 0x504 [Excel Line :0329]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_189                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_189;
    union { /* 0x508 [Excel Line :0330]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_190                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_190;
    union { /* 0x50c [Excel Line :0331]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_191                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_191;
    union { /* 0x510 [Excel Line :0332]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_192                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_192;
    union { /* 0x514 [Excel Line :0333]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_193                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_193;
    union { /* 0x518 [Excel Line :0334]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_194                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_194;
    union { /* 0x51c [Excel Line :0335]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_195                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_195;
    union { /* 0x520 [Excel Line :0336]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_196                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_196;
    union { /* 0x524 [Excel Line :0337]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_197                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_197;
    union { /* 0x528 [Excel Line :0338]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_198                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_198;
    union { /* 0x52c [Excel Line :0339]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_199                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_199;
    union { /* 0x530 [Excel Line :0340]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_200                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_200;
    union { /* 0x534 [Excel Line :0341]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_201                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_201;
    union { /* 0x538 [Excel Line :0342]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_202                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_202;
    union { /* 0x53c [Excel Line :0343]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_203                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_203;
    union { /* 0x540 [Excel Line :0344]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_204                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_204;
    union { /* 0x544 [Excel Line :0345]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_205                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_205;
    union { /* 0x548 [Excel Line :0346]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_206                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_206;
    union { /* 0x54c [Excel Line :0347]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_207                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_207;
    union { /* 0x550 [Excel Line :0348]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_208                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_208;
    union { /* 0x554 [Excel Line :0349]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_209                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_209;
    union { /* 0x558 [Excel Line :0350]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_210                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_210;
    union { /* 0x55c [Excel Line :0351]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_211                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_211;
    union { /* 0x560 [Excel Line :0352]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_212                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_212;
    union { /* 0x564 [Excel Line :0353]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_213                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_213;
    union { /* 0x568 [Excel Line :0354]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_214                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_214;
    union { /* 0x56c [Excel Line :0355]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_215                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_215;
    union { /* 0x570 [Excel Line :0356]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_216                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_216;
    union { /* 0x574 [Excel Line :0357]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_217                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_217;
    union { /* 0x578 [Excel Line :0358]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_218                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_218;
    union { /* 0x57c [Excel Line :0359]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_219                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_219;
    union { /* 0x580 [Excel Line :0360]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_220                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_220;
    union { /* 0x584 [Excel Line :0361]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_221                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_221;
    union { /* 0x588 [Excel Line :0362]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_222                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_222;
    union { /* 0x58c [Excel Line :0363]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_223                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_223;
    union { /* 0x590 [Excel Line :0364]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_224                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_224;
    union { /* 0x594 [Excel Line :0365]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_225                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_225;
    union { /* 0x598 [Excel Line :0366]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_226                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_226;
    union { /* 0x59c [Excel Line :0367]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_227                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_227;
    union { /* 0x5a0 [Excel Line :0368]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_228                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_228;
    union { /* 0x5a4 [Excel Line :0369]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_229                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_229;
    union { /* 0x5a8 [Excel Line :0370]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_230                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_230;
    union { /* 0x5ac [Excel Line :0371]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_231                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_231;
    union { /* 0x5b0 [Excel Line :0372]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_232                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_232;
    union { /* 0x5b4 [Excel Line :0373]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_233                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_233;
    union { /* 0x5b8 [Excel Line :0374]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_234                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_234;
    union { /* 0x5bc [Excel Line :0375]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_235                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_235;
    union { /* 0x5c0 [Excel Line :0376]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_236                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_236;
    union { /* 0x5c4 [Excel Line :0377]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_237                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_237;
    union { /* 0x5c8 [Excel Line :0378]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_238                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_238;
    union { /* 0x5cc [Excel Line :0379]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_239                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_239;
    union { /* 0x5d0 [Excel Line :0380]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_240                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_240;
    union { /* 0x5d4 [Excel Line :0381]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_241                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_241;
    union { /* 0x5d8 [Excel Line :0382]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_242                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_242;
    union { /* 0x5dc [Excel Line :0383]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_243                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_243;
    union { /* 0x5e0 [Excel Line :0384]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_244                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_244;
    union { /* 0x5e4 [Excel Line :0385]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_245                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_245;
    union { /* 0x5e8 [Excel Line :0386]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_246                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_246;
    union { /* 0x5ec [Excel Line :0387]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_247                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_247;
    union { /* 0x5f0 [Excel Line :0388]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_248                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_248;
    union { /* 0x5f4 [Excel Line :0389]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_249                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_249;
    union { /* 0x5f8 [Excel Line :0390]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_250                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_250;
    union { /* 0x5fc [Excel Line :0391]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_251                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_251;
    union { /* 0x600 [Excel Line :0392]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_252                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_252;
    union { /* 0x604 [Excel Line :0393]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_253                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_253;
    union { /* 0x608 [Excel Line :0394]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_254                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_254;
    union { /* 0x60c [Excel Line :0395]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_255                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_255;
    union { /* 0x610 [Excel Line :0396]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_256                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_256;
    union { /* 0x614 [Excel Line :0397]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_257                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_257;
    union { /* 0x618 [Excel Line :0398]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_258                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_258;
    union { /* 0x61c [Excel Line :0399]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_259                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_259;
    union { /* 0x620 [Excel Line :0400]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_260                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_260;
    union { /* 0x624 [Excel Line :0401]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_261                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_261;
    union { /* 0x628 [Excel Line :0402]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_262                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_262;
    union { /* 0x62c [Excel Line :0403]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_263                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_263;
    union { /* 0x630 [Excel Line :0404]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_264                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_264;
    union { /* 0x634 [Excel Line :0405]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_265                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_265;
    union { /* 0x638 [Excel Line :0406]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_266                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_266;
    union { /* 0x63c [Excel Line :0407]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_267                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_267;
    union { /* 0x640 [Excel Line :0408]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_268                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_268;
    union { /* 0x644 [Excel Line :0409]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_269                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_269;
    union { /* 0x648 [Excel Line :0410]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_270                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_270;
    union { /* 0x64c [Excel Line :0411]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_271                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_271;
    union { /* 0x650 [Excel Line :0412]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_272                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_272;
    union { /* 0x654 [Excel Line :0413]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_273                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_273;
    union { /* 0x658 [Excel Line :0414]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_274                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_274;
    union { /* 0x65c [Excel Line :0415]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_275                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_275;
    union { /* 0x660 [Excel Line :0416]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_276                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_276;
    union { /* 0x664 [Excel Line :0417]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_277                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_277;
    union { /* 0x668 [Excel Line :0418]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_278                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_278;
    union { /* 0x66c [Excel Line :0419]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_279                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_279;
    union { /* 0x670 [Excel Line :0420]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_280                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_280;
    union { /* 0x674 [Excel Line :0421]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_281                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_281;
    union { /* 0x678 [Excel Line :0422]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_282                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_282;
    union { /* 0x67c [Excel Line :0423]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_283                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_283;
    union { /* 0x680 [Excel Line :0424]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_284                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_284;
    union { /* 0x684 [Excel Line :0425]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_285                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_285;
    union { /* 0x688 [Excel Line :0426]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_286                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_286;
    union { /* 0x68c [Excel Line :0427]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_287                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_287;
    union { /* 0x690 [Excel Line :0428]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_288                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_288;
    union { /* 0x694 [Excel Line :0429]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_289                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_289;
    union { /* 0x698 [Excel Line :0430]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_290                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_290;
    union { /* 0x69c [Excel Line :0431]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_291                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_291;
    union { /* 0x6a0 [Excel Line :0432]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_292                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_292;
    union { /* 0x6a4 [Excel Line :0433]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_293                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_293;
    union { /* 0x6a8 [Excel Line :0434]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_294                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_294;
    union { /* 0x6ac [Excel Line :0435]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_295                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_295;
    union { /* 0x6b0 [Excel Line :0436]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_296                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_296;
    union { /* 0x6b4 [Excel Line :0437]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_297                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_297;
    union { /* 0x6b8 [Excel Line :0438]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_298                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_298;
    union { /* 0x6bc [Excel Line :0439]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_299                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_299;
    union { /* 0x6c0 [Excel Line :0440]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_300                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_300;
    union { /* 0x6c4 [Excel Line :0441]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_301                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_301;
    union { /* 0x6c8 [Excel Line :0442]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_302                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_302;
    union { /* 0x6cc [Excel Line :0443]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_303                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_303;
    union { /* 0x6d0 [Excel Line :0444]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_304                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_304;
    union { /* 0x6d4 [Excel Line :0445]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_305                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_305;
    union { /* 0x6d8 [Excel Line :0446]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_306                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_306;
    union { /* 0x6dc [Excel Line :0447]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_307                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_307;
    union { /* 0x6e0 [Excel Line :0448]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_308                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_308;
    union { /* 0x6e4 [Excel Line :0449]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_309                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_309;
    union { /* 0x6e8 [Excel Line :0450]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_310                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_310;
    union { /* 0x6ec [Excel Line :0451]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_311                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_311;
    union { /* 0x6f0 [Excel Line :0452]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_312                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_312;
    union { /* 0x6f4 [Excel Line :0453]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_313                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_313;
    union { /* 0x6f8 [Excel Line :0454]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_314                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_314;
    union { /* 0x6fc [Excel Line :0455]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_315                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_315;
    union { /* 0x700 [Excel Line :0456]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_316                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_316;
    union { /* 0x704 [Excel Line :0457]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_317                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_317;
    union { /* 0x708 [Excel Line :0458]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_318                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_318;
    union { /* 0x70c [Excel Line :0459]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_319                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_319;
    union { /* 0x710 [Excel Line :0460]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_320                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_320;
    union { /* 0x714 [Excel Line :0461]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_321                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_321;
    union { /* 0x718 [Excel Line :0462]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_322                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_322;
    union { /* 0x71c [Excel Line :0463]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_323                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_323;
    union { /* 0x720 [Excel Line :0464]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_324                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_324;
    union { /* 0x724 [Excel Line :0465]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_325                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_325;
    union { /* 0x728 [Excel Line :0466]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_326                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_326;
    union { /* 0x72c [Excel Line :0467]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_327                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_327;
    union { /* 0x730 [Excel Line :0468]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_328                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_328;
    union { /* 0x734 [Excel Line :0469]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_329                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_329;
    union { /* 0x738 [Excel Line :0470]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_330                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_330;
    union { /* 0x73c [Excel Line :0471]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_331                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_331;
    union { /* 0x740 [Excel Line :0472]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_332                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_332;
    union { /* 0x744 [Excel Line :0473]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_333                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_333;
    union { /* 0x748 [Excel Line :0474]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_334                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_334;
    union { /* 0x74c [Excel Line :0475]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_335                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_335;
    union { /* 0x750 [Excel Line :0476]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_336                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_336;
    union { /* 0x754 [Excel Line :0477]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_337                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_337;
    union { /* 0x758 [Excel Line :0478]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_338                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_338;
    union { /* 0x75c [Excel Line :0479]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_339                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_339;
    union { /* 0x760 [Excel Line :0480]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_340                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_340;
    union { /* 0x764 [Excel Line :0481]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_341                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_341;
    union { /* 0x768 [Excel Line :0482]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_342                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_342;
    union { /* 0x76c [Excel Line :0483]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_343                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_343;
    union { /* 0x770 [Excel Line :0484]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_344                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_344;
    union { /* 0x774 [Excel Line :0485]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_345                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_345;
    union { /* 0x778 [Excel Line :0486]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_346                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_346;
    union { /* 0x77c [Excel Line :0487]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_347                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_347;
    union { /* 0x780 [Excel Line :0488]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_348                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_348;
    union { /* 0x784 [Excel Line :0489]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_349                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_349;
    union { /* 0x788 [Excel Line :0490]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_350                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_350;
    union { /* 0x78c [Excel Line :0491]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_351                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_351;
    union { /* 0x790 [Excel Line :0492]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_352                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_352;
    union { /* 0x794 [Excel Line :0493]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_353                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_353;
    union { /* 0x798 [Excel Line :0494]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_354                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_354;
    union { /* 0x79c [Excel Line :0495]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_355                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_355;
    union { /* 0x7a0 [Excel Line :0496]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_356                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_356;
    union { /* 0x7a4 [Excel Line :0497]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_357                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_357;
    union { /* 0x7a8 [Excel Line :0498]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_358                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_358;
    union { /* 0x7ac [Excel Line :0499]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_359                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_359;
    union { /* 0x7b0 [Excel Line :0500]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_360                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_360;
    union { /* 0x7b4 [Excel Line :0501]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_361                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_361;
    union { /* 0x7b8 [Excel Line :0502]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_362                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_362;
    union { /* 0x7bc [Excel Line :0503]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_363                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_363;
    union { /* 0x7c0 [Excel Line :0504]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_364                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_364;
    union { /* 0x7c4 [Excel Line :0505]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_365                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_365;
    union { /* 0x7c8 [Excel Line :0506]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_366                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_366;
    union { /* 0x7cc [Excel Line :0507]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_367                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_367;
    union { /* 0x7d0 [Excel Line :0508]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_368                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_368;
    union { /* 0x7d4 [Excel Line :0509]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_369                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_369;
    union { /* 0x7d8 [Excel Line :0510]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_370                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_370;
    union { /* 0x7dc [Excel Line :0511]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_371                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_371;
    union { /* 0x7e0 [Excel Line :0512]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_372                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_372;
    union { /* 0x7e4 [Excel Line :0513]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_373                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_373;
    union { /* 0x7e8 [Excel Line :0514]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_374                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_374;
    union { /* 0x7ec [Excel Line :0515]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_375                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_375;
    union { /* 0x7f0 [Excel Line :0516]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_376                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_376;
    union { /* 0x7f4 [Excel Line :0517]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_377                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_377;
    union { /* 0x7f8 [Excel Line :0518]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_378                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_378;
    union { /* 0x7fc [Excel Line :0519]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_379                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_379;
    union { /* 0x800 [Excel Line :0520]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_380                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_380;
    union { /* 0x804 [Excel Line :0521]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_381                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_381;
    union { /* 0x808 [Excel Line :0522]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_382                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_382;
    union { /* 0x80c [Excel Line :0523]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_383                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_383;
    union { /* 0x810 [Excel Line :0524]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_384                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_384;
    union { /* 0x814 [Excel Line :0525]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_385                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_385;
    union { /* 0x818 [Excel Line :0526]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_386                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_386;
    union { /* 0x81c [Excel Line :0527]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_387                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_387;
    union { /* 0x820 [Excel Line :0528]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_388                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_388;
    union { /* 0x824 [Excel Line :0529]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_389                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_389;
    union { /* 0x828 [Excel Line :0530]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_390                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_390;
    union { /* 0x82c [Excel Line :0531]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_391                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_391;
    union { /* 0x830 [Excel Line :0532]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_392                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_392;
    union { /* 0x834 [Excel Line :0533]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_393                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_393;
    union { /* 0x838 [Excel Line :0534]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_394                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_394;
    union { /* 0x83c [Excel Line :0535]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_395                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_395;
    union { /* 0x840 [Excel Line :0536]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_396                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_396;
    union { /* 0x844 [Excel Line :0537]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_397                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_397;
    union { /* 0x848 [Excel Line :0538]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_398                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_398;
    union { /* 0x84c [Excel Line :0539]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_399                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_399;
    union { /* 0x850 [Excel Line :0540]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_400                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_400;
    union { /* 0x854 [Excel Line :0541]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_401                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_401;
    union { /* 0x858 [Excel Line :0542]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_402                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_402;
    union { /* 0x85c [Excel Line :0543]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_403                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_403;
    union { /* 0x860 [Excel Line :0544]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_404                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_404;
    union { /* 0x864 [Excel Line :0545]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_405                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_405;
    union { /* 0x868 [Excel Line :0546]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_406                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_406;
    union { /* 0x86c [Excel Line :0547]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_407                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_407;
    union { /* 0x870 [Excel Line :0548]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_408                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_408;
    union { /* 0x874 [Excel Line :0549]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_409                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_409;
    union { /* 0x878 [Excel Line :0550]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_410                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_410;
    union { /* 0x87c [Excel Line :0551]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_411                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_411;
    union { /* 0x880 [Excel Line :0552]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_412                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_412;
    union { /* 0x884 [Excel Line :0553]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_413                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_413;
    union { /* 0x888 [Excel Line :0554]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_414                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_414;
    union { /* 0x88c [Excel Line :0555]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_415                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_415;
    union { /* 0x890 [Excel Line :0556]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_416                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_416;
    union { /* 0x894 [Excel Line :0557]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_417                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_417;
    union { /* 0x898 [Excel Line :0558]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_418                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_418;
    union { /* 0x89c [Excel Line :0559]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_419                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_419;
    union { /* 0x8a0 [Excel Line :0560]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_420                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_420;
    union { /* 0x8a4 [Excel Line :0561]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_421                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_421;
    union { /* 0x8a8 [Excel Line :0562]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_422                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_422;
    union { /* 0x8ac [Excel Line :0563]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_423                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_423;
    union { /* 0x8b0 [Excel Line :0564]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_424                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_424;
    union { /* 0x8b4 [Excel Line :0565]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_425                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_425;
    union { /* 0x8b8 [Excel Line :0566]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_426                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_426;
    union { /* 0x8bc [Excel Line :0567]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_427                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_427;
    union { /* 0x8c0 [Excel Line :0568]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_428                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_428;
    union { /* 0x8c4 [Excel Line :0569]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_429                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_429;
    union { /* 0x8c8 [Excel Line :0570]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_430                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_430;
    union { /* 0x8cc [Excel Line :0571]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_431                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_431;
    union { /* 0x8d0 [Excel Line :0572]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_432                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_432;
    union { /* 0x8d4 [Excel Line :0573]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_433                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_433;
    union { /* 0x8d8 [Excel Line :0574]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_434                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_434;
    union { /* 0x8dc [Excel Line :0575]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_435                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_435;
    union { /* 0x8e0 [Excel Line :0576]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_436                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_436;
    union { /* 0x8e4 [Excel Line :0577]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_437                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_437;
    union { /* 0x8e8 [Excel Line :0578]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_438                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_438;
    union { /* 0x8ec [Excel Line :0579]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_439                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_439;
    union { /* 0x8f0 [Excel Line :0580]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_440                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_440;
    union { /* 0x8f4 [Excel Line :0581]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_441                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_441;
    union { /* 0x8f8 [Excel Line :0582]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_442                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_442;
    union { /* 0x8fc [Excel Line :0583]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_443                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_443;
    union { /* 0x900 [Excel Line :0584]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_444                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_444;
    union { /* 0x904 [Excel Line :0585]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_445                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_445;
    union { /* 0x908 [Excel Line :0586]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_446                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_446;
    union { /* 0x90c [Excel Line :0587]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_447                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_447;
    union { /* 0x910 [Excel Line :0588]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_448                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_448;
    union { /* 0x914 [Excel Line :0589]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_449                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_449;
    union { /* 0x918 [Excel Line :0590]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_450                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_450;
    union { /* 0x91c [Excel Line :0591]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_451                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_451;
    union { /* 0x920 [Excel Line :0592]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_452                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_452;
    union { /* 0x924 [Excel Line :0593]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_453                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_453;
    union { /* 0x928 [Excel Line :0594]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_454                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_454;
    union { /* 0x92c [Excel Line :0595]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_455                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_455;
    union { /* 0x930 [Excel Line :0596]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_456                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_456;
    union { /* 0x934 [Excel Line :0597]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_457                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_457;
    union { /* 0x938 [Excel Line :0598]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_458                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_458;
    union { /* 0x93c [Excel Line :0599]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_459                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_459;
    union { /* 0x940 [Excel Line :0600]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_460                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_460;
    union { /* 0x944 [Excel Line :0601]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_461                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_461;
    union { /* 0x948 [Excel Line :0602]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_462                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_462;
    union { /* 0x94c [Excel Line :0603]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_463                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_463;
    union { /* 0x950 [Excel Line :0604]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_464                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_464;
    union { /* 0x954 [Excel Line :0605]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_465                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_465;
    union { /* 0x958 [Excel Line :0606]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_466                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_466;
    union { /* 0x95c [Excel Line :0607]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_467                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_467;
    union { /* 0x960 [Excel Line :0608]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_468                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_468;
    union { /* 0x964 [Excel Line :0609]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_469                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_469;
    union { /* 0x968 [Excel Line :0610]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_470                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_470;
    union { /* 0x96c [Excel Line :0611]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_471                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_471;
    union { /* 0x970 [Excel Line :0612]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_472                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_472;
    union { /* 0x974 [Excel Line :0613]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_473                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_473;
    union { /* 0x978 [Excel Line :0614]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_474                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_474;
    union { /* 0x97c [Excel Line :0615]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_475                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_475;
    union { /* 0x980 [Excel Line :0616]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_476                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_476;
    union { /* 0x984 [Excel Line :0617]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_477                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_477;
    union { /* 0x988 [Excel Line :0618]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_478                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_478;
    union { /* 0x98c [Excel Line :0619]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_479                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_479;
    union { /* 0x990 [Excel Line :0620]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_480                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_480;
    union { /* 0x994 [Excel Line :0621]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_481                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_481;
    union { /* 0x998 [Excel Line :0622]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_482                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_482;
    union { /* 0x99c [Excel Line :0623]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_483                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_483;
    union { /* 0x9a0 [Excel Line :0624]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_484                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_484;
    union { /* 0x9a4 [Excel Line :0625]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_485                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_485;
    union { /* 0x9a8 [Excel Line :0626]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_486                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_486;
    union { /* 0x9ac [Excel Line :0627]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_487                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_487;
    union { /* 0x9b0 [Excel Line :0628]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_488                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_488;
    union { /* 0x9b4 [Excel Line :0629]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_489                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_489;
    union { /* 0x9b8 [Excel Line :0630]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_490                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_490;
    union { /* 0x9bc [Excel Line :0631]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_491                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_491;
    union { /* 0x9c0 [Excel Line :0632]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_492                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_492;
    union { /* 0x9c4 [Excel Line :0633]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_493                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_493;
    union { /* 0x9c8 [Excel Line :0634]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_494                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_494;
    union { /* 0x9cc [Excel Line :0635]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_495                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_495;
    union { /* 0x9d0 [Excel Line :0636]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_496                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_496;
    union { /* 0x9d4 [Excel Line :0637]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_497                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_497;
    union { /* 0x9d8 [Excel Line :0638]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_498                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_498;
    union { /* 0x9dc [Excel Line :0639]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_499                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_499;
    union { /* 0x9e0 [Excel Line :0640]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_500                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_500;
    union { /* 0x9e4 [Excel Line :0641]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_501                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_501;
    union { /* 0x9e8 [Excel Line :0642]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_502                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_502;
    union { /* 0x9ec [Excel Line :0643]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_503                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_503;
    union { /* 0x9f0 [Excel Line :0644]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_504                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_504;
    union { /* 0x9f4 [Excel Line :0645]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_505                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_505;
    union { /* 0x9f8 [Excel Line :0646]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_506                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_506;
    union { /* 0x9fc [Excel Line :0647]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_507                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_507;
    union { /* 0xa00 [Excel Line :0648]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_508                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_508;
    union { /* 0xa04 [Excel Line :0649]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_509                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_509;
    union { /* 0xa08 [Excel Line :0650]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_510                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_510;
    union { /* 0xa0c [Excel Line :0651]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_511                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_511;
    union { /* 0xa10 [Excel Line :0652]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_512                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_512;
    union { /* 0xa14 [Excel Line :0653]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_513                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_513;
    union { /* 0xa18 [Excel Line :0654]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_514                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_514;
    union { /* 0xa1c [Excel Line :0655]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_515                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_515;
    union { /* 0xa20 [Excel Line :0656]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_516                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_516;
    union { /* 0xa24 [Excel Line :0657]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_517                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_517;
    union { /* 0xa28 [Excel Line :0658]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_518                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_518;
    union { /* 0xa2c [Excel Line :0659]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_519                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_519;
    union { /* 0xa30 [Excel Line :0660]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_520                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_520;
    union { /* 0xa34 [Excel Line :0661]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_521                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_521;
    union { /* 0xa38 [Excel Line :0662]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_522                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_522;
    union { /* 0xa3c [Excel Line :0663]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_523                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_523;
    union { /* 0xa40 [Excel Line :0664]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_524                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_524;
    union { /* 0xa44 [Excel Line :0665]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_525                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_525;
    union { /* 0xa48 [Excel Line :0666]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_526                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_526;
    union { /* 0xa4c [Excel Line :0667]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_527                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_527;
    union { /* 0xa50 [Excel Line :0668]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_528                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_528;
    union { /* 0xa54 [Excel Line :0669]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_529                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_529;
    union { /* 0xa58 [Excel Line :0670]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_530                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_530;
    union { /* 0xa5c [Excel Line :0671]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_531                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_531;
    union { /* 0xa60 [Excel Line :0672]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_532                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_532;
    union { /* 0xa64 [Excel Line :0673]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_533                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_533;
    union { /* 0xa68 [Excel Line :0674]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_534                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_534;
    union { /* 0xa6c [Excel Line :0675]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_535                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_535;
    union { /* 0xa70 [Excel Line :0676]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_536                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_536;
    union { /* 0xa74 [Excel Line :0677]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_537                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_537;
    union { /* 0xa78 [Excel Line :0678]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_538                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_538;
    union { /* 0xa7c [Excel Line :0679]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_539                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_539;
    union { /* 0xa80 [Excel Line :0680]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_540                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_540;
    union { /* 0xa84 [Excel Line :0681]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_541                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_541;
    union { /* 0xa88 [Excel Line :0682]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_542                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_542;
    union { /* 0xa8c [Excel Line :0683]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_543                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_543;
    union { /* 0xa90 [Excel Line :0684]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_544                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_544;
    union { /* 0xa94 [Excel Line :0685]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_545                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_545;
    union { /* 0xa98 [Excel Line :0686]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_546                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_546;
    union { /* 0xa9c [Excel Line :0687]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_547                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_547;
    union { /* 0xaa0 [Excel Line :0688]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_548                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_548;
    union { /* 0xaa4 [Excel Line :0689]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_549                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_549;
    union { /* 0xaa8 [Excel Line :0690]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_550                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_550;
    union { /* 0xaac [Excel Line :0691]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_551                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_551;
    union { /* 0xab0 [Excel Line :0692]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_552                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_552;
    union { /* 0xab4 [Excel Line :0693]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_553                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_553;
    union { /* 0xab8 [Excel Line :0694]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_554                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_554;
    union { /* 0xabc [Excel Line :0695]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_555                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_555;
    union { /* 0xac0 [Excel Line :0696]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_556                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_556;
    union { /* 0xac4 [Excel Line :0697]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_557                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_557;
    union { /* 0xac8 [Excel Line :0698]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_558                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_558;
    union { /* 0xacc [Excel Line :0699]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_559                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_559;
    union { /* 0xad0 [Excel Line :0700]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_560                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_560;
    union { /* 0xad4 [Excel Line :0701]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_561                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_561;
    union { /* 0xad8 [Excel Line :0702]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_562                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_562;
    union { /* 0xadc [Excel Line :0703]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_563                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_563;
    union { /* 0xae0 [Excel Line :0704]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_564                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_564;
    union { /* 0xae4 [Excel Line :0705]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_565                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_565;
    union { /* 0xae8 [Excel Line :0706]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_566                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_566;
    union { /* 0xaec [Excel Line :0707]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_567                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_567;
    union { /* 0xaf0 [Excel Line :0708]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_568                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_568;
    union { /* 0xaf4 [Excel Line :0709]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_569                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_569;
    union { /* 0xaf8 [Excel Line :0710]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_570                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_570;
    union { /* 0xafc [Excel Line :0711]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_571                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_571;
    union { /* 0xb00 [Excel Line :0712]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_572                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_572;
    union { /* 0xb04 [Excel Line :0713]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_573                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_573;
    union { /* 0xb08 [Excel Line :0714]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_574                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_574;
    union { /* 0xb0c [Excel Line :0715]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_575                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_575;
    union { /* 0xb10 [Excel Line :0716]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_576                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_576;
    union { /* 0xb14 [Excel Line :0717]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_577                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_577;
    union { /* 0xb18 [Excel Line :0718]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_578                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_578;
    union { /* 0xb1c [Excel Line :0719]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_579                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_579;
    union { /* 0xb20 [Excel Line :0720]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_580                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_580;
    union { /* 0xb24 [Excel Line :0721]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_581                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_581;
    union { /* 0xb28 [Excel Line :0722]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_582                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_582;
    union { /* 0xb2c [Excel Line :0723]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_583                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_583;
    union { /* 0xb30 [Excel Line :0724]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_584                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_584;
    union { /* 0xb34 [Excel Line :0725]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_585                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_585;
    union { /* 0xb38 [Excel Line :0726]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_586                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_586;
    union { /* 0xb3c [Excel Line :0727]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_587                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_587;
    union { /* 0xb40 [Excel Line :0728]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_588                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_588;
    union { /* 0xb44 [Excel Line :0729]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_589                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_589;
    union { /* 0xb48 [Excel Line :0730]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_590                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_590;
    union { /* 0xb4c [Excel Line :0731]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_591                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_591;
    union { /* 0xb50 [Excel Line :0732]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_592                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_592;
    union { /* 0xb54 [Excel Line :0733]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_593                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_593;
    union { /* 0xb58 [Excel Line :0734]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_594                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_594;
    union { /* 0xb5c [Excel Line :0735]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_595                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_595;
    union { /* 0xb60 [Excel Line :0736]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_596                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_596;
    union { /* 0xb64 [Excel Line :0737]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_597                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_597;
    union { /* 0xb68 [Excel Line :0738]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_598                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_598;
    union { /* 0xb6c [Excel Line :0739]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_599                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_599;
    union { /* 0xb70 [Excel Line :0740]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_600                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_600;
    union { /* 0xb74 [Excel Line :0741]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_601                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_601;
    union { /* 0xb78 [Excel Line :0742]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_602                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_602;
    union { /* 0xb7c [Excel Line :0743]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_603                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_603;
    union { /* 0xb80 [Excel Line :0744]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_604                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_604;
    union { /* 0xb84 [Excel Line :0745]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_605                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_605;
    union { /* 0xb88 [Excel Line :0746]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_606                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_606;
    union { /* 0xb8c [Excel Line :0747]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_607                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_607;
    union { /* 0xb90 [Excel Line :0748]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_608                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_608;
    union { /* 0xb94 [Excel Line :0749]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_609                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_609;
    union { /* 0xb98 [Excel Line :0750]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_610                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_610;
    union { /* 0xb9c [Excel Line :0751]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_611                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_611;
    union { /* 0xba0 [Excel Line :0752]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_612                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_612;
    union { /* 0xba4 [Excel Line :0753]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_613                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_613;
    union { /* 0xba8 [Excel Line :0754]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_614                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_614;
    union { /* 0xbac [Excel Line :0755]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_615                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_615;
    union { /* 0xbb0 [Excel Line :0756]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_616                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_616;
    union { /* 0xbb4 [Excel Line :0757]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_617                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_617;
    union { /* 0xbb8 [Excel Line :0758]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_618                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_618;
    union { /* 0xbbc [Excel Line :0759]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_619                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_619;
    union { /* 0xbc0 [Excel Line :0760]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_620                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_620;
    union { /* 0xbc4 [Excel Line :0761]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_621                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_621;
    union { /* 0xbc8 [Excel Line :0762]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_622                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_622;
    union { /* 0xbcc [Excel Line :0763]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_623                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_623;
    union { /* 0xbd0 [Excel Line :0764]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_624                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_624;
    union { /* 0xbd4 [Excel Line :0765]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_625                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_625;
    union { /* 0xbd8 [Excel Line :0766]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_626                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_626;
    union { /* 0xbdc [Excel Line :0767]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_627                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_627;
    union { /* 0xbe0 [Excel Line :0768]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_628                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_628;
    union { /* 0xbe4 [Excel Line :0769]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_629                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_629;
    union { /* 0xbe8 [Excel Line :0770]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_630                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_630;
    union { /* 0xbec [Excel Line :0771]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_631                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_631;
    union { /* 0xbf0 [Excel Line :0772]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_632                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_632;
    union { /* 0xbf4 [Excel Line :0773]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_633                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_633;
    union { /* 0xbf8 [Excel Line :0774]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_634                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_634;
    union { /* 0xbfc [Excel Line :0775]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_635                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_635;
    union { /* 0xc00 [Excel Line :0776]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_636                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_636;
    union { /* 0xc04 [Excel Line :0777]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_637                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_637;
    union { /* 0xc08 [Excel Line :0778]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_638                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_638;
    union { /* 0xc0c [Excel Line :0779]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_639                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_639;
    union { /* 0xc10 [Excel Line :0780]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_640                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_640;
    union { /* 0xc14 [Excel Line :0781]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_641                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_641;
    union { /* 0xc18 [Excel Line :0782]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_642                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_642;
    union { /* 0xc1c [Excel Line :0783]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_643                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_643;
    union { /* 0xc20 [Excel Line :0784]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_644                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_644;
    union { /* 0xc24 [Excel Line :0785]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_645                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_645;
    union { /* 0xc28 [Excel Line :0786]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_646                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_646;
    union { /* 0xc2c [Excel Line :0787]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_647                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_647;
    union { /* 0xc30 [Excel Line :0788]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_648                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_648;
    union { /* 0xc34 [Excel Line :0789]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_649                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_649;
    union { /* 0xc38 [Excel Line :0790]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_650                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_650;
    union { /* 0xc3c [Excel Line :0791]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_651                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_651;
    union { /* 0xc40 [Excel Line :0792]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_652                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_652;
    union { /* 0xc44 [Excel Line :0793]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_653                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_653;
    union { /* 0xc48 [Excel Line :0794]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_654                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_654;
    union { /* 0xc4c [Excel Line :0795]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_655                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_655;
    union { /* 0xc50 [Excel Line :0796]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_656                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_656;
    union { /* 0xc54 [Excel Line :0797]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_657                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_657;
    union { /* 0xc58 [Excel Line :0798]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_658                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_658;
    union { /* 0xc5c [Excel Line :0799]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_659                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_659;
    union { /* 0xc60 [Excel Line :0800]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_660                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_660;
    union { /* 0xc64 [Excel Line :0801]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_661                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_661;
    union { /* 0xc68 [Excel Line :0802]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_662                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_662;
    union { /* 0xc6c [Excel Line :0803]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_663                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_663;
    union { /* 0xc70 [Excel Line :0804]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_664                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_664;
    union { /* 0xc74 [Excel Line :0805]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_665                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_665;
    union { /* 0xc78 [Excel Line :0806]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_666                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_666;
    union { /* 0xc7c [Excel Line :0807]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_667                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_667;
    union { /* 0xc80 [Excel Line :0808]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_668                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_668;
    union { /* 0xc84 [Excel Line :0809]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_669                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_669;
    union { /* 0xc88 [Excel Line :0810]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_670                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_670;
    union { /* 0xc8c [Excel Line :0811]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_671                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_671;
    union { /* 0xc90 [Excel Line :0812]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_672                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_672;
    union { /* 0xc94 [Excel Line :0813]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_673                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_673;
    union { /* 0xc98 [Excel Line :0814]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_674                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_674;
    union { /* 0xc9c [Excel Line :0815]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_675                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_675;
    union { /* 0xca0 [Excel Line :0816]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_676                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_676;
    union { /* 0xca4 [Excel Line :0817]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_677                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_677;
    union { /* 0xca8 [Excel Line :0818]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_678                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_678;
    union { /* 0xcac [Excel Line :0819]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_679                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_679;
    union { /* 0xcb0 [Excel Line :0820]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_680                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_680;
    union { /* 0xcb4 [Excel Line :0821]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_681                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_681;
    union { /* 0xcb8 [Excel Line :0822]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_682                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_682;
    union { /* 0xcbc [Excel Line :0823]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_683                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_683;
    union { /* 0xcc0 [Excel Line :0824]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_684                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_684;
    union { /* 0xcc4 [Excel Line :0825]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_685                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_685;
    union { /* 0xcc8 [Excel Line :0826]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_686                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_686;
    union { /* 0xccc [Excel Line :0827]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_687                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_687;
    union { /* 0xcd0 [Excel Line :0828]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_688                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_688;
    union { /* 0xcd4 [Excel Line :0829]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_689                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_689;
    union { /* 0xcd8 [Excel Line :0830]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_690                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_690;
    union { /* 0xcdc [Excel Line :0831]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_691                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_691;
    union { /* 0xce0 [Excel Line :0832]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_692                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_692;
    union { /* 0xce4 [Excel Line :0833]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_693                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_693;
    union { /* 0xce8 [Excel Line :0834]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_694                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_694;
    union { /* 0xcec [Excel Line :0835]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_695                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_695;
    union { /* 0xcf0 [Excel Line :0836]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_696                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_696;
    union { /* 0xcf4 [Excel Line :0837]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_697                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_697;
    union { /* 0xcf8 [Excel Line :0838]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_698                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_698;
    union { /* 0xcfc [Excel Line :0839]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_699                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_699;
    union { /* 0xd00 [Excel Line :0840]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_700                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_700;
    union { /* 0xd04 [Excel Line :0841]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_701                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_701;
    union { /* 0xd08 [Excel Line :0842]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_702                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_702;
    union { /* 0xd0c [Excel Line :0843]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_703                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_703;
    union { /* 0xd10 [Excel Line :0844]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_704                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_704;
    union { /* 0xd14 [Excel Line :0845]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_705                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_705;
    union { /* 0xd18 [Excel Line :0846]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_706                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_706;
    union { /* 0xd1c [Excel Line :0847]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_707                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_707;
    union { /* 0xd20 [Excel Line :0848]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_708                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_708;
    union { /* 0xd24 [Excel Line :0849]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_709                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_709;
    union { /* 0xd28 [Excel Line :0850]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_710                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_710;
    union { /* 0xd2c [Excel Line :0851]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_711                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_711;
    union { /* 0xd30 [Excel Line :0852]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_712                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_712;
    union { /* 0xd34 [Excel Line :0853]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_713                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_713;
    union { /* 0xd38 [Excel Line :0854]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_714                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_714;
    union { /* 0xd3c [Excel Line :0855]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_715                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_715;
    union { /* 0xd40 [Excel Line :0856]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_716                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_716;
    union { /* 0xd44 [Excel Line :0857]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_717                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_717;
    union { /* 0xd48 [Excel Line :0858]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_718                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_718;
    union { /* 0xd4c [Excel Line :0859]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_719                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_719;
    union { /* 0xd50 [Excel Line :0860]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_720                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_720;
    union { /* 0xd54 [Excel Line :0861]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_721                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_721;
    union { /* 0xd58 [Excel Line :0862]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_722                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_722;
    union { /* 0xd5c [Excel Line :0863]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_723                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_723;
    union { /* 0xd60 [Excel Line :0864]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_724                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_724;
    union { /* 0xd64 [Excel Line :0865]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_725                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_725;
    union { /* 0xd68 [Excel Line :0866]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_726                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_726;
    union { /* 0xd6c [Excel Line :0867]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_727                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_727;
    union { /* 0xd70 [Excel Line :0868]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_728                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_728;
    union { /* 0xd74 [Excel Line :0869]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_729                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_729;
    union { /* 0xd78 [Excel Line :0870]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_730                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_730;
    union { /* 0xd7c [Excel Line :0871]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_731                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_731;
    union { /* 0xd80 [Excel Line :0872]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_732                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_732;
    union { /* 0xd84 [Excel Line :0873]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_733                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_733;
    union { /* 0xd88 [Excel Line :0874]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_734                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_734;
    union { /* 0xd8c [Excel Line :0875]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_735                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_735;
    union { /* 0xd90 [Excel Line :0876]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_736                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_736;
    union { /* 0xd94 [Excel Line :0877]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_737                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_737;
    union { /* 0xd98 [Excel Line :0878]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_738                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_738;
    union { /* 0xd9c [Excel Line :0879]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_739                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_739;
    union { /* 0xda0 [Excel Line :0880]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_740                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_740;
    union { /* 0xda4 [Excel Line :0881]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_741                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_741;
    union { /* 0xda8 [Excel Line :0882]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_742                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_742;
    union { /* 0xdac [Excel Line :0883]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_743                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_743;
    union { /* 0xdb0 [Excel Line :0884]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_744                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_744;
    union { /* 0xdb4 [Excel Line :0885]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_745                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_745;
    union { /* 0xdb8 [Excel Line :0886]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_746                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_746;
    union { /* 0xdbc [Excel Line :0887]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_747                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_747;
    union { /* 0xdc0 [Excel Line :0888]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_748                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_748;
    union { /* 0xdc4 [Excel Line :0889]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_749                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_749;
    union { /* 0xdc8 [Excel Line :0890]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_750                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_750;
    union { /* 0xdcc [Excel Line :0891]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_751                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_751;
    union { /* 0xdd0 [Excel Line :0892]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_752                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_752;
    union { /* 0xdd4 [Excel Line :0893]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_753                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_753;
    union { /* 0xdd8 [Excel Line :0894]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_754                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_754;
    union { /* 0xddc [Excel Line :0895]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_755                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_755;
    union { /* 0xde0 [Excel Line :0896]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_756                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_756;
    union { /* 0xde4 [Excel Line :0897]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_757                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_757;
    union { /* 0xde8 [Excel Line :0898]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_758                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_758;
    union { /* 0xdec [Excel Line :0899]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_759                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_759;
    union { /* 0xdf0 [Excel Line :0900]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_760                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_760;
    union { /* 0xdf4 [Excel Line :0901]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_761                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_761;
    union { /* 0xdf8 [Excel Line :0902]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_762                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_762;
    union { /* 0xdfc [Excel Line :0903]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_763                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_763;
    union { /* 0xe00 [Excel Line :0904]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_764                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_764;
    union { /* 0xe04 [Excel Line :0905]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_765                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_765;
    union { /* 0xe08 [Excel Line :0906]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_766                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_766;
    union { /* 0xe0c [Excel Line :0907]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_767                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_767;
    union { /* 0xe10 [Excel Line :0908]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_768                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_768;
    union { /* 0xe14 [Excel Line :0909]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_769                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_769;
    union { /* 0xe18 [Excel Line :0910]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_770                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_770;
    union { /* 0xe1c [Excel Line :0911]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_771                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_771;
    union { /* 0xe20 [Excel Line :0912]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_772                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_772;
    union { /* 0xe24 [Excel Line :0913]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_773                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_773;
    union { /* 0xe28 [Excel Line :0914]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_774                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_774;
    union { /* 0xe2c [Excel Line :0915]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_775                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_775;
    union { /* 0xe30 [Excel Line :0916]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_776                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_776;
    union { /* 0xe34 [Excel Line :0917]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_777                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_777;
    union { /* 0xe38 [Excel Line :0918]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_778                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_778;
    union { /* 0xe3c [Excel Line :0919]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_779                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_779;
    union { /* 0xe40 [Excel Line :0920]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_780                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_780;
    union { /* 0xe44 [Excel Line :0921]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_781                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_781;
    union { /* 0xe48 [Excel Line :0922]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_782                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_782;
    union { /* 0xe4c [Excel Line :0923]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_783                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_783;
    union { /* 0xe50 [Excel Line :0924]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_784                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_784;
    union { /* 0xe54 [Excel Line :0925]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_785                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_785;
    union { /* 0xe58 [Excel Line :0926]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_786                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_786;
    union { /* 0xe5c [Excel Line :0927]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_787                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_787;
    union { /* 0xe60 [Excel Line :0928]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_788                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_788;
    union { /* 0xe64 [Excel Line :0929]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_789                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_789;
    union { /* 0xe68 [Excel Line :0930]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_790                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_790;
    union { /* 0xe6c [Excel Line :0931]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_791                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_791;
    union { /* 0xe70 [Excel Line :0932]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_792                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_792;
    union { /* 0xe74 [Excel Line :0933]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_793                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_793;
    union { /* 0xe78 [Excel Line :0934]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_794                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_794;
    union { /* 0xe7c [Excel Line :0935]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_795                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_795;
    union { /* 0xe80 [Excel Line :0936]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_796                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_796;
    union { /* 0xe84 [Excel Line :0937]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_797                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_797;
    union { /* 0xe88 [Excel Line :0938]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_798                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_798;
    union { /* 0xe8c [Excel Line :0939]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_799                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_799;
    union { /* 0xe90 [Excel Line :0940]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_800                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_800;
    union { /* 0xe94 [Excel Line :0941]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_801                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_801;
    union { /* 0xe98 [Excel Line :0942]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_802                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_802;
    union { /* 0xe9c [Excel Line :0943]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_803                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_803;
    union { /* 0xea0 [Excel Line :0944]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_804                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_804;
    union { /* 0xea4 [Excel Line :0945]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_805                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_805;
    union { /* 0xea8 [Excel Line :0946]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_806                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_806;
    union { /* 0xeac [Excel Line :0947]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_807                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_807;
    union { /* 0xeb0 [Excel Line :0948]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_808                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_808;
    union { /* 0xeb4 [Excel Line :0949]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_809                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_809;
    union { /* 0xeb8 [Excel Line :0950]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_810                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_810;
    union { /* 0xebc [Excel Line :0951]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_811                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_811;
    union { /* 0xec0 [Excel Line :0952]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_812                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_812;
    union { /* 0xec4 [Excel Line :0953]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_813                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_813;
    union { /* 0xec8 [Excel Line :0954]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_814                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_814;
    union { /* 0xecc [Excel Line :0955]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_815                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_815;
    union { /* 0xed0 [Excel Line :0956]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_816                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_816;
    union { /* 0xed4 [Excel Line :0957]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_817                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_817;
    union { /* 0xed8 [Excel Line :0958]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_818                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_818;
    union { /* 0xedc [Excel Line :0959]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_819                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_819;
    union { /* 0xee0 [Excel Line :0960]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_820                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_820;
    union { /* 0xee4 [Excel Line :0961]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_821                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_821;
    union { /* 0xee8 [Excel Line :0962]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_822                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_822;
    union { /* 0xeec [Excel Line :0963]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_823                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_823;
    union { /* 0xef0 [Excel Line :0964]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_824                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_824;
    union { /* 0xef4 [Excel Line :0965]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_825                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_825;
    union { /* 0xef8 [Excel Line :0966]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_826                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_826;
    union { /* 0xefc [Excel Line :0967]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_827                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_827;
    union { /* 0xf00 [Excel Line :0968]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_828                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_828;
    union { /* 0xf04 [Excel Line :0969]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_829                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_829;
    union { /* 0xf08 [Excel Line :0970]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_830                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_830;
    union { /* 0xf0c [Excel Line :0971]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_831                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_831;
    union { /* 0xf10 [Excel Line :0972]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_832                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_832;
    union { /* 0xf14 [Excel Line :0973]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_833                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_833;
    union { /* 0xf18 [Excel Line :0974]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_834                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_834;
    union { /* 0xf1c [Excel Line :0975]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_835                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_835;
    union { /* 0xf20 [Excel Line :0976]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_836                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_836;
    union { /* 0xf24 [Excel Line :0977]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_837                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_837;
    union { /* 0xf28 [Excel Line :0978]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_838                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_838;
    union { /* 0xf2c [Excel Line :0979]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_839                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_839;
    union { /* 0xf30 [Excel Line :0980]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_840                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_840;
    union { /* 0xf34 [Excel Line :0981]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_841                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_841;
    union { /* 0xf38 [Excel Line :0982]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_842                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_842;
    union { /* 0xf3c [Excel Line :0983]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_843                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_843;
    union { /* 0xf40 [Excel Line :0984]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_844                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_844;
    union { /* 0xf44 [Excel Line :0985]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_845                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_845;
    union { /* 0xf48 [Excel Line :0986]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_846                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_846;
    union { /* 0xf4c [Excel Line :0987]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_847                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_847;
    union { /* 0xf50 [Excel Line :0988]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_848                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_848;
    union { /* 0xf54 [Excel Line :0989]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_849                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_849;
    union { /* 0xf58 [Excel Line :0990]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_850                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_850;
    union { /* 0xf5c [Excel Line :0991]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_851                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_851;
    union { /* 0xf60 [Excel Line :0992]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_852                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_852;
    union { /* 0xf64 [Excel Line :0993]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_853                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_853;
    union { /* 0xf68 [Excel Line :0994]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_854                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_854;
    union { /* 0xf6c [Excel Line :0995]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_855                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_855;
    union { /* 0xf70 [Excel Line :0996]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_856                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_856;
    union { /* 0xf74 [Excel Line :0997]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_857                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_857;
    union { /* 0xf78 [Excel Line :0998]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_858                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_858;
    union { /* 0xf7c [Excel Line :0999]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_859                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_859;
    union { /* 0xf80 [Excel Line :1000]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_860                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_860;
    union { /* 0xf84 [Excel Line :1001]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_861                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_861;
    union { /* 0xf88 [Excel Line :1002]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_862                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_862;
    union { /* 0xf8c [Excel Line :1003]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_863                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_863;
    union { /* 0xf90 [Excel Line :1004]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_864                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_864;
    union { /* 0xf94 [Excel Line :1005]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_865                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_865;
    union { /* 0xf98 [Excel Line :1006]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_866                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_866;
    union { /* 0xf9c [Excel Line :1007]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_867                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_867;
    union { /* 0xfa0 [Excel Line :1008]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_868                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_868;
    union { /* 0xfa4 [Excel Line :1009]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_869                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_869;
    union { /* 0xfa8 [Excel Line :1010]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_870                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_870;
    union { /* 0xfac [Excel Line :1011]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_871                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_871;
    union { /* 0xfb0 [Excel Line :1012]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_872                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_872;
    union { /* 0xfb4 [Excel Line :1013]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_873                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_873;
    union { /* 0xfb8 [Excel Line :1014]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_874                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_874;
    union { /* 0xfbc [Excel Line :1015]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_875                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_875;
    union { /* 0xfc0 [Excel Line :1016]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_876                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_876;
    union { /* 0xfc4 [Excel Line :1017]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_877                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_877;
    union { /* 0xfc8 [Excel Line :1018]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_878                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_878;
    union { /* 0xfcc [Excel Line :1019]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_879                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_879;
    union { /* 0xfd0 [Excel Line :1020]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_880                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_880;
    union { /* 0xfd4 [Excel Line :1021]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_881                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_881;
    union { /* 0xfd8 [Excel Line :1022]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_882                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_882;
    union { /* 0xfdc [Excel Line :1023]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_883                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_883;
    union { /* 0xfe0 [Excel Line :1024]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_884                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_884;
    union { /* 0xfe4 [Excel Line :1025]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_885                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_885;
    union { /* 0xfe8 [Excel Line :1026]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_886                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_886;
    union { /* 0xfec [Excel Line :1027]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_887                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_887;
    union { /* 0xff0 [Excel Line :1028]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_888                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_888;
    union { /* 0xff4 [Excel Line :1029]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_889                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_889;
    union { /* 0xff8 [Excel Line :1030]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_890                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_890;
    union { /* 0xffc [Excel Line :1031]  */
        UINT32 Reg;
        struct {
            UINT32 ESW_REGION_891                                                         : 32;     /* [ 31:0]  */
        }Bit;
    }ESW_REGION_891;
    union { /* 0x1000 [Excel Line :1032]  */
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
    union { /* 0x1004 [Excel Line :1040]  */
        UINT32 Reg;
        struct {
            UINT32 NP2                                                                    : 5;      /* [  4:0]  */
            UINT32 MICRO_EN_CNT                                                           : 6;      /* [ 10:5]  */
            UINT32 RESPONSE_CON                                                           : 2;      /* [12:11]  */
            UINT32 PRE_READING_START                                                      : 1;      /* [   13]  */
            UINT32 RESERVED1                                                              : 18;     /* [31:14]  */
        }Bit;
    }OTP_CON_CONFIG;
    union { /* 0x1008 [Excel Line :1045]  */
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
    union { /* 0x100c [Excel Line :1051]  */
        UINT32 Reg;
        struct {
            UINT32 ADDRESS                                                                : 11;     /* [ 10:0]  */
            UINT32 RESERVED1                                                              : 20;     /* [30:11]  */
            UINT32 PROGRAM_DATA                                                           : 1;      /* [   31]  */
        }Bit;
    }OTP_IF;
    union { /* 0x1010 [Excel Line :1054]  */
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
    union { /* 0x1014 [Excel Line :1066]  */
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
    union { /* 0x1018 [Excel Line :1078]  */
        UINT32 Reg;
        struct {
            UINT32 TCRST                                                                  : 16;     /* [ 15:0]  */
            UINT32 TRW                                                                    : 16;     /* [31:16]  */
        }Bit;
    }OTP_CON_TIME_PARA_0;
    union { /* 0x101c [Excel Line :1080]  */
        UINT32 Reg;
        struct {
            UINT32 TPW                                                                    : 16;     /* [ 15:0]  */
            UINT32 TCWL                                                                   : 16;     /* [31:16]  */
        }Bit;
    }OTP_CON_TIME_PARA_1;
    union { /* 0x1020 [Excel Line :1082]  */
        UINT32 Reg;
        struct {
            UINT32 TDH                                                                    : 8;      /* [  7:0]  */
            UINT32 TWWH                                                                   : 8;      /* [ 15:8]  */
            UINT32 TWWL                                                                   : 8;      /* [23:16]  */
            UINT32 TAS                                                                    : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_2;
    union { /* 0x1024 [Excel Line :1086]  */
        UINT32 Reg;
        struct {
            UINT32 TCPH                                                                   : 8;      /* [  7:0]  */
            UINT32 TCWH                                                                   : 8;      /* [ 15:8]  */
            UINT32 TCPS                                                                   : 8;      /* [23:16]  */
            UINT32 TPES                                                                   : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_3;
    union { /* 0x1028 [Excel Line :1090]  */
        UINT32 Reg;
        struct {
            UINT32 TPGRST                                                                 : 8;      /* [  7:0]  */
            UINT32 TAH                                                                    : 8;      /* [ 15:8]  */
            UINT32 TPGML                                                                  : 8;      /* [23:16]  */
            UINT32 TPEH                                                                   : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_4;
    union { /* 0x102c [Excel Line :1094]  */
        UINT32 Reg;
        struct {
            UINT32 TPGVFY                                                                 : 8;      /* [  7:0]  */
            UINT32 TREW                                                                   : 8;      /* [ 15:8]  */
            UINT32 TRD                                                                    : 8;      /* [23:16]  */
            UINT32 TPGRD                                                                  : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_5;
    union { /* 0x1030 [Excel Line :1098]  */
        UINT32 Reg;
        struct {
            UINT32 TCLEH                                                                  : 8;      /* [  7:0]  */
            UINT32 TCLES                                                                  : 8;      /* [ 15:8]  */
            UINT32 TTWS                                                                   : 8;      /* [23:16]  */
            UINT32 TPGMAS                                                                 : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_6;
    union { /* 0x1034 [Excel Line :1102]  */
        UINT32 Reg;
        struct {
            UINT32 TLBV                                                                   : 16;     /* [ 15:0]  */
            UINT32 TPGL                                                                   : 8;      /* [23:16]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }OTP_CON_TIME_PARA_7;
    union { /* 0x1038 [Excel Line :1105]  */
        UINT32 Reg;
        struct {
            UINT32 SECURE_READ_DATA                                                       : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_IF_SECURE_READ_DATA;
    union { /* 0x103c [Excel Line :1106]  */
        UINT32 Reg;
        struct {
            UINT32 NONSECURE_READ_DATA                                                    : 32;     /* [ 31:0]  */
        }Bit;
    }OTP_IF_NONSECURE_READ_DATA;
}DRV_A6_OTP32K_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_A6_OTP32K_REGISTER* const RegA6_OTP32K = (DRV_A6_OTP32K_REGISTER*)APACHE_A6_OTP32K_BASE_ADDR;
 */



#endif /* end of  DRV_REGISTER_A6_OTP32K__ */

