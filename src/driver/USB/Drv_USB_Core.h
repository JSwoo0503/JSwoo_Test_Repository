#ifndef R5_USB_CORE_H_
#define R5_USB_CORE_H_

#include "Drv_USB_SPEC.h"

/* ========================================================================

======================================================================== */
#define APACHE_A6_USB_BASE_ADDR        	0x0B000000

/* ========================================================================
Global constants
======================================================================== */
#define DWC3_EP0_BOUNCE_SIZE	        512
#define DWC3_XHCI_RESOURCES_NUM	        2

#define DWC3_SCRATCHBUF_SIZE	        4096	
#define DWC3_EVENT_SIZE		            (4U)
#define DWC3_EVENT_MAX_NUM	            (64U)
#define DWC3_EVENT_BUFF_SIZE	        (DWC3_EVENT_SIZE * DWC3_EVENT_MAX_NUM)
#define DWC3_EVENT_TYPE_MASK	        0xfe

#define DWC3_EVENT_TYPE_DEV	            0
#define DWC3_EVENT_TYPE_CARKIT	        3
#define DWC3_EVENT_TYPE_I2C	            4

#define DWC3_DEVICE_EVENT_DISCONNECT	0
#define DWC3_DEVICE_EVENT_RESET			1
#define DWC3_DEVICE_EVENT_CONNECT_DONE	2
#define DWC3_DEVICE_EVENT_LINK_STATUS_CHANGE	3
#define DWC3_DEVICE_EVENT_WAKEUP		4
#define DWC3_DEVICE_EVENT_HIBER_REQ		5
#define DWC3_DEVICE_EVENT_EOPF			6
#define DWC3_DEVICE_EVENT_SOF			7
#define DWC3_DEVICE_EVENT_ERRATIC_ERROR	9
#define DWC3_DEVICE_EVENT_CMD_CMPL		10
#define DWC3_DEVICE_EVENT_OVERFLOW		11

#define DWC3_GEVNTCOUNT_MASK	        0xfffc
#define DWC3_GSNPSID_MASK	            0xffff0000UL
#define DWC3_GSNPSREV_MASK	            0xffff

/* ========================================================================
DWC3 registers memory space boundries
======================================================================== */
#define DWC3_XHCI_REGS_START		    0x0
#define DWC3_XHCI_REGS_END		        0x7fff
#define DWC3_GLOBALS_REGS_START		    0xc100
#define DWC3_GLOBALS_REGS_END		    0xc6ff
#define DWC3_DEVICE_REGS_START		    0xc700
#define DWC3_DEVICE_REGS_END		    0xcbff
#define DWC3_OTG_REGS_START		        0xcc00
#define DWC3_OTG_REGS_END		        0xccff

/* ========================================================================
Global Registers
======================================================================== */
#define DWC3_GSBUSCFG0		    0xc100
#define DWC3_GSBUSCFG1		    0xc104
#define DWC3_GTXTHRCFG		    0xc108
#define DWC3_GRXTHRCFG		    0xc10c
#define DWC3_GCTL		        0xc110
#define DWC3_GEVTEN		        0xc114
#define DWC3_GSTS		        0xc118
#define DWC3_GUCTL1		        0xc11c
#define DWC3_GSNPSID		    0xc120
#define DWC3_GGPIO		        0xc124
#define DWC3_GUID		        0xc128
#define DWC3_GUCTL		        0xc12c
#define DWC3_GBUSERRADDR0	    0xc130
#define DWC3_GBUSERRADDR1	    0xc134
#define DWC3_GPRTBIMAP0		    0xc138
#define DWC3_GPRTBIMAP1		    0xc13c
#define DWC3_GHWPARAMS0		    0xc140
#define DWC3_GHWPARAMS1		    0xc144
#define DWC3_GHWPARAMS2		    0xc148
#define DWC3_GHWPARAMS3		    0xc14c
#define DWC3_GHWPARAMS4		    0xc150
#define DWC3_GHWPARAMS5		    0xc154
#define DWC3_GHWPARAMS6		    0xc158
#define DWC3_GHWPARAMS7		    0xc15c
#define DWC3_GDBGFIFOSPACE	    0xc160
#define DWC3_GDBGLTSSM		    0xc164
#define DWC3_GPRTBIMAP_HS0	    0xc180
#define DWC3_GPRTBIMAP_HS1	    0xc184
#define DWC3_GPRTBIMAP_FS0	    0xc188
#define DWC3_GPRTBIMAP_FS1	    0xc18c
#define DWC3_GUSB2PHYCFG(n)	    (0xc200 + ((n) * 0x04))
#define DWC3_GUSB2I2CCTL(n)	    (0xc240 + ((n) * 0x04))
#define DWC3_GUSB2PHYACC(n)	    (0xc280 + ((n) * 0x04))
#define DWC3_GUSB3PIPECTL(n)	(0xc2c0 + ((n) * 0x04))
#define DWC3_GTXFIFOSIZ(n)	    (0xc300 + ((n) * 0x04))
#define DWC3_GRXFIFOSIZ(n)	    (0xc380 + ((n) * 0x04))
#define DWC3_GEVNTADRLO(n)	    (0xc400 + ((n) * 0x10))
#define DWC3_GEVNTADRHI(n)	    (0xc404 + ((n) * 0x10))
#define DWC3_GEVNTSIZ(n)	    (0xc408U + ((n) * 0x10U))
#define DWC3_GEVNTCOUNT(n)	    (0xc40c + ((n) * 0x10))
#define DWC3_GHWPARAMS8		    0xc600

