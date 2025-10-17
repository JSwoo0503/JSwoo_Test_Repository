#ifndef R5_USB_SPEC_H_
#define R5_USB_SPEC_H_


#include "Apache.h"

/* ===================================================================
USB directions
This bit flag is used in endpoint descriptors' bEndpointAddress field.
It's also one of three fields in control requests bRequestType.
=================================================================== */

#define USB_DIR_OUT							0			/* to device */
#define USB_DIR_IN							0x80U		/* to host */

#define USB_DIR_INPUT						1
#define USB_DIR_OUTPUT						0
/* ===================================================================
Descriptor types ... USB 2.0 spec table 9.5
=================================================================== */
#define USB_DT_DEVICE			  			0x01
#define USB_DT_CONFIG			  			0x02
#define USB_DT_STRING			   			0x03
#define USB_DT_INTERFACE				    0x04
#define USB_DT_ENDPOINT			 			0x05
#define USB_DT_DEVICE_QUALIFIER				0x06
#define USB_DT_OTHER_SPEED_CONFIG 			0x07
#define USB_DT_INTERFACE_POWER				0x08
#define USB_DT_ENDPOINT_SIZE 				7
#define USB_DT_CONFIG_SIZE					9
#define USB_DT_INTERFACE_SIZE				9

/* ===================================================================
Endpoints
=================================================================== */
#define USB_ENDPOINT_NUMBER_MASK 			0x0fUL
#define USB_ENDPOINT_DIR_MASK				0x80UL
#define USB_ENDPOINT_XFERTYPE_MASK			0x03UL
#define USB_ENDPOINT_XFER_CONTROL			0
#define USB_ENDPOINT_XFER_ISOC				1
#define USB_ENDPOINT_XFER_BULK				2
#define USB_ENDPOINT_XFER_INT				3
#define USB_ENDPOINTS_NUM					2

/* ===================================================================
USB types, the second of three bRequestType fields
=================================================================== */
#define USB_TYPE_MASK						(0x03U << 5)
#define USB_TYPE_STANDARD					(0x00U << 5)
#define USB_TYPE_CLASS						(0x01U << 5)
#define USB_TYPE_VENDOR						(0x02U << 5)
#define USB_TYPE_RESERVED					(0x03U << 5)

#define DWC3_DEPEVT_XFERCOMPLETE			0x01U
#define DWC3_DEPEVT_XFERINPROGRESS			0x02U
#define DWC3_DEPEVT_XFERNOTREADY			0x03U
#define DWC3_DEPEVT_RXTXFIFOEVT				0x04U
#define DWC3_DEPEVT_STREAMEVT				0x06U
#define DWC3_DEPEVT_EPCMDCMPLT				0x07U

/* ===================================================================
Standard requests, for the bRequest field of a SETUP packet.

These are qualified by the bRequestType field, so that for example
TYPE_CLASS or TYPE_VENDOR specific feature flags could be retrieved
by a GET_STATUS request.
=================================================================== */
#define USB_REQ_GET_STATUS					0x00
#define USB_REQ_CLEAR_FEATURE				0x01
#define USB_REQ_SET_FEATURE					0x03
#define USB_REQ_SET_ADDRESS					0x05
#define USB_REQ_GET_DESCRIPTOR				0x06
#define USB_REQ_SET_DESCRIPTOR				0x07
#define USB_REQ_GET_CONFIGURATION			0x08
#define USB_REQ_SET_CONFIGURATION			0x09
#define USB_REQ_GET_INTERFACE				0x0A
#define USB_REQ_SET_INTERFACE				0x0B
#define USB_REQ_SYNCH_FRAME					0x0C
#define USB_REQ_SET_SEL						0x30
#define USB_REQ_SET_ISOCH_DELAY				0x31


#define USB_REQ_VENDOR_NC_FWDN_START   		0xA
#define USB_REQ_VENDOR_NC_FWDN_END   		0xB
#define USB_REQ_VENDOR_NC_FWDN_PROGRESS		0xC
#define USB_REQ_VENDOR_NC_FWDN_HEADER		0xD
#define USB_REQ_VENDOR_NC_FWDN_IDLE			0xFF

/* USER Define */
#define USB_INTERFACE_CLASS         	0xff
#define USB_INTERFACE_SUB_CLASS     	0x1
#define USB_INTERFACE_PROTOCOL      	0x1

