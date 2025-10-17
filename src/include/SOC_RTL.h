
#ifndef SOC_RTL_H_
#define SOC_RTL_H_

#include "Apache.h"

#define PAD_SET_ADR_BASE        0xF040
#define TEST_ID_ADR             0xF044
#define PAD_SEL_RD              0xF048

#define     PULLUP          1
#define     PULLDOWN        0
//RESERVED
#define     PD_PULLUP       511
#define     PD_PULLDOWN     510
//APACHE5 I/O
#define     PD_NTRST                      0 
#define     PD_TCK                        1 
#define     PD_TMS                        2 
#define     PD_TDO                        3 
#define     PD_TDI                        4 
#define     PD_I2C1_SDA                   5 
#define     PD_I2C1_SCL                   6 
#define     PD_SEN_CK_O                   7 
#define     PD_SEN_RSTN_O                 8 
#define     PD_I2C0_SCL                   9 
#define     PD_I2C0_SDA                   10
#define     PD_I2C2_SCL                   11
#define     PD_I2C2_SDA                   12
#define     PD_PWM_0                      13
#define     PD_PWM_1                      14
#define     PD_PWM_2                      15
#define     PD_PWM_3                      16
#define     PD_SPI0_CK                    17
#define     PD_SPI0_SSN                   18
#define     PD_SPI0_MOSI                  19
#define     PD_SPI0_MISO                  20
#define     PD_SPI1_CK                    21
#define     PD_SPI1_SSN                   22
#define     PD_SPI1_MOSI                  23
#define     PD_SPI1_MISO                  24
#define     PD_CAN0_RX                    25
#define     PD_CAN0_TX                    26
#define     PD_CAN1_RX                    27
#define     PD_CAN1_TX                    28
#define     PD_UART0_RX                   29
#define     PD_UART0_TX                   30
#define     PD_UART1_RX                   31
#define     PD_UART1_TX                   32
#define     PD_UART2_RX                   33
#define     PD_UART2_TX                   34
#define     PD_UART3_RX                   35
#define     PD_UART3_TX                   36
#define     PD_QSPI_SCK                   37
#define     PD_QSPI_CSN                   38
#define     PD_QSPI_DQ0                   39
#define     PD_QSPI_DQ1                   40
#define     PD_QSPI_DQ2                   41
#define     PD_QSPI_DQ3                   42
#define     PD_SD_VOL_SEL                 43
#define     PD_EMMC_VOL_SEL               44
#define     PD_SD_CK                      45
#define     PD_SD_CMD                     46
#define     PD_SD_DATA0                   47
#define     PD_SD_DATA1                   48
#define     PD_SD_DATA2                   49
#define     PD_SD_DATA3                   50
#define     PD_SD_DETECT_N                51
#define     PD_SD_WRITE_PROT              52
#define     PD_EMMC_CK                    53
#define     PD_EMMC_RSTN                  54
#define     PD_EMMC_CMD                   55
#define     PD_EMMC_DATA0                 56
#define     PD_EMMC_DATA1                 57
#define     PD_EMMC_DATA2                 58
#define     PD_EMMC_DATA3                 59
#define     PD_EMMC_DATA4                 60
#define     PD_EMMC_DATA5                 61
#define     PD_EMMC_DATA6                 62
#define     PD_EMMC_DATA7                 63
#define     PD_EQOS_TXCLK                 64
#define     PD_EQOS_RXCLK                 65
#define     PD_EQOS_RMII_CLK              66
#define     PD_EQOS_MDC                   67
#define     PD_EQOS_MDIO                  68
#define     PD_EQOS_TXEN                  69
#define     PD_EQOS_TXD0                  70
#define     PD_EQOS_TXD1                  71
#define     PD_EQOS_TXD2                  72
#define     PD_EQOS_TXD3                  73
#define     PD_EQOS_RXDV                  74
#define     PD_EQOS_RXD0                  75
#define     PD_EQOS_RXD1                  76
#define     PD_EQOS_RXD2                  77
#define     PD_EQOS_RXD3                  78
#define     PD_TM                         79 
#define     PD_WBO_0                      100
#define     PD_WBO_1                      101

//SSP MODEL
#define     PD_MODEL_SSP_CSN               102  
#define     PD_MODEL_SSP_SCK               103  
#define     PD_MODEL_SSP_DQ0               104  
#define     PD_MODEL_SSP_DQ1               105  
#define     PD_MODEL_SSP_DQ2               106  
#define     PD_MODEL_SSP_DQ3               107  
//I2C
#define     PD_MODEL_I2C0_SDA              108  
#define     PD_MODEL_I2C0_SCL              109  
#define     PD_MODEL_I2C1_SDA              110  
#define     PD_MODEL_I2C1_SCL              111  
#define     PD_MODEL_I2C2_SDA              112
#define     PD_MODEL_I2C2_SCL              113  
//UART
#define     PD_MODEL_UART0_TX              114  
#define     PD_MODEL_UART0_RX              115  
#define     PD_MODEL_UART1_TX              116  
#define     PD_MODEL_UART1_RX              117  
#define     PD_MODEL_UART2_TX              118  
#define     PD_MODEL_UART2_RX              119  
#define     PD_MODEL_UART3_TX              120  
#define     PD_MODEL_UART3_RX              121  

