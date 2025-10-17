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
#include "Drv_SPI.h"
#include "Drv_SCU.h"
#include "Drv_A6_CPU_SCU_Register.h"
#include "Svc_sFlash.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/
/* PRQA S 0303,0306,3218 ++ */
static volatile DRV_SPI_REGISTER* const RegA6_SPI = (DRV_SPI_REGISTER *)APACHE_QSPI_BASE_ADDR;
volatile DRV_QSPI_REGISTER* const RegA6_QSPI = (DRV_QSPI_REGISTER *)APACHE_QSPI_BASE_ADDR;
/* PRQA S 0303,0306,3218 -- */

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Wait until the SPI TX FIFO is empty.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    SPI TX FIFO is empty.
        IF  Time out occurs.    THEN
            Ret = NC_FAILURE
            Exit Do
        ENDIF
    LOOP
    Return Ret
*/
NC_ERROR NC_SPI_WaitTxFIFOIsEmpty(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOutFlag = 0U;

    while(1)
    {
        /* TFE(1) : Transmit FIFO is empty, TFE(0) : Not Empty */
        if( (RegA6_SPI->SR.Bit.TFE == 0U) && (TimeOutFlag == 0U) )
        {
            if(NC_SCU_mTimeOut(SPI_WAIT_TIMEOUT) == TRUE)
            {
                Ret = NC_FAILURE;
                TimeOutFlag = 1U;
            }
        }
        else
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
    Wait until the SPI BUS is idle.
* @param    void
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    DO WHILE    SPI is busy.
        IF  Time out occurs.    THEN
            Ret = NC_FAILURE
            Exit Do
        ENDIF
    LOOP
    Return Ret
*/
NC_ERROR NC_SPI_WaitBusIsBusy(void)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT32 TimeOutFlag = 0U;

    while(1)
    {
        if( (RegA6_SPI->SR.Bit.BUSY == 1U) && (TimeOutFlag == 0U) )
        {
            if(NC_SCU_mTimeOut(SPI_WAIT_TIMEOUT) == TRUE)
            {
                Ret = NC_FAILURE;
                TimeOutFlag = 1U;
            }
        }
        else
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
    Initialize the IP to use SPI.
* @param    UINT32  BitRate     Bitrate value of SPI.
* @param    UINT32  RefClk      Reference clock value.
* @return   void
* @design
    To use SPI, set the value in Register.
*/
void NC_SPI_Init(UINT32 BitRate, UINT32 RefClk)
{
    UINT32 SPI_CLK_INV;
    UINT32 SPI_RX_DELAY;
    UINT32 Reg;

    /* SPI Disable */
    RegA6_SPI->SSIENR.Reg = DISABLE;

    /* Polarity & Phase config setting(from OTP or file header) */
    switch(gSPI_CLK_POL_PH)
    {
        case 0x1:   /* Polarity(0), Phase(1) */
            SPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
            SPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
            break;
        case 0x2:   /* Polarity(1), Phase(0) */
            SPI_CLK_INV = ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPOL);
            SPI_CLK_INV |= ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPH);
            break;
        case 0x3:   /* Polarity(1), Phase(1) */
            SPI_CLK_INV = ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPOL);
            SPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
            break;
        default:    /* case 0x0 : Polarity(0), Phase(0) */
            SPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
            SPI_CLK_INV |= ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPH);
            break;
    }

    /* CLK Inversion */
    if(gSPI_CLK_INV == TRUE)
    {
        SPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
        SPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
    }

    /* Protocol Set - Motorora SPI, Width, Clk/Data Pol */
    Reg = ((UINT32)SPI_DS_8BIT << (UINT32)SPI_DFS32);
    Reg |= (UINT32)(SPI_CLK_INV);
    Reg |= ((UINT32)SPI_TMOD_READ << (UINT32)SPI_TMOD8);
    Reg |= ((UINT32)SPI_SLV_OE_DIS << (UINT32)SPI_SLV_OE);
    /*Reg |= ((UINT32)SPI_SRL_NORMAL_MODE << (UINT32)SPI_SRL);*/
    Reg |= ((UINT32)SPI_CS_8BIT << (UINT32)SPI_CFS16);
    /*Reg |= ((UINT32)SPI_TRANS_MODE_SPI << (UINT32)SPI_FRAME_FORMAT);*/

    RegA6_SPI->CTRLR0.Reg = Reg;

    /* Slave Enable */
    RegA6_SPI->SER.Reg = ENABLE;

    /*
     * Fsclk_out(Bitrate) = Fssi_clk/SCKDV
     * -. Fssi_clk = InClk
     * -. SCKDV = Div ( RegA6_SPI[Ch]->BAUDR.Reg)
     */
    RegA6_SPI->BAUDR.Reg = (UINT32)(RefClk / BitRate);

    /* Receive FIFO Threshold Set */
    RegA6_SPI->TXFTLR.Reg = 0xFF;
    RegA6_SPI->RXFTLR.Reg = 0xFF;

    /* NDF */
    RegA6_SPI->CTRLR1.Reg = 0U;

    /* Interrupt Enable */
    /* RegA6_SPI->IMR.Reg = SPI_IMR_RXFIM; */

    /* Transmit Data Level */
    RegA6_SPI->DMATDLR.Reg = 0U;
    RegA6_SPI->DMARDLR.Reg = 0U;


    SPI_RX_DELAY = gSPI_RX_DELAY;
    SPI_RX_DELAY &= 0x000000FFU;
    if(SPI_RX_DELAY > 0U)
    {
        RegA6_SPI->RX_SAMPLE_DLY.Bit.RSD = (UINT8)SPI_RX_DELAY;
    }


    /* SPI Enable */
    RegA6_SPI->SSIENR.Reg = ENABLE;

    /* CSN CONTROL */
    RegA6_SPI->CSN_CONTROL.Bit.CSN_SEL = ENABLE;
}



