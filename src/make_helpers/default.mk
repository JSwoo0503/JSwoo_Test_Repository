#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/

#################################################################################
##            DO NOT PUT A COMMENT AT THE END OF VALUE!!!!!                    ##
#################################################################################

#========================================================================================
# Firmware Info
#========================================================================================
# Version
BL_VER_MAJOR := 1
BL_VER_MINOR := 0
BL_VER_PATCH := 5

# Target Platform information( DO NOT CHANGE!! )
PLATFORM_CHIP   := APACHE6
PLATFORM_MAGIC  := AP60

# default build target( # BL1 : 1, BL2 : 2 )
BL_SEL := 1

# Operation Mode ( SIM_EVT0, FPGA_EVT0, EST_EVT0, SIM_EVT1, FPGA_EVT1, EST_EVT1, SIM_EVT2, FPGA_EVT2, EST_EVT2 )
# OPERATION_MODE := FPGA_EVT0
OPERATION_MODE := EST_EVT0

### Generater file from $DEFINES to config.h
CONFIGHEADER := include/genconfig.h


#========================================================================================
# Core process
#========================================================================================
# AARCH Selection
ARCH := aarch32
# ARCH := aarch64

# Use arm by default( arm, T32)
AARCH32_INSTRUCTION_SET := arm

# ARM Architecture major and minor versions: 8.0 by default.
ARM_ARCH_MAJOR := 7
ARM_ARCH_MINOR := 0


#========================================================================================
# External Interface
#========================================================================================
# IOMUX Enable(FPGA(0), Other(1):SIM, EVT0....)
IOMUX_ENABLE := 0

# LPDDR4 ENABLE
LPDDR4_ENABLE := 0

# INTERRUPT ENABLE
INTC_ENABLE := 0


#========================================================================================
# FPGA DB CLK
#========================================================================================
# set FPGA DB Clock ( # 40000 Khz , # 37125 KHz )
FPGA_DB_CLOCK := 40000
#FPGA_DB_CLOCK := 37125


#========================================================================================
# Secure Boot
#========================================================================================
# support secure boot ( 0: Non-Secure Boot, 1 : Secure Boot  )
# ! This feature is not optional. It must be set to 1.
SECURE_BOOT := 1


#========================================================================================
# Debug
#========================================================================================
# Debug build (0 : -O2, 1 : --debug -O1  -g )
DEBUG := 0

# Print debuging message( 0: Off, 1: ON)
DEBUG_MSG := 0

# Build verbosity
V := 0

R5_UART_ENABLE := 0

#========================================================================================
# OTP Config
#========================================================================================
# otp enable/disable ( 0: Disable, 1 : Enable  )
OTP_ENABLE := 1
# for FPGA TEST : Configuration from <"..~~~.csf"> file
FPGA_TEST_OTP_ENABLE := 0


#========================================================================================
# FORCE OTP configuration - for TEST ( by "This file" )
#========================================================================================
# FORCE_OTP_CONFIG_1 := 0x0
# FORCE_OTP_CONFIG_2 := 0x0


#========================================================================================
# FORCE FPGA ONLY : Force Change boot Config
#========================================================================================
# Select boot memory ( 0:sFlash, 1:eMMC, 2:SD CARD, 3. sFlash_SPI_CLK_INV, 4:UART, 5:USB )
# FORCE_BOOT_MEMORY works based on whether it is declared or not,  so if you do not want to use it, you should comment it out (#).
# ! [Caution] FORCE_BOOT_MEMORY does not work with USB(5). The USB Base address (0x06630000, 0x0b000000) cannot be accessed.
# ! This problem occurs because the usb scu settings were entered before applying FORCE_BOOT_MEMORY, but since the distribution schedule is imminent, 
# !  I am cautious about modifying the SCU, so I will work on it later.
# FORCE_BOOT_MEMORY := 0


# SPI CTRL (0:Skip, 1:SPI, 2:QSPI, 3:DMA-SPI, 4:DMA-QSPI)
# FORCE_CONFIG_SPI_CTRL := 0


#========================================================================================
# USB Download : ENABLE USB Download feature
#========================================================================================
USB_DLOAD	:= 1


#========================================================================================
# OSC config : Change Default Oscillator Config
#========================================================================================
# OSC VALUE(0:27Mhz, 1:24Mhz)
# 24MHz Only
#EXT_OSC_CONFIG := 1


#========================================================================================
# Compiler config : Change Build ARM-Compiler Config
#========================================================================================
# ( 1:COMPILER VERSION 6.6.1, 2:COMPILER VERSION 6.16.2 )
COMPILER_VER_6_6_1  := 1
COMPILER_VER_6_16_2 := 2
BUILD_ARM_COMPILER_SEL := $(COMPILER_VER_6_6_1)
# BUILD_ARM_COMPILER_SEL := $(COMPILER_VER_6_16_2)


#========================================================================================
#                           Please do not edit below!!
#========================================================================================

