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
*              INCLUDE
********************************************************************************
*/

#include "Apache.h"
#include "Svc_sFlash.h"
#include "Drv_SPI.h"
#include "Drv_SCU.h"
#include "Drv_DMA330.h"

/*
********************************************************************************
*              FUNCTION DEFINITIONS
********************************************************************************
*/


/**
* @desc
    Reads the serial flash status value.
* @param    void
* @return   UINT8   Status value.
* @design
    Reads the serial flash status value.
    Return Status
*/
static UINT8 NC_SF_ReadStatus(void)
{
    UINT8 Command = CMD_sFLASH_RD_STS;
    UINT8 Status  = 0U;

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_Read(&Status, 1U);
    NC_SPI_DisableCS();

    return Status;
}



/**
* @desc
    Reads the serial flash status value for WINBOND type.
* @param    void
* @return   UINT8   Status value.
* @design
    Reads the serial flash status value.
    Return Status
*/
static UINT8 NC_SF_ReadStatus2(void)
{
    UINT8 Command = CMD_sFLASH_RD_STS2;
    UINT8 Status  = 0U;

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_Read(&Status, 1U);
    NC_SPI_DisableCS();

    return Status;
}



/**
* @desc
    Enable the write function of serial flash.
* @param    void
* @return   void
* @design
    Set write Enable in Serial Flash Status.
    DO WHILE    Serial flash write is disabled.
        IF  Time Out has occurred.  THEN
            Exit Do
        ENDIF
    LOOP
*/
static void NC_SF_WriteEnable(void)
{
    UINT8 Command = CMD_sFLASH_WR_EN;
    UINT32 TimeOutFlag = 0U;

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_DisableCS();

    while(1)
    {
        if( ((NC_SF_ReadStatus() & STS_WEL) != STS_WEL) && (TimeOutFlag == 0U) )
        {
            if(NC_SCU_mTimeOut(SPI_WAIT_TIMEOUT) == TRUE)
            {
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
}



/**
* @desc
    Disable the write function of serial flash.
* @param    void
* @return   void
* @design
    DO WHILE    Serial flash is in write operation.
        IF  Time Out has occurred.  THEN
            Exit Do
        ENDIF
    LOOP

    Set write Disable in Serial Flash Status.
*/
static void NC_SF_WriteDisable(void)
{
    UINT8 Command = (UINT8)CMD_sFLASH_WR_DS;

    while(NC_SCU_mTimeOut(SPI_WAIT_TIMEOUT) == FALSE)
    {
        if( ((NC_SF_ReadStatus() & STS_WIP) == STS_WIP) )
        {
            /* DO NOTHING */
        }
        else
        {
            break;
        }
    }

    /* Clear */
    (void)NC_SCU_mTimeOut(0U);

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_DisableCS();
}


/**
* @desc
    Write Status value to Serial Flash for GIGA Device type.
* @param    UINT8   Status  Status value
* @return   void
* @design
    Write Status value to Serial Flash.
*/
static void NC_SF_WriteStatus3(UINT8 Status)
{
    /*
     * GIGA DEVICE
     */
    UINT8 Command[2] = {0, };

    Command[0] = CMD_sFLASH_WR_STS3;
    Command[1] = Status;

    NC_SF_WriteEnable();
    NC_SPI_EnableCS();
    NC_SPI_Write(Command, 2U);
    NC_SPI_DisableCS();
    NC_SF_WriteDisable();
}



/**
* @desc
    Write Status value to Serial Flash for EON type.
* @param    void
* @return   void
* @design
    Write Status value to Serial Flash.
*/
static void NC_SF_WriteStatus4(void)
{
    /*
     * EON : EQIO
     */
    UINT8 Command = CMD_sFLASH_WR_STS4;

    NC_SF_WriteEnable();
    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_DisableCS();
    NC_SF_WriteDisable();
}



/**
* @desc
    Reads the serial flash configuration value.
* @param    void
* @return   UINT8   Serial flash status
* @design
    Reads the serial flash configuration value.
    Return Configuration value
*/
static UINT8 NC_SF_ReadConfigStatus(void)
{
    UINT8 Command = CMD_sFLASH_RD_CONFIG;
    UINT8 Status  = 0U;

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_Read(&Status, 1U);
    NC_SPI_DisableCS();

    return Status;
}



/**
* @desc
    Set status values to serial flash.
* @param    UINT8   Status  Status value
* @return   void
* @design
    Set status values to serial flash.
*/
static void NC_SF_WriteStatus(UINT8 Status)
{
    UINT8 Command[2];
    Command[0] = CMD_sFLASH_WR_STS;
    Command[1] = Status;

    NC_SF_WriteEnable();
    NC_SPI_EnableCS();
    NC_SPI_Write(Command, 2U);
    NC_SPI_DisableCS();
    NC_SF_WriteDisable();
}



/**
* @desc
    Set two status values to serial flash.
* @param    UINT8   Status1     Status1 value
* @param    UINT8   Status2     status2 value
* @return   void
* @design
    Set two status values to serial flash.
*/
static void NC_SF_WriteStatus2(UINT8 Status1, UINT8 Status2)
{
    UINT8 Command[3];
    Command[0] = CMD_sFLASH_WR_STS;
    Command[1] = Status1;
    Command[2] = Status2;

    NC_SF_WriteEnable();
    NC_SPI_EnableCS();
    NC_SPI_Write(Command, 3U);
    NC_SPI_DisableCS();
    NC_SF_WriteDisable();
}



/**
* @desc
    Writes configuration value to serial flash.
* @param    UINT8   Status  Configuration value
* @return   void
* @design
    Writes configuration value to serial flash.
*/
static void NC_SF_WriteConfigStatus(UINT8 Status)
{
    UINT8 Command[2];
    Command[0] = CMD_sFLASH_WD_CONFIG;
    Command[1] = Status;

    NC_SF_WriteEnable();
    NC_SPI_EnableCS();
    NC_SPI_Write((const UINT8*)&Command[0], 2U);
    NC_SPI_DisableCS();
    NC_SF_WriteDisable();
}



/**
* @desc
    Reads serial flash Device ID.
* @param    UINT8*  pBuff   Data Buffer
* @return   void
* @design
    Read Device ID of Serial Flash and save it in argument buffer.
*/
void NC_SF_ReadID(UINT8 *pBuff)
{
    UINT8 Command = CMD_sFLASH_RD_IDENTIFICATION;

    NC_SPI_EnableCS();
    NC_SPI_Write(&Command, 1U);
    NC_SPI_Read(pBuff, 3U);

    NC_SPI_DisableCS();
}



/**
* @desc
    This function enables the quad mode of Serial Flash.
* @param    UINT8*  pRDID   Serial Flash Device ID
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    Read Device ID of Serial Flash.
    IF  A matching Device ID exists.    THEN
        Enable quad mode.
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SF_EnableQuadMode(UINT8 *pRDID)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT8 Status1;
    UINT8 Status2;

    /* ID Read */
    NC_SF_ReadID(pRDID);

    /* Check Support ID */
    if((pRDID[0] == FLASH_ID_WINBOND) || (pRDID[0] == FLASH_ID_CYPRESS) || (pRDID[0] == FLASH_ID_AMIC))
    {
        Status1 = NC_SF_ReadStatus();
        Status2 = NC_SF_ReadStatus2();

        if((Status2 & (1U << 1)) == 0U)
        {
            /* Status Register2 : Quad Enable [bit1] */
            NC_SF_WriteStatus2(Status1, Status2 | (1U << 1));
        }
    }
    else if((pRDID[0] == FLASH_ID_MXIC) || (pRDID[0] == FLASH_ID_ISSI))
    {
        Status1 = NC_SF_ReadStatus();
        if((Status1 & (1U << 6)) == 0U)
        {
            /* Status Register : Quad Enable [bit6] */
            NC_SF_WriteStatus(Status1 | (1U << 6));
        }
    }
    else if(pRDID[0] == FLASH_ID_GIGA)
    {
        Status1 = NC_SF_ReadStatus2();
        if((Status1 & (1U << 1)) == 0U)
        {
            NC_SF_WriteStatus3(Status1 | (1U << 1));
        }
    }
    else if(pRDID[0] == FLASH_ID_EON)
    {
        /*
         *-----------------------------------------------
         *  8-Clock Instruction : Apache6 Support (?)
         *   -. Enable Bit and Command (X)
         *  2-Clock Instruction : Apache6 Not Support
         *  4-4-4 Command Set
         *   -. EQIO(0x38) - Quad IO Enable Command
         *-----------------------------------------------
         **/
        NC_SF_WriteStatus4();
    }
    else if(pRDID[0] == FLASH_ID_MICRON)
    {
        /*
         *-----------------------------------------------
         * FLASH_ID_MICRON
         *  1-4-4 Command Set
         *  10 Dummy Cycle Set
         *-----------------------------------------------
         **/

        Status1 = NC_SF_ReadConfigStatus();
        /*DEBUGMSG(MSGINFO, "    -. Status1 : 0x%x \n", Status1);*/
        if(((Status1 >> (UINT8)4U)) != (UINT8)SF_DUMMY_CLOCK_CYCLES)
        {
            /* Status Register : Quad Enable [bit6] */
            Status1 = ((SF_DUMMY_CLOCK_CYCLES & 0xFU) << 4U) + (Status1 & 0xFU);
            NC_SF_WriteConfigStatus(Status1);
        }
    }
    else
    {
        /*
         *-----------------------------------------------
         * FAASH_ID_SST
         *  -. The method is different.
         *  -. 8Clck Inst->24Clk Addr : Apache6 Not Support
         * FLASH_ID_ATML
         *  -. No supported devices found.
         *-----------------------------------------------
         **/

        Ret = NC_FAILURE;
    }

    return Ret;
}



/**
* @desc
    Enable quad mode according to Serial Flash model type.
* @param    UINT32  Config  Serial Flash model type
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF Serial Flash model types are 1~5.   THEN
        Set Status according to Type.
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
static NC_ERROR NC_SF_EnableQuadMode_Type(UINT32 Config)
{
    NC_ERROR Ret = NC_SUCCESS;
    UINT8 Status1;
    UINT8 Status2;

    if(Config == SF_CON_QE_TYPE1)
    {
        Status1 = NC_SF_ReadStatus();
        Status2 = NC_SF_ReadStatus2();

        if( (Status2 & (1U<<1)) == 0U )
        {
            (void)NC_SF_WriteStatus2(Status1, Status2|(1U<<1));
        }
    }
    else if(Config == SF_CON_QE_TYPE2)
    {
        Status1 = NC_SF_ReadStatus();
        if( (Status1 & (1U<<6)) == 0U )
        {
            (void)NC_SF_WriteStatus(Status1|(1U<<6));
        }
    }
    else if(Config == SF_CON_QE_TYPE3)
    {
        Status1 = NC_SF_ReadStatus2();
        if( (Status1 & (1U<<1)) == 0U )
        {
            (void)NC_SF_WriteStatus3(Status1|(1U<<1));
        }
    }
    else if(Config == SF_CON_QE_TYPE4)
    {
        /*
        *-----------------------------------------------
        *  8-Clock Instruction : Apache4 Support (?)
        *   -. Enable Bit and Command (X)
        *  2-Clock Instruction : Apache4 Not Support
        *   -. EQIO(0x38) - Quad IO Enable Command
        *-----------------------------------------------
        **/

        NC_SF_WriteStatus4();
    }
    else if(Config == SF_CON_QE_TYPE5)
    {
        /*
        *-----------------------------------------------
        * FLASH_ID_MICRON
        *  1-4-4 Command Set - ???
        *  10 Dummy Cycle Set - Valid
        *-----------------------------------------------
        **/

        Status1 = NC_SF_ReadConfigStatus();
        if((Status1 >> 4U) != SF_DUMMY_CLOCK_CYCLES)
        {
            /* Status Register : Quad Enable [bit6] */
            Status1 = (UINT8)((SF_DUMMY_CLOCK_CYCLES & 0xFU) << 4) + (Status1 & 0xFU);
            NC_SF_WriteConfigStatus(Status1);
        }
    }
    else
    {
        /*
        *-----------------------------------------------
        * FLASH_ID_SST
        *  -. The method is different.
        *  -. 8Clock Inst->24Clk Addr : Apache4 Not Support
        * FLASH_ID_ATML
        *  -. No supported devices found.
        *-----------------------------------------------
        **/

        Ret = NC_FAILURE;
    }

    return Ret;
}



