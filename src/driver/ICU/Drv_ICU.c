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
#include "Drv_ICU.h"
#include "seq_monitor.h"
#include "safety_engine.h"
#include "MPU.h"

/*
********************************************************************************
*               VARIABLE DECLARATIONS
********************************************************************************
*/

/* PRQA S 0303,0306,3218 ++ */
volatile DRV_A6_ICU_REGISTER* const RegA6_ICU = (DRV_A6_ICU_REGISTER*)APACHE_A6_ICU_BASE_ADDR;
/* PRQA S 0303,0306,3218 -- */

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/

/*
********************************************************************************
*               FUNCTION DEFINITIONS
********************************************************************************
*/



/**
* @desc
    This function performs the Pad ID function mode setting.
* @param    UINT32  Pad_ID  Pad Index
* @param    UINT32  Func    Pad Function Mode
* @return   void
* @design
    Calculate Pad Offset
    Set Function Mode of Pad
*/
void NC_ICU_SetPinMode(UINT32 Pad_ID, UINT32 Func)
{
    UINT32 ICU_TMUX_BASE = (UINT32)&RegA6_ICU->REG_TMUX_1000.Reg;
    UINT32 ICU_TMUX_CTRL;
    UINT32 Offset;
    UINT32 Pos;
    UINT32 Value;

#if (EVT == 0)
    Offset = (Pad_ID / 4U) * 4U;
    Pos    = (Pad_ID % 4U) * 8U;
#else
    #error "Who are you? EVT Version?"
#endif

    ICU_TMUX_CTRL = ICU_TMUX_BASE + Offset;

    Value = *(UINT32*)ICU_TMUX_CTRL;
    Value = Value & ~(0x7UL << Pos);
    Value |= ((Func & 0x7UL) << Pos);

    *(UINT32*)ICU_TMUX_CTRL = Value;
}



/**
* @desc
    This function sets the pad output signal level for the GPIO group.
* @param    UINT32  Pad_ID  Pad Index
* @param    BOOL    Level   High/Low
* @return   void
* @design
    Check Pad_ID for set the port and GPIO group.

    Set GPIO Direction Out.
    IF  Level == LOW    THEN
        Set GPIO Low Level.
    ELSE
        Set GPIO High Level.
    ENDIF
*/
void NC_ICU_SetPinLevel(UINT32 Pad_ID, BOOL Level)
{
    UINT32 Reg;
    UINT32 Group;
    UINT32 Port;

#if (EVT == 0)
    if(Pad_ID < PAD_PCIE0_WAKE_N)
    {
        Group = Pad_ID/32U;
        Port  = Pad_ID%32U;
    }
    else if (Pad_ID <= PAD_USB_PORT_PWR)
    {
        Group = 3U; /* GPIO_D */
        Port  = (Pad_ID - 2U);
    }
    else /* else if(Pad_ID > PAD_USB_PORT_PWR) */ /* for QAC */
    {
        Group = (Pad_ID - 6U)/32U;
        Port  = (Pad_ID - 6U)%32U;
    }
#else
    #error "Who are you? EVT Version?"
#endif

    /* Set GPIO Direction - OutPut Mode */
    RegA6_ICU->ICU_GPIO[Group].GPIO_OE.Reg |= (1UL<<Port);

    /* Set GPIO Level */
    Reg = RegA6_ICU->ICU_GPIO[Group].GPIO_OUT.Reg;
    if(Level == LOW)
    {
        Reg &= ~(1UL<<Port);
    }
    else
    {
        Reg |= (1UL<<Port);
    }
    RegA6_ICU->ICU_GPIO[Group].GPIO_OUT.Reg = Reg;
}



