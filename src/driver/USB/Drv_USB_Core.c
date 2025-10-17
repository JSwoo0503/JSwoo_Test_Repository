#include "Apache.h"
#include "Drv_USB_FEATURE.h"
#include "Drv_USB_REGS.h"
#include "Drv_USB_SPEC.h"
#include "main.h"

#include "Drv_USB_Core.h"
#include "Drv_USB_Ep0.h"
#include "Drv_USB_Device.h"
#include "Drv_USB.h"
#include "Drv_SCU.h"

#include "MPU.h"
/* ===================================================================
Firmware Downloader USB Context
=================================================================== */
/* #define ALIGNED(x) __attribute__((aligned(x))) */

/* ===================================================================
Global USB event buffer
=================================================================== */
/* UINT8 g_usb_event_buffer[DWC3_EVENT_BUFF_SIZE]; */


/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Enable_Interrupt(void)
{
    DEVTEN_T enable_event;
    
    enable_event.devten.dw = NC_DWC3_Read(DWC3_DEVTEN);
    enable_event.devten.b.VENDEVTSTRCVDEN   = 0x1;     /* Vendor Device Test LMP Received Event */
    enable_event.devten.b.CONNECTDONEEVTEN  = 0x1;     /* Connection Done Enable */
    enable_event.devten.b.DISSCONNEVTEN     = 0x1;     /* Disconnect Detected Event Enable */
    enable_event.devten.b.WKUPEVTEN         = 0x1;     /* U3/L2 or U3/L2L1 Resume Detected Event Enable. */
    enable_event.devten.b.ERRTICERREVTEN    = 0x1;     /* Erratic Error Event Enable */
    enable_event.devten.b.USBRSTEVTEN       = 0x1;     /* USB Reset Enable */
    enable_event.devten.b.ULSTCNGEN         = 0x1;     /* USB/Link State Change Event Enable */
    enable_event.devten.b.ECCERREN          = 0x1;     /* ECC Error Enable. */
    
    NC_DWC3_Write(DWC3_DEVTEN, enable_event.devten.dw);
}

