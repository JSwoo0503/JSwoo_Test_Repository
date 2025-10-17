#ifndef R5_USB_REGS_H_
#define R5_USB_REGS_H_

/* =======================================================================
Safety Engine Registers
======================================================================= */
#define safety_engine_base_address                  (0x05060000)

/* =======================================================================
APACHE PMU
======================================================================= */
#define APACHE_A6_PMU_BASE_ADDRESS                  0x0

/* =======================================================================
APACHE USB Controller
======================================================================= */
#define APACHE_A6_USB_CON_BASE_ADDRESS              (0x0B000000)

/* =======================================================================
The System Control Unit(SCU) provides control registers for configuring
APACHE6’s operating conditions such as clock and software reset.
======================================================================= */
#define APACHE_A6_USB_SCU_BASE_ADDRESS              (0x06630000)
/* 
=======================================================================
Chapter 1 A6 USB_SCU REGISTERS
The System Control Unit(SCU) provides control registers for configuring APACHE6’s operating conditions
such as clock and software reset.

1.2	Features
	- Clock Control : CLKMUX, CLKDIV, CLKEN
	- Reset Control
	- USB Controller setup
	- USB PHY setup
=======================================================================
 */
#if (0)
#define SFR_GEN_DATE	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0000) /* Reset Value: 0x20220613 */
#define SFR_GEN_TIME	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0004) /* Reset Value: 0x00173317 */
#define SFR_GEN_CHKSUM	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0008) /* Reset Value: 0x00000000 */
#define USB_PRE1_CLKMUX	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0400) /* Reset Value: 0x00000000 */
#define USB_PRE2_CLKMUX	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0404) /* Reset Value: 0x00000000 */
#define VAL_USBC_BUS	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0600) /* Reset Value: 0x00000005 */
#define VAL_USB_SUSPEND	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0604) /* Reset Value: 0x00000032 */
#define VAL_USB_REF	                                (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0608) /* Reset Value: 0x00000064 */
#define USB_CLKEN	                                (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0800) /* Reset Value: 0x00000007 */
#define USB_ONGO_RST_ACT	                        (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0A00) /* Reset Value: 0x00000000 */
#define USB_PUL_RST_ACT	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0B00) /* Reset Value: 0x00000000 */
#define USBC_BUS_RST_WIDTH	                        (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0C00) /* Reset Value: 0x00000000 */
#define USB_SUSPEND_RST_WIDTH	                    (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0C04) /* Reset Value: 0x00000000 */
#define USB_REF_CLK_RST_WIDTH	                    (APACHE_A6_USB_SCU_BASE_ADDRESS + 0x0C08) /* Reset Value: 0x00000000 */
#define USBCON_MISC0	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC000) /* Reset Value: 0x00000000 */
#define USBCON_MISC1	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC004) /* Reset Value: 0x000C0000 */
#define USBCON_MISC2	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC008) /* Reset Value: 0x00000000 */
#define USBCON_MISC3	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC00C) /* Reset Value: 0x00000411 */
#define USBCON_MISC4	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC010) /* Reset Value: 0x0001F200 */
#define USBCON_MISC5	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC080) /* Reset Value: 0x00000000 */
#define USBCON_MISC6	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC084) /* Reset Value: 0x00000000 */
#define USBCON_MISC7	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC088) /* Reset Value: 0x00000000 */
#define USBCON_MISC8	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC08C) /* Reset Value: 0x00000000 */
#define USBCON_MISC9	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC090) /* Reset Value: 0x00000000 */
#define USBCON_MISC10	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC094) /* Reset Value: 0x00000000 */
#define USBCON_MISC11	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC098) /* Reset Value: 0x00000000 */
#define USBCON_MISC12	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC09C) /* Reset Value: 0x00000000 */
#define USBCON_MISC13	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC0A0) /* Reset Value: 0x00000000 */
#define USBPHY_MISC0	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC100) /* Reset Value: 0x000000B4 */
#define USBPHY_MISC2	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC108) /* Reset Value: 0x00C80015 */
#define USBPHY_MISC3	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC10C) /* Reset Value: 0x0020005D */
#define USBPHY_MISC4	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC110) /* Reset Value: 0x00000000 */
#define USBPHY_MISC5	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC114) /* Reset Value: 0x00000000 */
#define USBPHY_MISC7	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC11C) /* Reset Value: 0x00000000 */
#define USBPHY_MISC11	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC12C) /* Reset Value: 0x00000000 */
#define USBPHY_MISC12	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC130) /* Reset Value: 0x00000509 */
#define USBPHY_MISC13	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC134) /* Reset Value: 0x00000000 */
#define USBPHY_MISC14	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC138) /* Reset Value: 0x00000070 */
#define USBPHY_MISC15	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC13C) /* Reset Value: 0x00000000 */
#define USBPHY_MISC16	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC140) /* Reset Value: 0x00000000 */
#define USBPHY_MISC17	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC144) /* Reset Value: 0x0000007D */
#define USBPHY_MISC18	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC148) /* Reset Value: 0x00003104 */
#define USBPHY_MISC19	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC14C) /* Reset Value: 0x00100000 */
#define USBPHY_MISC21	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC154) /* Reset Value: 0x00000010 */
#define USBPHY_MISC22	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC158) /* Reset Value: 0x44000033 */
#define USBPHY_MISC23	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC15C) /* Reset Value: 0x00030113 */
#define USBPHY_MISC24	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC180) /* Reset Value: 0x00000000 */
#define USBPHY_MISC25	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC184) /* Reset Value: 0x00000000 */
#define USBPHY_MISC27	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC18C) /* Reset Value: 0x00000000 */
#define USBPHY_MISC28	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC190) /* Reset Value: 0x00000000 */
#define USBPHY_MISC30	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC198) /* Reset Value: 0x00000000    CR Data Output Bus, Always presents last read data. Refer to USB PHY databook   */
#define USBCON_OVER_CTL	                            (APACHE_A6_USB_SCU_BASE_ADDRESS + 0xC200) /* Reset Value: 0x00000001    hub_port_overcurrent control) */
#endif

/* 
typedef unsigned int        UINT32;
typedef unsigned long long  u64;

#define TRUE    1
#define FALSE   0
 */
/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 SYS_PLL_K       : 16;
            UINT32 SYS_PLL_MFR     : 8;
            UINT32 SYS_PLL_MRR     : 6;
            UINT32 Reserved        : 2;
        } b;
    } sys_pll_modv_control;
} SYS_PLL_MOD_CONTROL_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 SYS_PLL_M       : 10;
            UINT32 Reserved_11_10  : 2;
            UINT32 SYS_PLL_P       : 6;
            UINT32 Reserved_19_18  : 2;
            UINT32 SYS_PLL_S       : 3;
            UINT32 Reserved_31_23  : 9;
        } b;
    } sys_pll_pms_control;
} SYS_PLL_PMS_CONTROL_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 CPU_PLL_M       : 10;
            UINT32 Reserved_11_10  : 2;
            UINT32 CPU_PLL_P       : 6;
            UINT32 Reserved_19_18  : 2;
            UINT32 CPU_PLL_S       : 3;
            UINT32 Reserved_31_23  : 9;
        } b;
    } cpu_pll_pms_control;

} CPU_PLL_PMS_CONTROL_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 CPU_PLL_K       : 16;
            UINT32 CPU_PLL_MFR     : 8;
            UINT32 CPU_PLL_MRR     : 6;
            UINT32 Reserved        : 2;
        } b;
    } cpu_pll_mod_control;

} CPU_PLL_MOD_CONTROL_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 COM_PLL_K       : 16;
            UINT32 COM_PLL_MFR     : 8;
            UINT32 COM_PLL_MRR     : 6;
            UINT32 Reserved        : 2;
        } b;
    } com_pll_mod_control;

} COM_PLL_MOD_CONTROL_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 COM_PLL_M       : 10;
            UINT32 Reserved_11_10  : 2;
            UINT32 COM_PLL_P       : 6;
            UINT32 Reserved_19_18  : 2;
            UINT32 COM_PLL_S       : 3;
            UINT32 Reserved_31_23  : 9;
        } b;
    } com_pll_pms_control;

} COM_PLL_PMS_CONTROL_T;
/* 
Datasheet USB_SCU.docx
=======================================================================
Indicates the DATE when this SCU register set was generated
[31:16] is Year, [15:8] is Month, [7:0] is Day
=======================================================================
 */
typedef struct
{
    union
    {
        UINT32 dw : 32; /* reser value : 0x20220613 */

        struct
        {
            UINT32 Day     : 8;
            UINT32 Month   : 8;
            UINT32 Year    : 8;
        } b;
    } sfr_gen_date;
} SFR_GEN_DATE_T;

/* =======================================================================
Indicates the TIME when this SCU register set was generated
[23:16] is Hour, [15:8] is Minute, [7:0] is Second
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x00173317 */
        struct
        {
            UINT32 Second  : 8;
            UINT32 Minute  : 8;
            UINT32 Hour    : 8;
        } b;
    } sfr_gen_time;

} SFR_GEN_TIME_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 SFR_GEN_CHKSUM  : 32;   /* reset value : 0xBA39F67D */
    } usb_sfr_gen_chksum;

} USB_SFR_GEN_CHKSUM_T;

/* 
=======================================================================
PLL selection for PRE1 clock source
0: SYS PLL
1: CPU PLL
======================================================================= 
*/
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 CLKMUX_SEL_USB_PRE1     : 1;    /* Reset Value : 0x0 */
            UINT32 Reserved_31_1           : 31;
        } b;
    } usb_pre1_clkmux;

} USB_PRE1_CLKMUX_T;
/* 
=======================================================================
PLL selection for PRE2 clock source
0: SYS PLL
1: CPU PLL
2: NPU PLL
3: NPU PLL
=======================================================================
 */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0 */

        struct
        {
            UINT32 CLKMUX_SEL_USB_PRE2     : 2;
            UINT32 Reserved_31_2           : 30;
        } b;
    } usb_pre2_clkmux;

} USB_PRE2_CLKMUX_T;
/* 
=======================================================================
USBC_BUS Clock divide value from USB_PRE1
('h5: 2000MHz -> 400MHz)
=======================================================================
 */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x05 */

        struct
        {
            UINT32 CLKDIV_VAL_USBC_BUS     : 8;    /* reset value : 0x05 */
            UINT32 Reserved_31_8           : 24;
        } b;
    } val_usbc_bus;

} VAL_USBC_BUS_T;

