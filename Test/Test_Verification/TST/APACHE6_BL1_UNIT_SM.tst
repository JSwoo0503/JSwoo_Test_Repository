-- VectorCAST 19.sp2 (09/10/19)
-- Test Case Script
-- 
-- Environment    : APACHE6_BL1_UNIT_SM
-- Unit(s) Under Test: seq_monitor
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: NC_SM_CheckFlow

-- Test Case: NC_SM_CheckFlow.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.001
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:42
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:42
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:-1
TEST.END

-- Test Case: NC_SM_CheckFlow.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.002
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0xFFFFF
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:19
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.ptBootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0xFFFFF
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:19
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:0
TEST.END

-- Test Case: NC_SM_CheckFlow.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.003
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:25
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:25
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:0
TEST.END

-- Test Case: NC_SM_CheckFlow.004
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.004
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:31
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:31
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:0
TEST.END

-- Test Case: NC_SM_CheckFlow.005
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.005
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:35
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:35
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:0
TEST.END

-- Test Case: NC_SM_CheckFlow.006
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.006
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:39,40
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:39,40
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:0
TEST.END

-- Test Case: NC_SM_CheckFlow.007
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.007
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.StepInfo:15
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:1
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.StepInfo:15
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:1
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:-1
TEST.END

-- Test Case: NC_SM_CheckFlow.008
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlow
TEST.NEW
TEST.NAME:NC_SM_CheckFlow.008
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.SNS_STEP:2
TEST.VALUE:seq_monitor.NC_SM_CheckFlow.return:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.SNS_STEP:2
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlow.return:-1
TEST.END

-- Subprogram: NC_SM_CheckFlowSecureStep

-- Test Case: NC_SM_CheckFlowSecureStep.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlowSecureStep
TEST.NEW
TEST.NAME:NC_SM_CheckFlowSecureStep.001
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep:<<null>>
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.return:-1
TEST.END

-- Test Case: NC_SM_CheckFlowSecureStep.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlowSecureStep
TEST.NEW
TEST.NAME:NC_SM_CheckFlowSecureStep.002
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.StepInfo:16
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.return:-1
TEST.END

-- Test Case: NC_SM_CheckFlowSecureStep.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlowSecureStep
TEST.NEW
TEST.NAME:NC_SM_CheckFlowSecureStep.003
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.StepInfo:10
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep[0].Step1:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Reg:0
TEST.VALUE:uut_prototype_stubs.NC_SE_NotifyFailure.Type:25
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep[0].Step1:0x7FF
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.END

-- Test Case: NC_SM_CheckFlowSecureStep.004
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_CheckFlowSecureStep
TEST.NEW
TEST.NAME:NC_SM_CheckFlowSecureStep.004
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.StepInfo:10
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep[0].Step1:0
TEST.VALUE:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Reg:0x7FF
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.pBundleStep[0].Step1:0x7FF
TEST.EXPECTED:seq_monitor.NC_SM_CheckFlowSecureStep.return:0
TEST.END

-- Subprogram: NC_SM_GetGoldenBootStep

-- Test Case: NC_SM_GetGoldenBootStep.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetGoldenBootStep
TEST.NEW
TEST.NAME:NC_SM_GetGoldenBootStep.001
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:30
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:4
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].ptWS_BootStatus:<<malloc 3>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:(2)0x0
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:30,10
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:30
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:4
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:0x7FFFFFFF,0x0
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:30,10
TEST.END

-- Test Case: NC_SM_GetGoldenBootStep.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetGoldenBootStep
TEST.NEW
TEST.NAME:NC_SM_GetGoldenBootStep.002
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:1,3
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:5,6
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:(2)0
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:2
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.MIN_STEP:1
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:1,3
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:5,6
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:0x3FFF,0x0
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:2
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.MIN_STEP:1
TEST.END

