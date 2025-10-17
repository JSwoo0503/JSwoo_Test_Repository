/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Enviroment : APACHE6 BSP
*   File       : Drv_ICU.c (SIM_EVT0)
*   Date       : 2020-06-08 17:46
*
*   THIS CODE IS GENERATED FROM APACHE6 HSI Document. DO NOT EDIT.
********************************************************************************/

#include "SOC_RTL.h"
#include "Drv_A6_CPU_SCU_Register.h"
#if defined(SIM_ONLY_)

void NC_SetPinMux(void)
{
#if 0 /* FIXME */
    /* Need pin muxing for Simulation ? */
#endif
}



#ifdef SIM_BL_NO_FLASH_
void NC_SIM_InitFastBoot(void)
{
#if 0 // test_code defined(BL1_)
    UINT32 i,j,efuse,strap;
#endif

    /*
     *-----------------------------------------------------------------------------------
     * by jjosuba, Only RTL simulation
     */

#if defined(BL1_)

    #if 0
        /*
         * if STRAP 3, Set PLL for MAX freq
         */

        /* Check STRAP */
        strap = REGRW32(0x08000000, 0x0080) & 0x3;
        if (strap == 0x3)
        {
            // OSC 27Mhz
            // PLL0 1398Mhz P = 9, M = 466, S = 0
            REGRW32(0x08000000, 0x0104) = (9 << 12) | (0 << 20) | (466 << 0) ; // PMS
            // PLL1 1200Mhz P = 9, M = 800, S = 1
            REGRW32(0x08000000, 0x0114) = (9 << 12) | (1 << 20) | (800 << 0) ; // PMS
            // PLL2 1485Mhz P = 9, M = 495, S = 0
            // PLL3 1593Mhz P = 9, M = 531, S = 0
            // Restart
            REGRW32(0x08000000, 0x0140) = (0x0 << 8) | (0x1 << 4) | (0x1 << 0) ; // PLL2, PLL1, PLL0
            // PLL SEL
            REGRW32(0x08000000, 0x0314)  = 0x00033333 ; // SYS_CLK_MUX_SEL2
            REGRW32(0x08020000, 0x0300)  = 0x00000000 ; // ARM_CLK_ROOT_MUX_SEL
            REGRW32(0x08000000, 0x0400) &= 0x00FFFFFF ; // SYS_CLK_DIV_VAL1 CLKDIV_VAL_SYS_G0_AXI RAM ECC ON
            REGRW32(0x08000000, 0x0400) |= 0x04000000 ; // SYS_CLK_DIV_VAL1 CLKDIV_VAL_SYS_G0_AXI RAM ECC ON
            #if 0
                REGRW32(0x08000000, 0x040C) &= 0x00FFFFFF ; // SYS_CLK_DIV_VAL4 CLKDIV_VAL_RAM_AXI
                REGRW32(0x08000000, 0x040C) |= 0x08000000 ; // SYS_CLK_DIV_VAL4 CLKDIV_VAL_RAM_AXI
            #else
                REGRW32(0x08000000, 0x040C) &= 0x00FFFFFF ; // SYS_CLK_DIV_VAL4 CLKDIV_VAL_RAM_AXI
                REGRW32(0x08000000, 0x040C) |= 0x04000000 ; // SYS_CLK_DIV_VAL4 CLKDIV_VAL_RAM_AXI
            #endif
        }
    #endif

    #if 0
        /* Read eFuse Value */
        for(i=0;i<3;i++)
        {
            for(j=0;j<8;j++)
            {
                efuse = REGRW32(0x09004060 + 0x1000*i, j*4) ;
                REGRW32(0x08000000, 0x201C) = efuse ;
            }
        }
        for(i=0;i<3;i++)
        {
            REGRW32(0x09004000 + 0x1000 * i, 0x10) = 0x02 ; // SCAN
            efuse = REGRW32(0x09004000 + 0x1000 * i, 0x14) ; // DONE
            REGRW32(0x09004000 + 0x1000 * i, 0x00) = 0x11 ; // CS, EN
            while (!REGRW32(0x09004000 + 0x1000 * i, 0x14));
            REGRW32(0x09004000 + 0x1000 * i, 0x10) = 0x00 ; // SCAN
            REGRW32(0x09004000 + 0x1000 * i, 0x00) = 0x00 ; // CS, EN
        }
    #endif
#endif
}
#endif


void NC_SIM_InitPort(void)
{
    /*
     *-----------------------------------------------------------------------------------
     * by jjosuba, Only RTL simulation
     * -. SPI Port Init
     */
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_CSN           << 16 ) | PD_MODEL_SFLASH_CSN   ) ; // SPI2_CSN0, NOR_FLASH_CSN0
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_CSN   << 16 ) | PD_QSPI_CSN           ) ;

    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_DQ0           << 16 ) | PD_MODEL_SFLASH_DIO   ) ; // SPI2_DQ0, NOR_FLASH_DQ0
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_DIO   << 16 ) | PD_QSPI_DQ0           ) ; // SPI2_DQ0, NOR_FLASH_DQ0

    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_DQ1           << 16 ) | PD_MODEL_SFLASH_DO    ) ; // SPI2_DQ1, NOR_FLASH_DQ1
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_DO    << 16 ) |  PD_QSPI_DQ1          ) ; // SPI2_DQ1, NOR_FLASH_DQ1

    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_DQ2           << 16 ) | PD_MODEL_SFLASH_WPN   ) ; // SPI2_DQ2, NOR_FLASH_DQ2
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_WPN   << 16 ) |  PD_QSPI_DQ2          ) ; // SPI2_DQ2, NOR_FLASH_DQ2

    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_DQ3           << 16 ) | PD_MODEL_SFLASH_HOLDN ) ; // SPI2_DQ3, NOR_FLASH_DQ3
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_HOLDN << 16 ) |  PD_QSPI_DQ3          ) ; // SPI2_DQ3, NOR_FLASH_DQ3

    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_QSPI_SCK           << 16 ) | PD_MODEL_SFLASH_CLK   ) ; // SPI2_SCK, NOR_FLASH_SCK
    REGRW32(APACHE_SCU_BASE, PAD_SET_ADR_BASE ) = ((PD_MODEL_SFLASH_CLK   << 16 ) |  PD_QSPI_SCK          ) ; // SPI2_SCK, NOR_FLASH_SCK
    /*---------------------------------------------------------------------------------*/

}

#endif // defined(SIM_ONLY_)
