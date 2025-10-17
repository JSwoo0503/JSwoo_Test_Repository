/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : Drv_ICU.h (ES_EVT0)
*   Date       : 2022-06-30 14:20
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#ifndef DRV_ICU_H__
#define DRV_ICU_H__

#include "Drv_A6_ICU_Register.h"

/* PRQA S 0791 ++ */

#define PAD_NTRST                                 0U
#define FM_NTRST_o_jtag_trstn                     0U
#define FM_NTRST_i_gpio_a_out_0                   5U
#define FM_NTRST_o_gpio_a_in_0                    5U

#define PAD_TCK                                   1U
#define FM_TCK_o_jtag_tck                         0U
#define FM_TCK_i_gpio_a_out_1                     5U
#define FM_TCK_o_gpio_a_in_1                      5U

#define PAD_TMS                                   2U
#define FM_TMS_i_swdo                             0U
#define FM_TMS_o_jtag_tms                         0U
#define FM_TMS_i_gpio_a_out_2                     5U
#define FM_TMS_o_gpio_a_in_2                      5U

#define PAD_TDO                                   3U
#define FM_TDO_i_jtag_tdo                         0U
#define FM_TDO_i_gpio_a_out_3                     5U
#define FM_TDO_o_gpio_a_in_3                      5U

#define PAD_TDI                                   4U
#define FM_TDI_o_jtag_tdi                         0U
#define FM_TDI_i_gpio_a_out_4                     5U
#define FM_TDI_o_gpio_a_in_4                      5U

#define PAD_PCIE0_WAKE_N                          5U
#define FM_PCIE0_WAKE_N_i_pcie0_wake_n_out        0U
#define FM_PCIE0_WAKE_N_o_pcie0_wake_n_in         0U
#define FM_PCIE0_WAKE_N_o_isp0_ext_sync           2U
#define FM_PCIE0_WAKE_N_o_isp1_ext_sync           3U
#define FM_PCIE0_WAKE_N_i__parallel__clkout       4U
#define FM_PCIE0_WAKE_N_i_gpio_d_out_3            5U
#define FM_PCIE0_WAKE_N_o_gpio_d_in_3             5U
#define FM_PCIE0_WAKE_N_i__parallel__data_14      6U
#define FM_PCIE0_WAKE_N_i__parallel__data_4       7U

#define PAD_PCIE0_CLKREQ_N                        6U
#define FM_PCIE0_CLKREQ_N_i_pcie0_clkreq_n_out    0U
#define FM_PCIE0_CLKREQ_N_o_pcie0_clkreq_n_in     0U
#define FM_PCIE0_CLKREQ_N_i__parallel__hsync_out  4U
#define FM_PCIE0_CLKREQ_N_i_gpio_d_out_4          5U
#define FM_PCIE0_CLKREQ_N_o_gpio_d_in_4           5U
#define FM_PCIE0_CLKREQ_N_i__parallel__data_15    6U
#define FM_PCIE0_CLKREQ_N_i__parallel__data_5     7U

#define PAD_PCIE1_WAKE_N                          7U
#define FM_PCIE1_WAKE_N_i_pcie1_wake_n_out        0U
#define FM_PCIE1_WAKE_N_o_pcie1_wake_n_in         0U
#define FM_PCIE1_WAKE_N_i_isp0_hd_slave           2U
#define FM_PCIE1_WAKE_N_i_isp1_hd_slave           3U
#define FM_PCIE1_WAKE_N_i__parallel__hact_out     4U
#define FM_PCIE1_WAKE_N_i_gpio_d_out_5            5U
#define FM_PCIE1_WAKE_N_o_gpio_d_in_5             5U
#define FM_PCIE1_WAKE_N_i__parallel__data_16      6U
#define FM_PCIE1_WAKE_N_i__parallel__data_6       7U

#define PAD_PCIE1_CLKREQ_N                        8U
#define FM_PCIE1_CLKREQ_N_i_pcie1_clkreq_n_out    0U
#define FM_PCIE1_CLKREQ_N_o_pcie1_clkreq_n_in     0U
#define FM_PCIE1_CLKREQ_N_i_isp0_vd_slave         2U
#define FM_PCIE1_CLKREQ_N_i_isp1_vd_slave         3U
#define FM_PCIE1_CLKREQ_N_i__parallel__vsync_out  4U
#define FM_PCIE1_CLKREQ_N_i_gpio_d_out_6          5U
#define FM_PCIE1_CLKREQ_N_o_gpio_d_in_6           5U
#define FM_PCIE1_CLKREQ_N_i__parallel__data_17    6U
#define FM_PCIE1_CLKREQ_N_i__parallel__data_7     7U

#define PAD_USB_OVRCUR_N                          9U
#define FM_USB_OVRCUR_N_o_usb_ovrcur_n_in         0U
#define FM_USB_OVRCUR_N_i_gpio_d_out_7            5U
#define FM_USB_OVRCUR_N_o_gpio_d_in_7             5U
#define FM_USB_OVRCUR_N_i__parallel__data_18      6U
#define FM_USB_OVRCUR_N_i__parallel__data_8       7U

#define PAD_USB_PORT_PWR                          10U
#define FM_USB_PORT_PWR_i_usb_port_pwr_out        0U
#define FM_USB_PORT_PWR_i_gpio_d_out_8            5U
#define FM_USB_PORT_PWR_o_gpio_d_in_8             5U
#define FM_USB_PORT_PWR_i__parallel__data_19      6U
#define FM_USB_PORT_PWR_i__parallel__data_9       7U

#define PAD_I2C1_SDA                              11U
#define FM_I2C1_SDA_i_gpio_a_out_5                0U
#define FM_I2C1_SDA_o_gpio_a_in_5                 0U
#define FM_I2C1_SDA_i_i2c1_sda_out                1U
#define FM_I2C1_SDA_o_i2c1_sda_in                 1U

