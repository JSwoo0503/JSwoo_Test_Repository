
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : DRV_EMMC_Register.h
*   Date       : 2020-07-31 11:32
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_EMMC_H__
#define DRV_REGISTER_EMMC_H__

#define APACHE_EMMC_BASE_ADDR        0x09000000       /* 0x34000000 */

/* PRQA S 828, 0635 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0006]  */
        UINT32 Reg;
        struct {
            UINT32 BLOCKCNT_SDMASA                                                        : 32;     /* [ 31:0] This register is used to configure a 32-bit Block Count or an SDMA System Address based on the Host Version 4 Enable bit in the Host Control 2 register This register is applicable for both SD and eMMC modes

                                                                                                               32-bit Block Count SDMA System Address
                                                                                                               SDMA System Address Host Version 4 Enable  0 This register contains the system memory address for an SDMA transfer in the 32-bit addressing mode When the Host Controller stops an SDMA transfer this register points to the system address of the next contiguous data position It can be accessed only if no transaction is executing Reading this register during data transfers may return an invalid value
                                                                                                               32-bit Block Count Host Version 4 Enable  1 From the Host Controller Version 410 specification this register is redefined as 32-bit Block Count The Host Controller decrements the block count of this register for every block transfer and the data transfer stops when the count reaches zero This register must be accessed when no transaction is executing Reading this register during data transfers may return invalid value
                                                                                                               Following are the values for BLOCKCNT_SDMASA
                                                                                                               0xFFFF_FFFF 4G - 1 Block

                                                                                                               0x0000_0002 2 Blocks
                                                                                                               0x0000_0001 1 Block
                                                                                                               0x0000_0000 Stop Count
                                                                                                               Note
                                                                                                               For Host Version 4 Enable  0 the Host driver does not program the system address in this register while operating in ADMA mode The system address must be programmed in the ADMA System Address register
                                                                                                               For Host Version 4 Enable  0 the Host driver programs a non-zero 32-bit block count value in this register when Auto CMD23 is enabled for non-DMA and ADMA modes Auto CMD23 cannot be used with SDMA
                                                                                                               This register must be programmed with a non-zero value for data transfer if the 32-bit Block count register is used instead of the 16-bit Block count register */
        }Bit;
    }SDMASA_R;
    union { /* 0x0004 [Excel Line :0007]  */
        UINT16 Reg;
        struct {
            UINT16 XFER_BLOCK_SIZE                                                        : 12;     /* [ 11:0] Transfer Block Size
                                                                                                               These bits specify the block size of data transfers In case of memory it is set to 512 bytes It can be accessed only if no transaction is executing Read operations during transfers may return an invalid value and write operations are ignored Following are the values for XFER_BLOCK_SIZE
                                                                                                               0x1 1 byte
                                                                                                               0x2 2 bytes
                                                                                                               0x3 3 bytes

                                                                                                               0x1FF 511 byte
                                                                                                               0x200 512 bytes

                                                                                                               0x800 2048 bytes
                                                                                                               Note This register must be programmed with a non-zero value for data transfer */
            UINT16 SDMA_BUF_BDARY                                                         : 3;      /* [14:12] SDMA Buffer Boundary
                                                                                                               These bits specify the size of contiguous buffer in system memory The SDMA transfer waits at every boundary specified by these fields and the Host Controller generates the DMA interrupt to request the Host Driver to update the SDMA System Address register
                                                                                                               Values
                                                                                                               0x0 BYTES_4K 4K bytes SDMA Buffer Boundary
                                                                                                               0x1 BYTES_8K 8K bytes SDMA Buffer Boundary
                                                                                                               0x2 BYTES_16K 16K bytes SDMA Buffer Boundary
                                                                                                               0x3 BYTES_16K 16K bytes SDMA Buffer Boundary
                                                                                                               0x4 BYTES_64K 64K bytes SDMA Buffer Boundary
                                                                                                               0x5 BYTES_128K 128K bytes SDMA Buffer Boundary
                                                                                                               0x6 BYTES_256K 256K bytes SDMA Buffer Boundary
                                                                                                               0x7 BYTES_512K 512K bytes SDMA Buffer Boundary */
            UINT16 RESERVED1                                                              : 1;      /* [   15]  */
        }Bit;
    }BLOCKSIZE_R;
    union { /* 0x0006 [Excel Line :0010]  */
        UINT16 Reg;
        struct {
            UINT16 BLOCK_CNT                                                              : 16;     /* [ 15:0] 16-bit Block Count
                                                                                                               If the Host Version 4 Enable bit is set 0 or the 16-bit Block Count register is set to non-zero the 16-bit Block Count register is selected
                                                                                                               If the Host Version 4 Enable bit is set 1 and the 16-bit Block Count register is set to zero the 16-bit Block Count register is selected
                                                                                                               Following are the values for BLOCK_CNT
                                                                                                               0x0 Stop Count
                                                                                                               0x1 1 Block
                                                                                                               0x2 2 Blocks
                                                                                                                -
                                                                                                               0xFFFF 65535 Blocks
                                                                                                               Note For Host Version 4 Enable  0 this register must be set to 0000h before programming the 16-bit block count register when Auto CMD23 is enabled for non-DMA and ADMA modes */
        }Bit;
    }BLOCKCOUNT_R;
    union { /* 0x0008 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 ARGUMENT                                                               : 32;     /* [ 31:0] Command Argument
                                                                                                               These bits specify the SDeMMC command argument that is specified in bits 39-8 of the Command format */
        }Bit;
    }ARGUMENT_R;
    union { /* 0x000C [Excel Line :0012]  */
        UINT16 Reg;
        struct {
            UINT16 DMA_ENABLE                                                             : 1;      /* [    0] DMA Enable
                                                                                                               This bit enables the DMA functionality If this bit is set to 1 a DMA operation begins when the Host Driver writes to the Command register You can select one of the DMA modes by using DMA Select in the Host Control 1 register
                                                                                                               Values
                                                                                                               0x1 ENABLED DMA Data transfer
                                                                                                               0x0 DISABLED No data transfer or Non-DMA data transfer */
            UINT16 BLOCK_COUNT_ENABLE                                                     : 1;      /* [    1] Block Count Enable
                                                                                                               This bit is used to enable the Block Count register which is relevant for multiple block transfers If this bit is set to 0 the Block Count register is disabled which is useful in executing an infinite transfer The Host Driver must set this bit to 0 when ADMA is used
                                                                                                               Values
                                                                                                               0x1 ENABLED Enable
                                                                                                               0x0 DISABLED Disable */
            UINT16 AUTO_CMD_ENABLE                                                        : 2;      /* [  3:2] Auto Command Enable
                                                                                                               This field determines use of Auto Command functions
                                                                                                               Note In SDIO this field must be set as 00b Auto Command Disabled
                                                                                                               Values
                                                                                                               0x0 AUTO_CMD_DISABLED Auto Command Disabled
                                                                                                               0x1 AUTO_CMD12_ENABLED Auto CMD12 Enable
                                                                                                               0x2 AUTO_CMD23_ENABLED Auto CMD23 Enable
                                                                                                               0x3 AUTO_CMD_AUTO_SEL Auto CMD Auto Select */
            UINT16 DATA_XFER_DIR                                                          : 1;      /* [    4] Data Transfer Direction Select
                                                                                                               This bit defines the direction of DAT line data transfers This bit is set to 1 by the Host Driver to transfer data from the SDeMMC card to the Host Controller and it is set to 0 for all other commands
                                                                                                               Values
                                                                                                               0x1 READ Read Card to Host
                                                                                                               0x0 WRITE Write Host to Card */
            UINT16 MULTI_BLK_SEL                                                          : 1;      /* [    5] MultiSingle Block Select
                                                                                                               This bit is set when issuing multiple-block transfer commands using the DAT line If this bit is set to 0 it is not necessary to set the Block Count register
                                                                                                               Values
                                                                                                               0x0 SINGLE Single Block
                                                                                                               0x1 MULTI Multiple Block */
            UINT16 RESP_TYPE                                                              : 1;      /* [    6] Response Type R1R5
                                                                                                               This bit selects either R1 or R5 as a response type when the Response Error Check is selected
                                                                                                               Error statuses checked in R1
                                                                                                               OUT_OF_RANGE
                                                                                                               ADDRESS_ERROR
                                                                                                               BLOCK_LEN_ERROR
                                                                                                               WP_VIOLATION
                                                                                                               CARD_IS_LOCKED
                                                                                                               COM_CRC_ERROR
                                                                                                               CARD_ECC_FAILED
                                                                                                               CC_ERROR
                                                                                                               ERROR
                                                                                                               Response Flags checked in R5
                                                                                                               COM_CRC_ERROR
                                                                                                               ERROR
                                                                                                               FUNCTION_NUMBER
                                                                                                               OUT_OF_RANGE
                                                                                                               Values
                                                                                                               0x0 RESP_R1 R1 Memory
                                                                                                               0x1 RESP_R5 R5 SDIO */
            UINT16 RESP_ERR_CHK_ENABLE                                                    : 1;      /* [    7] Response Error Check Enable
                                                                                                               The Host Controller supports response check function to avoid overhead of response error check by Host driver Response types of only R1 and R5 can be checked by the Controller If the Host Controller checks the response error set this bit to 1 and set Response Interrupt Disable to 1 If an error is detected the Response Error interrupt is generated in the Error Interrupt Status register
                                                                                                               Note
                                                                                                               Response error check must not be enabled for any response type other than R1 and R5
                                                                                                               Response check must not be enabled for the tuning command
                                                                                                               Values
                                                                                                               0x0 DISABLED Response Error Check is disabled
                                                                                                               0x1 ENABLED Response Error Check is enabled */
            UINT16 RESP_INT_DISABLE                                                       : 1;      /* [    8] Response Interrupt Disable
                                                                                                               The Host Controller supports response check function to avoid overhead of response error check by the Host driver Response types of only R1 and R5 can be checked by the Controller
                                                                                                               If Host Driver checks the response error set this bit to 0 and wait for Command Complete Interrupt and then check the response register
                                                                                                               If the Host Controller checks the response error set this bit to 1 and set the Response Error Check Enable bit to 1 The Command Complete Interrupt is disabled by this bit regardless of the Command Complete Signal Enable
                                                                                                               Note During tuning when the Execute Tuning bit in the Host Control2 register is set the Command Complete Interrupt is not generated irrespective of the Response Interrupt Disable setting
                                                                                                               Values
                                                                                                               0x0 ENABLED Response Interrupt is enabled
                                                                                                               0x1 DISABLED Response Interrupt is disabled */
            UINT16 RESERVED1                                                              : 7;      /* [ 15:9]  */
        }Bit;
    }XFER_MODE_R;
    union { /* 0x000E [Excel Line :0021]  */
        UINT16 Reg;
        struct {
            UINT16 RESP_TYPE_SELECT                                                       : 2;      /* [  1:0] Response Type Select
                                                                                                               This bit indicates the type of response expected from the card
                                                                                                               Values
                                                                                                               0x0 NO_RESP No Response
                                                                                                               0x1 RESP_LEN_136 Response Length 136
                                                                                                               0x2 RESP_LEN_48 Response Length 48
                                                                                                               0x3 RESP_LEN_48B Response Length 48 Check Busy after response */
            UINT16 SUB_CMD_FLAG                                                           : 1;      /* [    2] Sub Command Flag
                                                                                                               This bit distinguishes between a main command and a sub command
                                                                                                               Values
                                                                                                               0x0 MAIN Main Command
                                                                                                               0x1 SUB Sub Command */
            UINT16 CMD_CRC_CHK_ENABLE                                                     : 1;      /* [    3] Command CRC Check Enable
                                                                                                               This bit enables the Host Controller to check the CRC field in the response If an error is detected it is reported as a Command CRC error
                                                                                                               Note
                                                                                                               CRC Check enable must be set to 0 for the command with no response R3 response and R4 response
                                                                                                               For the tuning command this bit must always be set to 1 to enable the CRC check
                                                                                                               Values
                                                                                                               0x0 DISABLED Disable
                                                                                                               0x1 ENABLED Enable */
            UINT16 CMD_IDX_CHK_ENABLE                                                     : 1;      /* [    4] Command Index Check Enable
                                                                                                               This bit enables the Host Controller to check the index field in the response to verify if it has the same value as the command index If the value is not the same it is reported as a Command Index error
                                                                                                               Note
                                                                                                               Index Check enable must be set to 0 for the command with no response R2 response R3 response and R4 response
                                                                                                               For the tuning command this bit must always be set to enable the index check
                                                                                                               Values
                                                                                                               0x0 DISABLED Disable
                                                                                                               0x1 ENABLED Enable */
            UINT16 DATA_PRESENT_SEL                                                       : 1;      /* [    5] Data Present Select
                                                                                                               This bit is set to 1 to indicate that data is present and that the data is transferred using the DAT line This bit is set to 0 in the following instances
                                                                                                               Command using the CMD line
                                                                                                               Command with no data transfer but using busy signal on the DAT0 line
                                                                                                               Resume Command
                                                                                                               Values
                                                                                                               0x0 NO_DATA No Data Present
                                                                                                               0x1 DATA Data Present */
            UINT16 CMD_TYPE                                                               : 2;      /* [  7:6] Command Type
                                                                                                               These bits indicate the command type
                                                                                                               Note While issuing Abort CMD using CMD12CMD52 or reset CMD using CMD0CMD52 CMD_TYPE field shall be set to 0x3
                                                                                                               Values
                                                                                                               0x3 ABORT_CMD Abort
                                                                                                               0x2 RESUME_CMD Resume
                                                                                                               0x1 SUSPEND_CMD Suspend
                                                                                                               0x0 NORMAL_CMD Normal */
            UINT16 CMD_INDEX                                                              : 6;      /* [ 13:8] Command Index
                                                                                                               These bits are set to the command number that is specified in bits 45-40 of the Command Format */
            UINT16 RESERVED1                                                              : 2;      /* [15:14]  */
        }Bit;
    }CMD_R;
    union { /* 0x0010 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 RESP01                                                                 : 32;     /* [ 31:0] Command Response
                                                                                                               These bits reflect 39-8 bits of SDeMMC Response Field In UHS-II mode it stores the response of the TRANS_ABORT CCMD
                                                                                                               Note For Auto CMD the 32-bit response bits 39-8 of the Response Field is updated in the RESP67_R register */
        }Bit;
    }RESP01_R;
    union { /* 0x0014 [Excel Line :0030]  */
        UINT32 Reg;
        struct {
            UINT32 RESP23                                                                 : 32;     /* [ 31:0] Command Response
                                                                                                               These bits reflect 71-40 bits of the SDeMMC Response Field In UHS-II mode it is reserved */
        }Bit;
    }RESP23_R;
    union { /* 0x0018 [Excel Line :0031]  */
        UINT32 Reg;
        struct {
            UINT32 RESP45                                                                 : 32;     /* [ 31:0] Command Response
                                                                                                               These bits reflect 103-72 bits of the Response Field In UHS-II mode it stores the lower 4-byte CMD12 response */
        }Bit;
    }RESP45_R;
    union { /* 0x001C [Excel Line :0032]  */
        UINT32 Reg;
        struct {
            UINT32 RESP67                                                                 : 32;     /* [ 31:0] Command Response
                                                                                                               These bits reflect bits 135-104 of SDEMMC Response Field In UHS-II mode it stores the upper 4-byte CMD12 response
                                                                                                               Note For Auto CMD this register also reflects the 32-bit response bits 39-8 of the Response Field */
        }Bit;
    }RESP67_R;
    union { /* 0x0020 [Excel Line :0033]  */
        UINT32 Reg;
        struct {
            UINT32 BUF_DATA                                                               : 32;     /* [ 31:0] Buffer Data
                                                                                                               These bits enable access to the Host Controller packet buffer */
        }Bit;
    }BUF_DATA_R;
    union { /* 0x0024 [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 CMD_INHIBIT                                                            : 1;      /* [    0] Command Inhibit CMD
                                                                                                               This bit indicates the following
                                                                                                               SDeMMC mode If this bit is set to 0 it indicates that the CMD line is not in use and the Host controller can issue an SDeMMC command using the CMD line This bit is set when the command register is written This bit is cleared when the command response is received This bit is not cleared by the response of auto CMD1223 but cleared by the response of readwrite command
                                                                                                               UHS-II mode If this bit is set to 0 it indicates that a command packet can be issued by the Host Controller
                                                                                                               Values
                                                                                                               0x0 READY Host Controller is ready to issue a command
                                                                                                               0x1 NOT_READY Host Controller is not ready to issue a command */
            UINT32 CMD_INHIBIT_DAT                                                        : 1;      /* [    1] Command Inhibit DAT
                                                                                                               This bit is applicable for SDeMMC mode and is generated if either DAT line active or Read transfer active is set to 1 If this bit is set to 0 it indicates that the Host Controller can issue subsequent SDeMMC commands For the UHS-II mode this bit is irrelevant and always returns 0
                                                                                                               Values
                                                                                                               0x0 READY Can issue command which used DAT line
                                                                                                               0x1 NOT_READY Cannot issue command which used DAT line */
            UINT32 DAT_LINE_ACTIVE                                                        : 1;      /* [    2] DAT Line Active SDeMMC Mode only
                                                                                                               This bit indicates whether one of the DAT lines on the SDeMMC bus is in use This bit is irrelevant for the UHS-II mode
                                                                                                               In the case of read transactions this bit indicates whether a read transfer is executing on the SDeMMC bus
                                                                                                               In the case of write transactions this bit indicates whether a write transfer is executing on the SDeMMC bus
                                                                                                               For a command with busy this status indicates whether the command executing busy is executing on an SD or eMMC bus
                                                                                                               Values
                                                                                                               0x0 INACTIVE DAT Line Inactive
                                                                                                               0x1 ACTIVE DAT Line Active */
            UINT32 RE_TUNE_REQ                                                            : 1;      /* [    3] Re-Tuning Request
                                                                                                               DWC_mshc does not generate retuning request The software must maintain the Retuning timer */
            UINT32 DAT_7_4                                                                : 4;      /* [  7:4] DAT74 Line Signal Level
                                                                                                               This bit is used to check the DAT line level to recover from errors and for debugging These bits reflect the value of the sd_dat_in upper nibble signal These bits are irrelevant for the UHS-II mode and always return 0 */
            UINT32 WR_XFER_ACTIVE                                                         : 1;      /* [    8] Write Transfer Active
                                                                                                               This status indicates whether a write transfer is active for SDeMMC mode It is irrelevant for UHS-II mode and always returns 0
                                                                                                               Values
                                                                                                               0x0 INACTIVE No valid data
                                                                                                               0x1 ACTIVE Transferring data */
            UINT32 RD_XFER_ACTIVE                                                         : 1;      /* [    9] Read Transfer Active
                                                                                                               This bit indicates whether a read transfer is active for SDeMMC mode This bit irrelevant for the UHS-II mode and always returns 0
                                                                                                               Values
                                                                                                               0x0 INACTIVE No valid data
                                                                                                               0x1 ACTIVE Transferring data */
            UINT32 BUF_WR_ENABLE                                                          : 1;      /* [   10] Buffer Write Enable
                                                                                                               This bit is used for non-DMA transfers This bit is set if space is available for writing data
                                                                                                               Values
                                                                                                               0x0 DISABLED Write disable
                                                                                                               0x1 ENABLED Write enable */
            UINT32 BUF_RD_ENABLE                                                          : 1;      /* [   11] Buffer Read Enable
                                                                                                               This bit is used for non-DMA transfers This bit is set if valid data exists in the Host buffer
                                                                                                               Values
                                                                                                               0x0 DISABLED Read disable
                                                                                                               0x1 ENABLED Read enable */
            UINT32 RESERVED2                                                              : 4;      /* [15:12]  */
            UINT32 CARD_INSERTED                                                          : 1;      /* [   16] Card Inserted
                                                                                                               This bit indicates whether a card has been inserted The Host Controller debounces this signal so that Host Driver need not wait for it to stabilize
                                                                                                               Values
                                                                                                               0x0 FALSE Reset Debouncing or No card
                                                                                                               0x1 TRUE Card Inserted */
            UINT32 CARD_STABLE                                                            : 1;      /* [   17] Card Stable
                                                                                                               This bit indicates the stability of the Card Detect Pin Level A card is not detected if this bit is set to 1 and the value of the CARD_INSERTED bit is 0
                                                                                                               Values
                                                                                                               0x0 FALSE Reset or Debouncing
                                                                                                               0x1 TRUE No Card or Inserted */
            UINT32 CARD_DETECT_PIN_LEVEL                                                  : 1;      /* [   18] Card Detect Pin Level
                                                                                                               This bit reflects the inverse synchronized value of the card_detect_n signal
                                                                                                               Values
                                                                                                               0x0 FALSE No card present
                                                                                                               0x1 TRUE Card Present */
            UINT32 WR_PROTECT_SW_LVL                                                      : 1;      /* [   19] Write Protect Switch Pin Level
                                                                                                               This bit is supported only for memory and combo cards This bit reflects the synchronized value of the card_write_prot signal
                                                                                                               Values
                                                                                                               0x0 FALSE Write protected
                                                                                                               0x1 TRUE Write enabled */
            UINT32 DAT_3_0                                                                : 4;      /* [23:20] DAT30 Line Signal Level
                                                                                                               This bit is used to check the DAT line level to recover from errors and for debugging These bits reflect the value of the sd_dat_in lower nibble signal These bits are irrelevant for the UHS-II mode and always returns 0 */
            UINT32 CMD_LINE_LVL                                                           : 1;      /* [   24] Command-Line Signal Level
                                                                                                               This bit is used to check the CMD line level to recover from errors and for debugging These bits reflect the value of the sd_cmd_in signal This bit is irrelevant for an UHS-II mode and always returns 0 */
            UINT32 HOST_REG_VOL                                                           : 1;      /* [   25] Host Regulator Voltage Stable
                                                                                                               This bit is used to check whether the host regulator voltage is stable for switching the voltage of UHS-I mode This bit reflects the synchronized value of the host_reg_vol_stable signal
                                                                                                               Values
                                                                                                               0x0 FALSE Host Regulator Voltage is not stable
                                                                                                               0x1 TRUE Host Regulator Voltage is stable */
            UINT32 RESERVED1                                                              : 1;      /* [   26]  */
            UINT32 CMD_ISSUE_ERR                                                          : 1;      /* [   27] Command Not Issued by Error
                                                                                                               This bit is set if a command cannot be issued after setting the command register due to an error except the Auto CMD12 error
                                                                                                               Values
                                                                                                               0x0 FALSE No error for issuing a command
                                                                                                               0x1 TRUE Command cannot be issued */
            UINT32 SUB_CMD_STAT                                                           : 1;      /* [   28] Sub Command Status
                                                                                                               This bit is used to distinguish between a main command and a sub command status
                                                                                                               Values
                                                                                                               0x0 FALSE Main Command Status
                                                                                                               0x1 TRUE Sub Command Status */
            UINT32 IN_DORMANT_ST                                                          : 1;      /* [   29] In Dormant Status
                                                                                                               This bit indicates whether UHS-II lanes enter Dormant state in the UHS-II mode For SDeMMC mode this bit always returns 0
                                                                                                               Values
                                                                                                               0x0 FALSE Not in DORMANT state
                                                                                                               0x1 TRUE In DORMANT state */
            UINT32 LANE_SYNC                                                              : 1;      /* [   30] Lane Synchronization
                                                                                                               This bit indicates whether a lane is synchronized in the UHS-II mode For SDeMMC mode this bit always returns 0
                                                                                                               Values
                                                                                                               0x0 FALSE UHS-II PHY is not initialized
                                                                                                               0x1 TRUE UHS-II PHY is initialized */
            UINT32 UHS2_IF_DETECT                                                         : 1;      /* [   31] UHS-II Interface Detection
                                                                                                               This bit indicates whether a card supports the UHS-II interface For SDeMMC mode this bit always returns 0
                                                                                                               Values
                                                                                                               0x0 FALSE UHS-II interface is not detected
                                                                                                               0x1 TRUE UHS-II interface is detected */
        }Bit;
    }PSTATE_REG;
    union { /* 0x0028 [Excel Line :0057]  */
        UINT8 Reg;
        struct {
            UINT8 LED_CTRL                                                               : 1;      /* [    0] LED Control
                                                                                                               This bit is used to caution the user not to remove the card while the SD card is being accessed The value is reflected on the led_control signal
                                                                                                               Values
                                                                                                               0x0 OFF LED off
                                                                                                               0x1 ON LED on */
            UINT8 DAT_XFER_WIDTH                                                         : 1;      /* [    1] Data Transfer Width
                                                                                                               For SDeMMC modethis bit selects the data transfer width of the Host Controller The Host Driver sets it to match the data width of the SDeMMC card In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x1 FOUR_BIT 4-bit mode
                                                                                                               0x0 ONE_BIT 1-bit mode */
            UINT8 HIGH_SPEED_EN                                                          : 1;      /* [    2] High Speed Enable SDeMMC Mode only
                                                                                                               In SDeMMC mode this bit is used to determine the selection of preset value for High Speed mode Before setting this bit the Host Driver checks the High Speed Support in the Capabilities register
                                                                                                               Note DWC_MSHC always outputs the sd_cmd_out and sd_dat_out lines at the rising edge of cclk_tx clock irrespective of this bitPlease refer the section Connecting the Clock IO interface in the Mobile Storage Host Controller user guide on clocking requirement for an SDeMMC card
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x1 HIGH_SPEED High Speed mode
                                                                                                               0x0 NORMAL_SPEED Normal Speed mode */
            UINT8 DMA_SEL                                                                : 2;      /* [  4:3] DMA Select
                                                                                                               This field is used to select the DMA type
                                                                                                               When Host Version 4 Enable is 1 in Host Control 2 register
                                                                                                               0x0  SDMA is selected
                                                                                                               0x1  Reserved
                                                                                                               0x2  ADMA2 is selected
                                                                                                               0x3  ADMA2 or ADMA3 is selected
                                                                                                               When Host Version 4 Enable is 0 in Host Control 2 register
                                                                                                               0x0  SDMA is selected
                                                                                                               0x1  Reserved
                                                                                                               0x2  8-bit Address ADMA2 is selected
                                                                                                               0x3  64-bit Address ADMA2 is selected
                                                                                                               Values
                                                                                                               0x0 SDMA SDMA is selected
                                                                                                               0x1 RSVD_BIT Reserved
                                                                                                               0x2 ADMA2 ADMA2 is selected
                                                                                                               0x3 ADMA2_3 ADMA2 or ADMA3 is selected */
            UINT8 EXT_DAT_XFER                                                           : 1;      /* [    5] Extended Data Transfer Width
                                                                                                               This bit controls 8-bit bus width mode of embedded device This bit is not applicable for UHS-II mode
                                                                                                               Values
                                                                                                               0x1 EIGHT_BIT 8-bit Bus Width
                                                                                                               0x0 DEFAULT Bus Width is selected by the Data Transfer Width */
            UINT8 CARD_DETECT_TEST_LVL                                                   : 1;      /* [    6] Card Detect Test Level
                                                                                                               This bit is enabled while the Card Detect Signal Selection is set to 1 and it indicates whether a card inserted or not
                                                                                                               Values
                                                                                                               0x1 CARD_INSERTED Card Inserted
                                                                                                               0x0 No_CARD No Card */
            UINT8 CARD_DETECT_SIG_SEL                                                    : 1;      /* [    7] Card Detect Signal Selection
                                                                                                               This bit selects a source for card detection When the source for the card detection is switched the interrupt must be disabled during the switching period
                                                                                                               Values
                                                                                                               0x1 CARD_DT_TEST_LEVEL Card Detect Test Level is selected for test purpose
                                                                                                               0x0 SDCD_PIN SDCD card_detect_n signal is selected for normal use */
        }Bit;
    }HOST_CTRL1_R;
    union { /* 0x0029 [Excel Line :0064]  */
        UINT8 Reg;
        struct {
            UINT8 SD_BUS_PWR_VDD1                                                        : 1;      /* [    0] SD Bus Power for VDD1
                                                                                                               This bit enables VDD1 power of the card This setting is available on the sd_vdd1_on output of DWC_mshc so that it can be used to control the VDD1 power supply of the card Before setting this bit the SD Host Driver sets the SD Bus Voltage Select bit If the Host Controller detects a No Card state this bit is cleared
                                                                                                               In SD mode if this bit is cleared the Host Controller stops the SD Clock by clearing the SD_CLK_IN bit in the CLK_CTRL_R register
                                                                                                               In UHS-II mode before clearing this bit the Host Driver clears the SD_CLK_IN bit in the CLK_CTRL_R register
                                                                                                               Values
                                                                                                               0x0 OFF Power off
                                                                                                               0x1 ON Power on */
            UINT8 SD_BUS_VOL_VDD1                                                        : 3;      /* [  3:1] SD Bus Voltage Select for VDD1eMMC Bus Voltage Select for VDD
                                                                                                               These bits enable the Host Driver to select the voltage level for an SDeMMC card Before setting this register the Host Driver checks the Voltage Support bits in the Capabilities register If an unsupported voltage is selected the Host System does not supply the SD Bus voltage The value set in this field is available on the DWC_mshc output signal sd_vdd1_sel which is used by the voltage switching circuitry
                                                                                                               SD Bus Voltage Select options
                                                                                                               0x7  33VTypical
                                                                                                               0x6  30VTypical
                                                                                                               0x5  18VTypical for Embedded
                                                                                                               0x4  0x0 - Reserved
                                                                                                               eMMC Bus Voltage Select options
                                                                                                               0x7  33VTypical
                                                                                                               0x6  18VTypical
                                                                                                               0x5  12VTypical
                                                                                                               0x4  0x0 - Reserved
                                                                                                               Values
                                                                                                               0x7 V_3_3 33V Typ
                                                                                                               0x6 V_3_0 30V Typ
                                                                                                               0x5 V_1_8 18V Typ for Embedded
                                                                                                               0x4 RSVD4 Reserved
                                                                                                               0x3 RSVD3 Reserved
                                                                                                               0x2 RSVD2 Reserved
                                                                                                               0x1 RSVD1 Reserved
                                                                                                               0x0 RSVD0 Reserved */
            UINT8 SD_BUS_PWR_VDD2                                                        : 1;      /* [    4] SD Bus Power for VDD2
                                                                                                               This bit enables VDD2 power of UHS-II card This setting is available on the sd_vdd2_on output of DWC_mshc so that it can be used to control the VDD2 power supply of the card This is irrelevant for SDeMMC card
                                                                                                               Values
                                                                                                               0x0 OFF Power off
                                                                                                               0x1 ON Power on */
            UINT8 SD_BUS_VOL_VDD2                                                        : 3;      /* [  7:5] SD Bus Voltage Select for VDD2
                                                                                                               This bit determines supply voltage range to VDD2 of UHS-II card This bit be can set to 0x5 if 18V VDD2 Support in the Capabilities register is set to 1 This is irrelevant for SDeMMC card
                                                                                                               Values
                                                                                                               0x7 NOT_USED7 Not used
                                                                                                               0x6 NOT_USED6 Not used
                                                                                                               0x5 V_1_8 18V
                                                                                                               0x4 V_1_2 Reserved for 12V
                                                                                                               0x3 RSVD3 Reserved
                                                                                                               0x2 RSVD2 Reserved
                                                                                                               0x1 RSVD1 Reserved
                                                                                                               0x0 NO_VDD2 VDD2 Not Supported */
        }Bit;
    }PWR_CTRL_R;
    union { /* 0x002A [Excel Line :0068]  */
        UINT8 Reg;
        struct {
            UINT8 STOP_BG_REQ                                                            : 1;      /* [    0] Stop At Block Gap Request
                                                                                                               This bit is used to stop executing read and write transactions at the next block gap for non-DMA SDMA and ADMA transfers
                                                                                                               Values
                                                                                                               0x0 XFER Transfer
                                                                                                               0x1 STOP Stop */
            UINT8 CONTINUE_REQ                                                           : 1;      /* [    1] Continue Request
                                                                                                               This bit is used to restart the transaction which was stopped using the Stop At Block Gap Request The Host Controller automatically clears this bit when the transaction restarts If stop at block gap request is set to 1 any write to this bit is ignored
                                                                                                               Values
                                                                                                               0x0 NO_AFFECT No Affect
                                                                                                               0x1 RESTART Restart */
            UINT8 RD_WAIT_CTRL                                                           : 1;      /* [    2] Read Wait Control
                                                                                                               This bit is used to enable the read wait protocol to stop read data using DAT2 line if the card supports read wait Otherwise the Host Controller has to stop the card clock to hold the read data In UHS-II mode Read Wait is disabled
                                                                                                               Values
                                                                                                               0x0 DISABLE Disable Read Wait Control
                                                                                                               0x1 ENABLE Enable Read Wait Control */
            UINT8 INT_AT_BGAP                                                            : 1;      /* [    3] Interrupt At Block Gap
                                                                                                               This bit is valid only in the 4-bit mode of an SDIO card and is used to select a sample point in the interrupt cycle Setting to 1 enables interrupt detection at the block gap for a multiple block transfer In UHS-II mode this bit is disabled
                                                                                                               Values
                                                                                                               0x0 DISABLE Disabled
                                                                                                               0x1 ENABLE Enabled */
            UINT8 RESERVED1                                                              : 4;      /* [  7:4]  */
        }Bit;
    }BGAP_CTRL_R;
    union { /* 0x002B [Excel Line :0073]  */
        UINT8 Reg;
        struct {
            UINT8 CARD_INT                                                               : 1;      /* [    0] Wakeup Event Enable on Card Interrupt
                                                                                                               This bit enables wakeup event through a Card Interrupt assertion in the Normal Interrupt Status register This bit can be set to 1 if FN_WUS Wake Up Support in CIS is set to 1
                                                                                                               Values
                                                                                                               0x0 DISABLED Disable
                                                                                                               0x1 ENABLED Enable */
            UINT8 CARD_INSERT                                                            : 1;      /* [    1] Wakeup Event Enable on SD Card Insertion
                                                                                                               This bit enables wakeup event through Card Insertion assertion in the Normal Interrupt Status register FN_WUS Wake Up Support in CIS does not affect this bit
                                                                                                               Values
                                                                                                               0x0 DISABLED Disable
                                                                                                               0x1 ENABLED Enable */
            UINT8 CARD_REMOVAL                                                           : 1;      /* [    2] Wakeup Event Enable on SD Card Removal
                                                                                                               This bit enables wakeup event through Card Removal assertion in the Normal Interrupt Status register For the SDIO card Wake Up Support FN_WUS in the Card Information Structure CIS register does not affect this bit
                                                                                                               Values
                                                                                                               0x0 DISABLED Disable
                                                                                                               0x1 ENABLED Enable */
            UINT8 RESERVED1                                                              : 5;      /* [  7:3]  */
        }Bit;
    }WUP_CTRL_R;
    union { /* 0x002C [Excel Line :0077]  */
        UINT16 Reg;
        struct {
            UINT16 INTERNAL_CLK_EN                                                        : 1;      /* [    0] Internal Clock Enable
                                                                                                               This bit is set to 0 when the Host Driver is not using the Host Controller or the Host Controller awaits a wakeup interrupt The Host Controller must stop its internal clock to enter a very low power state However registers can still be read and written to The value is reflected on the intclk_en signal
                                                                                                               Note If this bit is not used to control the internal clock base clock and master clock it is recommended to set this bit to 1
                                                                                                               Values
                                                                                                               0x0 FALSE Stop
                                                                                                               0x1 TRUE Oscillate */
            UINT16 INTERNAL_CLK_STABLE                                                    : 1;      /* [    1] Internal Clock Stable
                                                                                                               This bit enables the Host Driver to check the clock stability twice after the Internal Clock Enable bit is set and after the PLL Enable bit is set This bit reflects the synchronized value of the intclk_stable signal after the Internal Clock Enable bit is set to 1 and also reflects the synchronized value of the card_clk_stable signal after the PLL Enable bit is set to 1
                                                                                                               Values
                                                                                                               0x0 FALSE Not Ready
                                                                                                               0x1 TRUE Ready */
            UINT16 SD_CLK_EN                                                              : 1;      /* [    2] SDeMMC Clock Enable
                                                                                                               This bit stops the SDCLK or RCLK when set to 0 The SDCLKRCLK Frequency Select bit can be changed when this bit is set to 0 The value is reflected on the clk2card_on pin
                                                                                                               Values
                                                                                                               0x0 FALSE Disable providing SDCLKRCLK
                                                                                                               0x1 TRUE Enable providing SDCLKRCLK */
            UINT16 PLL_ENABLE                                                             : 1;      /* [    3] PLL Enable
                                                                                                               This bit is used to activate the PLL applicable when Host Version 4 Enable  1 When Host Version 4 Enable  0 INTERNAL_CLK_EN bit may be used to activate PLL The value is reflected on the card_clk_en signal
                                                                                                               Note If this bit is not used to to active the PLL when Host Version 4 Enable  1 it is recommended to set this bit to 1
                                                                                                               Values
                                                                                                               0x0 FALSE PLL is in low power mode
                                                                                                               0x1 TRUE PLL is enabled */
            UINT16 RESERVED1                                                              : 1;      /* [    4]  */
            UINT16 CLK_GEN_SELECT                                                         : 1;      /* [    5] Clock Generator Select
                                                                                                               This bit is used to select the clock generator mode in SDCLKRCLK Frequency Select If Preset Value Enable  0 this bit is set by the Host Driver If Preset Value Enable  1 this bit is automatically set to a value specified in one of the Preset Value registers The value is reflected on the card_clk_gen_sel signal
                                                                                                               Values
                                                                                                               0x0 FALSE Divided Clock Mode
                                                                                                               0x1 TRUE Programmable Clock Mode */
            UINT16 UPPER_FREQ_SEL                                                         : 2;      /* [  7:6] These bits specify the upper 2 bits of 10-bit SDCLKRCLK Frequency Select control The value is reflected on the upper 2 bits of the card_clk_freq_sel signal */
            UINT16 FREQ_SEL                                                               : 8;      /* [ 15:8] SDCLKRCLK Frequency Select
                                                                                                               These bits are used to select the frequency of the SDCLK signal These bits depend on setting of Preset Value Enable in the Host Control 2 register If Preset Value Enable  0 these bits are set by the Host Driver If Preset Value Enable  1 these bits are automatically set to a value specified in one of the Preset Value register The value is reflected on the lower 8-bit of the card_clk_freq_selsignal
                                                                                                               10-bit Divided Clock Mode
                                                                                                               0x3FF  12046 Divided clock

                                                                                                               N  12N Divided Clock

                                                                                                               0x002  14 Divided Clock
                                                                                                               0x001  12 Divided Clock
                                                                                                               0x000  Base clock 10MHz - 255 MHz
                                                                                                               Programmable Clock Mode  Enables the Host System to select a fine grain SD clock frequency
                                                                                                               0x3FF  Base clock  M 1024

                                                                                                               N-1  Base clock  M N

                                                                                                               0x002  Base clock  M 3
                                                                                                               0x001  Base clock  M 2
                                                                                                               0x000  Base clock  M */
        }Bit;
    }CLK_CTRL_R;
    union { /* 0x002E [Excel Line :0085]  */
        UINT8 Reg;
        struct {
            UINT8 TOUT_CNT                                                               : 4;      /* [  3:0] Data Timeout Counter Value
                                                                                                               This value determines the interval by which DAT line timeouts are detected The Timeout clock frequency is generated by dividing the base clock TMCLK value by this value When setting this register prevent inadvertent timeout events by clearing the Data Timeout Error Status Enable in the Error Interrupt Status Enable register The values for these bits are
                                                                                                               0xF  Reserved
                                                                                                               0xE  TMCLK x 227

                                                                                                               0x1  TMCLK x 214
                                                                                                               0x0  TMCLK x 213
                                                                                                               Note During a boot operating in an eMMC mode an application must configure the boot data timeout value approximately 1 sec in this bit */
            UINT8 RESERVED1                                                              : 4;      /* [  7:4]  */
        }Bit;
    }TOUT_CTRL_R;
    union { /* 0x002F [Excel Line :0087]  */
        UINT8 Reg;
        struct {
            UINT8 SW_RST_ALL                                                             : 1;      /* [    0] Software Reset For All
                                                                                                               This reset affects the entire Host Controller except for the card detection circuit During its initialization the Host Driver sets this bit to 1 to reset the Host Controller All registers are reset except the capabilities register If this bit is set to 1 the Host Driver must issue reset command and reinitialize the card
                                                                                                               Values
                                                                                                               0x0 FALSE Work
                                                                                                               0x1 TRUE Reset */
            UINT8 SW_RST_CMD                                                             : 1;      /* [    1] Software Reset For CMD line
                                                                                                               This bit resets only a part of the command circuit to be able to issue a command It bit is also used to initialize a UHS-II command circuit This reset is effective only for a command issuing circuit including response error statuses related to Command Inhibit CMD control and does not affect the data transfer circuit Host Controller can continue data transfer even after this reset is executed while handling subcommand-response errors
                                                                                                               The following registers and bits are cleared by this bit
                                                                                                               Present State register  Command Inhibit CMD bit
                                                                                                               Normal Interrupt Status register  Command Complete bit
                                                                                                               Error Interrupt Status  Response error statuses related to Command Inhibit CMD bit
                                                                                                               Values
                                                                                                               0x0 FALSE Work
                                                                                                               0x1 TRUE Reset */
            UINT8 SW_RST_DAT                                                             : 1;      /* [    2] Software Reset For DAT line
                                                                                                               This bit is used in SDeMMC mode and it resets only a part of the data circuit and the DMA circuit is also reset
                                                                                                               The following registers and bits are cleared by this bit
                                                                                                               Buffer Data Port register
                                                                                                               -Buffer is cleared and initialized
                                                                                                               Present state register
                                                                                                               -Buffer Read Enable
                                                                                                               -Buffer Write Enable
                                                                                                               -Read Transfer Active
                                                                                                               -Write Transfer Active
                                                                                                               -DAT Line Active
                                                                                                               -Command Inhibit DAT
                                                                                                               Block Gap Control register
                                                                                                               -Continue Request
                                                                                                               -Stop At Block Gap Request
                                                                                                               Normal Interrupt status register
                                                                                                               -Buffer Read Ready
                                                                                                               -Buffer Write Ready
                                                                                                               -DMA Interrupt
                                                                                                               -Block Gap Event
                                                                                                               -Transfer Complete
                                                                                                               In UHS-II mode this bit shall be set to 0
                                                                                                               Values
                                                                                                               0x0 FALSE Work
                                                                                                               0x1 TRUE Reset */
            UINT8 RESERVED1                                                              : 5;      /* [  7:3]  */
        }Bit;
    }SW_RST_R;
    union { /* 0x0030 [Excel Line :0091]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_COMPLETE                                                           : 1;      /* [    0] Command Complete
                                                                                                               In an SDeMMC Mode this bit is set when the end bit of a response except for Auto CMD12 and Auto CMD23 In UHS-II Mode this bit is set when response packet is received
                                                                                                               This interrupt is not generated when the Response Interrupt Disable in Transfer Mode Register is set to 1
                                                                                                               Values
                                                                                                               0x0 FALSE No command complete
                                                                                                               0x1 TRUE Command Complete */
            UINT16 XFER_COMPLETE                                                          : 1;      /* [    1] Transfer Complete
                                                                                                               This bit is set when a readwrite transfer and a command with status busy is completed
                                                                                                               Values
                                                                                                               0x0 FALSE Not complete
                                                                                                               0x1 TRUE Command execution is completed */
            UINT16 BGAP_EVENT                                                             : 1;      /* [    2] Block Gap Event
                                                                                                               This bit is set when both readwrite transaction is stopped at block gap due to a Stop at Block Gap Request
                                                                                                               Values
                                                                                                               0x0 FALSE No Block Gap Event
                                                                                                               0x1 TRUE Transaction stopped at block gap */
            UINT16 DMA_INTERRUPT                                                          : 1;      /* [    3] DMA Interrupt
                                                                                                               This bit is set if the Host Controller detects the SDMA Buffer Boundary during transfer In case of ADMA by setting the Int field in the descriptor table the Host controller generates this interrupt This interrupt is not generated after a Transfer Complete
                                                                                                               Values
                                                                                                               0x0 FALSE No DMA Interrupt
                                                                                                               0x1 TRUE DMA Interrupt is generated */
            UINT16 BUF_WR_READY                                                           : 1;      /* [    4] Buffer Write Ready
                                                                                                               This bit is set if the Buffer Write Enable changes from 0 to 1
                                                                                                               Values
                                                                                                               0x0 FALSE Not ready to write buffer
                                                                                                               0x1 TRUE Ready to write buffer */
            UINT16 BUF_RD_READY                                                           : 1;      /* [    5] Buffer Read Ready
                                                                                                               This bit is set if the Buffer Read Enable changes from 0 to 1
                                                                                                               Values
                                                                                                               0x0 FALSE Not ready to read buffer
                                                                                                               0x1 TRUE Ready to read buffer */
            UINT16 CARD_INSERTION                                                         : 1;      /* [    6] Card Insertion
                                                                                                               This bit is set if the Card Inserted in the Present State register changes from 0 to 1
                                                                                                               Values
                                                                                                               0x0 FALSE Card state stable or Debouncing
                                                                                                               0x1 TRUE Card Inserted */
            UINT16 CARD_REMOVAL                                                           : 1;      /* [    7] Card Removal
                                                                                                               This bit is set if the Card Inserted in the Present State register changes from 1 to 0
                                                                                                               Values
                                                                                                               0x0 FALSE Card state stable or Debouncing
                                                                                                               0x1 TRUE Card Removed */
            UINT16 CARD_INTERRUPT                                                         : 1;      /* [    8] Card Interrupt
                                                                                                               This bit reflects the synchronized value of
                                                                                                               DAT1 Interrupt Input for SD Mode
                                                                                                               DAT2 Interrupt Input for UHS-II Mode
                                                                                                               Values
                                                                                                               0x0 FALSE No Card Interrupt
                                                                                                               0x1 TRUE Generate Card Interrupt */
            UINT16 NT_A                                                                   : 1;      /* [    9] INT_A Embedded
                                                                                                               This bit is set if INT_A is enabled and if INT_A pin is in low level The INT_A pin is not supported */
            UINT16 INT_B                                                                  : 1;      /* [   10] INT_B Embedded
                                                                                                               This bit is set if INT_B is enabled and if INT_B pin is in low level The INT_B pin is not supported */
            UINT16 INT_C                                                                  : 1;      /* [   11] INT_C Embedded
                                                                                                               This bit is set if INT_C is enabled and if INT_C pin is in low level The INT_C pin is not supported */
            UINT16 RE_TUNE_EVENT                                                          : 1;      /* [   12] Re-tuning Event
                                                                                                               This bit is set if the Re-Tuning Request changes from 0 to 1 Re-Tuning request is not supported */
            UINT16 FX_EVENT                                                               : 1;      /* [   13] FX Event
                                                                                                               This status is set when R14 of response register is set to 1 and Response Type R1R5 is set to 0 in Transfer Mode register This interrupt is used with response check function
                                                                                                               Values
                                                                                                               0x0 FALSE No Event
                                                                                                               0x1 TRUE FX Event is detected */
            UINT16 CQE_EVENT                                                              : 1;      /* [   14] Command Queuing Event
                                                                                                               This status is set if Command QueuingCrypto related event has occurred in eMMCSD mode Read CQHCIs CQISCRNQIS register for more details In UHS-II Mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No Event
                                                                                                               0x1 TRUE Command Queuing Event is detected */
            UINT16 ERR_INTERRUPT                                                          : 1;      /* [   15] Error Interrupt
                                                                                                               If any of the bits in the Error Interrupt Status register are set then this bit is set
                                                                                                               Values
                                                                                                               0x0 FALSE No Error
                                                                                                               0x1 TRUE Error */
        }Bit;
    }NORMAL_INT_STAT_R;
    union { /* 0x0032 [Excel Line :0107]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_TOUT_ERR                                                           : 1;      /* [    0] Command Timeout Error
                                                                                                               In SDeMMC Modethis bit is set only if no response is returned within 64 SD clock cycles from the end bit of the command If the Host Controller detects a CMD line conflict along with Command CRC Error bit this bit is set to 1 without waiting for 64 SDeMMC card clock cycles In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Time out */
            UINT16 CMD_CRC_ERR                                                            : 1;      /* [    1] Command CRC Error
                                                                                                               Command CRC Error is generated in SDeMMC mode for following two cases
                                                                                                               If a response is returned and the Command Timeout Error is set to 0 indicating no timeout this bit is set to 1 when detecting a CRC error in the command response
                                                                                                               The Host Controller detects a CMD line conflict by monitoring the CMD line when a command is issued If the Host Controller drives the CMD line to 1 level but detects 0 level on the CMD line at the next SD clock edge then the Host Controller aborts the command stop driving CMD line and set this bit to 1 The Command Timeout Error is also set to 1 to distinguish a CMD line conflict
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE CRC error generated */
            UINT16 CMD_END_BIT_ERR                                                        : 1;      /* [    2] Command End Bit Error
                                                                                                               This bit is set when detecting that the end bit of a command response is 0 in SDeMMC mode
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE End Bit error generated */
            UINT16 CMD_IDX_ERR                                                            : 1;      /* [    3] Command Index Error
                                                                                                               This bit is set if a Command Index error occurs in the command respons in SDeMMC mode
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 DATA_TOUT_ERR                                                          : 1;      /* [    4] Data Timeout Error
                                                                                                               This bit is set in SDeMMC mode when detecting one of the following timeout conditions
                                                                                                               Busy timeout for R1b R5b type
                                                                                                               Busy timeout after Write CRC status
                                                                                                               Write CRC Status timeout
                                                                                                               Read Data timeout
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Time out */
            UINT16 DATA_CRC_ERR                                                           : 1;      /* [    5] Data CRC Error
                                                                                                               This error occurs in SDeMMC mode when detecting CRC error when transferring read data which uses the DAT line when detecting the Write CRC status having a value of other than 010 or when write CRC status timeout
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 DATA_END_BIT_ERR                                                       : 1;      /* [    6] Data End Bit Error
                                                                                                               This error occurs in SDeMMC mode either when detecting 0 at the end bit position of read data that uses the DAT line or at the end bit position of the CRC status
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 CUR_LMT_ERR                                                            : 1;      /* [    7] Current Limit Error
                                                                                                               By setting the SD Bus Power bit in the Power Control register the Host Controller is requested to supply power for the SD Bus If the Host Controller supports the Current Limit function it can be protected from an illegal card by stopping power supply to the card in which case this bit indicates a failure status A reading of 1 for this bit means that the Host Controller is not supplying power to the SD card due to some failure A reading of 0 for this bit means that the Host Controller is supplying power and no error has occurred The Host Controller may require some sampling time to detect the current limit DWC_mshc Host Controller does not support this function this bit is always set to 0
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Power Fail */
            UINT16 AUTO_CMD_ERR                                                           : 1;      /* [    8] Auto CMD Error
                                                                                                               This error status is used by Auto CMD12 and Auto CMD23 in SDeMMC mode This bit is set when detecting that any of the bits D00 to D05 in Auto CMD Error Status register has changed from 0 to 1 D07 is effective in case of Auto CMD12 Auto CMD Error Status register is valid while this bit is set to 1 and may be cleared by clearing of this bit
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 ADMA_ERR                                                               : 1;      /* [    9] ADMA Error
                                                                                                               This bit is set when the Host Controller detects error during ADMA-based data transfer The error could be due to following reasons
                                                                                                               Error response received from System bus Master IF
                                                                                                               ADMA3ADMA2 Descriptors invalid
                                                                                                               CQE Task or Transfer descriptors invalid
                                                                                                               When the error occurs the state of the ADMA is saved in the ADMA Error Status register
                                                                                                               In eMMC CQE mode
                                                                                                               The Host Controller generates this Interrupt when it detects an invalid descriptor data Valid0 at the ST_FDS state ADMA Error State in the ADMA Error Status indicates that an error has occurred in ST_FDS state The Host Driver may find that Valid bit is not set at the error descriptor
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 TUNING_ERR                                                             : 1;      /* [   10] Tuning Error
                                                                                                               This bit is set when an unrecoverable error is detected in a tuning circuit except during the tuning procedure occurrence of an error during tuning procedure is indicated by Sampling Clock Select in the Host Control 2 register By detecting Tuning Error Host Driver needs to abort a command executing and perform tuning To reset tuning circuit Sampling Clock Select is set to 0 before executing tuning procedure The Tuning Error is higher priority than the other error interrupts generated during data transfer By detecting Tuning Error the Host Driver must discard data transferred by a current readwrite command and retry data transfer after the Host Controller retrieved from the tuning circuit error This is applicable in SDeMMC mode
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 RESP_ERR                                                               : 1;      /* [   11] Response Error
                                                                                                               Host Controller Version 400 supports response error check function to avoid overhead of response error check by Host Driver during DMA execution If Response Error Check Enable is set to 1 in the Transfer Mode register Host Controller Checks R1 or R5 response If an error is detected in a response this bit is set to 1This is applicable in SDeMMC mode
                                                                                                               In UHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 BOOT_ACK_ERR                                                           : 1;      /* [   12] Boot Acknowledgement Error
                                                                                                               This bit is set when there is a timeout for boot acknowledgement or when detecting boot ack status having a value other than 010 This is applicable only when boot acknowledgement is expected in eMMC mode
                                                                                                               In SDUHS-II mode this bit is irrelevant
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 VENDOR_ERR1                                                            : 1;      /* [   13] This bit VENDOR_ERR1 of the ERROR_INT_STAT_R register is reserved It always returns 0 */
            UINT16 VENDOR_ERR2                                                            : 1;      /* [   14] This bit VENDOR_ERR2 of the ERROR_INT_STAT_R register is reserved It always returns 0 */
            UINT16 VENDOR_ERR3                                                            : 1;      /* [   15] This bit VENDOR_ERR3 of the ERROR_INT_STAT_R register is reserved It always returns 0 */
        }Bit;
    }ERROR_INT_STAT_R;
    union { /* 0x0034 [Excel Line :0123]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_COMPLETE_STAT_EN                                                   : 1;      /* [    0] Command Complete Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 XFER_COMPLETE_STAT_EN                                                  : 1;      /* [    1] Transfer Complete Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BGAP_EVENT_STAT_EN                                                     : 1;      /* [    2] Block Gap Event Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DMA_INTERRUPT_STAT_EN                                                  : 1;      /* [    3] DMA Interrupt Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BUF_WR_READY_STAT_EN                                                   : 1;      /* [    4] Buffer Write Ready Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BUF_RD_READY_STAT_EN                                                   : 1;      /* [    5] Buffer Read Ready Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_INSERTION_STAT_EN                                                 : 1;      /* [    6] Card Insertion Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_REMOVAL_STAT_EN                                                   : 1;      /* [    7] Card Removal Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_INTERRUPT_STAT_EN                                                 : 1;      /* [    8] Card Interrupt Status Enable
                                                                                                               If this bit is set to 0 the Host Controller clears the interrupt request to the System The Card Interrupt detection is stopped when this bit is cleared and restarted when this bit is set to 1 The Host Driver may clear the Card Interrupt Status Enable before servicing the Card Interrupt and may set this bit again after all interrupt requests from the card are cleared to prevent inadvertent interrupts
                                                                                                               By setting this bit to 0 interrupt input must be masked by implementation so that the interrupt input is not affected by external signal in any state for example floating
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_A_STAT_EN                                                          : 1;      /* [    9] INT_A Embedded Status Enable
                                                                                                               If this bit is set to 0 the Host Controller clears the interrupt request to the System The Host Driver may clear this bit before servicing the INT_A and may set this bit again after all interrupt requests to INT_A pin are cleared to prevent inadvertent interrupts
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_B_STAT_EN                                                          : 1;      /* [   10] INT_B Embedded Status Enable
                                                                                                               If this bit is set to 0 the Host Controller clears the interrupt request to the System The Host Driver may clear this bit before servicing the INT_B and may set this bit again after all interrupt requests to INT_B pin are cleared to prevent inadvertent interrupts
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_C_STAT_EN                                                          : 1;      /* [   11] INT_C Embedded Status Enable
                                                                                                               If this bit is set to 0 the Host Controller clears the interrupt request to the System The Host Driver may clear this bit before servicing the INT_C and may set this bit again after all interrupt requests to INT_C pin are cleared to prevent inadvertent interrupts
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RE_TUNE_EVENT_STAT_EN                                                  : 1;      /* [   12] Re-Tuning Event UHS-I only Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 FX_EVENT_STAT_EN                                                       : 1;      /* [   13] FX Event Status Enable
                                                                                                               This bit is added from Version 410
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CQE_EVENT_STAT_EN                                                      : 1;      /* [   14] CQE Event Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RESERVED1                                                              : 1;      /* [   15]  */
        }Bit;
    }NORMAL_INT_STAT_EN_R;
    union { /* 0x0036 [Excel Line :0139]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_TOUT_ERR_STAT_EN                                                   : 1;      /* [    0] Command Timeout Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_CRC_ERR_STAT_EN                                                    : 1;      /* [    1] Command CRC Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_END_BIT_ERR_STAT_EN                                                : 1;      /* [    2] Command End Bit Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_IDX_ERR_STAT_EN                                                    : 1;      /* [    3] Command Index Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DATA_TOUT_ERR_STAT_EN                                                  : 1;      /* [    4] Data Timeout Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DATA_CRC_ERR_STAT_EN                                                   : 1;      /* [    5] Data CRC Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DATA_END_BIT_ERR_STAT_EN                                               : 1;      /* [    6] Data End Bit Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CUR_LMT_ERR_STAT_EN                                                    : 1;      /* [    7] Current Limit Error Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 AUTO_CMD_ERR_STAT_EN                                                   : 1;      /* [    8] Auto CMD Error Status Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 ADMA_ERR_STAT_EN                                                       : 1;      /* [    9] ADMA Error Status Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 TUNING_ERR_STAT_EN                                                     : 1;      /* [   10] Tuning Error Status Enable UHS-I Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RESP_ERR_STAT_EN                                                       : 1;      /* [   11] Response Error Status Enable SD Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BOOT_ACK_ERR_STAT_EN                                                   : 1;      /* [   12] Boot Acknowledgment Error eMMC Mode only
                                                                                                               Setting this bit to 1 enables setting of Boot Acknowledgment Error in Error Interrupt Status register ERROR_INT_STAT_R
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_STAT_EN1                                                    : 1;      /* [   13] The 13th bit of Error Interrupt Status Enable register is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_STAT_EN2                                                    : 1;      /* [   14] The 14th bit of Error Interrupt Status Enable register is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_STAT_EN3                                                    : 1;      /* [   15] The 15th bit of Error Interrupt Status Enable register is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
        }Bit;
    }ERROR_INT_STAT_EN_R;
    union { /* 0x0038 [Excel Line :0155]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_COMPLETE_SIGNAL_EN                                                 : 1;      /* [    0] Command Complete Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 XFER_COMPLETE_SIGNAL_EN                                                : 1;      /* [    1] Transfer Complete Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BGAP_EVENT_SIGNAL_EN                                                   : 1;      /* [    2] Block Gap Event Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DMA_INTERRUPT_SIGNAL_EN                                                : 1;      /* [    3] DMA Interrupt Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BUF_WR_READY_SIGNAL_EN                                                 : 1;      /* [    4] Buffer Write Ready Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BUF_RD_READY_SIGNAL_EN                                                 : 1;      /* [    5] Buffer Read Ready Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_INSERTION_SIGNAL_EN                                               : 1;      /* [    6] Card Insertion Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_REMOVAL_SIGNAL_EN                                                 : 1;      /* [    7] Card Removal Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CARD_INTERRUPT_SIGNAL_EN                                               : 1;      /* [    8] Card Interrupt Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_A_SIGNAL_EN                                                        : 1;      /* [    9] INT_A Embedded Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_B_SIGNAL_EN                                                        : 1;      /* [   10] INT_B Embedded Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 INT_C_SIGNAL_EN                                                        : 1;      /* [   11] INT_C Embedded Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RE_TUNE_EVENT_SIGNAL_EN                                                : 1;      /* [   12] Re-Tuning Event UHS-I only Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 FX_EVENT_SIGNAL_EN                                                     : 1;      /* [   13] FX Event Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CQE_EVENT_SIGNAL_EN                                                    : 1;      /* [   14] Command Queuing Engine Event Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RESERVED1                                                              : 1;      /* [   15]  */
        }Bit;
    }NORMAL_INT_SIGNAL_EN_R;
    union { /* 0x003A [Excel Line :0171]  */
        UINT16 Reg;
        struct {
            UINT16 CMD_TOUT_ERR_SIGNAL_EN                                                 : 1;      /* [    0] Command Timeout Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_CRC_ERR_SIGNAL_EN                                                  : 1;      /* [    1] Command CRC Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_END_BIT_ERR_SIGNAL_EN                                              : 1;      /* [    2] Command End Bit Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CMD_IDX_ERR_SIGNAL_EN                                                  : 1;      /* [    3] Command Index Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE No error
                                                                                                               0x1 TRUE Error */
            UINT16 DATA_TOUT_ERR_SIGNAL_EN                                                : 1;      /* [    4] Data Timeout Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DATA_CRC_ERR_SIGNAL_EN                                                 : 1;      /* [    5] Data CRC Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 DATA_END_BIT_ERR_SIGNAL_EN                                             : 1;      /* [    6] Data End Bit Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 CUR_LMT_ERR_SIGNAL_EN                                                  : 1;      /* [    7] Current Limit Error Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 AUTO_CMD_ERR_SIGNAL_EN                                                 : 1;      /* [    8] Auto CMD Error Signal Enable SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 ADMA_ERR_SIGNAL_EN                                                     : 1;      /* [    9] ADMA Error Signal Enable
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 TUNING_ERR_SIGNAL_EN                                                   : 1;      /* [   10] Tuning Error Signal Enable UHS-I Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 RESP_ERR_SIGNAL_EN                                                     : 1;      /* [   11] Response Error Signal Enable SD Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 BOOT_ACK_ERR_SIGNAL_EN                                                 : 1;      /* [   12] Boot Acknowledgment Error eMMC Mode only
                                                                                                               Setting this bit to 1 enables generating interrupt signal when Boot Acknowledgement Error in Error Interrupt Status register is set
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_SIGNAL_EN1                                                  : 1;      /* [   13] The 14th bit of Error Interrupt Signal Enable is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_SIGNAL_EN2                                                  : 1;      /* [   14] The 15th bit of Error Interrupt Signal Enable is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
            UINT16 VENDOR_ERR_SIGNAL_EN3                                                  : 1;      /* [   15] The 16th bit of Error Interrupt Signal Enable is reserved
                                                                                                               Values
                                                                                                               0x0 FALSE Masked
                                                                                                               0x1 TRUE Enabled */
        }Bit;
    }ERROR_INT_SIGNAL_EN_R;
    union { /* 0x003C [Excel Line :0187]  */
        UINT16 Reg;
        struct {
            UINT16 AUTO_CMD12_NOT_EXEC                                                    : 1;      /* [    0] Auto CMD12 Not Executed
                                                                                                               If multiple memory block data transfer is not started due to a command error this bit is not set because it is not necessary to issue an Auto CMD12 Setting this bit to 1 means that the Host Controller cannot issue Auto CMD12 to stop multiple memory block data transfer due to some error If this bit is set to 1 error status bits D04-D01 is meaningless
                                                                                                               This bit is set to 0 when Auto CMD Error is generated by Auto CMD23
                                                                                                               Values
                                                                                                               0x1 TRUE Not Executed
                                                                                                               0x0 FALSE Executed */
            UINT16 AUTO_CMD_TOUT_ERR                                                      : 1;      /* [    1] Auto CMD Timeout Error
                                                                                                               This bit is set if no response is returned with 64 SDCLK cycles from the end bit of the command
                                                                                                               If this bit is set to 1 error status bits D04-D01 are meaningless
                                                                                                               Values
                                                                                                               0x1 TRUE Time out
                                                                                                               0x0 FALSE No Error */
            UINT16 AUTO_CMD_CRC_ERR                                                       : 1;      /* [    2] Auto CMD CRC Error
                                                                                                               This bit is set when detecting a CRC error in the command response
                                                                                                               Values
                                                                                                               0x1 TRUE CRC Error Generated
                                                                                                               0x0 FALSE No Error */
            UINT16 AUTO_CMD_EBIT_ERR                                                      : 1;      /* [    3] Auto CMD End Bit Error
                                                                                                               This bit is set when detecting that the end bit of command response is 0
                                                                                                               Values
                                                                                                               0x1 TRUE End Bit Error Generated
                                                                                                               0x0 FALSE No Error */
            UINT16 AUTO_CMD_IDX_ERR                                                       : 1;      /* [    4] Auto CMD Index Error
                                                                                                               This bit is set if the command index error occurs in response to a command
                                                                                                               Values
                                                                                                               0x1 TRUE Error
                                                                                                               0x0 FALSE No Error */
            UINT16 AUTO_CMD_RESP_ERR                                                      : 1;      /* [    5] Auto CMD Response Error
                                                                                                               This bit is set when Response Error Check Enable in the Transfer Mode register is set to 1 and an error is detected in R1 response of either Auto CMD12 or CMD13 This status is ignored if any bit between D00 to D04 is set to 1
                                                                                                               Values
                                                                                                               0x1 TRUE Error
                                                                                                               0x0 FALSE No Error */
            UINT16 RESERVED2                                                              : 1;      /* [    6]  */
            UINT16 CMD_NOT_ISSUED_AUTO_CMD12                                              : 1;      /* [    7] Command Not Issued By Auto CMD12 Error
                                                                                                               If this bit is set to 1 CMD_wo_DAT is not executed due to an Auto CMD12 Error D04-D01 in this register
                                                                                                               This bit is set to 0 when Auto CMD Error is generated by Auto CMD23
                                                                                                               Values
                                                                                                               0x1 TRUE Not Issued
                                                                                                               0x0 FALSE No Error */
            UINT16 RESERVED1                                                              : 8;      /* [ 15:8]  */
        }Bit;
    }AUTO_CMD_STAT_R;
    union { /* 0x003E [Excel Line :0196]  */
        UINT16 Reg;
        struct {
            UINT16 UHS_MODE_SEL                                                           : 3;      /* [  2:0] ModeeMMC Speed Mode Select
                                                                                                               These bits are used to select UHS mode in the SD mode of operation In eMMC mode these bits are used to select eMMC Speed mode
                                                                                                               UHS Mode SDUHS-II mode only
                                                                                                               0x0 SDR12
                                                                                                               0x1 SDR25
                                                                                                               0x2 SDR50
                                                                                                               0x3 SDR104
                                                                                                               0x4 DDR50
                                                                                                               0x5 Reserved
                                                                                                               0x6 Reserved
                                                                                                               0x7 UHS-II
                                                                                                               eMMC Speed Mode eMMC mode only
                                                                                                               0x0 Legacy
                                                                                                               0x1 High Speed SDR
                                                                                                               0x2 Reserved
                                                                                                               0x3 HS200
                                                                                                               0x4 High Speed DDR
                                                                                                               0x5 Reserved
                                                                                                               0x6 Reserved
                                                                                                               0x7 HS400
                                                                                                               Values
                                                                                                               0x0 SDR12 SDR12Legacy
                                                                                                               0x1 SDR25 SDR25High Speed SDR
                                                                                                               0x2 SDR50 SDR50
                                                                                                               0x3 SDR104 SDR104HS200
                                                                                                               0x4 DDR50 DDR50High Speed DDR
                                                                                                               0x5 RSVD5 Reserved
                                                                                                               0x6 RSVD6 Reserved
                                                                                                               0x7 UHS2 UHS-IIHS400 */
            UINT16 SIGNALING_EN                                                           : 1;      /* [    3] 18V Signaling Enable
                                                                                                               This bit controls voltage regulator for IO cell in UHS-IeMMC speed modes Setting this bit from 0 to 1 starts changing the signal voltage from 33V to 18V Host Controller clears this bit if switching to 18 signaling fails The value is reflected on the uhs1_swvolt_en pinThis bit shall be set to 0 in UHS-II mode
                                                                                                               Note This bit must be set for all UHS-I speed modes SDR12SDR25SDR50SDR104DDR50
                                                                                                               Values
                                                                                                               0x0 V_3_3 33V Signalling
                                                                                                               0x1 V_1_8 18V Signalling */
            UINT16 DRV_STRENGTH_SEL                                                       : 2;      /* [  5:4] Driver Strength Select
                                                                                                               This bit is used to select the Host Controller output driver in 18V signaling UHS-IeMMC speed modes The bit depends on setting of Preset Value Enable The value is reflected on the uhs1_drv_sth pinThis bit is irrelevant in UHS-II mode
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver TYPEB is selected
                                                                                                               0x1 TYPEA Driver TYPEA is selected
                                                                                                               0x2 TYPEC Driver TYPEC is selected
                                                                                                               0x3 TYPED Driver TYPED is selected */
            UINT16 EXEC_TUNING                                                            : 1;      /* [    6] Execute Tuning
                                                                                                               This bit is set to 1 to start the tuning procedure in UHS-IeMMC speed modes and this bit is automatically cleared when tuning procedure is completedThis bit is irrelevant in UHS-II mode
                                                                                                               Values
                                                                                                               0x0 FALSE Not Tuned or Tuning completed
                                                                                                               0x1 TRUE Execute Tuning */
            UINT16 SAMPLE_CLK_SEL                                                         : 1;      /* [    7] Sampling Clock Select
                                                                                                               This bit is used by the Host Controller to select the sampling clock in SDeMMC mode to receive CMD and DAT This bit is set by the tuning procedure and is valid after the completion of tuning when Execute Tuning is cleared Setting this bit to 1 means that tuning is completed successfully and setting this bit to 0 means that tuning has failed The value is reflected on the sample_cclk_sel pinThis bit is irrelevant in UHS-II mode
                                                                                                               Values
                                                                                                               0x0 FALSE Fixed clock is used to sample data
                                                                                                               0x1 TRUE Tuned clock is used to sample data */
            UINT16 UHS2_IF_ENABLE                                                         : 1;      /* [    8] UHS-II Interface Enable
                                                                                                               This bit is used to enable the UHS-II Interface The value is reflected on the uhs2_if_en pin
                                                                                                               Values
                                                                                                               0x0 FALSE SDeMMC Interface Enabled
                                                                                                               0x1 TRUE UHS-II Interface Enabled */
            UINT16 RESERVED1                                                              : 1;      /* [    9]  */
            UINT16 ADMA2_LEN_MODE                                                         : 1;      /* [   10] ADMA2 Length Mode
                                                                                                               This bit selects ADMA2 Length mode to be either 16-bit or 26-bit
                                                                                                               Values
                                                                                                               0x0 FALSE 16-bit Data Length Mode
                                                                                                               0x1 TRUE 26-bit Data Length Mode */
            UINT16 CMD23_ENABLE                                                           : 1;      /* [   11] CMD23 Enable
                                                                                                               If the card supports CMD23 this bit is set to 1 This bit is used to select Auto CMD23 or Auto CMD12 for ADMA3 data transfer
                                                                                                               Values
                                                                                                               0x0 FALSE Auto CMD23 is disabled
                                                                                                               0x1 TRUE Auto CMD23 is enabled */
            UINT16 HOST_VER4_ENABLE                                                       : 1;      /* [   12] Host Version 4 Enable
                                                                                                               This bit selects either Version 300 compatible mode or Version 4 mode
                                                                                                               Functions of following fields are modified for Host Version 4 mode
                                                                                                               SDMA Address SDMA uses ADMA System Address 05Fh-058h instead of SDMA System Address register 003h-000h
                                                                                                               ADMA2ADMA3 selection ADMA3 is selected by DMA select in Host Control 1 register
                                                                                                               64-bit ADMA Descriptor Size 128-bit descriptor is used instead of 96-bit descriptor when 64-bit Addressing is set to 1
                                                                                                               Selection of 16-bit64-bit System Addressing Either 16-bit or 64-bit system addressing is selected by 64-bit Addressing bit in this register
                                                                                                               16-bit Block Count SDMA System Address register 003h-000h is modified to 16-bit Block Count register
                                                                                                               Note It is recommended not to program ADMA3 Integrated Descriptor Address registers UHS-II registers and Command Queuing registers if applicable while operating in Host version less than 4 mode Host Version 4 Enable  0
                                                                                                               Values
                                                                                                               0x0 FALSE Version 300 compatible mode
                                                                                                               0x1 TRUE Version 4 mode */
            UINT16 ADDRESSING                                                             : 1;      /* [   13] 64-bit Addressing
                                                                                                               This bit is effective when Host Version 4 Enable is set to 1
                                                                                                               Values
                                                                                                               0x0 FALSE 16 bits addressing
                                                                                                               0x1 TRUE 64 bits addressing */
            UINT16 ASYNC_INT_ENABLE                                                       : 1;      /* [   14] Asynchronous Interrupt Enable
                                                                                                               This bit can be set if a card supports asynchronous interrupts and Asynchronous Interrupt Support is set to 1 in the Capabilities register
                                                                                                               Values
                                                                                                               0x0 FALSE Disabled
                                                                                                               0x1 TRUE Enabled */
            UINT16 PRESET_VAL_ENABLE                                                      : 1;      /* [   15] Preset Value Enable
                                                                                                               This bit enables automatic selection of SDCLK frequency and Driver strength Preset Value registers When Preset Value Enable is set SDCLK frequency generation Frequency Select and Clock Generator Select and the driver strength selection are performed by the controller These values are selected from set of Preset Value registers based on selected speed mode
                                                                                                               Note For more information see the FAQ on Preset Register in the DWC_mshc Databook
                                                                                                               Values
                                                                                                               0x0 FALSE SDCLK and Driver Strength are controlled by Host Driver
                                                                                                               0x1 TRUE Automatic Selection by Preset Value are Enabled */
        }Bit;
    }HOST_CTRL2_R;
    union { /* 0x0040 [Excel Line :0209]  */
        UINT32 Reg;
        struct {
            UINT32 TOUT_CLK_FREQ                                                          : 6;      /* [  5:0] Timeout Clock Frequency
                                                                                                               This bit shows the base clock frequency used to detect Data Timeout Error The Timeout Clock unit defines the unit of timeout clock frequency It can be KHz or MHz
                                                                                                               0x00  Get information through another method
                                                                                                               0x01  1KHz  1MHz
                                                                                                               0x02  2KHz  2MHz
                                                                                                               0x03  3KHz  3MHz

                                                                                                               0x3F  63KHz  63MHz */
            UINT32 RESERVED2                                                              : 1;      /* [    6]  */
            UINT32 TOUT_CLK_UNIT                                                          : 1;      /* [    7] Timeout Clock Unit
                                                                                                               This bit shows the unit of base clock frequency used to detect Data TImeout Error
                                                                                                               Values
                                                                                                               0x0 KHZ KHz
                                                                                                               0x1 MHZ MHz */
            UINT32 BASE_CLK_FREQ                                                          : 8;      /* [ 15:8] Base Clock Frequency for SD clock
                                                                                                               These bits indicate the base maximum clock frequency for the SD Clock The definition of these bits depend on the Host Controller Version
                                                                                                               6-Bit Base Clock Frequency This mode is supported by the Host Controller version 100 and 200 The upper 2 bits are not effective and are always 0 The unit values are 1 MHz The supported clock range is 10 MHz to 63 MHz
                                                                                                               -0x00  Get information through another method
                                                                                                               -0x01  1 MHz
                                                                                                               -0x02  2 MHz
                                                                                                               -
                                                                                                               -0x3F  63 MHz
                                                                                                               -0x40-0xFF  Not Supported
                                                                                                               8-Bit Base Clock Frequency This mode is supported by the Host Controller version 300 The unit values are 1 MHz The supported clock range is 10 MHz to 255 MHz
                                                                                                               -0x00  Get information through another method
                                                                                                               -0x01  1 MHz
                                                                                                               -0x02  2 MHz
                                                                                                               -
                                                                                                               -0xFF  255 MHz
                                                                                                               If the frequency is 165 MHz the larger value is set to 0001001b 17 MHz because the Host Driver uses this value to calculate the clock divider value and it does not exceed the upper limit of the SD Clock frequency If these bits are all 0 the Host system has to get information using a different method */
            UINT32 MAX_BLK_LEN                                                            : 2;      /* [17:16] Maximum Block Length
                                                                                                               This bit indicates the maximum block size that the Host driver can read and write to the buffer in the Host Controller The buffer transfers this block size without wait cycles The transfer block length is always 512 bytes for the SD Memory irrespective of this bit
                                                                                                               Values
                                                                                                               0x0 ZERO 512 Byte
                                                                                                               0x1 ONE 1024 Byte
                                                                                                               0x2 TWO 2048 Byte
                                                                                                               0x3 THREE Reserved */
            UINT32 EMBEDDED_8_BIT                                                         : 1;      /* [   18] 8-bit Support for Embedded Device
                                                                                                               This bit indicates whether the Host Controller is capable of using an 8-bit bus width mode This bit is not effective when the Slot Type is set to 10b
                                                                                                               Values
                                                                                                               0x0 FALSE 8-bit Bus Width not Supported
                                                                                                               0x1 TRUE 8-bit Bus Width Supported */
            UINT32 ADMA2_SUPPORT                                                          : 1;      /* [   19] ADMA2 Support
                                                                                                               This bit indicates whether the Host Controller is capable of using ADMA2
                                                                                                               Values
                                                                                                               0x0 FALSE ADMA2 not Supported
                                                                                                               0x1 TRUE ADMA2 Supported */
            UINT32 RESERVED1                                                              : 1;      /* [   20]  */
            UINT32 HIGH_SPEED_SUPPORT                                                     : 1;      /* [   21] High Speed Support
                                                                                                               This bit indicates whether the Host Controller and the Host System supports High Speed mode and they can supply the SD Clock frequency from 25 MHz to 50 MHz
                                                                                                               Values
                                                                                                               0x0 FALSE High Speed not Supported
                                                                                                               0x1 TRUE High Speed Supported */
            UINT32 SDMA_SUPPORT                                                           : 1;      /* [   22] SDMA Support
                                                                                                               This bit indicates whether the Host Controller is capable of using SDMA to transfer data between the system memory and the Host Controller directly
                                                                                                               Values
                                                                                                               0x0 FALSE SDMA not Supported
                                                                                                               0x1 TRUE SDMA Supported */
            UINT32 SUS_RES_SUPPORT                                                        : 1;      /* [   23] SuspenseResume Support
                                                                                                               This bit indicates whether the Host Controller supports SuspendResume functionality If this bit is 0 the Host Driver does not issue either Suspend or Resume commands because the Suspend and Resume mechanism is not supported
                                                                                                               Values
                                                                                                               0x0 FALSE Not Supported
                                                                                                               0x1 TRUE Supported */
            UINT32 VOLT_33                                                                : 1;      /* [   24] Voltage Support for 33V
                                                                                                               Values
                                                                                                               0x0 FALSE 33V Not Supported
                                                                                                               0x1 TRUE 33V Supported */
            UINT32 VOLT_30                                                                : 1;      /* [   25] Voltage Support for SD 30V or Embedded 12V
                                                                                                               Values
                                                                                                               0x0 FALSE SD 30V or Embedded 12V Not Supported
                                                                                                               0x1 TRUE SD 30V or Embedded Supported */
            UINT32 VOLT_18                                                                : 1;      /* [   26] Voltage Support for 18V
                                                                                                               Values
                                                                                                               0x0 FALSE 18V Not Supported
                                                                                                               0x1 TRUE 18V Supported */
            UINT32 SYS_ADDR_64_V4                                                         : 1;      /* [   27] 64-bit System Address Support for V4
                                                                                                               This bit sets the Host Controller to support 64-bit System Addressing of V4 mode When this bit is set to 1 full or part of 64-bit address must be used to decode the Host Controller Registers so that Host Controller Registers can be placed above system memory area 64-bit address decode of Host Controller registers is effective regardless of setting to 64-bit Addressing in Host Control 2
                                                                                                               If this bit is set to 1 64-bit DMA Addressing for version 4 is enabled by setting Host Version 4 Enable HOST_VER4_ENABLE  1 and by setting 64-bit Addressing ADDRESSING 1 in the Host Control 2 register SDMA can be used and ADMA2 uses 128-bit Descriptor
                                                                                                               Values
                                                                                                               0x0 FALSE 64-bit System Address for V4 is Not Supported
                                                                                                               0x1 TRUE 64-bit System Address for V4 is Supported */
            UINT32 SYS_ADDR_64_V3                                                         : 1;      /* [   28] 64-bit System Address Support for V3
                                                                                                               This bit sets the Host controller to support 64-bit System Addressing of V3 mode
                                                                                                               SDMA cannot be used in 64-bit Addressing in Version 3 Mode
                                                                                                               If this bit is set to 1 64-bit ADMA2 with using 96-bit Descriptor can be enabled by setting Host Version 4 Enable HOST_VER4_ENABLE  0 and DMA select DMA_SEL  11b
                                                                                                               Values
                                                                                                               0x0 FALSE 64-bit System Address for V3 is Not Supported
                                                                                                               0x1 TRUE 64-bit System Address for V3 is Supported */
            UINT32 ASYNC_INT_SUPPORT                                                      : 1;      /* [   29] Asynchronous Interrupt Support SD Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Asynchronous Interrupt Not Supported
                                                                                                               0x1 TRUE Asynchronous Interrupt Supported */
            UINT32 SLOT_TYPE_R                                                            : 2;      /* [31:30] Slot Type
                                                                                                               These bits indicate usage of a slot by a specific Host System
                                                                                                               Values
                                                                                                               0x0 REMOVABLE_SLOT Removable Card Slot
                                                                                                               0x1 EMBEDDED_SLOT Embedded Slot for one Device
                                                                                                               0x2 SHARED_SLOT Shared Bus Slot SD mode
                                                                                                               0x3 UHS2_EMBEDDED_SLOT UHS-II Multiple Embedded Devices */
        }Bit;
    }CAPABILITIES1_R;
    union { /* 0x0044 [Excel Line :0227]  */
        UINT32 Reg;
        struct {
            UINT32 SDR50_SUPPORT                                                          : 1;      /* [    0] SDR50 Support UHS-I only
                                                                                                               Thsi bit indicates that SDR50 is supported The bit 13 USE_TUNING_SDR50 indicates whether SDR50 requires tuning or not
                                                                                                               Values
                                                                                                               0x0 FALSE SDR50 is not supported
                                                                                                               0x1 TRUE SDR50 is supported */
            UINT32 SDR104_SUPPORT                                                         : 1;      /* [    1] SDR104 Support UHS-I only
                                                                                                               This bit mentions that SDR104 requires tuning
                                                                                                               Values
                                                                                                               0x0 FALSE SDR104 is not supported
                                                                                                               0x1 TRUE SDR104 is supported */
            UINT32 DDR50_SUPPORT                                                          : 1;      /* [    2] DDR50 Support UHS-I only
                                                                                                               Values
                                                                                                               0x0 FALSE DDR50 is not supported
                                                                                                               0x1 TRUE DDR50 is supported */
            UINT32 UHS2_SUPPORT                                                           : 1;      /* [    3] UHS-II Support UHS-II only
                                                                                                               This bit indicates whether Host Controller supports UHS-II
                                                                                                               Values
                                                                                                               0x0 FALSE UHS-II is not supported
                                                                                                               0x1 TRUE UHS-II is supported */
            UINT32 DRV_TYPEA                                                              : 1;      /* [    4] Driver Type A Support UHS-I only
                                                                                                               This bit indicates support of Driver Type A for 18 Signaling
                                                                                                               Values
                                                                                                               0x0 FALSE Driver Type A is not supported
                                                                                                               0x1 TRUE Driver Type A is supported */
            UINT32 DRV_TYPEC                                                              : 1;      /* [    5] Driver Type C Support UHS-I only
                                                                                                               This bit indicates support of Driver Type C for 18 Signaling
                                                                                                               Values
                                                                                                               0x0 FALSE Driver Type C is not supported
                                                                                                               0x1 TRUE Driver Type C is supported */
            UINT32 DRV_TYPED                                                              : 1;      /* [    6] Driver Type D Support UHS-I only
                                                                                                               This bit indicates support of Driver Type D for 18 Signaling
                                                                                                               Values
                                                                                                               0x0 FALSE Driver Type D is not supported
                                                                                                               0x1 TRUE Driver Type D is supported */
            UINT32 RESERVED5                                                              : 1;      /* [    7]  */
            UINT32 RETUNE_CNT                                                             : 4;      /* [ 11:8] Timer Count for Re-Tuning UHS-I only
                                                                                                               0x0 Re-Tuning Timer disabled
                                                                                                               0x1 1 seconds
                                                                                                               0x2 2 seconds
                                                                                                               0x3 4 seconds

                                                                                                               0xB 1024 seconds
                                                                                                               0xC Reserved
                                                                                                               0xD Reserved
                                                                                                               0xE Reserved
                                                                                                               0xF Get information from other source */
            UINT32 RESERVED4                                                              : 1;      /* [   12]  */
            UINT32 USE_TUNING_SDR50                                                       : 1;      /* [   13] Use Tuning for SDR50 UHS-I only
                                                                                                               Values
                                                                                                               0x0 ZERO SDR50 does not require tuning
                                                                                                               0x1 ONE SDR50 requires tuning */
            UINT32 RE_TUNING_MODES                                                        : 2;      /* [15:14] Re-Tuning Modes UHS-I only
                                                                                                               These bits select the re-tuning method and limit the maximum data length
                                                                                                               Values
                                                                                                               0x0 MODE1 Timer
                                                                                                               0x1 MODE2 Timer and Re-Tuning Request Not supported
                                                                                                               0x2 MODE3 Auto Re-Tuning for transfer
                                                                                                               0x3 RSVD_MODE Reserved */
            UINT32 CLK_MUL                                                                : 8;      /* [23:16] Clock Multiplier
                                                                                                               These bits indicate the clock multiplier of the programmable clock generator Setting these bits to 0 means that the Host Controller does not support a programmable clock generator
                                                                                                               0x0 Clock Multiplier is not Supported
                                                                                                               0x1 Clock Multiplier M  2
                                                                                                               0x2 Clock Multiplier M  3

                                                                                                               0xFF Clock Multiplier M  256 */
            UINT32 RESERVED3                                                              : 3;      /* [26:24]  */
            UINT32 ADMA3_SUPPORT                                                          : 1;      /* [   27] ADMA3 Support
                                                                                                               This bit indicates whether the Host Controller is capable of using ADMA3
                                                                                                               Values
                                                                                                               0x0 FALSE ADMA3 not Supported
                                                                                                               0x1 TRUE ADMA3 Supported */
            UINT32 VDD2_18V_SUPPORT                                                       : 1;      /* [   28] 18V VDD2 Support
                                                                                                               This bit indicates support of VDD2 for the Host System
                                                                                                               Values
                                                                                                               0x0 FALSE 18V VDD2 is not Supported
                                                                                                               0x1 TRUE 18V VDD2 is Supported */
            UINT32 RESERVED2                                                              : 1;      /* [   29]  */
            UINT32 RESERVED1                                                              : 2;      /* [31:30]  */
        }Bit;
    }CAPABILITIES2_R;
    union { /* 0x0048 [Excel Line :0245]  */
        UINT32 Reg;
        struct {
            UINT32 MAX_CUR_33V                                                            : 8;      /* [  7:0] Maximum Current for 33V
                                                                                                               This bit specifies the Maximum Current for 33V VDD1 power supply for the card
                                                                                                               0 Get information through another method
                                                                                                               1 4mA
                                                                                                               2 8mA
                                                                                                               3 13mA

                                                                                                               255 1020mA */
            UINT32 MAX_CUR_30V                                                            : 8;      /* [ 15:8] Maximum Current for 30V
                                                                                                               This bit specifies the Maximum Current for 30V VDD1 power supply for the card
                                                                                                               0 Get information through another method
                                                                                                               1 4mA
                                                                                                               2 8mA
                                                                                                               3 13mA

                                                                                                               255 1020mA */
            UINT32 MAX_CUR_18V                                                            : 8;      /* [23:16] Maximum Current for 18V
                                                                                                               This bit specifies the Maximum Current for 18V VDD1 power supply for the card
                                                                                                               0 Get information through another method
                                                                                                               1 4mA
                                                                                                               2 8mA
                                                                                                               3 13mA

                                                                                                               255 1020mA */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }CURR_CAPABILITIES1_R;
    union { /* 0x004C [Excel Line :0249]  */
        UINT32 Reg;
        struct {
            UINT32 MAX_CUR_VDD2_18V                                                       : 8;      /* [  7:0] Maximum Current for 18V VDD2
                                                                                                               This bit specifies the Maximum Current for 18V VDD2 power supply for the UHS-II card
                                                                                                               0 Get information through another method
                                                                                                               1 4mA
                                                                                                               2 8mA
                                                                                                               3 13mA

                                                                                                               255 1020mA */
            UINT32 RESERVED1                                                              : 24;     /* [ 31:8]  */
        }Bit;
    }CURR_CAPABILITIES2_R;
    union { /* 0x0050 [Excel Line :0251]  */
        UINT16 Reg;
        struct {
            UINT16 FORCE_AUTO_CMD12_NOT_EXEC                                              : 1;      /* [    0] Force Event for Auto CMD12 Not Executed
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD12 Not Executed Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 FORCE_AUTO_CMD_TOUT_ERR                                                : 1;      /* [    1] Force Event for Auto CMD Timeout Error
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD Timeout Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 FORCE_AUTO_CMD_CRC_ERR                                                 : 1;      /* [    2] Force Event for Auto CMD CRC Error
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD CRC Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 FORCE_AUTO_CMD_EBIT_ERR                                                : 1;      /* [    3] Force Event for Auto CMD End Bit Error
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD End Bit Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 FORCE_AUTO_CMD_IDX_ERR                                                 : 1;      /* [    4] Force Event for Auto CMD Index Error
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD Index Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 FORCE_AUTO_CMD_RESP_ERR                                                : 1;      /* [    5] Force Event for Auto CMD Response Error
                                                                                                               Values
                                                                                                               0x1 TRUE Auto CMD Response Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 RESERVED2                                                              : 1;      /* [    6]  */
            UINT16 FORCE_CMD_NOT_ISSUED_AUTO_CMD12                                        : 1;      /* [    7] Force Event for Command Not Issued By Auto CMD12 Error
                                                                                                               Values
                                                                                                               0x1 TRUE Command Not Issued By Auto CMD12 Error Status is set
                                                                                                               0x0 FALSE Not Affected */
            UINT16 RESERVED1                                                              : 8;      /* [ 15:8]  */
        }Bit;
    }FORCE_AUTO_CMD_STAT_R;
    union { /* 0x0052 [Excel Line :0260]  */
        UINT16 Reg;
        struct {
            UINT16 FORCE_CMD_TOUT_ERR                                                     : 1;      /* [    0] Force Event for Command Timeout Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Command Timeout Error Status is set */
            UINT16 FORCE_CMD_CRC_ERR                                                      : 1;      /* [    1] Force Event for Command CRC Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Command CRC Error Status is set */
            UINT16 FORCE_CMD_END_BIT_ERR                                                  : 1;      /* [    2] Force Event for Command End Bit Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Command End Bit Error Status is set */
            UINT16 FORCE_CMD_IDX_ERR                                                      : 1;      /* [    3] Force Event for Command Index Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Command Index Error Status is set */
            UINT16 FORCE_DATA_TOUT_ERR                                                    : 1;      /* [    4] Force Event for Data Timeout Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Data Timeout Error Status is set */
            UINT16 FORCE_DATA_CRC_ERR                                                     : 1;      /* [    5] Force Event for Data CRC Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Data CRC Error Status is set */
            UINT16 FORCE_DATA_END_BIT_ERR                                                 : 1;      /* [    6] Force Event for Data End Bit Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Data End Bit Error Status is set */
            UINT16 FORCE_CUR_LMT_ERR                                                      : 1;      /* [    7] Force Event for Current Limit Error
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Current Limit Error Status is set */
            UINT16 FORCE_AUTO_CMD_ERR                                                     : 1;      /* [    8] Force Event for Auto CMD Error SDeMMC Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Auto CMD Error Status is set */
            UINT16 FORCE_ADMA_ERR                                                         : 1;      /* [    9] Force Event for ADMA Error
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE ADMA Error Status is set */
            UINT16 FORCE_TUNING_ERR                                                       : 1;      /* [   10] Force Event for Tuning Error UHS-I Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Tuning Error Status is set */
            UINT16 FORCE_RESP_ERR                                                         : 1;      /* [   11] Force Event for Response Error SD Mode only
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Response Error Status is set */
            UINT16 FORCE_BOOT_ACK_ERR                                                     : 1;      /* [   12] Force Event for Boot Ack error
                                                                                                               Values
                                                                                                               0x0 FALSE Not Affected
                                                                                                               0x1 TRUE Boot ack Error Status is set */
            UINT16 FORCE_VENDOR_ERR1                                                      : 1;      /* [   13] This bit FORCE_VENDOR_ERR1 of the FORCE_ERROR_INT_STAT_R register is reserved It always returns 0 */
            UINT16 FORCE_VENDOR_ERR2                                                      : 1;      /* [   14] This bit FORCE_VENDOR_ERR2 of the FORCE_ERROR_INT_STAT_R register is reserved It always returns 0 */
            UINT16 FORCE_VENDOR_ERR3                                                      : 1;      /* [   15] This bit FORCE_VENDOR_ERR3 of the FORCE_ERROR_INT_STAT_R register is reserved It always returns 0 */
        }Bit;
    }FORCE_ERROR_INT_STAT_R;
    union { /* 0x0054 [Excel Line :0276]  */
        UINT8 Reg;
        struct {
            UINT8 ADMA_ERR_STATES                                                        : 2;      /* [  1:0] ADMA Error States
                                                                                                               These bits indicate the state of ADMA when an error occurs during ADMA data transfer
                                                                                                               Values
                                                                                                               0x0 ST_STOP Stop DMA - SYS_ADR register points to a location next to the error descriptor
                                                                                                               0x1 ST_FDS Fetch Descriptor - SYS_ADR register points to the error descriptor
                                                                                                               0x2 UNUSED Never set this state
                                                                                                               0x3 ST_TFR Transfer Data - SYS_ADR register points to a location next to the error descriptor */
            UINT8 ADMA_LEN_ERR                                                           : 1;      /* [    2] ADMA Length Mismatch Error States
                                                                                                               This error occurs in the following instances
                                                                                                               While the Block Count Enable is being set the total data length specified by the Descriptor table is different from that specified by the Block Count and Block Length
                                                                                                               When the total data length cannot be divided by the block length
                                                                                                               Values
                                                                                                               0x0 NO_ERR No Error
                                                                                                               0x1 ERROR Error */
            UINT8 RESERVED1                                                              : 5;      /* [  7:3]  */
        }Bit;
    }ADMA_ERR_STAT_R;

    UINT8 EMPTY1[3]; /* 0x3 */

    union { /* 0x0058 [Excel Line :0279]  */
        UINT32 Reg;
        struct {
            UINT32 ADMA_SA_LOW                                                            : 32;     /* [ 31:0] ADMA System Address
                                                                                                               These bits indicate the lower 32 bits of the ADMA system address
                                                                                                               SDMA If Host Version 4 Enable is set to 1 this register stores the system address of the data location
                                                                                                               ADMA2 This register stores the byte address of the executing command of the descriptor table
                                                                                                               ADMA3 This register is set by ADMA3 ADMA2 increments the address of this register that points to the next line every time a Descriptor line is fetched */
        }Bit;
    }ADMA_SA_LOW_R;
    union { /* 0x005C [Excel Line :0280]  */
        UINT32 Reg;
        struct {
            UINT32 ADMA_SA_HIGH                                                           : 32;     /* [ 31:0] ADMA System Address
                                                                                                               These bits indicate the higher 32-bit of the ADMA system address */
        }Bit;
    }ADMA_SA_HIGH_R;
    union { /* 0x0060 [Excel Line :0281]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when the Host Controller supports a programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate that the Driver strength is supported by 18V signaling bus speed modes These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_INIT_R;
    union { /* 0x0062 [Excel Line :0285]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate the Driver strength value supported by 18V signaling bus speed modes This field is meaningless for the Default speed mode as it uses 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_DS_R;
    union { /* 0x0064 [Excel Line :0289]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate the Driver strength value supported by 18V signaling bus speed modes This field is meaningless for High speed mode as it uses 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_HS_R;
    union { /* 0x0066 [Excel Line :0293]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate the Driver strength value supported for the SDR12 bus speed mode These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_SDR12_R;
    union { /* 0x0068 [Excel Line :0297]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate the Driver strength value supported for the SDR25 bus speed mode These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_SDR25_R;
    union { /* 0x006A [Excel Line :0301]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               10-bit preset value to be set in SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate Driver strength value supported for SDR50 bus speed mode These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_SDR50_R;
    union { /* 0x006C [Excel Line :0305]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               These bits specify a 10-bit preset value that must be set in the SDCLKRCLK Frequency Select field of the Clock Control register described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate Driver strength value supported for SDR104 bus speed mode These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_SDR104_R;
    union { /* 0x006E [Excel Line :0309]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               These bits specify a 10-bit preset value that must be set in the SDCLKRCLK Frequency Select field of the Clock Control register as described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when Host Controller supports programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate Driver strength value supported for DDR50 bus speed mode These bits are meaningless for 33V signaling
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_DDR50_R;

    UINT8 EMPTY2[4]; /* 0x4 */

    union { /* 0x0074 [Excel Line :0313]  */
        UINT16 Reg;
        struct {
            UINT16 FREQ_SEL_VAL                                                           : 10;     /* [  9:0] SDCLKRCLK Frequency Select Value
                                                                                                               These bits specify the 10-bit preset value that must be set in the SDCLKRCLK Frequency Select field of the Clock Control register as described by a Host System */
            UINT16 CLK_GEN_SEL_VAL                                                        : 1;      /* [   10] Clock Generator Select Value
                                                                                                               This bit is effective when the Host Controller supports a programmable clock generator
                                                                                                               Values
                                                                                                               0x0 FALSE Host Controller Ver20 Compatible Clock Generator
                                                                                                               0x1 PROG Programmable Clock Generator */
            UINT16 RESERVED1                                                              : 3;      /* [13:11]  */
            UINT16 DRV_SEL_VAL                                                            : 2;      /* [15:14] Driver Strength Select Value
                                                                                                               These bits indicate the Driver strength value supported by 18V signaling bus speed modes in the SD mode This field is meaningless for UHS-II mode In eMMC mode these bits can be used for selecting the Drive strength value for HS400 mode
                                                                                                               Values
                                                                                                               0x0 TYPEB Driver Type B is selected
                                                                                                               0x1 TYPEA Driver Type A is selected
                                                                                                               0x2 TYPEC Driver Type C is selected
                                                                                                               0x3 TYPED Driver Type D is selected */
        }Bit;
    }PRESET_UHS2_R;

    UINT8 EMPTY3[2]; /* 0x2 */

    union { /* 0x0078 [Excel Line :0317]  */
        UINT32 Reg;
        struct {
            UINT32 ADMA_ID_LOW                                                            : 32;     /* [ 31:0] ADMA Integrated Descriptor Address
                                                                                                               These bits indicate the lower 32-bit of the ADMA Integrated Descriptor address The start address of Integrated Descriptor is set to these register bits The ADMA3 fetches one Descriptor Address and increments these bits to indicate the next Descriptor address */
        }Bit;
    }ADMA_ID_LOW_R;
    union { /* 0x007C [Excel Line :0318]  */
        UINT32 Reg;
        struct {
            UINT32 ADMA_ID_HIGH                                                           : 32;     /* [ 31:0] ADMA Integrated Descriptor Address
                                                                                                               These bits indicate the higher 32 bit of the ADMA Integrated Descriptor address */
        }Bit;
    }ADMA_ID_HIGH_R;

    UINT8 EMPTY4[102]; /* 0x66 */

    union { /* 0x00E6 [Excel Line :0319]  */
        UINT16 Reg;
        struct {
            UINT16 REG_OFFSET_ADDR                                                        : 12;     /* [ 11:0] Offset Address of Embedded Control register */
            UINT16 RESERVED1                                                              : 4;      /* [15:12]  */
        }Bit;
    }P_EMBEDDED_CNTRL;
    union { /* 0x00E8 [Excel Line :0321]  */
        UINT16 Reg;
        struct {
            UINT16 REG_OFFSET_ADDR                                                        : 12;     /* [ 11:0] Base offset Address for Vendor-Specific registers */
            UINT16 RESERVED1                                                              : 4;      /* [15:12]  */
        }Bit;
    }P_VENDOR_SPECIFIC_AREA;
    union { /* 0x00EA [Excel Line :0323]  */
        UINT16 Reg;
        struct {
            UINT16 REG_OFFSET_ADDR                                                        : 16;     /* [ 15:0] Base offset Address for Command Queuing registers */
        }Bit;
    }P_VENDOR2_SPECIFIC_AREA;

    UINT8 EMPTY5[16]; /* 0x10 */

    union { /* 0x00FC [Excel Line :0324]  */
        UINT16 Reg;
        struct {
            UINT16 INTR_SLOT                                                              : 8;      /* [  7:0] Interrupt signal for each Slot
                                                                                                               These status bits indicate the logical OR of Interrupt signal and Wakeup signal for each slot A maximum of 8 slots can be defined If one interrupt signal is associated with multiple slots the Host Driver can identify the interrupt that is generated by reading these bits By a power on reset or by setting Software Reset For All bit the interrupt signals are de-asserted and this status reads 00h
                                                                                                               Bit 00 Slot 1
                                                                                                               Bit 01 Slot 2
                                                                                                               Bit 02 Slot 3


                                                                                                               Bit 07 Slot 8
                                                                                                               Note MSHC Host Controller support single card slot This register shall always return 0 */
            UINT16 RESERVED1                                                              : 8;      /* [ 15:8]  */
        }Bit;
    }SLOT_INTR_STATUS_R;
    union { /* 0x00FE [Excel Line :0326]  */
        UINT16 Reg;
        struct {
            UINT16 PEC_VERSION_NUM                                                        : 8;      /* [  7:0] Specification Version Number
                                                                                                               These bits indicate the Host controller specification version The upper and lower 4-bits indicate the version Values 0x06-0xFF are reserved
                                                                                                               Values
                                                                                                               0x0 VER_1_00 SD Host Controller Specification Version 100
                                                                                                               0x1 VER_2_00 SD Host Controller Specification Version 200
                                                                                                               0x2 VER_3_00 SD Host Controller Specification Version 300
                                                                                                               0x3 VER_4_00 SD Host Controller Specification Version 400
                                                                                                               0x4 VER_4_10 SD Host Controller Specification Version 410
                                                                                                               0x5 VER_4_20 SD Host Controller Specification Version 420 */
            UINT16 VENDOR_VERSION_NUM                                                     : 8;      /* [ 15:8] Vendor Version Number
                                                                                                               This field is reserved for the vendor version number Host Driver must not use this status */
        }Bit;
    }HOST_CNTRL_VERS_R;

    UINT8 EMPTY6[128]; /* 0x80 */

    union { /* 0x0180 [Excel Line :0328]  */
        UINT32 Reg;
        struct {
            UINT32 EMMC_VER_SUFFIX                                                        : 4;      /* [  3:0] This bit indicates the eMMC version suffix 2nd digit right of decimal point in BCD format */
            UINT32 EMMC_VER_MINOR                                                         : 4;      /* [  7:4] This bit indicates the eMMC minor version 1st digit right of decimal point in BCD format */
            UINT32 EMMC_VER_MAJOR                                                         : 4;      /* [ 11:8] This bit indicates the eMMC major version 1st digit left of decimal point in BCD format */
            UINT32 RESERVED1                                                              : 20;     /* [31:12]  */
        }Bit;
    }CQVER;
    union { /* 0x0184 [Excel Line :0332]  */
        UINT32 Reg;
        struct {
            UINT32 ITCFVAL                                                                : 10;     /* [  9:0] Internal Timer Clock Frequency Value ITCFVAL
                                                                                                               This field scales the frequency of the timer clock provided by ITCFMUL The Final clock frequency of actual timer clock is calculated as ITCFVAL ITCFMUL */
            UINT32 RESERVED3                                                              : 2;      /* [11:10]  */
            UINT32 ITCFMUL                                                                : 4;      /* [15:12] Internal Timer Clock Frequency Multiplier ITCFMUL
                                                                                                               This field indicates the frequency of the clock used for interrupt coalescing timer and for determining the SQS polling period See ITCFVAL definition for details Values 0x5 to 0xF are reserved
                                                                                                               Values
                                                                                                               0x0 CLK_1KHz 1KHz clock
                                                                                                               0x1 CLK_10KHz 10KHz clock
                                                                                                               0x2 CLK_100KHz 100KHz clock
                                                                                                               0x3 CLK_1MHz 1MHz clock
                                                                                                               0x4 CLK_10MHz 10MHz clock */
            UINT32 RESERVED2                                                              : 12;     /* [27:16]  */
            UINT32 CRYPTO_SUPPORT                                                         : 1;      /* [   28] Crypto Support
                                                                                                               This bit indicates whether the Host Controller supports cryptographic operations
                                                                                                               Values
                                                                                                               0x0 FALSE Crypto not Supported
                                                                                                               0x1 TRUE Crypto Supported */
            UINT32 RESERVED1                                                              : 3;      /* [31:29]  */
        }Bit;
    }CQCAP;
    union { /* 0x0188 [Excel Line :0338]  */
        UINT32 Reg;
        struct {
            UINT32 CQ_EN                                                                  : 1;      /* [    0] Enable command queuing engine CQE
                                                                                                               When CQE is disable the software controls the eMMC bus using the registers between the addresses 0x000 to 0x1FF Before the software writes to this bit the software verifies that the eMMC host controller is in idle state and there are no ongoing commands or data transfers When software wants to exit command queuing mode it clears all previous tasks if any before setting this bit to 0
                                                                                                               Values
                                                                                                               0x1 CQE_ENABLE Enable command queuing
                                                                                                               0x0 CQE_DISABLE Disable command queuing */
            UINT32 CR_GENERAL_EN                                                          : 1;      /* [    1] Crypto General Enable
                                                                                                               EnableDisable bit for Crypto Engine If cryptographic operations are not supported this status bit is reserved
                                                                                                               Values
                                                                                                               0x1 ENABLE Enable cryptographic operations for transactions where TDCE1 or CRNQPCE1
                                                                                                               0x0 DISABLE Disable cryptographic operations for all transactions */
            UINT32 RESERVED3                                                              : 6;      /* [  7:2]  */
            UINT32 TASK_DESC_SIZE                                                         : 1;      /* [    8] Bit Value Description
                                                                                                               This bit indicates the size of task descriptor used in host memory This bit can only be configured when Command Queuing Enable bit is 0 command queuing is disabled
                                                                                                               Values
                                                                                                               0x1 TASK_DESC_128b Task descriptor size is 128 bits
                                                                                                               0x0 TASK_DESC_64b Task descriptor size is 64 bits */
            UINT32 RESERVED2                                                              : 3;      /* [ 11:9]  */
            UINT32 DCMD_EN                                                                : 1;      /* [   12] This bit indicates to the hardware whether the Task Descriptor in slot 31 of the TDL is a data transfer descriptor or a direct-command descriptor CQE uses this bit when a task is issued in slot 31 to determine how to decode the Task Descriptor
                                                                                                               Values
                                                                                                               0x1 SLOT31_DCMD_ENABLE Task descriptor in slot 31 is a DCMD Task Descriptor
                                                                                                               0x0 SLOT31_DCMD_DISABLE Task descriptor in slot 31 is a data Transfer Task Descriptor */
            UINT32 RESERVED1                                                              : 19;     /* [31:13]  */
        }Bit;
    }CQCFG;
    union { /* 0x018C [Excel Line :0345]  */
        UINT32 Reg;
        struct {
            UINT32 HALT                                                                   : 1;      /* [    0] Halt request and resume
                                                                                                               Values
                                                                                                               0x1 HALT_CQE Software writes 1 to this bit when it wants to acquire software control over the eMMC bus and to disable CQE from issuing command on the bus
                                                                                                               For example issuing a Discard Task command CMDQ_TASK_MGMT When the software writes 1 CQE completes the ongoing task if any in progress After the task is completed and the CQE is in idle state CQE does not issue new commands and indicates to the software by setting this bit to 1 The software can poll on this bit until it is set to 1 and only then send commands on the eMMC bus
                                                                                                               0x0 RESUME_CQE Software writes 0 to this bit to exit from the halt state and resume CQE activity */
            UINT32 RESERVED2                                                              : 7;      /* [  7:1]  */
            UINT32 CLR_ALL_TASKS                                                          : 1;      /* [    8] Clear all tasks
                                                                                                               This bit can only be written when the controller is halted This bit does not clear tasks in the device The software has to use the CMDQ_TASK_MGMT command to clear devices queue
                                                                                                               Values
                                                                                                               0x1 CLEAR_ALL_TASKS Clears all the tasks in the controller
                                                                                                               0x0 NO_EFFECT Programming 0 has no effect */
            UINT32 RESERVED1                                                              : 23;     /* [ 31:9]  */
        }Bit;
    }CQCTL;
    union { /* 0x0190 [Excel Line :0349]  */
        UINT32 Reg;
        struct {
            UINT32 HAC                                                                    : 1;      /* [    0] Halt complete interrupt
                                                                                                               This status bit is asserted only if CQISEHAC_STE1 when halt bit in the CQCTL register transitions from 0 to 1 indicating that the host controller has completed its current ongoing task and has entered halt state A value of 1 clears this status bit
                                                                                                               Values
                                                                                                               0x1 SET HAC Interrupt is set
                                                                                                               0x0 NOTSET HAC Interrupt is not set */
            UINT32 TCC                                                                    : 1;      /* [    1] Task complete interrupt
                                                                                                               This status bit is asserted if CQISETCC_STE1 when at least one of the following conditions are met
                                                                                                               A task is completed and the INT bit is set in its Task Descriptor
                                                                                                               Interrupt caused by Interrupt Coalescing logic due to timeout
                                                                                                               Interrupt Coalescing logic reached the configured threshold
                                                                                                               A value of 1 clears this status bit
                                                                                                               Values
                                                                                                               0x1 SET TCC Interrupt is set
                                                                                                               0x0 NOTSET TCC Interrupt is not set */
            UINT32 RED                                                                    : 1;      /* [    2] Response error detected interrupt
                                                                                                               This status bit is asserted if CQISERED_STE1 when a response is received with an error bit set in the device status field Configure the CQRMEM register to identify device status bit fields that may trigger an interrupt and that are masked A value of 1 clears this status bit
                                                                                                               Values
                                                                                                               0x1 SET RED Interrupt is set
                                                                                                               0x0 NOTSET RED Interrupt is not set */
            UINT32 TCL                                                                    : 1;      /* [    3] Task cleared interrupt
                                                                                                               This status bit is asserted if CQISETCL_STE1 when a task clear operation is completed by CQE The completed task clear operation is either an individual task clear by writing CQTCLR or clearing of all tasks by writing CQCTL A value of 1 clears this status bit
                                                                                                               Values
                                                                                                               0x1 SET TCL Interrupt is set
                                                                                                               0x0 NOTSET TCL Interrupt is not set */
            UINT32 GCE                                                                    : 1;      /* [    4] General Crypto Error
                                                                                                               If cryptographic operations is supported by host controller CQCAPCS1 and CQCFGGCE1 and encryptiondecryption is enabled TDCE1 this status bit is asserted if CQISEGCE_STE1 when the crypto hardware encounters any of the following error in the processing of a transaction
                                                                                                               Block size is not multiple of 16 bytes
                                                                                                               Total transfer length Block size  Block count is not an integral multiple of DUSize
                                                                                                               Device data block transfer starting address is not aligned to DUSize
                                                                                                               CQE task descriptor data transfer length is not multiple of 16 bytes
                                                                                                               If cryptographic operations are not supported this status bit is reserved
                                                                                                               Values
                                                                                                               0x1 SET GCE interrupt is set
                                                                                                               0x0 UNSET GCE interrupt is not set */
            UINT32 ICCE                                                                   : 1;      /* [    5] Invalid Crypto Configuration Error
                                                                                                               If cryptographic operations is supported by host controller CQCAPCS1 and CQCFGGCE1 and encryptiondecryption is enabled TDCE1 this status bit is asserted if CQISEICCE_STE1 if either of the below conditions are met
                                                                                                               CRYPTOCFG disabled CRYPTOCFG_i_16TDCCICFGE_i0 OR nonexistent TDCCICRCAPCFGC
                                                                                                               Capability index in Configuration CRYPTOCFG_i_16TDCCICAPIDX_i  is greater than maximum number of capabilities supported CAPIDX_i  CRCAPCC
                                                                                                               Data unit size in Configuration CRYPTOCFG_i_16TDCCIDUSIZE_i is not supported by selected capability CRYPTOCAP_xCAPIDX_iSDUSB
                                                                                                               If cryptographic operations are not supported this status bit is reserved
                                                                                                               Values
                                                                                                               0x1 SET ICCE interrupt is set
                                                                                                               0x0 UNSET ICCE interrupt is not set */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }CQIS;
    union { /* 0x0194 [Excel Line :0356]  */
        UINT32 Reg;
        struct {
            UINT32 HAC_STE                                                                : 1;      /* [    0] Halt complete interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISHAC is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISHAC is disabled */
            UINT32 TCC_STE                                                                : 1;      /* [    1] Task complete interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISTCC is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISTCC is disabled */
            UINT32 RED_STE                                                                : 1;      /* [    2] Response error detected interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISRED is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISRED is disabled */
            UINT32 TCL_STE                                                                : 1;      /* [    3] Task cleared interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISTCL is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISTCL is disabled */
            UINT32 GCE_STE                                                                : 1;      /* [    4] General Crypto Error interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISGCE is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISGCE is disabled */
            UINT32 ICCE_STE                                                               : 1;      /* [    5] Invalid Crypto Configuration Error interrupt status enable
                                                                                                               Values
                                                                                                               0x1 INT_STS_ENABLE CQISICCE is set when its interrupt condition is active
                                                                                                               0x0 INT_STS_DISABLE CQISICCE is disabled */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }CQISE;
    union { /* 0x0198 [Excel Line :0363]  */
        UINT32 Reg;
        struct {
            UINT32 HAC_SGE                                                                : 1;      /* [    0] Halt complete interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISHAC interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISHAC interrupt signal generation is disabled */
            UINT32 TCC_SGE                                                                : 1;      /* [    1] Task complete interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISTCC interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISTCC interrupt signal generation is disabled */
            UINT32 RED_SGE                                                                : 1;      /* [    2] Response error detected interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISRED interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISRED interrupt signal generation is disabled */
            UINT32 TCL_SGE                                                                : 1;      /* [    3] Task cleared interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISTCL interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISTCL interrupt signal generation is disabled */
            UINT32 GCE_SGE                                                                : 1;      /* [    4] General Crypto Error interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISGCE interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISGCE interrupt signal generation is disabled */
            UINT32 ICCE_SGE                                                               : 1;      /* [    5] Invalid Crypto Configuration Error interrupt signal enable
                                                                                                               Values
                                                                                                               0x1 INT_SIG_ENABLE CQISICCE interrupt signal generation is active
                                                                                                               0x0 INT_SIG_DISABLE CQISICCE interrupt signal generation is disabled */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }CQISGE;
    union { /* 0x019C [Excel Line :0370]  */
        UINT32 Reg;
        struct {
            UINT32 TOUT_VAL                                                               : 7;      /* [  6:0] Interrupt Coalescing Timeout Value
                                                                                                               Software uses this field to configure the maximum time allowed between the completion of a task on the bus and the generation of an interrupt
                                                                                                               Timer Operation The timer is reset by software during the interrupt service routine It starts running when the first data transfer task with INT0 is completed after the timer was reset When the timer reaches the value configured in ICTOVAL field it generates an interrupt and stops
                                                                                                               The timers unit is equal to 1024 clock periods of the clock whose frequency is specified in the Internal Timer Clock Frequency field CQCAP register
                                                                                                               0x0 Timer is disabled Timeout-based interrupt is not generated
                                                                                                               0x1 Timeout on 01x1024 cycles of timer clock frequency
                                                                                                               0x2 Timeout on 02x1024 cycles of timer clock frequency

                                                                                                               0x7f Timeout on 127x1024 cycles of timer clock frequency
                                                                                                               In order to write to this field the TOUT_VAL_WEN bit must be set at the same write operation */
            UINT32 TOUT_VAL_WEN                                                           : 1;      /* [    7] When software writes 1 to this bit the value TOUT_VAL is updated with the contents written on the same cycle
                                                                                                               Values
                                                                                                               0x1 WEN_SET Sets TOUT_VAL_WEN
                                                                                                               0x0 WEN_CLR clears TOUT_VAL_WEN */
            UINT32 INTC_TH                                                                : 5;      /* [ 12:8] Interrupt Coalescing Counter Threshold filed
                                                                                                               Software uses this field to configure the number of task completions only tasks with INT0 in the Task Descriptor which are required in order to generate an interrupt
                                                                                                               Counter Operation As data transfer tasks with INT0 complete they are counted by CQE The counter is reset by software during the interrupt service routine The counter stops counting when it reaches the value configured in INTC_TH and generates interrupt
                                                                                                               0x0 Interrupt coalescing feature disabled
                                                                                                               0x1 Interrupt coalescing interrupt generated after 1 task when INT0 completes
                                                                                                               0x2 Interrupt coalescing interrupt generated after 2 tasks when INT0 completes

                                                                                                               0x1f Interrupt coalescing interrupt generated after 31 tasks when INT0 completes
                                                                                                               To write to this field the INTC_TH_WEN bit must be set during the same write operation */
            UINT32 RESERVED3                                                              : 2;      /* [14:13]  */
            UINT32 INTC_TH_WEN                                                            : 1;      /* [   15] Interrupt Coalescing Counter Threshold Write Enable
                                                                                                               When software writes 1 to this bit the value INTC_TH is updated with the contents written on the same cycle
                                                                                                               Values
                                                                                                               0x1 WEN_SET Sets INTC_TH_WEN
                                                                                                               0x0 WEN_CLR Clears INTC_TH_WEN */
            UINT32 INTC_RST                                                               : 1;      /* [   16] Counter and Timer Reset
                                                                                                               When host driver writes 1 the interrupt coalescing timer and counter are reset
                                                                                                               Values
                                                                                                               0x1 ASSERT_INTC_RESET Interrupt coalescing timer and counter are reset
                                                                                                               0x0 NO_EFFECT No Effect */
            UINT32 RESERVED2                                                              : 3;      /* [19:17]  */
            UINT32 INTC_STAT                                                              : 1;      /* [   20] Interrupt Coalescing Status Bit
                                                                                                               This bit indicates to the software whether any tasks with INT0 have completed and counted towards interrupt coalescing that is this is set if and only if INTC counter  0
                                                                                                               Values
                                                                                                               0x1 INTC_ATLEAST1_COMP At least one INT0 task completion has been counted INTC counter  0
                                                                                                               0x0 INTC_NO_TASK_COMP INT0 Task completions have not occurred since last counter reset INTC counter  0 */
            UINT32 RESERVED1                                                              : 10;     /* [30:21]  */
            UINT32 INTC_EN                                                                : 1;      /* [   31] Interrupt Coalescing Enable Bit
                                                                                                               Values
                                                                                                               0x1 ENABLE_INT_COALESCING Interrupt coalescing mechanism is active Interrupts are counted and timed and coalesced interrupts are generated
                                                                                                               0x0 DISABLE_INT_COALESCING Interrupt coalescing mechanism is disabled Default */
        }Bit;
    }CQIC;
    union { /* 0x01A0 [Excel Line :0380]  */
        UINT32 Reg;
        struct {
            UINT32 TDLBA                                                                  : 32;     /* [ 31:0] This register stores the LSB bits 310 of the byte address of the head of the Task Descriptor List in system memory
                                                                                                               The size of the task descriptor list is 32  Task Descriptor size  Transfer Descriptor size as configured by the host driver This address is set on 1 KB boundary The lower 10 bits of this register are set to 0 by the software and are ignored by CQE */
        }Bit;
    }CQTDLBA;
    union { /* 0x01A4 [Excel Line :0381]  */
        UINT32 Reg;
        struct {
            UINT32 TDLBAU                                                                 : 32;     /* [ 31:0] This register stores the MSB bits 6332 of the byte address of the head of the Task Descriptor List in system memory
                                                                                                               The size of the task descriptor list is 32  Task Descriptor size  Transfer Descriptor size as configured by Host driver This address is set on 1 KB boundary The lower 10 bits of this register are set to 0 by the software and are ignored by CQE This register is reserved when using 32-bit addressing mode */
        }Bit;
    }CQTDLBAU;
    union { /* 0x01A8 [Excel Line :0382]  */
        UINT32 Reg;
        struct {
            UINT32 DBR                                                                    : 32;     /* [ 31:0] The software configures TDLBA and TDLBAU and enable CQE in CQCFG before using this register
                                                                                                               Writing 1 to bit n of this register triggers CQE to start processing the task encoded in slot n of the TDL Writing 0 by the software does not have any impact on the hardware and does not change the value of the register bit
                                                                                                               CQE always processes tasks according to the order submitted to the list by CQTDBR write transactions CQE processes Data Transfer tasks by reading the Task Descriptor and sending QUEUED_TASK_PARAMS CMD44 and QUEUED_TASK_ADDRESS CMD45 commands to the device CQE processes DCMD tasks in slot 31 when enabled by reading the Task Descriptor and generating the command encoded by its index and argument
                                                                                                               The corresponding bit is cleared to 0 by CQE in one of the following events
                                                                                                               A task execution is completed with success or error
                                                                                                               The task is cleared using CQTCLR register
                                                                                                               All tasks are cleared using CQCTL register
                                                                                                               CQE is disabled using CQCFG register
                                                                                                               Software may initiate multiple tasks at the same time batch submission by writing 1 to multiple bits of this register in the same transaction In the case of batch submission CQE processes the tasks in order of the task index starting with the lowest index If one or more tasks in the batch are marked with QBR the ordering of execution is based on said processing order */
        }Bit;
    }CQTDBR;
    union { /* 0x01AC [Excel Line :0383]  */
        UINT32 Reg;
        struct {
            UINT32 TCN                                                                    : 32;     /* [ 31:0] Task Completion Notification
                                                                                                               Each of the 32 bits are bit mapped to the 32 tasks
                                                                                                               Bit-N1 Task-N has completed execution with success or errors
                                                                                                               Bit-N0 Task-N has not completed could be pending or not submitted
                                                                                                               On task completion software may read this register to know tasks that have completed After reading this register software may clear the relevant bit fields by writing 1 to the corresponding bits */
        }Bit;
    }CQTCN;
    union { /* 0x01B0 [Excel Line :0384]  */
        UINT32 Reg;
        struct {
            UINT32 DQS                                                                    : 32;     /* [ 31:0] Device Queue Status
                                                                                                               Each of the 32 bits are bit mapped to the 32 tasks
                                                                                                               Bit-N1 Device has marked task N as ready for execution
                                                                                                               Bit-N0 Task-N is not ready for execution This task could be pending in device or not submitted
                                                                                                               Host controller updates this register with response of the Device Queue Status command */
        }Bit;
    }CQDQS;
    union { /* 0x01B4 [Excel Line :0385]  */
        UINT32 Reg;
        struct {
            UINT32 DPT                                                                    : 32;     /* [ 31:0] Device-Pending Tasks
                                                                                                               Each of the 32 bits are bit mapped to the 32 tasks
                                                                                                               Bit-N1 Task-N has been successfully queued into the device and is awaiting execution
                                                                                                               Bit-N0 Task-N is not yet queued
                                                                                                               Bit n of this register is set if and only if QUEUED_TASK_PARAMS CMD44 and QUEUED_TASK_ADDRESS CMD45 were sent for this specific task and if this task has not been executed
                                                                                                               The controller sets this bit after receiving a successful response for CMD45 CQE clears this bit after the task has completed execution
                                                                                                               Software reads this register in the task-discard procedure to determine if the task is queued in the device */
        }Bit;
    }CQDPT;
    union { /* 0x01B8 [Excel Line :0386]  */
        UINT32 Reg;
        struct {
            UINT32 TCLR                                                                   : 32;     /* [ 31:0] Writing 1 to bit n of this register orders CQE to clear a task that the software has previously issued
                                                                                                               This bit can only be written when CQE is in Halt state as indicated in CQCFG register Halt bit When software writes 1 to a bit in this register CQE updates the value to 1 and starts clearing the data structures related to the task CQE clears the bit fields sets a value of 0 in CQTCLR and in CQTDBR once the clear operation is complete Software must poll on the CQTCLR until it is cleared to verify that a clear operation was done */
        }Bit;
    }CQTCLR;

    UINT8 EMPTY7[4]; /* 0x4 */

    union { /* 0x01C0 [Excel Line :0387]  */
        UINT32 Reg;
        struct {
            UINT32 SQSCMD_IDLE_TMR                                                        : 16;     /* [ 15:0] This field configures the polling period to be used when using periodic SEND_QUEUE_STATUS CMD13 polling
                                                                                                               Periodic polling is used when tasks are pending in the device but no data transfer is in progress When a SEND_QUEUE_STATUS response indicates that no task is ready for execution CQE counts the configured time until it issues the next SEND_QUEUE_STATUS
                                                                                                               Timer units are clock periods of the clock whose frequency is specified in the Internal Timer Clock Frequency field CQCAP register The minimum value is 0001h 1 clock period and the maximum value is FFFFh 65535 clock periods
                                                                                                               For example a CQCAP field value of 0 indicates a 192 MHz clock frequency period  5208 ns If the setting in CQSSC1CIT is 1000h the calculated polling period is 40965208 ns 21333 ns
                                                                                                               Should be programmed only when CQCFGCQ_EN is 0 */
            UINT32 SQSCMD_BLK_CNT                                                         : 4;      /* [19:16] This field indicates when SQS CMD is sent while data transfer is in progress
                                                                                                               A value of n indicates that CQE sends status command on the CMD line during the transfer of data block BLOCK_CNT-n on the data lines where BLOCK_CNT is the number of blocks in the current transaction
                                                                                                               0x0 SEND_QUEUE_STATUS CMD13 command is not sent during the transaction Instead it is sent only when the data lines are idle
                                                                                                               0x1 SEND_QUEUE_STATUS command is to be sent during the last block of the transaction
                                                                                                               0x2 SEND_QUEUE_STATUS command when last 2 blocks are pending
                                                                                                               0x3 SEND_QUEUE_STATUS command when last 3 blocks are pending

                                                                                                               0xf SEND_QUEUE_STATUS command when last 15 blocks are pending
                                                                                                               Should be programmed only when CQCFGCQ_EN is 0 */
            UINT32 RESERVED1                                                              : 12;     /* [31:20]  */
        }Bit;
    }CQSSC1;
    union { /* 0x01C4 [Excel Line :0390]  */
        UINT32 Reg;
        struct {
            UINT32 SQSCMD_RCA                                                             : 16;     /* [ 15:0] This field provides CQE with the contents of the 16-bit RCA field in SEND_QUEUE_STATUS CMD13 command argument
                                                                                                               CQE copies this field to bits 3116 of the argument when transmitting SEND_ QUEUE_STATUS CMD13 command */
            UINT32 RESERVED1                                                              : 16;     /* [31:16]  */
        }Bit;
    }CQSSC2;
    union { /* 0x01C8 [Excel Line :0392]  */
        UINT32 Reg;
        struct {
            UINT32 DCMD_RESP                                                              : 32;     /* [ 31:0] This register contains the response of the command generated by the last direct command DCMD task that was sent
                                                                                                               Contents of this register are valid only after bit 31 of CQTDBR register is cleared by the controller */
        }Bit;
    }CQCRDCT;

    UINT8 EMPTY8[4]; /* 0x4 */

    union { /* 0x01D0 [Excel Line :0393]  */
        UINT32 Reg;
        struct {
            UINT32 RESP_ERR_MASK                                                          : 32;     /* [ 31:0] The bits of this field are bit mapped to the device response This bit is used as an interrupt mask on the device status filed that is received in R1R1b responses
                                                                                                               1 When a R1R1b response is received with a bit i in the device status set a RED interrupt is generated
                                                                                                               0 When a R1R1b response is received bit i in the device status is ignored
                                                                                                               The reset value of this register is set to trigger an interrupt on all Error type bits in the device status
                                                                                                               Note Responses to CMD13 SQS encode the QSR so that they are ignored by this logic */
        }Bit;
    }CQRMEM;
    union { /* 0x01D4 [Excel Line :0394]  */
        UINT32 Reg;
        struct {
            UINT32 RESP_ERR_CMD_INDX                                                      : 6;      /* [  5:0] This field captures the index of the command that was executed on the command line when the error occurred */
            UINT32 RESERVED4                                                              : 2;      /* [  7:6]  */
            UINT32 RESP_ERR_TASKID                                                        : 5;      /* [ 12:8] This field captures the ID of the task which was executed on the command line when the error occurred */
            UINT32 RESERVED3                                                              : 2;      /* [14:13]  */
            UINT32 RESP_ERR_FIELDS_VALID                                                  : 1;      /* [   15] This bit is updated when an error is detected while a command transaction was in progress
                                                                                                               Values
                                                                                                               0x1 SET Response-related error is detected Check contents of RESP_ERR_TASKID and RESP_ERR_CMD_INDX fields
                                                                                                               0x0 NOT_SET Ignore contents of RESP_ERR_TASKID and RESP_ERR_CMD_INDX */
            UINT32 TRANS_ERR_CMD_INDX                                                     : 6;      /* [21:16] This field captures the index of the command that was executed and whose data transfer has errors */
            UINT32 RESERVED2                                                              : 2;      /* [23:22]  */
            UINT32 TRANS_ERR_TASKID                                                       : 5;      /* [28:24] This field captures the ID of the task that was executed and whose data transfer has errors */
            UINT32 RESERVED1                                                              : 2;      /* [30:29]  */
            UINT32 TRANS_ERR_FIELDS_VALID                                                 : 1;      /* [   31] This bit is updated when an error is detected while a data transfer transaction was in progress
                                                                                                               Values
                                                                                                               0x1 SET data transfer related error detected Check contents of TRANS_ERR_TASKID and TRANS_ERR_CMD_INDX fields
                                                                                                               0x0 NOT_SET Ignore contents of TRANS_ERR_TASKID and TRANS_ERR_CMD_INDX */
        }Bit;
    }CQTERRI;
    union { /* 0x01D8 [Excel Line :0404]  */
        UINT32 Reg;
        struct {
            UINT32 CMD_RESP_INDX                                                          : 6;      /* [  5:0] Last Command Response index
                                                                                                               This field stores the index of the last received command response Controller updates the value every time a command response is received */
            UINT32 RESERVED1                                                              : 26;     /* [ 31:6]  */
        }Bit;
    }CQCRI;
    union { /* 0x01DC [Excel Line :0406]  */
        UINT32 Reg;
        struct {
            UINT32 CMD_RESP_ARG                                                           : 32;     /* [ 31:0] Last Command Response argument
                                                                                                               This field stores the argument of the last received command response Controller updates the value every time a command response is received */
        }Bit;
    }CQCRA;

    UINT8 EMPTY9[800]; /* 0x320 */

    union { /* 0x0500 [Excel Line :0407]  */
        UINT32 Reg;
        struct {
            UINT32 MSHC_VER_ID                                                            : 32;     /* [ 31:0] Current release number
                                                                                                               This field indicates the Synopsys DesignWare Cores DWC_mshcDWC_mshc_lite current release number that is read by an application
                                                                                                               An application reading this register in conjunction with the MSHC_VER_TYPE_R register gathers details of the current release */
        }Bit;
    }MSHC_VER_ID_R;
    union { /* 0x0504 [Excel Line :0408]  */
        UINT32 Reg;
        struct {
            UINT32 MSHC_VER_TYPE                                                          : 32;     /* [ 31:0] Current release type
                                                                                                               This field indicates the Synopsys DesignWare Cores DWC_mshcDWC_mshc_lite current release type that is read by an application
                                                                                                               An application reading this register in conjunction with the MSHC_VER_ID_R register gathers details of the current release */
        }Bit;
    }MSHC_VER_TYPE_R;
    union { /* 0x0508 [Excel Line :0409]  */
        UINT8 Reg;
        struct {
            UINT8 CMD_CONFLICT_CHECK                                                     : 1;      /* [    0] Command conflict check
                                                                                                               This bit enables command conflict check
                                                                                                               Note DWC_mshc controller monitors the CMD line whenever a command is issued and checks whether the value driven on sd_cmd_out matches the value on sd_cmd_in at next subsequent edge of cclk_tx to determine command conflict error This bit is cleared only if the feed back delay including IO Pad delay is more than t_card_clk_period - t_setup where t_setup is the setup time of a flop in DWC_mshc The IO pad delay is consistent across CMD and DATA lines and it is within the value
                                                                                                               2t_card_clk_period - t_setup
                                                                                                               Values
                                                                                                               0x0 DISABLE_CMD_CONFLICT_CHK Disable command conflict check
                                                                                                               0x1 CMD_CONFLICT_CHK_LAT1 Check for command conflict after 1 card clock cycle */
            UINT8 RESERVED2                                                              : 3;      /* [  3:1]  */
            UINT8 SW_CG_DIS                                                              : 1;      /* [    4] Internal clock gating disable control
                                                                                                               This bit must be used to disable IPs internal clock gating when required when disabled clocks are not gated Clocks to the core except hclk must be stopped when programming this bit
                                                                                                               Values
                                                                                                               0x0 ENABLE Internal clock gates are active and clock gating is controlled internally
                                                                                                               0x1 DISABLE Internal clock gating is disabled clocks are not gated internally */
            UINT8 RESERVED1                                                              : 1;      /* [    5]  */
            UINT8 PEDGE_DRV_EN                                                           : 1;      /* [    6] Launches CMDDATA with respect to positive edge of cclk_tx for low speed SDR only support
                                                                                                               Values
                                                                                                               0x0 NEDGE_DRV Launches CMDDATA with respect to negative edge of cclk_tx
                                                                                                               0x1 PEDGE_DRV Launches CMDDATA with respect to positive edge of cclk_tx */
            UINT8 NEDGE_SMPL_EN                                                          : 1;      /* [    7] Samples CMDDATA with respect to negative edge of cclk_rx for low speed SDR only support
                                                                                                               Note Negedge sampling shall be enable only if the total output delay is greater that t_clockperiod  t_setup  t_diff and limited to 15t_clockperiod  t_setup  t_diff
                                                                                                               Values
                                                                                                               0x0 PEDGE_SMPL Samples CMDDATA with respect to positive edge of cclk_rx
                                                                                                               0x1 NEDGE_SMPL Samples CMDDATA with respect to negative edge of cclk_rx */
        }Bit;
    }MSHC_CTRL_R;

    UINT8 EMPTY10[7]; /* 0x7 */

    union { /* 0x0510 [Excel Line :0415]  */
        UINT8 Reg;
        struct {
            UINT8 UNDEFL_INCR_EN                                                         : 1;      /* [    0] Undefined INCR Burst
                                                                                                               Controls generation of undefined length INCR transfer on Master interface
                                                                                                               Values
                                                                                                               0x0 FALSE Undefined INCR type burst is the least preferred burst on AHB Master IF
                                                                                                               0x1 TRUE Undefined INCR type burst is the most preferred burst on AHB Master IF */
            UINT8 BURST_INCR4_EN                                                         : 1;      /* [    1] INCR4 Burst
                                                                                                               Controls generation of INCR4 transfers on Master interface
                                                                                                               Values
                                                                                                               0x0 FALSE AHB INCR4 burst type is not generated on Master IF
                                                                                                               0x1 TRUE AHB INCR4 burst type can be generated on Master IF */
            UINT8 BURST_INCR8_EN                                                         : 1;      /* [    2] INCR8 Burst
                                                                                                               Controls generation of INCR8 transfers on Master interface
                                                                                                               Values
                                                                                                               0x0 FALSE AHB INCR8 burst type is not generated on Master IF
                                                                                                               0x1 TRUE AHB INCR8 burst type can be generated on Master IF */
            UINT8 BURST_INCR16_EN                                                        : 1;      /* [    3] INCR16 Burst
                                                                                                               Controls generation of INCR16 transfers on Master interface
                                                                                                               Values
                                                                                                               0x0 FALSE AHB INCR16 burst type is not generated on Master IF
                                                                                                               0x1 TRUE AHB INCR16 burst type can be generated on Master IF */
            UINT8 RESERVED1                                                              : 4;      /* [  7:4]  */
        }Bit;
    }MBIU_CTRL_R;

    UINT8 EMPTY11[27]; /* 0x1B */

    union { /* 0x052C [Excel Line :0420]  */
        UINT16 Reg;
        struct {
            UINT16 CARD_IS_EMMC                                                           : 1;      /* [    0] eMMC Card present
                                                                                                               This bit indicates the type of card connected An application program this bit based on the card connected to MSHC
                                                                                                               Values
                                                                                                               0x1 EMMC_CARD Card connected to MSHC is an eMMC card
                                                                                                               0x0 NON_EMMC_CARD Card connected to MSHC is a non-eMMC card */
            UINT16 DISABLE_DATA_CRC_CHK                                                   : 1;      /* [    1] Disable Data CRC Check
                                                                                                               This bit controls masking of CRC16 error for Card Write in eMMC mode This is useful in bus testing CMD19 for an eMMC device In bus testing an eMMC card does not send CRC status for a block which may generate CRC error This CRC error can be masked using this bit during bus testing
                                                                                                               Values
                                                                                                               0x1 DISABLE DATA CRC check is disabled
                                                                                                               0x0 ENABLE DATA CRC check is enabled */
            UINT16 EMMC_RST_N                                                             : 1;      /* [    2] EMMC Device Reset signal control
                                                                                                               This register field controls the sd_rst_n output of DWC_mshc
                                                                                                               Values
                                                                                                               0x1 RST_DEASSERT Reset to eMMC device is deasserted
                                                                                                               0x0 RST_ASSERT Reset to eMMC device asserted active low */
            UINT16 EMMC_RST_N_OE                                                          : 1;      /* [    3] Output Enable control for EMMC Device Reset signal PAD control
                                                                                                               This field drived sd_rst_n_oe output of DWC_mshc
                                                                                                               Values
                                                                                                               0x1 ENABLE sd_rst_n_oe is 1
                                                                                                               0x0 DISABLE sd_rst_n_oe is 0 */
            UINT16 RESERVED2                                                              : 4;      /* [  7:4]  */
            UINT16 ENH_STROBE_ENABLE                                                      : 1;      /* [    8] Enhanced Strobe Enable
                                                                                                               This bit instructs DWC_mshc to sample the CMD line using data strobe for HS400 mode
                                                                                                               Values
                                                                                                               0x1 ENH_STB_FOR_CMD CMD line is sampled using data strobe for HS400 mode
                                                                                                               0x0 NO_STB_FOR_CMD CMD line is sampled using cclk_rx for HS400 mode */
            UINT16 CQE_ALGO_SEL                                                           : 1;      /* [    9] Scheduler algorithm selected for execution
                                                                                                               This bit selects the Algorithm used for selecting one of the many ready tasks for execution
                                                                                                               Values
                                                                                                               0x0 PRI_REORDER_PLUS_FCFS Priority based reordering with FCFS to resolve equal priority tasks
                                                                                                               0x1 FCFS_ONLY First come First serve in the order of DBR rings */
            UINT16 CQE_PREFETCH_DISABLE                                                   : 1;      /* [   10] Enable or Disable CQEs PREFETCH feature
                                                                                                               This field allows Software to disable CQEs data prefetch feature when set to 1
                                                                                                               Values
                                                                                                               0x0 PREFETCH_ENABLE CQE can Prefetch data for sucessive WRITE transfers and pipeline sucessive READ transfers
                                                                                                               0x1 PREFETCH_DISABLE Prefetch for WRITE and Pipeline for READ are disabled */
            UINT16 RESERVED1                                                              : 5;      /* [15:11]  */
        }Bit;
    }EMMC_CTRL_R;
    union { /* 0x052E [Excel Line :0429]  */
        UINT16 Reg;
        struct {
            UINT16 MAN_BOOT_EN                                                            : 1;      /* [    0] Mandatory Boot Enable
                                                                                                               This bit is used to initiate the mandatory boot operation The application sets this bit along with VALIDATE_BOOT bit Writing 0 is ignored The DWC_mshc clears this bit after the boot transfer is completed or terminated
                                                                                                               Values
                                                                                                               0x1 MAN_BOOT_EN Mandatory boot enable
                                                                                                               0x0 MAN_BOOT_DIS Mandatory boot disable */
            UINT16 RESERVED2                                                              : 6;      /* [  6:1]  */
            UINT16 VALIDATE_BOOT                                                          : 1;      /* [    7] Validate Mandatory Boot Enable bit
                                                                                                               This bit is used to validate the MAN_BOOT_EN bit
                                                                                                               Values
                                                                                                               0x1 TRUE Validate Mandatory boot enable bit
                                                                                                               0x0 FALSE Ignore Mandatory boot Enable bit */
            UINT16 BOOT_ACK_ENABLE                                                        : 1;      /* [    8] Boot Acknowledge Enable
                                                                                                               When this bit set DWC_mshc checks for boot acknowledge start pattern of 0-1-0 during boot operation This bit is applicable for both mandatory and alternate boot mode
                                                                                                               Values
                                                                                                               0x1 TRUE Boot Ack enable
                                                                                                               0x0 FALSE Boot Ack disable */
            UINT16 RESERVED1                                                              : 3;      /* [ 11:9]  */
            UINT16 BOOT_TOUT_CNT                                                          : 4;      /* [15:12] Boot Ack Timeout Counter Value
                                                                                                               This value determines the interval by which boot ack timeout 50 ms is detected when boot ack is expected during boot operation
                                                                                                               0xF  Reserved
                                                                                                               0xE  TMCLK x 227
                                                                                                                -
                                                                                                               0x1  TMCLK x 214
                                                                                                               0x0  TMCLK x 213 */
        }Bit;
    }BOOT_CTRL_R;

    UINT8 EMPTY12[16]; /* 0x10 */

    union { /* 0x0540 [Excel Line :0435]  */
        UINT32 Reg;
        struct {
            UINT32 AT_EN                                                                  : 1;      /* [    0] Setting this bit enables Auto tuning engine This bit is enabled by default when core is configured with mode3 retuning support Clear this bit to 0 when core is configured to have Mode3 re-tuning but SW wishes to disable mode3 re-tuning
                                                                                                               This field should be programmed only when CLK_CTRL_RSD_CLK_EN is 0
                                                                                                               Values
                                                                                                               0x1 AT_ENABLE AutoTuning is enabled
                                                                                                               0x0 AT_DISABLE AutoTuning is disabled */
            UINT32 CI_SEL                                                                 : 1;      /* [    1] Selects the interval when the corrected center phase select code can be driven on tuning_cclk_sel output
                                                                                                               Values
                                                                                                               0x0 WHEN_IN_BLK_GAP Driven in block gap interval
                                                                                                               0x1 WHEN_IN_IDLE Driven at the end of the transfer */
            UINT32 SWIN_TH_EN                                                             : 1;      /* [    2] Sampling window Threshold enable
                                                                                                               Selects the tuning mode
                                                                                                               Field should be programmed only when SAMPLE_CLK_SEL is 0
                                                                                                               Values
                                                                                                               0x1 THRESHOLD_MODE Tuning engine selects the first complete sampling window that meets the threshold set by SWIN_TH_VAL field
                                                                                                               0x0 LARGEST_WIN_MODE Tuning engine sweeps all taps and settles at the largest window */
            UINT32 RPT_TUNE_ERR                                                           : 1;      /* [    3] Framing errors are not generated when executing tuning This debug bit allows users to report these errors
                                                                                                               Values
                                                                                                               0x1 DEBUG_ERRORS Debug mode for reporting framing errors
                                                                                                               0x0 ERRORS_DISABLED Default mode where as per SD-HCI no errors are reported */
            UINT32 SW_TUNE_EN                                                             : 1;      /* [    4] This fields enables software-managed tuning flow
                                                                                                               Values
                                                                                                               0x1 SW_TUNING_ENABLE Software-managed tuning enabled AT_STAT_RCENTER_PH_CODE Field is now writable
                                                                                                               0x0 SW_TUNING_DISABLE Software-managed tuning disabled */
            UINT32 RESERVED4                                                              : 3;      /* [  7:5]  */
            UINT32 WIN_EDGE_SEL                                                           : 4;      /* [ 11:8] This field sets the phase for Left and Right edges for drift monitoring Left edge offset  Right edge offset must not be less than total taps of delayLine
                                                                                                               0x0 User selection disabled Tuning calculated edges are used
                                                                                                               0x1 Right edge Phase is center  2 stages Left edge Phase is center - 2 stages
                                                                                                               0x2 Right edge Phase is center  3 stages Left edge Phase is center - 3 stages

                                                                                                               0xF Right edge Phase is center  16 stages Left edge Phase is center - 16 stages */
            UINT32 RESERVED3                                                              : 4;      /* [15:12]  */
            UINT32 TUNE_CLK_STOP_EN                                                       : 1;      /* [   16] Clock stopping control for Tuning and auto-tuning circuit
                                                                                                               When enabled clock gate control output of DWC_mshc clk2card_on is pulled low before changing phase select codes on tuning_cclk_sel and autotuning_cclk_sel This effectively stops the DeviceCard clock cclk_rx and also drift_cclk_rx Changing phase code when clocks are stopped ensures glitch free phase switching Set this bit to 0 if the PHY or delayline can guarantee glitch free switching
                                                                                                               Values
                                                                                                               0x1 ENABLE_CLK_STOPPING Clocks stopped during phase code change
                                                                                                               0x0 DISABLE_CLK_STOPPING Clocks not stopped PHY ensures glitch free phase switching */
            UINT32 PRE_CHANGE_DLY                                                         : 2;      /* [18:17] Maximum Latency specification between cclk_tx and cclk_rx
                                                                                                               Values
                                                                                                               0x0 LATENCY_LT_1 Less than 1-cycle latency
                                                                                                               0x1 LATENCY_LT_2 Less than 2-cycle latency
                                                                                                               0x2 LATENCY_LT_3 Less than 3-cycle latency
                                                                                                               0x3 LATENCY_LT_4 Less than 4-cycle latency */
            UINT32 POST_CHANGE_DLY                                                        : 2;      /* [20:19] Time taken for phase switching and stable clock output
                                                                                                               Specifies the maximum time in terms of cclk cycles that the delay line can take to switch its output phase after a change in tuning_cclk_sel or autotuning_cclk_sel
                                                                                                               Values
                                                                                                               0x0 LATENCY_LT_1 Less than 1-cycle latency
                                                                                                               0x1 LATENCY_LT_2 Less than 2-cycle latency
                                                                                                               0x2 LATENCY_LT_3 Less than 3-cycle latency
                                                                                                               0x3 LATENCY_LT_4 Less than 4-cycle latency */
            UINT32 RESERVED2                                                              : 3;      /* [23:21]  */
            UINT32 SWIN_TH_VAL                                                            : 3;      /* [26:24] Sampling window threshold value setting
                                                                                                               The maximum value that can be set here depends on the length of delayline used for tuning A delayLine with 128 taps can use values from 0x0 to 0x7F
                                                                                                               This field is valid only when SWIN_TH_EN is 1 Should be programmed only when SAMPLE_CLK_SEL is 0
                                                                                                               0x0  Threshold values is 0x1 windows of length 1 tap and above can be selected as sampling window
                                                                                                               0x1  Threshold values is 0x2 windows of length 2 taps and above can be selected as sampling window
                                                                                                               0x2  Threshold values is 0x1 windows of length 3 taps and above can be selected as sampling window

                                                                                                               0x7F  Threshold values is 0x1 windows of length 127 taps and above can be selected as sampling window */
            UINT32 RESERVED1                                                              : 5;      /* [31:27]  */
        }Bit;
    }AT_CTRL_R;
    union { /* 0x0544 [Excel Line :0449]  */
        UINT32 Reg;
        struct {
            UINT32 CENTER_PH_CODE                                                         : 8;      /* [  7:0] Centered Phase code Reading this field returns the current value on tuning_cclk_sel output Setting AT_CTRL_RSW_TUNE_EN enables software to write to this field and its contents are reflected on tuning_cclk_sel */
            UINT32 R_EDGE_PH_CODE                                                         : 8;      /* [ 15:8] Right Edge Phase code Reading this field returns the phase code value used by Auto-tuning engine to sample data on Right edge of sampling window */
            UINT32 L_EDGE_PH_CODE                                                         : 8;      /* [23:16] Left Edge Phase code Reading this field returns the phase code value used by Auto-tuning engine to sample data on Left edge of sampling window */
            UINT32 RESERVED1                                                              : 8;      /* [31:24]  */
        }Bit;
    }AT_STAT_R;

    UINT8 EMPTY13[2596]; /* 0xA24 */

    union { /* 0x0F6C [Excel Line :0453]  */
        UINT32 Reg;
        struct {
            UINT32 NUM_CLK_PIN                                                            : 3;      /* [  2:0] Number of Clock Pins SD Mode
                                                                                                               This field indicates support of clock pins to select one of devices for shared bus system Up to 7 clock pins can be supported
                                                                                                               0x0  Shared bus is not supported
                                                                                                               0x1  1 SDCLK is supported
                                                                                                               0x2 - 2 SDCLK is supported



                                                                                                               0x7  7 SDCLK is supported */
            UINT32 RESERVED6                                                              : 1;      /* [    3]  */
            UINT32 NUM_INT_PIN                                                            : 2;      /* [  5:4] Number of Interrupt Input Pins
                                                                                                               This field indicates support of interrupt input pins for an embedded system */
            UINT32 RESERVED5                                                              : 2;      /* [  7:6]  */
            UINT32 BUS_WIDTH_PRESET                                                       : 7;      /* [ 14:8] Bus Width Preset SD Mode
                                                                                                               Each bit of this field specifies the bus width for each embedded device The shared bus supports mixing of 4-bit and 8-bit bus width devices
                                                                                                               D08  Bus Width Preset for Device 1
                                                                                                               D09  Bus Width Preset for Device 2
                                                                                                               D10  Bus Width Preset for Device 3
                                                                                                               D11  Bus Width Preset for Device 4
                                                                                                               D12  Bus Width Preset for Device 5
                                                                                                               D13  Bus Width Preset for Device 6
                                                                                                               D14  Bus Width Preset for Device 7
                                                                                                               Function of each bit is defined as follows
                                                                                                               0  4-bit bus width mode
                                                                                                               1  8-bit bus width mode */
            UINT32 RESERVED4                                                              : 1;      /* [   15]  */
            UINT32 CLK_PIN_SEL                                                            : 3;      /* [18:16] Clock Pin Select SD Mode
                                                                                                               This bit is selected by one of clock pin outputs
                                                                                                               0x0  Clock pins are disabled
                                                                                                               0x1  CLK1 is selected
                                                                                                               0x2  CLK2 is selected



                                                                                                               0x7  CLK7 is selected */
            UINT32 RESERVED3                                                              : 1;      /* [   19]  */
            UINT32 INT_PIN_SEL                                                            : 3;      /* [22:20] Interrupt Pin Select
                                                                                                               These bits enable the interrupt pin inputs
                                                                                                               000  Interrupts INT_AINT_BINT_C are disabled
                                                                                                               xx1  INT_A is enabled
                                                                                                               x1x  INT_B is enabled
                                                                                                               1xx  INT_C is enabled */
            UINT32 RESERVED2                                                              : 1;      /* [   23]  */
            UINT32 BACK_END_PWR_CTRL                                                      : 7;      /* [30:24] Back-End Power Control SD Mode
                                                                                                               Each bit of this field controls back-end power supply for an embedded device
                                                                                                               0  Back-End Power is off
                                                                                                               1  Back-End Power is supplied
                                                                                                               D24  Back-End Power for Device 1
                                                                                                               D25  Back-End Power for Device 2
                                                                                                               D26  Back-End Power for Device 3
                                                                                                               D27  Back-End Power for Device 4
                                                                                                               D28  Back-End Power for Device 5
                                                                                                               D29  Back-End Power for Device 6
                                                                                                               D30  Back-End Power for Device 7 */
            UINT32 RESERVED1                                                              : 1;      /* [   31]  */
        }Bit;
    }EMBEDDED_CTRL_R;
}DRV_EMMC_REGISTER;
/* PRQA S 828, 0635 -- */

/*
 static volatile DRV_EMMC_REGISTER* const RegA6_EMMC = (DRV_EMMC_REGISTER*)APACHE_EMMC_BASE_ADDR;
 */



#endif /* end of  __DRV_REGISTER_EMMC__ */

