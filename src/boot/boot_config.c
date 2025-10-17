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
#include "Drv_ICU.h"
#include "Drv_Uart.h"
#include "Drv_SCU.h"
#include "Drv_OTP.h"
#include "boot_config.h"
#include "Svc_sFlash.h"
#include "seq_monitor.h"

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Check boot header
* @param    tBOOT_INFO*     ptBootInfo      Boot setting parameter information
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
    Result = NC_SUCCESS
    IF Check boot header != OK THEN
        Result = NC_FAILURE
    ELSE
        Result = NC_SUCCESS
    ENDIF
    Return Result
*/
NC_ERROR NC_CheckHeader(const tBOOT_INFO *ptBootInfo)
{
    NC_ERROR Ret = NC_SUCCESS;

    if(    (ptBootInfo->tHeader.mSignature != BL_IMG_SIGNATURE_ID)
        || (ptBootInfo->tHeader.mLength == 0U)
        || (ptBootInfo->tHeader.mLength > APACHE_IRAM_SIZE))
    {
        Ret = NC_FAILURE;
    }

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > Header Info [ImgType: %s]\n", (ptBootInfo->tImage.mImg_Type == E_IMG_NORMAL)?"IMG NORMAL":"IMG BACKUP");
    DEBUGMSG(MSGINFO, "    -. Length    = 0x%08X(%d)\n", ptBootInfo->tHeader.mLength, ptBootInfo->tHeader.mLength);
    DEBUGMSG(MSGINFO, "    -. CheckSum  = 0x%08X\n",     ptBootInfo->tHeader.mCheckSum);
    DEBUGMSG(MSGINFO, "    -. Config_1  = 0x%08X\n",     ptBootInfo->tHeader.mConfig_1.Reg);
    DEBUGMSG(MSGINFO, "    -. Config_2  = 0x%08X\n",     ptBootInfo->tHeader.mConfig_2.Reg);
    DEBUGMSG(MSGINFO, "    -. Signature = 0x%08X\n",     ptBootInfo->tHeader.mSignature);
    DEBUGMSG(MSGINFO, "    -. KEYSPLIT  = 0x%08X\n",     ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg);
    DEBUGMSG(MSGINFO, "    -. DIVERSIFY = 0x%08X\n",     ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH);
    if(Ret == NC_FAILURE)
    {
        DEBUGMSG(MSGERR, "    ==> Image Header Fail [ImgType: %s]\n", (ptBootInfo->tImage.mImg_Type==E_IMG_NORMAL)?"IMG NORMAL":"IMG BACKUP");
    }
#endif

    return Ret;
}



