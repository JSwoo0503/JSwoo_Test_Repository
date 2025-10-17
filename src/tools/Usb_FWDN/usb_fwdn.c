#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USB_REQ_VENDOR_NEXTCHIP_DL_START  	    0xA
#define USB_REQ_VENDOR_NEXTCHIP_DL_HEADER 	    0xD
#define USB_REQ_VENDOR_NEXTCHIP_DL_PROGRESS 	0xC
#define USB_REQ_VENDOR_NEXTCHIP_DL_END    	    0xB

#define FIRMWARE_HEADER_SIZE                    64
#define FIRMWARE_BUFFER_SIZE                    4096


#define VENDOR_ID                               0x345D 
#define PRODUCT_ID                              0x3000 

typedef unsigned long long                      UINT64;
typedef unsigned int                            UINT32;
typedef unsigned short                          UINT16;
typedef unsigned char                           UINT8;

typedef signed long long                        INT64;
typedef signed int                              INT32;
typedef signed short                            INT16;
typedef signed char                             INT8;

typedef char                                    CHAR;
typedef float                                   FLOAT;
typedef double                                  DOUBLE;
typedef unsigned char                           BOOL;

//=======================================================================================================
//
//=======================================================================================================
typedef union
{
    UINT32  Reg;                                            /* Image Configure2 */
    struct {
            /* B/D Dependency */ /* (X)->(OTP) */
            UINT32  mSPI_RX_DELAY                       :8; /* [  0:7] SPI RX Sample Delay
                                                                    0x0 default
                                                                    ...
                                                                    maximum <= SSI_RX_DLY_SR_DEPTH(ex:0xFF) */
            UINT32  mSPI_CLK_POL_PH                     :2; /* [  8:9] SPI/QSPi Clock Polarity & Phase Config Setting
                                                                    0x0 Polarity(0), Phase(0) (default)
                                                                    0x1 Polarity(0), Phase(1)
                                                                    0x2 Polarity(1), Phase(0)
                                                                    0x3 Polarity(1), Phase(1) */
            UINT32  mUART_BAUDRATE                      :2; /* [ 10:11] UART Baudrate table for Download
                                                                    0x0 115200 (default:MID_1)
                                                                    0x1 230400 (MAX)
                                                                    0x2 57600  (MID_2)
                                                                    0x3 19200  (MIN) */
            UINT32  mUSB_REF_CLK                        :4; /* [ 12:15] USB Ref Clock Table
                                                                    0x0 USB_REF_CLK_100_MHZ = 0, default(HW Reset Value)
                                                                    0x1 USB_REF_CLK_19_2_MHZ,
                                                                    0x2 USB_REF_CLK_20_MHZ,
                                                                    0x3 USB_REF_CLK_24_MHZ,
                                                                    0x4 USB_REF_CLK_25_MHZ,
                                                                    0x5 USB_REF_CLK_26_MHZ,
                                                                    0x6 USB_REF_CLK_38_4_MHZ,
                                                                    0x7 USB_REF_CLK_40_MHZ,
                                                                    0x8 USB_REF_CLK_48_MHZ,
                                                                    0x9 USB_REF_CLK_50_MHZ,
                                                                    0xA(10) USB_REF_CLK_52_MHZ,
                                                                    0xB(11) USB_REF_CLK_200_MHZ, */
            UINT32  RESERVED1                           :8; /* [ 16:23] RESERVED1
                                                                    0x0 Skip */
            UINT32  RESERVED2                           :8; /* [ 24:31] RESERVED2
                                                                    0x0 Skip */
    } Bit;
} tBOOT_CONF2;


