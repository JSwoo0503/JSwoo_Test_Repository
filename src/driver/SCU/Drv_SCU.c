/**
********************************************************************************
*
*  Copyright (C) 2020 NEXTCHIP Inc. All rights reserved.
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
#include "Drv_SCU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

/*
********************************************************************************
*              DEFINE
********************************************************************************
*/
 
#if 0
#define DEF_TICK_CLS_
#endif

/*#define KHZ                     (1000U)*/
#define MHZ                     (1000000U)

#define SYS_CK_XI_24M_FEQ       (24U * MHZ)
/*#define SAFE_CK_XI_24M_FEQ      (24U * MHZ)*/

/* OSC = 24Mhz */
#define SYS_CK_XI_FEQ           (SYS_CK_XI_24M_FEQ)


#define BLK_POR_RST_HSP_ID          (0U)
#define BLK_POR_RST_USB_ID          (1U)

#define PMU_BLK_USB_ID              (0U)

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/
/* PRQA S 0303,0306,3218 ++ */
volatile DRV_A6_SYS_SCU_REGISTER* const RegA6_SYS_SCU = (DRV_A6_SYS_SCU_REGISTER*)APACHE_A6_SYS_SCU_BASE_ADDR;
volatile DRV_A6_HSP_SCU_REGISTER* const RegA6_HSP_SCU = (DRV_A6_HSP_SCU_REGISTER*)APACHE_A6_HSP_SCU_BASE_ADDR;
volatile DRV_A6_CPU_SCU_REGISTER* const RegA6_CPU_SCU = (DRV_A6_CPU_SCU_REGISTER*)APACHE_A6_CPU_SCU_BASE_ADDR;
/* PRQA S 1514,3408 ++ */
volatile DRV_A6_PMU_REGISTER*     const RegA6_PMU_SCU = (DRV_A6_PMU_REGISTER*)APACHE_A6_PMU_BASE_ADDR;
/* PRQA S 1514,3408 -- */
#if defined(USB_DLOAD_)
volatile DRV_A6_USB_SCU_REGISTER* const RegA6_USB_SCU = (DRV_A6_USB_SCU_REGISTER*)APACHE_A6_USB_SCU_BASE_ADDR;
/* volatile DRV_A6_PMU_REGISTER*     const RegA6_PMU_SCU = (DRV_A6_PMU_REGISTER*)APACHE_A6_PMU_BASE_ADDR; */ /* rcma-2.0.0-1514 only reference by function ... */
#endif
/* PRQA S 0303,0306,3218 -- */

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

#if 0
/*
 * Disabled due to build error
 *  [Error code]
 *  driver/SCU/Drv_SCU.c:111:17: error: unused function 'NC_USB_PowerOnOff' [-Werror,-Wunused-function]
 *  static NC_ERROR NC_USB_PowerOnOff(BOOL pon)
 */  

static NC_ERROR NC_Wait_SCSTATUS(UINT8 value)
{
    NC_ERROR result = NC_SUCCESS;
    UINT32 Status = 0U;

    while(1)
    {
        if(RegA6_PMU_SCU->SC_STATUS_BLK_USB.Bit.SC_STATUS_BLK_USB == value)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(1000U) == TRUE)
        {
            result = NC_FAILURE;
            Status = (UINT32)1U;
        }

        if(Status == 1U)
        {
            break;
        }
    }
    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    return result;
}

static NC_ERROR NC_USB_PowerOnOff(BOOL pon)
{
    NC_ERROR result = NC_SUCCESS;

    if(pon == TRUE)
    {
        RegA6_PMU_SCU->PWR_OFF_BLK_USB.Bit.PWR_OFF_BLK_USB = 0U;
        if(NC_Wait_SCSTATUS(0U) == NC_FAILURE)
        {
            RegA6_PMU_SCU->PWR_OFF_BLK_USB.Bit.PWR_OFF_BLK_USB = 1U;
            (void)nc_mdelay(1U);
            RegA6_PMU_SCU->PWR_OFF_BLK_USB.Bit.PWR_OFF_BLK_USB = 0U;
            if(NC_Wait_SCSTATUS(0U) == NC_FAILURE)
            {
                result = NC_FAILURE;
            }
        }
        RegA6_PMU_SCU->ISO_EN_BLK_USB.Bit.ISO_EN_BLK_USB = 0U;
    }
    else
    {
        RegA6_PMU_SCU->ISO_EN_BLK_USB.Bit.ISO_EN_BLK_USB = 1U;
        RegA6_PMU_SCU->PWR_OFF_BLK_USB.Bit.PWR_OFF_BLK_USB = 1U;
        if(NC_Wait_SCSTATUS(0x7U) == NC_FAILURE){
            result = NC_FAILURE;
        }
    }
    return result;
}
#endif

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    TZPROT Enable.
* @param    void
* @return   void
* @design
    Set 1 in TZPROT Register.
*/
void NC_SYS_SCU_TZPROT_EN(void)
{
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_0 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_1 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_2 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_3 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_4 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_5 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_7 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_8 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_9 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_10 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_11 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_12 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_13 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_14 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_15 = 1;
    RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_16 = 1;
}



