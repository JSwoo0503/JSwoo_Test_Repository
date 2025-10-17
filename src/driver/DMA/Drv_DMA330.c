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

#include "Apache.h"
#include "main.h"
#include "Drv_DMA330.h"
#include "Drv_SPI.h"
#include "Drv_SCU.h"
#include "Drv_Uart.h"
/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define DMA_PTOM_INSTRUCTION            (1U)
#define BOOT_DMA_INST                   (0x10AFD00U)

/* PRQA S 0303,0306,3218,3678++ */
volatile DRV_DMA330_REGISTER* const RegA6_DMA330 = (DRV_DMA330_REGISTER*)APACHE_DMA330_BASE_ADDR2;
/* PRQA S 0303,0306,3218,3678-- */



/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/

/**
* @desc
    Set DMA IP kill.
* @param    UINT32  Ch      DMA channel
* @return   void
* @design
    Set a value in Register to kill DMA.
*/
void NC_DMA_Kill(UINT32 Ch)
{
    /*-----------------------------------------------*/
    RegA6_DMA330->DBGINST0.Bit.CHANNEL_NUMBER       = Ch;
    RegA6_DMA330->DBGINST0.Bit.DEBUG_THREAD         = 1;
    RegA6_DMA330->DBGINST0.Bit.INSTRUCTION_BYTE_0   = CMD_DMAKILL;
    RegA6_DMA330->DBGCMD.Reg                        = 0;
}



