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
*               INCLUDE
********************************************************************************
*/

#include "Apache.h"
#include "Drv_EMMC.h"
#include "Drv_SCU.h"
#include "Drv_Uart.h"
#include "Drv_OTP.h"
#include "Drv_SDC.h"
#include "main.h"
/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

/* PRQA S 0303,0306,3218 ++ */
volatile DRV_EMMC_REGISTER* const RegA6_EMMC = (DRV_EMMC_REGISTER*)APACHE_EMMC_BASE_ADDR;
/* PRQA S 0303,0306,3218 -- */

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
/* PRQA S 0635 ++*/
typedef struct //__attribute__((__packed__))
{
   UINT16      nADMAFlags : 6;
   UINT16      nDataSizeUpper : 10;
   UINT16      nDataSize;
   UINT32      nDataAddress;
}descriptor_adma2_t;
/* PRQA S 0635 --*/
#define ADMA_FLAGS_DESC_VALID               (0x00000001)
#define ADMA_FLAGS_DESC_END                 (0x00000002)
#define ADMA_FLAGS_OPERATION_TRAN           (0x00000020)
#define MAX_DESCRIPTOR_SIZE                 (0x3FFFFFF)

#define ADMA_DESC_MAX                       (5)
#define ADMA_DESC_SIZE                      (sizeof(descriptor_adma2_t) * (UINT32)ADMA_DESC_MAX)

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Wait time for interrupt setting.
* @param    UINT16      Value   Interrupt value
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF Interrupt value not setting in register THEN
        Wait time for interrupt setting
        IF Wait time over THEN
            Ret = NC_FAILURE
        ENDIF
    ELSE
        Set interrupt value
    ENDIF
    Return Ret
*/
static NC_ERROR NC_EMMC_Wait_INT(UINT16 Value)
{
    NC_ERROR  Ret = NC_SUCCESS;
    UINT32 TimeOut = EMMC_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    while(1)
    {
        if((RegA6_EMMC->NORMAL_INT_STAT_R.Reg & Value) != 0U)
        {
            Status = 1U;
        }

        if(NC_SCU_mTimeOut(TimeOut) == TRUE)
        {
            Ret = NC_FAILURE;
        #ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGINFO, "Wait INT TimeOut = %d\n", Value);
        #endif
            Status = 1U;
        }

        if(Status == 1U)
        {
            break;
        }
    }
    RegA6_EMMC->NORMAL_INT_STAT_R.Reg |= Value;

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    return Ret;
}



/**
* @desc
    Get eMMC frequency division value.
* @param    UINT32  ref_freq    Set frequency value
* @param    UINT32  freq        Target frequency value
* @return   UINT16  Division value
* @design
    div = 0
    IF Set frequency value <= Target frequency value THEN
        div = 1
    ELSE
        div = Calculate division value
    ENDIF
    Return div
*/
static UINT16 NC_EMMC_GetFreqDiv(UINT32 ref_freq, UINT32 freq)
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

    freqdiv >>= 1U;

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, "-------------------------------------------------------\n", NULL);
    DEBUGMSG(MSGINFO, "  > EMMC Freq Info\n", NULL);
    DEBUGMSG(MSGINFO, "    -. Input Freq  = %d\n", ref_freq);
    DEBUGMSG(MSGINFO, "    -. Target Freq = %d\n", freq);
    DEBUGMSG(MSGINFO, "    -. Div         = %d\n", freqdiv);
    DEBUGMSG(MSGINFO, "    -. Setted Freq = %d\n", (UINT32)(ref_freq / (2U * freqdiv)));
#endif

    return freqdiv;
}



/**
* @desc
    Check Internal Clock Stable.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Internal Clock Stable is 1    THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_EMMC_CheckClkStable(void)
{
    return (RegA6_EMMC->CLK_CTRL_R.Bit.INTERNAL_CLK_STABLE == 1U)? TRUE:FALSE;
}



/**
* @desc
    Check Software Reset For CMD line.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Software Reset For CMD line is 0  THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_EMMC_CheckCMDLineWork(void)
{
    return (RegA6_EMMC->SW_RST_R.Bit.SW_RST_CMD == 0U)? TRUE:FALSE;
}



/**
* @desc
    Check Software Reset For DAT line.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  Software Reset For DAT line is 0  THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_EMMC_CheckDATLineWork(void)
{
    return (RegA6_EMMC->SW_RST_R.Bit.SW_RST_DAT == 0U)? TRUE:FALSE;
}



/**
* @desc
    Check ADMA Error.
* @param    void
* @return   BOOL    TRUE or FALSE
* @design
    Ret
    IF  ADMA Error is 1   THEN
        Ret = TRUE
    ELSE
        Ret = FALSE
    ENDIF
    Return Ret
*/
static BOOL NC_EMMC_IntrADMAErr(void)
{
    return (RegA6_EMMC->ERROR_INT_STAT_R.Bit.ADMA_ERR == 1U)? TRUE:FALSE;
}