/* =======================================================================
USB_SUSPEND Clock divide value from USB_PRE2
('h50: 2000MHz -> 40MHz)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x32 */

        struct
        {
            UINT32 CLKDIV_VAL_USB_SUSPEND  : 8;    /* reset value : 0x32 */
            UINT32 Reserved_31_8           : 24;
        } b;
    } val_usb_suspend;

} VAL_USB_SUSPEND_T;

/* =======================================================================
                                                                                                                                                                                                                                                                                                                                                  USB_REF Clock divide value from USB_PRE2
('h64: 2000MHz -> 20MHz)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x64 */

        struct
        {
            UINT32 CLKDIV_VAL_USB_REF_CLK  : 8;    /*  reset value : 0x64 */
            UINT32 Reserved_31_8           : 24;
        } b;
    } val_usb_suspend;

} VAL_USB_REF_T;

/* =======================================================================
USB_SCU (Offset 0x0800)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value: 0x7 */

        struct
        {
            UINT32 CLKEN_USBC_BUS      : 1; /* reset value : 0x1 USBC_BUS Clock Enable */
            UINT32 CLKEN_USB_SUSPEND   : 1; /* reset value : 0x1 USB_SUSPEND Clock Enable */
            UINT32 CLKEN_USB_REF_CLK   : 1; /* reset value : 0x1 USB_REF Clock Enable */
            UINT32 Reserved_31_3       : 29;
        } b;
    } usb_clken;

} USB_CLKEN_T;

/* =======================================================================
Offset 0x0A00
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0 */

        struct
        {
            UINT32 ONGO_RST_ACT_USBC_BUS       : 1; /* USBC_BUS Reset Level Control */
            UINT32 ONGO_RST_ACT_USB_SUSPEND    : 1; /* USB_SUSPEND Reset Level Control */
            UINT32 ONGO_RST_ACT_USB_REF_CLK    : 1; /* USB_REF Reset Level Control */
            UINT32 Reserved_31_3               : 29;
        } b;
    } usb_ongo_rst_act;

} USB_ONGO_RST_ACT_T;

/* =======================================================================
Offset 0x0B00
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0 */

        struct
        {
            UINT32 PUL_RST_ACT_USBC_BUS        : 1; /* USBC_BUS Reset Pulse Trigger */
            UINT32 PUL_RST_ACT_USB_SUSPEND     : 1; /* USB_SUSPEND Reset Pulse Trigger */
            UINT32 PUL_RST_ACT_USB_REF_CLK     : 1; /* USB_REF Reset Pulse Trigger */
            UINT32 Reserved_31_3               : 29;
        } b;
    } usb_pul_rst_act;

} USB_PUL_RST_ACT_T;

/* =======================================================================
Offset 0x0C00
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0000 */

        struct
        {
            UINT32 PUL_RST_WIDTH_USBC_BUS      : 16; /* USB_REF Reset's Width of Pulse Trigger Reset */
            UINT32 Reserved_31_16              : 16;
        } b;
    } usbc_bus_rst_width;

} USBC_BUS_RST_WIDTH_T;

/* =======================================================================
Offset 0x0C04
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0000 */

        struct
        {
            UINT32 PUL_RST_WIDTH_USB_SUSPEND       : 16; /* USB_SUSPEND Reset's Width of Pulse Trigger Reset */
            UINT32 Reserved_31_16                  : 16;
        } b;
    } usb_suspend_rst_wdith;

} USB_SUSPEND_RST_WIDTH_T;

/* =======================================================================
Offset 0x0C08
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0000 */

        struct
        {
            UINT32 PUL_RST_WIDTH_USB_REF_CLK   : 16; /* USBC_BUS Reset's Width of Pulse Trigger Reset */
            UINT32 Reserved_31_16              : 16;
        } b;
    } usb_ref_clk_rst_width;

} USB_REF_CLK_RST_WIDTH_T;

/* =======================================================================
Offset 0xC000
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x0 */

        struct
        {
            UINT32 STARTRXDETU3RXDET       : 1;
            UINT32 DISRXDETU3RXDET         : 1;
            UINT32 Reserved_31_2           : 30;
        } b;
    } usbcon_misc0;

} USBCON_MISC0_T;

/* =======================================================================
Offset 0xC004
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 GP_IN                   : 16;   /* reset value : 0x0000, General Purpose Input Port; can be used as general purpose inputs */
            UINT32 Reserved_16             : 1;
            UINT32 BIGENDIAN_GS            : 1;    /* reset value : 0x0, Slave Big Endian Select (AHB/AXI/Native). */
            UINT32 BUS_CLKEN_GM            : 1;    /* reset value : 0x1, Master Interface Clock Enable (AHB/AXI/Native). */
            UINT32 BUS_CLKEN_GS            : 1;    /* reset value : 0x1, Slave Interface Clock Enable (AHB/AXI/Native). */
            /* Hibernation Support : Indicates the controller is requesting a wakeup and Power Management Event (PME) indication to the system. */
            UINT32 PME_EN                  : 1;    /* reset value : 0x0, Enable signal for the pme_generation. Enable the controller to assert */
            UINT32 Reserved_31_21          : 11;
        } b;
    } usbcon_misc1;

} USBCON_MISC1_T;

/* =======================================================================
Offset 0xC008
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 HUB_PORT_PERM_ATTACH    : 2;    /* Indicates if the device attached to a downstream port is permanently attached or not. */
            UINT32 HUB_PORT_OVERCURRENT    : 2;    /* This is the per port Overcurrent indication of the root-hub ports */
            UINT32 Reserved_31_4           : 28;
        } b;
    } usbcon_misc2;

} USBCON_MISC2_T;

/* =======================================================================
Offset 0xC00C
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 HOST_NUM_U2_PORT                    : 4;    /* reset value : 0x1, Number of USB 2.0 Ports */
            UINT32 HOST_NUM_U3_PORT                    : 4;    /* reset value : 0x1, Number of USB 3.0 SS Ports */
            UINT32 HOST_U2_PORT_DISABLE                : 1;    /* reset value : 0x0, USB 2.0 Port Disable control */
            UINT32 HOST_U3_PORT_DISABLE                : 1;    /* reset value : 0x0, USB 3.0 SS Port Disable control */
            UINT32 HOST_PORT_POWER_CONTROL_PRESENT     : 1;    /* reset value : 0x1, This port defines the bit [3] of Capability Parameters (HCCPARAMS). */
            UINT32 HOST_MSI_ENABLE                     : 1;    /* reset value : 0x0, This enables the pulse type interrupt signal (one bus clock cycle) 'interrupt' port instead of level-sensitive interrupt. */
            UINT32 HOST_LEGACY_SMI_PCI_CMD_REG_WR      : 1;    /* reset value : 0x0 */
            UINT32 HOST_LEGACY_SMI_BAR_WR              : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_4                      : 18;
        } b;
    } usbcon_misc3;

} USBCON_MISC3_T;

/* =======================================================================
Offset 0xC010
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 DFT_EN_RAM_CLK_GATED    : 1;    /* reset value : 0x0 */
            UINT32 DFT_EN_BUS_CLK_GATED    : 1;    /* reset value : 0x0 */
            UINT32 Reserved_3_2            : 2;
            UINT32 FLADJ_30MHZ_REG         : 6;    /* reset value : 0x20, HS Jitter Adjustment. Refer to USB controller databook for more information about this register. */
            UINT32 Reserved_11_10          : 2;
            UINT32 BUS_FILTER_BYPASS       : 4;    /* reset value : 0xF */
            UINT32 XHC_BME                 : 1;    /* reset value : 0x1, This signal is used to disable the bus mastering capability of the xHC.  */
            UINT32 Reserved_31_17          : 15;
        } b;
    } usbcon_misc4;

} USBCON_MISC4_T;

/* =======================================================================
Offset 0xC080
======================================================================= */
typedef struct
{
    UINT32 LOGIC_ANALYZER_TR_ACE_31_0;

} USBCON_MISC5_T;

/* =======================================================================
Offset 0xC084
======================================================================= */
typedef struct
{
    UINT32 LOGIC_ANALYZER_TR_ACE_63_32;

} USBCON_MISC6_T;

/* =======================================================================
Offset 0xC088
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 GP_OUT              : 16;
            UINT32 PME_GENERATION      : 1;    /* PME# Generation.This signal is used to generate a PME# (Power Management Event). */
            UINT32 Reserved_31_17      : 15;
        } b;
    } usbcon_misc7;

} USBCON_MISC7_T;

/* =======================================================================
Offset 0xC08C
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 HOST_CURRENT_BELT           : 12;
            UINT32 Reserved_15_12              : 4;
            UINT32 HOST_SYSTEM_ERR             : 1;
            UINT32 HOST_LEGACY_SMI_INTERRUPT   : 1;
            UINT32 Reserved_31_18              : 14;
        } b;
    } usbcon_misc8;

} USBCON_MISC8_T;

/* =======================================================================
Offset 0xC090
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 OPERATIONAL_MODE        : 2;
            UINT32 Reserved_7_2            : 6;
            UINT32 CLK_GATE_CTRL           : 3;
            UINT32 Reserved_31_11          : 21;
        } b;
    } usbcon_misc9;

} USBCON_MISC9_T;

/* =======================================================================
Offset 0xC094
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 DISRXDETU3RRXDET_ACK        : 1;
            UINT32 UTMI_L1_SUSPEND_COM_N       : 1;
            UINT32 UTMI_SUSPEND_COM_N          : 1;
            UINT32 PIPE3_PHY_MODE              : 2;
            UINT32 PIPE3_COMPLIANCE            : 1;
            UINT32 PIPE3_RATE                  : 1;
            UINT32 PIPE3_TXMARGIN              : 3;
            UINT32 PIPE3_TXSWING               : 1;
            UINT32 HUB_VBUS_CTRL               : 2;    /* Port Power control for each downstream port. */
            UINT32 UTMIOTG_DMPULLDWON          : 1;
            UINT32 UTMIOTG_DPPULLDOWN          : 1;
            UINT32 UTMI_SLEEP_N                : 1;
            UINT32 UTMI_L1_SUSPEND_N           : 1;
            UINT32 Reserved_31_17              : 15;
        } b;
    }usbcon_misc10;

} USBCON_MISC10_T;

