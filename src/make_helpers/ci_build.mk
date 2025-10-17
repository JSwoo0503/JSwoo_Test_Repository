#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/

## Test Case
## 1. Operation Mode : SIM_EVT0, FPGA_EVT0, EST_EVT0
## 2. Build target   : BL1, BL2
## 3. IOMUX_ENABLE   : Enable, Disable
## 4. SECURE_BOOT    : BIST, ROOT_KEY_TYPE
## 5. DEBUG          : Enable, Disable
## 6. DEBUG_MSG      : Enable, Disable



ci_build: sim_build ci_bl1 ci_bl2 maskrom
	$(ECHO) "CI Build Test ... Done"

ci_bl1:
	$(ECHO) "CI BL1 Build Test"
	make clean all BL_SEL=1 OPERATION_MODE=FPGA_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0
	make clean all BL_SEL=1 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=0 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0
	make clean all BL_SEL=1 OPERATION_MODE=EST_EVT0 DEBUG=0 DEBUG_MSG=0 SECURE_BOOT=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=1

ci_bl2:
	$(ECHO) "CI BL2 Build Test"
	make clean all BL_SEL=2 OPERATION_MODE=FPGA_EVT0 DEBUG=1 DEBUG_MSG=1 SECURE_BOOT=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0
	make clean all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1j SECURE_BOOT=0 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0
	make clean all BL_SEL=2 OPERATION_MODE=EST_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=1
