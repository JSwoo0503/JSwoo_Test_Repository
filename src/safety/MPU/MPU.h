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

#ifndef MPU_H_
#define MPU_H_


/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
/* debug라는 단어가 들어간 섹션은 빌드가 안됨 */
#define DEBUG_SECTION  ".dbg_section" /* the value of this macro must match the contents of the .scat DEBUG_SECTION file. */
#define DEBUG_FUNC_ATTR __attribute__((section (DEBUG_SECTION), used))

#define DEBUG_DATA_SECTION  ".dbg_data_section"
#define DEBUG_DATA_ATTR(align) __attribute__((aligned(align), section(DEBUG_DATA_SECTION), used))

/* data section 관련 */
/* #define SECTION2_NAME ".test2_section" */
/* #define TEST2_SECTIN              __attribute__((section (SECTION2_NAME), used)) */
/* #define ALIGN_TEST2_SECTION(align) __attribute__((aligned(align), section(SECTION2_NAME), used)) */


/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern void NC_MPU_EnterSafetyGate(void);
extern void NC_MPU_LeaveSafetyGate(void);

extern void NC_MPU_EnableDebugRegion(void);
/* extern void NC_MPU_DisableDebugRegion(void); */ /* Unused function */

#endif  /* MPU_H_ */

/* End Of File */
