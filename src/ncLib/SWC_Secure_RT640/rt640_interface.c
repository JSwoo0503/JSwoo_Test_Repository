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
#include "Drv_A6_OTP2K_Register.h"
#include "rt640_common.h"
#include "cmrt_interface.h"
#include "Drv_OTP.h"
#include "Drv_SCU.h"
#include "Drv_Uart.h"
#include "seq_monitor.h"

/* #include "Drv_SCU.h" */

#define SBOOT_OTP_SIZE              (0x0100u)        /* 256 byte */
#define SBOOT_OTP_BASE              (0x010AFF00u)    /* Image$$BOOT_RESERVED$$ZI$$Base */
#define SBOOT_ENABLE                (*(volatile UINT32 *)(SBOOT_OTP_BASE + 0x0000u))
#define SBOOT_RBCNT                 (*(volatile UINT32 *)(SBOOT_OTP_BASE + 0x0004u))

#define SBOOT_DECKEY_OTP_BASE       (SBOOT_OTP_BASE + 0x0040u) /*256bit, 32byte*/
#define SBOOT_DECKEY_MAC_BASE       (SBOOT_OTP_BASE + 0x0080u) /*256bit, 32byte*/
#define SBOOT_PUBKEY_DIGEST_BASE    (SBOOT_OTP_BASE + 0x00C0u) /*256bit(digested), 32byte*/
#define SYSTEM_OTP_BASE				SBOOT_DECKEY_OTP_BASE

#define KEY_TYPE_CMRT_INTER         (1U)
#define KEY_TYPE_CMRT_EXTER         (2U)

#define SWAP32(val)                     \
    (UINT32)(                           \
        ((UINT32)((val) & 0xffu) << ((UINT8)24u)) |         \
        ((UINT32)((val) & 0xff00u) << ((UINT8)8u)) |        \
        ((UINT32)((val) & 0xff0000u) >> ((UINT8)8u)) |      \
        ((UINT32)((val) & 0xff000000u) >> ((UINT8)24u))     \
    )

/* #define SSSR_SUCCESS	(0x00000000u) */	/**< Success Code */
/* #define SSSR_FAIL		(0x00000001u) */	/**< General Fail Code */

/*
********************************************************************************
*               LOCAL FUNCTION DEFINITIONS
********************************************************************************
*/

/**
* @desc
    Secure Boot mode initialize.
* @param    UINT32          os_with_user_container_img  OS Image start address
* @param    tBOOT_STATUS    *ptBootStatus               Boot Status
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
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
    Result = NC_SUCCESS
    Boot step into secure mode init
    Holding cmrt reset
    Bring up cmrt
    IF  Bringup CMRT is not SUCCESS   THEN
        Result = NC_FAILURE
    ENDIF
    Return Result
*/
NC_ERROR NC_SB_CMRT_Initialize(UINT32 os_with_user_container_img, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR ret = NC_SUCCESS;

    DEBUGMSG(MSGWARN, "[%d ms] NC_SB_CMRT_Initialize - start\n", nc_get_msec(0));


    /* SECURE INIT IN */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_INIT, ptBootStatus);

    NC_SB_Init_Param(ptBootStatus);

    NC_SB_Hold_Reset(ptBootStatus);

    NC_SB_BringUp(os_with_user_container_img, ptBootStatus);

    if(ptBootStatus->mSecureRunRes != (UINT32)NC_SUCCESS)
    {
        ret = NC_FAILURE;
    }

    DEBUGMSG(MSGWARN, "[%d ms] NC_SB_CMRT_Initialize - done\n", nc_get_msec(0));

    return ret;
}



/**
* @desc
    Swap value
* @param    UINT32  *pDst   Destination Address
* @param    UINT32  *pSrc   Source Address
* @param    UINT32  nSize   Data size
* @return   void
* @design
    Perform Data Swap
*/
static void NC_SB_CMRT_Swap(UINT32 *pDst, UINT32 *pSrc, UINT32 nSize)
{
    UINT32 i;

    for(i = 0; i < (nSize / 4U); i++)
    {
        pDst[i] = SWAP32(pSrc[i]);
    }
}



