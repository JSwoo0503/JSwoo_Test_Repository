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
ifneq (,$(filter SIM%, $(OPERATION_MODE)))
SRCS		+= $(LOCAL_DIR)/Drv_Uart_SIM.c
else
#ifeq ($(DEBUG_MSG), 1)
#endif
SRCS		+= $(LOCAL_DIR)/Drv_Uart.c
endif
SRCS		+= $(LOCAL_DIR)/ymodem.c
