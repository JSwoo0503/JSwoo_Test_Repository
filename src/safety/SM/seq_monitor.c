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
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

#if (BL_SEL == 2)
static volatile DRV_A6_SYS_SCU_REGISTER* const RegA6_SYS_SCU = (DRV_A6_SYS_SCU_REGISTER*)APACHE_A6_SYS_SCU_BASE_ADDR;
#endif

/*
********************************************************************************
*               IMPORTED FUNCTION DEFINITIONS
********************************************************************************
*/
typedef struct
{
    union
    {
        UINT32  Reg;                                        /* Secure Boot Step Information */
        struct {
                UINT32 SECURE_STP_INFO                 :16; /* [  0:15] Secure Boot Step information */
                UINT32 DO_NOT_ACCESS                   :16; /* [ 16:31] DO_NOT_ACCESS */
        } Bit;
    }mData;
} tSECURE_STEP_INFO;


typedef struct
{
    UINT32        WS_StepInfo;                          /* Step Information */
    UINT32        WS_Stage;                             /* Step Stage */
    tBOOT_STATUS  *ptWS_BootStatus;                     /* Boot Status Information */
}tWARRANT_STEP_INFO;


typedef struct
{
    UINT32        Step1;                                /* STEP 1 */
    UINT32        Step2;                                /* STEP 2 */
}tSTEP_INFO_BUNDLE;







/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Set Boot step.
* @param    UINT32      Start       Start position
* @param    UINT32      End         End position
* @param    UINT32*     pResStep    Result Step
* @return   void
* @design
    DO WHILE    Start position >= End position
        Result Step = step
        Start position --
    LOOP
*/
static void NC_SM_SetBootStep(UINT32 Start, UINT32 End, UINT32 *pResStep)
{
    INT32 Step;
    UINT32 Shift;

    Step = (INT32)Start;
    while(Step >= (INT32)End)
    {
        Shift = ((UINT32)Step - End);
        *pResStep |= (1UL << (UINT8)Shift);
        --Step;
    }
}



