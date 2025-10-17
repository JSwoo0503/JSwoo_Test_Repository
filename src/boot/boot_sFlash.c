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
#include "Drv_SPI.h"
#include "Drv_Uart.h"
#include "Drv_SCU.h"
#include "Svc_sFlash.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

#define QSPI_DIV_LOW_DEFAULT              (20U)
#define QSPI_DIV_MID                      (16U)
#define QSPI_DIV_HIGH                     (8U)

#define FAIL_SF_HDR_READ                  (1U)

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Read the header data.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter.
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
* @design
    Ret = NC_FAILURE

    DO WHILE    Image type is Nomal or Backup.
        Read Serial Flash data.
        IF  Signature ID of header is valid.    THEN
            Ret = NC_SUCCESS
        ELSE
            Output Debugging message.
        ENDIF
    LOOP

    Return Ret
*/
static NC_ERROR NC_SF_GetHeader(tBOOT_INFO *ptBootInfo)
{
    NC_ERROR Ret = NC_FAILURE;
    UINT32 ImgType;

    /* 0: E_IMG_NORMAL, 1:E_IMG_BACKUP */
    for(ImgType = E_IMG_NORMAL; ImgType < E_IMG_TYPE_MAX; ImgType++)
    {
        ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg   = 0;
        ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH = 0;
        ptBootInfo->tImage.mImg_Type = ImgType;

        NC_SF_ReadData(E_SF_SPI_MODE,
                            ptBootInfo->tImage.mFlashAddr[ImgType],
                            (UINT8 *)&(ptBootInfo->tHeader),
                            BL_IMG_HEADER_SIZE);

        DEBUGMSG(MSGINFO, "  > CMRT_BOOT_KEY_INFO\n", NULL);
        DEBUGMSG(MSGINFO, "    -. KEYSPLIT_NUM(0x%X), DIVERSIFY_PATH(0x%08X)\n", ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg, ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH);
        DEBUGMSG(MSGINFO, "  > CMRT_BOOT_RT640_SECURE_IMG_INFO\n", NULL);
        DEBUGMSG(MSGINFO, "    -. OS Offset(0x%X),          OS Size(%d)(0x%X)\n", ptBootInfo->tHeader.tBootSec.mOsOffset, ptBootInfo->tHeader.tBootSec.mOsSize, ptBootInfo->tHeader.tBootSec.mOsSize);
        DEBUGMSG(MSGINFO, "    -. SecureBoot Offset(0x%X), SecureBoot Size(%d)(0x%X)\n", ptBootInfo->tHeader.tBootSec.mSecureBootOffset, ptBootInfo->tHeader.tBootSec.mSecureBootSize, ptBootInfo->tHeader.tBootSec.mSecureBootSize);
/* PRQA S 2880, 2992, 2996 ++ */ /* This code operate to normal. HelixQAC doesn't work normal operation. */
        if(ptBootInfo->tHeader.mSignature == BL_IMG_SIGNATURE_ID)
        {
            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);
            Ret = NC_SUCCESS;
            break;
        }
/* PRQA S 2880, 2992, 2996 -- */
#ifdef DEBUG_ENABLE_
        else
        {
            UINT32 cnt;
            UINT8 *data = (UINT8 *)&(ptBootInfo->tHeader);

            DEBUGMSG(MSGERR, " > tHeader FAIL :[", NULL);
            for(cnt=0; cnt<BL_IMG_HEADER_SIZE; cnt++)
            {
                DEBUGMSG(MSGINFO, "%02x ", data[cnt]);
            }
            DEBUGMSG(MSGERR, "] \n", NULL);
        }
#endif
    }

    return Ret;
}


/**
* @desc
    Change the SPI Control mode value of DBG_BOOT_SUMMARY_REG
* @param    UINT32  delCtrlMode    Mode you want to delete value
* @param    UINT32  setCtrlMode  Mode you want to add value
* @return   void
* @design
    IF  I found the right bitrate.  THEN
        Set an appropriate rate for each Input Bitrate.
    ENDIF
    Return Bitrate
*/
static void NC_SF_ModifyDebugSummarySPIMode(UINT32 delCtrlMode, UINT32 setCtrlMode)
{
    CLEAR_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SF_CTRL_MODE, delCtrlMode);
    SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SF_CTRL_MODE, setCtrlMode);
}


/**
* @desc
    Set an appropriate rate for each Input Bitrate.
* @param    UINT32  BitRate     Bitrate value
* @return   UINT32  Bitrate value
* @design
    IF  I found the right bitrate.  THEN
        Set an appropriate rate for each Input Bitrate.
    ENDIF
    Return Bitrate
*/
static UINT32 NC_SF_SetTargetBitrate(UINT32 BitRate)
{
    UINT32 setBitRate;
    
    /* if(BitRate > (100U*MHZ))            { setBitRate =  (100U*MHZ); } */
    /* else */ if(BitRate > (50U*MHZ))        { setBitRate =  (50U*MHZ); }
    else if(BitRate > (45U*MHZ))              { setBitRate =  (45U*MHZ); }
    else if(BitRate > (40U*MHZ))              { setBitRate =  (40U*MHZ); }
    else if(BitRate > (35U*MHZ))              { setBitRate =  (35U*MHZ); }
    else if(BitRate > (30U*MHZ))              { setBitRate =  (30U*MHZ); }
    else if(BitRate > (25U*MHZ))              { setBitRate =  (25U*MHZ); }
    else if(BitRate > (20U*MHZ))              { setBitRate =  (20U*MHZ); }
    else if(BitRate > (15U*MHZ))              { setBitRate =  (15U*MHZ); }
    else if(BitRate > (10U*MHZ))              { setBitRate =  (10U*MHZ); }
    else if(BitRate > (5U*MHZ))               { setBitRate =  ( 5U*MHZ); }
    else if(BitRate > (1U*MHZ))               { setBitRate =  ( 1U*MHZ); }
    else if(BitRate > (500U*KHZ))             { setBitRate =  (  500U*KHZ); }
    else if(BitRate > (100U*KHZ))             { setBitRate =  (  100U*KHZ); }
    else                                      { setBitRate = 0U; }

    return setBitRate;
}



