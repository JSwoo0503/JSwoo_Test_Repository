/**
********************************************************************************
*
*  Copyright (C) 2017 NEXTCHIP Inc. All rights reserved.
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
#include "Drv_SDC.h"
#include "Drv_A6_SD_Register.h"
#include "Drv_SCU.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

/* PRQA S 0303,0306,3218 ++ */
static volatile DRV_SD_REGISTER*         const RegA6_SD      = (DRV_SD_REGISTER*)APACHE_SD_BASE_ADDR;
/* PRQA S 0303,0306,3218 -- */

#define RCA                              (RegA6_CPU_SCU->CPU_SCU_DEBUG10.Reg)

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Wait SD interrupt.
* @param    UINT16  Value   SD interrupt
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF Check SD status interrupt == 0 THEN
        IF Wait time over THEN
            Ret = NC_FAILURE
        ENDIF
    ENDIF
    Set SD interrupt
    Return Ret
 */
static NC_ERROR SD_Wait_INT(UINT16 Value)
{
    NC_ERROR  Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    while(1)
    {
        if((RegA6_SD->NORMAL_INT_STAT_R.Reg & Value) != 0U)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
        #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Wait INT TimeOut = %d\n", Value);
        #endif
        }

        if(Status == 1U)
        {
            break;
        }
    }
    RegA6_SD->NORMAL_INT_STAT_R.Reg = Value;

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    return Ret;
}



/**
* @desc
    Wait SD command.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF SD command interrupt == 1 THEN
        IF Wait time over THEN
            Ret = NC_FAILURE
        ENDIF
    ENDIF
    Return Ret
*/
static NC_ERROR SD_WaitCMD(void)
{
    NC_ERROR  Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    while(1)
    {
        if(RegA6_SD->PSTATE_REG.Bit.CMD_INHIBIT != 1U)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
        #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Wait CMD TimeOut\n", NULL);
        #endif
        }

        if(Status == 1U)
        {
            break;
        }
    }

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    return Ret;
}



/**
* @desc
    Wait SD Data.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF SD Data command == 1 THEN
        IF Wait time over THEN
            Ret = NC_FAILURE
        ENDIF
    ENDIF
    Return Ret
*/
static NC_ERROR SD_WaitCMD_DAT(void)
{
    NC_ERROR  Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    while(1)
    {
        if(RegA6_SD->PSTATE_REG.Bit.CMD_INHIBIT_DAT != 1U)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
        #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Wait CMD DAT TimeOut\n", NULL);
        #endif
        }

        if(Status == 1U)
        {
            break;
        }

    }

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    return Ret;
}



/**
* @desc
    Get SD frequency divide.
* @param    UINT32  ref_freq    Set frequency value
* @param    UINT32  freq        Target frequency value
* @return   UINT16  SD frequency divide
* @design
    IF Set frequency value <= Target frequency value THEN
        Ret = 1
    ELSE
        Ret = Calculate division value
    ENDIF
    Ret >>= 1
    Return Ret
*/
static UINT16 NC_SDC_GetFreqDiv(UINT32 ref_freq, UINT32 freq)
{
    UINT16 freqdiv;

    /* Version 3.00 divisors must be a multiple of 2. */
    if(ref_freq <= freq)
    {
        freqdiv = 1U;
    }
    else
    {
        for (freqdiv = 2U; freqdiv < SDHCI_MAX_DIV_SPEC_300; freqdiv += 2U)
        {
            if ((ref_freq / freqdiv) <= freq)
            {
                break;
            }
        }
    }
#if 1
    freqdiv >>= 1U;
#endif

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > SD Freq Info\n", NULL);
    DEBUGMSG(MSGINFO, "    -. Input Freq  = %d\n", ref_freq);
    DEBUGMSG(MSGINFO, "    -. Target Freq = %d\n", freq);
    DEBUGMSG(MSGINFO, "    -. Div         = %d\n", freqdiv);
    DEBUGMSG(MSGINFO, "    -. Setted Freq = %d\n", ref_freq / (2U * freqdiv));
#endif

    return freqdiv;
}