/**
* @desc
    Get last boot step information
* @param    tWARRANT_STEP_INFO  *ptStepInfo     Boot step information
* @param    UINT32              *pResStep1      Boot step 1 result information
* @param    UINT32              *pResStep2      Boot step 2 result information
* @return   void
* @struct
    typedef struct
    {
        UINT32        WS_StepInfo;              Step Information
        UINT32        WS_Stage;                 Step Stage
        tBOOT_STATUS  *ptWS_BootStatus;         Boot Status Information
    }tWARRANT_STEP_INFO;
* @design
    Select Case Check boot strap
        Case eMMC
            Set eMMC boot step result information
        case SD Card
            Set SD card boot step result information
        Case Serial flash
            Set serial flash boot step result informaition
        Case UART
            Set UART boot step result information
        Case Else
            Set USB boot step result information
    End Select
*/
/* TODO : 여기 있는 code flow는 어떻게 동작하는지 이해가 되지않는다.. 테스트를 어떻게 할까? */
static void NC_SM_GetLastBootStep(tWARRANT_STEP_INFO *ptStepInfo, UINT32 *pResStep1, UINT32 *pResStep2)
{
    UINT32   Step2;
    UINT32   Sh2;

    switch (ptStepInfo->ptWS_BootStatus->ptHandleBoot->tStrap.Bit.mBootMemory)
    {
        case E_BOOT_EMMC:
            *pResStep1 = 0x000FFFFFU;

            NC_SM_SetBootStep(ptStepInfo->WS_StepInfo, DBG_STP_JUMP, pResStep2);
            *pResStep2 = *pResStep2 << (DBG_STP_JUMP-32U);
            break;

        case E_BOOT_SDCARD:
            NC_SM_SetBootStep(DBG_STP_SDCARD_DEINIT_OUT, DBG_STP_SDCARD_INIT_IN, pResStep1);

            *pResStep1 = *pResStep1 << DBG_STP_SDCARD_INIT_IN;
            *pResStep1 |= 0x3FFFU;

            NC_SM_SetBootStep(ptStepInfo->WS_StepInfo, DBG_STP_JUMP, pResStep2);
            *pResStep2 = *pResStep2 << (DBG_STP_JUMP-32U);
            break;

        case E_BOOT_SFLASH:
        case E_BOOT_SPI_CLK_INVD: 
            NC_SM_SetBootStep(DBG_STP_SF_IMG_LOAD_OUT, DBG_STP_SF_INIT_IN, pResStep1);
            *pResStep1 = *pResStep1 << DBG_STP_SF_INIT_IN;
            *pResStep1 |= 0x3FFFU;

            NC_SM_SetBootStep(ptStepInfo->WS_StepInfo, DBG_STP_JUMP, pResStep2);
            *pResStep2 = *pResStep2 << (DBG_STP_JUMP-32U);
            break;

        case E_BOOT_UART:
            *pResStep1 = 0x3FFFU;
   
            Step2 = DBG_STP_YMODEM_IMG_LOAD_OUT;
            while(Step2 >= DBG_STP_YMODEM_INIT_IN)
            {
                Sh2 = (Step2 - DBG_STP_YMODEM_INIT_IN);
                *pResStep2 |= (1UL << (UINT8)Sh2);
                --Step2;
            }

            /* *pResStep2 = *pResStep2 << (DBG_STP_YMODEM_INIT_IN-32U); */
            Step2 = ptStepInfo->WS_StepInfo;
            while(Step2 >= DBG_STP_JUMP)
            {
                *pResStep2 |= (1UL << (UINT8)(Step2-32U));
                --Step2;
            }
            break;

        default: /* case E_BOOT_USB: */
            *pResStep1 = 0x3FFFU;

            Step2 = DBG_STP_USB_IMG_LOAD_OUT;
            while(Step2 >= DBG_STP_USB_INIT_IN)
            {
                Sh2 = (Step2 - DBG_STP_USB_INIT_IN);
                *pResStep2 |= (1UL << (UINT8)Sh2);
                --Step2;
            }
            *pResStep2 = *pResStep2 << (DBG_STP_USB_INIT_IN-32U);

            Step2 = ptStepInfo->WS_StepInfo;
            while(Step2 >= DBG_STP_JUMP)
            {
                *pResStep2 |= (1UL << (UINT8)(Step2-32U));
                --Step2;
            }
            break;
    }
}



