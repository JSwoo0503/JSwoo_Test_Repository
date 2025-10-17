
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE5 BSP
*   File       : DRV_A6_USB_Register.h
*   Date       : 2022-07-26 09:46
* 
*   THIS CODE IS GENERATED FROM APACHE5 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_USB_H__
#define DRV_REGISTER_A6_USB_H__

#if defined(__UBOOT__)
#define APACHE_A6_USB_BASE_ADDR        0xFE800000 /* rk3399 */
#else
#define APACHE_A6_USB_BASE_ADDR        0x0B000000
#endif

#if 0

/* Global constants */
#define DWC3_EP0_BOUNCE_SIZE	        512
#define DWC3_XHCI_RESOURCES_NUM	        2

#define DWC3_SCRATCHBUF_SIZE	        4096	/* each buffer is assumed to be 4KiB */
#define DWC3_EVENT_SIZE		            4	/* bytes */
#define DWC3_EVENT_MAX_NUM	            64	/* 2 events/endpoint */
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
#define DWC3_GSNPSID_MASK	            0xffff0000
#define DWC3_GSNPSREV_MASK	            0xffff

/* DWC3 registers memory space boundries */
#define DWC3_XHCI_REGS_START		    0x0
#define DWC3_XHCI_REGS_END		        0x7fff
#define DWC3_GLOBALS_REGS_START		    0xc100
#define DWC3_GLOBALS_REGS_END		    0xc6ff
#define DWC3_DEVICE_REGS_START		    0xc700
#define DWC3_DEVICE_REGS_END		    0xcbff
#define DWC3_OTG_REGS_START		        0xcc00
#define DWC3_OTG_REGS_END		        0xccff

/* Global Registers */
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
#define DWC3_GUSB2PHYCFG(n)	    (0xc200 + (n * 0x04))
#define DWC3_GUSB2I2CCTL(n)	    (0xc240 + (n * 0x04))
#define DWC3_GUSB2PHYACC(n)	    (0xc280 + (n * 0x04))
#define DWC3_GUSB3PIPECTL(n)	(0xc2c0 + (n * 0x04))
#define DWC3_GTXFIFOSIZ(n)	    (0xc300 + (n * 0x04))
#define DWC3_GRXFIFOSIZ(n)	    (0xc380 + (n * 0x04))
#define DWC3_GEVNTADRLO(n)	    (0xc400 + (n * 0x10))
#define DWC3_GEVNTADRHI(n)	    (0xc404 + (n * 0x10))
#define DWC3_GEVNTSIZ(n)	    (0xc408 + (n * 0x10))
#define DWC3_GEVNTCOUNT(n)	    (0xc40c + (n * 0x10))
#define DWC3_GHWPARAMS8		    0xc600

/* Device Registers */
/* #define DWC3_DCFG		        0xc700
#define DWC3_DCTL		        0xc704
#define DWC3_DEVTEN		        0xc708
#define DWC3_DSTS		        0xc70c
#define DWC3_DGCMDPAR		    0xc710
#define DWC3_DGCMD		        0xc714 */
/* #define DWC3_DALEPENA		    0xc720 */
#define DWC3_DEPCMDPAR2(n)	    (0xc800 + (n * 0x10))
#define DWC3_DEPCMDPAR1(n)	    (0xc804 + (n * 0x10))
#define DWC3_DEPCMDPAR0(n)	    (0xc808 + (n * 0x10))
#define DWC3_DEPCMD(n)		    (0xc80c + (n * 0x10))

/* Global Configuration Register */
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

/* Global USB2 PHY Configuration Register */
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

/* Global USB3 PIPE Control Register */
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

/* Global TX Fifo Size Register */
#define DWC3_GTXFIFOSIZ_TXFDEF(n)	        ((n) & 0xffff)
#define DWC3_GTXFIFOSIZ_TXFSTADDR(n)	    ((n) & 0xffff0000)