-- Test Case: NC_SM_GetGoldenBootStep.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetGoldenBootStep
TEST.NEW
TEST.NAME:NC_SM_GetGoldenBootStep.003
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:0,33,34
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:7,8
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:0x3FFF
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step2:0,3
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:33
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.MIN_STEP:32
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:0,33,34
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:7,8
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step1:0x3FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptBundleStep[0].Step2:0,3
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.MAX_STEP:33
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.MIN_STEP:32
TEST.END

-- Test Case: NC_SM_GetGoldenBootStep.004
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetGoldenBootStep
TEST.NEW
TEST.NAME:NC_SM_GetGoldenBootStep.004
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:41,42
TEST.VALUE:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:9
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_StepInfo:41,42
TEST.EXPECTED:seq_monitor.NC_SM_GetGoldenBootStep.ptWS_StepInfo[0].WS_Stage:9
TEST.END

-- Subprogram: NC_SM_GetLastBootStep

-- Test Case: NC_SM_GetLastBootStep.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.001
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:1
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:0xFFFFF
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:1
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:0xFFFFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x100,0x0
TEST.END

-- Test Case: NC_SM_GetLastBootStep.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.002
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:2
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0x0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:2
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0x3F03FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x100,0x0
TEST.END

-- Test Case: NC_SM_GetLastBootStep.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.003
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:3
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:3
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0xFC003FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x100,0x0
TEST.END

-- Test Case: NC_SM_GetLastBootStep.004
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.004
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:4
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:4
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0x3FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x10F,0xF
TEST.END

-- Test Case: NC_SM_GetLastBootStep.005
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.005
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:5
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:5
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0x3FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x1F0,0xF0
TEST.END

-- Test Case: NC_SM_GetLastBootStep.006
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetLastBootStep
TEST.NEW
TEST.NAME:NC_SM_GetLastBootStep.006
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:(2)0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].WS_StepInfo:40,39
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.ptStepInfo[0].ptWS_BootStatus[0].ptHandleBoot[0].tStrap.Bit.mBootMemory:0
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep1[0]:(2)0xFC003FFF
TEST.EXPECTED:seq_monitor.NC_SM_GetLastBootStep.pResStep2[0]:0x100,0x0
TEST.END

-- Subprogram: NC_SM_GetMediaRetryCnt

-- Test Case: NC_SM_GetMediaRetryCnt.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetMediaRetryCnt
TEST.NEW
TEST.NAME:NC_SM_GetMediaRetryCnt.001
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Reg:0x10000
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.InterfaceId:1
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.return:0
TEST.EXPECTED:seq_monitor.NC_SM_GetMediaRetryCnt.return:1
TEST.END

-- Test Case: NC_SM_GetMediaRetryCnt.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_GetMediaRetryCnt
TEST.NEW
TEST.NAME:NC_SM_GetMediaRetryCnt.002
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Reg:0x3000000
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.InterfaceId:0
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.return:0
TEST.EXPECTED:seq_monitor.NC_SM_GetMediaRetryCnt.return:3
TEST.END

-- Subprogram: NC_SM_Initialize

-- Test Case: NC_SM_Initialize.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_Initialize
TEST.NEW
TEST.NAME:NC_SM_Initialize.001
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG00.Bit.SE__DBG00:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Bit.SE__DBG03:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG04.Bit.SE__DBG04:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG05.Bit.SE__DBG05:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG06.Bit.SE__DBG06:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG07.Bit.SE__DBG07:0
TEST.VALUE:seq_monitor.NC_SM_Initialize.Val:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG00.Bit.SE__DBG00:0x1010005
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Bit.SE__DBG03:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG04.Bit.SE__DBG04:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG05.Bit.SE__DBG05:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG06.Bit.SE__DBG06:0
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG07.Bit.SE__DBG07:0
TEST.EXPECTED:seq_monitor.NC_SM_Initialize.Val:0
TEST.END

-- Subprogram: NC_SM_SetBOOT_Result

-- Test Case: NC_SM_SetBOOT_Result.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_Result
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_Result.001
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.Ret:0
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus[0].mBootDone_Res:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Result.Ret:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus[0].mBootDone_Res:1
TEST.END