/**
* @desc
    Set target divider value.
* @param    UINT32  BitRate     BitRate value
* @param    UINT32  RefClk      Reference value
* @return   UINT32
* @design
    targetDivider = Reference/BitRate
    IF  Check the value of targetDivider.   THEN
        Set the value of targetDivider.
    ENDIF
    Return  targetDivider
*/
static UINT32 NC_SF_SetTargetDivider(UINT32 BitRate, UINT32 RefClk)
{
    UINT32 targetDivider;
    UINT32 changeBitRate;

    targetDivider = RefClk / BitRate;

    if((targetDivider % 2U) == 1U) {
        targetDivider += 1U;
    } 

    changeBitRate = RefClk / targetDivider;

    if(changeBitRate > BitRate) {
        targetDivider += 2U;
    }

    while(1)
    {
        changeBitRate = RefClk / targetDivider;
        if(((changeBitRate % 1000U) == 0U) || (changeBitRate < (100U * KHZ))) {
            break;
        } else {
            targetDivider += 2U;
        }
    }

    return targetDivider;
}



/**
* @desc
    Check clock divider value.
* @param    tBOOT_INFO*     ptBootInfo  Boot Information Parameter
* @return   UINT32
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;            Boot Image header info
        tBOOT_IMG   tImage;             Boot Image info
        tBOOT_STRAP tStrap;             Boot strap info
        tBOOT_CLK   tClock;             Boot clock info
        tBOOT_CMRT  tCMRT;              Boot CMRT info
    } tBOOT_INFO;
* @design
    IF  Matches with mQspiClockDiv value.   THEN
        Div = Divider value.
    ENDIF
    Return Div
*/
static UINT32 NC_SF_CheckClockDiv(const tBOOT_INFO *ptBootInfo)
{
    UINT32 divider;

    switch(ptBootInfo->tImage.mQspiClockDiv)
    {
        case NC_BOOT_SFLASH_CLOCK_DIV_HIGH:
            divider = QSPI_DIV_HIGH;
            break;
        case NC_BOOT_SFLASH_CLOCK_DIV_MID:
            divider = QSPI_DIV_MID;
            break;
        case NC_BOOT_SFLASH_CLOCK_DIV_LOW:
        default:
            divider = QSPI_DIV_LOW_DEFAULT;
            break;
    }

    #ifdef FPGA_MODE_
    divider = 2;
    #endif

    return divider;
}



