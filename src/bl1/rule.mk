#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR_bl := $(GET_LOCAL_DIR)


#==========================================
# Includes
#==========================================
INCLUDES	+= -I$(LOCAL_DIR_bl)


#==========================================
# Source List
#==========================================
SRCS		+= $(LOCAL_DIR_bl)/main.c


#==========================================
# armlink scatter file
#==========================================
SCATTER_FILE	:= $(LOCAL_DIR_bl)/BL1_Linker.scat


#==========================================
# include rules
#==========================================
ifeq ($(IOMUX_ENABLE), 1)
include $(LOCAL_DIR_bl)/IOMUX/rule.mk
endif

include $(LOCAL_DIR_bl)/${ARCH}/rule.mk