/**
* @desc
    AXI2APB TZPC Enable.
* @param    void
* @return   void
* @design
    Set enable in AXI2APB TZPC Register.
*/
void NC_AXI2APB_TZPC_EN(void)
{
    REGRW32(0x05000000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_SYS_CTRL_APBB */ 
    REGRW32(0x05A00000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_GIC_CTRL_APBB */ 
    REGRW32(0x06200000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_PERI0_CTRL_APBB */ 
    REGRW32(0x06400000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_PERI1_CTRL_APBB */ 
    REGRW32(0x06600000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_HSP_CTRL_APBB */ 
    REGRW32(0x0C000000, 0x0000) = 0x0000FFFF;       /* BASE_ADDR_CPU_CTRL_APBB */ 
}



#if defined(USB_DLOAD_)
/**
* @desc
    Enable USB Clock.
* @param    UINT32  iOnOff  On or Off value
* @return   void
* @design
    IF  Clock is On     THEN
        Enable USB Clock.
    ELSE
        Disable USB Clock.
    ENDIF
*/
static void NC_SCU_USB_EnableClock(UINT32 iOnOff)
{
    if(iOnOff == ON)
    {        
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USBC_BUS = ON;
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USB_SUSPEND = ON;
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USB_REF_CLK = ON;
    }
    else
    {
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USBC_BUS = OFF;
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USB_SUSPEND = OFF;
        RegA6_USB_SCU->USB_CLKEN.Bit.CLKEN_USB_REF_CLK = OFF;
    }
}



/**
* @desc
    PMU Block power ON.
* @param    UINT32      BlkID   Block ID
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF ID is USB Block  THEN
        Turn on the power of the USB block.
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_PMU_BlockPowerON(UINT32 BlkID)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 prevTime;
    UINT64 loop;

    switch (BlkID)
    {
        case PMU_BLK_USB_ID:
            RegA6_PMU_SCU->T_WAKEUP_DLY_BLK_USB.Bit.T_WAKEUP_DLY_BLK_USB = 0xFFFU;
            RegA6_PMU_SCU->MANU_EN_BLK_USB.Bit.MANU_EN_BLK_USB = 0x0U;
            RegA6_PMU_SCU->PWR_OFF_BLK_USB.Bit.PWR_OFF_BLK_USB = 0x0U;            
            nc_udelay(1U);

            /* for CodeSonar (Potential Unbounded Loop) */
            loop = 0xffffffffULL;
            prevTime = (UINT32)nc_get_msec(FALSE);
  
            do
            {
                if (USB_PWR_ON_TIMEOUT_MS < ((UINT32)(nc_get_msec(FALSE)) - prevTime))
                {
                    Ret = NC_FAILURE;
                    loop = 0ULL;
                }
                else 
                {
                    if (RegA6_PMU_SCU->SC_STATUS_BLK_USB.Bit.SC_STATUS_BLK_USB == 0x0U)
                    {                        
                        loop = 0ULL;
                    }
                    else
                    {
                        loop--;
                    }
                }

            } while(0ULL < loop);

            /* Caution, USB ISO Registers are inversed */
            RegA6_PMU_SCU->ISO_EN_BLK_USB.Bit.ISO_EN_BLK_USB = 0x1U;
            break;


    default:
        /* error */
        Ret = NC_FAILURE;
        break;
    }

    return Ret;
}
#endif



/**
* @desc
    POR Hold Reset.
* @param    UINT32  BlkID   Block ID
* @return   void
* @design
    IF  Block ID is HSP     THEN
        HSP Hold Reset.
    ELSE
        USB Hold Reset.
    ENDIF
*/
static void NC_SCU_POR_HoldReset(UINT32 BlkID)
{
    switch(BlkID)
    {
        case BLK_POR_RST_HSP_ID:
            RegA6_SYS_SCU->HSP_POR_RST_ACT_0.Bit.HSP_POR_RST_ACT_0 = 0x1U;
            RegA6_SYS_SCU->HSP_POR_RST_ACT_1.Bit.HSP_POR_RST_ACT_1 = 0x1U;
            RegA6_SYS_SCU->HSP_POR_RST_ACT_2.Bit.HSP_POR_RST_ACT_2 = 0x1U;
            break;
        case BLK_POR_RST_USB_ID:
#if defined(USB_DLOAD_)
            RegA6_SYS_SCU->USB_POR_RST_ACT_0.Bit.USB_POR_RST_ACT_0 = 0x1U;
            RegA6_SYS_SCU->USB_POR_RST_ACT_1.Bit.USB_POR_RST_ACT_1 = 0x1U;
            RegA6_SYS_SCU->USB_POR_RST_ACT_2.Bit.USB_POR_RST_ACT_2 = 0x1U;
            nc_udelay(10U);
            RegA6_SYS_SCU->PUL_RST_ACT_6.Bit.PUL_RST_ACT_BLK_USB_APB = 0x1U;
#endif
            break;
        default:
            /* Do Nothing */
            break;
    }
}



/**
* @desc
    POR Release Reset.
* @param    UINT32  BlkID   Block ID
* @return   void
* @design
    IF  Block ID is HSP     THEN
        HSP Release Reset.
    ELSE
        USB Release Reset.
    ENDIF
*/
static void NC_SCU_POR_ReleaseReset(UINT32 BlkID)
{
    switch(BlkID)
    {
        case BLK_POR_RST_HSP_ID:
            RegA6_SYS_SCU->HSP_POR_RST_ACT_0.Bit.HSP_POR_RST_ACT_0 = 0x0U;
            RegA6_SYS_SCU->HSP_POR_RST_ACT_1.Bit.HSP_POR_RST_ACT_1 = 0x0U;
            RegA6_SYS_SCU->HSP_POR_RST_ACT_2.Bit.HSP_POR_RST_ACT_2 = 0x0U;
            break;
        case BLK_POR_RST_USB_ID:
#if defined(USB_DLOAD_)
            RegA6_SYS_SCU->USB_POR_RST_ACT_0.Bit.USB_POR_RST_ACT_0 = 0x0U;
            RegA6_SYS_SCU->USB_POR_RST_ACT_1.Bit.USB_POR_RST_ACT_1 = 0x0U;
            RegA6_SYS_SCU->USB_POR_RST_ACT_2.Bit.USB_POR_RST_ACT_2 = 0x0U;
            nc_udelay(10U);
            RegA6_SYS_SCU->PUL_RST_ACT_6.Bit.PUL_RST_ACT_BLK_USB_APB = 0x1U;
#endif
            break;
        default:
            /* Do Nothing */
            break;
    }
}



/**
* @desc
    Returns the System Tick count.
* @param    BOOL    Cls     Tick ​​Count Clear On/Off.
* @return   UINT64  System tick value
* @design
    IF  Is Tick Count Clear flag true?  THEN
        Tick Count clear.
    ENDIF
    system tick = Read System Tick count.
    Return  system tick
*/
UINT64 NC_SCU_GetTick(BOOL Cls)
{
    UINT64 SysTick;

    if(Cls == TRUE)
    {
        RegA6_SYS_SCU->TICK_CNT_CONTROL.Bit.TICK_CNT1_CLEAR = TRUE;
    }
/* PRQA S 0404 ++ */
    #if 1 /* [MISRA 2012 Rule 11.3, required] */
    SysTick = ((UINT64)RegA6_SYS_SCU->TICK_CNT1_H.Reg << 32) | (UINT64)RegA6_SYS_SCU->TICK_CNT1_L.Reg;
    /* SysTick = ((UINT64)REGRW32(APACHE_A6_SYS_SCU_BASE_ADDR, 0xEF14) << 32) | (UINT64)REGRW32(APACHE_A6_SYS_SCU_BASE_ADDR, 0xEF10); */
    #else
    SysTick = (*(volatile UINT64 *)(&(RegA6_SYS_SCU->TICK_CNT1_L.Reg)));
    #endif
/* PRQA S 0404 -- */

    return SysTick;
}



/**
* @desc
    Returns the Milli second value.
* @param    BOOL    Cls     Tick ​​Count Clear On/Off.
* @return   UINT64  Milli second value.
* @design
    current tick = Get tick value
    IF  current tick != 0  THEN
        current tick = Calculate the millisecond value from tick Count.
    ENDIF
    Return current tick
*/
UINT64 NC_SCU_GetMsec(BOOL Cls)
{
    UINT64 curr_tick = NC_SCU_GetTick(Cls);

    if(curr_tick != 0U)
    {
        curr_tick = curr_tick / (UINT64)(RegA6_SYS_SCU->DEBUG1.Reg / MSEC);
        /* curr_tick = curr_tick / (UINT64)(SYS_APB_CLK / MSEC); */
    }

    return curr_tick;
}



/**
* @desc
    A timeout occurs when milliseconds elapse.
* @param    UINT64  mSec    Milli second value
* @return   BOOL    TRUE or FALSE
* @design
    Ret = FALSE
    IF  Input milli second tim > 0    THEN
        IF  TimeOutCount == 0 THEN
            TimeOutCount = (Get milli second time + Input milli second time)
        ELSE
            Current time = Get milli second time
            IF  Current time > TimeOutCount THEN
                Ret = TRUE
                TimeOutCount = 0
            ENDIF
        ENDIF
    ELSE
        TimeOutCount = 0
    ENDIF
    Return Ret
*/
BOOL NC_SCU_mTimeOut(UINT64 mSec)
{
    BOOL Ret = FALSE;
    UINT64 CurrTick;
    /* PRQA S 0312, 3305, 0310 ++ */
    UINT64 *Sys_Timeout_Count = (UINT64 *)&RegA6_SYS_SCU->DEBUG2.Reg; /* #define SYS_TIMEOUT_CNT (*(volatile UINT64 *)(APACHE_A6_SYS_SCU_BASE_ADDR+0xF008U))  DEBUG2 ~ 3(DEBUG2 through DEBUG3.).  */
    /* PRQA S 0312, 3305, 0310 -- */

    if(mSec > 0U)
    {
        if(*Sys_Timeout_Count == (UINT64)0U)
        {
            /* Set TimeOut : SystemTick(msec) + TargetMsec; */
            #ifdef DEF_TICK_CLS_
                *Sys_Timeout_Count = NC_SCU_GetMsec(TRUE) + mSec;
            #else
                *Sys_Timeout_Count = NC_SCU_GetMsec(FALSE) + mSec;
            #endif
        }
        else
        {
            /* Timeout Check. */
            CurrTick = NC_SCU_GetMsec(FALSE);
            if(CurrTick > *Sys_Timeout_Count)
            {
                Ret = TRUE;
                *Sys_Timeout_Count = 0ULL;
            }
        }
    }
    else
    {
        *Sys_Timeout_Count = 0ULL;
    }

    return Ret;
}



/**
* @desc
    Wait as much as the input Tick value.
* @param    UINT64  Ticks   Tick value
* @return   void
* @design
    Start tick = Get tick value.
    DO WHILE    (Get tick value - Start tick) < Input tick value
        Wait until the current tick value minus the start_tick value is greater than Ticks.
    LOOP
*/
void NC_SCU_WaitTick(UINT64 Ticks)
{
#ifdef DEF_TICK_CLS_
    UINT64 sTicks = NC_SCU_GetTick(TRUE);
#else
    UINT64 sTicks = NC_SCU_GetTick(FALSE);
#endif
    while(1)
    {
        if((NC_SCU_GetTick(FALSE) - sTicks) < Ticks)
        {
            /* */
        }
        else
        {
            break;
        }
    }
}



#ifdef R5_UART_ENABLE_
void NC_SCU_PrintPLL(const tBOOT_STRAP *ptStrap, const tBOOT_CLK *ptClock)
{
    DEBUGMSG(MSGINFO, "=======================================================\n",NULL);
    DEBUGMSG(MSGINFO, " APACHE6 PLL CLK Information\n",NULL);
    DEBUGMSG(MSGINFO, "  > BOOT STRAP : 0x%x\n", ptStrap->Bit.mPLLConfig);
    DEBUGMSG(MSGINFO, "  > PLL P, M, S Value\n",NULL);
    DEBUGMSG(MSGINFO, "    -. CPU_PLL P:%d, M:%d, S:%d\n",  (UINT32)RegA6_SYS_SCU->CPU_PLL_PMS_CONTROL.Bit.CPU_PLL_P,
                                                            (UINT32)RegA6_SYS_SCU->CPU_PLL_PMS_CONTROL.Bit.CPU_PLL_M,
                                                            (UINT32)RegA6_SYS_SCU->CPU_PLL_PMS_CONTROL.Bit.CPU_PLL_S );
    DEBUGMSG(MSGINFO, "    -. SYS_PLL P:%d, M:%d, S:%d\n",  (UINT32)RegA6_SYS_SCU->SYS_PLL_PMS_CONTROL.Bit.SYS_PLL_P,
                                                            (UINT32)RegA6_SYS_SCU->SYS_PLL_PMS_CONTROL.Bit.SYS_PLL_M,
                                                            (UINT32)RegA6_SYS_SCU->SYS_PLL_PMS_CONTROL.Bit.SYS_PLL_S );
    DEBUGMSG(MSGINFO, "    -. COM_PLL P:%d, M:%d, S:%d\n",  (UINT32)RegA6_SYS_SCU->COM_PLL_PMS_CONTROL.Bit.COM_PLL_P,
                                                            (UINT32)RegA6_SYS_SCU->COM_PLL_PMS_CONTROL.Bit.COM_PLL_M,
                                                            (UINT32)RegA6_SYS_SCU->COM_PLL_PMS_CONTROL.Bit.COM_PLL_S );
    DEBUGMSG(MSGINFO, "  > PLL CLK Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. OSC                      : %dKHz\n", SYS_CK_XI_FEQ/KHZ);
    DEBUGMSG(MSGINFO, "    -. CPU_PLL                  : %dKHz\n", ptClock->mCPU_PLL/KHZ);
    DEBUGMSG(MSGINFO, "    -. SYS_PLL                  : %dKHz\n", ptClock->mSYS_PLL/KHZ);
    DEBUGMSG(MSGINFO, "    -. COM_PLL                  : %dKHz\n", ptClock->mCOM_PLL/KHZ);
    DEBUGMSG(MSGINFO, "  > OIC BUS Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. mBUS_APB                 : %dMHz\n", ptClock->mAPB/MHZ);
    DEBUGMSG(MSGINFO, "  > PERI CORE CLK Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. mSPI                     : %dMHz\n", ptClock->mSPI/MHZ);
    DEBUGMSG(MSGINFO, "    -. mUART                    : %dMHz\n", ptClock->mUART/MHZ);
    DEBUGMSG(MSGINFO, "  > HSP CLK Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. mQSPI_CORE               : %dMHz\n", ptClock->mQSPI/MHZ);
    DEBUGMSG(MSGINFO, "    -. mSD_TXRX                 : %dMHz\n", ptClock->mSD/MHZ);
    DEBUGMSG(MSGINFO, "    -. mEMMC_TXRX               : %dMHz\n", ptClock->mEMMC/MHZ);
#if defined(USB_DLOAD_)
    DEBUGMSG(MSGINFO, "  > USB CLK Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. mUSB                     : %dMHz\n", ptClock->mUSB/MHZ);
    DEBUGMSG(MSGINFO, "    -. mUSB_SUSPEND             : %dMHz\n", ptClock->mUSB_SUSPEND/MHZ);
    DEBUGMSG(MSGINFO, "    -. mUSB_REF_CLK             : %dMHz\n", ptClock->mUSB_REF_CLK/MHZ);
#endif
    DEBUGMSG(MSGINFO, "  > SYS_SCU Information\n",NULL);
    DEBUGMSG(MSGINFO, "    -. BUS_APB                  : %d \n", RegA6_SYS_SCU->VAL_BUS_APB_CLKDIV.Bit.CLKDIV_VAL_BUS_APB);
    DEBUGMSG(MSGINFO, "    -. UART_CORE                : %d \n", RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE);
    DEBUGMSG(MSGINFO, "    -. SPI_CORE                 : %d \n", RegA6_SYS_SCU->VAL_SPI_CORE_CLKDIV.Bit.CLKDIV_VAL_SPI_CORE);
    DEBUGMSG(MSGINFO, "    -. QSPI_CORE                : %d \n", RegA6_SYS_SCU->VAL_QSPI_CORE_CLKDIV.Bit.CLKDIV_VAL_QSPI_CORE);
    DEBUGMSG(MSGINFO, "=======================================================\n",NULL);
}

#endif



/**
* @desc
    Reads and calculates the PLL value to set the APB clock value.
* @param    tBOOT_CLK*      ptClock         Boot Clock parameter
* @param    tSCU_CLK_PLL*   ptSCUClk_PLL    PLL Clock parameter
* @return   void
* @struct
    typedef struct
    {
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
* @struct
    typedef struct
    {
        UINT32      mOSC;
        UINT32      mPLLConfig;
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
    } tSCU_CLK_PLL;
* @design
    select = Read the pll clock select register value.
    IF  select == 0 THEN
        pll value = system pll
    ELSE IF select == 1    THEN
        pll value = cpu pll
    ELSE
        pll value = system pll
    ENDIf
    APB value = (pll value / divider value)
*/
static void NC_SCU_SetSysClk(tBOOT_CLK *ptClock, volatile tSCU_CLK_PLL const *ptSCUClk_PLL)
{
#if 0 /* (BL_SEL == 1) */
    #define VALUE_CLKDIV_VAL_SYS_APB       (10U)
    ptClock->mAPB = (UINT32)(ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_SYS_APB);
#else /* BL2 */
    UINT32 Value;
    UINT32 SEL_Value;
    UINT32 MUX_Out;

    /* SYS Clocks ----------------------------------------- */
    Value = RegA6_SYS_SCU->BUS_PRE2_CLKMUX.Bit.CLKMUX_SEL_BUS_PRE2;
    SEL_Value = (Value & 0x1U);
    if(SEL_Value == 0U)
    {
        MUX_Out = ptSCUClk_PLL->mSYS_PLL;
    }
    else
    {
        MUX_Out = ptSCUClk_PLL->mCPU_PLL;
    }
    Value = RegA6_SYS_SCU->VAL_SYS_APB_CLKDIV.Bit.CLKDIV_VAL_SYS_APB;
    ptClock->mAPB = (UINT32)(MUX_Out/Value);
#endif
}



/**
* @desc
    Set the clock value of the peripheral device.
* @param    tBOOT_CLK*      ptClock         Boot Clock parameter
* @param    tSCU_CLK_PLL*   ptSCUClk_PLL    PLL Clock parameter
* @return   void
* @struct
    typedef struct
    {
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
* @struct
    typedef struct
    {
        UINT32      mOSC;
        UINT32      mPLLConfig;
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
    } tSCU_CLK_PLL;
* @design
    select = Read the peripheral clock select register value.
    IF  select == 0 THEN
        pll value = system pll
    ELSE IF select == 1    THEN
        pll value = cpu pll
    ELSE
        pll value = system pll
    ENDIf
    peripherals clock = (pll value / divider value)
*/
static void NC_SCU_SetPeriClk(tBOOT_CLK *ptClock, volatile tSCU_CLK_PLL const *ptSCUClk_PLL)
{
#if 0 /* (BL_SEL == 1) */
    #define VALUE_CLKDIV_VAL_UART_CORE      (50U)
    #define VALUE_CLKDIV_VAL_QSPI_CORE      (5U)
    #define VALUE_CLKDIV_VAL_CMRT           (5U)
    ptClock->mUART = (UINT32)(ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_UART_CORE);
    ptClock->mQSPI = (UINT32)(ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_QSPI_CORE);
    ptClock->mSPI  = (UINT32)(ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_QSPI_CORE);
    ptClock->mCMRT = (UINT32)(ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_CMRT);
#else /* BL2 */
    UINT32 Value;
    UINT32 SEL_Value;
    UINT32 MUX_Out;

    /* PERI CORE Clock ------------------------------------- */
    Value = RegA6_SYS_SCU->PERI_PRE2_CLKMUX.Bit.CLKMUX_SEL_PERI_PRE2;
    SEL_Value = (Value & 0x1U);
    if(SEL_Value == 0U)
    {
        MUX_Out = ptSCUClk_PLL->mSYS_PLL;
    }
    else
    {
        MUX_Out = ptSCUClk_PLL->mCPU_PLL;
    }

    Value = RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE;
    ptClock->mUART = (UINT32)(MUX_Out/Value);

    Value = RegA6_SYS_SCU->QSPI_PRE1_CLKMUX.Bit.CLKMUX_SEL_QSPI_PRE1;
    SEL_Value = (Value & 0x1U);
    if(SEL_Value == 0U)
    {
        MUX_Out = ptSCUClk_PLL->mSYS_PLL;
    }
    else
    {
        MUX_Out = ptSCUClk_PLL->mCPU_PLL;
    }

    Value = RegA6_SYS_SCU->VAL_QSPI_CORE_CLKDIV.Bit.CLKDIV_VAL_QSPI_CORE;
    ptClock->mQSPI = (UINT32)(MUX_Out/Value);
    ptClock->mSPI  = (UINT32)(MUX_Out/Value);

    /* SEC PRE1 */
    Value = RegA6_SYS_SCU->SEC_PRE1_CLKMUX.Bit.CLKMUX_SEL_SEC_PRE1;
    SEL_Value = (Value & 0x1U);
    if(SEL_Value == 0U)
    {
        MUX_Out = ptSCUClk_PLL->mSYS_PLL;
    }
    else
    {
        MUX_Out = ptSCUClk_PLL->mCPU_PLL;
    }

    Value = RegA6_SYS_SCU->VAL_CMRT_CLKDIV.Bit.CLKDIV_VAL_CMRT;
    ptClock->mCMRT = (UINT32)(MUX_Out/Value);
#endif
}



/**
* @desc
    Set the clock value of the HSP.
* @param    tBOOT_CLK*      ptClock         Boot Clock parameter
* @param    tSCU_CLK_PLL*   ptSCUClk_PLL    PLL Clock parameter
* @return   void
* @struct
    typedef struct
    {
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
* @struct
    typedef struct
    {
        UINT32      mOSC;
        UINT32      mPLLConfig;
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
    } tSCU_CLK_PLL;
* @design
    select = Read the clock select register value.
    IF  select == 0 THEN
        pll value = system pll
    ELSE IF select == 1    THEN
        pll value = cpu pll
    ELSE
        pll value = system pll
    ENDIf
    HSP clock = (pll value / divider value)
*/
static void NC_SCU_SetHSPClk(tBOOT_CLK *ptClock, volatile tSCU_CLK_PLL const *ptSCUClk_PLL)
{
#if 0 /* (BL_SEL == 1) */
    #define VALUE_CLKDIV_VAL_SD_IO      (2U)
    #define VALUE_CLKDIV_VAL_EMMC_IO    (2U)
    ptClock->mSD   = (UINT32)((ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_SD_IO)/CLK_DEF_DIV8);
    ptClock->mEMMC = (UINT32)((ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_EMMC_IO)/CLK_DEF_DIV8);
    ptClock->mUSB = (UINT32)((ptSCUClk_PLL->mSYS_PLL/VALUE_CLKDIV_VAL_EMMC_IO)/CLK_DEF_DIV8);
    /* USB Clock
      - in USB_Initialize function
     */
#else /* BL2 */
    UINT32 Value;
    UINT32 SEL_Value;
    UINT32 MUX_Out;

    /* HSP Clock ------------------------------------------ */
    Value = RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE2;
    SEL_Value = (Value & 0x3U);
    switch(SEL_Value)
    {
        case 1:   MUX_Out = ptSCUClk_PLL->mCPU_PLL;    break;
        case 2:   MUX_Out = ptSCUClk_PLL->mNPU_PLL;    break;
        case 3:   MUX_Out = ptSCUClk_PLL->mCOM_PLL;    break;
        default:  MUX_Out = ptSCUClk_PLL->mSYS_PLL;    break; /* case 0 */
    }
    Value = RegA6_HSP_SCU->SD_IO_CLKDIV.Bit.CLKDIV_VAL_SD_IO;
    MUX_Out = (UINT32)(MUX_Out / Value);
    Value = RegA6_HSP_SCU->SD_CORE_CLKDIV.Bit.CLKDIV_VAL_SD_CORE;
    ptClock->mSD = (UINT32)(MUX_Out / Value);

    Value = RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE2;
    SEL_Value = (Value & 0x3U);
    switch(SEL_Value)
    {
        case 1:   MUX_Out = ptSCUClk_PLL->mCPU_PLL;    break;
        case 2:   MUX_Out = ptSCUClk_PLL->mNPU_PLL;    break;
        case 3:   MUX_Out = ptSCUClk_PLL->mCOM_PLL;    break;
        default:  MUX_Out = ptSCUClk_PLL->mSYS_PLL;    break;  /* case 0 */
    }
    Value = RegA6_HSP_SCU->EMMC_IO_CLKDIV.Bit.CLKDIV_VAL_EMMC_IO;
    MUX_Out = (UINT32)(MUX_Out / Value);
    Value = RegA6_HSP_SCU->EMMC_CORE_CLKDIV.Bit.CLKDIV_VAL_EMMC_CORE;
    ptClock->mEMMC = (UINT32)(MUX_Out / Value);

#endif

}



#if 0
void NC_SCU_SetDefaultSysClk(void)
{
    /* Set Muxer */
    RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE1 = 0x0;                /* SYS_PLL  1000Mhz or 2000Mhz */ 
    RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE2 = 0x0;                /* SYS_PLL  1000Mhz or 2000Mhz */ 
    RegA6_SYS_SCU->PERI_PRE1_CLKMUX.Bit.CLKMUX_SEL_PERI_PRE1 = 0x0;
    RegA6_SYS_SCU->PERI_PRE2_CLKMUX.Bit.CLKMUX_SEL_PERI_PRE2 = 0x0;

    /* BLK_USB */
    RegA6_USB_SCU->USB_PRE1_CLKMUX.Bit.CLKMUX_SEL_USB_PRE1 = 0x0;
    RegA6_USB_SCU->USB_PRE2_CLKMUX.Bit.CLKMUX_SEL_USB_PRE2 = 0x0;


    /* Set Divider */
    RegA6_SYS_SCU->VAL_BUS_MAIN_CLKDIV.Bit.CLKDIV_VAL_BUS_MAIN = 0x2;
    RegA6_SYS_SCU->VAL_BUS_APB_CLKDIV.Bit.CLKDIV_VAL_BUS_APB = 0xA;
    RegA6_SYS_SCU->VAL_SYS_APB_CLKDIV.Bit.CLKDIV_VAL_SYS_APB = 0x14;    /* FECO21 changed 10 to 20 */ 
    RegA6_SYS_SCU->VAL_HSP_APB_CLKDIV.Bit.CLKDIV_VAL_HSP_APB = 0x14;    /* FECO21 changed 10 to 20 */ 

    RegA6_HSP_SCU->SD_CORE_CLKDIV.Bit.CLKDIV_VAL_SD_CORE = 0x8;
    RegA6_HSP_SCU->EMMC_CORE_CLKDIV.Bit.CLKDIV_VAL_EMMC_CORE = 0x8;

    RegA6_HSP_SCU->EMMC_IO_CLKDIV.Bit.CLKDIV_VAL_EMMC_IO = 0x2;
    RegA6_HSP_SCU->SD_IO_CLKDIV.Bit.CLKDIV_VAL_SD_IO = 0x02;

    RegA6_USB_SCU->VAL_USBC_BUS.Bit.CLKDIV_VAL_USBC_BUS = 0x5;              /* Max. 400Mhz */ 
    RegA6_USB_SCU->VAL_USB_SUSPEND.Bit.CLKDIV_VAL_USB_SUSPEND = 0x32;       /* Max. 40Mhz  */ 
    RegA6_USB_SCU->VAL_USB_REF.Bit.CLKDIV_VAL_USB_REF_CLK = 0x64;           /* Max. 20Mhz  */ 
}
#endif



/**
* @desc
    Get PLL Value.
* @param    tBOOT_STRAP*    ptStrap         Boot Strap Parameter
* @param    tBOOT_CLK*      ptClock         Boot Clock Parameter
* @param    tSCU_CLK_PLL*   ptSCUClk_PLL    PLL Clock parameter
* @return   void
* @struct
    typedef struct
    {
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
* @struct
    typedef struct
    {
        UINT32      mOSC;
        UINT32      mPLLConfig;
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
    } tSCU_CLK_PLL;
* @design
    IF  A matching PLL config value.   THEN
        Set PLL value
    ENDIF
    Get PLL Value.
*/

static void NC_SCU_GetPLL(const tBOOT_STRAP *ptStrap, tBOOT_CLK *ptClock, tSCU_CLK_PLL *ptSCUClk_PLL)
{
    switch(ptStrap->Bit.mPLLConfig)
    {
        case NC_BOOT_PLL_HALF_SSCG_OFF: /* Half Speed */
            ptSCUClk_PLL->mSYS_PLL = (1000U * MHZ); /* SYS : 1.0 GHz */
            ptSCUClk_PLL->mCPU_PLL = (1200U * MHZ); /* CPU : 1.2 GHz */
            ptSCUClk_PLL->mNPU_PLL = (1300U * MHZ); /* NPU : 1.3 GHz */
            ptSCUClk_PLL->mCOM_PLL = (2000U * MHZ); /* COM : 2.0 GHz */
            break;
        case NC_BOOT_PLL_FULL_SSCG_ON:
        case NC_BOOT_PLL_FULL_SSCG_OFF: /* Max Speed */
            ptSCUClk_PLL->mSYS_PLL = (2000U * MHZ); /* SYS : 2.0 GHz */
            ptSCUClk_PLL->mCPU_PLL = (2400U * MHZ); /* CPU : 2.4 GHz */
            ptSCUClk_PLL->mNPU_PLL = (2600U * MHZ); /* NPU : 2.6 GHz */
            ptSCUClk_PLL->mCOM_PLL = (2000U * MHZ); /* COM : 2.0 GHz */
            break;
        default: /* NC_BOOT_BYPASS :(Ext OSC) */
            ptSCUClk_PLL->mSYS_PLL = SYS_CK_XI_FEQ; /* SYS : 24 Hz */
            ptSCUClk_PLL->mCPU_PLL = SYS_CK_XI_FEQ; /* CPU : 24 Hz */
            ptSCUClk_PLL->mNPU_PLL = SYS_CK_XI_FEQ; /* NPU : 24 Hz */
            ptSCUClk_PLL->mCOM_PLL = SYS_CK_XI_FEQ; /* COM : 24 Hz */
            break;
    }
    
    ptClock->mSYS_PLL     = ptSCUClk_PLL->mSYS_PLL;
    ptClock->mCPU_PLL     = ptSCUClk_PLL->mCPU_PLL;
    ptClock->mNPU_PLL     = ptSCUClk_PLL->mNPU_PLL;
    ptClock->mCOM_PLL     = ptSCUClk_PLL->mCOM_PLL;
    
    /* HSP */
    NC_SCU_POR_HoldReset(BLK_POR_RST_HSP_ID);
    nc_mdelay(1U);
    NC_SCU_POR_ReleaseReset(BLK_POR_RST_HSP_ID);

    NC_SCU_SetSysClk(ptClock, ptSCUClk_PLL);
    NC_SCU_SetPeriClk(ptClock, ptSCUClk_PLL);
    NC_SCU_SetHSPClk(ptClock, ptSCUClk_PLL);
}



#if defined(USB_DLOAD_)
/**
* @desc
    Control the SCU BLK USB Power and Clock value.
* @param    tBOOT_INFO*     ptBootInfo  Boot information parameter.
* @param    tBOOT_CLK*      ptClock     Boot Clock parameter
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
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
* @design
    IF  BootMemory is E_BOOT_USB.  THEN
        select = Read the clock select register value.
        IF  select == 0 THEN
            pll value = system pll
        ELSE
            pll value = cpu pll
        ENDIf
        clock = (pll value / divider value)
    ENDIF
*/
static void NC_SCU_USB_PowerAndSetClk(const tBOOT_INFO *ptBootInfo, tBOOT_CLK *ptClock)
{
    UINT32 Value;
    UINT32 SEL_Value;
    UINT32 MUX_Out;


    if (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_USB)
    {
        /* 
        - USB Power On after reset control
        */
        NC_SCU_POR_HoldReset(BLK_POR_RST_USB_ID);
        (void)NC_PMU_BlockPowerON(PMU_BLK_USB_ID);
        NC_SCU_POR_ReleaseReset(BLK_POR_RST_USB_ID);
        
        NC_SCU_USB_EnableClock(ON);    


        /* USB Clock
        - in USB_Initialize function
        */
        Value = RegA6_USB_SCU->USB_PRE1_CLKMUX.Bit.CLKMUX_SEL_USB_PRE1;
        SEL_Value = (Value & 0x1U);
        if(SEL_Value == 0U)
        {
            MUX_Out = ptClock->mSYS_PLL;
        }
        else
        {
            MUX_Out = ptClock->mCPU_PLL;
        }    
        Value = RegA6_USB_SCU->VAL_USBC_BUS.Bit.CLKDIV_VAL_USBC_BUS;
        ptClock->mUSB = (UINT32)(MUX_Out / Value);

        Value = RegA6_USB_SCU->USB_PRE2_CLKMUX.Bit.CLKMUX_SEL_USB_PRE2;
        SEL_Value = (Value & 0x3U);
        if(SEL_Value == 0U)
        {
            MUX_Out = ptClock->mSYS_PLL;
        }
        else
        {
            MUX_Out = ptClock->mCPU_PLL;
        }
        Value = RegA6_USB_SCU->VAL_USB_SUSPEND.Bit.CLKDIV_VAL_USB_SUSPEND;
        ptClock->mUSB_SUSPEND = (UINT32)(MUX_Out / Value);

        Value = RegA6_USB_SCU->VAL_USB_REF.Bit.CLKDIV_VAL_USB_REF_CLK;
        ptClock->mUSB_REF_CLK = (UINT32)(MUX_Out / Value);
    } else {
        /* Do Nothing */
    }
}
#endif



/**
* @desc
    Read the SCU Clock value.
* @param    tBOOT_CLK*      ptClock         Boot Clock parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
* @return   void
* @struct
    typedef struct
    {
        UINT32      mSYS_PLL;       System PLL value
        UINT32      mCPU_PLL;       CPU PLL value
        UINT32      mNPU_PLL;       NPU PLL value
        UINT32      mCOM_PLL;       COM PLL value
        UINT32      mAPB;           APB clock value
        UINT32      mSPI;           SPI clock value
        UINT32      mQSPI;          QSPI clock value
        UINT32      mUART;          UART clock value
        UINT32      mSD;            SD clock value
        UINT32      mEMMC;          EMMC clock value
        UINT32      mUSB;           USB clock value
        UINT32      mCMRT;          CMRT clock value
        UINT32      mUSB_SUSPEND;
        UINT32      mUSB_REF_CLK;   USB Reference clock
        UINT32      mSPIDiv;        SPI Divider value
        UINT32      mQSPIDiv;       QSPI Divider value
    } tBOOT_CLK;
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
    Read the PLL value.
    The system clock value is stored in the argument value.
    The peripheral clock value is stored in the argument value.
    The HSP clock value is stored in the argument value.
*/
static void NC_SCU_GetClk(tBOOT_CLK *ptClock, tBOOT_STATUS *ptBootStatus)
{
    tSCU_CLK_PLL tSCUClk_PLL;

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_PLL_CONF_IN, ptBootStatus);

    NC_SCU_GetPLL((tBOOT_STRAP*)&(ptBootStatus->ptHandleBoot->tStrap), ptClock, &tSCUClk_PLL);

    NC_SM_SetBOOT_Step((UINT32)DBG_STP_PLL_CONF_OUT, ptBootStatus);
}



/**
* @desc
    This function performs strap configuration.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter.
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
    IF  SPI Clock inversion is enabled. THEN
        Enable clock inversion.
    ELSE
        Disable clock inversion.
    ENDIf
*/
void NC_SCU_StrapConfig(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_STRAP_CONF_IN, ptBootStatus);
    
#ifdef FORCE_BOOT_MEMORY
    ptBootInfo->tStrap.Bit.mBootMemory = FORCE_BOOT_MEMORY;
#endif
    /*SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_BOOT_MEDIA, ptBootInfo->tStrap.Bit.mBootMemory);*/
    DBG_BOOT_SUMMARY_REG |= ptBootInfo->tStrap.Bit.mBootMemory;

    /* Check & Set QSPI/SPI CLK Inversion */
    if( ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SPI_CLK_INVD )
    {
        ptBootInfo->tImage.mCLK_INV = TRUE;
        ptBootInfo->tStrap.Bit.mBootMemory = E_BOOT_SFLASH;
    }
    else
    {
        ptBootInfo->tImage.mCLK_INV = FALSE;
    }

    if((ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_UART) || (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_USB))
    {
        NC_MPU_EnableDebugRegion();
    }
    
    /* Set SPI CLK Inversion */
    gSPI_CLK_INV = ptBootInfo->tImage.mCLK_INV;

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_STRAP_CONF_OUT, ptBootStatus);
}