/* ===================================================================
endpoint-specific event (DEPEVT) handler, 
It is a term defined in the databook.
=================================================================== */
void DEBUG_FUNC_ATTR NC_Endpoint_Interrupt_Handler(UDC_CTX_T *ptBootUsbCtx)
{
    UINT8 epnum = ptBootUsbCtx->dwc3_event.dwc3_event_union.endpoint_event.endpoint_number;
    DWC3_EP_T *dep = &ptBootUsbCtx->eps[epnum];

    if(dep == NULL) { }

    ASSERT_USB(dep->flags & DWC3_EP_ENABLED, ASSERT_NO_0005);
    ASSERT_USB(epnum == 0 || epnum == 1, ASSERT_NO_0006);

    NC_USB_Ep0_Event(ptBootUsbCtx);
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Device_Event_Loop(UDC_CTX_T *ptBootUsbCtx, UINT64 *msec_time)
{
    GEVNTCOUNT_T event_buffer_count;
    UINT32 event_count;

    event_buffer_count.gevntcount.dw = NC_DWC3_Read(DWC3_GEVNTCOUNT(0));
    event_count = event_buffer_count.gevntcount.b.EVNTCOUNT;

    if (event_count != 0U) {
        /* global buffer size register */
        GEVNTSIZ_T event_buffer_size;
        event_buffer_size.gevntsiz.dw = NC_DWC3_Read(DWC3_GEVNTSIZ(0U));
        /* When set to '1', this prevents the interrupt from being generated.
        However, even when the mask is set, the events are queued.
        masking event interrupt */
        event_buffer_size.gevntsiz.b.EVNTINTRPTMASK = 0x1;
        NC_DWC3_Write(DWC3_GEVNTSIZ(0U), event_buffer_size.gevntsiz.dw);
        /* The Event Buffer contains one of the following types of information:
        ■ Endpoint-Specific Event (DEPEVT)
        ■ Device-Specific Event (DEVT) */

        while (event_count > 0U)
        {
            NC_USB_Process_Event_Buffer_Entry(ptBootUsbCtx);

            /* Event Count (EVNTCount)w
            When read, returns the number of valid events in the Event Buffer (in bytes).
            When written, hardware decrements the count by the value written.
            When Interrupt moderation is enabled (that is, DEVICE_IMODI!= 0), the interrupt line gets de-asserted when the first write happens on this register
            to decrement the count. When Interrupt moderation is disabled (that is, DEVICE_IMODI = 0),
            the Interrupt line continues to get asserted until the event count becomes zero (no-moderation behavior). */
        
            event_buffer_count.gevntcount.b.EVNTCOUNT = DWC3_EVENT_SIZE;
            event_count -= DWC3_EVENT_SIZE;
            NC_DWC3_Write(DWC3_GEVNTCOUNT(0), event_buffer_count.gevntcount.dw);

            *msec_time = NC_SCU_GetMsec(FALSE);
        }

        /* unmasking event interrupt */
        event_buffer_size.gevntsiz.dw = NC_DWC3_Read(DWC3_GEVNTSIZ(0U));    
        event_buffer_size.gevntsiz.b.EVNTINTRPTMASK = 0x0U;
        NC_DWC3_Write(DWC3_GEVNTSIZ(0U), event_buffer_size.gevntsiz.dw);
    }
}


/* ===================================================================

=================================================================== */

static void DEBUG_FUNC_ATTR NC_USB_Soft_Reset(void)
{
    GCTL_T g_control;
    GUSB3PIPECTL_T g_usb3pipe_control;
    GUSB2PHYCFG_T g_usb2phy_config;

	g_control.gctl.dw = NC_DWC3_Read(DWC3_GCTL);
	g_control.gctl.b.CORESOFTRESET = 0x1;
	NC_DWC3_Write(DWC3_GCTL, g_control.gctl.dw);
	
    g_usb3pipe_control.gusb3pipectl.dw  = NC_DWC3_Read(DWC3_GUSB3PIPECTL(0));
	g_usb3pipe_control.gusb3pipectl.b.PHYSoftRst = 0x1;
	NC_DWC3_Write(DWC3_GUSB3PIPECTL(0), g_usb3pipe_control.gusb3pipectl.dw);

	g_usb2phy_config.gusb2phycfg.dw = NC_DWC3_Read(DWC3_GUSB2PHYCFG(0));
	g_usb2phy_config.gusb2phycfg.b.PHYSOFTRST = 0x1;
	NC_DWC3_Write(DWC3_GUSB2PHYCFG(0), g_usb2phy_config.gusb2phycfg.dw);

	nc_mdelay(100U);

	/* Clear USB3 PHY reset */
	g_usb3pipe_control.gusb3pipectl.dw = NC_DWC3_Read(DWC3_GUSB3PIPECTL(0));
	g_usb3pipe_control.gusb3pipectl.b.PHYSoftRst = 0x0;
	NC_DWC3_Write(DWC3_GUSB3PIPECTL(0), g_usb3pipe_control.gusb3pipectl.dw);

	/* Clear USB2 PHY reset  */
	g_usb2phy_config.gusb2phycfg.dw = NC_DWC3_Read(DWC3_GUSB2PHYCFG(0));
	g_usb2phy_config.gusb2phycfg.b.PHYSOFTRST = 0x0;
	NC_DWC3_Write(DWC3_GUSB2PHYCFG(0), g_usb2phy_config.gusb2phycfg.dw);

	nc_mdelay(100U);

	g_control.gctl.dw = NC_DWC3_Read(DWC3_GCTL);
	g_control.gctl.b.CORESOFTRESET = 0x0;
	NC_DWC3_Write(DWC3_GCTL, g_control.gctl.dw);
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Core_Device_Reset(UDC_CTX_T *ptBootUsbCtx)
{

    /* #define DWC3_REVISION_IS_DWC31		0x80000000 */
    /* #define DWC3_USB31_REVISION_190A	(0x3139302a | DWC3_REVISION_IS_DWC31) */

    DCTL_T device_control;
    
    UINT32 timeout = 5000;
    if(ptBootUsbCtx == NULL) { }

    device_control.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
    /* Set the CSftRst field to ‘1’ and wait for a read to return ‘0’.
    This resets the device controller. */

    /* device_control.dctl.b.CSFTRST = 0x1; */
    device_control.dctl.dw |= (1UL << 30);
    NC_DWC3_Write(DWC3_DCTL, device_control.dctl.dw);

	/* For DWC_usb31 controller 1.90a and later, the DCTL.CSFRST bit
	is cleared only after all the clocks are synchronized. This can
	take a little more than 50ms. Set the polling rate at 20ms
	for 10 times instead. */
    while (timeout > 0U)
    {
        device_control.dctl.dw = NC_DWC3_Read(DWC3_DCTL);
        if (device_control.dctl.b.CSFTRST == 0U) 
        {
#ifdef DEBUG_ENABLE_
            DBGUSB(MSGDBG,  "%s: reset done.\n", __func__);
#endif
            break;
        }
        timeout--;
    } 
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Core_Phy_Init(void)
{
    GUSB3PIPECTL_T usb3pipe;
    GUSB2PHYCFG_T usb2phy;
    GUCTL1_T user_control;

    usb3pipe.gusb3pipectl.dw = NC_DWC3_Read(DWC3_GUSB3PIPECTL(0));
    usb3pipe.gusb3pipectl.b.SUSPENDENABLE = 0x1;
    
    usb2phy.gusb2phycfg.dw = NC_DWC3_Read(DWC3_GUSB2PHYCFG(0)); 
    usb2phy.gusb2phycfg.b.U2_FREECLK_EXISTS = 0x0U;
    /* usb2phy.gusb2phycfg.b.USBTRDTIM = 0x0U; */
    usb2phy.gusb2phycfg.b.ENBLSLPM = 0x0U;
    usb2phy.gusb2phycfg.b.PHYIF = 0x1U;
    usb2phy.gusb2phycfg.b.USBTRDTIM =0x5U;

    NC_DWC3_Write(DWC3_GUSB3PIPECTL(0), usb3pipe.gusb3pipectl.dw);
    NC_DWC3_Write(DWC3_GUSB2PHYCFG(0), usb2phy.gusb2phycfg.dw);

    user_control.guctl1.dw = NC_DWC3_Read(DWC3_GUCTL1);
    user_control.guctl1.b.DEV_FORCE_20_CLK_FOR_30_CLK = 0x1;
    NC_DWC3_Write(DWC3_GUCTL1, user_control.guctl1.dw);
}

/* ===================================================================
global control init
=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_GCTL_Init(void)
{
    GCTL_T gctl;
    gctl.gctl.dw = NC_DWC3_Read(DWC3_GCTL);
    /* Disable Scrambling (DisScramble)
    Transmit request to Link Partner on next transition to Recovery or Polling. */
    gctl.gctl.b.DISSCRAMBLE = 0x0;
    /* Scale-Down Mode (ScaleDown)
    When Scale-Down mode is enabled for simulation, the controller uses scaled-down timing values, resulting in faster simulations.
    When Scale-Down mode is disabled, actual timing values are used. This is required for hardware operation.
    HS/FS/LS Modes
    ■ 2'b00: Disables all scale-downs. Actual timing values are used.
    ■ 2'b01: */
    gctl.gctl.b.SCALEDOWN = 0x0;
    /* PRTCAPDIR: Port Capability Direction (PrtCapDir)
    ■ 2'b01: for Host configurations
    ■ 2'b10: for Device configurations */
    gctl.gctl.b.PRTCAPDIR = 0x2;

    NC_DWC3_Write(DWC3_GCTL, gctl.gctl.dw);
}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Event_Buffer_Init(UDC_CTX_T *ptBootUsbCtx)
{
    DWC3_EVENT_BUFFER_T *event_buffer = &ptBootUsbCtx->event;
    static UINT8 g_usb_event_buffer[DWC3_EVENT_BUFF_SIZE];
    
    /* allocation init */
    event_buffer->buf = &g_usb_event_buffer[0];
    event_buffer->addr = (UINT64)event_buffer->buf;
    event_buffer->size = DWC3_EVENT_BUFF_SIZE;
    event_buffer->lpos = 0;    

    NC_Memset_u08(g_usb_event_buffer, (UINT8)0, (INT32)DWC3_EVENT_BUFF_SIZE);

    /* buffer low, high address programming to H/W */
    NC_DWC3_Write(DWC3_GEVNTADRLO(0), LOWER_32BITS(event_buffer->addr));    
    NC_DWC3_Write(DWC3_GEVNTADRHI(0), UPPER_32BITS(event_buffer->addr));
    NC_DWC3_Write(DWC3_GEVNTSIZ(0U), DWC3_GEVNTSIZ_SIZE(event_buffer->size));
    NC_DWC3_Write(DWC3_GEVNTCOUNT(0), 0); 

}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Device_Run(BOOL is_on)
{
    DCTL_T device_control;
    UINT32 timeout = 5000;

    device_control.dctl.dw = NC_DWC3_Read(DWC3_DCTL);

    if (is_on == TRUE)
    {
        /* Normal operating mode where the controller attempts to connect to the host
        or maintain a connection while in suspend state. In this mode,
        the Hibernation Request Event is not generated and the controller exits U3, L2, or L1
        if the host initiates an exit without software intervention. */
        device_control.dctl.b.KeepConnect = 0x0;
        device_control.dctl.b.RUN_STOP = 0x1;
    }
    else
    {
        /* Only applicable after software receives the Hibernation event.
        This instructs the controller to disable event generation,
        prepare for subsequent hibernation entry commands, but remain connected to the host.
        This is the state the controller is in after exiting D3 and entering D0. */
        device_control.dctl.b.RUN_STOP = 0x0;

        /* USB/Link State Change Request
        Software writes this field to issue a USB/Link state change request. 
        A change in this field indicates a new request to the controller.
        ■ Value Requested Link State Transition/Action
        ■ 0 No Action
        ■ 4 SS.Disabled
        ■ 5 Rx.Detect
        ■ 6 SS.Inactive
        ■ 8 U3 exit request
        ■ 10 Compliance
        ■ Others: Reserved
        In HS/FS/LS mode:
        ■ ValueRequested USB state transition
        ■ 8 Remote wakeup request
        ■ Others: Reserved
        The Remote wakeup request */        
        device_control.dctl.b.ULSTCHNGREQ = 0x4;
    }

    NC_DWC3_Write(DWC3_DCTL, device_control.dctl.dw);

    /* Run/Stop
    The software writes 1 to this bit to start the device controller operation.
    To stop the device controller operation, the software must remove any active transfers and write 0 to this bit. 
    When the controller is stopped, it sets the DSTS.DevCtrlHlt bit when the controller is idle and the lower layer finishes 
    the disconnect process. */

    while (timeout > 0U)
    {
        DSTS_T dsts;
        UINT32 stop_flag = FALSE;
        dsts.dsts.dw = NC_DWC3_Read(DWC3_DSTS);

        if (is_on == TRUE)
        {
            if (dsts.dsts.b.DEVCTRLHLT == 0x0U) {
                stop_flag = TRUE;
            }
        }
        else
        {
            if (dsts.dsts.b.DEVCTRLHLT == 0x1U) {
                stop_flag = TRUE;
            }
        }

        if(stop_flag == TRUE) {   
            break;
        }

        timeout--;
    } 

}

/* ===================================================================

=================================================================== */
static void DEBUG_FUNC_ATTR NC_USB_Speed_Init(void)
{
    DCFG_T device_config;
    device_config.dcfg.dw = NC_DWC3_Read(DWC3_DCFG);
    /* Device Speed.
    Indicates the speed at which the application requires the controller to connect, 
    or the maximum speed the application can support.
    However, the actual bus speed is determined only after the chirp sequence is completed, 
    and is based on the speed of the USB host to which the controller is connected.
    ■ 3'b100: SuperSpeed (USB 3.0 PHY clock is 30 MHz or 60 MHz)     */
    device_config.dcfg.b.DEVSPD = 0x0;
    NC_DWC3_Write(DWC3_DCFG, device_config.dcfg.dw);
#ifdef DEBUG_ENABLE_
    DBGUSB(MSGINFO, "%s: usb speed : %d\n", __func__, device_config.dcfg.b.DEVADDR);
#endif
}

/* ===================================================================

=================================================================== */
void DEBUG_FUNC_ATTR NC_USB_Core_Init(UDC_CTX_T *ptBootUsbCtx)
{   
    UINT32 revision = NC_DWC3_Read(DWC3_GSNPSID);

    if ((revision & (UINT32)DWC3_GSNPSID_MASK) == (UINT32)APACHE6_GSNPSID)
    {
        ptBootUsbCtx->revision = revision;
    }
    else
    {
        ASSERT_USB((revision & DWC3_GSNPSID_MASK) == APACHE6_GSNPSID, ASSERT_NO_0007);
    }

    NC_USB_Core_Device_Reset(ptBootUsbCtx);  

    NC_USB_Soft_Reset();

    NC_USB_Core_Phy_Init();

    NC_USB_GCTL_Init();

    NC_USB_Event_Buffer_Init(ptBootUsbCtx);  

    NC_USB_Speed_Init();

    NC_USB_Prepare_Endpoint(ptBootUsbCtx);

    NC_USB_Device_Start(ptBootUsbCtx);

    NC_USB_Enable_Interrupt();
    
    NC_USB_Device_Run(TRUE);
}

/* =========================================================================
DWC3 UDC MEM read
========================================================================= */
UINT32 DEBUG_FUNC_ATTR NC_DWC3_Read(UINT32 offset)
{
	return (UINT32)(*(volatile unsigned int *)((UINT32)APACHE_A6_USB_BASE_ADDR + offset));
}

/* =========================================================================
DWC3 UDC MEM write
========================================================================= */
void DEBUG_FUNC_ATTR NC_DWC3_Write(UINT32 offset, UINT32 value)
{
    (*(volatile unsigned int *)((UINT32)APACHE_A6_USB_BASE_ADDR + offset) = (value));
}

/* =========================================================================

========================================================================= */
/*
UINT32 round_up(UINT32 x, UINT32 y) 
{
    return ((x + y - 1) / y) * y;
}
*/

