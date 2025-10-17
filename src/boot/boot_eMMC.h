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

#ifndef BOOT_EMMC_H_
#define BOOT_EMMC_H_

/*
********************************************************************************
*               TYPEDEFS
********************************************************************************
*/

#define EMMC_READ_TYPE_NORMAL   (0U)
#define EMMC_READ_TYPE_PRIMARY  (1U)
#define EMMC_READ_TYPE_BACKUP   (2U)

#define EMMC_WITHOUT_HEADER     (0x10U)

#define EMMC_SECTOR_SIZE    (512U)

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern NC_ERROR NC_Boot_eMMC(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus);

#endif  /* BOOT_EMMC_H_ */

/* End Of File */