/**
* @desc
    Initialize to use SCU IP.
* @param    tBOOT_INFO*     ptBootInfo      Boot information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot status parameter
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
    Set the value in SCU Register.
*/
void NC_SCU_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    /*------------------------------------------------*/
    /* Do Not Move !!! */
    ptBootStatus->ptHandleBoot = ptBootInfo;
    /*------------------------------------------------*/
    
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_SCU_INIT_IN, ptBootStatus);
    
    /*
     *------------------------------------------------
     * Check Boot Strap
     * -.[8:31] RESERVED
     * -. [  7] MAIN_BUS Divider value increase
     *          0b0(0)   : Not increase
     *          0b1(1)   : Increase the divider on the MAIN_BUS by one.
     * -. [5:6] R5/A65 Jtag
     *          0b00(0)  : RT640
     *          0b01(1)  : R5
     *          0b10(2)  : CoreSight
     *          0b11(3)  : RT+CS
     * -. [2:4] Boot memory selection
     *          0b000(0) : sFlash
     *          0b001(1) : eMMC
     *          0b010(2) : SD Card
     *          0b011(3) : sFlash CLK INV
     *          0b100(4) : UART
     *          0b101(5) : USB
     * -. [1:0] PLL Configuration
     *------------------------------------------------
     */
    /* Get Strap */
    ptBootInfo->tStrap.Reg = (RegA6_SYS_SCU->STRAP_STATE.Bit.STRAP_STATE & (UINT32)0xFFU);        

    /* Set Strap Value */
    NC_SetDBG_STRAP_Config(ptBootInfo->tStrap.Reg);
    
    /*
     * < PLL Configuration >
     *
     *  0 : EXT OSC 24MHz      : PLL   24MHz
     *  1 : HALF speed (24MHz) : PLL 1200MHz (1200.000 MHz) [P=2   M=200   S=1]
     *  2 : Not Used
     *  3 : MAX speed  (24MHz) : PLL 2400MHz (2400.000 MHz) [P=2   M=200   S=0]
     * ----------------------------------------------------------------\
     * BLOCK/STRAP        |  2'b00   |   2'b01   |  2'b10  |   2'b11   |
     * -------------------|----------|-----------|---------|-----------|
     * SYS_PLL    [1]     |   24 MHz |  1000 MHz |   TBD   |  2000 MHz |
     * CPU_PLL    [2]     |   24 MHz |  1200 MHz |   TBD   |  2400 MHz |
     * NPU_PLL    [3]     |   24 MHz |  1300 MHz |   TBD   |  2600 MHz |
     * COM_PLL    [4]     |   24 MHz |  2000 MHz |   TBD   |  2000 MHz |
     * VIDEO0_PLL [5]     |   24 MHz |  1188 MHz |   TBD   |  1188 MHz |
     * VIDEO1_PLL [6]     |   24 MHz |  1188 MHz |   TBD   |  1188 MHz |
     * APB        [1/10]  |  2.4 MHz |   100 MHz |   TBD   |   200 MHz |
     * SPI/QSPI   [1/5]   |  4.8 MHz |   200 MHz |   TBD   |   400 MHz |
     * sFlash     [1/4]   |  1.2 MHz |    50 MHz |   TBD   |   100 MHz |
     * UART       [1/N]   |   24 MHz |   500 MHz |   TBD   |   400 MHz |
     * EMMC       [1/8]   |    3 MHz |   125 MHz |   TBD   |   250 MHz |
     * SDC        [1/8]   |    3 MHz |   125 MHz |   TBD   |   250 MHz |
     * USB        [1/5]   |  4.8 MHz |   200 MHz |   TBD   |   400 MHz |
     * ----------------------------------------------------------------/
     *
     *  Note
     *     Depending on the PLL Configuration, the value of N varies as follows:
     *     1. Bypass     : N = 1
     *     2. Half-speed : N = 2
     *     3. MAX speed  : N = 5
     */
    /*
     *------------------------------------------------
     * Set Clock Path
     *   -. 0 : Used i_clk_ext_osc(24MHz)
     *   -. 1 : Used PLL
     *------------------------------------------------
     */
    if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_BYPASS)
    {/* Bypass */
        RegA6_SYS_SCU->PLL_OUT_CLKMUX.Reg = 0x0U;
    }
    else
    {
        /****************************************************************************************/
        /* Issue : Changed the value of MAIN_BUS the divider due to the Bus Timing Close issue. */
        /* Change to CLKDIV_VAL_BUS_MAIN      : 2(Org) -> 5(MAX Speed) , 3(Half Speed) */
        /* If strap 7bit is set then DIV (+1) : 6(Max Speed) , 4(Half Speed) */
        /****************************************************************************************/
        if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_PLL_HALF_SSCG_OFF)
        {/* Half Speed */
            if(ptBootInfo->tStrap.Bit.mIncMainBusDiv == 1U)
            {
                RegA6_SYS_SCU->VAL_BUS_MAIN_CLKDIV.Bit.CLKDIV_VAL_BUS_MAIN = 0x4U;
            }
            else
            {
                RegA6_SYS_SCU->VAL_BUS_MAIN_CLKDIV.Bit.CLKDIV_VAL_BUS_MAIN = 0x3U;
            }
        }
        else
        {/* MAX Speed */
            if(ptBootInfo->tStrap.Bit.mIncMainBusDiv == 1U)
            {
                RegA6_SYS_SCU->VAL_BUS_MAIN_CLKDIV.Bit.CLKDIV_VAL_BUS_MAIN = 0x6U;
            }
            else
            {
                RegA6_SYS_SCU->VAL_BUS_MAIN_CLKDIV.Bit.CLKDIV_VAL_BUS_MAIN = 0x5U;
            }
        }

        RegA6_SYS_SCU->PLL_OUT_CLKMUX.Reg = 0x3FU;
    }


    /*
     *-----------------------------------------------------------
     * Set CLKDIV_VAL_UART_CORE following the PLL Configurations
     *   -. Bypass     : CLKDIV_VAL_UART_CORE would be 1
     *   -. Half-speed : CLKDIV_VAL_UART_CORE would be 2
     *   -. Full-speed : CLKDIV_VAL_UART_CORE would be 5
     *-----------------------------------------------------------
     */
    if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_BYPASS)
    {   /* Bypass */
        RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE = (UINT32)0x1U;        
    }
    else
    {   /* Half-speed */
        if(ptBootInfo->tStrap.Bit.mPLLConfig == NC_BOOT_PLL_FULL_SSCG_OFF)
        {
            RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE = (UINT32)0x2U;
        }
        /* Full-speed */
        else
        {
            RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE = (UINT32)0x5U;
        }
    }

    
    NC_SCU_GetClk((tBOOT_CLK*)&(ptBootInfo->tClock), ptBootStatus);