/**
* @desc
    Wait for Internal Clock Stable.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    TRUE
        IF  Check Internal Clock Stable. == TRUE    THEN
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
static NC_ERROR NC_EMMC_waitForClockStatble(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = EMMC_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_EMMC_CheckClkStable() == TRUE)
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
static NC_ERROR NC_EMMC_waitForCMDLineWork(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = EMMC_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_EMMC_CheckCMDLineWork() == TRUE)
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
static NC_ERROR NC_EMMC_waitForDATLineWork(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOut = EMMC_WAIT_TIMEOUT;
    UINT32 Status = 0U;

    /* INTERNAL_CLK_STABLE */
    while (1)
    {
        if(NC_EMMC_CheckDATLineWork() == TRUE)
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
    Set eMMC clock.
* @param    UINT16  freq_sel    Select eMMC frequency
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Set eMMC freqency from select register
*/
static NC_ERROR NC_EMMC_SetClock(UINT16 freq_sel)
{
    UINT32 read_data;
    NC_ERROR Ret;

    /* FREQ_SEL | INTERNAL_CLK_EN */
    RegA6_EMMC->CLK_CTRL_R.Reg = (UINT16)((UINT16)(freq_sel << 8) | 1U);

    /* INTERNAL_CLK_STABLE */
    Ret = NC_EMMC_waitForClockStatble();

    if(Ret == NC_SUCCESS)
    {
        /* PLL_ENABLE */
        read_data = RegA6_EMMC->CLK_CTRL_R.Reg;
        RegA6_EMMC->CLK_CTRL_R.Reg = (UINT16)(read_data | (1U << 3U));

        /* INTERNAL_CLK_STABLE */
        Ret = NC_EMMC_waitForClockStatble();
    }

    if(Ret == NC_SUCCESS)
    {
        /* SD_CLK_EN */
        read_data = RegA6_EMMC->CLK_CTRL_R.Reg;
        RegA6_EMMC->CLK_CTRL_R.Reg = (UINT16)(read_data | (1U << 2U));

        /* RST CMD Line */
        RegA6_EMMC->SW_RST_R.Reg =  (1U << 1U);

        Ret = NC_EMMC_waitForCMDLineWork();
    }

    if(Ret == NC_SUCCESS)
    {
        /* RST DAT Line */
        RegA6_EMMC->SW_RST_R.Reg =  (1U << 2U);

        Ret = NC_EMMC_waitForDATLineWork();
    }

    return Ret;
}



/**
* @desc
    Prepare eMMC ADMA2 descriptor.
* @param    UINT32  rtype       eMMC read type
* @param    UINT8   *buffer     Read data
* @param    UINT32  Size        Read data size
* @return   void
* @design
    First descriptor table entry points to the buffer.
    Skip Backup size.
    Skip Header 64 byte.

    DO WHILE    nDataLeft > 0.
        Prepare eMMC ADMA2 descriptor.
    LOOP

    write the descriptor addr to the ADMA System Address Registers.
*/
/* for QAC Rule-8.13 */
static void NC_EMMC_PrepareADMA2Descriptor(UINT32 rtype, const UINT8 *buffer, UINT32 Size)
{
    static descriptor_adma2_t adma_desc[ADMA_DESC_SIZE];
    descriptor_adma2_t *pDescTableAddr = (descriptor_adma2_t *)adma_desc;
    volatile descriptor_adma2_t *pDescTable;
    UINT32 nCurrSize;
    UINT32 pData;
    UINT32 nDataLeft = Size;
    UINT32 pDescTableAddrLo;

    /*memset((void*)&adma_desc, 0x0, ADMA_DESC_SIZE);*/
    UINT32 Index;

    for(Index = 0U ; Index < ADMA_DESC_SIZE ; Index++)
    {
         adma_desc[Index].nADMAFlags = 0U;
         adma_desc[Index].nDataSizeUpper = 0U;
         adma_desc[Index].nDataSize = 0U;
         adma_desc[Index].nDataAddress = 0U;
    }

    pDescTable = pDescTableAddr;

    /* First descriptor table entry points to the buffer */
    pData = (UINT32) buffer;

    /* Skip Backup size */
    if(((rtype & 0x0FU) != EMMC_READ_TYPE_NORMAL) && ((rtype & 0x0FU) != EMMC_READ_TYPE_PRIMARY))
    {
        #ifdef OTP_ENABLE_
        UINT32 skipsize = BL_IMG_EMMC_DEFAULT_BACKUP_ADDR + NC_Get_Firmware_Backup_Offset();
        #else
        UINT32 skipsize = BL_IMG_EMMC_DEFAULT_BACKUP_ADDR;
        #endif
        /* for CodeSonar */
        const UINT32 skipblock = EMMC_SECTOR_SIZE;

        while((INT32)skipsize > 0)
        {
            pDescTable->nDataAddress = (UINT32)pData;
            pDescTable->nDataSize = (UINT16)(skipblock & 0xFFFFU);
            pDescTable->nDataSizeUpper = skipblock >> 16U;
            pDescTable->nADMAFlags = (UINT16)ADMA_FLAGS_DESC_VALID | (UINT16)ADMA_FLAGS_OPERATION_TRAN;
            pDescTable++;
            nDataLeft -= skipblock;
            skipsize -= skipblock;
        }
    }

    /* Skip Header 64 byte */
    if((rtype & 0xF0U) == EMMC_WITHOUT_HEADER)
    {
        UINT32 hdrsize = BL_IMG_HEADER_SIZE;
        pDescTable->nDataAddress = pData;
        pDescTable->nDataSize = (UINT16)(hdrsize & 0xFFFFU);
        pDescTable->nDataSizeUpper = hdrsize >> 16U;
        pDescTable->nADMAFlags = (UINT16)ADMA_FLAGS_DESC_VALID | (UINT16)ADMA_FLAGS_OPERATION_TRAN;
        pDescTable++;
        nDataLeft -= hdrsize;
    }

    while (nDataLeft > 0U)
    {
        nCurrSize = MAX_DESCRIPTOR_SIZE;

        if (nCurrSize > nDataLeft)
        {
            nCurrSize = nDataLeft;
        }

        pDescTable->nDataAddress = pData;
        pDescTable->nDataSize = (UINT16)(nCurrSize & 0xFFFFU);
        pDescTable->nDataSizeUpper = nCurrSize >> 16U;
        pDescTable->nADMAFlags = ADMA_FLAGS_DESC_VALID;

        nDataLeft -= nCurrSize;
        pDescTable->nADMAFlags |= (UINT8)ADMA_FLAGS_OPERATION_TRAN;
        pData += nCurrSize;

        /* the last descriptor entry has a DESC_END flag set */
        if (nDataLeft == 0u)
        {
            pDescTable->nADMAFlags |= (UINT8)ADMA_FLAGS_DESC_END;
            break;
        }

        pDescTable++;
    }

    pDescTableAddrLo = (UINT32)pDescTableAddr;

    /* write the descriptor addr to the ADMA System Address Registers */
    RegA6_EMMC->ADMA_SA_HIGH_R.Reg = 0;
    RegA6_EMMC->ADMA_SA_LOW_R.Reg = pDescTableAddrLo;
}



/**
* @desc
   Reset eMMC device.
* @param   void
* @return  void
* @design
    Reset eMMC device
 */
static void NC_EMMC_ResetDevice(void)
{
    RegA6_EMMC->SW_RST_R.Bit.SW_RST_ALL       = ENABLE;
    RegA6_EMMC->EMMC_CTRL_R.Bit.EMMC_RST_N_OE = ENABLE;
    RegA6_EMMC->EMMC_CTRL_R.Bit.EMMC_RST_N    = DISABLE;
    nc_mdelay(1U);
    RegA6_EMMC->EMMC_CTRL_R.Bit.EMMC_RST_N    = ENABLE;
}



/**
* @desc
    Read eMMC data to dummy buffer.
* @param    UINT32  count   Number of read count to dummy
* @return   void
* @design
    Read eMMC FIFO.
 */
static void NC_EMMC_Read2DummyBuffer(UINT32 count)
{
    UINT32 i;
    UINT32 skipcnt = count;
    UINT32 tmp;

    /* PRQA S 2983 ++ */ /* Erase operation on eMMC */
    for(i = 0U; i < skipcnt; i++)
    {
        tmp = RegA6_EMMC->BUF_DATA_R.Reg;
    }
    /* PRQA S 2983 -- */
}



/**
* @desc
    Initialize eMMC.
* @param    UINT32  RefClk  EMMC device clock
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Host Controller Setup Sequence for eMMC Interface
    Set Version 4 Parameters
    Use 32bit addressing
    eMMC speed mode  Legacy, Max clk 26MHz
    embedded 8bit mode
    ADMA2 mode
    Interrupt Enable
    Error Interrupt Enable
 */
NC_ERROR NC_EMMC_Initialize(UINT32 RefClk)
{
    NC_ERROR Ret;
    UINT16 freq_sel;

    RegA6_EMMC->PWR_CTRL_R.Bit.SD_BUS_VOL_VDD1  = EMMC_BUS_VOLTAGE_SELECT_3_3V;
    RegA6_EMMC->PWR_CTRL_R.Bit.SD_BUS_PWR_VDD1  = ENABLE;

    NC_EMMC_ResetDevice();

    /* Host Controller Setup Sequence for eMMC Interface */
    RegA6_EMMC->TOUT_CTRL_R.Bit.TOUT_CNT        = EMMC_TOUT_E;
    RegA6_EMMC->EMMC_CTRL_R.Bit.CARD_IS_EMMC    = ENABLE;

    freq_sel = NC_EMMC_GetFreqDiv(RefClk, SD_BOOT_FREQ);
    Ret = NC_EMMC_SetClock(freq_sel);

    RegA6_EMMC->HOST_CTRL2_R.Bit.UHS2_IF_ENABLE = DISABLE;

    /* Set Version 4 Parameters */
    RegA6_EMMC->HOST_CTRL2_R.Bit.HOST_VER4_ENABLE = ENABLE;

    /* Use 32bit addressing */
    RegA6_EMMC->HOST_CTRL2_R.Bit.ADDRESSING = DISABLE;

    /* eMMC speed mode  Legacy, Max clk 26MHz */
    RegA6_EMMC->HOST_CTRL2_R.Bit.UHS_MODE_SEL = 0;

    /* ADMA2 Data Length mode to 26bit */
    RegA6_EMMC->HOST_CTRL2_R.Bit.ADMA2_LEN_MODE = 1;

    /* embedded 8bit mode */
    RegA6_EMMC->HOST_CTRL1_R.Bit.EXT_DAT_XFER = 1;
    RegA6_EMMC->HOST_CTRL1_R.Bit.DAT_XFER_WIDTH = 0;

    /* ADMA2 mode  */
    RegA6_EMMC->HOST_CTRL1_R.Bit.DMA_SEL = 0x2;

    /* Interrupt Enable */
    RegA6_EMMC->NORMAL_INT_STAT_R.Reg = 0U;
    RegA6_EMMC->NORMAL_INT_STAT_EN_R.Bit.CMD_COMPLETE_STAT_EN  = ENABLE;
    RegA6_EMMC->NORMAL_INT_STAT_EN_R.Bit.XFER_COMPLETE_STAT_EN = ENABLE;
    RegA6_EMMC->NORMAL_INT_STAT_EN_R.Bit.DMA_INTERRUPT_STAT_EN = ENABLE;
    RegA6_EMMC->NORMAL_INT_STAT_EN_R.Bit.BUF_RD_READY_STAT_EN  = ENABLE;

    /* Error Interrupt Enable */
    RegA6_EMMC->ERROR_INT_STAT_EN_R.Reg   = 0xFFFF;
    RegA6_EMMC->ERROR_INT_SIGNAL_EN_R.Reg = 0xFFFF;

    return Ret;
}



/**
* @desc
    Deinitialize eMMC.
* @param    void
* @return   void
* @design
    Deinitialize eMMC device
 */
void NC_EMMC_DeInit(void)
{
    NC_EMMC_ResetDevice();

    RegA6_EMMC->CLK_CTRL_R.Reg = 0U;
}



/**
* @desc
    MultiSingle Block Select.
* @param    UINT32  blockCount  Block Count Value
* @return   void
* @design
    
    IF  blockCount > 1  THEN
        Block Select Enable
    ELSE
        Block Select Disable
    ENDIF
*/
static void NC_EMMC_EnableMultiBlkSelect(UINT32 blockCount)
{
    if(blockCount > 1U)
    {
        RegA6_EMMC->XFER_MODE_R.Bit.MULTI_BLK_SEL = ENABLE;
    }
    else
    {
        RegA6_EMMC->XFER_MODE_R.Bit.MULTI_BLK_SEL = DISABLE;
    }
}



/**
* @desc
    Read eMMC data on ADMA.
* @param    UINT32  rtype   eMMC Data Read type
* @param    UINT32* pData   Read data
* @param    UINT32  Size    Read data size
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Prepare eMMC ADMA2 descriptor
    IF eMMC read data == OK THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
/* for QAC Rule-8.13 */
NC_ERROR NC_EMMC_ReadByADMA2(UINT32 rtype, const UINT32 *pData, UINT32 Size)
{
    NC_ERROR  Ret;
    UINT16 BlkCnt;

    BlkCnt = (UINT16)(Size / EMMC_SECTOR_SIZE);

    if((Size % EMMC_SECTOR_SIZE) != 0U)
    {
        BlkCnt = BlkCnt + 1U;
    }

    NC_EMMC_PrepareADMA2Descriptor(rtype, (const UINT8 *)pData, ((UINT32)BlkCnt * (UINT32)EMMC_SECTOR_SIZE));

    RegA6_EMMC->BLOCKSIZE_R.Bit.XFER_BLOCK_SIZE = EMMC_SECTOR_SIZE;

    /* Enabled Host Version 4 */
    RegA6_EMMC->BLOCKCOUNT_R.Bit.BLOCK_CNT = 0U;
    RegA6_EMMC->SDMASA_R.Reg               = BlkCnt;

    RegA6_EMMC->XFER_MODE_R.Bit.DMA_ENABLE         = ENABLE;
    RegA6_EMMC->XFER_MODE_R.Bit.BLOCK_COUNT_ENABLE = ENABLE;
    RegA6_EMMC->XFER_MODE_R.Bit.DATA_XFER_DIR      = EMMC_TRANSFER_READ;

    /* It must be desabled when operating in boot mode. */
    RegA6_EMMC->XFER_MODE_R.Bit.AUTO_CMD_ENABLE    = EMMC_AUTO_CMD_DISABLED;/*EMMC_AUTO_CMD12_ENABLED;*/

    NC_EMMC_EnableMultiBlkSelect(BlkCnt);

    RegA6_EMMC->BOOT_CTRL_R.Reg = EMMC_VALIDATE_BOOT_EN | EMMC_MANDATORY_BOOT_EN;

    if(NC_EMMC_Wait_INT(EMMC_XFER_COMPLETE) == NC_SUCCESS)
    {
        Ret = NC_SUCCESS;
        DEBUGMSG(MSGINFO, "XFER_COMPLETE \n", NULL);
    }
    else
    {
        if(NC_EMMC_IntrADMAErr() == TRUE)
        {
            DEBUGMSG(MSGERR, "ADMA_ERR!!!\n", NULL);
        }
        else
        {
            DEBUGMSG(MSGERR, "XFER Timeout!!!\n", NULL);
        }
        Ret = NC_FAILURE;
    }

    return Ret;
}



/**
* @desc
    Set skip size and block count.
* @param    UINT32      readType        Read Type
* @param    UINT32*     pSkipCount      Skip count
* @param    UINT32*     pSkipBlkCount   Skip Block count
* @return   void
* @design
    IF  This is a value that matches readType.  THEN
        Calculate skipcnt and skipblkcnt.
    ENDIF

    pSkipCount = skipcnt
    pSkipBlkCount = skipblkcnt
*/
static void NC_EMMC_SetSkipSizeAndBlkCount(UINT32 readType, UINT32 *pSkipCount, UINT32 *pSkipBlkCount)
{
    UINT32 skipcnt;
    UINT32 skipblkcnt;

    if(readType == EMMC_READ_TYPE_PRIMARY)
    {
        skipcnt = BL_IMG_HEADER_SIZE/sizeof(UINT32);
        skipblkcnt = 0U;
    }
    else if(readType == EMMC_READ_TYPE_BACKUP)
    {
        #ifdef OTP_ENABLE_
        skipcnt = (BL_IMG_EMMC_DEFAULT_BACKUP_ADDR + BL_IMG_HEADER_SIZE + NC_Get_Firmware_Backup_Offset());
        #else
        skipcnt = (BL_IMG_EMMC_DEFAULT_BACKUP_ADDR + BL_IMG_HEADER_SIZE);
        #endif
        skipblkcnt = skipcnt/EMMC_SECTOR_SIZE;
        skipcnt %= EMMC_SECTOR_SIZE;
        skipcnt /= sizeof(UINT32);
        /*skipblkcnt++;*/
    }
    else
    {
        skipblkcnt = 0U;
        skipcnt = 0U;
    }

    *pSkipCount = skipcnt;
    *pSkipBlkCount = skipblkcnt;
}



/**
* @desc
    Read data from EMMC FIFO.
* @param    UINT32  rtype   eMMC Data Read type
* @param    UINT32  pData   Read data
* @param    UINT32  Size    Read data size
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NS_SUCCESS
    IF eMMC read data == OK THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
NC_ERROR NC_EMMC_ReadByFIFO(UINT32 rtype, UINT32 *pData, UINT32 Size)
{
    NC_ERROR    Ret = NC_SUCCESS;
    UINT32      i, j;
    UINT32      *buffer32 = pData;
    UINT16      BlkCnt;
    UINT32      SecCnt;
    UINT32      skipcnt, skipblkcnt;

    BlkCnt = (UINT16)(Size / EMMC_SECTOR_SIZE);

    if((Size % EMMC_SECTOR_SIZE) != 0U)
    {
        BlkCnt = BlkCnt + 1U;
    }

    RegA6_EMMC->BLOCKSIZE_R.Bit.XFER_BLOCK_SIZE = EMMC_SECTOR_SIZE;
    RegA6_EMMC->BLOCKSIZE_R.Bit.SDMA_BUF_BDARY  = EMMC_SDMA_BUF_BDARY_512K; /* 512K BDARY */

    /* Enabled Host Version 4 */
    RegA6_EMMC->BLOCKCOUNT_R.Bit.BLOCK_CNT = 0U;
    RegA6_EMMC->SDMASA_R.Reg               = BlkCnt;

    /*
     *  0 : No data transfer or Non-DMA data transfer.
     *  1 : DMA Data transfer.
     */
    RegA6_EMMC->XFER_MODE_R.Bit.DMA_ENABLE          = DISABLE;
    RegA6_EMMC->XFER_MODE_R.Bit.BLOCK_COUNT_ENABLE  = ENABLE;
    /*RegA6_EMMC->XFER_MODE_R.Bit.AUTO_CMD_ENABLE     = EMMC_AUTO_CMD12_ENABLED;*/
    RegA6_EMMC->XFER_MODE_R.Bit.AUTO_CMD_ENABLE     = EMMC_AUTO_CMD_DISABLED;
    RegA6_EMMC->XFER_MODE_R.Bit.DATA_XFER_DIR       = EMMC_TRANSFER_READ;
    NC_EMMC_EnableMultiBlkSelect(BlkCnt);

    RegA6_EMMC->BOOT_CTRL_R.Reg = EMMC_VALIDATE_BOOT_EN | EMMC_MANDATORY_BOOT_EN;

    NC_EMMC_SetSkipSizeAndBlkCount(rtype, &skipcnt, &skipblkcnt);

    for(j = 0U; j < BlkCnt; j++)
    {
        SecCnt = (EMMC_SECTOR_SIZE / sizeof(UINT32));
        if(NC_EMMC_Wait_INT(EMMC_BUF_RD_READY) == NC_SUCCESS)
        {
            if( (rtype == EMMC_READ_TYPE_PRIMARY) && (j == 0U) )
            {
                NC_EMMC_Read2DummyBuffer(skipcnt);
                SecCnt -= skipcnt;
            }
            else if( (rtype == EMMC_READ_TYPE_BACKUP) && (j <= skipblkcnt) )
            {
                if(j < skipblkcnt)
                {
                    NC_EMMC_Read2DummyBuffer(SecCnt);
                    SecCnt = 0;
                }
                else
                {
                    NC_EMMC_Read2DummyBuffer(skipcnt);
                    SecCnt -= skipcnt;
                }
            }
            else
            {
                /* */
            }
            
            for(i = 0U; i < SecCnt; i++)
            {
                *buffer32 = RegA6_EMMC->BUF_DATA_R.Reg;
                buffer32++;
            }
        }
        else
        {
#ifdef DEBUG_ENABLE_
            DEBUGMSG(MSGWARN, "ReadReady Timeout PSTATE : %08X, blknum : %d\n", RegA6_EMMC->PSTATE_REG.Reg, j);
#endif
            Ret = NC_FAILURE;
            break;
        }
    }

    if(NC_EMMC_Wait_INT(EMMC_XFER_COMPLETE) == NC_FAILURE)
    {
        Ret = NC_FAILURE;
        DEBUGMSG(MSGWARN, "Timeout XFER_COMPLETE for FIFO read\n", NULL);
    }

    return Ret;
}

/* End Of File */
