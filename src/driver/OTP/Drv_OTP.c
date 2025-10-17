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
#include "Drv_OTP.h"
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

#ifndef FPGA_MODE_
#define PRE_SENS_START    (0x1U)
#define PRE_SENS_READY    (0x1U << 1)
#define PRE_SENS_DONE     (0x1U << 2)
#endif


#if defined(OTP_ENABLE_)
    #if defined(FPGA_MODE_) && defined(FPGA_TEST_OTP_ENABLE_)
            /* PRQA S 0303,0306,3218 ++ */
            volatile DRV_A6_OTP2K_REGISTER* const RegA6_OTP = (DRV_A6_OTP2K_REGISTER*) 0x05C24000;
            volatile DRV_A6_OTP32K_REGISTER* const RegA6_OTP32K = (DRV_A6_OTP32K_REGISTER*)0x05C40000;
            /* PRQA S 0303,0306,3218 -- */
    #else
        /* PRQA S 0303,0306,3218 ++ */
        volatile DRV_A6_OTP2K_REGISTER* const RegA6_OTP = (DRV_A6_OTP2K_REGISTER*)APACHE_A6_OTP2K_BASE_ADDR;
        /* PRQA S 1514,3408 ++ */
        volatile DRV_A6_OTP32K_REGISTER*  const RegA6_OTP32K  = (DRV_A6_OTP32K_REGISTER*)APACHE_A6_OTP32K_BASE_ADDR;
        volatile DRV_A6_ANALOG_REGISTER*  const RegA6_ANALOG  = (DRV_A6_ANALOG_REGISTER*)APACHE_A6_ANALOG_BASE_ADDR;
        /* PRQA S 1514,3408 -- */
        /* PRQA S 0303,0306,3218 -- */
    #endif
#endif /* OTP_ENABLE_ */

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/

#ifdef OTP_ENABLE_



/**
* @desc
    Set OTP configuration
* @param    UINT32  Index       OTP configuration Index
* @param    UINT32  OtpConfig   OTP configuration value
* @return   void
* @design
    IF  Index is 1  THEN
        Set OTP_1 configuration
    ELSE
        Set OTP_2 configuration
    ENDIF
*/
static void NC_SetDBG_OTP_Config(UINT32 Index, UINT32 OtpConfig)
{
    if(Index == CONFIG_IDX_1)
    {
        DBG_OTP_1_REG   = OtpConfig;
    }
    else /* CONFIG_IDX_2 */
    {
        DBG_OTP_2_REG   = OtpConfig;
    }
}



/**
* @desc
    Get OTP configuration
* @param    UINT32  Index   OTP configuration Index
* @return   UINT32          OTP configuration value
* @design
    IF  Index is 1  THEN
        Get OTP_1 configuration
    ELSE
        Get OTP_2 configuration
    ENDIF
    Return  OTP configuration value
*/
UINT32 NC_GetDBG_OTP_Config(UINT32 Index)
{
    UINT32 Reg;

    if(Index == CONFIG_IDX_1)
    {
        Reg = DBG_OTP_1_REG;
    }
    else /* CONFIG_IDX_2 */
    {
        Reg = DBG_OTP_2_REG;
    }

    return Reg;
}