/**
* @desc
    Check the SF bitrate.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
    Ret = NC_FAILURE

    DO WHILE    No valid Bitrate found.
        IF  It succeeded in reading the header data.    THEN
            Read device ID.
            Ret = NC_SUCCESS
            Exit Do
        ELSE
            Set the Bitrate to the next value.
            IF  This is the last Bitrate value. THEN
                Exit Do
            ENDIF
        ENDIF
    LOOP

    IF  Ret == NC_SUCCESS   THEN
        IF  Header data check was successful.   THEN
            Ret = NC_SUCCESs
            Update the SPI colck value.
        ELSE
            Ret = NC_FAILURE
        ENDIF
    ENDIF

    Return Ret
*/
static NC_ERROR NC_SF_CheckSPIBitRate(tBOOT_INFO *ptBootInfo, tBOOT_STATUS* ptBootStatus)
{
    NC_ERROR Ret;
    UINT32 BitRate;
    UINT32 Divider;
    UINT32 Loop_Exit = FALSE;
    
    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_CHECK_CLOCK_IN, ptBootStatus);

    Divider = NC_SF_CheckClockDiv(ptBootInfo);
    
    BitRate = (ptBootInfo->tClock.mSPI/Divider);

    while(1)
    {
        Ret = NC_SF_GetHeader(ptBootInfo);
        if(Ret == NC_SUCCESS)
        {
#ifdef DEBUG_ENABLE_
            /* Display Spi-Flash ID */
            UINT8 rRDID[3];

            /* ID Read */
            NC_SF_ReadID(rRDID);

            DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
            DEBUGMSG(MSGINFO, "  > Spi-Flash Information\n", NULL);
            DEBUGMSG(MSGINFO, "    -. Manufacturer ID : 0x%02X\n", rRDID[0]);
            DEBUGMSG(MSGINFO, "    -. Memory type     : 0x%02X\n", rRDID[1]);
            DEBUGMSG(MSGINFO, "    -. Memory density  : 0x%02X\n", rRDID[2]);
#endif
            ptBootInfo->tClock.mSPIDiv = ptBootInfo->tClock.mSPI / BitRate;
            Loop_Exit = TRUE;
        }
        else
        {
            /* SPI-BitRate Down */
            BitRate = NC_SF_SetTargetBitrate(BitRate);
            if(BitRate == 0U) {
                ptBootInfo->tClock.mSPIDiv = 0;
                Loop_Exit = TRUE;
            }
            
            if(Loop_Exit == FALSE)
            {
                /* Update BitRate */
                NC_SPI_SetBitRate(&BitRate, ptBootInfo->tClock.mSPI);

                /* Debug - Update Retry Count */
                NC_SM_SetRETRY_Count(E_SPI_CTRL_SPI);
            }
        }

        if(Loop_Exit == TRUE)
        {
            break;
        }
    }

    ptBootStatus->mSF_CheckSCLKRes = BitRate;
    ptBootStatus->mBackupRes = ptBootInfo->tImage.mImg_Type;
    SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_USED_IMG_SFLASH_ID, ptBootInfo->tImage.mImg_Type);

    if(Ret == NC_SUCCESS)
    {
        /* Check  - Boot Header */
        Ret = NC_CheckHeader(ptBootInfo);
        if(Ret == NC_SUCCESS)
        {
            /* Update Last SPI-Clock */
            ptBootInfo->tClock.mSPI = BitRate;
        }
        else
        {
            if(ptBootInfo->tImage.mImg_Type == E_IMG_NORMAL)
            {
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FAULT_NR_IHDR);
                NC_MPU_LeaveSafetyGate();
            }
            else
            {
                NC_MPU_EnterSafetyGate();
                NC_SE_NotifyFailure(FAULT_BK_IHDR);
                NC_MPU_LeaveSafetyGate();
            }
        }
    }
    else
    {
        ptBootStatus->mHeaderReadRes |= FAIL_SF_HDR_READ;
        if(ptBootInfo->tImage.mImg_Type == E_IMG_NORMAL)
        {
            NC_MPU_EnterSafetyGate();
            NC_SE_SetFaultInfo(FAULT_NR_RHDR);
            NC_MPU_LeaveSafetyGate();
        }
        else
        {
            NC_MPU_EnterSafetyGate();
            NC_SE_NotifyFailure(FAULT_BK_RHDR);
            NC_MPU_LeaveSafetyGate();
        }
    }

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_CHECK_CLOCK_OUT, ptBootStatus);

    return Ret;
}