/**
* @desc
    Disable SPI usage.
* @param    void
* @return   void
* @design
    Set a value in Register to disable the SPI.
*/
void NC_SPI_DeInit(void)
{
    RegA6_SPI->SSIENR.Reg = DISABLE;
}



/**
* @desc
    Read data by 1 bytes.
* @param    UINT8*  pBuf    Data buffer
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Read Data from SPI Register.
        Data Length --
    LOOP
*/
void NC_SPI_Read(UINT8 *pBuf, UINT32 Length)
{
    UINT32 i;

    NC_SPI_SetTMOD(SPI_TMOD_READ);

    for(i = 0; i < Length; i++)
    {
        /* Check Busy */
        (void)NC_SPI_WaitBusIsBusy();

        /* Write Dummy data */
        RegA6_SPI->DRX.Reg = 0x00U;

        /* Check Busy */
        (void)NC_SPI_WaitBusIsBusy();

        /* Read data */
        pBuf[i] = (UINT8)(RegA6_SPI->DRX.Reg & 0xFFU);
    }
}



/**
* @desc
    Writes data by 1 bytes.
* @param    UINT8*  pBuf    Data buffer
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Write Data to SPI Register.
        Data Length --
    LOOP
*/
void NC_SPI_Write(const UINT8 *pBuf, UINT32 Length)
{
    UINT32 i;

    NC_SPI_SetTMOD(SPI_TMOD_WRITE);

    for(i = 0U; i < Length; i++)
    {
        /* Data Write */
        RegA6_SPI->DRX.Reg = (UINT32)pBuf[i];
    }

    /* Check Transmit FIFO */
    (void)NC_SPI_WaitTxFIFOIsEmpty();

    /* Check Busy */
    (void)NC_SPI_WaitBusIsBusy();
}



/**
* @desc
    Writes data by 4 bytes.
* @param    UINT32* pBuf    Data buffer
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Write Data to SPI Register.
        Data Length --
    LOOP
*/
void NC_SPI_Write32(const UINT32 *pBuf, UINT32 Length)
{
    UINT32 i;

    NC_SPI_SetTMOD(SPI_TMOD_WRITE);

    RegA6_SPI->SER.Reg = DISABLE;

    for(i = 0U; i < Length; i++)
    {
        /* Data Write */
        RegA6_SPI->DRX.Reg = pBuf[i];
    }

    RegA6_SPI->SER.Reg = ENABLE;

    /* Check Transmit FIFO */
    (void)NC_SPI_WaitTxFIFOIsEmpty();

    /* Check Busy */
    (void)NC_SPI_WaitBusIsBusy();
}



