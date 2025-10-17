/**
********************************************************************************
*
*  Copyright (C) 2020 NEXTCHIP Inc. All rights reserved.
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

#ifndef SCU_DRV_H_
#define SCU_DRV_H_

#include "Drv_A6_SYS_SCU_Register.h"
#include "Drv_A6_CPU_SCU_Register.h"
#include "Drv_A6_HSP_SCU_Register.h"
#include "Drv_A6_ICU_Register.h"
#include "Drv_A6_SE_Register.h"
#include "Drv_A6_PMU_Register.h"


/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

#define rSCU_RUN_TICK_CNT_1                 (0x01U)
#define rSCU_RUN_TICK_CNT_2                 (0x10U)
#define rSCU_RST_TICK_CNT_1                 (0x02U)
#define rSCU_RST_TICK_CNT_2                 (0x20U)

#define bSCU_BOOT_STRAP_CSN0                (0U)
#define bSCU_BOOT_STRAP_CSN1                (1U)
#define bSCU_BOOT_STRAP_OSC                 (0U)
#define bSCU_BOOT_STRAP_MIN                 (1U)
#define bSCU_BOOT_STRAP_MID                 (2U)
#define bSCU_BOOT_STRAP_MAX                 (3U)

#define USB_PWR_ON_TIMEOUT_MS               (5U)

/* Debug Sequence Moniter Register */
#define DBG_OTP_2_REG                  (RegA6_CPU_SCU->CPU_SCU_DEBUG14.Reg)       /* 9. OTP_2 Information */
#define DBG_BOOT_SUMMARY_REG           (RegA6_CPU_SCU->CPU_SCU_DEBUG15.Reg)
#define DBG_BOOT_COMPLETE_TIME         (RegA6_CPU_SCU->CPU_SCU_DEBUG18.Reg)

/* STATUS_SW_FAULT */
#define gSPI_RX_DELAY                  (RegA6_CPU_SCU->CPU_SCU_DEBUG11.Reg)
#define gSPI_CLK_POL_PH                (RegA6_CPU_SCU->CPU_SCU_DEBUG12.Reg)       /* from OTP_2 config */
#define TOGGLE_STATE                   (RegA6_CPU_SCU->CPU_SCU_DEBUG13.Reg)
#define gSPI_CLK_INV                   (RegA6_CPU_SCU->CPU_SCU_DEBUG17.Reg)       /* from STRAP config */

typedef struct
{
    UINT32      mOSC;
    UINT32      mPLLConfig;

    /* PLL Clock */
    UINT32      mSYS_PLL;
    UINT32      mCPU_PLL;
    UINT32      mNPU_PLL;
    UINT32      mCOM_PLL;
} tSCU_CLK_PLL;

typedef struct
{
    UINT32      P;
    UINT32      M;
    UINT32      S;
    UINT32      K;
} tSCU_PLL_PARAM;

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_A6_CPU_SCU_REGISTER* const RegA6_CPU_SCU;
extern volatile DRV_A6_SYS_SCU_REGISTER* const RegA6_SYS_SCU;
extern volatile DRV_A6_HSP_SCU_REGISTER* const RegA6_HSP_SCU;
#if defined(USB_DLOAD_)
extern volatile DRV_A6_USB_SCU_REGISTER* const RegA6_USB_SCU;
/* extern volatile DRV_A6_PMU_REGISTER* const RegA6_PMU_SCU; */ /* rcma-2.0.0-1514 only reference by function ... */
#endif

/*
********************************************************************************
*               MICRO FUNCTION
********************************************************************************
*/

/* PRQA S 0303 ++ */
#define nc_wait_tick(ticks)     (NC_SCU_WaitTick(ticks))

#define SYS_APB_CLK             (*(volatile UINT32 *)(APACHE_A6_SYS_SCU_BASE_ADDR+0xF004U))     /* DEBUG1 */
#define SYS_TIMEOUT_CNT         (*(volatile UINT64 *)(APACHE_A6_SYS_SCU_BASE_ADDR+0xF008U))     /* DEBUG2 ~ 3 */

#define nc_delay(s)             (nc_wait_tick((SYS_APB_CLK/SEC ) * s))
#define nc_mdelay(ms)           (nc_wait_tick(((UINT64)(SYS_APB_CLK)/(MSEC)) * (ms)))
#define nc_udelay(us)           (nc_wait_tick((UINT64)(SYS_APB_CLK/USEC) * (us)))
#define nc_get_tick(cls)        (NC_SCU_GetTick(cls))
#define nc_get_msec(cls)        (NC_SCU_GetMsec(cls))
/* PRQA S 0303 -- */

#define CLK_DEF_DIV8                             (8U)

#ifdef SIM_ONLY_ /* TODO : FIXME */
#define BL_SIM_APB_CLOCK                    (60U*MHZ)
#define BL_SIM_SPI_CLOCK                    (30U*MHZ)
#define BL_SIM_QSPI_CLOCK                   (30U*MHZ)
#define BL_SIM_UART_CLOCK                   (60U*MHZ)
#define BL_SIM_SD_CLOCK                     (60U*MHZ)
#define BL_SIM_EMMC_CLOCK                   (60U*MHZ)
#endif
/* PRQA S 3332 ++ */
#ifdef FPGA_MODE_ /* For FPGA */
/* FPGA Speed (2022/07/22) */
#define BL_FPGA_APB_CLOCK                   ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#define BL_FPGA_SPI_CLOCK                   ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#define BL_FPGA_QSPI_CLOCK                  ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#define BL_FPGA_UART_CLOCK                  ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#define BL_FPGA_SD_CLOCK                    ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#define BL_FPGA_EMMC_CLOCK                  ((UINT32)FPGA_DB_CLOCK*(UINT32)KHZ)
#endif /* FPGA_MODE_ */
/* PRQA S 3332 -- */


/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/

extern void NC_SYS_SCU_TZPROT_EN(void);
extern void NC_AXI2APB_TZPC_EN(void);
extern UINT64 NC_SCU_GetMsec(BOOL Cls);
extern BOOL   NC_SCU_mTimeOut(UINT64 mSec);
extern UINT64 NC_SCU_GetTick(BOOL Cls);
extern void   NC_SCU_WaitTick(UINT64 Ticks);
extern void   NC_SCU_StrapConfig(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
extern void   NC_SCU_Initialize(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
extern void NC_InitReset(const tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
#ifdef R5_UART_ENABLE_
extern void NC_SCU_PrintPLL(const tBOOT_STRAP *ptStrap, const tBOOT_CLK *ptClock);
#endif /* R5_UART_ENABLE */

#endif  /* SCU_DRV_H_ */

/* End Of File */