#if defined(USB_DLOAD_)
    NC_SCU_USB_PowerAndSetClk(ptBootInfo, (tBOOT_CLK*)&(ptBootInfo->tClock));
#endif

    /* PRQA S 3332 ++ */
#ifdef FPGA_MODE_ /* For FPGA  */
    ptBootInfo->tClock.mAPB  = BL_FPGA_APB_CLOCK;
    ptBootInfo->tClock.mSPI  = BL_FPGA_SPI_CLOCK;
    ptBootInfo->tClock.mQSPI = BL_FPGA_QSPI_CLOCK;
    ptBootInfo->tClock.mUART = BL_FPGA_UART_CLOCK;
    ptBootInfo->tClock.mSD   = BL_FPGA_SD_CLOCK;
    ptBootInfo->tClock.mEMMC = BL_FPGA_EMMC_CLOCK;
#endif /* FPGA_MODE_ */
#ifdef SIM_ONLY_ /* FIXME : TODO */    
    ptBootInfo->tClock.mAPB  = BL_SIM_APB_CLOCK;
    ptBootInfo->tClock.mSPI  = BL_SIM_SPI_CLOCK;
    ptBootInfo->tClock.mQSPI = BL_SIM_QSPI_CLOCK;
    ptBootInfo->tClock.mUART = BL_SIM_UART_CLOCK;
    ptBootInfo->tClock.mSD   = BL_SIM_SD_CLOCK;
    ptBootInfo->tClock.mEMMC = BL_SIM_EMMC_CLOCK;