#define PAD_I2C1_SCL                              12U
#define FM_I2C1_SCL_i_gpio_a_out_6                0U
#define FM_I2C1_SCL_o_gpio_a_in_6                 0U
#define FM_I2C1_SCL_i_i2c1_scl_out                1U
#define FM_I2C1_SCL_o_i2c1_scl_in                 1U

#define PAD_SEN0_CK_O                             13U
#define FM_SEN0_CK_O_i_gpio_a_out_7               0U
#define FM_SEN0_CK_O_o_gpio_a_in_7                0U
#define FM_SEN0_CK_O_i_sen0_ck_o_out              1U

#define PAD_SEN0_RSTN_O                           14U
#define FM_SEN0_RSTN_O_i_gpio_a_out_8             0U
#define FM_SEN0_RSTN_O_o_gpio_a_in_8              0U
#define FM_SEN0_RSTN_O_i_sen0_rstn_o_out          1U

#define PAD_SEN1_CK_O                             15U
#define FM_SEN1_CK_O_i_gpio_a_out_9               0U
#define FM_SEN1_CK_O_o_gpio_a_in_9                0U
#define FM_SEN1_CK_O_i_sen1_ck_o_out              1U

#define PAD_SEN1_RSTN_O                           16U
#define FM_SEN1_RSTN_O_i_gpio_a_out_10            0U
#define FM_SEN1_RSTN_O_o_gpio_a_in_10             0U
#define FM_SEN1_RSTN_O_i_sen1_rstn_o_out          1U

#define PAD_I2C0_SCL                              17U
#define FM_I2C0_SCL_i_gpio_a_out_11               0U
#define FM_I2C0_SCL_o_gpio_a_in_11                0U
#define FM_I2C0_SCL_i_i2c0_scl_out                1U
#define FM_I2C0_SCL_o_i2c0_scl_in                 1U

#define PAD_I2C0_SDA                              18U
#define FM_I2C0_SDA_i_gpio_a_out_12               0U
#define FM_I2C0_SDA_o_gpio_a_in_12                0U
#define FM_I2C0_SDA_i_i2c0_sda_out                1U
#define FM_I2C0_SDA_o_i2c0_sda_in                 1U

#define PAD_I2C2_SCL                              19U
#define FM_I2C2_SCL_o_i2c_safe_scl_in             0U
#define FM_I2C2_SCL_i_i2c2_scl_out                1U
#define FM_I2C2_SCL_o_i2c2_scl_in                 1U
#define FM_I2C2_SCL_i_gpio_a_out_13               5U
#define FM_I2C2_SCL_o_gpio_a_in_13                5U

#define PAD_I2C2_SDA                              20U
#define FM_I2C2_SDA_i_i2c_safe_sda_out            0U
#define FM_I2C2_SDA_o_i2c_safe_sda_in             0U
#define FM_I2C2_SDA_i_i2c2_sda_out                1U
#define FM_I2C2_SDA_o_i2c2_sda_in                 1U
#define FM_I2C2_SDA_i_gpio_a_out_14               5U
#define FM_I2C2_SDA_o_gpio_a_in_14                5U

#define PAD_I2C3_SCL                              21U
#define FM_I2C3_SCL_i_gpio_a_out_15               0U
#define FM_I2C3_SCL_o_gpio_a_in_15                0U
#define FM_I2C3_SCL_i_i2c3_scl_out                1U
#define FM_I2C3_SCL_o_i2c3_scl_in                 1U
#define FM_I2C3_SCL_i__parallel__data_9           6U

#define PAD_I2C3_SDA                              22U
#define FM_I2C3_SDA_i_gpio_a_out_16               0U
#define FM_I2C3_SDA_o_gpio_a_in_16                0U
#define FM_I2C3_SDA_i_i2c3_sda_out                1U
#define FM_I2C3_SDA_o_i2c3_sda_in                 1U
#define FM_I2C3_SDA_i__parallel__data_8           6U

#define PAD_I2C4_SCL                              23U
#define FM_I2C4_SCL_i_gpio_a_out_17               0U
#define FM_I2C4_SCL_o_gpio_a_in_17                0U
#define FM_I2C4_SCL_i_i2c4_scl_out                1U
#define FM_I2C4_SCL_o_i2c4_scl_in                 1U
#define FM_I2C4_SCL_i__parallel__data_7           6U

#define PAD_I2C4_SDA                              24U
#define FM_I2C4_SDA_i_gpio_a_out_18               0U
#define FM_I2C4_SDA_o_gpio_a_in_18                0U
#define FM_I2C4_SDA_i_i2c4_sda_out                1U
#define FM_I2C4_SDA_o_i2c4_sda_in                 1U
#define FM_I2C4_SDA_i__parallel__data_6           6U

#define PAD_I2C5_SCL                              25U
#define FM_I2C5_SCL_i_gpio_a_out_19               0U
#define FM_I2C5_SCL_o_gpio_a_in_19                0U
#define FM_I2C5_SCL_i_i2c5_scl_out                1U
#define FM_I2C5_SCL_o_i2c5_scl_in                 1U
#define FM_I2C5_SCL_i__parallel__data_5           6U

#define PAD_I2C5_SDA                              26U
#define FM_I2C5_SDA_i_gpio_a_out_20               0U
#define FM_I2C5_SDA_o_gpio_a_in_20                0U
#define FM_I2C5_SDA_i_i2c5_sda_out                1U
#define FM_I2C5_SDA_o_i2c5_sda_in                 1U
#define FM_I2C5_SDA_o_opt_jtag_trstn              4U
#define FM_I2C5_SDA_i__parallel__data_4           6U

#define PAD_I2C6_SCL                              27U
#define FM_I2C6_SCL_i_gpio_a_out_21               0U
#define FM_I2C6_SCL_o_gpio_a_in_21                0U
#define FM_I2C6_SCL_i_i2c6_scl_out                1U
#define FM_I2C6_SCL_o_i2c6_scl_in                 1U
#define FM_I2C6_SCL_o_eqos_crs_in                 2U
#define FM_I2C6_SCL_o_opt_jtag_tck                4U
#define FM_I2C6_SCL_i__parallel__data_3           6U

