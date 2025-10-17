/**
********************************************************************************
*
*  Copyright (C) 2018 NEXTCHIP Inc. All rights reserved.
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

#ifndef DRV_SDC_H_
#define DRV_SDC_H_

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define SD_INIT_FREQ                (400U * KHZ)
#define SD_DATA_FREQ                (25U * MHZ)

/* SD TimeOut - msec */
#define SD_WAIT_TIMEOUT             (1000U)

/* bit-31 is Card power up status bit (busy) */
#define SD_BUSY                     (0x80000000U)

#define SDHCI_MAX_DIV_SPEC_300      (2046U)

/* Register 0x34(0x38, 0x30)) Normal interrupt status(signal) en field */
#define SD_CMD_COMPLETE             (1U)
#define SD_XFER_COMPLETE            ((UINT16)1U << 1U)
#define SD_BGAP_EVENT               (1U << 2U)
#define SD_DMA_INTERRUPT            (1U << 3U)
#define SD_BUF_WR_READY             (1U << 4U)
#define SD_BUF_RD_READY             ((UINT16)1U << 5U)
#define SD_CARD_INSERTION           (1U << 6U)
#define SD_CARD_REMOVAL             (1U << 7U)
#define SD_CARD_INTERRUPT           (1U << 8U)
#define SD_INT_A                    (1U << 9U)
#define SD_INT_B                    (1U << 10U)
#define SD_INT_C                    (1U << 11U)
#define SD_RE_TUNE_EVENT            (1U << 12U)
#define SD_FX_EVENT                 (1U << 13U)
#define SD_CQE_EVENT                (1U << 14U)
#define SD_ERR                      (1U << 15U)

/* Register 0x29 Power Control */
#define SD_BUS_VOL_VDD2_18          (5U << 5U)
#define SD_BUS_VOL_VDD2_12          (4U << 5U)
#define SD_BUS_VOL_VDD2_OFF         (0U << 4U)
#define SD_BUS_PWR_VDD2_ON          (1U << 4U)
#define SD_BUS_VOL_VDD1_33          ((UINT8)7U << 1U)
#define SD_BUS_VOL_VDD1_18          (5U << 1U)
#define SD_BUS_PWR_VDD1_OFF         (0U)
#define SD_BUS_PWR_VDD1_ON          (1U)

/* Register 0x28 Host Control1 */
#define SD_DATA_WIDTH_1             (0U << 1U)
#define SD_DATA_WIDTH_4             ((UINT32)1U << (UINT8)1U)
#define SD_SPEED_NORMAL             ((UINT8)0U << 2U)
#define SD_SPEED_HIGH               (1U << 2U)
#define SD_SDMA_SEL                 ((UINT8)0U << 3U)
#define SD_ADMA2_SEL_V4_EN          (2U << 3U)
#define SD_ADMA2_ADMA3_SEL_V4_EN    (3U << 3U)
#define SD_ADMA2_32BIT_V4_DIS       (2U << 3U)
#define SD_ADMA2_64BIT_V4_DIS       (3U << 3U)
#define SD_8BIT_DATA                (1U << 5U)

/* Register 0x3E Host Control2 */
#define SD_PRESET_VAL_EN            (1U << 15U)
#define SD_PRESET_VAL_DIS           ((UINT16)0U << 15U)
#define SD_ASYNC_INT_EN             ((UINT16)1U << 14U)
#define SD_ASYNC_INT_DIS            (0U << 14U)
#define SD_ADDRESS_64               (1U << 13U)
#define SD_ADDRESS_32               ((UINT16)0U << 13U)
#define SD_HOST_VER4_EN             ((UINT16)1U << 12U)
#define SD_HOST_VER3_EN             (0U << 12U)
#define SD_CMD23_EN                 ((UINT16)1U << 11U)
#define SD_CMD23_DIS                (0U << 11U)
#define SD_ADMA2_LEN_26BIT          ((UINT16)1U << 10U)
#define SD_ADMA2_LEN_16BIT          (0U << 10U)
#define SD_SD_eMMC_INF              ((UINT16)0U << 8U)
#define SD_UHS2_IF                  (1U << 8U)
#define SD_RX_FIXED_CLK             ((UINT16)0U << 7U)
#define SD_RX_TUNED_CLK             (1U << 7U)
#define SD_EXEC_TUNE_ON             (1U << 6U)
#define SD_EXEC_TUNE_OFF            ((UINT16)0U << 6U)
#define SD_18V_SWITCH               (1U << 3U)
#define SD_33V_SWITCH               ((UINT16)0U << 3U)
#define SD_SDR12                    (0U)
#define SD_SDR25                    (1U)
#define SD_SDR50                    (2U)
#define SD_SDR104                   (3U)
#define SD_DDR50                    (4U)

/* Register 0x508 MSHX Control */
#define SD_CMD_CONFLICT_CHK_ON      (1U)
#define SD_CMD_CONFLICT_CHK_OFF     (0U)
#define SD_CLK_GATE_EN              (0U << 4U)
#define SD_CLK_GATE_DIS             (1U << 4U)
#define SD_NEDGE_DRIV               (0U << 6U)
#define SD_PEDGE_DRIV               (1U << 6U)