//=======================================================================================================
//
//=======================================================================================================
typedef union
{
    UINT32  Reg;                                            /* Image Configure1 */
    struct {
            UINT32 mSPI_CTRL                            :4; /* [  0:3] SPI Mode
                                                                    0x0 Skip
                                                                    0x1 SPI Mode
                                                                    0x2 QSPI Mode
                                                                    0x3 DMA-SPI Mode
                                                                    0x4 DMA-QSPI Mode */
            UINT32 mSECURE_MODE                         :4; /* [  4:7] Secure Booting Mode
                                                                    0x0 Skip
                                                                    0x1 Normal Booting
                                                                    0x2 Secure Booting
                                                                    0x3 Skip */
            UINT32 mKEY_STORAGE                         :2; /* [  8:9] Secure Key Storage
                                                                    0x0 Skip
                                                                    0x1 OTP
                                                                    0x2 ROM */
            UINT32 mUSE_KEY_CMRT                        :2; /* [ 10:11] Use RT640 Internal OTP Key
                                                                    0x0 Skip
                                                                    0x1 Use CMRT Internal OTP
                                                                    0x2 Not use CMRT Internal OTP */
            UINT32 mSAFETY_MODE                         :4; /* [ 12:15] Safety Mode(Global)
                                                                    0x0 Skip
                                                                    0x1 DISABLE
                                                                    0x2 ENABLE */
            UINT32 mSFLASH_TYPE                         :3; /* [ 16:18] sFlash Type
                                                                    0x0 Skip
                                                                    0x1 Type1
                                                                    0x2 Type2
                                                                    0x3 Type3
                                                                    0x4 Type4
                                                                    0x5 Type5 */
            UINT32 mQSPI_DS                             :3; /* [ 19:21]
                                                                    0x0 X1
                                                                    0x1 X1.5
                                                                    0x2 X2
                                                                    0x3 X2.5
                                                                    0x4 X3
                                                                    0x5 X4 */
            UINT32 mFAULT_RESET                         :2; /* [ 22:23] HW & SW FT : Default(ON)
                                                                    0x0 Skip
                                                                    0x1 DISABLE  : RST holding & Loop
                                                                    0x2 ENABLE   : Go to HW RST (safe_state : OE) */
            UINT32 mQSPI_CLK_DIV                        :2; /* [ 24:25] QSPI/SPI Clock Divider
                                                                    0x0 Mid  Speed(DIV=16) : (default)
                                                                    0x1 Low  Speed(DIV=20)
                                                                    0x2 High Speed(DIV=8) */
            UINT32 mQSPI_DCYCLE                         :3; /* [ 26:28] QSPI Dummy Cycle
                                                                    0x0     (6 Cycle) : Default
                                                                    0x1 x 2 (2 Cycle)
                                                                    0x2 x 2 (4 Cycle)
                                                                    ............
                                                                    0x7 x 2 (14 Cycle) */
            UINT32 mFW_SIZEUP                           :3; /* [ 29:31] Firmware size up(default :64Kbyte)
                                                                    + 0x0 x 64KB
                                                                    + 0x1 x 64KB
                                                                    ............
                                                                    + 0x7 x 64KB */
    } Bit;
} tBOOT_CONF1;

//=======================================================================================================
//
//=======================================================================================================
typedef struct
{
    union 
    {
        UINT32  Reg;
        struct 
        {
                UINT32      KEYSPLIT_NUM                :4; /* [  0:3] case CMRT Internal OTP : keysplit number
                                                                   0x0 KEYSPLIT 1
                                                                   0x1 KEYSPLIT 2
                                                                   0x2 KEYSPLIT 3
                                                                   0x3 KEYSPLIT 4
                                                                   0x4 KEYSPLIT 5
                                                                   0x5 KEYSPLIT 6
                                                                   0x6 KEYSPLIT 7 */
                UINT32      RESERVED1                   :4; /* [  4:7] RESERVED1
                                                                   0x0 Skip */
                UINT32      RESERVED2                   :8; /* [ 8:15] RESERVED2
                                                                   0x0 Skip */
                UINT32      RESERVED3                   :8; /* [ 16:23] RESERVED3
                                                                   0x0 Skip */
                UINT32      RESERVED4                   :8; /* [ 24:31 ] RESERVED4
                                                                   0x0 Skip */
        } Bit;
    } mKEYSPLIT;

    UINT32      RESERVED5;
    UINT32      RESERVED6;
    UINT32      mDIVERSIFY_PATH;                            /* case CMRT Internal OTP : diversify_path - just 1 character, is it enough size ? (max 16 byte, current 4 byte) */
} tBOOT_KEY;


