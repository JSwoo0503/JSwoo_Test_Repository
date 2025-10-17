-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_OTP
-- Unit(s) Under Test: Drv_OTP
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: NC_GetDBG_OTP_Config

-- Test Case: NC_GetDBG_OTP_Config.001
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_GetDBG_OTP_Config
TEST.NEW
TEST.NAME:NC_GetDBG_OTP_Config.001
TEST.VALUE:Drv_OTP.NC_GetDBG_OTP_Config.Index:1
TEST.VALUE:Drv_OTP.NC_GetDBG_OTP_Config.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE[0].SE__DBG06.Reg:2
TEST.EXPECTED:Drv_OTP.NC_GetDBG_OTP_Config.return:2
TEST.END

-- Test Case: NC_GetDBG_OTP_Config.002
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_GetDBG_OTP_Config
TEST.NEW
TEST.NAME:NC_GetDBG_OTP_Config.002
TEST.VALUE:Drv_OTP.NC_GetDBG_OTP_Config.Index:2
TEST.VALUE:Drv_OTP.NC_GetDBG_OTP_Config.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG14.Reg:4
TEST.EXPECTED:Drv_OTP.NC_GetDBG_OTP_Config.return:4
TEST.END

-- Subprogram: NC_Get_Firmware_Backup_Offset

-- Test Case: NC_Get_Firmware_Backup_Offset.001
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_Get_Firmware_Backup_Offset
TEST.NEW
TEST.NAME:NC_Get_Firmware_Backup_Offset.001
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].BOOT_CFG.Reg:0x10
TEST.VALUE:Drv_OTP.NC_Get_Firmware_Backup_Offset.return:0
TEST.EXPECTED:Drv_OTP.NC_Get_Firmware_Backup_Offset.return:0
TEST.END

-- Test Case: NC_Get_Firmware_Backup_Offset.002
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_Get_Firmware_Backup_Offset
TEST.NEW
TEST.NAME:NC_Get_Firmware_Backup_Offset.002
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].BOOT_CFG.Reg:0x20000000
TEST.VALUE:Drv_OTP.NC_Get_Firmware_Backup_Offset.return:0
TEST.EXPECTED:Drv_OTP.NC_Get_Firmware_Backup_Offset.return:65536
TEST.END

-- Subprogram: NC_OTP_Config

-- Test Case: NC_OTP_Config.001
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_OTP_Config
TEST.NEW
TEST.NAME:NC_OTP_Config.001
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].BOOT_CFG.Reg:0
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].UDF.Reg:0
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].OTP_INT_STATUS.Reg:0x2
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG[0].OTP_PRE_SENSING_STATE.Reg:2
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU[0].ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET:1
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootStatus:<<malloc 1>>
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootStatus[0].mOtpRes:0
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:1
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].OTP_INT_STATUS.Reg:0xFFFFFFFF
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG[0].OTP_PRE_SENSING_STATE.Reg:0
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU[0].ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootStatus[0].mOtpRes:2
TEST.END

-- Test Case: NC_OTP_Config.002
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_OTP_Config
TEST.NEW
TEST.NAME:NC_OTP_Config.002
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].BOOT_CFG.Reg:1
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].UDF.Reg:1
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].OTP_INT_STATUS.Reg:0x2
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG[0].OTP_PRE_SENSING_STATE.Reg:7
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU[0].ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET:1
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo:<<malloc 1>>
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mCtrlMode:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFlashType:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mDriveStrength:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSpiRxDelay:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mKeyStorage:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFlashAddr[1]:0
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootStatus:<<malloc 1>>
TEST.VALUE:Drv_OTP.NC_OTP_Config.ptBootStatus[0].mOtpRes:0
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:1
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_OTP[0].OTP_INT_STATUS.Reg:0xFFFFFFFF
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_ANALOG[0].OTP_PRE_SENSING_STATE.Reg:0
TEST.EXPECTED:Drv_OTP.<<GLOBAL>>.RegA6_SYS_SCU[0].ONGO_RST_ACT_4.Bit.ONGO_RST_ACT_CMRT_PRESET:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mCtrlMode:1
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFlashType:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mDriveStrength:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mQspiClockDiv:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mQspiDummyCycle:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSpiRxDelay:1
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSpiClockPolarityPhase:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUartBaudrate:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUsbRefClock:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSecuMode:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mSafetyMode:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mKeyStorage:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mUseKeyCmrt:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootInfo[0].tImage.mFlashAddr[1]:0
TEST.EXPECTED:Drv_OTP.NC_OTP_Config.ptBootStatus[0].mOtpRes:0
TEST.END

-- Subprogram: NC_SetDBG_OTP_Config

-- Test Case: NC_SetDBG_OTP_Config.001
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_SetDBG_OTP_Config
TEST.NEW
TEST.NAME:NC_SetDBG_OTP_Config.001
TEST.VALUE:Drv_OTP.NC_SetDBG_OTP_Config.Index:1
TEST.VALUE:Drv_OTP.NC_SetDBG_OTP_Config.OtpConfig:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE[0].SE__DBG06.Reg:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE[0].SE__DBG06.Reg:2
TEST.END

-- Test Case: NC_SetDBG_OTP_Config.002
TEST.UNIT:Drv_OTP
TEST.SUBPROGRAM:NC_SetDBG_OTP_Config
TEST.NEW
TEST.NAME:NC_SetDBG_OTP_Config.002
TEST.VALUE:Drv_OTP.NC_SetDBG_OTP_Config.Index:2
TEST.VALUE:Drv_OTP.NC_SetDBG_OTP_Config.OtpConfig:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG14.Reg:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG14.Reg:3
TEST.END