/* =======================================================================
Offset 0xC098
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 USB_DEBUG_66_64     : 3;
            UINT32 Reserved_31_3       : 29;
        } b;
    } usbcon_misc11;

} USBCON_MISC11_T;

/* =======================================================================
Offset 0xC09C
======================================================================= */
typedef struct
{
    UINT32 USB_DEBUG_63_32;

} USBCON_MISC12_T;

/* =======================================================================
Offset 0xC0A0
======================================================================= */
typedef struct
{
    UINT32 USB_DEBUG_31_0;

} USBCON_MISC13_T;



/* =======================================================================
USB PHY Control Registers
======================================================================= */
/*
The USB3.0 PHY Initialization sequence follows
1. Chip Power On
2. Set Reference clock with USBPHY_MISC0_T.ssc_en, USBPHY_MISC14_T.ref_use_pad, USBPHY_MISC18_T.fsel and USBPHY_MISC19_T.REFCLKSEL
3. Release PHY resets with U30_PCFG0.phy_reset, PORTRESET,  pipe_reset_n
4. if High-speed only mode, Set U30_LCFG0.USB20ONLY and U30PCFG1.test_powerdown_ssp to high.
5. Wait about 165us until PHY clock ouputs are stable.
*/

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TXBITSTUFFENH0          : 1;    /* reset value : 0x0, High-Byte Transmit Bit-Stuffing Enable */
            UINT32 TXBITSTUFFEN0           : 1;    /* reset value : 0x0, Low-Byte Transmit Bit-Stuffing Enable */
            UINT32 IDPULLUP0               : 1;    /* reset value : 0x0, Analog ID Input Sample Enable This controller signal controls IDN line sampling */
            UINT32 OTGDISABLE0             : 1;    /* reset value : 0x0, OTG Block Disable This controller signal powers down the OTG block, which disables the VBUS Valid and Session End comparators.  */
            UINT32 COMMONONN               : 1;    /* reset value : 0x1, Common Block Power-Down Control Controls the power-down signals in the PLL block when the USB 3.0, femtoPHY is in Suspend or Sleep mode */
            UINT32 SSC_EN                  : 1;    /* reset value : 0x1, Spread Spectrum Enable. Enable spread spectrum clock production in the USB 3.0 PHY. if tje reference clock already has spread spectrum applied, ssc_en must be deasserted. */
            UINT32 VBUSVLDEXTSEL0          : 1;    /* reset value : 0x0, External VBUS Valid Indicator Valid in Device mode and only when the VBUSVLDEXTSEL0 signal is set to 1'b1. VBUSVLDEXTN indicates whether the VBUS<#> */
            UINT32 VBUSVLDEXT0             : 1;    /* reset value : 0x1, */
            UINT32 Reserved_31_8           : 24;
        } b;
    } usbphy_misc0;

} USBPHY_MISC0_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 PCS_TX_DEEMPH_3P5DB     : 6;
            UINT32 Reserved_6_15           : 10;
            UINT32 PCS_RX_LOS_MASK_VAL     : 10;
            UINT32 Reserved_26_31          : 6;
        } b;
    } usbphy_misc2;

} USBPHY_MISC2_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 PCS_TX_SWING_FULL       : 7;
            UINT32 Reserved_7_15           : 9;
            UINT32 PCS_TX_DEEMPH_6DB       : 6;
            UINT32 Reserved                : 10;
        } b;
    } usbphy_misc3;

} USBPHY_MISC3_T;

/* =======================================================================
Offset 0xC114
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 ALT_PIPE_PCLK           : 1;    /* reset value : 0x0 */
            UINT32 ALT_PCS_CLK             : 1;    /* reset value : 0x0 */
            UINT32 ALT_CLK_SEL             : 1;    /* reset value : 0x0 */
            UINT32 ALT_CLK_EN              : 1;    /* reset value : 0x0 */
            UINT32 Reserved_4_31           : 28;   /* reset value : 0x0 */
        } b;
    } usbphy_misc4;

} USBPHY_MISC4_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 LANE0_TX_TERM_OFFSET    : 5;
            UINT32 Reserved_5_7            : 3;
            UINT32 LANE0_TX2RX_LOOPBK      : 1;
            UINT32 LANE0_EXT_PCLK_REQ      : 1;
            UINT32 Reserved_10_31          : 12;
        } b;
    } usbphy_misc5;

} USBPHY_MISC5_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TEST_BURNIN             : 1;    /* All Circuits Activator */
            UINT32 TEST_POWERDOWN_HSP      : 1;    /* HS Function Circuits Power-Down Control Powers down all HS function circuitry in the PHY for IDDQ testing. */
            UINT32 Reserved_2_31           : 30;
        } b;
    } usbphy_misc7;

} USBPHY_MISC7_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 CR_DATA_IN              : 16;
            UINT32 CR_READ                 : 1;
            UINT32 CR_CAP_DATA             : 1;
            UINT32 CR_CAP_ADDR             : 1;
            UINT32 CR_WRITE                : 1;
            UINT32 Reserved_20_31          : 12;
        } b;
    } usbphy_misc11;

} USBPHY_MISC11_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 LOS_LEVEL               : 5;    /* reset value : 0x09, Loss-of-Signal Detector Sensitivity Level Control Reserved. Set this bus to 0x09. */
            UINT32 Reserved_5_7            : 3;
            UINT32 LOS_BIAS                : 3;    /* reset value : 0x5, Loss-of-Signal Detector Threshold Level Control Sets the LOS detection threshold level. To enable tuning at the board */
            UINT32 Reserved_11_31          : 21;
        } b;
    } usbphy_misc12;

} USBPHY_MISC12_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 SSC_RANGE               : 3;    /* Spread Spectrum CLock Range.  Selects the range of spread spectrum modulation whe ssc_en is asserted an the PHY is spreading the high-speed transmit clocks. */
            UINT32 Reserved_3_7            : 5;
            UINT32 SSC_REF_CLK_SEL         : 9;    /* Spread Spectrum Reference Clock Shifting. Enables non-standard oscillator frequencies to generate targeted MPLL output rates. Input corresponds to frequency-synthesis coefficient. */
            UINT32 Reserved_17_31          : 15;
        } b;
    } usbphy_misc13;

} USBPHY_MISC13_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 REF_USE_XO              : 1;    /* reset value : 0x0, Use External Crystal Oscillator Reserved.  */
            UINT32 REF_XO_EN               : 1;    /* reset value : 0x0, Crystal Oscillator Always On Enable Reserved.  */
            UINT32 REF_REPEAT_CLK_EN       : 1;    /* reset value : 0x0, Clock Repeater Buffer Enable Enables the clock repeater buffer. */
            UINT32 REF_CLKDIV2             : 1;    /* reset value : 0x0, Input Reference Clock Divider Control. If the input reference clock frequency is greater than 100MHz, this signal must be asserted. The reference clock frequency is then divided by 2 to keep it in the range required by the MPLL. */
            UINT32 REF_USE_PAD             : 1;    /* reset value : 0x1, Select Reference Clock Connected to PAD. When Asserted, selects the external PAD inputs as the reference clock source. When ref_use_pad is deasserted, internal on-chip clock source is selected for a reference clock source. */
            UINT32 REF_ALT_CLK_M           : 1;    /* reset value : 0x1, Low-Swing Differential Input Clock Pair Internal Pin Reference clock from on-chip source. */
            UINT32 REF_SSP_EN              : 1;    /* reset value : 0x1, Reference Clock Enable for SS function. Enable the reference clock to prescaler. The ref_ssp_en signal ust remain deasserted until the reference clock is running at the appropriate fequency, at which point ref_ssp_en can be asserted. */
            UINT32 REF_ALT_CLK_P           : 1;    /* reset value : 0x0, Low-Swing Differential Input Clock Pair Internal Pin Reference clock from on-chip source. */
            UINT32 Reserved_8_31           : 24;
        } b;
    } usbphy_misc14;

} USBPHY_MISC14_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 JTAG_TMS                : 1;
            UINT32 JTAG_TCK                : 1;
            UINT32 JTAG_TRST_N             : 1;
            UINT32 JTAG_TDI                : 1;
            UINT32 Reserved_4_31           : 28;
        } b;
    } usbphy_misc15;

} USBPHY_MISC15_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 RTUNE_REQ               : 1;    /* Resistor Tune Request Assertion triggers a resistor tune request (if one is not already in progress). */
            UINT32 Reserved_1_31           : 31;
        } b;
    } usbphy_misc16;

} USBPHY_MISC16_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 MPLL_MULTIPLIER         : 7;    /* reset value : 0x0, MPLL Frequency Multiplier. Multiplies the reference clock to a frequency suitable for intended operating speed. */
            UINT32 Reserved_7              : 1;
            UINT32 MPLL_REFSSC_CLK_EN      : 1;    /* reset value : 0x7D */
            UINT32 Reserved_9_31           : 23;
        } b;
    } usbphy_misc17;

} USBPHY_MISC17_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TX_VBOOST_LVL           : 3;    /* reset value : 0x4, TX Voltage Boost Level Sets the boosted transmit launch amplitude (mVppd). To enable tuning at the board level, connect this bus to a register */
            UINT32 Reserved_3_7            : 5;    /*  */
            UINT32 FSEL                    : 6;    /* reset value : 0x31 */
            UINT32 Reserved_14_15          : 2;
            UINT32 ACJT_LEVEL              : 5;    /* reset value : 0x00 */
            UINT32 Reserved_21_31          : 11;
        } b;
    } usbphy_misc18;

} USBPHY_MISC18_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_0_16           : 17;
            UINT32 LOOPBACKENB0            : 1;
            UINT32 RX0LOSLFPSEN            : 1;    /* reset value : 0x0 */
            UINT32 REFCLKSEL               : 2;
            UINT32 FSSE0EXT0               : 1;
            UINT32 FSDATAEXT0              : 1;
            UINT32 DCDENB0                 : 1;
            UINT32 CHRGSEL0                : 1;
            UINT32 BYPASSSEL0              : 1;
            UINT32 BYPASSDPEN0             : 1;
            UINT32 BYPASSDPDATA0           : 1;
            UINT32 BYPASSDMEN0             : 1;
            UINT32 BYPASSDMDATA0           : 1;
            UINT32 ATERESET                : 1;    /* reset value : 0x0, Reset Input from Automatic Test Equipment When the USB 3.0 femtoPHY is powered up (not in Suspend or Sleep mode), an automatic tester can use this test signal to disable PHYCLOCKN and FREECLK, then re-enable them with an aligned phase. */
            UINT32 ACAENB0                 : 1;
        } b;
    } usbphy_misc19;

} USBPHY_MISC19_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 VDATSRCENB0             : 1;
            UINT32 VDATDETENB0             : 1;
            UINT32 VATESTENB               : 1;
            UINT32 TXPREEMPPULSETUNE0      : 1;
            UINT32 TXENABLEN0              : 1;
            UINT32 Reserved_5_31           : 27;
        } b;
    } usbphy_misc21;

} USBPHY_MISC21_T;

