#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR_safety := $(GET_LOCAL_DIR)


#==========================================
# include rules
#==========================================
include $(LOCAL_DIR_safety)/MPU/rule.mk
include $(LOCAL_DIR_safety)/SE/rule.mk
include $(LOCAL_DIR_safety)/SM/rule.mk

ifeq ($(SECURE_BOOT), 1)
include $(LOCAL_DIR_safety)/SB/rule.mk
endif