/**
* @desc
    Write dummy data.
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Write Dummy data.
        Data Length --
    LOOP
*/
void NC_SPI_WriteDummy(UINT32 Length)
{
    UINT32 i;

    NC_SPI_SetTMOD(SPI_TMOD_READ);

    for(i = 0U; i < Length; i++)
    {
        /* Data Write */
        RegA6_SPI->DRX.Reg = 0x0U;
    }

    /* Check Transmit FIFO */
    (void)NC_SPI_WaitTxFIFOIsEmpty();

    /* Check Busy */
    (void)NC_SPI_WaitBusIsBusy();
}



/**
* @desc
    Enable chip select.
* @param    void
* @return   void
* @design
    Set the value in Register to enable Chip select.
*/
void NC_SPI_EnableCS(void)
{
    (void)NC_SPI_WaitBusIsBusy();
    RegA6_SPI->CSN_CONTROL.Bit.CSN_VAL = LOW;
}



/**
* @desc
    Disable chip select.
* @param    void
* @return   void
* @design
    Set the value in Register to disable Chip select.
*/
void NC_SPI_DisableCS(void)
{
    (void)NC_SPI_WaitBusIsBusy();
    RegA6_SPI->CSN_CONTROL.Bit.CSN_VAL = HIGH;
}



/**
* @desc
    Enable trasmit and receive of DMA.
* @param    void
* @return   void
* @design
    Enable the transmit DMA.
    Enable the receive DMA.
*/
void NC_SPI_EnableDMAReq(void)
{
    RegA6_SPI->DMACR.Bit.RDMAE = ENABLE;
    RegA6_SPI->DMACR.Bit.TDMAE = ENABLE;
}



/**
* @desc
    Disable trasmit and receive of DMA.
* @param    void
* @return   void
* @design
    Disable the transmit DMA.
    Disable the receive DMA.
*/
void NC_SPI_DisableDMAReq(void)
{
    RegA6_SPI->DMACR.Bit.TDMAE = DISABLE;
    RegA6_SPI->DMACR.Bit.RDMAE = DISABLE;
}



/**
* @desc
    Set the bitrate of spi.
* @param    UINT32* pBitRate    A pointer where the bitrate value is stored.
* @param    UINT32  RefClk      Reference clock value.
* @return   void
* @design
    Set the divider value.
    Store the bitrate value.
*/
void NC_SPI_SetBitRate(UINT32 *pBitRate, UINT32 RefClk)
{
    volatile UINT32 Div = 4U;
    volatile UINT32 Sampling;
    UINT32 tBitrate;
    
    Sampling = (RefClk / Div);

    while(1)
    {
        if((*pBitRate < Sampling))
        {
            Div += 2U;
            Sampling = (RefClk / Div);
        }
        else
        {
            tBitrate = RefClk / Div;
            if(((tBitrate % 1000U) == 0U) || (tBitrate < (100U * KHZ))) 
            {
                break;
            }
            else
            {
                Div += 2U;
            }
        }
    }

    /*
     * Fsclk_out    = Fssi_clk/SCKDV
     * Fssi_clk     = RefClk
     * SCKDV        = Div ( A6_RegA6_SPI->SPI_BAUDR.Reg)
     * Fsclk_out    = Bitrate
     * where SCKDV is any even value between 2 and 65534
     */

    RegA6_SPI->SSIENR.Reg = DISABLE;
    RegA6_SPI->BAUDR.Reg  = Div;
    RegA6_SPI->SSIENR.Reg = ENABLE;
    *pBitRate             = RefClk / Div;

#ifdef DEBUG_ENABLE_
    DEBUGMSG(MSGINFO, " > Try to Set BitRate Div Value (%d), BitRate:%d, RefClk:%d \n", Div, *pBitRate, RefClk);
#endif
}



/**
* @desc
    Set the frame size.
* @param    UINT32  Size    Frame size.
* @return   void
* @design
    Set the frame size value in Register.
*/
void NC_SPI_SetFrameSize(UINT32 Size)
{
    RegA6_SPI->SSIENR.Reg        = DISABLE;
    RegA6_SPI->CTRLR0.Bit.DFS_32 = Size;
    RegA6_SPI->SSIENR.Reg        = ENABLE;
}