/* ========================================================================
Device Registers
======================================================================== */
#define DWC3_DCFG		        (0xc700U)					/* Device Configuration Register */
#define DWC3_DCTL		        (0xc704U)					/* Device Control Register */
#define DWC3_DEVTEN		        (0xc708U)					/* Device Event Enable Register */
#define DWC3_DSTS		        (0xc70cU)					/* Device Status Register */
#define DWC3_DGCMDPAR		    (0xc710U)					/* Device Generic Command Parameter Register, This register indicates the device command parameter. This must be programmed before or along with the device command. The available device commands are listed in DGCMD register. */
#define DWC3_DGCMD		        (0xc714U)					/* Device Generic Command Register */
#define DWC3_DALEPENA		    (0xc720U)					/* Device Active USB Endpoint Enable Register, This register indicates whether a USB endpoint is active in a given configuration or interface. */

#define DWC3_DEPCMDPAR2(n)	    (0xc800U + ((n) * 0x10U))		/* Device Physical Endpoint Command Parameter 2 Register, It must be programmed before issuing the command. */
#define DWC3_DEPCMDPAR1(n)	    (0xc804U + ((n) * 0x10U))		/* Device Physical Endpoint Command Parameter 1 Register, It must be programmed before issuing the command. */
#define DWC3_DEPCMDPAR0(n)	    (0xc808U + ((n) * 0x10U))		/* Device Physical Endpoint Command Parameter 0 Register, It must be programmed before issuing the command. */
#define DWC3_DEPCMD(n)		    (0xc80cU + ((n) * 0x10U))		/* Device Physical Endpoint Command Register */

/* ========================================================================
Global Configuration Register
======================================================================== */
#define DWC3_GCTL_PWRDNSCALE(n)	((n) << 19)
#define DWC3_GCTL_U2RSTECN	    (1 << 16)
#define DWC3_GCTL_CLK_BUS	    (0)
#define DWC3_GCTL_CLK_PIPE	    (1)
#define DWC3_GCTL_CLK_PIPEHALF	(2)
#define DWC3_GCTL_CLK_MASK	    (3) 
#define DWC3_GCTL_RAMCLKSEL(x)	(((x) & DWC3_GCTL_CLK_MASK) << 6)

#define DWC3_GCTL_PRTCAP(n)	    (((n) & (3 << 12)) >> 12)
#define DWC3_GCTL_PRTCAPDIR(n)	((n) << 12)
#define DWC3_GCTL_PRTCAP_HOST	1
#define DWC3_GCTL_PRTCAP_DEVICE	2
#define DWC3_GCTL_PRTCAP_OTG	3

#define DWC3_GCTL_CORESOFTRESET		(1 << 11)
#define DWC3_GCTL_SOFITPSYNC		(1 << 10)
#define DWC3_GCTL_SCALEDOWN(n)		((n) << 4)
#define DWC3_GCTL_SCALEDOWN_MASK	DWC3_GCTL_SCALEDOWN(3)
#define DWC3_GCTL_DISSCRAMBLE		(1 << 3)
#define DWC3_GCTL_U2EXIT_LFPS		(1 << 2)
#define DWC3_GCTL_GBLHIBERNATIONEN	(1 << 1)
#define DWC3_GCTL_DSBLCLKGTNG		(1 << 0)

/* ========================================================================
Global USB2 PHY Configuration Register
======================================================================== */
#define DWC3_GUSB2PHYCFG_PHYSOFTRST	        (1 << 31)
#define DWC3_GUSB2PHYCFG_U2_FREECLK_EXISTS	(1 << 30)
#define DWC3_GUSB2PHYCFG_ENBLSLPM           (1 << 8)
#define DWC3_GUSB2PHYCFG_SUSPHY		        (1 << 6)
#define DWC3_GUSB2PHYCFG_PHYIF_8BIT	        (0 << 3)
#define DWC3_GUSB2PHYCFG_PHYIF_16BIT	    (1 << 3)
#define DWC3_GUSB2PHYCFG_PHYIF_MASK         DWC3_GUSB2PHYCFG_PHYIF_16BIT
#define DWC3_GUSB2PHYCFG_USBTRDTIM_SHIFT	(10)
#define DWC3_GUSB2PHYCFG_USBTRDTIM_MASK	    (0xf << DWC3_GUSB2PHYCFG_USBTRDTIM_SHIFT)
#define DWC3_GUSB2PHYCFG_USBTRDTIM_16BIT    (0x5 << DWC3_GUSB2PHYCFG_USBTRDTIM_SHIFT)
#define DWC3_GUSB2PHYCFG_USBTRDTIM_8BIT     (0x9 << DWC3_GUSB2PHYCFG_USBTRDTIM_SHIFT)

/* ========================================================================
Global USB3 PIPE Control Register
======================================================================== */
#define DWC3_GUSB3PIPECTL_PHYSOFTRST	    (1 << 31)
#define DWC3_GUSB3PIPECTL_U2SSINP3OK	    (1 << 29)
#define DWC3_GUSB3PIPECTL_REQP1P2P3	        (1 << 24)
#define DWC3_GUSB3PIPECTL_DEP1P2P3(n)	    ((n) << 19)
#define DWC3_GUSB3PIPECTL_DEP1P2P3_MASK	    DWC3_GUSB3PIPECTL_DEP1P2P3(7)
#define DWC3_GUSB3PIPECTL_DEP1P2P3_EN	    DWC3_GUSB3PIPECTL_DEP1P2P3(1)
#define DWC3_GUSB3PIPECTL_DEPOCHANGE	    (1 << 18)
#define DWC3_GUSB3PIPECTL_SUSPHY	        (1 << 17)
#define DWC3_GUSB3PIPECTL_LFPSFILT	        (1 << 9)
#define DWC3_GUSB3PIPECTL_RX_DETOPOLL	    (1 << 8)
#define DWC3_GUSB3PIPECTL_TX_DEEPH(n)	    ((n) << 1)
#define DWC3_GUSB3PIPECTL_TX_DEEPH_MASK	    DWC3_GUSB3PIPECTL_TX_DEEPH(3)

