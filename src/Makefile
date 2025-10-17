#/*******************************************************************************
# *                                                                             *
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.             	*
# *                                                                             *
# *******************************************************************************/

#=================================================================================
# default option
#=================================================================================
include make_helpers/genconfig.mk
include make_helpers/default.mk
include make_helpers/ci_build.mk
#=================================================================================
# BUILD TYPE
#=================================================================================
TARGET		:= $(PLATFORM_CHIP)_EVT$(EVT)_BL$(BL_SEL)_$(ARCH).axf
OUTPUT		:= build/DebugRel_BL$(BL_SEL)
ROMDIR		:= build/DebugRel_BL$(BL_SEL)/ROM

#=================================================================================
# source code make rule
#=================================================================================
include include/rule.mk
include bl$(BL_SEL)/rule.mk
include boot/rule.mk
include driver/rule.mk
include ncLib/rule.mk
include safety/rule.mk


#=================================================================================
# maker helper
#=================================================================================
include make_helpers/rule.mk
include make_helpers/secure_boot.mk
-include make_helpers/sim_build.mk



#=================================================================================
# Compiler Select
#=================================================================================
CPU             := Cortex-R5

ifeq ($(UNAME), Linux)
ifeq ($(BUILD_ARM_COMPILER_SEL), $(COMPILER_VER_6_16_2))
ifneq (,$(filter SIM%, $(OPERATION_MODE)))
    CROSS_COMPILE   :=
else
    CROSS_COMPILE   := /opt/ArmCompilerforEmbeddedFuSa6.16.2/bin/
endif
else
    CROSS_COMPILE   := /opt/ARMCompiler6.6.1/bin/
endif
else
    CROSS_COMPILE   := "/c/Program Files/ARMCompiler6.6.1/bin/"
endif

CMRT_SECURE_BOOT_IMG := tools/SecureBoot/SecureImgGen/tools/secure_boot.img
CMRT_OS_IMG     := tools/SecureBoot/SecureImgGen/tools/os.img
NCBIN_SECURE    := tools/BootRemaker/BootRemakerCMD-CMRT$(EXEC)
NCBIN           := tools/BootRemaker/BootRemakerCMD$(EXEC)
#B2H		:= tools/Binary2Hex/bin_to_hex.py
B2H		:= xxd$(EXEC)
CC              := $(CROSS_COMPILE)armclang
AR              := $(CROSS_COMPILE)armar
AS              := $(CROSS_COMPILE)armasm
LINK            := $(CROSS_COMPILE)armlink
FROMELF         := $(CROSS_COMPILE)fromelf



#========================================================================================
# build Option
#========================================================================================

ASFLAGS			+= --diag_style=gnu --brief_diagnostics --keep --cpu=$(CPU)

# ARCH
ifeq ($(ARCH),aarch64)
CFLAGS			+= --target=aarch64-arm-none-eabi
else
CFLAGS			+= --target=arm-arm-none-eabi
# AARCH32_INSTRUCTION_SET
CFLAGS			+=  -m$(AARCH32_INSTRUCTION_SET)
endif

# CORE
CFLAGS			+=  -mcpu=cortex-r5

ifeq ($(DEBUG), 1)
CFLAGS  		+= --debug -O0  -gdwarf-3 -fno-function-sections -fno-data-sections
else
CFLAGS  		+= -O2
endif


# Define NEON Enable
ifeq (${NEON_ENABLE},1)
AFLAGS			+= -mfpu=neon-fp-armv8
CFLAGS			+= -mfpu=neon-fp-armv8
$(eval $(call add_define,NEON_ENABLE_))
else
ifeq (${BL_SEL},1)
AFLAGS			+= -mfpu=none
CFLAGS			+= -mfloat-abi=soft -mfpu=none
else
AFLAGS			+= -mfpu=vfpv3-d16
CFLAGS			+= -mfloat-abi=hard -mfpu=vfpv3-d16
endif
endif

# for code quallity
CFLAGS			+= -Wall -Wextra -Wformat=2 -Wpedantic -Wconversion -Werror

LDFLAGS			:= --diag_style=ide --datacompressor off --map --symbols --startup main --verbose --list=$(OUTPUT)/$(LIST_NAME) --scatter=$(SCATTER_FILE) --info=sizes  --remove --callgraph

