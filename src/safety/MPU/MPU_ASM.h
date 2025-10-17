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

#ifndef MPU_ASM_H_
#define MPU_ASM_H_


/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define MPU_REGION_TYPE_SAFETY_ENGINE_TXT   (1U)
#define MPU_REGION_TYPE_DEBUG_SECTION       (2U)
#define MPU_REGION_TYPE_DEBUG_DATA_SECTION  (3U)


/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern UINT32 NC_MPU_GET_REGION_AREA(UINT32 RegionType);
extern void NC_MPU_SET_REGION_SAFETY_ENGINE_TXT(UINT32 Region, UINT32 Attr);
extern void NC_MPU_SET_REGION_DEBUG_SECTION(UINT32 Region, UINT32 Attr);
extern void NC_MPU_SET_REGION_DEBUG_DATA_SECTION(UINT32 Region, UINT32 Attr);
#endif /* MPU_ASM_H_ */

/* End Of File */
