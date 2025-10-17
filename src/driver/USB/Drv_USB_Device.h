#ifndef R5_USB_DEVICE_H_
#define R5_USB_DEVICE_H_

#include "Drv_USB_SPEC.h"

extern void NC_USB_Device_Show_State(UDC_CTX_T *ptBootUsbCtx);
extern void NC_USB_Device_Change_State(UDC_CTX_T *ptBootUsbCtx, UINT8 state);
extern void NC_USB_Process_Event_Buffer_Entry(UDC_CTX_T *ptBootUsbCtx);
extern void NC_USB_Prepare_Endpoint(UDC_CTX_T *ptBootUsbCtx);
extern void NC_USB_Device_Start(UDC_CTX_T *ptBootUsbCtx);
#endif