/**
* @desc
    Check NC_QSPI bitrate.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
        UINT32      mBackupRes;              The index of the FW binary in use.
        UINT32      mOtpRes;                 OTP read result success or fail
        UINT32      mSecureRunRes;           Secure Run result success or fail
        UINT32      mSafetyModeRes;          Safety Mode init success or fail
        UINT32      mHeaderReadRes;          FW Header load success or fail
        UINT32      mCtrlMode;               SPI Ctrl Mode
        UINT32      mSF_CheckSCLKRes;        CheckSCLK Fail
        UINT32      mSF_FailRes;             SF Fail
        UINT32      mEMMC_FailRes;           eMMC Boot Fail
        UINT32      mSD_FailRes;             SD Boot Fail
        UINT32      mUART_FailRes;           UART Boot Fail
        UINT32      mUSB_FailRes;            USB Boot Fail
        UINT32      mBootDone_Res;           Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO* ptHandleBoot;
    } tBOOT_STATUS;
* @design
    Ret = NC_FAILURE
    DO WHILE    Divider value is not 0  THEN
        Get QSPI Bitrate value.
        IF  QSPI Bitrate value less than 100KHz THEN
            Exit Do
        ENDIF

        IF  Signature ID of header is valid.    THEN
            Read data and check if header data is valid.

            IF  Header data is valid    THEN
                Ret = NC_SUCCESS
                Exit Do
            ELSE
                Output Debugging message.
                Increase the Divider value to 2 for lower the bitrate of QSPI
            ENDIF
        ENDIF
    LOOP
    Return Ret
*/
/* cherry pick ... commit hash[6a0a997]y : Fixed an error that prints a wrong qspi frequency */
static NC_ERROR NC_SF_CheckQSPIBitRate(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR Ret = NC_FAILURE;
    UINT32 mCtrlMode = E_SF_QSPI_MODE;
    UINT32 Divider;
    UINT32 BitRate;
    UINT32 BitRateCheck_Flag = 0U;
    UINT32 ChangeTargetBitRate;
    UINT32 RefClock;
    /* Chek DMA Mode */
    if( (ptBootInfo->tImage.mCtrlMode == E_SF_SPI_DEFAULT) ||
        (ptBootInfo->tImage.mCtrlMode == E_SF_DMA_QSPI_MODE) )
    {
        mCtrlMode = E_SF_DMA_QSPI_MODE;
    }

    Divider = NC_SF_CheckClockDiv(ptBootInfo);
    RefClock = ptBootInfo->tClock.mQSPI;
#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > QSPI check\n", NULL);
    DEBUGMSG(MSGINFO, "    -. mCtrlMode  : %d\n", mCtrlMode);
    DEBUGMSG(MSGINFO, "    -. mQSPI  : %d\n", RefClock);
    DEBUGMSG(MSGINFO, "    -. S_Clk_Div  : %d\n", Divider);
#endif

    ptBootStatus->mCtrlMode = mCtrlMode;
    SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SF_CTRL_MODE, mCtrlMode);

    while(1)
    {
        if( (Divider != 0U) && (BitRateCheck_Flag == 0U) )
        {
            /* Set QSPI Default Bitrate */
            BitRate = NC_QSPI_SetBitRate(Divider, RefClock);
/*
            If the bitrate does not fall in MHz, calculate the value again.
            while(BitRate % (1*MHZ)) {
                Divider += 2;
                BitRate = (ptBootInfo->tClock.mQSPI/Divider);
            }
            DEBUGMSG(MSGERR, "    -. ???DIV  : %d\n", Divider);
            */
            ptBootStatus->mSF_CheckSCLKRes = BitRate;
            if(BitRate < (100U * KHZ))
            {
                BitRateCheck_Flag = 1U;/* break; */
            }
            else
            {
                /* Check Noraml - Finds the header identified by the SPI. */
                if(ptBootInfo->tHeader.mSignature == BL_IMG_SIGNATURE_ID)
                {
                    NC_SF_ReadData(mCtrlMode,
                                    ptBootInfo->tImage.mFlashAddr[ptBootInfo->tImage.mImg_Type],
                                    (UINT8 *)(ptBootInfo->tImage.mTempBuff),
                                    BL_IMG_HEADER_SIZE);
                    /* Compare SPI-Read Header vs QSPI-Read Hader */
                    Ret = NC_Compare((UINT8 *)&(ptBootInfo->tHeader), (UINT8 *)(ptBootInfo->tImage.mTempBuff), BL_IMG_HEADER_SIZE);

                    if(Ret == NC_SUCCESS)
                    {
#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "    -. E_Clk_Div  : %d\n", Divider);
#endif
                        ptBootInfo->tClock.mQSPI = RefClock / Divider;
                        ptBootInfo->tClock.mQSPIDiv = Divider;
                        Divider = 0U;
                        /* break; */

                        /* Set QSPI Mode */
                        ptBootInfo->tImage.mCtrlMode = mCtrlMode;
                    }
                    else
                    {
        #ifdef DEBUG_ENABLE_
                        UINT32 cnt;
                        UINT8 *data = (UINT8 *)(ptBootInfo->tImage.mTempBuff);

                        DEBUGMSG(MSGERR, " > tHeader FAIL :[", NULL);
                        for(cnt=0;cnt<BL_IMG_HEADER_SIZE;cnt++)
                        {
                            DEBUGMSG(MSGINFO, "%02x ", data[cnt]);
                        }
                        DEBUGMSG(MSGERR, "] \n", NULL);
        #endif

                        /* QSPI-BitRate Down */
                        ChangeTargetBitRate = NC_SF_SetTargetBitrate(BitRate);
                        Divider = NC_SF_SetTargetDivider(ChangeTargetBitRate, RefClock);
                        DEBUGMSG(MSGINFO, "    -. Change_Div  : %d\n", Divider);
                        /* Debug - Update Retry Count */
                        NC_SM_SetRETRY_Count(E_SPI_CTRL_QSPI);
                    }
                }
                else
                {
                    BitRateCheck_Flag = 1U;/* break; */
                }
            }
        }
        else
        {
            break;
        }
    }

    if(Ret == NC_FAILURE)
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_QSPI_INIT, (UINT32)TRUE);
    }

    return Ret;
}



/**
* @desc
    Read boot image data.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
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
* @design
    IF  Storage type is Secure Boot Key.    THEN
        The offset is Header Size * 3.
    ELSE
        The offset is Header Size.
    ENDIf

    IF  Data Read is successful.    THEN
        Ret = NC_SUCCESS
        IF  Checksum check failed.  THEN
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SF_GetImage(const tBOOT_INFO *ptBootInfo)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TotalLength;
    UINT32 CheckSum;

    /* Quad-SPI 64bit(8Byte) Align */
    TotalLength = ALIGN(ptBootInfo->tHeader.mLength, 0x8U);

    /* FW Image Data Read */
    NC_SF_ReadData(ptBootInfo->tImage.mCtrlMode,
                            ptBootInfo->tImage.mFlashAddr[ptBootInfo->tImage.mImg_Type] + BL_IMG_HEADER_SIZE,
                            (UINT8 *)(ptBootInfo->tImage.mDestAddr),
                            TotalLength);

    /* Confirm FW loading success */
    CheckSum = NC_Checksum((UINT32*)(ptBootInfo->tImage.mDestAddr), (ptBootInfo->tHeader.mLength/4U));
    if(ptBootInfo->tHeader.mCheckSum != CheckSum)
    {
        Ret = NC_FAILURE;
    }
    
