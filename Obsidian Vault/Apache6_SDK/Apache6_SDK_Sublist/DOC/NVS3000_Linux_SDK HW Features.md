![[NVS3000 Overview.png]]
The NVS3000(APACHE6 SoC) is a ADAS SoC for various Automotive camera solution. 

ARM Cortex-A65AE Quad Core 
ARM Cortex-R5F Dual Core.

ARM MALI-G78AE, Video CODEC, Automotive ISP, ADAS Hardware accelerator and NPU is also including. 
It supports high speed interface such as PCI express Gen.3, USB 3.0 and 1G Ethernet MAC (RGMII).

**ARM Cortex-A65AE Quad Core**
	. Dual-Core Lock Step mode and Hybrid mode
	. 1.2GHz(NM), 1.35GHz(OD) core clock f requency
	. 32KB/32KB L1 Cache, 128KB L2 Cache for each core
	. 1MB L3 cache
	. AArch64 only
**ARM Cortex-R5F Dual Core**
	. Dual-Core Lock Step only
	. 32KB/32KB L1 Cache
**ARM MALI-G78AE GPU**
	. 1 Slice 2 Shader Cores
	. 94GFLOPS
	. 800MHz core clock f requency
**NPU**
	. AiMotive aiWare4SM+ 3K
	. 6.77 TOPS
	. up to 1.1GHz core clock f requency
**Security**
	. Secure Island for Secure Boot
	. Cryptographic HW Accelerator for IPsec, SSL/TLS and MACsec
	. TrustZone Architecture
**DDR**
	. LPDDR4/LPDDR4X 2 Ch
		: 3732Mbps data rate
**Automotive ISP**
	. Two 4-Ch ISP
		: 8M pixel 45 fps or 3M pixel 30 fps x 4Ch ISP
	. Support 2x2 CFA (RGGB, RCCB, RYYCy) and 4x4 CFA (RGB-IR)
	. enhanced RGB-IR/RCCB image quality
	. enhanced Color Representation for RCCB, RYYCy
	. enhanced 3DNR
	. Full resolution LDC
	. Real time 4-Ch overlayer Mixer
	. OFRC supporting Parallel Video Interface and MIPI Tx
	. Multi channel capability of up to 4 Ch Input and up to 4 Ch Output
**ADAS Hardware Accelerator**
	. Image Preprocessing for VSLAM Tracking
	. SIFT feature Extraction
	. Line Detection
**Video Codec**
	. 4K H.265/HEVC and H.264/AVC Encoder and Decoder
**Sensor and Video Interface**
	. 4 lane 10Gbps MIPI CSI Rx 2 Ch
	. 4 lane 10Gbps MIPI CSI Tx 2 Ch
	. Parallel Video Interface Output
**External Memory Interface**
	. Quad SPI
	. eMMC
	. SD
**High Speed Interface**
	. PCI express Gen3 x1 2 Ch
	. USB3.0 DRD 1 Ch
	. 1G Ethernet MAC
**Interface**
	. UART 4 Ch
	. CAN 2.0B/FD 2 Ch
	. LIN 2 Ch
	. I2C 8 Ch
	. SPI 3 Ch
	. PWM 4 Ch
	. I2S 1 Ch
**Analog IP**
	. ADC
	. Voltage level detector
	. Temperature Sensor
	. 2Kbits OTP for System
	. 32Kbits OTP for Security Core