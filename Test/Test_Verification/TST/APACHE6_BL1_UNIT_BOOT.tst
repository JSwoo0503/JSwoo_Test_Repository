-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_BOOT
-- Unit(s) Under Test: boot_SD boot_UART boot_config boot_eMMC boot_sFlash
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: boot_SD

-- Subprogram: NC_Boot_SD

-- Test Case: NC_Boot_SD.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD
TEST.NEW
TEST.NAME:NC_Boot_SD.001
TEST.STUB:boot_SD.NC_Boot_SD_Initialize
TEST.STUB:boot_SD.NC_Boot_SD_DeInitialize
TEST.STUB:boot_SD.NC_Boot_SD_ImageLoading
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.return:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.return:0
TEST.VALUE:boot_SD.NC_Boot_SD.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD.return:0
TEST.EXPECTED:boot_SD.NC_Boot_SD.return:0
TEST.END

-- Test Case: NC_Boot_SD.002
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD
TEST.NEW
TEST.NAME:NC_Boot_SD.002
TEST.STUB:boot_SD.NC_Boot_SD_Initialize
TEST.STUB:boot_SD.NC_Boot_SD_DeInitialize
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.return:-1
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBackupRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mOtpRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSecureRunRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSafetyModeRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mCtrlMode:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mUART_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mUSB_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBootDone_Res:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_SD.NC_Boot_SD.pStatus[0].mBootImgType:0
TEST.VALUE:boot_SD.NC_Boot_SD.return:0
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:14
TEST.EXPECTED:boot_SD.NC_Boot_SD.return:-1
TEST.END

-- Subprogram: NC_Boot_SD_DeInitialize

-- Test Case: NC_Boot_SD_DeInitialize.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_DeInitialize
TEST.NEW
TEST.NAME:NC_Boot_SD_DeInitialize.001
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_DeInitialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:uut_prototype_stubs.NC_SM_SetBOOT_Step.StepInfo:24,25
TEST.VALUE:uut_prototype_stubs.NC_SM_SetBOOT_Step.ptBootStatus[0].mSD_FailRes:0
TEST.END

-- Subprogram: NC_Boot_SD_GetHeader

-- Test Case: NC_Boot_SD_GetHeader.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_GetHeader
TEST.NEW
TEST.NAME:NC_Boot_SD_GetHeader.001
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.return:0
TEST.VALUE:uut_prototype_stubs.NC_Memcpy_u08.Length:64
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:0,1
TEST.VALUE:boot_config.NC_CheckHeader.return:-1,0
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetHeader.return:0
TEST.END

-- Test Case: NC_Boot_SD_GetHeader.002
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_GetHeader
TEST.NEW
TEST.NAME:NC_Boot_SD_GetHeader.002
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.return:0
TEST.VALUE:uut_prototype_stubs.NC_Memcpy_u08.Length:64
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:0,1
TEST.VALUE:boot_config.NC_CheckHeader.return:-1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetHeader.return:-1
TEST.END

-- Subprogram: NC_Boot_SD_GetImage

-- Test Case: NC_Boot_SD_GetImage.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_GetImage
TEST.NEW
TEST.NAME:NC_Boot_SD_GetImage.001
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mLength:1024
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mCheckSum:512
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mDestAddr:0x10000
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.readType:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.return:0
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:256
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:1024
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Addr:17
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Size:1024
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetImage.return:-1
TEST.END

-- Test Case: NC_Boot_SD_GetImage.002
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_GetImage
TEST.NEW
TEST.NAME:NC_Boot_SD_GetImage.002
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mLength:1024
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mCheckSum:1024
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mDestAddr:0x10000
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.readType:1
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.return:0
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:256
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:1024
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Addr:17
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Size:1024
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetImage.return:0
TEST.END

-- Test Case: NC_Boot_SD_GetImage.003
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_GetImage
TEST.NEW
TEST.NAME:NC_Boot_SD_GetImage.003
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mLength:1024
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tHeader.mCheckSum:1024
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mDestAddr:0x10000
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.readType:1
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.return:0
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:256
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:1024
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Addr:17
TEST.VALUE:uut_prototype_stubs.NC_SDC_Read.Size:1024
TEST.VALUE:boot_config.NC_CheckHeader.return:-1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_SD.NC_Boot_SD_GetImage.return:-1
TEST.END

-- Subprogram: NC_Boot_SD_ImageLoading

-- Test Case: NC_Boot_SD_ImageLoading.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_SD_ImageLoading.001
TEST.STUB:boot_SD.NC_Boot_SD_GetImage
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.readType:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.return:0
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSD_FailRes:1
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.return:0
TEST.EXPECTED:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSD_FailRes:0
TEST.EXPECTED:boot_SD.NC_Boot_SD_ImageLoading.return:0
TEST.END

-- Test Case: NC_Boot_SD_ImageLoading.002
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_SD_ImageLoading.002
TEST.STUB:boot_SD.NC_Boot_SD_GetImage
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.readType:0
TEST.VALUE:boot_SD.NC_Boot_SD_GetImage.return:-1
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSD_FailRes:1
TEST.VALUE:boot_SD.NC_Boot_SD_ImageLoading.return:0
TEST.EXPECTED:boot_SD.NC_Boot_SD_ImageLoading.pStatus[0].mSD_FailRes:3
TEST.EXPECTED:boot_SD.NC_Boot_SD_ImageLoading.return:-1
TEST.END

-- Subprogram: NC_Boot_SD_Initialize

-- Test Case: NC_Boot_SD_Initialize.001
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_Initialize
TEST.NEW
TEST.NAME:NC_Boot_SD_Initialize.001
TEST.STUB:boot_SD.NC_Boot_SD_GetHeader
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.ptBootInfo[0].tClock.mSD:40000000
TEST.VALUE:boot_SD.NC_Boot_SD_GetHeader.return:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.ptBootInfo[0].tClock.mSD:40000000
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.NC_SDC_Init.RefClk:40000000
TEST.VALUE:uut_prototype_stubs.NC_SDC_Init.return:0
TEST.EXPECTED:boot_SD.NC_Boot_SD_Initialize.return:0
TEST.END