#define PAD_I2C6_SDA                              28U
#define FM_I2C6_SDA_i_gpio_a_out_22               0U
#define FM_I2C6_SDA_o_gpio_a_in_22                0U
#define FM_I2C6_SDA_i_i2c6_sda_out                1U
#define FM_I2C6_SDA_o_i2c6_sda_in                 1U
#define FM_I2C6_SDA_o_eqos_col_in                 2U
#define FM_I2C6_SDA_i_opt_swdo                    4U
#define FM_I2C6_SDA_o_opt_jtag_tms                4U
#define FM_I2C6_SDA_i__parallel__data_2           6U

#define PAD_I2C7_SCL                              29U
#define FM_I2C7_SCL_i_gpio_a_out_23               0U
#define FM_I2C7_SCL_o_gpio_a_in_23                0U
#define FM_I2C7_SCL_i_i2c7_scl_out                1U
#define FM_I2C7_SCL_o_i2c7_scl_in                 1U
#define FM_I2C7_SCL_i_sd_vdd_on                   2U
#define FM_I2C7_SCL_o_opt_jtag_tdi                4U
#define FM_I2C7_SCL_i__parallel__data_1           6U
#define FM_I2C7_SCL_i__parallel__data_8           7U

#define PAD_I2C7_SDA                              30U
#define FM_I2C7_SDA_i_gpio_a_out_24               0U
#define FM_I2C7_SDA_o_gpio_a_in_24                0U
#define FM_I2C7_SDA_i_i2c7_sda_out                1U
#define FM_I2C7_SDA_o_i2c7_sda_in                 1U
#define FM_I2C7_SDA_i_emmc_vdd_on                 2U
#define FM_I2C7_SDA_i_opt_jtag_tdo                4U
#define FM_I2C7_SDA_i__parallel__data_0           6U
#define FM_I2C7_SDA_i__parallel__data_9           7U

#define PAD_PWM_0                                 31U
#define FM_PWM_0_i_gpio_a_out_25                  0U
#define FM_PWM_0_o_gpio_a_in_25                   0U
#define FM_PWM_0_i_pwm_0_out                      1U
#define FM_PWM_0_o_lin1_rx_in                     3U
#define FM_PWM_0_i_pcie0_cmn_div_clk              4U
#define FM_PWM_0_i_pcie0_o_dtb                    6U
#define FM_PWM_0_i_usbphy_clk12mohci              7U

#define PAD_PWM_1                                 32U
#define FM_PWM_1_i_gpio_a_out_26                  0U
#define FM_PWM_1_o_gpio_a_in_26                   0U
#define FM_PWM_1_i_pwm_1_out                      1U
#define FM_PWM_1_i_lin1_tx_out                    3U
#define FM_PWM_1_i_pcie0_phylayer_dbg             4U
#define FM_PWM_1_i_pcie0_layer2_dbg               6U
#define FM_PWM_1_i_usbphy_freeclk                 7U

#define PAD_PWM_2                                 33U
#define FM_PWM_2_i_gpio_a_out_27                  0U
#define FM_PWM_2_o_gpio_a_in_27                   0U
#define FM_PWM_2_i_pwm_2_out                      1U
#define FM_PWM_2_i_pcie1_cmn_div_clk              4U
#define FM_PWM_2_i_pcie1_o_dtb                    6U
#define FM_PWM_2_i_usbphy_pipe_pclk               7U

#define PAD_PWM_3                                 34U
#define FM_PWM_3_i_gpio_a_out_28                  0U
#define FM_PWM_3_o_gpio_a_in_28                   0U
#define FM_PWM_3_i_pwm_3_out                      1U
#define FM_PWM_3_o_eqos_phy_intr_in               3U
#define FM_PWM_3_i_pcie1_phylayer_dbg             4U
#define FM_PWM_3_i_pcie1_layer2_dbg               6U
#define FM_PWM_3_i_usbphy_clk48mohci              7U

#define PAD_SPI0_CK                               35U
#define FM_SPI0_CK_i_spi_0_sck_out                0U
#define FM_SPI0_CK_o_spi_0_sck_in_fm0             0U
#define FM_SPI0_CK_o_uart2_rx_in                  3U
#define FM_SPI0_CK_i_gpio_a_out_29                5U
#define FM_SPI0_CK_o_gpio_a_in_29                 5U

#define PAD_SPI0_SSN                              36U
#define FM_SPI0_SSN_i_spi_0_ssn_out               0U
#define FM_SPI0_SSN_o_spi_0_ssn_in_fm0            0U
#define FM_SPI0_SSN_i_uart2_tx_out                3U
#define FM_SPI0_SSN_i_gpio_a_out_30               5U
#define FM_SPI0_SSN_o_gpio_a_in_30                5U

#define PAD_SPI0_MOSI                             37U
#define FM_SPI0_MOSI_i_spi_0_mosi_out             0U
#define FM_SPI0_MOSI_o_spi_0_mosi_in_fm0          0U
#define FM_SPI0_MOSI_o_uart3_rx_in                4U
#define FM_SPI0_MOSI_i_gpio_a_out_31              5U
#define FM_SPI0_MOSI_o_gpio_a_in_31               5U

#define PAD_SPI0_MISO                             38U
#define FM_SPI0_MISO_i_spi_0_miso_out             0U
#define FM_SPI0_MISO_o_spi_0_miso_in_fm0          0U
#define FM_SPI0_MISO_i_uart3_tx_out               4U
#define FM_SPI0_MISO_i_gpio_b_out_0               5U
#define FM_SPI0_MISO_o_gpio_b_in_0                5U

#define PAD_SPI1_CK                               39U
#define FM_SPI1_CK_i_gpio_b_out_1                 0U
#define FM_SPI1_CK_o_gpio_b_in_1                  0U
#define FM_SPI1_CK_i_spi_1_sck_out                1U
#define FM_SPI1_CK_o_spi_1_sck_in                 1U
#define FM_SPI1_CK_i_cs_trace_data_2              2U
#define FM_SPI1_CK_o_uart0_rx_in                  3U

