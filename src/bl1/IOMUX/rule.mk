#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR := $(GET_LOCAL_DIR)


#==========================================
# Source List
#==========================================
ifneq (,$(filter FPGA%,$(OPERATION_MODE)))
SRCS		+= $(LOCAL_DIR)/IOMUX_FPGA.c
endif

ifneq (,$(filter SIM%,$(OPERATION_MODE)))
SRCS		+= $(LOCAL_DIR)/IOMUX_SIM.c
endif

ifneq (,$(filter EST%,$(OPERATION_MODE)))
SRCS		+= $(LOCAL_DIR)/IOMUX_EST.c
endif
