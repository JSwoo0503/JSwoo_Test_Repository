-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_SB
-- Unit(s) Under Test: rt640_hlos rt640_interface secure_boot
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: rt640_hlos

-- Subprogram: NC_SB_BringUp

-- Test Case: NC_SB_BringUp.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_BringUp
TEST.NEW
TEST.NAME:NC_SB_BringUp.001
TEST.STUB:rt640_hlos.NC_SB_CPU_Sram_Check
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:8
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xF111
TEST.EXPECTED:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.END

-- Test Case: NC_SB_BringUp.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_BringUp
TEST.NEW
TEST.NAME:NC_SB_BringUp.002
TEST.STUB:rt640_hlos.NC_SB_CPU_Sram_Check
TEST.STUB:rt640_hlos.NC_SB_Check_SW_Boot_Status
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].mSecureRunRes:2
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:2
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:8
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xF111
TEST.EXPECTED:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.END

-- Test Case: NC_SB_BringUp.003
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_BringUp
TEST.NEW
TEST.NAME:NC_SB_BringUp.003
TEST.STUB:rt640_hlos.NC_SB_CPU_Sram_Check
TEST.STUB:rt640_hlos.NC_SB_Check_SW_Boot_Status
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].mSecureRunRes:0,3
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:2,3
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:8
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xF111
TEST.EXPECTED:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.END

-- Test Case: NC_SB_BringUp.004
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_BringUp
TEST.NEW
TEST.NAME:NC_SB_BringUp.004
TEST.STUB:rt640_hlos.NC_SB_CPU_Sram_Check
TEST.STUB:rt640_hlos.NC_SB_Check_SW_Boot_Status
TEST.STUB:rt640_hlos.NC_SB_Check_Scratch_Reg
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:7
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:2,3
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:7
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:8
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xF111
TEST.EXPECTED:rt640_hlos.NC_SB_BringUp.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0xC111
TEST.END

-- Subprogram: NC_SB_CMRT_IORead32

-- Test Case: NC_SB_CMRT_IORead32.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_CMRT_IORead32
TEST.NEW
TEST.NAME:NC_SB_CMRT_IORead32.001
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:5
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_CMRT_IORead32.return:5
TEST.END

-- Subprogram: NC_SB_CMRT_IOWrite32

-- Test Case: NC_SB_CMRT_IOWrite32.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_CMRT_IOWrite32
TEST.NEW
TEST.NAME:NC_SB_CMRT_IOWrite32.001
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:5
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:0
TEST.EXPECTED:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:5
TEST.END

-- Subprogram: NC_SB_CPU_Sram_Check

-- Test Case: NC_SB_CPU_Sram_Check.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_CPU_Sram_Check
TEST.NEW
TEST.NAME:NC_SB_CPU_Sram_Check.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:5
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0x0,0x10
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x0
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:0x140000
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:17
TEST.EXPECTED:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:1
TEST.END

-- Test Case: NC_SB_CPU_Sram_Check.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_CPU_Sram_Check
TEST.NEW
TEST.NAME:NC_SB_CPU_Sram_Check.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Hold_Reset
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:5
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0x30,0x20
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:100
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:100
TEST.EXPECTED:rt640_hlos.NC_SB_CPU_Sram_Check.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:100
TEST.END

-- Subprogram: NC_SB_Check_CMRT_Reg

-- Test Case: NC_SB_Check_CMRT_Reg.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_Check_CMRT_Reg.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:1
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:0x140000
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:21
TEST.END

-- Test Case: NC_SB_Check_CMRT_Reg.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_Check_CMRT_Reg.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:1,0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:7
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:1
TEST.END

-- Test Case: NC_SB_Check_CMRT_Reg.003
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_Check_CMRT_Reg.003
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:7
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:2
TEST.END

-- Subprogram: NC_SB_Check_SW_Boot_Status

-- Test Case: NC_SB_Check_SW_Boot_Status.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_SW_Boot_Status
TEST.NEW
TEST.NAME:NC_SB_Check_SW_Boot_Status.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0xC0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:2
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:0x140000
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.EXPECTED:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].mSecureRunRes:0x3
TEST.END

-- Test Case: NC_SB_Check_SW_Boot_Status.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_SW_Boot_Status
TEST.NEW
TEST.NAME:NC_SB_Check_SW_Boot_Status.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0x0,0x3F
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:3
TEST.END

-- Test Case: NC_SB_Check_SW_Boot_Status.003
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_SW_Boot_Status
TEST.NEW
TEST.NAME:NC_SB_Check_SW_Boot_Status.003
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:0
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0x0
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_Check_SW_Boot_Status.Step:4
TEST.END

-- Subprogram: NC_SB_Check_Scratch_Reg