/**
* @desc
    Depending on the type, enable Quad mode of Serial Flash.
* @param    UINT8*  pRDID   Serial Flash Device ID
* @param    UINT32  Config  Serial Flash model type
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    IF  Find the device by ID of Serial Flash.  THEN
        Ret = Find the device by ID of Serial Flash and enable Quad mode.
    ELSE
        Ret = Find the device by the Serial False Type and enable Qaud mode.
    ENDIF
    Return Ret
*/
NC_ERROR NC_SF_EnableDeviceQuadMode(UINT8 *pRDID, UINT32 Config)
{
    NC_ERROR Ret;

    if (Config == SF_CON_NO)
    {
        /*
         * Find sFlash Model Type
         */
        Ret = NC_SF_EnableQuadMode(pRDID);
    }
    else
    {
        /*
         * Not Fixed sFlash Model Type
         */
        Ret = NC_SF_EnableQuadMode_Type(Config);
    }

    return Ret;
}



/**
* @desc
    This function reads data from serial flash in DMA single mode.
* @param    UINT32  Addr    Address to read
* @param    UINT8*  pData   Data buffer
* @param    UINT32  Size    Size to read
* @return   void
* @design
    DO WHILE    Size is more than 0
        IF  The size of the remaining size is larger than 64Kbyte.  THEN
            The size to read is 64Kbyte.
        ELSE
            The size to read is the remaining bytes.
        ENDIF
        Read data by size in DMA SPI single mode.
        Subtract the read size value from the remaining size value.
    LOOP
*/
void NC_SF_DMA_SPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size)
{
    UINT32 Command[2];
    UINT8 *pInBuff = pData;
    UINT32 InAddr  = Addr;
    UINT32 InSize  = Size;
    UINT32 ReadSize;

    while(1)
    {
        if(InSize > 0U)
        {
            ReadSize = (InSize >= SF_MAX_NDF_64K) ? SF_MAX_NDF_64K : InSize;

            NC_SPI_SetTransferLength(ReadSize / 4U);

            NC_SPI_SetTMOD(SPI_TMOD_READ);

            NC_SPI_EnableCS();

            NC_SPI_SetFrameSize(0x1FU);

            NC_DMA_SPI_Gen_Instruction(pInBuff, InAddr, ReadSize);

            NC_DMA_Start();

            NC_SPI_SetDataLevel(4U);

            NC_SPI_EnableDMAReq();

            /* Send Read Command */
            Command[0] = (UINT32)CMD_sFLASH_RD_DATA << 24U;
            Command[0] += (InAddr & 0xFFFFFFU);
            NC_SPI_Write32(Command, 1U);

            nc_udelay(1ULL);

            /* make clock */
            NC_SPI_WriteDummy(1U);

            /* wait DMA done */
            NC_DMA_Wait_Complete();

            NC_SPI_DisableCS();

            NC_DMA_Deinit();

            NC_SPI_DisableDMAReq();

            pInBuff = (UINT8 *)((UINT32)pInBuff + ReadSize);
            InAddr += ReadSize;
            InSize -= ReadSize;
        }
        else
        {
            break;
        }
    }

    ASM_DCACHE_FLUSH((UINT32)pData, Size);
}