/* Register 0x2C CLK Control */
#define SD_INT_CLK_EN               (1U)
#define SD_INT_CLK_DIS              (0U)
#define SD_SD_CLK_EN                (1U << 2U)
#define SD_SD_CLK_DIS               (0U << 2U)

/* Register 0x2F Software Reset Control */
#define SD_SW_RST_ALL               (1U)
#define SD_SW_RST_CMD               (1U << 1U)
#define SD_SW_RST_DAT               (1U << 2U)

/* Register 0x36(0x3A) Error interrupt status(signal) enable */
#define SD_VENDOR_ERR3              (1U << 15U)
#define SD_VENDOR_ERR2              (1U << 14U)
#define SD_VENDOR_ERR1              (1U << 13U)
#define SD_BOOT_ACK_ERR             (1U << 12U)
#define SD_RESP_ERR                 ((UINT16)1U << 11U)
#define SD_TUNING_ERR               ((UINT16)1U << 10U)
#define SD_ADMA_ERR                 ((UINT16)1U << 9U)
#define SD_AUTO_CMD_ERR             ((UINT16)1U << 8U)
#define SD_CUR_LMT_ERR              (1U << 7U)
#define SD_DATA_END_BIT_ERR         (1U << 6U)
#define SD_DATA_CRC_ERR             (1U << 5U)
#define SD_DATA_TOUT_ERR            (1U << 4U)
#define SD_CMD_IDX_ERR              (1U << 3U)
#define SD_CMD_END_BIT_ERR          (1U << 2U)
#define SD_CMD_CRC_ERR              (1U << 1U)
#define SD_CMD_TOUT_ERR             (1U)

/* Register 0x04 BLOCKSIZE Register */
#define SD_SDMA_BUF_BDARY_4K        (0U << 12U)
#define SD_SDMA_BUF_BDARY_8K        (1U << 12U)
#define SD_SDMA_BUF_BDARY_16K       (2U << 12U)
#define SD_SDMA_BUF_BDARY_32K       (3U << 12U)
#define SD_SDMA_BUF_BDARY_64K       (4U << 12U)
#define SD_SDMA_BUF_BDARY_128K      (5U << 12U)
#define SD_SDMA_BUF_BDARY_256K      (6U << 12U)
#define SD_SDMA_BUF_BDARY_512K      (7U << 12U)

/* Register 0x0C XFER_MODE Register */
#define SD_DMA_ENABLE               (1U)
#define SD_DMA_DISABLE              (0U)
#define SD_BLOCK_CNT_ENABLE         ((UINT16)1U << 1U)
#define SD_BLOCK_CNT_DISABLE        (0U << 1U)
#define SD_AUTO_CMD_DISABLE         (0U << 2U)
#define SD_AUTO_CMD12_ENABLE        ((UINT16)1U << 2U)
#define SD_AUTO_CMD23_ENABLE        (2U << 2U)
#define SD_AUTO_CMD_AUTO_SEL        (3U << 2U)
#define SD_DATA_XFER_READ           ((UINT16)1U << 4U)
#define SD_DATA_XFER_WRITE          (0U << 4U)
#define SD_MULT_BLK_SEL             ((UINT16)1U << 5U)
#define SD_SINGLE_BLK_SEL           ((UINT16)0U << 5U)
#define SD_RESP_TYPE_R1             (0U << 6U)
#define SD_RESP_TYPE_R5             (1U << 6U)
#define SD_RESP_ERR_CHK_ENABLE      (1U << 7U)
#define SD_RESP_ERR_CHK_DISABLE     (0U << 7U)
#define SD_RESP_INT_DISBALE         (1U << 8U)
#define SD_RESP_INT_ENABLE          (0U << 8U)

/* Register 0xE CMD Register */
#define SD_ABORT_CMD                (3U << 6U)
#define SD_RESUME_CMD               (2U << 6U)
#define SD_SUSPEND_CMD              (1U << 6U)
#define SD_NORMAL_CMD               (0U << 6U)
#define SD_NO_DATA_PRESENT          (0U << 5U)
#define SD_DATA_PRESENT             ((UINT16)1U << 5U)
#define SD_IDX_CHK_ENB              ((UINT16)1U << 4U)
#define SD_IDX_CHK_DIS              ((UINT16)0U << 4U)
#define SD_CMD_CHK_ENB              ((UINT16)1U << 3U)
#define SD_CMD_CHK_DIS              ((UINT16)0U << 3U)
#define SD_SUB_CMD_FLAG             (1U << 2U)
#define SD_MAIN_CMD_FLAG            (0U << 2U)
#define SD_NO_RESP                  (0U)
#define SD_RESP_LEN_136             (1U)
#define SD_RESP_LEN_48              (2U)
#define SD_RESP_LEN_48B             (3U)

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern NC_ERROR NC_SDC_Init(UINT32 RefClk);
extern void NC_SDC_DeInit(void);
extern void NC_SDC_Read(UINT32 Addr, UINT32 *pData, UINT32 Size);

#endif /* SD_DRV_H_ */

/* End Of File */