-- Test Case: NC_Boot_SD_Initialize.002
TEST.UNIT:boot_SD
TEST.SUBPROGRAM:NC_Boot_SD_Initialize
TEST.NEW
TEST.NAME:NC_Boot_SD_Initialize.002
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.ptBootInfo[0].tClock.mSD:40000000
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus:<<malloc 1>>
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSD_FailRes:0
TEST.VALUE:boot_SD.NC_Boot_SD_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.NC_SDC_Init.RefClk:40000000
TEST.VALUE:uut_prototype_stubs.NC_SDC_Init.return:-1
TEST.EXPECTED:boot_SD.NC_Boot_SD_Initialize.pStatus[0].mSD_FailRes:3
TEST.EXPECTED:boot_SD.NC_Boot_SD_Initialize.return:-1
TEST.END

-- Unit: boot_UART

-- Subprogram: NC_Boot_UART

-- Test Case: NC_Boot_UART.001
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART
TEST.NEW
TEST.NAME:NC_Boot_UART.001
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.rxlen:458752
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.filename:"test.tx"
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.pRxFileSize[0]:0
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.return:-1
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.return:0
TEST.EXPECTED:boot_UART.NC_Boot_UART.return:-1
TEST.END

-- Test Case: NC_Boot_UART.002
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART
TEST.NEW
TEST.NAME:NC_Boot_UART.002
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:64
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:100
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.rxlen:458752
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.filename:"test.tx"
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.pRxFileSize[0]:0
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.return:0
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tHeader.mLength:256
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tHeader.mCheckSum:123
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tImage.mDestAddr:0x21000000
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.return:0
TEST.EXPECTED:boot_UART.NC_Boot_UART.return:-1
TEST.END

-- Test Case: NC_Boot_UART.003
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART
TEST.NEW
TEST.NAME:NC_Boot_UART.003
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:64
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:123
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.rxlen:458752
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.filename:"test.tx"
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.pRxFileSize[0]:0
TEST.VALUE:uut_prototype_stubs.NC_Ymodem_receive.return:0
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tHeader.mLength:256
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tHeader.mCheckSum:123
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootInfo[0].tImage.mDestAddr:0x21000000
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART.ptBootStatus[0].mUART_FailRes:0
TEST.VALUE:boot_UART.NC_Boot_UART.return:0
TEST.EXPECTED:boot_UART.NC_Boot_UART.ptBootStatus[0].mUART_FailRes:0
TEST.EXPECTED:boot_UART.NC_Boot_UART.return:0
TEST.END

-- Subprogram: NC_Boot_UART_Initialize

-- Test Case: NC_Boot_UART_Initialize.001
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART_Initialize
TEST.NEW
TEST.NAME:NC_Boot_UART_Initialize.001
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.BaudRate:115200
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.RefClk:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tImage.mUartBaudrate:1
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tClock.mUART:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootStatus:<<malloc 1>>
TEST.END

-- Test Case: NC_Boot_UART_Initialize.002
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART_Initialize
TEST.NEW
TEST.NAME:NC_Boot_UART_Initialize.002
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.BaudRate:115200
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.RefClk:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tImage.mUartBaudrate:2
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tClock.mUART:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootStatus:<<malloc 1>>
TEST.END

-- Test Case: NC_Boot_UART_Initialize.003
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART_Initialize
TEST.NEW
TEST.NAME:NC_Boot_UART_Initialize.003
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.BaudRate:115200
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.RefClk:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tImage.mUartBaudrate:3
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tClock.mUART:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootStatus:<<malloc 1>>
TEST.END

-- Test Case: NC_Boot_UART_Initialize.004
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART_Initialize
TEST.NEW
TEST.NAME:NC_Boot_UART_Initialize.004
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.BaudRate:115200
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.RefClk:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo[0].tClock.mUART:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootStatus:<<malloc 1>>
TEST.END

-- Test Case: NC_Boot_UART_Initialize.005
TEST.UNIT:boot_UART
TEST.SUBPROGRAM:NC_Boot_UART_Initialize
TEST.NEW
TEST.NAME:NC_Boot_UART_Initialize.005
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.BaudRate:115200
TEST.VALUE:uut_prototype_stubs.NC_UART_Initialize.RefClk:40000000
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootInfo:<<null>>
TEST.VALUE:boot_UART.NC_Boot_UART_Initialize.ptBootStatus:<<malloc 1>>
TEST.END

-- Unit: boot_config

-- Subprogram: NC_BootConfig

-- Test Case: NC_BootConfig.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_BootConfig
TEST.NEW
TEST.NAME:NC_BootConfig.001
TEST.STUB:boot_config.NC_DefaultConfig
TEST.VALUE:boot_config.NC_BootConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_BootConfig.ptBootStatus:<<malloc 1>>
TEST.END

-- Subprogram: NC_CheckHeader

-- Test Case: NC_CheckHeader.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_CheckHeader
TEST.NEW
TEST.NAME:NC_CheckHeader.001
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tHeader.mSignature:0x30365041
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.EXPECTED:boot_config.NC_CheckHeader.return:0
TEST.END

-- Test Case: NC_CheckHeader.002
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_CheckHeader
TEST.NEW
TEST.NAME:NC_CheckHeader.002
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tHeader.mSignature:0x30365000
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.EXPECTED:boot_config.NC_CheckHeader.return:-1
TEST.END

-- Subprogram: NC_DefaultConfig

