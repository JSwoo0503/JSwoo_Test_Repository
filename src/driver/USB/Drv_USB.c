/**
********************************************************************************
*
*  Copyright (C) 2022 NEXTCHIP Inc. All rights reserved.
*
*  file    :
*
*  brief   :
*
*  author  :
*
*  date    :
*
*  version :
*
********************************************************************************
*  note    :
*
********************************************************************************
*/


/*
********************************************************************************
*               INCLUDE
********************************************************************************
*/
#include "Apache.h"
#include "Drv_USB.h"
/* #include "dwc3_core.h" */
/* #include "dwc3_gadget.h" */
/* #include "usb.h" */
#ifdef OTP_ENABLE_
#include "Drv_A6_OTP2K_Register.h"
#endif
#include "Drv_SCU.h"

#include "Drv_USB_FEATURE.h"
#include "boot_config.h"
#include "Drv_USB_REGS.h"
#include "Drv_USB_SPEC.h"

#include "Drv_USB_Core.h"
#include "Drv_USB_Ep0.h"
#include "Drv_USB_Device.h"
#include "Drv_USB_Descriptor.h"

#include "MPU.h"
/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

/* #define NCDLOAD_INTERFACE_CLASS	    0xff */ /* qac-9.6.0-3214 not used and could be remmoved */
/* #define NCDLOAD_INTERFACE_SUB_CLASS	0x1 */ /* qac-9.6.0-3214 not used and could be remmoved */
/* #define NCDLOAD_INTERFACE_PROTOCOL	0x1 */  /* qac-9.6.0-3214 not used and could be remmoved */

/* #define MAX_STRING_SERIAL   128 */ /* qac-9.6.0-3214 not used and could be remmoved */

#if 0
static const char product[] = "NVS3000";
/* static const char apache6_serial[] = "A01"; */ /* {'A','0', '1'}; */
static char apache6_serial[MAX_STRING_SERIAL];
static const char manufacturer[] = "NEXTCHIP Co, Ltd";
static const usb_string_t apache6_string_defs[] = {
	{.s = manufacturer,
     .id = 1 },
	{.s = product,
    .id = 2 },
	{.s = apache6_serial,
    .id =3 },
	{ }		/* end of list */
};

static const usb_gadget_strings_t apache6_string = {
	.language = 0x0409, /* en-us */
	.strings = apache6_string_defs,
};

