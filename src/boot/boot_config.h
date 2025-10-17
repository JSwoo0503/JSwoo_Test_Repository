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

#ifndef BOOT_CONFIG_H_
#define BOOT_CONFIG_H_

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/


/*****************************************************************************************
 *
 *   |-----------------------------------------------------------------------------|
 *   |        LEN        |     Checksum     |       Conf_1      |      Conf_2      |   <-- 16 Byte ( LEN(Start-End) : From A to E ,  Checksum(Start-End) : From A to E )
 *   |-----------------------------------------------------------------------------|
 *   |    KeySplit_Num   |     reserved     |      reserved     |    Diver_Path    |   <-- 16 Byte
 *   |-----------------------------------------------------------------------------|
 *   | OS+Usr Img_Offset | OS+Usr_Real_Size |      reserved     |     reserved     |   <-- 16 Byte ( OS+Usr Img Offset : From A to B ,  OS+Usr Real Size : From B to E )
 *   |-----------------------------------------------------------------------------|
 *   |      reserved     |     reserved     |      reserved     |     Signature    |   <-- 16 Byte
 *   A-----------------------------------------------------------------------------|
 *   |                                                                             |
 *   |                                    BL2                                      |
 *   |                           (Plain OR cipher Img)          -------------------|
 *   |                                                          |     Pad(0x0)     |
 *   B-----------------------------------------------------------------------------|  ---|
 *   |                                                                             |    /|
 *   |                                                                             |    /|
 *   |                                   OS Img                                    |    /|
 *   |                            (OS Img of RT-640)                               |    /| <-- OS Img ( Start address == 512 Byte Align )
 *   |                                                                             |    /|
 *   |                                                                             |    /|
 *   |                         C-----------------------D-------------------------- |    /|
 *   |                         |  Secboot Size(4byte)  |                           |  ---|
 *   |--------------------------------------------------                           |    /|
 *   |                                                                             |    /|
 *   |                                                                             |    /|
 *   |                                                                             |    /| <-- Secure Boot Img ( Start address ==  "Not" 512 Byte Align )
 *   |                               Secure Boot Img                               |    /|                     ( Secure Boot Size : From D to E )
 *   |                        (User Container App of RT-640)                       |    /|
 *   |                                                                             |    /|
 *   |                                              -------------------------------|    /|
 *   |                                              |                              |    /|
 *   |----------------------------------------------E                              |  ---|
 *
 * **************************************************************************************/



/*
 * typedef enum
 * {
 *     E_IMG_NORMAL = 0,
 *     E_IMG_BACKUP,
 *
 *     E_IMG_TYPE_MAX
 * } eBOOT_IMG_TYPE;
 */
#define E_IMG_NORMAL                        (0U)
#define E_IMG_BACKUP                        (1U)
#define E_IMG_TYPE_MAX                      (2U)

/* Boot Memory type */
#define E_BOOT_SFLASH                       (0U)
#define E_BOOT_EMMC                         (1U)
#define E_BOOT_SDCARD                       (2U)
#define E_BOOT_SPI_CLK_INVD                 (3U)
#define E_BOOT_UART                         (4U)
#define E_BOOT_USB                          (5U)
#define E_BOOT_MAX                          (6U)

/* SPI Ctrl mode */
#define E_SPI_CTRL_DEFAULT                  (0U)
#define E_SPI_CTRL_SPI                      (1U)
#define E_SPI_CTRL_QSPI                     (2U)
#define E_SPI_CTRL_DMA_SPI                  (3U)
#define E_SPI_CTRL_DMA_QSPI                 (4U)

/* Secure Boot Key Storage type */
#define E_SBOOT_KEY_STORAGE_DEFAULT         (0U)
#define E_SBOOT_KEY_STORAGE_OTP             (1U)
#define E_SBOOT_KEY_STORAGE_ROM             (2U)    /* default */

/* CMRT Key Use(RT640 Internal OTP) */
#define E_SBOOT_KEY_CMRT_USE_DEFAULT        (0U)
#define E_SBOOT_KEY_CMRT_OTP_USE            (1U)
#define E_SBOOT_KEY_CMRT_OTP_NOT_USE        (2U)

