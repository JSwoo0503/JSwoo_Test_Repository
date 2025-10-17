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
#include "cmrt_interface.h"
#include "seq_monitor.h"
#include "MPU.h"
#include "safety_engine.h"
#include "secure_boot.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/



/*
********************************************************************************
*               IMPORTED FUNCTION DEFINITIONS
********************************************************************************
*/



/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

/**
* @desc
    This function makes set the secure boot.
* @param    tBOOT_INFO      *ptBootInfo     Boot setting parameter information
* @param    tBOOT_STATUS    *ptBootStatus   Boot Status
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
    Result = NC_SUCCESS
    IF The secure boot mode set THEN
        IF Secure boot initialize success THEN
            IF Secure boot run success THEN
                DCache flush
            ELSE
                Result = NC_FAILURE
            ENDIF
        ELSE
            Result = NC_FAILURE
        ENDIF
    ENDIF
    Return Result
*/
#if defined(SECURE_BOOT_)
NC_ERROR NC_Secure_Boot(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR  Ret = NC_FAILURE;
    UINT32 In_KEY_STORAGE;
    UINT32 DestAddr, OsOffset, HeaderLength;
    UINT32 KeysplitReg, In_DiversifyPath;
#ifdef DEBUG_ENABLE_
    UINT32 UseCmrtKey;
#endif

    /* Image Decoding */
    if(ptBootInfo->tImage.mSecuMode == E_SBOOT_SECURE_MODE)
    {
        In_KEY_STORAGE = ptBootInfo->tImage.mKeyStorage;

        #ifdef DEBUG_ENABLE_
        UseCmrtKey  = ptBootInfo->tImage.mUseKeyCmrt;
        DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
        DEBUGMSG(MSGINFO, "  > Secure Boot\n", NULL);
        DEBUGMSG(MSGINFO, "    -. Dest.  Addr : 0x%08X\n", ptBootInfo->tImage.mDestAddr);
        DEBUGMSG(MSGINFO, "    -. Key Storage : %s\n", (In_KEY_STORAGE==1)?"OTP":(In_KEY_STORAGE==2)?"ROM":(In_KEY_STORAGE==4)?"CMRT":"Unknown");
        DEBUGMSG(MSGINFO, "    -. Use CMRT Key: %s\n", (UseCmrtKey==1)?"Use CMRT Internal OTP Key":(UseCmrtKey==2)?"Not use CMRT Internal OTP Key":"Unknown");
        #endif

        #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "os with user_container address : 0x%08x\n", ptBootInfo->tImage.mDestAddr + ptBootInfo->tHeader.tBootSec.mOsOffset);
        DEBUGMSG(MSGINFO, "os with user_container size : 0x%08x\n", ptBootInfo->tHeader.tBootSec.mOsSize);
        DEBUGMSG(MSGINFO, "Key Split Num : 0x%08x\n", ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg);
        DEBUGMSG(MSGINFO, "Diversify Path : 0x%08x\n", ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH);
        #endif

        DestAddr = (UINT32)(ptBootInfo->tImage.mDestAddr);
        OsOffset = (UINT32)(ptBootInfo->tHeader.tBootSec.mOsOffset);

        Ret = NC_SB_CMRT_Initialize(DestAddr + OsOffset, ptBootStatus);

        if(Ret == NC_SUCCESS)
        {
        }
        else
        {
            /* SECURE BOOT FAIL */
            ptBootStatus->mSecureRunRes |= NC_BOOT_SECURE_INIT_FAIL;
            NC_MPU_EnterSafetyGate();
            NC_SE_NotifyFailure(FAULT_SB_INIT);
            NC_MPU_LeaveSafetyGate();
        }

        if (Ret == NC_SUCCESS)
        {
            KeysplitReg = (UINT32)(ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg);
            In_DiversifyPath = (UINT32)(ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH);
            #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Key Storage : %d ,  KeysplitReg : 0x%x, Diversify Path : 0x%08x\n", In_KEY_STORAGE, KeysplitReg, In_DiversifyPath);
            #endif
            Ret = NC_SB_CMRT_Secure_Run(DestAddr, (UINT8)In_KEY_STORAGE, KeysplitReg, In_DiversifyPath, ptBootStatus);
        }

        if(Ret == NC_SUCCESS)
        {
            HeaderLength = ptBootInfo->tHeader.mLength;
            ASM_DCACHE_FLUSH(DestAddr, HeaderLength);
        }
        else
        {
            /* SECURE BOOT FAIL */
            ptBootStatus->mSecureRunRes |= NC_BOOT_SECURE_RUN_FAIL;
            NC_MPU_EnterSafetyGate();
            NC_SE_NotifyFailure(FAULT_SB_RUN);
            NC_MPU_LeaveSafetyGate();
        }

        #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "    -. Result      : %s\n", (Ret == NC_SUCCESS)?"OK":"Fail");
        #endif
    }

    return Ret;
}
#endif
/* End Of File */

