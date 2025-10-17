#include "Apache.h"
#include "Drv_USB_FEATURE.h"
#include "Drv_USB_REGS.h"
#include "Drv_USB_SPEC.h"

#include "Drv_USB_Core.h"
#include "Drv_USB_Descriptor.h"
#include "Drv_USB.h"

#include "MPU.h"

/* ===================================================================

=================================================================== */

#define STRING_LENGTH(str) ((sizeof(str) / sizeof(char)) - 1U)

#if (ENABLED_USB_OTP_SERIAL_NO==1)
#include "Drv_OTP.h"
#endif

/* static USB_DEVICE_STRINGS_T apache6_string; */

/* static char OTP_SERIAL[MAX_STRING_SERIAL]; */

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Int2String(char* str, UINT32 len, UINT32 val)
{
  UINT8 i;
  UINT8 ch;
  UINT32 value = val;

  for(i=1; i<=len; i++)
  {
    ch = (UINT8)(value % 16UL);
    if(ch > (UINT8)9) {
        str[len-i] = ((ch % (UINT8)10) + 'A');
    } else {
        str[len-i] = (ch + '0');
    }

    value /= 16U;
  }

  /* str[i-1] = '\0'; */
}

/* ===================================================================

=================================================================== */
static UINT32 DEBUG_FUNC_ATTR NC_USB_Device_Set_Serial_No(UDC_CTX_T *ptBootUsbCtx, char *szOtpSerial)
{
    UINT32 iRet = 24;

    if(ptBootUsbCtx == NULL) { }

    NC_Memset_u08(szOtpSerial, 0, MAX_STRING_SERIAL);

    #if (ENABLED_USB_OTP_SERIAL_NO==1)
    {
        NC_USB_Device_Int2String(&szOtpSerial[0], 8,  RegA6_OTP->CHIP_ID_0.Reg);
        NC_USB_Device_Int2String(&szOtpSerial[8], 8,  RegA6_OTP->CHIP_ID_1.Reg);
        NC_USB_Device_Int2String(&szOtpSerial[16], 8, RegA6_OTP->CHIP_ID_2.Reg);
    }
    #else
    {
        UINT32 id0, id1, id2;

        id0 = 0x11223344U;
        id1 = 0x55667788U;
        id2 = 0x99aabbccU;

        NC_USB_Device_Int2String(&szOtpSerial[0], 8,  id0);
        NC_USB_Device_Int2String(&szOtpSerial[8], 8,  id1);
        NC_USB_Device_Int2String(&szOtpSerial[16], 8, id2);
    }
    #endif

    return iRet;
}

/* ===================================================================

=================================================================== */
#if 0
USB_STRING_T DEBUG_FUNC_ATTR usb_device_string[MAX_USB_STRING_PER_INST_SIZE] = {
    {
        .s = "NVS3000 MaskROM",
        .id = 1,
        .length = STRING_LENGTH("NVS3000 MaskROM")
    },
    {
        .s = "NEXTCHIP Co, Ltd",
        .id = 2,
        .length = STRING_LENGTH("NEXTCHIP Co, Ltd")
    },
    {
        .s = "1234567890ABCDEF",
        .id = 3,
        .length = STRING_LENGTH("1234567890ABCDEF")
    }
};
#endif



/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Get_Apache6_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    static USB_DEVICE_STRINGS_T apache6_string;
    /* UINT32 instance; */

    NC_Memset_u08(&apache6_string, (UINT8)0, (INT32)sizeof(USB_DEVICE_STRINGS_T));

    ptBootUsbCtx->desc_str = &apache6_string;
    ptBootUsbCtx->desc_str->language = (UINT16)USB_DEVICE_LANGUAGE_CODE;