#endif /* SIM_ONLY_ */
/* PRQA S 3332 -- */

    RegA6_SYS_SCU->DEBUG1.Reg  = ptBootInfo->tClock.mAPB; /*  SYS_APB_CLK  = ptBootInfo->tClock.mAPB */
    RegA6_SYS_SCU->DEBUG2.Reg = 0U;                       /*  SYS_TIMEOUT_CNT = 0ULL; */
    RegA6_SYS_SCU->DEBUG3.Reg = 0U;

    /* [MISRA 2012 Rule 8.13, advisory] */
    RegA6_SYS_SCU->DEBUG0.Reg = 0U;
    
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_SCU_INIT_OUT, ptBootStatus);
}



/**
* @desc
    Reset all register.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
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
    Reset all register.
*/
void NC_InitReset(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus)
{
    NC_SM_SetBOOT_Step((UINT8)DBG_STP_RESET_IP_IN, ptBootStatus);
    
    /* Reset PERI, HSP, UART, SD, eMMC, QSPI, DMA, USB */
    /* Reset SAFETY, CMRT640 */
    /* Reset OTP, ANALOG */

    RegA6_SYS_SCU->ONGO_RST_ACT_0.Bit.ONGO_RST_ACT_BLK_SAFETY = 0U;
    RegA6_SYS_SCU->ONGO_RST_ACT_0.Bit.ONGO_RST_ACT_BLK_ICU    = 0U;
    RegA6_SYS_SCU->ONGO_RST_ACT_0.Bit.ONGO_RST_ACT_ANALOG_APB = 0U;

    /* CORE/APB : PERI0/1, DMA, UART, TIMER, QSPI, SPI, PWM */
    RegA6_SYS_SCU->ONGO_RST_ACT_1.Reg = 0U;

    /* HSP APB */
    RegA6_SYS_SCU->ONGO_RST_ACT_5.Bit.ONGO_RST_ACT_HSP_APB = 0U;

    /* CORE : OTP, ADC, VLD, PVT */
    RegA6_SYS_SCU->ONGO_RST_ACT_7.Reg = 0U;

    /* HSP CORE/AXI/AHB/TX/RX/TIMER */
    RegA6_HSP_SCU->HSP_AHB_ONGO_RST_ACT.Reg  = 0U;
    RegA6_HSP_SCU->HSP_AXI_ONGO_RST_ACT.Reg  = 0U;
    RegA6_HSP_SCU->HSP_CORE_ONGO_RST_ACT.Reg = 0U;

    RegA6_HSP_SCU->HSP_TX_ONGO_RST_ACT.Bit.ONGO_RST_ACT_EMMC_TX = 0U;
    RegA6_HSP_SCU->HSP_TX_ONGO_RST_ACT.Bit.ONGO_RST_ACT_SD_TX   = 0U;
    RegA6_HSP_SCU->HSP_RX_ONGO_RST_ACT.Bit.ONGO_RST_ACT_EMMC_RX = 0U;
    RegA6_HSP_SCU->HSP_RX_ONGO_RST_ACT.Bit.ONGO_RST_ACT_SD_RX   = 0U;

    RegA6_HSP_SCU->HSP_TIMER_ONGO_RST_ACT.Bit.ONGO_RST_ACT_EMMC_CQETIMER = 0U;
    RegA6_HSP_SCU->HSP_TIMER_ONGO_RST_ACT.Bit.ONGO_RST_ACT_EMMC_TIMER    = 0U;
    RegA6_HSP_SCU->HSP_TIMER_ONGO_RST_ACT.Bit.ONGO_RST_ACT_SD_TIMER      = 0U;

    RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_PERI0_APB  = 0x1U;
    RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_PERI1_APB  = 0x1U;

    if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SDCARD)
    {
        RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 1U;
        RegA6_HSP_SCU->SD_CLKEN.Reg = 0x3E3U;
    }
    else if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_EMMC)
    {
        RegA6_SYS_SCU->BUS_S_TZPROT.Bit.BUS_S_TZPROT_6 = 1U;
        RegA6_HSP_SCU->EMMC_CLKEN.Reg = 0x3E3U;
    }
    else if (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SFLASH)
    {
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_DMAC0_AXI  = 0x1U;
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_DMAC1_AXI  = 0x1U;
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_QSPI_APB   = 0x1U;
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_QSPI_CORE  = 0x1U;
    }
    else if (ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_UART)
    {
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_UART0_APB  = 0x1U;
        RegA6_SYS_SCU->SYS_CLKEN_1.Bit.CLKEN_UART0_CORE = 0x1U;
    }
    else
    {
        /* Do Nothing */
    }

    NC_SM_SetBOOT_Step((UINT8)DBG_STP_RESET_IP_OUT, ptBootStatus);
}