/* Global Event Size Registers */
#define DWC3_GEVNTSIZ_INTMASK		        (1 << 31)
#define DWC3_GEVNTSIZ_SIZE(n)		        ((n) & 0xffff)

/* Global HWPARAMS1 Register */
#define DWC3_GHWPARAMS1_EN_PWROPT(n)	    (((n) & (3 << 24)) >> 24)
#define DWC3_GHWPARAMS1_EN_PWROPT_NO	    0
#define DWC3_GHWPARAMS1_EN_PWROPT_CLK	    1
#define DWC3_GHWPARAMS1_EN_PWROPT_HIB	    2
#define DWC3_GHWPARAMS1_PWROPT(n)	        ((n) << 24)
#define DWC3_GHWPARAMS1_PWROPT_MASK	        DWC3_GHWPARAMS1_PWROPT(3)

/* Global HWPARAMS3 Register */
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

/* Global HWPARAMS4 Register */
#define DWC3_GHWPARAMS4_HIBER_SCRATCHBUFS(n)	(((n) & (0x0f << 13)) >> 13)
#define DWC3_MAX_HIBER_SCRATCHBUFS		    15

/* Global HWPARAMS6 Register */
#define DWC3_GHWPARAMS6_EN_FPGA			    (1 << 7)

/* Device Configuration Register */
#define DWC3_DCFG_DEVADDR(addr)	            ((addr) << 3)
#define DWC3_DCFG_DEVADDR_MASK	            DWC3_DCFG_DEVADDR(0x7f)

#define DWC3_DCFG_SPEED_MASK	            (7 << 0)
#define DWC3_DCFG_SUPERSPEED	            (4 << 0)
#define DWC3_DCFG_HIGHSPEED	                (0 << 0)
#define DWC3_DCFG_FULLSPEED2	            (1 << 0)
#define DWC3_DCFG_LOWSPEED	                (2 << 0)
#define DWC3_DCFG_FULLSPEED1	            (3 << 0)
#define DWC3_DCFG_LPM_CAP	                (1 << 22)

/* Device Control Register */
#define DWC3_DCTL_RUN_STOP	                (1 << 31)
#define DWC3_DCTL_CSFTRST	                (1 << 30)
#define DWC3_DCTL_LSFTRST	                (1 << 29)

#define DWC3_DCTL_HIRD_THRES_MASK	        (0x1f << 24)
#define DWC3_DCTL_HIRD_THRES(n)	            ((n) << 24)

#define DWC3_DCTL_APPL1RES	                (1 << 23)

/* These apply for core versions 1.87a and earlier */
#define DWC3_DCTL_TRGTULST_MASK		        (0x0f << 17)
#define DWC3_DCTL_TRGTULST(n)		        ((n) << 17)
#define DWC3_DCTL_TRGTULST_U2		        (DWC3_DCTL_TRGTULST(2))
#define DWC3_DCTL_TRGTULST_U3		        (DWC3_DCTL_TRGTULST(3))
#define DWC3_DCTL_TRGTULST_SS_DIS	        (DWC3_DCTL_TRGTULST(4))
#define DWC3_DCTL_TRGTULST_RX_DET	        (DWC3_DCTL_TRGTULST(5))
#define DWC3_DCTL_TRGTULST_SS_INACT	        (DWC3_DCTL_TRGTULST(6))

/* These apply for core versions 1.94a and later */
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

/* Device Event Enable Register */
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

/* Device Status Register */
#define DWC3_DSTS_DCNRD			            (1 << 29)

/* This applies for core versions 1.87a and earlier */
#define DWC3_DSTS_PWRUPREQ		            (1 << 24)

/* These apply for core versions 1.94a and later */
/*
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
#define DWC3_DSTS_HIGHSPEED		            (0 << 0)
#define DWC3_DSTS_FULLSPEED2		        (1 << 0)
#define DWC3_DSTS_LOWSPEED		            (2 << 0)
#define DWC3_DSTS_FULLSPEED1		        (3 << 0)
*/