/* Boot mode */
#define E_SBOOT_DEFAULT_MODE                (0U)
#define E_SBOOT_NORMAL_MODE                 (1U)    /* default */
#define E_SBOOT_SECURE_MODE                 (2U)


/* IMG SafetyEngine Mode */
#define E_SAFETY_MODE_SKIP                  (0U)
#define E_SAFETY_MODE_DISABLE               (1U)
#define E_SAFETY_MODE_ENABLE                (2U)    /* default */
#define E_SAFETY_MODE_MAX                   (3U)


/* IMG QSPI Drive Strength */
#define E_QSPI_DS_SKIP                      (0U)
#define E_QSPI_DS_X1                        (1U)
#define E_QSPI_DS_X1_5                      (2U)
#define E_QSPI_DS_X2                        (3U)
#define E_QSPI_DS_X2_5                      (4U)
#define E_QSPI_DS_X3                        (5U)
#define E_QSPI_DS_X4                        (6U)
#define E_QSPI_DS_MAX                       (7U)

#define E_FAULT_BEHAVIOUR_SKIP              (0U)    /* default */
#define E_FAULT_BEHAVIOUR_CPU_HOLD          (1U)
#define E_FAULT_BEHAVIOUR_CPU_RESET         (2U)


#define IMG_SIZEUP_64KB                     (65536U)

/* Boot Done Res */
#define NC_BOOT_DONE_FAIL                   (0U)
#define NC_BOOT_DONE_SUCCESS                (1U)

/* Secure Res */
#define NC_BOOT_SECURE_INIT_FAIL            (0x10000U)
#define NC_BOOT_SECURE_RUN_FAIL             (0x20000U)
#define NC_BOOT_SECURE_TOV_FAIL_1           (0x1U)
#define NC_BOOT_SECURE_TOV_FAIL_2           (0x2U)
#define NC_BOOT_SECURE_TOV_FAIL_3           (0x4U)
#define NC_BOOT_SECURE_TOV_FAIL_4           (0x8U)
#define NC_BOOT_SECURE_TOV_FAIL_5           (0x10U)
#define NC_BOOT_SECURE_TOV_FAIL_6           (0x20U)
#define NC_BOOT_SECURE_TOV_FAIL_7           (0x40U)
#define NC_BOOT_SECURE_TOV_FAIL_8           (0x80U)


/* sFlash Res */
#define NC_SF_BACKUP_SPI_RETRY_MASK         (0x00000001U)
#define NC_SF_NORMAL_SPI_RETRY_MASK         (0x00000002U)
#define NC_SF_BACKUP_QSPI_RETRY_MASK        (0x00000004U)
#define NC_SF_NORMAL_QSPI_RETRY_MASK        (0x00000008U)
#define NC_SF_BACKUP_DMA_SPI_RETRY_MASK     (0x00000010U)
#define NC_SF_NORMAL_DMA_SPI_RETRY_MASK     (0x00000020U)
#define NC_SF_BACKUP_DMA_QSPI_RETRY_MASK    (0x00000040U)
#define NC_SF_NORMAL_DMA_QSPI_RETRY_MASK    (0x00000080U)

#define NC_BOOT_BYPASS               (0U)
#define NC_BOOT_PLL_HALF_SSCG_OFF    (1U)
#define NC_BOOT_PLL_FULL_SSCG_ON     (2U)
#define NC_BOOT_PLL_FULL_SSCG_OFF    (3U)

#define NC_BOOT_SFLASH_CLOCK_DIV_LOW   (0U)
#define NC_BOOT_SFLASH_CLOCK_DIV_MID   (1U)
#define NC_BOOT_SFLASH_CLOCK_DIV_HIGH  (2U)

/*
********************************************************************************
*               ENUMERATION
********************************************************************************
*/


/*
********************************************************************************
*               TYPEDEFS
********************************************************************************
*/

