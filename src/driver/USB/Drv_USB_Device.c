#include "Apache.h"
#include "Drv_USB_FEATURE.h"
#include "Drv_USB_REGS.h"

#include "Drv_USB_Core.h"
#include "Drv_USB_Ep0.h"
#include "Drv_USB_Descriptor.h"
#include "Drv_USB_Device.h"
#include "Drv_USB.h"

#include "MPU.h"
/* ===================================================================
 Function Declaration
=================================================================== */
#ifdef DEBUG_ENABLE_
const char *NC_USB_Get_Link_State(UINT32 iIdx);
#endif

/* ==================================================================
엔드포인트0 디스크립터
=================================================================== */


/* ===================================================================
Global USB request buffer (0, 1), MaxPacketSize 64Byte
=================================================================== */
/* PRQA S 3218++ */
static UINT8 g_usb_req_buffer[USB_ENDPOINTS_NUM][64] DEBUG_DATA_ATTR(4);

/* PRQA S 3218-- */
/* ===================================================================

=================================================================== */
#ifdef DEBUG_ENABLE_
const char DEBUG_FUNC_ATTR *NC_USB_Get_Link_State(UINT32 iIdx)
{
    const char *szLinkState;

    switch(iIdx)
    {
        case 0: szLinkState = (const char *)"U0"; break;
        case 1: szLinkState = (const char *)"U1"; break;
        case 2: szLinkState = (const char *)"U3"; break;
        case 3: szLinkState = (const char *)"SS_DIS"; break;
        case 4: szLinkState = (const char *)"RX_DET"; break;
        case 5: szLinkState = (const char *)"SS_INACT"; break;
        case 6: szLinkState = (const char *)"POLL"; break;
        case 7: szLinkState = (const char *)"RECOV"; break;
        case 8: szLinkState = (const char *)"HRESET"; break;
        case 9: szLinkState = (const char *)"CMPLY"; break;
        case 10: szLinkState = (const char *)"LPBK"; break;
        case 11: szLinkState = (const char *)"RESET"; break;
        case 12: szLinkState = (const char *)"RESUME"; break;
        default: szLinkState = (const char *)"None"; break;
    }
    return szLinkState;
}

const static char DEBUG_FUNC_ATTR *NC_USB_Get_Device_State(UINT32 iIdx)
{    
    const char *szDevState;

    switch(iIdx)
    {
        case 0: szDevState = (const char *)"PREPARE_INIT"; break;
        case 1: szDevState = (const char *)"NOTATTACHED"; break;
        case 2: szDevState = (const char *)"ATTACHED"; break;
        case 3: szDevState = (const char *)"RESET"; break;
        case 4: szDevState = (const char *)"SETUP"; break;
        case 5: szDevState = (const char *)"ADDRESS"; break;
        case 6: szDevState = (const char *)"CONFIGURED"; break;
        case 7: szDevState = (const char *)"SUSPENDED"; break;
        default: szDevState = (const char *)"None";   break;

    }
    return szDevState;
}
#endif

static void DEBUG_FUNC_ATTR NC_USB_Init_Ep0_Desc(USB_ENDPOINT_DESCRIPTOR_T *pDeviceEp0Desc)
{
    pDeviceEp0Desc->bLength            = sizeof(USB_ENDPOINT_DESCRIPTOR_T); /*USB_DT_ENDPOINT, */
    pDeviceEp0Desc->bDescriptorType    = USB_DT_ENDPOINT;
    pDeviceEp0Desc->bmAttributes       = USB_ENDPOINT_XFER_CONTROL;
    pDeviceEp0Desc->wMaxPacketSize     = 64;
    /* 
    pDeviceEp0Desc->bEndpointAddress = ep_num | (direction ? USB_DIR_IN : 0);
    pDeviceEp0Desc->bmAttributes = type;
    pDeviceEp0Desc->wMaxPacketSize = max_packet_size;
    pDeviceEp0Desc->bInterval = 0;
     */
}


