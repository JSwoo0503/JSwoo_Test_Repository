#include "Apache.h"
#include "Drv_USB_FEATURE.h"
#include "boot_config.h"
#include "Drv_USB_REGS.h"

#include "Drv_USB_Device.h"
#include "Drv_USB_Core.h"
#include "Drv_USB_Descriptor.h"
#include "Drv_USB_Ep0.h"
#include "Drv_USB.h"
#include "Drv_SCU.h"

#include "MPU.h"

/* qac-9.6.0-1021 */
/* 
#define min(x, y) ({				\
	typeof(x) _min1 = (x);			\
	typeof(y) _min2 = (y);			\
	(void) (&_min1 == &_min2);		\
	_min1 < _min2 ? _min1 : _min2; })
 */

/* qac-9.6.0-3205 */
/* 
typedef enum 
{
    EP0_EVENT_XFER_COMPLETE,
    EP0_EVENT_XFER_NOT_READY,
    EP0_EVENT_XFER_IN_PROGRESS,
    EP0_EVENT_SETUP,
    EP0_EVENT_STALL
} EP0_EVENT_T;
*/

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Set_Address(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CTRL_REQUEST_T *req = &ptBootUsbCtx->ctrl_req;
    UINT16 set_address = req->wValue;
    DCFG_T device_config;

    ASSERT_USB(set_address <= 127, ASSERT_NO_0015);
    ASSERT_USB(ptBootUsbCtx->device_state != USB_STATE_CONFIGURED, ASSERT_NO_0016);

    
    device_config.dcfg.dw = NC_DWC3_Read(DWC3_DCFG);
    device_config.dcfg.b.DEVADDR = set_address;
    NC_DWC3_Write(DWC3_DCFG, device_config.dcfg.dw);

    if(set_address != 0U) {
        NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_CONFIGURED);
    } else {
        NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_ADDRESS);
    }
}

/* ===================================================================

=================================================================== */
/* qac-9.6.0-3219 */
/* 
void DEBUG_FUNC_ATTR ep0_update_next_phase(UDC_CTX_T *ptBootUsbCtx, UINT32 next_stage)
{
    if (ptBootUsbCtx->ep0state != next_stage) {
        ptBootUsbCtx->ep0state = next_stage;
    }
}
*/
/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Get_Descriptor(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CTRL_REQUEST_T *ctrl = &ptBootUsbCtx->ctrl_req;
    UINT16 ctrl_length = ctrl->wLength;       
    UINT16 ctrl_value = ctrl->wValue;         
    UINT16 type = ctrl_value >> 8;           
    UINT8 direction = ((ctrl->bRequestType & (UINT8)USB_DIR_IN) != 0U) ? (UINT8)USB_DIR_INPUT : (UINT8)USB_DIR_OUTPUT;
    /* DWC3_EP_T *dep = &ptBootUsbCtx->eps[direction]; */
    USB_REQUEST_T *usb_req = &ptBootUsbCtx->req[direction];
    UINT32 usb_req_size = 0;
    UINT16 id;

    switch(type)
    {
        case USB_DT_DEVICE:
            usb_req_size = MIN(ctrl_length, (UINT16)sizeof(ptBootUsbCtx->device_descriptor));        
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);
            DBGUSB(MSGDBG, "%s:USB_DT_DEVICE. %d %d %d\n", __func__, ctrl_length, sizeof(ptBootUsbCtx->device_descriptor), usb_req_size);
            DBGUSB(MSGDBG, "===================================================\n", NULL);
#endif            
            NC_Memcpy_u08((UINT8 *)&ptBootUsbCtx->device_descriptor, usb_req->buf, usb_req_size);
            break;
        case USB_DT_CONFIG:
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);         
            DBGUSB(MSGDBG, "%s:USB_DT_CONFIG\n", __func__);
            DBGUSB(MSGDBG, "===================================================\n", NULL);             
#endif
            usb_req_size = USB_DT_CONFIG_SIZE + USB_DT_INTERFACE_SIZE;            
            ptBootUsbCtx->configuration_descriptor.wTotalLength = (UINT16)usb_req_size;

            NC_Memcpy_u08((UINT8 *)&ptBootUsbCtx->configuration_descriptor, usb_req->buf, USB_DT_CONFIG_SIZE);
            NC_Memcpy_u08((UINT8 *)&ptBootUsbCtx->interface_descriptor, (usb_req->buf + USB_DT_CONFIG_SIZE), USB_DT_INTERFACE_SIZE);

            if(usb_req_size > ctrl_length)
            {
                usb_req_size = ctrl_length;
            }
            break;
        case USB_DT_STRING:
            id = (ctrl_value & 0xFFU);
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);             
            DBGUSB(MSGDBG, "%s:USB_DT_STRING : id = %x\n", __func__, id);            
            DBGUSB(MSGDBG, "===================================================\n", NULL);             