//=======================================================================================================
//
//=======================================================================================================
typedef struct
{
    UINT32      mOsOffset;                                  /* Image Offset */
    UINT32      mOsSize;                                    /* Image Size */
    UINT32      mSecureBootOffset;                          /* Image Offset */
    UINT32      mSecureBootSize;                            /* Image Size */
} tBOOT_SEC;

//=======================================================================================================
//
//=======================================================================================================
typedef struct
{
    UINT32      mLength;                                    /* Image length */
    UINT32      mCheckSum;                                  /* Image Checksum */
    tBOOT_CONF1 mConfig_1;                                  /* Image Boot Config_1 */
    tBOOT_CONF2 mConfig_2;                                  /* Image Boot Config_2 */
    tBOOT_KEY   tBootKey;
    tBOOT_SEC   tBootSec;
    UINT32      mRESERVED1;
    UINT32      mRESERVED2;
    UINT32      mRESERVED3;
    UINT32      mSignature;                                 /* Image Signature */
} tBOOT_HDR;

//=======================================================================================================
//
//=======================================================================================================
void send_control_transfer(libusb_device_handle *handle, UINT8 request, UINT16 value, UINT16 index, UINT8 *data, UINT16 length) 
{
    int res = libusb_control_transfer(handle,
                                      LIBUSB_REQUEST_TYPE_VENDOR | 
                                      LIBUSB_RECIPIENT_DEVICE | 
                                      LIBUSB_ENDPOINT_OUT,
                                      request, value, index, data, length, 10000000);
    if (res < 0) 
    {
        fprintf(stderr, "Error in control transfer: %s\n", libusb_error_name(res));
        exit(EXIT_FAILURE);
    }
}

//=======================================================================================================
//
//=======================================================================================================
UINT32 swap_to_little_endian(UINT32 *value) 
{
    *value = ((*value & 0x000000FF) << 24)    |
             ((*value & 0x0000FF00) << 8)     |
             ((*value & 0x00FF0000) >> 8)     |
             ((*value & 0xFF000000) >> 24);
}

//=======================================================================================================
//
//=======================================================================================================
void convert_buffer_endian(UINT8 *buffer, UINT32 length) 
{
    
    if (length % 4 != 0) 
    {
        fprintf(stderr, "buffer size error\n");
        return;
    }

    for (UINT32 i = 0; i < length; i += 4) 
    {
        UINT32 *value = (UINT32 *)(buffer + i);
        swap_to_little_endian(value);
    }
}