/**
* @desc
    Get PAD Information matching Boot Device.
* @param    UINT32          BootDevice  Boot device
* @param    tBOOT_PAD_INFO* ptPadInfo   Pad information parameter
* @return   NC_ERROR    NC_SUCCESS or NC_INVALID
* @struct
    typedef struct
    {
        UINT32      mBootDevice;    Boot device.
        UINT32      mCount;         Buffer count of pad id.
        UINT32      mPAD_ID[14];    Pad id buffer.
    } tBOOT_PAD_INFO;
* @design
    Ret = NC_SUCCESS
    IF  Boot device value is not valid. THEN
        NC_NC_INVALID
    ELSE
        IF  A matching boot device was found.   THEN
            Get Boot device value, PAD ID and PAD ID Count.
        ELSE
            Do not get Boot device value, PAD ID and PAD ID Count.
        ENDIF
    ENDIF
    Return Ret
*/
NC_ERROR NC_ICU_GetPadInfo(UINT32 BootDevice, tBOOT_PAD_INFO* ptPadInfo)
{
    NC_ERROR Ret = NC_SUCCESS;

    if(BootDevice >= E_BOOT_MAX)
    {
        Ret = NC_INVALID;
    }
    else
    {
        switch(BootDevice)
        {
            case E_BOOT_SFLASH:
            case E_BOOT_SPI_CLK_INVD:
                ptPadInfo->mBootDevice = E_BOOT_SFLASH;
                ptPadInfo->mCount = 6U;
                ptPadInfo->mPAD_ID[0] = PAD_QSPI_SCK;
                ptPadInfo->mPAD_ID[1] = PAD_QSPI_CSN;
                ptPadInfo->mPAD_ID[2] = PAD_QSPI_DQ0;
                ptPadInfo->mPAD_ID[3] = PAD_QSPI_DQ1;
                ptPadInfo->mPAD_ID[4] = PAD_QSPI_DQ2;
                ptPadInfo->mPAD_ID[5] = PAD_QSPI_DQ3;
                break;
            case E_BOOT_EMMC:
                ptPadInfo->mBootDevice = E_BOOT_EMMC;
                ptPadInfo->mCount = 12U;
                ptPadInfo->mPAD_ID[0] = PAD_EMMC_VOL_SEL;
                ptPadInfo->mPAD_ID[1] = PAD_EMMC_CLK;
                ptPadInfo->mPAD_ID[2] = PAD_EMMC_RSTN;
                ptPadInfo->mPAD_ID[3] = PAD_EMMC_CMD;
                ptPadInfo->mPAD_ID[4] = PAD_EMMC_DQ0;
                ptPadInfo->mPAD_ID[5] = PAD_EMMC_DQ1;
                ptPadInfo->mPAD_ID[6] = PAD_EMMC_DQ2;
                ptPadInfo->mPAD_ID[7] = PAD_EMMC_DQ3;
                ptPadInfo->mPAD_ID[8] = PAD_EMMC_DQ4;
                ptPadInfo->mPAD_ID[9] = PAD_EMMC_DQ5;
                ptPadInfo->mPAD_ID[10] = PAD_EMMC_DQ6;
                ptPadInfo->mPAD_ID[11] = PAD_EMMC_DQ7;
                break;
            case E_BOOT_SDCARD:
                ptPadInfo->mBootDevice = E_BOOT_SDCARD;
                ptPadInfo->mCount = 9U;
                ptPadInfo->mPAD_ID[0] = PAD_SD_VOL_SEL;
                ptPadInfo->mPAD_ID[1] = PAD_SD_CLK;
                ptPadInfo->mPAD_ID[2] = PAD_SD_CMD;
                ptPadInfo->mPAD_ID[3] = PAD_SD_DQ0;
                ptPadInfo->mPAD_ID[4] = PAD_SD_DQ1;
                ptPadInfo->mPAD_ID[5] = PAD_SD_DQ2;
                ptPadInfo->mPAD_ID[6] = PAD_SD_DQ3;
                ptPadInfo->mPAD_ID[7] = PAD_SD_DETECT_N;
                ptPadInfo->mPAD_ID[8] = PAD_SD_WRITE_PROT;
                break;
            case E_BOOT_USB:
                ptPadInfo->mBootDevice = E_BOOT_USB;
                ptPadInfo->mCount = 2U;
                ptPadInfo->mPAD_ID[0] = PAD_USB_OVRCUR_N;
                ptPadInfo->mPAD_ID[1] = PAD_USB_PORT_PWR;
                break;
            default: /* E_BOOT_UART */
                break;
        }
    }

    return Ret;
}



