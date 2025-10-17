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

#ifndef MAIN_H_
#define MAIN_H_

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

/* BL2 Img header MAGIC CODE */
#define BL_IMG_SIGNATURE_ID                 (0x30365041U)       /* AP60 */

/* IROM, IRAM Information */
#define APACHE_IROM_BASE                    (0x00000000U)
#define APACHE_IRAM_BASE                    (0x01000000U)
#define APACHE_IRAM_SIZE                    (0x00070000U)       /* 448KByte */

/* BL Image loading Buffer */
#define BL_TEMP_BUFF_ADDR                   (APACHE_IRAM_BASE)
#define BL_IMG_MAX_SIZE                     (APACHE_IRAM_SIZE)

/* BL Image Header Size */
#define BL_IMG_HEADER_SIZE                  (64U)

/* sFlash Img offset */
#define BL_IMG_SRC_NORMAL_ADDR              (0x00001000U)
#define BL_IMG_SRC_BACKUP_ADDR              (0x00011000U)
#define BL_IMG_SRC_BACKUP_ADDR_OFFSET       (0x00010000U)
#define BL_IMG_DEST_ADDR                    (APACHE_IRAM_BASE)

/* eMMC Img Offset */
#define BL_IMG_EMMC_DEFAULT_NORMAL_ADDR      (0x00000000U)      /* minimum normal address offset 0 [KByte] : 0x0 */
#define BL_IMG_EMMC_DEFAULT_BACKUP_ADDR      (0x00050000U)      /* minimum backup address offset 64 [KByte] */

/* SD Image Offset Sector for fat32 partion */
#define BL_IMG_SD_DEFAULT_NORMAL_SECTOR      (16U)               /* minimum normal address offset 16 [KByte] : address 0x2000 */
#define BL_IMG_SD_DEFAULT_BACKUP_SECTOR      (640U)             /* minimum backup address offset 320 [KByte] : address 0x5_0000 */

#endif  /* MAIN_H_ */

/* End Of File */