ifeq ($(ARCH),aarch64)
LDFLAGS 		+= --entry=startup
else
LDFLAGS 		+= --entry=VECTOR_TABLE
endif

ASFLAGS			+= $(INCLUDES)
CFLAGS			+= $(INCLUDES)

ELFFLAGS		:= --bin --output
ARFLAGS			:=


# end of genconfig.h
$(eval $(call end_genconfig))

#========================================================================================
# build target
#========================================================================================
all: $(OUTPUT)/$(TARGET) ncbin relbin


$(OUTPUT)/$(TARGET): $(OBJS)
	@if [ ! -d "$(OUTPUT)" ]; then \
		mkdir "$(OUTPUT)"; \
	fi
	$(ECHO) "Linking ...            $@"
	$(Q)$(LINK) $(LDFLAGS) --output $(OUTPUT)/$(TARGET) $(OBJS) $(NCLIB_TARGETS)

fromelf:
	$(ECHO) ""
	$(Q)rm -rf $(OUTPUT)/$(BIN_NAME)

	$(ECHO) "FROMELF ...            $(OUTPUT)/$(BIN_NAME)"
	$(Q)$(FROMELF) $(OUTPUT)/$(TARGET) $(ELFFLAGS) $(OUTPUT)/$(BIN_NAME)

	$(ECHO) "FROMELF ...            $(OUTPUT)/$(TXT_NAME)"
	$(Q)$(FROMELF) $(OUTPUT)/$(TARGET) --vhx --64x1 --output $(OUTPUT)/$(TXT_NAME)

	$(ECHO) "FROMELF ...            $(OUTPUT)/$(ASM_NAME)"
	$(Q)$(FROMELF) $(OUTPUT)/$(TARGET) -c > $(OUTPUT)/$(ASM_NAME)

ncbin:  fromelf secure_boot
ifeq ($(UNAME), Linux)
ifeq ($(CMRT_ENABLE),1)
ifeq ($(BL_SEL), 2)
	$(eval DOWNOAD_IMG_SECURE_CMRT := $(BINPURE_NAME)_SECURE_$(PLATFORM_MAGIC)_CMRT.bin)
	$(ECHO) "NCBIN SECURE BOOT ...  $(OUTPUT)/$(DOWNOAD_IMG_SECURE_CMRT)"
	$(Q)$(NCBIN_SECURE) $(DST_BIN) $(IMG_CONFIG_1) $(PLATFORM_MAGIC) $(OUTPUT)/$(DOWNOAD_IMG_SECURE_CMRT) $(GEN_SECURE) $(KEY_NUM) $(DIVERSIFY_PATH) $(CMRT_OS_IMG) $(CMRT_SECURE_BOOT_IMG) $(SUPPRESS_OUTPUT) $(IMG_SEC_CONFIG) $(IMG_CONFIG_2)
endif
else
	$(eval DOWNOAD_IMG := $(BINPURE_NAME)_$(PLATFORM_MAGIC).bin)
	$(ECHO) "NCBIN ...              $(OUTPUT)/$(DOWNOAD_IMG)"
#	$(Q)$(NCBIN_SECURE) $(OUTPUT)/$(BIN_NAME) $(IMG_CONFIG_1) $(PLATFORM_MAGIC) $(OUTPUT)/$(DOWNOAD_IMG) $(GEN_SECURE) $(SUPPRESS_OUTPUT) $(IMG_CONFIG_2)
#	delete [IMG_CONFIG_1, IMG_CONFIG_2] => change dummy value [0x0 0x0]
	$(Q)$(NCBIN_SECURE) $(OUTPUT)/$(BIN_NAME) 0x0 $(PLATFORM_MAGIC) $(OUTPUT)/$(DOWNOAD_IMG) $(GEN_SECURE) $(SUPPRESS_OUTPUT) 0x0
endif
endif

relbin:
	@if [ ! -d DebugRel ]; then \
		mkdir DebugRel; \
	fi

ifeq ($(SECURE_BOOT),1)
	$(eval SBIN_HEX_NAME := $(patsubst %.bin,%.hex,$(DOWNOAD_IMG_SECURE_CMRT)))
	$(eval BINARY_IMG_NAME := $(DOWNOAD_IMG_SECURE_CMRT))
