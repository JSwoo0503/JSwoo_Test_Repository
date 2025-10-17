-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_MAIN
-- Unit(s) Under Test: main
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Test Case: NC_GetBootInfo.001
TEST.UNIT:main
TEST.SUBPROGRAM:NC_GetBootInfo
TEST.NEW
TEST.NAME:NC_GetBootInfo.001
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tImage.mSecuMode:1
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tStrap.Bit.mBootMemory:0x2
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus[0].mBootDone_Res:0
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:0
TEST.EXPECTED:main.NC_GetBootInfo.return:0x2
TEST.END

-- Test Case: NC_GetBootInfo.002
TEST.UNIT:main
TEST.SUBPROGRAM:NC_GetBootInfo
TEST.NEW
TEST.NAME:NC_GetBootInfo.002
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tImage.mSecuMode:1
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tStrap.Bit.mBootMemory:0x2
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus[0].mBootDone_Res:0
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:2
TEST.VALUE:main.NC_GetBootInfo.return:0
TEST.EXPECTED:main.NC_GetBootInfo.return:0x1
TEST.END

-- Test Case: NC_GetBootInfo.003
TEST.UNIT:main
TEST.SUBPROGRAM:NC_GetBootInfo
TEST.NEW
TEST.NAME:NC_GetBootInfo.003
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tImage.mSecuMode:1
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tStrap.Bit.mBootMemory:0x2
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus[0].mBootDone_Res:0
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:3
TEST.VALUE:main.NC_GetBootInfo.return:0
TEST.EXPECTED:main.NC_GetBootInfo.return:0x0
TEST.END

-- Test Case: NC_GetBootInfo.004
TEST.UNIT:main
TEST.SUBPROGRAM:NC_GetBootInfo
TEST.NEW
TEST.NAME:NC_GetBootInfo.004
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tImage.mSecuMode:1
TEST.VALUE:main.NC_GetBootInfo.ptBootInfo[0].tStrap.Bit.mBootMemory:0x2
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus:<<malloc 1>>
TEST.VALUE:main.NC_GetBootInfo.ptBootStatus[0].mBootDone_Res:0
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:0
TEST.VALUE:main.NC_GetBootInfo.return:0
TEST.EXPECTED:main.NC_GetBootInfo.return:0x0
TEST.END

-- Subprogram: main

-- Test Case: main.001
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.001
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:1
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_eMMC.return:0
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:0
TEST.EXPECTED:main.main.return:0
TEST.END

-- Test Case: main.002
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.002
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:2
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_SD.return:0
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.VALUE:uut_prototype_stubs.NC_Secure_Boot.return:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x4000
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:0
TEST.EXPECTED:main.main.return:0
TEST.END

-- Test Case: main.003
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.003
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:2
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_SD.return:-1
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.VALUE:uut_prototype_stubs.NC_Secure_Boot.return:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x4000
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.EXPECTED:main.main.return:-1
TEST.END

-- Test Case: main.004
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.004
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:4
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_UART.return:0
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.VALUE:uut_prototype_stubs.NC_Secure_Boot.return:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.EXPECTED:main.main.return:0
TEST.END

-- Test Case: main.005
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.005
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:5
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_USB.return:0
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.VALUE:uut_prototype_stubs.NC_Secure_Boot.return:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.EXPECTED:main.main.return:0
TEST.END

-- Test Case: main.006
TEST.UNIT:main
TEST.SUBPROGRAM:main
TEST.NEW
TEST.NAME:main.006
TEST.STUB:main.NC_GetBootInfo
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.VALUE:main.NC_GetBootInfo.GetInfoId:1
TEST.VALUE:main.NC_GetBootInfo.return:0
TEST.VALUE:main.main.return:0
TEST.VALUE:uut_prototype_stubs.NC_Boot_sFlash.return:0
TEST.VALUE:uut_prototype_stubs.NC_SM_Initialize.Val:0
TEST.VALUE:uut_prototype_stubs.NC_Secure_Boot.return:0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_CPU_SCU[0].CPU_SCU_DEBUG15.Reg:0x0
TEST.EXPECTED:main.<<GLOBAL>>.RegA6_SYS_SCU[0].BUS_S_TZPROT.Bit.BUS_S_TZPROT_6:1
TEST.EXPECTED:main.main.return:0
TEST.END