/* ========================================================================
Global TX Fifo Size Register
======================================================================== */
#define DWC3_GTXFIFOSIZ_TXFDEF(n)	        ((n) & 0xffff)
#define DWC3_GTXFIFOSIZ_TXFSTADDR(n)	    ((n) & 0xffff0000)

/* ========================================================================
Global Event Size Registers
======================================================================== */
#define DWC3_GEVNTSIZ_INTMASK		        (1 << 31)
#define DWC3_GEVNTSIZ_SIZE(n)		        ((n) & 0xffffU)

/* ========================================================================
Global HWPARAMS1 Register
======================================================================== */
#define DWC3_GHWPARAMS1_EN_PWROPT(n)	    (((n) & (3 << 24)) >> 24)
#define DWC3_GHWPARAMS1_EN_PWROPT_NO	    0
#define DWC3_GHWPARAMS1_EN_PWROPT_CLK	    1
#define DWC3_GHWPARAMS1_EN_PWROPT_HIB	    2
#define DWC3_GHWPARAMS1_PWROPT(n)	        ((n) << 24)
#define DWC3_GHWPARAMS1_PWROPT_MASK	        DWC3_GHWPARAMS1_PWROPT(3)

/* ========================================================================
Global HWPARAMS3 Register
======================================================================== */
#define DWC3_GHWPARAMS3_SSPHY_IFC(n)		((n) & 3)
#define DWC3_GHWPARAMS3_SSPHY_IFC_DIS		0
#define DWC3_GHWPARAMS3_SSPHY_IFC_ENA		1
#define DWC3_GHWPARAMS3_HSPHY_IFC(n)		(((n) & (3 << 2)) >> 2)
#define DWC3_GHWPARAMS3_HSPHY_IFC_DIS		0
#define DWC3_GHWPARAMS3_HSPHY_IFC_UTMI		1
#define DWC3_GHWPARAMS3_HSPHY_IFC_ULPI		2
#define DWC3_GHWPARAMS3_HSPHY_IFC_UTMI_ULPI	3
#define DWC3_GHWPARAMS3_FSPHY_IFC(n)		(((n) & (3 << 4)) >> 4)
#define DWC3_GHWPARAMS3_FSPHY_IFC_DIS		0
#define DWC3_GHWPARAMS3_FSPHY_IFC_ENA		1

/* ========================================================================
Global HWPARAMS4 Register
======================================================================== */
#define DWC3_GHWPARAMS4_HIBER_SCRATCHBUFS(n)	(((n) & (0x0f << 13)) >> 13)
#define DWC3_MAX_HIBER_SCRATCHBUFS		    15

/* ========================================================================
Global HWPARAMS6 Register
======================================================================== */
#define DWC3_GHWPARAMS6_EN_FPGA			    (1 << 7)

/* ========================================================================
Device Configuration Register
======================================================================== */
#define DWC3_DCFG_DEVADDR(addr)	            ((addr) << 3)
#define DWC3_DCFG_DEVADDR_MASK	            DWC3_DCFG_DEVADDR(0x7f)

#define DWC3_DCFG_SPEED_MASK	            (7 << 0)
#define DWC3_DCFG_SUPERSPEED	            (4 << 0)
#define DWC3_DCFG_HIGHSPEED	                (0 << 0)
#define DWC3_DCFG_FULLSPEED2	            (1 << 0)
#define DWC3_DCFG_LOWSPEED	                (2 << 0)
#define DWC3_DCFG_FULLSPEED1	            (3 << 0)
#define DWC3_DCFG_LPM_CAP	                (1 << 22)

/* ========================================================================
Device Control Register
======================================================================== */
#define DWC3_DCTL_RUN_STOP	                (1 << 31)
#define DWC3_DCTL_CSFTRST	                (1 << 30)
#define DWC3_DCTL_LSFTRST	                (1 << 29)

#define DWC3_DCTL_HIRD_THRES_MASK	        (0x1f << 24)
#define DWC3_DCTL_HIRD_THRES(n)	            ((n) << 24)

#define DWC3_DCTL_APPL1RES	                (1 << 23)

/* ========================================================================
These apply for core versions 1.87a and earlier
======================================================================== */
#define DWC3_DCTL_TRGTULST_MASK		        (0x0f << 17)
#define DWC3_DCTL_TRGTULST(n)		        ((n) << 17)
#define DWC3_DCTL_TRGTULST_U2		        (DWC3_DCTL_TRGTULST(2))
#define DWC3_DCTL_TRGTULST_U3		        (DWC3_DCTL_TRGTULST(3))
#define DWC3_DCTL_TRGTULST_SS_DIS	        (DWC3_DCTL_TRGTULST(4))
#define DWC3_DCTL_TRGTULST_RX_DET	        (DWC3_DCTL_TRGTULST(5))
#define DWC3_DCTL_TRGTULST_SS_INACT	        (DWC3_DCTL_TRGTULST(6))

/* ========================================================================
These apply for core versions 1.94a and later
======================================================================== */
#define DWC3_DCTL_LPM_ERRATA(n)		        ((n) << 20)
#define DWC3_DCTL_LPM_ERRATA_MASK	        DWC3_DCTL_LPM_ERRATA(0xf)


#define DWC3_DCTL_KEEP_CONNECT		        (1 << 19)
#define DWC3_DCTL_L1_HIBER_EN		        (1 << 18)
#define DWC3_DCTL_CRS			            (1 << 17)
#define DWC3_DCTL_CSS			            (1 << 16)