#endif
            usb_req_size = (UINT32)NC_USB_Device_Set_String(ptBootUsbCtx->desc_str, id, usb_req->buf);
            break;
#ifdef DEBUG_ENABLE_
        case USB_DT_INTERFACE:
            DBGUSB(MSGDBG, "%s:USB_DT_INTERFACE\n", __func__);
        case USB_DT_ENDPOINT:
            DBGUSB(MSGDBG, "%s:USB_DT_ENDPOINT\n", __func__);
            break;
#endif            
        default: 
#ifdef DEBUG_ENABLE_        
            DBGUSB(MSGDBG, "%s: Other DT??? :%x\n", __func__, type);
#endif
            /* Do Nothing */
            break;
    }

    usb_req->length = usb_req_size;
    
    /* NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_SETUP); */
    
    ASSERT_USB(usb_req_size > 0, ASSERT_NO_0017);
    
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Set_Configuration(UDC_CTX_T *ptBootUsbCtx)
{
    /* USB_CTRL_REQUEST_T *ctrl_req = &ptBootUsbCtx->ctrl_req; */
    UINT32 usb_device_state = ptBootUsbCtx->device_state;

    switch(usb_device_state)
    {
        case USB_STATE_SETUP:
        case USB_STATE_RESET:
        case USB_STATE_ADDRESS:
        case USB_STATE_CONFIGURED:
        {
            /* On USB reset, hardware clears this bit to 0.
            Software sets this bit after receiving SetFeature(U2_ENABLE, U1_ENABLE),
            and clears this bit when ClearFeature(U2_ENABLE, U1_ENABLE) is received. */
            DCTL_T device_control;
            device_control.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
            /* 디바이스 펌웨어가 제어한다. 기본적으로 절전 모드에 진입할 필요가 없다. */
            device_control.dctl.b.ACCEPTU1ENA = 0x0;
            device_control.dctl.b.ACCEPTU2ENA = 0x0;
            NC_DWC3_Write(DWC3_DCTL, device_control.dctl.dw);
            NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_CONFIGURED);
            break;
        }
        default:
            DBGUSB(MSGERR, "%s: Unknown device state:%x\n", __func__, usb_device_state);
            break;
    }
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Standard_Request(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CTRL_REQUEST_T *req = &ptBootUsbCtx->ctrl_req;
    UINT8 bRequest = req->bRequest;

    switch(bRequest)
    {
        case USB_REQ_SET_ADDRESS:
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);           
            DBGUSB(MSGDBG, "%s:USB_REQ_SET_ADDRESS\n",__func__);
            DBGUSB(MSGDBG, "===================================================\n", NULL);               
#endif            
            NC_USB_Ep0_Set_Address(ptBootUsbCtx);
            break;
        case USB_REQ_GET_DESCRIPTOR:
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);           
            DBGUSB(MSGDBG, "%s:USB_REQ_GET_DESCRIPTOR\n", __func__);
            DBGUSB(MSGDBG, "===================================================\n", NULL);               
#endif            
            NC_USB_Ep0_Get_Descriptor(ptBootUsbCtx);
            break;
        case USB_REQ_SET_CONFIGURATION:
#if 0 /* def DEBUG_ENABLE_ */
            DBGUSB(MSGDBG, "===================================================\n", NULL);           
            DBGUSB(MSGDBG, "%s:USB_REQ_SET_CONFIGURATION\n", __func__);
            DBGUSB(MSGDBG, "===================================================\n", NULL);
#endif            
            NC_USB_Ep0_Set_Configuration(ptBootUsbCtx);
            break;
#ifdef DEBUG_ENABLE_            
        case USB_REQ_GET_STATUS:
            DBGUSB(MSGDBG, "%s:USB_REQ_GET_STATUS\n", __func__);
        case USB_REQ_CLEAR_FEATURE:
            DBGUSB(MSGDBG, "%s:USB_REQ_CLEAR_FEATURE\n", __func__);
        case USB_REQ_SET_FEATURE:
            DBGUSB(MSGDBG, "%s:USB_REQ_SET_FEATURE\n", __func__);
            break;
#endif            
        default:
#ifdef DEBUG_ENABLE_            
            DBGUSB(MSGDBG, "%s:Unkown Standard Request\n", __func__);
