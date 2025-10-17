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
*               INCLUDE
********************************************************************************
*/

#include "Apache.h"
#include "Drv_Uart.h"
/*
 * ARM Complier v6.6 Not Support
 *  -. I don't Know..
 *  -. Disable Simple va_list
 **/
/* #define USED_SIMPLE_VALIST_ */

#ifdef DEBUG_ENABLE_
#ifndef USED_SIMPLE_VALIST_
#include <stdarg.h>
#endif
#endif

/*
 * MISRA C 2012 - Rule 21.6
 **/
#define USED_SIMPLE_PRINTF_

#ifndef USED_SIMPLE_PRINTF_
#include <stdio.h>
#endif








 
/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
#ifdef DEBUG_ENABLE_

#ifdef USED_SIMPLE_PRINTF_
#define PAD_RIGHT                   (1U)
#define PAD_ZERO                    (2U)

/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN               (12U)
#endif


#ifdef USED_SIMPLE_VALIST_
typedef char* va_list;

#define INT_SIZEOF(n)               ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v)             (ap = (va_list) &v + INT_SIZEOF(v))
#define va_arg(ap, t)               (*(t *)((ap += INT_SIZEOF(t)) - INT_SIZEOF(t)))
#endif


#define STR_COLOR_RED_ON            "\033""[1;31m"
#define STR_COLOR_YELLOW_ON         "\033""[1;33m"
#define STR_COLOR_OFF               "\033""[0m"

#endif