-- Test Case: NC_SB_Check_Scratch_Reg.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_Scratch_Reg
TEST.NEW
TEST.NAME:NC_SB_Check_Scratch_Reg.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0xFEEDBEE0
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x0
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:0x140000
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:0x14
TEST.EXPECTED:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].mSecureRunRes:0x9
TEST.ATTRIBUTES:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:INPUT_BASE=16
TEST.END

-- Test Case: NC_SB_Check_Scratch_Reg.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Check_Scratch_Reg
TEST.NEW
TEST.NAME:NC_SB_Check_Scratch_Reg.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0xFEEDBEE0,0xFEEDBEE3
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.EXPECTED:rt640_hlos.NC_SB_Check_Scratch_Reg.ptBootStatus[0].mSecureRunRes:0x1
TEST.ATTRIBUTES:rt640_hlos.NC_SB_Check_SW_Boot_Status.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:INPUT_BASE=16
TEST.END

-- Subprogram: NC_SB_GetTimeOverCount

-- Test Case: NC_SB_GetTimeOverCount.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_GetTimeOverCount
TEST.NEW
TEST.NAME:NC_SB_GetTimeOverCount.001
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0xBEB0
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_GetTimeOverCount.return:0xBEB
TEST.ATTRIBUTES:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SB_GetTimeOverCount.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_GetTimeOverCount
TEST.NEW
TEST.NAME:NC_SB_GetTimeOverCount.002
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x0
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverCount.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_GetTimeOverCount.return:0x40
TEST.ATTRIBUTES:rt640_hlos.NC_SB_GetTimeOverCount.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:EXPECTED_BASE=16
TEST.END

-- Subprogram: NC_SB_GetTimeOverEnable

-- Test Case: NC_SB_GetTimeOverEnable.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_GetTimeOverEnable
TEST.NEW
TEST.NAME:NC_SB_GetTimeOverEnable.001
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverEnable.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverEnable.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverEnable.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0xA
TEST.VALUE:rt640_hlos.NC_SB_GetTimeOverEnable.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_GetTimeOverEnable.return:0xA
TEST.END

-- Subprogram: NC_SB_Hold_Reset

-- Test Case: NC_SB_Hold_Reset.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Hold_Reset
TEST.NEW
TEST.NAME:NC_SB_Hold_Reset.001
TEST.STUB:rt640_hlos.NC_SB_Wait_Cycles
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.count:5000
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0x3064
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:100
TEST.EXPECTED:rt640_hlos.NC_SB_Hold_Reset.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:0x3064
TEST.END

-- Subprogram: NC_SB_Init_Param

-- Test Case: NC_SB_Init_Param.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Init_Param
TEST.NEW
TEST.NAME:NC_SB_Init_Param.001
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus[0].ptHandleBoot[0].tCMRT.pSCB_CONTROL[0]:100
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus[0].ptHandleBoot[0].tCMRT.pR_HLOS2ESW_D0:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Init_Param.ptBootStatus[0].ptHandleBoot[0].tCMRT.pR_HLOS2ESW_D0[0]:100
TEST.END

-- Subprogram: NC_SB_ReadByte_CMRT_Reg

-- Test Case: NC_SB_ReadByte_CMRT_Reg.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_ReadByte_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_ReadByte_CMRT_Reg.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:3
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.mSec:0x140000
TEST.VALUE:uut_prototype_stubs.NC_SCU_mTimeOut.return:0,1
TEST.VALUE:uut_prototype_stubs.NC_SE_SetFaultInfo.Type:23
TEST.EXPECTED:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0x40
TEST.END

-- Test Case: NC_SB_ReadByte_CMRT_Reg.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_ReadByte_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_ReadByte_CMRT_Reg.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0,1
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:4
TEST.ATTRIBUTES:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:EXPECTED_BASE=16
TEST.END

-- Test Case: NC_SB_ReadByte_CMRT_Reg.003
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_ReadByte_CMRT_Reg
TEST.NEW
TEST.NAME:NC_SB_ReadByte_CMRT_Reg.003
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:1
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].ptHandleBoot[0].tHeader.tBootSec.mSecureBootSize:0x7
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:0
TEST.ATTRIBUTES:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:EXPECTED_BASE=16
TEST.END

-- Subprogram: NC_SB_Request_Decrypt_Service

-- Test Case: NC_SB_Request_Decrypt_Service.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.001
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:100
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.END

-- Test Case: NC_SB_Request_Decrypt_Service.002
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.002
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.STUB:rt640_hlos.NC_SB_ReadByte_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:100
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0,1
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:3,4
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.END

-- Test Case: NC_SB_Request_Decrypt_Service.003
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.003
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:100
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0,1
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0,1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.END

-- Test Case: NC_SB_Request_Decrypt_Service.004
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.004
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.STUB:rt640_hlos.NC_SB_ReadByte_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:100
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:3
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.END