#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > Image Loading - 0x%08X, [CtrlMode:%d, ImgType:%d]\n",  ptBootInfo->tImage.mDestAddr, ptBootInfo->tImage.mCtrlMode, ptBootInfo->tImage.mImg_Type);
    DEBUGMSG(MSGINFO, "    -. CtrlMode : 1:SPI,2:QSPI,3:DMA_SPI,4:DMA_QSPI\n", NULL);
    if(ptBootInfo->tHeader.mCheckSum != CheckSum)
    {
        DEBUGMSG(MSGERR, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
        Ret = NC_FAILURE;
    }
    else
    {
        DEBUGMSG(MSGINFO, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
    }
#endif

    return Ret;
}



/**
* @desc
    Initialize for use of SF IP.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
        UINT32      mBackupRes;              The index of the FW binary in use.
        UINT32      mOtpRes;                 OTP read result success or fail
        UINT32      mSecureRunRes;           Secure Run result success or fail
        UINT32      mSafetyModeRes;          Safety Mode init success or fail
        UINT32      mHeaderReadRes;          FW Header load success or fail
        UINT32      mCtrlMode;               SPI Ctrl Mode
        UINT32      mSF_CheckSCLKRes;        CheckSCLK Fail
        UINT32      mSF_FailRes;             SF Fail
        UINT32      mEMMC_FailRes;           eMMC Boot Fail
        UINT32      mSD_FailRes;             SD Boot Fail
        UINT32      mUART_FailRes;           UART Boot Fail
        UINT32      mUSB_FailRes;            USB Boot Fail
        UINT32      mBootDone_Res;           Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO* ptHandleBoot;
    } tBOOT_STATUS;
* @design
    IF  Valid Bitrate retrieval is successful.  THEN
        Ret = NC_SUCCESS
        IF  QSPI mode is enabled.   THEN
            Disable Single mode and activate Quad mod.
            If Quad mode activation fails, it returns to single mode.
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SF_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS* ptBootStatus)
{
    NC_ERROR  Ret;
    INT32  TmpRet;
    UINT32 Divider;
    UINT8  rRDID[3] = {0xA5, 0x5A, 0xC3};        /* b'1010_0101, b'0101_1010, b'1100_0011 */

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_INIT_IN, ptBootStatus);

    Divider = NC_SF_CheckClockDiv(ptBootInfo);

    /* Init sFlash Inferface : Default SPI Mode */
    NC_SF_Init((UINT32)(ptBootInfo->tClock.mSPI/Divider), ptBootInfo->tClock.mSPI);

    /* Check SPI-BitRate */
    Ret = NC_SF_CheckSPIBitRate(ptBootInfo, ptBootStatus);
    
        /* QSPI mode */
    if( (ptBootInfo->tImage.mCtrlMode == E_SF_SPI_DEFAULT) ||
        (ptBootInfo->tImage.mCtrlMode == E_SF_QSPI_MODE) ||
        (ptBootInfo->tImage.mCtrlMode == E_SF_DMA_QSPI_MODE) ) 
    {
        /* QSPI Support Check and Set QSPI Mode */
        TmpRet = NC_SF_EnableDeviceQuadMode(rRDID, ptBootInfo->tImage.mFlashType);

        /* Support QSPI Mode */
        if(TmpRet == NC_SUCCESS) 
        {
            /* DeInit sFlash Inferface : SPI Mode */
            NC_SF_DeInit();

            /* Init sFlash Inferface : QSPI Mode */
            NC_QSPI_Init((UINT32)(ptBootInfo->tClock.mQSPI/Divider), ptBootInfo->tClock.mQSPI, ptBootInfo->tImage.mQspiDummyCycle);

            /* Check QSPI-BitRate */
            TmpRet = NC_SF_CheckQSPIBitRate(ptBootInfo, ptBootStatus);
        }

        /* Not Supported QSPI/DMA */
        if(TmpRet == NC_FAILURE)
        { 
            if((ptBootInfo->tImage.mCtrlMode == E_SF_SPI_DEFAULT) ||
                (ptBootInfo->tImage.mCtrlMode == E_SF_DMA_QSPI_MODE) )
            {
                NC_SF_ModifyDebugSummarySPIMode(ptBootInfo->tImage.mCtrlMode, E_SF_DMA_SPI_MODE);
                ptBootInfo->tImage.mCtrlMode = E_SF_DMA_SPI_MODE;
                NC_SF_Init(ptBootInfo->tClock.mSPI, (ptBootInfo->tClock.mSPI * ptBootInfo->tClock.mSPIDiv));
            }
        }
    }
    else
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SF_CTRL_MODE, ptBootInfo->tImage.mCtrlMode);
    }


#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > Serial Flash [CtrlMode:%d],[CLK_INV:%d]\n", ptBootInfo->tImage.mCtrlMode,ptBootInfo->tImage.mCLK_INV);
    DEBUGMSG(MSGINFO, "    -. CtrlMode : 1:SPI,2:QSPI,3:DMA_SPI,4:DMA_QSPI\n", NULL);
    DEBUGMSG(MSGINFO, "    -. CLK_INV  : 0:SPI_SPH_LOW, 1:SPI_SPH_HIGH(default)\n", NULL);
    DEBUGMSG(MSGINFO, "    -. SPI  : %8d Hz\n", ptBootInfo->tClock.mSPI);
    DEBUGMSG(MSGINFO, "    -. QSPI : %8d Hz\n", ptBootInfo->tClock.mQSPI);
    DEBUGMSG(MSGINFO, "    -. INFO : 0x%02X,0x%02X,0x%02X\n", rRDID[0], rRDID[1], rRDID[2]);
#endif

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_INIT_OUT, ptBootStatus);

    return Ret;
}