-- Test Case: NC_DefaultConfig.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_DefaultConfig
TEST.NEW
TEST.NAME:NC_DefaultConfig.001
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCLK_INV:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mTempBuff:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mKeyStorage:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDestAddr:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[0..1]:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tStrap.Bit.mPLLConfig:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCLK_INV:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mTempBuff:0x1000000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUartBaudrate:3
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSecuMode:1
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSafetyMode:2
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mKeyStorage:2
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDestAddr:0x1000000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[0]:0x1000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0x11000
TEST.END

-- Test Case: NC_DefaultConfig.002
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_DefaultConfig
TEST.NEW
TEST.NAME:NC_DefaultConfig.002
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCLK_INV:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mTempBuff:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mKeyStorage:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDestAddr:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[0..1]:0
TEST.VALUE:boot_config.NC_DefaultConfig.ptBootInfo[0].tStrap.Bit.mPLLConfig:1
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mCLK_INV:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mTempBuff:0x1000000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSecuMode:1
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mSafetyMode:2
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mKeyStorage:2
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mDestAddr:0x1000000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[0]:0x1000
TEST.EXPECTED:boot_config.NC_DefaultConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0x11000
TEST.END

-- Subprogram: NC_IMGConfig

-- Test Case: NC_IMGConfig.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig
TEST.NEW
TEST.NAME:NC_IMGConfig.001
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.Index:1,2
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.return:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Reg:0
TEST.END

-- Test Case: NC_IMGConfig.002
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig
TEST.NEW
TEST.NAME:NC_IMGConfig.002
TEST.VALUE:uut_prototype_stubs.NC_ICU_GetPadInfo.BootDevice:0
TEST.VALUE:uut_prototype_stubs.NC_ICU_GetPadInfo.return:0
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.Index:1,2
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.return:0x25491511,0x3510
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mKeyStorage:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mCtrlMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashType:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mDriveStrength:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiDummyCycle:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiRxDelay:0x10
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUartBaudrate:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUsbRefClock:3
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSecuMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSafetyMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFaultCpuReset:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mKeyStorage:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUseKeyCmrt:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0x21000
TEST.ATTRIBUTES:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Reg:EXPECTED_BASE=16
TEST.ATTRIBUTES:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Reg:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_IMGConfig.003
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig
TEST.NEW
TEST.NAME:NC_IMGConfig.003
TEST.VALUE:uut_prototype_stubs.NC_ICU_GetPadInfo.BootDevice:0
TEST.VALUE:uut_prototype_stubs.NC_ICU_GetPadInfo.return:-1
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.Index:1,2
TEST.VALUE:uut_prototype_stubs.NC_GetDBG_OTP_Config.return:0x0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mSPI_CTRL:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mSECURE_MODE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mKEY_STORAGE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mUSE_KEY_CMRT:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mSAFETY_MODE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mSFLASH_TYPE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DS:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mFAULT_RESET:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_CLK_DIV:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DCYCLE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_1.Bit.mFW_SIZEUP:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Bit.mSPI_RX_DELAY:0x10
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Bit.mSPI_CLK_POL_PH:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Bit.mUART_BAUDRATE:1
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mConfig_2.Bit.mUSB_REF_CLK:3
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mDriveStrength:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mKeyStorage:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mCtrlMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashType:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mDriveStrength:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mQspiDummyCycle:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiRxDelay:0x10
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSpiClockPolarityPhase:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUartBaudrate:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUsbRefClock:3
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSecuMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mSafetyMode:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFaultCpuReset:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mKeyStorage:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mUseKeyCmrt:1
TEST.EXPECTED:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0x21000
TEST.END

-- Subprogram: NC_IMGConfig_OTP1

-- Test Case: NC_IMGConfig_OTP1.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP1
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP1.001
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.return:0
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.return:0
TEST.END

-- Test Case: NC_IMGConfig_OTP1.002
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP1
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP1.002
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Reg:0x28411613
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSPI_CTRL:0x3
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSECURE_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mKEY_STORAGE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mUSE_KEY_CMRT:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSAFETY_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSFLASH_TYPE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DS:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFAULT_RESET:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_CLK_DIV:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DCYCLE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFW_SIZEUP:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Reg:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.return:0
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0x3
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0x1
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.return:1
TEST.END

-- Test Case: NC_IMGConfig_OTP1.003
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP1
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP1.003
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Reg:0x28411613
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSPI_CTRL:0x3
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSECURE_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mKEY_STORAGE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mUSE_KEY_CMRT:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSAFETY_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSFLASH_TYPE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DS:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFAULT_RESET:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_CLK_DIV:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DCYCLE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFW_SIZEUP:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Reg:0x28411613
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSPI_CTRL:0x3
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSECURE_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mKEY_STORAGE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mUSE_KEY_CMRT:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSAFETY_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSFLASH_TYPE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_DS:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mFAULT_RESET:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_CLK_DIV:0x0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_DCYCLE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mFW_SIZEUP:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.return:0
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0x3
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0x1
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.return:1
TEST.END

-- Test Case: NC_IMGConfig_OTP1.004
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP1
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP1.004
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Reg:0x28411613
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSPI_CTRL:0x3
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSECURE_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mKEY_STORAGE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mUSE_KEY_CMRT:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSAFETY_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mSFLASH_TYPE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DS:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFAULT_RESET:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_CLK_DIV:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mQSPI_DCYCLE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tHeader.mConfig_1.Bit.mFW_SIZEUP:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Reg:0x28411613
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSPI_CTRL:0x3
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSECURE_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mKEY_STORAGE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mUSE_KEY_CMRT:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSAFETY_MODE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mSFLASH_TYPE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_DS:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mFAULT_RESET:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_CLK_DIV:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mQSPI_DCYCLE:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.pOTPConfig1[0].Bit.mFW_SIZEUP:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP1.return:0
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mCtrlMode:0x3
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.ptBootInfo[0].tImage.mSecuMode:0x1
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP1.return:1
TEST.END

-- Subprogram: NC_IMGConfig_OTP2