#define DWC3_DCTL_INITU2ENA		            (1 << 12)
#define DWC3_DCTL_ACCEPTU2ENA		        (1 << 11)
#define DWC3_DCTL_INITU1ENA		            (1 << 10)
#define DWC3_DCTL_ACCEPTU1ENA		        (1 << 9)
#define DWC3_DCTL_TSTCTRL_MASK		        (0xf << 1)

#define DWC3_DCTL_ULSTCHNGREQ_MASK	        (0x0f << 5)
#define DWC3_DCTL_ULSTCHNGREQ(n)            (((n) << 5) & DWC3_DCTL_ULSTCHNGREQ_MASK)

#define DWC3_DCTL_ULSTCHNG_NO_ACTION	    (DWC3_DCTL_ULSTCHNGREQ(0))
#define DWC3_DCTL_ULSTCHNG_SS_DISABLED	    (DWC3_DCTL_ULSTCHNGREQ(4))
#define DWC3_DCTL_ULSTCHNG_RX_DETECT	    (DWC3_DCTL_ULSTCHNGREQ(5))
#define DWC3_DCTL_ULSTCHNG_SS_INACTIVE	    (DWC3_DCTL_ULSTCHNGREQ(6))
#define DWC3_DCTL_ULSTCHNG_RECOVERY	        (DWC3_DCTL_ULSTCHNGREQ(8))
#define DWC3_DCTL_ULSTCHNG_COMPLIANCE	    (DWC3_DCTL_ULSTCHNGREQ(10))
#define DWC3_DCTL_ULSTCHNG_LOOPBACK	        (DWC3_DCTL_ULSTCHNGREQ(11))

/* ========================================================================
Device Event Enable Register
======================================================================== */
#define DWC3_DEVTEN_VNDRDEVTSTRCVEDEN	    (1 << 12)
#define DWC3_DEVTEN_EVNTOVERFLOWEN	        (1 << 11)
#define DWC3_DEVTEN_CMDCMPLTEN		        (1 << 10)
#define DWC3_DEVTEN_ERRTICERREN		        (1 << 9)
#define DWC3_DEVTEN_SOFEN		            (1 << 7)
#define DWC3_DEVTEN_EOPFEN		            (1 << 6)
#define DWC3_DEVTEN_HIBERNATIONREQEVTEN	    (1 << 5)
#define DWC3_DEVTEN_WKUPEVTEN		        (1 << 4)
#define DWC3_DEVTEN_ULSTCNGEN		        (1 << 3)
#define DWC3_DEVTEN_CONNECTDONEEN	        (1 << 2)
#define DWC3_DEVTEN_USBRSTEN		        (1 << 1)
#define DWC3_DEVTEN_DISCONNEVTEN	        (1 << 0)

/* ========================================================================
Device Status Register
======================================================================== */
#define DWC3_DSTS_DCNRD			            (1 << 29)

/* ========================================================================
This applies for core versions 1.87a and earlier
======================================================================== */
#define DWC3_DSTS_PWRUPREQ		            (1 << 24)

/* ========================================================================
These apply for core versions 1.94a and later
======================================================================== */
#define DWC3_DSTS_RSS			            (1 << 25)
#define DWC3_DSTS_SSS			            (1 << 24)
#define DWC3_DSTS_COREIDLE		            (1 << 23)
#define DWC3_DSTS_DEVCTRLHLT		        (1 << 22)
#define DWC3_DSTS_USBLNKST_MASK		        (0x0f << 18)
#define DWC3_DSTS_USBLNKST(n)		        (((n) & DWC3_DSTS_USBLNKST_MASK) >> 18)
#define DWC3_DSTS_RXFIFOEMPTY		        (1 << 17)
#define DWC3_DSTS_SOFFN_MASK		        (0x3fff << 3)
#define DWC3_DSTS_SOFFN(n)		            (((n) & DWC3_DSTS_SOFFN_MASK) >> 3)
#define DWC3_DSTS_CONNECTSPD		        (7 << 0)
#define DWC3_DSTS_SUPERSPEED		        (4 << 0)
#define DWC3_DSTS_HIGHSPEED		            (0)
#define DWC3_DSTS_FULLSPEED			        (1 << 0)
#define DWC3_DSTS_LOWSPEED		            (2 << 0)
#define DWC3_DSTS_FULLSPEED1		        (3 << 0)

/* ========================================================================
Device Generic Command Register
======================================================================== */
#define DWC3_DGCMD_SET_LMP		            0x01
#define DWC3_DGCMD_SET_PERIODIC_PAR	        0x02
#define DWC3_DGCMD_XMIT_FUNCTION	        0x03

/* ========================================================================
These apply for core versions 1.94a and later
======================================================================== */
#define DWC3_DGCMD_SET_SCRATPAD_ADDR_LO	0x04        /* origin name DWC3_DGCMD_SET_SCRATCHPAD_ADDR_LO */
#define DWC3_DGCMD_SET_SCRATPAD_ADDR_HI	0x05        /* origin name DWC3_DGCMD_SET_SCRATCHPAD_ADDR_HI */
#define DWC3_DGCMD_SELECTED_FIFO_FLUSH	    0x09
#define DWC3_DGCMD_ALL_FIFO_FLUSH	        0x0a
#define DWC3_DGCMD_SET_ENDPOINT_NRDY	    0x0c
#define DWC3_DGCMD_RUN_SOC_BUS_LOOPBACK	    0x10
#define DWC3_DGCMD_STATUS(n)		        (((n) >> 15) & 1)
#define DWC3_DGCMD_CMDIOC		            (1 << 8)				/* Command Interrupt on Complete */
																	/* When this bit is set, the device controller issues a generic Endpoint Command Complete event after executing the command. */
																	/* Note that this interrupt is mapped to DEPCFG.IntrNum. */
																	/* When the DEPCFG command is executed, the command interrupt on completion goes to the interrupt pointed by the DEPCFG.IntrNum in the current command. */
