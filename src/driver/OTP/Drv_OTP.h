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

#ifndef DRV_OTP_H_
#define DRV_OTP_H_

#include "Drv_A6_OTP2K_Register.h"
#include "Drv_A6_OTP32K_Register.h"
#include "Drv_A6_ANALOG_Register.h"

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
#ifdef OTP_ENABLE_
#if defined(FPGA_MODE_) && defined(FPGA_TEST_OTP_ENABLE_)
extern volatile DRV_A6_OTP2K_REGISTER* const RegA6_OTP;
extern volatile DRV_A6_OTP32K_REGISTER* const RegA6_OTP32K;
#elif !defined(FPGA_MODE_)
extern volatile DRV_A6_OTP2K_REGISTER* const RegA6_OTP;
/* extern volatile DRV_A6_OTP32K_REGISTER* const RegA6_OTP32K; */
/* extern volatile DRV_A6_ANALOG_REGISTER* const RegA6_ANALOG; */
#endif
#endif

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/



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

extern void NC_OTP_Config(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
#ifndef OTP_ENABLE_
extern void NC_OTP_Config_WhileDisabled(tBOOT_STATUS *ptBootStatus);
#endif
extern UINT32 NC_Get_Firmware_Backup_Offset(void);
extern UINT32 NC_GetDBG_OTP_Config(UINT32 Index);

#endif /* DRV_OTP_H_ */


/* End Of File */

