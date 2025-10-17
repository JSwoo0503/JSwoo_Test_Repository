#include "Type.h"
#include "genconfig.h"
#include "boot_config.h"

#ifdef CMRT_ENABLE_
extern NC_ERROR NC_SB_CMRT_Initialize(UINT32 os_with_user_container_img, tBOOT_STATUS *ptBootStatus);
extern NC_ERROR NC_SB_CMRT_Secure_Run(UINT32 Addr, UINT8 KEY_STORAGE, UINT32 KeySplitNum, UINT32 DiversifyPath, tBOOT_STATUS *ptBootStatus);
#else
extern NC_ERROR NC_SB_CMRT_Secure_Run(UINT32 Addr, UINT8 ROOT_KEY_TYPE);
#endif