/**
* @desc
    Select between OTP and CPU to set the environment settings.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter.
* @param    tBOOT_CONF1*    pOTPConfig1     OTP Config Parameter.
* @return   BOOL
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
        UINT32 mSPI_CTRL    	SPI Mode
        UINT32 mSECURE_MODE 	Secure Booting Mode
        UINT32 mKEY_STORAGE 	Secure Key Storage
        UINT32 mUSE_KEY_CMRT	Use RT640 Internal OTP Key
        UINT32 mSAFETY_MODE 	Safety Mode(Global)
        UINT32 mSFLASH_TYPE 	sFlash Type
        UINT32 mQSPI_DS     	Driver Strength
        UINT32 mFAULT_RESET 	HW & SW FT : Default(ON)
        UINT32 mQSPI_CLK_DIV	QSPI/SPI Clock Divider
        UINT32 mQSPI_DCYCLE 	QSPI Dummy Cycle
        UINT32 mFW_SIZEUP   	Firmware size up
    } tBOOT_CONF1;
* @design
    Ret
    IF  Config value is valid.  THEN
        Set the Config value saved in OTP or CPU.
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF

    Return Ret
*/
static BOOL NC_IMGConfig_OTP1(tBOOT_INFO *ptBootInfo, tBOOT_CONF1 *pOTPConfig1)
{
    BOOL Ret;

    if( (pOTPConfig1->Reg > 0U) || (ptBootInfo->tHeader.mConfig_1.Reg > 0U) )
    {
        if(pOTPConfig1->Bit.mSPI_CTRL != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mCtrlMode = pOTPConfig1->Bit.mSPI_CTRL;
        }
        else
        {/* Media Apply */
            /* SPI Ctrl Mode
            0x0 : Skip, 0x1 : SPI Mode, 0x2 : QSPI Mode, 0x3 : DMA SPI, 0x4 : DMA QSPI */
            ptBootInfo->tImage.mCtrlMode = ptBootInfo->tHeader.mConfig_1.Bit.mSPI_CTRL;
        }

        if(pOTPConfig1->Bit.mSECURE_MODE != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mSecuMode = pOTPConfig1->Bit.mSECURE_MODE;
        }
        else
        {/* Secure Boot Mode
            0x0 : Skip, 0x1 : NORMAL BOOT, 0x2 : SECURE BOOT */
            ptBootInfo->tImage.mSecuMode = ptBootInfo->tHeader.mConfig_1.Bit.mSECURE_MODE;
        }

        if(pOTPConfig1->Bit.mKEY_STORAGE != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mKeyStorage = pOTPConfig1->Bit.mKEY_STORAGE;
        }
        else
        {/* Secure Boot Root Key Storage
            0x0 Skip, 0x1 OTP, 0x2 FIXED_ROM */
            ptBootInfo->tImage.mKeyStorage = ptBootInfo->tHeader.mConfig_1.Bit.mKEY_STORAGE;
        }

        if(pOTPConfig1->Bit.mUSE_KEY_CMRT != 0U)
        {
            ptBootInfo->tImage.mUseKeyCmrt = pOTPConfig1->Bit.mUSE_KEY_CMRT;
        }
        else
        {/* CMRT internal OTP key
            0x0 : Skip, 0x1 : Use key, 0x2 : Not use key */
            ptBootInfo->tImage.mUseKeyCmrt = ptBootInfo->tHeader.mConfig_1.Bit.mUSE_KEY_CMRT;
        }

        if(pOTPConfig1->Bit.mSAFETY_MODE != 0U)
        {
            ptBootInfo->tImage.mSafetyMode = pOTPConfig1->Bit.mSAFETY_MODE;
        }
        else
        {
            ptBootInfo->tImage.mSafetyMode = ptBootInfo->tHeader.mConfig_1.Bit.mSAFETY_MODE;
        }

#if 1
        if(pOTPConfig1->Bit.mSFLASH_TYPE != 0U)
        {
            ptBootInfo->tImage.mFlashType = pOTPConfig1->Bit.mSFLASH_TYPE;
        }
        else
        {
            ptBootInfo->tImage.mFlashType = ptBootInfo->tHeader.mConfig_1.Bit.mSFLASH_TYPE;
        }

        if(pOTPConfig1->Bit.mQSPI_DS != 0U)
        {
            ptBootInfo->tImage.mDriveStrength = pOTPConfig1->Bit.mQSPI_DS;
        }
        else
        {
            ptBootInfo->tImage.mDriveStrength = ptBootInfo->tHeader.mConfig_1.Bit.mQSPI_DS;
        }
#else
        if(ptBootInfo->tHeader.mConfig_1.Bit.mSFLASH_TYPE != 0U)
        {
            ptBootInfo->tImage.mFlashType = ptBootInfo->tHeader.mConfig_1.Bit.mSFLASH_TYPE;
        }
        else
        {
            ptBootInfo->tImage.mFlashType = pOTPConfig1->Bit.mSFLASH_TYPE;
        }

        if(ptBootInfo->tHeader.mConfig_1.Bit.mQSPI_DS != 0U)
        {
            ptBootInfo->tImage.mDriveStrength = ptBootInfo->tHeader.mConfig_1.Bit.mQSPI_DS;
        }
        else
        {
            ptBootInfo->tImage.mDriveStrength = pOTPConfig1->Bit.mQSPI_DS;
        }
#endif
        if(pOTPConfig1->Bit.mFAULT_RESET != 0U)
        {
            ptBootInfo->tImage.mFaultCpuReset = pOTPConfig1->Bit.mFAULT_RESET;
        }
        else
        {
            ptBootInfo->tImage.mFaultCpuReset = ptBootInfo->tHeader.mConfig_1.Bit.mFAULT_RESET;
        }

        if(pOTPConfig1->Bit.mQSPI_CLK_DIV != 0U)
        {
            ptBootInfo->tImage.mQspiClockDiv = pOTPConfig1->Bit.mQSPI_CLK_DIV;
        }
        else
        {
            ptBootInfo->tImage.mQspiClockDiv = ptBootInfo->tHeader.mConfig_1.Bit.mQSPI_CLK_DIV;
        }

        if(pOTPConfig1->Bit.mQSPI_DCYCLE != 0U)
        {
            ptBootInfo->tImage.mQspiDummyCycle = pOTPConfig1->Bit.mQSPI_DCYCLE;
        }
        else
        {
            ptBootInfo->tImage.mQspiDummyCycle = ptBootInfo->tHeader.mConfig_1.Bit.mQSPI_DCYCLE;
        }

        if(pOTPConfig1->Bit.mFW_SIZEUP != 0U)
        {
            ptBootInfo->tImage.mFlashAddr[E_IMG_BACKUP] = ((IMG_SIZEUP_64KB) * pOTPConfig1->Bit.mFW_SIZEUP) + (BL_IMG_SRC_BACKUP_ADDR);
        }
        else
        {
            ptBootInfo->tImage.mFlashAddr[E_IMG_BACKUP] = ((IMG_SIZEUP_64KB) * ptBootInfo->tHeader.mConfig_1.Bit.mFW_SIZEUP) + (BL_IMG_SRC_BACKUP_ADDR);
        }

    #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
        DEBUGMSG(MSGINFO, "  > IMG Config update\n", NULL);
        DEBUGMSG(MSGINFO, "    -. Header Config_1  : 0x%08X\n", ptBootInfo->tHeader.mConfig_1.Reg);
        DEBUGMSG(MSGINFO, "    -. OTP_1    Config  : 0x%08X\n", pOTPConfig1->Reg);
    #endif
        
        Ret = TRUE;
    } 
    else
    {
        Ret = FALSE;
    }

    return Ret;
}



