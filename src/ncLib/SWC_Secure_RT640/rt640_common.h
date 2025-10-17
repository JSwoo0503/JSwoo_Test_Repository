#define API

extern API void NC_SB_Init_Param(tBOOT_STATUS *ptBootStatus);
extern API void NC_SB_Hold_Reset(tBOOT_STATUS *ptBootStatus);
extern API void NC_SB_BringUp(UINT32 os_with_user_container_img, tBOOT_STATUS *ptBootStatus);
extern API NC_ERROR NC_SB_Request_Decrypt_Service(UINT32 Addr, UINT32 system_otp_base, UINT32 KeySplitNum, UINT32 DiversifyPath, tBOOT_STATUS *ptBootStatus);
