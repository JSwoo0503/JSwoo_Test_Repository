#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR := $(GET_LOCAL_DIR)

#==========================================
# include rules
#==========================================
INCLUDES	+= -I$(LOCAL_DIR)

SRCS	+= $(LOCAL_DIR)/Stdlib.c

# Secure Boot Enable
ifeq ($(SECURE_BOOT), 1)
ifeq ($(CMRT_ENABLE), 1)
	# RT-640
-include $(LOCAL_DIR)/SWC_Secure_RT640/rule.mk
else
	# SSS
#-include $(LOCAL_DIR)/SWC_Secure/rule.mk

ifeq ($(LIB_SECURE_TARGET), )
$(error "Secure boot is not supported yet!!!")
endif
endif
endif