/**
* @desc
    Read the key value and proceed with Secure Boot.
* @param    UINT32          Addr            FW Image Start Address
* @param    UINT8           KEY_STORAGE     Key Storage
* @param    UINT32          KeySplitNum     Key split number
* @param    UINT32          DiversifyPath   Diversify path
* @param    tBOOT_STATUS    *ptBootStatus   Boot Status
* @return   NC_ERROR    NC_SUCCESS or NC_FAILURE
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
    Result = NC_FAILURE
    Boot step into secure run mode
    Select Key storage
        Case OTP
            Boot step into secure key load mode
        Case EFUSE
            Boot step into secure key load mode
        Cale else
            Set primary key
            Boot step into secure key load mode
    End Select
    IF Request decryption service != NC_SUCCESS THEN
        Result = NC_FAILURE
    ELSE
        Result = NC_SUCCESS
    ENDIF
    Return Result
*/
NC_ERROR NC_SB_CMRT_Secure_Run(UINT32 Addr, UINT8 KEY_STORAGE, UINT32 KeySplitNum, UINT32 DiversifyPath, tBOOT_STATUS *ptBootStatus)
{
    NC_ERROR ret;
    UINT32 BOOT_DECKEY_AES[8], BOOT_DECKEY_MAC[8], BOOT_PUBKEY_DIGEST[8];
    UINT32 i;

    static const UINT32 gzu32SBOOT_DECKEY_AES[8] =
    {
#if 0
        /* little endian */
        0x461f5658U, 0x5ceeea10U, 0x77c56d9cU, 0xbfd491c3U,
        0x39c02f2fU, 0x847bcf33U, 0x821b85b5U, 0xed7df504U
#else
        /* big endian */
        0x58561f46U, 0x10eaee5cU, 0x9c6dc577U, 0xc391d4bfU,
        0x2f2fc039U, 0x33cf7b84U, 0xb5851b82U, 0x04f57dedU
#endif
    };

    static const UINT32 gzu32SBOOT_PUBKEY_DIGEST[8] =
    {
#if 0
        /* little endian */
        0x2277850fU, 0xaed13cd7U, 0xf6847f2bU, 0x862cbccaU,
        0xc576af6fU, 0x97b4b547U, 0x3d3ff00aU, 0x4041623dU
#else
        /* big endian */
        0x0f857722U, 0xd73cd1aeU, 0x2b7f84f6U, 0xcabc2c86U,
        0x6faf76c5U, 0x47b5b497U, 0x0af03f3dU, 0x3d624140U
#endif
    };

    static const UINT32 gzu32SBOOT_DECKEY_MAC[8] =
    {
#if 0
        /* little endian */
        0x5677b3a4U, 0x481b83a8U, 0xa3e33498U, 0x216ead59U,
        0x35a2d911U, 0x83936ce3U, 0xf817268aU, 0x7d815deeU
#else
        /* big endian */
        0xa4b37756U, 0xa8831b48U, 0x9834e3a3U, 0x59ad6e21U,
        0x11d9a235U, 0xe36c9383U, 0x8a2617f8U, 0xee5d817dU
#endif

    };

    DEBUGMSG(MSGWARN, "[%d ms] NC_SB_CMRT_Secure_Run - start\n", nc_get_msec(0));

    DEBUGMSG(MSGWARN, "KEY_STORAGE(%d), KeySplitNum(0x%x), DiversifyPath(0x%08x)\n", KEY_STORAGE, KeySplitNum, DiversifyPath);

    /* SECURE RUN IN */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_IN, ptBootStatus);

    /*! > Step 1. Key Apply */
    switch(KEY_STORAGE)
    {
        case E_SBOOT_KEY_STORAGE_OTP :

            #ifdef OTP_ENABLE_
/* PRQA S 0312 ++ */
            #if ((defined(FPGA_MODE_) && defined(FPGA_TEST_OTP_ENABLE_)) || !defined(FPGA_MODE_))
            NC_SB_CMRT_Swap((UINT32 *)SBOOT_DECKEY_OTP_BASE,    (UINT32 *)(&RegA6_OTP->OTP_KEY0_0.Reg), 32U);    /* AES */
            NC_SB_CMRT_Swap((UINT32 *)SBOOT_DECKEY_MAC_BASE,    (UINT32 *)(&RegA6_OTP->OTP_KEY1_0.Reg), 32U);    /* HMAC */
            NC_SB_CMRT_Swap((UINT32 *)SBOOT_PUBKEY_DIGEST_BASE, (UINT32 *)(&RegA6_OTP->OTP_KEY1_0.Reg), 32U);    /* Hashed Public Key */
            #endif
/* PRQA S 0312 -- */
            #endif

            NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_KEY_LOAD, ptBootStatus);
            break;

        case E_SBOOT_KEY_STORAGE_ROM :
        case E_SBOOT_KEY_STORAGE_DEFAULT :
            for(i = 0 ; i < 8U ; i++)
            {
                BOOT_DECKEY_AES[i] = gzu32SBOOT_DECKEY_AES[i];
                BOOT_DECKEY_MAC[i] = gzu32SBOOT_DECKEY_MAC[i];
                BOOT_PUBKEY_DIGEST[i] = gzu32SBOOT_PUBKEY_DIGEST[i];
            }

            NC_SB_CMRT_Swap((UINT32 *)SBOOT_DECKEY_OTP_BASE,    BOOT_DECKEY_AES, 32U);        /* AES */
            NC_SB_CMRT_Swap((UINT32 *)SBOOT_DECKEY_MAC_BASE,    BOOT_DECKEY_MAC, 32U);        /* HMAC */
            NC_SB_CMRT_Swap((UINT32 *)SBOOT_PUBKEY_DIGEST_BASE, BOOT_PUBKEY_DIGEST, 32U);     /* Hashed Public Key */

            NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_KEY_LOAD, ptBootStatus);
            break;

        default :
            DEBUGMSG(MSGWARN, "Unkown key storage value(%d)\n", KEY_STORAGE);
            break;
    }

    SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SECURE_KEY_STORE, (UINT32)KEY_STORAGE);

    if(KeySplitNum == 0U)
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SECURE_KEY_TYPE, (UINT32)KEY_TYPE_CMRT_EXTER);
    }
    else
    {
        SET_BITWISE(DBG_BOOT_SUMMARY_REG, SUM_BIT_SECURE_KEY_TYPE, (UINT32)KEY_TYPE_CMRT_INTER);
    }

    SBOOT_RBCNT  = 0;
    SBOOT_ENABLE = TRUE;

    /*! > Step 2. Start Secure Boot */
    /*
        System OTP :
        aes + hmac + key_hashed_public : continuos memory (each 32bytes, total 32bytes*3)
    */
	ret = NC_SB_Request_Decrypt_Service(Addr, SYSTEM_OTP_BASE, KeySplitNum, DiversifyPath, ptBootStatus);

    /*! > Step 3. Key Clear */
    for(i=0U;i<SBOOT_OTP_SIZE;i+=4U)
    {
        REGRW32(SBOOT_OTP_BASE, i) = 0x0U;
    }

    DEBUGMSG(MSGWARN, "[%d ms] NC_SB_CMRT_Secure_Run - done\n", nc_get_msec(0));

    /* SECURE RUN OUT */
    NC_SM_SetBOOT_SecureStep(DBG_STP_SECURE_RUN_OUT, ptBootStatus);

    return ret;
}

/* End Of File */
