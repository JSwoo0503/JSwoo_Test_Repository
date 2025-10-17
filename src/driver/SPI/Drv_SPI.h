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

#ifndef SSP_DRV_H_
#define SSP_DRV_H_

#include "Drv_A6_SPI_Register.h"
#include "Drv_A6_QSPI_Register.h"

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

/* SPI TimeOut - msec */
#define SPI_WAIT_TIMEOUT            (1000U)
/* DMA TimeOut - msec */
#define SPI_DMA_WAIT_TIMEOUT        (1000U)

#define SPI_SPH_LOW                 (0U)
#define SPI_SPH_HIGH                (1U)

#define SPI_SPO_LOW                 (0U)
#define SPI_SPO_HIGH                (1U)

#define SPI_DS_8BIT                 (7U)
#define SPI_DS_32BIT                (0x1FU)
#define SPI_CS_8BIT                 (7U)

#define	SPI_FRF_MOTORORA_SPI        (0x0U)

#define	SPI_TMOD_RW                 (0x0U)
#define	SPI_TMOD_WRITE              (0x1U)
#define	SPI_TMOD_READ               (0x2U)
#define SPI_TMOD_EPROMREAD          (0x3U)		/* eeprom read mode */

#define SPI_DMA_READ_MODE           (0U)
#define SPI_DMA_WRITE_MODE          (1U)
#define SPI_DMA_RW_MODE             (2U)

#define	SPI_TRANS_MODE_SPI          (0U)
#define	SPI_TRANS_MODE_DPI          (1U)
#define	SPI_TRANS_MODE_QPI          (2U)

#define	SPI_TRANS_TYPE0             (0U)
#define	SPI_TRANS_TYPE1             (1U)
#define	SPI_TRANS_TYPE2             (2U)

#define	SPI_ADDRL_0BIT              (0x0U)
#define	SPI_ADDRL_24BIT             (0x6U)

#define	SPI_INST_8BIT               (0x2U)

#define SPI_SLV_OE_EN               (0x0)
#define SPI_SLV_OE_DIS              (0x1)

#define SPI_SRL_NORMAL_MODE         (0x0)
#define SPI_SRL_TESTING_MODE        (0x1)

/* SPI_CTRO0 : 0x00 */
#define SPI_PROTOCOL                (4U)
#define SPI_SCPH                    (6U)
#define SPI_SCPOL                   (7U)
#define SPI_TMOD8                   (8U)
#define SPI_SLV_OE                  (10U)
#define SPI_SRL                     (11U)
#define SPI_CFS16                   (12U)  /* Control Frame Size. */
#define SPI_DFS32                   (16U)  /* Data Frame Size. */
#define SPI_FRAME_FORMAT            (21U)

/* Interrupt Mask Register : 0x2C */
#define SPI_IMR_TXEIM               (1U)
#define SPI_IMR_TXOIM               (1U<<1)
#define SPI_IMR_RXUIM               (1U<<2)
#define SPI_IMR_RXOIM               (1U<<3)
#define SPI_IMR_RXFIM               (1U<<4)
#define SPI_IMR_MSTIM               (1U<<5)

/* DMA */
#define SPI_DMA_TX_EN               (0x1U<<1)
#define SPI_DMA_RX_EN               (0x1U)

/* SPI Control : 0xF4 */
#define SPI_WAIT_CYCLE              (11U)
#define SPI_INST_LEN                (8U)
#define SPI_ADDR_LEN                (2U)


/**********************************************************************/
#define BIT(nr)                     (1UL << (nr))
#define BITS_PER_LONG               (32)
#define GENMASK(h, l)               (((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

/* Only present when SSI_MAX_XFER_SIZE=32 */
#define CTRLR0_DFS_32_MASK          (16) /*GENMASK(20, 16)*/

#define CTRLR0_FRF_MASK             (4)  /*GENMASK(5, 4)*/
#define CTRLR0_FRF_SPI              (0x0)

#define CTRLR0_MODE_MASK            (6)  /*GENMASK(7, 6)*/
#define CTRLR0_MODE_SCPH            (0x1)
#define CTRLR0_MODE_SCPOL           (0x2)

/* The next field is only present on versions after 4.00a */
#define CTRLR0_SPI_FRF_MASK         (21) /*GENMASK(22, 21)*/
#define CTRLR0_SPI_FRF_BYTE         (0x0)
#define	CTRLR0_SPI_FRF_DUAL         (0x1)
#define	CTRLR0_SPI_FRF_QUAD         (0x2)

#define CTRLR0_TMOD_MASK            (8)  /*GENMASK(9, 8)*/

