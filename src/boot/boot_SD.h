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

#ifndef BOOT_SD_H_
#define BOOT_SD_H_

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define SD_READ_SECTION0    (0U)
#define SD_READ_SECTION1    (1U)

#define SD_SECTOR_SIZE      (512U)

#define SD_READ_TYPE_NORMAL   (0U)
#define SD_READ_TYPE_BACKUP   (1U)

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern NC_ERROR NC_Boot_SD(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *pStatus);

#endif  /* BOOT_SD_H_ */

/* End Of File */
