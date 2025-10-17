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
#include "ymodem.h"
#include "Drv_SCU.h"
#include "Drv_Uart.h"

#include "MPU.h"

/*
********************************************************************************
*              DEFINE
********************************************************************************
*/
#define YM_BOOT_HDR_SIZE    (64U) /* 64 byte */



/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/


/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    Data returns when data is entered into the console, and an error is returned when the timeout period elapses.
* @return   INT32   Console input value
* @design
    result value
    DO WHILE    The time elapsed so far does not exceed the value of timeout
        IF  When entering values ​​in the console.  THEN
            result = Console input value
            Exit Do
        ENDIF
    LOOP

    IF  No data has entered even after timeout     THEN
        result is -1
    ENDIF

    Return result
*/
static INT32 DEBUG_FUNC_ATTR NC_Ymodem_Get_ConsoleData(void)
{
    INT32 cr = NC_FAILURE;
    CHAR c = (CHAR)0;    
    UINT32 prevTime = (UINT32)nc_get_msec(FALSE);
    UINT64 loop = 0xfffffffULL;

    /* Reflected on a feedback from CodeSonar (Potential Unbounded Loop) */
    do
    {
        if (NC_UART_GetCharN(&c) != NC_FAILURE)
        {
            cr = (INT32)c;
            loop = 0ULL;
        }
        else
        {
            if (YM_PACKET_RX_TIMEOUT_MS < ((UINT32)(nc_get_msec(FALSE)) - prevTime))
            {
                cr = NC_FAILURE;
                loop = 0ULL;
            }
            else
            {
                loop--;
            }
        }
        
    } while (0ULL < loop);

    return cr;
}



/* ------------------------------------------------ */
/* Rule-3.1 Nested comments are not recognized in the ISO standard. */
/* calculate crc16-ccitt very fast
   Idea from: http:\\www.ccsinfo.com/forum/viewtopic.php?t=24977
*/
/**
* @desc
    Calculates and returns the crc 16 value of the input data.
* @param    UINT8*  buf Data Buffer
* @param    UINT16  len Data Length
* @return   UINT16  CRC value
* @design
    DO WHILE    Length is not 0.
        Calculate the crc value.
    LOOP
    Return crc value
*/
static UINT16 DEBUG_FUNC_ATTR NC_Ymodem_crc16(const UINT8 *buf, UINT16 len)
{
    UINT16 x;
    UINT16 crc = 0U;

    const UINT8* crc16_buf;
    UINT16 crc16_len = len;
    
    crc16_buf = buf;        
    while (crc16_len > 0U)
    {
        x = (crc >> 8) ^ *crc16_buf;
        x ^= x >> 4;
        crc = (UINT16)((crc << 8) ^ (x << 12) ^ (x << 5) ^ x);
        crc16_len--;
        crc16_buf++;
    }

    return crc;
}



/**
* @desc
    Converts a numeric string to a decimal number.
* @param    const UINT8*    buf     String Data
* @param    UINT32          val     Data Buffer
* @return   void
* @design
    DO WHILE    It is an ASCII value of "0" to "9"
        IF  It is an ASCII value of "0" to "9" THEN
            Convert to decimal.
        ELSE
            Exit Do
        ENDIF
    LOOP
    Stores the converted decimal number in argument.
*/
static void DEBUG_FUNC_ATTR NC_Ymodem_ATOI(const UINT8 *buf, UINT32 *val)
{
    const UINT8 *s = buf;
    UINT32 res = 0U;
    UINT8 c;
    /* trim and strip leading spaces if any */

    while (1)
    {
        c = *s;
        s++;

        if (c != (UINT8)' ')
        {
            break;
        }
    }

    while (1)
    {
        if ((c >= (UINT8)'0') && (c <= (UINT8)'9'))
        {
            c -= (UINT8)'0';
            res *= 10U;
            res += c;
            /* next char */
            c = *s;
            s++;
        }
        else
        {
            break;
        }
    }

    *val = res;
}



/**
* @desc
    Ymodem's error handler.
* @param    void
* @return   void
* @design
    Two CAN in succession will abort transfer.
*/
static void DEBUG_FUNC_ATTR NC_Ymodem_RxErrHandler(void)
{
    NC_UART_PutChar((CHAR)YM_CAN);
    NC_UART_PutChar((CHAR)YM_CAN);

    /* -> QAC Rule-10.7  A composite expression of 'essentially unsigned' type (unsigned int) is being implicitly converted to a wider unsigned type, 'unsigned long long'. */
    nc_mdelay(1000ULL);
}