-- Test Case: NC_IMGConfig_OTP2.001
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP2
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP2.001
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.return:0
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.return:0
TEST.END

-- Test Case: NC_IMGConfig_OTP2.002
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP2
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP2.002
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG11.Reg:0
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG12.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Reg:0x5611
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Bit.mSPI_RX_DELAY:0x11
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Bit.mSPI_CLK_POL_PH:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Bit.mUART_BAUDRATE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tHeader.mConfig_2.Bit.mUSB_REF_CLK:0x5
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.return:0
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG11.Reg:0x11
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG12.Reg:0x2
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiRxDelay:0x11
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0x2
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUartBaudrate:0x1
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUsbRefClock:0x5
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.return:1
TEST.END

-- Test Case: NC_IMGConfig_OTP2.003
TEST.UNIT:boot_config
TEST.SUBPROGRAM:NC_IMGConfig_OTP2
TEST.NEW
TEST.NAME:NC_IMGConfig_OTP2.003
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG11.Reg:0
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG12.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2:<<malloc 1>>
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Reg:0x5611
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Bit.mSPI_RX_DELAY:0x11
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Bit.mSPI_CLK_POL_PH:0x2
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Bit.mUART_BAUDRATE:0x1
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.pOTPConfig2[0].Bit.mUSB_REF_CLK:0x5
TEST.VALUE:boot_config.NC_IMGConfig_OTP2.return:0
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG11.Reg:0x11
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG12.Reg:0x2
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiRxDelay:0x11
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0x2
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUartBaudrate:0x1
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.ptBootInfo[0].tImage.mUsbRefClock:0x5
TEST.EXPECTED:boot_config.NC_IMGConfig_OTP2.return:1
TEST.END

-- Unit: boot_eMMC

-- Subprogram: NC_Boot_EMMC_DeInitialize

-- Test Case: NC_Boot_EMMC_DeInitialize.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_DeInitialize
TEST.NEW
TEST.NAME:NC_Boot_EMMC_DeInitialize.001
TEST.VALUE:uut_prototype_stubs.NC_SM_SetBOOT_Step.StepInfo:18,19
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_DeInitialize.pStatus:<<malloc 1>>
TEST.END

-- Subprogram: NC_Boot_EMMC_GetHeader

-- Test Case: NC_Boot_EMMC_GetHeader.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetHeader
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetHeader.001
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_Get_Firmware_Backup_Offset.return:0x100
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:1,2
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:0x50300
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.return:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetHeader.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_GetHeader.002
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetHeader
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetHeader.002
TEST.STUB:boot_config.NC_CheckHeader
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_Get_Firmware_Backup_Offset.return:0x100
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:1,2
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:0x50300
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:-1
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.rtype:1
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.Size:0x50300
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.return:-1
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.return:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x100200
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetHeader.return:-1
TEST.END

-- Subprogram: NC_Boot_EMMC_GetImage

-- Test Case: NC_Boot_EMMC_GetImage.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetImage
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetImage.001
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:4
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:10
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:0x11
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:80
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mCheckSum:10
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tImage.mDestAddr:0x2000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_GetImage.002
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetImage
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetImage.002
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:4
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:5,10
TEST.VALUE:uut_prototype_stubs.NC_Get_Firmware_Backup_Offset.return:0x100
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:0x12
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:80
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:0
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.rtype:2
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mCheckSum:10
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tImage.mDestAddr:0x2000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:2
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:2
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_GetImage.003
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetImage
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetImage.003
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:4
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:5
TEST.VALUE:uut_prototype_stubs.NC_Get_Firmware_Backup_Offset.return:0x100
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:0x12
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:80
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:0
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.rtype:2
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mCheckSum:10
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tImage.mDestAddr:0x2000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:2
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:2
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.return:-1
TEST.END

-- Test Case: NC_Boot_EMMC_GetImage.004
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_GetImage
TEST.NEW
TEST.NAME:NC_Boot_EMMC_GetImage.004
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:4
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:5
TEST.VALUE:uut_prototype_stubs.NC_Get_Firmware_Backup_Offset.return:0x100
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.rtype:0x12
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.Size:80
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByADMA2.return:-1
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.rtype:2
TEST.VALUE:uut_prototype_stubs.NC_EMMC_ReadByFIFO.return:-1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mLength:16
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tHeader.mCheckSum:10
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.ptBootInfo[0].tImage.mDestAddr:0x2000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:2
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.pStatus[0].mEMMC_FailRes:1
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_GetImage.return:-1
TEST.END

-- Subprogram: NC_Boot_EMMC_ImageLoading

-- Test Case: NC_Boot_EMMC_ImageLoading.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_EMMC_ImageLoading.001
TEST.STUB:boot_eMMC.NC_Boot_EMMC_GetImage
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_ImageLoading.002
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_EMMC_ImageLoading.002
TEST.STUB:boot_eMMC.NC_Boot_EMMC_GetImage
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:13
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:-1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.EXPECTED:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:-1
TEST.END

-- Test Case: NC_Boot_EMMC_ImageLoading.003
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_EMMC_ImageLoading.003
TEST.STUB:boot_eMMC.NC_Boot_EMMC_GetImage
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:13
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:-1,0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.EXPECTED:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_ImageLoading.004
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_ImageLoading
TEST.NEW
TEST.NAME:NC_Boot_EMMC_ImageLoading.004
TEST.STUB:boot_eMMC.NC_Boot_EMMC_GetImage
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:13
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.readType:1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetImage.return:-1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:3
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.EXPECTED:boot_eMMC.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0xC00
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.pStatus[0].mEMMC_FailRes:3
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:-1
TEST.END

-- Subprogram: NC_Boot_EMMC_Initialize

