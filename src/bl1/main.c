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
#include "Drv_ICU.h"
#include "safety_engine.h"
#include "seq_monitor.h"
#include "MPU.h"
#if defined(SECURE_BOOT_)
#include "secure_boot.h"
#endif

#define INFO_BOOT_NONE             (0U)
#define INFO_BOOT_MEDIA            (1U)
#define INFO_BOOT_SECURE_MODE      (2U)
#define INFO_BOOT_DONE_RESULT      (3U)

/*
********************************************************************************
*               IMPORTED FUNCTION DEFINITIONS
********************************************************************************
*/

#ifdef SIM_ONLY_
extern void NC_SIM_InitPort(void);
extern void NC_SIM_InitFastBoot(void);

static UINT8 test[4] DEBUG_DATA_ATTR(4);
#endif

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/
/** 
* @desc
    Get Boot Info.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter
* @param    tBOOT_STATUS*   ptIED_Param     Boot Status
* @param    UINT32          GetInfoId       ID value
* @return   UINT32  Boot Information          
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
    Info
    Select Case GetInfoId
        Case INFO_BOOT_MEDIA
            Info = Boot Memory Info
        Case INFO_BOOT_SECURE_MODE
            Info = Secure Mode Info
        Case INFO_BOOT_DONE_RESULT
            Info = Booting Done Success or Fail 
        Case Else
            Info = INFO_BOOT_NONE
    End Select
    Return  Info
*/
static UINT32 NC_GetBootInfo(const tBOOT_INFO *ptBootInfo, const tBOOT_STATUS *ptBootStatus, UINT32 GetInfoId)
{
    UINT32 Info;

    switch(GetInfoId)
    {
        case INFO_BOOT_MEDIA:
            Info = ptBootInfo->tStrap.Bit.mBootMemory;
            break;
        case INFO_BOOT_SECURE_MODE:
            Info = ptBootInfo->tImage.mSecuMode;
            break;
        case INFO_BOOT_DONE_RESULT:
            Info = ptBootStatus->mBootDone_Res;
            break;
        default:
            Info = INFO_BOOT_NONE;
            break;
    }

    return Info;
}

#ifdef DEBUG_ENABLE_
static void NC_DEBUG_Initialize(tBOOT_INFO *ptBootInfo)
{
    UINT32 InBaudrate;

    /* UART init - 115200(default) */
    switch(ptBootInfo->tImage.mUartBaudrate)
    {
        case NC_UART_SET_BAUDRATE_230400: /* 230400(MAX) */
            InBaudrate = (UINT32)UT_BAUDRATE_230400;
            break;
        case NC_UART_SET_BAUDRATE_57600: /* 57600 (MID_2) */
            InBaudrate = (UINT32)UT_BAUDRATE_57600;
            break;
        case NC_UART_SET_BAUDRATE_19200: /* 19200 (MIN) */
            InBaudrate = (UINT32)UT_BAUDRATE_19200;
            break;
        default: /* NC_UART_SET_BAUDRATE_115200 : 115200(default:MID_1) */
            InBaudrate = (UINT32)UT_BAUDRATE_115200;
            break;
    }

    NC_UART_Initialize(InBaudrate, ptBootInfo->tClock.mUART);


    /* Boot Information Display */
    DEBUGMSG(MSGINFO, "\n\n",NULL);
    DEBUGMSG(MSGWARN, "[%d ms] - start. - UART Init\n", nc_get_msec(0));
    DEBUGMSG(MSGWARN, "                >>>>> BL_%d Start <<<<<        \n", BL_SEL);
    DEBUGMSG(MSGINFO, "=======================================================\n",NULL);
    DEBUGMSG(MSGINFO, " APACHE6 BL%d Version: [v%d.%d.%d] [%s, %s]\n", BL_SEL,
                                                                    BL_VER_MAJOR,
                                                                    BL_VER_MINOR,
                                                                    BL_VER_PATCH,
                                                                    (const CHAR*)__DATE__,
                                                                    (const CHAR*)__TIME__);
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n",NULL);
    DEBUGMSG(MSGINFO, "  > Boot-Strap Information\n", NULL);
    /* DEBUGMSG(MSGINFO, "    -. %s Boot Mode\n",     (ptBootInfo->tImage.mSecuMode == 2U)?"Secure":"Normal"); */
    DEBUGMSG(MSGINFO, "    -. %s Boot Mode(%d)\n",     (ptBootInfo->tImage.mSecuMode == 2U)?"Secure":"Normal", ptBootInfo->tImage.mSecuMode);
    DEBUGMSG(MSGINFO, "    -. Boot Memory : %s\n", (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_EMMC) ?"eMMC":
                                                (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_UART) ?"UART":
                                                (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_USB)  ?"USB":
                                                (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SDCARD)?"SD"  :"sFlash");
    if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_BYPASS)                       { DEBUGMSG(MSGINFO, "    -. External Clock mode\n", NULL);  }
    else if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_PLL_HALF_SSCG_OFF) { DEBUGMSG(MSGINFO, "    -. PLL Half. Clock Mode\n", NULL); }
    else if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_PLL_FULL_SSCG_ON)  { DEBUGMSG(MSGINFO, "    -. Reserved Clock Mode\n", NULL);  }
    else if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_PLL_FULL_SSCG_OFF) { DEBUGMSG(MSGINFO, "    -. PLL Max. Clock Mode\n", NULL);  }
    else                                             { DEBUGMSG(MSGINFO, "    -. FPGA Test Clock Mode\n", NULL); }
    DEBUGMSG(MSGINFO, "  > Clock Information\n", NULL);
    DEBUGMSG(MSGINFO, "    -. APB : %10d Hz   UART : %10d Hz\n", ptBootInfo->tClock.mAPB, ptBootInfo->tClock.mUART);
    DEBUGMSG(MSGINFO, "    -. SPI : %10d Hz   QSPI : %10d Hz\n", ptBootInfo->tClock.mSPI, ptBootInfo->tClock.mQSPI);
    DEBUGMSG(MSGINFO, "    -. SDC : %10d Hz   EMMC : %10d Hz\n", ptBootInfo->tClock.mSD, ptBootInfo->tClock.mEMMC);

}
#endif