/**
* @desc
    Get golden boot step information
* @param    tWARRANT_STEP_INFO  *ptWS_StepInfo      Boot step information
* @param    tSTEP_INFO_BUNDLE   *ptBundleStep       Boot step bundle information
* @param    UINT32              MAX_STEP            Maximum boot step
* @param    UINT32              MIN_STEP            Minimum boot step+
* @return   void
* @struct
    typedef struct
    {
        UINT32        WS_StepInfo;                  Step Information
        UINT32        WS_Stage;                     Step Stage
        tBOOT_STATUS  *ptWS_BootStatus;             Boot Status Information
    }tWARRANT_STEP_INFO;
* @struct
    typedef struct
    {
        UINT32        Step1;                        Boot step 1
        UINT32        Step2;                        Boot step 2
    }tSTEP_INFO_BUNDLE;
* @design
    IF Boot step information is not last state THEN
        Set boot step information on each stage
    ELSE
        Set boot step information from boot strap information
    ENDIF
*/
static void NC_SM_GetGoldenBootStep(tWARRANT_STEP_INFO *ptWS_StepInfo, tSTEP_INFO_BUNDLE *ptBundleStep, UINT32 MAX_STEP, UINT32 MIN_STEP)
{
    UINT32   TempStep1;
    UINT32   TempStep2;
    UINT32   Shift1;
    UINT32   Shift2;

    switch (ptWS_StepInfo->WS_Stage)
    {
        case SM_STAGE_4:
            if(ptWS_StepInfo->WS_StepInfo <= MAX_STEP)
            {
                Shift1 = 31U - ptWS_StepInfo->WS_StepInfo;
                ptBundleStep->Step1 = 0xFFFFFFFFU << Shift1;
                ptBundleStep->Step1 = ptBundleStep->Step1 >> Shift1;
            }
            break;
        case SM_STAGE_5:
        case SM_STAGE_6:
            if(ptWS_StepInfo->WS_StepInfo <= MAX_STEP)
            {
                TempStep1 = ptWS_StepInfo->WS_StepInfo;
                while(TempStep1 >= MIN_STEP)
                {
                    Shift1 = (TempStep1 - MIN_STEP);
                    ptBundleStep->Step1 |= (1UL << (UINT8)Shift1);
                    --TempStep1;
                }
                ptBundleStep->Step1 = ptBundleStep->Step1 << MIN_STEP;
                ptBundleStep->Step1 |= 0x3FFFU;
            }
            break;
        case SM_STAGE_7:
        case SM_STAGE_8:
            if(ptWS_StepInfo->WS_StepInfo <= MAX_STEP)
            {
                ptBundleStep->Step1 = 0x3FFFU;

                TempStep2 = ptWS_StepInfo->WS_StepInfo;
                while(TempStep2 >= MIN_STEP)
                {
                    Shift2 = (TempStep2 - MIN_STEP);
                    ptBundleStep->Step2 |= (1UL << (UINT8)Shift2);
                    --TempStep2;
                }
                ptBundleStep->Step2 = ptBundleStep->Step2 << (MIN_STEP-32U);
            }
            break;
        default: /* case SM_STAGE_9 */
            if(ptWS_StepInfo->WS_StepInfo <= DBG_STP_BOOT_FAIL_WAIT)
            {
                NC_SM_GetLastBootStep(ptWS_StepInfo, &ptBundleStep->Step1, &ptBundleStep->Step2);
            }
            break;
    }
}



/**
* @desc
    Check flow step.
* @param    UINT32                  StepInfo        Step Infomation value
* @param    tSTEP_INFO_BUNDLE*      pBundleStep     Step Struct
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF  Step Struct is valid    THEN
        IF  Step Infomation value is valid  THEN
            Check Step
            IF  Step check failed.  THEND
                SE Fault
            ELSE
                Ret = NC_SUCCESS
            ENDIF
        ELSE
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Ret = NC_FAILURE
    ENDIF

    Return Ret
*/
static NC_ERROR NC_SM_CheckFlowSecureStep(UINT32 StepInfo, tSTEP_INFO_BUNDLE *pBundleStep)
{
    NC_ERROR Ret;
    UINT32 Shiftbit;
    tSECURE_STEP_INFO* ptSECURE_STEP = (tSECURE_STEP_INFO*)(volatile int)&DBG_SSTP_SRC_QSRC_REG;

    if(pBundleStep != NULL) 
    {
        if(StepInfo > DBG_STP_SECURE_RUN_OUT)
        {
            /* Invalid Parameter */
            Ret = NC_FAILURE;
        }
        else
        {
            Shiftbit = (31U - StepInfo);
            pBundleStep->Step1 = 0xFFFFFFFFU << Shiftbit;
            pBundleStep->Step1 = pBundleStep->Step1 >> Shiftbit;

            /* Check SM Step */
            if(pBundleStep->Step1 != ptSECURE_STEP->mData.Bit.SECURE_STP_INFO)
            {
                NC_MPU_EnterSafetyGate();
                NC_SE_NotifyFailure(FAULT_SM);
                NC_MPU_LeaveSafetyGate();
            }
            Ret = NC_SUCCESS;
        }
    } 
    else
    {
        Ret = NC_FAILURE;
    }


    return Ret;
}