/**
* @desc
    Check the received packet data.
* @param    tYMDEM_INFO*    ptYmodem    Ymodem parameter
* @param    UINT8*          filename    File name
* @param    UINT32          rxlen       The file size to read
* @return   void
* @struct
    typedef struct
    {
        INT32 rx_packet_len;        Packet Length
        UINT32 filesize;            File size
        UINT32 packets_rxed;        Sequence number
        BOOL file_done;             File done flag
        BOOL session_done;          Session done flag
        BOOL standby_first_body;    Check if it is the first packet
        BOOL crc_nak;               Check CRC or NAK
        UINT8 rx_packet_data[];     Packet Data
        UINT8 *hptr;                H pointer
        UINT8 *rxdata;              Rx data
        UINT8 *rxptr;               Rx pointer
    } tYMDEM_INFO;
* @design
    IF  Packet Length is 0  THEN
        Request for packet transmission again.
    ELSE
        Check packet data.
    ENDIF
*/
static void DEBUG_FUNC_ATTR NC_Ymodem_Check_RxPacket(tYMDEM_INFO* ptYmodem, UINT8* filename, UINT32 rxlen)
{
    UINT8 filesize_asc[YM_FILE_SIZE_LENGTH] = {0,};
    const UINT8* file_ptr;
    UINT8 seq_nbr;
    BOOL isBreak;

    INT32 i;
    INT32 j;
    INT32 k;

    if(ptYmodem->rx_packet_len == 0)
    {
        /* EOT - End Of Transmission */
        NC_UART_PutChar((CHAR)YM_ACK);
        /* TODO: Add some sort of sanity check on the number of
        packets received and the advertised file length. */
        ptYmodem->file_done = TRUE;
        /* resend CRC to re-initiate transfer */
        NC_UART_PutChar((CHAR)YM_CRC);
    }
    else
    {
        /* normal packet, check seq nbr */
        seq_nbr = ptYmodem->rx_packet_data[YM_PACKET_SEQNO_INDEX];
        if (seq_nbr != (UINT8)(ptYmodem->packets_rxed & (UINT32)0xff))
        {
            /* wrong seq number */
            NC_UART_PutChar((CHAR)YM_NAK);
        }
        else
        {
            if (ptYmodem->packets_rxed == 0U)
            {
                /* The spec suggests that the whole data section should
                be zeroed, but some senders might not do this.
                If we have a NULL filename and the first few digits of
                the file length are zero, then call it empty. */
                i = YM_PACKET_HEADER;
                isBreak = FALSE;
                do
                {
                    /* for CodeSonar (Unreachable Call) */
                    if ((YM_PACKET_HEADER + 4) <= i)
                    {
                        /* filename packet is empty, end session */
                        NC_UART_PutChar((CHAR)YM_ACK);
                        ptYmodem->file_done = TRUE;
                        ptYmodem->session_done = TRUE;
                        ptYmodem->standby_first_body = FALSE;
                        isBreak = TRUE;
                    }
                    else
                    {
                        if (ptYmodem->rx_packet_data[i] != 0U)
                        {
                            isBreak = TRUE;
                        }
                    }
                    i++;
                } while (isBreak == FALSE);
                /* non-zero bytes found in header, filename packet has data */
                if (i < (YM_PACKET_HEADER + 4))
                {
                    /* read file name */
                    /* for QAC Rule-18.4 file_ptr = (UINT8 *)(ptYmodem->rx_packet_data + YM_PACKET_HEADER); */
                    file_ptr = (UINT8 *)(&ptYmodem->rx_packet_data[YM_PACKET_HEADER]);
                    i = 0;
                    while ((*file_ptr != (UINT8)'\0') && (i < YMODEM_FILE_NAME_MAX_LENGTH))
                    {
                        filename[i] = *file_ptr;
                        file_ptr++;
                        i++;
                    }
                    filename[i] = (UINT8)'\0';
                    /* skip null term char */
                    file_ptr++;
                    /* read file size */
                    i = 0;
                    while ((*file_ptr != (UINT8)'\0') && (*file_ptr != (UINT8)' ') && (i < YM_FILE_SIZE_LENGTH))
                    {
                        filesize_asc[i] = *file_ptr;
                        file_ptr++;
                        i++;
                    }
                    filesize_asc[i] = (UINT8)'\0';
                    /* convert file size */
                    NC_Ymodem_ATOI(filesize_asc, &ptYmodem->filesize);
                    /* check file size */
                    if (ptYmodem->filesize > rxlen)
                    {
#ifdef DEBUG_ENABLE_
                        DEBUGMSG(MSGERR, "YM: RX buffer too small (0x%08x vs 0x%08x)\n", (unsigned int)rxlen, (unsigned int)ptYmodem->filesize);
#endif
                        NC_Ymodem_RxErrHandler();
                        /* Ymodem END */
                        ptYmodem->filesize = 0;
                        ptYmodem->file_done = TRUE;
                        ptYmodem->session_done = TRUE;
                    }
                    else
                    {
                        NC_UART_PutChar((CHAR)YM_ACK);
                        if (ptYmodem->crc_nak == TRUE)
                        {
                            ptYmodem->standby_first_body = TRUE;
                            NC_UART_PutChar((CHAR)YM_CRC);
                        }
                        else
                        {
                            NC_UART_PutChar((CHAR)YM_NAK);
                        }
                        ptYmodem->crc_nak = FALSE;
                    }
                }
            }
            else
            {
                /* This shouldn't happen, but we check anyway in case the sender sent wrong info in its filename packet */
                if ((((INT32)ptYmodem->rxptr + ptYmodem->rx_packet_len) - (INT32)ptYmodem->rxdata) > (INT32)rxlen)
                {
#ifdef DEBUG_ENABLE_
                    DEBUGMSG(MSGERR, "YM: RX buffer overflow (exceeded 0x%08x)\n", (unsigned int)rxlen);
#endif
                    NC_Ymodem_RxErrHandler();
                    /* Ymodem END */
                    ptYmodem->filesize = 0;
                    ptYmodem->file_done = TRUE;
                    ptYmodem->session_done = TRUE;
                }
                else
                {
                    /* first body packet */
                    if (ptYmodem->standby_first_body == TRUE) 
                    {
                        k = 0;
                        if (ptYmodem->rx_packet_len > (INT32)YM_BOOT_HDR_SIZE)
                        {
                            for (i = 0; i < (INT32)YM_BOOT_HDR_SIZE; i++)
                            {
                                ptYmodem->hptr[i] = ptYmodem->rx_packet_data[YM_PACKET_HEADER + i];
                                k++;
                            }
                            j = 0;
                            for ( ; i < ptYmodem->rx_packet_len; i++)
                            {
                                ptYmodem->rxptr[j] = ptYmodem->rx_packet_data[YM_PACKET_HEADER + i];
                                j++;
                            }
                        }
                        else
                        {
    #ifdef DEBUG_ENABLE_
                            DEBUGMSG(MSGERR, "YM: RX length small - packet size(%d)\n", ptYmodem->rx_packet_len);
    #endif
                        }
                        /* rxptr += rx_packet_len; */
                        /* for QAC Rule-18.4, Original code : ptYmodem->rxptr += (ptYmodem->rx_packet_len - k) */
                        ptYmodem->rxptr = &ptYmodem->rxptr[ptYmodem->rx_packet_len - k];
                        ptYmodem->standby_first_body = FALSE;
                    }
                    else
                    {
                        for (i = 0; i < ptYmodem->rx_packet_len; i++)
                        {
                            ptYmodem->rxptr[i] = ptYmodem->rx_packet_data[YM_PACKET_HEADER + i];
                        }
                        /* for QAC Rule-18.4, Original code : ptYmodem->rxptr += ptYmodem->rx_packet_len;*/
                        ptYmodem->rxptr = &ptYmodem->rxptr[ptYmodem->rx_packet_len];
                    }
                    NC_UART_PutChar((CHAR)YM_ACK);
                }
            }
            if ((ptYmodem->file_done == FALSE) && (ptYmodem->session_done == FALSE))
            {
                ptYmodem->packets_rxed++; /* sequence number check ok */
            }
        }
    }
}



