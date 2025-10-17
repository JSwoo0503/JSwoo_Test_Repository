
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_A6_HSP_SCU_Register.h
*   Date       : 2022-07-27 21:27
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_HSP_SCU_H__
#define DRV_REGISTER_A6_HSP_SCU_H__

#define APACHE_A6_HSP_SCU_BASE_ADDR        0x06610000

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

    UINT8 EMPTY1[756]; /* 0x2F4 */

    union { /* 0x300 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 SHIFT_SEL_SD_PAD_OUT                                                   : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }SD_PAD_OUT_SHIFT;
    union { /* 0x304 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 SHIFT_SEL_EMMC_PAD_OUT                                                 : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }EMMC_PAD_OUT_SHIFT;

    UINT8 EMPTY2[760]; /* 0x2F8 */

    union { /* 0x0600 [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SD_AHB                                                      : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SD_AHB_CLKDIV;
    union { /* 0x0604 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SD_AXI                                                      : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SD_AXI_CLKDIV;
    union { /* 0x0608 [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SD_CORE                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SD_CORE_CLKDIV;
    union { /* 0x060C [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SD_IO                                                       : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SD_IO_CLKDIV;
    union { /* 0x0610 [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_SD_TIMER                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }SD_TIMER_CLKDIV;
    union { /* 0x0614 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_AHB                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_AHB_CLKDIV;
    union { /* 0x0618 [Excel Line :0027]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_AXI                                                    : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_AXI_CLKDIV;
    union { /* 0x061C [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_CORE                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_CORE_CLKDIV;
    union { /* 0x0620 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_IO                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_IO_CLKDIV;
    union { /* 0x0624 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_TIMER                                                  : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_TIMER_CLKDIV;
    union { /* 0x0628 [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_EMMC_CQETIMER                                               : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }EMMC_CQETIMER_CLKDIV;
    union { /* 0x062C [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_ETH_AXI                                                     : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_AXI_CLKDIV;
    union { /* 0x0630 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_ETH_IO                                                      : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_IO_CLKDIV;
    union { /* 0x0634 [Excel Line :0041]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_PTP_REF                                                : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_PTP_REF_CLKDIV;
    union { /* 0x0638 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_RGMII_TX0                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_RGMII_TX0_CLKDIV;
    union { /* 0x063C [Excel Line :0045]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_RGMII_TX1                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_RGMII_TX1_CLKDIV;
    union { /* 0x0640 [Excel Line :0047]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_RGMII_TX2                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_RGMII_TX2_CLKDIV;
    union { /* 0x0644 [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_RMII_DIVCLK                                            : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_RMII_DIVCLK_CLKDIV;
    union { /* 0x0648 [Excel Line :0051]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_GMAC_RMII_PRE1                                              : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_RMII_PRE1_CLKDIV;

    UINT8 EMPTY3[180]; /* 0xB4 */

    union { /* 0x0700 [Excel Line :0053]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_HSP_PRE1                                                    : 2;      /* [  1:0]  */
            UINT32 RESERVED3                                                              : 2;      /* [  3:2]  */
            UINT32 CLKMUX_SEL_HSP_PRE2                                                    : 2;      /* [  5:4]  */
            UINT32 RESERVED2                                                              : 2;      /* [  7:6]  */
            UINT32 CLKMUX_SEL_ETH_PRE1                                                    : 2;      /* [  9:8]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }HSP_PRE_CLKMUX;
    union { /* 0x0704 [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_GMAC_RMII_PRE2                                              : 1;      /* [    0]  */
            UINT32 CLKMUX_SEL_GMAC_RGMII_TX1                                              : 1;      /* [    1]  */
            UINT32 CLKMUX_SEL_GMAC_RGMII_TX0                                              : 1;      /* [    2]  */
            UINT32 CLKMUX_SEL_GMAC_PTP_REF                                                : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }GMAC_CLKMUX;

    UINT8 EMPTY4[248]; /* 0xF8 */

    union { /* 0x0800 [Excel Line :0064]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                              : 1;      /* [    0]  */
            UINT32 CLKEN_SD_TIMER                                                         : 1;      /* [    1]  */
            UINT32 CLKEN_SD_PAD_OUT                                                       : 1;      /* [    2]  */
            UINT32 CLKEN_SD_RX                                                            : 1;      /* [    3]  */
            UINT32 CLKEN_SD_TX                                                            : 1;      /* [    4]  */
            UINT32 CLKEN_SD_CORE2                                                         : 1;      /* [    5]  */
            UINT32 CLKEN_SD_CORE                                                          : 1;      /* [    6]  */
            UINT32 CLKEN_SD_IO                                                            : 1;      /* [    7]  */
            UINT32 CLKEN_SD_AHB                                                           : 1;      /* [    8]  */
            UINT32 CLKEN_SD_AXI                                                           : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }SD_CLKEN;
    union { /* 0x0804 [Excel Line :0075]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_EMMC_CQETIMER                                                    : 1;      /* [    0]  */
            UINT32 CLKEN_EMMC_TIMER                                                       : 1;      /* [    1]  */
            UINT32 CLKEN_EMMC_PAD_OUT                                                     : 1;      /* [    2]  */
            UINT32 CLKEN_EMMC_RX                                                          : 1;      /* [    3]  */
            UINT32 CLKEN_EMMC_TX                                                          : 1;      /* [    4]  */
            UINT32 CLKEN_EMMC_CORE2                                                       : 1;      /* [    5]  */
            UINT32 CLKEN_EMMC_CORE                                                        : 1;      /* [    6]  */
            UINT32 CLKEN_EMMC_IO                                                          : 1;      /* [    7]  */
            UINT32 CLKEN_EMMC_AHB                                                         : 1;      /* [    8]  */
            UINT32 CLKEN_EMMC_AXI                                                         : 1;      /* [    9]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }EMMC_CLKEN;
    union { /* 0x0808 [Excel Line :0086]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_GMAC_PTP_REF                                                     : 1;      /* [    0]  */
            UINT32 CLKEN_GMAC_RMII_DIVCLK                                                 : 1;      /* [    1]  */
            UINT32 CLKEN_GMAC_RGMII_TX                                                    : 1;      /* [    2]  */
            UINT32 CLKEN_GMAC_RMII                                                        : 1;      /* [    3]  */
            UINT32 CLKEN_ETHERNET_TX_CLK                                                  : 1;      /* [    4]  */
            UINT32 CLKEN_ETHERNET_TX_INV_CLK                                              : 1;      /* [    5]  */
            UINT32 CLKEN_ETHERNET_RX_CLK                                                  : 1;      /* [    6]  */
            UINT32 CLKEN_ETHERNET_RX_INV_CLK                                              : 1;      /* [    7]  */
            UINT32 CLKEN_ETH_IO                                                           : 1;      /* [    8]  */
            UINT32 CLKEN_ETH_AXI                                                          : 1;      /* [    9]  */
            UINT32 RESERVED2                                                              : 2;      /* [11:10]  */
            UINT32 CLKEN_ETHERNET_RMII_CLKOUT                                             : 1;      /* [   12]  */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }GMAC_CLKEN;

    UINT8 EMPTY5[500]; /* 0x1F4 */

    union { /* 0x0A00 [Excel Line :0099]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_AHB                                                    : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_AHB                                                  : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_AHB_ONGO_RST_ACT;
    union { /* 0x0A04 [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_AXI                                                    : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_AXI                                                  : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_ETH_AXI                                                   : 1;      /* [    2]  */
            UINT32 ONGO_RST_ACT_ETH_BUS_AXI                                               : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }HSP_AXI_ONGO_RST_ACT;
    union { /* 0x0A08 [Excel Line :0107]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_CORE                                                   : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_CORE                                                 : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_CORE_ONGO_RST_ACT;
    union { /* 0x0A0C [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_TX                                                     : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_TX                                                   : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_TX_ONGO_RST_ACT;
    union { /* 0x0A10 [Excel Line :0113]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_RX                                                     : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_RX                                                   : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_RX_ONGO_RST_ACT;
    union { /* 0x0A14 [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_SD_TIMER                                                  : 1;      /* [    0]  */
            UINT32 ONGO_RST_ACT_EMMC_TIMER                                                : 1;      /* [    1]  */
            UINT32 ONGO_RST_ACT_EMMC_CQETIMER                                             : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }HSP_TIMER_ONGO_RST_ACT;

    UINT8 EMPTY6[232]; /* 0xE8 */

    union { /* 0x0B00 [Excel Line :0120]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_AHB                                                     : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_AHB                                                   : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_AHB_PUL_RST_ACT;
    union { /* 0x0B04 [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_AXI                                                     : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_AXI                                                   : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_ETH_AXI                                                    : 1;      /* [    2]  */
            UINT32 PUL_RST_ACT_ETH_BUS_AXI                                                : 1;      /* [    3]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }HSP_AXI_PUL_RST_ACT;
    union { /* 0x0B08 [Excel Line :0128]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_CORE                                                    : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_CORE                                                  : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_CORE_PUL_RST_ACT;
    union { /* 0x0B0C [Excel Line :0131]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_TX                                                      : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_TX                                                    : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_TX_PUL_RST_ACT;
    union { /* 0x0B10 [Excel Line :0134]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_RX                                                      : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_RX                                                    : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }HSP_RX_PUL_RST_ACT;
    union { /* 0x0B14 [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_SD_TIMER                                                   : 1;      /* [    0]  */
            UINT32 PUL_RST_ACT_EMMC_TIMER                                                 : 1;      /* [    1]  */
            UINT32 PUL_RST_ACT_EMMC_CQETIMER                                              : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }HSP_TIMER_PUL_RST_ACT;

    UINT8 EMPTY7[232]; /* 0xE8 */

    union { /* 0x0C00 [Excel Line :0141]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_AHB                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_AHB_PUL_RST_WIDTH;
    union { /* 0x0C04 [Excel Line :0143]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_AHB                                                   : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_AHB_PUL_RST_WIDTH;
    union { /* 0x0C08 [Excel Line :0145]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ETH_BUS_AXI                                              : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ETH_BUS_AXI_PUL_RST_WIDTH;
    union { /* 0x0C0C [Excel Line :0147]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_ETH_AXI                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }ETH_AXI_PUL_RST_WIDTH;
    union { /* 0x0C10 [Excel Line :0149]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_AXI                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_AXI_PUL_RST_WIDTH;
    union { /* 0x0C14 [Excel Line :0151]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_AXI                                                   : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_AXI_PUL_RST_WIDTH;
    union { /* 0x0C18 [Excel Line :0153]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_CORE                                                : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_CORE_PUL_RST_WIDTH;
    union { /* 0x0C1C [Excel Line :0155]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_CORE                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_CORE_PUL_RST_WIDTH;
    union { /* 0x0C20 [Excel Line :0157]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_TX                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_TX_PUL_RST_WIDTH;
    union { /* 0x0C24 [Excel Line :0159]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_TX                                                    : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_TX_PUL_RST_WIDTH;
    union { /* 0x0C28 [Excel Line :0161]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_RX                                                  : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_RX_PUL_RST_WIDTH;
    union { /* 0x0C2C [Excel Line :0163]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_RX                                                    : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_RX_PUL_RST_WIDTH;
    union { /* 0x0C30 [Excel Line :0165]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_CQETIMER                                            : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_CQETIMER_PUL_RST_WIDTH;
    union { /* 0x0C34 [Excel Line :0167]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_EMMC_TIMER                                               : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }EMMC_TIMER_PUL_RST_WIDTH;
    union { /* 0x0C38 [Excel Line :0169]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_SD_TIMER                                                 : 16;     /* [ 15:0]  */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }SD_TIMER_PUL_RST_WIDTH;

    UINT8 EMPTY8[196]; /* 0xC4 */

    union { /* 0x0D00 [Excel Line :0171]  */
        UINT32 Reg;
        struct {
            UINT32 RST_READ_SD_TIMER                                                      : 1;      /* [    0]  */
            UINT32 RST_READ_EMMC_TIMER                                                    : 1;      /* [    1]  */
            UINT32 RST_READ_EMMC_CQETIMER                                                 : 1;      /* [    2]  */
            UINT32 RST_READ_SD_RX                                                         : 1;      /* [    3]  */
            UINT32 RST_READ_EMMC_RX                                                       : 1;      /* [    4]  */
            UINT32 RST_READ_SD_TX                                                         : 1;      /* [    5]  */
            UINT32 RST_READ_EMMC_TX                                                       : 1;      /* [    6]  */
            UINT32 RST_READ_SD_CORE                                                       : 1;      /* [    7]  */
            UINT32 RST_READ_EMMC_CORE                                                     : 1;      /* [    8]  */
            UINT32 RST_READ_SD_AXI                                                        : 1;      /* [    9]  */
            UINT32 RST_READ_EMMC_AXI                                                      : 1;      /* [   10]  */
            UINT32 RST_READ_ETH_AXI                                                       : 1;      /* [   11]  */
            UINT32 RST_READ_ETH_BUS_AXI                                                   : 1;      /* [   12]  */
            UINT32 RST_READ_SD_AHB                                                        : 1;      /* [   13]  */
            UINT32 RST_READ_EMMC_AHB                                                      : 1;      /* [   14]  */
            UINT32 RESERVED1                                                              : 17;     /* [31:15]  */
        }Bit;
    }RST_READ_HSP;

    UINT8 EMPTY9[29440]; /* 0x7300 */

    union { /* 0x8004 [Excel Line :0187]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_MCG_PST_TRIG                                                      : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GMAC_MCG_PST_TRIG;
    union { /* 0x8008 [Excel Line :0189]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PHY_INTF_SEL                                                      : 3;      /* [  2:0]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }GMAC_PHY_INTF_SEL;

    UINT8 EMPTY10[8]; /* 0x8 */

    union { /* 0x8014 [Excel Line :0191]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_RMII_SEL                                                          : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GMAC_RMII_SEL;
    union { /* 0x8018 [Excel Line :0193]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_FLOWCTRL                                                      : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_SBD_FLOWCTRL;
    union { /* 0x801C [Excel Line :0195]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_RXDMA_START                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_SBD_RXDMA_START;
    union { /* 0x8020 [Excel Line :0197]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_TXDMA_START                                                   : 8;      /* [  7:0]  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }GMAC_SBD_TXDMA_START;

    UINT8 EMPTY11[12]; /* 0xC */

    union { /* 0x8030 [Excel Line :0199]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_AR_DMA_CH_NO                                                  : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }GMAC_SBD_AR_DMA_CH_NO;
    union { /* 0x8034 [Excel Line :0201]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_AW_DMA_CH_NO                                                  : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }GMAC_SBD_AW_DMA_CH_NO;
    union { /* 0x8038 [Excel Line :0203]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_W_DMA_CH_NO                                                   : 4;      /* [  3:0]  */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }GMAC_SBD_W_DMA_CH_NO;

    UINT8 EMPTY12[196]; /* 0xC4 */

    union { /* 0x8100 [Excel Line :0205]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_MAC_SPEED                                                         : 2;      /* [  1:0]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }GMAC_MAC_SPEED;

    UINT8 EMPTY13[4]; /* 0x4 */

    union { /* 0x8108 [Excel Line :0207]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_PPS_STAMP_CLR                                                 : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GMAC_PTP_PPS_STAMP_CLR;
    union { /* 0x810C [Excel Line :0209]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_PPS_STAMP                                                     : 32;     /* [ 31:0]  */
        }Bit;
    }GMAC_PTP_PPS_STAMP;

    UINT8 EMPTY14[16]; /* 0x10 */

    union { /* 0x8120 [Excel Line :0210]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_CONST_NANO                                             : 6;      /* [  9:4]  */
            UINT32 GMAC_PTP_TSTAMP_SET                                                    : 1;      /* [    1]  */
            UINT32 RESERVED2                                                              : 2;      /* [  3:2]  */
            UINT32 GMAC_PTP_TSTAMP_CLR                                                    : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }GMAC_PTP_TSTAMP_CTRL;
    union { /* 0x8124 [Excel Line :0215]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_WR_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }GMAC_PTP_TSTAMP_WR_L;
    union { /* 0x8128 [Excel Line :0216]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_WR_M                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }GMAC_PTP_TSTAMP_WR_M;
    union { /* 0x812C [Excel Line :0217]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_WR_H                                                   : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GMAC_PTP_TSTAMP_WR_H;
    union { /* 0x8130 [Excel Line :0219]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_RD_L                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }GMAC_PTP_TSTAMP_RD_L;
    union { /* 0x8134 [Excel Line :0220]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_RD_M                                                   : 32;     /* [ 31:0]  */
        }Bit;
    }GMAC_PTP_TSTAMP_RD_M;
    union { /* 0x8138 [Excel Line :0221]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PTP_TSTAMP_RD_H                                                   : 24;     /* [ 23:0]  */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }GMAC_PTP_TSTAMP_RD_H;

    UINT8 EMPTY15[196]; /* 0xC4 */

    union { /* 0x8200 [Excel Line :0223]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_PWR_DOWN                                                          : 1;      /* [    0]  */
            UINT32 GMAC_PWR_CLAMP                                                         : 1;      /* [    1]  */
            UINT32 GMAC_PWR_ISOLATE                                                       : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }GMAC_PWR_CONTROL;
    union { /* 0x8204 [Excel Line :0227]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_SBD_PWR_DOWN_ACK                                                  : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GMAC_PWR_DOWN_ACK;
    union { /* 0x8208 [Excel Line :0229]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_CSYSREQ                                                           : 1;      /* [    0]  */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }GMAC_CSYSREQ;
    union { /* 0x820C [Excel Line :0231]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_CSYSACK                                                           : 1;      /* [    0]  */
            UINT32 GMAC_CACTIVE                                                           : 1;      /* [    1]  */
            UINT32 GMAC_TX_CLK_GATING                                                     : 1;      /* [    2]  */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }GMAC_CSYSACK;
    union { /* 0x8210 [Excel Line :0235]  */
        UINT32 Reg;
        struct {
            UINT32 GMAC_MEM_INIT_START                                                    : 1;      /* [    0]  */
            UINT32 GMAC_MEM_INIT_DONE                                                     : 1;      /* [    1]  */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }GMAC_MEM_INIT;
}DRV_A6_HSP_SCU_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_A6_HSP_SCU_REGISTER* const RegA6_HSP_SCU = (DRV_A6_HSP_SCU_REGISTER*)APACHE_A6_HSP_SCU_BASE_ADDR;
 */



#endif /* end of  DRV_REGISTER_A6_HSP_SCU__ */

