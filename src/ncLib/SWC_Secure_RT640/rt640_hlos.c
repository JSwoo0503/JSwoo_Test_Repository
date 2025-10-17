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
#include "rt640_common.h"
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "MPU.h"
#include "safety_engine.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/
#define CMRT_TOV_TURN_ON                (0x0)      /* TOV Turn ON Signature , TOV Turn OFF == 0x1 */
#define DEFAULT_CMRT_TIME_OVER_CNT      (0x40U)    /* Timeout Count */

/* base code comes from url : gitlab.nextchip.com/apache6/sw/cmrt/hlos */

#define ARGO

#define CMRT640_BASE    (0x04400000U)

/* typedef unsigned long long uint64_t; */
/* typedef unsigned long uint32_t; */

#define WORDS(x) (((x) + 3U) / 4U)

#ifdef ZC706
volatile UINT32 *SCB_CONTROL = (0x40000000 + 0x04);
volatile UINT32 *R_SCB_TDV  = (0x40000000 + 0x2C);
volatile UINT32 *DM_CONTROL = (0x41200000 + 0x00);
#define SIC_BASE 0x40800000
#define HARD_RESET 		0x1
#define POWERON_RESET 	0x2
#elif defined(ARGO)
/* static volatile UINT32 *SCB_CONTROL = (UINT32*)(0x0680E008); */
#define SIC_BASE                (CMRT640_BASE)
#define R_SCATCH_0_ADDR         (SIC_BASE + 0x530UL)
#define R_HLOS2ESW_LENGTH_ADDR  (SIC_BASE + 0x650UL)
#define R_ESW2HLOS_LENGTH_ADDR  (SIC_BASE + 0x620UL)

/* PRQA S 3332 ++ */
#define HARD_RESET      ((UINT16)0x1U << (UINT8)12U)
#define POWERON_RESET   ((UINT16)0x1U << (UINT8)13U)
/* PRQA S 3332 -- */
#else
    #error "who are you ? ZC706? ARGO?"
#endif


#ifdef ZC706
volatile unsigned int *R_NON_EXISTING		= (SIC_BASE + 0x700UL); /* FPGA quirk */
#endif

/* #define CPU_SRAM_BIST_IDLE         0b000000 */
#define CPU_SRAM_CHECK_IN_PROGRESS 0x10U  /* 0b010000 */
#define CPU_SRAM_CHECK_SUCCESSFUL  0x20U  /* 0b100000 */
#define CPU_SRAM_CHECK_FAILED      0x30U  /* 0b110000 */

#define CMD_REQUEST  1UL
#define CMD_DATA     3UL


#define SET_HEADER_VER(h, v) ((h) = ((h) & 0x0fffffffUL) | ((UINT32)((v) & 0xfUL) << (UINT8)28))
#define SET_HEADER_SRC(h, v) ((h) = ((h) & 0xf000ffffUL) | ((UINT32)((v) & 0xfffUL) << (UINT8)16))
#define SET_HEADER_CMD(h, v) ((h) = ((h) & 0xffff0fffUL) | ((UINT32)((v) & 0xfUL) << (UINT8)12))
#define SET_HEADER_DST(h, v) ((h) = ((h) & 0xfffff000UL) | ((v) & 0xfffUL))
#define SIDEBAND_RESET    0x0fUL /* Reset communications */

#define CMRT_BOOT_STEP_2    (2U)
#define CMRT_BOOT_STEP_3    (3U)

#define CMRT_REG_SIDEBAND_RESET    (0U)
#define CMRT_REG_DECRYPT_STAGE1    (1U)
#define CMRT_REG_DECRYPT_STAGE3    (3U)
#define CMRT_REG_DECRYPT_STAGE4    (4U)

/* #define SIC_DATA_REGS 8UL */

typedef struct {
    UINT32 hdr;
} cmrt_sic_header_t;

/*
 * HLOS messaging protocol structures.
 */
typedef struct {
    cmrt_sic_header_t hdr;
    UINT32 address;
    UINT32 length;
} cmrt_sic_request_t;


typedef struct {
    UINT32 /*ptr*/ chiper_image;
    UINT32 chiper_image_size;
    UINT32 /*ptr*/ plain_image; /* or chiper_image in-place */
    UINT32 plain_image_size;
    UINT32 key_mode; /* AES | HMAC */
    UINT32 key_place; /* System OTP passing | CMRT OTP with derivation */
    UINT32 /*ptr*/ system_otp;
    UINT32 system_otp_size;
    UINT32 keysplit_num; /* 0 : System Key, 1~7 : Internal Key split number */
    UINT32 diversify_path; /* max 16 bytes, but use 4 bytes only */
    /* UINT32 derivation_path_size; */
} request_t;