/**
* @desc
    This function reads data from serial flash in DMA quad mode.
* @param    UINT32  Addr    Address to read
* @param    UINT8*  pData   Data buffer
* @param    UINT32  Size    Size to read
* @return   void
* @design
    DO WHILE    Size is more than 0
        IF  The size of the remaining size is larger than 64Kbyte.  THEN
            The size to read is 64Kbyte.
        ELSE
            The size to read is the remaining bytes.
        ENDIF
        Read data by size in DMA QSPI mode.
        Subtract the read size value from the remaining size value.
    LOOP
*/
void NC_SF_DMA_QSPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size)
{
    UINT32 Command[2];
    UINT8 *pInBuff = pData;
    UINT32 InAddr  = Addr;
    UINT32 InSize  = Size;
    UINT32 ReadSize;

    while(1)
    {
        if(InSize > 0U)
        {
            ReadSize = (InSize >= SF_MAX_NDF_64K) ? SF_MAX_NDF_64K : InSize;

            NC_SPI_SetTransferLength(ReadSize / 4U);

            NC_SPI_SetTMOD(SPI_TMOD_READ);

            NC_SPI_EnableCS();

            NC_SPI_SetFrameSize(0x1FU);

            NC_DMA_QSPI_Gen_Instruction(pInBuff, InAddr, ReadSize);

            NC_DMA_Start();


            NC_SPI_SetDataLevel(16U);

            NC_SPI_EnableDMAReq();

            /* Send Read Command */
            Command[0] = CMD_SFLASH_QUAD_RD_QUAD_INST;
            Command[1] = InAddr;
            NC_QSPI_Write((UINT32*)&Command[0], 2U);

            /* wait DMA done */
            NC_DMA_Wait_Complete();

            NC_SPI_DisableCS();

            NC_DMA_Deinit();

            NC_SPI_DisableDMAReq();

            ASM_DCACHE_FLUSH((UINT32)pInBuff, ReadSize);

            /* pInBuff += ReadSize, [MISRA 2012 Rule 18.4, advisory] */
            pInBuff = (UINT8 *)((UINT32)pInBuff + ReadSize);
            InAddr += ReadSize;
            InSize -= ReadSize;
        }
        else
        {
            break;
        }
    }
}



