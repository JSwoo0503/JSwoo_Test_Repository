/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_DMA330_Register.h
*   Date       : 2020-07-31 11:32
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_DMA330_H__
#define DRV_REGISTER_DMA330_H__

#define APACHE_DMA330_BASE_ADDR1        0x0621C000
#define APACHE_DMA330_BASE_ADDR2        0x06220000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0006]  */
        UINT32 Reg;
        struct {
            UINT32 DMA_STATUS                                                             : 4;      /* [  3:0] The operating state of the DMA manager
                                                                                                                0b0000  Stopped
                                                                                                                0b0001  Executing
                                                                                                                0b0010  Cache miss
                                                                                                                0b0011  Updating PC
                                                                                                                0b0100  Waiting for event
                                                                                                                0b0101-0b1110  reserved
                                                                                                                0b1111  Faulting
                                                                                                                See Operating states on page 2-8 for more information */
            UINT32 WAKEUP_EVENT                                                           : 5;      /* [  8:4] When the DMA manager thread executes a DMAWFE instruction it waits for the following event to occur
                                                                                                                0b00000  event0
                                                                                                                0b00001  event1
                                                                                                                0b00010  event2



                                                                                                                0b11111  event31 */
            UINT32 DNS                                                                    : 1;      /* [    9] Provides the security status of the DMA manager thread
                                                                                                                0  DMA manager operates in the Secure state
                                                                                                                1  DMA manager operates in the Non-secure state
                                                                                                                - Note -
                                                                                                                You must use the boot_manager_ns signal to set the secure state of the DMA manager thread */
            UINT32 RESERVED1                                                              : 22;     /* [31:10] Read UNDEFINED */
        }Bit;
    }DSR;
    union { /* 0x0004 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 PC_MGR                                                                 : 32;     /* [ 31:0] Program counter for the DMA manager thread */
        }Bit;
    }DPC;

    UINT8 EMPTY1[24]; /* 0x18 */

    union { /* 0x0020 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 EVENT_IRQ_SELECT                                                       : 32;     /* [ 31:0] Program the appropriate bit to control how the DMAC responds when it executes DMASEV DMA Send Event
                                                                                                                Bit N  0 If the DMAC executes DMASEV for the event-interrupt resource N then the DMAC signals
                                                                                                                event N to all of the threads Set bit N to 0 if your system design does not use irqN to
                                                                                                                signal an interrupt request
                                                                                                                Bit N  1 If the DMAC executes DMASEV for the event-interrupt resource N then the DMAC sets
                                                                                                                irqN HIGH Set bit N to 1 if your system design requires irqN to signal an interrupt
                                                                                                                request
                                                                                                                - Note -
                                                                                                                See DMASEV on page 4-14 for information about selecting an event number */
        }Bit;
    }INTEN;
    union { /* 0x0024 [Excel Line :0012]  */
        UINT32 Reg;
        struct {
            UINT32 DMASEV_ACTIVE                                                          : 32;     /* [ 31:0] Returns the status of the event-interrupt resources
                                                                                                                Bit N  0 Event N is inactive or irqN is LOW
                                                                                                                Bit N  1 Event N is active or irqN is HIGH
                                                                                                                Note
                                                                                                                When the DMAC executes a DMASEV N instruction to send event N the INTEN Register
                                                                                                                controls whether the DMAC
                                                                                                                - Signals an interrupt using the appropriate irq
                                                                                                                - Sends the event to all of the threads
                                                                                                                See Interrupt Enable Register on page 3-13
                                                                                                                - Note -
                                                                                                                The DMAC clears bit N when either
                                                                                                                - The INTEN Register is programmed to process the event and the DMAC executes a DMAWFE instruction for that event
                                                                                                                - The INTEN Register is programmed to signal an interrupt and you write to the corresponding bit in the INTCLR Register see Interrupt Clear Register on page 3-15 */
        }Bit;
    }INT_EVENT_RIS;
    union { /* 0x0028 [Excel Line :0013]  */
        UINT32 Reg;
        struct {
            UINT32 IRQ_STATUS                                                             : 32;     /* [ 31:0] Provides the status of the interrupts that are active in the DMAC
                                                                                                                Bit N  0 Interrupt N is inactive and therefore irqN is LOW
                                                                                                                Bit N  1 Interrupt N is active and therefore irqN is HIGH
                                                                                                                - Note -
                                                                                                                You must use the INTCLR Register to set bit N to 0 see Interrupt Clear Register
                                                                                                                - Note -
                                                                                                                Bit N is 0 if the INTEN Register programs DMASEV to signal an event see Interrupt Enable Register on page 3-13 */
        }Bit;
    }INTMIS;
    union { /* 0x002C [Excel Line :0014]  */
        UINT32 Reg;
        struct {
            UINT32 IRQ_CLR                                                                : 32;     /* [ 31:0] Controls the clearing of the irq outputs
                                                                                                                Bit N  0 The status of irqN does not change
                                                                                                                Bit N  1 The DMAC sets irqN LOW if the INTEN Register programs the DMAC to signal an interrupt
                                                                                                                Otherwise the status of irqN does not change See Interrupt Enable Register on page 3-13 */
        }Bit;
    }INTCLR;
    union { /* 0x0030 [Excel Line :0015]  */
        UINT32 Reg;
        struct {
            UINT32 FS_MGR                                                                 : 1;      /* [    0] Provides the fault status of the DMA manager Read as
                                                                                                                0  the DMA manager thread is not in the Faulting state
                                                                                                                1  the DMA manager thread is in the Faulting state See Fault Type DMA Manager Register on page 3-17 for
                                                                                                                information about the type of fault that occurred */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1] Reserved read UNDEFINED */
        }Bit;
    }FSRD;
    union { /* 0x0034 [Excel Line :0017]  */
        UINT32 Reg;
        struct {
            UINT32 FAULT_STATUS                                                           : 8;      /* [  7:0] Each bit provides the fault status of the corresponding channel Read as
                                                                                                                Bit N  0 No fault is present on DMA channel N
                                                                                                                Bit N  1 DMA channel N is in the Faulting or Faulting completing state See Fault Type DMA Channel
                                                                                                                Registers on page 3-18 for information about the type of fault that occurred */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }FSRC;
    union { /* 0x0038 [Excel Line :0019]  */
        UINT32 Reg;
        struct {
            UINT32 UNDEF_INSTR                                                            : 1;      /* [    0] Indicates whether the DMA manager was attempting to execute an undefined instruction
                                                                                                                0  defined instruction
                                                                                                                1  undefined instruction */
            UINT32 OPERAND_INVALID                                                        : 1;      /* [    1] Indicates whether the DMA manager was attempting to execute an instruction operand that was not valid
                                                                                                                for the configuration of the DMAC
                                                                                                                0  valid operand
                                                                                                                1  invalid operand */
            UINT32 RESERVED4                                                              : 2;      /* [  3:2] Read UNDEFINED */
            UINT32 DMAGO_ERR                                                              : 1;      /* [    4] Indicates whether the DMA manager was attempting to execute DMAGO with inappropriate security
                                                                                                                permissions
                                                                                                                0  the DMA manager has appropriate security to execute DMAGO
                                                                                                                1  a DMA manager thread in the Non-secure state attempted to execute DMAGO to create a DMA channel
                                                                                                                operating in the Secure state */
            UINT32 MGR_EVNT_ERR                                                           : 1;      /* [    5] Indicates whether the DMA manager was attempting to execute DMAWFE or DMASEV with inappropriate
                                                                                                                security permissions
                                                                                                                0  the DMA manager has appropriate security to execute DMAWFE or DMASEV
                                                                                                                1  a DMA manager thread in the Non-secure state attempted to execute either
                                                                                                                 DMAWFE to wait for a secure event
                                                                                                                 DMASEV to create a secure event or secure interrupt */
            UINT32 RESERVED3                                                              : 10;     /* [ 15:6] Read UNDEFINED */
            UINT32 INSTR_FETCH_ERR                                                        : 1;      /* [   16] Indicates the AXI response that the DMAC receives on the RRESP bus after the DMA manager
                                                                                                                performs an instruction fetch
                                                                                                                0  OKAY response
                                                                                                                1  EXOKAY SLVERR or DECERR response */
            UINT32 RESERVED2                                                              : 13;     /* [29:17] Read UNDEFINED */
            UINT32 DBG_INSTR                                                              : 1;      /* [   30] If the DMA manager aborts this bit indicates whether the erroneous instruction was read from the
                                                                                                                system memory or from the debug interface
                                                                                                                0  instruction that generated an abort was read from system memory
                                                                                                                1  instruction that generated an abort was read from the debug interface */
            UINT32 RESERVED1                                                              : 1;      /* [   31] Read UNDEFINED */
        }Bit;
    }FTRD;

    UINT8 EMPTY2[4]; /* 0x4 */

    /* GROUP Start : DMA330_FTR */
    struct {
         union { /* 0x0040 [Excel Line :0029]  */
             UINT32 Reg;
             struct {
                 UINT32 UNDEF_INSTR                                                       : 1;      /* [    0] Indicates whether the DMA channel thread was attempting to execute an undefined instruction
                                                                                                                0  defined instruction
                                                                                                                1  undefined instruction
                                                                                                                This fault is a precise abort */
                 UINT32 OPERAND_INVALID                                                   : 1;      /* [    1] Indicates whether the DMA channel thread was attempting to execute an instruction operand that was
                                                                                                                not valid for the configuration of the DMAC
                                                                                                                0  valid operand
                                                                                                                1  invalid operand
                                                                                                                This fault is a precise abort */
                 UINT32 RESERVED4                                                         : 3;      /* [  4:2] Reserved read UNDEFINED */
                 UINT32 CH_EVNT_ERR                                                       : 1;      /* [    5] Indicates whether the DMA channel thread attempts to execute DMAWFE or DMASEV with inappropriate
                                                                                                                security permissions
                                                                                                                0  a DMA channel thread in the Non-secure state is not violating the security permissions
                                                                                                                1  a DMA channel thread in the Non-secure state attempted to execute either
                                                                                                                 DMAWFE to wait for a secure event
                                                                                                                 DMASEV to create a secure event or secure interrupt
                                                                                                                This fault is a precise abort */
                 UINT32 CH_PERIPH_ERR                                                     : 1;      /* [    6] Indicates whether a DMA channel thread in the Non-secure state attempts to execute DMAWFP DMALDP
                                                                                                                DMASTP or DMAFLUSHP with inappropriate security permissions
                                                                                                                0  a DMA channel thread in the Non-secure state is not violating the security permissions
                                                                                                                1  a DMA channel thread in the Non-secure state attempted to execute either
                                                                                                                 DMAWFP to wait for a secure peripheral
                                                                                                                 DMALDP or DMASTP to notify a secure peripheral
                                                                                                                 DMAFLUSHP to flush a secure peripheral
                                                                                                                This fault is a precise abort */
                 UINT32 CH_RDWR_ERR                                                       : 1;      /* [    7] Indicates whether a DMA channel thread in the Non-secure state attempts to program the CCRn
                                                                                                                Register to perform a secure read or secure write
                                                                                                                0  a DMA channel thread in the Non-secure state is not violating the security permissions
                                                                                                                1  a DMA channel thread in the Non-secure state attempted to perform a secure read or secure write
                                                                                                                This fault is a precise abort */
                 UINT32 RESERVED3                                                         : 4;      /* [ 11:8] Reserved read UNDEFINED */
                 UINT32 MFIFO_ERR                                                         : 1;      /* [   12] Indicates whether the MFIFO prevented the DMA channel thread from executing DMALD or DMAST
                                                                                                                Depending on the instruction
                                                                                                                DMALD 0  MFIFO contains sufficient space
                                                                                                                1  MFIFO is too small to hold the data that DMALD requires
                                                                                                                DMAST 0  MFIFO contains sufficient data
                                                                                                                1  MFIFO is too small to store the data to enable DMAST to complete
                                                                                                                This fault is an imprecise abort */
                 UINT32 ST_DATA_UNAVAILABLE                                               : 1;      /* [   13] Indicates whether the MFIFO did not contain the data to enable the DMAC to perform the DMAST
                                                                                                                0  MFIFO contains all the data to enable the DMAST to complete
                                                                                                                1  previous DMALDs have not put enough data in the MFIFO to enable the DMAST to complete
                                                                                                                This fault is a precise abort */
                 UINT32 RESERVED2                                                         : 2;      /* [15:14] Reserved read UNDEFINED */
                 UINT32 INSTR_FETCH_ERR                                                   : 1;      /* [   16] Indicates the AXI response that the DMAC receives on the RRESP bus after the DMA channel
                                                                                                                thread performs an instruction fetch
                                                                                                                0  OKAY response
                                                                                                                1  EXOKAY SLVERR or DECERR response
                                                                                                                This fault is a precise abort */
                 UINT32 DATA_WRITE_ERR                                                    : 1;      /* [   17] Indicates the AXI response that the DMAC receives on the BRESP bus after the DMA channel
                                                                                                                thread performs a data write
                                                                                                                0  OKAY response
                                                                                                                1  EXOKAY SLVERR or DECERR response
                                                                                                                This fault is an imprecise abort */
                 UINT32 DATA_READ_ERR                                                     : 1;      /* [   18] Indicates the AXI response that the DMAC receives on the RRESP bus after the DMA channel
                                                                                                                thread performs a data read
                                                                                                                0  OKAY response
                                                                                                                1  EXOKAY SLVERR or DECERR response
                                                                                                                This fault is an imprecise abort */
                 UINT32 RESERVED1                                                         : 11;     /* [29:19] Reserved read UNDEFINED */
                 UINT32 DBG_INSTR                                                         : 1;      /* [   30] If the DMA channel aborts this bit indicates whether the erroneous instruction was read from the
                                                                                                                system memory or from the debug interface
                                                                                                                0  instruction that generated an abort was read from system memory
                                                                                                                1  instruction that generated an abort was read from the debug interface
                                                                                                                This fault is an imprecise abort but the bit is only valid when a precise abort occurs */
                 UINT32 LOCKUP_ERR                                                        : 1;      /* [   31] Indicates whether the DMA channel has locked-up because of resource starvation
                                                                                                                0  DMA channel has adequate resources
                                                                                                                1  DMA channel has locked-up because of insufficient resources
                                                                                                                This fault is an imprecise abort */
             }Bit;
         }FTR;
    }DMA330_FTR[8];

    UINT8 EMPTY3[160]; /* 0xA0 */

    /* GROUP Start : DMA330_THR_ST */
    struct {
         union { /* 0x0100 [Excel Line :0157]  */
             UINT32 Reg;
             struct {
                 UINT32 CHANNEL_STATUS                                                    : 4;      /* [  3:0] The channel status encoding is
                                                                                                                0b0000  Stopped
                                                                                                                0b0001  Executing
                                                                                                                0b0010  Cache miss
                                                                                                                0b0011  Updating PC
                                                                                                                0b0100  Waiting for event
                                                                                                                0b0101  At barrier
                                                                                                                0b0110  reserved
                                                                                                                0b0111  Waiting for peripheral
                                                                                                                0b1000  Killing
                                                                                                                0b1001  Completing
                                                                                                                0b1010-0b1101  reserved
                                                                                                                0b1110  Faulting completing
                                                                                                                0b1111  Faulting
                                                                                                                See Operating states on page 2-8 for more information */
                 UINT32 WAKEUP_NUMBER                                                     : 5;      /* [  8:4] If the DMA channel is in the Waiting for event state or the Waiting for peripheral state then these bits
                                                                                                                indicate the event or peripheral number that the channel is waiting for
                                                                                                                0b00000  DMA channel is waiting for event or peripheral 0
                                                                                                                0b00001  DMA channel is waiting for event or peripheral 1
                                                                                                                0b00010  DMA channel is waiting for event or peripheral 2



                                                                                                                0b11111  DMA channel is waiting for event or peripheral 31 */
                 UINT32 RESERVED3                                                         : 5;      /* [ 13:9] Reserved read UNDEFINED */
                 UINT32 DMAWFP_B_NS                                                       : 1;      /* [   14] When the DMA channel thread executes DMAWFP this bit indicates whether the burst or single operand
                                                                                                                were set
                                                                                                                0  DMAWFP executed with the single operand set
                                                                                                                1  DMAWFP executed with the burst operand set
                                                                                                                See DMAWFP on page 4-18 */
                 UINT32 DMAWFP_PERIPH                                                     : 1;      /* [   15] When the DMA channel thread executes DMAWFP this bit indicates whether the periph operand was set
                                                                                                                0  DMAWFP executed with the periph operand not set
                                                                                                                1  DMAWFP executed with the periph operand set
                                                                                                                See DMAWFP on page 4-18 */
                 UINT32 RESERVED2                                                         : 5;      /* [20:16] Reserved read UNDEFINED */
                 UINT32 CNS                                                               : 1;      /* [   21] The channel non-secure bit provides the security of the DMA channel
                                                                                                                0  DMA channel operates in the Secure state
                                                                                                                1  DMA channel operates in the Non-secure state
                                                                                                                Note
                                                                                                                The DMAGO instruction determines the security state of a DMA channel See DMAGO on page 4-6 */
                 UINT32 RESERVED1                                                         : 10;     /* [31:22] Reserved read UNDEFINED */
             }Bit;
         }CSR;
         union { /* 0x0104 [Excel Line :0165]  */
             UINT32 Reg;
             struct {
                 UINT32 PC_CHNL                                                           : 32;     /* [ 31:0] Program counter for the DMA channel n thread where n depends on the address
                                                                                                                of the register See Figure 3-13 */
             }Bit;
         }CPC;
    }DMA330_THR_ST[8];

    UINT8 EMPTY4[704]; /* 0x2C0 */

    /* GROUP Start : DMA330_BUS_AND_CNT_ST */
    struct {
         union { /* 0x0400 [Excel Line :0229]  */
             UINT32 Reg;
             struct {
                 UINT32 SRC_ADDR                                                          : 32;     /* [ 31:0] Address of the source data for DMA channel n where n depends on the address
                                                                                                                of the register See Figure 3-14 */
             }Bit;
         }SAR;
         union { /* 0x0404 [Excel Line :0230]  */
             UINT32 Reg;
             struct {
                 UINT32 DST_ADDR                                                          : 32;     /* [ 31:0] Address for the destination data for DMA channel n where n depends on the
                                                                                                                address of the register See Figure 3-15 on page 3-24 */
             }Bit;
         }DAR;
         union { /* 0x0408 [Excel Line :0231]  */
             UINT32 Reg;
             struct {
                 UINT32 SRC_INC                                                           : 1;      /* [    0] Programs the burst type that the DMAC performs when it reads the source data
                                                                                                                0  Fixed-address burst The DMAC signals ARBURST0 LOW
                                                                                                                1  Incrementing-address burst The DMAC signals ARBURST0 HIGH */
                 UINT32 SRC_BURST_SIZE                                                    : 3;      /* [  3:1] For each beat within a burst it programs the number of bytes that the DMAC reads from the source
                                                                                                                0b000  reads 1 byte per beat
                                                                                                                0b001  reads 2 bytes per beat
                                                                                                                0b010  reads 4 bytes per beat
                                                                                                                0b011  reads 8 bytes per beat
                                                                                                                0b100  reads 16 bytes per beat
                                                                                                                0b101-0b111  reserved
                                                                                                                The total number of bytes that the DMAC reads into the MFIFO when it executes a DMALD instruction
                                                                                                                is the product of src_burst_len and src_burst_size
                                                                                                                Note
                                                                                                                These bits control the state of ARSIZE20 */
                 UINT32 SRC_BURST_LEN                                                     : 4;      /* [  7:4] For each burst these bits program the number of data transfers that the DMAC performs when it reads
                                                                                                                the source data
                                                                                                                0b0000  1 data transfer
                                                                                                                0b0001  2 data transfers
                                                                                                                0b0010  3 data transfers



                                                                                                                0b1111  16 data transfers
                                                                                                                The total number of bytes that the DMAC reads into the MFIFO when it executes a DMALD instruction
                                                                                                                is the product of src_burst_len and src_burst_size
                                                                                                                Note
                                                                                                                These bits control the state of ARLEN30 */
                 UINT32 SRC_PROT_CTRL                                                     : 3;      /* [ 10:8] Programs the state of ARPROT20a when the DMAC reads the source data
                                                                                                                Bit 10 0  ARPROT2 is LOW
                                                                                                                1  ARPROT2 is HIGH
                                                                                                                Bit 9 0  ARPROT1 is LOW
                                                                                                                1  ARPROT1 is HIGH
                                                                                                                Bit 8 0  ARPROT0 is LOW
                                                                                                                1  ARPROT0 is HIGH
                                                                                                                Note
                                                                                                                Only DMA channels in the Secure state can program ARPROT1 LOW that is a secure access If a
                                                                                                                DMA channel in the Non-secure state attempts to set ARPROT1 LOW the DMA channel aborts */
                 UINT32 SRC_CACHE_CTRL                                                    : 3;      /* [13:11] Set the bits to control the state of ARCACHE20a when the DMAC reads the source data
                                                                                                                Bit 13 0  ARCACHE2 is LOW
                                                                                                                1  ARCACHE2 is HIGH
                                                                                                                Bit 12 0  ARCACHE1 is LOW
                                                                                                                1  ARCACHE1 is HIGH
                                                                                                                Bit 11 0  ARCACHE0 is LOW
                                                                                                                1  ARCACHE0 is HIGH
                                                                                                                Note
                                                                                                                The DMAC ties ARCACHE3 LOW
                                                                                                                Setting ARCACHE210b10 violates the AXI protocol See the AMBA AXI and ACE Protocol
                                                                                                                Specification */
                 UINT32 DST_INC                                                           : 1;      /* [   14] Programs the burst type that the DMAC performs when it writes the destination data
                                                                                                                0  Fixed-address burst The DMAC signals AWBURST0 LOW
                                                                                                                1  Incrementing-address burst The DMAC signals AWBURST0 HIGH */
                 UINT32 DST_BURST_SIZE                                                    : 3;      /* [17:15] For each beat within a burst it programs the number of bytes that the DMAC writes to the destination
                                                                                                                0b000  writes 1 byte per beat
                                                                                                                0b001  writes 2 bytes per beat
                                                                                                                0b010  writes 4 bytes per beat
                                                                                                                0b011  writes 8 bytes per beat
                                                                                                                0b100  writes 16 bytes per beat
                                                                                                                0b101-0b111  reserved
                                                                                                                The total number of bytes that the DMAC writes out of the MFIFO when it executes a DMAST instruction
                                                                                                                is the product of dst_burst_len and dst_burst_size
                                                                                                                Note
                                                                                                                These bits control the state of AWSIZE20 */
                 UINT32 DST_BURST_LEN                                                     : 4;      /* [21:18] For each burst these bits program the number of data transfers that the DMAC performs when it writes
                                                                                                                the destination data
                                                                                                                0b0000  1 data transfer
                                                                                                                0b0001  2 data transfers
                                                                                                                0b0010  3 data transfers



                                                                                                                0b1111  16 data transfers
                                                                                                                The total number of bytes that the DMAC writes out of the MFIFO when it executes a DMAST instruction
                                                                                                                is the product of dst_burst_len and dst_burst_size
                                                                                                                Note
                                                                                                                These bits control the state of AWLEN30 */
                 UINT32 DST_PROT_CTRL                                                     : 3;      /* [24:22] Programs the state of AWPROT20a when the DMAC writes the destination data
                                                                                                                Bit 24 0  AWPROT2 is LOW
                                                                                                                1  AWPROT2 is HIGH
                                                                                                                Bit 23 0  AWPROT1 is LOW
                                                                                                                1  AWPROT1 is HIGH
                                                                                                                Bit 22 0  AWPROT0 is LOW
                                                                                                                1  AWPROT0 is HIGH
                                                                                                                Note
                                                                                                                Only DMA channels in the Secure state can program AWPROT1 LOW that is a secure access If
                                                                                                                a DMA channel in the Non-secure state attempts to set AWPROT1 LOW then the DMA channel
                                                                                                                aborts */
                 UINT32 DST_CACHE_CTRL                                                    : 3;      /* [27:25] Programs the state of AWCACHE310a when the DMAC writes the destination data
                                                                                                                Bit 27 0  AWCACHE3 is LOW
                                                                                                                1  AWCACHE3 is HIGH
                                                                                                                Bit 26 0  AWCACHE1 is LOW
                                                                                                                1  AWCACHE1 is HIGH
                                                                                                                Bit 25 0  AWCACHE0 is LOW
                                                                                                                1  AWCACHE0 is HIGH
                                                                                                                Note
                                                                                                                AWCACHE2 is tied LOW by the DMAC
                                                                                                                Setting AWCACHE310b10 violates the AXI protocol See the AMBA AXI and ACE Protocol
                                                                                                                Specification */
                 UINT32 ENDIAN_SWAP_SIZE                                                  : 3;      /* [30:28] See Endian swap size on page 3-28 */
                 UINT32 RESERVED1                                                         : 1;      /* [   31] Reserved read UNDEFINED */
             }Bit;
         }CCR;
         union { /* 0x040C [Excel Line :0243]  */
             UINT32 Reg;
             struct {
                 UINT32 LOOP_COUNTER_ITERATIONS                                           : 8;      /* [  7:0] The number of loop counter iterations */
                 UINT32 RESERVED1                                                         : 24;     /* [ 31:8] Reserved read UNDEFINED */
             }Bit;
         }LC0;
         union { /* 0x0410 [Excel Line :0245]  */
             UINT32 Reg;
             struct {
                 UINT32 LOOP_COUNTER_ITERATIONS                                           : 8;      /* [  7:0] The number of loop counter iterations */
                 UINT32 RESERVED1                                                         : 24;     /* [ 31:8] Reserved read UNDEFINED */
             }Bit;
         }LC1;
         union { /* 0x0414 [Excel Line :0247]  */
             UINT32 Reg;
             struct {
                 UINT32 RESERVED1                                                         : 32;     /* [ 31:0]  */
             }Bit;
         }RESERVED0;
         union { /* 0x0418 [Excel Line :0248]  */
             UINT32 Reg;
             struct {
                 UINT32 RESERVED1                                                         : 32;     /* [ 31:0]  */
             }Bit;
         }RESERVED1;
         union { /* 0x041C [Excel Line :0249]  */
             UINT32 Reg;
             struct {
                 UINT32 RESERVED1                                                         : 32;     /* [ 31:0]  */
             }Bit;
         }RESERVED2;
    }DMA330_BUS_AND_CNT_ST[8];

    UINT8 EMPTY5[2048]; /* 0x800 */

    union { /* 0x0D00 [Excel Line :0397]  */
        UINT32 Reg;
        struct {
            UINT32 DBGSTATUS                                                              : 1;      /* [    0] The debug status encoding is
                                                                                                                0  Idle
                                                                                                                1  Busy */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1] Reserved read UNDEFINED */
        }Bit;
    }DBGSTATUS;
    union { /* 0x0D04 [Excel Line :0399]  */
        UINT32 Reg;
        struct {
            UINT32 DBGCMD                                                                 : 2;      /* [  1:0] The debug encoding is as follows
                                                                                                                0b00  execute the instruction that the DBGINST 10 Registers contain
                                                                                                                0b01  reserved
                                                                                                                0b10  reserved
                                                                                                                0b11  reserved */
            UINT32 RESERVED1                                                              : 30;     /* [ 31:2] Reserved Write as zero */
        }Bit;
    }DBGCMD;
    union { /* 0x0D08 [Excel Line :0401]  */
        UINT32 Reg;
        struct {
            UINT32 DEBUG_THREAD                                                           : 1;      /* [    0] The debug thread encoding is as follows
                                                                                                                0  DMA manager thread
                                                                                                                1  DMA channel
                                                                                                                Note
                                                                                                                When set to 1 the Channel number field selects the DMA channel to debug */
            UINT32 RESERVED2                                                              : 7;      /* [  7:1] Reserved Write as zero */
            UINT32 CHANNEL_NUMBER                                                         : 3;      /* [ 10:8] DMA channel number
                                                                                                                0b000  DMA channel 0
                                                                                                                0b001  DMA channel 1
                                                                                                                0b010  DMA channel 2



                                                                                                                0b111  DMA channel 7 */
            UINT32 RESERVED1                                                              : 5;      /* [15:11] Reserved Write as zero */
            UINT32 INSTRUCTION_BYTE_0                                                     : 8;      /* [23:16] Instruction byte 0 */
            UINT32 INSTRUCTION_BYTE_1                                                     : 8;      /* [31:24] Instruction byte 1 */
        }Bit;
    }DBGINST0;
    union { /* 0x0D0C [Excel Line :0407]  */
        UINT32 Reg;
        struct {
            UINT32 INSTRUCTION_BYTE_2                                                     : 8;      /* [  7:0] Instruction byte 2 */
            UINT32 INSTRUCTION_BYTE_3                                                     : 8;      /* [ 15:8] Instruction byte 3 */
            UINT32 INSTRUCTION_BYTE_4                                                     : 8;      /* [23:16] Instruction byte 4 */
            UINT32 INSTRUCTION_BYTE_5                                                     : 8;      /* [31:24] Instruction byte 5 */
        }Bit;
    }DBGINST1;

    UINT8 EMPTY6[240]; /* 0xF0 */

    union { /* 0x0E00 [Excel Line :0411]  */
        UINT32 Reg;
        struct {
            UINT32 PERIPH_REQ                                                             : 1;      /* [    0] Supports peripheral requests
                                                                                                                0  the DMAC does not provide a peripheral request interface
                                                                                                                1  the DMAC provides the number of peripheral request interfaces that the num_periph_req field
                                                                                                                specifies */
            UINT32 BOOT_EN                                                                : 1;      /* [    1] Indicates the status of the boot_from_pc signal when the DMAC exited from reset
                                                                                                                0  boot_from_pc was LOW
                                                                                                                1  boot_from_pc was HIGH */
            UINT32 MGR_NS_AT_RST                                                          : 1;      /* [    2] Indicates the status of the boot_manager_ns signal when the DMAC exited from reset
                                                                                                                0  boot_manager_ns was LOW
                                                                                                                1  boot_manager_ns was HIGH */
            UINT32 RESERVED3                                                              : 1;      /* [    3] Reserved read UNDEFINED */
            UINT32 NUM_CHNLS                                                              : 3;      /* [  6:4] Number of DMA channels that the DMAC supports
                                                                                                                0b000  1 DMA channel
                                                                                                                0b001  2 DMA channels
                                                                                                                0b010  3 DMA channels



                                                                                                                0b111  8 DMA channels */
            UINT32 RESERVED2                                                              : 5;      /* [ 11:7] Reserved read UNDEFINED */
            UINT32 NUM_PERIPH_REQ                                                         : 5;      /* [16:12] Number of peripheral request interfaces that the DMAC provides
                                                                                                                0b00000  1 peripheral request interface
                                                                                                                0b00001  2 peripheral request interfaces
                                                                                                                0b00010  3 peripheral request interfaces



                                                                                                                0b11111  32 peripheral request interfaces
                                                                                                                Note
                                                                                                                This field is only valid when the periph_req bit is set to 1 */
            UINT32 NUM_EVENTS                                                             : 5;      /* [21:17] Number of interrupt outputs that the DMAC provides
                                                                                                                0b00000  1 interrupt output irq0
                                                                                                                0b00001  2 interrupt outputs irq10
                                                                                                                0b00010  3 interrupt outputs irq20



                                                                                                                0b11111  32 interrupt outputs irq310 */
            UINT32 RESERVED1                                                              : 10;     /* [31:22] Reserved read UNDEFINED */
        }Bit;
    }CR0;
    union { /* 0x0E04 [Excel Line :0420]  */
        UINT32 Reg;
        struct {
            UINT32 I_CACHE_LEN                                                            : 3;      /* [  2:0] The length of an i-cache line
                                                                                                                0b000-0b001  reserved
                                                                                                                0b010  4 bytes
                                                                                                                0b011  8 bytes
                                                                                                                0b100  16 bytes
                                                                                                                0b101  32 bytes
                                                                                                                0b110-0b111  reserved */
            UINT32 RESERVED2                                                              : 1;      /* [    3] Reserved read UNDEFINED */
            UINT32 NUM_I_CACHE_LINES                                                      : 4;      /* [  7:4] Number of i-cache lines
                                                                                                                0b0000  1 i-cache line
                                                                                                                0b0001  2 i-cache lines
                                                                                                                0b0010  3 i-cache lines



                                                                                                                0b1111  16 i-cache lines */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }CR1;
    union { /* 0x0E08 [Excel Line :0424]  */
        UINT32 Reg;
        struct {
            UINT32 BOOT_ADDR                                                              : 32;     /* [ 31:0] Provides the value of boot_addr310 when the DMAC exited from reset */
        }Bit;
    }CR2;
    union { /* 0x0E0C [Excel Line :0425]  */
        UINT32 Reg;
        struct {
            UINT32 INS                                                                    : 32;     /* [ 31:0] Provides the security state of an event-interrupt resource
                                                                                                                Bit N  0 EventN or irqN is in the Secure state
                                                                                                                Bit N  1 EventN or irqN is in the Non-secure state
                                                                                                                Note
                                                                                                                The boot_irq_nsx0 signals initialize the bits in this register when the DMAC exits from reset See Table A-12
                                                                                                                on page A-9 for more information */
        }Bit;
    }CR3;
    union { /* 0x0E10 [Excel Line :0426]  */
        UINT32 Reg;
        struct {
            UINT32 PNS                                                                    : 32;     /* [ 31:0] Provides the security state of the peripheral request interfaces
                                                                                                                Bit N  0 Peripheral request interface N is in the Secure state
                                                                                                                Bit N  1 Peripheral request interface N is in the Non-secure state
                                                                                                                Note
                                                                                                                The boot_periph_ns tie-off signals initialize the bits in this register when the DMAC exits from reset See
                                                                                                                Table A-12 on page A-9 for more information */
        }Bit;
    }CR4;
    union { /* 0x0E14 [Excel Line :0427]  */
        UINT32 Reg;
        struct {
            UINT32 DATA_WIDTH                                                             : 3;      /* [  2:0] The data bus width of the AXI master interface
                                                                                                                0b000  reserved
                                                                                                                0b001  reserved
                                                                                                                0b010  32-bit
                                                                                                                0b011  64-bit
                                                                                                                0b100  128-bit
                                                                                                                0b101-0b111  reserved */
            UINT32 RESERVED4                                                              : 1;      /* [    3] Reserved read UNDEFINED */
            UINT32 WR_CAP                                                                 : 3;      /* [  6:4] Write issuing capability that programs the number of outstanding write transactions
                                                                                                                0b000  1
                                                                                                                0b001  2



                                                                                                                0b111  8 */
            UINT32 RESERVED3                                                              : 1;      /* [    7] Reserved read UNDEFINED */
            UINT32 WR_Q_DEP                                                               : 4;      /* [ 11:8] The depth of the write queue
                                                                                                                0b0000  1 line
                                                                                                                0b0001  2 lines



                                                                                                                0b1111  16 lines */
            UINT32 RD_CAP                                                                 : 3;      /* [14:12] Read issuing capability that programs the number of outstanding read transactions
                                                                                                                0b000  1
                                                                                                                0b001  2



                                                                                                                0b111  8 */
            UINT32 RESERVED2                                                              : 1;      /* [   15] Reserved read UNDEFINED */
            UINT32 RD_Q_DEP                                                               : 4;      /* [19:16] The depth of the read queue
                                                                                                                0b0000  1 line
                                                                                                                0b0001  2 lines



                                                                                                                0b1111  16 lines */
            UINT32 DATA_BUFFER_DEP                                                        : 10;     /* [29:20] The number of lines that the data buffer contains
                                                                                                                0b000000000  1 line
                                                                                                                0b000000001  2 lines



                                                                                                                0b111111111  1024 lines */
            UINT32 RESERVED1                                                              : 2;      /* [31:30] Reserved read UNDEFINED */
        }Bit;
    }CRD;

    UINT8 EMPTY7[104]; /* 0x68 */

    union { /* 0x0E80 [Excel Line :0437]  */
        UINT32 Reg;
        struct {
            UINT32 WD_IRQ_ONLY                                                            : 1;      /* [    0] Controls how the DMAC responds when it detects a lock-up condition
                                                                                                                0  the DMAC aborts all of the contributing DMA channels and sets irq_abort HIGH
                                                                                                                1  the DMAC sets irq_abort HIGH See Watchdog abort on page 2-26 for more information */
            UINT32 RESERVED1                                                              : 31;     /* [ 31:1] Reserved read UNDEFINED */
        }Bit;
    }WD;

    UINT8 EMPTY8[348]; /* 0x15C */

    union { /* 0x0FE0 [Excel Line :0439]  */
        UINT32 Reg;
        struct {
            UINT32 PART_NUMBER_0                                                          : 8;      /* [  7:0] Returns 0x30 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }PERIPH_ID_0;
    union { /* 0x0FE4 [Excel Line :0441]  */
        UINT32 Reg;
        struct {
            UINT32 PART_NUMBER_1                                                          : 4;      /* [  3:0] Returns 0x3 */
            UINT32 DESIGNER_0                                                             : 4;      /* [  7:4] Returns 0x1 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }PERIPH_ID_1;
    union { /* 0x0FE8 [Excel Line :0444]  */
        UINT32 Reg;
        struct {
            UINT32 DESIGNER_1                                                             : 4;      /* [  3:0] Returns 0x4 */
            UINT32 REVISION                                                               : 4;      /* [  7:4] Identifies the revision
                                                                                                                 0x0 for r0p0
                                                                                                                 0x1 for r1p0
                                                                                                                 0x2 for r1p1
                                                                                                                 0x3 for r1p2 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }PERIPH_ID_2;
    union { /* 0x0FEC [Excel Line :0447]  */
        UINT32 Reg;
        struct {
            UINT32 INTEGRATION_CFG                                                        : 1;      /* [    0] Returns 0 to indicate that the DMAC does not contain integration test logic */
            UINT32 RESERVED2                                                              : 7;      /* [  7:1] Reserved for future use read UNDEFINED */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Reserved read UNDEFINED */
        }Bit;
    }PERIPH_ID_3;
    union { /* 0x0FF0 [Excel Line :0450]  */
        UINT32 Reg;
        struct {
            UINT32 PCELL_ID_0                                                             : 8;      /* [  7:0] Returns 0x0D */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Read UNDEFINED */
        }Bit;
    }PCELL_ID_0;
    union { /* 0x0FF4 [Excel Line :0452]  */
        UINT32 Reg;
        struct {
            UINT32 PCELL_ID_1                                                             : 8;      /* [  7:0] Returns 0xF0 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Read UNDEFINED */
        }Bit;
    }PCELL_ID_1;
    union { /* 0x0FF8 [Excel Line :0454]  */
        UINT32 Reg;
        struct {
            UINT32 PCELL_ID_2                                                             : 8;      /* [  7:0] Returns 0x05 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Read UNDEFINED */
        }Bit;
    }PCELL_ID_2;
    union { /* 0x0FFC [Excel Line :0456]  */
        UINT32 Reg;
        struct {
            UINT32 PCELL_ID_3                                                             : 8;      /* [  7:0] Returns 0xB1 */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8] Read UNDEFINED */
        }Bit;
    }PCELL_ID_3;
}DRV_DMA330_REGISTER;
/*PRQA S 828 -- */



/*__________________ REGISTER GROUP DEFINE SET_____________________*/

 /* GROUP IDX : DMA330_FTR */
#define DMA330_FTR_CH0                                                                  0
#define DMA330_FTR_CH1                                                                  1
#define DMA330_FTR_CH2                                                                  2
#define DMA330_FTR_CH3                                                                  3
#define DMA330_FTR_CH4                                                                  4
#define DMA330_FTR_CH5                                                                  5
#define DMA330_FTR_CH6                                                                  6
#define DMA330_FTR_CH7                                                                  7
#define DMA330_FTR_MAX                          8

 /* GROUP IDX : DMA330_THR_ST */
#define DMA330_THR_ST_CH0                                                               0
#define DMA330_THR_ST_CH1                                                               1
#define DMA330_THR_ST_CH2                                                               2
#define DMA330_THR_ST_CH3                                                               3
#define DMA330_THR_ST_CH4                                                               4
#define DMA330_THR_ST_CH5                                                               5
#define DMA330_THR_ST_CH6                                                               6
#define DMA330_THR_ST_CH7                                                               7
#define DMA330_THR_ST_MAX                       8

 /* GROUP IDX : DMA330_BUS_AND_CNT_ST */
#define DMA330_BUS_AND_CNT_ST_CH0                                                       0
#define DMA330_BUS_AND_CNT_ST_CH1                                                       1
#define DMA330_BUS_AND_CNT_ST_CH2                                                       2
#define DMA330_BUS_AND_CNT_ST_CH3                                                       3
#define DMA330_BUS_AND_CNT_ST_CH4                                                       4
#define DMA330_BUS_AND_CNT_ST_CH5                                                       5
#define DMA330_BUS_AND_CNT_ST_CH6                                                       6
#define DMA330_BUS_AND_CNT_ST_CH7                                                       7
#define DMA330_BUS_AND_CNT_ST_MAX               8

#endif /* end of DRV_REGISTER_DMA330__ */