/**
* @desc
    Clear retry mask.
* @param    UINT32          CtrlMode        Control mode value
* @param    UINT32          ImgType         Img Type value
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
* @return   void
* @design
    IF  CtrlMode and ImgType match.     THEN
        Clear the matching retry mask.
    ENDIF
*/
static void NC_SF_ClearCtrlModeRetryMask(UINT32 CtrlMode, UINT32 ImgType, tBOOT_STATUS *ptBootStatus)
{
#define CLEAR(R, V)                     ((R) &= ~(V))
    /* failed case bit clear */
    if((CtrlMode == E_SF_SPI_MODE) && (ImgType == E_IMG_NORMAL))            {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_NORMAL_SPI_RETRY_MASK);         }
    else if((CtrlMode == E_SF_SPI_MODE) && (ImgType == E_IMG_BACKUP))       {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_BACKUP_SPI_RETRY_MASK);         }
    else if((CtrlMode == E_SF_QSPI_MODE) && (ImgType == E_IMG_NORMAL))      {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_NORMAL_QSPI_RETRY_MASK);        }
    else if((CtrlMode == E_SF_QSPI_MODE) && (ImgType == E_IMG_BACKUP))      {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_BACKUP_QSPI_RETRY_MASK);        }
    else if((CtrlMode == E_SF_DMA_SPI_MODE) && (ImgType == E_IMG_NORMAL))   {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_NORMAL_DMA_SPI_RETRY_MASK);     }
    else if((CtrlMode == E_SF_DMA_SPI_MODE) && (ImgType == E_IMG_BACKUP))   {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_BACKUP_DMA_SPI_RETRY_MASK);     }
    else if((CtrlMode == E_SF_DMA_QSPI_MODE) && (ImgType == E_IMG_NORMAL))  {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_NORMAL_DMA_QSPI_RETRY_MASK);    }
    else if((CtrlMode == E_SF_DMA_QSPI_MODE) && (ImgType == E_IMG_BACKUP))  {     CLEAR(ptBootStatus->mSF_ImgLoadRetryType, NC_SF_BACKUP_DMA_QSPI_RETRY_MASK);    }
    else                                                                          {                                  /* DO NOTHING */                                   }
}



/**
* @desc
    Change SPI mode.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
    Set the Retry Mask according to the operation mode and operation image.
    See the mSF_ImgLoadFailRes declaration for information about the mode and image type corresponding to each bitmask.
    Change SPI mode.
*/
static void NC_SF_ChangeCtrlModeAndImgType(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus) 
{
    UINT32 CurCtrlMode;
    UINT32 CurImgType;
    INT32 i;

    CurCtrlMode = ptBootInfo->tImage.mCtrlMode;
    CurImgType = ptBootInfo->tImage.mImg_Type;

    NC_SF_ClearCtrlModeRetryMask(CurCtrlMode, CurImgType, ptBootStatus);

    /* See the mSF_ImgLoadFailRes declaration for information about the mode and image type corresponding to each bitmask */ 
    for(i = (INT32)((E_SF_CTRL_MODE_MAX * E_IMG_TYPE_MAX) - 1U); i >= 0; i--) {
        if(CHECK_BITWISE((UINT32)i, ptBootStatus->mSF_ImgLoadRetryType) == TRUE) {
            if(0 < (i % 2)) {
                CurImgType = E_IMG_NORMAL;
            } else {
                CurImgType = E_IMG_BACKUP;
            }
            CurCtrlMode = (((UINT32)(i)) / 2U) + 1U;
            break;
        }
    }

    if((CurCtrlMode == E_SF_QSPI_MODE) || (CurCtrlMode == E_SF_DMA_QSPI_MODE)) 
    {
        if(CurCtrlMode != ptBootInfo->tImage.mCtrlMode) 
        {
            NC_QSPI_Init(ptBootInfo->tClock.mQSPI, (ptBootInfo->tClock.mQSPI * ptBootInfo->tClock.mQSPIDiv), ptBootInfo->tImage.mQspiDummyCycle);
        }
    }
    else if((CurCtrlMode == E_SF_SPI_MODE) || (CurCtrlMode == E_SF_DMA_SPI_MODE))
    {
        if(CurCtrlMode != ptBootInfo->tImage.mCtrlMode)
        {
            NC_SF_Init(ptBootInfo->tClock.mSPI, (ptBootInfo->tClock.mSPI * ptBootInfo->tClock.mSPIDiv));
        }
    }
    else {  /* DO NOTHING */  }

    ptBootInfo->tImage.mCtrlMode = CurCtrlMode;
    ptBootInfo->tImage.mImg_Type = CurImgType;
}



