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

/* GpioToggle */
#define DBG_GPIO_PAD_ID     PAD_I2S_SCLK

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

/**
* @desc
    Set GPIO toogle
* @param        void        N/A
* @return       void        N/A
* @design
    Set GPIO toogle High or Low
*/
void NC_Gpio_toggle(void)
{
    if(TOGGLE_STATE == LOW)
    {
        TOGGLE_STATE = HIGH;
    }
    else
    {
        TOGGLE_STATE = LOW;
    }

    NC_ICU_SetPinLevel((UINT32)DBG_GPIO_PAD_ID, (BOOL)TOGGLE_STATE);
}



/**
* @desc
    Input unsigned char data.
* @param    const UINT8*    pSrc        Data source
* @param    UINT8*          pDes        Data destination
* @param    UINT32          Length      Data length
* @return   void            N/A
* @design
    Copy unsigned char data
*/
void NC_Memcpy_u08(const UINT8 *pSrc, UINT8 *pDes, const UINT32 Length)
{
	UINT32 i;

	for (i = 0u; i < Length; i++)
	{
		pDes[i] = pSrc[i];
	}
}

/**
* @desc
    Input unsigned char data.
* @param    UINT8*          pSrc        Data source
* @param    UINT8*          pDes        Data destination
* @param    UINT32          Length      Data length
* @return   void            N/A
* @design
    Copy unsigned char data
*/
void NC_Memset_u08(void *p, UINT8 c, INT32 count)
{
    /* for CodeSonar */
    INT32 i;

    for(i = 0; i < count; i++)
    {
        ((UINT8 *)p)[i] = c;
    }
}

/* =========================================================================

 =========================================================================*/
 /* qac-9.6.0-3408
    rcma-2.0.0-1503 not used */
 #if 0
void NC_Memset_u32(UINT32* addr, UINT32 value32, UINT32 num_bytes)
{
    /* for CodeSonar */
	UINT32 count = num_bytes / sizeof(UINT32);
    UINT32 index;

	for (index = count; index > 0U; index--)
	{
		*(addr++) = value32;
	}
}


/*
 *=========================================================================
 *
 *=========================================================================
 */
 void NC_Memcopy_U32(UINT32* dst, UINT32* src, UINT32 num_bytes)
{
    /* for CodeSonar */
	UINT32 index;
	UINT32 count = num_bytes / sizeof(UINT32);
    
	for (index = count; index > 0U; index--)
	{
		*(dst++) = *(src++);
	}
}

/**
 * @desc
 *  Get string length
* @param    const UINT8*    str        String
*
*    Result string size
*
*/
INT32 NC_Strlen(const UINT8 *str)
{
    const UINT8 *p;

    if (str == NULL) {
        return 0;
    }

    p = str;
    while (*p != '\0') {
        p++;
    }

    return p - str;
}
#endif
/**
* @desc
    Compare unsigned char data.
* @param    UINT8*          pSrc    Compare data 1
* @param    UINT8*          pDes    Compare data 2
* @param    UINT32          Length  Compare data legnth
* @return   INT32           Ret     NC_SUCCESS, NC_FAILURE
* @design
    Result = NC_SUCCESS
    IF Data A == Data B THEN
        Result = NC_SUCCESS
    ELSE
        Result = NC_FAILURE
    ENDIF
    Return Result
*/
INT32 NC_Compare(const UINT8 *pSrc, const UINT8* pDes, UINT32 Length)
{
    UINT32 i;
    INT32 Ret = NC_SUCCESS;

    for(i=0; i<Length; i++)
    {
        if(pSrc[i] != pDes[i])
        {
            Ret = NC_FAILURE;
            break;
        }
    }

    return Ret;
}


/**
* @desc
    Set bootstrap configuration
* @param    UINT32      BootStrap   Bootstrap value
* @return   void        N/A
* @design
    Set bootstrap configuration
*/
void NC_SetDBG_STRAP_Config(UINT32 BootStrap)
{
    DBG_STRAP_REG = BootStrap;
}


/**
* @desc
    Make checksum data.
* @param    UINT32*   pSrc        Checksum data source
* @param    UINT32          Length      Checksum data length
* @return   UINT32          CheckSum    Checksum data
* @design
    Result = 0
    Make checksum data
    Result = checksum data
    Return Result
*/
UINT32 NC_Checksum(UINT32 *pSrc, UINT32 Length)
{
    UINT32 CheckSum = 0;
    UINT32 i;

    for(i=0; i<Length; i++)
    {
        CheckSum += pSrc[i];
    }
    
    return CheckSum;
}