#define DWC3_DGCMD_CMDACT		            (1 << 10)				/* Command Active, Software sets this bit to 1 to enable the device endpoint controller to execute the generic command. */
																	/* The device controller sets this bit to 0 when the CmdStatus field is valid and the endpoint is ready to accept another command.  */
																	/* This does not imply that all the effects of the previously-issued command have taken place. */

/* ========================================================================
Device Generic Command Parameter Register
======================================================================== */
#define DWC3_DGCMDPAR_FORCE_LINKPM_ACCEPT	(1 << 0)
#define DWC3_DGCMDPAR_FIFO_NUM(n)		    ((n) << 0)
#define DWC3_DGCMDPAR_RX_FIFO			    (0 << 5)
#define DWC3_DGCMDPAR_TX_FIFO			    (1 << 5)
#define DWC3_DGCMDPAR_LOOPBACK_DIS		    (0 << 0)
#define DWC3_DGCMDPAR_LOOPBACK_ENA		    (1 << 0)

/* ========================================================================
Device Endpoint Command Register
======================================================================== */
#define DWC3_DEPCMD_PARAM_SHIFT		        16U
#define DWC3_DEPCMD_PARAM(x)		        ((x) << DWC3_DEPCMD_PARAM_SHIFT)
#define DWC3_DEPCMD_GET_RSC_IDX(x)	        (((x) >> DWC3_DEPCMD_PARAM_SHIFT) & 0x7fU)
#define DWC3_DEPCMD_STATUS(x)		        (((x) >> 15) & 1)
#define DWC3_DEPCMD_HIPRI_FORCERM	        (1UL << 11)
#define DWC3_DEPCMD_CMDACT		            (1UL << 10)
#define DWC3_DEPCMD_CMDIOC		            (1UL << 8)
/*
	#define DWC3_DEPCMD_DEPSTARTCFG		        (0x09UL << 0)
	#define DWC3_DEPCMD_ENDTRANSFER		        (0x08UL << 0)
	#define DWC3_DEPCMD_UPDATETRANSFER	        (0x07UL << 0)
	#define DWC3_DEPCMD_STARTTRANSFER	        (0x06UL << 0)
	#define DWC3_DEPCMD_CLEARSTALL		        (0x05UL << 0)
	#define DWC3_DEPCMD_SETSTALL		        (0x04UL << 0)
*/
#define DWC3_DEPCMD_DEPSTARTCFG		        (0x09U)
#define DWC3_DEPCMD_ENDTRANSFER		        (0x08U)
#define DWC3_DEPCMD_UPDATETRANSFER	        (0x07U)
#define DWC3_DEPCMD_STARTTRANSFER	        (0x06U)
#define DWC3_DEPCMD_CLEARSTALL		        (0x05U)
#define DWC3_DEPCMD_SETSTALL		        (0x04U)

/* ========================================================================
This applies for core versions 1.90a and earlier
======================================================================== */
#define DWC3_DEPCMD_GETSEQNUMBER	        (0x03 << 0)

/* ========================================================================
This applies for core versions 1.94a and later
======================================================================== */
#define DWC3_DEPCMD_GETEPSTATE		        (3UL << 0)
#define DWC3_DEPCMD_SETTRANSFRESOURCE	    (2UL << 0)
#define DWC3_DEPCMD_SETEPCONFIG		        (1UL << 0)

/* ========================================================================
The EP number goes 0..31 so ep0 is always out and ep1 is always in
======================================================================== */
#define DWC3_DALEPENA_EP(n)		            (1UL << (n))
#define DWC3_DEPCMD_TYPE_CONTROL	        0
#define DWC3_DEPCMD_TYPE_ISOC		        1
#define DWC3_DEPCMD_TYPE_BULK		        2
#define DWC3_DEPCMD_TYPE_INTR		        3

#define DWC3_GUCTL1_DEV_FORCE_20CLK_FOR_30CLK   (1 << 26)

/* ========================================================================
HWPARAMS0
======================================================================== */
#define DWC3_MODE(n)		                ((n) & 0x7)
#define DWC3_MDWIDTH(n)		                (((n) & 0xff00) >> 8)

/* ========================================================================
HWPARAMS1
======================================================================== */
#define DWC3_NUM_INT(n)		                (((n) & (0x3f << 15)) >> 15)

/* ========================================================================
HWPARAMS3
======================================================================== */
#define DWC3_NUM_IN_EPS_MASK	            (0x1f << 18)
#define DWC3_NUM_EPS_MASK	                (0x3f << 12)
#define DWC3_NUM_EPS(p)		                (((p)->hwparams3 & (DWC3_NUM_EPS_MASK)) >> 12)
#define DWC3_NUM_IN_EPS(p)	                (((p)->hwparams3 &	(DWC3_NUM_IN_EPS_MASK)) >> 18)

/* ========================================================================
HWPARAMS7
======================================================================== */
#define DWC3_RAM1_DEPTH(n)	                ((n) & 0xffff)
#define DWC3_TRB_NUM		                32
#define DWC3_TRB_MASK		                (DWC3_TRB_NUM - 1)

/* ========================================================================
TRB Length, PCM and Status
======================================================================== */
#define DWC3_TRB_SIZE_MASK	                (0x00ffffff)
#define DWC3_TRB_SIZE_LENGTH(n)	            ((n) & DWC3_TRB_SIZE_MASK)
#define DWC3_TRB_SIZE_PCM1(n)	            (((n) & 0x03) << 24)
#define DWC3_TRB_SIZE_TRBSTS(n)	            (((n) & (0x0f << 28)) >> 28)