/**
* @desc
    Check normal image faule.
* @param    UINT32  RetryType   Retry Type value
* @param    UINT32  CtrlMode    Control Mode value
* @return   BOOL    TREU or FALSE
* @design
    Ret
    IF  The value matches CtrlMode.     THEN
        Mask = Matching Retry Mask value
    ENDIF

    IF  RetryType&Mask==FALSE   THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_SF_CheckNormalImageFault(UINT32 RetryType, UINT32 CtrlMode)
{
    BOOL Ret;
    UINT32 Mask;
    
    switch(CtrlMode)
    {
        case E_SF_SPI_MODE:
            Mask = NC_SF_NORMAL_SPI_RETRY_MASK;
            break;
        case E_SF_QSPI_MODE:
            Mask = NC_SF_NORMAL_QSPI_RETRY_MASK;
            break;
        case E_SF_DMA_SPI_MODE:
            Mask = NC_SF_NORMAL_DMA_SPI_RETRY_MASK;
            break;
        case E_SF_DMA_QSPI_MODE:
            Mask = NC_SF_NORMAL_DMA_QSPI_RETRY_MASK;
            break;
        default:
            Mask = NC_SF_NORMAL_SPI_RETRY_MASK;
            break;
    }

    if((RetryType & Mask) == FALSE) {
        Ret = TRUE;
    } else {
        Ret = FALSE;
    }

    return Ret;
}



/**
* @desc
    Record the boot results of both normal and backup images based on boot status.
* @param    NC_ERROR        Ret             Boot result
* @param    UINT32          OrgCtrlMode     .
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
* @return   void
* @struct
    typedef struct
    {
        UINT32      mBackupRes;              The index of the FW binary in use.
        UINT32      mOtpRes;                 OTP read result success or fail
        UINT32      mSecureRunRes;           Secure Run result success or fail
        UINT32      mSafetyModeRes;          Safety Mode init success or fail
        UINT32      mHeaderReadRes;          FW Header load success or fail
        UINT32      mCtrlMode;               SPI Ctrl Mode
        UINT32      mSF_CheckSCLKRes;        CheckSCLK Fail
        UINT32      mSF_FailRes;             SF Fail
        UINT32      mEMMC_FailRes;           eMMC Boot Fail
        UINT32      mSD_FailRes;             SD Boot Fail
        UINT32      mUART_FailRes;           UART Boot Fail
        UINT32      mUSB_FailRes;            USB Boot Fail
        UINT32      mBootDone_Res;           Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO* ptHandleBoot;
    } tBOOT_STATUS;
* @design
    IF  Ret == NC_SUCCESS   THEN
        There is a mode which was configured at the first, but if that mode's normal image failed and its backup image was loaded, it would be considered a fault.
    ELSE
        If both the normal and backup image were found broken, set FAULT_NR_SF and FAULT_BK_SF together.
    ENDIF
*/
#if 1
static void NC_SF_RecordFaults(NC_ERROR Ret, UINT32 OrgCtrlMode, tBOOT_STATUS* ptBootStatus)
{
    BOOL ResultNormalFault = FALSE;

    if(Ret == NC_SUCCESS)
    {
        /* There is a mode which was configured at the first, but if that mode's normal image failed and its backup image was loaded, it would be considered a fault. */
        if(ptBootStatus->mBootImgType == E_IMG_BACKUP) {
            ResultNormalFault = NC_SF_CheckNormalImageFault(ptBootStatus->mSF_ImgLoadRetryType, OrgCtrlMode);
        }

        if(ResultNormalFault == TRUE) {
            NC_MPU_EnterSafetyGate();
            NC_SE_SetFaultInfo(FAULT_NR_SF);
            NC_MPU_LeaveSafetyGate();
        }
    } else {
        /* If both the normal and backup image were found broken, set FAULT_NR_SF and FAULT_BK_SF together */
        NC_MPU_EnterSafetyGate();
        NC_SE_SetFaultInfo(FAULT_NR_SF);
        NC_SE_NotifyFailure(FAULT_BK_SF);
        NC_MPU_LeaveSafetyGate();
    }
}
#endif