/**
* @desc
    Set the TMOD.
* @param    UINT32  Mode    Transfer mode.
* @return   void
* @design
    Set the TMOD value in Register.
*/
void NC_SPI_SetTMOD(UINT32 Mode)
{
    RegA6_SPI->SSIENR.Reg      = DISABLE;
    RegA6_SPI->CTRLR0.Bit.TMOD = Mode;
    RegA6_SPI->SSIENR.Reg      = ENABLE;
}

/**
* @desc
    This setting controls the level at which a DMA request is made by the receive logic.
* @param    UINT32  Rx  Data level value.
* @return   void
* @design
    Set the data level
*/
void NC_SPI_SetDataLevel(UINT32 Rx)
{
    RegA6_SPI->DMARDLR.Reg = Rx - 1U;
}



/**
* @desc
    Set the transfer length.
* @param    UINT32  Size    Length value
* @return   void
* @design
    Set the transfer length in Register.
*/
void NC_SPI_SetTransferLength(UINT32 Size)
{
    RegA6_SPI->SSIENR.Reg = DISABLE;
    RegA6_SPI->CTRLR1.Reg = Size - 1U;
    RegA6_SPI->SSIENR.Reg = ENABLE;
}



#if 0
/**
* @desc
    Read the DFS value.(DFS : Data Frame Size in 32-bit transfer size mode)
* @param    void
* @return   UINT32  DFS value
* @design
    Read the DFS value from Register.
    Return DFS value
*/
UINT32 NC_SPI_GetDFS(void)
{
    return RegA6_SPI->CTRLR0.Bit.DFS_32;
}
#endif



/**
* @desc
    Initialize NC_QSPI.
* @param    UINT32  BitRate Bitrate value.
* @param    UINT32  RefClk  Reference clock value.
* @param    UINT32  DummyCycle  Dummy cycle value.
* @return   void
* @design
    To use NC_QSPI, set the value in Register.
*/
void NC_QSPI_Init(UINT32 BitRate, UINT32 RefClk, UINT32 DummyCycle)
{
    UINT32 QSPI_CLK_INV;
    UINT32 QSPI_DUMMY_CYCLE;
    UINT32 QSPI_RX_DELAY;
    UINT32 Reg;

    if(DummyCycle == 0U)
    {
        QSPI_DUMMY_CYCLE = 6U;
    }
    else
    {
        QSPI_DUMMY_CYCLE = (DummyCycle*2U);
    }

    /* SPI Disable */
    RegA6_SPI->SSIENR.Reg = DISABLE;

    /* Polarity & Phase config setting(from OTP or file header) */
    switch(gSPI_CLK_POL_PH)
    {
        case 0x1:   /* Polarity(0), Phase(1) */
            QSPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
            QSPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
            break;
        case 0x2:   /* Polarity(1), Phase(0) */
            QSPI_CLK_INV = ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPOL);
            QSPI_CLK_INV |= ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPH);
            break;
        case 0x3:   /* Polarity(1), Phase(1) */
            QSPI_CLK_INV = ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPOL);
            QSPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
            break;
        default:    /* case 0x0 : Polarity(0), Phase(0) */
            QSPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
            QSPI_CLK_INV |= ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPH);
            break;
    }

    /* CLK Inversion */
    if(gSPI_CLK_INV == TRUE)
    {
        QSPI_CLK_INV = ((UINT32)SPI_SPO_LOW << (UINT32)SPI_SCPOL);
        QSPI_CLK_INV |= ((UINT32)SPI_SPH_HIGH << (UINT32)SPI_SCPH);
    }

    /* Protocol Set - Motorora SPI, Width, Clk/Data Pol */
    Reg = ((UINT32)SPI_DS_8BIT << (UINT32)SPI_DFS32);
    Reg |= (QSPI_CLK_INV);
    Reg |= ((UINT32)SPI_TMOD_READ << (UINT32)SPI_TMOD8);
    Reg |= ((UINT32)SPI_SLV_OE_DIS << (UINT32)SPI_SLV_OE);
    /*Reg |= ((UINT32)SPI_SRL_NORMAL_MODE << (UINT32)SPI_SRL);*/
    Reg |= ((UINT32)SPI_CS_8BIT << (UINT32)SPI_CFS16);
    Reg |= ((UINT32)SPI_TRANS_MODE_QPI << (UINT32)SPI_FRAME_FORMAT);

    RegA6_SPI->CTRLR0.Reg = Reg;

    /* QSPI Trans Mode Set */
    /* 1-4-4 Mode */
    Reg = (SPI_TRANS_TYPE1);
    Reg |= ((UINT32)SPI_ADDRL_24BIT << (UINT32)SPI_ADDR_LEN);
    Reg |= ((UINT32)SPI_INST_8BIT << (UINT32)SPI_INST_LEN);
    Reg |= (QSPI_DUMMY_CYCLE << (UINT32)SPI_WAIT_CYCLE);

    RegA6_QSPI->SPI_CTRLR0.Reg = Reg;

    /* Slave Enable */
    RegA6_SPI->SER.Reg = ENABLE;

    /*
     * Fsclk_out(Bitrate) = Fssi_clk/SCKDV
     * -. Fssi_clk = InClk
     * -. SCKDV = Div ( A6_RegSPI[Ch]->BAUDR.Reg)
     */
    RegA6_SPI->BAUDR.Reg = (UINT32)(RefClk / BitRate);

    /* Receive FIFO Threshold Set */
    RegA6_SPI->TXFTLR.Reg = 0xFFU;
    RegA6_SPI->RXFTLR.Reg = 0xFFU;

    /* NDF */
    RegA6_SPI->CTRLR1.Reg = SF_PAGE_SIZE;

    /* Transmit Data Level */
    RegA6_SPI->DMATDLR.Reg = 0U;
    RegA6_SPI->DMARDLR.Reg = 0U;

    QSPI_RX_DELAY = gSPI_RX_DELAY;
    QSPI_RX_DELAY &= 0x000000FFU;
    if(QSPI_RX_DELAY > 0U)
    {
        RegA6_SPI->RX_SAMPLE_DLY.Bit.RSD = (UINT8)QSPI_RX_DELAY;
    }

    /* SPI Enable */
    RegA6_SPI->SSIENR.Reg = ENABLE;

    /* CSN CONTROL */
    RegA6_SPI->CSN_CONTROL.Bit.CSN_SEL = ENABLE;
}



