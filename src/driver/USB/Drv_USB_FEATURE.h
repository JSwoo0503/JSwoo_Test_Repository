/**
********************************************************************************
*
*  Copyright (C) 2022 NEXTCHIP Inc. All rights reserved.
*
*  file    :
*
*  brief   :
*
*  author  :
*
*  date    :
*
*  version :
*
********************************************************************************
*/
#ifndef USB_FEATURE_H_
#define USB_FEATURE_H_


/**
 * 
*/
#define ENABLE_USB_ASSERT                   (0)
#define ENABLE_USB_PRINTF                   (1)
#define ENABLE_USB_BYTES_PROGRESS           (0) 

#define ENABLED_USB_PRINT_MSGINFO           (1)
#define ENABLED_USB_PRINT_MSGERR            (1)
#define ENABLED_USB_PRINT_MSGWARN           (0)
#define ENABLED_USB_PRINT_MSGDBG            (0)

#if defined(OTP_ENABLE) && (OTP_ENABLE == 1)
#define ENABLED_USB_OTP_SERIAL_NO (1)
#else
#define ENABLED_USB_OTP_SERIAL_NO (0)
#endif


/**
 * 
*/
typedef enum ASSERT_NO_
{
	ASSERT_NO_0000		= 0x0000,
	ASSERT_NO_0001		= 0x0001,
	ASSERT_NO_0002		= 0x0002,
	ASSERT_NO_0003		= 0x0003,
	ASSERT_NO_0004		= 0x0004,
	ASSERT_NO_0005		= 0x0005,
	ASSERT_NO_0006		= 0x0006,
	ASSERT_NO_0007		= 0x0007,
	ASSERT_NO_0008		= 0x0008,
	ASSERT_NO_0009		= 0x0009,
	ASSERT_NO_000A		= 0x000A,
	ASSERT_NO_000B		= 0x000B,
	ASSERT_NO_000C		= 0x000C,
	ASSERT_NO_000D		= 0x000D,
    ASSERT_NO_000E		= 0x000E,
    ASSERT_NO_000F		= 0x000F,

	ASSERT_NO_0010		= 0x0010,
	ASSERT_NO_0011		= 0x0011,
	ASSERT_NO_0012		= 0x0012,
	ASSERT_NO_0013		= 0x0013,
	ASSERT_NO_0014		= 0x0014,
	ASSERT_NO_0015		= 0x0015,
	ASSERT_NO_0016		= 0x0016,
	ASSERT_NO_0017		= 0x0017,
	ASSERT_NO_0018		= 0x0018,
	ASSERT_NO_0019		= 0x0019,
	ASSERT_NO_001A		= 0x001A,
	ASSERT_NO_001B		= 0x001B,
	ASSERT_NO_001C		= 0x001C,
	ASSERT_NO_001D		= 0x001D,
    ASSERT_NO_001E		= 0x001E,
    ASSERT_NO_001F		= 0x001F,

	ASSERT_NO_0020		= 0x0020,
	ASSERT_NO_0021		= 0x0021,
	ASSERT_NO_0022		= 0x0022,
	ASSERT_NO_0023		= 0x0023,
	ASSERT_NO_0024		= 0x0024,
	ASSERT_NO_0025		= 0x0025,
	ASSERT_NO_0026		= 0x0026,
	ASSERT_NO_0027		= 0x0027,
	ASSERT_NO_0028		= 0x0028,
	ASSERT_NO_0029		= 0x0029,
	ASSERT_NO_002A		= 0x002A,
	ASSERT_NO_002B		= 0x002B,
	ASSERT_NO_002C		= 0x002C,
	ASSERT_NO_002D		= 0x002D,
    ASSERT_NO_002E		= 0x002E,
    ASSERT_NO_002F		= 0x002F,

	ASSERT_NO_0030		= 0x0030,
	ASSERT_NO_0031		= 0x0031,
	ASSERT_NO_0032		= 0x0032,
	ASSERT_NO_0033		= 0x0033,
	ASSERT_NO_0034		= 0x0034,
	ASSERT_NO_0035		= 0x0035,
	ASSERT_NO_0036		= 0x0036,
	ASSERT_NO_0037		= 0x0037,
	ASSERT_NO_0038		= 0x0038,
	ASSERT_NO_0039		= 0x0039,
	ASSERT_NO_003A		= 0x003A,
	ASSERT_NO_003B		= 0x003B,
	ASSERT_NO_003C		= 0x003C,
	ASSERT_NO_003D		= 0x003D,
    ASSERT_NO_003E		= 0x003E,
    ASSERT_NO_003F		= 0x003F,

	ASSERT_NO_0040		= 0x0040,
	ASSERT_NO_0041		= 0x0041,
	ASSERT_NO_0042		= 0x0042,
	ASSERT_NO_0043		= 0x0043,
	ASSERT_NO_0044		= 0x0044,
	ASSERT_NO_0045		= 0x0045,
	ASSERT_NO_0046		= 0x0046,
	ASSERT_NO_0047		= 0x0047,
	ASSERT_NO_0048		= 0x0048,
	ASSERT_NO_0049		= 0x0049,
	ASSERT_NO_004A		= 0x004A,
	ASSERT_NO_004B		= 0x004B,
	ASSERT_NO_004C		= 0x004C,
	ASSERT_NO_004D		= 0x004D,
    ASSERT_NO_004E		= 0x004E,
    ASSERT_NO_004F		= 0x004F,

	ASSERT_NO_0050		= 0x0050,
	ASSERT_NO_0051		= 0x0051,
	ASSERT_NO_0052		= 0x0052,
	ASSERT_NO_0053		= 0x0053,
	ASSERT_NO_0054		= 0x0054,
	ASSERT_NO_0055		= 0x0055,
	ASSERT_NO_0056		= 0x0056,
	ASSERT_NO_0057		= 0x0057,
	ASSERT_NO_0058		= 0x0058,
	ASSERT_NO_0059		= 0x0059,
	ASSERT_NO_005A		= 0x005A,
	ASSERT_NO_005B		= 0x005B,
	ASSERT_NO_005C		= 0x005C,
	ASSERT_NO_005D		= 0x005D,
    ASSERT_NO_005E		= 0x005E,
    ASSERT_NO_005F		= 0x005F,

	ASSERT_NO_0060		= 0x0060,
	ASSERT_NO_0061		= 0x0061,
	ASSERT_NO_0062		= 0x0062,
	ASSERT_NO_0063		= 0x0063,
	ASSERT_NO_0064		= 0x0064,
	ASSERT_NO_0065		= 0x0065,
	ASSERT_NO_0066		= 0x0066,
	ASSERT_NO_0067		= 0x0067,
	ASSERT_NO_0068		= 0x0068,
	ASSERT_NO_0069		= 0x0069,
	ASSERT_NO_006A		= 0x006A,
	ASSERT_NO_006B		= 0x006B,
	ASSERT_NO_006C		= 0x006C,
	ASSERT_NO_006D		= 0x006D,
    ASSERT_NO_006E		= 0x006E,
    ASSERT_NO_006F		= 0x006F,

	ASSERT_NO_0070		= 0x0070,
	ASSERT_NO_0071		= 0x0071,
	ASSERT_NO_0072		= 0x0072,
	ASSERT_NO_0073		= 0x0073,
	ASSERT_NO_0074		= 0x0074,
	ASSERT_NO_0075		= 0x0075,
	ASSERT_NO_0076		= 0x0076,
	ASSERT_NO_0077		= 0x0077,
	ASSERT_NO_0078		= 0x0078,
	ASSERT_NO_0079		= 0x0079,
	ASSERT_NO_007A		= 0x007A,
	ASSERT_NO_007B		= 0x007B,
	ASSERT_NO_007C		= 0x007C,
	ASSERT_NO_007D		= 0x007D,
    ASSERT_NO_007E		= 0x007E,
    ASSERT_NO_007F		= 0x007F
} ASSERT_NO;


/**
 * 
*/
#define DEBUG_BREAK()               \
do                                  \
{                                   \
    volatile UINT32 lock = TRUE;    \
    while (lock == TRUE)            \
    {                               \
        ;                           \
    }                               \
} while (0)


#if (ENABLE_USB_ASSERT==1)
    #define ASSERT_USB(condition, assert_no)                      \
        do {                                                      \
            if (!(condition)) {                                   \
                DEBUGMSG(MSGERR, "**** ASSERT (0x%04X) ****\n",   \
                        assert_no);                               \
                DEBUG_BREAK();                                    \
            }                                                     \
        } while (0)

#else
    #define ASSERT_USB(CONDITION, ERROR_NO)
#endif


#endif /* USB_FEATURE_H_ */
