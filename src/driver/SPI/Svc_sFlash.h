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

#ifndef SFLASH_SVC_H_
#define SFLASH_SVC_H_

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define CMD_sFLASH_WR_EN                        (0x06U)
#define CMD_sFLASH_WR_DS                        (0x04U)
#define CMD_sFLASH_RD_STS                       (0x05U)
#define CMD_sFLASH_RD_STS2                      (0x35U)     /* for WINBOND Type */
#define CMD_sFLASH_WR_STS                       (0x01U)
#define CMD_sFLASH_WR_STS3                      (0x31U)     /* for GIGA DEVICE Type */
#define CMD_sFLASH_WR_STS4                      (0x38U)     /* for EON Type : EQIO */
#define CMD_sFLASH_RD_DATA                      (0x03U)
#define CMD_sFLASH_RD_IDENTIFICATION            (0x9FU)

#define CMD_sFLASH_EQIO                         (0x35U)     /* for MXIC, MICRON : Enter QIO Mode */
#define CMD_sFLASH_RSTQIO                       (0xF5U)     /* for MXIC, MICRON : Reset QIO Mode */

#define CMD_sFLASH_RD_CONFIG                    (0x85U)     /* for MICRON : Check Dummy Clock Cycles */
#define CMD_sFLASH_WD_CONFIG                    (0x81U)     /* for MICRON : Set Dummy Clock Cycles */

#define CMD_SFLASH_QUAD_RD_QUAD_INST            (0xEBU)     /* Extended SPI 1-4-4 or Quad 4-4-4(QIO Mode) */
#define CMD_SFLASH_QUAD_WD_SINGLE_INST          (0x38U)


#define STS_WIP                                 (1U)
#define STS_WEL                                 (1UL<<1)

#define FLASH_ID_WINBOND                        (0xEFU)
#define FLASH_ID_EON                            (0x1CU)
#define FLASH_ID_MXIC                           (0xC2U)
#define FLASH_ID_CYPRESS                        (0x01U)      /* Spansion */
#define FLASH_ID_AMIC                           (0x37U)
#define FLASH_ID_ISSI                           (0x7FU)
#define FLASH_ID_GIGA                           (0xC8U)
#define FLASH_ID_MICRON                         (0x20U)
#define FAASH_ID_SST                            (0xBFU)
#define FLASH_ID_ATML                           (0x1FU)


/* sFlash Quad Enable Types */
#define SF_CON_NO                               (0U)
#define SF_CON_QE_TYPE1                         (1U)         /* QSPI Model Type1 (Winbond, CYPRESS, AMIC) */
#define SF_CON_QE_TYPE2                         (2U)         /* QSPI Model Type2 (MXIC, ISSI)             */
#define SF_CON_QE_TYPE3                         (3U)         /* QSPI Model Type3 (GIGA)                   */
#define SF_CON_QE_TYPE4                         (4U)         /* QSPI Model Type4 (EON)                    */
#define SF_CON_QE_TYPE5                         (5U)         /* QSPI Model Type5 (Micron)                 */
#define SF_CON_QE_MAX                           (6U)


#define SF_BLOCK_SIZE                           (64U*KB)
#define SF_SECTOR_SIZE                          (4U*KB)
#define SF_PAGE_SIZE                            (256U)
#define SF_MAX_NDF_64K                          (0x10000U)

#define SF_DMA_TIME_OUT                         (2000UL)     /* 2-msec */

#define SF_DUMMY_CLOCK_CYCLES                   (6U)

#define CTRL_NONE                               (0x0U)
#define E_SF_SPI_DEFAULT                        (0x0U)       /*default mode */
#define E_SF_SPI_MODE                           (0x1U)
#define E_SF_QSPI_MODE                          (0x2U)
#define E_SF_DMA_SPI_MODE                       (0x3U)
#define E_SF_DMA_QSPI_MODE                      (0x4U)

#define E_SF_CTRL_MODE_MAX                      (0x4U)

/*
********************************************************************************
*               ENUMERATION
********************************************************************************
*/


/*
********************************************************************************
*              FUNCTION DEFINITIONS
********************************************************************************
*/

extern void  NC_SF_ReadID(UINT8* pBuff);
extern NC_ERROR NC_SF_EnableDeviceQuadMode(UINT8* pRDID, UINT32 Config);
extern void NC_SF_DMA_SPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size);
extern void NC_SF_DMA_QSPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size);
extern void NC_SF_SPI_ReadData(UINT32 Addr, UINT8 *pData, UINT32 Size);
extern void NC_SF_QSPI_ReadData(UINT32 Addr, UINT32 pData, UINT32 Size);
extern void NC_SF_ReadData(UINT32 CtrlMode, UINT32 Addr, UINT8 *pData, UINT32 Size);
extern void  NC_SF_DeInit(void);
extern void  NC_SF_Init(UINT32 BitRate, UINT32 RefClk);


#endif /* SFLASH_SVC_H_ */


/* End Of File */