/**
* @desc
    Read data in quad mode.
* @param    UINT32  pBuf    Data buffer.
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Read Data from SPI Register.
        Data Length --
    LOOP
*/
void NC_QSPI_Read(UINT32 pBuf, UINT32 Length)
{
    UINT32 i;
/*PRQA S 0306 ++*/
    UINT8 *pDes32 = (UINT8 *)pBuf;
/*PRQA S 0306 --*/

    for(i = 0U; i < Length; i += 1U)
    {
        /* Check Busy */
        (void)NC_SPI_WaitBusIsBusy();

        /* Read data */
        pDes32[i] = (UINT8)(RegA6_SPI->DRX.Reg & 0xFFU);
    }
}



/**
* @desc
    Write data with quad SPI.
* @param    UINT32* pBuf    Data buffer
* @param    UINT32  Length  Data size
* @return   void
* @design
    DO WHILE    Data Length is more than 0  THEN
        Write Data from SPI Register.
        Data Length --
    LOOP
*/
void NC_QSPI_Write(const UINT32 *pBuf, UINT32 Length)
{
    UINT32 i;

    for(i = 0U; i < Length; i++)
    {
        /* Data Write */
        RegA6_SPI->DRX.Reg = pBuf[i];
    }

    /* Check Transmit FIFO */
    (void)NC_SPI_WaitTxFIFOIsEmpty();

    /* Check Busy */
    (void)NC_SPI_WaitBusIsBusy();
}



/**
* @desc
    Set the bitrate of Quad spi.
* @param    UINT32  Div     Divider value.
* @param    UINT32  RefClk  Reference clock value.
* @return   UINT32  Rate value
* @design
    Set the bitrate of Quad spi.
    Return BitRate value.
*/
UINT32 NC_QSPI_SetBitRate(UINT32 Div, UINT32 RefClk)
{
    RegA6_SPI->SSIENR.Reg      = DISABLE;
    RegA6_SPI->BAUDR.Bit.SCKDV = Div;
    RegA6_SPI->SSIENR.Reg      = ENABLE;

    return RefClk / Div;
}

/* End Of File */