/*

    --- Sequence ---
      Prepare CMRT's mw and secure_boot default user container
          Copy mw, secure_boot from System Media to system SRAM

      Bringup CMRT
            Release Reset
                  sys_cm_POResetn to 0 to reset the chip
            fboot running (@ SOG)
                  copy sboot from CMRT OTP to sram
              jump
          sboot running
                <pre-condition> SAC|REMAPPER map to system SRAM
                  copy mw from external memory to sram
              jump
          mw running
                <pre-condition> SAC|REMAPPER map to system SRAM
                  copy default container from external memory to sram
              autoload

      Invoke secure_boot service
          <pre-condition> SAC|REMAPPER map to system SRAM|DDR
            Message passing
                DMAC or FIFO
          Result return
                DMAC or FIFO

    --- Address Map

      Address Map (Host ASIC Side)
          *Offset*     *Size Limit*          *Used Size*  *Remark*                                                     	*Link to CMRT*
          0x0100_0000  0x0100_0000   16MB           		SYS_RAM                                                      	L2
          0x8000_0000  0x8000_0000    2GB           		DDR0 - Areas that exist in any DDR component configuration   	L2
          0x0440_0000  0x0020_0000    2MB           		AHB Slave : Map to CMRT's SIC                                	L1

      Address Map (CMRT Side)
          *Offset*     *Size Limit*          *Used Size*  *Remark*														*Link to Host ASIC*
        0x0000_0000										HW Common
          0x0000_1000                                    	SIC (System Interface Core)                                  	L1
          0x0000_2000                                    	FMC
          0x0000_4000                                    	TMC
          0x0000_8000                                    	CC
          0x0000_B000                                    	EAC
        0x0001_0000										AES
        0x0002_0000										HC
        0x0002_2000										WHC
        0x0002_4000										CSHC
        0x0002_6000										HC2
        0x0003_0000										PKE
        0x0004_0000										OMC
        0x0005_0000										KDC
        0x0005_2000										KTC
        0x0005_A000										CPU
        0x0006_0000										SAC
        0x0006_2000										DMAC
        0x0007_0000										MPU
        0x0007_2000										PLIC
        0x0007_4000										TIMER
        0x0007_5000										UART
        0x0008_0000										UFC
        0x0009_0000										CCP
        0x0010_0000  0x0000_C000   48KB					ROM
        0x0020_0000				  256KB					SRAM
        0x4000_0000	 ???						      	SAC (System Aperture Core) Mapping                            	Choose L2 by SEGMENT_CONFIG_0


*/

/*
   This code will located in BL1(MaskROM) of Cortex-R5F
   This code is running at Cortex-R5F
*/

#define API

#ifdef FPGA_MODE_
#define CMRT_CLK (40000000UL) /* 40Mhz @ FPGA */
#endif



/**
* @desc
    Get Timeover count.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter.
* @return   UINT32  Timeover count
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
    TimeoverCount = (mSecureBootSize & 0x0000FFF0) >> 4
    IF  TimeoverCount == 0  THEN
        TimeoverCount = 0x40
    ENDIF
    Return TimeoverCount
*/
static UINT32 NC_SB_GetTimeOverCount(tBOOT_STATUS *ptBootStatus)
{
    UINT32 TimeOverCount;
    
    TimeOverCount = (ptBootStatus->ptHandleBoot->tHeader.tBootSec.mSecureBootSize & 0x0000FFF0U) >> 4U;

    if(TimeOverCount == 0U)
    {
        TimeOverCount = DEFAULT_CMRT_TIME_OVER_CNT;  /* default set */
    }

    return TimeOverCount;
}



/**
* @desc
    Get Timeover enable.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter.
* @return   UINT32  Timeover enable
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
    TimeoverEnable = mSecureBootSize & 0xF
    Return TimeoverEnable
*/
static UINT32 NC_SB_GetTimeOverEnable(tBOOT_STATUS *ptBootStatus)
{
    UINT32 TimeOverEnable;

    TimeOverEnable = ptBootStatus->ptHandleBoot->tHeader.tBootSec.mSecureBootSize & 0xFU;

    return TimeOverEnable;
}



/**
* @desc
    Wait time - ms
* @param    UINT32          count           Wait time - ms
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
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
    start tick = current system tick
    timeout tick = start tick + wait time
    IF  Get system tick < timeout tick  THEN
        Wait time
    ENDIF
*/
#ifdef FPGA_MODE_
static void NC_SB_Wait_Cycles(UINT32 count)
#else
static void NC_SB_Wait_Cycles(UINT32 count, tBOOT_STATUS *ptBootStatus)
#endif
{
    UINT64 start_tick, timeout_tick;

    start_tick = NC_SCU_GetTick(FALSE);
/* PRQA S 0303++ */
#ifdef FPGA_MODE_
    timeout_tick = start_tick + ((UINT64)count * SYS_APB_CLK / CMRT_CLK);
#else
    timeout_tick = start_tick + ((UINT64)count * SYS_APB_CLK / ptBootStatus->ptHandleBoot->tClock.mCMRT);
#endif
/* PRQA S 0303-- */

    while (1)
    {
        if(NC_SCU_GetTick(FALSE) < timeout_tick)
        {
            /*  */
        }
        else
        {
            break;
        }
    }
}



/**
* @desc
    Initialize cmrt parameter.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
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
    Set the value in cmrt register.
*/
API void NC_SB_Init_Param(tBOOT_STATUS *ptBootStatus)
{
/* PRQA S 3332 ++ */
    ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL   = (UINT32*)(0x05014010);
/* PRQA S 3332 -- */
    ptBootStatus->ptHandleBoot->tCMRT.pR_HLOS2ESW_D0 = (UINT32*)(SIC_BASE + 0x630UL);
}



/**
* @desc
    Write CMRT value in pointer
* @param    UINT32  v   Write CMRT value
* @param    UINT32  *r  Write pointer
* @return   void
* @design
    Write CMRT value in pointer
*/
static void NC_SB_CMRT_IOWrite32(UINT32 v, volatile UINT32 *r)
{
    *r = v;
}



/**
* @desc
    Read CMRT value from pointer
* @param    UINT32  *r  Read CMRT value from pointer
* @return   UINT32  Pointer value
* @design
    Read CMRT value from pointer
*/
static UINT32 NC_SB_CMRT_IORead32(volatile UINT32 *r)
{
    return *r;
}



/**
* @desc
    Hold CMRT reset.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
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
    Wait cycle for holding cmrt reset
*/
API void NC_SB_Hold_Reset(tBOOT_STATUS *ptBootStatus)
{
    /* printf("enter %s\r\n", __func__); */

    /* 1. The High Level Operation System (HLOS) sets sys_cm_POResetn = 1'b0 to enter the power-on reset
     state. */

    /*  Reset */
    /* ASSERT(*SCB_CONTROL == 0);  CMRT may be hold */
/* PRQA S 3332 ++ */
    UINT32 Reg;
    Reg = *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL);
    Reg |= (UINT32)(HARD_RESET | POWERON_RESET);
    *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL) = Reg;