#define     PD_MODEL_SD_DATA0              122
#define     PD_MODEL_SD_DATA1              123   
#define     PD_MODEL_SD_DATA2              124   
#define     PD_MODEL_SD_DATA3              125   
#define     PD_MODEL_SD_CMD                126   
#define     PD_MODEL_SD_CK                 127   
#define     PD_MODEL_SD_WRITE_PROT         128    
#define     PD_MODEL_SD_DETECT_N           129    

#define     PD_MODEL_EMMC_DATA_STRB        130   
#define     PD_MODEL_EMMC_DATA7            131   
#define     PD_MODEL_EMMC_DATA6            132   
#define     PD_MODEL_EMMC_DATA5            133   
#define     PD_MODEL_EMMC_DATA4            134   
#define     PD_MODEL_EMMC_DATA3            135   
#define     PD_MODEL_EMMC_DATA2            136   
#define     PD_MODEL_EMMC_DATA1            137   
#define     PD_MODEL_EMMC_DATA0            138   
#define     PD_MODEL_EMMC_CMD              139   
#define     PD_MODEL_EMMC_CK               140   
#define     PD_MODEL_EMMC_RSTN             141   

#define     PD_TMODE_AHB                   149
#define     PD_TEST_AHB_CLK                150
#define     PD_TEST_AHB_RSTN               151
#define     PD_TEST_AHB_MODE               152

#define     PD_TEST_AHB_DATA_READY           153
#define     PD_TEST_AHB_DOUT0                154
#define     PD_TEST_AHB_DOUT1                155
#define     PD_TEST_AHB_DOUT2                156
#define     PD_TEST_AHB_DOUT3                157
#define     PD_TEST_AHB_DOUT4                158
#define     PD_TEST_AHB_DOUT5                159
#define     PD_TEST_AHB_DOUT6                160
#define     PD_TEST_AHB_DOUT7                161
#define     PD_TEST_AHB_DOUT8                162
#define     PD_TEST_AHB_DOUT9                163
#define     PD_TEST_AHB_DOUT10               164
#define     PD_TEST_AHB_DOUT11               165
#define     PD_TEST_AHB_DOUT12               166
#define     PD_TEST_AHB_DOUT13               167
#define     PD_TEST_AHB_DOUT14               168
#define     PD_TEST_AHB_DOUT15               169
#define     PD_TEST_AHB_DOUT16               170
#define     PD_TEST_AHB_DOUT17               171
#define     PD_TEST_AHB_DOUT18               172
#define     PD_TEST_AHB_DOUT19               173
#define     PD_TEST_AHB_DOUT20               174
#define     PD_TEST_AHB_DOUT21               175
#define     PD_TEST_AHB_DOUT22               176
#define     PD_TEST_AHB_DOUT23               177
#define     PD_TEST_AHB_DOUT24               178
#define     PD_TEST_AHB_DOUT25               179
#define     PD_TEST_AHB_DOUT26               180
#define     PD_TEST_AHB_DOUT27               181
#define     PD_TEST_AHB_DOUT28               182
#define     PD_TEST_AHB_DOUT29               183
#define     PD_TEST_AHB_DOUT30               184
#define     PD_TEST_AHB_DOUT31               185
#define     PD_TEST_AHB_DOUT_EN              186

#define     PD_TEST_AHB_DIN0                187
#define     PD_TEST_AHB_DIN1                188
#define     PD_TEST_AHB_DIN2                189
#define     PD_TEST_AHB_DIN3                190
#define     PD_TEST_AHB_DIN4                191
#define     PD_TEST_AHB_DIN5                192
#define     PD_TEST_AHB_DIN6                193
#define     PD_TEST_AHB_DIN7                194
#define     PD_TEST_AHB_DIN8                195
#define     PD_TEST_AHB_DIN9                196
#define     PD_TEST_AHB_DIN10               197
#define     PD_TEST_AHB_DIN11               198
#define     PD_TEST_AHB_DIN12               199
#define     PD_TEST_AHB_DIN13               200
#define     PD_TEST_AHB_DIN14               201
#define     PD_TEST_AHB_DIN15               202
#define     PD_TEST_AHB_DIN16               203
#define     PD_TEST_AHB_DIN17               204
#define     PD_TEST_AHB_DIN18               205
#define     PD_TEST_AHB_DIN19               206
#define     PD_TEST_AHB_DIN20               207
#define     PD_TEST_AHB_DIN21               208
#define     PD_TEST_AHB_DIN22               209
#define     PD_TEST_AHB_DIN23               210
#define     PD_TEST_AHB_DIN24               211
#define     PD_TEST_AHB_DIN25               212
#define     PD_TEST_AHB_DIN26               213
#define     PD_TEST_AHB_DIN27               214
#define     PD_TEST_AHB_DIN28               215
#define     PD_TEST_AHB_DIN29               216
#define     PD_TEST_AHB_DIN30               217
#define     PD_TEST_AHB_DIN31               218
#define     PD_TEST_AHB_DIN_EN              219