typedef struct
{
    UINT32      mSYS_PLL;
    UINT32      mCPU_PLL;
    UINT32      mNPU_PLL;
    UINT32      mCOM_PLL;

    UINT32      mAPB;
    UINT32      mSPI;
    UINT32      mQSPI;
    UINT32      mUART;
    UINT32      mSD;
    UINT32      mEMMC;
    UINT32      mUSB;
    UINT32      mCMRT;

    UINT32      mUSB_SUSPEND;
    UINT32      mUSB_REF_CLK;
    
    UINT32      mSPIDiv;
    UINT32      mQSPIDiv;
} tBOOT_CLK;



typedef struct
{
    UINT32*     pSCB_CONTROL;                               /* CMRT Reset Control */
    UINT32*     pR_HLOS2ESW_D0;                             /* CMRT Control */
} tBOOT_CMRT;



typedef union
{
    UINT32  Reg;                                            /* Boot Strap */
    struct {
            UINT32 mPLLConfig                           :2; /* [  0:1] PLL Config
                                                                    0x0 BL_OSC_CLOCK
                                                                    0x1 BL_HALF_CLOCK
                                                                    0x2 Reserved
                                                                    0x3 BL_MAX_CLOCK*/
            UINT32 mBootMemory                          :3; /* [  2:4] Boot memory
                                                                    0x0 E_BOOT_SFLASH
                                                                    0x1 E_BOOT_EMMC
                                                                    0x2 E_BOOT_SDCARD
                                                                    0x3 E_BOOT_SFLASH / CLK_INV
                                                                    0x4 E_BOOT_UART
                                                                    0x5 E_BOOT_USB  */
            UINT32 mJTAG                                :2; /* [  5:6] R5/A65 Jtag
                                                                    0x0 RT640
                                                                    0x1 R5
                                                                    0x2 CoreSight
                                                                    0x3 RT+CS */
            UINT32 mIncMainBusDiv                       :1; /* [    7] MAIN_Bus Divider value increase
                                                                    0x0 Not increase
                                                                    0x1 Increase the divider on the MAIN_BUS by one */
            UINT32 RESERVED                             :24;/* [ 8:31] RESERVED */
    }Bit;
} tBOOT_STRAP;



