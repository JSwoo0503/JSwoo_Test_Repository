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


/*
********************************************************************************
*               INCLUDE
********************************************************************************
*/

#include "Apache.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/* Based on CPU_SCU register memory map --> exchange to DEBUG_APB_BASE define in Apahce.h */
#define SIM_CMD_BUFFER              (DEBUG_APB_BASE + 0xD100)
#define rDEBUG_COMMAND              (DEBUG_APB_BASE + 0xD000)
#define SIM_CMD_BUFFER5             (DEBUG_APB_BASE + 0xD900)
#define rDEBUG_COMMAND5             (DEBUG_APB_BASE + 0xD800)
#define PAD_RIGHT                   (1U)
#define PAD_ZERO                    (2U)

/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN               (12U)

volatile DRV_UART_REGISTER* const RegA6_UART = (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR1;

//extern UINT32 ReadMPIDR(void);

void ncDrv_UART_Printf1(UINT32 DebugZone, const CHAR *fmt, ...)
{
    va_list args;
    int len;
    char buffer[128];
    int *pBuff;
    int i;

    memset((char*)&buffer[0],0,128);
    va_start(args, fmt);
    len = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    pBuff = (int*)&buffer[0];
    for(i=0; i<len; i+=4)
    {
        REGRW32(SIM_CMD_BUFFER, i) = *pBuff++;
    }

    REGRW32(rDEBUG_COMMAND, 0x0) = 0x1;
}

void ncDrv_UART_Printf2(UINT32 DebugZone, const CHAR *fmt, ...)
{
    va_list args;
    int len;
    char buffer[256] = {0, };
    int i;
    UINT32 idx_cpu;
    //idx_cpu = ReadMPIDR();
#ifdef AARCH64
    idx_cpu = ASM_GET_CORE_ID();
#else
    asm volatile("mrc p15,0,%0,c0,c0,5":"=r"(idx_cpu)::"memory");
#endif
    idx_cpu = (UINT32)(idx_cpu & 0x3) * 0x200;

    va_start(args, fmt);
    //len = vsnprintf(SIM_CMD_BUFFER + idx_cpu, 256, fmt, args);
    len = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    for (i = 0; i < len; i = i + 4)
    {
        (*(volatile UINT32 *)((UINT32)(SIM_CMD_BUFFER) + (UINT32)(idx_cpu) + (UINT32)(i))) =  buffer[i + 0] | buffer[i + 1] << 8 | buffer[i + 2] << 16 | buffer[i + 3] << 24;
    }

    REGRW32(rDEBUG_COMMAND, idx_cpu) = 0x1;
}

void NC_UART_PutChar(CHAR Data)
{
#if defined(SIM_SINGLE_)
    *(volatile UINT32 *)((UINT32)(SIM_CMD_BUFFER5)) = (UINT32)Data;
#else
    UINT32 idx_cpu;
    //idx_cpu = ReadMPIDR();
#ifdef AARCH64
    idx_cpu = ASM_GET_CORE_ID();
#else
    asm volatile("mrc p15,0,%0,c0,c0,5":"=r"(idx_cpu)::"memory");
#endif
    idx_cpu = (UINT32)(idx_cpu & 0x3) * 0x200;
    /* Data Write */
    *(volatile UINT32 *)((UINT32)(SIM_CMD_BUFFER) + (UINT32)(idx_cpu)) = (UINT32)Data;
#endif

}
static void ncLib_DEBUG_Printc(CHAR c)
{
    if( c == (CHAR)'\n' )
    {
      NC_UART_PutChar((CHAR)'\r');
    }
    NC_UART_PutChar((CHAR)c);
}

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

void ncDrv_UART_Printf(UINT32 DebugZone, const CHAR *fmt, ...)
{
    va_list args;
#if defined(SIM_SINGLE_)
    va_start(args, fmt);
    ncLib_DEBUG_Printf(fmt, args);
    REGRW32(rDEBUG_COMMAND5, 0x0) = 0x1;
#else
    UINT32 idx_cpu;
    va_start(args, fmt);
    ncLib_DEBUG_Printf(fmt, args);
#ifdef AARCH64
    idx_cpu = ASM_GET_CORE_ID();
#else
    asm volatile("mrc p15,0,%0,c0,c0,5":"=r"(idx_cpu)::"memory");
#endif
    idx_cpu = (UINT32)(idx_cpu & 0x3) * 0x200;
    *(volatile UINT32 *)((UINT32)(rDEBUG_COMMAND) + (UINT32)(idx_cpu)) = 0x1;
#endif
    va_end(args);
}

void NC_UART_Initialize(UINT32 BaudRate, UINT32 RefClk)
{
    // nothing to do.
}


INT8 NC_UART_GetChar(void)
{
    return NC_FAILURE;
}


INT32 NC_UART_GetCharN(CHAR *c)
{
    INT8 Ret = NC_SUCCESS;

    return Ret;
}
/* End Of File */

