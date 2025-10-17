#ifndef R5_USB_DESCRIPTOR_H_
#define R5_USB_DESCRIPTOR_H_

#include "Drv_USB_SPEC.h"
#include "Drv_USB_Core.h"

/* ===================================================================

=================================================================== */
void NC_USB_Prepare_Descriptor(UDC_CTX_T *ptBootUsbCtx);
UINT16 NC_USB_Device_Set_String(USB_DEVICE_STRINGS_T *table, UINT16 id, UINT8 *buf);

#endif
