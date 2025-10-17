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
#include "Drv_SDC.h"
#include "Drv_OTP.h"
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

#define FAIL_SDC_CHECKSUM           (2U)
#define FAIL_SDC_INIT               (3U)



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
static NC_ERROR NC_Boot_SD_GetHeader(tBOOT_INFO *ptBootInfo)
{
    UINT32  read_buffer[SD_SECTOR_SIZE/4U] __attribute__ ((aligned (64))) = {0U,};
    NC_ERROR Ret;
    UINT32 ImgType, ReadOffsetSector;
    UINT32 PreDownloadedSize;

    /* 0: E_IMG_NORMAL, 1:E_IMG_BACKUP */
    for (ImgType=E_IMG_NORMAL; ImgType<E_IMG_TYPE_MAX; ImgType++)
    {
        ptBootInfo->tImage.mImg_Type = ImgType;

        if(ImgType == E_IMG_NORMAL)
        {
            ReadOffsetSector = BL_IMG_SD_DEFAULT_NORMAL_SECTOR;
        }
        else
        {
            /* Compute the location of backup image based on OTP configuration when failed to boot using a primary image */
            /*
                (Example) if OTP_CONFIG_1 = 0xE2001104...

                The value of mFW_SIZEUP depends on the first 3 bits from MSB of OTP_CONFIG_1
                For the case OTP_CONFIG_1 is 0xE2001104, mFW_SIZEUP shall be a decimal number 7 (3'b111)
                
                Then, the backup image would be located on the sector 1536 based on following eqution:
                  ((64 [Byte] * 1024) * mFW_SIZEUP) / SD_SECTOR_SIZE) + (BL_IMG_SD_DEFAULT_BACKUP_SECTOR) 
                = ((64 [Byte] * 1024) *     7     ) /      512      ) + (              640              ) 
                = 1536
            */
            #ifdef OTP_ENABLE_
            ReadOffsetSector = (NC_Get_Firmware_Backup_Offset() / (UINT32)SD_SECTOR_SIZE) + BL_IMG_SD_DEFAULT_BACKUP_SECTOR;
            #else
            ReadOffsetSector = BL_IMG_SD_DEFAULT_BACKUP_SECTOR;
            #endif
        }

         /* Read header */
        NC_SDC_Read(ReadOffsetSector, read_buffer, SD_SECTOR_SIZE);

        /* Copy Image header */
        NC_Memcpy_u08((const UINT8*)read_buffer, (UINT8*)&ptBootInfo->tHeader, BL_IMG_HEADER_SIZE);

        Ret = NC_CheckHeader(ptBootInfo);
        if(Ret == NC_SUCCESS)
        {
            PreDownloadedSize = ((UINT32)SD_SECTOR_SIZE - BL_IMG_HEADER_SIZE);

            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);

            /* previously downloaded data */
            NC_Memcpy_u08((const UINT8 *)((UINT8*)read_buffer + BL_IMG_HEADER_SIZE), (UINT8*)(ptBootInfo->tImage.mDestAddr), PreDownloadedSize);
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
    Initialize SD Boot
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
    IF  SD device initialize == OK  THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_Boot_SD_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus)
{
    NC_ERROR  Ret;

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_SDCARD_INIT_IN, pStatus);
    
    Ret = NC_SDC_Init(ptBootInfo->tClock.mSD);
    
    if(Ret == NC_SUCCESS)
    {
        Ret = NC_Boot_SD_GetHeader(ptBootInfo);
    }
    else
    {
        Ret = NC_FAILURE;
        pStatus->mSD_FailRes |= ((UINT32)FAIL_SDC_INIT);
    }

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_SDCARD_INIT_OUT, pStatus);
    
    return Ret;
}



/**
* @desc
    Deinitialize SD device
* @param    tBOOT_STATUS    *ptBootStatus   Boot Status
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
    Deinitialize SD device
*/
static void NC_Boot_SD_DeInitialize(tBOOT_STATUS *pStatus)
{
    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SDCARD_DEINIT_IN, pStatus);

    NC_SDC_DeInit();

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SDCARD_DEINIT_OUT, pStatus);
}