void DEBUG_FUNC_ATTR NC_USB_Device_Show_State(UDC_CTX_T *ptBootUsbCtx)
{
    if(ptBootUsbCtx->device_state != ptBootUsbCtx->old_state) {
#ifdef DEBUG_ENABLE_         
        DEBUGMSG(MSGINFO, " usb state: %s => %s\n",
                 NC_USB_Get_Device_State((UINT32)ptBootUsbCtx->old_state), 
                 NC_USB_Get_Device_State((UINT32)ptBootUsbCtx->device_state) );
#endif
        ptBootUsbCtx->old_state = ptBootUsbCtx->device_state;
    }
}

/* ===================================================================

 ===================================================================*/
void DEBUG_FUNC_ATTR NC_USB_Prepare_Endpoint(UDC_CTX_T *ptBootUsbCtx)
{
    UINT8 epnum;

    NC_Memset_u08(g_usb_req_buffer, (UINT8)0, (INT32)(sizeof(g_usb_req_buffer)));

    for (epnum = 0U; epnum < (UINT8)USB_ENDPOINTS_NUM; epnum++)
    {
        /* usb request buffer memory allocations */
        USB_REQUEST_T *req = &ptBootUsbCtx->req[epnum];

        /* logical endpoint init */
        DWC3_EP_T *dep = &ptBootUsbCtx->eps[epnum];        

        dep->number = epnum;
        dep->direction = epnum;
        dep->maxpacket = 64; /* USB3.0 512 */
        
        req->buf = g_usb_req_buffer[epnum];
        /* PRQA S 0306 ++ */
        req->addr = (UINT64)req->buf;
        /* PRQA S 0306 -- */
    }

    NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_PREPARE_INIT);
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Device_Change_State(UDC_CTX_T *ptBootUsbCtx, UINT8 state)
{
    if (ptBootUsbCtx->device_state != state) {
        ptBootUsbCtx->device_state = state;
    }
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Clear_Stall_All_Ep(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 epnum = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.endpoint_number;
    UINT32 ep_stall_status = TRUE;
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[epnum];

    if ((dep->flags & DWC3_EP_STALL) == FALSE) {
        ep_stall_status = FALSE;   
    }

    if(ep_stall_status == TRUE) {
        dep->flags &= ~DWC3_EP_STALL;
    }

    /* 
        4.2.7 Handling ENDPOINT_HALT
        "For control endpoints, the application issues only the Set Stall command, 
        and only on the OUT direction of the control endpoint. 
        The controller automatically clears the STALL when it receives a SETUP token for the endpoint. 
        The application must not issue the Clear Stall command on a control endpoint."
        
        엔드포인트 0 에는 CLEAR STALL 을 할 필요없다.
        Setup Packet을 받으면 하드웨어가 자동으로 클리어 하기 때문..
     */
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Disconnect(UDC_CTX_T *ptBootUsbCtx)
{
    /* 
        4.1.8 어플리케이션이 호스트에서 연결 해제를 원한며 다음 작업을 수행해야 한다.
        DEPCMD0 (Congiure-Setup TRP / Start Transfer 상태로 간다)
        DEPCMDn : Active Transfer 에 대해 DEPENDXFER command 를 Issue 한다. (ep0 제외)
        DCTL : DCTL.RunStop -> 0으로 설정하여 호스트에서 연결을 해제한다.
        DSTS : DevCtrHlt -> 1 이 될 때까지 폴링한다.
     */
    DCTL_T device_ctrl;
    device_ctrl.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
    /*
        Initiate U1 Enable
        ■ 1'b0: May not initiate U1 (default);
        ■ 1'b1: May initiate U1.
        On USB reset, hardware clears this bit to 0. Software sets this
        bit after receiving SetFeature(U1_ENABLE), and clears this bit
        when ClearFeature(U1_ENABLE) is received.
        If DCTL[9] (AcceptU1Ena) is 0, the link immediately exits U1 state.
    */
    device_ctrl.dctl.b.INITU1ENA = 0x0;
    device_ctrl.dctl.b.INITU2ENA = 0x0;
    NC_DWC3_Write(DWC3_DCTL, device_ctrl.dctl.dw);

    ptBootUsbCtx->usb_device_speed = (UINT8)USB_SPEED_UNKNOWN;
    /* ptBootUsbCtx->setup_packet_pending = FALSE; */
    /* ptBootUsbCtx->connected = FALSE; */
    ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;
    ptBootUsbCtx->num_bytes_per_split_transfer = 0U;
    ptBootUsbCtx->accumulation_received_bytes = 0U;

    NC_Memset_u08(&ptBootUsbCtx->vendor_req, (UINT8)0, (INT32)(sizeof(USB_REQUEST_T)));
    NC_Memset_u08(&ptBootUsbCtx->ctrl_req, (UINT8)0, (INT32)(sizeof(USB_CTRL_REQUEST_T)));

    /* test */
    NC_USB_Device_Clear_Stall_All_Ep(ptBootUsbCtx);

    NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_NOTATTACHED);
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Reset(UDC_CTX_T *ptBootUsbCtx)
{
    DCFG_T device_cfg;

    /* 
        DEVT.USBRst 이벤트가 왔을 때 호출되는 함수.
        이는 USB에서 리셋이 감지되었음을 나타냄. 
        여기에서 4.1.2 USB Reset Init 에 기술된 단계를 수행해야 한다.

        DEPCMD0 : Congtrol Transfer 진행 중인 경우는 완료하고 -> Control-Setup TRP / Start Transfer 상태로 간다
        DEPCMDn : Issue a DEPENDXFER command for any active transfers (except ep0)
        DEPCMDn : USB Reset 전 Stall 모드에 있는 엔드포인트에 대해 DEPCSTALL(Stall 해제) 명령을 설정 (ep0 제외)
    */
    DCTL_T device_ctrl;
    device_ctrl.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
    device_ctrl.dctl.b.TSTCTL = 0x0;
    NC_DWC3_Write(DWC3_DCTL, device_ctrl.dctl.dw);
    
    NC_USB_Device_Clear_Stall_All_Ep(ptBootUsbCtx);

    /* Set DevAddr to ‘0’ */
    device_cfg.dcfg.dw = NC_DWC3_Read(DWC3_DCFG);
    device_cfg.dcfg.b.DEVADDR = 0x0;
    NC_DWC3_Write(DWC3_DCFG, device_cfg.dcfg.dw);

    NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_RESET);
    ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Ep_Config(const UDC_CTX_T *ptBootUsbCtx, const DWC3_EP_T *dep, UINT32 action)
{
    UINT32 cmd;
    /* 
        Issue a DEPCFG command (with Config Action set to “Modify”) for physical endpoints 0 & 1 
        using the same endpoint characteristics from Power-On Reset, 
        but set MaxPacketSize to 512 (SuperSpeed), 64 (High-Speed), 8/16/32/64 (Full-Speed), or 8 (Low-Speed).
     */
    DWC3_EP_CMD_PARAMS_T params;
    NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));
    /* 
        bLength: 디스크립터의 길이.
        bDescriptorType: 디스크립터 타입(엔드포인트 디스크립터는 항상 0x05).
        bEndpointAddress: 엔드포인트 주소 및 방향.
        bmAttributes: 전송 타입(제어, 동기화, 버스트 등).
        wMaxPacketSize: 이 엔드포인트에서 전송할 수 있는 최대 패킷 크기.
        bInterval: 데이터 전송 간격(인터럽트, 등시성 전송에 사용).
    */
    params.param0 = DWC3_DEPCFG_EP_TYPE((UINT32)ptBootUsbCtx->dev_ep0_desc.bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) | 
			                    DWC3_DEPCFG_MAX_PACKET_SIZE(ptBootUsbCtx->dev_ep0_desc.wMaxPacketSize);

    /*
        Config Action
        ■ 0 Initialize endpoint state: This action is used when an endpoint is configured the first time. 
            It will cause the data sequence number and flow control state to be reset. 
            DEPCMDPAR2 will be ignored. 
            The encoding of this action is backward compatible with software that previously set "Ignore Sequence Number" to 0.
        ■ 1 Restore endpoint state: This action is used when reconfiguring an endpoint with saved state after hibernation. 
            It will cause the data sequence number and flow control state to be restored from DEPCMDPAR2.
        ■ 2 Modify endpoint state: This action is used when modifying an existing endpoint configuration, 
            such as changing the DEPEVTEN event enable bits, interrupt number, or MaxPacketSize. 
            The data sequence number and flow control state will be unchanged, and DEPCMDPAR2 will be ignored. 
            The encoding of this action is backward compatible with software that previously set "Ignore Sequence Number" to 1.
        
            When issuing a Endpoint Configuration command with Config Action=Restore, 
            Parameter 2 must be filled in with the same value returned by the Get Endpoint State command prior to hibernation.
    */
    params.param0 |= action;    /* DWC3_DEPCFG_IGN_SEQ_NUM */

    params.param1 = ((UINT32)DWC3_DEPCFG_XFER_COMPLETE_EN | (UINT32)DWC3_DEPCFG_XFER_NOT_READY_EN);
    /* 
    if ((ptBootUsbCtx->dev_ep0_desc.bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) != USB_ENDPOINT_XFER_CONTROL)
       params.param1 |= DWC3_DEPCFG_XFER_IN_PROGRESS_EN;
     */
    params.param1 |= DWC3_DEPCFG_EP_NUMBER(dep->number);
    /* 
        (optional) Based on the new MaxPacketSize of IN endpoint 0, 
        software may choose to re-allocate the TX FIFO sizes by writing to these registers.
    */
    if (dep->direction != FALSE) {
        params.param0 |= DWC3_DEPCFG_FIFO_NUMBER((UINT32)dep->number >> 1);
    }
    
    cmd = DWC3_DEPCMD_SETEPCONFIG;
    NC_USB_Ep0_Send_Command(dep->number, cmd, &params);

}