/* List of default values and their changes, planned to remove if not necessary */
#if 0
static void NC_SCU_SYS_SetDefaultClock(void) {
    /***************************************************************************************
     *  Set Muxer
     * 
    ***************************************************************************************/
    RegA6_SYS_SCU->SEC_PRE1_CLKMUX.Bit.CLKMUX_SEL_SEC_PRE1          = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->PERI_PRE1_CLKMUX.Bit.CLKMUX_SEL_PERI_PRE1        = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->PERI_PRE2_CLKMUX.Bit.CLKMUX_SEL_PERI_PRE2        = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->BUS_PRE1_CLKMUX.Bit.CLKMUX_SEL_BUS_PRE1          = 0x0U; /* SYS_PLL */           /* It does not stay constant at 0x2U for the case of BUS_MAIN_CLKDIV due to timing issue */
    RegA6_SYS_SCU->BUS_PRE2_CLKMUX.Bit.CLKMUX_SEL_BUS_PRE2          = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->MEM_PRE1_CLKMUX.Bit.CLKMUX_SEL_MEM_PRE1          = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->QSPI_PRE1_CLKMUX.Bit.CLKMUX_SEL_QSPI_PRE1        = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->GIC_PRE1_CLKMUX.Bit.CLKMUX_SEL_GIC_PRE1          = 0x0U; /* SYS_PLL */
    RegA6_SYS_SCU->ANALOG_PRE1_CLKMUX.Bit.CLKMUX_SEL_ANALOG_PRE1    = 0x0U; /* SYS_PLL */

    RegA6_SYS_SCU->LIN_PRE1_CLKMUX.Bit.CLKMUX_SEL_LIN_PRE1          = 0x1U; /* COM_PLL */
    RegA6_SYS_SCU->CAN_PRE1_CLKMUX.Bit.CLKMUX_SEL_CAN_PRE1          = 0x1U; /* COM_PLL */
    

    RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE1           = 0x0U; /* SYS_PLL_AWAY */
    RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_HSP_PRE2           = 0x0U; /* SYS_PLL_AWAY */
    RegA6_HSP_SCU->HSP_PRE_CLKMUX.Bit.CLKMUX_SEL_ETH_PRE1           = 0x2U; /* NPU_PLL_AWAY & TODO : bl2에서는 0x0으로 입력되어 SYS_PLL_AWAY가 들어오게 되어있음 */




    /***************************************************************************************
     *  Set Divider
     * 
     * MHz 계산은 Sys PLL Full mode 기준 (Sys_PLL 2GHz)
    ***************************************************************************************/
    /* input extern oscillator : 24MHz */
    RegA6_SYS_SCU->VAL_VLD_CORE_CLKDIV.Bit.CLKDIV_VAL_VLD_CORE      = 0x6U;         /* input clk_ext_osc(24MHz) & TODO : bl2에서 변경한 값을 사용 : 0x16 */ 

    /* input com_pll : 2000MHz */
    RegA6_SYS_SCU->VAL_LIN_CORE_CLKDIV.Bit.CLKDIV_VAL_LIN_CORE      = 0x32U;        /* 40MHz       TODO : bl2에서는 COM PLL 1600MHz 기준으로 본 것으로 보이며 0x14U가 들어가있음.(100MHz) */
    RegA6_SYS_SCU->VAL_CAN_CORE_CLKDIV.Bit.CLKDIV_VAL_CAN_CORE      = 0x14U;        /* 80MHz       TODO : bl2에서는 COM PLL 1600MHz 기준으로 본 것으로 보이며 0x14U가 들어가있음.(100MHz) */

    /* input sys_pll */
    /* etc */    
    RegA6_SYS_SCU->VAL_CMRT_CLKDIV.Bit.CLKDIV_VAL_CMRT              = 0x5U;         /* 400MHz  */
    RegA6_SYS_SCU->VAL_IRAM_CLKDIV.Bit.CLKDIV_VAL_IRAM              = 0x5U;         /* 400MHz */
    RegA6_SYS_SCU->VAL_IROM_CLKDIV.Bit.CLKDIV_VAL_IROM              = 0x5U;         /* 400MHz */
    RegA6_SYS_SCU->VAL_GIC_CLKDIV.Bit.CLKDIV_VAL_GIC                = 0x4U;         /* 500MHz     TODO : bl2에서 변경한 값을 사용 : 0xA */
    RegA6_SYS_SCU->VAL_PERI_AXI_CLKDIV.Bit.CLKDIV_VAL_PERI_AXI      = 0x5U;         /* 400MHz     TODO : bl2에서 변경한 값을 사용 : 0xA */
    

    /* peri */
    RegA6_SYS_SCU->VAL_QSPI_CORE_CLKDIV.Bit.CLKDIV_VAL_QSPI_CORE    = 0x5U;         /* 400MHz    TODO : bl2에서 변경한 값을 사용 : 0xA & TODO : qspi core 구하는데 사용 */
    RegA6_SYS_SCU->VAL_SPI_CORE_CLKDIV.Bit.CLKDIV_VAL_SPI_CORE      = 0xAU;         /* 200MHz    TODO : spi core에 사용 */
    RegA6_SYS_SCU->VAL_UART_CORE_CLKDIV.Bit.CLKDIV_VAL_UART_CORE    = 0x32U;        /* 40MHz     TODO : uart core에 사용 */
    RegA6_SYS_SCU->VAL_I2C_CORE_CLKDIV.Bit.CLKDIV_VAL_I2C_CORE      = 0x32U;        /* 40MHz     TODO : i2c core에 사용 */
    RegA6_SYS_SCU->VAL_PWM_CORE_CLKDIV.Bit.CLKDIV_VAL_PWM_CORE      = 0x32U;        /* 40MHz     TODO : 문서상에는 왜 100MHz라고 기재되어있는지? BL2는 동일하게 40MHz로 코딩되어있음. 이게 페리가 맞나? */
    


    /* analog*/    
    RegA6_SYS_SCU->VAL_ANALOG_APB_CLKDIV.Bit.CLKDIV_VAL_ANALOG_APB  = 0xAU;         /* 100MHz */
    RegA6_SYS_SCU->VAL_ADC_CORE_CLKDIV.Bit.CLKDIV_VAL_ADC_CORE      = 0x14;         /* 100Mhz */
    RegA6_SYS_SCU->VAL_PVT_CORE_CLKDIV.Bit.CLKDIV_VAL_PVT_CORE      = 0x14;         /* 100Mhz */

    /* apb */
    RegA6_SYS_SCU->VAL_BUS_APB_CLKDIV.Bit.CLKDIV_VAL_BUS_APB        = 0xAU;         /* 200MHz */
    RegA6_SYS_SCU->VAL_PERI_APB_CLKDIV.Bit.CLKDIV_VAL_PERI_APB      = 0xAU;         /* 200MHz    TODO : bl2에서 변경한 값을 사용 : 0x14 */
    RegA6_SYS_SCU->VAL_ACC_APB_CLKDIV.Bit.CLKDIV_VAL_ACC_APB        = 0xAU;         /* 200MHz    TODO : bl2에서 변경한 값을 사용 : 0x14 */
    RegA6_SYS_SCU->VAL_HSP_APB_CLKDIV.Bit.CLKDIV_VAL_HSP_APB        = 0x14U;        /* 100MHz    TODO : bl2에서 변경한 값을 사용 : 0x19 & TODO : evt1에서 200MHz 나오도록 rollback함 */
    RegA6_SYS_SCU->VAL_SYS_APB_CLKDIV.Bit.CLKDIV_VAL_SYS_APB        = 0x14U;        /* 100MHz    TODO : bl2에서 변경한 값을 사용 : 0x14 & TODO : evt1에서 200MHz 나오도록 rollback함 */
    
    /* input sys_pll_away */
    RegA6_HSP_SCU->EMMC_CORE_CLKDIV.Bit.CLKDIV_VAL_EMMC_CORE        = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->EMMC_AXI_CLKDIV.Bit.CLKDIV_VAL_EMMC_AXI          = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->EMMC_AHB_CLKDIV.Bit.CLKDIV_VAL_EMMC_AHB          = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->EMMC_IO_CLKDIV.Bit.CLKDIV_VAL_EMMC_IO            = 0x2U;         /* 1000MHz   & TODO : bl2에서는 0x1을 사용 & default로 0x1을 설정했다가 이후에 0x2로 변경 => 변경 코드는 실제 호출을 안함 */
    
    RegA6_HSP_SCU->SD_CORE_CLKDIV.Bit.CLKDIV_VAL_SD_CORE            = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->SD_AXI_CLKDIV.Bit.CLKDIV_VAL_SD_AXI              = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->SD_AHB_CLKDIV.Bit.CLKDIV_VAL_SD_AHB              = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->SD_IO_CLKDIV.Bit.CLKDIV_VAL_SD_IO                = 0x2U;         /* 1000MHz & TODO : bl2에서는 0x1을 사용 & default로 0x1을 설정했다가 이후에 0x2로 변경 => 변경  코드는 실제 호출을 안함 */

    RegA6_HSP_SCU->GMAC_AXI_CLKDIV.Bit.CLKDIV_VAL_ETH_AXI           = 0x8U;         /* 250MHz */
    RegA6_HSP_SCU->GMAC_IO_CLKDIV.Bit.CLKDIV_VAL_ETH_IO             = 0x4U;         /* 500MHz */

    /***************************************************************************************
     *  CLk Enable
     * 
     *  !! 여기서 처리하면 안됨, 기록용
    ***************************************************************************************/
    /* Clk Enable 관련  */ 
    /*
     * TODO sys_clock_con 시트의 CLKMUX_SEL_PERI_PRE1 Mux로부터 분기되어 각 PERI로 들어가는 PERI1_APB_CLKEN 에 해당하는 값들 다 동작되는지 확인 필요, 일단 넘어감
     * CLKEN_BUS_MAIN = 0x1U; 코드에서 사용하는 부분이 없음
     * CLKEN_BUS_APB = 0x1U; 코드에서 사용하는 부분이 없음
     * CLKEN_ACC_APB, CLKEN_BLK_SEC_APB, CLKEN_BLK_NPU_APB 코드에서 사용하는 부분이 없음 
     * CLKEN_IRAM = 0x1U , CLKEN_IROM = 0x1U  ..상동
     * CLKEN_SPI0_CORE = 0x1U, CLKEN_SPI1_CORE = 0x1U, CLKEN_SPI2_CORE = 0x1U 상동
     * CLKEN_UART0_CORE = 0x1U 는 사용 , CLKEN_UART1_CORE = 0x1U, CLKEN_UART2_CORE = 0x1U, CLKEN_UART3_CORE = 0x1U 사용 안함
     * CLKEN_I2C0_CORE, ... CLKEN_I2C7_CORE 까지 모두 0X1U 사용안함
     * CLKEN_GIC_APB = 0x1U, CLKEN_GIC_R5 = 0x1U, CLKEN_GIC_A65 = 0x1U, CLKEN_GIC_A65_FDC = 0x1U  상동
     * CLKEN_CAN0_CORE = 0x1U, CLKEN_CAN1_CORE = 0x1U  상동
     * CLKEN_BLK_USB_APB = 0x1U, CLKEN_BLK_PCIE_APB = 0x1U, CLKEN_ETH_APB = 0x1U  상동
     * CLKEN_BLK_SYS_SCU = 0x1U, CLKEN_BLK_PMU = 0x1U, CLKEN_BLK_MEM = 0x1U, CLKEN_BLK_ICU = 0x1U, CLKEN_TEST_MST = 0x1U, CLKEN_BLK_SAFETY = 0x1U  상동
     * CLKEN_DMAC0_AXI = 0x1U, CLKEN_DMAC1_AXI = 0x1U  SFLASH 모드에서만 사용
     * CLKEN_QSPI_APB = 0x1U  SFLASH 모드에서만 사용
     * CLKEN_SPI0_APB = 0x1U, CLKEN_SPI1_APB = 0x1U, CLKEN_SPI2_APB = 0x1U  사용 안함
     * CLKEN_I2S_APB = 0x1U, CLKEN_CAN0_APB = 0x1U, CLKEN_CAN1_APB = 0x1U, CLKEN_PWM_APB = 0x1U  사용 안함
     * CLKEN_TIMER0_APB = 0x1U, CLKEN_TIMER1_APB = 0x1U, CLKEN_TIMER2_APB = 0X1u  사용 안함
     * CLKEN_PERI_SCU_APB = 0x1U  문서상엔 있지만 코드상엔 없음
     * CLKEN_EMMC_CORE = 0x1U, CLKEN_EMMC_AXI = 0x1U, CLKEN_EMMC_AHB = 0x1U, CLKEN_EMMC_IO = 0x1U  사용 안함
     * CLKEN_SD_CORE = 0x1U, CLKEN_SD_AXI = 0x1U, CLKEN_SD_AHB = 0x1U, CLKEN_SD_IO = 0x1U  사용 안함
     * CLKEN_ETH_AXI = 0x1U  사용 안함
     * CLKEN_ETH_IO = 0x1U  사용 안함
     */
}
#endif
/* End Of File */
