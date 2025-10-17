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
#include "Drv_SCU.h"
#include "Drv_EMMC.h"
#include "Drv_OTP.h"
#include "seq_monitor.h"
#include "MPU.h"
#include "safety_engine.h"

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/


#define FAIL_EMMC_READ               (1U)
#define FAIL_EMMC_CHECKSUM           (2U)

#define EMMC_CTRL_MODE_FIFO          (1U)



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
static NC_ERROR NC_Boot_EMMC_GetHeader(tBOOT_INFO *ptBootInfo)
{
    UINT32 read_buffer [EMMC_SECTOR_SIZE/4U] __attribute__ ((aligned (64))) = {0U,};
    NC_ERROR Ret;
    UINT32 ImgType;
    UINT32 ReadSize;

    ptBootInfo->tHeader.tBootKey.mKEYSPLIT.Reg   = 0U;
    ptBootInfo->tHeader.tBootKey.mDIVERSIFY_PATH = 0U;

    /* 0: E_IMG_NORMAL, 1:E_IMG_BACKUP */
    for(ImgType=E_IMG_NORMAL; ImgType<E_IMG_TYPE_MAX; ImgType++)
    {
        ptBootInfo->tImage.mImg_Type = ImgType;

        if(ImgType == E_IMG_NORMAL)
        {
            /*SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_USED_IMG_EMMC_ID, 0U);*/ /* Normal */
            ReadSize = EMMC_SECTOR_SIZE;
        }
        else
        {
            SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_USED_IMG_EMMC_ID, (UINT32)TRUE); /* Backup */
            #ifdef OTP_ENABLE_
            ReadSize = EMMC_SECTOR_SIZE + BL_IMG_EMMC_DEFAULT_BACKUP_ADDR + NC_Get_Firmware_Backup_Offset();
            #else
            ReadSize = EMMC_SECTOR_SIZE + BL_IMG_EMMC_DEFAULT_BACKUP_ADDR;
            #endif
        }

        /* Read header */
        Ret = NC_EMMC_ReadByADMA2((UINT32)EMMC_READ_TYPE_PRIMARY + ImgType, (const UINT32 *)read_buffer, ReadSize);
        if(Ret == NC_FAILURE)
        {
            SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_EMMC_CTRL_MODE, (UINT32)EMMC_CTRL_MODE_FIFO);

            /* Retry Read header by FIFO mode */
            Ret = NC_EMMC_ReadByFIFO((UINT32)EMMC_READ_TYPE_PRIMARY + ImgType, (UINT32* const)read_buffer, ReadSize);
        }

        if(Ret == NC_SUCCESS)
        {
            /* Copy Image header */
            NC_Memcpy_u08((const UINT8*)read_buffer, (UINT8*)&ptBootInfo->tHeader, BL_IMG_HEADER_SIZE);

            Ret = NC_CheckHeader(ptBootInfo);
        }

        if(Ret == NC_SUCCESS /* && ptBootInfo->tHeader.mSignature == BL_IMG_SIGNATURE_ID */)
        {
            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);
            break;
        }
        else
        {
            Ret = NC_FAILURE;
        }
    }
    return Ret;
}



/**
* @desc
   Initialize eMMC Boot.
* @param    tBOOT_INFO      *ptBootInfo     Boot setting parameter information
* @param    tBOOT_STATUS    *pStatus        Boot Status
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
    IF eMMC initialize == OK THEN
        Read eMMC data on ADMA
        IF Check Boot header == OK THEN
            Ret = NC_SUCCESS
        ELSE
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
 */
static NC_ERROR NC_Boot_EMMC_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus)
{
    NC_ERROR  Ret;

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_INIT_IN, pStatus);
    
    Ret = NC_EMMC_Initialize(ptBootInfo->tClock.mEMMC);
    if(Ret == NC_SUCCESS)
    {
        Ret = NC_Boot_EMMC_GetHeader(ptBootInfo);
    }
    
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_INIT_OUT, pStatus);
    
    return Ret;
}



/**
* @desc
    Deinitialize eMMC Boot.
* @param    tBOOT_STATUS    *pStatus     Boot Status
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
    Deinitialize eMMC
 */
static void NC_Boot_EMMC_DeInitialize(tBOOT_STATUS* pStatus)
{
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_DEINIT_IN, pStatus);
    
    NC_EMMC_DeInit();

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_DEINIT_OUT, pStatus);
}



/**
* @desc
    Get eMMC BootImage.
* @param    tBOOT_INFO      *ptBootInfo     Boot setting parameter information
* @param    tBOOT_STATUS    *pStatus        Boot Status
* @param    UINT32          readType        Read Type Value
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
    IF Secure Boot mode == Enable THEN
        Set eMMC read secure mode
    ELSE
        Set eMMC read header mode
    ENDIF

    IF eMMC GetImage == OK THEN
        IF Check checksum == OK THEN
            Ret = NC_SUCCESS
        ELSE
            Ret = NC_FAILURe
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Retuen Ret
 */