#define DWC3_TRBSTS_OK			            0
#define DWC3_TRBSTS_MISSED_ISOC		        1
#define DWC3_TRBSTS_SETUP_PENDING	        2
#define DWC3_TRB_STS_XFER_IN_PROG	        4

/* ========================================================================`
TRB Control
======================================================================== */
#define DWC3_TRB_CTRL_HWO		            (1UL << 0)				/* Hardware Owner of Descriptor (HWO) */
#define DWC3_TRB_CTRL_LST		            (1UL << 1)				/* Last TRB (LST) */
#define DWC3_TRB_CTRL_CHN		            (1UL << 2)				/* Chain Buffers (CHN) */
#define DWC3_TRB_CTRL_CSP		            (1UL << 3)				/* Continue on Short Packet (CSP) */
#define DWC3_TRB_CTRL_TRBCTL(n)		        (((n) & 0x3fUL) << 4)		/* TRB Control (TRBCTL) */
#define DWC3_TRB_CTRL_ISP_IMI		        (1UL << 10)				/* Interrupt on Short Packet / Interrupt on Missed ISOC (ISP/IMI) */
#define DWC3_TRB_CTRL_IOC		            (1UL << 11)				/* Interrupt on Complete (IOC) */
#define DWC3_TRB_CTRL_SID_SOFN(n)	        (((n) & 0xffffUL) << 14)	/* Stream ID / SOF Number */

#define DWC3_TRBCTL_NORMAL		            DWC3_TRB_CTRL_TRBCTL(1U)	/* Ctrl data phase (두번째 이후), 벌크, 인터럽트 전송에 사용, 일반적인 데이터 전송에 사용됨. */
#define DWC3_TRBCTL_CONTROL_SETUP	        DWC3_TRB_CTRL_TRBCTL(2U)	/* Ctrl 전공의 셋업 phase 에서 사용. 8바이트 셋업 패킷을 위한 특별한 TRB */

#define DWC3_TRBCTL_CONTROL_STATUS2	        DWC3_TRB_CTRL_TRBCTL(3U)	/* 2 단계 Ctrl 전송의 status phase 에서 사용, 데이터 phase 가 없는 컨트롤 전송의 상태 정보 전송 */
#define DWC3_TRBCTL_CONTROL_STATUS3	        DWC3_TRB_CTRL_TRBCTL(4U)	/* 3 단계 ctrl 전송의 status phase 에서 사용, 데이터 phase 가 있는 컨트롤 전송의 상태 정보 전송 */

#define DWC3_TRBCTL_CONTROL_DATA	        DWC3_TRB_CTRL_TRBCTL(5U)	/* 컨트롤 전송의 데이터 단계 첫번째 TRB 에 사용한다. */

#define DWC3_TRBCTL_ISOCHRONOUS_FIRST	    DWC3_TRB_CTRL_TRBCTL(6U)
#define DWC3_TRBCTL_ISOCHRONOUS		        DWC3_TRB_CTRL_TRBCTL(7U)

#define DWC3_TRBCTL_LINK_TRB		        DWC3_TRB_CTRL_TRBCTL(8U)	/* TRB 리스트를 연결하는데 사용한다, 다음 TRB 세트의 주소를 가리키면, 순환버퍼 구현에 사용 */
#define DWC3_NORMAL_ZLP						DWC3_TRB_CTRL_TRBCTL(9U)	/* 벌크 In 전송에서 제로Length 패킷 종료가 필요한 경우 사용 */
/* 
 static volatile DRV_A6_USB_REGISTER* const RegA6_USB = (DRV_A6_USB_REGISTER*)APACHE_A6_USB_BASE_ADDR;
 */

/* =========================================================================

========================================================================= */
#define APACHE6_GSNPSID     0x55330000UL

/* =========================================================================

========================================================================= */
typedef struct
{
	UINT32	hwparams0;
	UINT32	hwparams1;
	UINT32	hwparams2;
	UINT32	hwparams3;
	UINT32	hwparams4;
	UINT32	hwparams5;
	UINT32	hwparams6;
	UINT32	hwparams7;
	UINT32	hwparams8;
} DWC3_HWPARAMS_T;

/* =========================================================================

========================================================================= */
typedef struct
{
	UINT32	param2;
	UINT32	param1;
	UINT32	param0;
} DWC3_EP_CMD_PARAMS_T;

/* =========================================================================
3.1.2 Structures (TRB Control and Status Fields)
========================================================================= */
typedef struct __attribute__ ((packed))
{
	UINT32		bpl;	/* buffer-pointer-low	 (03-00) */
	UINT32		bph;	/* buffer-pointer-high	 (07-04) */
	UINT32		size;	/* buffer-size 		 (0B-08) */
	UINT32		ctrl;	
} DWC3_TRB_T;

/* =========================================================================

========================================================================= */
typedef struct
{
	#define DWC3_EP_ENABLED		   		 (1UL << 0)
	#define DWC3_EP_STALL		   		 (1UL << 1)
	#define DWC3_EP_WEDGE		   		 (1UL << 2)
	#define DWC3_EP_TRANSFER_STARTED	 (1UL << 3)
	#define DWC3_EP_END_TRANSFER_PENDING (1UL << 4)
	#define DWC3_EP_PENDING_REQUEST		 (1UL << 5)
	#define DWC3_EP_MISSED_ISOC			 (1UL << 6)
	
	#define DWC3_EP0_DIR_IN				 (1UL << 31)

	/* USB_EP_T        		    endpoint; */
	/* DWC3_TRB_T	    		*trb_pool; */
	UINT32		                state;
	UINT32		                flags;
	UINT16				maxpacket;
	UINT8			            number;
	UINT8			            type;
	UINT8			            resource_index;
	/* char			            name[20]; */
	UINT32			            direction:1;
	/* UINT8			            stream_capable:1; */
} DWC3_EP_T;