-- Test Case: NC_Boot_EMMC_Initialize.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_Initialize
TEST.NEW
TEST.NAME:NC_Boot_EMMC_Initialize.001
TEST.STUB:boot_eMMC.NC_Boot_EMMC_GetHeader
TEST.VALUE:uut_prototype_stubs.NC_SM_SetBOOT_Step.StepInfo:14,15
TEST.VALUE:uut_prototype_stubs.NC_EMMC_Initialize.RefClk:40000000
TEST.VALUE:uut_prototype_stubs.NC_EMMC_Initialize.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.ptBootInfo[0].tClock.mEMMC:40000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_GetHeader.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.ptBootInfo[0].tClock.mEMMC:40000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_Initialize.return:0
TEST.END

-- Test Case: NC_Boot_EMMC_Initialize.002
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_EMMC_Initialize
TEST.NEW
TEST.NAME:NC_Boot_EMMC_Initialize.002
TEST.VALUE:uut_prototype_stubs.NC_SM_SetBOOT_Step.StepInfo:14,15
TEST.VALUE:uut_prototype_stubs.NC_EMMC_Initialize.RefClk:40000000
TEST.VALUE:uut_prototype_stubs.NC_EMMC_Initialize.return:-1
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.ptBootInfo[0].tClock.mEMMC:40000000
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_EMMC_Initialize.return:-1
TEST.END

-- Subprogram: NC_Boot_eMMC

-- Test Case: NC_Boot_eMMC.001
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_eMMC
TEST.NEW
TEST.NAME:NC_Boot_eMMC.001
TEST.STUB:boot_eMMC.NC_Boot_EMMC_Initialize
TEST.STUB:boot_eMMC.NC_Boot_EMMC_DeInitialize
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.return:-1
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_eMMC.return:-1
TEST.END

-- Test Case: NC_Boot_eMMC.002
TEST.UNIT:boot_eMMC
TEST.SUBPROGRAM:NC_Boot_eMMC
TEST.NEW
TEST.NAME:NC_Boot_eMMC.002
TEST.STUB:boot_eMMC.NC_Boot_EMMC_Initialize
TEST.STUB:boot_eMMC.NC_Boot_EMMC_DeInitialize
TEST.STUB:boot_eMMC.NC_Boot_EMMC_ImageLoading
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_Initialize.return:0
TEST.VALUE:boot_eMMC.NC_Boot_EMMC_ImageLoading.return:0
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.pStatus:<<malloc 1>>
TEST.VALUE:boot_eMMC.NC_Boot_eMMC.return:0
TEST.EXPECTED:boot_eMMC.NC_Boot_eMMC.return:0
TEST.END

-- Unit: boot_sFlash

-- Subprogram: NC_Boot_sFlash

-- Test Case: NC_Boot_sFlash.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_Boot_sFlash
TEST.NEW
TEST.NAME:NC_Boot_sFlash.001
TEST.STUB:boot_sFlash.NC_SF_Initialize
TEST.STUB:boot_sFlash.NC_SF_ImageLoading
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.return:0
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.return:0
TEST.EXPECTED:boot_sFlash.NC_Boot_sFlash.return:0
TEST.END

-- Test Case: NC_Boot_sFlash.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_Boot_sFlash
TEST.NEW
TEST.NAME:NC_Boot_sFlash.002
TEST.STUB:boot_sFlash.NC_SF_Initialize
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:-1
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_Boot_sFlash.return:0
TEST.EXPECTED:boot_sFlash.NC_Boot_sFlash.return:-1
TEST.END

-- Subprogram: NC_SF_ChangeCtrlModeAndImgType

-- Test Case: NC_SF_ChangeCtrlModeAndImgType.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ChangeCtrlModeAndImgType
TEST.NEW
TEST.NAME:NC_SF_ChangeCtrlModeAndImgType.001
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0x0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:1
TEST.END

-- Test Case: NC_SF_ChangeCtrlModeAndImgType.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ChangeCtrlModeAndImgType
TEST.NEW
TEST.NAME:NC_SF_ChangeCtrlModeAndImgType.002
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0x20
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:3
TEST.END

-- Test Case: NC_SF_ChangeCtrlModeAndImgType.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ChangeCtrlModeAndImgType
TEST.NEW
TEST.NAME:NC_SF_ChangeCtrlModeAndImgType.003
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0x7
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:2
TEST.END

-- Test Case: NC_SF_ChangeCtrlModeAndImgType.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ChangeCtrlModeAndImgType
TEST.NEW
TEST.NAME:NC_SF_ChangeCtrlModeAndImgType.004
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0xD0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:4
TEST.END

-- Test Case: NC_SF_ChangeCtrlModeAndImgType.005
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ChangeCtrlModeAndImgType
TEST.NEW
TEST.NAME:NC_SF_ChangeCtrlModeAndImgType.005
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0x0
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:5
TEST.END

-- Subprogram: NC_SF_CheckClockDiv

-- Test Case: NC_SF_CheckClockDiv.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckClockDiv
TEST.NEW
TEST.NAME:NC_SF_CheckClockDiv.001
TEST.VALUE:boot_sFlash.NC_SF_CheckClockDiv.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckClockDiv.ptBootInfo[0].tImage.mQspiClockDiv:0,1,2,3
TEST.VALUE:boot_sFlash.NC_SF_CheckClockDiv.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckClockDiv.return:20,16,8,20
TEST.END

-- Subprogram: NC_SF_CheckNormalImageFault

-- Test Case: NC_SF_CheckNormalImageFault.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckNormalImageFault
TEST.NEW
TEST.NAME:NC_SF_CheckNormalImageFault.001
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.RetryType:1
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.CtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckNormalImageFault.return:1
TEST.END

-- Test Case: NC_SF_CheckNormalImageFault.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckNormalImageFault
TEST.NEW
TEST.NAME:NC_SF_CheckNormalImageFault.002
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.RetryType:8
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.CtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.END