#endif            
            /* Do Nothing */
            break;
    }
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Vendor_Request(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CTRL_REQUEST_T *ctrl = &ptBootUsbCtx->ctrl_req;
    USB_REQUEST_T *vendor_req = &ptBootUsbCtx->vendor_req;

    UINT16 wlength = ctrl->wLength;
    /* UINT8 direction = !!(ctrl->bRequestType & USB_DIR_IN);
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[direction]; */

    ptBootUsbCtx->allocated_data_length = 0;
    ptBootUsbCtx->binary_transferred = FALSE;
    ptBootUsbCtx->split_transfer_bytes_expected = 0;
    ptBootUsbCtx->num_bytes_per_split_transfer = 0;
    ptBootUsbCtx->zlp_needed = 0;
    vendor_req->actual = 0;

    switch(ctrl->bRequest)
    {
        case USB_REQ_VENDOR_NC_FWDN_HEADER:
        {
            vendor_req->buf = (UINT8*)ptBootUsbCtx->hdraddr.dw[0];
            vendor_req->addr = ptBootUsbCtx->hdraddr.qw;
            vendor_req->length = (UINT32)wlength;
            ptBootUsbCtx->allocated_data_length = (UINT32)ROUND_UP(vendor_req->length, 64U);
            ptBootUsbCtx->header_transferred = (BOOL)TRUE;
            ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_HEADER; 
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGDBG, "%s: USB_REQ_VENDOR_NC_FWDN_HEADER %d byte\n", __func__, ptBootUsbCtx->allocated_data_length);   
#endif            
            break;            
        }
        case USB_REQ_VENDOR_NC_FWDN_START:        
        {
#ifdef DEBUG_ENABLE_            
            DBGUSB(MSGDBG, "%s: USB_REQ_VENDOR_NC_FWDN_START\n", __func__);
#endif            
            vendor_req->buf = (UINT8*)ptBootUsbCtx->dstaddr.dw[0];
            vendor_req->addr = ptBootUsbCtx->dstaddr.qw;
            vendor_req->actual = 0;
            ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_START;
            break;
        }        
        case USB_REQ_VENDOR_NC_FWDN_PROGRESS:
        {
            vendor_req->length = 64;
            ptBootUsbCtx->allocated_data_length = (UINT32)ROUND_UP(vendor_req->length, 64U);
            ptBootUsbCtx->binary_transferred = TRUE;
            ptBootUsbCtx->split_transfer_bytes_expected = ctrl->wLength;
            ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_PROGRESS;
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGDBG, "%s: USB_REQ_VENDOR_NC_FWDN_PROGRESS wlength %d data length%d total:%d bytes\n", 
                                        __func__, wlength, ptBootUsbCtx->allocated_data_length, ptBootUsbCtx->split_transfer_bytes_expected); 
#endif
            break;            
        }
        case USB_REQ_VENDOR_NC_FWDN_END:
        {
#ifdef DEBUG_ENABLE_            
            DBGUSB(MSGDBG, "%s: USB_REQ_VENDOR_NC_FWDN_END\n", __func__);
#endif            
            ptBootUsbCtx->num_bytes_per_split_transfer = 0;
            ptBootUsbCtx->accumulation_received_bytes = 0;
            NC_Memset_u08(&ptBootUsbCtx->vendor_req, (UINT8)0x0, (INT32)sizeof(USB_REQUEST_T));            
            ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_END;
            break;
        }
        default:
        {
            DBGUSB(MSGERR, "%s: Unknown vendor request :%x\n", ctrl->bRequest);
            ptBootUsbCtx->firmware_downloading_status = USB_REQ_VENDOR_NC_FWDN_IDLE;
            break;
        }
    }

}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Ep0_Send_Command(UINT32 epnum, UINT32 cmd, DWC3_EP_CMD_PARAMS_T *param)
{
    UINT32 timeout = 5000;

    NC_DWC3_Write(DWC3_DEPCMDPAR0(epnum), param->param0);
    NC_DWC3_Write(DWC3_DEPCMDPAR1(epnum), param->param1);
    NC_DWC3_Write(DWC3_DEPCMDPAR2(epnum), param->param2);
    /* device physical endpoint-n command register
    CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command.
    command type
    ■ 00h: Reserved
    ■ 01h: Set Endpoint Configuration - -64 or 96-bit Parameter
    ■ 02h: Set Endpoint Transfer Resource Configuration - 32-bit Parameter
    ■ 03h: Get Endpoint State - No Parameter Needed
    ■ 04h: Set Stall - No Parameter Needed
    ■ 05h: Clear Stall (see Set Stall) - No Parameter Needed
    ■ 06h: Start Transfer - 64-bit Parameter
    ■ 07h: Update Transfer - No Parameter Needed
    ■ 08h: End Transfer - No Parameter Needed
    ■ 09h: Start New Configuration - No Parameter Needed */

    NC_DWC3_Write(DWC3_DEPCMD(epnum), (cmd | DWC3_DEPCMD_CMDACT));

    while (timeout > 0U)
    {
        /* Software sets this bit to 1 to enable the device endpoint controller to execute the generic command.
        The device controller sets this bit to 0 when the CmdStatus field is valid and the endpoint is ready
        to accept another command. This does not imply that all the effects of the previously-issued command
        have taken place. */
        DEPCMD_T endpoint_cmd;
        endpoint_cmd.depcmd.dw = NC_DWC3_Read(DWC3_DEPCMD(epnum));

        if (endpoint_cmd.depcmd.b.CMDACT == FALSE) {
            break;
        }

        /* ASSERT_USB(timeout != 0, ASSERT_NO_0018); */

        timeout--;

        nc_mdelay(1U);
    } 

}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Prepare_One_TRB(UDC_CTX_T *ptBootUsbCtx, UINT64_T buffer_addr, UINT32 length, UINT32 type)
{   
    DWC3_TRB_T *trb = &ptBootUsbCtx->ep0_trb;
    
    trb->bpl = buffer_addr.highrow32.low;                         /* 전송할 버퍼 Low Address를  TRB0 에 설정 */
    trb->bph = buffer_addr.highrow32.high;                        /* 전송할 버퍼 High Address를 TRB0 에 설정     */
    trb->size = length;                                 /* data length */
	trb->ctrl = type;                                   /* trb command */
	trb->ctrl |= (UINT32)DWC3_TRB_CTRL_HWO;                     /* h/w own bit 설정, 하드웨어에 제어권 넘김 */
    trb->ctrl |= (UINT32)DWC3_TRB_CTRL_ISP_IMI;                 /* short packet or isochronous miss 시 인터럽트 발생 */
    trb->ctrl |= (UINT32)DWC3_TRB_CTRL_IOC;                     /* trb 완료시 인터럽트 발생 */
    trb->ctrl |= (UINT32)DWC3_TRB_CTRL_LST;                     /* last trb */
    /* trb->ctrl &= ~DWC3_TRB_CTRL_CSP; */                  /* 제어 전송에서는 CSP를 0으로 설정 */

    ptBootUsbCtx->ep0_trb_addr.highrow32.low = LOWER_32BITS((UINT64)trb);
    ptBootUsbCtx->ep0_trb_addr.highrow32.high = UPPER_32BITS((UINT64)trb);
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Start_Transfer(UDC_CTX_T *ptBootUsbCtx, DWC3_EP_T *dep)
{
    DWC3_EP_CMD_PARAMS_T params;
    UINT32 cmd;
    UINT32 resource_idx;
    
    ASSERT_USB(dep->flags != DWC3_EP_TRANSFER_STARTED, ASSERT_NO_0019);

    NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));
    params.param0 = ptBootUsbCtx->ep0_trb_addr.highrow32.high;
    params.param1 = ptBootUsbCtx->ep0_trb_addr.highrow32.low;

    dep->flags |= (UINT32)DWC3_EP_TRANSFER_STARTED;                             /* logical 엔드포인트 플래그 셋 */
    cmd = DWC3_DEPCMD_STARTTRANSFER;                             /* 하드웨어 엔드포인트 설정 명령 */
    NC_USB_Ep0_Send_Command(dep->number, cmd, &params);                        /* 하드웨어 엔드포인트 활성화 */

    /* Command6: Start Transfer (DEPSTRTXFER) 섹션 참조. */
    resource_idx = NC_DWC3_Read(DWC3_DEPCMD((UINT32)dep->number));          /* 하드웨어어는 Start Transfer 명령에 응답하여 전송 리소스 인덱스를 할당한다. */
    dep->resource_index = (UINT8)DWC3_DEPCMD_GET_RSC_IDX(resource_idx);        /* 이벤트 파라미터 필드 22:16 에 XferRscIdx가 포함된다. 이 인덱스는 이후의 Update Transfer 및 End Transfer 명령에서 사용된다. */
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Ep0_Out_Start(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 setup_packet_size = 8U;

    DWC3_EP_T *dep = &ptBootUsbCtx->eps[0];
    UINT64_T buffer;
    buffer.qw = (UINT64)&ptBootUsbCtx->ctrl_req;

    NC_USB_Ep0_Prepare_One_TRB(ptBootUsbCtx, buffer, setup_packet_size, DWC3_TRBCTL_CONTROL_SETUP);
    NC_USB_Ep0_Start_Transfer(ptBootUsbCtx, dep);

}