/**
* @desc
    Loads boot image from serial flash.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
        UINT32      mBackupRes;              The index of the FW binary in use.
        UINT32      mOtpRes;                 OTP read result success or fail
        UINT32      mSecureRunRes;           Secure Run result success or fail
        UINT32      mSafetyModeRes;          Safety Mode init success or fail
        UINT32      mHeaderReadRes;          FW Header load success or fail
        UINT32      mCtrlMode;               SPI Ctrl Mode
        UINT32      mSF_CheckSCLKRes;        CheckSCLK Fail
        UINT32      mSF_FailRes;             SF Fail
        UINT32      mEMMC_FailRes;           eMMC Boot Fail
        UINT32      mSD_FailRes;             SD Boot Fail
        UINT32      mUART_FailRes;           UART Boot Fail
        UINT32      mUSB_FailRes;            USB Boot Fail
        UINT32      mBootDone_Res;           Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO* ptHandleBoot;
    } tBOOT_STATUS;
* @design
    Ret = NC_FAILURE
    IF  Image loading was successful.   THEN
        Ret = NC_SUCCESS
        Update image load success in status value.
    ELSE
        Ret = NC_FAILURE
        Update image load failure in status value.
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SF_ImageLoading(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR Ret;
    BOOL  SetFlag = FALSE;
    UINT32 OrgCtrlMode = ptBootInfo->tImage.mCtrlMode;
    BOOL  BreakFlag = FALSE;

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_IMG_LOAD_IN, ptBootStatus);
    
    /* Boot image loading */
    while(1)
    {
        Ret = NC_SF_GetImage(ptBootInfo);
        
        if(Ret == NC_SUCCESS) 
        {
            NC_SF_ModifyDebugSummarySPIMode(OrgCtrlMode, ptBootInfo->tImage.mCtrlMode);
            ptBootStatus->mBootImgType = ptBootInfo->tImage.mImg_Type;
            ptBootStatus->mSF_FailRes = ((UINT32)NC_SUCCESS);
            BreakFlag = TRUE;
        } 
        else 
        {
            if(SetFlag == FALSE) 
            {
                SetFlag = TRUE;
                switch(OrgCtrlMode)
                {
                    case E_SF_SPI_MODE:     
                        ptBootStatus->mSF_ImgLoadRetryType = (NC_SF_NORMAL_SPI_RETRY_MASK | NC_SF_BACKUP_SPI_RETRY_MASK);
                        break;
                    case E_SF_QSPI_MODE:    
                        ptBootStatus->mSF_ImgLoadRetryType = (NC_SF_NORMAL_SPI_RETRY_MASK | NC_SF_BACKUP_SPI_RETRY_MASK | \
                                                                NC_SF_NORMAL_QSPI_RETRY_MASK | NC_SF_BACKUP_QSPI_RETRY_MASK);
                        break;
                    case E_SF_DMA_SPI_MODE: 
                        ptBootStatus->mSF_ImgLoadRetryType = (NC_SF_NORMAL_SPI_RETRY_MASK | NC_SF_BACKUP_SPI_RETRY_MASK | \
                                                                NC_SF_NORMAL_DMA_SPI_RETRY_MASK | NC_SF_BACKUP_DMA_SPI_RETRY_MASK);
                        break;
                    case E_SF_DMA_QSPI_MODE:
                    case E_SF_SPI_DEFAULT:
                        ptBootStatus->mSF_ImgLoadRetryType = (NC_SF_NORMAL_SPI_RETRY_MASK | NC_SF_BACKUP_SPI_RETRY_MASK | \
                                                                NC_SF_NORMAL_QSPI_RETRY_MASK | NC_SF_BACKUP_QSPI_RETRY_MASK | \
                                                                NC_SF_NORMAL_DMA_SPI_RETRY_MASK | NC_SF_BACKUP_DMA_SPI_RETRY_MASK | \
                                                                NC_SF_NORMAL_DMA_QSPI_RETRY_MASK | NC_SF_BACKUP_DMA_QSPI_RETRY_MASK);
                        break;
                    default:
                        /* DO NOTHING */
                        break;
                }
            }
            
            NC_SF_ChangeCtrlModeAndImgType(ptBootInfo, ptBootStatus);

            if(ptBootStatus->mSF_ImgLoadRetryType == FALSE)
            {
                NC_SF_ModifyDebugSummarySPIMode(OrgCtrlMode, ptBootInfo->tImage.mCtrlMode);
                SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_CRC_IMG, (UINT32)TRUE);
                ptBootStatus->mSF_FailRes |= (UINT32)NC_FAILURE;
                Ret = NC_FAILURE;
                BreakFlag = TRUE;
            }
        }

        if(BreakFlag == TRUE)
        {
            break;
        }
    } 

    /*
    *------------------------------------------------
    * Record the faults of sFlash boot
    *  -. Analyze the boot results of normal and backup images
    *  -. Record the image faults to DBG_FAULT_INFO_REG if any
    *------------------------------------------------
    */

    NC_SF_RecordFaults(Ret, OrgCtrlMode, ptBootStatus);

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SF_IMG_LOAD_OUT, ptBootStatus);

    return Ret;
}



/**
* @desc
    Boot in serial flash mode.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
        UINT32      mBackupRes;              The index of the FW binary in use.
        UINT32      mOtpRes;                 OTP read result success or fail
        UINT32      mSecureRunRes;           Secure Run result success or fail
        UINT32      mSafetyModeRes;          Safety Mode init success or fail
        UINT32      mHeaderReadRes;          FW Header load success or fail
        UINT32      mCtrlMode;               SPI Ctrl Mode
        UINT32      mSF_CheckSCLKRes;        CheckSCLK Fail
        UINT32      mSF_FailRes;             SF Fail
        UINT32      mEMMC_FailRes;           eMMC Boot Fail
        UINT32      mSD_FailRes;             SD Boot Fail
        UINT32      mUART_FailRes;           UART Boot Fail
        UINT32      mUSB_FailRes;            USB Boot Fail
        UINT32      mBootDone_Res;           Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO* ptHandleBoot;
    } tBOOT_STATUS;
* @design
    IF  SF initialize succeeds. THEN
        Ret = NC_SUCCESS
        IF  Image loading was successful.   THEN
            Ret = NC_SUCCESS
        ELSE
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
NC_ERROR NC_Boot_sFlash(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    /* Success or Fail */
    NC_ERROR Ret;
    /*
    *------------------------------------------------
    * Init sFlash Interface
    *  -. SPI, QSPI
    *  -. Get Image Header (Used SPI Interface)
    *------------------------------------------------
    */
    Ret = NC_SF_Initialize(ptBootInfo, ptBootStatus);
    
    NC_Gpio_toggle();

    /*
    *------------------------------------------------
    * If (SPI Init == Success)
    *  -. Check Header
    *  -. Loading FW Image
    *------------------------------------------------
    */
    if(Ret == NC_SUCCESS)
    {
        Ret = NC_SF_ImageLoading(ptBootInfo, ptBootStatus);
    }

    /*
    *------------------------------------------------
    * De-Init sFlash Interface
    *  -. Debug - loading Fail/Ok Save
    *------------------------------------------------
    */
    NC_SF_DeInit();

    NC_Gpio_toggle();

    




    return Ret;
}


/* End Of File */