/**
* @desc
    Select between OTP and CPU to set the environment settings.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter.
* @param    tBOOT_CONF2*    pOTPConfig2     OTP Config Parameter.
* @return   BOOL
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
        UINT32  mSPI_RX_DELAY  		SPI RX Sample Delay
        UINT32  mSPI_CLK_POL_PH		SPI/QSPi Clock Polarity & Phase Config Setting
        UINT32  mUART_BAUDRATE 		UART Baudrate table for Download
        UINT32  mUSB_REF_CLK   		USB Ref Clock Table
	} tBOOT_CONF2;
* @design
    Ret
    IF  Config value is valid.  THEN
        Set the Config value saved in OTP or CPU.
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF

    Return Ret
*/
static BOOL NC_IMGConfig_OTP2(tBOOT_INFO *ptBootInfo, tBOOT_CONF2 *pOTPConfig2)
{
    BOOL Ret;

    if( (pOTPConfig2->Reg > 0U) || (ptBootInfo->tHeader.mConfig_2.Reg > 0U) )
    {
        if(pOTPConfig2->Bit.mSPI_RX_DELAY != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mSpiRxDelay = pOTPConfig2->Bit.mSPI_RX_DELAY;
        }
        else
        {/* Media Apply */
            ptBootInfo->tImage.mSpiRxDelay = ptBootInfo->tHeader.mConfig_2.Bit.mSPI_RX_DELAY;
        }
        gSPI_RX_DELAY = ptBootInfo->tImage.mSpiRxDelay;

        if(pOTPConfig2->Bit.mSPI_CLK_POL_PH != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mSpiClockPolarityPhase = pOTPConfig2->Bit.mSPI_CLK_POL_PH;
        }
        else
        {/* Media Apply */
            ptBootInfo->tImage.mSpiClockPolarityPhase = ptBootInfo->tHeader.mConfig_2.Bit.mSPI_CLK_POL_PH;
        }
        gSPI_CLK_POL_PH = ptBootInfo->tImage.mSpiClockPolarityPhase;

        if(pOTPConfig2->Bit.mUART_BAUDRATE != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mUartBaudrate = pOTPConfig2->Bit.mUART_BAUDRATE;
        }
        else
        {/* Media Apply */
            ptBootInfo->tImage.mUartBaudrate = ptBootInfo->tHeader.mConfig_2.Bit.mUART_BAUDRATE;
        }

        if(pOTPConfig2->Bit.mUSB_REF_CLK != 0U)
        {/* Otp Apply */
            ptBootInfo->tImage.mUsbRefClock = pOTPConfig2->Bit.mUSB_REF_CLK;
        }
        else
        {/* Media Apply */
            ptBootInfo->tImage.mUsbRefClock = ptBootInfo->tHeader.mConfig_2.Bit.mUSB_REF_CLK;
        }

        Ret = TRUE;
    }
    else
    {
        Ret = FALSE;
    }
    
    return Ret;
}



