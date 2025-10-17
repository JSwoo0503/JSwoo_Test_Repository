#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR := $(GET_LOCAL_DIR)


#==========================================
# Includes
#==========================================
INCLUDES	+= -I$(LOCAL_DIR)


#==========================================
# Source List
#==========================================
SRCS		+= $(LOCAL_DIR)/Drv_USB.c
SRCS		+= $(LOCAL_DIR)/Drv_USB_Core.c
SRCS		+= $(LOCAL_DIR)/Drv_USB_Ep0.c
SRCS		+= $(LOCAL_DIR)/Drv_USB_Descriptor.c
SRCS		+= $(LOCAL_DIR)/Drv_USB_Device.c