/**
* @desc
    FW Image Data Read.
* @param    tBOOT_INFO  *ptBootInfo     Boot setting parameter information
* @param    UINT32      readType        Read type value
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
    IF Read SD image == OK THEN
        IF Check image checksum == OK THEN
            Ret = NC_SUCCESS
        ElSE
            Ret = NC_FAILURE
        EDNIF
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_Boot_SD_GetImage(tBOOT_INFO *ptBootInfo, UINT32 readType)
{
    NC_ERROR  Ret = NC_SUCCESS;
    UINT32 TotalLength;
    UINT32 CheckSum;
    UINT32 PreDownloadedSize;
    UINT32 ReadOffsetSector;
    
    /* previously downloaded data */
    PreDownloadedSize = ((UINT32)SD_SECTOR_SIZE - BL_IMG_HEADER_SIZE);

    /* already download : (512byte - BL_IMG_HEADER_SIZE) */
    /* SD_SECTOR_SIZE(512Byte) Align */
    TotalLength = ALIGN((ptBootInfo->tHeader.mLength - PreDownloadedSize), (UINT32)SD_SECTOR_SIZE);

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > SD Image Info\n", NULL);
    DEBUGMSG(MSGINFO, "    -. Image size   = %d\n", TotalLength);
    DEBUGMSG(MSGINFO, "    -. Read Sectors = %d\n", TotalLength / SD_SECTOR_SIZE);
#endif
    
    if(readType == E_IMG_NORMAL)
    {
        ReadOffsetSector = BL_IMG_SD_DEFAULT_NORMAL_SECTOR;
    }
    else
    {
        /* Compute the location of backup image based on OTP configuration */
        /*
            (Example) if OTP_CONFIG_1 = 0xE2001104...

            The value of mFW_SIZEUP depends on the first 3 bits from MSB of OTP_CONFIG_1
            For the case OTP_CONFIG_1 is 0xE2001104, mFW_SIZEUP shall be a decimal number 7 (3'b111)
            
            Then, the backup image would be located on the sector 1536 based on following eqution:
              ((64 [Byte] * 1024) * mFW_SIZEUP) / SD_SECTOR_SIZE) + (BL_IMG_SD_DEFAULT_BACKUP_SECTOR) 
            = ((64 [Byte] * 1024) *     7     ) /      512      ) + (              640              ) 
            = 1536
        */
       
        #ifdef OTP_ENABLE_
        ReadOffsetSector = (NC_Get_Firmware_Backup_Offset() / (UINT32)SD_SECTOR_SIZE) + BL_IMG_SD_DEFAULT_BACKUP_SECTOR;
        #else
        ReadOffsetSector = BL_IMG_SD_DEFAULT_BACKUP_SECTOR;
        #endif
    }

    /* If data from a header does not match, read the rest 448 Bytes of a sector again */
    if(ptBootInfo->tImage.mImg_Type != readType) 
    {
        UINT32 read_buffer [SD_SECTOR_SIZE/4U] __attribute__ ((aligned (64))) = {0U,};

        ptBootInfo->tImage.mImg_Type = readType;

        NC_SDC_Read(ReadOffsetSector, read_buffer, SD_SECTOR_SIZE);
        NC_Memcpy_u08((const UINT8*)read_buffer, (UINT8*)&ptBootInfo->tHeader, BL_IMG_HEADER_SIZE);

        Ret = NC_CheckHeader(ptBootInfo);
        if(Ret == NC_SUCCESS)
        {
            PreDownloadedSize = ((UINT32)SD_SECTOR_SIZE - BL_IMG_HEADER_SIZE);

            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);

            /* previously downloaded data */
            NC_Memcpy_u08((const UINT8 *)((UINT8*)read_buffer + BL_IMG_HEADER_SIZE), (UINT8*)(ptBootInfo->tImage.mDestAddr), PreDownloadedSize);
            TotalLength = ALIGN((ptBootInfo->tHeader.mLength - PreDownloadedSize), (UINT32)SD_SECTOR_SIZE);
        }
    }

    if(Ret == NC_SUCCESS)
    {
        /* FW Image Data Read */
        NC_SDC_Read(ReadOffsetSector + SD_READ_SECTION1, (UINT32 *)(ptBootInfo->tImage.mDestAddr + PreDownloadedSize), TotalLength);

        CheckSum = NC_Checksum((UINT32 *)(ptBootInfo->tImage.mDestAddr), (ptBootInfo->tHeader.mLength / 4U));
        if(ptBootInfo->tHeader.mCheckSum != CheckSum)
        {
            Ret = NC_FAILURE;
        }    
    #ifdef DEBUG_ENABLE_
        else
        {
            DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
            DEBUGMSG(MSGINFO, "  > Image Loading - 0x%08X, [CtrlMode:%d, ImgType:%d]\n",  ptBootInfo->tImage.mDestAddr, ptBootInfo->tImage.mCtrlMode, ptBootInfo->tImage.mImg_Type);
            DEBUGMSG(MSGINFO, "    -. Header(0x%08X) vs Calc(0x%08X)\n", ptBootInfo->tHeader.mCheckSum, CheckSum);
        }
    #endif
    }

    
    return Ret;
}



