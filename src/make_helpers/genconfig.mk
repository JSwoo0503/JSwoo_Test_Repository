#/*******************************************************************************
# *                                                                            	*
# * Copyright (C) 2022 by Nextchip Co., Ltd. All rights reserved.               *
# *                                                                             *
# ******************************************************************************/

#========================================================================================
# make macros
#========================================================================================


# Convenience function for adding build definitions
# $(eval $(call add_define,FOO)) will have:
# -DFOO if $(FOO) is empty; -DFOO=$(FOO) otherwise
# $(eval $(call add_define,FOO_)) will have: -DFOO
define add_define
        DEFINES +=      -D$(1)$(if $(value $(1)),=$(value $(1)),)
endef


# Convenience function for adding build definitions
# $(eval $(call add_define_val,FOO,BAR)) will have:
# -DFOO=BAR
define add_define_val
        DEFINES +=      -D$(1)=$(2)
endef


