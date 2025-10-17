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
SRCS	+= $(LOCAL_DIR)/load_IMG.c
SRCS	+= $(LOCAL_DIR)/boot_config.c
SRCS	+= $(LOCAL_DIR)/boot_eMMC.c
SRCS	+= $(LOCAL_DIR)/boot_SD.c
SRCS	+= $(LOCAL_DIR)/boot_sFlash.c
SRCS	+= $(LOCAL_DIR)/boot_UART.c
ifeq ($(USB_DLOAD), 1)
SRCS	+= $(LOCAL_DIR)/boot_USB.c
endif