-- Test Case: NC_SF_CheckNormalImageFault.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckNormalImageFault
TEST.NEW
TEST.NAME:NC_SF_CheckNormalImageFault.003
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.RetryType:15
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.CtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckNormalImageFault.return:1
TEST.END

-- Test Case: NC_SF_CheckNormalImageFault.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckNormalImageFault
TEST.NEW
TEST.NAME:NC_SF_CheckNormalImageFault.004
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.RetryType:15
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.CtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckNormalImageFault.return:1
TEST.END

-- Test Case: NC_SF_CheckNormalImageFault.005
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckNormalImageFault
TEST.NEW
TEST.NAME:NC_SF_CheckNormalImageFault.005
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.RetryType:15
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.CtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckNormalImageFault.return:0
TEST.END

-- Subprogram: NC_SF_CheckQSPIBitRate

-- Test Case: NC_SF_CheckQSPIBitRate.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckQSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckQSPIBitRate.001
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.Div:16
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.RefClk:1500000
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.return:93750
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPI:1500000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x42000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:4
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:93750
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.return:-1
TEST.END

-- Test Case: NC_SF_CheckQSPIBitRate.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckQSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckQSPIBitRate.002
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.Div:20
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.RefClk:2000000
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.return:100000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tHeader.mSignature:0x30365000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPI:2000000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x22000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:2
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:100000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.return:-1
TEST.END

-- Test Case: NC_SF_CheckQSPIBitRate.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckQSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckQSPIBitRate.003
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_Compare.pSrc[0]:1
TEST.VALUE:uut_prototype_stubs.NC_Compare.pSrc[1]:2
TEST.VALUE:uut_prototype_stubs.NC_Compare.pSrc[2]:3
TEST.VALUE:uut_prototype_stubs.NC_Compare.pDes[0]:1
TEST.VALUE:uut_prototype_stubs.NC_Compare.pDes[1]:2
TEST.VALUE:uut_prototype_stubs.NC_Compare.pDes[2]:2,3
TEST.VALUE:uut_prototype_stubs.NC_Compare.Length:64
TEST.VALUE:uut_prototype_stubs.NC_Compare.return:-1,0
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.Div:8,6
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.RefClk:2000000
TEST.VALUE:uut_prototype_stubs.NC_QSPI_SetBitRate.return:250000,333333
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.CtrlMode:2
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Addr:0x10000000
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Size:64
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tHeader.mSignature:0x30365041
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mFlashAddr[0]:0x10000000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPI:2000000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x20000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPI:100000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPIDiv:20
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mCtrlMode:2
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:333333
TEST.EXPECTED:boot_sFlash.NC_SF_CheckQSPIBitRate.return:0
TEST.END

-- Subprogram: NC_SF_CheckSPIBitRate

-- Test Case: NC_SF_CheckSPIBitRate.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckSPIBitRate.001
TEST.STUB:boot_config.NC_CheckHeader
TEST.STUB:boot_sFlash.NC_SF_GetHeader
TEST.STUB:boot_sFlash.NC_SF_SetTargetBitrate
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.pBitRate[0]:1000000
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.RefClk:25000000
TEST.VALUE:uut_prototype_stubs.NC_SM_SetRETRY_Count.InterfaceId:1
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_config.NC_CheckHeader.return:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:1562500
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:1000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:1000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:25
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:1000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.END

-- Test Case: NC_SF_CheckSPIBitRate.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckSPIBitRate.002
TEST.STUB:boot_config.NC_CheckHeader
TEST.STUB:boot_sFlash.NC_SF_GetHeader
TEST.STUB:boot_sFlash.NC_SF_SetTargetBitrate
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:3
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.pBitRate[0]:1000000
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.RefClk:25000000
TEST.VALUE:uut_prototype_stubs.NC_SM_SetRETRY_Count.InterfaceId:1
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_config.NC_CheckHeader.return:-1
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:1250000
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:1000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:25
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:1000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.return:-1
TEST.END

-- Test Case: NC_SF_CheckSPIBitRate.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckSPIBitRate.003
TEST.STUB:boot_config.NC_CheckHeader
TEST.STUB:boot_sFlash.NC_SF_GetHeader
TEST.STUB:boot_sFlash.NC_SF_SetTargetBitrate
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:11
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.pBitRate[0]:1000000
TEST.VALUE:uut_prototype_stubs.NC_SPI_SetBitRate.RefClk:25000000
TEST.VALUE:uut_prototype_stubs.NC_SM_SetRETRY_Count.InterfaceId:1
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_config.NC_CheckHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_config.NC_CheckHeader.return:-1
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:3125000
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:1000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.EXPECTED:boot_config.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x100
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:25
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:1
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:1000000
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.return:-1
TEST.END

-- Test Case: NC_SF_CheckSPIBitRate.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckSPIBitRate.004
TEST.STUB:boot_sFlash.NC_SF_GetHeader
TEST.STUB:boot_sFlash.NC_SF_SetTargetBitrate
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:10
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tClock.mSPI:20
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:-1
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:1
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:20
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mHeaderReadRes:1
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.return:-1
TEST.END

-- Test Case: NC_SF_CheckSPIBitRate.005
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_CheckSPIBitRate
TEST.NEW
TEST.NAME:NC_SF_CheckSPIBitRate.005
TEST.STUB:boot_sFlash.NC_SF_GetHeader
TEST.STUB:boot_sFlash.NC_SF_SetTargetBitrate
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:10
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tClock.mSPI:20
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:-1
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:1
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:20
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mHeaderReadRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:256
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPIDiv:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mBackupRes:1
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mHeaderReadRes:1
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootStatus[0].mSF_CheckSCLKRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_CheckSPIBitRate.return:-1
TEST.END

-- Subprogram: NC_SF_ClearCtrlModeRetryMask

