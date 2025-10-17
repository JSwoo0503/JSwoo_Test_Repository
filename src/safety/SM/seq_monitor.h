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
*  note    :
*
********************************************************************************
*/

#ifndef SEQ_MONITOR_H_
#define SEQ_MONITOR_H_

/* PRQA S 0791 ++ */

/*
********************************************************************************
*               DEFINES
********************************************************************************
*/
/* Debug Steps for Bootloader */
/* Stage-1 : SCU */
#define DBG_STP_SCU_INIT_IN                             (0U)
#define DBG_STP_PLL_CONF_IN                             (1U)
#define DBG_STP_PLL_CONF_OUT                            (2U)
#define DBG_STP_SCU_INIT_OUT                            (3U)
#define DBG_STP_STRAP_CONF_IN                           (4U)
#define DBG_STP_STRAP_CONF_OUT                          (5U)
#define DBG_STP_OTP_CONF_IN                             (6U)
#define DBG_STP_OTP_CONF_OUT                            (7U)
#define DBG_STP_RESET_IP_IN                             (8U)
#define DBG_STP_RESET_IP_OUT                            (9U)

/* Stage-2 : ICU */
#define DBG_STP_PIN_MUX_IN                              (10U)
#define DBG_STP_PIN_MUX_OUT                             (11U)

/* Stage-3 : SE */
#define DBG_STP_SE_IN                                   (12U)
#define DBG_STP_SE_OUT                                  (13U)

/* Stage-4 : EMMC */
#define DBG_STP_EMMC_INIT_IN                            (14U)
#define DBG_STP_EMMC_INIT_OUT                           (15U)
#define DBG_STP_EMMC_IMG_LOAD_IN                        (16U)
#define DBG_STP_EMMC_IMG_LOAD_OUT                       (17U)
#define DBG_STP_EMMC_DEINIT_IN                          (18U)
#define DBG_STP_EMMC_DEINIT_OUT                         (19U)

/* Stage-5 : SD */
#define DBG_STP_SDCARD_INIT_IN                          (20U)
#define DBG_STP_SDCARD_INIT_OUT                         (21U)
#define DBG_STP_SDCARD_IMG_LOAD_IN                      (22U)
#define DBG_STP_SDCARD_IMG_LOAD_OUT                     (23U)
#define DBG_STP_SDCARD_DEINIT_IN                        (24U)
#define DBG_STP_SDCARD_DEINIT_OUT                       (25U)

/* Stage-6 : SF */
#define DBG_STP_SF_INIT_IN                              (26U)
#define DBG_STP_SF_CHECK_CLOCK_IN                       (27U)
#define DBG_STP_SF_CHECK_CLOCK_OUT                      (28U)
#define DBG_STP_SF_INIT_OUT                             (29U)
#define DBG_STP_SF_IMG_LOAD_IN                          (30U)
#define DBG_STP_SF_IMG_LOAD_OUT                         (31U)

/* Stage-7 : YMODEM */
#define DBG_STP_YMODEM_INIT_IN                          (32U)
#define DBG_STP_YMODEM_INIT_OUT                         (33U)
#define DBG_STP_YMODEM_IMG_LOAD_IN                      (34U)
#define DBG_STP_YMODEM_IMG_LOAD_OUT                     (35U)

/* Stage-8 : USB */
#define DBG_STP_USB_INIT_IN                             (36U)
#define DBG_STP_USB_INIT_OUT                            (37U)
#define DBG_STP_USB_IMG_LOAD_IN                         (38U)
#define DBG_STP_USB_IMG_LOAD_OUT                        (39U)

/* Stage=9 : BOOT Done */
#define DBG_STP_JUMP                                    (40U)
#define DBG_STP_BOOT_FAIL_WAIT                          (41U)

/* Stage-9 : Secure Boot */
#define DBG_STP_SECURE_INIT                             (0U)
#define DBG_STP_SECURE_BRINGUP_IN                       (1U)
#define DBG_STP_SECURE_BRINGUP_STAGE_1                  (2U)
#define DBG_STP_SECURE_BRINGUP_STAGE_2                  (3U)
#define DBG_STP_SECURE_BRINGUP_OUT                      (4U)
#define DBG_STP_SECURE_RUN_IN                           (5U)
#define DBG_STP_SECURE_RUN_KEY_LOAD                     (6U)
#define DBG_STP_SECURE_RUN_DECRYPT_IN                   (7U)
#define DBG_STP_SECURE_RUN_DECRYPT_STAGE_1              (8U)
#define DBG_STP_SECURE_RUN_DECRYPT_STAGE_2              (9U)
#define DBG_STP_SECURE_RUN_DECRYPT_STAGE_3              (10U)
#define DBG_STP_SECURE_RUN_DECRYPT_STAGE_4              (11U)
#define DBG_STP_SECURE_RUN_DECRYPT_STAGE_5              (12U)
#define DBG_STP_SECURE_RUN_DECRYPT_OUT                  (13U)
#define DBG_STP_SECURE_RUN_OUT                          (14U)

#define NS_STEP                                         (0U)
#define S_STEP                                          (1U)

#define SM_STAGE_4                                      (4U)
#define SM_STAGE_5                                      (5U)
#define SM_STAGE_6                                      (6U)
#define SM_STAGE_7                                      (7U)
#define SM_STAGE_8                                      (8U)
#define SM_STAGE_9                                      (9U)

#define CONFIG_IDX_1                                    (1U)
#define CONFIG_IDX_2                                    (2U)
/* PRQA S 0791 -- */

/*
********************************************************************************
*               FUNCTION DECLARATIONS
********************************************************************************
*/

extern void     NC_SM_Initialize(UINT32 Val);
extern void     NC_SM_SetBOOT_Step(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus);
extern void     NC_SM_SetBOOT_SecureStep(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus);
extern NC_ERROR NC_SM_CheckFlow(UINT32 StepInfo, tBOOT_STATUS *ptBootStatus, UINT32 SNS_STEP);
extern void     NC_SM_SetRETRY_Count(UINT32 InterfaceId);
extern void     NC_SM_SetBOOT_Result(NC_ERROR Ret, tBOOT_STATUS *ptBootStatus);

#endif  /* SEQ_MONITOR_H_ */

/* End Of File */