/* PRQA S 3332 -- */
    /* 2. After about 5,000 cycles, HLOS sets sys_cm_POResetn = 1'b1 to exit Power-On Reset. */
    #ifdef FPGA_MODE_
    NC_SB_Wait_Cycles(5000);
    #else
    NC_SB_Wait_Cycles(5000, ptBootStatus);
    #endif
}



/**
* @desc
    Sram check.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
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
    DO WHILE    TRUE
        IF  TimeOut THEN
            SE Fault
            break
        ELSE
            Check Time
        ENDIF

        IF  Sram Check is Successful    THEN
            break
        ELSE
            Hold CMRT reset.
        ENDIF
    LOOP
*/
static void NC_SB_CPU_Sram_Check(tBOOT_STATUS *ptBootStatus)
{
    volatile UINT32 *R_BOOT_STATUS = (UINT32*)(SIC_BASE + 0x400UL);
    UINT32 TOV_ON;
    UINT32 TOV_Cnt;
    UINT32 Reg;
    BOOL GO_AHEAD1_Flag = TRUE;
    BOOL TOV_EXIT_1 = FALSE;

    TOV_ON = NC_SB_GetTimeOverEnable(ptBootStatus);
    TOV_Cnt = NC_SB_GetTimeOverCount(ptBootStatus);

    while(1)
    {
        if( (GO_AHEAD1_Flag != TRUE) || (TOV_EXIT_1 == TRUE) )
        {
            break;
        }

        /* Timeout Exit Condition - 1 */
        if(TOV_ON == (UINT32)CMRT_TOV_TURN_ON)
        {
            if(NC_SCU_mTimeOut((UINT64)TOV_Cnt*10U) == TRUE)
            {
                ptBootStatus->mSecureRunRes |= NC_BOOT_SECURE_TOV_FAIL_1;
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FAULT_SB_TOV_1);
                NC_MPU_LeaveSafetyGate();
                TOV_EXIT_1 = TRUE;
            }
        }

        switch(NC_SB_CMRT_IORead32(R_BOOT_STATUS))
        {
            case CPU_SRAM_CHECK_IN_PROGRESS:
                /* Nothing */
                break;

            case CPU_SRAM_CHECK_FAILED:
                NC_SB_Hold_Reset(ptBootStatus);
    /* PRQA S 3332 ++ */
                Reg = *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL);
                Reg &= ~((UINT32)(HARD_RESET | POWERON_RESET));
                *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL) = Reg;
    /* PRQA S 3332 -- */
                break;

            case CPU_SRAM_CHECK_SUCCESSFUL:
                GO_AHEAD1_Flag = FALSE;
                break;

            default:
            /* Nothing */
    #ifdef DEBUG_ENABLE_
                DEBUGMSG(MSGINFO, "wrong R_BOOT_STATUS : %d (0x%08x)\r\n", *R_BOOT_STATUS, *R_BOOT_STATUS);
    #endif
            break;
        }
    }
}



/**
* @desc
    Check SW boot status.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
* @param    UINT32          Step            Boot Step
* @return   void
* @design
    IF  Step values ​​are matched.  THEN
        The value is set in the parameter.
    ELSE
        Parameter value is '0'
    ENDIF

    DO WHILE    TRUE
        Read CMRT value
        IF  CMRT value is valid THEN
            break
        ENDIF

        IF  Timeout THEN
            SE Fault
            break
        ELSE
            Check Time
        ENDIF
    LOOP
*/
static void NC_SB_Check_SW_Boot_Status(tBOOT_STATUS *ptBootStatus, UINT32 Step)
{
    volatile UINT32 *R_SW_BOOT_STATUS = (UINT32*)(SIC_BASE + 0x404UL);
    UINT32 TOV_ON;
    UINT32 TOV_Cnt;
    UINT32 FailResValue = 0x0U;
    UINT32 FaultInfo = 0x0U;
    UINT32 RegValue = 0x0U;
    BOOL TOV_EXIT_1 = FALSE;

    if(Step == CMRT_BOOT_STEP_2)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_2;
        FaultInfo = FAULT_SB_TOV_2;
        RegValue = 0x08U;
    }
    else if(Step == CMRT_BOOT_STEP_3)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_3;
        FaultInfo = FAULT_SB_TOV_3;
        RegValue = 0x3fU;
    } else
    {
        /* No Operation */
    }

    TOV_ON = NC_SB_GetTimeOverEnable(ptBootStatus);
    TOV_Cnt = NC_SB_GetTimeOverCount(ptBootStatus);

    while(1)
    {
        #ifdef DEBUG_ENABLE_
        /* DEBUGMSG(MSGINFO, "1.R_SW_BOOT_STATUS : %d (0x%08x)\r\n", *R_SW_BOOT_STATUS, *R_SW_BOOT_STATUS); */
        #endif
        if( (((UINT8)NC_SB_CMRT_IORead32(R_SW_BOOT_STATUS) & RegValue) == RegValue) || (TOV_EXIT_1 == TRUE) )
        {
            break;
        }

        /* Timeout Exit Condition - 2 */
        if(TOV_ON == (UINT32)CMRT_TOV_TURN_ON)
        {
            if(NC_SCU_mTimeOut((UINT64)TOV_Cnt*10U) == TRUE)
            {
                ptBootStatus->mSecureRunRes |= FailResValue;
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FaultInfo);
                NC_MPU_LeaveSafetyGate();
                TOV_EXIT_1 = TRUE;
            }
        }
    }
}



/**
* @desc
    Check scratch register.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter.
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
    DO WHILE    TRUE
        IF  CMRT value is valid     THEN
            break
        ENDIF
        IF  Timeout     THEN
            SE Fault
            break
        ENDIF
    LOOP
*/