/* Bit fields in SR, 7 bits */
#define SPI_CTRLR0_WAIT_CYCLES      (11) /*GENMASK(15, 11)*/
#define SPI_CTRLR0_INST_L           (8)  /*GENMASK(9, 8)*/
#define SPI_CTRLR0_INST_NO          (0)
#define SPI_CTRLR0_INST_4BIT        (1)
#define SPI_CTRLR0_INST_8BIT        (2)
#define SPI_CTRLR0_INST_16BIT       (3)
#define SPI_CTRLR0_ADDR_L           (2)  /*GENMASK(5, 2)*/
#define SPI_CTRLR0_ADDR_NO          (0)
#define SPI_CTRLR0_ADDR_4BIT        (1)
#define SPI_CTRLR0_ADDR_8BIT        (2)
#define SPI_CTRLR0_ADDR_12BIT       (3)
#define SPI_CTRLR0_ADDR_16BIT       (4)
#define SPI_CTRLR0_ADDR_20BIT       (5)
#define SPI_CTRLR0_ADDR_24BIT       (6)
#define SPI_CTRLR0_ADDR_28BIT       (7)
#define SPI_CTRLR0_ADDR_32BIT       (8)
#define SPI_CTRLR0_ADDR_36BIT       (9)
#define SPI_CTRLR0_ADDR_40BIT       (10)
#define SPI_CTRLR0_ADDR_44BIT       (11)
#define SPI_CTRLR0_ADDR_48BIT       (12)
#define SPI_CTRLR0_ADDR_52BIT       (13)
#define SPI_CTRLR0_ADDR_56BIT       (14)
#define SPI_CTRLR0_ADDR_60BIT       (15)
#define SPI_CTRLR0_TRANS_TYPE       (0) /*GENMASK(1, 0)*/
#define SPI_CTRLR0_TRANS_TYPE0      (0)	/* Instruction and Address will be sent in Standard SPI Mode. */
#define SPI_CTRLR0_TRANS_TYPE1      (1)	/* Instruction will be sent in Standard SPI Mode and Address will be sent in the mode specified by CTRLR0.SPI_FRF. */
#define SPI_CTRLR0_TRANS_TYPE2      (2)	/* Both Instruction and Address will be sent in the mode specified by SPI_FRF. */

#define CSN_SEL_POS                 (0)
#define CSN_VAL_POS                 (4)
#define CSN_SEL_MASK                BIT(0)
#define CSN_VAL_MASK                BIT(4)

#define SwapTwoBytes(data) \
                    ( (((data) >> 8U) & 0x00FFU) | (((data) << 8U) & 0xFF00U) )

#define SwapFourBytes(data)   \
                    ( ((data) >> 24U) | (((data) >>  8U) & 0x0000FF00U) | \
                      (((data) <<  8U) & 0x00FF0000U) | ((data) << 24U) )

/**********************************************************************/

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_QSPI_REGISTER* const RegA6_QSPI;

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern NC_ERROR  NC_SPI_WaitTxFIFOIsEmpty(void);
extern NC_ERROR  NC_SPI_WaitBusIsBusy(void);
extern void   NC_SPI_Init(UINT32 BitRate, UINT32 RefClk);
extern void   NC_SPI_DeInit(void);
extern void   NC_SPI_Read(UINT8 *pBuf, UINT32 Length);
extern void   NC_SPI_Write(const UINT8 *pBuf, UINT32 Length);
extern void   NC_SPI_Write32(const UINT32 *pBuf, UINT32 Length);
extern void   NC_SPI_WriteDummy(UINT32 Length);
extern void   NC_SPI_EnableCS(void);
extern void   NC_SPI_DisableCS(void);
extern void   NC_SPI_EnableDMAReq(void);
extern void   NC_SPI_DisableDMAReq(void);
extern void   NC_SPI_SetBitRate(UINT32 *pBitRate, UINT32 RefClk);
extern void   NC_SPI_SetFrameSize(UINT32 Size);
extern void   NC_SPI_SetTMOD(UINT32 Mode);
extern void   NC_SPI_SetDataLevel(UINT32 Rx);
extern void   NC_SPI_SetTransferLength(UINT32 Size);
#if 0
extern UINT32 NC_SPI_GetDFS(void);
#endif
extern void   NC_QSPI_Init(UINT32 BitRate, UINT32 RefClk, UINT32 DummyCycle);
extern void   NC_QSPI_Read(UINT32 pBuf, UINT32 Length);
extern void   NC_QSPI_Write(const UINT32 *pBuf, UINT32 Length);
extern UINT32 NC_QSPI_SetBitRate(UINT32 Div, UINT32 RefClk);


#endif /* SSP_DRV_H_ */


/* End Of File */