/**
* @desc
    Receive a packet from sender.
* @param    UINT8*   rxdata     Read Data
* @param    INT32*   rxlen      Read file size (0: end of transmission, -1: abort by sender, >0: packet length)
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE or NC_WAIT
* @design
    Ret = NC_SUCCESS
    IF  Time out value is less than 0   THEN
        Ret = NC_FAILURE
    ELSE
        Check Ymodem protocol.
        IF  Packet Size is more than 0  THEN
            IF  Data was not input as much as packet size from the console  THEN
                Ret = NC_FAILURE
            ENDIF
            IF  The Packet data integrity check was successful. THEN
                Ret = NC_SUCCESS
            ELSE
                Ret = NC_WAIT
            ENDIF
        ENDIF
    ENDIF

    Return Ret
*/
static NC_ERROR DEBUG_FUNC_ATTR NC_Ymodem_RxPacket(UINT8 *rxdata, INT32 *rxlen)
{
    NC_ERROR Ret = NC_SUCCESS;
    INT32 c;
    UINT32 rx_packet_size = 0U;
    UINT32 i;

    /* just a sanity check on the sequence number/complement value.
     caller should check for in-order arrival. */
    UINT8 seq_nbr;
    UINT8 seq_cmp;

    UINT16 crc16_val;

    *rxlen = 0;    
    c = NC_Ymodem_Get_ConsoleData();

    if (c == NC_FAILURE)
    {
        /* end of stream */
        Ret = NC_FAILURE;
    }
    else
    {
        switch (c)
        {
            case YM_SOH:
                rx_packet_size = YM_PACKET_SIZE;
            break;

            case YM_STX:
                rx_packet_size = YM_PACKET_1K_SIZE;
            break;

            case YM_EOT:
                Ret = NC_SUCCESS;
            break;

            case YM_CAN:
                c = NC_Ymodem_Get_ConsoleData();

                if (c == YM_CAN)
                {
                    *rxlen = NC_FAILURE;
                    /* ok */
                    Ret = NC_SUCCESS;
                }
                else
                {
                    Ret = NC_WAIT;
                }
                break;

            /* fall-through */
            case YM_CRC:
#if 0   /* for QAC Rule-16.3 */
                if (packets_rxed == 0U)
                {
                    /* could be start condition, first byte */
                    Ret =  NC_WAIT;
                    break;
                }
#endif
            case YM_ABT1:
            case YM_ABT2:
                Ret = NC_WAIT;
            break;

            default:
                /* This case could be the result of corruption on the first octet
                of the packet, but it's more likely that it's the user banging
                on the terminal trying to abort a transfer. Technically, the
                former case deserves a NAK, but for now we'll just treat this
                as an abort case. */
                *rxlen = NC_FAILURE;
                Ret = NC_SUCCESS;
            break;
        }

        if (rx_packet_size > 0U)
        {
            /* store data RXed */
            *rxdata = (UINT8)c;

            for (i = 1U; i < (rx_packet_size + (UINT32)YM_PACKET_OVERHEAD); i++)
            {
                c = NC_Ymodem_Get_ConsoleData();
                if (c == NC_FAILURE)
                {
                    /* end of stream */
                    Ret = NC_FAILURE;
                    break;
                }
                /* store data RXed */
                rxdata[i] = (UINT8)c;
            }


            if (Ret == NC_SUCCESS)
            {
                /* This operation is redundant. The value of the result is always that of the left-hand operand. for QAC */
                /* seq_nbr = (rxdata[YM_PACKET_SEQNO_INDEX] & 0xff); */
                /* seq_cmp = ((rxdata[YM_PACKET_SEQNO_COMP_INDEX] ^ 0xff) & 0xff); */

                seq_nbr = rxdata[YM_PACKET_SEQNO_INDEX];
                seq_cmp = (rxdata[YM_PACKET_SEQNO_COMP_INDEX] ^ (UINT8)0xff);

                if (seq_nbr != seq_cmp)
                {
                    /* seq nbr error */
                    Ret = NC_WAIT;
                }
                else
                {
                    /* for QAC Rule-18.4 */
                    crc16_val = NC_Ymodem_crc16((const UINT8*)(&rxdata[(UINT8)YM_PACKET_HEADER]), (UINT16)(rx_packet_size + (UINT32)YM_PACKET_TRAILER));
                    if (crc16_val > 0U)
                    {
                        /* CRC error, non zero */
                        Ret = NC_WAIT;
                    }
                    else
                    {
                        *rxlen = (INT32)rx_packet_size;
                        /* success */
                        Ret = NC_SUCCESS;
                    }
                }
            }
        }
    }
    return Ret;
}



