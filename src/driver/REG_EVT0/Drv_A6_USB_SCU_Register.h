
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Platform   : APACHE6
*   File       : DRV_A6_USB_SCU_Register.h
*   Date       : 2022-10-12 10:54
* 
*   THIS CODE WAS GENERATED FROM THE APACHE6 HSI DOCUMENTATION. PLEASE DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_USB_SCU_H__
#define DRV_REGISTER_A6_USB_SCU_H__

#define APACHE_A6_USB_SCU_BASE_ADDR        0x06630000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_DATE                                                                                         : 32;     /* [ 31:0] Indicates the DATE when this SCU register set was generated
                                                                                                                                             3116 is Year 158 is Month 70 is Day */
        }Bit;
    }SFR_GEN_DATE;
    union { /* 0x0004 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_TIME                                                                                         : 32;     /* [ 31:0] Indicates the TIME when this SCU register set was generated
                                                                                                                                             2316 is Hour 158 is Minute 70 is Second */
        }Bit;
    }SFR_GEN_TIME;
    union { /* 0x0008 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_CHKSUM                                                                                       : 32;     /* [ 31:0] Indicates the CHECKSUM of scu_regreg_config file */
        }Bit;
    }SFR_GEN_CHKSUM;

    UINT8 EMPTY1[1012]; /* 0x3F4 */

    union { /* 0x0400 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_USB_PRE1                                                                                  : 1;      /* [    0] PLL selection for PRE1 clock source
                                                                                                                                             0 SYS PLL
                                                                                                                                             1 CPU PLL */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }USB_PRE1_CLKMUX;
    union { /* 0x0404 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 CLKMUX_SEL_USB_PRE2                                                                                  : 2;      /* [  1:0] PLL selection for PRE2 clock source
                                                                                                                                             0 SYS PLL
                                                                                                                                             1 CPU PLL
                                                                                                                                             2 NPU PLL
                                                                                                                                             3 NPU PLL */
            UINT32 RESERVED1                                                                                            : 30;     /* [ 31:2]  */
        }Bit;
    }USB_PRE2_CLKMUX;

    UINT8 EMPTY2[504]; /* 0x1F8 */

    union { /* 0x0600 [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_USBC_BUS                                                                                  : 8;      /* [  7:0] USBC_BUS Clock divide value from USB_PRE1
                                                                                                                                             h5 2000MHz - 400MHz */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_USBC_BUS;
    union { /* 0x0604 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_USB_SUSPEND                                                                               : 8;      /* [  7:0] USB_SUSPEND Clock divide value from USB_PRE2
                                                                                                                                             h50 2000MHz - 40MHz */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_USB_SUSPEND;
    union { /* 0x0608 [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 CLKDIV_VAL_USB_REF_CLK                                                                               : 8;      /* [  7:0] USB_REF Clock divide value from USB_PRE2
                                                                                                                                             h64 2000MHz - 20MHz */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }VAL_USB_REF;

    UINT8 EMPTY3[500]; /* 0x1F4 */

    union { /* 0x0800 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 CLKEN_USBC_BUS                                                                                       : 1;      /* [    0] USBC_BUS Clock Enable */
            UINT32 CLKEN_USB_SUSPEND                                                                                    : 1;      /* [    1] USB_SUSPEND Clock Enable */
            UINT32 CLKEN_USB_REF_CLK                                                                                    : 1;      /* [    2] USB_REF Clock Enable */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }USB_CLKEN;

    UINT8 EMPTY4[508]; /* 0x1FC */

    union { /* 0x0a00 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 ONGO_RST_ACT_USBC_BUS                                                                                : 1;      /* [    0] USBC_BUS Reset Level Control */
            UINT32 ONGO_RST_ACT_USB_SUSPEND                                                                             : 1;      /* [    1] USB_SUSPEND Reset Level Control */
            UINT32 ONGO_RST_ACT_USB_REF_CLK                                                                             : 1;      /* [    2] USB_REF Reset Level Control */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }USB_ONGO_RST_ACT;

    UINT8 EMPTY5[252]; /* 0xFC */

    union { /* 0x0b00 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_ACT_USBC_BUS                                                                                 : 1;      /* [    0] USBC_BUS Reset Pulse Trigger */
            UINT32 PUL_RST_ACT_USB_SUSPEND                                                                              : 1;      /* [    1] USB_SUSPEND Reset Pulse Trigger */
            UINT32 PUL_RST_ACT_USB_REF_CLK                                                                              : 1;      /* [    2] USB_REF Reset Pulse Trigger */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }USB_PUL_RST_ACT;

    UINT8 EMPTY6[252]; /* 0xFC */

    union { /* 0x0c00 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_USBC_BUS                                                                               : 16;     /* [ 15:0] USB_REF Resets Width of Pulse Trigger Reset */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }USBC_BUS_RST_WIDTH;
    union { /* 0x0c04 [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_USB_SUSPEND                                                                            : 16;     /* [ 15:0] USB_SUSPEND Resets Width of Pulse Trigger Reset */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }USB_SUSPEND_RST_WIDTH;
    union { /* 0x0c08 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 PUL_RST_WIDTH_USB_REF_CLK                                                                            : 16;     /* [ 15:0] USBC_BUS Resets Width of Pulse Trigger Reset */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }USB_REF_CLK_RST_WIDTH;

    UINT8 EMPTY7[46068]; /* 0xB3F4 */

    union { /* 0xc000 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 STARTRXDETU3RXDET                                                                                    : 1;      /* [    0] This signal is the Start Receiver Detection in U3RxDetect
                                                                                                                                             StartRxdetU3RxDet
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 DISRXDETU3RXDET                                                                                      : 1;      /* [    1] This input signal requests the controller to stop issuing more PHY
                                                                                                                                             commands and release the PIPE ownership
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 30;     /* [ 31:2]  */
        }Bit;
    }USBCON_MISC0;
    union { /* 0xc004 [Excel Line :0042]  */
        UINT32 Reg;
        struct {
            UINT32 GP_IN                                                                                                : 16;     /* [ 15:0] General Purpose Input Port can be used as general purpose inputs
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 1;      /* [   16]  */
            UINT32 BIGENDIAN_GS                                                                                         : 1;      /* [   17] Slave Big Endian Select AHBAXINative
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 BUS_CLKEN_GM                                                                                         : 1;      /* [   18] Master Interface Clock Enable AHBAXINative
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 BUS_CLKEN_GS                                                                                         : 1;      /* [   19] Slave Interface Clock Enable AHBAXINative
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PME_EN                                                                                               : 1;      /* [   20] Enable signal for the pme_generation Enable the controller to assert
                                                                                                                                             pme_generation
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 11;     /* [31:21]  */
        }Bit;
    }USBCON_MISC1;
    union { /* 0xc008 [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 HUB_PORT_PERM_ATTACH                                                                                 : 2;      /* [  1:0] Indicates if the device attached to a downstream port is permanently
                                                                                                                                             attached or not
                                                                                                                                              0 Not permanently attached
                                                                                                                                              1 Permanently attached
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HUB_PORT_OVERCURRENT                                                                                 : 2;      /* [  3:2] This is the per port Overcurrent indication of the root-hub ports
                                                                                                                                              0 No Overcurrent
                                                                                                                                              1 Overcurrent
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 28;     /* [ 31:4]  */
        }Bit;
    }USBCON_MISC2;
    union { /* 0xc00c [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 HOST_NUM_U2_PORT                                                                                     : 4;      /* [  3:0] Number of USB 20 Ports
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_NUM_U3_PORT                                                                                     : 4;      /* [  7:4] Number of USB 30 SS Ports
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_U2_PORT_DISABLE                                                                                 : 1;      /* [    8] USB 20 Port Disable control
                                                                                                                                              0 Port Enabled
                                                                                                                                              1 Port Disabled When 1 this signal stops reporting
                                                                                                                                             connectdisconnect events the port and keeps the port in disabled
                                                                                                                                             state
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_U3_PORT_DISABLE                                                                                 : 1;      /* [    9] USB 30 SS Port Disable control
                                                                                                                                              0 Port Enabled
                                                                                                                                              1 Port Disabled
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_PORT_POWER_CONTROL_PRESENT                                                                      : 1;      /* [   10] This port defines the bit 3 of Capability Parameters HCCPARAMS
                                                                                                                                             Change the PPC value through the pin Port Power Control PPC This indicates whether the host controller implementation includes port
                                                                                                                                             power control
                                                                                                                                              0 Indicates that the port does not have port power switches
                                                                                                                                              1 Indicates that the port has port power switches
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_MSI_ENABLE                                                                                      : 1;      /* [   11] This enables the pulse type interrupt signal one bus clock cycle
                                                                                                                                             interrupt port instead of level-sensitive interrupt
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_LEGACY_SMI_PCI_CMD_REG_WR                                                                       : 1;      /* [   12] PCI command register write
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_LEGACY_SMI_BAR_WR                                                                               : 1;      /* [   13] PCI Base Address register BAR write
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 18;     /* [31:14]  */
        }Bit;
    }USBCON_MISC3;
    union { /* 0xc010 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 DFT_EN_RAM_CLK_GATED                                                                                 : 1;      /* [    0] At-Speed DFT port that controls ram_clk_gated and
                                                                                                                                             ram_clk_gated_ram0
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 DFT_EN_BUS_CLK_GATED                                                                                 : 1;      /* [    1] At-Speed DFT control port that controls bus_clk_gated
                                                                                                                                             This signal is 0 by default
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 2;      /* [  3:2]  */
            UINT32 FLADJ_30MHZ_REG                                                                                      : 6;      /* [  9:4] HS Jitter Adjustment
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 2;      /* [11:10]  */
            UINT32 BUS_FILTER_BYPASS                                                                                    : 4;      /* [15:12] Bus Filter Bypass Disables the internal bus filters that are enabled by
                                                                                                                                             DWC_USB3_EN_BUS_FILTERS coreConsultant parameter This static signal is present only when DWC_USB3_EN_BUS_FILTERS is 1 It is expected that this signal is set or reset at power-on reset and is not changed during the normal operation of the controller The function of each bit is
                                                                                                                                              bus_filter_bypass3 Reserved
                                                                                                                                              bus_filter_bypass2 Bypass the filter for utmisrp_bvalid
                                                                                                                                              bus_filter_bypass1 Bypass the filter for pipe3_PowerPresent all
                                                                                                                                             U3 ports
                                                                                                                                              bus_filter_bypass0 Bypass the filter for utmiotg_vbusvalid all U2
                                                                                                                                             ports
                                                                                                                                             In Host-only mode internal bus filters are not needed Therefore
                                                                                                                                             bus_filter_bypass20 must be connected to logic high value 3b111
                                                                                                                                             The reserved bit can be tied to 0 or 1 but should not be floating
                                                                                                                                             Values
                                                                                                                                              1b0 Bus filters enabled
                                                                                                                                              1b1 Bus filters disabled bypassed
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 XHC_BME                                                                                              : 1;      /* [   16] This signal is used to disable the bus mastering capability of the xHC In a PCI system it comes from the Bus Master Enable BME bit of the
                                                                                                                                             Device Control Register in the PCI Configuration register space
                                                                                                                                              1b0 Bus mastering capability is disabled The host controller
                                                                                                                                             cannot use the bus master interface
                                                                                                                                              1b1 Bus mastering capability is enabled
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 15;     /* [31:17]  */
        }Bit;
    }USBCON_MISC4;

    UINT8 EMPTY8[108]; /* 0x6C */

    union { /* 0xc080 [Excel Line :0069]  */
        UINT32 Reg;
        struct {
            UINT32 LOGIC_ANALYZER_TRACE_31_0                                                                            : 32;     /* [ 31:0] Logic Analyzer Trace310 These are internal design signals that you can use for debug purposes Some of the signals are interface signals like PIPE UTMI ULPI AXI and AHB and others are internal state
                                                                                                                                             machines and status information signals During chip bring-up to debug functional issues you can probe the interface signals for additional visibility Chip Debug
                                                                                                                                             Refer to USB controller databook for more information about this register */
        }Bit;
    }USBCON_MISC5;
    union { /* 0xc084 [Excel Line :0070]  */
        UINT32 Reg;
        struct {
            UINT32 LOGIC_ANALYZER_TRACE_63_32                                                                           : 32;     /* [ 31:0] Logic Analyzer Trace6331 These are internal design signals that you can use for debug purposes Some of the signals are interface signals like PIPE UTMI ULPI AXI and AHB and others are internal state machines and status information signals During chip bring-up to debug functional issues you can probe the interface signals for additional visibility Chip Debug
                                                                                                                                             Refer to USB controller databook for more information about this register */
        }Bit;
    }USBCON_MISC6;
    union { /* 0xc088 [Excel Line :0071]  */
        UINT32 Reg;
        struct {
            UINT32 GP_OUT                                                                                               : 16;     /* [ 15:0] General Purpose Output Port can be used as general purpose outputs
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PME_GENERATION                                                                                       : 1;      /* [   16] PME Generation
                                                                                                                                             This signal is used to generate a PME Power Management Event
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 15;     /* [31:17]  */
        }Bit;
    }USBCON_MISC7;
    union { /* 0xc08c [Excel Line :0074]  */
        UINT32 Reg;
        struct {
            UINT32 HOST_CURRENT_BELT                                                                                    : 12;     /* [ 11:0] Current BELT Value
                                                                                                                                             This signal indicates the minimum value of all received BELT values and the BELT that is set by the Set LTV command This signal is valid only in Host mode
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 4;      /* [15:12]  */
            UINT32 HOST_SYSTEM_ERR                                                                                      : 1;      /* [   16] Host System Error
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HOST_LEGACY_SMI_INTERRUPT                                                                            : 1;      /* [   17] SMI interrupt active high
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }USBCON_MISC8;
    union { /* 0xc090 [Excel Line :0079]  */
        UINT32 Reg;
        struct {
            UINT32 OPERATIONAL_MODE                                                                                     : 2;      /* [  1:0] Port capability direction
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CLK_GATE_CTRL                                                                                        : 3;      /* [ 10:8] Clock gating control
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 21;     /* [31:11]  */
        }Bit;
    }USBCON_MISC9;
    union { /* 0xc094 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 DISRXDETU3RXDET_ACK                                                                                  : 1;      /* [    0] DisRxDetU3RxDet_ack of USB 30 SS Ports
                                                                                                                                             This signal is an acknowledgment of DisRxDetU3RxDet When this
                                                                                                                                             signal is 1b1 the controller releases the ownership of the the PIPE
                                                                                                                                             interface and does not issue PHY commands to the PIPE interface
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMI_L1_SUSPEND_COM_N                                                                                : 1;      /* [    1] Common L1 suspend
                                                                                                                                             For device mode this signal is the same as inverted
                                                                                                                                             utmi_l1_suspend_n0
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMI_SUSPEND_COM_N                                                                                   : 1;      /* [    2] UTMI common Suspend
                                                                                                                                             For device mode of operation this signal is same as inverted
                                                                                                                                             utmi_suspend_n0
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PIPE3_PHY_MODE                                                                                       : 2;      /* [  4:3] PIPE3 PHY Mode Hard wire to USB3 mode
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PIPE3_COMPLIANCE                                                                                     : 1;      /* [    5] PIPE3 PCIe Compliance Pattern Hard wired to 1b0
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PIPE3_RATE                                                                                           : 1;      /* [    6] PIPE3 Data Rate Hard wired to 1b1
                                                                                                                                             Values
                                                                                                                                              1b0 25GHz
                                                                                                                                              1b1 5GHz
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PIPE3_TXMARGIN                                                                                       : 3;      /* [  9:7] PIPE3 Transmit Voltage Level
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 PIPE3_TXSWING                                                                                        : 1;      /* [   10] PIPE3 Voltage Swing
                                                                                                                                             Values
                                                                                                                                              1b0 Full swing
                                                                                                                                              1b1 Low swing
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 HUB_VBUS_CTRL                                                                                        : 2;      /* [12:11] Port Power control for each downstream port
                                                                                                                                              0 VBUS OFF
                                                                                                                                              1 VBUS ON
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMIOTG_DMPULLDOWN                                                                                   : 1;      /* [   13] D Pull-down Resistor Enable Enables the 15 KW pull-down resistor on the D line
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMIOTG_DPPULLDOWN                                                                                   : 1;      /* [   14] D Pull-down Resistor Enable Enables the 15 KW pull-down resistor
                                                                                                                                             the D line
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMI_SLEEP_N                                                                                         : 1;      /* [   15] This port uses utmi_clki during USB 20 HSFSLS operational mode otherwise bus_clk_early or ulpi_clki where 0i14 depending on your configuration
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 UTMI_L1_SUSPEND_N                                                                                    : 1;      /* [   16] UTMI Suspend in L1
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 15;     /* [31:17]  */
        }Bit;
    }USBCON_MISC10;
    union { /* 0xc098 [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 USB_DEBUG_66_64                                                                                      : 3;      /* [  2:0] Debug6664 Port
                                                                                                                                             Refer to USB controller databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }USBCON_MISC11;
    union { /* 0xc09c [Excel Line :0099]  */
        UINT32 Reg;
        struct {
            UINT32 USB_DEBUG_63_32                                                                                      : 32;     /* [ 31:0] Debug6332 Port
                                                                                                                                             Refer to USB controller databook for more information about this register */
        }Bit;
    }USBCON_MISC12;
    union { /* 0xc0a0 [Excel Line :0100]  */
        UINT32 Reg;
        struct {
            UINT32 USB_DEBUG_31_0                                                                                       : 32;     /* [ 31:0] Debug310 Port
                                                                                                                                             Refer to USB controller databook for more information about this register */
        }Bit;
    }USBCON_MISC13;

    UINT8 EMPTY9[92]; /* 0x5C */

    union { /* 0xc100 [Excel Line :0101]  */
        UINT32 Reg;
        struct {
            UINT32 TXBITSTUFFENH0                                                                                       : 1;      /* [    0] High-Byte Transmit Bit-Stuffing Enable
                                                                                                                                             This controller signal controls bit stuffing on DATAINHN70 when
                                                                                                                                             OPMODEN10  2b11
                                                                                                                                              1 Bit stuffing is enabled
                                                                                                                                              0 Bit stuffing is disabled
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TXBITSTUFFEN0                                                                                        : 1;      /* [    1] Low-Byte Transmit Bit-Stuffing Enable
                                                                                                                                             This controller signal controls bit stuffing on DATAINN70 when
                                                                                                                                             OPMODEN10  2b11
                                                                                                                                              1 Bit stuffing is enabled
                                                                                                                                              0 Bit stuffing is disabled
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 IDPULLUP0                                                                                            : 1;      /* [    2] Analog ID Input Sample Enable
                                                                                                                                             This controller signal controls IDN line sampling
                                                                                                                                              1 IDN pin sampling is enabled and the IDDIG0 output is valid
                                                                                                                                              0 IDN pin sampling is disabled and the IDDIG0 output is not
                                                                                                                                             valid
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 OTGDISABLE0                                                                                          : 1;      /* [    3] OTG Block Disable
                                                                                                                                             This controller signal powers down the OTG block which disables the
                                                                                                                                             VBUS Valid and Session End comparators The Session Valid
                                                                                                                                             comparator the output of which is used to enable the pull-up resistor
                                                                                                                                             on DPN in Device mode is always on irrespective of the state of
                                                                                                                                             OTGDISABLE0 If the application does not use the OTG function
                                                                                                                                             this input can be set high to save power
                                                                                                                                              1 OTG block is powered down
                                                                                                                                              0 OTG block is powered up
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 COMMONONN                                                                                            : 1;      /* [    4] Common Block Power-Down Control
                                                                                                                                             Controls the power-down signals in the PLL block when the USB 30
                                                                                                                                             femtoPHY is in Suspend or Sleep mode
                                                                                                                                              1 In Suspend or Sleep mode the PLL block is powered down
                                                                                                                                              0 In Suspend or Sleep mode the PLL block remains powered
                                                                                                                                             and continues to draw current
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 SSC_EN                                                                                               : 1;      /* [    5] Spread Spectrum Enable
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 VBUSVLDEXTSEL0                                                                                       : 1;      /* [    6] External VBUS Valid Select
                                                                                                                                             Selects the VBUSVLDEXTN input or the internal Session Valid
                                                                                                                                             comparator to indicate when the VBUS signal on the USB cable
                                                                                                                                             is valid
                                                                                                                                              1 VBUSVLDEXTN input is used
                                                                                                                                              0 Internal Session Valid comparator is used
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 VBUSVLDEXT0                                                                                          : 1;      /* [    7] External VBUS Valid Indicator
                                                                                                                                             Valid in Device mode and only when the VBUSVLDEXTSEL0 signal
                                                                                                                                             is set to 1b1 VBUSVLDEXTN indicates whether the VBUS
                                                                                                                                             signal on the USB cable is valid In addition VBUSVLDEXTN
                                                                                                                                             enables the pull- up resistor on the D line
                                                                                                                                              1 VBUS signal is valid and the pull-up resistor on D is
                                                                                                                                             enabled
                                                                                                                                              0 VBUS signal is not valid and the pull-up resistor on D is
                                                                                                                                             disabled In Host mode this input is not used and can be tied to
                                                                                                                                             1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }USBPHY_MISC0;

    UINT8 EMPTY10[4]; /* 0x4 */

    union { /* 0xc108 [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 PCS_TX_DEEMPH_3P5DB                                                                                  : 6;      /* [  5:0] TX De-Emphasis at 35 dB
                                                                                                                                             This static value sets the TX driver de-emphasis value when
                                                                                                                                             pipeN_tx_deemph10 is set to 2b01 according to the PIPE3
                                                                                                                                             specification To enable tuning at the board level for RX eye
                                                                                                                                             compliance connect this signal to a register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 10;     /* [ 15:6]  */
            UINT32 PCS_RX_LOS_MASK_VAL                                                                                  : 10;     /* [25:16] Configurable Loss-of-Signal Mask Width
                                                                                                                                             Sets the number of reference clock cycles to mask the incoming
                                                                                                                                             LFPS in U3 and U2 states Masks the incoming LFPS for the number
                                                                                                                                             of reference clock cycles equal to the value of
                                                                                                                                             pcs_rx_los_mask_val90 This control filters out short noncompliant
                                                                                                                                             LFPS glitches sent by a non-compliant host
                                                                                                                                             For normal operation set to a targeted mask interval of 10 us value
                                                                                                                                              10 us  Tref_clk If the ref_clkdiv2 signal is used the value  10 us
                                                                                                                                              2  Tref_clk Setting this bus to 10b0 disables masking This bus
                                                                                                                                             should be accessible to general configuration registers for system
                                                                                                                                             testing and debug The value should be defined when in reset
                                                                                                                                             Changing this value during operation might disrupt normal operation
                                                                                                                                             of the link
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 6;      /* [31:26]  */
        }Bit;
    }USBPHY_MISC2;
    union { /* 0xc10c [Excel Line :0114]  */
        UINT32 Reg;
        struct {
            UINT32 PCS_TX_SWING_FULL                                                                                    : 7;      /* [  6:0] TX Amplitude Full Swing Mode
                                                                                                                                             This static value sets the launch amplitude of the transmitter To
                                                                                                                                             enable tuning at the board level for RX eye compliance connect this
                                                                                                                                             signal to a register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 9;      /* [ 15:7]  */
            UINT32 PCS_TX_DEEMPH_6DB                                                                                    : 6;      /* [21:16] TX De-Emphasis at 6 dB
                                                                                                                                             This static value sets the TX driver de-emphasis value when
                                                                                                                                             pipeN_tx_deemph10 is set to 2b10 according to the PIPE3
                                                                                                                                             specification This bus is provided for completeness and as a
                                                                                                                                             second potential launch amplitude
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 10;     /* [31:22]  */
        }Bit;
    }USBPHY_MISC3;
    union { /* 0xc110 [Excel Line :0118]  */
        UINT32 Reg;
        struct {
            UINT32 ALT_PIPE_PCLK                                                                                        : 1;      /* [    0] Alternate PIPE Clock Source
                                                                                                                                             Alternate input clock for pipe_pclk domain To select this clock set
                                                                                                                                             alt_clk_sel to 1b1
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ALT_PCS_CLK                                                                                          : 1;      /* [    1] Alternate PCS Clock Source
                                                                                                                                             Alternate input clock for pcs_clk domain To select this clock set
                                                                                                                                             alt_clk_sel to 1b1
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ALT_CLK_SEL                                                                                          : 1;      /* [    2] Alternate Clock Source Select
                                                                                                                                             Selects the alternate clock sources instead of the internal MPLL
                                                                                                                                             outputs for the PCS clocks
                                                                                                                                              1 Uses alternate clocks
                                                                                                                                              0 Uses internal MPLL clocks
                                                                                                                                             Change only during a reset
                                                                                                                                             Note In Scan mode tie this
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ALT_CLK_EN                                                                                           : 1;      /* [    3] Alternate Clock Enable
                                                                                                                                             Enables the ref_pcs_clk and ref_pipe_pclk output clocks if
                                                                                                                                             necessary powers up the MPLL
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 28;     /* [ 31:4]  */
        }Bit;
    }USBPHY_MISC4;
    union { /* 0xc114 [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 LANE0_TX_TERM_OFFSET                                                                                 : 5;      /* [  4:0] Transmitter Termination Offset
                                                                                                                                             Reserved Set to 5b00000
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 3;      /* [  7:5]  */
            UINT32 LANE0_TX2RX_LOOPBK                                                                                   : 1;      /* [    8] Loopback
                                                                                                                                             When this signal is asserted data from the transmit predriver is
                                                                                                                                             looped back to the receive slicers LOS is bypassed and based on
                                                                                                                                             the tx0_en input so that rx0_los  tx0_data_en
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 LANE0_EXT_PCLK_REQ                                                                                   : 1;      /* [    9] External PIPE Clock Enable Request
                                                                                                                                             When asserted this signal enables the pipeN_pclk output regardless
                                                                                                                                             of power state along with the associated increase in power
                                                                                                                                             consumption
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 22;     /* [31:10]  */
        }Bit;
    }USBPHY_MISC5;

    UINT8 EMPTY11[4]; /* 0x4 */

    union { /* 0xc11c [Excel Line :0128]  */
        UINT32 Reg;
        struct {
            UINT32 TEST_BURNIN                                                                                          : 1;      /* [    0] All Circuits Activator
                                                                                                                                             Reserved Tie this signal to ground gd
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TEST_POWERDOWN_HSP                                                                                   : 1;      /* [    1] HS Function Circuits Power-Down Control
                                                                                                                                             Powers down all HS function circuitry in the PHY for IDDQ testing
                                                                                                                                             Before asserting this signal ensure that VDATSRCENBN
                                                                                                                                             VDATDETENBN DCDENBN BYPASSSELN and test_burnin are
                                                                                                                                             set to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 30;     /* [ 31:2]  */
        }Bit;
    }USBPHY_MISC7;

    UINT8 EMPTY12[12]; /* 0xC */

    union { /* 0xc12c [Excel Line :0131]  */
        UINT32 Reg;
        struct {
            UINT32 CR_DATA_IN                                                                                           : 16;     /* [ 15:0] CR Address and Write Data Input Bus
                                                                                                                                             Supplies and captures address and write data
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 CR_READ                                                                                              : 1;      /* [   16] CR Read
                                                                                                                                             Reads from the referenced Address register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 CR_CAP_DATA                                                                                          : 1;      /* [   17] CR Capture Data
                                                                                                                                             Captures cr_data_in150 into the Write Data register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 CR_CAP_ADDR                                                                                          : 1;      /* [   18] CR Capture Address
                                                                                                                                             Captures cr_data_in150 into the Address register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 CR_WRITE                                                                                             : 1;      /* [   19] CR Write
                                                                                                                                             Writes the Write Data register to the referenced Address register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 12;     /* [31:20]  */
        }Bit;
    }USBPHY_MISC11;
    union { /* 0xc130 [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 LOS_LEVEL                                                                                            : 5;      /* [  4:0] Loss-of-Signal Detector Sensitivity Level Control
                                                                                                                                             Reserved Set this bus to 0x09
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 3;      /* [  7:5]  */
            UINT32 LOS_BIAS                                                                                             : 3;      /* [ 10:8] Loss-of-Signal Detector Threshold Level Control
                                                                                                                                             Sets the LOS detection threshold level To enable tuning at the board
                                                                                                                                             level connect this bus to a register
                                                                                                                                              111 135 mV
                                                                                                                                              110 120 mV
                                                                                                                                              101 105 mV
                                                                                                                                              100 90 mV
                                                                                                                                              011 75 mV
                                                                                                                                              010 60 mV
                                                                                                                                              001 45 mV
                                                                                                                                              000 Invalid
                                                                                                                                              Default 3b010
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 21;     /* [31:11]  */
        }Bit;
    }USBPHY_MISC12;
    union { /* 0xc134 [Excel Line :0141]  */
        UINT32 Reg;
        struct {
            UINT32 SSC_RANGE                                                                                            : 3;      /* [  2:0] Spread Spectrum Clock Range
                                                                                                                                             Selects the range of spread spectrum modulation when ssc_en is
                                                                                                                                             asserted and the PHY is spreading the high-speed transmit clocks
                                                                                                                                             Applies a fixed offset to the phase accumulator
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 5;      /* [  7:3]  */
            UINT32 SSC_REF_CLK_SEL                                                                                      : 9;      /* [ 16:8] Spread Spectrum Reference Clock Shifting
                                                                                                                                             Enables non-standard oscillator frequencies to generate targeted
                                                                                                                                             MPLL output rates Input corresponds to frequency-synthesis
                                                                                                                                             coefficient
                                                                                                                                              ssc_ref_clk_sel86  modulus - 1
                                                                                                                                              ssc_ref_clk_sel50  2s complement push amount
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 15;     /* [31:17]  */
        }Bit;
    }USBPHY_MISC13;
    union { /* 0xc138 [Excel Line :0145]  */
        UINT32 Reg;
        struct {
            UINT32 REF_USE_XO                                                                                           : 1;      /* [    0] Use External Crystal Oscillator
                                                                                                                                             Reserved Set it to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_XO_EN                                                                                            : 1;      /* [    1] Crystal Oscillator Always On Enable
                                                                                                                                             Reserved Set it to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_REPEAT_CLK_EN                                                                                    : 1;      /* [    2] Clock Repeater Buffer Enable
                                                                                                                                             Enables the clock repeater buffer
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_CLKDIV2                                                                                          : 1;      /* [    3] Input Reference Clock Divider Control
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_USE_PAD                                                                                          : 1;      /* [    4] Select Reference Clock Connected to ref_pad_clk_pm
                                                                                                                                             When asserted selects the external ref_pad_clk_pm inputs as the
                                                                                                                                             reference clock source When ref_use_pad is de-asserted
                                                                                                                                             ref_alt_clk_pm are selected for an on-chip reference clock source
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_ALT_CLK_M                                                                                        : 1;      /* [    5] Low-Swing Differential Input Clock Pair Internal Pin
                                                                                                                                             Reference clock from on-chip source
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_SSP_EN                                                                                           : 1;      /* [    6] Reference Clock Enable for SS function
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REF_ALT_CLK_P                                                                                        : 1;      /* [    7] Low-Swing Differential Input Clock Pair Internal Pin
                                                                                                                                             Reference clock from on-chip source
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }USBPHY_MISC14;
    union { /* 0xc13c [Excel Line :0154]  */
        UINT32 Reg;
        struct {
            UINT32 JTAG_TMS                                                                                             : 1;      /* [    0] JTAG State Machine Control
                                                                                                                                             JTAG test mode select signal for use in ATE testing and debug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 JTAG_TCK                                                                                             : 1;      /* [    1] JTAG Clock
                                                                                                                                             JTAG state machine clock signal for use in ATE testing and debug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 JTAG_TRST_N                                                                                          : 1;      /* [    2] PHY JTAG Reset
                                                                                                                                             Top-level asynchronous JTAG reset pin According to JTAG
                                                                                                                                             specifications a TRST reset is optional
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 JTAG_TDI                                                                                             : 1;      /* [    3] JTAG Input Port
                                                                                                                                             JTAG test data input signal for use in ATE testing and debug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 28;     /* [ 31:4]  */
        }Bit;
    }USBPHY_MISC15;
    union { /* 0xc140 [Excel Line :0159]  */
        UINT32 Reg;
        struct {
            UINT32 RTUNE_REQ                                                                                            : 1;      /* [    0] Resistor Tune Request
                                                                                                                                             Assertion triggers a resistor tune request if one is not already in
                                                                                                                                             progress
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }USBPHY_MISC16;
    union { /* 0xc144 [Excel Line :0161]  */
        UINT32 Reg;
        struct {
            UINT32 MPLL_MULTIPLIER                                                                                      : 7;      /* [  6:0] MPLL Frequency Multiplier Control
                                                                                                                                             Multiplies the reference clock to a frequency suitable for intended
                                                                                                                                             operating speed
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 1;      /* [    7]  */
            UINT32 MPLL_REFSSC_CLK_EN                                                                                   : 1;      /* [    8] Double-Word Clock Enable
                                                                                                                                             Reserved Set this control to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }USBPHY_MISC17;
    union { /* 0xc148 [Excel Line :0165]  */
        UINT32 Reg;
        struct {
            UINT32 TX_VBOOST_LVL                                                                                        : 3;      /* [  2:0] TX Voltage Boost Level
                                                                                                                                             Sets the boosted transmit launch amplitude mVppd To enable
                                                                                                                                             tuning at the board level connect this bus to a register
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 5;      /* [  7:3]  */
            UINT32 FSEL                                                                                                 : 6;      /* [ 13:8] Frequency Select
                                                                                                                                             Selects the reference clock frequency used for both SS and HS
                                                                                                                                             operations
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 2;      /* [15:14]  */
            UINT32 ACJT_LEVEL                                                                                           : 5;      /* [20:16] 11496 Receiver Sensitivity Level Control
                                                                                                                                             Selects the sensitivity level for the 11496 receiver for AC JTAG Set
                                                                                                                                             the level based on the amplitude of the incoming Step during AC
                                                                                                                                             JTAG boundary scan testing
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 11;     /* [31:21]  */
        }Bit;
    }USBPHY_MISC18;
    union { /* 0xc14c [Excel Line :0171]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                                                            : 17;     /* [ 16:0]  */
            UINT32 LOOPBACKENB0                                                                                         : 1;      /* [   17] Loopback Test Enable
                                                                                                                                             This controller signal places the USB 30 femtoPHY in HS Loopback
                                                                                                                                             mode which concurrently enables the HS receive and transmit logic
                                                                                                                                              1 During HS data transmission the HS receive logic is enabled
                                                                                                                                              0 During HS data transmission the HS receive logic is disabled
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RX0LOSLFPSEN                                                                                         : 1;      /* [   18] RX LOS LFPS Filter Enable
                                                                                                                                             Enables the RX LOS LFPS filter During USB 30 operation set to
                                                                                                                                             1b1
                                                                                                                                              1 Enables RX LOS LFPS filter
                                                                                                                                              0 Disables RX LOS LFPS filter
                                                                                                                                             Change this pin setting only during a reset
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 REFCLKSEL                                                                                            : 2;      /* [20:19] Reference Clock Select for PLL Block
                                                                                                                                             Reserved Set it to 2b10
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 FSSE0EXT0                                                                                            : 1;      /* [   21] USB 11 SE0 Generation
                                                                                                                                             This controller signal sets the USB 20 to an SE0 state This signal
                                                                                                                                             is valid only if FSXCVROWNERN is set to 1b1 and TXENABLENN is
                                                                                                                                             set to 1b0
                                                                                                                                              1 D and D- lines are driven to an SE0 state
                                                                                                                                              0 D and D- line states are determined by FSDATAEXTN If
                                                                                                                                             FSSE0EXTN is not used set it to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 FSDATAEXT0                                                                                           : 1;      /* [   22] USB 11 Transmit Data
                                                                                                                                             This controller signal sets the USB 20 to either a J or K state This
                                                                                                                                             signal is valid only if FSXCVROWNERN is set to 1b1
                                                                                                                                             TXENABLENN is set to 1b0 and FSSE0EXTN is set to 1b0
                                                                                                                                              1 D and D- lines are driven to a Differential 1
                                                                                                                                              0 D and D- lines are driven to a Differential 0 If FSDATAEXTN is
                                                                                                                                             not used set it to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 DCDENB0                                                                                              : 1;      /* [   23] Data Contact Detection Enable
                                                                                                                                             Enables current sourcing on the D line For special applications the
                                                                                                                                             IDP_SRC control and the RDM_DWN control are separated For
                                                                                                                                             standard DCD operation in accordance with the Battery Charger v12
                                                                                                                                             specification simultaneously set DCDENBN  1b1 to enable
                                                                                                                                             IDP_SRC and set DMPULLDOWNN  1b1 to enable RDM_DWN
                                                                                                                                             Set both signals to 1b0 when DCD is completed
                                                                                                                                              1 IDP_SRC current is sourced onto DPN
                                                                                                                                              0 IDP_SRC current is disabled
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 CHRGSEL0                                                                                             : 1;      /* [   24] Battery Charging Source Select
                                                                                                                                             Determines whether current is sourced onto or sunk from DPN or
                                                                                                                                             DMN
                                                                                                                                              1 Data source voltage VDAT_SRC is sourced onto DMN and
                                                                                                                                             sunk from DPN
                                                                                                                                              0 Data source voltage VDAT_SRC is sourced onto DPN and
                                                                                                                                             sunk from DMN
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BYPASSSEL0                                                                                           : 1;      /* [   25] Transmitter Digital Bypass Select
                                                                                                                                             Enablesdisables Transmitter Digital Bypass mode
                                                                                                                                              1 Transmitter Digital Bypass mode is enabled
                                                                                                                                              0 Transmitter Digital Bypass mode is disabled
                                                                                                                                             If Transmitter Digital Bypass mode is not used tie this input to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BYPASSDPEN0                                                                                          : 1;      /* [   26] DPN Transmitter Digital Bypass Enable
                                                                                                                                             Enablesdisables the DPN FSLS driver in Transmitter Digital Bypass
                                                                                                                                             mode
                                                                                                                                              1 DPN FSLS driver is enabled and driven with the
                                                                                                                                             BYPASSDPDATAN signal
                                                                                                                                              0 DPN FSLS driver is disabled in Transmitter Digital Bypass
                                                                                                                                             mode
                                                                                                                                             If Transmitter Digital Bypass mode is not used tie this input to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BYPASSDPDATA0                                                                                        : 1;      /* [   27] Data for DPN Transmitter Digital Bypass
                                                                                                                                             In Transmitter Digital Bypass mode this signal provides the data that
                                                                                                                                             is transmitted on DPN
                                                                                                                                              1 DPN FSLS driver drives to a high state
                                                                                                                                              0 DPN FSLS driver drives to a low state
                                                                                                                                             If Transmitter Digital Bypass mode is not used tie this input to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BYPASSDMEN0                                                                                          : 1;      /* [   28] DMN Transmitter Digital Bypass Enable
                                                                                                                                             Enablesdisables the DMN FSLS driver in Transmitter Digital Bypass
                                                                                                                                             mode
                                                                                                                                              1 DMN FSLS driver is enabled and driven with the
                                                                                                                                             BYPASSDPDATAN signal
                                                                                                                                              0 DMN FSLS driver is disabled in Transmitter Digital Bypass
                                                                                                                                             mode
                                                                                                                                             If Transmitter Digital Bypass mode is not used tie this input to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BYPASSDMDATA0                                                                                        : 1;      /* [   29] Data for DMN Transmitter Digital Bypass
                                                                                                                                             In Transmitter Digital Bypass mode this signal provides the data that
                                                                                                                                             is transmitted on DMN
                                                                                                                                              1 DMN FSLS driver drives to a high state
                                                                                                                                              0 DMN FSLS driver drives to a low state
                                                                                                                                             If Transmitter Digital Bypass mode is not used tie this input to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ATERESET                                                                                             : 1;      /* [   30] Reset Input from Automatic Test Equipment
                                                                                                                                             When the USB 30 femtoPHY is powered up not in Suspend or
                                                                                                                                             Sleep mode an automatic tester can use this test signal to disable
                                                                                                                                             PHYCLOCKN and FREECLK then re-enable them with an aligned
                                                                                                                                             phase
                                                                                                                                              1 PHYCLOCKN and FREECLK outputs are disabled
                                                                                                                                              0 PHYCLOCKN and FREECLK outputs are available within a
                                                                                                                                             specific period after ATERESET is de-asserted
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ACAENB0                                                                                              : 1;      /* [   31] ACA ID_OTG Pin Resistance Detection Enable
                                                                                                                                             Enables detection of resistance on the ID_OTG pin of an ACA
                                                                                                                                              1 Enables detection of resistance on ID_OTG pin of an ACA
                                                                                                                                              0 Disables detection of resistance on ID_OTG pin of an ACA
                                                                                                                                             Refer to USB PHY databook for more information about this register */
        }Bit;
    }USBPHY_MISC19;

    UINT8 EMPTY13[4]; /* 0x4 */

    union { /* 0xc154 [Excel Line :0186]  */
        UINT32 Reg;
        struct {
            UINT32 VDATSRCENB0                                                                                          : 1;      /* [    0] Battery Charging Sourcing Select
                                                                                                                                             Enables or disables sourcing for battery charging
                                                                                                                                              1 Data source voltage VDAT_SRC is enabled
                                                                                                                                              0 Data source voltage VDAT_SRC is disabled
                                                                                                                                             During USB 30 femtoPHY normal operation set this signal low
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 VDATDETENB0                                                                                          : 1;      /* [    1] Battery Charging AttachConnect Detection Enable
                                                                                                                                             Enables or disables attachconnect detection
                                                                                                                                              1 Data detect voltage CHG_DET is enabled
                                                                                                                                              0 Data detect voltage CHG_DET is disabled
                                                                                                                                             During USB 30 femtoPHY normal operation set this signal
                                                                                                                                             low
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 VATESTENB                                                                                            : 1;      /* [    2] Analog Test Pin Select
                                                                                                                                             Enables analog test voltages to be placed on the IDN pin
                                                                                                                                              1 Analog test voltages can be viewed or applied on IDN
                                                                                                                                              0 Analog test voltages cannot be viewed or applied on IDN
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TXPREEMPPULSETUNE0                                                                                   : 1;      /* [    3] HS Transmitter Pre-Emphasis Duration Control
                                                                                                                                             This signal controls the duration for which the HS pre-emphasis
                                                                                                                                             current is sourced onto DPN or DMN The HS Transmitter preemphasis
                                                                                                                                             duration is defined in terms of unit amounts One unit of
                                                                                                                                             pre-emphasis duration is approximately 580 ps and is defined as 1X
                                                                                                                                             pre-emphasis duration This signal is valid only if either
                                                                                                                                             TXPREEMPAMPTUNEN1 or TXPREEMPAMPTUNEN0 is set to
                                                                                                                                             1b1
                                                                                                                                              1 Short
                                                                                                                                              0 Long default
                                                                                                                                             If TXPREEMPPULSETUNEN is not used set it to 1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TXENABLEN0                                                                                           : 1;      /* [    4] USB 11 Data Enable
                                                                                                                                             This controller signal enables the FSDATAEXTN and FSSE0EXTN
                                                                                                                                             inputs TXENABLENN is valid only when the FSXCVROWNERN
                                                                                                                                             signal is set to 1b1
                                                                                                                                              1 FSDATAEXTN and FSSE0EXTN are disabled
                                                                                                                                              0 FSDATAEXTN and FSSE0EXTN are enabled If TXENABLENN
                                                                                                                                             is not used set it to 1b1
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }USBPHY_MISC21;
    union { /* 0xc158 [Excel Line :0192]  */
        UINT32 Reg;
        struct {
            UINT32 TXFSLSTUNE0                                                                                          : 4;      /* [  3:0] FSLS Source Impedance Adjustment Adjusts the low- and full-speed single-ended source impedance while driving high To enable tuning at the board level connect this bus to a register
                                                                                                                                              1111 - 107
                                                                                                                                              0111 - 56
                                                                                                                                              0011 0 default
                                                                                                                                              0001  65
                                                                                                                                              0000  14
                                                                                                                                             This parameter control is encoded in thermometer code Any nonthermometer code setting that is 1001 is reserved and not
                                                                                                                                             supported
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 SQRXTUNE0                                                                                            : 3;      /* [  6:4] Squelch Threshold Adjustment Adjusts the voltage level for the threshold used to detect valid highspeed data To enable tuning at the board level connect this bus to a register
                                                                                                                                              111 - 20
                                                                                                                                              110 - 15
                                                                                                                                              101 - 10
                                                                                                                                              100 - 5
                                                                                                                                              011 0 default
                                                                                                                                              010  5
                                                                                                                                              001  10
                                                                                                                                              000  15
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 17;     /* [ 23:7]  */
            UINT32 OTGTUNE0                                                                                             : 3;      /* [26:24] VBUS Valid Threshold Adjustment
                                                                                                                                             This bus adjusts the voltage level for the VBUS valid threshold
                                                                                                                                             To enable tuning at the board level connect this bus to a register
                                                                                                                                              111  12
                                                                                                                                              110  9
                                                                                                                                              101  6
                                                                                                                                              100  3
                                                                                                                                              011 0 default
                                                                                                                                              010 - 3
                                                                                                                                              001 - 6
                                                                                                                                              000 - 9
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 1;      /* [   27]  */
            UINT32 COMPDISTUNE0                                                                                         : 3;      /* [30:28] Disconnect Threshold Adjustment
                                                                                                                                             Adjusts the voltage level for the threshold used to detect a disconnect
                                                                                                                                             event at the host To enable tuning at the board level connect this
                                                                                                                                             bus to a register
                                                                                                                                              111  12
                                                                                                                                              110  10
                                                                                                                                              101  7
                                                                                                                                              100  3
                                                                                                                                              011 0 default
                                                                                                                                              010 - 4
                                                                                                                                              001 - 6
                                                                                                                                              000 - 9
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 1;      /* [   31]  */
        }Bit;
    }USBPHY_MISC22;
    union { /* 0xc15c [Excel Line :0199]  */
        UINT32 Reg;
        struct {
            UINT32 TXVREFTUNE0                                                                                          : 4;      /* [  3:0] HS DC Voltage Level Adjustment
                                                                                                                                             Adjusts the high-speed DC level voltage To enable tuning at the
                                                                                                                                             board level connect this bus to a register
                                                                                                                                              1111  24
                                                                                                                                              1110  22
                                                                                                                                              1101  20
                                                                                                                                              1100  18
                                                                                                                                              1011  16
                                                                                                                                              1010  14
                                                                                                                                              1001  12
                                                                                                                                              1000  10
                                                                                                                                              0111  8
                                                                                                                                              0110  6
                                                                                                                                              0101  4
                                                                                                                                              0100  2
                                                                                                                                              0011 0 default
                                                                                                                                              0010 - 2
                                                                                                                                              0001 - 4
                                                                                                                                              0000 - 6
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TXRISETUNE0                                                                                          : 2;      /* [  5:4] HS Transmitter RiseFall Time Adjustment
                                                                                                                                             Adjusts the risefall times of the high-speed waveform To enable
                                                                                                                                             tuning at the board level connect this bit to a register
                                                                                                                                              11 - 81
                                                                                                                                              10 - 72
                                                                                                                                              01 0 default
                                                                                                                                              00  54
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED4                                                                                            : 2;      /* [  7:6]  */
            UINT32 TXRESTUNE0                                                                                           : 2;      /* [  9:8] USB Source Impedance Adjustment
                                                                                                                                             Some applications require additional devices to be added on the
                                                                                                                                             USB such as a series switch which can add significant series
                                                                                                                                             resistance This bus adjusts the driver source impedance for both
                                                                                                                                             pull-uppull-down impedances in LSFS mode and the pull-down
                                                                                                                                             impedance in HS mode to compensate for added series resistance
                                                                                                                                             on the USB
                                                                                                                                              11 - 56 ohms
                                                                                                                                              10 - 36 ohms
                                                                                                                                              01 0 default
                                                                                                                                              00  13 ohms
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 2;      /* [11:10]  */
            UINT32 TXPREEMPAMPTUNE0                                                                                     : 2;      /* [13:12] HS Transmitter Pre-Emphasis Current Control
                                                                                                                                             This signal controls the amount of current sourced to DPN and DMN
                                                                                                                                             after a J- to-K or K-to-J transition The HS Transmitter pre-emphasis
                                                                                                                                             current is defined in terms of unit amounts One unit amount is
                                                                                                                                             approximately 600 uA and is defined as 1X pre-emphasis current
                                                                                                                                              11 3x pre-emphasis current
                                                                                                                                              10 2x pre-emphasis current
                                                                                                                                              01 1x pre-emphasis current
                                                                                                                                              00 Disabled default
                                                                                                                                             If these signals are not used set them to 2b00
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 2;      /* [15:14]  */
            UINT32 TXHSXVTUNE0                                                                                          : 2;      /* [17:16] Transmitter High-Speed Crossover Adjustment
                                                                                                                                             This bus adjusts the voltage at which the DPN and DMN signals
                                                                                                                                             cross while transmitting in HS mode
                                                                                                                                              11 0 default
                                                                                                                                              10  15 mV
                                                                                                                                              01 - 15 mV
                                                                                                                                              00 Reserved
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }USBPHY_MISC23;

    UINT8 EMPTY14[32]; /* 0x20 */

    union { /* 0xc180 [Excel Line :0208]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                                                            : 13;     /* [ 12:0]  */
            UINT32 RIDGND0                                                                                              : 1;      /* [   13] ACA ID_OTG Pin Resistance Indicator
                                                                                                                                             Indicates whether the connected ACAs ID_OTG pin is grounded
                                                                                                                                             has resistance  1 kohm
                                                                                                                                              1 Connected ACAs ID_OTG pins resistance is  1 kohm
                                                                                                                                              0 Connected ACAs ID_OTG pins resistance is  1 kohm
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RIDFLOAT0                                                                                            : 1;      /* [   14] ACA ID_OTG Pin Resistance Indicator
                                                                                                                                             Indicates whether the connected ACAs ID_OTG pin is floating has
                                                                                                                                             resistance  220 kohm
                                                                                                                                              1 Connected ACAs ID_OTG pins resistance is  220 kohm
                                                                                                                                              0 Connected ACAs ID_OTG pins resistance is  220 kohm
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RIDC0                                                                                                : 1;      /* [   15] ACA ID_OTG Pin Resistance Indicator
                                                                                                                                             Indicates whether the connected ACAs ID_OTG pin resistance
                                                                                                                                             within range of 35-39 kohm
                                                                                                                                              1 Connected ACAs ID_OTG pins resistance is within range of
                                                                                                                                             35-39 kohm
                                                                                                                                              0 Connected ACAs ID_OTG pins resistance is out of range of
                                                                                                                                             35-39 kohm
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RIDB0                                                                                                : 1;      /* [   16] ACA ID_OTG Pin Resistance Indicator
                                                                                                                                             Indicates whether the connected ACAs ID_OTG pin resistance
                                                                                                                                             within range of 65-72 kohm
                                                                                                                                              1 Connected ACAs ID_OTG pins resistance is within range of
                                                                                                                                             65-72 kohm
                                                                                                                                              0 Connected ACAs ID_OTG pins resistance is out of range of
                                                                                                                                             65-72 kohm
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RIDA0                                                                                                : 1;      /* [   17] ACA ID_OTG Pin Resistance Indicator
                                                                                                                                             Indicates whether the connected ACAs ID_OTG pin resistance
                                                                                                                                             within range of 119-132 kohm
                                                                                                                                              1 Connected ACAs ID_OTG pins resistance is within range of
                                                                                                                                             119-132 kohm
                                                                                                                                              0 Connected ACAs ID_OTG pins resistance is out of range of
                                                                                                                                             119-132 kohm
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 1;      /* [   18]  */
            UINT32 OTGSESSVLD0                                                                                          : 1;      /* [   19] OTG Device Session Valid Indicator Low Voltage
                                                                                                                                             This controller signal is output from the USB 30 femtoPHYs Session
                                                                                                                                             Valid comparator and indicates whether the voltage on VBUS is
                                                                                                                                             below the OTG Device Session Valid threshold
                                                                                                                                              1 The voltage on VBUS is above the OTG Device Session Valid
                                                                                                                                             threshold
                                                                                                                                              0 The voltage on VBUS is below the OTG Device Session Valid
                                                                                                                                             threshold
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 1;      /* [   20]  */
            UINT32 IDDIG0                                                                                               : 1;      /* [   21] Mini AB Plug Indicator
                                                                                                                                             This controller signal indicates whether the connected plug is a mini-
                                                                                                                                             A or mini-B plug
                                                                                                                                             This signal must be valid within 20 ms after the IDPULLUP0 signal is
                                                                                                                                             set to 1b1
                                                                                                                                              1 Connected plug is a mini-B plug
                                                                                                                                              0 Connected plug is a mini-A plug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 FSVPLUS0                                                                                             : 1;      /* [   22] Single-Ended D Indicator
                                                                                                                                             This controller signal indicates the state of the D line in normal
                                                                                                                                             operation
                                                                                                                                              1 Voltage on D is high
                                                                                                                                              0 Voltage on D is low
                                                                                                                                             To enable FSVPLUSN the TXVALIDN signal must be set to 1b0 If
                                                                                                                                             FSVPLUSN is not used leave it disconnected
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 FSVMINUS0                                                                                            : 1;      /* [   23] Single-Ended D- Indicator
                                                                                                                                             This controller signal indicates the state of the D- line in normal
                                                                                                                                             operation
                                                                                                                                              1 Voltage on D- is high
                                                                                                                                              0 Voltage on D- is low
                                                                                                                                             To enable FSVMINUSN the TXVALIDN signal must be set to 1b0 If
                                                                                                                                             FSVMINUSN is not used leave it disconnected
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 FSLSRCV0                                                                                             : 1;      /* [   24] Differential Data Receive Indicator
                                                                                                                                             This controller signal indicates the state of differential data on the
                                                                                                                                             USB 20 during normal operation
                                                                                                                                              1 Voltage on D is greater than the voltage on D-
                                                                                                                                              0 Voltage on D is less than the voltage on D-
                                                                                                                                             To enable FSLSRCVN the TXVALIDN signal must be set to 1b0 If
                                                                                                                                             FSLSRCVN is not used leave it disconnected
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 5;      /* [29:25]  */
            UINT32 CHGDET0                                                                                              : 1;      /* [   30] Battery Charger Detection Output
                                                                                                                                             Indicates whether the voltage level on DPN or DMN is greater than
                                                                                                                                             VDAT_REF as defined in the Battery Charger specification
                                                                                                                                              1 VDP  VDAT_REF for CHRGSELN  1b1 or VDM 
                                                                                                                                             VDAT_REF for CHRGSELN  1b0
                                                                                                                                              0 VDP  VDAT_REF for CHRGSELN  1b1 or VDM 
                                                                                                                                             VDAT_REF for CHRGSELN  1b0
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 AVALID0                                                                                              : 1;      /* [   31] A-Device Session Valid Indicator
                                                                                                                                             This controller signal is output from the USB 30 femtoPHYs Session
                                                                                                                                             Valid comparator and indicates whether the session for an A-device
                                                                                                                                             is valid
                                                                                                                                              1 Session for the A-device is valid
                                                                                                                                              0 Session for the A-device is not valid
                                                                                                                                             Refer to USB PHY databook for more information about this register */
        }Bit;
    }USBPHY_MISC24;
    union { /* 0xc184 [Excel Line :0224]  */
        UINT32 Reg;
        struct {
            UINT32 SESSEND0                                                                                             : 1;      /* [    0] B-Device Session End Indicator
                                                                                                                                             This controller signal is output from the USB 30 femtoPHYs Session
                                                                                                                                             End comparator and indicates whether the voltage on VBUS is below
                                                                                                                                             the Session End threshold
                                                                                                                                              1 Voltage on VBUS is below the Session End threshold
                                                                                                                                              0 Voltage on VBUS is above the Session End threshold
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 TXREADY0                                                                                             : 1;      /* [    1] UTMI Transmit Ready Indicator
                                                                                                                                             This controller signal indicates that the USB 30 femtoPHY is ready
                                                                                                                                             to accept data on the DATAINN and DATAINHN buses
                                                                                                                                              If TXVALIDN and TXREADYN are set to 1b1 the data on
                                                                                                                                             DATAINN and DATAINHN is sampled at the rising edge of
                                                                                                                                             PHYCLOCKN The controllers Serial Interface Engine SIE
                                                                                                                                             immediately presents data for the next transfer on DATAINN and
                                                                                                                                             DATAINHN
                                                                                                                                              If TXVALIDN and TXREADYN are set to 1b0 the controller must
                                                                                                                                             hold the previously asserted data on DATAINN and DATAINHN
                                                                                                                                             When TXVALIDN is set to 1b0 the UTMI controller no longer
                                                                                                                                             requires TXREADYN as an input
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RXVALIDH0                                                                                            : 1;      /* [    2] UTMI Receive Data Valid Indicator High Byte
                                                                                                                                             This USB 20 controller signal indicates that the DATAOUTHN70
                                                                                                                                             bus holds valid data
                                                                                                                                             The data is valid when RXACTIVEN RXVALIDN and RXVALIDHN
                                                                                                                                             are set to 1b1
                                                                                                                                             This signal is valid only in 16- bit Data mode WORDINTERFACEN 
                                                                                                                                             1b1
                                                                                                                                             If this signal is not used leave this pin floating or ignore any
                                                                                                                                             signaling on it
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RXVALID0                                                                                             : 1;      /* [    3] UTMI Receive Data Valid Indicator Low Byte
                                                                                                                                             This USB 20 controller signal indicates that the DATAOUTN70 bus
                                                                                                                                             holds valid data
                                                                                                                                             The data is valid when both RXACTIVEN and RXVALIDN are set to
                                                                                                                                             1b1
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RXACTIVE0                                                                                            : 1;      /* [    4] UTMI Receive Active
                                                                                                                                             This USB 20 controller signal indicates a SYNC pattern is detected
                                                                                                                                             for a received packet
                                                                                                                                             The USB 30 femtoPHY de-asserts RXACTIVEN as follows
                                                                                                                                              HS When the USB returns to the Idle state
                                                                                                                                              FS When the USB 30 femtoPHY detects an EOP
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RXERROR0                                                                                             : 1;      /* [    5] UTMI Receive Error Indicator
                                                                                                                                             This USB 20 controller signal indicates an error is detected in the
                                                                                                                                             current received packet
                                                                                                                                              1 A receive error was detected
                                                                                                                                              0 No error was detected
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 LINESTATE0                                                                                           : 2;      /* [  7:6] Line State Indicator
                                                                                                                                             This controller bus reflects the state of the single-ended receivers In
                                                                                                                                             Suspend or Sleep mode this bus is a combinatorial output directly
                                                                                                                                             reflecting the current state of D- and D respectively
                                                                                                                                              11 SE1 D high D- high
                                                                                                                                              10 K state for high-speed and full-speed USB 20 traffic J state
                                                                                                                                             for low-speed USB 20 traffic D low D- high
                                                                                                                                              01 J state for high-speed and full-speed USB20 traffic K state
                                                                                                                                             for low-speed USB 20 traffic D high D- low
                                                                                                                                              00 SE0 D low D- low
                                                                                                                                             During normal high-speed packet transfers the line indicates a highspeed
                                                                                                                                             J state
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 HOSTDISCONNECT0                                                                                      : 1;      /* [    8] Peripheral Disconnect Indicator
                                                                                                                                             This controller signal indicates to the host controller that a peripheral
                                                                                                                                             has been disconnected from or connected to the USB cable
                                                                                                                                              1 No peripheral is connected
                                                                                                                                              0 Peripheral is connected
                                                                                                                                             In high-speed host operation HOSTDISCONNECTN is updated only
                                                                                                                                             at the end of SOF packet transmission In FS and LS host
                                                                                                                                             operations HOSTDISCONNECTN is updated according to UTMI
                                                                                                                                             specification
                                                                                                                                             This output is valid only when the USB 30 femtoPHYs
                                                                                                                                             DPPULLDOWNN and DMPULLDOWNN signals are both set to 1b1
                                                                                                                                             Otherwise ignore this signal
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 VBUSVALID0                                                                                           : 1;      /* [    9] VBUS Valid Indicator
                                                                                                                                             This controller signal is output from the USB 30 femtoPHYs VBUS
                                                                                                                                             Valid comparator and indicates whether the VBUS0 output is at a
                                                                                                                                             valid level
                                                                                                                                              1 VBUS output is valid
                                                                                                                                              0 VBUS output is not valid
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 BVALID0                                                                                              : 1;      /* [   10] B-Device Session Valid Indicator
                                                                                                                                             This controller signal is output from the USB 30 femtoPHYs Session
                                                                                                                                             Valid comparator and indicates whether the session for a B-device is
                                                                                                                                             valid
                                                                                                                                              1 Session for the B-device is valid
                                                                                                                                              0 Session for the B-device is not valid
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 PIPE0_PHYSTATUS                                                                                      : 1;      /* [   11] PIPE PHY Status
                                                                                                                                             Communicates completion of several PHY functions including power
                                                                                                                                             management state transitions rate change and receiver detection
                                                                                                                                             When this signal transitions during entry and exit from P3 states and
                                                                                                                                             PCLK is not running the signaling is asynchronous In error
                                                                                                                                             situations where the PHY fails to assert PhyStatus the MAC can
                                                                                                                                             take MAC-specific error recovery actions
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 PIPE0_RX_ELECIDLE                                                                                    : 1;      /* [   12] PIPE Receiver Electrical Idle
                                                                                                                                             Indicates receiver detection of an electrical idle Signal de-assertion
                                                                                                                                             while the PHY is in a P0 P1 P2 or P3 state indicates the detection
                                                                                                                                             of Low Frequency Periodic Signaling LFPS
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 PIPE0_RX_STATUS                                                                                      : 3;      /* [15:13] PIPE Receiver Status
                                                                                                                                             Encodes receiver status and error codes for the received datastream
                                                                                                                                             when receiving data
                                                                                                                                              111 Receive disparity error reserved if Receive Disparity error is
                                                                                                                                             reported with code 0b100
                                                                                                                                              110 Elastic Buffer underflow This error code is not used if the
                                                                                                                                             Elasticity Buffer is operating in the nominal Buffer Empty mode
                                                                                                                                              101 Elastic Buffer overflow
                                                                                                                                              100 Both 8B10B decode error and optionally Receive Disparity
                                                                                                                                             error - 011 Receiver detected
                                                                                                                                              010 1 SKP Ordered Set removed - 001 1 SKP Ordered Set
                                                                                                                                             added
                                                                                                                                              000 Received data valid
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }USBPHY_MISC25;

    UINT8 EMPTY15[4]; /* 0x4 */

    union { /* 0xc18c [Excel Line :0238]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED2                                                                                            : 4;      /* [  3:0]  */
            UINT32 REF_CLKREQ_N                                                                                         : 1;      /* [    4] Reference Clock Removal Acknowledge
                                                                                                                                             Reserved
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }USBPHY_MISC27;
    union { /* 0xc190 [Excel Line :0241]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED4                                                                                            : 1;      /* [    0]  */
            UINT32 CR_ACK                                                                                               : 1;      /* [    1] CR Acknowledgment
                                                                                                                                             Acknowledgment for the cr_cap_addr cr_cap_data cr_write and
                                                                                                                                             cr_read control signals
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED3                                                                                            : 5;      /* [  6:2]  */
            UINT32 JTAG_TDO_EN                                                                                          : 1;      /* [    7] JTAG Output Enable
                                                                                                                                             JTAG test data output enable signal for use in ATE testing and debug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RTUNE_ACK                                                                                            : 1;      /* [    8] Resistor Tune Acknowledge
                                                                                                                                             While asserted indicates that a resistor tune is still in progress
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED2                                                                                            : 1;      /* [    9]  */
            UINT32 JTAG_TDO                                                                                             : 1;      /* [   10] JTAG Output Port
                                                                                                                                             JTAG test data output signal for use in ATE testing and debug
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 ALT_CLK_REQ                                                                                          : 1;      /* [   11] Alternate Clock Source Request
                                                                                                                                             Indicates that the alternate clocks are needed by the slave PCS that
                                                                                                                                             is to boot the master MPLL Connect to alt_clk_en on the master
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 20;     /* [31:12]  */
        }Bit;
    }USBPHY_MISC28;

    UINT8 EMPTY16[4]; /* 0x4 */

    union { /* 0xc198 [Excel Line :0250]  */
        UINT32 Reg;
        struct {
            UINT32 CR_DATA_OUT                                                                                          : 16;     /* [ 15:0] CR Data Output Bus
                                                                                                                                             Always presents last read data
                                                                                                                                             Refer to USB PHY databook for more information about this register */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }USBPHY_MISC30;

    UINT8 EMPTY17[100]; /* 0x64 */

    union { /* 0xc200 [Excel Line :0252]  */
        UINT32 Reg;
        struct {
            UINT32 OVERCUR_REG_EN                                                                                       : 1;      /* [    0] hub_port_overcurrent control
                                                                                                                                              1 Register control enable
                                                                                                                                              0 PAD enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }USBCON_OVER_CTL;
}DRV_A6_USB_SCU_REGISTER;
/* PRQA S 828 -- */

#endif /* end of  __DRV_REGISTER_A6_USB_SCU__ */