-- Test Case: NC_SM_SetBOOT_Result.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_Result
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_Result.002
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.Ret:1
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus[0].mBootDone_Res:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Result.Ret:1
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Result.ptBootStatus[0].mBootDone_Res:0
TEST.END

-- Subprogram: NC_SM_SetBOOT_SecureStep

-- Test Case: NC_SM_SetBOOT_SecureStep.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_SecureStep
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_SecureStep.001
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:0
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_SecureStep.StepInfo:16
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_SecureStep.StepInfo:16
TEST.END

-- Test Case: NC_SM_SetBOOT_SecureStep.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_SecureStep
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_SecureStep.002
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Bit.SE__DBG03:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:1
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_SecureStep.StepInfo:1
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG03.Bit.SE__DBG03:2
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:1
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_SecureStep.StepInfo:1
TEST.END

-- Subprogram: NC_SM_SetBOOT_Step

-- Test Case: NC_SM_SetBOOT_Step.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_Step
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_Step.001
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:0
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:31
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG01.Bit.SE__DBG01:0x80000000
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:31
TEST.END

-- Test Case: NC_SM_SetBOOT_Step.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_Step
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_Step.002
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE:<<malloc 1>>
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:0
TEST.VALUE:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:1
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:32
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__DBG02.Bit.SE__DBG02:1
TEST.EXPECTED:seq_monitor.<<GLOBAL>>.RegA6_SE[0].SE__SW__SAFETY.Bit.ERR:1
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:32
TEST.END

-- Test Case: NC_SM_SetBOOT_Step.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBOOT_Step
TEST.NEW
TEST.NAME:NC_SM_SetBOOT_Step.003
TEST.VALUE:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:40
TEST.EXPECTED:seq_monitor.NC_SM_SetBOOT_Step.StepInfo:40
TEST.END

-- Subprogram: NC_SM_SetBootStep

-- Test Case: NC_SM_SetBootStep.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBootStep
TEST.NEW
TEST.NAME:NC_SM_SetBootStep.001
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.Start:2
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.End:4
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.pResStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.pResStep[0]:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBootStep.pResStep[0]:0
TEST.END

-- Test Case: NC_SM_SetBootStep.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetBootStep
TEST.NEW
TEST.NAME:NC_SM_SetBootStep.002
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.Start:4
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.End:0
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.pResStep:<<malloc 1>>
TEST.VALUE:seq_monitor.NC_SM_SetBootStep.pResStep[0]:0
TEST.EXPECTED:seq_monitor.NC_SM_SetBootStep.pResStep[0]:31
TEST.END

-- Subprogram: NC_SM_SetRETRY_Count

-- Test Case: NC_SM_SetRETRY_Count.001
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetRETRY_Count
TEST.NEW
TEST.NAME:NC_SM_SetRETRY_Count.001
TEST.STUB:seq_monitor.NC_SM_GetMediaRetryCnt
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.return:300
TEST.END

-- Test Case: NC_SM_SetRETRY_Count.002
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetRETRY_Count
TEST.NEW
TEST.NAME:NC_SM_SetRETRY_Count.002
TEST.STUB:seq_monitor.NC_SM_GetMediaRetryCnt
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.return:0
TEST.VALUE:seq_monitor.NC_SM_SetRETRY_Count.InterfaceId:1
TEST.END

-- Test Case: NC_SM_SetRETRY_Count.003
TEST.UNIT:seq_monitor
TEST.SUBPROGRAM:NC_SM_SetRETRY_Count
TEST.NEW
TEST.NAME:NC_SM_SetRETRY_Count.003
TEST.STUB:seq_monitor.NC_SM_GetMediaRetryCnt
TEST.VALUE:seq_monitor.NC_SM_GetMediaRetryCnt.return:0
TEST.VALUE:seq_monitor.NC_SM_SetRETRY_Count.InterfaceId:0
TEST.END
