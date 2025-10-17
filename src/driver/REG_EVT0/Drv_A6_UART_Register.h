
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_UART_Register.h
*   Date       : 2020-07-31 11:32
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_UART_H__
#define DRV_REGISTER_UART_H__

#define APACHE_UART_BASE_ADDR1        0x06424000
#define APACHE_UART_BASE_ADDR2        0x06428000
#define APACHE_UART_BASE_ADDR3        0x0642C000
#define APACHE_UART_BASE_ADDR4        0x06430000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 RBR_DLL_THR                                                            : 8;      /* [  7:0] When DLAB Bit LCR7 is 0
                                                                                                                  Write
                                                                                                                     70 Transmitter Buffer Register THR
                                                                                                                  Read
                                                                                                                     70 Receiver Buffer Register RBR
                                                                                                               When DLAB Bit LCR7 is 1
                                                                                                                  RW
                                                                                                                     70 Transmitter Holding Register THR */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_RBR_DLL_THR;
    union { /* 0x0004 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 DLH_IER                                                                : 8;      /* [  7:0] When DLAB Bit LCR7 is 0  IER
                                                                                                                  7  Programmable THRE Interrupt Mode Enable PTIME RW
                                                                                                                         0x0  Disable Programmable THRE Interrupt Mode
                                                                                                                         0x1  Enable Programmable THRE Interrupt Mode
                                                                                                                  65  Reserved bits
                                                                                                                  4  Interrupt Enable RegisterELCOLR RO
                                                                                                                         this bit controls the method for clearing the status in the LSR register
                                                                                                                         0  LSR status bits are cleared either on reading Rx FIFO RBR Read or On reading LSR register Disable ALC
                                                                                                                         1  LSR status bits are cleared only on reading LSR register Enable ALC
                                                                                                                  3  Enable Modem Status Interrupt EDSSI RW
                                                                                                                         This is used to enabledisable the generation of Modem Status Interrupt EDSSI RW
                                                                                                                         This is the fourth highest priority interrupt
                                                                                                                         0x0   Disable Modem Status Interrupt
                                                                                                                         0x1  Enable Modem Status Interrupt
                                                                                                                  2  Enable Receiver Line Status Interrupt ELSI RW
                                                                                                                         This is used to enabledisable the generation of Receiver Line Status Interrupt
                                                                                                                         This is the highest priority interrupt
                                                                                                                         0x0  Disable Receiver Line Status Interrupt
                                                                                                                         0x1  Enable Receiver Line Status Interrupt
                                                                                                                  1  Enable Transmit Holding Register Empty Interrupt ETBEI RW
                                                                                                                         This is used to enabledisable the generation of Transmitter Holding Register Empty Interrupt
                                                                                                                         This is the third highest priority interrupt
                                                                                                                         0x0  Disable Transmit empty interrupt
                                                                                                                         0x1  Enable Transmit empty interrupt
                                                                                                                  0  Enable Received Data Available Interrupt ERBFI RW
                                                                                                                         This is used to enabledisable the generation of Received Data Available Interrupt and the Character Timeout Interrupt
                                                                                                                         0x0  Disable Receive data Interrupt
                                                                                                                         0x1  Enable Receive data Interrupt
                                                                                                               WhenDLAB Bit LCR7 is 1   DLH
                                                                                                                  70 Divisor Latch register that contains the baud rate divisor for the UART DLH RW
                                                                                                                       baud rate  serial clock freq  16  divisor */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_DLH_IER;
    union { /* 0x0008 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 DMAM_XRFIFOR_FIFOE_IID                                                 : 4;      /* [  3:0] Write
                                                                                                               3  DMA Mode DMAM
                                                                                                                         This determines the DMA signalling mode used for the dma_tx_req_n and dma_rx_req_n output signals
                                                                                                                         0x0 MODE0 Mode 0
                                                                                                                         0x1 MODE1 Mode 1
                                                                                                               2  XMIT FIFO Reset XFIFOR
                                                                                                                         This resets the control portion of the transmit FIFO and treats the FIFO as empty
                                                                                                                         0x1 RESET Transmit FIFO reset
                                                                                                               1  RCVR FIFO Reset RFIFOR
                                                                                                                         This resets the control portion of the receive FIFO and treats the FIFO as empty
                                                                                                                         0x1 RESET Receive FIFO reset
                                                                                                               0  FIFO Enable FIFOE
                                                                                                                         This enablesdisables the transmit XMIT and receive RCVR FIFOs
                                                                                                                         0x0 DISABLED FIFO disabled
                                                                                                                         0x1 ENABLED FIFO enabled
                                                                                                               Read
                                                                                                               30  Interrupt ID IID
                                                                                                                         This indicates the highest priority pending interrupt which can be one of the following types specified in Values
                                                                                                                         0x0 MODEM_STATUS modem status
                                                                                                                         0x1 NO_INTERRUPT_PENDING no interrupt pending
                                                                                                                         0x2 THR_EMPTY THR empty
                                                                                                                         0x4 RECEIVED_DATA_AVAILABLE received data available
                                                                                                                         0x6 RECEIVER_LINE_STATUS receiver line status
                                                                                                                         0x7 BUSY_DETECT busy detect
                                                                                                                         0xc CHARACTER_TIMEOUT character timeout */
            UINT32 TET                                                                    : 2;      /* [  5:4] Write
                                                                                                               54  TX Empty Trigger TET
                                                                                                                         This is used to select the empty threshold level at which the THRE Interrupts will be generated when the mode is active
                                                                                                                         0x0 FIFO_EMPTY FIFO Empty
                                                                                                                         0x1 FIFO_CHAR_2 2 characters in FIFO
                                                                                                                         0x2 FIFO_QUARTER_FULL FIFO 14 full
                                                                                                                         0x3 FIFO_HALF_FULL FIFO 12 full
                                                                                                               Read
                                                                                                               54  Reserved bits */
            UINT32 RT_FIFOSE                                                              : 2;      /* [  7:6] Write
                                                                                                               76 RCVR Rtigger RT
                                                                                                                         This is used to select the trigger level in the receiver FIFO at which the Received Data Available Interrupt will be generated
                                                                                                                         0x0 FIFO_CHAR_1 1 character in FIFO
                                                                                                                         0x1 FIFO_QUARTER_FULL FIFO 14 full
                                                                                                                         0x2 FIFO_HALF_FULL FIFO 12 full
                                                                                                                         0x3 FIFO_FULL_2 FIFO 2 less than full
                                                                                                               Read
                                                                                                               76  FIFOs Enabled FIFOSE
                                                                                                                         This is used to indicate whether the FIFOs are enabled or disabled
                                                                                                                         0x0 DISABLED FIFOs are disabled
                                                                                                                         0x3 ENABLED FIFOs are enabled */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_FCR_IIR;
    union { /* 0x000C [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 DLS                                                                    : 2;      /* [  1:0] Data Length Select or CLS as used in legacy
                                                                                                               When DLS_E in LCR_EXT is set to 0 this register is used to select the number of data bits per character that the peripheral will transmit and receive
                                                                                                               0x0 CHAR_5BITS 5 data bits per character
                                                                                                               0x1 CHAR_6BITS 6 data bits per character
                                                                                                               0x2 CHAR_7BITS 7 data bits per character
                                                                                                               0x3 CHAR_8BITS 8 data bits per character */
            UINT32 STOP                                                                   : 1;      /* [    2] Number of stop bits
                                                                                                               This is used to select the number of stop bits per character that the peripheral will transmit and receive
                                                                                                               0x0 STOP_1BIT 1 stop bit
                                                                                                               0x1 STOP_1_5BIT_OR_2BIT 15 stop bits when DLS LCR10 is zero else 2 stop bit */
            UINT32 PEN                                                                    : 1;      /* [    3] Parity Enable
                                                                                                               This bit is used to enable and disable parity generation and detection in transmitted and received serial character respectively
                                                                                                               0x0 DISABLED disable parity
                                                                                                               0x1 ENABLED enable parity */
            UINT32 EPS                                                                    : 1;      /* [    4] Even Parity Select
                                                                                                               This is used to select between even and odd parity when parity is enabled PEN set to one
                                                                                                               0x0 ODD_PARITY an odd parity is transmitted or checked
                                                                                                               0x1 EVEN_PARITY an even parity is transmitted or checked */
            UINT32 SP                                                                     : 1;      /* [    5] Stick Parity
                                                                                                               This bit is used to force parity value
                                                                                                               0x0 DISABLED Stick parity disabled
                                                                                                               0x1 ENABLED Stick parity enabled */
            UINT32 BC                                                                     : 1;      /* [    6] Break Control Bit
                                                                                                               This is used to cause a break condition to be transmitted to the receiving device
                                                                                                               0x0 DISABLED Serial output is released for data transmission
                                                                                                               0x1 ENABLED Serial output is forced to spacing state */
            UINT32 DLAB                                                                   : 1;      /* [    7] Divisor Latch Access Bit
                                                                                                               This bit is used to enable reading and writing of the Divisor Latch register to set the baud rate of the UART
                                                                                                               0x0 DISABLED Divisor Latch register is writable only when UART Not BUSY
                                                                                                               0x1 ENABLED Divisor Latch register is always readable and writable */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_LINE_CTRL;
    union { /* 0x0010 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 DTR                                                                    : 1;      /* [    0] Data Terminal Ready
                                                                                                               This is used to directly control the Data Terminal Ready dtr_n output
                                                                                                               0x0 INACTIVE dtr_n de-asserted logic1
                                                                                                               0x1 ACTIVE dtr_n asserted logic 0 */
            UINT32 RTS                                                                    : 1;      /* [    1] Request to Send
                                                                                                               This is used to directly control the Request to Send rts_n output
                                                                                                               0x0 INACTIVE Request to Send rts_n de-asserted logic 1
                                                                                                               0x1 ACTIVE Request to Send rts_n asserted logic 0 */
            UINT32 OUT1                                                                   : 1;      /* [    2] OUT1
                                                                                                               This is used to directly control the user-designated Output1 out1_n output
                                                                                                               0x0 OUT1_0 out1_n de-asserted logic 1
                                                                                                               0x1 OUT1_1 out1_n asserted logic 0 */
            UINT32 OUT2                                                                   : 1;      /* [    3] OUT2
                                                                                                               This is used to directly control the user-designated Output2 out2_n output
                                                                                                               0x0 OUT2_0 out2_n de-asserted logic 1
                                                                                                               0x1 OUT2_1 out2_n asserted logic 0 */
            UINT32 LOOPBACK                                                               : 1;      /* [    4] LoopBack Bit
                                                                                                               This is used to put the UART into a diagnostic mode for test purposes
                                                                                                               0x0 DISABLED Loopback mode disabled
                                                                                                               0x1 ENABLED Loopback mode enabled */
            UINT32 AFCE                                                                   : 1;      /* [    5] Auto Flow Control Enable
                                                                                                               When FIFOs are enabled and the Auto Flow Control Enable AFCE bit is set Auto Flow Control features are enabled as described in section Auto Flow Control in data book
                                                                                                               0x0 DISABLED Auto Flow Control Mode disabled
                                                                                                               0x1 ENABLED Auto Flow Control Mode enabled */
            UINT32 SIRE                                                                   : 1;      /* [    6] SIR Mode Enable
                                                                                                               This is used to enable disable the IrDA SIR Mode
                                                                                                               0x0 DISABLED IrDA SIR Mode disabled
                                                                                                               0x1 ENABLED IrDA SIR Mode enabled */
            UINT32 RESERVED1                                                              : 25;     /* [ 31:7]  */
        }Bit;
    }UART_MODEM_CTRL;
    union { /* 0x0014 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 DR                                                                     : 1;      /* [    0] Data Ready bit
                                                                                                               This is used to indicate that the receiver contains at least one character in the RBR or the receiver FIFO
                                                                                                               0x0 NOT_READY data not ready
                                                                                                               0x1 READY data ready */
            UINT32 OE                                                                     : 1;      /* [    1] Overrun error bit
                                                                                                               This is used to indicate the occurrence of an overrun error
                                                                                                               0x0 NO_OVER_RUN_ERROR no overrun error
                                                                                                               0x1 OVER_RUN_ERROR overrun error */
            UINT32 PE                                                                     : 1;      /* [    2] Parity Error bit
                                                                                                               This is used to indicate the occurrence of a parity error in the receiver if the Parity Enable PEN bit LCR3 is set
                                                                                                               0x0 NO_PARITY_ERROR no parity error
                                                                                                               0x1 PARITY_ERROR parity error */
            UINT32 FE                                                                     : 1;      /* [    3] Framing Error bit
                                                                                                               This is used to indicate the occurrence of a framing error in the receiver
                                                                                                               0x0 NO_FRAMING_ERROR no framing error
                                                                                                               0x1 FRAMING_ERROR framing error */
            UINT32 BI                                                                     : 1;      /* [    4] Break Interrupt bit
                                                                                                               This is used to indicate the detection of a break sequence on the serial input data
                                                                                                               0x0 NO_BREAK No break sequence detected
                                                                                                               0x1 BREAK Break sequence detected */
            UINT32 THRE                                                                   : 1;      /* [    5] Transmit Holding Register Empty bit
                                                                                                               This bit is set whenever data is transferred from the THR or TX FIFO to the transmitter shift register and no new data has been written to the THR or TX FIFO
                                                                                                               0x0 DISABLED THRE interrupt control is disabled
                                                                                                               0x1 ENABLED THRE interrupt control is enabled */
            UINT32 TEMT                                                                   : 1;      /* [    6] Transmitter Empty bit
                                                                                                               This bit is set whenever the Transmitter Shift Register and the FIFO are both empty
                                                                                                               0x0 DISABLED Transmitter not empty
                                                                                                               0x1 ENABLED Transmitter empty */
            UINT32 RFE                                                                    : 1;      /* [    7] Receiver FIFO Error bit
                                                                                                               This is used to indicate if there is at least one parity error framing error or break indication in the FIFO
                                                                                                               0x0 NO_RX_FIFO_ERROR No error in RX FIFO
                                                                                                               0x1 RX_FIFO_ERROR Error in RX FIFO */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_LINE_STAT;
    union { /* 0x0018 [Excel Line :0042]  */
        UINT32 Reg;
        struct {
            UINT32 DCTS                                                                   : 1;      /* [    0] Delta Clear to Send
                                                                                                               This is used to indicate that the modem control line cts_n has changed since the last time the MSR was read
                                                                                                               0x0 NO_CHANGE no change on cts_n since last read of MSR
                                                                                                               0x1 CHANGE change on cts_n since last read of MSR */
            UINT32 DDSR                                                                   : 1;      /* [    1] Delta Data Set Ready
                                                                                                               This is used to indicate that the modem control line dsr_n has changed since the last time the MSR was read
                                                                                                               0x0 NO_CHANGE no change on dsr_n since last read of MSR
                                                                                                               0x1 CHANGE change on dsr_n since last read of MSR */
            UINT32 TERI                                                                   : 1;      /* [    2] Trailing Edge of Ring Indicator
                                                                                                               This is used to indicate that a change on the input ri_n from an active low to an inactive high state has occurred since the last time the MSR was read
                                                                                                               0x0 NO_CHANGE no change on ri_n since last read of MSR
                                                                                                               0x1 CHANGE change on ri_n since last read of MSR */
            UINT32 DDCD                                                                   : 1;      /* [    3] Delta Data Carrier Detect
                                                                                                               This is used to indicate that the modem control line dcd_n has changed since the last time the MSR was read
                                                                                                               0x0 NO_CHANGE No change on dcd_n since last read of MSR
                                                                                                               0x1 CHANGE change on dcd_n since last read of MSR */
            UINT32 CTS                                                                    : 1;      /* [    4] Clear to Send
                                                                                                               This is used to indicate the current state of the modem control line cts_n
                                                                                                               0x0 DEASSERTED cts_n input is de-asserted logic 1
                                                                                                               0x1 ASSERTED cts_n input is asserted logic 0 */
            UINT32 DSR                                                                    : 1;      /* [    5] Data Set Ready
                                                                                                               This is used to indicate the current state of the modem control line dsr_n
                                                                                                               0x0 DEASSERTED dsr_n input is de-asserted logic 1
                                                                                                               0x1 ASSERTED dsr_n input is asserted logic 0 */
            UINT32 RI                                                                     : 1;      /* [    6] Ring Indicator
                                                                                                               This is used to indicate the current state of the modem control line ri_n
                                                                                                               0x0 DEASSERTED ri_n input is de-asserted logic 1
                                                                                                               0x1 ASSERTED ri_n input is asserted logic 0 */
            UINT32 DCD                                                                    : 1;      /* [    7] Data Carrier Detect
                                                                                                               This is used to indicate the current state of the modem control line dcd_n
                                                                                                               0x0 DEASSERTED dcd_n input is de-asserted logic 1
                                                                                                               0x1 ASSERTED dcd_n input is asserted logic 0 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_MSR;
    union { /* 0x001C [Excel Line :0051]  */
        UINT32 Reg;
        struct {
            UINT32 SCR                                                                    : 8;      /* [  7:0] This register is for programmers to use as a temporary storage space */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_SCR;
    union { /* 0x0020 [Excel Line :0053]  */
        UINT32 Reg;
        struct {
            UINT32 LPDLL                                                                  : 8;      /* [  7:0] Exists SIR_LP_RX  1  SIR_MODE  1
                                                                                                               This register makes up the lower 8-bits of a 16-bit readwrite Low Power Divisor Latch register that contains the baud rate divisor for the UART which must give a baud rate of 1152K
                                                                                                               Low power baud rate  serial clock freq  16  divisor */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_LPDLL;
    union { /* 0x0024 [Excel Line :0055]  */
        UINT32 Reg;
        struct {
            UINT32 LPDLH                                                                  : 8;      /* [  7:0] Exists SIR_LP_RX  1  SIR_MODE  1
                                                                                                               This register makes up the upper 8-bits of a 16-bit readwrite Low Power Divisor Latch register that contains the baud rate divisor for the UART which must give a baud rate of 1152K */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_LPDLH;

    UINT8 EMPTY1[8]; /* 0x8 */

    union { /* 0x0030 [Excel Line :0057]  */
        UINT32 Reg;
        struct {
            UINT32 SRBR_STHR                                                              : 8;      /* [  7:0] When DLAB Bit LCR7 is 0
                                                                                                               Write
                                                                                                               70  Shadow Transmit Holding Register n STHR
                                                                                                               This register contains the data byte received on the serial out port sout in UART mode or the serial infrared output sir_out_n in infrared mode
                                                                                                               Read
                                                                                                               70  Shadow Receive Buffer Register n SRBR
                                                                                                               This register contains the data byte received on the serial input port sin in UART mode or the serial infrared input sir_in in infrared mode  */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_SRBR_STHR;

    UINT8 EMPTY2[60]; /* 0x3C */

    union { /* 0x0070 [Excel Line :0059]  */
        UINT32 Reg;
        struct {
            UINT32 FAR                                                                    : 1;      /* [    0] FIFO Access Register
                                                                                                               0x0 DISABLED FIFO access mode disabled
                                                                                                               0x1 ENABLED FIFO access mode enabled */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_FAR;
    union { /* 0x0074 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 TFR                                                                    : 8;      /* [  7:0] Transmit FIFO Read
                                                                                                               Each consecutive read pops the transmit FIFO and gives the next data value that is currently at the top of the FIFO
                                                                                                               When FIFOs are not implemented or not enabled reading this register gives the data in the THR */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_TFR;
    union { /* 0x0078 [Excel Line :0063]  */
        UINT32 Reg;
        struct {
            UINT32 RFWD                                                                   : 8;      /* [  7:0] Receive FIFO Write Data
                                                                                                               When FIFOs are implemented and enabled the data that is written to the RFWD is pushed into the receive FIFO Each consecutive write pushes the new data to the next write location in the receive FIFO When FIFOs are not implemented or not enabled the data that is written to the RFWD is pushed into the RBR */
            UINT32 RFPE                                                                   : 1;      /* [    8] Receive FIFO Parity Error
                                                                                                               When FIFOs are implemented and enabled this bit is used to write parity error detection information to the receive FIFO When FIFOs are not implemented or not enabled this bit is used to write parity error detection information to the RBR
                                                                                                               0x0 DISABLED Parity error disabled
                                                                                                               0x1 ENABLED Parity error enabled */
            UINT32 RFFE                                                                   : 1;      /* [    9] Receive FIFO Framing Error
                                                                                                               When FIFOs are implemented and enabled this bit is used to write framing error detection information to the receive FIFO When FIFOs are not implemented or not enabled this bit is used to write framing error detection information to the RBR
                                                                                                               0x0 DISABLED Frame error disabled
                                                                                                               0x1 ENABLED Frame error enabled */
            UINT32 RESERVED1                                                              : 22;     /* [31:10]  */
        }Bit;
    }UART_RFW;
    union { /* 0x007C [Excel Line :0067]  */
        UINT32 Reg;
        struct {
            UINT32 BUSY                                                                   : 1;      /* [    0] UART Busy
                                                                                                               This indicates that a serial transfer is in progress when cleared indicates that the DW_apb_uart is idle or inactive
                                                                                                               0x0 IDLE DW_apb_uart is idle or inactive
                                                                                                               0x1 BUSY DW_apb_uart is busy actively transferring data */
            UINT32 TFNF                                                                   : 1;      /* [    1] Transmit FIFO Not Full
                                                                                                               This is used to indicate that the transmit FIFO in not full
                                                                                                               0x0 FULL Transmit FIFO is full
                                                                                                               0x1 NOT_FULL Transmit FIFO is not full */
            UINT32 TFE                                                                    : 1;      /* [    2] Transmit FIFO Empty
                                                                                                               This is used to indicate that the transmit FIFO is completely empty
                                                                                                               0x0 NOT_EMPTY Transmit FIFO is not empty
                                                                                                               0x1 EMPTY Transmit FIFO is empty */
            UINT32 RFNE                                                                   : 1;      /* [    3] Receive FIFO Not Empty
                                                                                                               This is used to indicate that the receive FIFO contains one or more entries
                                                                                                               0x0 EMPTY Receive FIFO is empty
                                                                                                               0x1 NOT_EMPTY Receive FIFO is not empty */
            UINT32 RFF                                                                    : 1;      /* [    4] Receive FIFO Full
                                                                                                               This is used to indicate that the receive FIFO is completely full
                                                                                                               0x0 NOT_FULL Receive FIFO not full
                                                                                                               0x1 FULL Receive FIFO full */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }UART_USR;
    union { /* 0x0080 [Excel Line :0073]  */
        UINT32 Reg;
        struct {
            UINT32 TFL                                                                    : 9;      /* [  8:0] Transmit FIFO Level
                                                                                                               This indicates the number of data entries in the transmit FIFO */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }UART_TFL;
    union { /* 0x0084 [Excel Line :0075]  */
        UINT32 Reg;
        struct {
            UINT32 RFL                                                                    : 9;      /* [  8:0] Receive FIFO Level
                                                                                                               This is indicates the number of data entries in the receive FIFO */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }UART_RFL;
    union { /* 0x0088 [Excel Line :0077]  */
        UINT32 Reg;
        struct {
            UINT32 UR                                                                     : 1;      /* [    0] UART Reset
                                                                                                               This asynchronously resets the DW_apb_uart and synchronously removes the reset assertion
                                                                                                               0x0 NO_RESET No Uart Reset
                                                                                                               0x1 RESET Uart reset */
            UINT32 RFR                                                                    : 1;      /* [    1] RCVR FIFO Reset
                                                                                                               This is a shadow register for the RCVR FIFO Reset bit FCR1 */
            UINT32 XFR                                                                    : 1;      /* [    2] XMIT FIFO Reset
                                                                                                               This is a shadow register for the XMIT FIFO Reset bit FCR2 */
            UINT32 RESERVED1                                                              : 29;     /* [ 31:3]  */
        }Bit;
    }UART_SRR;
    union { /* 0x008C [Excel Line :0081]  */
        UINT32 Reg;
        struct {
            UINT32 SRTS                                                                   : 1;      /* [    0] Shadow Request to Send
                                                                                                               This is used to directly control the Request to Send rts_n output
                                                                                                               0x0 DEASSERTED Shadow Request to Send uart_rts_n logic1
                                                                                                               0x1 ASSERTED Shadow Request to Send uart_rts_n logic0 */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_SRTS;
    union { /* 0x0090 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 SBCB                                                                   : 1;      /* [    0] Shadow Break Control Bit
                                                                                                               This is used to cause a break condition to be transmitted to the receiving device
                                                                                                               0x0 NO_BREAK No spacing on serial output
                                                                                                               0x1 BREAK Serial output forced to the spacing */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_SBCR;
    union { /* 0x0094 [Excel Line :0085]  */
        UINT32 Reg;
        struct {
            UINT32 SDMAM                                                                  : 1;      /* [    0] Shadow DMA Mode
                                                                                                               This can be used to remove the burden of having to store the previously written value to the FCR in memory and having to mask this value so that only the DMA Mode bit gets updated
                                                                                                               0x0 MODE_0 Mode 0
                                                                                                               0x1 MODE_1 Mode 1 */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_SDMAM;
    union { /* 0x0098 [Excel Line :0087]  */
        UINT32 Reg;
        struct {
            UINT32 SFE                                                                    : 1;      /* [    0] Shadow FIFO Enable
                                                                                                               This can be used to remove the burden of having to store the previously written value to the FCR in memory and having to mask this value so that only the FIFO enable bit gets updated
                                                                                                               0x0 DISABLED FIFOs are disabled
                                                                                                               0x1 ENABLED FIFOs are enabled */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_SFE;
    union { /* 0x009C [Excel Line :0089]  */
        UINT32 Reg;
        struct {
            UINT32 SRT                                                                    : 2;      /* [  1:0] Shadow RCVR Trigger
                                                                                                               This can be used to remove the burden of having to store the previously written value to the FCR in memory and having to mask this value so that only the RCVR trigger bit gets updated
                                                                                                               0x0 FIFO_CHAR_1 1 character in FIFO
                                                                                                               0x1 FIFO_QUARTER_FULL FIFO 14 full
                                                                                                               0x2 FIFO_HALF_FULL FIFO 12 full
                                                                                                               0x3 FIFO_FULL_2 FIFO 2 less than full */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }UART_SRT;
    union { /* 0x00A0 [Excel Line :0091]  */
        UINT32 Reg;
        struct {
            UINT32 STET                                                                   : 2;      /* [  1:0] Shadow TX Empty Trigger
                                                                                                               This can be used to remove the burden of having to store the previously written value to the FCR in memory and having to mask this value so that only the TX empty trigger bit gets updated
                                                                                                               0x0 FIFO_EMPTY FIFO empty
                                                                                                               0x1 FIFO_CHAR_2 2 characters in FIFO
                                                                                                               0x2 FIFO_QUARTER_FULL FIFO 14 full
                                                                                                               0x3 FIFO_HALF_FULL FIFO 12 full */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2]  */
        }Bit;
    }UART_STET;
    union { /* 0x00A4 [Excel Line :0093]  */
        UINT32 Reg;
        struct {
            UINT32 HTX                                                                    : 1;      /* [    0] Halt TX
                                                                                                               This register is use to halt transmissions for testing so that the transmit FIFO can be filled by the master when FIFOs are implemented and enabled
                                                                                                               0x0 DISABLED Halt Transmission disabled
                                                                                                               0x1 ENABLED Halt Transmission enabled */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_HTX;
    union { /* 0x00A8 [Excel Line :0095]  */
        UINT32 Reg;
        struct {
            UINT32 DMASA                                                                  : 1;      /* [    0] DMA Software Acknowledge
                                                                                                               This register is use to perform DMA software acknowledge if a transfer needs to be terminated due to an error condition
                                                                                                               0x1 SOFT_ACK DMA software acknowledge */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_DMASA;
    union { /* 0x00AC [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 RS485_EN                                                               : 1;      /* [    0] RS485 Transfer Enable
                                                                                                               0x0  In this mode the transfers are still in the RS232 mode All other fields in this register are reserved and register DE_ENRE_ENTAT are also reserved
                                                                                                               0x1  In this mode the transfers will happen in RS485 mode All other fields of this register are applicable */
            UINT32 RE_POL                                                                 : 1;      /* [    1] Receiver Enable Polarity
                                                                                                               0x1  RE signal is active high
                                                                                                               0x0  RE signal is active low */
            UINT32 DE_POL                                                                 : 1;      /* [    2] Driver Enable Polarity
                                                                                                               0x1  DE signal is active high
                                                                                                               0x0  DE signal is active low */
            UINT32 XFER_MODE                                                              : 2;      /* [  4:3] Transfer Mode
                                                                                                               0x0  In this mode transmit and receive can happen simultaneously
                                                                                                               0x1  In this mode DE and RE are mutually exclusive Either DE or RE only one of them is expected to be enabled through programming
                                                                                                               0x2  In this mode DE and RE are mutually exclusive Once DE_ENRE_EN is programed - by default re will be enabled and DW_apb_uart controller will be ready to receive */
            UINT32 RESERVED1                                                              : 27;     /* [ 31:5]  */
        }Bit;
    }UART_TCR;
    union { /* 0x00B0 [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 DE_EN                                                                  : 1;      /* [    0] DE Enable control
                                                                                                               The DE Enable register bit is used to control assertion and de-assertion of de signal
                                                                                                               0x0  De-assert de signal
                                                                                                               0x1  Assert de signal */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_DE_EN;
    union { /* 0x00B4 [Excel Line :0104]  */
        UINT32 Reg;
        struct {
            UINT32 RE_EN                                                                  : 1;      /* [    0] RE Enable control
                                                                                                               The RE Enable register bit is used to control assertion and de-assertion of re signal
                                                                                                               0x0  De-assert re signal
                                                                                                               0x1  Assert re signal */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1]  */
        }Bit;
    }UART_RE_EN;
    union { /* 0x00B8 [Excel Line :0106]  */
        UINT32 Reg;
        struct {
            UINT32 DE_ASRT_TIME                                                           : 8;      /* [  7:0] Driver Enable assertion time */
            UINT32 RESERVED2                                                              : 8;      /* [ 15:8]  */
            UINT32 DE_DE_ASRT_TIME                                                        : 8;      /* [23:16] Driver Enable de-assertion time */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }UART_DET;
    union { /* 0x00BC [Excel Line :0110]  */
        UINT32 Reg;
        struct {
            UINT32 DE_TO_RE                                                               : 16;     /* [ 15:0] Driver Enable to Receiver Enable TurnAround time
                                                                                                               Turnaround time in terms of serial clock for DE De-assertion to RE assertion */
            UINT32 RE_TO_DE                                                               : 16;     /* [31:16] Receiver Enable to Driver Enable TurnAround time
                                                                                                               Turnaround time in terms of serial clock for RE De-assertion to DE assertion */
        }Bit;
    }UART_TAT;
    union { /* 0x00C0 [Excel Line :0112]  */
        UINT32 Reg;
        struct {
            UINT32 DLF                                                                    : 6;      /* [  5:0] Fractional part of divisor
                                                                                                               The fractional value is added to integer value set by DLH DLL Fractional value is determined by Divisor Fraction value2DLF_SIZE */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }UART_DLF;
    union { /* 0x00C4 [Excel Line :0114]  */
        UINT32 Reg;
        struct {
            UINT32 RAR                                                                    : 8;      /* [  7:0] Receive Address Register
                                                                                                               This is an address matching register during receive mode If the 9-th bit is set in the incoming character then the remaining 8-bits will be checked against this register value If the match happens then sub-sequent characters with 9-th bit set to 0 will be treated as data byte until the next address byte is received */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_RAR;
    union { /* 0x00C8 [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 TAR                                                                    : 8;      /* [  7:0] Transmit Address Register
                                                                                                               This is an address matching register during transmit mode If DLS_E LCR_EXT0 bit is enabled then DW_apb_uart will send the 9-bit character with 9-th bit set to 1 and remaining 8-bit address will be sent from this register provided SEND_ADDR LCR_EXT2 bit is set to 1 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }UART_TAR;
    union { /* 0x00CC [Excel Line :0118]  */
        UINT32 Reg;
        struct {
            UINT32 DLS_E                                                                  : 1;      /* [    0] Extension for DLS
                                                                                                               This bit is used to enable 9-bit data for transmit and receive transfers */
            UINT32 ADDR_MATCH                                                             : 1;      /* [    1] Address Match Mode
                                                                                                               This bit is used to enable the address match feature during receive
                                                                                                               0x1  Address match mode DW_apb_uart will wait until the incoming character with 9-th bit set to 1
                                                                                                               0x0  Normal mode DW_apb_uart will start to receive the data and 9-bit character will be formed and written into the receive RXFIFO */
            UINT32 SEND_ADDR                                                              : 1;      /* [    2] UART_9BIT_DATA_EN  1
                                                                                                               Send address control bit
                                                                                                               This bit is used as a control knob for the user to determine when to send the address during transmit mode
                                                                                                               0x1  9-bit character will be transmitted with 9-th bit set to 1 and the remaining 8-bits will match to what is being programmed in Transmit Address Register
                                                                                                               0x0  9-bit character will be transmitted with 9-th bit set to 0 and the remaining 8-bits will be taken from the TXFIFO which is programmed through 8-bit wide THRSTHR register */
            UINT32 TRANSMIT_MODE                                                          : 1;      /* [    3] Transmit mode control bit
                                                                                                               This bit is used to control the type of transmit mode during 9-bit data transfers
                                                                                                               0x1  In this mode of operation Transmit Holding Register THR and Shadow Transmit Holding Register STHR are 9-bit wide
                                                                                                               0x0  In this mode of operation Transmit Holding Register THR and Shadow Transmit Holding register STHR are 8-bit wide */
            UINT32 RESERVED1                                                              : 28;     /* [ 31:4]  */
        }Bit;
    }UART_EXT;

    UINT8 EMPTY3[36]; /* 0x24 */

    union { /* 0x00F4 [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 APB_DATA_WIDTH                                                         : 2;      /* [  1:0] Encoding of APB_DATA_WIDTH configuration parameter value
                                                                                                               0x0 APB_8BITS APB data width is 8 bits
                                                                                                               0x1 APB_16BITS APB data width is 16 bits
                                                                                                               0x2 APB_32BITS APB data width is 32 bits */
            UINT32 RESERVED3                                                              : 2;      /* [  3:2]  */
            UINT32 AFCE_MODE                                                              : 1;      /* [    4] Encoding of AFCE_MODE configuration parameter value
                                                                                                               0x0 DISABLED AFCE mode disabled
                                                                                                               0x1 ENABLED AFCE mode enabled */
            UINT32 THRE_MODE                                                              : 1;      /* [    5] Encoding of THRE_MODE configuration parameter value
                                                                                                               0x0 DISABLED THRE mode disabled
                                                                                                               0x1 ENABLED THRE mode enabled */
            UINT32 SIR_MODE                                                               : 1;      /* [    6] Encoding of SIR_MODE configuration parameter value
                                                                                                               0x0 DISABLED SIR mode disabled
                                                                                                               0x1 ENABLED SIR mode enabled */
            UINT32 SIR_LP_MODE                                                            : 1;      /* [    7] Encoding of SIR_LP_MODE configuration parameter value
                                                                                                               0x0 DISABLED SIR_LP mode disabled
                                                                                                               0x1 ENABLED SIR_LP mode enabled */
            UINT32 ADDITIONAL_FEAT                                                        : 1;      /* [    8] Encoding of ADDITIONAL_FEATURES configuration parameter value
                                                                                                               0x0 DISABLED Additional features disabled
                                                                                                               0x1 ENABLED Additional features enabled */
            UINT32 FIFO_ACCESS                                                            : 1;      /* [    9] Encoding of FIFO_ACCESS configuration parameter value
                                                                                                               0x0 DISABLED FIFO_ACCESS disabled
                                                                                                               0x1 ENABLED FIFO ACCESS enabled */
            UINT32 FIFO_STAT                                                              : 1;      /* [   10] Encoding of FIFO_STAT configuration parameter value
                                                                                                               0x0 DISABLED FIFO_STAT disabled
                                                                                                               0x1 ENABLED FIFO_STAT enabled */
            UINT32 SHADOW                                                                 : 1;      /* [   11] Encoding of SHADOW configuration parameter value
                                                                                                               0x0 DISABLED SHADOW disabled
                                                                                                               0x1 ENABLED SHADOW enabled */
            UINT32 UART_ADD_ENCODED_PARAMS                                                : 1;      /* [   12] Encoding of UART_ADD_ENCODED_PARAMS configuration parameter value
                                                                                                               0x0 DISABLED UART_ADD_ENCODED_PARAMS disabled
                                                                                                               0x1 ENABLED UART_ADD_ENCODED_PARAMS enabled */
            UINT32 DMA_EXTRA                                                              : 1;      /* [   13] Encoding of DMA_EXTRA configuration parameter value
                                                                                                               0x0 DISABLED DMA_EXTRA disabled
                                                                                                               0x1 ENABLED DMA_EXTRA enabled */
            UINT32 RESERVED2                                                              : 2;      /* [15:14]  */
            UINT32 FIFO_MODE                                                              : 8;      /* [23:16] Encoding of FIFO_MODE configuration parameter value
                                                                                                               0x0 FIFO_MODE_0 FIFO mode is 0
                                                                                                               0x1 FIFO_MODE_16 FIFO mode is 16
                                                                                                               0x2 FIFO_MODE_32 FIFO mode is 32
                                                                                                               0x4 FIFO_MODE_64 FIFO mode is 64
                                                                                                               0x8 FIFO_MODE_128 FIFO mode is 128
                                                                                                               0x10 FIFO_MODE_256 FIFO mode is 256
                                                                                                               0x20 FIFO_MODE_512 FIFO mode is 512
                                                                                                               0x40 FIFO_MODE_1024 FIFO mode is 1024
                                                                                                               0x80 FIFO_MODE_2048 FIFO mode is 2048 */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }UART_CPR;
    union { /* 0x00F8 [Excel Line :0138]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }UART_UCV;
    union { /* 0x00FC [Excel Line :0139]  */
        UINT32 Reg;
        struct {
            UINT32 RESERVED1                                                              : 32;     /* [ 31:0]  */
        }Bit;
    }UART_CTR;
}DRV_UART_REGISTER;
/* PRQA S 828 -- */

/*
 static volatile DRV_UART_REGISTER* const RegA6_UART[4] = {(DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR1, (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR2, (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR3, (DRV_UART_REGISTER*)APACHE_UART_BASE_ADDR4, };
 */



#endif /* end of  __DRV_REGISTER_UART__ */