-- Test Case: NC_SB_Request_Decrypt_Service.005
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.005
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.STUB:rt640_hlos.NC_SB_ReadByte_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:100
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:3,4
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.END

-- Test Case: NC_SB_Request_Decrypt_Service.006
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Request_Decrypt_Service
TEST.NEW
TEST.NAME:NC_SB_Request_Decrypt_Service.006
TEST.STUB:rt640_hlos.NC_SB_CMRT_IOWrite32
TEST.STUB:rt640_hlos.NC_SB_CMRT_IORead32
TEST.STUB:rt640_hlos.NC_SB_Check_CMRT_Reg
TEST.STUB:rt640_hlos.NC_SB_ReadByte_CMRT_Reg
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.v:983040,100
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IOWrite32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.r[0]:50
TEST.VALUE:rt640_hlos.NC_SB_CMRT_IORead32.return:0x1,0x0,0x1,0xA,0x59414B4F
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Check_CMRT_Reg.readType:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_ReadByte_CMRT_Reg.readType:3,4
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x1000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:32
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.EXPECTED:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.END

-- Subprogram: NC_SB_Wait_Cycles

-- Test Case: NC_SB_Wait_Cycles.001
TEST.UNIT:rt640_hlos
TEST.SUBPROGRAM:NC_SB_Wait_Cycles
TEST.NEW
TEST.NAME:NC_SB_Wait_Cycles.001
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.count:0
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:rt640_hlos.NC_SB_Wait_Cycles.ptBootStatus[0].ptHandleBoot[0].tClock.mCMRT:1
TEST.VALUE:uut_prototype_stubs.NC_SCU_GetTick.Cls:0
TEST.VALUE:uut_prototype_stubs.NC_SCU_GetTick.return:100,50,200
TEST.END

-- Unit: rt640_interface

-- Subprogram: NC_SB_CMRT_Initialize

-- Test Case: NC_SB_CMRT_Initialize.001
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Initialize
TEST.NEW
TEST.NAME:NC_SB_CMRT_Initialize.001
TEST.STUB:rt640_hlos.NC_SB_Init_Param
TEST.STUB:rt640_hlos.NC_SB_Hold_Reset
TEST.STUB:rt640_hlos.NC_SB_BringUp
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.os_with_user_container_img:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.ptBootStatus[0].mSecureRunRes:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Initialize.return:-1
TEST.END

-- Test Case: NC_SB_CMRT_Initialize.002
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Initialize
TEST.NEW
TEST.NAME:NC_SB_CMRT_Initialize.002
TEST.STUB:rt640_hlos.NC_SB_Init_Param
TEST.STUB:rt640_hlos.NC_SB_Hold_Reset
TEST.STUB:rt640_hlos.NC_SB_BringUp
TEST.VALUE:rt640_hlos.NC_SB_BringUp.os_with_user_container_img:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.os_with_user_container_img:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.ptBootStatus[0].mSecureRunRes:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Initialize.return:0
TEST.END

-- Subprogram: NC_SB_CMRT_Secure_Run

-- Test Case: NC_SB_CMRT_Secure_Run.001
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Secure_Run
TEST.NEW
TEST.NAME:NC_SB_CMRT_Secure_Run.001
TEST.STUB:rt640_hlos.NC_SB_Request_Decrypt_Service
TEST.STUB:rt640_interface.NC_SB_CMRT_Swap
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x10000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:0x10AFF40
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_0.Reg:123
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_1.Reg:456
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_2.Reg:789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[0]:123,456,789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.nSize:32
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.Addr:0x10000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KEY_STORAGE:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KeySplitNum:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.DiversifyPath:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.END

-- Test Case: NC_SB_CMRT_Secure_Run.002
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Secure_Run
TEST.NEW
TEST.NAME:NC_SB_CMRT_Secure_Run.002
TEST.STUB:rt640_hlos.NC_SB_Request_Decrypt_Service
TEST.STUB:rt640_interface.NC_SB_CMRT_Swap
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x10000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:0x10AFF40
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:-1
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_0.Reg:123
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_1.Reg:456
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_2.Reg:789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[0]:123,456,789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.nSize:32
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.Addr:0x10000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KEY_STORAGE:2
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KeySplitNum:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.DiversifyPath:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Secure_Run.return:-1
TEST.END

-- Test Case: NC_SB_CMRT_Secure_Run.003
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Secure_Run
TEST.NEW
TEST.NAME:NC_SB_CMRT_Secure_Run.003
TEST.STUB:rt640_hlos.NC_SB_Request_Decrypt_Service
TEST.STUB:rt640_interface.NC_SB_CMRT_Swap
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x10000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:0x10AFF40
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_0.Reg:123
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_1.Reg:456
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_2.Reg:789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[0]:123,456,789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.nSize:32
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.Addr:0x10000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KEY_STORAGE:3
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KeySplitNum:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.DiversifyPath:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.END