-- Test Case: NC_SF_ClearCtrlModeRetryMask.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ClearCtrlModeRetryMask
TEST.NEW
TEST.NAME:NC_SF_ClearCtrlModeRetryMask.001
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.CtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ImgType:0,1
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.EXPECTED:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFD,0xFC
TEST.END

-- Test Case: NC_SF_ClearCtrlModeRetryMask.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ClearCtrlModeRetryMask
TEST.NEW
TEST.NAME:NC_SF_ClearCtrlModeRetryMask.002
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.CtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ImgType:0,1
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.EXPECTED:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xF7,0xF3
TEST.END

-- Test Case: NC_SF_ClearCtrlModeRetryMask.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ClearCtrlModeRetryMask
TEST.NEW
TEST.NAME:NC_SF_ClearCtrlModeRetryMask.003
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.CtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ImgType:0,1
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.EXPECTED:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xDF,0xCF
TEST.END

-- Test Case: NC_SF_ClearCtrlModeRetryMask.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ClearCtrlModeRetryMask
TEST.NEW
TEST.NAME:NC_SF_ClearCtrlModeRetryMask.004
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.CtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ImgType:0,1
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.EXPECTED:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0x7F,0x3F
TEST.END

-- Test Case: NC_SF_ClearCtrlModeRetryMask.005
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ClearCtrlModeRetryMask
TEST.NEW
TEST.NAME:NC_SF_ClearCtrlModeRetryMask.005
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.CtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.EXPECTED:boot_sFlash.NC_SF_ClearCtrlModeRetryMask.ptBootStatus[0].mSF_ImgLoadRetryType:0xFF
TEST.END

-- Subprogram: NC_SF_GetHeader

-- Test Case: NC_SF_GetHeader.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_GetHeader
TEST.NEW
TEST.NAME:NC_SF_GetHeader.001
TEST.STUB:boot_config.NC_IMGConfig
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.CtrlMode:1
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Addr:0x10000000
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Size:64
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mSignature:0x30365041
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[0]:0x10000000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.mSignature:0x30365041
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.return:0
TEST.END

-- Test Case: NC_SF_GetHeader.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_GetHeader
TEST.NEW
TEST.NAME:NC_SF_GetHeader.002
TEST.STUB:boot_config.NC_IMGConfig
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.CtrlMode:1
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Addr:0x10000000,0x30000000
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Size:64
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tHeader.mSignature:0x30365000
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[0]:0x10000000
TEST.VALUE:boot_config.NC_IMGConfig.ptBootInfo[0].tImage.mFlashAddr[1]:0x30000000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.mSignature:0x30365000
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetHeader.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:0
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.ptBootInfo[0].tImage.mImg_Type:1
TEST.EXPECTED:boot_sFlash.NC_SF_GetHeader.return:-1
TEST.END

-- Subprogram: NC_SF_GetImage

-- Test Case: NC_SF_GetImage.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_GetImage
TEST.NEW
TEST.NAME:NC_SF_GetImage.001
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:2
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:35
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.CtrlMode:0
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Addr:0x10000040
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Size:8
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tHeader.mLength:8
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tHeader.mCheckSum:36
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mFlashAddr[0]:0x10000040
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:boot_sFlash.NC_SF_GetImage.return:-1
TEST.END

-- Test Case: NC_SF_GetImage.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_GetImage
TEST.NEW
TEST.NAME:NC_SF_GetImage.002
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_Checksum.Length:2
TEST.VALUE:uut_prototype_stubs.NC_Checksum.return:36
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.CtrlMode:0
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Addr:0x10000040
TEST.VALUE:uut_prototype_stubs.NC_SF_ReadData.Size:8
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tHeader.mLength:8
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tHeader.mCheckSum:36
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mFlashAddr[0]:0x10000040
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:0
TEST.EXPECTED:boot_SD.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:boot_sFlash.NC_SF_GetImage.return:0
TEST.END

-- Subprogram: NC_SF_ImageLoading

-- Test Case: NC_SF_ImageLoading.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.001
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_RecordFaults
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.Ret:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.OrgCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus[0].mSF_FailRes:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus[0].mBootImgType:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:0
TEST.EXPECTED:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:1
TEST.EXPECTED:boot_sFlash.NC_SF_ImageLoading.return:0
TEST.END

-- Test Case: NC_SF_ImageLoading.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.002
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SF_ImageLoading.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.003
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SF_ImageLoading.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.004
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SF_ImageLoading.005
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.005
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SF_ImageLoading.006
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.006
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SF_ImageLoading.007
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ImageLoading
TEST.NEW
TEST.NAME:NC_SF_ImageLoading.007
TEST.STUB:boot_sFlash.NC_SF_GetImage
TEST.STUB:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_GetImage.ptBootInfo[0].tImage.mCtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_GetImage.return:-1,1,0
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootInfo[0].tImage.mCtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mSF_ImgLoadRetryType:1
TEST.VALUE:boot_sFlash.NC_SF_ChangeCtrlModeAndImgType.ptBootStatus[0].mBootImgType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mImg_Type:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootInfo[0].tImage.mCtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:1
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_ImgLoadRetryType:0
TEST.VALUE:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mBootImgType:0
TEST.ATTRIBUTES:boot_sFlash.NC_SF_ImageLoading.ptBootStatus[0].mSF_FailRes:EXPECTED_BASE=16
TEST.END

-- Subprogram: NC_SF_Initialize

-- Test Case: NC_SF_Initialize.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_Initialize
TEST.NEW
TEST.NAME:NC_SF_Initialize.001
TEST.STUB:boot_sFlash.NC_SF_CheckSPIBitRate
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.BitRate:1562500
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.RefClk:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:-1
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:3
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.return:-1
TEST.END

-- Test Case: NC_SF_Initialize.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_Initialize
TEST.NEW
TEST.NAME:NC_SF_Initialize.002
TEST.STUB:boot_sFlash.NC_SF_CheckSPIBitRate
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[0]:0xA5
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[1]:0x5A
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[2]:0xC3
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.Config:1
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.return:-1
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.BitRate:1250000
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.RefClk:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mFlashType:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mFlashType:1
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mQspiClockDiv:1
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:3
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.return:0
TEST.END