/**
* @desc
    Set boot image configure.
* @param    tBOOT_INFO*     ptBootInfo      Boot setting parameter information
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
* @design
    IF  Image configure set || Image boot configure set     THEN
        Set SPI control mode
        Set secure boot mode
        Set secure boot key storage
        Set CMRT internal OTP key
        Set safety mode
        Set serial flash type
        Set QSPI description
        Set memory fault reset
        Set firmware image size
        Set ICU PAD
    ENDIF
*/
void NC_IMGConfig(tBOOT_INFO *ptBootInfo)
{
    tBOOT_CONF1    mOtpConf_1;
    tBOOT_CONF2    mOtpConf_2;
    tBOOT_PAD_INFO tPad_Info;
    UINT32 i;
    BOOL Ret;

    mOtpConf_1.Reg = NC_GetDBG_OTP_Config(CONFIG_IDX_1);
    mOtpConf_2.Reg = NC_GetDBG_OTP_Config(CONFIG_IDX_2);


    Ret = NC_IMGConfig_OTP1(ptBootInfo, &mOtpConf_1);
    if(Ret == TRUE)
    {
        tPad_Info.mBootDevice = 0U;
        tPad_Info.mCount = 0U;

        for(i=0U; i<14U; i++)
        {
            tPad_Info.mPAD_ID[i] = 0U;
        }

        if(NC_ICU_GetPadInfo(ptBootInfo->tStrap.Bit.mBootMemory, &tPad_Info) == NC_SUCCESS)
        {
            NC_ICU_SetDriveStrength(&tPad_Info, ptBootInfo->tImage.mDriveStrength);
        }
        else
        {
            DEBUGMSG(MSGERR, "Ooops, Invalid Boot Media..\n", NULL);
        }
    }

    Ret = NC_IMGConfig_OTP2(ptBootInfo, &mOtpConf_2);
    if(Ret == TRUE)
    {
        #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "    -. Header Config_2  : 0x%08X\n", ptBootInfo->tHeader.mConfig_2.Reg);
        DEBUGMSG(MSGINFO, "    -. OTP_2    Config  : 0x%08X\n", mOtpConf_2.Reg);
        #endif
    }
/* PRQA S 3332 ++ */
#if FORCE_CONFIG_SPI_CTRL > 0   /* for TEST : Config from default.mk file */
    ptBootInfo->tImage.mCtrlMode = FORCE_CONFIG_SPI_CTRL;
#endif
/* PRQA S 3332 -- */
}