/**
* @desc
    Check Clock Stable.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Internal Clock Stable is '1'    THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_SDC_CheckClkStable(void)
{
    return (RegA6_SD->CLK_CTRL_R.Bit.INTERNAL_CLK_STABLE == 1U)? TRUE:FALSE;
}



/**
* @desc
    Check CMD Line Work.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Software Reset For CMD line is '0'    THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_SDC_CheckCMDLineWork(void)
{
    return (RegA6_SD->SW_RST_R.Bit.SW_RST_CMD == 0U)? TRUE:FALSE;
}



/**
* @desc
    Check DAT Line Work.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Software Reset For DAT line is '0'    THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_SDC_CheckDATLineWork(void)
{
    return (RegA6_SD->SW_RST_R.Bit.SW_RST_DAT == 0U)? TRUE:FALSE;
}



/**
* @desc
    Wait for clock statble.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    TRUE
        IF  Check Clock Stable==TRUE    THEN
            break
        ENDIF

        IF  Time out    THEN
            break
        ELSE
            Time check.
        ENDIF
    LOOP
    Return Ret
*/
static NC_ERROR NC_SDC_waitForClockStatble(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_SDC_CheckClkStable() == TRUE)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
            DEBUGMSG(MSGERR, "%s Wait INT TimeOut\n", __func__);
        }

        if(Status == 1U)
        {
            break;
        }
    }
    
    return Ret;
}



/**
* @desc
    Wait until the command line is not in the working state.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    TRUE
        IF  CMD line work is false. THEN
            break
        ENDIF

        IF  Timeout THEN
            Ret = NC_FAILURE
            break
        ELSE
            Check Time
        ENDIF
    LOOP
    Return Ret
*/
static NC_ERROR NC_SDC_waitForCMDLineWork(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_SDC_CheckCMDLineWork() == TRUE)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
            DEBUGMSG(MSGERR, "%s Wait INT TimeOut\n", __func__);
        }

        if(Status == 1U)
        {
            break;
        }
    }
    
    return Ret;
}



/**
* @desc
    Wait for dat line work.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    TRUE
        IF  DAT line work is false. THEN
            break
        ENDIF

        IF  Timeout THEN
            Ret = NC_FAILURE
            break
        ELSE
            Check Time
        ENDIF
    LOOP
    Return Ret
*/
static NC_ERROR NC_SDC_waitForDATLineWork(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = SD_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_SDC_CheckDATLineWork() == TRUE)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
            Status = 1U;
            DEBUGMSG(MSGERR, "%s Wait INT TimeOut\n", __func__);
        }

        if(Status == 1U)
        {
            break;
        }
    }
    
    return Ret;
}

/**
* @desc
    Set SD clock.
* @param    UINT16  freq_sel    Set clock
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = Check DAT Line Work.

    IF  Ret == NC_SUCCESS   THEN
        PLL Enable
        Ret = Wait for clock stable.
    ENDIF

    IF  Ret==NC_SUCCESS     THEN
        SD clock enable
        Ret = Wait until the command line is not in the working state.
    ENDIF

    IF  Ret==NC_SUCCESS     THEN
        Reset data line
        Ret = Wait for dat line work.
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SDC_SetClock(UINT16 freq_sel)
{
    NC_ERROR Ret;
    UINT32 read_data;

    /* FREQ_SEL | INTERNAL_CLK_EN */
    RegA6_SD->CLK_CTRL_R.Reg = (UINT16)((UINT16)(freq_sel << 8) | 1U);

    /* INTERNAL_CLK_STABLE */
    Ret = NC_SDC_waitForClockStatble();
    
    if(Ret == NC_SUCCESS)
    {
        read_data = RegA6_SD->CLK_CTRL_R.Reg;

        /* PLL_ENABLE */
        RegA6_SD->CLK_CTRL_R.Reg = (UINT16)read_data | (1U << 3U);

        /* INTERNAL_CLK_STABLE */
        Ret = NC_SDC_waitForClockStatble();
    }

    if(Ret == NC_SUCCESS)
    {
        read_data = RegA6_SD->CLK_CTRL_R.Reg;

        /* SD_CLK_EN */
        RegA6_SD->CLK_CTRL_R.Reg = (UINT16)read_data | (1U << 2U);

        /* RST CMD Line */
        RegA6_SD->SW_RST_R.Reg = (1U << 1U);

        Ret = NC_SDC_waitForCMDLineWork();
    }

    if(Ret == NC_SUCCESS)
    {
        /* RST DAT Line */
        RegA6_SD->SW_RST_R.Reg = (1U << 2U);

        Ret = NC_SDC_waitForDATLineWork();
    }
    
    return Ret;
}