/**
* @desc
    This function reads data from serial flash in single mode.
* @param    UINT32  Addr    Address to read
* @param    UINT8*  pData   Data buffer
* @param    UINT32  Size    Size to read
* @return   void
* @design
    DO WHILE    Size is more than 0
        IF  The size of the remaining size is larger than 256byte.  THEN
            The size to read is 256yte.
        ELSE
            The size to read is the remaining bytes.
        ENDIF
        Read data by size in SPI single mode.
        Subtract the read size value from the remaining size value.
    LOOP
*/
void NC_SF_SPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size)
{
    UINT8 Command[4];
    UINT8 *pInBuff = pData;
    UINT32 InAddr  = Addr;
    UINT32 InSize  = Size;
    UINT32 ReadSize;

    while(1)
    {
        if(InSize > 0U)
        {
            ReadSize = (InSize >= SF_PAGE_SIZE) ? SF_PAGE_SIZE : InSize;

            NC_SPI_SetTMOD(SPI_TMOD_READ);

            NC_SPI_EnableCS();

            Command[0] = (UINT8)CMD_sFLASH_RD_DATA;
            Command[1] = (UINT8)(InAddr >> 16U);
            Command[2] = (UINT8)(InAddr >> 8U);
            Command[3] = (UINT8)(InAddr & 0xFFU);

            NC_SPI_Write(Command, 4U);

            NC_SPI_Read(pInBuff, ReadSize);

            NC_SPI_DisableCS();

            /* pInBuff += ReadSize, [MISRA 2012 Rule 18.4, advisory] */
            pInBuff = (UINT8 *)((UINT32)pInBuff + ReadSize);
            InAddr += ReadSize;
            InSize -= ReadSize;
        }
        else
        {
            break;
        }
    }
}