/**
* @desc
    Set up the configuration to use OTP IP.
* @param    tBOOT_INFO*     ptBootInfo      boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    boot ststus value
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
    Set boot step and OTP Register.
    IF  config value exists     THEN
        If there is a config value, need to overwrite the value.
    ENDIF
*/
void NC_OTP_Config(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    tBOOT_CONF1  mConfig_01;
    tBOOT_CONF2  mConfig_02;
    UINT32 TimeOutFlag = 0U;

/* PRQA S 2982 ++ */ /* This variable real otp value */
#ifdef FPGA_MODE_
    mConfig_01.Reg = 0U;
    mConfig_02.Reg = 0U;
#endif
/* PRQA S 2982 -- */
    
    NC_SM_SetBOOT_Step(DBG_STP_OTP_CONF_IN, ptBootStatus);
    
#ifndef FPGA_MODE_  /* Sim OR Real Target EVT */
    /* Check Analog block state */    
    while (1)
    {
        if( (RegA6_ANALOG->OTP_PRE_SENSING_STATE.Reg != (PRE_SENS_START | PRE_SENS_READY | PRE_SENS_DONE)) && (TimeOutFlag == 0U) )
        {
            /* Defence Code */
            if(NC_SCU_mTimeOut(1UL) == TRUE)
            {
                TimeOutFlag = 1U;    
                ptBootStatus->mOtpRes = E_TIME_OVER;
                DBG_FAULT_INFO_REG   |= (1UL << FAULT_OTP_TOV);
            }
        }
        else
        {
            break;
        }
    }
    /* Clear */
    (void)NC_SCU_mTimeOut(0UL);

    /* Need to set 0 after initializing done */
    RegA6_ANALOG->OTP_PRE_SENSING_STATE.Reg = 0U;

    /* Pre-reding done */
    RegA6_OTP->OTP_INT_STATUS.Reg    = 0xFFFFFFFFU;
    RegA6_SYS_SCU->ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET = 0x0;
    RegA6_OTP32K->OTP_INT_STATUS.Reg = 0xFFFFFFFFU;

    /* Boot Configuration Read */
    mConfig_01.Reg = (UINT32)RegA6_OTP->BOOT_CFG.Reg;
    mConfig_02.Reg = (UINT32)RegA6_OTP->UDF.Reg;
#endif

#ifdef FORCE_OTP_CONFIG_1  /* for TEST : Config from default,mk file */
    if((UINT32)FORCE_OTP_CONFIG_1 > 0)
    {
        mConfig_01.Reg = (UINT32)FORCE_OTP_CONFIG_1;
    }
    else
    {
        mConfig_01.Reg = 0U;
    }
#endif

#ifdef FORCE_OTP_CONFIG_2
    if((UINT32)FORCE_OTP_CONFIG_2 > 0)
    {
        mConfig_02.Reg = (UINT32)FORCE_OTP_CONFIG_2;
    }
    else
    {
        mConfig_02.Reg = 0U;
    }
#endif

#ifdef FPGA_TEST_OTP_ENABLE_ /* for FPGA TEST : Config from ~.csf file */
    /* Pre-reding done */
    RegA6_OTP->OTP_INT_STATUS.Reg    = 0xFFFFFFFFU;
    RegA6_SYS_SCU->ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET = 0x0;
    RegA6_OTP32K->OTP_INT_STATUS.Reg = 0xFFFFFFFFU;

    /* Boot Configuration Read */
    mConfig_01.Reg = (UINT32)RegA6_OTP->BOOT_CFG.Reg;
    mConfig_02.Reg = (UINT32)RegA6_OTP->UDF.Reg;
#endif

    /* Boot config DEBUG */
    NC_SetDBG_OTP_Config(CONFIG_IDX_1, mConfig_01.Reg);
    NC_SetDBG_OTP_Config(CONFIG_IDX_2, mConfig_02.Reg);

    if(ptBootStatus->mOtpRes != E_TIME_OVER)
    {
        ptBootStatus->mOtpRes = E_SUCCESS;
    }

/* PRQA S 2992, 2996 ++ */ /* This code operate to normal. HelixQAC doesn't work normal operation */
    /* If there is a config value, need to overwrite the value */
    if(mConfig_01.Reg > 0U)
    {
        /* SPI Ctrl Mode
        0x0 : Skip, 0x1 : SPI Mode, 0x2 : QSPI Mode, 0x3 : DMA SPI, 0x4 : DMA QSPI */
        ptBootInfo->tImage.mCtrlMode = mConfig_01.Bit.mSPI_CTRL;

        /* Secure Boot Mode
        0x0 : Skip, 0x1 : NORMAL BOOT, 0x2 : SECURE BOOT */
        ptBootInfo->tImage.mSecuMode = mConfig_01.Bit.mSECURE_MODE;

        /* Secure Boot Root Key Storage
        0x0 Skip, 0x1 OTP, 0x2 FIXED_ROM */
        ptBootInfo->tImage.mKeyStorage = mConfig_01.Bit.mKEY_STORAGE;

        /* CMRT internal OTP key
        0x0 : Skip, 0x1 : Use key, 0x2 : Not use key */
        ptBootInfo->tImage.mUseKeyCmrt = mConfig_01.Bit.mUSE_KEY_CMRT;

        /* Safety Mode
        0x0 Skip, 0x1 DISABLE, 0x2 ENABLE */
        ptBootInfo->tImage.mSafetyMode = mConfig_01.Bit.mSAFETY_MODE;

        ptBootInfo->tImage.mFlashType      = mConfig_01.Bit.mSFLASH_TYPE;
        ptBootInfo->tImage.mDriveStrength  = mConfig_01.Bit.mQSPI_DS;
        ptBootInfo->tImage.mFaultCpuReset  = mConfig_01.Bit.mFAULT_RESET;
        ptBootInfo->tImage.mQspiClockDiv   = mConfig_01.Bit.mQSPI_CLK_DIV;
        ptBootInfo->tImage.mQspiDummyCycle = mConfig_01.Bit.mQSPI_DCYCLE;
        ptBootInfo->tImage.mFlashAddr[E_IMG_BACKUP] += (IMG_SIZEUP_64KB) * mConfig_01.Bit.mFW_SIZEUP;
    }

    if(mConfig_02.Reg > 0U)
    {
        ptBootInfo->tImage.mSpiRxDelay            = mConfig_02.Bit.mSPI_RX_DELAY;
        ptBootInfo->tImage.mSpiClockPolarityPhase = mConfig_02.Bit.mSPI_CLK_POL_PH;
        ptBootInfo->tImage.mUartBaudrate          = mConfig_02.Bit.mUART_BAUDRATE;
        ptBootInfo->tImage.mUsbRefClock           = mConfig_02.Bit.mUSB_REF_CLK;
    }
/* PRQA S 2992, 2996 -- */

    NC_SM_SetBOOT_Step(DBG_STP_OTP_CONF_OUT, ptBootStatus);
}