/**
* @desc
    Check the boot sequence
* @param    UINT32          StepInfo        Boot step information
* @param    tBOOT_STATUS    *ptBootStatus   Boot status
* @param    UINT32          SNS_STEP        Boot step
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
    Result NC_FAILURE
    Select Case Boot step
        Case Normal boot step
            IF Boot step is fail THEN
                Result = NC_FAILURE
            ELSE
                Check boot step stage
                Set boot step information
            ENDIF
            IF Boot step result is ok THEN
                Result = NC_SUCCESS
            ELSE
                Set boot step fault
            ENDIF
        Case Secure boot step
            IF Boot step is not secure boot mode THEN
                Result = NC_FAILURE
            ELSE
                Set secure boot result information
                IF Boot step result is ok THEN
                    Result = NC_SUCCESS
                ELSE
                    Set boot step fault
                ENDIF
            ENDIF
        Case Else
            Result = NC_FAILURE
    End Select
    Return Result
*/
NC_ERROR NC_SM_CheckFlow(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus, UINT32 SNS_STEP)
{
    NC_ERROR           Ret;
    tSTEP_INFO_BUNDLE  tBundleStep;
    tWARRANT_STEP_INFO tWarrant_info;

    tWarrant_info.WS_StepInfo     = StepInfo;
    tWarrant_info.ptWS_BootStatus = ptBootStatus;
    tBundleStep.Step1    = 0U;
    tBundleStep.Step2    = 0U;

    switch(SNS_STEP)
    {
        case NS_STEP:
            if(StepInfo > DBG_STP_BOOT_FAIL_WAIT)
            {
                /* Invalid Parameter */
                Ret = NC_FAILURE;
            }
            else
            {
                if(StepInfo <= DBG_STP_EMMC_DEINIT_OUT)
                {
                    tWarrant_info.WS_Stage = SM_STAGE_4;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_EMMC_DEINIT_OUT, 0U);
                }
                else if(StepInfo <= DBG_STP_SDCARD_DEINIT_OUT)
                {
                    tWarrant_info.WS_Stage = SM_STAGE_5;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_SDCARD_DEINIT_OUT, DBG_STP_SDCARD_INIT_IN);
                }
                else if(StepInfo <= DBG_STP_SF_IMG_LOAD_OUT)
                {
                    tWarrant_info.WS_Stage = SM_STAGE_6;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_SF_IMG_LOAD_OUT, DBG_STP_SF_INIT_IN);
                }
                else if(StepInfo <= DBG_STP_YMODEM_IMG_LOAD_OUT)
                {
                    tWarrant_info.WS_Stage = SM_STAGE_7;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_YMODEM_IMG_LOAD_OUT, DBG_STP_YMODEM_INIT_IN);
                }
                else if(StepInfo <= DBG_STP_USB_IMG_LOAD_OUT)
                {
                    tWarrant_info.WS_Stage = SM_STAGE_8;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_USB_IMG_LOAD_OUT, DBG_STP_USB_INIT_IN);
                }
                else /* (StepInfo <= DBG_STP_BOOT_FAIL_WAIT) */
                {
                    tWarrant_info.WS_Stage = SM_STAGE_9;
                    NC_SM_GetGoldenBootStep(&tWarrant_info, &tBundleStep, DBG_STP_BOOT_FAIL_WAIT, 0U);
                }

                /* Check SM Step */
                if((tBundleStep.Step1 != DBG_STP1_REG) || (tBundleStep.Step2 != DBG_STP2_REG))
                {
                    NC_MPU_EnterSafetyGate();
                    NC_SE_NotifyFailure(FAULT_SM);
                    NC_MPU_LeaveSafetyGate();
                }
                Ret = NC_SUCCESS;
            }
            break;
        case S_STEP:
            Ret = NC_SM_CheckFlowSecureStep(StepInfo, &tBundleStep);
            break;
        default:
            Ret = NC_FAILURE;
            break;
    }

    return Ret;
}