#define PAD_SPI1_SSN                              40U
#define FM_SPI1_SSN_i_gpio_b_out_2                0U
#define FM_SPI1_SSN_o_gpio_b_in_2                 0U
#define FM_SPI1_SSN_i_spi_1_ssn_out               1U
#define FM_SPI1_SSN_o_spi_1_ssn_in                1U
#define FM_SPI1_SSN_i_cs_trace_data_3             2U
#define FM_SPI1_SSN_i_uart0_tx_out                3U

#define PAD_SPI1_MOSI                             41U
#define FM_SPI1_MOSI_i_gpio_b_out_3               0U
#define FM_SPI1_MOSI_o_gpio_b_in_3                0U
#define FM_SPI1_MOSI_i_spi_1_mosi_out             1U
#define FM_SPI1_MOSI_o_spi_1_mosi_in              1U
#define FM_SPI1_MOSI_o_cs_edbg_req                2U
#define FM_SPI1_MOSI_o_uart1_rx_in                3U

#define PAD_SPI1_MISO                             42U
#define FM_SPI1_MISO_i_gpio_b_out_4               0U
#define FM_SPI1_MISO_o_gpio_b_in_4                0U
#define FM_SPI1_MISO_i_spi_1_miso_out             1U
#define FM_SPI1_MISO_o_spi_1_miso_in              1U
#define FM_SPI1_MISO_i_cs_edbg_ack                2U
#define FM_SPI1_MISO_i_uart1_tx_out               3U

#define PAD_SPI2_CK                               43U
#define FM_SPI2_CK_i_gpio_b_out_5                 0U
#define FM_SPI2_CK_o_gpio_b_in_5                  0U
#define FM_SPI2_CK_i_spi_2_sck_out                1U
#define FM_SPI2_CK_o_spi_2_sck_in                 1U
#define FM_SPI2_CK_i_pcie0_o_dtb                  3U
#define FM_SPI2_CK_i_pcie0_cmn_div_clk            4U
#define FM_SPI2_CK_i__parallel__data_10           6U
#define FM_SPI2_CK_i__parallel__hact_out          7U

#define PAD_SPI2_SSN                              44U
#define FM_SPI2_SSN_i_gpio_b_out_6                0U
#define FM_SPI2_SSN_o_gpio_b_in_6                 0U
#define FM_SPI2_SSN_i_spi_2_ssn_out               1U
#define FM_SPI2_SSN_o_spi_2_ssn_in                1U
#define FM_SPI2_SSN_i_pcie0_layer2_dbg            3U
#define FM_SPI2_SSN_i_pcie0_phylayer_dbg          4U
#define FM_SPI2_SSN_i__parallel__data_11          6U
#define FM_SPI2_SSN_i__parallel__vsync_out        7U

#define PAD_SPI2_MOSI                             45U
#define FM_SPI2_MOSI_i_gpio_b_out_7               0U
#define FM_SPI2_MOSI_o_gpio_b_in_7                0U
#define FM_SPI2_MOSI_i_spi_2_mosi_out             1U
#define FM_SPI2_MOSI_o_spi_2_mosi_in              1U
#define FM_SPI2_MOSI_i_pcie1_o_dtb                3U
#define FM_SPI2_MOSI_i_pcie1_cmn_div_clk          4U
#define FM_SPI2_MOSI_i__parallel__data_12         6U
#define FM_SPI2_MOSI_i__parallel__clkout          7U

#define PAD_SPI2_MISO                             46U
#define FM_SPI2_MISO_i_gpio_b_out_8               0U
#define FM_SPI2_MISO_o_gpio_b_in_8                0U
#define FM_SPI2_MISO_i_spi_2_miso_out             1U
#define FM_SPI2_MISO_o_spi_2_miso_in              1U
#define FM_SPI2_MISO_o_isp0_ext_sync              2U
#define FM_SPI2_MISO_i_pcie1_layer2_dbg           3U
#define FM_SPI2_MISO_i_pcie1_phylayer_dbg         4U
#define FM_SPI2_MISO_i__parallel__data_13         6U
#define FM_SPI2_MISO_i__parallel__hsync_out       7U

#define PAD_I2S_DIN                               47U
#define FM_I2S_DIN_i_gpio_b_out_9                 0U
#define FM_I2S_DIN_o_gpio_b_in_9                  0U
#define FM_I2S_DIN_o_i2s_sdi                      1U
#define FM_I2S_DIN_o_isp1_ext_sync                2U
#define FM_I2S_DIN_i__parallel__data_23           6U
#define FM_I2S_DIN_i__parallel__hact_out          7U

#define PAD_I2S_DOUT                              48U
#define FM_I2S_DOUT_i_gpio_b_out_10               0U
#define FM_I2S_DOUT_o_gpio_b_in_10                0U
#define FM_I2S_DOUT_i_i2s_sdo                     1U
#define FM_I2S_DOUT_i__parallel__data_22          6U
#define FM_I2S_DOUT_i__parallel__vsync_out        7U

#define PAD_I2S_WCLK                              49U
#define FM_I2S_WCLK_i_gpio_b_out_11               0U
#define FM_I2S_WCLK_o_gpio_b_in_11                0U
#define FM_I2S_WCLK_o_i2s_ws_slv                  1U
#define FM_I2S_WCLK_i__parallel__data_21          6U
#define FM_I2S_WCLK_i__parallel__clkout           7U

#define PAD_I2S_SCLK                              50U
#define FM_I2S_SCLK_i_gpio_b_out_12               0U
#define FM_I2S_SCLK_o_gpio_b_in_12                0U
#define FM_I2S_SCLK_o_i2s_sclk                    1U
#define FM_I2S_SCLK_i__parallel__data_20          6U
#define FM_I2S_SCLK_i__parallel__hsync_out        7U