/* =======================================================================
Offset (0xc158)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TXFSLSTUNE0             : 4;    /* reset value : 0x3, FS/LS Source Impedance Adjustment Adjusts the low- and full-speed single-ended source impedance while driving high. */
            UINT32 SQRXTUNE0               : 3;    /* reset value : 0x3, Squelch Threshold Adjustment Adjusts the voltage level for the threshold used to detect valid highspeed data.  */
            UINT32 Reserved_23_7           : 17;
            UINT32 OTGTUNE0                : 3;    /* reset value : 0x4, VBUS Valid Threshold Adjustment This bus adjusts the voltage level for the VBUS<#> valid threshold. */
            UINT32 Reserved_27             : 1;
            UINT32 COMPDISTUNE0            : 3;    /* reset value : 0x4, Disconnect Threshold Adjustment Adjusts the voltage level for the threshold used to detect a disconnect event at the host. To enable tuning at the board level, connect this bus to a register. */
            UINT32 Reserved_31             : 1;
        } b;
    } usbphy_misc22;

} USBPHY_MISC22_T;

/* =======================================================================
Offset 0xc15c
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TXVREFTUNE0             : 4;
            UINT32 TXRISETUNE0             : 2;
            UINT32 Reserved_6_7            : 2;
            UINT32 TXRESTUNE0              : 2;
            UINT32 Reserved_10_11          : 2;
            UINT32 TXPREEMPAMPTUNE0        : 2;
            UINT32 Reserved_14_15          : 2;
            UINT32 TXHSXVTUNE0             : 2;
            UINT32 Reserved_18_31          : 4;
        } b;
    } usbphy_misc23;

} USBPHY_MISC23_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_0_12           : 13;
            UINT32 RIDGND0                 : 1;
            UINT32 RIDFLOAT0               : 1;
            UINT32 RIDC0                   : 1;
            UINT32 RIDB0                   : 1;
            UINT32 RIDA0                   : 1;
            UINT32 Reserved_18             : 1;
            UINT32 OTGSESSVLD0             : 1;
            UINT32 Reserved_20             : 1;
            UINT32 IDDIG0                  : 1;
            UINT32 FSVPLUS0                : 1;
            UINT32 FSVMINUS0               : 1;
            UINT32 FSLSRCV0                : 1;
            UINT32 Reserved_25_29          : 5;
            UINT32 CHGDET0                 : 1;
            UINT32 AVALID0                 : 1;
        } b;
    } usbphy_misc24;

} USBPHY_MISC24_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 SESSEND0                : 1;
            UINT32 TXREADY0                : 1;
            UINT32 RXVALIDH0               : 1;
            UINT32 RXVALID0                : 1;
            UINT32 RXACTIVE0               : 1;
            UINT32 RXERROR0                : 1;
            UINT32 LINESTATE0              : 2;
            UINT32 HOSTIDSCONNECT0         : 1;
            UINT32 VBUSVALID0              : 1;
            UINT32 BVALID0                 : 1;
            UINT32 PIPE0_PHYSTATUS         : 1;
            UINT32 PIPE0_RX_ELECIDLE       : 1;
            UINT32 PIPE0_RX_STATUS         : 3;
            UINT32 Reserved                : 16;
        } b;
    } usbphy_misc25;

} USBPHY_MISC25_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_0_3            : 4;
            UINT32 REF_CLKREQ_N            : 1;
            UINT32 Reserved_5_31           : 27;
        } b;
    } usbphy_misc27;

} USBPHY_MISC27_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_0              : 1;
            UINT32 CR_ACK                  : 1;
            UINT32 Reserved_2_6            : 5;
            UINT32 JTAG_TDO_EN             : 1;
            UINT32 RTUNE_ACK               : 1;
            UINT32 Reserved_9              : 1;
            UINT32 JTAG_TDO                : 1;
            UINT32 ALT_CLK_REQ             : 1;
            UINT32 Reserved_12_31          : 20;
        } b;
    } usbphy_misc28;

} USBPHY_MISC28_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 CR_DATA_OUT             : 16;
            UINT32 Reserved                : 16;
        } b;
    } usbphy_misc30;

} USBPHY_MISC30_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 OVERCUR_REG_EN          : 1;
            UINT32 Reserved                : 31;
        } b;
    } usbcon_over_ctl;

} USBCON_OVER_CTL_T;

/* End of USB_SCU.docx */



/* =======================================================================
Datasheet USB_Con.docx
======================================================================= */

/* =======================================================================
1.2 DWC_usb3_block_gbl Registers
======================================================================= */

/* =======================================================================
1.2.1 GSBUSCFG0
Leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32; /* resetvalue : 0x00000001 */

        struct
        {
            UINT32 INCRBRSTENA     : 1;
            UINT32 INCR4BRSTENA    : 1;
            UINT32 INCR8BRSTENA    : 1;
            UINT32 INCR16BRSTENA   : 1;
            UINT32 INCR32BRSTENA   : 1;
            UINT32 INCR64BRSTENA   : 1;
            UINT32 INCR128BRSTENA  : 1;
            UINT32 INCR256BRSTENA  : 1;
            UINT32 reserved_9_8    : 2;
            UINT32 DESBIGEND       : 1;
            UINT32 DATBIGEND       : 1;
            UINT32 reserved_15_12  : 4;
            UINT32 DESWRREQINFO    : 4;
            UINT32 DATWRREQINFO    : 4;
            UINT32 DESRDREQINFO    : 4;
            UINT32 DATRDREQINFO    : 4;
        } b;
    } g5buscfg0;

} GSBUSCFG0_T;

/* =======================================================================
1.2.2 GSBUSCFG1
Leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value: 0x00000300 */

        struct
        {
            UINT32 reserved_7_0    : 8;
            UINT32 PipeTransLimit  : 4;
            UINT32 EN1KPAGE        : 1;
            UINT32 reserved_31_13  : 9;
        } b;
    } g5buscfg1;

} GSBUSCFG1_T;

/* =======================================================================
1.2.3 GTXTHRCFG
This is required only if you are planning to enable thresholding.
Leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value : 0x24080000 */

        struct
        {
            UINT32 reserved_10_0       : 11;
            UINT32 reserved_13_11      : 3;
            UINT32 reserved_14         : 1;
            UINT32 reserved_15         : 1;
            UINT32 UsbMaxTxBurstSize   : 8;
            UINT32 UsbTxPktCnt         : 4;
            UINT32 reserved_28         : 1;
            UINT32 UsbTxPktCntSel      : 1;
            UINT32 reserved_30         : 1;
            UINT32 reserved_31         : 1;
        } b;
    } gtxthrcfg;

} GTXTHRCFG_T;

/* =======================================================================
1.2.4 GRXTHRCFG
This is required only if you are planning to enable thresholding.
Leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;    /* reset value: 0x24400000 */

        struct
        {
            UINT32 ResvISOCOUTSpc      : 13;
            UINT32 reserved_14_13      : 2;
            UINT32 reserved_15         : 1;
            UINT32 reserved_18_16      : 3;
            UINT32 UsbMaxRxBurstSize   : 5;
            UINT32 UsbRxPktCnt         : 4;
            UINT32 reserved_28         : 1;
            UINT32 UsbRxPktCntSel      : 1;
            UINT32 reserved_31_30      : 2;
        } b;
    } grxthrcfg;

} GRXTHRCFG_T;

/* =======================================================================
1.2.5 GCTL : Global Core Control Register
Program this register to override scaledown, RAM clock select, and clock gating parameters.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 DSBLCLKGTNG         : 1;
            UINT32 GblHibernationEn    : 1;
            UINT32 U2EXIT_LFPS         : 1;
            UINT32 DISSCRAMBLE         : 1;
            UINT32 SCALEDOWN           : 2;
            UINT32 RAMCLKSEL           : 2;
            UINT32 DEBUGATTACH         : 1;
            UINT32 U1U2TimerScale      : 1;
            UINT32 SOFITPSYNC          : 1;
            UINT32 CORESOFTRESET       : 1;    /* reset value : 0x0 */
            UINT32 PRTCAPDIR           : 2;
            UINT32 FRMSCLDWN           : 2;
            UINT32 U2RSTECN            : 1;
            UINT32 BYPSSETADDR         : 1;
            UINT32 MASTERFILTBYPASS    : 1;
            UINT32 PwRDNSCALE          : 13;

        } b;
    } gctl;

} GCTL_T;