/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Prepare_Status_Phase(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 ep_num = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.endpoint_number;
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[ep_num];
    UINT64_T buffer_addr;
    UINT32 length = 0;
    UINT32 type = DWC3_TRBCTL_CONTROL_STATUS3;

    buffer_addr.qw = (UINT64)&ptBootUsbCtx->ctrl_req;

    NC_USB_Ep0_Prepare_One_TRB(ptBootUsbCtx, buffer_addr, length, type);
    NC_USB_Ep0_Start_Transfer(ptBootUsbCtx, dep);

    /* DBGUSB(MSGINFO, "%s: Prepared status phase done, ep num:%d %x\n", __func__, ep_num, type); */
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Handle_XferNotReady(UDC_CTX_T *ptBootUsbCtx)
{
    UINT8 status = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.status;
    UINT8 ep_num = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.endpoint_number;

    switch(status)
    {
        case DEPEVT_STATUS_CONTROL_DATA:
        {
#ifdef DEBUG_ENABLE_            
            DBGUSB(MSGDBG, "%s:DEPEVT_STATUS_CONTROL_DATA expect ep(%d)\n", __func__, ep_num);
#endif
            break;
        }
        case DEPEVT_STATUS_CONTROL_STATUS:
        {
#ifdef DEBUG_ENABLE_                        
            DBGUSB(MSGDBG, "%s:DEPEVT_STATUS_CONTROL_STATUS: ep_num:%x status:%x\n", __func__, ep_num, status);            
#endif
            ptBootUsbCtx->ep0state = (((ep_num & (UINT8)1U) != 0U) ? (UINT32)EP0_STATE_STATUS_IN_PHASE : (UINT32)EP0_STATE_STATUS_OUT_PHASE);
            NC_USB_Ep0_Prepare_Status_Phase(ptBootUsbCtx);
            break;
        }
        default:
            DBGUSB(MSGDBG, "Unknown Status: %x\n", status);
            break;
    }
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Handle_Setup_Stage(UDC_CTX_T *ptBootUsbCtx)
{
    USB_CTRL_REQUEST_T *ctrl = &ptBootUsbCtx->ctrl_req;
    UINT8 type = ctrl->bRequestType & (UINT8)USB_TYPE_MASK;

#ifdef DEBUG_ENABLE_            
    DBGUSB(MSGDBG, "SETUP: bRequestType=0x%x, bRequest=0x%x, wValue=0x%x, wIndex=0x%x, wLength=%d\n",
               ctrl->bRequestType, ctrl->bRequest,
               ctrl->wValue, ctrl->wIndex, ctrl->wLength);
#endif
    switch(type)
    {
        case USB_TYPE_STANDARD:
            NC_USB_Ep0_Standard_Request(ptBootUsbCtx);
            break;
        case USB_TYPE_VENDOR:
            NC_USB_Ep0_Vendor_Request(ptBootUsbCtx);
            break;
        default:
            DBGUSB(MSGDBG, "%s: Unknown request type:%x\n", type);
            break;
    }
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Handle_Stall(UDC_CTX_T *ptBootUsbCtx)
{
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[0];
    DWC3_EP_CMD_PARAMS_T params;
    UINT32 timeout = 5000;

    NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));

    /* 엔드포인트 0에 대한 STALL은 특정 상황에서만 사용해야 함.
    1. 지원하지 않는 요청 수신 시:
    2. 프로토콜 오류 발생 시:
    3. 디바이스 상태가 요청을 처리할 수 없을 때:
    4. 데이터 단계에서 오류 발생 시:

    STALL을 설정한 후에는 다음 SETUP 패킷을 기다려야 함. 
    SETUP 패킷을 받아야  하드웨어가 자동으로 STALL을 해제하기 때문.
    STALL 설정 후 즉시 SETUP 패킷을 처리할 준비를 해야 함. 새로운 SETUP 패킷용 버퍼를 준비하고 대기 상태로 전환한다.
    STALL 설정을 잘못하면 SETUP 패킷이 오지 않다는..Recovery가 되질 않는다. */

    dep->flags |= DWC3_EP_STALL;
    NC_USB_Ep0_Send_Command(0U, DWC3_DEPCMD_SETSTALL, &params);
    
    while (timeout > 0U)
    {
        /* Software sets this bit to 1 to enable the device endpoint controller to execute the generic command.
        The device controller sets this bit to 0 when the CmdStatus field is valid and the endpoint is ready
        to accept another command. This does not imply that all the effects of the previously-issued command
        have taken place. */
        DEPCMD_T endpoint_cmd;
        endpoint_cmd.depcmd.dw = NC_DWC3_Read(DWC3_DEPCMD(0U));

        if (endpoint_cmd.depcmd.b.CMDACT == FALSE) {
            break;
        }

        timeout--;

        /* ASSERT_USB(timeout != 0, ASSERT_NO_0020); */

        nc_mdelay(1U);
    } 

    /* Setup 패킷 수신을 위한 준비 */
    NC_USB_Ep0_Out_Start(ptBootUsbCtx);
    NC_USB_Enable_Interrupt();
    ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;  
#ifdef DEBUG_ENABLE_            
    DBGUSB(MSGERR, "%s: STALL handling complete, ready for next SETUP\n", __func__);
#endif    
}

/* ===================================================================

=================================================================== */
#if 0
void DEBUG_FUNC_ATTR NC_USB_Ep0_Handle_XferComplete(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 req_stat = TRUE;
    /* UINT32 epnum = ptBootUsbCtx->dwc3_event.endpoint_event.endpoint_number; */
    /* DWC3_EP_T *dep = &ptBootUsbCtx->eps[epnum]; */

    USB_CTRL_REQUEST_T *ctrl = &ptBootUsbCtx->ctrl_req;
    UINT8 req_type = ctrl->bRequestType & USB_TYPE_MASK;
#ifdef DEBUG_ENABLE_            
    DBGUSB(MSGDBG, "SETUP: bmRequestType=0x%x, bRequest=0x%x, wValue=0x%x, wIndex=0x%x, wLength=%d\n",
               ctrl->bRequestType, ctrl->bRequest,
               ctrl->wValue, ctrl->wIndex, ctrl->wLength);
#endif
    switch (req_type) 
    {
        case USB_TYPE_STANDARD:
            NC_USB_Ep0_Standard_Request(ptBootUsbCtx);
            break;
        case USB_TYPE_VENDOR:
            NC_USB_Ep0_Vendor_Request(ptBootUsbCtx);
            break;
        default:
            DBGUSB(MSGERR, "Unknown request type: 0x%x\n", req_type);
            NC_USB_Ep0_Handle_Stall(ptBootUsbCtx);
            req_stat = FALSE;
    }

    if(req_stat == TRUE) {
        /* Write additional code if req_type value exists */
    }
    
    return;
}
#endif
/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Prepare_Data_Phase(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 ep_num = ((ptBootUsbCtx->ctrl_req.bRequestType & (UINT8)USB_DIR_IN) != 0U) ? 1U : 0U;
    USB_REQUEST_T *req = &ptBootUsbCtx->req[ep_num];
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[ep_num];
    UINT64_T buffer_addr;
    UINT32 length;

    if ((ptBootUsbCtx->header_transferred == (BOOL)TRUE) || 
        (ptBootUsbCtx->binary_transferred == (BOOL)TRUE))
    {
        /* 최대 바이트 수보다 적은 데이터를 받을 경우 (Shor packet) 처리 -> ZLP??? */
        req = &ptBootUsbCtx->vendor_req;
        length = ptBootUsbCtx->allocated_data_length;
    }
    else
    {
        length = req->length;
    }

    NC_Memset_u08(&buffer_addr, (UINT8)0, (INT32)sizeof(buffer_addr));
    buffer_addr.dw[0] = (UINT32)(req->buf + req->offset);

    NC_USB_Ep0_Prepare_One_TRB(ptBootUsbCtx, buffer_addr, length, DWC3_TRBCTL_CONTROL_DATA);
    NC_USB_Ep0_Start_Transfer(ptBootUsbCtx, dep);

}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_Process_Data_Transfer(UDC_CTX_T *ptBootUsbCtx) 
{
    /* UINT32 ep_num = ptBootUsbCtx->dwc3_event.endpoint_event.endpoint_number; */
    USB_REQUEST_T *req = &ptBootUsbCtx->vendor_req;
    /* DWC3_TRB_T *trb = &ptBootUsbCtx->ep0_trb; */

    req->actual += req->length;
    req->offset += req->length;
    
    /* 분할 전송(64바이트) 누적 바이트, 이것은 split_transfer_bytes_expected 값과 일치해야 한다. */
    ptBootUsbCtx->num_bytes_per_split_transfer = req->actual; 

}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Ep0_State_Transition(UDC_CTX_T *ptBootUsbCtx, UINT32 ep_event) 
{
    UINT32 ep0_state = ptBootUsbCtx->ep0state;
    /* UINT32 status = ptBootUsbCtx->dwc3_event.endpoint_event.status; */
    UINT32 ep_num = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.endpoint_number;
    UINT32 real_bytes;

    switch (ep0_state) 
    {
        case (UINT32)EP0_STATE_SETUP_PHASE:
            /* DBGUSB(MSGDBG, "%s: EP0_STATE_SETUP_PHASE\n", __func__); */
            /* ===================================================================
            Setup Phase
            =================================================================== */
            if (ep_event == DWC3_DEPEVT_XFERCOMPLETE) 
            {
                NC_USB_Ep0_Handle_Setup_Stage(ptBootUsbCtx);
            
                if (ptBootUsbCtx->ctrl_req.wLength == (UINT16)0) 
                {
                    /* set address 의 경우 데이터가 없고 바로 상태 단계로 간다 -> EP 1, 즉 status-in 안맞는다?? */
                    ptBootUsbCtx->ep0state = ((ptBootUsbCtx->ctrl_req.bRequestType & (UINT8)USB_DIR_IN) != 0U) ? 
                                    (UINT32)EP0_STATE_STATUS_IN_PHASE : (UINT32)EP0_STATE_STATUS_OUT_PHASE;
                } 
                else 
                {
                    ptBootUsbCtx->ep0state = ((ptBootUsbCtx->ctrl_req.bRequestType & (UINT8)USB_DIR_IN) != 0U) ? 
                                    (UINT32)EP0_STATE_DATA_IN_PHASE : (UINT32)EP0_STATE_DATA_OUT_PHASE;
                    NC_USB_Ep0_Prepare_Data_Phase(ptBootUsbCtx);
                }

            } 
            else 
            {
                NC_USB_Ep0_Handle_Stall(ptBootUsbCtx);
            }
            break;

        case (UINT32)EP0_STATE_DATA_IN_PHASE:
        case (UINT32)EP0_STATE_DATA_OUT_PHASE:
            /* DBGUSB(MSGDBG, "%s: %s\n", __func__, ep0_state == EP0_STATE_DATA_IN_PHASE ? "EP0_STATE_DATA_IN_PHASE" : "EP0_STATE_DATA_OUT_PHASE"); */
            /* ===================================================================
            Data Phase
            =================================================================== */        
            if (ep_event == DWC3_DEPEVT_XFERCOMPLETE) 
            {
                if (ptBootUsbCtx->binary_transferred == TRUE)
                {
                    USB_REQUEST_T *req = &ptBootUsbCtx->vendor_req;
                    
                    NC_USB_Ep0_Process_Data_Transfer(ptBootUsbCtx);

                    /* if (ptBootUsbCtx->binary_transferred == TRUE)
                    { */
                        /* 예: 호스트에서 4k chunk 를 보내는 시나리오, 트랜젝션은 64바이트로 받는다. */
                        if (ptBootUsbCtx->split_transfer_bytes_expected > ptBootUsbCtx->num_bytes_per_split_transfer)
                        {
                            ptBootUsbCtx->ep0state = (((ep_num & 1U) != 0U) ? (UINT32)EP0_STATE_DATA_IN_PHASE : (UINT32)EP0_STATE_DATA_OUT_PHASE);
                            NC_USB_Ep0_Prepare_Data_Phase(ptBootUsbCtx);     
                            ptBootUsbCtx->accumulation_received_bytes += req->length;  
                        }
                        else
                        {
                            ptBootUsbCtx->ep0state = ((ptBootUsbCtx->ep0state == (UINT32)EP0_STATE_DATA_IN_PHASE) ?  (UINT32)EP0_STATE_STATUS_OUT_PHASE : (UINT32)EP0_STATE_STATUS_IN_PHASE);
                            real_bytes = ptBootUsbCtx->split_transfer_bytes_expected % 64U;
                            ptBootUsbCtx->accumulation_received_bytes += ((real_bytes != 0U) ? real_bytes : req->length);
                        }

                        #if (ENABLE_USB_BYTES_PROGRESS==1)
                        {
#ifdef DEBUG_ENABLE_            
                            DBGUSB(MSGINFO, " Binary %s: %d / %d bytes\r", 
                                                        ptBootUsbCtx->accumulation_received_bytes < ptBootUsbCtx->total_bytes_expected ? 
                                                        "Downloading" : "Downloading Complete!!",
                                                        ptBootUsbCtx->accumulation_received_bytes,
                                                        ptBootUsbCtx->total_bytes_expected);
#endif

                            if (ptBootUsbCtx->accumulation_received_bytes == ptBootUsbCtx->total_bytes_expected)
                            {
                                /* r5_usb_show_bin_info(); */

                                ptBootUsbCtx->firmware_downloading_complete = TRUE;
                                ptBootUsbCtx->total_bytes_received = ptBootUsbCtx->accumulation_received_bytes;
                            }
                        }
                        #else
                        {
                            if (ptBootUsbCtx->accumulation_received_bytes == ptBootUsbCtx->total_bytes_expected)
                            {
#ifdef DEBUG_ENABLE_            
                                DBGUSB(MSGINFO, " Binary %s: %d / %d bytes\r", 
                                                        ptBootUsbCtx->accumulation_received_bytes < ptBootUsbCtx->total_bytes_expected ? 
                                                        "Downloading" : "Downloading Complete!!",
                                                        ptBootUsbCtx->accumulation_received_bytes,
                                                        ptBootUsbCtx->total_bytes_expected);
#endif
                                ptBootUsbCtx->firmware_downloading_complete = TRUE;
                                ptBootUsbCtx->total_bytes_received = ptBootUsbCtx->accumulation_received_bytes;
                            }

                        }
                        #endif
                    /* } */
                }

                if (ptBootUsbCtx->header_transferred == TRUE)
                {
                    USB_CTRL_REQUEST_T *ctrl = &ptBootUsbCtx->ctrl_req;

                    if (ctrl->bRequest == (UINT8)USB_REQ_VENDOR_NC_FWDN_HEADER)
                    {
                        tBOOT_HDR *bin_header = (tBOOT_HDR*)ptBootUsbCtx->hdraddr.dw[0];
                        ptBootUsbCtx->total_bytes_expected = bin_header->mLength;
                    }
                }
            } 
            else if (ep_event == DWC3_DEPEVT_XFERNOTREADY) 
            {
                NC_USB_Ep0_Handle_XferNotReady(ptBootUsbCtx);
            } 
            else 
            {
                NC_USB_Ep0_Handle_Stall(ptBootUsbCtx);
            }
            break;

        case (UINT32)EP0_STATE_STATUS_IN_PHASE:
        case (UINT32)EP0_STATE_STATUS_OUT_PHASE:
#ifdef DEBUG_ENABLE_                    
            DBGUSB(MSGDBG, "%s: %s\n", __func__, ep0_state == EP0_STATE_STATUS_IN_PHASE ? "EP0_STATE_STATUS_IN_PHASE" : "EP0_STATE_STATUS_OUT_PHASE");
#endif            
            /* ===================================================================
            Status Phase
            =================================================================== */
            if (ep_event == DWC3_DEPEVT_XFERCOMPLETE) 
            {
                ptBootUsbCtx->header_transferred = FALSE;
                ptBootUsbCtx->binary_transferred = FALSE;

                NC_USB_Ep0_Out_Start(ptBootUsbCtx);
                NC_USB_Enable_Interrupt();                
                ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;
            } 
            else if (ep_event == DWC3_DEPEVT_XFERNOTREADY) 
            {
                NC_USB_Ep0_Handle_XferNotReady(ptBootUsbCtx);
            } 
            else 
            {
                NC_USB_Ep0_Handle_Stall(ptBootUsbCtx);
            }
            break;

        case (UINT32)EP0_STATE_STALL_PHASE:
            /* ===================================================================
            EP0 Stall 
            =================================================================== */
            if (ep_event == DWC3_DEPEVT_XFERCOMPLETE) 
            {
                ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;
                NC_USB_Ep0_Handle_Setup_Stage(ptBootUsbCtx);
            }
            break;
        default:
            NC_USB_Ep0_Handle_Stall(ptBootUsbCtx);
            break;
    }
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Ep0_Event(UDC_CTX_T *ptBootUsbCtx)
{
    DWC3_EVENT_DEPEVT_T ep_event;
    
    ep_event = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event;

    switch(ep_event.endpoint_event)
    {    
        case DWC3_DEPEVT_XFERCOMPLETE:
#ifdef DEBUG_ENABLE_                    
            DBGUSB(MSGDBG, "%s:DWC3_DEPEVT_XFERCOMPLETE\n", __func__);
#endif            
            break;
        case DWC3_DEPEVT_XFERNOTREADY:
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGDBG, "%s:DWC3_DEPEVT_XFERNOTREADY\n", __func__);
#endif            
            break;
        case DWC3_DEPEVT_XFERINPROGRESS:
        case DWC3_DEPEVT_RXTXFIFOEVT:
        case DWC3_DEPEVT_STREAMEVT:
        case DWC3_DEPEVT_EPCMDCMPLT:
        default:
            DBGUSB(MSGERR, "%s:Unknown EP event : 0x%x\n", __func__, ep_event);
            break;
    }

    NC_USB_Ep0_State_Transition(ptBootUsbCtx, ep_event.endpoint_event);    
}
