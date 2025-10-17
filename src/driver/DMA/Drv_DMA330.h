/*
  *===================================================================================================================
  *                            List of abbreviation of keywords (prefix, structure name, ...)
  *===================================================================================================================
  * t (prefix) -> structure  ex) tDMA_THREAD, tDMA_REQ
  * SEV        -> Send Event
  * Xfer       -> Transfer
  * ri         -> Request Information
  * rc         -> Request Configuration
  * oft        -> Offset -- Used for calculating instruction binary size
  * ENC        -> Encoded (for using with instruction set)
  *===================================================================================================================
  */

#ifndef DMA_330_H__
#define DMA_330_H__

#include "Drv_A6_DMA330_Register.h"
/* #include "Drv_A6_QSPI_Register.h" */

/****************************************************************************
*               DEFINES
*****************************************************************************/

#define CMD_DMAADDH	        (0x54)
#define CMD_DMAADNH         (0x5C)
#define CMD_DMAEND	        (0x00)
#define CMD_DMAFLUSHP	    (0x35)
#define CMD_DMAGO	        (0xA0)
#define CMD_DMALD	        (0x04)
#define CMD_DMALDP	        (0x25)
#define CMD_DMALP	        (0x20)
#define CMD_DMALPEND	    (0x28)
#define CMD_DMAKILL	        (0x01)
#define CMD_DMAMOV	        (0xBC)
#define CMD_DMANOP	        (0x18)
#define CMD_DMARMB	        (0x12)
#define CMD_DMASEV	        (0x34)
#define CMD_DMAST	        (0x08)
#define CMD_DMASTP	        (0x29)
#define CMD_DMASTZ	        (0x0C)
#define CMD_DMAWFE	        (0x36)
#define CMD_DMAWFP	        (0x30)
#define CMD_DMAWMB	        (0x13)

/* CSR (Channel Status Register) */
#define CSR_NON_SECURE      (1<<21)
#define CSR_WFP_PERIPH      (1<<15)
#define CSR_WFP_BURST       (1<<14)
#define CSR_WAKE_NUM_SFT    (4)
#define CSR_WAKE_NUM_MSK    (0x1F<<4)
#define CSR_CS_MASK         (0xF<<0)
#define CSR_CS_FAULTING     (0xF<<0)
#define CSR_CS_FAULT_COMP   (0xE<<0)
#define CSR_CS_COMPLETING   (0x9<<0)
#define CSR_CS_KILLING      (0x8<<0)
#define CSR_CS_WFP          (0x7<<0)
#define CSR_CS_AT_BARRIER   (0x5<<0)
#define CSR_CS_WFE          (0x4<<0)
#define CSR_CS_UPDATE_PC    (0x3<<0)
#define CSR_CS_CACHE_MISS   (0x2<<0)
#define CSR_CS_EXECUTING    (0x1<<0)
#define CSR_CS_STOPPED      (0x0<<0)

/* DMA Microcode size */
#define BL_INST_BUFF_SIZE           (256U)


/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_DMA330_REGISTER* const RegA6_DMA330;

typedef enum
{
    ESS_NO,
    ESS_2,
    ESS_4,
    ESS_8,
    ESS_16
}tENDIAN_SWAP_SIZE;

typedef enum
{
    BL_1XFER = 1, /* XFER == Abbreviation of Transfer */
    BL_2XFER,
    BL_3XFER,
    BL_4XFER,
    BL_5XFER,
    BL_6XFER,
    BL_7XFER,
    BL_8XFER,
    BL_9XFER,
    BL_10XFER,
    BL_11XFER,
    BL_12XFER,
    BL_13XFER,
    BL_14XFER,
    BL_15XFER,
    BL_16XFER
}tBURST_LEN;

typedef enum
{
    BS_1B,
    BS_2B,
    BS_4B,
    BS_8B,
    BS_16B
}tBURST_SIZE;

typedef enum
{
    RT_MEM_TO_MEM,
    RT_MEM_TO_DEV,
    RT_DEV_TO_MEM
}tREQ_TYPE;

