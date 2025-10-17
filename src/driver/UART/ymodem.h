#ifndef YMODEM_H_
#define YMODEM_H_

/**
 * Free YModem implementation.
 *
 * Fredrik Hederstierna 2014
 *
 * This file is in the public domain.
 * You can do whatever you want with it.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */


/* filesize 999999999999999 should be enough... */
#define YM_FILE_SIZE_LENGTH (16)

/* packet constants */
#define YM_PACKET_SEQNO_INDEX (1)
#define YM_PACKET_SEQNO_COMP_INDEX (2)
#define YM_PACKET_HEADER (3)  /* start, block, block-complement */
#define YM_PACKET_TRAILER (2) /* CRC bytes */
#define YM_PACKET_OVERHEAD (YM_PACKET_HEADER + YM_PACKET_TRAILER)
#define YM_PACKET_SIZE (128)
#define YM_PACKET_1K_SIZE (1024)
#define YM_PACKET_RX_TIMEOUT_MS (10000U)
#define YM_PACKET_ERROR_MAX_NBR (5)

/* contants defined by YModem protocol */
#define YM_SOH (0x01)  /* start of 128-byte data packet */
#define YM_STX (0x02)  /* start of 1024-byte data packet */
#define YM_EOT (0x04)  /* End Of Transmission */
#define YM_ACK (0x06)  /* ACKnowledge, receive OK */
#define YM_NAK (0x15)  /* Negative ACKnowledge, receiver ERROR, retry */
#define YM_CAN (0x18)  /* two CAN in succession will abort transfer */
#define YM_CRC (0x43)  /* 'C' == 0x43, request 16-bit CRC, use in place of first NAK for CRC mode */
#define YM_ABT1 (0x41) /* 'A' == 0x41, assume try abort by user typing */
#define YM_ABT2 (0x61) /* 'a' == 0x61, assume try abort by user typing */

/* max length of filename */
#define YMODEM_FILE_NAME_MAX_LENGTH (64)

typedef struct
{
    INT32 rx_packet_len;
    UINT32 filesize;
    UINT32 packets_rxed;

    BOOL file_done;
    BOOL session_done;
    BOOL standby_first_body;
    BOOL crc_nak;
    UINT8 rx_packet_data[YM_PACKET_1K_SIZE + YM_PACKET_OVERHEAD];

    UINT8 *hptr;
    UINT8 *rxdata;
    UINT8 *rxptr;
} tYMDEM_INFO;


/* receive file over ymodem */
extern NC_ERROR NC_Ymodem_receive(const tBOOT_INFO *ptBootInfo, UINT32 rxlen, UINT8* filename, UINT32* pRxFileSize);

#endif /* YMODEM_H_ */