static USB_REF_CLK_TABLE a6_usbphy_ext_clk_table[USB_REF_CLK_MAX] ={
    {/* USB_REF_CLK_100_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x27U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_19_2_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x38U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_20_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x31U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_24_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x2AU,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_25_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x02U,
        .Bit.mpll_multiplier    = 0x64U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_26_MHZ */
        .Bit.ref_clkdiv2        = 0U,
        .Bit.fsel               = 0x02U,
        .Bit.mpll_multiplier    = 0x60U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_38_4_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x38U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_40_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x31U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_48_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x2AU,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_50_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x02U,
        .Bit.mpll_multiplier    = 0x64U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_52_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x02U,
        .Bit.mpll_multiplier    = 0x60U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
    {/* USB_REF_CLK_200_MHZ */
        .Bit.ref_clkdiv2        = 1U,
        .Bit.fsel               = 0x27U,
        .Bit.mpll_multiplier    = 0U,
        .Bit.ssc_ref_clk_sel    = 0U,
    },
};

static dwc3_t dwc;
#endif

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    USB Phy Initialize.
* @param   void
* @return  void
* @design
    USB Phy Initialize.
 */
static DEBUG_FUNC_ATTR void NC_USB_Phy_Init(void)
{
    RegA6_USB_SCU->USBPHY_MISC14.Bit.REF_CLKDIV2                = 0x0;
    RegA6_USB_SCU->USBPHY_MISC14.Bit.REF_USE_PAD                = 0x1;            
    RegA6_USB_SCU->USBPHY_MISC14.Bit.REF_SSP_EN                 = 0x1;
    RegA6_USB_SCU->USBPHY_MISC14.Bit.REF_ALT_CLK_M              = 0x1;
    /* 13 */
    RegA6_USB_SCU->USBPHY_MISC13.Bit.SSC_REF_CLK_SEL            = 0x0;
    RegA6_USB_SCU->USBPHY_MISC13.Bit.SSC_RANGE                  = 0x0;
    RegA6_USB_SCU->USBPHY_MISC17.Bit.MPLL_MULTIPLIER            = 0x0;
    RegA6_USB_SCU->USBPHY_MISC18.Bit.TX_VBOOST_LVL              = 0x4;
    RegA6_USB_SCU->USBPHY_MISC18.Bit.FSEL                       = 0x27;
    
    RegA6_USB_SCU->USBPHY_MISC22.Bit.COMPDISTUNE0               = 0x3U;
    RegA6_USB_SCU->USBPHY_MISC22.Bit.OTGTUNE0                   = 0x3U;
    RegA6_USB_SCU->USBPHY_MISC12.Bit.LOS_BIAS                   = 0x2U;
    RegA6_USB_SCU->USBPHY_MISC2.Bit.PCS_TX_DEEMPH_3P5DB         = 0x17U;
    RegA6_USB_SCU->USBPHY_MISC3.Bit.PCS_TX_DEEMPH_6DB           = 0x21U;
    RegA6_USB_SCU->USBPHY_MISC3.Bit.PCS_TX_SWING_FULL           = 0x78U;

    RegA6_USB_SCU->USBPHY_MISC0.Bit.SSC_EN                      = 0x1;    
    RegA6_USB_SCU->USBPHY_MISC5.Bit.LANE0_TX_TERM_OFFSET        = 0x0;       

    RegA6_USB_SCU->USBPHY_MISC12.Bit.LOS_BIAS                   = 0x2;  
    RegA6_USB_SCU->USBPHY_MISC12.Bit.LOS_LEVEL                  = 0x9;      

    RegA6_USB_SCU->USBPHY_MISC22.Bit.TXFSLSTUNE0                = 0x3;      
    RegA6_USB_SCU->USBPHY_MISC22.Bit.SQRXTUNE0                  = 0x3;      
    /* RegA6_USB_SCU->USBPHY_MISC22.Bit.OTGTUNE0                   = 0x3; */      
    /* RegA6_USB_SCU->USBPHY_MISC22.Bit.COMPDISTUNE0               = 0x3; */    
}



/**
* @desc
    USB Initialize.
* @param   usb_init_type    type    type value
* @return  void
* @design
    USB Initialize.
 */
void DEBUG_FUNC_ATTR NC_USB_Initialize(usb_init_type type)
{
    if(type == USB_INIT_DEVICE) { }
}


#ifdef DEBUG_ENABLE_
void DEBUG_FUNC_ATTR NC_USB_ShowInfo(const tBOOT_HDR *tHeader)
{
    if(tHeader == NULL) { }

    /* tBOOT_HDR *bin_header = (tBOOT_HDR*)&g_boot_info.tHeader; */
    DBGUSB(MSGINFO, "\n=============================\n", NULL);
    DBGUSB(MSGINFO, "// Bin Header Info!!\n", NULL);
    DBGUSB(MSGINFO, "=============================\n", NULL);
    DBGUSB(MSGINFO, "mCheckSum: 0x%08X\n", tHeader->mCheckSum);
    DBGUSB(MSGINFO, "mLength: %d\n", tHeader->mLength);
    DBGUSB(MSGINFO, "mConfig_1: 0x%08X\n", tHeader->mConfig_1);
    DBGUSB(MSGINFO, "mConfig_2: 0x%08X\n", tHeader->mConfig_2);
    DBGUSB(MSGINFO, "mSignature: 0x%08X\n", tHeader->mSignature);
    DBGUSB(MSGINFO, "=============================\n", NULL);
}
#endif



/**
* @desc
    USB Device firmware Upgrade.
* @param    tBOOT_INFO      *ptBootInfo     Boot Information Parameter
* @param    UDC_CTX_T       *ptBootUsbCtx   Boot USB ctx
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Initailization context.
    USB Phy Initialize.
    USB Device Run.
 */
NC_ERROR DEBUG_FUNC_ATTR NC_USB_DeviceFirmwareUpgrade(const tBOOT_INFO *ptBootInfo, UDC_CTX_T *ptBootUsbCtx)
{
    NC_ERROR Ret = NC_FAILURE;
    UINT64 start_time = NC_SCU_GetMsec(FALSE);
    UINT64 current_time;
    UINT64 loop = 0xffffffffULL;

    /* Initailization context */
    NC_Memset_u08(ptBootUsbCtx, (UINT8)0, (INT32)sizeof(UDC_CTX_T));

    NC_USB_Phy_Init(); 

    NC_USB_Prepare_Descriptor(ptBootUsbCtx);

    NC_USB_Core_Init(ptBootUsbCtx);

    ptBootUsbCtx->hdraddr.qw = (UINT64)&(ptBootInfo->tHeader);
    ptBootUsbCtx->dstaddr.qw = (UINT64)ptBootInfo->tImage.mDestAddr;

    ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_IDLE;
    ptBootUsbCtx->firmware_downloading_complete = FALSE;

    do
    {
        loop--;
        NC_USB_Device_Event_Loop(ptBootUsbCtx, &start_time);

        if ((ptBootUsbCtx->firmware_downloading_status == (UINT8)USB_REQ_VENDOR_NC_FWDN_END) &&
            (ptBootUsbCtx->firmware_downloading_complete == (UINT8)TRUE)) 
        {
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGWARN, "Binary Downloading Complete!!! %d / %d bytes\n",
                                    ptBootUsbCtx->total_bytes_received,
                                    ptBootUsbCtx->total_bytes_expected); 
#endif
            Ret = NC_SUCCESS;

            start_time = NC_SCU_GetMsec(FALSE); /* When a packet is received, the time for the timeout is reset */
            
            if (ptBootUsbCtx->ep0state == (UINT32)EP0_STATE_SETUP_PHASE)
            {
                ASSERT_USB(ptBootUsbCtx->header_transferred == FALSE, ASSERT_NO_0003);
                ASSERT_USB(ptBootUsbCtx->binary_transferred == FALSE, ASSERT_NO_0004);
                /* 모든 펌웨어를 받고 셋업 패킷 Ready 상태가 되면 호스트 연결을 끊는다. */
#ifdef DEBUG_ENABLE_
                DBGUSB(MSGINFO, "\n usb task done, r5 will be disconnect\n", NULL);
#endif
                NC_USB_Device_Run(FALSE);
            }
            else
            {
                if (0ULL < loop)
                {
                    /* DBGUSB(MSGINFO, "\n ussb state:%d\n", ptBootUsbCtx->ep0state); */
                    continue;
                }
            }
	        
            break;
        }
        current_time = NC_SCU_GetMsec(FALSE);
        
        /* DEBUGMSG(MSGINFO, "time:%dmsec\n", current_time-start_time); */

        if(((UINT32)(current_time - start_time) / 1000U) >= (UINT32)USB_FW_UPGRADE_RECEIVE_TIMEOUT)
        {
            loop = 0ULL;
        } 
    } while(0ULL < loop);
    
#ifdef DEBUG_ENABLE_
    NC_USB_ShowInfo(&ptBootInfo->tHeader);
#endif
    return Ret;
}
