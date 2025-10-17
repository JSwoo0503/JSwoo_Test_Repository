-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_ICU
-- Unit(s) Under Test: Drv_ICU
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: NC_ICU_GetPadInfo

-- Test Case: NC_ICU_GetPadInfo.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.001
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:6
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:6
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:-2
TEST.END

-- Test Case: NC_ICU_GetPadInfo.002
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.002
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:0,3
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0..5]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:0,3
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:6
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:63
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[1]:64
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[2]:65
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[3]:66
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[4]:67
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[5]:68
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.END

-- Test Case: NC_ICU_GetPadInfo.003
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.003
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:1
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0..11]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:1
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:1
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:12
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:70
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[1]:79
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[2]:80
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[3]:81
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[4]:82
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[5]:83
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[6]:84
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[7]:85
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[8]:86
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[9]:87
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[10]:88
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[11]:89
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.END

-- Test Case: NC_ICU_GetPadInfo.004
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.004
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:2
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0..8]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:2
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:2
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:9
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:69
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[1]:71
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[2]:72
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[3]:73
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[4]:74
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[5]:75
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[6]:76
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[7]:77
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[8]:78
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.END

-- Test Case: NC_ICU_GetPadInfo.005
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.005
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:5
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0..1]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:5
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:5
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:2
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:9
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[1]:10
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.END

-- Test Case: NC_ICU_GetPadInfo.006
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_GetPadInfo
TEST.NEW
TEST.NAME:NC_ICU_GetPadInfo.006
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:4
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:4
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0]:0
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.END

-- Subprogram: NC_ICU_Initialize

-- Test Case: NC_ICU_Initialize.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_Initialize
TEST.NEW
TEST.NAME:NC_ICU_Initialize.001
TEST.STUB:Drv_ICU.NC_ICU_SetPinMode
TEST.STUB:Drv_ICU.NC_ICU_GetPadInfo
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrength
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mPAD_ID[0..5]:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mCount:6
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[0]:63
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[1]:64
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[2]:65
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[3]:66
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[4]:67
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo[0].mPAD_ID[5]:68
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:2
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tImage.mDriveStrength:2
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tStrap.Bit.mBootMemory:0
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootStatus:<<malloc 1>>
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:0
TEST.EXPECTED:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:2
TEST.EXPECTED:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tImage.mDriveStrength:2
TEST.EXPECTED:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tStrap.Bit.mBootMemory:0
TEST.END

-- Test Case: NC_ICU_Initialize.002
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_Initialize
TEST.NEW
TEST.NAME:NC_ICU_Initialize.002
TEST.STUB:Drv_ICU.NC_ICU_SetPinMode
TEST.STUB:Drv_ICU.NC_ICU_GetPadInfo
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:6
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mBootDevice:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.ptPadInfo[0].mCount:0
TEST.VALUE:Drv_ICU.NC_ICU_GetPadInfo.return:-2
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tImage.mDriveStrength:2
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tStrap.Bit.mBootMemory:6
TEST.VALUE:Drv_ICU.NC_ICU_Initialize.ptBootStatus:<<malloc 1>>
TEST.EXPECTED:Drv_ICU.NC_ICU_GetPadInfo.BootDevice:6
TEST.EXPECTED:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tImage.mDriveStrength:2
TEST.EXPECTED:Drv_ICU.NC_ICU_Initialize.ptBootInfo[0].tStrap.Bit.mBootMemory:6
TEST.END

-- Subprogram: NC_ICU_SetDriveStrength

-- Test Case: NC_ICU_SetDriveStrength.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.001
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:1
TEST.END

-- Test Case: NC_ICU_SetDriveStrength.002
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.002
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:2
TEST.END

-- Test Case: NC_ICU_SetDriveStrength.003
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.003
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:3
TEST.END

-- Test Case: NC_ICU_SetDriveStrength.004
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.004
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:4
TEST.END

-- Test Case: NC_ICU_SetDriveStrength.005
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.005
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:5
TEST.END

-- Test Case: NC_ICU_SetDriveStrength.006
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrength
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrength.006
TEST.STUB:Drv_ICU.NC_ICU_SetDriveStrengthPadControl
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrength.DriveStrength:0,6,7
TEST.END