typedef enum
{
    DPN_UART_0_RX = 0, /*  0 */
    DPN_UART_0_TX,     /*  1 */
    DPN_UART_1_RX,     /*  2 */
    DPN_UART_1_TX,     /*  3 */
    DPN_UART_2_RX,     /*  4 */
    DPN_UART_2_TX,     /*  5 */
    DPN_UART_3_RX,     /*  6 */
    DPN_UART_3_TX,     /*  7 */
    DPN_I2C_0_RX,      /*  8 */
    DPN_I2C_0_TX,      /*  9 */
    DPN_I2C_1_RX,      /* 10 */
    DPN_I2C_1_TX,      /* 11 */
    DPN_I2C_2_RX,      /* 12 */
    DPN_I2C_2_TX,      /* 13 */
    DPN_I2C_3_RX,      /* 14 */
    DPN_I2C_3_TX,      /* 15 */
    DPN_I2C_4_RX,      /* 16 */
    DPN_I2C_4_TX,      /* 17 */
    DPN_I2C_5_RX,      /* 18 */
    DPN_I2C_5_TX,      /* 19 */
    DPN_I2C_6_RX,      /* 20 */
    DPN_I2C_6_TX,      /* 21 */
    DPN_I2C_7_RX,      /* 22 */
    DPN_I2C_7_TX,      /* 23 */
    DPN_SPI_0_RX,      /* 24 */
    DPN_SPI_0_TX,      /* 25 */
    DPN_SPI_1_RX,      /* 26 */
    DPN_SPI_1_TX,      /* 27 */
    DPN_SPI_2_RX,      /* 28 */
    DPN_SPI_2_TX       /* 29 */
}tDMA_0_PERI_NUM;

typedef enum
{
    DPN_CAN_0_RX = 0,  /*  0 */
    DPN_CAN_1_TX,      /*  1 */
    DPN_QSPI_RX,       /*  2 */
    DPN_QSPI_TX,       /*  3 */
    DPN_I2S_RX,        /*  4 */
    DPN_I2S_TX         /*  5 */
}tDMA_1_PERI_NUM;


typedef union
{
    UINT32 Reg;
    struct {
        UINT32 srcInc:1;         /* [0] */
        UINT32 srcBurstSize:3;   /* [3:1] */
        UINT32 srcBurstLen:4;    /* [7:4] */
        UINT32 srcProtCtrl:3;    /* [10:8] */
        UINT32 srcCacheCtrl:3;   /* [13:11] */
        UINT32 dstInc:1;         /* [14] */
        UINT32 dstBurstSize:3;   /* [17:15] */
        UINT32 dstBurstLen:4;    /* [21:18] */
        UINT32 dstProtCtrl:3;    /* [24:22] */
        UINT32 dstCacheCtrl:3;   /* [27:25] */
        UINT32 endianSwapSize:3; /* [30:28] */
        UINT32 Reserved:1;       /* [31] */
    }Bit;
}tCCR;

typedef enum
{
    ERD_SAR, /* Source Address Register */
    ERD_CCR, /* Channel Control Register */
    ERD_DAR /* Destination Address Register */
}tENC_RD;   /* DMAMOV */

/*enum
{
    DMA_SPI = 0,
    DMA_QSPI
};*/

typedef struct
{
    UINT8 Mode;
    UINT32 InstAddr;
    UINT8 SrcBurstSize;
    UINT8 SrcBurstLength;
    UINT8 DstBurstSize;
    UINT8 DstBurstLength;
    UINT8 EndianSwapSize;
    UINT32 SrcAddress;
    UINT32 DstAddress;
    UINT8 PeriNumber;
    UINT32 TotalLength;
}INSTRUCTION_PARAM;


/****************************************************************************
 *       Global Variable Definitions
 *****************************************************************************/


/****************************************************************************
 *       Global Function Definitions
 *****************************************************************************/
extern void     NC_DMA_Kill(UINT32 Ch);
extern void     NC_DMA_Gen_microCode(INSTRUCTION_PARAM Inst);
extern void     NC_DMA_Run (UINT32 Ch);
extern void     NC_DMA_Wait_Ch_Complete(UINT32 Ch);
extern void     NC_DMA_QSPI_Gen_Instruction(const UINT8 *pData, UINT32 PageAddr, UINT32 Length);
extern void     NC_DMA_SPI_Gen_Instruction(const UINT8 *pData, UINT32 PageAddr, UINT32 Length);
extern void     NC_DMA_Start(void);
extern void     NC_DMA_Wait_Complete(void);
extern void     NC_DMA_Deinit(void);

#endif /* DMA_330_H__ */