/* Device Generic Command Register */
#define DWC3_DGCMD_SET_LMP		            0x01
#define DWC3_DGCMD_SET_PERIODIC_PAR	        0x02
#define DWC3_DGCMD_XMIT_FUNCTION	        0x03

/* These apply for core versions 1.94a and later */
#define DWC3_DGCMD_SET_SCRATCHPAD_ADDR_LO	0x04
#define DWC3_DGCMD_SET_SCRATCHPAD_ADDR_HI	0x05
#define DWC3_DGCMD_SELECTED_FIFO_FLUSH	    0x09
#define DWC3_DGCMD_ALL_FIFO_FLUSH	        0x0a
#define DWC3_DGCMD_SET_ENDPOINT_NRDY	    0x0c
#define DWC3_DGCMD_RUN_SOC_BUS_LOOPBACK	    0x10
#define DWC3_DGCMD_STATUS(n)		        (((n) >> 15) & 1)
#define DWC3_DGCMD_CMDACT		            (1 << 10)
#define DWC3_DGCMD_CMDIOC		            (1 << 8)

/* Device Generic Command Parameter Register */
#define DWC3_DGCMDPAR_FORCE_LINKPM_ACCEPT	(1 << 0)
#define DWC3_DGCMDPAR_FIFO_NUM(n)		    ((n) << 0)
#define DWC3_DGCMDPAR_RX_FIFO			    (0 << 5)
#define DWC3_DGCMDPAR_TX_FIFO			    (1 << 5)
#define DWC3_DGCMDPAR_LOOPBACK_DIS		    (0 << 0)
#define DWC3_DGCMDPAR_LOOPBACK_ENA		    (1 << 0)

/* Device Endpoint Command Register */
#define DWC3_DEPCMD_PARAM_SHIFT		        16
#define DWC3_DEPCMD_PARAM(x)		        ((x) << DWC3_DEPCMD_PARAM_SHIFT)
#define DWC3_DEPCMD_GET_RSC_IDX(x)	        (((x) >> DWC3_DEPCMD_PARAM_SHIFT) & 0x7f)
#define DWC3_DEPCMD_STATUS(x)		        (((x) >> 15) & 1)
#define DWC3_DEPCMD_HIPRI_FORCERM	        (1 << 11)
#define DWC3_DEPCMD_CMDACT		            (1 << 10)
#define DWC3_DEPCMD_CMDIOC		            (1 << 8)

/*
#define DWC3_DEPCMD_DEPSTARTCFG		        (0x09 << 0)
#define DWC3_DEPCMD_ENDTRANSFER		        (0x08 << 0)
#define DWC3_DEPCMD_UPDATETRANSFER	        (0x07 << 0)
#define DWC3_DEPCMD_STARTTRANSFER	        (0x06 << 0)
#define DWC3_DEPCMD_CLEARSTALL		        (0x05 << 0)
#define DWC3_DEPCMD_SETSTALL		        (0x04 << 0)
*/
/* This applies for core versions 1.90a and earlier */
/*
#define DWC3_DEPCMD_GETSEQNUMBER	        (0x03 << 0)
*/
/* This applies for core versions 1.94a and later */
/*
    #define DWC3_DEPCMD_GETEPSTATE		        (0x03 << 0)
    #define DWC3_DEPCMD_SETTRANSFRESOURCE	    (0x02 << 0)
    #define DWC3_DEPCMD_SETEPCONFIG		        (0x01 << 0)
*/

/* The EP number goes 0..31 so ep0 is always out and ep1 is always in */
/* #define DWC3_DALEPENA_EP(n)		            (1 << n) */
#define DWC3_DEPCMD_TYPE_CONTROL	        0
#define DWC3_DEPCMD_TYPE_ISOC		        1
#define DWC3_DEPCMD_TYPE_BULK		        2
#define DWC3_DEPCMD_TYPE_INTR		        3