/**
* @desc
    This function reads data from serial flash in quad mode.
* @param    UINT32  Addr    Address to read
* @param    UINT32  pData   Address of data buffer
* @param    UINT32  Size    Size to read
* @return   void
* @design
    DO WHILE    Size is more than 0
        IF  The size of the remaining size is larger than 1024byte.  THEN
            The size to read is 1024yte.
        ELSE
            The size to read is the remaining bytes.
        ENDIF
        Read data by size in QSPI mode.
        Subtract the read size value from the remaining size value.
    LOOP
*/
void NC_SF_QSPI_ReadData(UINT32 Addr, UINT32 pData, UINT32 Size)
{
    UINT32 pInBuff = pData;
    UINT32 InAddr  = Addr;
    UINT32 InSize  = Size;
    UINT32 ReadSize;

    UINT32 Command[2];
/*PRQA S 0303,0306 ++*/
    UINT32 pCMD = (UINT32)&(Command[0]);
/*PRQA S 0303,0306 --*/

    while(1)
    {
        if(InSize <= 0U)
        {
            break;
        }

        if(InSize >= SF_PAGE_SIZE)
        {
            ReadSize = SF_PAGE_SIZE;
        }
        else
        {
            ReadSize = InSize;
        }

        NC_SPI_SetTMOD(SPI_TMOD_READ);

        NC_SPI_EnableCS();

        Command[0] = CMD_SFLASH_QUAD_RD_QUAD_INST;
        Command[1] = InAddr;

        NC_QSPI_Write((UINT32*)pCMD, 2U);

        NC_QSPI_Read(pInBuff, ReadSize);

        NC_SPI_DisableCS();

        pInBuff += ReadSize;
        InAddr += ReadSize;
        InSize -= ReadSize;
    }
}