/* =======================================================================
Program the following PHY configuration fields: USBTrdTim, FSIntf, PHYIf, TOUTCal,
or leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TOutCal                 : 3;
            UINT32 PHYIF                   : 1;
            UINT32 ULPI_UTMI_Sel           : 1;
            UINT32 FSINTF                  : 1;
            UINT32 SUSPENDUSB20            : 1;
            UINT32 PHYSEL                  : 1;
            UINT32 ENBLSLPM                : 1;
            UINT32 XCVRDLY                 : 1;
            UINT32 USBTRDTIM               : 4;
            UINT32 reserved_14             : 1;
            UINT32 ULPIAUTORES             : 1;
            UINT32 reserved_16             : 1;
            UINT32 ULPIEXTVBUSDRV          : 1;
            UINT32 ULPIEXTVBUSINDICATOR    : 1;
            UINT32 LSIPD                   : 3;
            UINT32 LSTRD                   : 3;
            UINT32 OVRD_FSLS_DISC_TIME     : 1;
            UINT32 INV_SEL_HSIC            : 1;
            UINT32 HSIC_CON_WIDTH_ADJ      : 1;
            UINT32 ULPI_LPM_WITH_OPMODE_CHK: 1;
            UINT32 U2_FREECLK_EXISTS       : 1;
            UINT32 PHYSOFTRST              : 1; /* UTMI PHY Soft Reset (PHYSoftRst) */
        } b;
    } gusb2phycfg;

} GUSB2PHYCFG_T;

/* =======================================================================
Program the following PHY configuration fields: DatWidth, PrtOpDir,
or leave the default values if the correct power-on values were selected during coreConsultant configuration.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 ELASTIC_BUFFER_MODE                 : 1;
            UINT32 SS_TX_DE_EMPHASIS                   : 2;
            UINT32 TX_MARGIN                           : 3;
            UINT32 TX_SWING                            : 1;
            UINT32 SSICEn                              : 1;
            UINT32 RX_DETECT_to_Polling_LFPS_Control   : 1;
            UINT32 LFPSFILTER                          : 1;
            UINT32 P3ExSigP2                           : 1;
            UINT32 P3P2TranOK                          : 1;
            UINT32 LFPSP0Algn                          : 1;
            UINT32 SkipRxDet                           : 1;
            UINT32 AbortRxDetInU2                      : 1;
            UINT32 DATWIDTH                            : 2;
            UINT32 SUSPENDENABLE                       : 1;
            UINT32 DELAYP1TRANS                        : 1;
            UINT32 DelayP1P2P3                         : 3;
            UINT32 DisRxDetU3RxDet                     : 1;
            UINT32 StartRxDetU3RxDet                   : 1;
            UINT32 request_p1p2p3                      : 1;
            UINT32 u1u2exitfail_to_recov               : 1;
            UINT32 ping_enhancement_en                 : 1;
            UINT32 Ux_exit_in_Px                       : 1;
            UINT32 DisRxDetP3                          : 1;
            UINT32 U2P3ok                              : 1;
            UINT32 HstPrtCmpl                          : 1;
            UINT32 PHYSoftRst                          : 1;
        } b;
    } gusb3pipectl;

} GUSB3PIPECTL_T;

/* =======================================================================
Program these registers based on the speed used for the FIFO.
For details, see the “Architecture” chapter in the DWC SuperSpeed USB 3.0 Controller Databook.
Unless the packet sizes of the endpoints are application-specific, it is recommended that you use the default value.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 TXFDEP_N        : 16;
            UINT32 TXFSTADDR_N     : 16;
        } b;
    } gtxfifosiz;

} GTXFIFOSIZ_T;

/* =======================================================================
Program these registers based on the speed used for the FIFO.
For details, see the “Architecture” chapter in the DWC SuperSpeed USB 3.0 Controller Databook.
Unless the packet sizes of the endpoints are application-specific, it is recommended that you use the default value.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 RXFDEP_N        : 16;
            UINT32 RXFASTADDR_N    : 16;
        } b;
    } grxfifosiz;

} GRXFIFOSIZ_T;

/* =======================================================================
GPMSTS
======================================================================= */

/* =======================================================================
GSTS
======================================================================= */

/* =======================================================================
GUCTL1
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw      : 32;

        struct
        {
            UINT32 LOA_FILTER_EN                   : 1;
            UINT32 OVRLD_L1_SUSP_COM               : 1;
            UINT32 HC_PARCHK_DISABLE               : 1;
            UINT32 HC_ERRATA_ENABLE                : 1;
            UINT32 L1_SUSP_THRLD_FOR_HOST          : 4;
            UINT32 L1_SUSP_THRLD_EN_FOR_HOST       : 1;
            UINT32 DEV_HS_NYET_BULK_SPR            : 1;
            UINT32 RESUME_OPMODE_HS_HOST           : 1;
            UINT32 DisRefClkGtng                   : 1;
            UINT32 DisUSB2RefClkGtng               : 1;
            UINT32 Reserved_14_13                  : 2;
            UINT32 PARKMODE_DISABLE_FSLS           : 1;
            UINT32 PARKMODE_DISABLE_HS             : 1;
            UINT32 PARKMODE_DISABLE_SS             : 1;
            UINT32 NAK_PER_ENH_HS                  : 1;
            UINT32 NAK_PER_ENH_FS                   : 1;
            UINT32 DEV_LSP_TAIL_LOCK_DIS           : 1;
            UINT32 IP_GAP_ADD_ON                   : 3;
            UINT32 DEV_L1_EXIT_BY_HW               : 1;
            UINT32 P3_IN_U2                        : 1;
            UINT32 DEV_FORCE_20_CLK_FOR_30_CLK     : 1;
            UINT32 DEV_TRB_OUT_SPR_IND             : 1;
            UINT32 TX_IPGAP_LINECHECK_DIS          : 1;
            UINT32 FILTER_SE0_FSLS_EOP             : 1;
            UINT32 DS_RXDET_MAX_TOUT_CTRL          : 1;
            UINT32 DEV_DECOUPLE_L1L2_EVT           : 1;
        } b;
    } guctl1;
} GUCTL1_T;

/* =======================================================================
1.2.9 GSNPSID
The software can read the Synopsys ID register to find the controller version and
configure the firmware for any version-specific features.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 SYNOPSYSID : 32;

        struct
        {
            UINT32 ReleaseNumber               : 16;
            UINT32 CoreIdentificationNumber    : 16;
        } b;
    } g5npsid;

} GSNPSID_T;

/* =======================================================================
GGPIO
======================================================================= */

/* =======================================================================
GUID
======================================================================= */

/* =======================================================================
1.2.12 GUCTL
If you want to improve the interoperability with different devices,
program this register to override the behavior of the controller in Host mode.

Description: Global User Control Register:
This register provides a few options for the software to control the controller behavior in the Host mode.
Most of the options are used to improve host inter-operability with different devices.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 DTFT                : 9;
            UINT32 DTCT                : 2;
            UINT32 InsrtExtrFSBODI     : 1;
            UINT32 ExtCapSupptEN       : 1;
            UINT32 EnOverlapChk        : 1;
            UINT32 USBHstInAutoRetryEn : 1;
            UINT32 reserved_15         : 1;
            UINT32 ResBwHSEPS          : 1;
            UINT32 SprsCtrTransEn      : 1;
            UINT32 reserved_20_18      : 3;
            UINT32 NoExtrDl            : 1;
            UINT32 REFCLKPER           : 10;
        } b;
    } guctl;

} GUCTL_T;

/* =======================================================================
GBUSERRADDRLO
======================================================================= */

/* =======================================================================
GBUSERRADDRHI
======================================================================= */

/* =======================================================================
GPRTBIMAPLO
======================================================================= */

/* =======================================================================
GPRTBIMAPHI
======================================================================= */

/* =======================================================================
GHWPARAMS0
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams0_2_0      : 3;    /* reset value : 0x2 */ /* DWC_USB3_MODE */
            UINT32 ghwparams0_5_3      : 3;    /* reset value : 0x1 */
            UINT32 ghwparams0_7_6      : 2;    /* reset value : 0x0 */
            UINT32 ghwparams0_15_8     : 8;    /* reset value : 0x80 */
            UINT32 ghwparams0_23_16    : 8;    /* reset value : 0x20 */
            UINT32 ghwparams0_31_24    : 8;    /* reset value : 0x40 */
        } b;
    } ghwparams0;

} GHWPARAMS0_T;

/* =======================================================================
GHWPARAMS1
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams1_2_0      : 3;    /* reset value : 0x3 */
            UINT32 ghwparams1_5_3      : 3;    /* reset value : 0x7 */
            UINT32 ghwparams1_8_6      : 3;    /* reset value : 0x4 */
            UINT32 ghwparams1_11_9     : 3;    /* reset value : 0x4 */
            UINT32 ghwparams1_14_12    : 3;    /* reset value : 0x4 */
            UINT32 ghwparams1_20_15    : 6;    /* reset value : 0x1 */
            UINT32 ghwparams1_22_21    : 2;    /* reset value : 0x3 */
            UINT32 ghwparams1_23       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_25_24    : 2;    /* reset value : 0x1 */
            UINT32 ghwparams1_26       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_27       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_28       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_29       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_30       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams1_31       : 1;    /* reset value : 0x0 */
        } b;
    } ghwparams1;

} GHWPARAMS1_T;

/* =======================================================================
GHWPARAMS2
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams2_31_0     : 32;   /* reset value : 0x12345678 */
        } b;
    } ghwparams2;

} GHWPARAMS2_T;

/* =======================================================================
GHWPARAMS3
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams3_1_0      : 2;    /* reset value : 0x1 */ /* DWC_USB3_SSPHY_INTERFACE */
            UINT32 ghwparams3_3_2      : 2;    /* reset value : 0x1 */ /* DWC_USB3_HSPHY_INTERFACE */
            UINT32 ghwparams3_5_4      : 2;    /* reset value : 0x0 */ /* DWC_USB3_FSPHY_INTERFACE */
            UINT32 ghwparams3_7_6      : 2;    /* reset value : 0x2 */
            UINT32 ghwparams3_9_8      : 2;    /* reset value : 0x0 */
            UINT32 ghwparams3_10       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams3_11       : 1;    /* reset value : 0x0 */
            UINT32 ghwparams3_17_12    : 6;    /* reset value : 0x10 */
            UINT32 ghwparams3_22_18    : 5;    /* reset value : 0x8 */
            UINT32 ghwparams3_30_23    : 8;    /* reset value : 0x10 */
            UINT32 ghwparams3_31       : 1;    /* reset value : 0x0 */
        } b;
    } ghwparams3;

} GHWPARAMS3_T;

