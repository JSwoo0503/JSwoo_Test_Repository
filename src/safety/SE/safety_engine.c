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
#include "safety_engine.h"
#include "seq_monitor.h"

#include "MPU.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

/* PRQA S 0303,0306,3218++ */ /* For VectorCAST */
volatile DRV_A6_SE_REGISTER* const RegA6_SE = (DRV_A6_SE_REGISTER*)APACHE_A6_SE_BASE_ADDR;
/* PRQA S 0303,0306,3218-- */
/*
********************************************************************************
*               IMPORTED FUNCTION DEFINITIONS
********************************************************************************
*/


extern void _sys_exit(void);

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

/**
* @desc
    Save fail information at secure engine register
* @param    UINT32  Type    Fail type
* @return   void
* @design
    IF  The type is failure THEN
        Set notifyfailure
    ENDIF
*/
void NC_SE_NotifyFailure(UINT32 Type)
{
    if(Type < FAULT_SW_MAX)
    {
        NC_SE_SetFaultInfo(Type);
#if (BL_SEL == 1)
    #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "Fault_Info:[0x%08x]\r\n", DBG_FAULT_INFO_REG);
    #endif
#endif
        /* SE_ENABLE */

        /* SE_SW_FAULT_TRIG_EN */
        RegA6_SE->SE__SW__FT__MASK.Bit.SE__FT__MASK |= (1UL << Type);
#if (BL_SEL == 1)
        if(RegA6_SE->SE__MODE.Bit.EN == ENABLE)
        {
            /* SE_SW_FAULT_TRIG */
            RegA6_SE->SE__SW__SAFETY.Bit.ERR |= (1UL << Type);

            _sys_exit();
        }
#endif
        /* Wait (set bit Check) */
        /*while(( RegA6_SE->SE__SW__FT__STAT.Reg & Type) != Type)
        {
        }*/
    }
}



/**
* @desc
    Set fault information
* @param    UINT32  Type    Failure type
* @return   void
* @design
    Set fault information
*/
void NC_SE_SetFaultInfo(UINT32 Type)
{
    DBG_FAULT_INFO_REG |= (1UL << Type);
}



/**
* @desc
    Safy engine initialize
* @param    tBOOT_INFO      *ptBootInfo      Boot information
* @param    tBOOT_STATUS    *ptBootStatus    Boot status
* @return   void
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;       Boot Image header info
        tBOOT_IMG   tImage;        Boot Image info
        tBOOT_STRAP tStrap;        Boot strap info
        tBOOT_CLK   tClock;        Boot clock info
        tBOOT_CMRT  tCMRT;         Boot CMRT info
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
    Boot step info safty engine mode
    IF Safety mode == disable THEN
        Set disable
    ELSE
        Set enable
        IF cpu reset fault == cpu reset THEN
            Hardware reset
        ELSEIF cpu reset fault == cpu hold THEN
            Cpu hold
        ELSE
            Skip fault set
        ENDIF
        Hardware fault mask enable
    ENDIF
    Boot step end of the safty engine mode
*/
void NC_SE_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    /* SE IN */
    NC_SM_SetBOOT_Step(DBG_STP_SE_IN, ptBootStatus);

    /* Check : 1.OTP -> 2.tHeader */
    if(ptBootInfo->tImage.mSafetyMode == E_SAFETY_MODE_DISABLE)
    {
        RegA6_SE->SE__MODE.Bit.SAFE_OE = DISABLE;
        RegA6_SE->SE__MODE.Bit.EN      = DISABLE;
    }
    else
    {
        RegA6_SE->SE__MODE.Bit.EN = ENABLE;

        if(ptBootInfo->tImage.mFaultCpuReset == E_FAULT_BEHAVIOUR_CPU_RESET)
        {
            /* Go to HW RST */
            RegA6_SE->SE__MODE.Bit.SAFE_OE = ENABLE;
        }
        else if(ptBootInfo->tImage.mFaultCpuReset == E_FAULT_BEHAVIOUR_CPU_HOLD)
        {
            /* CPU Hold */
            RegA6_SE->SE__MODE.Bit.SAFE_OE = DISABLE;
        }
        else /* E_FAULT_BEHAVIOUR_SKIP */
        {
            RegA6_SE->SE__MODE.Bit.SAFE_OE = DISABLE;
        }

        /* SW FT Mask All Enable */
        RegA6_SE->SE__SW__FT__MASK.Bit.SE__FT__MASK = 0xFFFFFFFFU;

#ifndef FPGA_MODE_
        /* HW FT Mask Enable */
        /* Mem */
        RegA6_SE->SE__HW__FT__MASK.Bit.BLK_MEM = ENABLE;
        RegA6_SE->MEM__FT__MASK.Bit.ROM_ERR    = ENABLE;
        RegA6_SE->MEM__FT__MASK.Reg = 0x7FFFFFFC;

        /* CPU */
        RegA6_SE->SE__HW__FT__MASK.Bit.BLK_CPU = ENABLE;
#endif
        /* RT640 */
        RegA6_SE->SE__HW__FT__MASK.Bit.BLK_SECURE = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0  = ENABLE;
        RegA6_SE->SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1  = ENABLE;

        RegA6_SE->SE__OP_CTRL.Bit.ENDOFBOOTUP = ENABLE;

        if((RegA6_SE->SE__OP_STAT.Bit.OP_CURR == SE_MODE_RESET)
           || (RegA6_SE->SE__OP_STAT.Bit.OP_CURR == SE_MODE_SAFE)
           || (RegA6_SE->SE__OP_STAT.Bit.OP_CURR == SE_MODE_POT))
        {            
            ptBootStatus->mSafetyModeRes = E_INIT_FAIL;
        }
        else
        {
            ptBootStatus->mSafetyModeRes = E_SUCCESS;
        }
    }
    
    /* SE OUT */
    NC_SM_SetBOOT_Step(DBG_STP_SE_OUT, ptBootStatus);
}

/* End Of File */