/**
* @desc
    Receive data with ymodem protocol.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter
* @param    UINT32          rxlen           The file size to read.
* @param    UINT8*          filename        File Name
* @param    UINT32*         pRxFileSize     Read file size
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;            Boot Image header info
        tBOOT_IMG   tImage;             Boot Image info
        tBOOT_STRAP tStrap;             Boot strap info
        tBOOT_CLK   tClock;             Boot clock info
        tBOOT_CMRT  tCMRT;              Boot CMRT info
    } tBOOT_INFO;
* @design
    DO WHILE    Session is not done.
        DO WHILE    File is not done.
            IF  Packet receive was successful   THEN
                IF  Packet Length is more than 0    THEN
                    Check the packet data.
                ELSE
                    File and Session is done.
                    Ret = NC_FAILURE
                ENDIF
            ELSE
                File and Session is done.
                Ret = NC_FAILURE
            ENDIF

            IF  File is done THEN
                Exit Do
            ENDIF
        LOOP

        IF  Session is done THEN
            Exit Do
        ENDIF
    LOOP

    IF  File size is more than 0    THEN
        Ret = NC_SUCCESS
    ELSE
        Ret = NC_FAILURE
    ENDIF

    Return Ret
*/
/* for QAC Rule-8.13 */
NC_ERROR DEBUG_FUNC_ATTR NC_Ymodem_receive(const tBOOT_INFO *ptBootInfo, UINT32 rxlen, UINT8* filename, UINT32* pRxFileSize)
{
    NC_ERROR Ret;
    BOOL first_try = TRUE;
    UINT32 nbr_errors = 0U;
    INT32 res;

    tYMDEM_INFO tYmodem;

    tYmodem.rx_packet_len = 0;
    tYmodem.filesize = 0U;

    tYmodem.session_done = FALSE;
    tYmodem.standby_first_body = FALSE;

    /* z-term string */
    filename[0] = 0;

    /* receive files */
    while (1)
    { /* ! session done */
        if (first_try == TRUE)
        {
            /* initiate transfer */
            NC_UART_PutChar((CHAR)YM_CRC);
        }
        first_try = FALSE;

        tYmodem.crc_nak = TRUE;
        tYmodem.file_done = FALSE;
        tYmodem.packets_rxed = 0U;

        /* set start position of rxing data */
        tYmodem.hptr   = (UINT8*)(volatile unsigned int)&(ptBootInfo->tHeader);
        tYmodem.rxdata = (UINT8*)ptBootInfo->tImage.mDestAddr;
        tYmodem.rxptr  = (UINT8*)ptBootInfo->tImage.mDestAddr;

#ifdef DEBUG_ENABLE_
        DEBUGMSG(MSGWARN, "hptr[0x%08x] -- rxdata[0x%08x], rxptr[0x%08x]\n", tYmodem.hptr, tYmodem.rxdata, tYmodem.rxptr);
#endif

        while (1)
        { /* ! file_done */
            /* receive packets */
            res = NC_Ymodem_RxPacket(tYmodem.rx_packet_data, &tYmodem.rx_packet_len);

            if (res == NC_SUCCESS)
            {
                /* packet received, clear packet error counter */
                nbr_errors = 0;

                if (tYmodem.rx_packet_len == NC_FAILURE)
                {
                    /* aborted by sender and end the function */
                    tYmodem.filesize = 0;
                    tYmodem.file_done = TRUE;
                    tYmodem.session_done = TRUE;
                    NC_UART_PutChar((CHAR)YM_ACK);
                }
                else
                {
                    /* packet received, clear packet error counter */
                    NC_Ymodem_Check_RxPacket(&tYmodem, filename, rxlen);
                }
            }
            else
            {
                /* NC_Ymodem_RxPacket() returned error */
                if (tYmodem.packets_rxed > 0U)
                {
                    nbr_errors++;
                    if (nbr_errors >= (UINT32)YM_PACKET_ERROR_MAX_NBR)
                    {
#ifdef DEBUG_ENABLE_
                        DEBUGMSG(MSGERR, "YM: RX errors too many: %d - ABORT.\n", (unsigned int)nbr_errors);
#endif
                        tYmodem.filesize = 0;
                        tYmodem.file_done = TRUE;
                        tYmodem.session_done = TRUE;
                        NC_Ymodem_RxErrHandler();
                    }
                }

                if (tYmodem.file_done == FALSE)
                {
                    NC_UART_PutChar((CHAR)YM_CRC);
                }
            }
            /* check end of receive packets */
            if (tYmodem.file_done == TRUE)
            {
                break;
            }
        }

        /* check end of receive files */
        if (tYmodem.session_done == TRUE)
        {
            break;
        }
    }

    /* return bytes received */
    if (tYmodem.filesize > 0U)
    {
        Ret = NC_SUCCESS;
    }
    else
    {
        Ret = NC_FAILURE;
    }

    *pRxFileSize = tYmodem.filesize;
    return Ret;
}


/* end of file */