#define DWC3_GUCTL1_DEV_FORCE_20CLK_FOR_30CLK   (1 << 26)

/* HWPARAMS0 */
#define DWC3_MODE(n)		                ((n) & 0x7)
#define DWC3_MDWIDTH(n)		                (((n) & 0xff00) >> 8)

/* HWPARAMS1 */
#define DWC3_NUM_INT(n)		                (((n) & (0x3f << 15)) >> 15)

/* HWPARAMS3 */
#define DWC3_NUM_IN_EPS_MASK	            (0x1f << 18)
#define DWC3_NUM_EPS_MASK	                (0x3f << 12)
#define DWC3_NUM_EPS(p)		                (((p)->hwparams3 & (DWC3_NUM_EPS_MASK)) >> 12)
#define DWC3_NUM_IN_EPS(p)	                (((p)->hwparams3 &	(DWC3_NUM_IN_EPS_MASK)) >> 18)

/* HWPARAMS7 */
#define DWC3_RAM1_DEPTH(n)	                ((n) & 0xffff)
#define DWC3_TRB_NUM		                32
#define DWC3_TRB_MASK		                (DWC3_TRB_NUM - 1)

/* TRB Length, PCM and Status */
#define DWC3_TRB_SIZE_MASK	                (0x00ffffff)
#define DWC3_TRB_SIZE_LENGTH(n)	            ((n) & DWC3_TRB_SIZE_MASK)
#define DWC3_TRB_SIZE_PCM1(n)	            (((n) & 0x03) << 24)
#define DWC3_TRB_SIZE_TRBSTS(n)	            (((n) & (0x0f << 28)) >> 28)

#define DWC3_TRBSTS_OK			            0
#define DWC3_TRBSTS_MISSED_ISOC		        1
#define DWC3_TRBSTS_SETUP_PENDING	        2
#define DWC3_TRB_STS_XFER_IN_PROG	        4

/* TRB Control */
#define DWC3_TRB_CTRL_HWO		            (1 << 0)
#define DWC3_TRB_CTRL_LST		            (1 << 1)
#define DWC3_TRB_CTRL_CHN		            (1 << 2)
#define DWC3_TRB_CTRL_CSP		            (1 << 3)
#define DWC3_TRB_CTRL_TRBCTL(n)		        (((n) & 0x3f) << 4)
#define DWC3_TRB_CTRL_ISP_IMI		        (1 << 10)
#define DWC3_TRB_CTRL_IOC		            (1 << 11)
#define DWC3_TRB_CTRL_SID_SOFN(n)	        (((n) & 0xffff) << 14)

#define DWC3_TRBCTL_NORMAL		            DWC3_TRB_CTRL_TRBCTL(1)
#define DWC3_TRBCTL_CONTROL_SETUP	        DWC3_TRB_CTRL_TRBCTL(2)
#define DWC3_TRBCTL_CONTROL_STATUS2	        DWC3_TRB_CTRL_TRBCTL(3)
#define DWC3_TRBCTL_CONTROL_STATUS3	        DWC3_TRB_CTRL_TRBCTL(4)
#define DWC3_TRBCTL_CONTROL_DATA	        DWC3_TRB_CTRL_TRBCTL(5)
#define DWC3_TRBCTL_ISOCHRONOUS_FIRST	    DWC3_TRB_CTRL_TRBCTL(6)
#define DWC3_TRBCTL_ISOCHRONOUS		        DWC3_TRB_CTRL_TRBCTL(7)
#define DWC3_TRBCTL_LINK_TRB		        DWC3_TRB_CTRL_TRBCTL(8)

#endif

/* 
 static volatile DRV_A6_USB_REGISTER* const RegA6_USB = (DRV_A6_USB_REGISTER*)APACHE_A6_USB_BASE_ADDR;
 */



#endif /* end of  __DRV_REGISTER_A6_USB__ */

