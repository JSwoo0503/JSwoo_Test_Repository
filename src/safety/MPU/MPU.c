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


/*
********************************************************************************
*               INCLUDES
********************************************************************************
*/
#include "Apache.h"
#include "MPU.h"
#include "MPU_ASM.h"
#include "Drv_SCU.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

#define MPU_NESTED                     (RegA6_CPU_SCU->CPU_SCU_DEBUG16.Reg)
#define MPU_SEL_CTRL_NO                (0xBU)
#define MPU_SEL_CTRL_ALL               (0x30BU)

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/



/* PRQA S 3335 ++ */ /* startup.S function */
/**
* @desc
    Set MPU region.
* @param    UINT32  Region  MPU region
* @param    UINT32  Attr    MPU attribute
* @return   void
* @design
    Set MPU region
*/
static void NC_MPU_SetRegion(UINT32 Region, UINT32 Attr, UINT32 RegionType)
{
    if(RegionType == MPU_REGION_TYPE_SAFETY_ENGINE_TXT) {
        NC_MPU_SET_REGION_SAFETY_ENGINE_TXT(Region, Attr);
    } else if(RegionType == MPU_REGION_TYPE_DEBUG_SECTION) {
        NC_MPU_SET_REGION_DEBUG_SECTION(Region, Attr);
    } else if(RegionType == MPU_REGION_TYPE_DEBUG_DATA_SECTION) {
        NC_MPU_SET_REGION_DEBUG_DATA_SECTION(Region, Attr);
    } else {
        /* No Operation */
    }
}



/**
* @desc
    MPU enter saftey gate.
* @param    void
* @return   void
* @design
    Get MPU region
    Set MPU safety region
*/
void NC_MPU_EnterSafetyGate(void)
{
    UINT32 Region;

    MPU_NESTED += 1U;
    Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_SAFETY_ENGINE_TXT);
    NC_MPU_SetRegion(Region, MPU_SEL_CTRL_ALL, MPU_REGION_TYPE_SAFETY_ENGINE_TXT);
}



/**
* @desc
    MPU leave safety gate.
* @param    void
* @return   void
* @design
    Get MPU region
    Set MPU leave safety region
*/
void NC_MPU_LeaveSafetyGate(void)
{
    UINT32 Region;

    if(MPU_NESTED > 0U)
    {
        MPU_NESTED -= 1U;
    }

    if(MPU_NESTED == 0U)
    {
        Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_SAFETY_ENGINE_TXT);
        NC_MPU_SetRegion(Region, MPU_SEL_CTRL_NO, MPU_REGION_TYPE_SAFETY_ENGINE_TXT);
    }
}



/**
* @desc
    MPU Enable debug region.
* @param    void
* @return   void
* @design
    Set Debug Region.
*/
void NC_MPU_EnableDebugRegion(void)
{
    UINT32 Region;

    /* MPU_NESTED += 1U; */ /* TODO : Whether to write status to CPU_SCU_DEBUG16 register or not? */
    Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_DEBUG_SECTION);
    NC_MPU_SetRegion(Region, MPU_SEL_CTRL_ALL, MPU_REGION_TYPE_DEBUG_SECTION);
    Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_DEBUG_DATA_SECTION);
    NC_MPU_SetRegion(Region, MPU_SEL_CTRL_ALL, MPU_REGION_TYPE_DEBUG_DATA_SECTION);
}

#if 0
/* Unused function */
void NC_MPU_DisableDebugRegion(void)
{
    UINT32 Region;

    /* TODO : Whether to write status to CPU_SCU_DEBUG16 register or not? */
    Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_DEBUG_SECTION);
    NC_MPU_SetRegion(Region, MPU_SEL_CTRL_NO, MPU_REGION_TYPE_DEBUG_SECTION);
    Region = (UINT32)NC_MPU_GET_REGION_AREA(MPU_REGION_TYPE_DEBUG_DATA_SECTION);
    NC_MPU_SetRegion(Region, MPU_SEL_CTRL_NO, MPU_REGION_TYPE_DEBUG_DATA_SECTION);
}
#endif

/* PRQA S 3335 -- */

 
/* End Of File */