//=======================================================================================================
//
//=======================================================================================================
void send_file_to_device(libusb_device_handle *handle, const char *filename,  int *transaction_count, long *total_bytes_sent) 
{
    FILE *file = fopen(filename, "rb");

    if (!file) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    //unsigned char buffer[4096];
    UINT8 buffer[4096];
    size_t bytes_read;

    // Read the file header
    tBOOT_HDR file_header;

    if (fread(&file_header, sizeof(tBOOT_HDR), 1, file) != 1) 
    {
        perror("Error reading file header");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    printf("===============================================\n");
    printf("Firmware Header !!\n");
    printf("===============================================\n");
    printf("mLength: %d\n",         file_header.mLength);
    printf("mCheckSum: %08X\n",     file_header.mCheckSum);
    printf("mConfig_1: %08X\n",     file_header.mConfig_1.Reg);
    printf("mConfig_2: %08X\n",     file_header.mConfig_2.Reg);
    printf("tBootKey: %08X\n",      file_header.tBootKey.mKEYSPLIT.Reg);
    printf("tBootSec.mOsOffset: %08X\n",      file_header.tBootSec.mOsOffset);
    printf("tBootSec.mOsSize: %08X\n",      file_header.tBootSec.mOsSize);
    printf("tBootSec.mSecureBootOffset: %08X\n",      file_header.tBootSec.mSecureBootOffset);
    printf("tBootSec.mSecureBootSize: %08X\n",      file_header.tBootSec.mSecureBootSize);
    printf("mSignature: %08X\n",    file_header.mSignature);
    printf("total header size:%ld\n", sizeof(tBOOT_HDR));
    printf("===============================================\n");

    
    if (fseek(file, sizeof(tBOOT_HDR), SEEK_SET) != 0) 
    {
        perror("Next offset error\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *transaction_count = 0;
    *total_bytes_sent = 0;

    // 명령어 순서 중요
    // Send header (assuming the first 512 bytes are header)
    send_control_transfer(handle, USB_REQ_VENDOR_NEXTCHIP_DL_HEADER, 0, 0, (UINT8*)&file_header, sizeof(tBOOT_HDR));
    
    // Inform the device about the file size and header
    send_control_transfer(handle, USB_REQ_VENDOR_NEXTCHIP_DL_START, 0, 0, NULL, 0);

    UINT32 count = 0;
    #if (1)
    // Send the remaining file data
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) 
    {
        //convert_buffer_endian(buffer, bytes_read);

    	send_control_transfer(handle, USB_REQ_VENDOR_NEXTCHIP_DL_PROGRESS, (filesize >> 16) & 0xFFFF, filesize & 0xFFFF, buffer, bytes_read);

        (*transaction_count)++;
        *total_bytes_sent += bytes_read;

        // count++;

        // if (count == 10)
        // {
        //     printf("XXXX\n");
        //     break;
        // }
    }
    #endif

    // End the file transfer
    send_control_transfer(handle, USB_REQ_VENDOR_NEXTCHIP_DL_END, 0, 0, NULL, 0);

    fclose(file);
}

//=======================================================================================================
//
//=======================================================================================================
int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <binary file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    libusb_context *ctx = NULL;
    libusb_device_handle *handle = NULL;
    int res;

    res = libusb_init(&ctx);
    if (res < 0) 
    {
        fprintf(stderr, "libusb_init error: %s\n", libusb_error_name(res));
        return EXIT_FAILURE;
    }

    handle = libusb_open_device_with_vid_pid(ctx, VENDOR_ID, PRODUCT_ID);
    if (!handle) 
    {
        fprintf(stderr, "Error finding USB device\n");
        libusb_exit(ctx);
        return EXIT_FAILURE;
    }

    if (libusb_kernel_driver_active(handle, 0) == 1) 
    {
        libusb_detach_kernel_driver(handle, 0);
    }

    res = libusb_claim_interface(handle, 0);
    if (res < 0) 
    {
        fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(res));
        libusb_close(handle);
        libusb_exit(ctx);
        return EXIT_FAILURE;
    }

    struct timeval start_time, end_time;
    int transaction_count = 0;
    long total_bytes_sent = 0;

    gettimeofday(&start_time, NULL);

    send_file_to_device(handle, argv[1],  &transaction_count, &total_bytes_sent);

     gettimeofday(&end_time, NULL);

    double time_taken = (end_time.tv_sec - start_time.tv_sec) + 
                        (end_time.tv_usec - start_time.tv_usec) / 1000000.0;


    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(ctx);


    printf("Binary file name: %s\n", argv[1]);
    printf("File size: %ld bytes\n", total_bytes_sent);
    printf("Number of transactions: %d\n", transaction_count);
    printf("Total data sent: %.2f KB\n", (double)total_bytes_sent / 1024);
    printf("Time taken: %.2f seconds\n", time_taken);

    printf("File transfer complete.\n");

    return 0;
}