/**
* @desc
    DMA Instruction setting.
* @param    INSTRUCTION_PARAM  Inst     DMA Instruction parameter
* @return   void
* @struct
    typedef struct
     {
        UINT8 Mode;             M to M or M to D or D to M
        UINT32 InstAddr;        Instruction address
        UINT8 SrcBurstSize;     Source burst size
        UINT8 SrcBurstLength;   Source burst length
        UINT8 DstBurstSize;     Destination burst size
        UINT8 DstBurstLength;   Destination burst length
        UINT8 EndianSwapSize;   Endian swap size
        UINT32 SrcAddress;      Source address
        UINT32 DstAddress;      Destination address
        UINT8 PeriNumber;       Peri number
        UINT32 TotalLength;     Total length
    } INSTRUCTION_PARAM;
* @design
    It is initialized according to the Instruction mode.

    DO WHILE    Burst size is more than 0
        Save WFP, LD, STP, FLUSH according to Instruction mode.
    LOOP
    Write data to register.
*/
void NC_DMA_Gen_microCode(INSTRUCTION_PARAM Inst)
{
    UINT8  buf[100] = {0U,};
    UINT32 mergedCode[100] = {0U,};
    tCCR   ccr = { 0 };
    UINT8  g_oft = 0, tmp;
    UINT32 i;
    UINT32 loopCnt0, loopCnt1, cyc;
    UINT32 bursts, cnt, bursts_remander;
    UINT32 totalleng = Inst.TotalLength;
    UINT32 srcsize = Inst.SrcBurstSize;
    UINT32 srcleng = Inst.SrcBurstLength;
    UINT32 dstsize = Inst.DstBurstSize;
    UINT32 dstleng = Inst.DstBurstLength;
    UINT8  loopCnt_tem;
    /*-----------------------------------------------*/
    /*  CCR */
    if(Inst.Mode == (UINT8)RT_DEV_TO_MEM)   /*  p to m */
    {
        ccr.Bit.srcInc = 0U;
        ccr.Bit.dstInc = 1U;
    }
    else                        /*  m to p */
    {
        ccr.Bit.srcInc = 1U;
        ccr.Bit.dstInc = 0U;
    }

    ccr.Bit.srcBurstSize = srcsize;
    ccr.Bit.srcBurstLen = (srcleng - 1U);
    ccr.Bit.srcProtCtrl = 1U;
    ccr.Bit.srcCacheCtrl = 0U;

    ccr.Bit.dstBurstSize = dstsize;
    ccr.Bit.dstBurstLen = (dstleng - 1U);
    ccr.Bit.dstProtCtrl = 1U;
    ccr.Bit.dstCacheCtrl = 0U;
    ccr.Bit.endianSwapSize = Inst.EndianSwapSize;
    ccr.Bit.Reserved = 0U;

    buf[g_oft] = (UINT8)CMD_DMAMOV;                                 g_oft++;
    buf[g_oft] = (UINT8)ERD_CCR;                                    g_oft++;
    buf[g_oft] = (UINT8)(ccr.Reg          & 0xFFU);                 g_oft++;
    buf[g_oft] = (UINT8)((ccr.Reg >> 8U)  & 0xFFU);                 g_oft++;
    buf[g_oft] = (UINT8)((ccr.Reg >> 16U) & 0xFFU);                 g_oft++;
    buf[g_oft] = (UINT8)((ccr.Reg & 0xFF000000U) >> 24U);           g_oft++;
    /*-----------------------------------------------*/
    /*  Source Address */
    buf[g_oft] = (UINT8)CMD_DMAMOV;                                 g_oft++;
    buf[g_oft] = (UINT8)ERD_SAR;                                    g_oft++;
    buf[g_oft] = (UINT8)(Inst.SrcAddress          & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.SrcAddress >> 8U)  & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.SrcAddress >> 16U) & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.SrcAddress & 0xFF000000U) >> 24U);   g_oft++;
    /*-----------------------------------------------*/
    /*  Destination Address */
    buf[g_oft] = (UINT8)CMD_DMAMOV;                                 g_oft++;
    buf[g_oft] = (UINT8)ERD_DAR;                                    g_oft++;
    buf[g_oft] = (UINT8)(Inst.DstAddress          & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.DstAddress >> 8U)  & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.DstAddress >> 16U) & 0xFFU);         g_oft++;
    buf[g_oft] = (UINT8)((Inst.DstAddress & 0xFF000000U) >> 24U);   g_oft++;
    /*-----------------------------------------------*/
    /*  flush */
    buf[g_oft] = (UINT8)CMD_DMAFLUSHP;                              g_oft++;
    buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U);          g_oft++;
    /*-----------------------------------------------*/
    /*  burst calculate   */
    bursts = totalleng / ((UINT32)1U << srcsize) / srcleng;

    if(totalleng < 0x10000U)
    {
        bursts_remander = totalleng % (((UINT32)1U << srcsize) * srcleng);

        if(bursts_remander > 0U)
        {
            bursts += 1U;
        }
    }

    while(1)
    {
        if(bursts > 0U)
        {
            cnt = bursts;

            if(cnt >= (256U * 256U))
            {
                loopCnt1 = 256U;
                loopCnt0 = 256U;
                cyc = cnt / loopCnt1 / loopCnt0;
            }
            else if(cnt > 256U)
            {
                loopCnt1 = 256U;
                loopCnt0 = cnt / loopCnt1;
                cyc = 1U;
            }
            else
            {
                loopCnt1 = cnt;
                loopCnt0 = 0U;
                cyc = 1U;
            }

            /* loop */
            if(loopCnt0 > 0U)
            {
                buf[g_oft] = (UINT8)CMD_DMALP;                              g_oft++;
                loopCnt_tem = (UINT8)(loopCnt0 - 1U);
                buf[g_oft] = (loopCnt_tem);  g_oft++;
            }
            buf[g_oft] = (UINT8)CMD_DMALP | (UINT8)0x02U;                   g_oft++;
            loopCnt_tem = (UINT8)(loopCnt1 - 1U);
            buf[g_oft] = ( loopCnt_tem);      g_oft++;

            /* Burst */
            while(cyc > 0U)
            {
                if(Inst.Mode == (UINT8)RT_MEM_TO_DEV)    /* m to p */
                {
                    if(srcleng <= (UINT32)BL_1XFER)      /* single mode */
                    {
                        /* WFP */
                        buf[g_oft] = (UINT8)CMD_DMAWFP;                          g_oft++;
                        buf[g_oft] = (UINT8)(((Inst.PeriNumber & 0x1FU) << 3U)); g_oft++;
                        /* LD */
                        buf[g_oft] = (UINT8)CMD_DMALD;                           g_oft++;
                        /* STP */
                        buf[g_oft] = (UINT8)CMD_DMASTP;                          g_oft++;
                        buf[g_oft] = (UINT8)(((Inst.PeriNumber & 0x1FU) << 3U)); g_oft++;
                    }
                    else                                 /* burst mode */
                    {
                        /* WFP */
                        buf[g_oft] = (UINT8)CMD_DMAWFP | (UINT8)0x02U;         g_oft++;
                        buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U);   g_oft++;
                        /* LD */
                        buf[g_oft] = (UINT8)CMD_DMALD;                           g_oft++;
                        /* STP */
                        buf[g_oft] = (UINT8)CMD_DMASTP | (UINT8)0x02U;         g_oft++;
                        buf[g_oft] = (UINT8)(((Inst.PeriNumber & 0x1FU) << 3U)); g_oft++;
                    }
                    /* FLUSH */
                    buf[g_oft] = (UINT8)CMD_DMAFLUSHP;                           g_oft++;
                    buf[g_oft] = (UINT8)(((Inst.PeriNumber & 0x1FU) << 3U));     g_oft++;
                }
                else                                    /* p to m */
                {
                    if(srcleng <= (UINT32)BL_1XFER)     /* single mode */
                    {
                        /* WFP */
                        buf[g_oft] = (UINT8)CMD_DMAWFP; g_oft++;
                        buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U); g_oft++;
                        /* LDP */
                        buf[g_oft] = (UINT8)CMD_DMALDP; g_oft++;
                        buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U); g_oft++;
                        /* ST */
                        buf[g_oft] = CMD_DMAST; g_oft++;
                    }
                    else                                /* burst mode */
                    {
                        /* WFP */
                        buf[g_oft] = (UINT8)CMD_DMAWFP | (UINT8)0x02; g_oft++;
                        buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U); g_oft++;
                        /* LDP */
                        buf[g_oft] = (UINT8)CMD_DMALDP | (UINT8)0x02; g_oft++;
                        buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U); g_oft++;
                        /* ST */
                        buf[g_oft] = (UINT8)CMD_DMAST; g_oft++;
                    }

                    /* FLUSH */
                    buf[g_oft] = (UINT8)CMD_DMAFLUSHP; g_oft++;
                    buf[g_oft] = (UINT8)((Inst.PeriNumber & 0x1FU) << 3U); g_oft++;
                }
                cyc--;
            }

            /*-----------------------------------------------*/

            /* LPEND */
            if(srcleng <= (UINT32)BL_1XFER)             /* single mode */
            {
                buf[g_oft] = (UINT8)CMD_DMALPEND | (UINT8)0x14U; g_oft++;
                buf[g_oft] = (UINT8)7U;    g_oft++;     /*arg->backJump; */
            }
            else                                        /* burst mode */
            {
                buf[g_oft] = (UINT8)CMD_DMALPEND | (UINT8)0x17U; g_oft++;
                buf[g_oft] = (UINT8)7U; g_oft++;/* arg->backJump; */
            }

            if(loopCnt0 > 0U)
            {
                if(srcleng <= (UINT32)BL_1XFER)         /* single mode */
                {
                    buf[g_oft] = (UINT8)CMD_DMALPEND | (UINT8)0x10U; g_oft++;
                    buf[g_oft] = (UINT8)0x0BU; g_oft++;/* arg->backJump; */
                }
                else                                    /* burst mode */
                {
                    buf[g_oft] = (UINT8)CMD_DMALPEND | (UINT8)0x13U; g_oft++;
                    buf[g_oft] = (UINT8)0x0BU; g_oft++;/* arg->backJump; */
                }
            }


            cnt = loopCnt1;
            if(loopCnt0 > 0U)
            {
                cnt *= loopCnt0;
            }

            bursts -= cnt;
        }
        else
        {
            break;
        }
    }
    /*-----------------------------------------------*/
    /* END*/
    buf[g_oft] = (UINT8)CMD_DMAEND; g_oft++;
    /*-----------------------------------------------*/

    for (i = 0U; i < g_oft; i++)
    {
        tmp = buf[i];
        mergedCode[(UINT32)(i/4U)] |= (((UINT32)tmp) << (8U * (i % 4U)));
    }

    if( (g_oft % 4U) != 0U)
    {
        g_oft += 4U - (g_oft % 4U);
        g_oft /= 4U;
    }

    /*  register write  */
    for (i = 0U; i < g_oft; i++)
    {
        REGRW32(Inst.InstAddr, i*4U) = mergedCode[i];
    }
}