-- Subprogram: NC_ICU_SetDriveStrengthPadControl

-- Test Case: NC_ICU_SetDriveStrengthPadControl.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetDriveStrengthPadControl
TEST.NEW
TEST.NAME:NC_ICU_SetDriveStrengthPadControl.001
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU:<<malloc 1>>
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[0].PAD_CTRL.Bit.DS0:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[0].PAD_CTRL.Bit.DS1:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[0].PAD_CTRL.Bit.DS2:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS0:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS1:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS2:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.ptPadInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.ptPadInfo[0].mCount:2
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.ptPadInfo[0].mPAD_ID[0]:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.ptPadInfo[0].mPAD_ID[1]:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS0:1
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS1:0
TEST.VALUE:Drv_ICU.NC_ICU_SetDriveStrengthPadControl.DS2:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[0].PAD_CTRL.Bit.DS0:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[0].PAD_CTRL.Bit.DS1:0
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS0:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS1:0
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_PAD_CTRL[1].PAD_CTRL.Bit.DS2:1
TEST.END

-- Subprogram: NC_ICU_SetPinLevel

-- Test Case: NC_ICU_SetPinLevel.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetPinLevel
TEST.NEW
TEST.NAME:NC_ICU_SetPinLevel.001
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU:<<malloc 1>>
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OE.Reg:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OUT.Reg:0xFF
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:4
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Level:0
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OE.Reg:16
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OUT.Reg:0xEF
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:4
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Level:0
TEST.END

-- Test Case: NC_ICU_SetPinLevel.002
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetPinLevel
TEST.NEW
TEST.NAME:NC_ICU_SetPinLevel.002
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU:<<malloc 1>>
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[3].GPIO_OE.Reg:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[3].GPIO_OUT.Reg:0xFF
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:10
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Level:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[3].GPIO_OE.Reg:256
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[3].GPIO_OUT.Reg:0x1FF
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:10
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Level:1
TEST.ATTRIBUTES:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OUT.Reg:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: NC_ICU_SetPinLevel.003
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetPinLevel
TEST.NEW
TEST.NAME:NC_ICU_SetPinLevel.003
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU:<<malloc 1>>
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[1].GPIO_OE.Reg:0
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[1].GPIO_OUT.Reg:0
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:38
TEST.VALUE:Drv_ICU.NC_ICU_SetPinLevel.Level:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[1].GPIO_OE.Reg:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[1].GPIO_OUT.Reg:1
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Pad_ID:38
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinLevel.Level:1
TEST.ATTRIBUTES:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[0].GPIO_OUT.Reg:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].ICU_GPIO[3].GPIO_OUT.Reg:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: NC_ICU_SetPinMode

-- Test Case: NC_ICU_SetPinMode.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetPinMode
TEST.NEW
TEST.NAME:NC_ICU_SetPinMode.001
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU:<<malloc 1>>
TEST.VALUE:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].REG_TMUX_1000.Reg:1
TEST.VALUE:Drv_ICU.NC_ICU_SetPinMode.Pad_ID:7
TEST.VALUE:Drv_ICU.NC_ICU_SetPinMode.Func:1
TEST.EXPECTED:Drv_ICU.<<GLOBAL>>.RegA6_ICU[0].REG_TMUX_1000.Reg:1
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinMode.Pad_ID:7
TEST.EXPECTED:Drv_ICU.NC_ICU_SetPinMode.Func:1
TEST.END

-- Subprogram: NC_ICU_SetPinMux

-- Test Case: NC_ICU_SetPinMux.001
TEST.UNIT:Drv_ICU
TEST.SUBPROGRAM:NC_ICU_SetPinMux
TEST.NEW
TEST.NAME:NC_ICU_SetPinMux.001
TEST.STUB:Drv_ICU.NC_ICU_SetPinMode
TEST.VALUE:Drv_ICU.NC_ICU_SetPinMux.ptBootInfo:<<malloc 1>>
TEST.VALUE:Drv_ICU.NC_ICU_SetPinMux.ptBootInfo[0].tStrap.Bit.mBootMemory:0,1,5,2,3
TEST.END
