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

#ifndef DRV_UART_H_
#define DRV_UART_H_

#include "Drv_A6_UART_Register.h"

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
#define UART_LCR_DLAB_ENABLE        (0x1UL << 7) /* Divisor latch access bit */
#define NC_UART_LCR_STOP_2          (2U)        /* Number of stop bits */
#define NC_UART_LCR_PEN_3           (3U)	    /* Parity Enable */

#define UART_LSR_THRE_ENABLE        (0x1UL << 5) /* Transmit-hold-register empty */
#define UART_LSR_TEMT_ENABLE        (0x1UL << 6) /* Transmitter empty */
#define UART_LSR_DR_READY           (0x1U) /* data ready */

#define UART_FCR_FIFOE_ENABLE       (0x1U) /* FIFO Enable*/
#define UART_FCR_RFIFOR_RESET       (0x1U << 1) /* Clear the RCVR FIFO */
#define UART_FCR_XFIFOR_RESET       (0x1U << 2) /* Clear the XMIT FIFO */
#define UART_FCR_TET_2CHAR_FIFO     (0x1U << 4) /* TX Empty Trigger */

#define UART_USR_RFF                (0x1U << 4) /* Receive FIFO FUll */
#define UART_USR_RFNE               (0x1U << 3) /* Receive FIFO Not Empty - 0:Empty, 1:Not Empty */

#define UART_IER_RESET              (0x0U)


/*
 *------------------------------------------------------------------------------
 * ETC
 *------------------------------------------------------------------------------
 **/

#define UT_BAUDRATE_300             (300UL)
#define UT_BAUDRATE_600             (600UL)
#define UT_BAUDRATE_1200            (1200UL)
#define UT_BAUDRATE_2400            (2400UL)
#define UT_BAUDRATE_4800            (4800UL)
#define UT_BAUDRATE_9600            (9600UL)
#define UT_BAUDRATE_19200           (19200UL)
#define UT_BAUDRATE_38400           (38400UL)
#define UT_BAUDRATE_57600           (57600UL)
#define UT_BAUDRATE_115200          (115200UL)
#define UT_BAUDRATE_230400          (230400UL)
#define UT_BAUDRATE_460800          (460800UL)
#define UT_BAUDRATE_921600          (921600UL)

#define UT_DATA_8BIT                (3U)


#define MSGERR                      (1U)         /* Error message enable */
#define MSGWARN                     (1UL<<1)     /* Warning message enable */
#define MSGINFO                     (1UL<<2)     /* Information message enable */
#define MSGDBG                      (1UL<<3)

#define NC_UART_SET_BAUDRATE_115200 (0U)
#define NC_UART_SET_BAUDRATE_230400 (1U)
#define NC_UART_SET_BAUDRATE_57600  (2U)
#define NC_UART_SET_BAUDRATE_19200  (3U)

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_UART_REGISTER* const RegA6_UART;

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/

#ifdef DEBUG_ENABLE_
extern INT8  NC_UART_GetChar(void);
extern void  NC_UART_PutStr(const CHAR *Str);
#endif
extern void  NC_UART_PutChar(CHAR Data);
extern void  NC_UART_Initialize(UINT32 BaudRate, UINT32 RefClk);
extern NC_ERROR NC_UART_GetCharN(CHAR *c);

#if defined(DEBUG_ENABLE_) || defined(SIM_DBGMSG_ON_)
extern void  ncDrv_UART_Printf(UINT32 DebugZone, const CHAR *fmt, ...);
#endif

#endif  /* DRV_UART_H_ */


/* End Of File */