/* ===================================================================

=================================================================== */
/* rcma-2.0.0-1503 not used */
#if 0
void DEBUG_FUNC_ATTR NC_USB_Device_Set_Xfer_Resource(UDC_CTX_T *ptBootUsbCtx, UINT32 ep_num)
{
    UINT32 cmd;
    DWC3_EP_CMD_PARAMS_T params;
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[ep_num];

    NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));
    /* 설정 방법의 의도에 대해서 스펙에서 확인 필요 */
    params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);

    cmd = DWC3_DEPCMD_SETTRANSFRESOURCE;
    NC_USB_Ep0_Send_Command(dep->number, cmd, &params);
}
#endif
/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Ep_Enable(UDC_CTX_T *ptBootUsbCtx, DWC3_EP_T *dep, UINT32 action)
{
    /*
        Software can issue physical endpoint-specific commands using 
        DEPCMDn, DEPCMDPAR0n, DEPCMDPAR1n, and DEPCMDPAR2n registers. 
        For register descriptions, see “Register Descriptions” on page 17.    

        endpoint new configuration 
    */
    #if (1)
    {
        if ((dep->flags & DWC3_EP_ENABLED) == FALSE)
        {
            UINT32 new_config_cmd;
            /* 엔드포인트 0 설정 */
            if ((UINT32)dep->number == 0U)
            {
                DWC3_EP_CMD_PARAMS_T params;
                NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));
                /* 
                    3.2.2.8Command 9: Start New Configuration (DEPSTARTCFG)
                    After power-on-reset with XferRscIdx=0 before starting to configure Endpoints 0 and 1.
                    CmdIOC must be set to '0' and software must poll the CmdAct bit to determine when 
                    the command is complete because Endpoint 0 is not yet configured with a valid interrupt number.
                    With XferRscIdx=2 when it receives SetConfiguration before starting to configure Endpoints > 1.
                    CmdIOC may be set to '0' or '1'.
                 */
                new_config_cmd = DWC3_DEPCMD_DEPSTARTCFG;
                NC_USB_Ep0_Send_Command(dep->number, new_config_cmd, &params);
                /*
                    FIXME: resouce 프로그램 순서에 따라 컨트롤러 동작이 상이해진다.
                    set xfer resource
                    MEM_SET(&params, 0x0, sizeof(params));
                    params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);
                    UINT32 transfer_res_cmd = DWC3_DEPCMD_SETTRANSFRESOURCE;
                    NC_USB_Ep0_Send_Command(dep->number, transfer_res_cmd, &params);
                */

            }
        }

        NC_USB_Device_Ep_Config(ptBootUsbCtx, dep, action);
    }
    #endif

    if ((dep->flags & DWC3_EP_ENABLED) == FALSE)
    {
        UINT32 transfer_res_cmd;
        UINT32 active_ep;
        UINT8 desc_type;
        /* 전송 리소스 인덱스 할당. */
        DWC3_EP_CMD_PARAMS_T params;
        NC_Memset_u08(&params, (UINT8)0, (INT32)sizeof(params));
        params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);
        transfer_res_cmd = (UINT32)DWC3_DEPCMD_SETTRANSFRESOURCE;
        NC_USB_Ep0_Send_Command(dep->number, transfer_res_cmd, &params);

        /* 컨트롤 전송이어야 한다. */
        desc_type = ptBootUsbCtx->dev_ep0_desc.bmAttributes & (UINT8)USB_ENDPOINT_XFERTYPE_MASK;
        ASSERT_USB(desc_type == USB_ENDPOINT_XFER_CONTROL, ASSERT_NO_0009);
        if(desc_type == (UINT8)0) {}

        dep->type = USB_ENDPOINT_XFER_CONTROL;
        dep->flags |= DWC3_EP_ENABLED;

        /* 
            엔드포인트 활성화 
            This register indicates whether a USB endpoint is active in a given configuration or interface
            ne bit for each of the 32 possible endpoints. 
            Even numbers are for USB OUT endpoints, and odd numbers are for USB IN endpoints.
            ■ Bit[0]: USB EP0-OUT
            ■ Bit[1]: USB EP0-IN
            ■ Bit[2]: USB EP1-OUT
            ■ Bit[3]: USB EP1-IN 
        */

        active_ep = NC_DWC3_Read(DWC3_DALEPENA);
        active_ep |= DWC3_DALEPENA_EP(dep->number);
        NC_DWC3_Write(DWC3_DALEPENA, active_ep);
    }

}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Device_Start(UDC_CTX_T *ptBootUsbCtx)
{
    #define EP_DIR_OUT      0
    #define EP_DIR_IN       1
    DWC3_EP_T *dep;
    
    NC_USB_Init_Ep0_Desc(&ptBootUsbCtx->dev_ep0_desc);

    /* endpoint enable */
    dep = &ptBootUsbCtx->eps[EP_DIR_OUT];
    ASSERT_USB(dep->number == 0, ASSERT_NO_0010);
    ASSERT_USB(dep->direction == !!dep->number, ASSERT_NO_0011);
    NC_USB_Device_Ep_Enable(ptBootUsbCtx, dep, (UINT32)DWC3_DEPCFG_ACTION_INIT);

    dep = &ptBootUsbCtx->eps[EP_DIR_IN];
    ASSERT_USB(dep->number == 1, ASSERT_NO_0012);
    ASSERT_USB(dep->direction == !!dep->number, ASSERT_NO_0013);
    NC_USB_Device_Ep_Enable(ptBootUsbCtx, dep, DWC3_DEPCFG_ACTION_INIT);

    ptBootUsbCtx->ep0state = (UINT32)EP0_STATE_SETUP_PHASE;
    ptBootUsbCtx->link_state = (UINT32)DWC3_LINK_STATE_SS_DIS;

    /* ep0 be ready!! */
    NC_USB_Ep0_Out_Start(ptBootUsbCtx);

    NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_NOTATTACHED);
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Connection_Done(UDC_CTX_T *ptBootUsbCtx)
{
    /* 
        Wait for a DEVT.ConnectionDone event. 
        This event indicates the end of the reset on the USB. 
        On this event, read the DSTS register to get the connection speed. 
        On this event, the application needs to perform the steps 
        listed in section Initialization on Connect Done.
    */

    DSTS_T device_status;
    DCFG_T device_config;
    DCTL_T device_control;
    DWC3_EP_T *dep;
    /* Read this register to obtain the connection speed. */
    device_status.dsts.dw = NC_DWC3_Read(DWC3_DSTS);   
    
    if (device_status.dsts.b.CONNECTSPD == (UINT32)DWC3_DSTS_HIGHSPEED)
    {
        ptBootUsbCtx->dev_ep0_desc.wMaxPacketSize = 64;
        ptBootUsbCtx->usb_device_speed = (UINT8)USB_SPEED_HIGH;
    }
    /* 
        GCTL Programming
        Program the RAMClkSel field to select the correct clock for the RAM clock domain. 
        This field is reset to 0 after USB reset, so it must be reprogrammed each time on Connect Done.
    */
    /* 
        LPM Capable
        The application uses this bit to control the LPM capabilities of the DWC_usb3 controller. 
        If the controller operates as a non-LPM-capable device, it cannot respond to LPM transactions.
    */
    device_config.dcfg.dw = NC_DWC3_Read(DWC3_DCFG);
    device_config.dcfg.b.LPMCAP = 0x1;
    NC_DWC3_Write(DWC3_DCFG, device_config.dcfg.dw);

    device_control.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
    device_control.dctl.b.L1HibernationEn = 0x0;
    device_control.dctl.b.HIRDTHRES = 0x12;
    NC_DWC3_Write(DWC3_DCTL, device_control.dctl.dw);

    dep = &ptBootUsbCtx->eps[0];
    NC_USB_Device_Ep_Enable(ptBootUsbCtx, dep, (UINT32)DWC3_DEPCFG_ACTION_MODIFY);
    dep = &ptBootUsbCtx->eps[1];
    NC_USB_Device_Ep_Enable(ptBootUsbCtx, dep, (UINT32)DWC3_DEPCFG_ACTION_MODIFY);

    NC_USB_Device_Change_State(ptBootUsbCtx, USB_STATE_ATTACHED);
}

