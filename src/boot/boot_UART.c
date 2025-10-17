#include "Apache.h"
#include "main.h"
#include "ymodem.h"
#include "Drv_Uart.h"
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

#define FAIL_UART_DOWNLOAD           (1U)
#define FAIL_UART_CHECKSUM           (2U)

/**
* @desc
    Initialize UART to use UART IP.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information parameter.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status parameter.
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
    Call the UART initialization function to set the value in the UART Register.
*/
void NC_Boot_UART_Initialize(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
#ifndef DEBUG_ENABLE_
    UINT32 InBaudrate;
#endif

    /* for NULL CHECK */
    
    NC_SM_SetBOOT_Step((UINT32)DBG_STP_YMODEM_INIT_IN, ptBootStatus);

    if(ptBootInfo != NULL)
    {
#ifndef DEBUG_ENABLE_
        switch(ptBootInfo->tImage.mUartBaudrate)
        {
            case 1: /* 230400(MAX) */
                InBaudrate = (UINT32)UT_BAUDRATE_230400;
                break;
            case 2: /* 57600 (MID_2) */
                InBaudrate = (UINT32)UT_BAUDRATE_57600;
                break;
            case 3: /* 19200 (MIN) */
                InBaudrate = (UINT32)UT_BAUDRATE_19200;
                break;
            default: /* case 0 : 115200(default:MID_1) */
                InBaudrate = (UINT32)UT_BAUDRATE_115200;
                break;
        }
        
        NC_UART_Initialize(InBaudrate, ptBootInfo->tClock.mUART);
#endif
    }

    /* UART init - 115200(default) */


    NC_SM_SetBOOT_Step((UINT32)DBG_STP_YMODEM_INIT_OUT, ptBootStatus);
}



/**
* @desc
    Boot with UART communication.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information parameter.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status parameter.
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
    Ret = Download image into target address
    IF  Ret == NC_SUCCESS  THEN
        Checksum = Checksum Verification
        IF  Checksum failure   THEN
            Ret = NC_FAILURE
        ELSE
            Ret = NC_SUCCESS
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF

    Return Ret
*/
NC_ERROR NC_Boot_UART(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR  Ret;
    UINT32 CheckSum;
#ifdef DEBUG_ENABLE_ /* for QAC */
    UINT32 buf;
#endif
    UINT32 length = (UINT32)(1 * 1024 * 448);

    UINT32 Checksum_Src;
    UINT32 Checksum_Length;
    UINT32 FileSize = 0U;

    UINT8 fname[YMODEM_FILE_NAME_MAX_LENGTH] = "fw.dat";

#ifdef DEBUG_ENABLE_
    CheckSum = 0U;
    buf = ptBootInfo->tImage.mDestAddr; /* 0x01000000; */
    DEBUGMSG(MSGWARN, "[YMODEM] Waiting for a firmware file(xxxx.bin) , Upload to Addr[0x%08x]....\n", buf);
    #endif

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_YMODEM_IMG_LOAD_IN, ptBootStatus);
    
    /* download image into target address */
    Ret = NC_Ymodem_receive(ptBootInfo, length, fname, &FileSize);
    
#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGWARN, ">file : %s\n"
               ">addr: 0x%x\n"
               ">size: %d bytes\n"
               ">Header Len: %d \n",
               fname, buf, FileSize, ptBootInfo->tHeader.mLength);
#endif
    if(Ret == NC_SUCCESS) /* Success */
    {
        Checksum_Src = ptBootInfo->tImage.mDestAddr; /* for QAC */
        Checksum_Length = ptBootInfo->tHeader.mLength/4U; /* for QAC */

        CheckSum = NC_Checksum((UINT32 *)Checksum_Src, Checksum_Length);

        NC_Gpio_toggle();

        if(ptBootInfo->tHeader.mCheckSum != CheckSum)
        {
            Ret = NC_FAILURE;
            ptBootStatus->mUART_FailRes |= ((UINT32)FAIL_UART_CHECKSUM);
            /* for QAC Rule 12.2 */
            SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_CRC_IMG, (UINT32)TRUE);
            NC_MPU_EnterSafetyGate();
            NC_SE_NotifyFailure(FAULT_UART_CS);
            NC_MPU_LeaveSafetyGate();
        }
        else
        {
            /* Update IMG Config */
            NC_IMGConfig(ptBootInfo);

            Ret = NC_SUCCESS;
            ptBootStatus->mUART_FailRes = ((UINT32)NC_SUCCESS);
        }
    }
    else
    {
        NC_Gpio_toggle();

        Ret = NC_FAILURE;
        ptBootStatus->mUART_FailRes |= ((UINT32)FAIL_UART_DOWNLOAD);
        /* for QAC Rule 12.2 */
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_FAIL_READ_IMG, (UINT32)TRUE);
        NC_MPU_EnterSafetyGate();
        NC_SE_NotifyFailure(FAULT_UART_DL);
        NC_MPU_LeaveSafetyGate();
#ifdef DEBUG_ENABLE_
        CheckSum = 0xA5A55A5AU;
#endif
    }
#ifdef DEBUG_ENABLE_

    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > Image Loading - 0x%08X, [BootStrapMode:%d, ImgType:%d]\n",  ptBootInfo->tImage.mDestAddr, ptBootInfo->tStrap.Bit.mBootMemory, ptBootInfo->tImage.mImg_Type);
    DEBUGMSG(MSGINFO, "    -. Boot Mode : 0:SPI,1:EMMC,2:SD,3:SPI-INV,4:UART,5:USB\n", NULL);
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
    
        NC_SM_SetBOOT_Step((UINT8)DBG_STP_YMODEM_IMG_LOAD_OUT, ptBootStatus);
    
    return Ret;
}


/* end of file */