#define     PD_MODEL_EQOS_TXCLK             220
#define     PD_MODEL_EQOS_RXCLK             221
#define     PD_MODEL_EQOS_RMII_CLK          222
#define     PD_MODEL_EQOS_MDC               223
#define     PD_MODEL_EQOS_MDIO              224
#define     PD_MODEL_EQOS_TXEN              225
#define     PD_MODEL_EQOS_TXD0              226
#define     PD_MODEL_EQOS_TXD1              227
#define     PD_MODEL_EQOS_TXD2              228
#define     PD_MODEL_EQOS_TXD3              229
#define     PD_MODEL_EQOS_RXDV              230
#define     PD_MODEL_EQOS_RXD0              231
#define     PD_MODEL_EQOS_RXD1              232
#define     PD_MODEL_EQOS_RXD2              233
#define     PD_MODEL_EQOS_RXD3              234
#define     PD_MODEL_EQOS_PHY_INTR          235
#define     PD_MODEL_EQOS_AUX_TS_TRIG0      236
#define     PD_MODEL_EQOS_AUX_TS_TRIG1      237
#define     PD_MODEL_EQOS_AUX_TS_TRIG2      238
#define     PD_MODEL_EQOS_AUX_TS_TRIG3      239
                                     
#define     PD_CXDT_TDO                     240
#define     PD_CXDT_TDI                     241
#define     PD_CXDT_NTRST                   242
#define     PD_CXDT_SWCLKTCK                243
#define     PD_CXDT_SWDIOTMS                244
//LIN_MODEL & TRX
#define     PD_LIN0_TRX_TX                  245  
#define     PD_LIN0_TRX_RX                  246   
#define     PD_LIN1_TRX_TX                  247   
#define     PD_LIN1_TRX_RX                  248   
#define     PD_LIN0_MODEL_TX                249   
#define     PD_LIN0_MODEL_RX                250   

#define     PD_UART_MODEL_I_TX              251   
#define     PD_UART_MODEL_O_RX              252   

#define     PD_MODEL_SFLASH_CLK             253
#define     PD_MODEL_SFLASH_CSN             254
#define     PD_MODEL_SFLASH_DIO             255
#define     PD_MODEL_SFLASH_DO              256
#define     PD_MODEL_SFLASH_WPN             257
#define     PD_MODEL_SFLASH_HOLDN           258
//PWM MODEL
#define     PD_MODEL_IN_PWM_0            259
#define     PD_MODEL_IN_PWM_1            260
#define     PD_MODEL_IN_PWM_2            261
#define     PD_MODEL_IN_PWM_3            262
#define     PD_MODEL_OUT_PWM_0           263
#define     PD_MODEL_OUT_PWM_1           264
#define     PD_MODEL_OUT_PWM_2           265
#define     PD_MODEL_OUT_PWM_3           266

//CAN MODEL
#define     PD_MODEL_CAN_TX           267
#define     PD_MODEL_CAN_RX           268