/* ===================================================================

=================================================================== */
#if 0
static void DEBUG_FUNC_ATTR NC_USB_Device_Wake_Up(void)
{
	/* DBGUSB(MSGINFO,  "%s:\n", __func__); */
}
#endif

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Link_Status_Change(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 next = ptBootUsbCtx->dwc3_event.dwc3_event_union.device_event.event_info & (UINT32)DWC3_LINK_STATE_MASK;

#ifdef DEBUG_ENABLE_
	DBGUSB(MSGDBG," usb speed:%d, link_state:[%s => %s] \n",
                    ptBootUsbCtx->usb_device_speed,
                    NC_USB_Get_Link_State(ptBootUsbCtx->link_state),
                    NC_USB_Get_Link_State(next));
#endif
	ptBootUsbCtx->link_state = next;

}

/* ===================================================================
device-specific event (DEVT) handler
=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Device_Interrupt_Handler(UDC_CTX_T *ptBootUsbCtx)
{
    UINT32 event_type = ptBootUsbCtx->dwc3_event.dwc3_event_union.device_event.type;

    switch (event_type)
    {
        case DWC3_DEVICE_EVENT_DISCONNECT:
            NC_USB_Device_Disconnect(ptBootUsbCtx);
            break;
        case DWC3_DEVICE_EVENT_RESET:
            NC_USB_Device_Reset(ptBootUsbCtx);
            break;      
        case DWC3_DEVICE_EVENT_CONNECT_DONE:
            /* At this point, the device is ready to receive micro-SOF/ITP and is configured 
            to receive control transfers on control endpoint 0 with a new address assigned. */                        
            NC_USB_Device_Connection_Done(ptBootUsbCtx);
            break;        
        case DWC3_DEVICE_EVENT_WAKEUP:
            /* NC_USB_Device_Wake_Up(); */ /* qac-9.6.0-2987 this function call produces no side effects and is redundant */
            break;               
        case DWC3_DEVICE_EVENT_LINK_STATUS_CHANGE:
            NC_USB_Device_Link_Status_Change(ptBootUsbCtx);
            break;