else
	$(eval SBIN_HEX_NAME := $(patsubst %.bin,%.hex,$(DOWNOAD_IMG)))
	$(eval BINARY_IMG_NAME := $(DOWNOAD_IMG))
endif

ifeq ($(BL_SEL), 2)
# 1 byte hex file generation
# for SFLASH
#	$(Q)$(B2H) $(OUTPUT)/$(BINARY_IMG_NAME) $(SBIN_HEX_NAME)_SFLASH 8 0
	$(Q)$(B2H) -u -p -c 1 $(OUTPUT)/$(BINARY_IMG_NAME) >  $(OUTPUT)/$(SBIN_HEX_NAME)_SFLASH.hex
# for SD
#	$(Q)$(B2H) $(OUTPUT)/$(BINARY_IMG_NAME) $(SBIN_HEX_NAME)_SD 8 0
	$(Q)$(B2H) -u -p -c 1 $(OUTPUT)/$(BINARY_IMG_NAME) >  $(OUTPUT)/$(SBIN_HEX_NAME)_SD.hex
# for EMMC
#	$(Q)$(B2H) $(OUTPUT)/$(BINARY_IMG_NAME) $(SBIN_HEX_NAME)_EMMC 8 0
	$(Q)$(B2H) -u -p -c 1 $(OUTPUT)/$(BINARY_IMG_NAME) >  $(OUTPUT)/$(SBIN_HEX_NAME)_EMMC.hex
endif

ifeq ($(BL_SEL), 1)
#	$(Q)cp -a $(OUTPUT)/$(TXT_NAME)  DebugRel/APACHE6_BL1_ROM_64.hex
	$(Q)cp -rf $(OUTPUT)/*.*  DebugRel/
endif
ifeq ($(BL_SEL), 2)
	$(Q)cp -a $(OUTPUT)/$(SBIN_HEX_NAME)_SFLASH.hex  DebugRel/APACHE6_BL2_SFLASH.hex
	$(Q)cp -a $(OUTPUT)/$(SBIN_HEX_NAME)_SD.hex  DebugRel/APACHE6_BL2_SD.hex
	$(Q)cp -a $(OUTPUT)/$(SBIN_HEX_NAME)_EMMC.hex  DebugRel/APACHE6_BL2_EMMC.hex
	$(Q)cp -rf $(OUTPUT)/*.*  DebugRel/
endif

dep:
	$(CC) $(CFLAGS) -MM $(SRCS) > .depend


clean:
	$(ECHO) "cleaning ...           $(LOCAL_OBJS_DIR)"
	$(Q)rm -rf $(LOCAL_OBJS_DIR)


cleanall:
	$(ECHO) "cleaning ...           build"
	$(Q)rm -rf build DebugRel


#========================================================================================
# Compilation target for source files
#========================================================================================
$(LOCAL_OBJS_DIR)/%.o:%.c
	@if [ ! -d "$(dir $@)" ]; then \
		mkdir -p "$(dir $@)"; \
	fi
	$(ECHO) "C Compiling ...        $<"
	$(Q)$(CC) -c $(CFLAGS) $(DEFINES) $*.c -o $(LOCAL_OBJS_DIR)/$*.o -MD -MF $@.d

#
# Compilation target for Assembly files
#
$(LOCAL_OBJS_DIR)/%.o:%.S
	$(ECHO) "ASM Compiling ...      $<"
	@if [ ! -d "$(dir $@)" ]; then \
		mkdir -p "$(dir $@)"; \
	fi

ifeq ($(ARCH),aarch64)
	$(Q)$(CC) --target=aarch64-arm-none-eabi -march=armv8-a $(CFLAGS) $(DEFINES) -c -o $@ $<
else
	$(Q)$(AS) $(ASFLAGS) --cpreproc --cpreproc_opts=--target=arm-arm-none-eabi,-march=armv7-r,$(subst $(SPACE),$(COMMA),$(subst -D,-D$(COMMA),$(DEFINES)))  -o $@ $<
endif


#========================================================================================
# dependency : pull in dependency info for *existing* .o files
#========================================================================================
# pull in dependency info for *existing* .o files
DEP_FILES := $(OBJS:%=%.d)
-include $(DEP_FILES)

ifeq (.depend,$(wildcard .depend))
include .depend
endif


