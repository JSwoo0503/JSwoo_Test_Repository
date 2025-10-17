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
#include "seq_monitor.h"


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

#ifdef DEBUG_ENABLE_
BOOL ncBL_GetExitKey(void)
{
    BOOL ret = FALSE;
    CHAR buf;

    /* Input Key Exit - Test Stop */
    buf = (CHAR)NC_UART_GetChar();
    if(buf != (CHAR)NC_FAILURE)
    {
        if((buf == 'q') || (buf == 'Q'))
        {
            ret = TRUE;
        }
    }

    return ret;
}
#endif



/**
* @desc
    Jump to the loaded image.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
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
    IF No. 0 Core ready ok  THEN
        It notifies the sequence monitor that the current status is 'Jump Image'.
    ENDIF
    Jump to the image location.
*/
void NC_LD_JumpImage(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    if(((ptBootStatus->mBootDone_Res) & (1UL<<E_CORE_0)) == (1UL<<E_CORE_0))
    {                
        NC_SM_SetBOOT_Step((UINT32)DBG_STP_JUMP, ptBootStatus);
    }

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGWARN, " >>>>> Jump to RAM <<<<< \n", NULL);
#endif
    ASM_PC_JUMP(ptBootInfo->tImage.mDestAddr);
    /*
     *-----------------------------------------------------------------------------------
     * The end of BL1.
     * Never run here.
     *-----------------------------------------------------------------------------------
     */
}

/* End Of File */