typedef struct
{
    UINT32      mImg_Type;                                  /*  0x0 E_IMG_NORMAL
                                                                0x1 E_IMG_BACKUP */
    UINT32      mCtrlMode;                                  /*  0x0 Skip
                                                                0x1 SPI Mode
                                                                0x2 QSPI Mode
                                                                0x3 DMA-SPI Mode
                                                                0x4 DMA-QSPI Mode */
    UINT32      mCLK_INV;                                   /*  0x0 Skip
                                                                0x1 SPI/QSPI CLK INVERSION */
    UINT32      mTempBuff;                                  /*  Used QSPI/DMA BitRate Test Area (Only Temp) */
    UINT32      mFlashType;                                 /*  0x0:Skip, 0x1:Type1, 0x2:Type2, 0x3:Type3, 0x4:Type4, 0x5:Type5 */
    UINT32      mDriveStrength;                             /*  0x0:X1, 0x1:X1.5, 0x2:X2, 0x3:X2.5, 0x4:X3, 0x5:X4 */
    UINT32      mQspiClockDiv;                              /*  0x0:16 Div(Mid), 0x1:20 Div(Low), 0x2:8 Div(High) */
    UINT32      mQspiDummyCycle;                            /*  0x0:6Cycle, 0x1:2Cycle, 0x2:4Cycle ... 0x7:14Cycle */
    UINT32      mSpiRxDelay;                                /*  Rx Sample Delay
                                                                0x0 default ... 0xFF */
    UINT32      mSpiClockPolarityPhase;                     /*  SPI/QSPi Clock Polarity & Phase Config Setting
                                                                0x0 Polarity(0), Phase(0) (default)
                                                                0x1 Polarity(0), Phase(1)
                                                                0x2 Polarity(1), Phase(0)
                                                                0x3 Polarity(1), Phase(1) */
    UINT32      mUartBaudrate;                              /*  UART Baudrate Table
                                                                0x0 115200 (default:MID_1)
                                                                0x1 230400 (MAX)
                                                                0x2 57600  (MID_2)
                                                                0x3 19200  (MIN) */
    UINT32      mUsbRefClock;                               /*  USB Reference Clock Table
                                                                0x0 USB_REF_CLK_100_MHZ = 0, default(HW Reset Value)
                                                                0x1 USB_REF_CLK_19_2_MHZ,
                                                                0x2 USB_REF_CLK_20_MHZ,
                                                                0x3 USB_REF_CLK_24_MHZ,
                                                                0x4 USB_REF_CLK_25_MHZ,
                                                                0x5 USB_REF_CLK_26_MHZ,
                                                                0x6 USB_REF_CLK_38_4_MHZ,
                                                                0x7 USB_REF_CLK_40_MHZ,
                                                                0x8 USB_REF_CLK_48_MHZ,
                                                                0x9 USB_REF_CLK_50_MHZ,
                                                                0xA(10) USB_REF_CLK_52_MHZ,
                                                                0xB(11) USB_REF_CLK_200_MHZ, */
    UINT32      mSecuMode;                                  /*  0x0 Skip
                                                                0x1 Non-Secure Boot
                                                                0x2 Secure Boot */
    UINT32      mSafetyMode;                                /*  Safety Mode(Global)
                                                                0x0 Skip
                                                                0x1 DISABLE
                                                                0x2 ENABLE */
    UINT32      mFaultCpuReset;                             /*  HW & SW FT : Default(ON)
                                                                0x0 Skip
                                                                0x1 DISABLE  : RST holding & Loop
                                                                0x2 ENABLE   : Go to HW RST (safe_state : OE) */
    UINT32      mKeyStorage;                                /*  0x0 Skip
                                                                0x1 OTP
                                                                0x2 ROM */
    UINT32      mUseKeyCmrt;                                /*  0x0 Skip
                                                                0x1 Use Key in CMRT Internal OTP
                                                                0x2 Not use key in CMRT Internal OTP */
    UINT32      mDestAddr;                                  /*  Image Loading Dest. Address */
    UINT32      mFlashAddr[E_IMG_TYPE_MAX];                 /*  0x0 Original
                                                                0x1 Backup */
} tBOOT_IMG;



typedef union
{
    UINT32  Reg;                                            /* Image Configure1 */
    struct { /* skip" mean is writen to OPT */
            UINT32 mSPI_CTRL                            :4; /* [  0:3] SPI Mode
                                                                    0x0 Skip
                                                                    0x1 SPI Mode
                                                                    0x2 QSPI Mode
                                                                    0x3 DMA-SPI Mode
                                                                    0x4 DMA-QSPI Mode */
            UINT32 mSECURE_MODE                         :4; /* [  4:7] Secure Booting Mode
                                                                    0x0 Skip
                                                                    0x1 Normal Booting
                                                                    0x2 Secure Booting
                                                                    0x3 Skip */
            UINT32 mKEY_STORAGE                         :2; /* [  8:9] Secure Key Storage
                                                                    0x0 Skip
                                                                    0x1 OTP
                                                                    0x2 ROM */
            UINT32 mUSE_KEY_CMRT                        :2; /* [ 10:11] Use RT640 Internal OTP Key
                                                                    0x0 Skip
                                                                    0x1 Use CMRT Internal OTP
                                                                    0x2 Not use CMRT Internal OTP */
            UINT32 mSAFETY_MODE                         :4; /* [ 12:15] Safety Mode(Global)
                                                                    0x0 Skip
                                                                    0x1 DISABLE
                                                                    0x2 ENABLE */
            UINT32 mSFLASH_TYPE                         :3; /* [ 16:18] sFlash Type
                                                                    0x0 Skip
                                                                    0x1 Type1
                                                                    0x2 Type2
                                                                    0x3 Type3
                                                                    0x4 Type4
                                                                    0x5 Type5 */
            UINT32 mQSPI_DS                             :3; /* [ 19:21]
                                                                    0x0 Skip : Default (X4)
                                                                    0x0 X1
                                                                    0x1 X1.5
                                                                    0x2 X2
                                                                    0x3 X2.5
                                                                    0x4 X3
                                                                    0x5 X4 */
            UINT32 mFAULT_RESET                         :2; /* [ 22:23] HW & SW FT : Default(ON)
                                                                    0x0 Skip
                                                                    0x1 DISABLE  : RST holding & Loop
                                                                    0x2 ENABLE   : Go to HW RST (safe_state : OE) */
            UINT32 mQSPI_CLK_DIV                        :2; /* [ 24:25] QSPI/SPI Clock Divider
                                                                    0x0 Mid  Speed(DIV=16) : (default)
                                                                    0x1 Low  Speed(DIV=20)
                                                                    0x2 High Speed(DIV=8) */
            UINT32 mQSPI_DCYCLE                         :3; /* [ 26:28] QSPI Dummy Cycle
                                                                    0x0     (6 Cycle) : Default
                                                                    0x1 x 2 (2 Cycle)
                                                                    0x2 x 2 (4 Cycle)
                                                                    ............
                                                                    0x7 x 2 (14 Cycle) */
            UINT32 mFW_SIZEUP                           :3; /* [ 29:31] Firmware size up(default :64Kbyte)
                                                                    + 0x0 x 64KB
                                                                    + 0x1 x 64KB
                                                                    ............
                                                                    + 0x7 x 64KB */
    } Bit;
} tBOOT_CONF1;