/* =========================================================================

========================================================================= */
/* rcma-2.0.0-1755 */
/* 
enum dwc3_phy 
{
	DWC3_PHY_UNKNOWN = 0,
	DWC3_PHY_USB3,
	DWC3_PHY_USB2
};
 */
/* =========================================================================

========================================================================= */
typedef enum 
{
    EP0_STATE_INIT_PHASE,
    EP0_STATE_SETUP_PHASE,
    EP0_STATE_DATA_IN_PHASE,
    EP0_STATE_DATA_OUT_PHASE,
    EP0_STATE_STATUS_IN_PHASE,
    EP0_STATE_STATUS_OUT_PHASE,
    EP0_STATE_STALL_PHASE
} EP0_STATE_T;

/* =========================================================================

========================================================================= */
#if 0
enum dwc3_link_state
{
	/* In SuperSpeed */
	DWC3_LINK_STATE_U0			= 0x00, /* in HS, means ON */
	DWC3_LINK_STATE_U1			= 0x01,
	DWC3_LINK_STATE_U2			= 0x02, /* in HS, means SLEEP */
	DWC3_LINK_STATE_U3			= 0x03, /* in HS, means SUSPEND */
	DWC3_LINK_STATE_SS_DIS		= 0x04,
	DWC3_LINK_STATE_RX_DET		= 0x05, /* in HS, means Early Suspend */
	DWC3_LINK_STATE_SS_INACT	= 0x06,
	DWC3_LINK_STATE_POLL		= 0x07,
	DWC3_LINK_STATE_RECOV		= 0x08,
	DWC3_LINK_STATE_HRESET		= 0x09,
	DWC3_LINK_STATE_CMPLY		= 0x0a,
	DWC3_LINK_STATE_LPBK		= 0x0b,
	DWC3_LINK_STATE_RESET		= 0x0e,
	DWC3_LINK_STATE_RESUME		= 0x0f,
	DWC3_LINK_STATE_MASK		= 0x0f
};
#else
#define DWC3_LINK_STATE_U0			(0x00U); /* in HS, means ON */
#define DWC3_LINK_STATE_U1			(0x01U);
#define DWC3_LINK_STATE_U2			(0x02U); /* in HS, means SLEEP */
#define DWC3_LINK_STATE_U3			(0x03U); /* in HS, means SUSPEND */
#define DWC3_LINK_STATE_SS_DIS		(0x04U);
#define DWC3_LINK_STATE_RX_DET		(0x05U); /* in HS, means Early Suspend */
#define DWC3_LINK_STATE_SS_INACT	(0x06U);
#define DWC3_LINK_STATE_POLL		(0x07U);
#define DWC3_LINK_STATE_RECOV		(0x08U);
#define DWC3_LINK_STATE_HRESET		(0x09U);
#define DWC3_LINK_STATE_CMPLY		(0x0aU);
#define DWC3_LINK_STATE_LPBK		(0x0bU);
#define DWC3_LINK_STATE_RESET		(0x0eU);
#define DWC3_LINK_STATE_RESUME		(0x0fU);
#define DWC3_LINK_STATE_MASK		(0x0fU);
#endif
typedef union UINT32_T_
{
	UINT32	dw;
	UINT16	w[2];
	UINT8	b[4];
} UINT32_T;

typedef union UINT16_T_
{
	UINT16	w;
	UINT8	b[2];
} UINT16_T;

typedef union UINT64_T_
{
	UINT64	qw;
	UINT32	dw[2];
	UINT16	w[4];
	UINT8	b[8];
	struct
	{
		UINT32	low;
		UINT32	high;
	} highrow32;
} UINT64_T;
/* =========================================================================

========================================================================= */
typedef struct
{
	UINT8		*buf;
    UINT64      addr;
    UINT32  	size;
	UINT32  	lpos;
} DWC3_EVENT_BUFFER_T;

/* =========================================================================

========================================================================= */
typedef struct 
{
	union
	{
		UINT8 buffer[16];		/* 4DW */

		struct 
		{
			UINT32		bpl;	/* buffer-pointer-low	 (03-00) */
			UINT32		bph;	/* buffer-pointer-high	 (07-04) */
			UINT32		size;	/* buffer-size 			 (0B-08) */
			UINT32		ctrl;	
		} trb;
	} EP0_TRB_BUFF_UNION_T;
	
} EP0_TRB_BUFF_T;