/* =======================================================================
GHWPARAMS4
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams4_5_0          : 6;    /* reset value : 0x8 */
            UINT32 ghwparams4_6            : 1;    /* reset value : 0x0 */
            UINT32 ghwparams4_8_7          : 2;    /* reset value : 0x0 */
            UINT32 ghwparams4_10_9         : 2;    /* reset value : 0x0 */
            UINT32 ghwparams4_11           : 1;    /* reset value : 0x0 */
            UINT32 ghwparams4_12           : 1;    /* reset value : 0x0 */
            UINT32 ghwparams4_16_13        : 4;    /* reset value : 0x1 */
            UINT32 ghwparams4_20_17        : 4;    /* reset value : 0x1 */
            UINT32 ghwparams4_21           : 1;    /* reset value : 0x0 */
            UINT32 ghwparams4_22           : 1;    /* reset value : 0x0 */
            UINT32 ghwparams4_23           : 1;    /* reset value : 0x1 */
            UINT32 ghwparams4_27_24        : 4;    /* reset value : 0x3 */
            UINT32 ghwparams4_31_28        : 4;    /* reset value : 0x4 */
        } b;
    } ghwparams4;

} GHWPARAMS4_T;

/* =======================================================================
GHWPARAMS5 (Offset 0xC150)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams5_3_0          : 4;    /* reset value : 0x8 */
            UINT32 ghwparams5_9_4          : 6;    /* reset value : 0x8 */
            UINT32 ghwparams5_15_10        : 6;    /* reset value : 0x8 */
            UINT32 ghwparams5_21_16        : 6;    /* reset value : 0x14 */
            UINT32 ghwparams5_27_22        : 6;    /* reset value : 0x8 */
            UINT32 ghwparams5_31_28        : 4;    /* reset value : 0x0 */
        } b;
    } ghwparams5;

} GHWPARAMS5_T;

/* =======================================================================
GHWPARAMS6
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams6_5_0          : 6;    /* reset value : 0x20 */
            UINT32 ghwparams6_6            : 1;    /* reset value : 0x0 */
            UINT32 ghwparams6_7            : 1;    /* reset value : 0x0 */
            UINT32 ghwparams6_9_8          : 2;    /* reset value : 0x0 */
            UINT32 SRPSupport              : 1;    /* reset value : 0x0 */
            UINT32 HNPSupport              : 1;    /* reset value : 0x0 */
            UINT32 ADPSupport              : 1;    /* reset value : 0x0 */
            UINT32 OTG_SS_Support          : 1;    /* reset value : 0x0 */
            UINT32 BCSupport               : 1;    /* reset value : 0x0 */
            UINT32 BusFltrsSupport         : 1;    /* reset value : 0x1 */
            UINT32 ghwparams6_31_16        : 16;   /* reset value : 0x5c3 */
        } b;
    } ghwparams6;

} GHWPARAMS6_T;

/* =======================================================================
GHWPARAMS7
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams7_15_0         : 16;   /* reset value : 0x4fc */
            UINT32 ghwparams7_31_16        : 16;   /* reset value : 0x244 */
        } b;
    } ghwparams7;

} GHWPARAMS7_T;

/* =======================================================================
GDBGFIFOSPACE
======================================================================= */

/* =======================================================================
GDBGLTSSM
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 TXONESZEROS             : 1;    /* RO, reset value : 0x0 */
            UINT32 RXTERMINATION           : 1;    /* RO, reset value : 0x0 */
            UINT32 TXSWING                 : 1;    /* RO, reset value : 0x0 */
            UINT32 LTDBClkState            : 3;    /* RO, reset value : 0x0, LTSSM Clock State */
            UINT32 TXDEEMPHASIS            : 2;    /* RO, reset value : 0x1 */
            UINT32 RXEQTRAIN               : 1;
            UINT32 POWERDOWN               : 2;
            UINT32 LTDBPhyCmdState         : 3;
            UINT32 TxDetRxLoopback         : 1;
            UINT32 RXPOLARITY              : 1;
            UINT32 TXELECLDLE              : 1;
            UINT32 ELASTICBUFFERMODE       : 1;
            UINT32 LTDBSUBSTATE            : 4;
            UINT32 LTDBLINKSTATE           : 4;
            UINT32 LTDBTIMEOUT             : 1;
            UINT32 PRTDIRECTION            : 1;
            UINT32 X3_DS_HOST_SHUTDOWN     : 1;
            UINT32 X3_XS_SWAPPING          : 1;
            UINT32 RxElecidle              : 1;
            UINT32 Reserved                : 1;
        } b;
    } gdbgltssm;

} GDBGLTSSM_T;

/* =======================================================================
GDBGLNMCC
======================================================================= */


/* =======================================================================
GDBGBMU
======================================================================= */

/* =======================================================================
GDBGLSPMUX_HST
======================================================================= */

/* =======================================================================
GDBGLSP
======================================================================= */

/* =======================================================================
GDBGEPINFO0
======================================================================= */

/* =======================================================================
GDBGEPINFO1
======================================================================= */

/* =======================================================================
GPRTBIMAP_HSLO
======================================================================= */

/* =======================================================================
GPRTBIMAP_HSHI
======================================================================= */

/* =======================================================================
GPRTBIMAP_FSLO
======================================================================= */

/* =======================================================================
GPRTBIMAP_FSHI
======================================================================= */

/* =======================================================================
Reserved_94
======================================================================= */

/* =======================================================================
Reserved_98
======================================================================= */


/* =======================================================================
GUCTL2  (Offset 0xc19c)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 TxPingDuration          : 5;    /* reset value : 0xd */
            UINT32 RxPingDuration          : 6;    /* reset value : 0x20 */
            UINT32 DisableCFC              : 1;    /* reset value : 0x0 */
            UINT32 EnableEpCacheEvit       : 1;    /* reset value : 0x0 */
            UINT32 Reserved_13             : 1;    /* reset value : 0x0 */
            UINT32 Rst_actbitlater         : 1;    /* reset value : 0x0 */
            UINT32 NOLOWPWRDUR             : 4;    /* reset value : 0x0 */
            UINT32 EN_HP_PM_TIMER          : 7;    /* reset value : 0x33 */
            UINT32 Reserved_31_26          : 6;    /* reset value : 0x0 */
        } b;
    } guctl2;

} GUCTL2_T;

/* =======================================================================
GEVNTCOUNT(#n) (Offset 0xc40c)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw        :32;

        struct
        {
            UINT32 EVNTCOUNT            :16;
            UINT32 reserved_30_16       :15;
            UINT32 EVNT_HANDLER_BUSY    :1;
        } b;
    } gevntcount;

} GEVNTCOUNT_T;

/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw       :32;

        struct
        {
            UINT32 EVENTSIZ             :16;
            UINT32 reserved_30_16       :15;
            UINT32 EVNTINTRPTMASK       :1;
        } b;
    } gevntsiz;

} GEVNTSIZ_T;

/* =======================================================================
GHWPARAMS8 (Offset 0xc600)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ghwparams8_32_0         : 32;   /* reset value : 0x5c3 */
        } b;
    } ghwparams8;

} GHWPARAMS8_T;

/* =======================================================================
GUCTL3 (Offset 0xc60c)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 Reserved_0_15           : 16;   /* reset value : 0x0 */
            UINT32 Sch_Ping_early          : 1;    /* reset value : 0x1 */
            UINT32 Reserved_31_17          : 15;   /* reset value : 0x0 */
        } b;
    } guctl3;

} GUCTL3_T;

/* =======================================================================
GTXFIFOPRIDEV
======================================================================= */

/* =======================================================================
GTXFIFOPRIHST
======================================================================= */

/* =======================================================================
GRXFIFOPRIHST
======================================================================= */

/* =======================================================================
GDMAHLRATIO
======================================================================= */

/* =======================================================================
GFLADJ
======================================================================= */

/* =======================================================================
DCFG (Offset 0xc700)
=======================================================================
Device Speed.
Indicates the speed at which the application requires the controller to connect, or the maximum speed the application can support.
However, the actual bus speed is determined only after the chirp sequence is completed, and is based on the speed of the USB host to which the controller is connected.
■ 3'b100: SuperSpeed (USB 3.0 PHY clock is 125 MHz or 250 MHz)
■ 3'b000: High-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz)
■ 3'b001: Full-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz)
Values:
■ 0x4 (SuperSpeed): SuperSpeed (USB 3.0 PHY clock is 125 MHz or 250 MHz)
■ 0x0 (HighSpeed): High-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz)
■ 0x1 (FullSpeed): Full-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz) */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 DEVSPD              : 3;    /* reset value : 0x4 */
            UINT32 DEVADDR             : 7;    /* reset value : 0x0 */
            UINT32 Reserved_11_10      : 2;    /* reset value : 0x2 */
            UINT32 INTRNUM             : 5;    /* reset value : 0x0 */
            UINT32 NUMP                : 5;    /* reset value : 0x4 */
            UINT32 LPMCAP              : 1;    /* reset value : 0x0 */
            UINT32 IgnStmPP            : 1;    /* reset value : 0x0 */
            UINT32 Reserved_24         : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_25      : 7;    /* reset value : 0x0 */
        } b;
    } dcfg;

} DCFG_T;

/* =======================================================================
DCTL: Device Control Register (Offset 0xc704)
If you want to improve interoperability as a Debug Capability Target,
program the InitU1/U2Ena and AcceptU1/U2Ena fields to '0' to disable U1/U2 entry.
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 Reserved_0          : 1;    /* reset value : 0x0 */
            UINT32 TSTCTL              : 4;    /* reset value : 0x0 */
            UINT32 ULSTCHNGREQ         : 4;    /* reset value : 0x0 */
            UINT32 ACCEPTU1ENA         : 1;    /* reset value : 0x0 */
            UINT32 INITU1ENA           : 1;    /* reset value : 0x0 */
            UINT32 ACCEPTU2ENA         : 1;    /* reset value : 0x0 */
            UINT32 INITU2ENA           : 1;    /* reset value : 0x0 */
            UINT32 Reserved_15_13      : 3;    /* reset value : 0x0 */
            UINT32 CSS                 : 1;    /* reset value : 0x0 */
            UINT32 CRS                 : 1;    /* reset value : 0x0 */
            UINT32 L1HibernationEn     : 1;    /* reset value : 0x0 */
            UINT32 KeepConnect         : 1;    /* reset value : 0x0 */
            UINT32 LPM_NYET_thres      : 4;    /* reset value : 0xf */
            UINT32 HIRDTHRES           : 5;    /* reset value : 0x0 */
            UINT32 Reserved_29         : 1;    /* reset value : 0x0 */
            UINT32 CSFTRST             : 1;    /* reset value : 0x0 */
            UINT32 RUN_STOP            : 1;    /* reset value : 0x0 */
        } b;
    } dctl;

} DCTL_T;