#ifdef DEBUG_ENABLE_
/**
* @desc
    Print debug message for core
* @param    const tARM_FAULT    pFault      ARM fault information
* @param    const CHAR          msg         Print message
* @return   void                N/A
* @struct
    typedef struct
    {
        UINT32      mSPSR;      Save process status register
        UINT32      mSP;        Stack pointer
        UINT32      mLR;        Link register
        UINT32      mReg[13];   Register
        UINT32      mPC;        Program counter
    } tARM_FAULT;
* @design
    Print core fault information.
*/
static void NC_DebugCoreDump(const tARM_FAULT *pFault, const CHAR *msg)
{
    UINT32 i = 0;

    /* Display Current Core Register */
    DEBUGMSG(MSGINFO,     "\n------------------------------------------------\n", NULL);
    DEBUGMSG(MSGERR,      " [Halt] Core %s Abort \n", msg);
    DEBUGMSG(MSGINFO,     "------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO,     "   SPSR: 0x%08x\n", pFault->mSPSR);
    DEBUGMSG(MSGINFO,     "   PC  : 0x%08x  r%02d : 0x%08x\n", pFault->mPC, i, pFault->mReg[i]);
    for(i=1U; i<12U; i+=2U)
    {
        DEBUGMSG(MSGINFO, "   r%02d : 0x%08x  r%02d : 0x%08x\n", i, pFault->mReg[i], (i+1U), pFault->mReg[i+1U]);
    }
}
#endif /* DEBUG_ENABLE_ */



/**
* @desc
    Undefined handler
* @param    tARM_FAULT      *pFault  ARM fault information
* @return   void            N/A
* @struct
    typedef struct
    {
        UINT32      mSPSR;      Save process status register
        UINT32      mSP;        Stack pointer
        UINT32      mLR;        Link register
        UINT32      mReg[13];   Register
        UINT32      mPC;        Program counter
    } tARM_FAULT;
* @design
    IF ARM mode is Thumb mode THEN
        Program counter minus 2
    ELSE
        Program counter minus 4
    ENDIF
    Set undefined fault
*/
/* PRQA S 1503 ++ */
void NC_Undefined_Handler(tARM_FAULT *pFault)
{
    /* Check Thumb Mode */
    if((pFault->mSPSR & (1UL<<5)) == (1UL<<5))
    {
        pFault->mPC -= 2U;
    }
    else
    {
        pFault->mPC -= 4U;
    }

    #ifdef DEBUG_ENABLE_
        NC_DebugCoreDump(pFault, "Undefined");
    #endif

    NC_MPU_EnterSafetyGate();
    NC_SE_NotifyFailure(FAULT_UNDEF);
    NC_MPU_LeaveSafetyGate();
}
/* PRQA S 1503 -- */


/**
* @desc
    Prefetch handler
* @param    tARM_FAULT      *pFault  ARM fault information
* @return   void            N/A
* @struct
    typedef struct
    {
        UINT32      mSPSR;      Save process status register
        UINT32      mSP;        Stack pointer
        UINT32      mLR;        Link register
        UINT32      mReg[13];   Register
        UINT32      mPC;        Program counter
    } tARM_FAULT;
* @design
    Program counter minus 4
    Set prefetch fault
*/
/* PRQA S 1503 ++ */
void NC_Prefetch_Handler(tARM_FAULT *pFault)
{
    pFault->mPC -= 4U;

    #ifdef DEBUG_ENABLE_
        NC_DebugCoreDump(pFault, "Prefetch");
    #endif

    NC_MPU_EnterSafetyGate();
    NC_SE_NotifyFailure(FAULT_PREF);
    NC_MPU_LeaveSafetyGate();
}
/* PRQA S 1503 -- */


/**
* @desc
    Abort handler
* @param    tARM_FAULT      *pFault  ARM fault information
* @return   void            N/A
* @struct
    typedef struct
    {
        UINT32      mSPSR;      Save process status register
        UINT32      mSP;        Stack pointer
        UINT32      mLR;        Link register
        UINT32      mReg[13];   Register
        UINT32      mPC;        Program counter
    } tARM_FAULT;
* @design
    Program counter minus 8
    Set abort fault
*/
/* PRQA S 1503 ++ */
void NC_Abort_Handler(tARM_FAULT *pFault)
{
    pFault->mPC -= 8U;

    #ifdef DEBUG_ENABLE_
        NC_DebugCoreDump(pFault, "Data");
    #endif

    NC_MPU_EnterSafetyGate();
    NC_SE_NotifyFailure(FAULT_ABORT);
    NC_MPU_LeaveSafetyGate();
}
/* PRQA S 1503 -- */

/* End Of File */