#define PAD_CAN0_RX                               51U
#define FM_CAN0_RX_i_gpio_b_out_13                0U
#define FM_CAN0_RX_o_gpio_b_in_13                 0U
#define FM_CAN0_RX_o_can0_rx_in                   1U
#define FM_CAN0_RX_o_lin0_rx_in                   2U

#define PAD_CAN0_TX                               52U
#define FM_CAN0_TX_i_gpio_b_out_14                0U
#define FM_CAN0_TX_o_gpio_b_in_14                 0U
#define FM_CAN0_TX_i_can0_tx_out                  1U
#define FM_CAN0_TX_i_lin0_tx_out                  2U

#define PAD_CAN1_RX                               53U
#define FM_CAN1_RX_i_gpio_b_out_15                0U
#define FM_CAN1_RX_o_gpio_b_in_15                 0U
#define FM_CAN1_RX_o_can1_rx_in                   1U
#define FM_CAN1_RX_o_lin1_rx_in                   2U

#define PAD_CAN1_TX                               54U
#define FM_CAN1_TX_i_gpio_b_out_16                0U
#define FM_CAN1_TX_o_gpio_b_in_16                 0U
#define FM_CAN1_TX_i_can1_tx_out                  1U
#define FM_CAN1_TX_i_lin1_tx_out                  2U

#define PAD_UART0_RX                              55U
#define FM_UART0_RX_i_gpio_b_out_17               0U
#define FM_UART0_RX_o_gpio_b_in_17                0U
#define FM_UART0_RX_o_uart0_rx_in                 1U
#define FM_UART0_RX_o_lin0_rx_in                  4U

#define PAD_UART0_TX                              56U
#define FM_UART0_TX_i_gpio_b_out_18               0U
#define FM_UART0_TX_o_gpio_b_in_18                0U
#define FM_UART0_TX_i_uart0_tx_out                1U
#define FM_UART0_TX_i_lin0_tx_out                 4U

#define PAD_UART1_RX                              57U
#define FM_UART1_RX_i_gpio_b_out_19               0U
#define FM_UART1_RX_o_gpio_b_in_19                0U
#define FM_UART1_RX_o_uart1_rx_in                 1U
#define FM_UART1_RX_o_lin1_rx_in                  4U

#define PAD_UART1_TX                              58U
#define FM_UART1_TX_i_gpio_b_out_20               0U
#define FM_UART1_TX_o_gpio_b_in_20                0U
#define FM_UART1_TX_i_uart1_tx_out                1U
#define FM_UART1_TX_i_lin1_tx_out                 4U

#define PAD_UART2_RX                              59U
#define FM_UART2_RX_i_gpio_b_out_21               0U
#define FM_UART2_RX_o_gpio_b_in_21                0U
#define FM_UART2_RX_o_uart2_rx_in                 1U
#define FM_UART2_RX_i_cs_trace_clk                2U
#define FM_UART2_RX_o_eqos_aux_ts_trig0_in        3U

#define PAD_UART2_TX                              60U
#define FM_UART2_TX_i_gpio_b_out_22               0U
#define FM_UART2_TX_o_gpio_b_in_22                0U
#define FM_UART2_TX_i_uart2_tx_out                1U
#define FM_UART2_TX_i_cs_trace_ctl                2U
#define FM_UART2_TX_o_eqos_aux_ts_trig1_in        3U

#define PAD_UART3_RX                              61U
#define FM_UART3_RX_i_gpio_b_out_23               0U
#define FM_UART3_RX_o_gpio_b_in_23                0U
#define FM_UART3_RX_o_uart3_rx_in                 1U
#define FM_UART3_RX_i_cs_trace_data_0             2U
#define FM_UART3_RX_o_eqos_aux_ts_trig2_in        3U

#define PAD_UART3_TX                              62U
#define FM_UART3_TX_i_gpio_b_out_24               0U
#define FM_UART3_TX_o_gpio_b_in_24                0U
#define FM_UART3_TX_i_uart3_tx_out                1U
#define FM_UART3_TX_i_cs_trace_data_1             2U
#define FM_UART3_TX_o_eqos_aux_ts_trig3_in        3U

#define PAD_QSPI_SCK                              63U
#define FM_QSPI_SCK_i_qspi_sck_out                0U
#define FM_QSPI_SCK_i_spi_1_sck_out               2U
#define FM_QSPI_SCK_o_spi_1_sck_in                2U
#define FM_QSPI_SCK_i_spi_0_sck_out               3U
#define FM_QSPI_SCK_o_spi_0_sck_in                3U
#define FM_QSPI_SCK_i_gpio_b_out_25               5U
#define FM_QSPI_SCK_o_gpio_b_in_25                5U

#define PAD_QSPI_CSN                              64U
#define FM_QSPI_CSN_i_qspi_csn_out                0U
#define FM_QSPI_CSN_i_spi_1_ssn_out               2U
#define FM_QSPI_CSN_o_spi_1_ssn_in                2U
#define FM_QSPI_CSN_i_spi_0_ssn_out               3U
#define FM_QSPI_CSN_o_spi_0_ssn_in                3U
#define FM_QSPI_CSN_i_gpio_b_out_26               5U
#define FM_QSPI_CSN_o_gpio_b_in_26                5U

#define PAD_QSPI_DQ0                              65U
#define FM_QSPI_DQ0_i_qspi_dq0_out                0U
#define FM_QSPI_DQ0_o_qspi_dq0_in                 0U
#define FM_QSPI_DQ0_i_spi_1_mosi_out              2U
#define FM_QSPI_DQ0_o_spi_1_mosi_in               2U
#define FM_QSPI_DQ0_i_spi_0_mosi_out              3U
#define FM_QSPI_DQ0_o_spi_0_mosi_in               3U
#define FM_QSPI_DQ0_i_gpio_b_out_27               5U
#define FM_QSPI_DQ0_o_gpio_b_in_27                5U

