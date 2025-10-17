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

#ifndef APACHE_H_
#define APACHE_H_

/*
********************************************************************************
*               INCLUDE
********************************************************************************
*/

/* Default */
#include "Type.h"
#include "genconfig.h"
#include "ASM.h"


/* Common */
#include "Stdlib.h"
#include "boot_config.h"
#include "load_IMG.h"
#include "boot_eMMC.h"
#include "boot_SD.h"
#include "boot_sFlash.h"
#include "boot_UART.h"
#include "boot_USB.h"
/* safety */
/* #include "MPU.h" */
/* #include "safety_engine.h" */
/* #include "seq_monitor.h" */
/* 
#ifdef SECURE_BOOT_
#include "secure_boot.h"
#endif
 */

#ifdef BL2_
/* #include "GICv2.h"
#include "Drv_INTC.h" */
/* #include "Drv_DDRC.h" */
/* #include "Drv_Timer.h"
#ifdef LPDDR4_ENABLE_
#include "Drv_OMC.h"
#endif */
#endif


/*
********************************************************************************
*               DEFINES FOR APACHE
********************************************************************************
*/
#define E_SUCCESS                       (0U)
#define E_INIT_FAIL                     (1U)
#define E_TIME_OVER                     (2U)



/*
********************************************************************************
*               MEMORY MAP FOR APACHE
********************************************************************************
*/

/* Core Number */
#define E_CORE_0                        (0U)
/* #define E_CORE_1                        (1U) */
/* #define E_CORE_2                        (2U) */
/* #define E_CORE_3                        (3U) */
/* #define E_CORE_TYPE_MAX                 (4U) */


/* for UART Debug MSG Print */
#define DEBUG_APB_BASE                  (0x05040000)

/* Peripheral Memory Map */

#define APACHE_SCU_BASE                 (APACHE_A6_CPU_SCU_BASE_ADDR)
/*
#define APACHE_ICU_BASE                 (APACHE_A5_ICU_BASE_ADDR)
*/

/* Storage Memory Map */
/*
#define APACHE_DRAM_BASE                (0x80000000U)
#define APACHE_DRMA_ECC                 (0x5000A000U)
#define APACHE_RMAP_SIZE                (0x00100000U)
*/

/*
*******************************************************************************
*               DEFINITION FOR ARM ASM CODE SECTION
*******************************************************************************
*/

#ifdef IOMUX_ENABLE_
extern void NC_SetPinMux(void);
#endif

#endif  /* APACHE_H_ */

/* End Of File */

