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
## 7. OTP_ENABLE     : Enable
##


sim_build: sim_bl1 sim_bl2 sim_bl2_se_hmac_key_rom sim_bl2_se_hmac_key_sysotp sim_bl2_se_hashed_aes_key_rom sim_bl2_se_hashed_aes_key_sysotp sim_bl2_se_hashed_aes_key_rt640otp
	$(ECHO) "SIM Build Test ... Done"

## BL1 : FW_IMG(BL1 is only non-secure img) ##
sim_bl1:
	$(ECHO) "SIM BL1 Build Test"
	make clean BL_SEL=1; make all BL_SEL=1 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0


## BL2 : Non-Secure FW_IMG ##
sim_bl2:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=0 CMRT_ENABLE=0 OTP_ENABLE=1 V=0 PGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

## BL2 : Secure FW_IMG ##
sim_bl2_se_hmac_key_rom:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 ROOT_KEY_TYPE=2 IMG_CONFIG_SBOOT_KEY=2 CMRT_KEY=2 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

sim_bl2_se_hmac_key_sysotp:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 ROOT_KEY_TYPE=2 IMG_CONFIG_SBOOT_KEY=1 CMRT_KEY=2 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

sim_bl2_se_hashed_aes_key_rom:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 ROOT_KEY_TYPE=1 IMG_CONFIG_SBOOT_KEY=2 CMRT_KEY=2 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

sim_bl2_se_hashed_aes_key_sysotp:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 ROOT_KEY_TYPE=1 IMG_CONFIG_SBOOT_KEY=1 CMRT_KEY=2 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

sim_bl2_se_hashed_aes_key_rt640otp:
	$(ECHO) "SIM BL2 Build Test"
	make clean BL_SEL=2; make all BL_SEL=2 OPERATION_MODE=SIM_EVT0 DEBUG=0 DEBUG_MSG=1 SECURE_BOOT=1 CMRT_ENABLE=1 OTP_ENABLE=1 ROOT_KEY_TYPE=1 IMG_CONFIG_SBOOT_KEY=1 CMRT_KEY=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=0

## Maskrom : (BL1)FW_IMG ##
maskrom:
	$(ECHO) "Final Maskrom Build Test"
	make clean all BL_SEL=1 OPERATION_MODE=EST_EVT0 DEBUG=0 DEBUG_MSG=0 SECURE_BOOT=1 CMRT_ENABLE=1 V=0 FPGA_TEST_OTP_ENABLE=0 IOMUX_ENABLE=1 USB_DLOAD=1 OTP_ENABLE=1
