#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/
LOCAL_DIR_driver := $(GET_LOCAL_DIR)


#==========================================
# include rules
#==========================================

# EVT0 / EVT1
include $(LOCAL_DIR_driver)/REG_EVT${EVT}/rule.mk

include $(LOCAL_DIR_driver)/ICU/rule.mk
include $(LOCAL_DIR_driver)/SCU/rule.mk
include $(LOCAL_DIR_driver)/UART/rule.mk
include $(LOCAL_DIR_driver)/SPI/rule.mk
include $(LOCAL_DIR_driver)/EMMC/rule.mk
include $(LOCAL_DIR_driver)/SDC/rule.mk
include $(LOCAL_DIR_driver)/DMA/rule.mk
ifeq ($(USB_DLOAD), 1)
include $(LOCAL_DIR_driver)/USB/rule.mk
endif
include $(LOCAL_DIR_driver)/OTP/rule.mk