typedef union
{
    UINT32  Reg;                                            /* Image Configure2 */
    struct {
            /* B/D Dependency */ /* (X)->(OTP) */
            UINT32  mSPI_RX_DELAY                       :8; /* [  0:7] SPI RX Sample Delay
                                                                    0x0 default
                                                                    ...
                                                                    maximum <= SSI_RX_DLY_SR_DEPTH(ex:0xFF) */
            UINT32  mSPI_CLK_POL_PH                     :2; /* [  8:9] SPI/QSPi Clock Polarity & Phase Config Setting
                                                                    0x0 Polarity(0), Phase(0) (default)
                                                                    0x1 Polarity(0), Phase(1)
                                                                    0x2 Polarity(1), Phase(0)
                                                                    0x3 Polarity(1), Phase(1) */
            UINT32  mUART_BAUDRATE                      :2; /* [ 10:11] UART Baudrate table for Download
                                                                    0x0 115200 (default:MID_1)
                                                                    0x1 230400 (MAX)
                                                                    0x2 57600  (MID_2)
                                                                    0x3 19200  (MIN) */
            UINT32  mUSB_REF_CLK                        :4; /* [ 12:15] USB Ref Clock Table
                                                                    0x0 USB_REF_CLK_100_MHZ = 0, default(HW Reset Value)
                                                                    0x1 USB_REF_CLK_19_2_MHZ,
                                                                    0x2 USB_REF_CLK_20_MHZ,
                                                                    0x3 USB_REF_CLK_24_MHZ,
                                                                    0x4 USB_REF_CLK_25_MHZ,
                                                                    0x5 USB_REF_CLK_26_MHZ,
                                                                    0x6 USB_REF_CLK_38_4_MHZ,
                                                                    0x7 USB_REF_CLK_40_MHZ,
                                                                    0x8 USB_REF_CLK_48_MHZ,
                                                                    0x9 USB_REF_CLK_50_MHZ,
                                                                    0xA(10) USB_REF_CLK_52_MHZ,
                                                                    0xB(11) USB_REF_CLK_200_MHZ, */
            UINT32  RESERVED1                           :8; /* [ 16:23] RESERVED1
                                                                    0x0 Skip */
            UINT32  RESERVED2                           :8; /* [ 24:31] RESERVED2
                                                                    0x0 Skip */
    } Bit;
} tBOOT_CONF2;