#define     PD_TEST_IO_NTRST                     400 
#define     PD_TEST_IO_TCK                       401 
#define     PD_TEST_IO_TMS                       402 
#define     PD_TEST_IO_TDO                       403 
#define     PD_TEST_IO_TDI                       404 
#define     PD_TEST_IO_I2C1_SDA                  405 
#define     PD_TEST_IO_I2C1_SCL                  406 
#define     PD_TEST_IO_SEN_CK_O                  407 
#define     PD_TEST_IO_SEN_RSTN_O                408 
#define     PD_TEST_IO_I2C0_SCL                  409 
#define     PD_TEST_IO_I2C0_SDA                  410
#define     PD_TEST_IO_I2C2_SCL                  411
#define     PD_TEST_IO_I2C2_SDA                  412
#define     PD_TEST_IO_PWM_0                     413
#define     PD_TEST_IO_PWM_1                     414
#define     PD_TEST_IO_PWM_2                     415
#define     PD_TEST_IO_PWM_3                     416
#define     PD_TEST_IO_SPI0_CK                   417
#define     PD_TEST_IO_SPI0_SSN                  418
#define     PD_TEST_IO_SPI0_MOSI                 419
#define     PD_TEST_IO_SPI0_MISO                 420
#define     PD_TEST_IO_SPI1_CK                   421
#define     PD_TEST_IO_SPI1_SSN                  422
#define     PD_TEST_IO_SPI1_MOSI                 423
#define     PD_TEST_IO_SPI1_MISO                 424
#define     PD_TEST_IO_CAN0_RX                   425
#define     PD_TEST_IO_CAN0_TX                   426
#define     PD_TEST_IO_CAN1_RX                   427
#define     PD_TEST_IO_CAN1_TX                   428
#define     PD_TEST_IO_UART0_RX                  429
#define     PD_TEST_IO_UART0_TX                  430
#define     PD_TEST_IO_UART1_RX                  431
#define     PD_TEST_IO_UART1_TX                  432
#define     PD_TEST_IO_UART2_RX                  433
#define     PD_TEST_IO_UART2_TX                  434
#define     PD_TEST_IO_UART3_RX                  435
#define     PD_TEST_IO_UART3_TX                  436
#define     PD_TEST_IO_QSPI_SCK                  437
#define     PD_TEST_IO_QSPI_CSN                  438
#define     PD_TEST_IO_QSPI_DQ0                  439
#define     PD_TEST_IO_QSPI_DQ1                  440
#define     PD_TEST_IO_QSPI_DQ2                  441
#define     PD_TEST_IO_QSPI_DQ3                  442
#define     PD_TEST_IO_SD_VOL_SEL                443
#define     PD_TEST_IO_EMMC_VOL_SEL              444
#define     PD_TEST_IO_SD_CK                     445
#define     PD_TEST_IO_SD_CMD                    446
#define     PD_TEST_IO_SD_DATA0                  447
#define     PD_TEST_IO_SD_DATA1                  448
#define     PD_TEST_IO_SD_DATA2                  449
#define     PD_TEST_IO_SD_DATA3                  450
#define     PD_TEST_IO_SD_DETECT_N               451
#define     PD_TEST_IO_SD_WRITE_PROT             452
#define     PD_TEST_IO_EMMC_CK                   453
#define     PD_TEST_IO_EMMC_RSTN                 454
#define     PD_TEST_IO_EMMC_CMD                  455
#define     PD_TEST_IO_EMMC_DATA0                456
#define     PD_TEST_IO_EMMC_DATA1                457
#define     PD_TEST_IO_EMMC_DATA2                458
#define     PD_TEST_IO_EMMC_DATA3                459
#define     PD_TEST_IO_EMMC_DATA4                460
#define     PD_TEST_IO_EMMC_DATA5                461
#define     PD_TEST_IO_EMMC_DATA6                462
#define     PD_TEST_IO_EMMC_DATA7                463
#define     PD_TEST_IO_EQOS_TXCLK                464
#define     PD_TEST_IO_EQOS_RXCLK                465
#define     PD_TEST_IO_EQOS_RMII_CLK             466
#define     PD_TEST_IO_EQOS_MDC                  467
#define     PD_TEST_IO_EQOS_MDIO                 468
#define     PD_TEST_IO_EQOS_TXEN                 469
#define     PD_TEST_IO_EQOS_TXD0                 470
#define     PD_TEST_IO_EQOS_TXD1                 471
#define     PD_TEST_IO_EQOS_TXD2                 472
#define     PD_TEST_IO_EQOS_TXD3                 473
#define     PD_TEST_IO_EQOS_RXDV                 474
#define     PD_TEST_IO_EQOS_RXD0                 475
#define     PD_TEST_IO_EQOS_RXD1                 476
#define     PD_TEST_IO_EQOS_RXD2                 477
#define     PD_TEST_IO_EQOS_RXD3                 478

#define     PD_MODEL_SEN_RST_N                   479

extern INT32 nxtc__diff(UINT32 SADDR0, UINT32 SADDR1, UINT32 SIZE);
extern INT32 nxtc__fwrite(UINT32 st_adr, UINT32 ed_adr, CHAR *fname);
extern INT32 nxtc__fread(UINT32 st_adr, CHAR *fname);
extern void ASM_PC_JUMP_TO_RAM(void);
extern void ASM_PC_JUMP_TO_DDR(void);
extern void SoCDrv_TB_PAD_Set(UINT32 PAD_A, UINT32 PAD_B);
extern void SoCDrv_TEST_ID_Set(UINT32 TEST_ID);
extern UINT32 SoCDrv_TB_PAD_SEL_RD(UINT32 PAD_A);


#endif
