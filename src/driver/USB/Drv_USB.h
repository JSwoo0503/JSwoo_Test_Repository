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
#ifndef DRV_USB_H_
#define DRV_USB_H_

#include "Drv_A6_USB_Register.h"
#include "Drv_A6_USB_SCU_Register.h"
#include "Drv_USB_Core.h"
#include "boot_config.h"

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define USB_FW_UPGRADE_RECEIVE_TIMEOUT (600U * (SEC)) /* SEC */

typedef enum  {
	USB_INIT_HOST,
	USB_INIT_DEVICE
}usb_init_type;


enum {
    USB_REF_CLK_100_MHZ = 0,	/* default(HW Reset Value) */
    USB_REF_CLK_19_2_MHZ,
    USB_REF_CLK_20_MHZ,
    USB_REF_CLK_24_MHZ,
    USB_REF_CLK_25_MHZ,
    USB_REF_CLK_26_MHZ,
    USB_REF_CLK_38_4_MHZ,
    USB_REF_CLK_40_MHZ,
    USB_REF_CLK_48_MHZ,
    USB_REF_CLK_50_MHZ,
    USB_REF_CLK_52_MHZ,
    USB_REF_CLK_200_MHZ,	/* 11 */
    USB_REF_CLK_MAX
};

typedef union {
    UINT32  Value;
    struct {
        UINT32  ref_clkdiv2     : 1;
        UINT32  fsel            : 6;
        UINT32  mpll_multiplier : 7;
        UINT32  ssc_ref_clk_sel : 9;
        UINT32  reserved        : 9;
    }Bit;
}USB_REF_CLK_TABLE;

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/
extern void  NC_USB_Initialize(usb_init_type type);
extern NC_ERROR NC_USB_DeviceFirmwareUpgrade(const tBOOT_INFO *ptBootInfo, UDC_CTX_T *ptBootUsbCtx);
#endif  /* DRV_USB_H_ */


/* End Of File */
