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

#ifndef COMMON_H_
#define COMMON_H_

#if defined(DEBUG_ENABLE_)
#include "Drv_Uart.h"
#if defined(USB_DLOAD_)
#include "Drv_USB.h"
#endif
#endif

/* For VectorCast. Vectorcast does not recognize the UINT format. */
#include "Type.h"

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

/************************/
/* SW Fault (Bit shift) */
/************************/
#define FAULT_OTP_TOV                  ((UINT8)1U)    /* OTP Read Time Over */
#define FAULT_NR_RHDR                  ((UINT8)2U)    /* Normal Header Read Error */
#define FAULT_NR_IHDR                  ((UINT8)3U)    /* Normal Invalid Header Error */
#define FAULT_NR_SF                    ((UINT8)4U)    /* sFlash Normal Image Loading Error */
#define FAULT_NR_EMMC                  ((UINT8)5U)    /* EMMC   Normal Image Loading Error */
#define FAULT_NR_SD                    ((UINT8)6U)    /* SD     Normal Image Loading Error */
#define FAULT_UART_DL                  ((UINT8)7U)    /* UART   Normal Image Loading Error */
#define FAULT_UART_CS                  ((UINT8)8U)    /* UART   Normal Image Checksum Error */
#define FAULT_USB                      ((UINT8)9U)    /* USB    Normal Image Loading Error */
#define FAULT_BK_RHDR                  ((UINT8)10U)   /* Backup Header Read Error */
#define FAULT_BK_IHDR                  ((UINT8)11U)   /* Backup Invalid Header Error */
#define FAULT_BK_SF                    ((UINT8)12U)   /* sFlash Backup Image Loading Error */
#define FAULT_BK_EMMC                  ((UINT8)13U)   /* EMMC   Backup Image Loading Error */
#define FAULT_BK_SD                    ((UINT8)14U)   /* SD     Backup Image Loading Error */
#define FAULT_SB_INIT                  ((UINT8)15U)   /* Secure Boot Init Error */
#define FAULT_SB_RUN                   ((UINT8)16U)   /* Secure Boot Run & Decryption Error */
#define FAULT_SB_TOV_1                 ((UINT8)17U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_2                 ((UINT8)18U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_3                 ((UINT8)19U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_4                 ((UINT8)20U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_5                 ((UINT8)21U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_6                 ((UINT8)22U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_7                 ((UINT8)23U)   /* Secure Boot Time Over Error */
#define FAULT_SB_TOV_8                 ((UINT8)24U)   /* Secure Boot Time Over Error */
#define FAULT_SM                       ((UINT8)25U)   /* Booting Sequence Monitor Error */

#define FAULT_BOOT_FAIL                ((UINT8)28U)   /* Boot Fail */
#define FAULT_ABORT                    ((UINT8)29U)   /* Abort */
#define FAULT_UNDEF                    ((UINT8)30U)   /* Undefined */
#define FAULT_PREF                     ((UINT8)31U)   /* Prefetch */

#define FAULT_SW_MAX                   ((UINT8)32U)   /* Limit */



#define SUM_BIT_BOOT_MEDIA             (0U)
#define SUM_BIT_USED_IMG_SFLASH_ID     (8U)
#define SUM_BIT_USED_IMG_EMMC_ID       (9U)
#define SUM_BIT_IS_FAIL_READ_IMG       (10U)
#define SUM_BIT_IS_FAIL_CRC_IMG        (11U)
#define SUM_BIT_IS_FAIL_SPI_INIT       (12U)
#define SUM_BIT_IS_FAIL_QSPI_INIT      (13U)
#define SUM_BIT_IS_SECURE_BOOT         (14U)
#define SUM_BIT_SF_CTRL_MODE           (16U)
#define SUM_BIT_EMMC_CTRL_MODE         (20U)
#define SUM_BIT_SDC_CTRL_MODE          (21U)
#define SUM_BIT_SECURE_KEY_STORE       (22U)
#define SUM_BIT_SECURE_KEY_TYPE        (24U)

#define SET_BITWISE(R, S, D)           ((R) |= ((D) << (S)))
#define CLEAR_BITWISE(R, S, D)         ((R) &= ~((D) << (S)))
#define CHECK_BITWISE(S, V)            (((((UINT32)0x1 << (S)) & (V)) != FALSE) ? TRUE : FALSE)

#define CLEAR(R, V)                     ((R) &= ~(V))

typedef struct
{
    UINT32      mSPSR;
    UINT32      mSP;
    UINT32      mLR;
    UINT32      mReg[13];
    UINT32      mPC;
} tARM_FAULT;

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern void   NC_Gpio_toggle(void);
extern void   NC_Memcpy_u08(const UINT8 *pSrc, UINT8 *pDes, const UINT32 Length);
extern void   NC_Memset_u08(void *p, UINT8 c, INT32 count);
#if 0
extern void   NC_Memset_u32(UINT32* addr, UINT32 value32, UINT32 num_bytes);
extern void   NC_Memcopy_U32(UINT32* dst, UINT32* src, UINT32 num_bytes);
extern INT32 NC_Strlen(const UINT8 *str) ;
#endif
extern INT32  NC_Compare(const UINT8 *pSrc, const UINT8* pDes, UINT32 Length);
extern UINT32 NC_Checksum(UINT32 *pSrc, UINT32 Length);
extern void   NC_SetDBG_STRAP_Config(UINT32 BootStrap);
extern void   NC_Abort_Handler(tARM_FAULT *pFault);
extern void   NC_Undefined_Handler(tARM_FAULT *pFault);
extern void   NC_Prefetch_Handler(tARM_FAULT *pFault);

#if defined(DEBUG_ENABLE_) || defined(SIM_DBGMSG_ON_)
#define DEBUGMSG(zone, fmt, ...)  (ncDrv_UART_Printf(zone, fmt, __VA_ARGS__))
#else
/* PRQA S 1030 ++ */
#define DEBUGMSG(zone, fmt, ...)  do{} while(0)
/* PRQA S 1030 -- */
#endif

#if defined(DEBUG_ENABLE_)
    #define DBGUSB(zone, fmt, ...) ((void)0) /* DEBUGMSG(zone, fmt, __VA_ARGS__) */
#else
    /* PRQA S 1030 ++ */
    #define DBGUSB(zone, fmt, ...)  ((void)0)
    /* PRQA S 1030 -- */
#endif

#endif  /* COMMON_H_ */

/* End Of File */