#========================================================================================
# Default Variable
#========================================================================================
APP_BUILD_DATE  := \"$(shell date +%Y/%m/%d)\"
APP_BUILD_TIME  := \"$(shell date +%H:%M:%S)\"
ROOT_DIR        := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
TOPDIR          := $(shell pwd)
SUBDIRS	        :=
DEFINES	        :=
INCLUDES        :=
SRCS			:=
NCLIB_TARGETS	:=
COMMA           :=,
EMPTY           :=
SPACE           := $(EMPTY) $(EMPTY)
EVT				:= 0


#================================================================================
# Directory variable
#================================================================================
# Find the local dir of the make file
GET_LOCAL_DIR    = $(patsubst %/,%,$(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))

# makes sure the target dir exists
MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi


#========================================================================================
# Check dependency
#========================================================================================
# Check ARCH type
ifeq (,$(filter $(ARCH),aarch32 aarch64))
$(error "Check ARCH : aarch32 or aarch64!!")
endif

# BL1 supports aarch32 only
ifeq ($(BL_SEL), 1)
ifeq ($(ARCH), aarch64)
$(error "[ERROR] BL1 support only aarch32!!")
endif
endif

$(eval $(call add_define_val,FPGA_DB_CLOCK,$(FPGA_DB_CLOCK)))


# ! The SECURE_BOOT option is currently intended for generating rt640 library code and will be removed in the future.
# BOOT TYPE (0:Skip, 1:NORMAL BOOT, 2:SECURE BOOT)
######### SECURE BOOT #########
ifeq ($(SECURE_BOOT),1)
# use CMRT (not use legacy SSS) when use SECURE_BOOT
GEN_SECURE           := 1
CMRT_ENABLE          := 1
# KEY_SPLIT_NUM [0x0 : System Key only, 0x1 ~ 0x7 (keysplt_num 1 ~ keysplt_num 7) ]
else
GEN_SECURE           := 0
CMRT_ENABLE          := 0
endif


# EVT0 / EVT1 /EVT2 Selection
ifneq (,$(filter %EVT1,$(OPERATION_MODE)))
EVT := 1
endif
ifneq (,$(filter %EVT2,$(OPERATION_MODE)))
EVT := 2
endif

# add -DEVT=0
$(eval $(call add_define,EVT))

# add -DBL_SEL=1 -DBL1_
$(eval $(call add_define,BL$(BL_SEL)_))
$(eval $(call add_define,BL_SEL))
#$(eval $(call add_define,SIM_FAST_BOOT_MODE_))

# add -DUART_ENABLE_
ifeq ($(DEBUG_MSG), 1)
$(eval $(call add_define,DEBUG_ENABLE_))
endif

# add -DR5_UART_ENABLE_ with UART1
ifeq ($(R5_UART_ENABLE), 1)
$(eval $(call add_define,R5_UART_ENABLE_))
endif

# add -DSIM_ONLY_
#$(eval $(call add_define_val,OPERATION_MODE,$(OPERATION_MODE)))
ifneq (,$(filter SIM%,$(OPERATION_MODE)))
$(eval $(call add_define,SIM_ONLY_))
## Force DEBUG_MSG Off
FORCE_DEBUG_OFF := 0
ifeq ($(DEBUG),1)
FORCE_DEBUG_OFF := 1
endif
ifeq ($(DEBUG_MSG),1)
FORCE_DEBUG_OFF := 1
endif
###ifeq ($(FORCE_DEBUG_OFF), 1)
###$(error  "[ERROR] SIM_ONLY_ should be turned off : DEBUG := 0, DEBUG_MSG = 0")
###endif
endif

# add -DFPGA_MODE_
ifneq (,$(filter FPGA%,$(OPERATION_MODE)))
$(eval $(call add_define,FPGA_MODE_))
endif

ifdef FORCE_BOOT_MEMORY
$(eval $(call add_define,FORCE_BOOT_MEMORY))
endif

# add -DFORCE_CONFIG_SPI_CTRL=1
ifdef FORCE_CONFIG_SPI_CTRL
$(eval $(call add_define,FORCE_CONFIG_SPI_CTRL))
endif

# add -DUSB_DLOAD_
ifeq ($(USB_DLOAD), 1)
$(eval $(call add_define,USB_DLOAD_))
endif

# Define Operation Mode : Board
ifneq (,$(filter EST_EVT%,$(OPERATION_MODE)))
$(eval $(call add_define,EST_MODE_))
endif

# add -DSECURE_BOOT_
ifeq ($(SECURE_BOOT), 1)
$(eval $(call add_define,SECURE_BOOT_))
endif

# add -DOTP_ENABLE_ -DFORCE_OTP_CONFIG_1=1
ifeq ($(OTP_ENABLE), 1)
$(eval $(call add_define,OTP_ENABLE_))
ifdef FORCE_OTP_CONFIG_1
$(eval $(call add_define,FORCE_OTP_CONFIG_1))
endif
ifdef FORCE_OTP_CONFIG_2
$(eval $(call add_define,FORCE_OTP_CONFIG_2))
endif
endif

