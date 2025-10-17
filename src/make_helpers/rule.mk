#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/

ASM_NAME	:= $(patsubst %.axf,%.asm,$(TARGET))
LIST_NAME	:= $(patsubst %.axf,%.map,$(TARGET))
BIN_NAME	:= $(patsubst %.axf,%.bin,$(TARGET))
TXT_NAME	:= $(patsubst %.axf,%.txt,$(TARGET))
TXT32_NAME	:= $(patsubst %.axf,%_32.txt,$(TARGET))
TXT64_NAME	:= $(patsubst %.axf,%_64.txt,$(TARGET))
BINPURE_NAME    := $(patsubst %.axf,%,$(TARGET))


#==========================================
# Option List
#==========================================
LOCAL_OBJS_DIR	:= $(OUTPUT)

# all_source_patterns contains the list of filename patterns that correspond
# to source files recognized by our build system
ALL_SOURCE_EXTENSIONS	:= .c .s .S $(LOCAL_CPP_EXTENSION)
ALL_SOURCE_PATTERNS		:= $(foreach _ext,$(ALL_SOURCE_EXTENSIONS),%$(_ext))
ALL_CPP_PATERNS			:= $(foreach _ext,$(LOCAL_CPP_EXTENSION),%$(_ext))
UNKNOWN_SOURCES 		:= $(strip $(filter-out $(ALL_SOURCE_PATTERNS),$(LOCAL_SRC_FILES)))

ifdef UNKNOWN_SOURCES
#    $(call __ndk_info,WARNING: Unsupported source file extensions in $(LOCAL_MAKEFILE) for module $(LOCAL_MODULE))
#    $(call __ndk_info,  $(UNKNOWN_SOURCES))
	@echo "WARNING: Unsupported source file extensions in source list"
	@echo "$(UNKNOWN_SOURCES)"
endif

# OBJS will list all object files corresponding to the sources
# listed in SRCS, in the *same* order.
#
OBJS 	:= $(SRCS)
$(foreach _ext,$(ALL_SOURCE_EXTENSIONS),\
    $(eval OBJS := $$(OBJS:%$(_ext)=%.o))\
)

OBJS := $(foreach _obj,$(OBJS),$(LOCAL_OBJS_DIR)/$(_obj))