static void NC_SB_Check_Scratch_Reg(tBOOT_STATUS *ptBootStatus)
{
    volatile UINT32 *R_SCRATCH_0 = (UINT32*)R_SCATCH_0_ADDR;
    UINT32 TOV_ON;
    UINT32 TOV_Cnt;
    BOOL TOV_EXIT_1 = FALSE;

    TOV_ON = (ptBootStatus->ptHandleBoot->tHeader.tBootSec.mSecureBootSize & 0xFU);
    TOV_Cnt = DEFAULT_CMRT_TIME_OVER_CNT;  /* default set */

    while(1)
    {
        #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "R_SCRATCH_0 : %d (0x%08x)\r\n", *R_SCRATCH_0, *R_SCRATCH_0);
        #endif
        if( (NC_SB_CMRT_IORead32(R_SCRATCH_0) == 0xFEEDBEE3U) || (TOV_EXIT_1 == TRUE) )
        {
            break;
        }

        /* Timeout Exit Condition - 4 */
        if(TOV_ON == (UINT32)CMRT_TOV_TURN_ON)
        {
            if(NC_SCU_mTimeOut((UINT64)TOV_Cnt*10U) == TRUE)
            {
                ptBootStatus->mSecureRunRes |= NC_BOOT_SECURE_TOV_FAIL_4;
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FAULT_SB_TOV_4);
                NC_MPU_LeaveSafetyGate();
                TOV_EXIT_1 = TRUE;
            }
        }
    }
}



/**
* @desc
    Bring up CMRT
* @param    UINT32          os_with_user_container_img      OS Image start address
* @param    tBOOT_STATUS*   ptBootStatus                    Boot Status
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
    CPU SRAM check
    Boot step into the bring up secure mode
    Boot step into the bring up secure stage 1 mode
    Boot step into the bring up secure stage 2 mode
    Boot step end of the bring up secure mode
*/
API void NC_SB_BringUp(UINT32 os_with_user_container_img, tBOOT_STATUS *ptBootStatus)
{
/*
	3.3.11 Determining if the RT-640 is Booting Up Correctly with the Real eSW
	While observing RT-640 progress through the multi-stage secure boot process from a Power-On Reset (POR),
	one can look for the following events to check if the expected events occurred:
	1. The High Level Operation System (HLOS) sets sys_cm_POResetn = 1'b0 to enter the power-on reset
	state.
	2. After about 5,000 cycles, HLOS sets sys_cm_POResetn = 1'b1 to exit Power-On Reset.
	3. The HLOS can read the SIC BOOT_STATUSReg[5:4] to see 2'b01, which means the SRAM check is in
	progress. The HLOS can poll the SIC BOOT_STATUSReg[5:4] for 2'b10 which indicates the SRAM check
	was successful. If SIC BOOT_STATUSReg[5:4] is 2'b11, the SRAM check failed and secure boot will not
	continue.
	4. Assuming the SRAM check was successful, the bcu2cpu_reset signal transitions from 1 to 0, indicating the
	RISC-V CPU has been released from reset.
	5. About 2 million clock cycles later, cm_sys_InitDone is asserted to indicate the RT-640 has completed the
	multi-stage secure boot process and is running in Supervisor mode.
	6. The SIC SW_BOOT_STATUSReg[3] = 1 indicates the Supervisor is running.

	;; System Control Block registers
	;; used in FPGA					                        ;; not founded yet
															#define R_SCB_VERSION            0x00
	#define R_SCB_CONTROL            0x04 ;; used in FPGA
															#define R_SCB_STATUS             0x0C
															#define R_SCB_SW_SCRATCH         0x10
	#define R_SCB_SOC_INTERRUPT_IN   0x14 ;; used in FPGA
	#define R_SCB_SOC_INTERRUPT_OUT  0x18 ;; used in FPGA
															#define R_SCB_IDLE               0x1C
															#define R_SCB_ISOLATE            0x20
															#define R_SCB_RESET_IN_PROGRESS  0x24
	#define R_SCB_POWER_MANAGEMENT   0x28 ;; used in FPGA
	#define R_SCB_TDV                0x2C ;; used in FPGA
	#define R_FMC_FEATURE_BITS       0x30 ;; used in FPGA
															#define R_SCB_KTC_BUS_KEY_0      0x34
															#define R_SCB_KTC_BUS_KEY_1      0x38
															#define R_SCB_KTC_BUS_KEY_2      0x3C
															#define R_SCB_KTC_BUS_KEY_3      0x40
	#define R_SCB_KTC_BUS_METADATA_0 0x44 ;; used in FPGA
															#define R_SCB_KTC_BUS_METADATA_1 0x48
	#define R_SCB_KTC_CONTROL        0x4C ;; used in FPGA
	#define R_SCB_KTC_OUTPUT         0x50 ;; used in FPGA
															#define R_SCB_FIPS_MODE          0x54
															#define R_SCB_TRNG_CHARACT       0x58
															#define R_SCB_TRNG_VALID_1       0x5C
															#define R_SCB_TRNG_VALID_2       0x60
															#define R_SCB_TRNG_VALID_3       0x64


	;; Addresses as seen from CMRT's CPU.  Taken from Zephyr kconfigs.
	#define CMRT_SOG_BASE_ADDR       0x00100000 ;; fboot and security monitor
	#define CMRT_SOG_SIZE            0xC000
	#define CMRT_ROM_BASE_ADDR       0x00180000 ;; optional masked rom for sboot
	#define CMRT_ROM_SIZE            0x40000
	#define CMRT_RAM_BASE_ADDR       0x00200000
	#define CMRT_RAM_SIZE            0x80000
	#define CMRT_OTP_BASE_ADDR       0x00300000
	#define CMRT_OTP_SIZE            0xD000
	#define CMRT_SAC_BASE_ADDR       0x40000000
	#define CMRT_SAC_BASE_ADDR_VCU   0x40200000
	#define CMRT_SAC_SIZE            0x80000

	;; Ref: B.16 of zynq-7000 SOC TRM v1.12.2
	#define DEVCFG_BASE_ADDR         0xF8007000
	#define DEVCFG_MEM_SIZE          0x1000
	;; Ref: Bristol FPGA Design V1.0
	#define SYSCTL_BASE_ADDR         0x40000000
	#define SYSCTL_MEM_SIZE          0x10000
	#define SIC_REG_BASE_ADDR        0x40800000
	#define SIC_REG_MEM_SIZE         0x02000
	#define SOG_LOAD_BAR0_OFFSET     0x100000
	#define SOG_LOAD_MEM_SIZE        0x0C000
	#define ROM_LOAD_BASE_ADDR       0x40200000
	#define ROM_LOAD_MEM_SIZE        0x0D000
	#define ROM_LOAD_BAR0_OFFSET     0x200000
	#define OTP_LOAD_BASE_ADDR       0x40300000
	#define OTP_LOAD_MEM_SIZE        0x0D000
	#define OTP_LOAD_BAR0_OFFSET     0x300000
	#define SRAM_LOAD_BASE_ADDR      0x40400000
	#define SRAM_LOAD_MEM_SIZE       0x80000 ;; maximum across all boards
	#define SRAM_LOAD_BAR0_OFFSET    0x400000
	#define SAC_LOAD_BASE_ADDR       0x41500000
	#define SAC_LOAD_MEM_SIZE        0x80000
	#define DM_REG_BASE_ADDR         0x41200000
	#define DM_REG_MEM_SIZE          0x10000
	#define SERIAL_REG_BASE_ADDR     0x41600000
	#define SERIAL_REG_MEM_SIZE      0x10000
	#define OEC_LOAD_BASE_ADDR       0x42500000
	#define OEC_LOAD_MEM_SIZE        0x02000
	#define FIC_REG_BASE_ADDR        0x43000000
	#define FIC_REG_MEM_SIZE         0x02000
	#define FIC_LOAD_BAR5_OFFSET     0x10000
	#define FIC_LOAD_MEM_SIZE        0x40000
    volatile UINT32 *R_HLOS2ESW_D1      = (UINT32*)(SIC_BASE + 0x634UL);
*/
    volatile UINT32 *R_SCRATCH_0 = (UINT32*)R_SCATCH_0_ADDR;
    UINT32 Reg;

    /* printf("enter %s\r\n", __func__); */
/******************************************************/
    /* BRINGUP IN */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_BRINGUP_IN, ptBootStatus);