/* =======================================================================
DEVTEN (Offset 0xc708)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 DISSCONNEVTEN           : 1;    /* reset value : 0x0 */
            UINT32 USBRSTEVTEN             : 1;    /* reset value : 0x0 */
            UINT32 CONNECTDONEEVTEN        : 1;    /* reset value : 0x0 */
            UINT32 ULSTCNGEN               : 1;    /* reset value : 0x0 */
            UINT32 WKUPEVTEN               : 1;    /* reset value : 0x0 */
            UINT32 HibernationReqEvtEn     : 1;    /* reset value : 0x0 */
            UINT32 U3L2L1SuspEn            : 1;    /* reset value : 0x0 */
            UINT32 SOFTEVTEN               : 1;    /* reset value : 0x0 */
            UINT32 L1SUSPEN                : 1;    /* reset value : 0x0 */
            UINT32 ERRTICERREVTEN          : 1;    /* reset value : 0x0 */
            UINT32 Reserved_10             : 1;    /* reset value : 0x0 */
            UINT32 Reserved_11             : 1;    /* reset value : 0x0 */
            UINT32 VENDEVTSTRCVDEN         : 1;    /* reset value : 0x0 */
            UINT32 StopOnDisconnectEn      : 1;
            UINT32 L1WKUPEVTEN             : 1;    /* reset value : 0x0 */
            UINT32 Reserved_15             : 1;    /* reset value : 0x0 */
            UINT32 ECCERREN                : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_17          : 15;   /* reset value : 0x0 */
        } b;
    } devten;

} DEVTEN_T;

/* =======================================================================
DSTS (Offset 0xc70c)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 CONNECTSPD          : 3;    /* reset value : 0x4 */
            UINT32 SOFFN               : 14;   /* reset value : 0x0 */
            UINT32 RXFIFOEMPTY         : 1;    /* reset value : 0x1 */
            UINT32 USBLNKST            : 4;    /* reset value : 0x4 */
            UINT32 DEVCTRLHLT          : 1;    /* reset value : 0x1 */
            UINT32 COREIDLE            : 1;    /* reset value : 0x1 */
            UINT32 SSS                 : 1;    /* reset value : 0x0 */
            UINT32 RSS                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved_27_26      : 2;    /* reset value : 0x0 */
            UINT32 SRE                 : 1;    /* reset value : 0x0 */
            UINT32 DCNRD               : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_30      : 2;    /* reset value : 0x0 */
        } b;
    } dsts;

} DSTS_T;

/* =======================================================================
DGCMDPAR
======================================================================= */

/* =======================================================================
DGCMD (Offset 0xc714)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 CMDTYP              : 8;    /* reset value : 0x0 */
            UINT32 CMDIOC              : 1;    /* reset value : 0x0 */
            UINT32 Reserved_9          : 1;    /* reset value : 0x0 */
            UINT32 CMDACT              : 1;    /* reset value : 0x0 */
            UINT32 Reserved_11         : 1;    /* reset value : 0x0 */
            UINT32 CMDSTATUS           : 4;    /* reset value : 0x0 */
            UINT32 Reserved_31_16      : 16;   /* reset value : 0x0 */
        } b;
    } dgcmd;

} DGCMD_T;

/* =======================================================================
PORTSC_T
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 CCS                 : 1;    /* current connect status */
            UINT32 PED                 : 1;    /* Port Enabled / Disabled */
            UINT32 Reserved            : 1;
            UINT32 OCA                 : 1;    /* Over-current Active */
            UINT32 PR                  : 1;    /* Port Reset */
            UINT32 PLS                 : 4;    /* Port Link State */
            UINT32 PP                  : 1;    /* Port Power */
            UINT32 PS                  : 4;    /* Port Speed */
            UINT32 PIC                 : 2;    /* Port Indicator */
            UINT32 LWS                 : 1;    /* Port Link State Write Strobe */
            UINT32 CSC                 : 1;    /* Connect Status Change */
            UINT32 PEC                 : 1;    /* PEC */
            UINT32 WRC                 : 1;    /* Warm Port Reset */
            UINT32 OCC                 : 1;    /* Over-Current Change */
            UINT32 PRC                 : 1;    /* Port Reset Change */
            UINT32 PLC                 : 1;    /* Port Link State */
            UINT32 CEC                 : 1;    /* Port Config Error Change */
            UINT32 CAS                 : 1;    /* Cold Attach Status */
            UINT32 WCE                 : 1;    /* Wake On Connect Enable */
            UINT32 WDE                 : 1;    /* Wake On Disconnect Enable */
            UINT32 Reserved_29_28      : 2;
            UINT32 DR                  : 1;    /* Dvice Removable */
            UINT32 WPR                 : 1;    /* Warm Port Reset */
        } b;
    } portsc;

} PORTSC_T;

/* =======================================================================
USBCMD
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 R_S                 : 1;    /* reset value : 0x0 */
            UINT32 HCRST               : 1;    /* reset value : 0x0 */
            UINT32 INTE                : 1;    /* reset value : 0x0 */
            UINT32 HSEE                : 1;    /* reset value : 0x0 */
            UINT32 Reserved_6_4        : 3;    /* reset value : 0x0 */
            UINT32 LHCRST              : 1;    /* reset value : 0x0 */
            UINT32 CSS                 : 1;    /* reset value : 0x0 */
            UINT32 CRS                 : 1;    /* reset value : 0x0 */
            UINT32 EWE                 : 1;    /* reset value : 0x0 */
            UINT32 EU3S                : 1;    /* reset value : 0x0 */
            UINT32 Reserved_12         : 1;    /* reset value : 0x0 */
            UINT32 CME                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_14      : 18;   /* reset value : 0x0 */
        } b;
    } usbcmd;

} USBCMD_T;

/* =======================================================================
USBSTS (Offset 0x24)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 HCH                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved_1          : 1;    /* reset value : 0x0 */
            UINT32 HSE                 : 1;    /* reset value : 0x0 */
            UINT32 EINT                : 1;    /* reset value : 0x0 */
            UINT32 PCD                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved_7_15       : 3;    /* reset value : 0x0 */
            UINT32 SSS                 : 1;    /* reset value : 0x0 */
            UINT32 RSS                 : 1;    /* reset value : 0x0 */
            UINT32 SRE                 : 1;    /* reset value : 0x0 */
            UINT32 CNR                 : 1;    /* reset value : 0x1 */
            UINT32 HCE                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_13      : 19;   /* reset value : 0x0 */
        } b;
    } usbsts;

} USBSTS_T;

/* =======================================================================
PAGESIZE
======================================================================= */

/* =======================================================================
DNCTRL
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 N0_N15              : 16;   /* reset value : 0x0 */
            UINT32 Reserved            : 16;   /* reset value : 0x0 */
        } b;
    } dnctrl;

} DNCTRL_T;

/* =======================================================================
CRCR_LO
======================================================================= */

/* =======================================================================
CRCR_HI
======================================================================= */

/* =======================================================================
DCBAAP_LO
======================================================================= */

/* =======================================================================
DCBAAP_HI
======================================================================= */

/* =======================================================================
CONFIG
======================================================================= */

/* =======================================================================
MFINDEX
======================================================================= */

/* =======================================================================
RsvdZ
======================================================================= */

/* =======================================================================
USBLEGSUP
======================================================================= */

/* =======================================================================
USBLEGCTLSTS
======================================================================= */

/* =======================================================================
SUPTPRT2_DW0
======================================================================= */


/* =======================================================================
SUPTPRT2_DW1
======================================================================= */


/* =======================================================================
SUPTPRT2_DW2
======================================================================= */


/* =======================================================================
SUPTPRT2_DW3
======================================================================= */


/* =======================================================================
SUPTPRT3_DW0
======================================================================= */


/* =======================================================================
SUPTPRT3_DW1
======================================================================= */


/* =======================================================================
SUPTPRT3_DW2
======================================================================= */


/* =======================================================================
SUPTPRT3_DW3
======================================================================= */


/* =======================================================================

======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw       :32;

        struct
        {
            UINT32      CMDTYP              :4;
            UINT32      reserved_7_4        :4;
            UINT32      CMDIOC              :1;
            UINT32      reserved_9          :1;
            UINT32      CMDACT              :1;
            UINT32      HIPRI_FORCERM       :1;
            UINT32      CMDSTATUS           :4;
            UINT32      COMMANDPARAM        :16;
        } b;
    } depcmd;

} DEPCMD_T;

/* =======================================================================
APACHE6_PMU
=======================================================================
=======================================================================
ISO_EN_BLK_USB (Offset 0x0560)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        /* BLK_USB Boundary port Isolation Control */
        /* 0: Isolation Disable (Connected)     0x1 */
        /* 1: Isolation Enable (Disconnected) */
        struct
        {
            UINT32 ISO_EN_BLK_USB          : 1;    /* reset value : 0x1 */
            UINT32 Reserved                : 31;
        } b;
    } iso_en_blk_usb;

} ISO_EN_BLK_USB_T;

/* =======================================================================
PWR_OFF_BLK_USB (Offset 0x0564)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        /* BLK_USB Power Domain Power Gate Control */
        /* 0: Power On      0x1 */
        /* 1: Power Off */
        struct
        {
            UINT32 PWR_OFF_BLK_USB         : 1;    /* reset value : 0x1 */
            UINT32 Reserved                : 31;
        } b;
    } pwr_off_blk_usb;

} PWR_OFF_BLK_USB_T;

