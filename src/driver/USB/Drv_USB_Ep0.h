#ifndef R5_USB_EP0_H_
#define R5_USB_EP0_H_

extern void NC_USB_Ep0_Out_Start(UDC_CTX_T *ptBootUsbCtx);
extern void NC_USB_Ep0_Send_Command(UINT32 epnum, UINT32 cmd, DWC3_EP_CMD_PARAMS_T *param);
extern void NC_USB_Ep0_Event(UDC_CTX_T *ptBootUsbCtx);
#endif