/* PRQA S 3332 ++ */
    Reg = *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL);
    Reg &= ~((UINT32)(HARD_RESET | POWERON_RESET));
    *(ptBootStatus->ptHandleBoot->tCMRT.pSCB_CONTROL) = Reg;
/* PRQA S 3332 -- */

    NC_SB_CPU_Sram_Check(ptBootStatus);

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);
/******************************************************/

    if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
    {
        *R_SCRATCH_0 = os_with_user_container_img;

        /* 4. Assuming the SRAM check was successful, the bcu2cpu_reset signal transitions from 1 to 0, indicating the
        RISC-V CPU has been released from reset. */

        /* print_sw_boot_status(*R_SW_BOOT_STATUS); */
        /* 5. About 2 million clock cycles later, cm_sys_InitDone is asserted to indicate the RT-640 has completed the
        multi-stage secure boot process and is running in Supervisor mode . */
        /* NC_SB_Wait_Cycles(2 * 1000000, ptBootStatus); */

        /* print_sw_boot_status(*R_SW_BOOT_STATUS); */

        /* 6. The SIC SW_BOOT_STATUSReg[3] = 1 indicates the Supervisor is running. */

        /*
        last stage 					SW_BOOT_STATUS
        mw							0x0000002F = fboot:1 sboot:1 tboot:1 sv:1 cr:0 rrc:1
            user_container (=<<<NEED to confirm>>> autoload)	0x0000003F = fboot:1 sboot:1 tboot:1 sv:1 cr:1 rrc:1
        */

        NC_SB_Check_SW_Boot_Status(ptBootStatus, CMRT_BOOT_STEP_2);

        /* Clear */
        (void)NC_SCU_mTimeOut(0U);

        /* BRINGUP STAGE 1 */
        NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_BRINGUP_STAGE_1, ptBootStatus);

        if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
        {
            NC_SB_Check_SW_Boot_Status(ptBootStatus, CMRT_BOOT_STEP_3);

            /* Clear */
            (void)NC_SCU_mTimeOut(0U);

            /* BRINGUP STAGE 2 */
            NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_BRINGUP_STAGE_2, ptBootStatus);

            if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
            {
                NC_SB_Check_Scratch_Reg(ptBootStatus);
                
                /* Clear */
                (void)NC_SCU_mTimeOut(0U);
            } /* NC_BOOT_SECURE_TOV_FAIL_3 */
        } /* NC_BOOT_SECURE_TOV_FAIL_2 */
    } /* NC_BOOT_SECURE_TOV_FAIL_1 */

    /* BRINGUP OUT */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_BRINGUP_OUT, ptBootStatus);

    /* NOW, secure_boot container IS READY !!!
       Let's use decrypt service */
    /* print_sw_boot_status(*R_SW_BOOT_STATUS); */

    /* printf("leave %s\r\n", __func__); */

    /* NC_SB_Wait_Cycles(20000, ptBootStatus); */
}



