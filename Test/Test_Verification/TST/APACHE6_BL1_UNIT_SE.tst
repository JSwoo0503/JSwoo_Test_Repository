-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_SE
-- Unit(s) Under Test: safety_engine
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: NC_SE_Initialize

-- Test Case: NC_SE_Initialize.001
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_Initialize
TEST.NEW
TEST.NAME:NC_SE_Initialize.001
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:1
TEST.END

-- Test Case: NC_SE_Initialize.002
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_Initialize
TEST.NEW
TEST.NAME:NC_SE_Initialize.002
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:2
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:4294967295
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:2
TEST.END

-- Test Case: NC_SE_Initialize.003
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_Initialize
TEST.NEW
TEST.NAME:NC_SE_Initialize.003
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:4294967295
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:1
TEST.END

-- Test Case: NC_SE_Initialize.004
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_Initialize
TEST.NEW
TEST.NAME:NC_SE_Initialize.004
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__OP_STAT.Bit.OP_CURR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootStatus[0].mSafetyModeRes:0
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:4294967295
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootStatus[0].mSafetyModeRes:1
TEST.END

-- Test Case: NC_SE_Initialize.005
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_Initialize
TEST.NEW
TEST.NAME:NC_SE_Initialize.005
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__OP_STAT.Bit.OP_CURR:1
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_Initialize.ptBootStatus[0].mSafetyModeRes:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM0_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM1_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM2_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_RAM3_DED_ERROR:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM0:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SECURE__FT__MASK.Bit.RT640_SAFETY_ALARM1:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.SAFE_OE:0
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__HW__FT__MASK.Bit.BLK_SECURE:1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:4294967295
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mSafetyMode:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootInfo[0].tImage.mFaultCpuReset:0
TEST.EXPECTED:safety_engine.NC_SE_Initialize.ptBootStatus[0].mSafetyModeRes:0
TEST.END

-- Subprogram: NC_SE_NotifyFailure

-- Test Case: NC_SE_NotifyFailure.001
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_NotifyFailure
TEST.NEW
TEST.NAME:NC_SE_NotifyFailure.001
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_NotifyFailure.Type:0,1
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:3
TEST.EXPECTED:safety_engine.NC_SE_NotifyFailure.Type:0,1
TEST.END

-- Test Case: NC_SE_NotifyFailure.002
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_NotifyFailure
TEST.NEW
TEST.NAME:NC_SE_NotifyFailure.002
TEST.VALUE:safety_engine.NC_SE_NotifyFailure.Type:33
TEST.END

-- Test Case: NC_SE_NotifyFailure.003
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_NotifyFailure
TEST.NEW
TEST.NAME:NC_SE_NotifyFailure.003
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__MODE.Bit.EN:1
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:0
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:0
TEST.VALUE:safety_engine.NC_SE_NotifyFailure.Type:10
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:1024
TEST.EXPECTED:safety_engine.<<GLOBAL>>.RegA6_SE[0].SE__SW__FT__MASK.Bit.SE__FT__MASK:1024
TEST.END

-- Subprogram: NC_SE_SetFaultInfo

-- Test Case: NC_SE_SetFaultInfo.001
TEST.UNIT:safety_engine
TEST.SUBPROGRAM:NC_SE_SetFaultInfo
TEST.NEW
TEST.NAME:NC_SE_SetFaultInfo.001
TEST.VALUE:safety_engine.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:safety_engine.NC_SE_SetFaultInfo.Type:0
TEST.EXPECTED:safety_engine.NC_SE_SetFaultInfo.Type:0
TEST.END