/**
* @desc
    Set the debug to boot result
* @param    NC_ERROR        Ret             Boot result
* @param    tBOOT_STATUS    *ptBootStatus   Boot status
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
    IF boot result is success THEN
        Save OK on Boot status register
    ELSE
        Save F1 on Boot status register
    ENDIF
*/
void NC_SM_SetBOOT_Result(NC_ERROR Ret, tBOOT_STATUS *ptBootStatus)
{
    if(Ret == NC_SUCCESS)
    {
#ifdef BL1_
        /* OK */
        DBG_BL_RES_REG &= 0xFFFF0000U;
        DBG_BL_RES_REG |= (0x0000FFFFU & (((UINT32)((CHAR)'K') << 8) | ((UINT32)((CHAR)'O') << 0)));
        ptBootStatus->mBootDone_Res = NC_BOOT_DONE_SUCCESS;
#else /* BL2_ */
        /* OK */
#endif
    }
    else
    {
#ifdef BL1_
        /* FAIL : F1 */
        DBG_BL_RES_REG &= 0xFFFF0000U;
        DBG_BL_RES_REG |= (0x0000FFFFU & (((UINT32)((CHAR)'1') << 8) | ((UINT32)((CHAR)'F') << 0)));
        ptBootStatus->mBootDone_Res = NC_BOOT_DONE_FAIL;
#else /* BL2_ */
        /* FAIL : F2 */
#endif
    }

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "\n---------- DBG REG ------------\n", NULL);
    DEBUGMSG(MSGINFO, "DBG_VER_REG           : 0x%08X\n", DBG_VER_REG);
    DEBUGMSG(MSGINFO, "DBG_STP1_REG          : 0x%08X\n", DBG_STP1_REG);
    DEBUGMSG(MSGINFO, "DBG_STP2_REG          : 0x%08X\n", DBG_STP2_REG);
    DEBUGMSG(MSGINFO, "DBG_SSTP_SRC_QSRC_REG : 0x%08X\n", DBG_SSTP_SRC_QSRC_REG);
    DEBUGMSG(MSGINFO, "DBG_BL_RES_REG        : 0x%08X\n", DBG_BL_RES_REG);
    DEBUGMSG(MSGINFO, "DBG_STRAP_REG         : 0x%08X\n", DBG_STRAP_REG);
    DEBUGMSG(MSGINFO, "DBG_OTP_1_REG         : 0x%08X\n", DBG_OTP_1_REG);
    DEBUGMSG(MSGINFO, "DBG_OTP_2_REG         : 0x%08X\n", DBG_OTP_2_REG);
    DEBUGMSG(MSGINFO, "DBG_SUMMARY_REG       : 0x%08X\n", DBG_BOOT_SUMMARY_REG);
    DEBUGMSG(MSGINFO, "DBG_FAULT_INFO_REG    : 0x%08X\n", DBG_FAULT_INFO_REG);
    DEBUGMSG(MSGINFO, "------------------------------\n", NULL);

    if(Ret == NC_SUCCESS)
    {
        DEBUGMSG(MSGWARN, "\n >>>>> BL_%d Success\n", BL_SEL);
    }
    else
    {
        DEBUGMSG(MSGERR, "\n >>>>> BL_%d Failure\n", BL_SEL);
    }
#endif
}



/**
* @desc
    Get Retry Count.
* @param    UINT32  Interface ID
* @return   UINT32  Count value
* @design
    Cnt
    IF  Interface ID is SPI ID. THEN
        Cnt = SPI Retry count.
    ELSE
        Cnt = QSPI Retry count.
    ENDIF
    Return Cnt
*/
static UINT32 NC_SM_GetMediaRetryCnt(UINT32 InterfaceId)
{
    UINT32 Cnt;

    Cnt = DBG_SSTP_SRC_QSRC_REG;

    if(InterfaceId == E_SPI_CTRL_SPI)
    {
        Cnt = (UINT32)((Cnt >> 16U) & 0xFFU);
    }
    else /* InterfaceId == E_SPI_CTRL_QSPI */
    {
        Cnt = (UINT32)(Cnt >> 24U);
    }

    return Cnt;
}