/* descriptor 부분의 인덱스 접근에 대한 호환성을 고려하여 작성하려고 하였으나, QAC에서 desc_str->strings[0] 에 대한 접근을 할 때, 잘못된 포인터 접근이라고 하여 에러가 지속 발생하여 static 하게 접근하도록 변경함. */
#if 0
    for(instance = 0U; instance < MAX_USB_STRING_PER_INST_SIZE; instance++) {
        if(instance == USB_INST_NUM_MANUFACTURER) {
            ptBootUsbCtx->desc_str->strings[instance].id = (UINT8)USB_INST_ID_MANUFACTURER;
            ptBootUsbCtx->desc_str->strings[instance].length = (UINT8)STRING_LENGTH(USB_INST_NVS3000_MASKROM);
            NC_Memcpy_u08((UINT8 *)USB_INST_NVS3000_MASKROM, (UINT8*)ptBootUsbCtx->desc_str->strings[instance].s, (const UINT32)ptBootUsbCtx->desc_str->strings[instance].length); /* MAX_STRING_SERIAL check ? */
        } else if(instance == USB_INST_NUM_PRODUCT) {
            ptBootUsbCtx->desc_str->strings[instance].id = (UINT8)USB_INST_ID_PRODUCT;
            ptBootUsbCtx->desc_str->strings[instance].length = (UINT8)STRING_LENGTH(USB_INST_NEXTCHIP_CO_LTD);
            NC_Memcpy_u08((UINT8 *)USB_INST_NEXTCHIP_CO_LTD, (UINT8*)ptBootUsbCtx->desc_str->strings[instance].s, (const UINT32)ptBootUsbCtx->desc_str->strings[instance].length); /* MAX_STRING_SERIAL check ? */
        } else {
            ptBootUsbCtx->desc_str->strings[instance].id = (UINT8)USB_INST_ID_SERIAL_NUMBER;
            ptBootUsbCtx->desc_str->strings[instance].length = (UINT8)NC_USB_Device_Set_Serial_No(ptBootUsbCtx, (char *)ptBootUsbCtx->desc_str->strings[instance].s);
        }
    }
#else
    ptBootUsbCtx->desc_str->strings[0].id = (UINT8)USB_INST_ID_MANUFACTURER;
    ptBootUsbCtx->desc_str->strings[0].length = (UINT8)STRING_LENGTH(USB_INST_NVS3000_MASKROM);
    NC_Memcpy_u08((UINT8 *)USB_INST_NVS3000_MASKROM, (UINT8*)ptBootUsbCtx->desc_str->strings[0].s, (const UINT32)ptBootUsbCtx->desc_str->strings[0].length); /* MAX_STRING_SERIAL check ? */

    ptBootUsbCtx->desc_str->strings[1].id = (UINT8)USB_INST_ID_PRODUCT;
    ptBootUsbCtx->desc_str->strings[1].length = (UINT8)STRING_LENGTH(USB_INST_NEXTCHIP_CO_LTD);
    NC_Memcpy_u08((UINT8 *)USB_INST_NEXTCHIP_CO_LTD, (UINT8*)ptBootUsbCtx->desc_str->strings[1].s, (const UINT32)ptBootUsbCtx->desc_str->strings[1].length); /* MAX_STRING_SERIAL check ? */

    ptBootUsbCtx->desc_str->strings[2].id = (UINT8)USB_INST_ID_SERIAL_NUMBER;
    ptBootUsbCtx->desc_str->strings[2].length = (UINT8)NC_USB_Device_Set_Serial_No(ptBootUsbCtx, (char *)ptBootUsbCtx->desc_str->strings[2].s);
#endif
}