#ifdef DEBUG_ENABLE_
        case DWC3_DEVICE_EVENT_HIBER_REQ:       
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_HIBER_REQ\n", __func__); 
        case DWC3_DEVICE_EVENT_EOPF:            
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_EOPF\n", __func__);        
        case DWC3_DEVICE_EVENT_SOF:             
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_SOF\n", __func__);        
        case DWC3_DEVICE_EVENT_ERRATIC_ERROR:   
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_ERRATIC_ERROR\n", __func__);        
        case DWC3_DEVICE_EVENT_CMD_CMPL:        
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_CMD_CMPL\n", __func__);        
        case DWC3_DEVICE_EVENT_OVERFLOW:        
            DBGUSB(MSGDBG,  "%s: DWC3_DEVICE_EVENT_OVERFLOW\n", __func__);                    
            break;
#endif            
        default:
            DBGUSB(MSGERR, "%s: Unknown usb device event!!\n", __func__);
            break;
    }
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Process_Event_Buffer_Entry(UDC_CTX_T *ptBootUsbCtx)
{
    /* fetch event from controller */
    ptBootUsbCtx->dwc3_event.dwc3_event_union.raw = *(UINT32*)((UINT8*)ptBootUsbCtx->event.buf + ptBootUsbCtx->event.lpos);
#ifdef DEBUG_ENABLE_    
    /* DBGUSB(MSGDBG,  "\n\n%s: event buffer (0x%x) lpos:%d\n", __func__, ptBootUsbCtx->dwc3_event.raw, ptBootUsbCtx->event.lpos); */
#endif
    /* endpoint or device event parsing */
    if (ptBootUsbCtx->dwc3_event.dwc3_event_union.type.is_devspec == 0U)
    {
        NC_Endpoint_Interrupt_Handler(ptBootUsbCtx); 
    }
    else if (ptBootUsbCtx->dwc3_event.dwc3_event_union.type.type == (UINT8)DWC3_EVENT_TYPE_DEV)
    {
        NC_USB_Device_Interrupt_Handler(ptBootUsbCtx);
    }
    else
    {
        ASSERT_USB(FALSE,  ASSERT_NO_0014);
    }
    
    NC_USB_Device_Show_State(ptBootUsbCtx);

/*     The first event produced by the controller after the Event Buffer is configured 
    is written to the address specified in GEVNTADRn.
    Most events are 32 bits, and subsequent events are written to the address (PreviousEventAddress + 4).
    When that address exceeds the sum of GEVNTADR and GEVNTSIZ, the controller wraps around to the first GEVNTADR value.
    In this way, the Event Buffer operates like a circular buffer with hardware writing to the “tail” of the buffer and software reading from the “head.”
    Most events are exactly four bytes in size, but there is one exception:
    The Vendor Device Test LMP Received Event (VndrDevTstRcved) is a 12-byte event that includes a header in the first four bytes
    and the contents of the LMP in the following eight bytes. */
    ptBootUsbCtx->event.lpos = (ptBootUsbCtx->event.lpos + (UINT32)DWC3_EVENT_SIZE) % (UINT32)DWC3_EVENT_BUFF_SIZE;
    
}