#define VENDOR_ID                   	0x345D
#define PRODUCT_ID                  	0x3000
#define MAX_STRING_SERIAL           	128

#define MAX_USB_DEVICE_INSTANCE         	(2U)
#define MAX_USB_STRING_PER_INST_SIZE        (3U)
#define USB_DEVICE_LANGUAGE_CODE        (0x0409)

#define USB_INST_NVS3000_MASKROM "NVS3000 MaskROM"
#define USB_INST_NEXTCHIP_CO_LTD "NEXTCHIP Co, Ltd"

#define USB_INST_NUM_MANUFACTURER	(0U)
#define USB_INST_NUM_PRODUCT		(1U)
#define USB_INST_NUM_SERIAL			(2U)

#define USB_INST_ID_MANUFACTURER	(1U)
#define USB_INST_ID_PRODUCT			(2U)
#define USB_INST_ID_SERIAL_NUMBER	(3U)
/* typedef enum {
	USB_INST_NUM_MANUFACTURER = 0U,
	USB_INST_NUM_PRODUCT = 1U,
	USB_INST_NUM_SERIAL = 2U
} USB_INST_NUM;

typedef enum {
	USB_INST_ID_MANUFACTURER = 1U,
	USB_INST_ID_PRODUCT = 2U,
	USB_INST_ID_SERIAL_NUMBER = 3U
} USB_INST_ID;*/


/* ========================================================================
TYPEDEFS
======================================================================== */

typedef unsigned long long dma_addr_t;

/* ========================================================================
Endpoint Events
======================================================================== */
typedef struct __attribute__ ((packed))
{
	/* Within XferNotReady */
	#define DEPEVT_STATUS_TRANSFER_ACTIVE	(1 << 3)

	/* Within XferComplete */
	#define DEPEVT_STATUS_BUSERR			(1 << 0)
	#define DEPEVT_STATUS_SHORT				(1 << 1)
	#define DEPEVT_STATUS_IOC				(1 << 2)
	#define DEPEVT_STATUS_LST				(1 << 3)

	/* Stream event only */
	#define DEPEVT_STREAMEVT_FOUND			1
	#define DEPEVT_STREAMEVT_NOTFOUND		2

	/* Control-only Status */
	#define DEPEVT_STATUS_CONTROL_DATA		1
	#define DEPEVT_STATUS_CONTROL_STATUS	2
	#define DEPEVT_STATUS_CONTROL_PHASE(n)	((n) & 3)

	/* In response to Start Transfer */
	#define DEPEVT_TRANSFER_NO_RESOURCE		1
	#define DEPEVT_TRANSFER_BUS_EXPIRY		2

	/* For Command Complete Events */
	#define DEPEVT_PARAMETER_CMD(n) 		(((n) & (0xf << 8)) >> 8)

    UINT32 one_bit							:1; 	/* not used */
    UINT32 endpoint_number					:5; 	/* endpoint number */
    UINT32 endpoint_event					:4; 	/* event type (XferComplete, XferInProgress, XfernotReady, Stream Event, Enpoint Command Complete) */
    UINT32 reserved11_10					:2; 	/* Reserved */
    UINT32 status							:4; 	/* event status */
    UINT32 parameters						:16; 	/* event parameters */
} DWC3_EVENT_DEPEVT_T;

/* ========================================================================
Device Events
======================================================================== */
typedef struct __attribute__ ((packed))
{
    UINT32 is_devspec						:1; 	/* indicates this is a non-endpoint event (device-specific) */
    UINT32 device_event						:7; 	/* indicates it's a device event */
    UINT32 type								:4; 	/* type of device event */
    UINT32 reserved15_12					:4;
    UINT32 event_info						:9; 	/* Information about this event */
    UINT32 reserved31_25					:7;
} DWC3_EVENT_DEVT_T;

/* ===================================================================

=================================================================== */
typedef struct __attribute__ ((packed))
{
	UINT32	is_devspec						:1;
	UINT32	type							:7;
	UINT32	reserved8_31					:24;
} DWC3_EVENT_TYPE_T;

/* ===================================================================

=================================================================== */
typedef struct  __attribute__ ((packed))
{
	union
	{
		UINT32 								raw;
		DWC3_EVENT_TYPE_T 					type;
		DWC3_EVENT_DEPEVT_T    				endpoint_event;
	    DWC3_EVENT_DEVT_T   				device_event;
	} dwc3_event_union;
} DWC3_EVENT_T;

