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

#ifndef EMMC_DRV_H_
#define EMMC_DRV_H_

#include "Drv_A6_EMMC_Register.h"

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define SD_BOOT_FREQ                    (25U * MHZ)

#define USE_INTERRUPT                   (0U)
#define USE_BOOT_ACK                    (0U)

/* EMMC TimeOut - msec */
#define EMMC_WAIT_TIMEOUT               (1000U)

/* bit-31 is Card power up status bit (busy) */
#define EMMC_BUSY                       (0x80000000)
#define EMMC_MAX_LOOP_CNT               (50U)

/* Response Length */
#define EMMC_NO_RESP                    (0U)
#define EMMC_RESP_LEN_136               (1U)
#define EMMC_RESP_LEN_48                (2U)
#define EMMC_RESP_LEN_48B               (3U)

/* Response Type */
#define EMMC_R1_MEMORY                  (0U)
#define EMMC_R5_SDIO                    (1U)

/* Data Bus Width */
#define EMMC_DATABUSWIDTH_1BIT          (0U)
#define EMMC_DATABUSWIDTH_4BIT          (1U)
#define EMMC_DATABUSWIDTH_8BIT          (2U)

/* Transfer Type */
#define EMMC_TRANSFER_WRITE             (0U)
#define EMMC_TRANSFER_READ              (1U)

/* Voltage Selection */
#define EMMC_BUS_VOLTAGE_SELECT_1_2V    (5U)
#define EMMC_BUS_VOLTAGE_SELECT_1_8V    (6U)
#define EMMC_BUS_VOLTAGE_SELECT_3_3V    (7U)

/* Register 0x34(0x38, 0x30)) Normal interrupt status(signal) en field */
#define EMMC_CMD_COMPLETE               (1U)
#define EMMC_XFER_COMPLETE              ((UINT16)1U << 1U)
#define EMMC_BGAP_EVENT                 (1U << 2U)
#define EMMC_DMA_INTERRUPT              (1U << 3U)
#define EMMC_BUF_WR_READY               (1U << 4U)
#define EMMC_BUF_RD_READY               ((UINT16)1U << 5U)
#define EMMC_CARD_INSERTION             (1U << 6U)
#define EMMC_CARD_REMOVAL               (1U << 7U)
#define EMMC_CARD_INTERRUPT             (1U << 8U)
#define EMMC_INT_A                      (1U << 9U)
#define EMMC_INT_B                      (1U << 10U)
#define EMMC_INT_C                      (1U << 11U)
#define EMMC_RE_TUNE_EVENT              (1U << 12U)
#define EMMC_FX_EVENT                   (1U << 13U)
#define EMMC_CQE_EVENT                  (1U << 14U)
#define EMMC_ERR                        (1U << 15U)

/* 0x04 BLOCKSIZE Register */
#define EMMC_SDMA_BUF_BDARY_4K          (0U)
#define EMMC_SDMA_BUF_BDARY_8K          (1U)
#define EMMC_SDMA_BUF_BDARY_16K         (2U)
#define EMMC_SDMA_BUF_BDARY_32K         (3U)
#define EMMC_SDMA_BUF_BDARY_64K         (4U)
#define EMMC_SDMA_BUF_BDARY_128K        (5U)
#define EMMC_SDMA_BUF_BDARY_256K        (6U)
#define EMMC_SDMA_BUF_BDARY_512K        (7U)

/* 0x2e TOUT Register */
#define EMMC_TOUT_E                     (0xE)    /* TMCLK x 2^27 */
#define EMMC_TOUT_D                     (0xD)    /* TMCLK x 2^26 */
#define EMMC_TOUT_C                     (0xC)    /* TMCLK x 2^25 */
#define EMMC_TOUT_B                     (0xB)    /* TMCLK x 2^24 */
#define EMMC_TOUT_A                     (0xA)    /* TMCLK x 2^23 */
#define EMMC_TOUT_9                     (0x9)    /* TMCLK x 2^22 */
#define EMMC_TOUT_8                     (0x8)    /* TMCLK x 2^21 */
#define EMMC_TOUT_7                     (0x7)    /* TMCLK x 2^20 */
#define EMMC_TOUT_6                     (0x6)    /* TMCLK x 2^19 */
#define EMMC_TOUT_5                     (0x5)    /* TMCLK x 2^18 */
#define EMMC_TOUT_4                     (0x4)    /* TMCLK x 2^17 */
#define EMMC_TOUT_3                     (0x3)    /* TMCLK x 2^16 */
#define EMMC_TOUT_2                     (0x2)    /* TMCLK x 2^15 */
#define EMMC_TOUT_1                     (0x1)    /* TMCLK x 2^14 */
#define EMMC_TOUT_0                     (0x0)    /* TMCLK x 2^13 */

#define EMMC_AUTO_CMD_DISABLED          (0x0)
#define EMMC_AUTO_CMD12_ENABLED         (0x1)
#define EMMC_AUTO_CMD23_ENABLED         (0x2)
#define EMMC_AUTO_CMD_AUTO_SEL          (0x3)

#define EMMC_BOOT_ACK_EN                (1U << 8)
#define EMMC_VALIDATE_BOOT_EN           (1U << 7)
#define EMMC_MANDATORY_BOOT_EN          (1U)

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_EMMC_REGISTER* const RegA6_EMMC;

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern NC_ERROR NC_EMMC_Initialize(UINT32 RefClk);
extern void     NC_EMMC_DeInit(void);
extern NC_ERROR NC_EMMC_ReadByADMA2(UINT32 rtype, const UINT32 *pData, UINT32 Size);
extern NC_ERROR NC_EMMC_ReadByFIFO(UINT32 rtype, UINT32 *pData, UINT32 Size);
#endif  /* EMMC_DRV_H_ */

/* End Of File */