static NC_ERROR NC_Boot_EMMC_GetImage(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus, UINT32 readType)
{
    NC_ERROR  Ret;
    UINT32 CheckSum;
    UINT32 readsize;

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > EMMC Image Info\n", NULL);
    DEBUGMSG(MSGINFO, "    -. Image size   = %d\n", ptBootInfo->tHeader.mLength);
#endif

    /* (void)NC_EMMC_Initialize(ptBootInfo->tClock.mEMMC); */
    /*SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_EMMC_CTRL_MODE, EMMC_CTRL_MODE_ADMA);*/

    if(readType == EMMC_READ_TYPE_PRIMARY)
    {
        /*SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_USED_IMG_EMMC_ID, 0U);*/ /* Normal */
        readsize = ptBootInfo->tHeader.mLength + BL_IMG_HEADER_SIZE;
    }
    else
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_USED_IMG_EMMC_ID, (UINT32)1U); /* Backup */
#ifdef OTP_ENABLE_
        readsize = ptBootInfo->tHeader.mLength + BL_IMG_HEADER_SIZE + BL_IMG_EMMC_DEFAULT_BACKUP_ADDR + NC_Get_Firmware_Backup_Offset();
#else
        readsize = ptBootInfo->tHeader.mLength + BL_IMG_HEADER_SIZE + BL_IMG_EMMC_DEFAULT_BACKUP_ADDR;
#endif
    }

    /* FW Image Data Read */
    Ret = NC_EMMC_ReadByADMA2(readType | EMMC_WITHOUT_HEADER, (UINT32*)ptBootInfo->tImage.mDestAddr, readsize);
    if(Ret == NC_SUCCESS)
    {
        CheckSum = NC_Checksum((UINT32 *)(ptBootInfo->tImage.mDestAddr), (UINT32)(ptBootInfo->tHeader.mLength / 4U));
        if(ptBootInfo->tHeader.mCheckSum != CheckSum)
        {
            Ret = NC_FAILURE;
            pStatus->mEMMC_FailRes |= ((UINT32)FAIL_EMMC_CHECKSUM);
            #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGERR, "Failed to Image Check, ADMA rtype[%s]\n", (readType==EMMC_READ_TYPE_PRIMARY)?"primary":"backup");
            #endif
        }
        #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "ptBootInfo->tImage.mDestAddr : 0x%x\n", ptBootInfo->tImage.mDestAddr);
        DEBUGMSG(MSGINFO, "ptBootInfo->tHeader.mLength  : 0x%x\n", ptBootInfo->tHeader.mLength);
        DEBUGMSG(MSGINFO, "Expected Checksum : 0x%x\n", ptBootInfo->tHeader.mCheckSum);
        DEBUGMSG(MSGINFO, "Actual Checksum   : 0x%x\n", CheckSum);
        #endif
    }

    if(Ret == NC_FAILURE)
    {
#ifdef DEBUG_ENABLE_	
        DEBUGMSG(MSGINFO, "Failed to read Image by ADMA2.. Try to read image by FIFO rtype[%s]\n", (readType==EMMC_READ_TYPE_PRIMARY)?"primary":"backup");
#endif
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_EMMC_CTRL_MODE, (UINT32)EMMC_CTRL_MODE_FIFO);
        /* Retry FW Image Data Read By FIFO Mode */
        Ret = NC_EMMC_ReadByFIFO(readType, (UINT32*)ptBootInfo->tImage.mDestAddr, readsize);
        if(Ret == NC_SUCCESS)
        {
            CheckSum = NC_Checksum((UINT32 *)(ptBootInfo->tImage.mDestAddr), (UINT32)(ptBootInfo->tHeader.mLength / 4U));
            if(ptBootInfo->tHeader.mCheckSum != CheckSum)
            {
                Ret = NC_FAILURE;
                pStatus->mEMMC_FailRes |= ((UINT32)FAIL_EMMC_CHECKSUM);
                DEBUGMSG(MSGERR, "Failed to Image Check, FIFO rtype[%s]\n", (readType==EMMC_READ_TYPE_PRIMARY)?"primary":"backup");
            }
        }
        else
        {
            Ret = NC_FAILURE;
            pStatus->mEMMC_FailRes |= ((UINT32)FAIL_EMMC_READ);          
            #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGERR, "Failed to Image Read rtype[%s]\n", (readType==EMMC_READ_TYPE_PRIMARY)?"primary":"backup");
            CheckSum = 0xA5A55A5AU;
            #endif
        }
    }