/**
* @desc
    main function.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret
    Init debug register
    Init SCU
    Init boot configure
    Init IP
    Init ICU pin mux
    Init safety engine
    Init GPIO
    Ret = Load boot image
    Secure boot mode set
    Disable IP clock
    Jump image location
    Return Ret
*/
NC_ERROR main(void)
{
    /*
     * All the information needed
     * for booting is in this structure.
     */
    tBOOT_INFO tBootInfo;


    /*
     * It contains information about boot result.
     */
    tBOOT_STATUS tBootStatus;

#if defined(USB_DLOAD_)
    UDC_CTX_T tBootUsbCtx;
#endif

    /* Success or Failure */
    NC_ERROR Ret;
    UINT32   BootType;


    /*
    *------------------------------------------------
    * Init Debug Register
    *  -. for RTL Simulation
    *  -. Used when debugging in UART Off state.
    *------------------------------------------------
    */
    NC_SM_Initialize(0U);



    /*
    *------------------------------------------------
    * Init SCU
    *  -. Check Boot-Strap
    *  -. Clock Enable and IP Reset
    *------------------------------------------------
    */
    NC_SCU_Initialize(&tBootInfo, &tBootStatus);



    /*
    *------------------------------------------------
    * Init Boot Config
    *  -. Check Boot-Strap
    *  -. Check OTP Boot config
    *------------------------------------------------
    */
    NC_BootConfig(&tBootInfo, &tBootStatus);



    /*
    *------------------------------------------------
    * Release IP Ongo Reset
    *  -.  UART / QSPI / SD / EMMC / USB / Others Bus
    * Enable IP Clock
    *  -.  UART / QSPI / SD / EMMC / USB / Core
    *------------------------------------------------
    */
    NC_InitReset(&tBootInfo, &tBootStatus);



    /*
    *------------------------------------------------
    * Simulation Mode
    *  -. Set SPI Port
    *------------------------------------------------
    */
#ifdef SIM_ONLY_
    NC_SIM_InitPort();
#endif



    /*
    *------------------------------------------------
    * Set ICU Pin Mux
    *------------------------------------------------
    */
    NC_ICU_Initialize(&tBootInfo, &tBootStatus);





    /*
    *------------------------------------------------
    * Enable Safety Engine
    *------------------------------------------------
    */
    NC_MPU_EnterSafetyGate();
    NC_SE_Initialize(&tBootInfo, &tBootStatus);
    NC_MPU_LeaveSafetyGate();



    /*
    *------------------------------------------------
    * GPIO Debug output
    *  -. Check Booting-Speed
    *  -. Debug GPIO Toggle
    *------------------------------------------------
    */
    NC_Gpio_toggle();




    /*
    *------------------------------------------------
    * Simulation Fast Boot Mode
    *  -. Set SPI Port
    *------------------------------------------------
    */
#ifdef SIM_BL_NO_FLASH_
    /* Simulation Mode */
    NC_SIM_InitFastBoot();
#else





    /*
    *------------------------------------------------
    * Init UART Interface
    *  -. Used Control UART-0 (Only Tx)
    *  -. Default BaudRate - 115200
    *------------------------------------------------
    */
#ifdef DEBUG_ENABLE_
    NC_DEBUG_Initialize(&tBootInfo);
#endif

#ifdef R5_UART_ENABLE_
    NC_SCU_PrintPLL(&tBootInfo.tStrap, &tBootInfo.tClock);
#endif

    /*
    *------------------------------------------------
    * Load Boot Image
    *  -. Check Boot Memory(sFlash, eMMC, SDCARD )
    *  -. Load Next Bootloader Image
    *------------------------------------------------
    */
    BootType = NC_GetBootInfo(&tBootInfo, &tBootStatus, INFO_BOOT_MEDIA);
    if(BootType == E_BOOT_EMMC)
    {
        /* eMMC Boot */
        Ret = NC_Boot_eMMC(&tBootInfo, &tBootStatus);
        RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 0U;
    }
    else if(BootType == E_BOOT_SDCARD)
    {
        /* SD CARD Boot */
        Ret = NC_Boot_SD(&tBootInfo, &tBootStatus);
        RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 0U;
    }
    else if(BootType == E_BOOT_UART)
    {
        /* UART Boot */
        NC_Boot_UART_Initialize(&tBootInfo, &tBootStatus);
        Ret = NC_Boot_UART(&tBootInfo, &tBootStatus);
    }
    
    else if(BootType == E_BOOT_USB)
    {
        /* USB Boot */
        #if defined(USB_DLOAD_)
        NC_SYS_SCU_TZPROT_EN();
        NC_AXI2APB_TZPC_EN();

        NC_Boot_USB_Initialize(&tBootInfo, &tBootStatus);
        Ret = NC_Boot_USB(&tBootInfo, &tBootStatus, &tBootUsbCtx);
        #else
        Ret = NC_FAILURE;
        DEBUGMSG(MSGERR, "[ERROR] USB DOWNLOAD OPTION IS DISABLED\n", NULL);
        #endif
    }
    else
    {
        /* sFlash Boot */
        Ret = NC_Boot_sFlash(&tBootInfo, &tBootStatus);
    }

    if(NC_GetBootInfo(&tBootInfo, &tBootStatus, INFO_BOOT_SECURE_MODE) == E_SBOOT_SECURE_MODE)
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_SECURE_BOOT, (UINT32)TRUE);
        RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 1U;

        /*
        *------------------------------------------------
        * Secure Boot
        *  -. Load Root Key
        *  -. Check Validity
        *  -. Check Authentication
        *  -. Check Confidentiality
        *------------------------------------------------
        */
       
        #ifdef SECURE_BOOT_
        if(Ret == NC_SUCCESS)
        {
            Ret = NC_Secure_Boot(&tBootInfo, &tBootStatus);
            RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 0U;

            NC_Gpio_toggle();
        }
        #endif
    }
    else
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_IS_SECURE_BOOT, (UINT32)FALSE);
    }
#endif /* SIM_BL_NO_FLASH_ */



    /*
    *------------------------------------------------
    * If (FW Loading == Success)
    *  -. Jump SRAM or DDR
    *------------------------------------------------
    */
    NC_SM_SetBOOT_Result(Ret, &tBootStatus);

    if(NC_GetBootInfo(&tBootInfo, &tBootStatus, INFO_BOOT_DONE_RESULT) == NC_BOOT_DONE_SUCCESS)
    {
        NC_LD_JumpImage(&tBootInfo, &tBootStatus);
    }
    else
    {
        NC_MPU_EnterSafetyGate();
        NC_SE_NotifyFailure(FAULT_BOOT_FAIL);
        NC_MPU_LeaveSafetyGate();
    }


    return Ret;
}

/* End Of File */