/**
* @desc
    This function reads data from serial flash.
* @param    UINT32  CtrlMode    SF Control mode
* @param    UINT32  Addr        Address to read
* @param    UINT8*  pData       Data buffer
* @param    UINT32  Size        Size to read
* @return   void
* @design
    IF  Control Type is DMA QSPI    THEN
        Read data in DMA QSPI mode.
    ELSE IF Control Type is DMA SPI THEN
        Read data in DMA SPI mode.
    ELSE IF Control Type is QSPI    THEN
        Read data in QSPI mode.
    ELSE
        Read data in SPI mode.
    ENDIF
*/
void NC_SF_ReadData(UINT32 CtrlMode, UINT32 Addr, UINT8 *pData, UINT32 Size)
{
    UINT8 *pInBuff = pData;
    UINT32 InAddr  = Addr;
    UINT32 InSize  = Size;

    if(CtrlMode == (UINT32)E_SF_DMA_QSPI_MODE)
    {
        /* Quad-SPI 64Byte Align */
        InSize = ALIGN(InSize, 0x40U);
        NC_SF_DMA_QSPI_ReadData(InAddr, pInBuff, InSize);
    }
    else if(CtrlMode == (UINT32)E_SF_DMA_SPI_MODE)
    {
        InSize = ALIGN(InSize, 0x04U);
        NC_SF_DMA_SPI_ReadData(InAddr, pInBuff, InSize);
    }
    else if(CtrlMode == (UINT32)E_SF_QSPI_MODE)
    {
        NC_SF_QSPI_ReadData(InAddr, (UINT32)pInBuff, InSize);
    }
    else
    {
        NC_SF_SPI_ReadData(InAddr, pInBuff, InSize);
    }
}



/**
* @desc
    This function disables the use of SF.
* @param    void
* @return   void
* @design
    Disable SF usage.
*/
void NC_SF_DeInit(void)
{
    /* DeInit SSP */
    NC_SPI_DeInit();
}



/**
* @desc
    This function initializes to use SF.
* @param    UINT32 BitRate   SF Bitrate value
* @param    UINT32 RefClk    Reference clock value
* @return   void
* @design
    Enable SF usage.
*/
void NC_SF_Init(UINT32 BitRate, UINT32 RefClk)
{
    /* Init SPI */
    NC_SPI_Init(BitRate, RefClk);
}

/* End Of File */