typedef struct
{
    union {
        UINT32  Reg;
        struct {
                UINT32      KEYSPLIT_NUM                :4; /* [  0:3] case CMRT Internal OTP : keysplit number
                                                                   0x0 KEYSPLIT 1
                                                                   0x1 KEYSPLIT 2
                                                                   0x2 KEYSPLIT 3
                                                                   0x3 KEYSPLIT 4
                                                                   0x4 KEYSPLIT 5
                                                                   0x5 KEYSPLIT 6
                                                                   0x6 KEYSPLIT 7 */
                UINT32      RESERVED1                   :4; /* [  4:7] RESERVED1
                                                                   0x0 Skip */
                UINT32      RESERVED2                   :8; /* [ 8:15] RESERVED2
                                                                   0x0 Skip */
                UINT32      RESERVED3                   :8; /* [ 16:23] RESERVED3
                                                                   0x0 Skip */
                UINT32      RESERVED4                   :8; /* [ 24:31 ] RESERVED4
                                                                   0x0 Skip */
        }Bit;
    }mKEYSPLIT;

    UINT32      RESERVED5;
    UINT32      RESERVED6;
    UINT32      mDIVERSIFY_PATH;                            /* case CMRT Internal OTP : diversify_path - just 1 character, is it enough size ? (max 16 byte, current 4 byte) */
} tBOOT_KEY;



typedef struct
{
    UINT32      mOsOffset;                                  /* Image Offset */
    UINT32      mOsSize;                                    /* Image Size */
    UINT32      mSecureBootOffset;                          /* Image Offset */
    UINT32      mSecureBootSize;                            /* Image Size */ /* 필드 설정이 실제 사이즈가 아닌 TimeOver에 대한 [31:4]Count [3:0]ENABLE 임 */
} tBOOT_SEC;



typedef struct
{
    UINT32      mLength;                                    /* Image length */
    UINT32      mCheckSum;                                  /* Image Checksum */
    tBOOT_CONF1 mConfig_1;                                  /* Image Boot Config_1 */
    tBOOT_CONF2 mConfig_2;                                  /* Image Boot Config_2 */
    tBOOT_KEY   tBootKey;
    tBOOT_SEC   tBootSec;
    UINT32      mRESERVED1;
    UINT32      mRESERVED2;
    UINT32      mRESERVED3;
    UINT32      mSignature;                                 /* Image Signature */
} tBOOT_HDR;


typedef struct
{
    tBOOT_HDR   tHeader;
    tBOOT_IMG   tImage;
    tBOOT_STRAP tStrap;
    tBOOT_CLK   tClock;
    tBOOT_CMRT  tCMRT;
} tBOOT_INFO;



typedef struct
{
    UINT32       mBackupRes;              /* The index of the FW binary in use.    */
    UINT32       mOtpRes;                 /* OTP read result success or fail       */
    UINT32       mSecureRunRes;           /* Secure Run result success or fail     */
    UINT32       mSafetyModeRes;          /* Safety Mode init success or fail      */
    UINT32       mHeaderReadRes;          /* FW Header load success or fail        */
    UINT32       mCtrlMode;               /* SPI Ctrl Mode                         */
    UINT32       mSF_CheckSCLKRes;        /* CheckSCLK Fail                        */
    UINT32       mSF_FailRes;             /* SF Fail                               */
    UINT32       mEMMC_FailRes;           /* eMMC Boot Fail                        */
    UINT32       mSD_FailRes;             /* SD Boot Fail                          */
    UINT32       mUART_FailRes;           /* UART Boot Fail                        */
    UINT32       mUSB_FailRes;            /* USB Boot Fail                         */
    UINT32       mBootDone_Res;           /* Booting Done Success/Fail             */
    UINT32       mSF_ImgLoadRetryType;    /* Set boot retry mode based on bootstrap settings */
                                        /* [7] Normal DMA-QSPI [6] Backup DMA-QSPI [5] Normal DMA-SPI [4] Backup DMA-SPI [3] Normal QSPI [2] Backup QSPI [1] Normal SPI [0] Backup SPI */
    UINT32       mBootImgType;
    tBOOT_INFO*  ptHandleBoot;
} tBOOT_STATUS;


/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/
extern void  NC_BootConfig(tBOOT_INFO *ptBootInfo, tBOOT_STATUS *ptBootStatus);
extern void  NC_IMGConfig(tBOOT_INFO *ptBootInfo);
extern NC_ERROR NC_CheckHeader(const tBOOT_INFO *ptBootInfo);


#endif  /* BOOT_CONFIG_H_ */


/* End Of File */