/**
* @desc
    Set SD command 0.
* @param    void
* @return   void
* @design
    Set SD command 0
*/
static void NC_SDC_CMD0(void)
{
    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = 0U;
    RegA6_SD->CMD_R.Reg = 0U;

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    (void)SD_WaitCMD();

    /* wait for 74 clock cycles. */
    nc_mdelay(10U);
}



/**
* @desc
    Set SD command 8.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    IF Set SD command 8 == OK THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SDC_CMD8(void)
{
    NC_ERROR  Ret = NC_FAILURE;
    UINT32 read_data32;
    UINT8 VHS;

    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    /* 0x100(Voltage supplied) + 0x0AA(Check pattern) */
    RegA6_SD->ARGUMENT_R.Reg = 0x1AAU;
    RegA6_SD->CMD_R.Reg = (((UINT16)8U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    read_data32 = RegA6_SD->RESP01_R.Reg;

    (void)SD_WaitCMD();

    VHS = (UINT8)((read_data32 >> 8U) & 0xFU);

    switch (VHS)
    {
        case 0x0000:
            break;
        case 0x0001:
            Ret = NC_SUCCESS;
            break;
        default:
            /* */
            #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Not Defined\n", NULL);
            #endif
            break;
    }

    return Ret;
}



/**
* @desc
    Set SD commnad 55.
* @param    UINT32  Argument    Argument
* @return   UINT32  Command Response Value 
* @design
    Set SD command 55
    Read SD command 55 response data
    Return response data
*/
static UINT32 NC_SDC_CMD55(UINT32 Argument)
{
    UINT32 resp;

    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = Argument;
    RegA6_SD->CMD_R.Reg = (((UINT16)55U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    resp = RegA6_SD->RESP01_R.Reg;

    (void)SD_WaitCMD();

    return resp;
}



/**
* @desc
    Set SD ADMA command 41.
* @param    void
* @return   UINT32  Command Response Value 
* @design
    Set SD ADMA command 41
    Read SD ADMA command 41 reponse data
    Return response data
*/
static UINT32 NC_SDC_ACMD41(void)
{
    UINT32 resp;

    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = 0x40FF8000;
    RegA6_SD->CMD_R.Reg = (((UINT16)41U << 8U) | SD_IDX_CHK_DIS | SD_CMD_CHK_DIS | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    resp = RegA6_SD->RESP01_R.Reg;

    (void)SD_WaitCMD();

    return resp;
}



/**
* @desc
    Set SD command 2.
* @param    void
* @return   void
* @design
    Set SD command 2
*/
static void NC_SDC_CMD2(void)
{
    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = 0x0;
    RegA6_SD->CMD_R.Reg = (((UINT16)2U << 8U) | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_136);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    (void)SD_WaitCMD();
}



/**
* @desc
    Set SD command 3.
* @param    void
* @return   void
* @design
    Set SD command 3
*/
static void NC_SDC_CMD3(void)
{
    UINT32 read_data32;

    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = 0x0;
    RegA6_SD->CMD_R.Reg = (((UINT16)3U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    read_data32 = RegA6_SD->RESP01_R.Reg;

    (void)SD_WaitCMD();

    RCA = (read_data32 & 0xFFFF0000U);
}



/**
* @desc
    Set SD command 7.
* @param    UINT32  Argument    Argument
* @return   void
* @design
    Set SD command 7
*/
static void NC_SDC_CMD7(UINT32 Argument)
{
    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = Argument;
    RegA6_SD->CMD_R.Reg = (((UINT16)7U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48B);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);
    (void)SD_Wait_INT(SD_XFER_COMPLETE);

    (void)SD_WaitCMD();
}



/**
* @desc
    Set SD command 6.
* @param    UINT32  Argument    Argument
* @return   void
* @design
    Set SD command 6
*/
static void NC_SDC_ACMD6(UINT32 Argument)
{
    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = Argument;
    RegA6_SD->CMD_R.Reg = (((UINT16)6U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    (void)SD_WaitCMD();
}



/**
* @desc
    Set SD command 16.
* @param    UINT32  Argument    Argument
* @return   void
* @design
    set SD command 16
*/
static void NC_SDC_CMD16(UINT32 Argument)
{
    RegA6_SD->XFER_MODE_R.Reg = (SD_BLOCK_CNT_ENABLE | SD_DATA_XFER_READ | SD_MULT_BLK_SEL);
    RegA6_SD->ARGUMENT_R.Reg = Argument;
    RegA6_SD->CMD_R.Reg = (((UINT16)16U << 8U) | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);

    (void)SD_WaitCMD();
}



/**
* @desc
    Set SD command 17.
* @param    UINT32  Argument    Argument
* @param    UINT32  *pData      Read data
* @return   void
* @design
    Set SD command 17
    Get SD data
*/
static void NC_SDC_CMD17(UINT32 Argument, UINT32 *pData)
{
    UINT32 i;

    RegA6_SD->XFER_MODE_R.Reg = (SD_SINGLE_BLK_SEL | SD_DATA_XFER_READ | SD_BLOCK_CNT_ENABLE | SD_AUTO_CMD12_ENABLE);
    RegA6_SD->BLOCKCOUNT_R.Reg  = 1U;
    RegA6_SD->BLOCKSIZE_R.Reg = SD_SECTOR_SIZE;
    RegA6_SD->ARGUMENT_R.Reg = Argument;
    RegA6_SD->CMD_R.Reg = (((UINT16)17U << 8U) | SD_DATA_PRESENT | SD_IDX_CHK_ENB | SD_CMD_CHK_ENB | (UINT16)SD_RESP_LEN_48);

    (void)SD_Wait_INT(SD_CMD_COMPLETE);
    (void)SD_Wait_INT(SD_BUF_RD_READY);

    for(i = 0U; i < ((UINT32)(SD_SECTOR_SIZE) / 4U); i++)
    {
        pData[i] = RegA6_SD->BUF_DATA_R.Reg;
    }

    (void)SD_WaitCMD_DAT();
    (void)SD_Wait_INT(SD_XFER_COMPLETE);
}



/**
* @desc
    SD initialize.
* @param    UINT32      RefClk  SD target frequency
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret
    Set SD register initialize
    Get SD frequency divide
    Set SD clock
    Ret = Check SDC CMD8
    Return Ret
*/
NC_ERROR NC_SDC_Init(UINT32 RefClk)
{
    NC_ERROR  Ret;
    UINT32 nCnt;
    UINT32 read_data32[4];
    UINT16 freq_sel;

    RegA6_SD->PWR_CTRL_R.Reg = (SD_BUS_VOL_VDD1_33 | (UINT8)SD_BUS_PWR_VDD1_OFF);

    RegA6_SD->HOST_CTRL1_R.Reg = ((UINT8)SD_DATA_WIDTH_4 | SD_SPEED_NORMAL | SD_SDMA_SEL);

    RegA6_SD->HOST_CTRL2_R.Reg = ((UINT16)SD_SDR12
                                | (UINT16)SD_33V_SWITCH
                                | SD_EXEC_TUNE_OFF
                                | SD_RX_FIXED_CLK
                                | SD_SD_eMMC_INF
                                | SD_ADMA2_LEN_26BIT
                                | SD_CMD23_EN
                                | SD_HOST_VER4_EN
                                | SD_ADDRESS_32
                                | SD_ASYNC_INT_EN
                                | SD_PRESET_VAL_DIS);

    RegA6_SD->PWR_CTRL_R.Reg = (SD_BUS_VOL_VDD1_33 | (UINT8)SD_BUS_PWR_VDD1_ON);

    RegA6_SD->HOST_CTRL2_R.Reg = ((UINT16)SD_SDR12
                                | SD_33V_SWITCH
                                | SD_EXEC_TUNE_OFF
                                | SD_RX_FIXED_CLK
                                | SD_SD_eMMC_INF
                                | SD_ADMA2_LEN_26BIT
                                | SD_CMD23_EN
                                | SD_HOST_VER4_EN
                                | SD_ADDRESS_32
                                | SD_ASYNC_INT_EN);

    /* MSHC_CTRL_R / (SW_CG_DIS | CMD_CONFLICT_CHECK) */
    RegA6_SD->MSHC_CTRL_R.Reg = (((UINT8)1U << 4U) | (UINT8)1U);

    /* Change Freq to 400KHz */
    freq_sel = NC_SDC_GetFreqDiv(RefClk, SD_INIT_FREQ);
    Ret = NC_SDC_SetClock(freq_sel);
    if(Ret == NC_SUCCESS)
    {
        RegA6_SD->NORMAL_INT_STAT_EN_R.Reg = SD_CMD_COMPLETE
                                            | SD_XFER_COMPLETE
                                            | SD_BGAP_EVENT
                                            | SD_DMA_INTERRUPT
                                            | SD_BUF_WR_READY
                                            | SD_BUF_RD_READY
                                            | SD_CARD_INSERTION
                                            | SD_CARD_REMOVAL;

        RegA6_SD->ERROR_INT_STAT_EN_R.Reg = SD_CMD_TOUT_ERR
                                            | SD_CMD_CRC_ERR
                                            | SD_CMD_END_BIT_ERR
                                            | SD_CMD_IDX_ERR
                                            | SD_DATA_TOUT_ERR
                                            | SD_DATA_CRC_ERR
                                            | SD_DATA_END_BIT_ERR
                                            | SD_CUR_LMT_ERR
                                            | SD_AUTO_CMD_ERR
                                            | SD_ADMA_ERR
                                            | SD_TUNING_ERR
                                            | SD_RESP_ERR;

        RegA6_SD->TOUT_CTRL_R.Reg = 0xE;

        NC_SDC_CMD0();

    #if 1
        nCnt = 0U;
        do
        {
            RegA6_HSP_SCU->SD_PAD_OUT_SHIFT.Bit.SHIFT_SEL_SD_PAD_OUT = nCnt;

            Ret = NC_SDC_CMD8();
            if(Ret == NC_SUCCESS)
            {
                RegA6_HSP_SCU->SD_PAD_OUT_SHIFT.Bit.SHIFT_SEL_SD_PAD_OUT = nCnt + 1U;
            }
            nCnt++;
            nc_mdelay(1U);
        } while ((Ret == NC_FAILURE) && (nCnt < 8U));
    #else
        Ret = NC_SDC_CMD8();
    #endif
    }

    if (Ret == NC_SUCCESS)
    {
#if 0
        do
        {
            read_data32[0] = NC_SDC_CMD55(0x0);
            read_data32[0] = NC_SDC_ACMD41();

            nCnt++;
            nc_mdelay(100U);
        } while (((read_data32[0] & SD_BUSY) != SD_BUSY) && (nCnt < 10U));
#else
        read_data32[0] = NC_SDC_CMD55(0x0);
        read_data32[0] = NC_SDC_ACMD41();
        nCnt = 0U;
        while (((read_data32[0] & SD_BUSY) != SD_BUSY) && (nCnt < 10U))
        {
            read_data32[0] = NC_SDC_CMD55(0x0);
            read_data32[0] = NC_SDC_ACMD41();

            nCnt++;
            nc_mdelay(100U);
        }
#endif

        NC_SDC_CMD2();
        NC_SDC_CMD3();

        /* Select SD card */
        NC_SDC_CMD7(RCA);

        /* Change Freq to 25MHz */
        freq_sel = NC_SDC_GetFreqDiv(RefClk, SD_DATA_FREQ);
        Ret = NC_SDC_SetClock(freq_sel);
    }
    else
    {
        NC_SDC_DeInit();
    #ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGINFO, "  > SDC command [NC_SDC_CMD8] error\n", NULL);
    #endif
    }

    return Ret;
}



/**
* @desc
    Deinitialize SD register.
* @param    void
* @return   void
* @design
    Deinitialize SD register
*/
void NC_SDC_DeInit(void)
{
    NC_SDC_CMD0();

    RegA6_SD->CLK_CTRL_R.Reg = 0U;
}



/**
* @desc
    Read data from SD.
* @param    UINT32  Addr    SD card address
* @param    UINT32  *pData  Read data
* @param    UINT32  Size    Read data size
* @return   void
* @design
    Read data from SD
    Return NC_SUCCESS
*/
void NC_SDC_Read(UINT32 Addr, UINT32 *pData, UINT32 Size)
{
    UINT32 BlkCnt;
    UINT32* pInBuff = pData;
    UINT32 buffIdx = 0U;
    UINT32 read_data32[4];
    UINT32 i;
    UINT32 Raddr = Addr;

    /* Set bit width */
    read_data32[0] = NC_SDC_CMD55(RCA);

    /* Set data transfer width */
    NC_SDC_ACMD6((UINT8)SD_DATA_WIDTH_4);

    /* Set block length */
    NC_SDC_CMD16(SD_SECTOR_SIZE);

    BlkCnt = (UINT32)(Size / (UINT32)SD_SECTOR_SIZE);

    if((Size % (UINT32)SD_SECTOR_SIZE) != 0U)
    {
        BlkCnt = BlkCnt + 1U;
    }

    for (i = 0U; i < BlkCnt; i++)
    {
        NC_SDC_CMD17(Raddr, &(pInBuff[buffIdx]));

        Raddr += 1U;
        buffIdx += ((UINT32)SD_SECTOR_SIZE / 4U);
    }
}


/* End Of File */