/**
* @desc
    Check CMRT Register.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
* @param    UINT32          readType        Read Type
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
    IF  reaType is valid.    THEN
        The value is set in the parameter.
    ELSE
        Parameter value is'0'.
    ENDIF

    DO WHILE    TREU
        IF  CMRT value is valid     THEN
            break
        ENDIF

        IF  Timeout THEN
            SE Fault
            break
        ELSE
            Check Time
        ENDIF
    LOOP
*/
static void NC_SB_Check_CMRT_Reg(tBOOT_STATUS *ptBootStatus, UINT32 readType)
{
    volatile UINT32 *R_HLOS2ESW_LENGTH = (UINT32*)R_HLOS2ESW_LENGTH_ADDR;
    BOOL   TOV_EXIT_2 = FALSE;
    UINT32 TOV_ON;
    UINT32 TOV_Cnt;
    UINT32 FailResValue = 0x0U;
    UINT32 FaultInfo = 0x0U;
    UINT32 RegValue = 0x0U;

    if(readType == CMRT_REG_SIDEBAND_RESET)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_5;
        FaultInfo = FAULT_SB_TOV_5;
        RegValue = 0x0U;
    }
    else if(readType == CMRT_REG_DECRYPT_STAGE1)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_6;
        FaultInfo = FAULT_SB_TOV_6;
        RegValue = 0x0U;
    } else
    {
        /* No Operation */
    }

    TOV_ON = NC_SB_GetTimeOverEnable(ptBootStatus);
    TOV_Cnt = NC_SB_GetTimeOverCount(ptBootStatus);

    while (1)
    {
        if((NC_SB_CMRT_IORead32(R_HLOS2ESW_LENGTH) == RegValue) || (TOV_EXIT_2 == TRUE))
        {
            break;
        }

        /* Timeout Exit Condition - 5 */
        if(TOV_ON == (UINT32)CMRT_TOV_TURN_ON)
        {
            if(NC_SCU_mTimeOut((UINT64)TOV_Cnt*10U) == TRUE)
            {
                ptBootStatus->mSecureRunRes |= FailResValue;
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FaultInfo);
                NC_MPU_LeaveSafetyGate();
                TOV_EXIT_2 = TRUE;
            }
        }
    }
}



/**
* @desc
    Read CMRT Register.
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status Parameter
* @param    UINT32          readType        Read Type
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
    Read_Data
    IF  reaType is valid.    THEN
        The value is set in the parameter.
    ELSE
        Parameter value is'0'.
    ENDIF

    DO WHILE    TREU
        Read_Data = Read_CMRT_Register()
        IF  Read_Data>0     THEN
            break
        ENDIF

        IF  Timeout THEN
            SE Fault
            break
        ELSE
            Check Time
        ENDIF
    LOOP
*/
static void NC_SB_ReadByte_CMRT_Reg(tBOOT_STATUS *ptBootStatus, UINT32 readType)
{
    volatile UINT32 *R_ESW2HLOS_LENGTH = (UINT32*)R_ESW2HLOS_LENGTH_ADDR;
    UINT32 TOV_ON;
    UINT32 TOV_Cnt;
    UINT32 bytes_to_read;
    UINT32 FailResValue = 0x0U;
    UINT32 FaultInfo = 0x0U;
    BOOL TOV_EXIT_2 = FALSE;

    if(readType == CMRT_REG_DECRYPT_STAGE3)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_7;
        FaultInfo = FAULT_SB_TOV_7;
    }
    else if(readType == CMRT_REG_DECRYPT_STAGE4)
    {
        FailResValue = NC_BOOT_SECURE_TOV_FAIL_8;
        FaultInfo = FAULT_SB_TOV_8;
    } else
    {
        /* No Operation */
    }

    TOV_ON  = (ptBootStatus->ptHandleBoot->tHeader.tBootSec.mSecureBootSize & 0xFU);
    TOV_Cnt = DEFAULT_CMRT_TIME_OVER_CNT;  /* default set */

    while(1)
    {
        bytes_to_read = NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH);

        if( (bytes_to_read != 0x0U) || (TOV_EXIT_2 == TRUE) )
        {
            break;
        }

        /* Timeout Exit Condition - 7 */
        if(TOV_ON == (UINT32)CMRT_TOV_TURN_ON)
        {
            if(NC_SCU_mTimeOut((UINT64)TOV_Cnt*10U) == TRUE)
            {
                ptBootStatus->mSecureRunRes |= FailResValue;
                NC_MPU_EnterSafetyGate();
                NC_SE_SetFaultInfo(FaultInfo);
                NC_MPU_LeaveSafetyGate();
                TOV_EXIT_2 = TRUE;
            }
        }
    }
}