/**
* @desc
    Set driver strength.
* @param    tBOOT_PAD_INFO*     ptPadInfo   Pad Information parameter
* @param    UINT32              DS0         Drive Strength  0
* @param    UINT32              DS1         Drive Strength  1
* @param    UINT32              DS2         Drive Strength  2
* @return   void
* @struct
    typedef struct
    {
        UINT32      mBootDevice;    Boot device.
        UINT32      mCount;         Buffer count of pad id.
        UINT32      mPAD_ID[14];    Pad id buffer.
    } tBOOT_PAD_INFO;
* @design
    DO WHILE    i < Pad count
        Set driver strength 0,1 and 2.
        i++
    LOOP
*/
static void NC_ICU_SetDriveStrengthPadControl(const tBOOT_PAD_INFO* ptPadInfo, UINT32 DS0, UINT32 DS1, UINT32 DS2)
{
    UINT32 i;

    for(i=0; i<ptPadInfo->mCount; i++)
    {
        RegA6_ICU->ICU_PAD_CTRL[ptPadInfo->mPAD_ID[i]].PAD_CTRL.Bit.DS0 = DS0;
        RegA6_ICU->ICU_PAD_CTRL[ptPadInfo->mPAD_ID[i]].PAD_CTRL.Bit.DS1 = DS1;
        RegA6_ICU->ICU_PAD_CTRL[ptPadInfo->mPAD_ID[i]].PAD_CTRL.Bit.DS2 = DS2;
    }
}



/**
* @desc
    Set Drive Strength.
* @param    tBOOT_PAD_INFO*  ptPadInfo       Pad information parameter
* @param    UINT32           DriveStrength   Drive strength value.
* @return   void
* @struct
    typedef struct
    {
        UINT32      mBootDevice;    Boot device.
        UINT32      mCount;         Buffer count of pad id.
        UINT32      mPAD_ID[14];    Pad id buffer.
    } tBOOT_PAD_INFO;
* @design
    IF  There is a matching Drive Strength. THEN
        Set the Drive Strength value at the PAD ID position of the PAD Controller.
    ELSE
        Do not set the Drive Strength value.
    ENDIF
*/
/* for QAC Rule-8.13 */
void NC_ICU_SetDriveStrength(const tBOOT_PAD_INFO* ptPadInfo, UINT32 DriveStrength)
{
    switch(DriveStrength)
    {
        case E_QSPI_DS_X1: 
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 0, 0, 0);
            break;
        case E_QSPI_DS_X1_5:
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 0, 0, 1);
            break;
        case E_QSPI_DS_X2:
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 0, 1, 0);
            break;
        case E_QSPI_DS_X2_5:
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 0, 1, 1);
            break;
        case E_QSPI_DS_X3:
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 1, 0, 0);
            break;
        case E_QSPI_DS_X4:
        case E_QSPI_DS_SKIP:
        default:
            NC_ICU_SetDriveStrengthPadControl(ptPadInfo, 1, 0, 1);
            break;
    }
}