#define PAD_QSPI_DQ1                              66U
#define FM_QSPI_DQ1_i_qspi_dq1_out                0U
#define FM_QSPI_DQ1_o_qspi_dq1_in                 0U
#define FM_QSPI_DQ1_i_spi_1_miso_out              2U
#define FM_QSPI_DQ1_o_spi_1_miso_in               2U
#define FM_QSPI_DQ1_i_spi_0_miso_out              3U
#define FM_QSPI_DQ1_o_spi_0_miso_in               3U
#define FM_QSPI_DQ1_i_gpio_b_out_28               5U
#define FM_QSPI_DQ1_o_gpio_b_in_28                5U

#define PAD_QSPI_DQ2                              67U
#define FM_QSPI_DQ2_i_qspi_dq2_out                0U
#define FM_QSPI_DQ2_o_qspi_dq2_in                 0U
#define FM_QSPI_DQ2_i_spi_1_sck_out               3U
#define FM_QSPI_DQ2_o_spi_1_sck_in                3U
#define FM_QSPI_DQ2_o_uart2_rx_in                 4U
#define FM_QSPI_DQ2_i_gpio_b_out_29               5U
#define FM_QSPI_DQ2_o_gpio_b_in_29                5U

#define PAD_QSPI_DQ3                              68U
#define FM_QSPI_DQ3_i_qspi_dq3_out                0U
#define FM_QSPI_DQ3_o_qspi_dq3_in                 0U
#define FM_QSPI_DQ3_i_spi_1_ssn_out               3U
#define FM_QSPI_DQ3_o_spi_1_ssn_in                3U
#define FM_QSPI_DQ3_i_uart2_tx_out                4U
#define FM_QSPI_DQ3_i_gpio_b_out_30               5U
#define FM_QSPI_DQ3_o_gpio_b_in_30                5U

#define PAD_SD_VOL_SEL                            69U
#define FM_SD_VOL_SEL_i_sd_vol_sel                0U
#define FM_SD_VOL_SEL_o_uart3_rx_in               2U
#define FM_SD_VOL_SEL_i_spi_1_mosi_out            3U
#define FM_SD_VOL_SEL_o_spi_1_mosi_in             3U
#define FM_SD_VOL_SEL_i_gpio_b_out_31             5U
#define FM_SD_VOL_SEL_o_gpio_b_in_31              5U

#define PAD_EMMC_VOL_SEL                          70U
#define FM_EMMC_VOL_SEL_i_emmc_vol_sel            0U
#define FM_EMMC_VOL_SEL_i_uart3_tx_out            2U
#define FM_EMMC_VOL_SEL_i_spi_1_miso_out          3U
#define FM_EMMC_VOL_SEL_o_spi_1_miso_in           3U
#define FM_EMMC_VOL_SEL_i_gpio_c_out_0            5U
#define FM_EMMC_VOL_SEL_o_gpio_c_in_0             5U

#define PAD_SD_CLK                                71U
#define FM_SD_CLK_i_gpio_c_out_1                  0U
#define FM_SD_CLK_o_gpio_c_in_1                   0U
#define FM_SD_CLK_i_sd_clk_out                    1U
#define FM_SD_CLK_i__parallel__data_0             7U

#define PAD_SD_CMD                                72U
#define FM_SD_CMD_i_gpio_c_out_2                  0U
#define FM_SD_CMD_o_gpio_c_in_2                   0U
#define FM_SD_CMD_i_sd_cmd_out                    1U
#define FM_SD_CMD_o_sd_cmd_in                     1U
#define FM_SD_CMD_o_isp0_ext_sync                 3U
#define FM_SD_CMD_o_isp1_ext_sync                 4U
#define FM_SD_CMD_i__parallel__data_1             7U

#define PAD_SD_DQ0                                73U
#define FM_SD_DQ0_i_gpio_c_out_3                  0U
#define FM_SD_DQ0_o_gpio_c_in_3                   0U
#define FM_SD_DQ0_i_sd_dq0_out                    1U
#define FM_SD_DQ0_o_sd_dq0_in                     1U
#define FM_SD_DQ0_i_isp0_hd_slave                 3U
#define FM_SD_DQ0_i_isp1_hd_slave                 4U
#define FM_SD_DQ0_i__parallel__data_2             7U

#define PAD_SD_DQ1                                74U
#define FM_SD_DQ1_i_gpio_c_out_4                  0U
#define FM_SD_DQ1_o_gpio_c_in_4                   0U
#define FM_SD_DQ1_i_sd_dq1_out                    1U
#define FM_SD_DQ1_o_sd_dq1_in                     1U
#define FM_SD_DQ1_i_isp0_vd_slave                 3U
#define FM_SD_DQ1_i_isp1_vd_slave                 4U
#define FM_SD_DQ1_i__parallel__data_3             7U

#define PAD_SD_DQ2                                75U
#define FM_SD_DQ2_i_gpio_c_out_5                  0U
#define FM_SD_DQ2_o_gpio_c_in_5                   0U
#define FM_SD_DQ2_i_sd_dq2_out                    1U
#define FM_SD_DQ2_o_sd_dq2_in                     1U
#define FM_SD_DQ2_i__parallel__data_4             7U

#define PAD_SD_DQ3                                76U
#define FM_SD_DQ3_i_gpio_c_out_6                  0U
#define FM_SD_DQ3_o_gpio_c_in_6                   0U
#define FM_SD_DQ3_i_sd_dq3_out                    1U
#define FM_SD_DQ3_o_sd_dq3_in                     1U
#define FM_SD_DQ3_i__parallel__data_5             7U

#define PAD_SD_DETECT_N                           77U
#define FM_SD_DETECT_N_i_gpio_c_out_7             0U
#define FM_SD_DETECT_N_o_gpio_c_in_7              0U
#define FM_SD_DETECT_N_o_sd_detect_n_in           1U
#define FM_SD_DETECT_N_i_isp0_tp_vsync            3U
#define FM_SD_DETECT_N_i_isp1_tp_vsync            4U
#define FM_SD_DETECT_N_i__parallel__data_6        7U