/* PRQA S 0306++ */
#ifdef R5_UART_ENABLE_
volatile DRV_UART_REGISTER* const RegA6_UART = (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR2;
#else
volatile DRV_UART_REGISTER* const RegA6_UART = (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR1;
#endif
/* PRQA S 0306-- */

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/

#ifdef USED_SIMPLE_PRINTF_

#ifdef DEBUG_ENABLE_
/**
* @desc
	This function transfers 1 byte of data through UART.
* @param   CHAR c   1 byte transfer data
* @return  void
* @design
    IF  The argument is a '\n' value.   THEN
        Sending newline data.
    ENDIF
    Transfers 1 byte of data through UART.
*/
static void ncLib_DEBUG_Printc(CHAR c)
{
    if( c == (CHAR)'\n' )
    {
      NC_UART_PutChar((CHAR)'\r');
    }
    NC_UART_PutChar((CHAR)c);
}



/**
* @desc
	Outputs the character string to the debug UART.
* @param   CHAR*  string     Character string to print
* @param   UINT32 width      Width of number characters.
* @param   UINT32 pad        PAD for debug message print
* @return  void
* @design
    IF  Width of number characters value is greater than 0  THEN
        Calculation length and check pad character.
    ENDIF
    Output string characters and pad characters to the debug uart port.
*/
static void ncLib_DEBUG_Prints(const CHAR *string, UINT32 width, UINT32 pad)
{
    UINT32 i;
    CHAR padchar = (CHAR)' ';
    UINT32 nWidth = width;

    if (nWidth > 0U)
    {
        UINT32 len = 0;
        const CHAR *ptr;

        for (ptr = string; (*ptr != (CHAR)0); ++ptr)
        {
            ++len;
        }

        if (len >= nWidth)
        {
            nWidth = 0;
        }
        else
        {
            nWidth -= len;
        }

        if( (pad & PAD_ZERO) == PAD_ZERO)
        {
            padchar = (CHAR)'0';
        }
    }


    if ((pad & PAD_RIGHT) != PAD_RIGHT)
    {
        for ( ; nWidth > 0U; --nWidth)
        {
            ncLib_DEBUG_Printc (padchar);
        }
    }

    for (i=0; (string[i] != (CHAR)0); i++)
    {
        ncLib_DEBUG_Printc (string[i]);
    }

    for ( ; nWidth > 0U; --nWidth)
    {
        ncLib_DEBUG_Printc (padchar);
    }
}



/**
* @desc
	Outputs Decimal & Hexadecimal strings to the debug UART.
* @param   INT32  i          characters to output
* @param   UINT32 b          Decimal or Hexadecimal flag_1.
* @param   BOOL   sg         Decimal or Hexadecimal flag_2.
* @param   UINT32 width      Width of number characters.
* @param   UINT32 pad        PAD for debug message print
* @param   CHAR   letbase    base ascii code value
* @return  void
* @design
    IF  The input character is '0'  THEN
        Output null character('\0') to the debug port.
    ELSE
        Calculation decimal & hexadecimal string.
        Output string to the debug uart port.
    ENDIF
*/
static void ncLib_DEBUG_Printi(INT32 i, UINT32 b, BOOL sg, UINT32 width, UINT32 pad, CHAR letbase)
{
    CHAR print_buf[PRINT_BUF_LEN];
    CHAR *s;
    CHAR t;
    BOOL  neg = FALSE;
    UINT32 u = (UINT32)i;
    UINT32 nWidth = width;
    UINT32 Temp;


    if(i == 0)
    {
        print_buf[0] = (CHAR)'0';
        print_buf[1] = (CHAR)'\0';

        ncLib_DEBUG_Prints(print_buf, nWidth, pad);
    }
    else
    {
        if( (sg == TRUE) && (b == 10U) && (i < 0))
        {
            neg = TRUE;
            u = (UINT32)-i;
        }

        s = &print_buf[PRINT_BUF_LEN-1U];
        *s = (CHAR)'\0';

        while(u != 0U)
        {
            Temp = u % b;
            t = (CHAR)Temp;
            if( t >= (CHAR)10 )
            {
                t += (letbase - (CHAR)'0' - 10);
            }

            --s;
            *s = t + 0x30; /* (CHAR)'0'*/
            u /= b;
        }

        if(neg == TRUE)
        {
            if( (width != 0U) && ((pad & PAD_ZERO) == PAD_ZERO) )
            {
                ncLib_DEBUG_Printc ((CHAR)'-');
                --nWidth;
            }
            else
            {
                --s;
                *s = (CHAR)'-';
            }
        }

        ncLib_DEBUG_Prints (s, nWidth, pad);
    }
}



/**
* @desc
	String Outputs a string to the debug UART.
* @param   const CHAR* fmt   String to output
* @param   va_list ap        va_list parameter
* @return  void
* @design
    DO  WHILE  String parameter is not 0
        IF  String parameter is '%'  THEN
            Check parameter is decimal or hexadecimal or string.
            Output decimal or hexadecimal or string to the debug port.
        ELSE
            Output string to the debug port.
        ENDIF
    LOOP
*/
static void ncLib_DEBUG_Printf(const CHAR *fmt, va_list ap)
{
    const CHAR *format = (const CHAR *)fmt;
    UINT32 width;
    UINT32 pad;
    CHAR scr[2];
    INT32 arg;

    while(*format != (CHAR)0)
    {
        if(*format == (CHAR)'%')
        {
            ++format;
            width = 0;
            pad = 0;
            if(*format == (CHAR)'\0')
            {
                break;
            }

            if( *format == (CHAR)'%' )
            {
                ncLib_DEBUG_Printc (*format);
            }
            else
            {
                if( *format == (CHAR)'-' )
                {
                    ++format;
                    pad = PAD_RIGHT;
                }

                while( *format == (CHAR)'0' )
                {
                    ++format;
                    pad |= PAD_ZERO;
                }

                for( ; ((*format >= (CHAR)'0') && (*format <= (CHAR)'9')); ++format)
                {
                    width *= 10U;
                    scr[0] = (CHAR)(*format - (CHAR)'0');
                    width += (UINT32)scr[0];
                }

                if( *format == (CHAR)'s' )
                {
                    const CHAR *s = (CHAR *)va_arg(ap, int);
                    ncLib_DEBUG_Prints ((s != (CHAR*)0)?s:"(null)", width, pad);
                }
                else if( *format == (CHAR)'d' )
                {
                    arg = va_arg(ap, int);
                    ncLib_DEBUG_Printi (arg, 10U, TRUE, width, pad, (CHAR)'a');
                }
                else if( *format == (CHAR)'x' )
                {
                    arg = va_arg(ap, int);
                    ncLib_DEBUG_Printi (arg, 16U, FALSE, width, pad, (CHAR)'a');
                }
                else if( *format == (CHAR)'X' )
                {
                    arg = va_arg(ap, int);
                    ncLib_DEBUG_Printi (arg, 16U, FALSE, width, pad, (CHAR)'A');
                }
                else if( *format == (CHAR)'u' )
                {
                    arg = va_arg(ap, int);
                    ncLib_DEBUG_Printi (arg, 10U, FALSE, width, pad, (CHAR)'a');
                }
                else if( *format == (CHAR)'c' )
                {
                    /* char are converted to int then pushed on the stack */
                    scr[0] = (CHAR)va_arg(ap, int);
                    scr[1] = (CHAR)'\0';
                    ncLib_DEBUG_Prints (scr, width, pad);
                }
                else
                {
                   /* just ignore.. either not supported or not correctly */
                }
            }
        }
        else
        {
            ncLib_DEBUG_Printc (*format);
        }
        ++format;
    }
}
#endif /* USED_SIMPLE_PRINTF_ */
#endif



#ifdef DEBUG_ENABLE_
/**
* @desc
    Print data on UART
* @param    UINT32      DebugZone       Debug message area
* @param    CHAR*   fmt         Print data
* @param    variable argument   Print data
* @return   void
* @design
    IF Debug area is error THEN
        Set string color is red
    ENDIF
    IF Debug area is warnning THEN
        Set string color is yellow
    ENDIF
*/
void ncDrv_UART_Printf(UINT32 DebugZone, const CHAR *fmt, ...)
{
    va_list ap;
#ifndef USED_SIMPLE_PRINTF_
    CHAR Buff[512];
#endif

    if((DebugZone&MSGERR) == MSGERR)
    {
        NC_UART_PutStr(STR_COLOR_RED_ON);
    }
    if((DebugZone&MSGWARN) == MSGWARN)
    {
        NC_UART_PutStr(STR_COLOR_YELLOW_ON);
    }


    va_start(ap, fmt);
#ifdef USED_SIMPLE_PRINTF_
    /* www.menie.org/georges/embedded/small_printf_source_code.html */
    ncLib_DEBUG_Printf(fmt, ap);
#else
    (void)vsnprintf((CHAR*)Buff, 512, (const CHAR*)fmt, ap);
    NC_UART_PutStr(Buff);
#endif
    /* va_end(ap); */

    if(((DebugZone&MSGERR) == MSGERR) || ((DebugZone&MSGWARN) == MSGWARN))
    {
        NC_UART_PutStr(STR_COLOR_OFF);
    }
}



/**
* @desc
    Get character from UART
* @param    void
* @return   INT8    character
* @design
    IF  Data is ready   THEN
        Ret = Get the character from UART
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
INT8 NC_UART_GetChar(void)
{
    INT8 Ret;

    if((RegA6_UART->UART_LINE_STAT.Reg & UART_LSR_DR_READY ) == UART_LSR_DR_READY )
    {
        Ret = (INT8)RegA6_UART->UART_RBR_DLL_THR.Reg;
    }
    else
    {
        Ret = NC_FAILURE;
    }

    return Ret;
}
#endif /* DEBUG_ENABLE_ */



/**
* @desc
    This function uses UART communication interface to receive 1 byte data.
* @param    CHAR*   c   Data Buffer
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @design
    Ret = NC_SUCCESS
    IF Is the received data exists THEN
        pointer argument value = Read UART Data Register
    ELSE
        Ret = NC_FAILURE
    ENDIF
    Return Ret
*/
NC_ERROR NC_UART_GetCharN(CHAR *c)
{
    NC_ERROR Ret = NC_SUCCESS;

    if((RegA6_UART->UART_LINE_STAT.Reg & UART_LSR_DR_READY ) == UART_LSR_DR_READY )
    {
        *c = (CHAR)RegA6_UART->UART_RBR_DLL_THR.Bit.RBR_DLL_THR;
    }
    else
    {
        Ret = NC_FAILURE;
    }

    return Ret;
}



/**
* @desc
    Get UART line state value.
* @param   void
* @return  UINT32   state value
* @design
    Get UART line state value.
*/
static UINT32 NC_UART_GetLineStat(void)
{
    return RegA6_UART->UART_LINE_STAT.Reg;
}



/**
* @desc
    This function transfers 1 byte of data through UART communication interface.
* @param    CHAR    Data    Transfer data
* @return   void
* @design
    DO  WHILE   Transmit-hold-register is not empty.
        Read UART status register.
    LOOP

    Put Character Data to UART.

    DO  WHILE   Transmitter and Transmit-hold-register in not emptied.
        Read UART status register.
    LOOP
*/
void NC_UART_PutChar(CHAR Data)
{
    volatile UINT32 Reg;

    /* WAIT_FOR_THRE */
    while(1)
    {
        /* Reg = RegA6_UART->UART_LINE_STAT.Reg; */
        Reg = NC_UART_GetLineStat();

        if((Reg & UART_LSR_THRE_ENABLE) == UART_LSR_THRE_ENABLE )
        {
            break;
        }
    }

    /* Data Write */
    RegA6_UART->UART_RBR_DLL_THR.Reg = (UINT8)Data;

    /* WAIT_FOR_XMITR */
    while(1)
    {
        /* Reg = RegA6_UART->UART_LINE_STAT.Reg; */
        Reg = NC_UART_GetLineStat();
        if((Reg & (UART_LSR_TEMT_ENABLE|UART_LSR_THRE_ENABLE)) == (UART_LSR_TEMT_ENABLE | UART_LSR_THRE_ENABLE))
        {
            break;
        }
    }
}



#ifdef DEBUG_ENABLE_
/**
* @desc
    This function transfers string data through UART communication interface.
* @param   CHAR*    Str     String Data
* @return  void
* @design
    DO WHILE    String data is not empty.
         Put String Data to UART.
    LOOP
*/
void NC_UART_PutStr(const CHAR *Str)
{
    CHAR prev = (CHAR)'\0';
    UINT32 i = 0;

    while(Str[i] != (CHAR)0)
    {
        if((Str[i] == (CHAR)'\n') && (prev != (CHAR)'\r'))
        {
            NC_UART_PutChar((CHAR)'\r');
        }

        NC_UART_PutChar((CHAR)Str[i]);

        prev = Str[i];
        i++;
    }
}
#endif



/**
* @desc
    This function performs UART initialization.
* @param    UINT32  BaudRate    UART Baudrate.
* @param    UINT32  RefClk      UART Reference clock.
* @return   void
* @design
    IF  BaudRate == 230400  THEN
        Increase the divider value by 1.
    ENDIF
    Set the initial value in UART Register.
*/
void NC_UART_Initialize(UINT32 BaudRate, UINT32 RefClk)
{
    volatile UINT32 DIV;

    /* Reset receiver and transmiter */
    RegA6_UART->UART_FCR_IIR.Reg    = UART_FCR_FIFOE_ENABLE
                                    | UART_FCR_RFIFOR_RESET
                                    | UART_FCR_XFIFOR_RESET
                                    | UART_FCR_TET_2CHAR_FIFO;

    /* Disable all interrupts */
    RegA6_UART->UART_DLH_IER.Reg = UART_IER_RESET;

    /* Set 8 bit char, 1 stop bit, no parity */
    RegA6_UART->UART_LINE_CTRL.Reg = UT_DATA_8BIT;

    /* Set baud rate */
    DIV = RefClk/(16U * BaudRate);
    if(UT_BAUDRATE_230400 == BaudRate)
    {
        DIV += 1U;
    }

    /* open divisor latch */
    RegA6_UART->UART_LINE_CTRL.Reg |= UART_LCR_DLAB_ENABLE;

    /* set divisor latch */
    RegA6_UART->UART_RBR_DLL_THR.Reg = DIV & 0xffU;
    RegA6_UART->UART_DLH_IER.Reg     = (DIV >> 8) & 0xffU;

    /* close divisor latch */
    RegA6_UART->UART_LINE_CTRL.Reg &= (~UART_LCR_DLAB_ENABLE);

    /* Enable UART */
    RegA6_UART->UART_DLH_IER.Reg = 0x15U;
}

/* End Of File */