/* =======================================================================
T_WAKEUP_DLY_BLK_USB (Offset 0x0568)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        /* SCPRE to SCALL delay when wake-up (OSC_CK clock) */
        struct
        {
            UINT32 T_WAKEUP_DLY_BLK_USB            : 16;    /* reset value : 0x0FFF */
            UINT32 Reserved                        : 16;
        } b;
    } t_wakeup_dly_blk_usb;

} T_WAKEUP_DLY_BLK_USB_T;

/* =======================================================================
MANU_EN_BLK_USB (Offset 0x056c)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        struct
        {
            /* Power Gating Manual Control */
            /* [2]: SCALL out */
            /* [1]: SCPRE out */
            /* [0]: Reserved */
            UINT32 MANU_EN_BLK_USB                 : 1;    /* reset value : 0x0 */
            UINT32 Reserved                        : 31;
        } b;
    } manu_en_blk_usb;
} MANU_EN_BLK_USB_T;

/* =======================================================================
SC_CTRL_BLK_USB (Offset 0x0574)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        struct
        {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_USB          : 1;    /* ISO_EN polarity 1: Inverse, 0: Normal     reset value : 0x0 */
            UINT32 SC_CTRL_POL_SCPRE_BLK_USB           : 1;    /* SCPRE polarity 1: Inverse, 0: Normal      reset value : 0x0 */
            UINT32 SC_CTRL_POL_SCALL_BLK_USB           : 1;    /* SCALL polarity 1: Inverse, 0: Normal      reset value : 0x0 */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_USB       : 1;    /* SCALL_OUT polarity 1: Inverse, 0: Normal  reset value : 0x0 */
            UINT32 SC_CTRL_REG_CLEAR_BLK_USB           : 1;    /* Power Gate Control CLear                  reset value : 0x0 */
            UINT32 Reserved                            : 27;   /*                                           reset value : 0x0 */
        } b;
    } sc_ctrl_blk_usb;

} SC_CTRL_BLK_USB_T;

/* =======================================================================
SC_STATUS_BLK_USB (Offset 0x0578)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        /* BLK_USB Power Domain Gating Congtrol Signal Status */
        /* [2]: SCALL */
        /* [1]: SCPRE */
        /* [0]: CALL_OUT */
        struct
        {
            UINT32 SC_STATUS_BLK_USB                   : 3;    /* reset value : 0x0 */
            UINT32 Reserved                            : 29;
        } b;
    } sc_status_blk_usb;

} SC_STATUS_BLK_USB_T;

/* =======================================================================
APACHE6_Datasheet_SYS_SCU
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        struct
        {
            UINT32 PUL_RST_ACT_BLK_USB_APB                 : 1;
            UINT32 Reserved_3_1                            : 3;
            UINT32 PUL_RST_ACT_BLK_PCIE_APB                : 1;
            UINT32 Reserved_31_5                           : 27;
        } b;
    } pu_rst_act_6;

} PUL_RST_ACT_6_T;

/* =======================================================================
SYS_CLKEN6 (Offsete 0x3058)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw          : 32;

        struct
        {
            UINT32 CLKEN_BLK_USB_APB                   : 1;    /* reset value : 0x1 */
            UINT32 Reserved_3_1                        : 3;
            UINT32 CLKEN_BLK_PCIE_APB                  : 1;    /* reset value : 0x1 */
            UINT32 Reserved_31_5                       : 27;
        } b;
    } sys_clken6;

} SYS_CLKEN6_T;

/* =======================================================================
ONGO_RST_ACT_6 (Offsete 0x4018)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 ONGO_RST_ACT_BLK_USB_APB            : 1;    /* reset value : 0x0 */
            UINT32 Reserved_3_1                        : 3;
            UINT32 ONGO_RST_ACT_BLK_PCIE_APB           : 1;    /* reset value : 0x0 */
            UINT32 Reserved_31_5                       : 27;
        } b;
    } ongo_rst_act_6;

} ONGO_RST_ACT_6_T;

/* =======================================================================
USB_POR_RST_ACT_0 (Offsete 0x4F90)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 USB_POR_RST_ACT_0                   : 1;    /* reset value : 0x */
            UINT32 Reserved_31_1                       : 31;
        } b;
    } usb_por_pst_act_0;

} USB_POR_RST_ACT_0_T;

/* =======================================================================
USB_POR_RST_ACT_1 (Offsete 0x4F94)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 USB_POR_RST_ACT_1                   : 1;    /* reset value : 0x */
            UINT32 Reserved_31_1                       : 31;
        } b;
    } usb_por_rst_act_1;

} USB_POR_RST_ACT_1_T;

/* =======================================================================
USB_POR_RST_ACT_2 (Offsete 0x4F98)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw  : 32;

        struct
        {
            UINT32 USB_POR_RST_ACT_2                   : 1;    /* reset value : 0x */
            UINT32 Reserved_31_1                       : 31;
        } b;
    } usb_por_rst_act;

} USB_POR_RST_ACT_2_T;



/* =======================================================================
xHCI Host Registers
=======================================================================
For the starting address of xHCI registers, ~~
For register definitions, refer to the xHCI spsecification.
The following sections give information on parameters in the capability registers. */


/* =======================================================================
1.1 DWC_usb3_block_eXtensible_Host_Cntrl_Cap_Regs Registers
======================================================================= */

/* =======================================================================
1.1.1 CAPLENGTH     0x71000000
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 CAPLENGTH   : 8;    /* reset value : 0x100      Capability Registers Length */
            UINT32 reserved    : 8;
            UINT32 HCIVERSION  : 16;   /* reset value : 0x20       HC Interface Version Number */
        } b;
    } caplength;

} CAPLENGTH_T;

/* 0x71000004 */ 
/* =======================================================================
1.1.2 HCSPARAMS1 (Host Controller Structural Parameters 1)   
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 MAXSLOTS : 8;       /*  reset value : 0x40   Number of Device Slots, Defined by configurable parameter DWC_USB3_NUM_DEVICE_SUPT    */
            UINT32 MAXINTRS : 11;      /*  reset value : 0x1    Number of Interrupters Defined by the configurable parameter DWC_USB3_HOST_NUM_INTERRUPTER_SUPT */
            UINT32 reserved : 5;       /*  reset value : 0x0 */
            UINT32 MAXPORTS : 8;       /*  reset value : 0x40   Number of Ports, Number of ports implemnted is defined by the parameter (DWC_USB3_HOST_NUM_U2_ROOT_PORTS + DWC_USB3_HOST_NUM_U3_ROOT_PORTS) */
                                    /* Number of ports enabled is controlled by the core input pings host_num_u2_port[3:0] + host_num_u3_port[3:0] */
        } b;
    } hcsparams1;

} HCSPARAMS1_T;

/* =======================================================================
1.1.3 HCSPARAMS2 (Host Controller Structural Parameters 2)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 IST                         : 4;
            UINT32 ERSTMAX                     : 4;
            UINT32 Reserved_20_8               : 13;
            UINT32 MAXSCRaTCHPADBUFS_HI        : 5;
            UINT32 SPR                         : 1;
            UINT32 MAXSCRaTCHPaDBUFS           : 5;
        } b;
    } hcsparams2;

} HCSPARAMS2_T;

/* =======================================================================
1.1.4 HCSPARAMS3 (Host Controller Structural Parameters 3)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 U1_DEVICE_EXIT_LAT      : 8;    /* U1 Device Exit Latency */
            UINT32 Reserved_15_8           : 8;
            UINT32 U2_DEVICE_EXIT_LaT      : 16;   /* U2 Device Exit Latency */
        } b;
    } hcsparams3;

} HCSPARAMS3_T;

/* =======================================================================
1.1.5 HCCPARAMS1 (Host Controller Capability Parameters 1)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 AC64            : 1;
            UINT32 BNC             : 1;
            UINT32 CSZ             : 1;
            UINT32 PPC             : 1;
            UINT32 PIND            : 1;
            UINT32 LHRC            : 1;    /* Light HC Reset Capability */
            UINT32 LTC             : 1;
            UINT32 NSS             : 1;
            UINT32 PAE             : 1;
            UINT32 SPC             : 1;
            UINT32 SECS             : 1;   /*  FIX: TODO */
            UINT32 CFC             : 1;
            UINT32 MAXPSASIZE      : 4;
            UINT32 XECP            : 16;   /* xHCI Extended Capabilities Pointer */
        } b;
    } hccparams1;

} HCCPARAMS1_T;

/* =======================================================================
1.1.6 DBOFF (Doorbell Offset)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_1_0                : 2;
            UINT32 DOORBELL_ARRaY_OFFSET       : 30;   /* Doorbell Array Offset */
        } b;
    } dboff_t;

} DBOFF_T;

/* =======================================================================
1.1.7 RTSOFF
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 Reserved_4_0                : 5;
            UINT32 RUNTIME_REG_SPACE_OFFSET    : 27;
        } b;
    } rtsoff;

} RTSOFF_T;

/* =======================================================================
1.1.8 HCCPARAMS2 (Host Controller Capability Parameters 2)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 U3C             : 1;
            UINT32 CMC             : 1;
            UINT32 FSC             : 1;
            UINT32 CTC             : 1;
            UINT32 LEC             : 1;
            UINT32 CIC             : 1;
            UINT32 Reserved_31_6   : 26;
        } b;
    } hccparams2;

} HCCPARAMS2_T;

/* =======================================================================
1.4.2.692 USB Fault mask (Offset 0x10100)
======================================================================= */
typedef struct
{
    union
    {
        UINT32 dw : 32;

        struct
        {
            UINT32 clkmoni__clk_usb_apb        : 1;
            UINT32 clkmoni__clk_usb_core       : 1;
            UINT32 clkmoni__clk_usb_safety     : 1;
            UINT32 clkmoni__clk_usb_suspend    : 1;
            UINT32 clkmoni__clk_usb_refclk     : 1;
            UINT32 usb_ram0_ded_error          : 1;
            UINT32 usb_ram0_sec_warning        : 1;
            UINT32 usb_ram1_ded_error          : 1;
            UINT32 usb_ram1_sec_warning        : 1;
            UINT32 usb_ram2_ded_error          : 1;
            UINT32 usb_ram2_sec_warning        : 1;
            UINT32 Reserved_31_11              : 21;
        } b;
    } usb_ft_mask;

} USB_FT_MASK_T;



#endif
