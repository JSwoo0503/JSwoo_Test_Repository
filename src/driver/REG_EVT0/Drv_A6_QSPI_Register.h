
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_QSPI_Register.h
*   Date       : 2020-07-31 11:32
* 
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_QSPI_H__
#define DRV_REGISTER_QSPI_H__

#define APACHE_QSPI_BASE_ADDR        0x06224000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 DFS                                                                    : 4;      /* [  3:0] Data Frame Size
                                                                                                               Note When SSI_SPI_MODE is either set to Dual or Quad or Octal mode and SPI_FRF is not set to 2b00
                                                                                                               - DFS value should be multiple of 2 if SPI_FRF  01
                                                                                                               - DFS value should be multiple of 4 if SPI_FRF  10
                                                                                                               - DFS value should be multiple of 8 if SPI_FRF  11
                                                                                                               0x3 FRAME_04BITS 4-bit serial data transfer
                                                                                                               0x4 FRAME_05BITS 5-bit serial data transfer
                                                                                                               0x5 FRAME_06BITS 6-bit serial data transfer
                                                                                                               0x6 FRAME_07BITS 7-bit serial data transfer
                                                                                                               0x7 FRAME_08BITS 8-bit serial data transfer
                                                                                                               0x8 FRAME_09BITS 9-bit serial data transfer
                                                                                                               0x9 FRAME_10BITS 10-bit serial data transfer
                                                                                                               0xa FRAME_11BITS 11-bit serial data transfer
                                                                                                               0xb FRAME_12BITS 12-bit serial data transfer
                                                                                                               0xc FRAME_13BITS 13-bit serial data transfer
                                                                                                               0xd FRAME_14BITS 14-bit serial data transfer
                                                                                                               0xe FRAME_15BITS 15-bit serial data transfer
                                                                                                               0xf FRAME_16BITS 16-bit serial data transfer */
            UINT32 FRF                                                                    : 2;      /* [  5:4] Frame Format Selects which serial protocol transfers the data
                                                                                                               0x0 MOTOROLA_SPI Motorolla SPI Frame Format
                                                                                                               0x1 TEXAS_SSP Texas Instruments SSP Frame Format
                                                                                                               0x2 NS_MICROWIRE National Microwire Frame Format
                                                                                                               0x3 RESERVED Reserved value */
            UINT32 SCPH                                                                   : 1;      /* [    6] Serial Clock Phase
                                                                                                               0x0 SCPH_MIDDLE Serial clock toggles in middle of first data bit
                                                                                                               0x1 SCPH_START */
            UINT32 SCPOL                                                                  : 1;      /* [    7] Serial Clock Polarity
                                                                                                               0x0 SCLK_LOW Inactive state of serial clock is low
                                                                                                               0x1 SCLK_HIGH Inactive state of serial clock is high */
            UINT32 TMOD                                                                   : 2;      /* [  9:8] Transfer Mode
                                                                                                               When SSI_SPI_MODE is either set to Dual or Quad or Octal mode and SPI_FRF is not set to 2b00 There are only two valid combinations
                                                                                                               10 - Read
                                                                                                               01 - Write
                                                                                                               0x0 TX_AND_RX Transmit  receive
                                                                                                               0x1 TX_ONLY Transmit only mode or Write SPI_FRF  2b00
                                                                                                               0x2 RX_ONLY Receive only mode or Read SPI_FRF  2b00
                                                                                                               0x3 EEPROM_READ EEPROM Read mode */
            UINT32 SLV_OE                                                                 : 1;      /* [   10] Slave Output Enable
                                                                                                               0x1 DISABLED Slave Output is disabled
                                                                                                               0x0 ENABLED Slave Output is enabled */
            UINT32 SRL                                                                    : 1;      /* [   11] Shift Register Loop
                                                                                                               0x1 TESTING_MODE Test mode Tx  Rx shift reg connected
                                                                                                               0x0 NORMAL_MODE Normal mode operation */
            UINT32 CFS                                                                    : 4;      /* [15:12] Control Frame Size
                                                                                                               0x0 SIZE_01_BIT 1-bit Control Word
                                                                                                               0x1 SIZE_02_BIT 2-bit Control Word
                                                                                                               0x2 SIZE_03_BIT 3-bit Control Word
                                                                                                               0x3 SIZE_04_BIT 4-bit Control Word
                                                                                                               0x4 SIZE_05_BIT 5-bit Control Word
                                                                                                               0x5 SIZE_06_BIT 6-bit Control Word
                                                                                                               0x6 SIZE_07_BIT 7-bit Control Word
                                                                                                               0x7 SIZE_08_BIT 8-bit Control Word
                                                                                                               0x8 SIZE_09_BIT 9-bit Control Word
                                                                                                               0x9 SIZE_10_BIT 10-bit Control Word
                                                                                                               0xa SIZE_11_BIT 11-bit Control Word
                                                                                                               0xb SIZE_12_BIT 12-bit Control Word
                                                                                                               0xc SIZE_13_BIT 13-bit Control Word
                                                                                                               0xd SIZE_14_BIT 14-bit Control Word
                                                                                                               0xe SIZE_15_BIT 15-bit Control Word
                                                                                                               0xf SIZE_16_BIT 16-bit Control Word */
            UINT32 DFS_32                                                                 : 5;      /* [20:16] Data Frame Size in 32-bit transfer size mode
                                                                                                               - DFS value should be multiple of 2 if SPI_FRF  0x01
                                                                                                               - DFS value should be multiple of 4 if SPI_FRF  0x10
                                                                                                               - DFS value should be multiple of 8 if SPI_FRF  0x11
                                                                                                               0x3 FRAME_04BITS 4-bit serial data transfer
                                                                                                               0x4 FRAME_05BITS 5-bit serial data transfer
                                                                                                               0x5 FRAME_06BITS 6-bit serial data transfer
                                                                                                               0x6 FRAME_07BITS 7-bit serial data transfer
                                                                                                               0x7 FRAME_08BITS 8-bit serial data transfer
                                                                                                               0x8 FRAME_09BITS 9-bit serial data transfer
                                                                                                               0x9 FRAME_10BITS 10-bit serial data transfer
                                                                                                               0xa FRAME_11BITS 11-bit serial data transfer
                                                                                                               0xb FRAME_12BITS 12-bit serial data transfer
                                                                                                               0xc FRAME_13BITS 13-bit serial data transfer
                                                                                                               0xd FRAME_14BITS 14-bit serial data transfer
                                                                                                               0xe FRAME_15BITS 15-bit serial data transfer
                                                                                                               0xf FRAME_16BITS 16-bit serial data transfer
                                                                                                               0x10 FRAME_17BITS 17-bit serial data transfer
                                                                                                               0x11 FRAME_18BITS 18-bit serial data transfer
                                                                                                               0x12 FRAME_19BITS 19-bit serial data transfer
                                                                                                               0x13 FRAME_20BITS 20-bit serial data transfer
                                                                                                               0x14 FRAME_21BITS 21-bit serial data transfer
                                                                                                               0x15 FRAME_22BITS 22-bit serial data transfer
                                                                                                               0x16 FRAME_23BITS 23-bit serial data transfer
                                                                                                               0x17 FRAME_24BITS 24-bit serial data transfer
                                                                                                               0x18 FRAME_25BITS 25-bit serial data transfer
                                                                                                               0x19 FRAME_26BITS 26-bit serial data transfer
                                                                                                               0x1a FRAME_27BITS 27-bit serial data transfer
                                                                                                               0x1b FRAME_28BITS 28-bit serial data transfer
                                                                                                               0x1c FRAME_29BITS 29-bit serial data transfer
                                                                                                               0x1d FRAME_30BITS 30-bit serial data transfer
                                                                                                               0x1e FRAME_31BITS 31-bit serial data transfer
                                                                                                               0x1f FRAME_32BITS 32-bit serial data transfer */
            UINT32 SPI_FRF                                                                : 2;      /* [22:21] SPI Frame Format  It can be written when SSI_SPI_MODE parameter is not 0 Dual  Quad  Octal Mode 
                                                                                                               0x0 STD_SPI_FRF Standard SPI Frame Format
                                                                                                               0x1 DUAL_SPI_FRF Dual SPI Frame Format
                                                                                                               0x2 QUAD_SPI_FRF Quad SPI Frame Format
                                                                                                               0x3 OCTAL_SPI_FRF Octal SPI Frame Format */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 SSTE                                                                   : 1;      /* [   24] Slave Select Toggle Enable
                                                                                                               When operating in SPI mode with clock phase SCPH set to 0 this register controls the behavior of the slave select line ss__n between data frames
                                                                                                               If this register field is set to 1 the ss__n line will toggle between consecutive data frames with the serial clock sclk being held to its default value while ss__n is high if this register field is set to 0 the ss__n will stay low and sclk will run continuously for the duration of the transfer */
            UINT32 RESERVED1                                                              : 7;      /* [31:25]  */
        }Bit;
    }CTRLR0;
    union { /* 0x0004 [Excel Line :0021]  */
        UINT32 Reg;
        struct {
            UINT32 NDF                                                                    : 16;     /* [ 15:0] Number of Data Frames */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CTRLR1;
    union { /* 0x0008 [Excel Line :0023]  */
        UINT32 Reg;
        struct {
            UINT32 SSI_EN                                                                 : 1;      /* [    0] SSI Enable
                                                                                                               0x0 DISABLE Disables Serial Transfer
                                                                                                               0x1 ENABLED Enables Serial Transfer */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SSIENR;
    union { /* 0x000c [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 MWMOD                                                                  : 1;      /* [    0] Microwire Transfer Mode
                                                                                                               0x0 NON_SEQUENTIAL Non-Sequential Microwire Transfer
                                                                                                               0x1 SEQUENTIAL Sequential Microwire Transfer */
            UINT32 MDD                                                                    : 1;      /* [    1] Microwire Control
                                                                                                               0x0 RECEIVE SSI receives data
                                                                                                               0x1 TRANSMIT SSI transmits data */
            UINT32 MHS                                                                    : 1;      /* [    2] Microwire Handshaking
                                                                                                               0x0 DISABLE Handshaking interface is disabled
                                                                                                               0x1 ENABLED Handshaking interface is enabled */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }MWCR;
    union { /* 0x0010 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 SER                                                                    : 1;      /* [    0] Slave Select Enable Flag
                                                                                                               0x0 NOT_SELECTED No slave selected
                                                                                                               0x1 SELECTED Slave is selected */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }SER;
    union { /* 0x0014 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 SCKDV                                                                  : 16;     /* [ 15:0] SSI Clock Divider
                                                                                                               The LSB for this field is always set to 0 and is unaffected by a write operation which ensures an even value is held in this register If the value is 0 the serial output clock sclk_out is disabled The frequency of the sclk_out is derived from the following equation
                                                                                                               Fsclk_out  Fssi_clkSCKDV
                                                                                                               where SCKDV is any even value between 2 and 65534 For example
                                                                                                               for Fssi_clk  36864MHz and SCKDV 2 Fsclk_out  368642  18432MHz */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }BAUDR;
    union { /* 0x0018 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 TFT                                                                    : 8;      /* [  7:0] Transmit FIFO Threshold
                                                                                                               Controls the level of entries or below at which the transmit FIFO controller triggers an interrupt The FIFO depth is configurable in the range 2-256 this register is sized to the number of address bits needed to access the FIFO If you attempt to set this value greater than or equal to the depth of the FIFO this field is not written and retains its current value When the number of transmit FIFO entries is less than or equal to this value the transmit FIFO empty interrupt is triggered
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }TXFTLR;
    union { /* 0x001c [Excel Line :0035]  */
        UINT32 Reg;
        struct {
            UINT32 RFT                                                                    : 8;      /* [  7:0] Receive FIFO Threshold
                                                                                                               Controls the level of entries or above at which the receive FIFO controller triggers an interrupt The FIFO depth is configurable in the range 2-256 This register is sized to the number of address bits needed to access the FIFO If you attempt to set this value greater than the depth of the FIFO this field is not written and retains its current value When the number of receive FIFO entries is greater than or equal to this value  1 the receive FIFO full interrupt is triggered
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }RXFTLR;
    union { /* 0x0020 [Excel Line :0037]  */
        UINT32 Reg;
        struct {
            UINT32 TXTFL                                                                  : 9;      /* [  8:0] Transmit FIFO Level
                                                                                                               Contains the number of valid data entries in the transmit FIFO
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }TXFLR;
    union { /* 0x0024 [Excel Line :0039]  */
        UINT32 Reg;
        struct {
            UINT32 RXTFL                                                                  : 9;      /* [  8:0] Receive FIFO Level
                                                                                                               Contains the number of valid data entries in the receive FIFO
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }RXFLR;
    union { /* 0x0028 [Excel Line :0041]  */
        UINT32 Reg;
        struct {
            UINT32 BUSY                                                                   : 1;      /* [    0] SSI Busy Flag
                                                                                                               0x0 INACTIVE DW_apb_ssi is idle or disabled
                                                                                                               0x1 ACTIVE DW_apb_ssi is actively transferring data */
            UINT32 TFNF                                                                   : 1;      /* [    1] Transmit FIFO Not Full
                                                                                                               0x0 FULL Transmit FIFO is full
                                                                                                               0x1 NOT_FULL Transmit FIFO is not Full */
            UINT32 TFE                                                                    : 1;      /* [    2] Transmit FIFO Empty
                                                                                                               0x0 NOT_EMPTY Transmit FIFO is not empty
                                                                                                               0x1 EMPTY Transmit FIFO is empty */
            UINT32 RFNE                                                                   : 1;      /* [    3] Receive FIFO Not Empty
                                                                                                               0x0 EMPTY Receive FIFO is empty
                                                                                                               0x1 NOT_EMPTY Receive FIFO is not empty */
            UINT32 RFF                                                                    : 1;      /* [    4] Receive FIFO Full
                                                                                                               0x0 NOT_FULL Receive FIFO is not full
                                                                                                               0x1 FULL Receive FIFO is full */
            UINT32 TXE                                                                    : 1;      /* [    5] Transmission Error
                                                                                                               0x0 NO_ERROR No Error
                                                                                                               0x1 TX_ERROR Transmission Error */
            UINT32 DCOL                                                                   : 1;      /* [    6] Data Collision Error
                                                                                                               0x0 NO_ERROR_CONDITION No Error
                                                                                                               0x1 TX_COLLISION_ERROR Transmit Data Collision Error */
            UINT32 RESERVED1                                                              : 25;     /* [ 31:7]  */
        }Bit;
    }SR;
    union { /* 0x002c [Excel Line :0049]  */
        UINT32 Reg;
        struct {
            UINT32 TXEIM                                                                  : 1;      /* [    0] Transmit FIFO Empty Interrupt Mask
                                                                                                               0x0 MASKED ssi_txe_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_txe_intr interrupt is not masked */
            UINT32 TXOIM                                                                  : 1;      /* [    1] Transmit FIFO Overflow Interrupt Mask
                                                                                                               0x0 MASKED ssi_txo_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_txo_intr interrupt is not masked */
            UINT32 RXUIM                                                                  : 1;      /* [    2] Receive FIFO Underflow Interrupt Mask
                                                                                                               0x0 MASKED ssi_rxu_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_rxu_intr interrupt is not masked */
            UINT32 RXOIM                                                                  : 1;      /* [    3] Receive FIFO Overflow Interrupt Mask
                                                                                                               0x0 MASKED ssi_rxo_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_rxo_intr interrupt is not masked */
            UINT32 RXFIM                                                                  : 1;      /* [    4] Receive FIFO Full Interrupt Mask
                                                                                                               0x0 MASKED ssi_rxf_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_rxf_intr interrupt is not masked */
            UINT32 MSTIM                                                                  : 1;      /* [    5] Multi-Master Contention Interrupt Mask 
                                                                                                               0x0 MASKED ssi_mst_intr interrupt is masked
                                                                                                               0x1 UNMASKED ssi_mst_intr interrupt is not masked */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }IMR;
    union { /* 0x0030 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 TXIEIS                                                                 : 1;      /* [    0] Transmit FIFO Empty Interrupt Status
                                                                                                               0x0 INACTIVE ssi_txe_intr interrupt is not active after masking
                                                                                                               0x1 ACTIVE ssi_txe_intr interrupt is active after masking */
            UINT32 TXOIS                                                                  : 1;      /* [    1] Transmit FIFO Overflow Interrupt Status
                                                                                                               0x0 INACTIVE ssi_txo_intr interrupt is not active after masking
                                                                                                               0x1 ACTIVE ssi_txo_intr interrupt is active after masking */
            UINT32 RXUIS                                                                  : 1;      /* [    2] Receive FIFO Underflow Interrupt Status
                                                                                                               0x0 INACTIVE ssi_rxu_intr interrupt is not active after masking
                                                                                                               0x1 ACTIVE ssi_rxu_intr interrupt is active after masking */
            UINT32 RXOIS                                                                  : 1;      /* [    3] Receive FIFO Overflow Interrupt Status
                                                                                                               0x0 INACTIVE ssi_rxo_intr interrupt is not active after masking
                                                                                                               0x1 ACTIVE ssi_rxo_intr interrupt is active after masking */
            UINT32 RXFIS                                                                  : 1;      /* [    4] Receive FIFO Full Interrupt Status
                                                                                                               0x0 INACTIVE ssi_rxf_intr interrupt is not active after masking
                                                                                                               0x1 ACTIVE ssi_rxf_intr interrupt is full after masking */
            UINT32 MSTIS                                                                  : 1;      /* [    5] Multi-Master Contention Interrupt Status
                                                                                                               0x0 INACTIVE ssi_mst_intr interrupt not active after masking
                                                                                                               0x1 ACTIVE ssi_mst_intr interrupt is active after masking */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }ISR;
    union { /* 0x0034 [Excel Line :0063]  */
        UINT32 Reg;
        struct {
            UINT32 TXEIR                                                                  : 1;      /* [    0] Transmit FIFO Empty Raw Interrupt Status
                                                                                                               0x0 INACTIVE ssi_txe_intr interrupt is not active prior to masking
                                                                                                               0x1 ACTIVE ssi_txe_intr interrupt is active prior masking */
            UINT32 TXOIR                                                                  : 1;      /* [    1] Transmit FIFO Overflow Raw Interrupt Status
                                                                                                               0x0 INACTIVE ssi_txo_intr interrupt is not active prior to masking
                                                                                                               0x1 ACTIVE ssi_txo_intr interrupt is active prior masking */
            UINT32 RXUIR                                                                  : 1;      /* [    2] Receive FIFO Underflow Raw Interrupt Status
                                                                                                               0x0 INACTIVE ssi_rxu_intr interrupt is not active prior to masking
                                                                                                               0x1 ACTIVE ssi_rxu_intr interrupt is active prior to masking */
            UINT32 RXOIR                                                                  : 1;      /* [    3] Receive FIFO Overflow Raw Interrupt Status
                                                                                                               0x1 ACTIVE ssi_rxo_intr interrupt is not active prior to masking
                                                                                                               0x0 INACTIVE ssi_rxo_intr interrupt is active prior masking */
            UINT32 RXFIR                                                                  : 1;      /* [    4] Receive FIFO Full Raw Interrupt Status
                                                                                                               0x0 INACTIVE ssi_rxf_intr interrupt is not active prior to masking
                                                                                                               0x1 ACTIVE ssi_rxf_intr interrupt is active prior to masking */
            UINT32 MSTIR                                                                  : 1;      /* [    5] Multi-Master Contention Raw Interrupt Status
                                                                                                               0x0 INACTIVE ssi_mst_intr interrupt is not active prior to masking
                                                                                                               0x1 ACTIVE */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }RISR;
    union { /* 0x0038 [Excel Line :0070]  */
        UINT32 Reg;
        struct {
            UINT32 TXOICR                                                                 : 1;      /* [    0] Clear Transmit FIFO Overflow Interrupt
                                                                                                               This register reflects the status of the interrupt A read from this register clears the ssi_txo_intr interrupt writing has no effect */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }TXOICR;
    union { /* 0x003c [Excel Line :0072]  */
        UINT32 Reg;
        struct {
            UINT32 RXOICR                                                                 : 1;      /* [    0] Clear Receive FIFO Overflow Interrupt
                                                                                                               This register reflects the status of the interrupt A read from this register clears the ssi_rxo_intr interrupt writing has no effect */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }RXOICR;
    union { /* 0x0040 [Excel Line :0074]  */
        UINT32 Reg;
        struct {
            UINT32 RXUICR                                                                 : 1;      /* [    0] Clear Receive FIFO Underflow Interrupt
                                                                                                               This register reflects the status of the interrupt A read from this register clears the ssi_rxu_intr interrupt writing has no effect
                                                                                                               Exists */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }RXUICR;
    union { /* 0x0044 [Excel Line :0076]  */
        UINT32 Reg;
        struct {
            UINT32 MSTICR                                                                 : 1;      /* [    0] Clear Multi-Master Contention Interrupt
                                                                                                               This register reflects the status of the interrupt A read from this register clears the ssi_mst_intr interrupt writing has no effect */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }MSTICR;
    union { /* 0x0048 [Excel Line :0078]  */
        UINT32 Reg;
        struct {
            UINT32 ICR                                                                    : 1;      /* [    0] Clear Interrupts
                                                                                                               This register is set if any of the interrupts below are active A read clears the ssi_txo_intr ssi_rxu_intr ssi_rxo_intr and the ssi_mst_intr interrupts Writing to this register has no effect */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }ICR;
    union { /* 0x004c [Excel Line :0080]  */
        UINT32 Reg;
        struct {
            UINT32 RDMAE                                                                  : 1;      /* [    0] Receive DMA Enable
                                                                                                               This bit enablesdisables the receive FIFO DMA channel
                                                                                                               0x0 DISABLE Receive DMA disabled
                                                                                                               0x1 ENABLED Receive DMA enabled */
            UINT32 TDMAE                                                                  : 1;      /* [    1] Transmit DMA Enable
                                                                                                               This bit enablesdisables the transmit FIFO DMA channel
                                                                                                               0x0 DISABLE Transmit DMA disabled
                                                                                                               0x1 ENABLED Transmit DMA enabled */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }DMACR;
    union { /* 0x0050 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 DMATDL                                                                 : 8;      /* [  7:0] Transmit Data Level
                                                                                                               This bit field controls the level at which a DMA request is made by the transmit logic It is equal to the watermark level that is the dma_tx_req signal is generated when the number of valid data entries in the transmit FIFO is equal to or below this field value and TDMAE  1
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }DMATDLR;
    union { /* 0x0054 [Excel Line :0085]  */
        UINT32 Reg;
        struct {
            UINT32 DMARDL                                                                 : 8;      /* [  7:0] Receive Data Level
                                                                                                               This bit field controls the level at which a DMA request is made by the receive logic The watermark level  DMARDL1 that is dma_rx_req is generated when the number of valid data entries in the receive FIFO is equal to or above this field value  1 and RDMAE1
                                                                                                               Note  When in SPI Slave Mode it is used as bits30 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }DMARDLR;
    union { /* 0x0058 [Excel Line :0087]  */
        UINT32 Reg;
        struct {
            UINT32 IDMODE                                                                 : 32;     /* [ 31:0] Identification code */
        }Bit;
    }IDR;
    union { /* 0x005c [Excel Line :0088]  */
        UINT32 Reg;
        struct {
            UINT32 VERSION_ID                                                             : 32;     /* [ 31:0] Contains the hex representation of the Nextchip component version */
        }Bit;
    }VERSION_ID;
    union { /* 0x0060 [Excel Line :0089]  */
        UINT32 Reg;
        struct {
            UINT32 DR                                                                     : 32;     /* [ 31:0] Data RegisterFIFO 
                                                                                                               When writing to this register you must right-justify the data Read data are automatically right-justified
                                                                                                               Read  Receive FIFO buffer Write  Transmit FIFO buffer */
        }Bit;
    }DRX;

    UINT8 EMPTY1[140]; /* 0x8C */

    union { /* 0x00f0 [Excel Line :0090]  */
        UINT32 Reg;
        struct {
            UINT32 RSD                                                                    : 8;      /* [  7:0] Rxd Sample Delay
                                                                                                               This register is used to delay the sample of the rxd input port Each value represents a single ssi_clk delay on the sample of rxd */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }RX_SAMPLE_DLY;
    union { /* 0x00f4 [Excel Line :0092]  */
        UINT32 Reg;
        struct {
            UINT32 TRANS_TYPE                                                             : 2;      /* [  1:0] Address and instruction transfer format
                                                                                                               00 - Instruction and Address will be sent in Standard SPI Mode
                                                                                                               01 - Instruction will be sent in Standard SPI Mode and Address will be sent in the mode specified by CTRLR0SPI_FRF
                                                                                                               10 - Both Instruction and Address will be sent in the mode specified by SPI_FRF 
                                                                                                               11 - Reserved */
            UINT32 ADDR_L                                                                 : 4;      /* [  5:2] Address Length
                                                                                                               This bit defines Length of Address to be transmitted Only after this much bits are programmed in to the FIFO the transfer can begin
                                                                                                               0x0 ADDR_L_0 0-bit Address Width
                                                                                                               0x1 ADDR_L_1 4-bit Address Width
                                                                                                               0x2 ADDR_L_2 8-bit Address Width
                                                                                                               0x3 ADDR_L_3 12-bit Address Width
                                                                                                               0x4 ADDR_L_4 16-bit Address Width
                                                                                                               0x5 ADDR_L_5 20-bit Address Width
                                                                                                               0x6 ADDR_L_6 24-bit Address Width
                                                                                                               0x7 ADDR_L_7 28-bit Address Width
                                                                                                               0x8 ADDR_L_8 32-bit Address Width
                                                                                                               0x9 ADDR_L_9 36-bit Address Width
                                                                                                               0xa ADDR_L_10 40-bit Address Width
                                                                                                               0xb ADDR_L_11 44-bit Address Width
                                                                                                               0xc ADDR_L_12 48-bit Address Width
                                                                                                               0xd ADDR_L_13 52-bit Address Width
                                                                                                               0xe ADDR_L_14 56-bit Address Width
                                                                                                               0xf ADDR_L_15 60-bit Address Width */
            UINT32 RESERVED3                                                              : 2;      /* [  7:6]  */
            UINT32 INST_L                                                                 : 2;      /* [  9:8] Instruction Length
                                                                                                               DualQuadOctal mode instruction length in bits
                                                                                                               0x0 INST_L_0 0-bit No Instruction
                                                                                                               0x1 INST_L_1 4-bit Instruction
                                                                                                               0x2 INST_L_2 8-bit Instruction
                                                                                                               0x3 INST_L_3 16-bit Instruction */
            UINT32 RESERVED2                                                              : 1;      /* [   10]  */
            UINT32 WAIT_CYCLES                                                            : 5;      /* [15:11] Wait cycles
                                                                                                               Number of wait cycles in DualQuadOctal mode between control frames transmit and data reception This value is specified as number of SPI clock cycles */
            UINT32 SPI_DDR_EN                                                             : 1;      /* [   16] SPI DDR Enable bit
                                                                                                               This will enable Dual-data rate transfers in DualQuadOctal frame formats of SPI */
            UINT32 INST_DDR_EN                                                            : 1;      /* [   17] Instruction DDR Enable bit
                                                                                                               This will enable Dual-data rate transfer for Instruction phase */
            UINT32 SPI_RXDS_EN                                                            : 1;      /* [   18] Read data strobe enable bit
                                                                                                               Once this bit is set to 1 DW_apb_ssi will use Read data strobe rxds to capture read data in DDR mode */
            UINT32 RESERVED1                                                              : 13;     /* [31:19]  */
        }Bit;
    }SPI_CTRLR0;
    union { /* 0x00f8 [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 TDE                                                                    : 8;      /* [  7:0] TXD Drive edge
                                                                                                               value of which decides the driving edge of tramit data The maximum value of this regster is  BAUDR2 -1 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }TXD_DRIVE_EDGE;

    UINT8 EMPTY2[4]; /* 0x4 */

    union { /* 0x0100 [Excel Line :0104]  */
        UINT32 Reg;
        struct {
            UINT32 APB_SLV_ERR_EN                                                         : 1;      /* [    0] APB slave error enable
                                                                                                               0  APB slave error disconnect
                                                                                                               1  APB slave error connect */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }APB_SLV_ERR_EN;

    UINT8 EMPTY3[12]; /* 0xC */

    union { /* 0x0110 [Excel Line :0106]  */
        UINT32 Reg;
        struct {
            UINT32 CSN_SEL                                                                : 1;      /* [    0] Slave Select Manual Control Mode Enable
                                                                                                               0x0  Use output of QSPI as Slave Select signal
                                                                                                               0x1  Use CSN_VAL value as Slave Select signal */
            UINT32 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT32 CSN_VAL                                                                : 1;      /* [    4] Manual Slave Select Output
                                                                                                                When CSN_SEL is Low it has no effect 
                                                                                                               0x0  Manual Slave Select Signal is Low
                                                                                                               0x1                                           High */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }CSN_CONTROL;

    UINT8 EMPTY4[12]; /* 0xC */

    union { /* 0x0120 [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 DATA_SWAP                                                              : 3;      /* [  2:0] QSPI Data Swap in DW_QSPI mode
                                                                                                               2 Swap DATA3116 and DATA150
                                                                                                               1 Swap DATA3124 and DATA2316 -- upper 2 bytes
                                                                                                               0 Swap DATA158   and DATA70    -- lower 2 bytes */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }DATA_SWAP;
}DRV_QSPI_REGISTER;
/* PRQA S 828 -- */

#endif /* end of  __DRV_REGISTER_QSPI__ */