/* ===================================================================

=================================================================== */
UINT16 DEBUG_FUNC_ATTR NC_USB_Device_Set_String(USB_DEVICE_STRINGS_T *table, UINT16 id, UINT8 *buf)
{
    USB_STRING_T *s;
    UINT32 len;
    UINT32 idx;
    UINT16 ret;
    UINT32 i;

    /* descriptor 0 has the language id */
    if (id == 0U)
    {
        buf[0] = (UINT8)4U;
        buf[1] = (UINT8)USB_DT_STRING;
        buf[2] = (UINT8)table->language;
        buf[3] = (UINT8)(table->language >> 8);
        /* return 4; */
        ret = 4U;
    } else {
        if(table != NULL) {
            s = table->strings;

            for(i = 0U; i < MAX_USB_STRING_PER_INST_SIZE; i++)
            {
                if(s->id == id) {
                    break;
                }
                s++;
            }

            ASSERT_USB(((s->s != NULL)), ASSERT_NO_0008);

            /* string descriptors have length, tag, then UTF16-LE text */
            len = MIN(126U, (UINT32)s->length);

            /* ASCII format -> UTF-16 */
            for (idx = 0U; idx < len; idx++)
            {
                buf[2U + (idx * 2U)] = (UINT8)(s->s[idx]); /* UTF-16-Low */
                buf[3U + (idx * 2U)] = 0;         /* UTF-16 High */
            }

            buf[0] = (UINT8)((len + 1U) * 2U);
            buf[1] = USB_DT_STRING;

            ret = buf[0];
        }
        else
        {
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGDBG,  "%s: Using NULL pointers as an argument is strictly prohibited.\n", __func__);
#endif
            ret = 0U;
        }
    }

    return ret;
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    USB_DEVICE_DESCRIPTOR_T *device_descriptor = (USB_DEVICE_DESCRIPTOR_T *)&ptBootUsbCtx->device_descriptor;

    device_descriptor->bDescriptorType = USB_DT_DEVICE; /* 0x1 */
    device_descriptor->bLength = 18;
    device_descriptor->bcdUSB = 0x200;
    device_descriptor->bDeviceClass = 0;
    device_descriptor->bDeviceSubClass = 0;
    device_descriptor->bDeviceProtocol = 0;
    device_descriptor->bMaxPacketSize0 = 64;
    device_descriptor->idProduct = PRODUCT_ID;
    device_descriptor->idVendor = VENDOR_ID;
    device_descriptor->iManufacturer = 1;
    device_descriptor->iProduct = 2;
    device_descriptor->iSerialNumber = 3;
    device_descriptor->bNumConfigurations = 1;
    device_descriptor->bcdDevice = ((UINT16)0x1) << 8;
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Configuration_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CONFIG_DESCRIPTOR_T *configuration_descriptor = (USB_CONFIG_DESCRIPTOR_T *)&ptBootUsbCtx->configuration_descriptor;

    configuration_descriptor->bDescriptorType = USB_DT_CONFIG;
    configuration_descriptor->bLength = USB_DT_CONFIG_SIZE;
    configuration_descriptor->bmAttributes = 0xc0;
    configuration_descriptor->bMaxPower = 1;
    configuration_descriptor->bNumInterfaces = 1;
    configuration_descriptor->iConfiguration = 2;
    configuration_descriptor->wTotalLength = 9;
    configuration_descriptor->bConfigurationValue = 1;
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Interface_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    USB_INTERFACE_DESCRIPTOR_T *interface_descriptor = (USB_INTERFACE_DESCRIPTOR_T *)&ptBootUsbCtx->interface_descriptor;

    interface_descriptor->bDescriptorType = USB_DT_INTERFACE;
    interface_descriptor->bLength = USB_DT_INTERFACE_SIZE;
    interface_descriptor->bAlternateSetting = 0x00;
    interface_descriptor->bInterfaceNumber = 0x00;
    interface_descriptor->bInterfaceClass = USB_INTERFACE_CLASS;
    interface_descriptor->bInterfaceProtocol = USB_INTERFACE_PROTOCOL;
    interface_descriptor->bInterfaceSubClass = USB_INTERFACE_SUB_CLASS;
    interface_descriptor->bNumEndpoints = 0;
    interface_descriptor->iInterface = 0;
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Prepare_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    NC_USB_Device_Descriptor(ptBootUsbCtx);

    NC_USB_Configuration_Descriptor(ptBootUsbCtx);

    NC_USB_Interface_Descriptor(ptBootUsbCtx);

    NC_USB_Device_Get_Apache6_Descriptor(ptBootUsbCtx);
}