/* ===================================================================

=================================================================== */
typedef struct  __attribute__ ((packed))
{
	UINT8  bLength;
	UINT8  bDescriptorType;

	/* UINT16 wData[1]; */ /* Modified for qac 9.6.0 error code 1039 issue, 
								code must be modified if array size is greater than 1 */
	UINT16 wData;		/* UTF-16LE encoded */

} USB_STRING_DESCRIPTOR_T;

/* ===================================================================

=================================================================== */
typedef struct
{
	UINT8 id;
	char s[MAX_STRING_SERIAL];
	UINT8 length;
} USB_STRING_T;

/* ===================================================================

=================================================================== */
typedef struct
{
	UINT16				language;	/* 0x0409 for en-us */
	USB_STRING_T		strings[MAX_USB_STRING_PER_INST_SIZE];
} USB_DEVICE_STRINGS_T;

/* ===================================================================

=================================================================== */
typedef enum
{
	USB_SPEED_UNKNOWN = 0,			/* enumerating */
	USB_SPEED_LOW, USB_SPEED_FULL,	/* usb 1.1 */
	USB_SPEED_HIGH,				    /* usb 2.0 */
	USB_SPEED_WIRELESS,			    /* wireless (usb 2.5) */
	USB_SPEED_SUPER,			    /* usb 3.0 */
	USB_SPEED_SUPER_PLUS			/* usb 3.1 */
} USB_DEVICE_SPEED_T;

/* ===================================================================

=================================================================== */
typedef struct  __attribute__ ((packed))
{
	UINT8  bLength;
	UINT8  bDescriptorType;

	UINT8  bInterfaceNumber;
	UINT8  bAlternateSetting;
	UINT8  bNumEndpoints;
	UINT8  bInterfaceClass;
	UINT8  bInterfaceSubClass;
	UINT8  bInterfaceProtocol;
	UINT8  iInterface;
} USB_INTERFACE_DESCRIPTOR_T ;

/* ===================================================================

=================================================================== */
typedef struct  __attribute__ ((packed))
{
	UINT8  bLength;
	UINT8  bDescriptorType;

	UINT16 wTotalLength;
	UINT8  bNumInterfaces;
	UINT8  bConfigurationValue;
	UINT8  iConfiguration;
	UINT8  bmAttributes;
	UINT8  bMaxPower;
} USB_CONFIG_DESCRIPTOR_T;

/* ===================================================================

=================================================================== */
typedef struct  __attribute__ ((packed))
{
	UINT8  bLength;
	UINT8  bDescriptorType;

	UINT16 bcdUSB;
	UINT8  bDeviceClass;
	UINT8  bDeviceSubClass;
	UINT8  bDeviceProtocol;
	UINT8  bMaxPacketSize0;
	UINT16 idVendor;
	UINT16 idProduct;
	UINT16 bcdDevice;
	UINT8  iManufacturer;
	UINT8  iProduct;
	UINT8  iSerialNumber;
	UINT8  bNumConfigurations;
} USB_DEVICE_DESCRIPTOR_T;

/* ===================================================================

=================================================================== */
typedef struct __attribute__ ((packed))
{
	UINT8 bRequestType;
	UINT8 bRequest;
	UINT16 wValue;
	UINT16 wIndex;
	UINT16 wLength;
} USB_CTRL_REQUEST_T;

/* ===================================================================

=================================================================== */
typedef struct __attribute__ ((aligned(4)))
{
	UINT8			*buf;
	UINT32			length;
	UINT32			offset;
	UINT64			addr;
	UINT32			actual;
} USB_REQUEST_T;

/* ===================================================================

=================================================================== */
typedef struct __attribute__ ((packed))
{
	UINT8  bLength;
	UINT8  bDescriptorType;
	UINT8  bEndpointAddress;
	UINT8  bmAttributes;
	UINT16 wMaxPacketSize;
	UINT8  bInterval;
	UINT8  bRefresh;
	UINT8  bSynchAddress;
} USB_ENDPOINT_DESCRIPTOR_T;

/* ===================================================================

=================================================================== */
enum
{
	USB_STATE_PREPARE_INIT = 0,
	USB_STATE_NOTATTACHED,
	USB_STATE_ATTACHED,
	USB_STATE_RESET,
	USB_STATE_SETUP,
	USB_STATE_ADDRESS,
	USB_STATE_CONFIGURED,
	USB_STATE_SUSPENDED
};

#endif