/* =========================================================================

========================================================================= */
typedef struct
{
	#define DWC3_REVISION_173A	0x5533173a
	#define DWC3_REVISION_175A	0x5533175a
	#define DWC3_REVISION_180A	0x5533180a
	#define DWC3_REVISION_183A	0x5533183a
	#define DWC3_REVISION_185A	0x5533185a
	#define DWC3_REVISION_187A	0x5533187a
	#define DWC3_REVISION_188A	0x5533188a
	#define DWC3_REVISION_190A	0x5533190a
	#define DWC3_REVISION_194A	0x5533194a
	#define DWC3_REVISION_200A	0x5533200a
	#define DWC3_REVISION_202A	0x5533202a
	#define DWC3_REVISION_210A	0x5533210a
	#define DWC3_REVISION_220A	0x5533220a
	#define DWC3_REVISION_230A	0x5533230a
	#define DWC3_REVISION_240A	0x5533240a
	#define DWC3_REVISION_250A	0x5533250a
	#define DWC3_REVISION_260A	0x5533260a
	#define DWC3_REVISION_270A	0x5533270a
	#define DWC3_REVISION_280A	0x5533280a

    DWC3_EVENT_BUFFER_T         event;		/* USB event buffer */
	USB_CTRL_REQUEST_T       	ctrl_req;	/* USB control request */
	DWC3_TRB_T  			    ep0_trb;	/* ep0 TRB */

	USB_REQUEST_T               req[USB_ENDPOINTS_NUM];	/* usb request buffer memory */
	USB_REQUEST_T				vendor_req;				/* usb vendor request buffer */
	DWC3_EP_T       		    eps[USB_ENDPOINTS_NUM];	/* usb logical endpoints */

	/* usb standard descriptor */
	USB_DEVICE_DESCRIPTOR_T	    device_descriptor;
	USB_CONFIG_DESCRIPTOR_T		configuration_descriptor;
	USB_INTERFACE_DESCRIPTOR_T  interface_descriptor;
	USB_DEVICE_STRINGS_T		*desc_str;

	UINT64_T					ep0_trb_addr;
	UINT64_T					dstaddr;				/* bootloader2(BL2) base address */
	UINT64_T					hdraddr;				/* image header base address */
	UINT32				        ep0state;
	UINT32					    revision;
	UINT32						link_state;
	UINT32						allocated_data_length;	
	UINT32						total_bytes_expected;
	UINT32						total_bytes_received;
	UINT32						num_bytes_per_split_transfer;
	UINT32						split_transfer_bytes_expected;
	UINT32						accumulation_received_bytes;
	UINT8					    usb_device_speed;
	UINT8						firmware_downloading_status;
	UINT8						firmware_downloading_complete;
	UINT8 						old_state;
	UINT8						device_state;	

	BOOL						header_transferred;
	BOOL						binary_transferred;	
	BOOL						zlp_needed;

	/* Add global variables  */
	DWC3_EVENT_T 				dwc3_event;
	USB_ENDPOINT_DESCRIPTOR_T	dev_ep0_desc;
} UDC_CTX_T;

/* =========================================================================
DEPCFG parameter 1
========================================================================= */
#define DWC3_DEPCFG_INT_NUM(n)				((UINT32)(n) << 0)
#define DWC3_DEPCFG_XFER_COMPLETE_EN		(1UL << 8)
#define DWC3_DEPCFG_XFER_IN_PROGRESS_EN		(1UL << 9)
#define DWC3_DEPCFG_XFER_NOT_READY_EN		(1UL << 10)
#define DWC3_DEPCFG_FIFO_ERROR_EN			(1UL << 11)
#define DWC3_DEPCFG_STREAM_EVENT_EN			(1UL << 13)
#define DWC3_DEPCFG_BINTERVAL_M1(n) 		((UINT32)(n) << 16)
#define DWC3_DEPCFG_STREAM_CAPABLE			(1UL << 24)
#define DWC3_DEPCFG_EP_NUMBER(n) 			((UINT32)(n) << 25)
#define DWC3_DEPCFG_BULK_BASED				(1UL << 30)
#define DWC3_DEPCFG_FIFO_BASED				(1UL << 31)

/* =========================================================================
DEPCFG parameter 0
========================================================================= */
#define DWC3_DEPCFG_EP_TYPE(n)				((UINT32)(n) << 1)
#define DWC3_DEPCFG_MAX_PACKET_SIZE(n) 		((UINT32)(n) << 3)
#define DWC3_DEPCFG_FIFO_NUMBER(n) 			((UINT32)(n) << 17)
#define DWC3_DEPCFG_BURST_SIZE(n) 			((UINT32)(n) << 22)
#define DWC3_DEPCFG_DATA_SEQ_NUM(n) 		((UINT32)(n) << 26)

/* =========================================================================
This applies for core versions earlier than 1.94a
========================================================================= */
#define DWC3_DEPCFG_IGN_SEQ_NUM				(1 << 31)

/* =========================================================================
These apply for core versions 1.94a and later
========================================================================= */
#define DWC3_DEPCFG_ACTION_INIT				(0UL << 30)
#define DWC3_DEPCFG_ACTION_RESTORE 			(1UL << 30)
#define DWC3_DEPCFG_ACTION_MODIFY 			(2UL << 30)

/* =========================================================================
DEPXFERCFG parameter 0
========================================================================= */
#define DWC3_DEPXFERCFG_NUM_XFER_RES(n)	((UINT32)(n) & 0xffffU)


/* #define MEM_SET(DEST_ADDR, VALUE8, NUM_BYTES)		NC_Memset_u32((void*)(DEST_ADDR), (VALUE8), (NUM_BYTES))
#define MEM_COPY(DEST_ADDR, SRC_ADDR, NUM_BYTES)	NC_Memcopy_U32((UINT32*)(DEST_ADDR), (UINT32*)(SRC_ADDR), (NUM_BYTES)) */
#define MIN(A, B)				(((A) < (B)) ? (A) : (B))
#define MAX(A, B)				(((A) > (B)) ? (A) : (B))

#define ROUND_UP(x, y) ((((x) + ((y) - 1U)) / (y)) * (y))
#define UPPER_32BITS(n) ((UINT32)(((n) >> 16) >> 16))
#define LOWER_32BITS(n) ((UINT32)(n))


/* =========================================================================

========================================================================= */
/* 
extern UDC_CTX_T *g_r5_usb_ctx;
extern DWC3_EVENT_T g_event;
 */
extern void NC_USB_Core_Init(UDC_CTX_T *ptBootUsbCtx);
extern void NC_USB_Device_Run(BOOL is_on);
extern void NC_USB_Device_Event_Loop(UDC_CTX_T *ptBootUsbCtx, UINT64 *msec_time);
extern void NC_USB_Enable_Interrupt(void);
extern void NC_Endpoint_Interrupt_Handler(UDC_CTX_T *ptBootUsbCtx);
extern UINT32 NC_DWC3_Read(UINT32 offset);
extern void NC_DWC3_Write(UINT32 offset, UINT32 value);
/* extern UINT32 round_up(UINT32 x, UINT32 y); */

#endif