/**
* @desc
    Run DMA operation.
* @param    UINT32   Ch     DMA channel
* @return   void
* @design
    IF DMA channel is 1 THEN
        To run DMA, set the value in Register.
    ENDIF
*/
void NC_DMA_Run(UINT32 Ch)
{
    UINT32 microCodeBase_rx = (UINT32)BOOT_DMA_INST;

    /*  microCodeBase */
    if(Ch == 1U)     /* rx */
    {
        RegA6_DMA330->DBGINST0.Reg = 0x1A00000;  /* Hard coding */
        RegA6_DMA330->DBGINST1.Reg = microCodeBase_rx;

        /* Get going */
        RegA6_DMA330->DBGCMD.Reg = 0;
    }
}



/**
* @desc
    Wait DMA operation for complete.
* @param    UINT32  Ch  DMA channel
* @return   void
* @design
    DO WHILE    Channel Status value is not 0x0 and 0xF.
        Read Channel Status Register.
        IF  A timeout has occurred. THEN
            Exit Do
        ENDIF
    LOOP
*/
void NC_DMA_Wait_Ch_Complete(UINT32 Ch)
{
    UINT32 csr;    /* Channel Status Register */
    UINT32 ftr;    /* Channel Fault  Register */
    UINT32 TimeOut = SPI_DMA_WAIT_TIMEOUT;
    UINT32 TimeOutFlag = 0U;
    /*-----------------------------------------------*/
    /* Wait DMAC Operation Stop */
    while(1)
    {
        csr = RegA6_DMA330->DMA330_THR_ST[Ch].CSR.Bit.CHANNEL_STATUS;

        if( (!((csr == 0x0U) || (csr == 0xFU))) && (TimeOutFlag == 0U))
        {
            if(NC_SCU_mTimeOut(TimeOut) == TRUE)
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

    if(csr == 0xFU)
    {
/* PRQA S 2983 ++ */ /* This code operate to debugging. HelixQAC doesn't work normal operation */
        ftr = RegA6_DMA330->DMA330_FTR[Ch].FTR.Reg;
        DEBUGMSG(MSGINFO, " > ftr(0x08x) \n", ftr);
/* PRQA S 2983 -- */
    }
}



/**
* @desc
    Start DMA operation.
* @param    void
* @return   void
* @design
    DO WHILE    DMA is not idle.
    LOOP
    Run DMA
*/
void NC_DMA_Start(void)
{
    UINT32 TimeOut = (SPI_DMA_WAIT_TIMEOUT*6U);
    UINT32 TimeOutFlag = 0U;

    while(1)
    {
        if((RegA6_DMA330->DBGSTATUS.Bit.DBGSTATUS != 0U) && (TimeOutFlag == 0U))
        {
            if(NC_SCU_mTimeOut(TimeOut) == TRUE)
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

    /*-----------------------------------------------*/
    NC_DMA_Run(DMA_PTOM_INSTRUCTION);
}



/**
* @desc
    Wait DMA operation for complete.
* @param    void
* @return   void
* @design
    Wait DMA operation for complete.
*/
void NC_DMA_Wait_Complete(void)
{
    /*-----------------------------------------------*/
    NC_DMA_Wait_Ch_Complete(DMA_PTOM_INSTRUCTION);
}



/**
* @desc
    Deinitialize DMA.
* @param    void
* @return   void
* @design
    Deinitialize DMA.
*/
void NC_DMA_Deinit(void)
{
    /*-----------------------------------------------*/
    NC_DMA_Kill(DMA_PTOM_INSTRUCTION);
}



/**
* @desc
    Generate DMA instrcution on SPI.
* @param    UINT8*   pData          Destination Address
* @param    UINT32   PageAddr       Page address
* @param    UINT32   Length         Data length
* @return   void
* @design
    Set and apply DMA instruction for SPI.
*/
/* for QAC Rule-8.13 */
void NC_DMA_SPI_Gen_Instruction(const UINT8 *pData, UINT32 PageAddr, UINT32 Length)
{
    INSTRUCTION_PARAM Inst;

    /* for NULL CHECK */
    if((pData != (UINT8*)NULL) && (PageAddr != 0U))
    { 
        /*-----------------------------------------------*/
        /* rx insruction */
        Inst.Mode            = (UINT8)RT_DEV_TO_MEM;                         /*  DMA Mode                    */
        Inst.InstAddr        = (UINT32)BOOT_DMA_INST;                                /*  Instruction Address         */
        Inst.SrcBurstSize    = (UINT8)BS_4B;                                 /*  Source Bursts size          */
        Inst.SrcBurstLength  = (UINT8)BL_1XFER;                              /*  Source Bursts length        */
        Inst.DstBurstSize    = (UINT8)BS_4B;                                 /*  Destination Bursts size     */
        Inst.DstBurstLength  = (UINT8)BL_1XFER;                              /*  Destination Bursts length   */
        Inst.EndianSwapSize  = (UINT8)ESS_4;                                 /*  Endian Swap size            */
        Inst.SrcAddress      = (UINT32)&RegA6_QSPI->DRX.Reg;                 /*  Source Address              */
        Inst.DstAddress      = (UINT32)pData;                                /*  Destination Address         */
        Inst.PeriNumber      = (UINT8)DPN_QSPI_RX;                           /*  Peri Number                 */
        Inst.TotalLength     = (UINT32)Length;                               /*  length                      */

        NC_DMA_Gen_microCode(Inst);
    }
}



/**
* @desc
    Generate DMA instrcution on QSPI.
* @param    UINT8*  pData       Destination Address
* @param    UINT32  PageAddr    Page address
* @param    UINT32  Length      Data length
* @return   void
* @design
    Set and apply DMA instruction for QSPI.
*/
/* for QAC Rule-8.13 */
void NC_DMA_QSPI_Gen_Instruction(const UINT8 *pData, UINT32 PageAddr, UINT32 Length)
{
    INSTRUCTION_PARAM Inst;

    /* for NULL CHECK */
    if((pData != (UINT8*)NULL) && (PageAddr != 0U)) 
    {
        /*-----------------------------------------------*/
        Inst.Mode            = (UINT8)RT_DEV_TO_MEM;                         /*  DMA Mode                    */
        Inst.InstAddr        = (UINT32)BOOT_DMA_INST;                        /*  Instruction Address         */
        Inst.SrcBurstSize    = (UINT8)BS_4B;                                 /*  Source Bursts size          */
        Inst.SrcBurstLength  = (UINT8)BL_16XFER;                             /*  Source Bursts length        */
        Inst.DstBurstSize    = (UINT8)BS_16B;                                /*  Destination Bursts size     */
        Inst.DstBurstLength  = (UINT8)BL_4XFER;                              /*  Destination Bursts length   */
        Inst.EndianSwapSize  = (UINT8)ESS_4;                                 /*  Endian Swap size            */
        Inst.SrcAddress      = (UINT32)&RegA6_QSPI->DRX.Reg;                 /*  Source Address              */
        Inst.DstAddress      = (UINT32)pData;                                /*  Destination Address         */
        Inst.PeriNumber      = (UINT8)DPN_QSPI_RX;                           /*  Peri Number                 */
        Inst.TotalLength     = (UINT32)Length;                               /*  length                      */

        NC_DMA_Gen_microCode(Inst);
    }
}

/* End Of File */
