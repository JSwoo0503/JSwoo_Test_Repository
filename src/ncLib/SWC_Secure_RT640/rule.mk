#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/


LIB_SECURE_DIR		:= ncLib/SWC_Secure_RT640
LIB_SECURE_TARGET	:= ncLib_Secure_RT640.a
LIB_SECURE_OBJS_DIR := $(OUTPUT)/$(LIB_SECURE_DIR)

# Add NCLiB target
NCLIB_TARGETS 		+= $(LIB_SECURE_OBJS_DIR)/$(LIB_SECURE_TARGET)

#==========================================
# Includes
#==========================================

#==========================================
# Source List
#==========================================
LIB_SECURE_SRCS		:= $(LIB_SECURE_DIR)/rt640_interface.c
LIB_SECURE_SRCS		+= $(LIB_SECURE_DIR)/rt640_hlos.c

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
LIB_SECURE_OBJS 	:= $(LIB_SECURE_SRCS)
$(foreach _ext,$(ALL_SOURCE_EXTENSIONS),\
    $(eval LIB_SECURE_OBJS := $$(LIB_SECURE_OBJS:%$(_ext)=%.o))\
)

LIB_SECURE_OBJS := $(foreach _obj,$(LIB_SECURE_OBJS),$(OUTPUT)/$(_obj))


#========================================================================================
# build target
#========================================================================================
all: $(LIB_SECURE_TARGET)_info $(LIB_SECURE_DIR)/$(LIB_SECURE_TARGET)

$(LIB_SECURE_TARGET)_info:
	$(ECHO) ""
	$(ECHO) "Target ...             $(LIB_SECURE_TARGET)"

$(LIB_SECURE_DIR)/$(LIB_SECURE_TARGET): $(LIB_SECURE_OBJS)
	$(ECHO) "AR create ...          $(LIB_SECURE_OBJS_DIR)/$(LIB_SECURE_TARGET)" 
	$(Q)$(AR) --create $(ARFLAGS) $(LIB_SECURE_OBJS_DIR)/$(LIB_SECURE_TARGET) $(LIB_SECURE_OBJS)



#========================================================================================
# Compilation target for source files
#========================================================================================
$(LIB_SECURE_DIR)/%.o:%.c
	@if [ ! -d "$(dir $@)" ]; then \
		mkdir -p "$(dir $@)"; \
	fi
	$(ECHO) "C Compiling ...        $<" 

	$(Q)$(CC) -c $(CFLAGS) $(DEFINES) $*.c -o $(LIB_SECURE_OBJS_DIR)/$*.o -MD -MF $@.d

#========================================================================================
# dependency : pull in dependency info for *existing* .o files
#========================================================================================
# pull in dependency info for *existing* .o files
LIB_SECURE_DEP_FILES := $(LIB_SECURE_OBJS:%.o=%.d)
-include $(LIB_SECURE_DEP_FILES)

ifeq (.depend,$(wildcard .depend)) 
include .depend 
endif 