/**
* @desc
    Request decryption service
* @param    UINT32          Addr                FW Image Start Address
* @param    UINT32          system_otp_base     System OTP base
* @param    UINT32          KeySplitNum         Key split number
* @param    UINT32          DiversifyPath       Diversify path
* @param    tBOOT_STATUS    *ptBootStatus       Boot Status
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
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
    Result = NC_FAILURE
    Boot step into secure decryption mode
    Send Side band reset data
    Check response
    Boot step into secure decryption stage 1 mode
    Send command request
    Check response
    Boot step into secure decryption stage 2 mode
    Send primary key information
    Check response
    Boot step into secure decryption stage 3 mode
    Send key information length
    Check response
    Boot step into secure decryption stage 4 mode
    Send ack
    Check response
    Boot step into secure decryption stage 5 mode
    Read decryption data lenth
    Read data
    Send ack
    IF Check decryption success THEN
        Result = NC_SUCCESS
    ENDIF
    Boot step end of secure decryption mode
    Return Result
*/
API NC_ERROR NC_SB_Request_Decrypt_Service(UINT32 Addr, UINT32 system_otp_base, UINT32 KeySplitNum, UINT32 DiversifyPath, tBOOT_STATUS *ptBootStatus)
{
    volatile UINT32 *R_ESW2HLOS_D0       = (UINT32*)(SIC_BASE + 0x600UL);
    volatile UINT32 *R_SOC_INTERRUPT_OUT = (UINT32*)(SIC_BASE + 0x500UL);
    volatile UINT32 *R_HLOS2ESW_LENGTH   = (UINT32*)R_HLOS2ESW_LENGTH_ADDR;
    volatile UINT32 *R_ESW2HLOS_LENGTH   = (UINT32*)R_ESW2HLOS_LENGTH_ADDR;

    UINT32 sideband;
    UINT32 bytes_to_read;
    UINT32 interrupt_out;
    NC_ERROR ret = NC_FAILURE;
    UINT32 result = 0U;
    UINT32 length = 4U * sizeof(UINT32);

    volatile UINT32 *raw = (volatile UINT32 *)(ptBootStatus->ptHandleBoot->tCMRT.pR_HLOS2ESW_D0);

    UINT32 hdr = 0U;
    UINT32 contents[8];
    INT32 i;
    UINT32 *data = contents;
    UINT32 words = WORDS(length);
    /*UINT8 expected_value[5]; */
    UINT32 expected_value; /* New */

    /* printf("enter %s\r\n", __func__); */

    /* printf("Addr = 0x%08x\n", Addr); */
    /* printf("system_otp_base = 0x%08x\n", system_otp_base); */
    /* printf("KeySplitNum = 0x%08x\n", KeySplitNum); */
    /* printf("DiversifyPath = 0x%08x\n", DiversifyPath); */

    request_t req_ = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
    request_t *req = &req_;

    /* DECRYPT IN */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_IN, ptBootStatus);

    /*
    for (i=0; i < (INT32)sizeof(request_t); i++)
    {
        ((UINT8 *)&req)[i] = 0U;
    }
    */

    /* void * chiper_image; */
    /* req.chiper_image = 0x01040000UL; -- 0x41510000 */
    req_.chiper_image = Addr;
    /* int chiper_image_size; */
    /* req_.chiper_image_size = Size; -- not need */
    /* req_.chiper_image_size = 1264; -- sample_image_cipher_hmac.bin -- */
    /* req.chiper_image_size = 1232; -- sample_image_cipher_aes.bin */
    /* void * plain_image; -- or chiper_image in-place */
    /* int plain_image_size; */
    /* int key_mode; -- AES | HMAC */
    /* int key_place; -- System OTP passing | CMRT OTP with derivation */
    /* void * system_otp; */
    req_.system_otp = system_otp_base;
    /* int system_otp_size; */
    /* unsigned char derivation_path[32 NEED TO CONFIRM]; */
    /* int derivation_path_size; */
    req_.keysplit_num = KeySplitNum;
    req_.diversify_path = DiversifyPath;

    /* Reset communications always when starting up. */
    sideband = 0U;

    /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) == 0); */

    SET_HEADER_VER(sideband, 1U);
    SET_HEADER_CMD(sideband, SIDEBAND_RESET);
    SET_HEADER_SRC(sideband, 0U);
    NC_SB_CMRT_IOWrite32(sideband, R_HLOS2ESW_LENGTH);

    /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */
    /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */

    interrupt_out = NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT);
    NC_SB_CMRT_IOWrite32(interrupt_out, R_SOC_INTERRUPT_OUT);

    /* SEND */

    /* DATA */
    /* check_sideband_reset */
    NC_SB_Check_CMRT_Reg(ptBootStatus, CMRT_REG_SIDEBAND_RESET);

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    /* DECRYPT STAGE 1 */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_STAGE_1, ptBootStatus);

    if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
    {
        /* REQUEST */
        /* ASSERT(NC_SB_CMRT_IORead32(R_HLOS2ESW_LENGTH) == 0); */

        SET_HEADER_VER(hdr, 1U);
        SET_HEADER_CMD(hdr, CMD_REQUEST);
        SET_HEADER_SRC(hdr, 0x900U/*e->src*/);
        SET_HEADER_DST(hdr, 100U/*e->dst*/);

        /*NC_SB_CMRT_IOWrite32(hdr, raw++); */ /* Org */
        NC_SB_CMRT_IOWrite32(hdr, raw); raw++;

        /* NC_SB_CMRT_IOWrite32(0x0 e->address, raw++); */ /* Org */
        NC_SB_CMRT_IOWrite32(0x0U/*e->address*/, raw); raw++;

        NC_SB_CMRT_IOWrite32(length/*strlen("ping")*/ /*e->length*/, raw);
        NC_SB_CMRT_IOWrite32(sideband | sizeof(cmrt_sic_request_t), R_HLOS2ESW_LENGTH);

        /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */
        /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */

        interrupt_out = NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT);
        /* printf("%s:%d set 0x%08x to R_SOC_INTERRUPT_OUT and R_NON_EXISTING\r\n", __func__, __LINE__, interrupt_out); */
        NC_SB_CMRT_IOWrite32(interrupt_out, R_SOC_INTERRUPT_OUT);

        /* DATA */
        NC_SB_Check_CMRT_Reg(ptBootStatus, CMRT_REG_DECRYPT_STAGE1);

        /* Clear */
        (void)NC_SCU_mTimeOut(0U);

        /* DECRYPT STAGE 2 */
        NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_STAGE_2, ptBootStatus);

        if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
        {
            /* ASSERT(NC_SB_CMRT_IORead32(R_HLOS2ESW_LENGTH) == 0); */
            /* printf("%s:%d\r\n", __func__, __LINE__); */
            raw = (volatile UINT32 *)(ptBootStatus->ptHandleBoot->tCMRT.pR_HLOS2ESW_D0);


            /* memset(contents, 0, 32); */
            for (i=0; i<8; i++)
            {
                contents[i] = 0;
            }

            data[0] = req->chiper_image;
            data[1] = req->system_otp;
            data[2] = req->keysplit_num;
            data[3] = req->diversify_path;

            hdr = 0;
            SET_HEADER_VER(hdr, 1UL);
            SET_HEADER_CMD(hdr, CMD_DATA);
            SET_HEADER_SRC(hdr, 0x900UL/*e->src*/);
            SET_HEADER_DST(hdr, 100UL/*e->dst*/);

            /* NC_SB_CMRT_IOWrite32(hdr, raw++); */ /* Org */
            NC_SB_CMRT_IOWrite32(hdr, raw); raw++;

            /* printf("%s:%d\r\n", __func__, __LINE__); */
        #if 1 /* def HelixQACFlag_SB */
            while (words > 0U) {
                NC_SB_CMRT_IOWrite32(*data, raw);
                data++;
                raw++;
                words--;
            }
        #else /* Org */
            while (words--) { /* Org */
                NC_SB_CMRT_IOWrite32(*data++, raw++);
            }
        #endif
            /* printf("%s:%d\r\n", __func__, __LINE__); */

            /* DECRYPT STAGE 3 */
            NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_STAGE_3, ptBootStatus);

            NC_SB_CMRT_IOWrite32(sideband | (length + sizeof(cmrt_sic_header_t)), R_HLOS2ESW_LENGTH);

            /* printf("%s:%d\r\n", __func__, __LINE__); */

            /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */
            /* ASSERT(NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT) != 0); */

            interrupt_out = NC_SB_CMRT_IORead32(R_SOC_INTERRUPT_OUT);
            /* printf("%s:%d set 0x%08x to R_SOC_INTERRUPT_OUT and R_NON_EXISTING\r\n", __func__, __LINE__, interrupt_out); */
            NC_SB_CMRT_IOWrite32(interrupt_out, R_SOC_INTERRUPT_OUT);

            /* RECEIVE */
            /* wait time over */
            NC_SB_ReadByte_CMRT_Reg(ptBootStatus, CMRT_REG_DECRYPT_STAGE3);

            /* Clear */
            (void)NC_SCU_mTimeOut(0U);

            /* DECRYPT STAGE 4 */
            NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_STAGE_4, ptBootStatus);

            if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
            {
                /* RESPONSE */
                /* ASSERT(NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH) > 0); */
                /* ASSERT(NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH) > 0); */
                /* printf("recv %d bytes\r\n", bytes_to_read); */

                NC_SB_CMRT_IOWrite32(0, R_ESW2HLOS_LENGTH);

                /* DATA */
                /* ASSERT(NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH) > 0); */
                /* ASSERT(NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH) > 0); */
                NC_SB_ReadByte_CMRT_Reg(ptBootStatus, CMRT_REG_DECRYPT_STAGE4);

                /* Clear */
                (void)NC_SCU_mTimeOut(0U);

                /* DECRYPT STAGE 5 */
                NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_STAGE_5, ptBootStatus);

                if(ptBootStatus->mSecureRunRes == (UINT32)NC_SUCCESS)
                {
                    bytes_to_read = NC_SB_CMRT_IORead32(R_ESW2HLOS_LENGTH);
                    /* printf("recv %d bytes\r\n", bytes_to_read); */
                    /*
                        if (bytes_to_read == 0)
                        {
                            printf("there are no data to receive\r\n");
                            goto OUT;
                        }
                    */
                #if 1
                    raw = R_ESW2HLOS_D0;
                    raw++;
                #else /* Org */
                    raw = (UINT32 *)R_ESW2HLOS_D0;
                    hdr = NC_SB_CMRT_IORead32(raw++);
                #endif
                    /* printf("version = %d\r\n", GET_HEADER_VER(hdr)); */
                    /* printf("source flow id = %d (0x%08x)\r\n", GET_HEADER_SRC(hdr), GET_HEADER_SRC(hdr)); */
                    /* printf("command = %d\r\n", GET_HEADER_CMD(hdr)); */
                    /* printf("destination flow id = %d (0x%08x)\r\n", GET_HEADER_DST(hdr), GET_HEADER_DST(hdr)); */

                    length = bytes_to_read - sizeof(cmrt_sic_header_t);
                    words = WORDS(length);
                #if 1
                    while (words > 0U) {
                        result = NC_SB_CMRT_IORead32(raw);
                        /* printf("data - 0x%08x\r\n", result); */
                        raw++;
                        words--;
                    }
                #else /* Org */
                    while (words--) {
                        result = NC_SB_CMRT_IORead32(raw++);
                        printf("data - 0x%08x\r\n", result);
                    }
                #endif
                    NC_SB_CMRT_IOWrite32(0, R_ESW2HLOS_LENGTH);

                    /* expected_value[0] = (UINT8)'O'; */
                    /* expected_value[1] = (UINT8)'K'; */
                    /* expected_value[2] = (UINT8)'A'; */
                    /* expected_value[3] = (UINT8)'Y'; */
                    /* expected_value[4] = (UINT8)'\0'; */

                    /* New */
                    #ifdef DEBUG_ENABLE_
                    DEBUGMSG(MSGINFO, "FAIL   : is [ 0x%08x ]\r\n", expected_value = 0x4c494146U /* Fail */);
                    #endif

                    expected_value = 0x59414b4fU;  /* OKAY */
                    #ifdef DEBUG_ENABLE_
                    DEBUGMSG(MSGINFO, "OK     : is [ 0x%08x ]\r\n", expected_value);

                    /*DEBUGMSG(MSGINFO, "result : is [ 0x%08x ]\r\n", result);*/
                    DEBUGMSG(MSGINFO, "result : is [ 0x%08x ], Fault_Info:[0x%08x]\r\n", result, DBG_FAULT_INFO_REG);
                    #endif

                    /* if(result == *expected_value) */
                    if(result == expected_value) /* New */
                    {
                        ret = NC_SUCCESS;
                    }
                } /* NC_BOOT_SECURE_TOV_FAIL_8 */
            } /* NC_BOOT_SECURE_TOV_FAIL_7 */
        } /* NC_BOOT_SECURE_TOV_FAIL_6 */
    } /* NC_BOOT_SECURE_TOV_FAIL_5 */

    /* DECRYPT OUT */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_DECRYPT_OUT, ptBootStatus);

/* OUT: */
    /* printf("leave %s with %d\r\n", __func__, ret); */
    return ret;
}
