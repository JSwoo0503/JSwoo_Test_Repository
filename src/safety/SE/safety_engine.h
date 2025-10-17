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

#ifndef SAFETY_ENGINE_H_
#define SAFETY_ENGINE_H_

#include "Drv_A6_SE_Register.h"
#include "Drv_A6_CPU_SCU_Register.h"


/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define SE_MODE_RESET                  (0U)
#define SE_MODE_START_UP               (1U)
#define SE_MODE_STD_OP                 (2U)
#define SE_MODE_POT                    (4U)
#define SE_MODE_SAFE                   (5U)


/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_A6_SE_REGISTER* const RegA6_SE;

/*
********************************************************************************
*               ENUMERATION
********************************************************************************
*/


/*
********************************************************************************
*               TYPEDEFS
********************************************************************************
*/

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
/* Debug Sequence Moniter Register */
#define DBG_VER_REG                    (RegA6_SE->SE__DBG00.Reg)                  /* 1. Version */
#define DBG_STP1_REG                   (RegA6_SE->SE__DBG01.Reg)                  /* 2. Sequence Monitor Step1 Information */
#define DBG_STP2_REG                   (RegA6_SE->SE__DBG02.Reg)                  /* 3. Sequence Monitor Step2 Information */
#define DBG_SSTP_SRC_QSRC_REG          (RegA6_SE->SE__DBG03.Reg)                  /* 4. SSTEP(16), RetryCnt(16) */
#define DBG_BL_RES_REG                 (RegA6_SE->SE__DBG04.Reg)                  /* 5. BL1(16)-(OK:F1),  BL2(16)-(OK:F2) */
#define DBG_STRAP_REG                  (RegA6_SE->SE__DBG05.Reg)                  /* 6. Strap Information */
#define DBG_OTP_1_REG                  (RegA6_SE->SE__DBG06.Reg)                  /* 7. OTP_1 Information */
#define DBG_FAULT_INFO_REG             (RegA6_SE->SE__DBG07.Reg)                  /* 8. Fault Information */

/* STATUS_SW_FAULT */
#define STATUS_SW_FAULT                (RegA6_SE->SE__SW__SAFETY.Bit.ERR)




/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern void NC_SE_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
extern void NC_SE_NotifyFailure(UINT32 Type);
extern void NC_SE_SetFaultInfo(UINT32 Type);
#endif  /* SAFETY_ENGINE_H_ */


/* End Of File */