/**
* @desc
    Set RETRY count
* @param    UINT32  Interface ID
* @return   void
* @design
    Set RETRY count
*/
void NC_SM_SetRETRY_Count(UINT32 InterfaceId)
{
    UINT32 Reg;
    UINT32 Cnt;

    Cnt = NC_SM_GetMediaRetryCnt(InterfaceId);

    if(Cnt < 255U)
    {
        Cnt++;
        Reg = DBG_SSTP_SRC_QSRC_REG;
        if(InterfaceId == E_SPI_CTRL_SPI)
        {
            Reg &= ~(0x00FF0000U);
            Cnt = (UINT32)((Cnt << 16) | Reg);
        }
        else /* InterfaceId == E_SPI_CTRL_QSPI */
        {
            Reg &= ~(0xFF000000U);
            Cnt = (UINT32)((Cnt << 24) | Reg);
        }
        DBG_SSTP_SRC_QSRC_REG = Cnt;
    }
}



/**
* @desc
    Set the secure boot step
* @param    UINT32          StepInfo        Boot step information
* @param    tBOOT_STATUS    *ptBootStatus   Boot status
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
    IF Boot step is secure boot step THEN
        Set secure boot step information
    ENDIF
    IF Current status is not fault THEN
        Check secure boot step
    ENDIF
*/
void NC_SM_SetBOOT_SecureStep(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus)
{
    if(StepInfo < 16U)
    {
        DBG_SSTP_SRC_QSRC_REG |= ((UINT32)1U << StepInfo);
    }

    if(STATUS_SW_FAULT == 0U)
    {
        /* Booting sequence monitor function call */
        (void)NC_SM_CheckFlow(StepInfo, ptBootStatus, S_STEP);
    }
}



/**
* @desc
    Set boot step
* @param    UINT32          StepInfo        Boot step information
* @param    tBOOT_STATUS    ptBootStatus    Boot status
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
    Check current boot step stage
    Set boot complete time
    IF Current status is not fault THEN
        Check boot step
    ENDIF
*/
void NC_SM_SetBOOT_Step(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus)
{
    if(StepInfo < 32U)
    {
        DBG_STP1_REG   |= (1UL << (UINT8)StepInfo);
    }
    else
    {
        DBG_STP2_REG   |= (1UL << (UINT8)(StepInfo - 32U));
    }

    if(StepInfo == DBG_STP_JUMP)
    {
        DBG_BOOT_COMPLETE_TIME = (UINT32)nc_get_msec(FALSE);
    }

    if(STATUS_SW_FAULT == 0U)
    {
        /* Booting sequence monitor function call */
        (void)NC_SM_CheckFlow(StepInfo, ptBootStatus, NS_STEP);        
    }
}



/**
* @desc
    Sequence monitor initialize
* @param    UINT32  Val     Set sequence monitor value
* @return   void
* @design
    Initialize sequence monitor
*/
void NC_SM_Initialize(UINT32 Val)
{
    DBG_VER_REG         = (((UINT32)BL_SEL       << 24)     /* 1. VERSION */
                         | ((UINT32)BL_VER_MAJOR << 16)
                         | ((UINT32)BL_VER_MINOR << 8)
                         | ((UINT32)BL_VER_PATCH));

    DBG_STP1_REG            = Val;                          /* 2. Sequence Monitor Step1 Information */
    DBG_STP2_REG            = Val;                          /* 3. Sequence Monitor Step2 Information */
    DBG_SSTP_SRC_QSRC_REG   = Val;                          /* 4. SSTEP(16), SPI-RetryCnt(8), QSPI-RetryCnt(8) */
    DBG_BL_RES_REG          = Val;                          /* 5. BL1(16)-(OK:F1),  BL2(16)-(OK:F2) */
    DBG_STRAP_REG           = Val;                          /* 6. Strap Information */
    DBG_OTP_1_REG           = Val;                          /* 7. OTP_1 Information */
    DBG_FAULT_INFO_REG      = Val;                          /* 8. Fault Information */
    DBG_OTP_2_REG           = Val;                          /* 9. OTP_2 Information */

    TOGGLE_STATE            = 0U;
}

/* End Of File */