/**
* @desc
    Set default configure.
* @param    tBOOT_INFO*     ptBootInfo      Boot setting parameter information
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
* @design
    Set default configure
*/
static void NC_DefaultConfig(tBOOT_INFO *ptBootInfo)
{
    /*
    * Boot Image Address
    *  -. Set Loading FW Count
    *  -. Set Temp Buffer (Used QSPI or DMA BitRate Check)
    *  -. Set Limit Image Size
    */


    ptBootInfo->tImage.mTempBuff  = BL_TEMP_BUFF_ADDR;

    /* sFlash Address */
    ptBootInfo->tImage.mFlashAddr[E_IMG_NORMAL] = BL_IMG_SRC_NORMAL_ADDR;
    ptBootInfo->tImage.mFlashAddr[E_IMG_BACKUP] = BL_IMG_SRC_BACKUP_ADDR;

    /* SRAM or DDR (destination address to copy FW image) */
    ptBootInfo->tImage.mDestAddr = BL_IMG_DEST_ADDR;

    /* default SPI Mode */
    ptBootInfo->tImage.mCtrlMode = E_SF_SPI_DEFAULT;
    ptBootInfo->tImage.mImg_Type = E_IMG_NORMAL;

    /* default Key Storage */
    ptBootInfo->tImage.mKeyStorage = E_SBOOT_KEY_STORAGE_ROM;

    /* default CMRT internal OTP use */
    ptBootInfo->tImage.mUseKeyCmrt = E_SBOOT_KEY_CMRT_USE_DEFAULT;

    /* default Secure boot */
    ptBootInfo->tImage.mSecuMode = E_SBOOT_NORMAL_MODE;

    /* default Safety mode, safety engine use */
    ptBootInfo->tImage.mSafetyMode = E_SAFETY_MODE_ENABLE;

    /* default fault cpu holding or HW Reset */
    ptBootInfo->tImage.mFaultCpuReset = E_FAULT_BEHAVIOUR_SKIP;
    ptBootInfo->tImage.mCLK_INV        = 0x0U;
    ptBootInfo->tImage.mFlashType      = 0x0U;
    ptBootInfo->tImage.mDriveStrength  = E_QSPI_DS_SKIP;
    ptBootInfo->tImage.mQspiClockDiv   = 0x0U;
    ptBootInfo->tImage.mQspiDummyCycle = 0x0U;
    ptBootInfo->tImage.mSpiRxDelay     = 0x0U;

    /*
    * This code automatically sets baudrate of the UART channels to 19200 [bps] when running under bypass mode 
    * For the other cases, baud rate would be assigned as 115200 [bps]
    */
    if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_BYPASS)
    {
        ptBootInfo->tImage.mUartBaudrate = NC_UART_SET_BAUDRATE_19200;
    }
    else
    {
        ptBootInfo->tImage.mUartBaudrate = NC_UART_SET_BAUDRATE_115200;
    }
    
    ptBootInfo->tImage.mUsbRefClock    = 0x0U;
    ptBootInfo->tImage.mSpiClockPolarityPhase = 0x0U;
}



/**
* @desc
    Boot Configuration.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
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
    Set default configure
    Set strap configure
*/
void NC_BootConfig(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    /* 1. Default config */
    NC_DefaultConfig(ptBootInfo);

    /* 2. strap config */
    NC_SCU_StrapConfig(ptBootInfo, ptBootStatus);

#ifdef OTP_ENABLE_
    /* 4. OTP config ( OTP config is the top priority) */
    NC_OTP_Config(ptBootInfo, ptBootStatus);
#else
    /* 4. OTP config for the case being disabled */
    NC_OTP_Config_WhileDisabled(ptBootStatus);
#endif
}

/* End Of File */