#define PAD_SD_WRITE_PROT                         78U
#define FM_SD_WRITE_PROT_i_gpio_c_out_8           0U
#define FM_SD_WRITE_PROT_o_gpio_c_in_8            0U
#define FM_SD_WRITE_PROT_o_sd_write_prot_in       1U
#define FM_SD_WRITE_PROT_i_isp0_tp_hsync          3U
#define FM_SD_WRITE_PROT_i_isp1_tp_hsync          4U
#define FM_SD_WRITE_PROT_i__parallel__data_7      7U

#define PAD_EMMC_CLK                              79U
#define FM_EMMC_CLK_i_emmc_clk_out                0U
#define FM_EMMC_CLK_i_gpio_c_out_9                5U
#define FM_EMMC_CLK_o_gpio_c_in_9                 5U
#define FM_EMMC_CLK_i__parallel__vact_out         6U

#define PAD_EMMC_RSTN                             80U
#define FM_EMMC_RSTN_i_emmc_rstn_out              0U
#define FM_EMMC_RSTN_i_gpio_c_out_10              5U
#define FM_EMMC_RSTN_o_gpio_c_in_10               5U
#define FM_EMMC_RSTN_i__parallel__data_10         6U
#define FM_EMMC_RSTN_i__parallel__data_14         7U

#define PAD_EMMC_CMD                              81U
#define FM_EMMC_CMD_i_emmc_cmd_out                0U
#define FM_EMMC_CMD_o_emmc_cmd_in                 0U
#define FM_EMMC_CMD_i_gpio_c_out_11               5U
#define FM_EMMC_CMD_o_gpio_c_in_11                5U
#define FM_EMMC_CMD_i__parallel__data_11          6U
#define FM_EMMC_CMD_i__parallel__data_15          7U

#define PAD_EMMC_DQ0                              82U
#define FM_EMMC_DQ0_i_emmc_dq0_out                0U
#define FM_EMMC_DQ0_o_emmc_dq0_in                 0U
#define FM_EMMC_DQ0_i_gpio_c_out_12               5U
#define FM_EMMC_DQ0_o_gpio_c_in_12                5U
#define FM_EMMC_DQ0_i__parallel__data_12          6U
#define FM_EMMC_DQ0_i__parallel__data_16          7U

#define PAD_EMMC_DQ1                              83U
#define FM_EMMC_DQ1_i_emmc_dq1_out                0U
#define FM_EMMC_DQ1_o_emmc_dq1_in                 0U
#define FM_EMMC_DQ1_i_gpio_c_out_13               5U
#define FM_EMMC_DQ1_o_gpio_c_in_13                5U
#define FM_EMMC_DQ1_i__parallel__data_13          6U
#define FM_EMMC_DQ1_i__parallel__data_17          7U

#define PAD_EMMC_DQ2                              84U
#define FM_EMMC_DQ2_i_emmc_dq2_out                0U
#define FM_EMMC_DQ2_o_emmc_dq2_in                 0U
#define FM_EMMC_DQ2_i_gpio_c_out_14               5U
#define FM_EMMC_DQ2_o_gpio_c_in_14                5U
#define FM_EMMC_DQ2_i__parallel__data_14          6U
#define FM_EMMC_DQ2_i__parallel__data_18          7U

#define PAD_EMMC_DQ3                              85U
#define FM_EMMC_DQ3_i_emmc_dq3_out                0U
#define FM_EMMC_DQ3_o_emmc_dq3_in                 0U
#define FM_EMMC_DQ3_i_gpio_c_out_15               5U
#define FM_EMMC_DQ3_o_gpio_c_in_15                5U
#define FM_EMMC_DQ3_i__parallel__data_15          6U
#define FM_EMMC_DQ3_i__parallel__data_19          7U

#define PAD_EMMC_DQ4                              86U
#define FM_EMMC_DQ4_i_emmc_dq4_out                0U
#define FM_EMMC_DQ4_o_emmc_dq4_in                 0U
#define FM_EMMC_DQ4_i_gpio_c_out_16               5U
#define FM_EMMC_DQ4_o_gpio_c_in_16                5U
#define FM_EMMC_DQ4_i__parallel__data_16          6U
#define FM_EMMC_DQ4_i__parallel__data_20          7U

#define PAD_EMMC_DQ5                              87U
#define FM_EMMC_DQ5_i_emmc_dq5_out                0U
#define FM_EMMC_DQ5_o_emmc_dq5_in                 0U
#define FM_EMMC_DQ5_i_gpio_c_out_17               5U
#define FM_EMMC_DQ5_o_gpio_c_in_17                5U
#define FM_EMMC_DQ5_i__parallel__data_17          6U
#define FM_EMMC_DQ5_i__parallel__data_21          7U

#define PAD_EMMC_DQ6                              88U
#define FM_EMMC_DQ6_i_emmc_dq6_out                0U
#define FM_EMMC_DQ6_o_emmc_dq6_in                 0U
#define FM_EMMC_DQ6_i_gpio_c_out_18               5U
#define FM_EMMC_DQ6_o_gpio_c_in_18                5U
#define FM_EMMC_DQ6_i__parallel__data_18          6U
#define FM_EMMC_DQ6_i__parallel__data_22          7U

#define PAD_EMMC_DQ7                              89U
#define FM_EMMC_DQ7_i_emmc_dq7_out                0U
#define FM_EMMC_DQ7_o_emmc_dq7_in                 0U
#define FM_EMMC_DQ7_i_gpio_c_out_19               5U
#define FM_EMMC_DQ7_o_gpio_c_in_19                5U
#define FM_EMMC_DQ7_i__parallel__data_19          6U
#define FM_EMMC_DQ7_i__parallel__data_23          7U

#define PAD_EQOS_TXCLK                            90U
#define FM_EQOS_TXCLK_i_gpio_c_out_20             0U
#define FM_EQOS_TXCLK_o_gpio_c_in_20              0U
#define FM_EQOS_TXCLK_i_eqos_txclk_out            1U
#define FM_EQOS_TXCLK_i__parallel__clkout         6U