/**
* @desc
    This function sets the Pin Mode.
* @param    tBOOT_INFO* ptBootInfo  Boot Information Parameter
* @return   void
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
    IF  There is a matching Device. THEN
        Set Pin mode.
    ENDIF
*/
static void NC_ICU_SetPinMux(const tBOOT_INFO *ptBootInfo)
{
        /* Toggle GPIO : OE En */
    NC_ICU_SetPinMode(PAD_I2S_SCLK, FM_I2S_SCLK_i_gpio_b_out_12);

    /* UART PinMux */
#ifdef R5_UART_ENABLE_
    NC_ICU_SetPinMode(PAD_UART1_RX, FM_UART1_RX_o_uart1_rx_in);
    NC_ICU_SetPinMode(PAD_UART1_TX, FM_UART1_TX_i_uart1_tx_out);
#else /* Original */
    NC_ICU_SetPinMode(PAD_UART0_RX, FM_UART0_RX_o_uart0_rx_in);
    NC_ICU_SetPinMode(PAD_UART0_TX, FM_UART0_TX_i_uart0_tx_out);
#endif

    if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SFLASH)
    {
        /* QSPI PinMux */
        NC_ICU_SetPinMode(PAD_QSPI_SCK,      FM_QSPI_SCK_i_qspi_sck_out);
        NC_ICU_SetPinMode(PAD_QSPI_CSN,      FM_QSPI_CSN_i_qspi_csn_out);
        NC_ICU_SetPinMode(PAD_QSPI_DQ0,      FM_QSPI_DQ0_i_qspi_dq0_out);
        NC_ICU_SetPinMode(PAD_QSPI_DQ1,      FM_QSPI_DQ1_i_qspi_dq1_out);
        NC_ICU_SetPinMode(PAD_QSPI_DQ2,      FM_QSPI_DQ2_i_qspi_dq2_out);
        NC_ICU_SetPinMode(PAD_QSPI_DQ3,      FM_QSPI_DQ3_i_qspi_dq3_out);
    }
    else if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_EMMC)
    {
        /* EMMC PinMux */
        NC_ICU_SetPinMode(PAD_EMMC_VOL_SEL,  FM_EMMC_VOL_SEL_i_emmc_vol_sel);
        NC_ICU_SetPinMode(PAD_EMMC_CLK,      FM_EMMC_CLK_i_emmc_clk_out);
        NC_ICU_SetPinMode(PAD_EMMC_RSTN,     FM_EMMC_RSTN_i_emmc_rstn_out);
        NC_ICU_SetPinMode(PAD_EMMC_CMD,      FM_EMMC_CMD_i_emmc_cmd_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ0,      FM_EMMC_DQ0_i_emmc_dq0_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ1,      FM_EMMC_DQ1_i_emmc_dq1_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ2,      FM_EMMC_DQ2_i_emmc_dq2_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ3,      FM_EMMC_DQ3_i_emmc_dq3_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ4,      FM_EMMC_DQ4_i_emmc_dq4_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ5,      FM_EMMC_DQ5_i_emmc_dq5_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ6,      FM_EMMC_DQ6_i_emmc_dq6_out);
        NC_ICU_SetPinMode(PAD_EMMC_DQ7,      FM_EMMC_DQ7_i_emmc_dq7_out);
    }
    else if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_USB)
    {
        /* USB PinMux */
        NC_ICU_SetPinMode(PAD_USB_OVRCUR_N,  FM_USB_OVRCUR_N_o_usb_ovrcur_n_in);
        NC_ICU_SetPinMode(PAD_USB_PORT_PWR,  FM_USB_PORT_PWR_i_usb_port_pwr_out);
    }
    else if(ptBootInfo->tStrap.Bit.mBootMemory == E_BOOT_SDCARD)
    {
        /* SD PinMux */
        NC_ICU_SetPinMode(PAD_SD_VOL_SEL,    FM_SD_VOL_SEL_i_sd_vol_sel);
        NC_ICU_SetPinMode(PAD_SD_CLK,        FM_SD_CLK_i_sd_clk_out);
        NC_ICU_SetPinMode(PAD_SD_CMD,        FM_SD_CMD_i_sd_cmd_out);
        NC_ICU_SetPinMode(PAD_SD_DQ0,        FM_SD_DQ0_i_sd_dq0_out);
        NC_ICU_SetPinMode(PAD_SD_DQ1,        FM_SD_DQ1_i_sd_dq1_out);
        NC_ICU_SetPinMode(PAD_SD_DQ2,        FM_SD_DQ2_i_sd_dq2_out);
        NC_ICU_SetPinMode(PAD_SD_DQ3,        FM_SD_DQ3_i_sd_dq3_out);
        NC_ICU_SetPinMode(PAD_SD_DETECT_N,   FM_SD_DETECT_N_o_sd_detect_n_in);
        NC_ICU_SetPinMode(PAD_SD_WRITE_PROT, FM_SD_WRITE_PROT_o_sd_write_prot_in);
    }
    else
    {
        /* ... */
    }
}