/**
* @desc
    Get the firmware backup offset.
* @param    void
* @return   UINT32  offset value.
* @design
    offset = 0
    Set boot step and OTP Register.
    IF  Firmware size is not 0  THEN
        offset = firmware backup offset.
    ENDIF
    Return offset
*/
UINT32 NC_Get_Firmware_Backup_Offset(void) 
{
    tBOOT_CONF1  mConfig_01;
    UINT32 offset = 0U;

#ifdef FPGA_MODE_
    mConfig_01.Reg = 0U;
#else
    mConfig_01.Reg = (UINT32)RegA6_OTP->BOOT_CFG.Reg;
#endif
 
#ifdef FORCE_OTP_CONFIG_1  /* for TEST : Config from default,mk file */
    if((UINT32)FORCE_OTP_CONFIG_1 > 0U) 
    {
        mConfig_01.Reg = (UINT32)FORCE_OTP_CONFIG_1;
    } 
    else 
    {
        mConfig_01.Reg = 0U;
    }
#endif

#ifdef FPGA_TEST_OTP_ENABLE_ /* for FPGA TEST : Config from ~.csf file */
    mConfig_01.Reg = (UINT32)RegA6_OTP->BOOT_CFG.Reg;
#endif

    /* Debug Registers are not being used as it is used for a purpose of simple boot */
    if(mConfig_01.Bit.mFW_SIZEUP != 0U) 
    {
        offset = (IMG_SIZEUP_64KB) * mConfig_01.Bit.mFW_SIZEUP;
    }

    return offset;
}
#else



/**
* @desc
    Set OTP Boot Step.
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
* @return   void
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
    Boot setp OTP Config in
    Boot setp OTP Config out
*/
void NC_OTP_Config_WhileDisabled(tBOOT_STATUS *ptBootStatus)
{
    NC_SM_SetBOOT_Step(DBG_STP_OTP_CONF_IN, ptBootStatus);
    NC_SM_SetBOOT_Step(DBG_STP_OTP_CONF_OUT, ptBootStatus);
}

#endif /* OTP_ENABLE_ */
/* End Of File */