# add -DFPGA_TEST_OTP_ENABLE_
ifeq ($(FPGA_TEST_OTP_ENABLE), 1)
$(eval $(call add_define,FPGA_TEST_OTP_ENABLE_))
endif


# add -DCMRT_ENABLE_ -DFORCE_CMRT_OTP_CONFIG=1
ifeq ($(CMRT_ENABLE), 1)
$(eval $(call add_define,CMRT_ENABLE_))
ifneq ($(DFORCE_CMRT_OTP_CONFIG), 0)
$(eval $(call add_define,DFORCE_CMRT_OTP_CONFIG_))
endif
endif

# add -DIOMUX_ENABLE_
ifeq ($(IOMUX_ENABLE), 1)
$(eval $(call add_define,IOMUX_ENABLE_))
endif

# add -LPDDR4_ENABLE_
ifeq ($(LPDDR4_ENABLE), 1)
$(eval $(call add_define,LPDDR4_ENABLE_))
endif

# add -DBL_VER_MAJOR=1 -DBL_VER_MINOR=0 -DBL_VER_PATCH=0 (V1.0.0)
$(eval $(call add_define,BL_VER_MAJOR))
$(eval $(call add_define,BL_VER_MINOR))
$(eval $(call add_define,BL_VER_PATCH))

# add -INTC_ENABLE_
ifeq ($(INTC_ENABLE), 1)
$(eval $(call add_define,INTC_ENABLE_))
endif

# add -ARCH
ifeq ($(ARCH), aarch64)
$(eval $(call add_define,ARCH64_))
endif

# add -DLINUX_ENABLE_
ifeq ($(LINUX_ENABLE), 1)
$(eval $(call add_define,LINUX_ENABLE_))
endif

# add -DEXT_OSC_CONFIG
##$(eval $(call add_define,EXT_OSC_CONFIG))

# add -DSUPPORT_ISP_4CH
ifeq ($(SUPPORT_ISP_4CH), 1)
$(eval $(call add_define,SUPPORT_ISP_4CH))
endif

#========================================================================================
# Debug Msg
#========================================================================================
# Verbose flag
ifeq (${V},0)
        Q:=@
        ECHO:=@echo
        SUPPRESS_OUTPUT := > /dev/null 2>&1
else
        Q:=
        ECHO:=@\#
        SUPPRESS_OUTPUT :=
endif

export Q ECHO

UNAME := $(shell uname)

# check extention
ifeq ($(UNAME), Linux)
EXEC :=
else
EXEC := .exe
endif


all: build_info genconfig

build_info:
	$(ECHO) ""
	$(ECHO) "-- Build Information ---------"
	$(ECHO) " - Target          : BL$(BL_SEL)"
	$(ECHO) " - ARCH            : $(ARCH)"
	$(ECHO) " - OPERATION_MODE  : $(OPERATION_MODE)"
	$(ECHO) " - SECURE_BOOT     : $(SECURE_BOOT)"
	$(ECHO) " - CMRT_ENABLE     : $(CMRT_ENABLE)"
	$(ECHO) " - GENCONFIG       : $(CONFIGHEADER)"
	$(ECHO) "------------------------------"

#========================================================================================
# generate a config.h file with all of the DEFINES laid out in #define format
#========================================================================================
genconfig:
	@$(MKDIR)
	@rm -f $(CONFIGHEADER).tmp; \
    echo "/* This file is automatically generated by the Makefile! [ $(APP_BUILD_DATE) $(APP_BUILD_TIME) ]  */" >> $(CONFIGHEADER).tmp; \
	echo \#ifndef GENCONFIG_H_ >> $(CONFIGHEADER).tmp; \
	echo \#define GENCONFIG_H_ >> $(CONFIGHEADER).tmp; \
	echo "" >> $(CONFIGHEADER).tmp; \
	for d in `echo $(DEFINES) | tr [:lower:] [:upper:]`; do \
		echo "#ifndef $$d" | sed "s/=.*/\ /g;s/-D//g" >> $(CONFIGHEADER).tmp; \
		echo "#define $$d" | sed "s/=/\ /g;s/-D//g" >> $(CONFIGHEADER).tmp; \
		echo "#endif" >> $(CONFIGHEADER).tmp; \
		echo "" >> $(CONFIGHEADER).tmp; \
	done; \
	echo \#endif >> $(CONFIGHEADER).tmp; \
	if [ -f "$(CONFIGHEADER)" ]; then \
		if cmp "$(CONFIGHEADER).tmp" "$(CONFIGHEADER)"; then \
			rm -f $(CONFIGHEADER).tmp; \
		else \
			mv $(CONFIGHEADER).tmp $(CONFIGHEADER); \
		fi \
	else \
		mv $(CONFIGHEADER).tmp $(CONFIGHEADER); \
	fi

