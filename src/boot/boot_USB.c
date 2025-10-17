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
*               INCLUDES
********************************************************************************
*/
#include "Apache.h"
#include "main.h"
#if defined(USB_DLOAD_)
#include "Drv_USB.h"
#endif
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"


#define FAIL_USB_DOWNLOAD           (1U)
#define FAIL_USB_CHECKSUM           (2U)

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Initialize USB.
* @param    tBOOT_INFO      *ptBootInfo     Boot Information Parameter
* @param    tBOOT_STATUS    *ptBootStatus   Boot Status Parameter
* @return   void
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;            Boot Image header info
        tBOOT_IMG   tImage;             Boot Image info
        tBOOT_STRAP tStrap;             Boot strap info
        tBOOT_CLK   tClock;             Boot clock info
        tBOOT_CMRT  tCMRT;              Boot CMRT info
    } tBOOT_INFO;
* @struct
    typedef struct
    {
        UINT32  mBackupRes;             The index of the FW binary in use.
        UINT32  mOtpRes;                OTP read result success or fail
        UINT32  mSecureRunRes;          Secure Run result success or fail
        UINT32  mSafetyModeRes;         Safety Mode init success or fail
        UINT32  mHeaderReadRes;         FW Header load success or fail
        UINT32  mCtrlMode;              SPI Ctrl Mode
        UINT32  mSF_CheckSCLKRes;       CheckSCLK Fail
        UINT32  mSF_FailRes;            SF Fail
        UINT32  mEMMC_FailRes;          eMMC Boot Fail
        UINT32  mSD_FailRes;            SD Boot Fail
        UINT32  mUART_FailRes;          UART Boot Fail
        UINT32  mUSB_FailRes;           USB Boot Fail
        UINT32  mBootDone_Res;          Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO*  ptHandleBoot;
    } tBOOT_STATUS;
* @design
    Initialize USB.
*/
void DEBUG_FUNC_ATTR NC_Boot_USB_Initialize(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    if(ptBootInfo == NULL) { }

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_USB_INIT_IN, ptBootStatus);

    NC_USB_Initialize(USB_INIT_DEVICE);

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_USB_INIT_OUT, ptBootStatus);
}



/**
* @desc
    Boot in USB mode.
* @param    tBOOT_INFO      *ptBootInfo     Boot Information Parameter
* @param    tBOOT_STATUS    *ptBootStatus   Boot Status Parameter
* @param    UDC_CTX_T       *ptBootUsbCtx   Boot USB Ctx
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;            Boot Image header info
        tBOOT_IMG   tImage;             Boot Image info
        tBOOT_STRAP tStrap;             Boot strap info
        tBOOT_CLK   tClock;             Boot clock info
        tBOOT_CMRT  tCMRT;              Boot CMRT info
    } tBOOT_INFO;
* @struct
    typedef struct
    {
        UINT32  mBackupRes;             The index of the FW binary in use.
        UINT32  mOtpRes;                OTP read result success or fail
        UINT32  mSecureRunRes;          Secure Run result success or fail
        UINT32  mSafetyModeRes;         Safety Mode init success or fail
        UINT32  mHeaderReadRes;         FW Header load success or fail
        UINT32  mCtrlMode;              SPI Ctrl Mode
        UINT32  mSF_CheckSCLKRes;       CheckSCLK Fail
        UINT32  mSF_FailRes;            SF Fail
        UINT32  mEMMC_FailRes;          eMMC Boot Fail
        UINT32  mSD_FailRes;            SD Boot Fail
        UINT32  mUART_FailRes;          UART Boot Fail
        UINT32  mUSB_FailRes;           USB Boot Fail
        UINT32  mBootDone_Res;          Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO*  ptHandleBoot;
    } tBOOT_STATUS;
* @design
    Ret = USB Firmware Up Grade
        IF  Checksum fail   THEN
            Ret = NC_FAILURE
        ELSE
            Ret = NC_SUCCESS
        ENDIF
    Return Ret
*/
NC_ERROR DEBUG_FUNC_ATTR NC_Boot_USB(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus, UDC_CTX_T *ptBootUsbCtx)
{
    NC_ERROR Ret;
    UINT32 CheckSum, Checksum_Src;
    UINT32 Checksum_Length;

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_USB_IMG_LOAD_IN, ptBootStatus);

    NC_Gpio_toggle();
    
    Ret = NC_USB_DeviceFirmwareUpgrade(ptBootInfo, ptBootUsbCtx);
    
    if(Ret == NC_SUCCESS) /* Success */
    {
        Checksum_Src = ptBootInfo->tImage.mDestAddr; /* for QAC */
        Checksum_Length = ptBootInfo->tHeader.mLength/4U; /* for QAC */

        CheckSum = NC_Checksum((UINT32 *)Checksum_Src, Checksum_Length);
        if(ptBootInfo->tHeader.mCheckSum != CheckSum)
        {
            Ret = NC_FAILURE;
            ptBootStatus->mUSB_FailRes |= ((UINT32)FAIL_USB_CHECKSUM);
            SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_CRC_IMG, (UINT32)TRUE);
        }
        else
        {
            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);
            Ret = NC_SUCCESS;
            /* Image Loading Result (Success or Fail) */
            ptBootStatus->mUSB_FailRes = ((UINT32)NC_SUCCESS);
        }
    }
    else
    {
        Ret = NC_FAILURE;
        ptBootStatus->mUSB_FailRes |= ((UINT32)FAIL_USB_DOWNLOAD);
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_READ_IMG, (UINT32)TRUE);
    }

    NC_Gpio_toggle();

    if(Ret != NC_SUCCESS)
    {
        NC_MPU_EnterSafetyGate();
        NC_SE_NotifyFailure(FAULT_USB);
        NC_MPU_LeaveSafetyGate();
    }

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_USB_IMG_LOAD_OUT, ptBootStatus);

    return Ret;
}

/* End Of File */