#define PAD_EQOS_RXCLK                            91U
#define FM_EQOS_RXCLK_i_gpio_c_out_21             0U
#define FM_EQOS_RXCLK_o_gpio_c_in_21              0U
#define FM_EQOS_RXCLK_o_eqos_rxclk_in             1U
#define FM_EQOS_RXCLK_i__parallel__hsync_out      6U

#define PAD_EQOS_RMII_CLK                         92U
#define FM_EQOS_RMII_CLK_i_gpio_c_out_22          0U
#define FM_EQOS_RMII_CLK_o_gpio_c_in_22           0U
#define FM_EQOS_RMII_CLK_i_eqos_rmii_clk_out      1U
#define FM_EQOS_RMII_CLK_o_eqos_rmii_clk_in       1U

#define PAD_EQOS_MDC                              93U
#define FM_EQOS_MDC_i_gpio_c_out_23               0U
#define FM_EQOS_MDC_o_gpio_c_in_23                0U
#define FM_EQOS_MDC_i_eqos_mdc_out                1U
#define FM_EQOS_MDC_i__parallel__hact_out         6U

#define PAD_EQOS_MDIO                             94U
#define FM_EQOS_MDIO_i_gpio_c_out_24              0U
#define FM_EQOS_MDIO_o_gpio_c_in_24               0U
#define FM_EQOS_MDIO_i_eqos_mdio_out              1U
#define FM_EQOS_MDIO_o_eqos_mdio_in               1U
#define FM_EQOS_MDIO_i__parallel__vsync_out       6U

#define PAD_EQOS_TXEN                             95U
#define FM_EQOS_TXEN_i_gpio_c_out_25              0U
#define FM_EQOS_TXEN_o_gpio_c_in_25               0U
#define FM_EQOS_TXEN_i_eqos_txen_out              1U
#define FM_EQOS_TXEN_i__parallel__data_0          6U

#define PAD_EQOS_TXD0                             96U
#define FM_EQOS_TXD0_i_gpio_c_out_26              0U
#define FM_EQOS_TXD0_o_gpio_c_in_26               0U
#define FM_EQOS_TXD0_i_eqos_txd0_out              1U
#define FM_EQOS_TXD0_i__parallel__data_1          6U

#define PAD_EQOS_TXD1                             97U
#define FM_EQOS_TXD1_i_gpio_c_out_27              0U
#define FM_EQOS_TXD1_o_gpio_c_in_27               0U
#define FM_EQOS_TXD1_i_eqos_txd1_out              1U
#define FM_EQOS_TXD1_i__parallel__data_2          6U

#define PAD_EQOS_TXD2                             98U
#define FM_EQOS_TXD2_i_gpio_c_out_28              0U
#define FM_EQOS_TXD2_o_gpio_c_in_28               0U
#define FM_EQOS_TXD2_i_eqos_txd2_out              1U
#define FM_EQOS_TXD2_i__parallel__data_3          6U

#define PAD_EQOS_TXD3                             99U
#define FM_EQOS_TXD3_i_gpio_c_out_29              0U
#define FM_EQOS_TXD3_o_gpio_c_in_29               0U
#define FM_EQOS_TXD3_i_eqos_txd3_out              1U
#define FM_EQOS_TXD3_i__parallel__data_4          6U

#define PAD_EQOS_RXDV                             100U
#define FM_EQOS_RXDV_i_gpio_c_out_30              0U
#define FM_EQOS_RXDV_o_gpio_c_in_30               0U
#define FM_EQOS_RXDV_o_eqos_rxdv_in               1U
#define FM_EQOS_RXDV_i__parallel__data_5          6U

#define PAD_EQOS_RXD0                             101U
#define FM_EQOS_RXD0_i_gpio_c_out_31              0U
#define FM_EQOS_RXD0_o_gpio_c_in_31               0U
#define FM_EQOS_RXD0_o_eqos_rxd0_in               1U
#define FM_EQOS_RXD0_i__parallel__data_6          6U

#define PAD_EQOS_RXD1                             102U
#define FM_EQOS_RXD1_i_gpio_d_out_0               0U
#define FM_EQOS_RXD1_o_gpio_d_in_0                0U
#define FM_EQOS_RXD1_o_eqos_rxd1_in               1U
#define FM_EQOS_RXD1_i__parallel__data_7          6U

#define PAD_EQOS_RXD2                             103U
#define FM_EQOS_RXD2_i_gpio_d_out_1               0U
#define FM_EQOS_RXD2_o_gpio_d_in_1                0U
#define FM_EQOS_RXD2_o_eqos_rxd2_in               1U
#define FM_EQOS_RXD2_i__parallel__data_8          6U

#define PAD_EQOS_RXD3                             104U
#define FM_EQOS_RXD3_i_gpio_d_out_2               0U
#define FM_EQOS_RXD3_o_gpio_d_in_2                0U
#define FM_EQOS_RXD3_o_eqos_rxd3_in               1U
#define FM_EQOS_RXD3_i__parallel__data_9          6U

/* PRQA S 0791 -- */

/*
********************************************************************************
*               DECLARE BASEADDRESS
********************************************************************************
*/
extern volatile DRV_A6_ICU_REGISTER* const RegA6_ICU;

typedef struct
{
    UINT32      mBootDevice;
    UINT32      mCount;
    UINT32      mPAD_ID[14];
} tBOOT_PAD_INFO;


extern void  NC_ICU_SetPinMode(UINT32 Pad_ID, UINT32 Func);
extern void  NC_ICU_SetPinLevel(UINT32 Pad_ID, BOOL Level);
extern void  NC_ICU_SetDriveStrength(const tBOOT_PAD_INFO* ptPadInfo, UINT32 DriveStrength);
extern NC_ERROR NC_ICU_GetPadInfo(UINT32 BootDevice, tBOOT_PAD_INFO* ptPadInfo);
extern void  NC_ICU_Initialize(const tBOOT_INFO *ptBootInfo,  tBOOT_STATUS *ptBootStatus);

#endif /* end of  DRV_ICU_H__ */