/**
* @desc
    Boot image loading.
* @param    tBOOT_INFO      *ptBootInfo     Boot Information parameter
* @param    tBOOT_STATUS    *pStatus        Boot Status parameter
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
    IF Get Boot image from SD == OK THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_Boot_SD_ImageLoading(tBOOT_INFO *ptBootInfo, tBOOT_STATUS* pStatus)
{
    NC_ERROR Ret;

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SDCARD_IMG_LOAD_IN, pStatus);

    /* Boot image loading */
    Ret = NC_Boot_SD_GetImage(ptBootInfo, SD_READ_TYPE_NORMAL);
    if(Ret == NC_FAILURE)
    {
        /* If primary image was found unavailable, report it to a fault register */
        NC_MPU_EnterSafetyGate();
        NC_SE_SetFaultInfo(FAULT_NR_SD);
        NC_MPU_LeaveSafetyGate();
#ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "\nFailed to check Primary Image, try to read Backup Image \n", NULL);
#endif
        Ret = NC_Boot_SD_GetImage(ptBootInfo, SD_READ_TYPE_BACKUP);
    }

    if(Ret == NC_SUCCESS)
    {
        /* Image Loading Result (Success or Fail) */
        pStatus->mSD_FailRes = ((UINT32)NC_SUCCESS);
    }
    else
    {
        pStatus->mSD_FailRes |= ((UINT32)FAIL_SDC_CHECKSUM);
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_CRC_IMG, (UINT32)TRUE);
#ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "\nFailed to check Backup Image, ensure that backup image is located on a right address \n", NULL);
#endif
    }

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_SDCARD_IMG_LOAD_OUT, pStatus);

    return Ret;
}



/**
* @desc
    Boot device from SD.
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
    IF Initialize SD device == OK THEN
       IF Boot imageloading from SD == OK THEN
           Ret = NC_SUCCESS
       ELSE
           Ret = NC_FAILURE
       ENDIF
    ELSE
       Ret = NC_FAILURE
    ENDIF
    Return Ret
 */
NC_ERROR NC_Boot_SD(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus)
{
    /* Success or Fail */
    NC_ERROR Ret;

    /*
    *------------------------------------------------
    * Init SDC Interface
    *  -. Get Image Header (Used SDC Interface)
    *------------------------------------------------
    */
    Ret = NC_Boot_SD_Initialize(ptBootInfo, pStatus);
    if(Ret == NC_FAILURE)
    {
        NC_SDC_DeInit();

        NC_MPU_EnterSafetyGate();
        NC_SE_SetFaultInfo(FAULT_NR_SD);
        NC_MPU_LeaveSafetyGate();
    }

    NC_Gpio_toggle();

    /*
    *------------------------------------------------
    * If (SDC Init == Success)
    *  -. Check Header
    *  -. Loading FW Image
    *------------------------------------------------
    */
    if(Ret == NC_SUCCESS)
    {
        Ret = NC_Boot_SD_ImageLoading(ptBootInfo, pStatus);
    }


    /*
    *------------------------------------------------
    * De-Init sFlash Interface
    *  -. Debug - loading Fail/Ok Save
    *------------------------------------------------
    */
   if(Ret == NC_SUCCESS)
   {
        NC_Boot_SD_DeInitialize(pStatus);
   }
    

    NC_Gpio_toggle();


    if(Ret != NC_SUCCESS)
    {
        NC_MPU_EnterSafetyGate();
        NC_SE_NotifyFailure(FAULT_BK_SD);
        NC_MPU_LeaveSafetyGate();
    }

    return Ret;
}

/* End Of File */