-- Test Case: NC_SB_CMRT_Secure_Run.004
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Secure_Run
TEST.NEW
TEST.NAME:NC_SB_CMRT_Secure_Run.004
TEST.STUB:rt640_hlos.NC_SB_Request_Decrypt_Service
TEST.STUB:rt640_interface.NC_SB_CMRT_Swap
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.Addr:0x10000000
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.system_otp_base:0x10AFF40
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.KeySplitNum:0
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.DiversifyPath:1
TEST.VALUE:rt640_hlos.NC_SB_Request_Decrypt_Service.return:0
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP:<<malloc 1>>
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_0.Reg:123
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_1.Reg:456
TEST.VALUE:rt640_interface.<<GLOBAL>>.RegA6_OTP[0].OTP_KEY0_2.Reg:789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[0]:123,456,789
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.nSize:32
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.Addr:0x10000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KEY_STORAGE:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KeySplitNum:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.DiversifyPath:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.ptBootStatus:<<malloc 1>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.END

-- Subprogram: NC_SB_CMRT_Swap

-- Test Case: NC_SB_CMRT_Swap.001
TEST.UNIT:rt640_interface
TEST.SUBPROGRAM:NC_SB_CMRT_Swap
TEST.NEW
TEST.NAME:NC_SB_CMRT_Swap.001
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pDst:<<malloc 2>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pDst[0]:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pDst[1]:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc:<<malloc 2>>
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[0]:0x12345678
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.pSrc[1]:0x87654321
TEST.VALUE:rt640_interface.NC_SB_CMRT_Swap.nSize:8
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Swap.pDst[0]:0x78563412
TEST.EXPECTED:rt640_interface.NC_SB_CMRT_Swap.pDst[1]:0x21436587
TEST.END

-- Unit: secure_boot

-- Subprogram: NC_Secure_Boot

-- Test Case: NC_Secure_Boot.001
TEST.UNIT:secure_boot
TEST.SUBPROGRAM:NC_Secure_Boot
TEST.NEW
TEST.NAME:NC_Secure_Boot.001
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo:<<malloc 1>>
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mSecuMode:0
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootStatus:<<malloc 1>>
TEST.VALUE:secure_boot.NC_Secure_Boot.return:0
TEST.EXPECTED:secure_boot.NC_Secure_Boot.return:-1
TEST.END

-- Test Case: NC_Secure_Boot.002
TEST.UNIT:secure_boot
TEST.SUBPROGRAM:NC_Secure_Boot
TEST.NEW
TEST.NAME:NC_Secure_Boot.002
TEST.STUB:rt640_interface.NC_SB_CMRT_Initialize
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:15
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.os_with_user_container_img:0x30000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.return:-1
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo:<<malloc 1>>
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tHeader.tBootSec.mOsOffset:0x10000000
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mSecuMode:2
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mKeyStorage:1
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mDestAddr:0x20000000
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootStatus:<<malloc 1>>
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootStatus[0].mSecureRunRes:0x0
TEST.VALUE:secure_boot.NC_Secure_Boot.return:0
TEST.EXPECTED:secure_boot.NC_Secure_Boot.ptBootStatus[0].mSecureRunRes:0x30000
TEST.EXPECTED:secure_boot.NC_Secure_Boot.return:-1
TEST.END

-- Test Case: NC_Secure_Boot.003
TEST.UNIT:secure_boot
TEST.SUBPROGRAM:NC_Secure_Boot
TEST.NEW
TEST.NAME:NC_Secure_Boot.003
TEST.STUB:rt640_interface.NC_SB_CMRT_Initialize
TEST.STUB:rt640_interface.NC_SB_CMRT_Secure_Run
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:15
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.os_with_user_container_img:0x30000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Initialize.return:0
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.Addr:0x20000000
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KEY_STORAGE:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.KeySplitNum:2
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.DiversifyPath:1
TEST.VALUE:rt640_interface.NC_SB_CMRT_Secure_Run.return:0
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo:<<malloc 1>>
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tHeader.mLength:8
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tHeader.tBootKey.mKEYSPLIT.Reg:0x2
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tHeader.tBootKey.mDIVERSIFY_PATH:1
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tHeader.tBootSec.mOsOffset:0x10000000
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mSecuMode:2
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mKeyStorage:1
TEST.VALUE:secure_boot.NC_Secure_Boot.ptBootInfo[0].tImage.mDestAddr:0x20000000
TEST.VALUE:secure_boot.NC_Secure_Boot.return:0
TEST.EXPECTED:secure_boot.NC_Secure_Boot.return:0
TEST.ATTRIBUTES:secure_boot.NC_Secure_Boot.ptBootStatus[0].mSecureRunRes:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END