-- Test Case: NC_SF_Initialize.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_Initialize
TEST.NEW
TEST.NAME:NC_SF_Initialize.003
TEST.STUB:boot_sFlash.NC_SF_CheckSPIBitRate
TEST.STUB:boot_sFlash.NC_SF_CheckQSPIBitRate
TEST.VALUE:uut_prototype_stubs.NC_QSPI_Init.BitRate:3125000
TEST.VALUE:uut_prototype_stubs.NC_QSPI_Init.RefClk:25000000
TEST.VALUE:uut_prototype_stubs.NC_QSPI_Init.DummyCycle:0
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[0]:0xA5
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[1]:0x5A
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[2]:0xC3
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.Config:0
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.return:0
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.BitRate:3125000
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.RefClk:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.ptBootInfo[0].tClock.mQSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckQSPIBitRate.return:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mQspiClockDiv:2
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tClock.mQSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.return:0
TEST.END

-- Test Case: NC_SF_Initialize.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_Initialize
TEST.NEW
TEST.NAME:NC_SF_Initialize.004
TEST.STUB:boot_sFlash.NC_SF_CheckSPIBitRate
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[0]:0xA5
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[1]:0x5A
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.pRDID[2]:0xC3
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.Config:1
TEST.VALUE:uut_prototype_stubs.NC_SF_EnableDeviceQuadMode.return:-1
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.BitRate:1250000
TEST.VALUE:uut_prototype_stubs.NC_SF_Init.RefClk:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mFlashType:1
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_CheckSPIBitRate.return:0
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:2
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mFlashType:1
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mQspiClockDiv:3
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tClock.mSPI:25000000
TEST.VALUE:boot_sFlash.NC_SF_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_Initialize.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.ptBootInfo[0].tImage.mCtrlMode:2
TEST.EXPECTED:boot_sFlash.NC_SF_Initialize.return:0
TEST.END

-- Subprogram: NC_SF_ModifyDebugSummarySPIMode

-- Test Case: NC_SF_ModifyDebugSummarySPIMode.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_ModifyDebugSummarySPIMode
TEST.NEW
TEST.NAME:NC_SF_ModifyDebugSummarySPIMode.001
TEST.VALUE:boot_sFlash.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:boot_sFlash.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:boot_sFlash.NC_SF_ModifyDebugSummarySPIMode.delCtrlMode:4
TEST.VALUE:boot_sFlash.NC_SF_ModifyDebugSummarySPIMode.setCtrlMode:3
TEST.EXPECTED:boot_sFlash.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x30000
TEST.END

-- Subprogram: NC_SF_RecordFaults

-- Test Case: NC_SF_RecordFaults.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_RecordFaults
TEST.NEW
TEST.NAME:NC_SF_RecordFaults.001
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:12
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:4
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.Ret:-1
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.OrgCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus:<<malloc 1>>
TEST.END

-- Test Case: NC_SF_RecordFaults.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_RecordFaults
TEST.NEW
TEST.NAME:NC_SF_RecordFaults.002
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.Ret:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.OrgCtrlMode:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus[0].mBootImgType:0
TEST.END

-- Test Case: NC_SF_RecordFaults.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_RecordFaults
TEST.NEW
TEST.NAME:NC_SF_RecordFaults.003
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:4
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.Ret:0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.OrgCtrlMode:5
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus:<<malloc 1>>
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus[0].mSF_ImgLoadRetryType:0x0
TEST.VALUE:boot_sFlash.NC_SF_RecordFaults.ptBootStatus[0].mBootImgType:1
TEST.END

-- Subprogram: NC_SF_SetTargetBitrate

-- Test Case: NC_SF_SetTargetBitrate.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetBitrate
TEST.NEW
TEST.NAME:NC_SF_SetTargetBitrate.001
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:55
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetBitrate.return:0
TEST.END

-- Test Case: NC_SF_SetTargetBitrate.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetBitrate
TEST.NEW
TEST.NAME:NC_SF_SetTargetBitrate.002
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.BitRate:55000000,46000000,41000000,36000000,31000000,26000000,21000000,16000000,11000000,6000000,2000000,600000,200000
TEST.VALUE:boot_sFlash.NC_SF_SetTargetBitrate.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetBitrate.return:50000000,45000000,40000000,35000000,30000000,25000000,20000000,15000000,10000000,5000000,1000000,500000,100000
TEST.END

-- Subprogram: NC_SF_SetTargetDivider

-- Test Case: NC_SF_SetTargetDivider.001
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetDivider
TEST.NEW
TEST.NAME:NC_SF_SetTargetDivider.001
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.BitRate:10
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.RefClk:100
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetDivider.return:10
TEST.END

-- Test Case: NC_SF_SetTargetDivider.002
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetDivider
TEST.NEW
TEST.NAME:NC_SF_SetTargetDivider.002
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.BitRate:15
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.RefClk:100
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetDivider.return:8
TEST.END

-- Test Case: NC_SF_SetTargetDivider.003
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetDivider
TEST.NEW
TEST.NAME:NC_SF_SetTargetDivider.003
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.BitRate:11
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.RefClk:100
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetDivider.return:10
TEST.END

-- Test Case: NC_SF_SetTargetDivider.004
TEST.UNIT:boot_sFlash
TEST.SUBPROGRAM:NC_SF_SetTargetDivider
TEST.NEW
TEST.NAME:NC_SF_SetTargetDivider.004
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.BitRate:4000000
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.RefClk:44000040
TEST.VALUE:boot_sFlash.NC_SF_SetTargetDivider.return:0
TEST.EXPECTED:boot_sFlash.NC_SF_SetTargetDivider.return:44
TEST.END