/**
* @desc
    This function sets the Pin Mode.
* @param    tBOOT_INFO*     ptBootInfo      Boot Information Parameter
* @param    tBOOT_STATUS*   ptBootStatus    Boot Status
* @return   void
* @struct
    typedef struct
    {
        tBOOT_HDR   tHeader;            Boot Image header info
        tBOOT_IMG   tImage;             Boot Image info
        tBOOT_STRAP tStrap;             Boot strap info
        tBOOT_CLK   tClock;             Boot clock info
        tBOOT_CMRT  tCMRT;              Boot CMRT info
    } tBOOT_INFO;
* @struct
    typedef struct
    {
        UINT32  mBackupRes;             The index of the FW binary in use.
        UINT32  mOtpRes;                OTP read result success or fail
        UINT32  mSecureRunRes;          Secure Run result success or fail
        UINT32  mSafetyModeRes;         Safety Mode init success or fail
        UINT32  mHeaderReadRes;         FW Header load success or fail
        UINT32  mCtrlMode;              SPI Ctrl Mode
        UINT32  mSF_CheckSCLKRes;       CheckSCLK Fail
        UINT32  mSF_FailRes;            SF Fail
        UINT32  mEMMC_FailRes;          eMMC Boot Fail
        UINT32  mSD_FailRes;            SD Boot Fail
        UINT32  mUART_FailRes;          UART Boot Fail
        UINT32  mUSB_FailRes;           USB Boot Fail
        UINT32  mBootDone_Res;          Booting Done Success/Fail
        UINT32  mSF_ImgLoadRetryType;   Set boot retry mode based on bootstrap settings
        UINT32  mBootImgType;           Boot Img Type value.
        tBOOT_INFO*  ptHandleBoot;
    } tBOOT_STATUS;
* @design
    Set Boot step.
    Set Pin mode.
    IF  Pin mod is Success   THEN
        Set Drive Strength.
    ENDIF
*/
/* for QAC Rule-8.13 */
void NC_ICU_Initialize(const tBOOT_INFO *ptBootInfo,  tBOOT_STATUS *ptBootStatus)
{
    tBOOT_PAD_INFO tPad_DsInfo;
    UINT32 i;

    /* ICU IN */
    NC_SM_SetBOOT_Step(DBG_STP_PIN_MUX_IN, ptBootStatus);

    NC_ICU_SetPinMux(ptBootInfo);

    tPad_DsInfo.mBootDevice = 0U;
    tPad_DsInfo.mCount = 0U;

    for(i=0U; i<14U; i++)
    {
        tPad_DsInfo.mPAD_ID[i] = 0U;
    }
    
    if(NC_ICU_GetPadInfo(ptBootInfo->tStrap.Bit.mBootMemory, &tPad_DsInfo) == NC_SUCCESS)
    {
        NC_ICU_SetDriveStrength(&tPad_DsInfo, ptBootInfo->tImage.mDriveStrength);
    }

    /* ICU OUT */
    NC_SM_SetBOOT_Step(DBG_STP_PIN_MUX_OUT, ptBootStatus);
}

/* End Of File */