#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > Image Loading - 0x%08X, [CtrlMode:%d, ImgType:%d]\n",  ptBootInfo->tImage.mDestAddr, ptBootInfo->tImage.mCtrlMode, ptBootInfo->tImage.mImg_Type);
    if((CheckSum != 0xA5A55A5AU) && (ptBootInfo->tHeader.mCheckSum != CheckSum))
    {
        DEBUGMSG(MSGERR, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
    }
    else
    {
        if(CheckSum == 0xA5A55A5AU)
        {
            DEBUGMSG(MSGERR, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
        }
        else
        {
            DEBUGMSG(MSGINFO, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
        }
    }
#endif

    return Ret;
}



/**
* @desc
   Set eMMC Boot Imageloading.
* @param    tBOOT_INFO      *ptBootInfo     Boot setting parameter information
* @param    tBOOT_STATUS    *Status         Boot Status
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
    IF eMMC GetImage == OK THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIf
    Return Ret
 */
static NC_ERROR NC_Boot_EMMC_ImageLoading(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS* pStatus)
{
    NC_ERROR Ret;

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_IMG_LOAD_IN, pStatus);
        
    /* Boot image loading */
    Ret = NC_Boot_EMMC_GetImage(ptBootInfo, pStatus, EMMC_READ_TYPE_PRIMARY);
    if(Ret == NC_SUCCESS)
    {
        /* Image Loading Result (Success or Fail) */
        pStatus->mEMMC_FailRes = ((UINT32)NC_SUCCESS);        
    }
    else
    {
        #ifdef DEBUG_ENABLE_	
        DEBUGMSG(MSGINFO, "\nFailed to check Primary Image, try to read Backup Image \n", NULL);
        #endif		
        /* If primary image was found unavailable, report it to a fault register */
        NC_MPU_EnterSafetyGate();
        NC_SE_SetFaultInfo(FAULT_NR_EMMC);
        NC_MPU_LeaveSafetyGate();
        
        CLEAR_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_EMMC_CTRL_MODE, (UINT32)EMMC_CTRL_MODE_FIFO);
        
        Ret = NC_Boot_EMMC_GetImage(ptBootInfo, pStatus, EMMC_READ_TYPE_BACKUP);
        if(Ret == NC_SUCCESS)
        {
            /* Image Loading Result (Success or Fail) */
            pStatus->mEMMC_FailRes = ((UINT32)NC_SUCCESS);
        }
        else
        {   
            if((pStatus->mEMMC_FailRes & ((UINT32)FAIL_EMMC_CHECKSUM)) != 0U)
            {
                SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_CRC_IMG, (UINT32)TRUE);
            }

            if((pStatus->mEMMC_FailRes & ((UINT32)FAIL_EMMC_READ)) != 0U)
            {
                SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_READ_IMG, (UINT32)TRUE); 
            }

            /* If backup image was found unavailable as well, report it to a fault register */
            NC_MPU_EnterSafetyGate();
            NC_SE_NotifyFailure(FAULT_BK_EMMC);
            NC_MPU_LeaveSafetyGate();                    
        }
    }

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_EMMC_IMG_LOAD_OUT, pStatus);
    
    return Ret;
}



/**
* @desc
    Boot eMMC.
* @param    tBOOT_INFO      *ptBootInfo     Boot setting parameter information
* @param    tBOOT_STATUS    *pStatus        Boot Status
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
    IF eMMC initialize == OK THEN
        IF eMMC Boot Imageloading == OK THEN
            Ret = NC_SUCCESS
        ELSE
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    RETURN Ret
 */
NC_ERROR NC_Boot_eMMC(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus)
{
    /* Success or Fail */
    NC_ERROR Ret;

    /*
    *------------------------------------------------
    * Init eMMC Interface
    *  -. Get Image Header (Used eMMC Interface)
    *------------------------------------------------
    */
    Ret = NC_Boot_EMMC_Initialize(ptBootInfo, pStatus);
    if(Ret == NC_FAILURE)
    {
        NC_EMMC_DeInit();
        
        NC_MPU_EnterSafetyGate();
        NC_SE_SetFaultInfo(FAULT_NR_EMMC);
        NC_SE_NotifyFailure(FAULT_BK_EMMC);
        NC_MPU_LeaveSafetyGate();
    }

    NC_Gpio_toggle();


    /*
    *------------------------------------------------
    * If (eMMC Init == Success)
    *  -. Check Header
    *  -. Loading FW Image
    *------------------------------------------------
    */
    if(Ret == NC_SUCCESS)
    {
        Ret = NC_Boot_EMMC_ImageLoading(ptBootInfo, pStatus);
    }


    /*
    *------------------------------------------------
    * De-Init eMMC Interface
    *  -. Debug - loading Fail/Ok Save
    *------------------------------------------------
    */
    NC_Boot_EMMC_DeInitialize(pStatus);
    

    NC_Gpio_toggle();

    return Ret;
}

/* End Of File */
