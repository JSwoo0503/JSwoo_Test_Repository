
/********************************************************************************
*   Copyright (C) NEXTCHIP Co.,Ltd. All rights reserved.
********************************************************************************
*   Platform   : APACHE6
*   File       : DRV_A6_PMU_Register.h
*   Date       : 2022-10-14 09:24
* 
*   THIS CODE WAS GENERATED FROM THE APACHE6 HSI DOCUMENTATION. PLEASE DO NOT EDIT.
********************************************************************************/

#ifndef DRV_REGISTER_A6_PMU_H__
#define DRV_REGISTER_A6_PMU_H__

#define APACHE_A6_PMU_BASE_ADDR        0x05020000

/* PRQA S 828 ++ */
typedef struct
{
    union { /* 0x0000 [Excel Line :0008]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_DATE                                                                                         : 32;     /* [ 31:0] Indicates the DATE when this register set was generated
                                                                                                                                             3116 is Year 158 is Month 70 is Day */
        }Bit;
    }SFR_GEN_DATE;
    union { /* 0x0004 [Excel Line :0009]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_TIME                                                                                         : 32;     /* [ 31:0] Indicates the TIME when this register set was generated
                                                                                                                                             2316 is Hour 158 is Minute 70 is Second */
        }Bit;
    }SFR_GEN_TIME;
    union { /* 0x0008 [Excel Line :0010]  */
        UINT32 Reg;
        struct {
            UINT32 SFR_GEN_CHKSUM                                                                                       : 32;     /* [ 31:0] Indicates the CHECKSUM of its reg_config file */
        }Bit;
    }SFR_GEN_CHKSUM;

    UINT8 EMPTY1[260]; /* 0x104 */

    union { /* 0x0110 [Excel Line :0011]  */
        UINT32 Reg;
        struct {
            UINT32 OIC_PACCEPT                                                                                          : 1;      /* [    0] PACCEPT from OIC */
            UINT32 OIC_PDENY                                                                                            : 1;      /* [    1] PDENY from OIC */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 OIC_PACTIVE                                                                                          : 9;      /* [ 16:8] PACTIVE from OIC */
            UINT32 RESERVED1                                                                                            : 15;     /* [31:17]  */
        }Bit;
    }PCH_OIC_IN;
    union { /* 0x0114 [Excel Line :0016]  */
        UINT32 Reg;
        struct {
            UINT32 OIC_PREQ                                                                                             : 1;      /* [    0] PREQ to OIC */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 OIC_PSTATE                                                                                           : 5;      /* [ 12:8] PSTATE to OIC */
            UINT32 RESERVED1                                                                                            : 19;     /* [31:13]  */
        }Bit;
    }PCH_OIC_OUT;

    UINT8 EMPTY2[8]; /* 0x8 */

    union { /* 0x0120 [Excel Line :0020]  */
        UINT32 Reg;
        struct {
            UINT32 OMC0_PACCEPT                                                                                         : 1;      /* [    0] PACCEPT from OMC0 */
            UINT32 OMC0_PDENY                                                                                           : 1;      /* [    1] PDENY from OMC0 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 OMC0_PACTIVE                                                                                         : 1;      /* [    8] PACTIVE from OMC0 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }PCH_OMC0_IN;
    union { /* 0x0124 [Excel Line :0025]  */
        UINT32 Reg;
        struct {
            UINT32 OMC0_PREQ                                                                                            : 1;      /* [    0] PREQ to OMC0 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 OMC0_PSTATE                                                                                          : 3;      /* [ 10:8] PSTATE to OMC0 */
            UINT32 RESERVED1                                                                                            : 21;     /* [31:11]  */
        }Bit;
    }PCH_OMC0_OUT;

    UINT8 EMPTY3[8]; /* 0x8 */

    union { /* 0x0130 [Excel Line :0029]  */
        UINT32 Reg;
        struct {
            UINT32 OMC1_PACCEPT                                                                                         : 1;      /* [    0] PACCEPT from OMC1 */
            UINT32 OMC1_PDENY                                                                                           : 1;      /* [    1] PDENY from OMC1 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 OMC1_PACTIVE                                                                                         : 1;      /* [    8] PACTIVE from OMC1 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }PCH_OMC1_IN;
    union { /* 0x0134 [Excel Line :0034]  */
        UINT32 Reg;
        struct {
            UINT32 OMC1_PREQ                                                                                            : 1;      /* [    0] PREQ to OMC1 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 OMC1_PSTATE                                                                                          : 3;      /* [ 10:8] PSTATE to OMC1 */
            UINT32 RESERVED1                                                                                            : 21;     /* [31:11]  */
        }Bit;
    }PCH_OMC1_OUT;

    UINT8 EMPTY4[8]; /* 0x8 */

    union { /* 0x0140 [Excel Line :0038]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE0_PACCEPT                                                                                    : 1;      /* [    0] PACCEPT from A65_CORE0 */
            UINT32 A65_CORE0_PDENY                                                                                      : 1;      /* [    1] PDENY from A65_CORE0 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 A65_CORE0_PACTIVE                                                                                    : 18;     /* [ 25:8] PACTIVE from A65_CORE0 */
            UINT32 RESERVED1                                                                                            : 6;      /* [31:26]  */
        }Bit;
    }PCH_A65_CORE0_IN;
    union { /* 0x0144 [Excel Line :0043]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE0_PREQ                                                                                       : 1;      /* [    0] PREQ to A65_CORE0 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 A65_CORE0_PSTATE                                                                                     : 6;      /* [ 13:8] PSTATE to A65_CORE0 */
            UINT32 RESERVED1                                                                                            : 18;     /* [31:14]  */
        }Bit;
    }PCH_A65_CORE0_OUT;
    union { /* 0x0148 [Excel Line :0047]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE1_PACCEPT                                                                                    : 1;      /* [    0] PACCEPT from A65_CORE1 */
            UINT32 A65_CORE1_PDENY                                                                                      : 1;      /* [    1] PDENY from A65_CORE1 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 A65_CORE1_PACTIVE                                                                                    : 18;     /* [ 25:8] PACTIVE from A65_CORE1 */
            UINT32 RESERVED1                                                                                            : 6;      /* [31:26]  */
        }Bit;
    }PCH_A65_CORE1_IN;
    union { /* 0x014c [Excel Line :0052]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE1_PREQ                                                                                       : 1;      /* [    0] PREQ to A65_CORE1 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 A65_CORE1_PSTATE                                                                                     : 6;      /* [ 13:8] PSTATE to A65_CORE1 */
            UINT32 RESERVED1                                                                                            : 18;     /* [31:14]  */
        }Bit;
    }PCH_A65_CORE1_OUT;
    union { /* 0x0150 [Excel Line :0056]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE2_PACCEPT                                                                                    : 1;      /* [    0] PACCEPT from A65_CORE2 */
            UINT32 A65_CORE2_PDENY                                                                                      : 1;      /* [    1] PDENY from A65_CORE2 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 A65_CORE2_PACTIVE                                                                                    : 18;     /* [ 25:8] PACTIVE from A65_CORE2 */
            UINT32 RESERVED1                                                                                            : 6;      /* [31:26]  */
        }Bit;
    }PCH_A65_CORE2_IN;
    union { /* 0x0154 [Excel Line :0061]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE2_PREQ                                                                                       : 1;      /* [    0] PREQ to A65_CORE2 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 A65_CORE2_PSTATE                                                                                     : 6;      /* [ 13:8] PSTATE to A65_CORE2 */
            UINT32 RESERVED1                                                                                            : 18;     /* [31:14]  */
        }Bit;
    }PCH_A65_CORE2_OUT;
    union { /* 0x0158 [Excel Line :0065]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE3_PACCEPT                                                                                    : 1;      /* [    0] PACCEPT from A65_CORE3 */
            UINT32 A65_CORE3_PDENY                                                                                      : 1;      /* [    1] PDENY from A65_CORE3 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 A65_CORE3_PACTIVE                                                                                    : 18;     /* [ 25:8] PACTIVE from A65_CORE3 */
            UINT32 RESERVED1                                                                                            : 6;      /* [31:26]  */
        }Bit;
    }PCH_A65_CORE3_IN;
    union { /* 0x015c [Excel Line :0070]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE3_PREQ                                                                                       : 1;      /* [    0] PREQ to A65_CORE3 */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 A65_CORE3_PSTATE                                                                                     : 6;      /* [ 13:8] PSTATE to A65_CORE3 */
            UINT32 RESERVED1                                                                                            : 18;     /* [31:14]  */
        }Bit;
    }PCH_A65_CORE3_OUT;
    union { /* 0x0160 [Excel Line :0074]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CLUSTER_PACCEPT                                                                                  : 1;      /* [    0] PACCEPT from A65_CLUSTER */
            UINT32 A65_CLUSTER_PDENY                                                                                    : 1;      /* [    1] PDENY from A65_CLUSTER */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 A65_CLUSTER_PACTIVE                                                                                  : 20;     /* [ 27:8] PACTIVE from A65_CLUSTER */
            UINT32 RESERVED1                                                                                            : 4;      /* [31:28]  */
        }Bit;
    }PCH_A65_CLUSTER_IN;
    union { /* 0x0164 [Excel Line :0079]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CLUSTER_PREQ                                                                                     : 1;      /* [    0] PREQ to A65_CLUSTER */
            UINT32 RESERVED2                                                                                            : 7;      /* [  7:1]  */
            UINT32 A65_CLUSTER_PSTATE                                                                                   : 7;      /* [ 14:8] PSTATE to A65_CLUSTER */
            UINT32 RESERVED1                                                                                            : 17;     /* [31:15]  */
        }Bit;
    }PCH_A65_CLUSTER_OUT;

    UINT8 EMPTY5[152]; /* 0x98 */

    union { /* 0x0200 [Excel Line :0083]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCLK_DOM_QACCEPT                                                                                 : 1;      /* [    0] QACCEPT from CPU_SCLK_DOM */
            UINT32 CPU_SCLK_DOM_QDENY                                                                                   : 1;      /* [    1] QDENY from CPU_SCLK_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_SCLK_DOM_QACTIVE                                                                                 : 1;      /* [    8] QACTIVE from CPU_SCLK_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_SCLK_DOM_IN;
    union { /* 0x0204 [Excel Line :0088]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCLK_DOM_QREQ                                                                                    : 1;      /* [    0] QREQ to CPU_SCLK_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_SCLK_DOM_OUT;
    union { /* 0x0208 [Excel Line :0090]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PCLK_DOM_QACCEPT                                                                                 : 1;      /* [    0] QACCEPT from CPU_PCLK_DOM */
            UINT32 CPU_PCLK_DOM_QDENY                                                                                   : 1;      /* [    1] QDENY from CPU_PCLK_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_PCLK_DOM_QACTIVE                                                                                 : 1;      /* [    8] QACTIVE from CPU_PCLK_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_PCLK_DOM_IN;
    union { /* 0x020c [Excel Line :0095]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PCLK_DOM_QREQ                                                                                    : 1;      /* [    0] QREQ to CPU_PCLK_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_PCLK_DOM_OUT;
    union { /* 0x0210 [Excel Line :0097]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_ATCLK_DOM_QACCEPT                                                                                : 1;      /* [    0] QACCEPT from CPU_ATCLK_DOM */
            UINT32 CPU_ATCLK_DOM_QDENY                                                                                  : 1;      /* [    1] QDENY from CPU_ATCLK_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_ATCLK_DOM_QACTIVE                                                                                : 1;      /* [    8] QACTIVE from CPU_ATCLK_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_ATCLK_DOM_IN;
    union { /* 0x0214 [Excel Line :0102]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_ATCLK_DOM_QREQ                                                                                   : 1;      /* [    0] QREQ to CPU_ATCLK_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_ATCLK_DOM_OUT;
    union { /* 0x0218 [Excel Line :0104]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_GICCLK_DOM_QACCEPT                                                                               : 1;      /* [    0] QACCEPT from CPU_GICCLK_DOM */
            UINT32 CPU_GICCLK_DOM_QDENY                                                                                 : 1;      /* [    1] QDENY from CPU_GICCLK_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_GICCLK_DOM_QACTIVE                                                                               : 1;      /* [    8] QACTIVE from CPU_GICCLK_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_GICCLK_DOM_IN;
    union { /* 0x021c [Excel Line :0109]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_GICCLK_DOM_QREQ                                                                                  : 1;      /* [    0] QREQ to CPU_GICCLK_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_GICCLK_DOM_OUT;

    UINT8 EMPTY6[8]; /* 0x8 */

    union { /* 0x0228 [Excel Line :0111]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PDBGCLK_DOM_QACCEPT                                                                              : 1;      /* [    0] QACCEPT from CPU_PDBGCLK_DOM */
            UINT32 CPU_PDBGCLK_DOM_QDENY                                                                                : 1;      /* [    1] QDENY from CPU_PDBGCLK_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_PDBGCLK_DOM_QACTIVE                                                                              : 1;      /* [    8] QACTIVE from CPU_PDBGCLK_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_PDBGCLK_DOM_IN;
    union { /* 0x022c [Excel Line :0116]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_PDBGCLK_DOM_QREQ                                                                                 : 1;      /* [    0] QREQ to CPU_PDBGCLK_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_PDBGCLK_DOM_OUT;
    union { /* 0x0230 [Excel Line :0118]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_DBGPWR_DOM_QACCEPT                                                                               : 1;      /* [    0] QACCEPT from CPU_DBGPWR_DOM */
            UINT32 CPU_DBGPWR_DOM_QDENY                                                                                 : 1;      /* [    1] QDENY from CPU_DBGPWR_DOM */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 CPU_DBGPWR_DOM_QACTIVE                                                                               : 1;      /* [    8] QACTIVE from CPU_DBGPWR_DOM */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_CPU_DBGPWR_DOM_IN;
    union { /* 0x0234 [Excel Line :0123]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_DBGPWR_DOM_QREQ                                                                                  : 1;      /* [    0] QREQ to CPU_DBGPWR_DOM */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_CPU_DBGPWR_DOM_OUT;

    UINT8 EMPTY7[8]; /* 0x8 */

    union { /* 0x0240 [Excel Line :0125]  */
        UINT32 Reg;
        struct {
            UINT32 GIC_CLK_QACCEPT                                                                                      : 1;      /* [    0] QACCEPT from GIC_CLK */
            UINT32 GIC_CLK_QDENY                                                                                        : 1;      /* [    1] QDENY from GIC_CLK */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GIC_CLK_QACTIVE                                                                                      : 1;      /* [    8] QACTIVE from GIC_CLK */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GIC_CLK_IN;
    union { /* 0x0244 [Excel Line :0130]  */
        UINT32 Reg;
        struct {
            UINT32 GIC_CLK_QREQ                                                                                         : 1;      /* [    0] QREQ to GIC_CLK */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GIC_CLK_OUT;

    UINT8 EMPTY8[8]; /* 0x8 */

    union { /* 0x0250 [Excel Line :0132]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_QACCEPT                                                                                          : 1;      /* [    0] QACCEPT from GPU */
            UINT32 GPU_QDENY                                                                                            : 1;      /* [    1] QDENY from GPU */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_QACTIVE                                                                                          : 1;      /* [    8] QACTIVE from GPU */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_IN;
    union { /* 0x0254 [Excel Line :0137]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_QREQ                                                                                             : 1;      /* [    0] QREQ to GPU */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_OUT;
    union { /* 0x0258 [Excel Line :0139]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU0_QACCEPT                                                                                : 1;      /* [    0] QACCEPT from GPU_SMMU_TBU0 */
            UINT32 GPU_SMMU_TBU0_QDENY                                                                                  : 1;      /* [    1] QDENY from GPU_SMMU_TBU0 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_TBU0_QACTIVE                                                                                : 1;      /* [    8] QACTIVE from GPU_SMMU_TBU0 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_TBU0_IN;
    union { /* 0x025c [Excel Line :0144]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU0_QREQ                                                                                   : 1;      /* [    0] QREQ to GPU_SMMU_TBU0 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_TBU0_OUT;
    union { /* 0x0260 [Excel Line :0146]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU1_QACCEPT                                                                                : 1;      /* [    0] QACCEPT from GPU_SMMU_TBU1 */
            UINT32 GPU_SMMU_TBU1_QDENY                                                                                  : 1;      /* [    1] QDENY from GPU_SMMU_TBU1 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_TBU1_QACTIVE                                                                                : 1;      /* [    8] QACTIVE from GPU_SMMU_TBU1 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_TBU1_IN;
    union { /* 0x0264 [Excel Line :0151]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU1_QREQ                                                                                   : 1;      /* [    0] QREQ to GPU_SMMU_TBU1 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_TBU1_OUT;
    union { /* 0x0268 [Excel Line :0153]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU2_QACCEPT                                                                                : 1;      /* [    0] QACCEPT from GPU_SMMU_TBU2 */
            UINT32 GPU_SMMU_TBU2_QDENY                                                                                  : 1;      /* [    1] QDENY from GPU_SMMU_TBU2 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_TBU2_QACTIVE                                                                                : 1;      /* [    8] QACTIVE from GPU_SMMU_TBU2 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_TBU2_IN;
    union { /* 0x026c [Excel Line :0158]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU2_QREQ                                                                                   : 1;      /* [    0] QREQ to GPU_SMMU_TBU2 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_TBU2_OUT;
    union { /* 0x0270 [Excel Line :0160]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU3_QACCEPT                                                                                : 1;      /* [    0] QACCEPT from GPU_SMMU_TBU3 */
            UINT32 GPU_SMMU_TBU3_QDENY                                                                                  : 1;      /* [    1] QDENY from GPU_SMMU_TBU3 */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_TBU3_QACTIVE                                                                                : 1;      /* [    8] QACTIVE from GPU_SMMU_TBU3 */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_TBU3_IN;
    union { /* 0x0274 [Excel Line :0165]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU3_QREQ                                                                                   : 1;      /* [    0] QREQ to GPU_SMMU_TBU3 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_TBU3_OUT;
    union { /* 0x0278 [Excel Line :0167]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TCU_QACCEPT                                                                                 : 1;      /* [    0] QACCEPT from GPU_SMMU_TCU */
            UINT32 GPU_SMMU_TCU_QDENY                                                                                   : 1;      /* [    1] QDENY from GPU_SMMU_TCU */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_TCU_QACTIVE                                                                                 : 1;      /* [    8] QACTIVE from GPU_SMMU_TCU */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_TCU_IN;
    union { /* 0x027c [Excel Line :0172]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TCU_QREQ                                                                                    : 1;      /* [    0] QREQ to GPU_SMMU_TCU */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_TCU_OUT;
    union { /* 0x0280 [Excel Line :0174]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QACCEPT                                                                        : 1;      /* [    0] QACCEPT from GPU_SMMU_LPD_CG_A_CLK */
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QDENY                                                                          : 1;      /* [    1] QDENY from GPU_SMMU_LPD_CG_A_CLK */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QACTIVE                                                                        : 1;      /* [    8] QACTIVE from GPU_SMMU_LPD_CG_A_CLK */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_A_CLK_IN;
    union { /* 0x0284 [Excel Line :0179]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QREQ                                                                           : 1;      /* [    0] QREQ to GPU_SMMU_LPD_CG_A_CLK */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_A_CLK_OUT;
    union { /* 0x0288 [Excel Line :0181]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QACCEPT                                                                        : 1;      /* [    0] QACCEPT from GPU_SMMU_LPD_CG_B_CLK */
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QDENY                                                                          : 1;      /* [    1] QDENY from GPU_SMMU_LPD_CG_B_CLK */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QACTIVE                                                                        : 1;      /* [    8] QACTIVE from GPU_SMMU_LPD_CG_B_CLK */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_B_CLK_IN;
    union { /* 0x028c [Excel Line :0186]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QREQ                                                                           : 1;      /* [    0] QREQ to GPU_SMMU_LPD_CG_B_CLK */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_B_CLK_OUT;
    union { /* 0x0290 [Excel Line :0188]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QACCEPT                                                                        : 1;      /* [    0] QACCEPT from GPU_SMMU_LPD_CG_C_CLK */
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QDENY                                                                          : 1;      /* [    1] QDENY from GPU_SMMU_LPD_CG_C_CLK */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QACTIVE                                                                        : 1;      /* [    8] QACTIVE from GPU_SMMU_LPD_CG_C_CLK */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_C_CLK_IN;
    union { /* 0x0294 [Excel Line :0193]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QREQ                                                                           : 1;      /* [    0] QREQ to GPU_SMMU_LPD_CG_C_CLK */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_CG_C_CLK_OUT;
    union { /* 0x0298 [Excel Line :0195]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QACCEPT                                                                        : 1;      /* [    0] QACCEPT from GPU_SMMU_LPD_PD_C_CLK */
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QDENY                                                                          : 1;      /* [    1] QDENY from GPU_SMMU_LPD_PD_C_CLK */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QACTIVE                                                                        : 1;      /* [    8] QACTIVE from GPU_SMMU_LPD_PD_C_CLK */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_PD_C_CLK_IN;
    union { /* 0x029c [Excel Line :0200]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QREQ                                                                           : 1;      /* [    0] QREQ to GPU_SMMU_LPD_PD_C_CLK */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_LPD_PD_C_CLK_OUT;
    union { /* 0x02a0 [Excel Line :0202]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QACCEPT                                                                      : 1;      /* [    0] QACCEPT from GPU_SMMU_ADB_TBU_AC_PWR */
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QDENY                                                                        : 1;      /* [    1] QDENY from GPU_SMMU_ADB_TBU_AC_PWR */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QACTIVE                                                                      : 1;      /* [    8] QACTIVE from GPU_SMMU_ADB_TBU_AC_PWR */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_ADB_TBU_AC_PWR_IN;
    union { /* 0x02a4 [Excel Line :0207]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QREQ                                                                         : 1;      /* [    0] QREQ to GPU_SMMU_ADB_TBU_AC_PWR */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_ADB_TBU_AC_PWR_OUT;
    union { /* 0x02a8 [Excel Line :0209]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QACCEPT                                                                      : 1;      /* [    0] QACCEPT from GPU_SMMU_ADB_TBU_BC_PWR */
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QDENY                                                                        : 1;      /* [    1] QDENY from GPU_SMMU_ADB_TBU_BC_PWR */
            UINT32 RESERVED2                                                                                            : 6;      /* [  7:2]  */
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QACTIVE                                                                      : 1;      /* [    8] QACTIVE from GPU_SMMU_ADB_TBU_BC_PWR */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }QCH_GPU_SMMU_ADB_TBU_BC_PWR_IN;
    union { /* 0x02ac [Excel Line :0214]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QREQ                                                                         : 1;      /* [    0] QREQ to GPU_SMMU_ADB_TBU_BC_PWR */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }QCH_GPU_SMMU_ADB_TBU_BC_PWR_OUT;

    UINT8 EMPTY9[80]; /* 0x50 */

    union { /* 0x0300 [Excel Line :0216]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CL_EVENT_I_REQ                                                                               : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CL_EVENTIREQ;
    union { /* 0x0304 [Excel Line :0218]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CL_EVENT_I_ACK                                                                               : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CL_EVENTIACK;
    union { /* 0x0308 [Excel Line :0220]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CL_EVENT_O_REQ                                                                               : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CL_EVENTOREQ;
    union { /* 0x030c [Excel Line :0222]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CL_EVENT_O_ACK                                                                               : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CL_EVENTOACK;
    union { /* 0x0310 [Excel Line :0224]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_PMU_SNAPSHOT_REQ                                                                             : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_PMU_SNAPSHOTREQ;
    union { /* 0x0314 [Excel Line :0226]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_PMU_SNAPSHOT_ACK                                                                             : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_PMU_SNAPSHOTACK;
    union { /* 0x0318 [Excel Line :0228]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREINSTRRUN                                                                                 : 8;      /* [  7:0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_COREINSTRRUN;
    union { /* 0x031c [Excel Line :0230]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_COREINSTRRET                                                                                 : 8;      /* [  7:0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_COREINSTRRET;
    union { /* 0x0320 [Excel Line :0232]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_CL_DBGPWRUPREQ                                                                               : 1;      /* [    0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_A65_CL_DBGWRUPREQ;
    union { /* 0x0324 [Excel Line :0234]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_A65_DBGPWRUPREQ                                                                                  : 8;      /* [  7:0] Refer Cortex-A65AE */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }CPU_A65_DBGPWRUPREQ;

    UINT8 EMPTY10[24]; /* 0x18 */

    union { /* 0x0340 [Excel Line :0236]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_CPUHALT0                                                                                      : 1;      /* [    0] Refer Cortex-R5 */
            UINT32 CPU_R5_CPUHALT1                                                                                      : 1;      /* [    1] Refer Cortex-R5 */
            UINT32 RESERVED1                                                                                            : 30;     /* [ 31:2]  */
        }Bit;
    }CPU_R5_CPUHALT;
    union { /* 0x0344 [Excel Line :0239]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_DBGNOCLKSTOP                                                                                  : 1;      /* [    0] Refer Cortex-R5 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_STOP_OUT;
    union { /* 0x0348 [Excel Line :0241]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_CLKSTOPPED0                                                                                   : 1;      /* [    0] Refer Cortex-R5 */
            UINT32 CPU_R5_CLKSTOPPED1                                                                                   : 1;      /* [    1] Refer Cortex-R5 */
            UINT32 RESERVED3                                                                                            : 2;      /* [  3:2]  */
            UINT32 CPU_R5_WFEPIPESTOPPED0                                                                               : 1;      /* [    4] Refer Cortex-R5 */
            UINT32 CPU_R5_WFEPIPESTOPPED1                                                                               : 1;      /* [    5] Refer Cortex-R5 */
            UINT32 RESERVED2                                                                                            : 2;      /* [  7:6]  */
            UINT32 CPU_R5_WFIPIPESTOPPED0                                                                               : 1;      /* [    8] Refer Cortex-R5 */
            UINT32 CPU_R5_WFIPIPESTOPPED1                                                                               : 1;      /* [    9] Refer Cortex-R5 */
            UINT32 RESERVED1                                                                                            : 22;     /* [31:10]  */
        }Bit;
    }CPU_R5_STOP_IN;

    UINT8 EMPTY11[4]; /* 0x4 */

    union { /* 0x0350 [Excel Line :0250]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTI0                                                                                       : 1;      /* [    0] Refer Cortex-R5 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_EVENTI;
    union { /* 0x0354 [Excel Line :0252]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTO0                                                                                       : 1;      /* [    0] Refer Cortex-R5 */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }CPU_R5_EVENTO;

    UINT8 EMPTY12[8]; /* 0x8 */

    union { /* 0x0360 [Excel Line :0254]  */
        UINT32 Reg;
        struct {
            UINT32 GIC_CPU_ACTIVE                                                                                       : 8;      /* [  7:0] Refer GIC */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }GIC_CPU_ACTIVE;
    union { /* 0x0364 [Excel Line :0256]  */
        UINT32 Reg;
        struct {
            UINT32 GIC_WAKE_REQ                                                                                         : 8;      /* [  7:0] Refer GIC */
            UINT32 RESERVED1                                                                                            : 24;     /* [ 31:8]  */
        }Bit;
    }GIC_WAKE_REQ;

    UINT8 EMPTY13[8]; /* 0x8 */

    union { /* 0x0370 [Excel Line :0258]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TCU_SYSCO_ACK                                                                               : 1;      /* [    0] Refer SMMU in BLK_GPU */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }GPU_SMMU_TCU_SYSCO_EVENT_OUT;
    union { /* 0x0374 [Excel Line :0260]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TCU_SYSCO_REQ                                                                               : 1;      /* [    0] Refer SMMU in BLK_GPU */
            UINT32 RESERVED2                                                                                            : 3;      /* [  3:1]  */
            UINT32 GPU_SMMU_TCU_EVENTO                                                                                  : 1;      /* [    4] Refer SMMU in BLK_GPU */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }GPU_SMMU_TCU_SYSCO_EVENT_IN;
    union { /* 0x0378 [Excel Line :0264]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU0_PMUSNAPSHOT_REQ                                                                        : 1;      /* [    0] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU1_PMUSNAPSHOT_REQ                                                                        : 1;      /* [    1] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU2_PMUSNAPSHOT_REQ                                                                        : 1;      /* [    2] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU3_PMUSNAPSHOT_REQ                                                                        : 1;      /* [    3] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TCU_PMUSNAPSHOT_REQ                                                                         : 1;      /* [    4] Refer SMMU in BLK_GPU */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }GPU_SMMU_PMUSNAPSHOT_OUT;
    union { /* 0x037c [Excel Line :0270]  */
        UINT32 Reg;
        struct {
            UINT32 GPU_SMMU_TBU0_PMUSNAPSHOT_ACK                                                                        : 1;      /* [    0] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU1_PMUSNAPSHOT_ACK                                                                        : 1;      /* [    1] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU2_PMUSNAPSHOT_ACK                                                                        : 1;      /* [    2] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TBU3_PMUSNAPSHOT_ACK                                                                        : 1;      /* [    3] Refer SMMU in BLK_GPU */
            UINT32 GPU_SMMU_TCU_PMUSNAPSHOT_ACK                                                                         : 1;      /* [    4] Refer SMMU in BLK_GPU */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }GPU_SMMU_PMUSNAPSHOT_IN;

    UINT8 EMPTY14[128]; /* 0x80 */

    union { /* 0x0400 [Excel Line :0276]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_A65_FULL                                                                                      : 1;      /* [    0] A65_FULL Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_A65_FULL;
    union { /* 0x0404 [Excel Line :0278]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_A65_FULL                                                                                     : 1;      /* [    0] A65_FULL Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_A65_FULL;
    union { /* 0x0408 [Excel Line :0280]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_A65_FULL                                                                                : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_A65_FULL;
    union { /* 0x040c [Excel Line :0282]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_A65_FULL                                                                                     : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_A65_FULL;
    union { /* 0x0410 [Excel Line :0284]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_A65_FULL                                                                                     : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_A65_FULL;
    union { /* 0x0414 [Excel Line :0286]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_A65_FULL                                                                          : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_A65_FULL                                                                           : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_A65_FULL                                                                           : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_A65_FULL                                                                       : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_A65_FULL                                                                           : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_A65_FULL;
    union { /* 0x0418 [Excel Line :0292]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_A65_FULL                                                                                   : 3;      /* [  2:0] A65_FULL Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_A65_FULL;

    UINT8 EMPTY15[4]; /* 0x4 */

    union { /* 0x0420 [Excel Line :0294]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_A65_CORE_1                                                                                    : 1;      /* [    0] A65_CORE_1 Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_A65_CORE_1;
    union { /* 0x0424 [Excel Line :0296]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_A65_CORE_1                                                                                   : 1;      /* [    0] A65_CORE_1 Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_A65_CORE_1;
    union { /* 0x0428 [Excel Line :0298]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_A65_CORE_1                                                                              : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_A65_CORE_1;
    union { /* 0x042c [Excel Line :0300]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_A65_CORE_1                                                                                   : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_A65_CORE_1;
    union { /* 0x0430 [Excel Line :0302]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_A65_CORE_1                                                                                   : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_A65_CORE_1;
    union { /* 0x0434 [Excel Line :0304]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_A65_CORE_1                                                                        : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_A65_CORE_1                                                                         : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_A65_CORE_1                                                                         : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_A65_CORE_1                                                                     : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_A65_CORE_1                                                                         : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_A65_CORE_1;
    union { /* 0x0438 [Excel Line :0310]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_A65_CORE_1                                                                                 : 3;      /* [  2:0] A65_CORE_1 Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_A65_CORE_1;

    UINT8 EMPTY16[4]; /* 0x4 */

    union { /* 0x0440 [Excel Line :0312]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_A65_CORE_2                                                                                    : 1;      /* [    0] A65_CORE_2 Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_A65_CORE_2;
    union { /* 0x0444 [Excel Line :0314]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_A65_CORE_2                                                                                   : 1;      /* [    0] A65_CORE_2 Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_A65_CORE_2;
    union { /* 0x0448 [Excel Line :0316]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_A65_CORE_2                                                                              : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_A65_CORE_2;
    union { /* 0x044c [Excel Line :0318]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_A65_CORE_2                                                                                   : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_A65_CORE_2;
    union { /* 0x0450 [Excel Line :0320]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_A65_CORE_2                                                                                   : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_A65_CORE_2;
    union { /* 0x0454 [Excel Line :0322]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_A65_CORE_2                                                                        : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_A65_CORE_2                                                                         : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_A65_CORE_2                                                                         : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_A65_CORE_2                                                                     : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_A65_CORE_2                                                                         : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_A65_CORE_2;
    union { /* 0x0458 [Excel Line :0328]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_A65_CORE_2                                                                                 : 3;      /* [  2:0] A65_CORE_2 Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_A65_CORE_2;

    UINT8 EMPTY17[4]; /* 0x4 */

    union { /* 0x0460 [Excel Line :0330]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_A65_CORE_3                                                                                    : 1;      /* [    0] A65_CORE_3 Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_A65_CORE_3;
    union { /* 0x0464 [Excel Line :0332]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_A65_CORE_3                                                                                   : 1;      /* [    0] A65_CORE_3 Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_A65_CORE_3;
    union { /* 0x0468 [Excel Line :0334]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_A65_CORE_3                                                                              : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_A65_CORE_3;
    union { /* 0x046c [Excel Line :0336]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_A65_CORE_3                                                                                   : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_A65_CORE_3;
    union { /* 0x0470 [Excel Line :0338]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_A65_CORE_3                                                                                   : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_A65_CORE_3;
    union { /* 0x0474 [Excel Line :0340]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_A65_CORE_3                                                                        : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_A65_CORE_3                                                                         : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_A65_CORE_3                                                                         : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_A65_CORE_3                                                                     : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_A65_CORE_3                                                                         : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_A65_CORE_3;
    union { /* 0x0478 [Excel Line :0346]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_A65_CORE_3                                                                                 : 3;      /* [  2:0] A65_CORE_3 Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_A65_CORE_3;

    UINT8 EMPTY18[4]; /* 0x4 */

    union { /* 0x0480 [Excel Line :0348]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_VISION0                                                                                   : 1;      /* [    0] BLK_VISION0 Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_VISION0;
    union { /* 0x0484 [Excel Line :0350]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_VISION0                                                                                  : 1;      /* [    0] BLK_VISION0 Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_VISION0;
    union { /* 0x0488 [Excel Line :0352]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_VISION0                                                                             : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_VISION0;
    union { /* 0x048c [Excel Line :0354]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_VISION0                                                                                  : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_VISION0;
    union { /* 0x0490 [Excel Line :0356]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_VISION0                                                                                  : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_VISION0;
    union { /* 0x0494 [Excel Line :0358]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_VISION0                                                                       : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_VISION0                                                                        : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_VISION0                                                                        : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_VISION0                                                                    : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_VISION0                                                                        : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_VISION0;
    union { /* 0x0498 [Excel Line :0364]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_VISION0                                                                                : 3;      /* [  2:0] BLK_VISION0 Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_VISION0;

    UINT8 EMPTY19[4]; /* 0x4 */

    union { /* 0x04a0 [Excel Line :0366]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_VISION1                                                                                   : 1;      /* [    0] BLK_VISION1 Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_VISION1;
    union { /* 0x04a4 [Excel Line :0368]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_VISION1                                                                                  : 1;      /* [    0] BLK_VISION1 Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_VISION1;
    union { /* 0x04a8 [Excel Line :0370]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_VISION1                                                                             : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_VISION1;
    union { /* 0x04ac [Excel Line :0372]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_VISION1                                                                                  : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_VISION1;
    union { /* 0x04b0 [Excel Line :0374]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_VISION1                                                                                  : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_VISION1;
    union { /* 0x04b4 [Excel Line :0376]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_VISION1                                                                       : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_VISION1                                                                        : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_VISION1                                                                        : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_VISION1                                                                    : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_VISION1                                                                        : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_VISION1;
    union { /* 0x04b8 [Excel Line :0382]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_VISION1                                                                                : 3;      /* [  2:0] BLK_VISION1 Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_VISION1;

    UINT8 EMPTY20[4]; /* 0x4 */

    union { /* 0x04c0 [Excel Line :0384]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_DDR1                                                                                      : 1;      /* [    0] NA */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_DDR1;
    union { /* 0x04c4 [Excel Line :0386]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_DDR1                                                                                     : 1;      /* [    0] NA */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_DDR1;
    union { /* 0x04c8 [Excel Line :0388]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_DDR1                                                                                : 16;     /* [ 15:0] NA */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_DDR1;
    union { /* 0x04cc [Excel Line :0390]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_DDR1                                                                                     : 1;      /* [    0] NA */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_DDR1;
    union { /* 0x04d0 [Excel Line :0392]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_DDR1                                                                                     : 3;      /* [  2:0] NA */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_DDR1;
    union { /* 0x04d4 [Excel Line :0394]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_DDR1                                                                          : 1;      /* [    0] NA */
            UINT32 SC_CTRL_POL_SCPRE_BLK_DDR1                                                                           : 1;      /* [    1] NA */
            UINT32 SC_CTRL_POL_SCALL_BLK_DDR1                                                                           : 1;      /* [    2] NA */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_DDR1                                                                       : 1;      /* [    3] NA */
            UINT32 SC_CTRL_REG_CLEAR_BLK_DDR1                                                                           : 1;      /* [    4] NA */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_DDR1;
    union { /* 0x04d8 [Excel Line :0400]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_DDR1                                                                                   : 3;      /* [  2:0] NA */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_DDR1;

    UINT8 EMPTY21[4]; /* 0x4 */

    union { /* 0x04e0 [Excel Line :0402]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_CODEC                                                                                         : 1;      /* [    0] CODEC Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_CODEC;
    union { /* 0x04e4 [Excel Line :0404]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_CODEC                                                                                        : 1;      /* [    0] CODEC Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_CODEC;
    union { /* 0x04e8 [Excel Line :0406]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_CODEC                                                                                   : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_CODEC;
    union { /* 0x04ec [Excel Line :0408]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_CODEC                                                                                        : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_CODEC;
    union { /* 0x04f0 [Excel Line :0410]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_CODEC                                                                                        : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_CODEC;
    union { /* 0x04f4 [Excel Line :0412]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_CODEC                                                                             : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_CODEC                                                                              : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_CODEC                                                                              : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_CODEC                                                                          : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_CODEC                                                                              : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_CODEC;
    union { /* 0x04f8 [Excel Line :0418]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_CODEC                                                                                      : 3;      /* [  2:0] CODEC Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_CODEC;

    UINT8 EMPTY22[4]; /* 0x4 */

    union { /* 0x0500 [Excel Line :0420]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_NPU                                                                                       : 1;      /* [    0] BLK_NPU Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_NPU;
    union { /* 0x0504 [Excel Line :0422]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_NPU                                                                                      : 1;      /* [    0] BLK_NPU Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_NPU;
    union { /* 0x0508 [Excel Line :0424]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_NPU                                                                                 : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_NPU;
    union { /* 0x050c [Excel Line :0426]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_NPU                                                                                      : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_NPU;
    union { /* 0x0510 [Excel Line :0428]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_NPU                                                                                      : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_NPU;
    union { /* 0x0514 [Excel Line :0430]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_NPU                                                                           : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_NPU                                                                            : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_NPU                                                                            : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_NPU                                                                        : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_NPU                                                                            : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_NPU;
    union { /* 0x0518 [Excel Line :0436]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_NPU                                                                                    : 3;      /* [  2:0] BLK_NPU Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_NPU;

    UINT8 EMPTY23[4]; /* 0x4 */

    union { /* 0x0520 [Excel Line :0438]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_GPU                                                                                       : 1;      /* [    0] BLK_GPU Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_GPU;
    union { /* 0x0524 [Excel Line :0440]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_GPU                                                                                      : 1;      /* [    0] BLK_GPU Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_GPU;
    union { /* 0x0528 [Excel Line :0442]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_GPU                                                                                 : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_GPU;
    union { /* 0x052c [Excel Line :0444]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_GPU                                                                                      : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_GPU;
    union { /* 0x0530 [Excel Line :0446]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_GPU                                                                                      : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_GPU;
    union { /* 0x0534 [Excel Line :0448]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_GPU                                                                           : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_GPU                                                                            : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_GPU                                                                            : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_GPU                                                                        : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_GPU                                                                            : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_GPU;
    union { /* 0x0538 [Excel Line :0454]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_GPU                                                                                    : 3;      /* [  2:0] BLK_GPU Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_GPU;

    UINT8 EMPTY24[4]; /* 0x4 */

    union { /* 0x0540 [Excel Line :0456]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_PCIE                                                                                      : 1;      /* [    0] BLK_PCIE Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_PCIE;
    union { /* 0x0544 [Excel Line :0458]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_PCIE                                                                                     : 1;      /* [    0] BLK_PCIE Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_PCIE;
    union { /* 0x0548 [Excel Line :0460]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_PCIE                                                                                : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_PCIE;
    union { /* 0x054c [Excel Line :0462]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_PCIE                                                                                     : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_PCIE;
    union { /* 0x0550 [Excel Line :0464]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_PCIE                                                                                     : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_PCIE;
    union { /* 0x0554 [Excel Line :0466]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_PCIE                                                                          : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_PCIE                                                                           : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_PCIE                                                                           : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_PCIE                                                                       : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_PCIE                                                                           : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_PCIE;
    union { /* 0x0558 [Excel Line :0472]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_PCIE                                                                                   : 3;      /* [  2:0] BLK_PCIE Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_PCIE;

    UINT8 EMPTY25[4]; /* 0x4 */

    union { /* 0x0560 [Excel Line :0474]  */
        UINT32 Reg;
        struct {
            UINT32 ISO_EN_BLK_USB                                                                                       : 1;      /* [    0] BLK_USB Boundary port Isolation Control
                                                                                                                                             0 Isolation Disable connected
                                                                                                                                             1 Isolation Enable disconnected */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }ISO_EN_BLK_USB;
    union { /* 0x0564 [Excel Line :0476]  */
        UINT32 Reg;
        struct {
            UINT32 PWR_OFF_BLK_USB                                                                                      : 1;      /* [    0] BLK_USB Power Domain Power Gate Control
                                                                                                                                             0 Power On
                                                                                                                                             1 Power Off */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PWR_OFF_BLK_USB;
    union { /* 0x0568 [Excel Line :0478]  */
        UINT32 Reg;
        struct {
            UINT32 T_WAKEUP_DLY_BLK_USB                                                                                 : 16;     /* [ 15:0] SCPRE to SCALL delay when wake-up OSC_CK clock */
            UINT32 RESERVED1                                                                                            : 16;     /* [31:16]  */
        }Bit;
    }T_WAKEUP_DLY_BLK_USB;
    union { /* 0x056c [Excel Line :0480]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_EN_BLK_USB                                                                                      : 1;      /* [    0] Power Gating Manual control enable */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }MANU_EN_BLK_USB;
    union { /* 0x0570 [Excel Line :0482]  */
        UINT32 Reg;
        struct {
            UINT32 MANU_SC_BLK_USB                                                                                      : 3;      /* [  2:0] Power Gating Manual control
                                                                                                                                             2  SCALL out
                                                                                                                                             1  SCPRE out
                                                                                                                                             0  Reserved */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }MANU_SC_BLK_USB;
    union { /* 0x0574 [Excel Line :0484]  */
        UINT32 Reg;
        struct {
            UINT32 SC_CTRL_POL_ISO_EN_BLK_USB                                                                           : 1;      /* [    0] ISO_EN polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCPRE_BLK_USB                                                                            : 1;      /* [    1] SCPRE polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_BLK_USB                                                                            : 1;      /* [    2] SCALL polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_POL_SCALL_OUT_BLK_USB                                                                        : 1;      /* [    3] SCALL_OUT polarity 1Inverse 0Normal */
            UINT32 SC_CTRL_REG_CLEAR_BLK_USB                                                                            : 1;      /* [    4] Power Gate Control Clear */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }SC_CTRL_BLK_USB;
    union { /* 0x0578 [Excel Line :0490]  */
        UINT32 Reg;
        struct {
            UINT32 SC_STATUS_BLK_USB                                                                                    : 3;      /* [  2:0] BLK_USB Power Domain Gating Control Signal Status
                                                                                                                                             2  SCALL
                                                                                                                                             1  SCPRE
                                                                                                                                             0  SCALL_OUT */
            UINT32 RESERVED1                                                                                            : 29;     /* [ 31:3]  */
        }Bit;
    }SC_STATUS_BLK_USB;

    UINT8 EMPTY26[132]; /* 0x84 */

    union { /* 0x0600 [Excel Line :0492]  */
        UINT32 Reg;
        struct {
            UINT32 OIC_PACTIVE_CHG_IRQ                                                                                  : 1;      /* [    0] OIC_PACTIVE Change Interrupt pending and Clear */
            UINT32 OMC0_PACTIVE_CHG_IRQ                                                                                 : 1;      /* [    1] OMC0_PACTIVE Change Interrupt pending and Clear */
            UINT32 OMC1_PACTIVE_CHG_IRQ                                                                                 : 1;      /* [    2] OMC1_PACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED4                                                                                            : 1;      /* [    3]  */
            UINT32 A65_CORE0_PACTIVE_CHG_IRQ                                                                            : 1;      /* [    4] A65_CORE0_PACTIVE Change Interrupt pending and Clear */
            UINT32 A65_CORE1_PACTIVE_CHG_IRQ                                                                            : 1;      /* [    5] A65_CORE1_PACTIVE Change Interrupt pending and Clear */
            UINT32 A65_CORE2_PACTIVE_CHG_IRQ                                                                            : 1;      /* [    6] A65_CORE2_PACTIVE Change Interrupt pending and Clear */
            UINT32 A65_CORE3_PACTIVE_CHG_IRQ                                                                            : 1;      /* [    7] A65_CORE3_PACTIVE Change Interrupt pending and Clear */
            UINT32 A65_CLUSTER_PACTIVE_CHG_IRQ                                                                          : 1;      /* [    8] A65_CLUSTER_PACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED3                                                                                            : 7;      /* [ 15:9]  */
            UINT32 OIC_PACTIVE_PAT_IRQ                                                                                  : 1;      /* [   16] OIC_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 OMC0_PACTIVE_PAT_IRQ                                                                                 : 1;      /* [   17] OMC0_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 OMC1_PACTIVE_PAT_IRQ                                                                                 : 1;      /* [   18] OMC1_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 RESERVED2                                                                                            : 1;      /* [   19]  */
            UINT32 A65_CORE0_PACTIVE_PAT_IRQ                                                                            : 1;      /* [   20] A65_CORE0_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 A65_CORE1_PACTIVE_PAT_IRQ                                                                            : 1;      /* [   21] A65_CORE1_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 A65_CORE2_PACTIVE_PAT_IRQ                                                                            : 1;      /* [   22] A65_CORE2_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 A65_CORE3_PACTIVE_PAT_IRQ                                                                            : 1;      /* [   23] A65_CORE3_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 A65_CLUSTER_PACTIVE_PAT_IRQ                                                                          : 1;      /* [   24] A65_CLUSTER_PACTIVE Pattern Matched Interrupt pending and Clear */
            UINT32 RESERVED1                                                                                            : 7;      /* [31:25]  */
        }Bit;
    }PMU_PCH_IRQ;
    union { /* 0x0604 [Excel Line :0512]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCLK_DOM_QACTIVE_IRQ                                                                             : 1;      /* [    0] CPU_SCLK_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 CPU_PCLK_DOM_QACTIVE_IRQ                                                                             : 1;      /* [    1] CPU_PCLK_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 CPU_ATCLK_DOM_QACTIVE_IRQ                                                                            : 1;      /* [    2] CPU_ATCLK_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 CPU_GICCLK_DOM_QACTIVE_IRQ                                                                           : 1;      /* [    3] CPU_GICCLK_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 CPU_PDBGCLK_DOM_QACTIVE_IRQ                                                                          : 1;      /* [    4] CPU_PDBGCLK_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED4                                                                                            : 1;      /* [    5]  */
            UINT32 CPU_DBGPWR_DOM_QACTIVE_IRQ                                                                           : 1;      /* [    6] CPU_DBGPWR_DOM_QACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED3                                                                                            : 2;      /* [  8:7]  */
            UINT32 GIC_CLK_QACTIVE_IRQ                                                                                  : 1;      /* [    9] GIC_CLK_QACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED2                                                                                            : 2;      /* [11:10]  */
            UINT32 GPU_QACTIVE_IRQ                                                                                      : 1;      /* [   12] GPU_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TBU0_QACTIVE_IRQ                                                                            : 1;      /* [   13] GPU_SMMU_TBU0_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TBU1_QACTIVE_IRQ                                                                            : 1;      /* [   14] GPU_SMMU_TBU1_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TBU2_QACTIVE_IRQ                                                                            : 1;      /* [   15] GPU_SMMU_TBU2_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TBU3_QACTIVE_IRQ                                                                            : 1;      /* [   16] GPU_SMMU_TBU3_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TCU_QACTIVE_IRQ                                                                             : 1;      /* [   17] GPU_SMMU_TCU_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QACTIVE_IRQ                                                                    : 1;      /* [   18] GPU_SMMU_LPD_CG_A_CLK_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QACTIVE_IRQ                                                                    : 1;      /* [   19] GPU_SMMU_LPD_CG_B_CLK_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QACTIVE_IRQ                                                                    : 1;      /* [   20] GPU_SMMU_LPD_CG_C_CLK_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QACTIVE_IRQ                                                                    : 1;      /* [   21] GPU_SMMU_LPD_PD_C_CLK_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QACTIVE_IRQ                                                                  : 1;      /* [   22] GPU_SMMU_ADB_TBU_AC_PWR_QACTIVE Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QACTIVE_IRQ                                                                  : 1;      /* [   23] GPU_SMMU_ADB_TBU_BC_PWR_QACTIVE Change Interrupt pending and Clear */
            UINT32 RESERVED1                                                                                            : 8;      /* [31:24]  */
        }Bit;
    }PMU_QCH_IRQ;
    union { /* 0x0608 [Excel Line :0535]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTO0_IRQ                                                                                   : 1;      /* [    0] CPU_R5_EVENTO0 Change Interrupt pending and Clear */
            UINT32 CPU_R5_CLKSTOPPED0_IRQ                                                                               : 1;      /* [    1] CPU_R5_CLKSTOPPED0 Change Interrupt pending and Clear */
            UINT32 CPU_R5_CLKSTOPPED1_IRQ                                                                               : 1;      /* [    2] CPU_R5_CLKSTOPPED1 Change Interrupt pending and Clear */
            UINT32 CPU_R5_WFEPIPESTOPPED0_IRQ                                                                           : 1;      /* [    3] CPU_R5_WFEPIPESTOPPED0 Change Interrupt pending and Clear */
            UINT32 CPU_R5_WFEPIPESTOPPED1_IRQ                                                                           : 1;      /* [    4] CPU_R5_WFEPIPESTOPPED1 Change Interrupt pending and Clear */
            UINT32 CPU_R5_WFIPIPESTOPPED0_IRQ                                                                           : 1;      /* [    5] CPU_R5_WFIPIPESTOPPED0 Change Interrupt pending and Clear */
            UINT32 CPU_R5_WFIPIPESTOPPED1_IRQ                                                                           : 1;      /* [    6] CPU_R5_WFIPIPESTOPPED1 Change Interrupt pending and Clear */
            UINT32 RESERVED4                                                                                            : 1;      /* [    7]  */
            UINT32 CPU_A65_CL_EVENT_O_REQ_IRQ                                                                           : 1;      /* [    8] CPU_A65_CL_EVENT_O_REQ Change Interrupt pending and Clear */
            UINT32 CPU_A65_CL_DBGPWRUPREQ_IRQ                                                                           : 1;      /* [    9] CPU_A65_CL_DBGPWRUPREQ Change Interrupt pending and Clear */
            UINT32 CPU_A65_DBGPWRUPREQ_IRQ                                                                              : 1;      /* [   10] CPU_A65_DBGPWRUPREQ Change Interrupt pending and Clear */
            UINT32 RESERVED3                                                                                            : 5;      /* [15:11]  */
            UINT32 GIC_WAKE_REQ_IRQ                                                                                     : 1;      /* [   16] GIC_WAKE_REQ Change Interrupt pending and Clear */
            UINT32 RESERVED2                                                                                            : 3;      /* [19:17]  */
            UINT32 GPU_SMMU_TCU_SYSCO_REQ_IRQ                                                                           : 1;      /* [   20] GPU_SMMU_TCU_SYSCO_REQ Change Interrupt pending and Clear */
            UINT32 GPU_SMMU_TCU_EVENTO_IRQ                                                                              : 1;      /* [   21] GPU_SMMU_TCU_EVENTO Change Interrupt pending and Clear */
            UINT32 RESERVED1                                                                                            : 10;     /* [31:22]  */
        }Bit;
    }PMU_IRQ;

    UINT8 EMPTY27[4]; /* 0x4 */

    union { /* 0x0610 [Excel Line :0552]  */
        UINT32 Reg;
        struct {
            UINT32 OIC_PACTIVE_CHG_IRQ_EN                                                                               : 1;      /* [    0] OIC_PACTIVE Change Interrupt Enable */
            UINT32 OMC0_PACTIVE_CHG_IRQ_EN                                                                              : 1;      /* [    1] OMC0_PACTIVE Change Interrupt Enable */
            UINT32 OMC1_PACTIVE_CHG_IRQ_EN                                                                              : 1;      /* [    2] OMC1_PACTIVE Change Interrupt Enable */
            UINT32 RESERVED4                                                                                            : 1;      /* [    3]  */
            UINT32 A65_CORE0_PACTIVE_CHG_IRQ_EN                                                                         : 1;      /* [    4] A65_CORE0_PACTIVE Change Interrupt Enable */
            UINT32 A65_CORE1_PACTIVE_CHG_IRQ_EN                                                                         : 1;      /* [    5] A65_CORE1_PACTIVE Change Interrupt Enable */
            UINT32 A65_CORE2_PACTIVE_CHG_IRQ_EN                                                                         : 1;      /* [    6] A65_CORE2_PACTIVE Change Interrupt Enable */
            UINT32 A65_CORE3_PACTIVE_CHG_IRQ_EN                                                                         : 1;      /* [    7] A65_CORE3_PACTIVE Change Interrupt Enable */
            UINT32 A65_CLUSTER_PACTIVE_CHG_IRQ_EN                                                                       : 1;      /* [    8] A65_CLUSTER_PACTIVE Change Interrupt Enable */
            UINT32 RESERVED3                                                                                            : 7;      /* [ 15:9]  */
            UINT32 OIC_PACTIVE_PAT_IRQ_EN                                                                               : 1;      /* [   16] OIC_PACTIVE Pattern Match Interrupt Enable */
            UINT32 OMC0_PACTIVE_PAT_IRQ_EN                                                                              : 1;      /* [   17] OMC0_PACTIVE Pattern Match Interrupt Enable */
            UINT32 OMC1_PACTIVE_PAT_IRQ_EN                                                                              : 1;      /* [   18] OMC1_PACTIVE Pattern Match Interrupt Enable */
            UINT32 RESERVED2                                                                                            : 1;      /* [   19]  */
            UINT32 A65_CORE0_PACTIVE_PAT_IRQ_EN                                                                         : 1;      /* [   20] A65_CORE0_PACTIVE Pattern Match Interrupt Enable */
            UINT32 A65_CORE1_PACTIVE_PAT_IRQ_EN                                                                         : 1;      /* [   21] A65_CORE1_PACTIVE Pattern Match Interrupt Enable */
            UINT32 A65_CORE2_PACTIVE_PAT_IRQ_EN                                                                         : 1;      /* [   22] A65_CORE2_PACTIVE Pattern Match Interrupt Enable */
            UINT32 A65_CORE3_PACTIVE_PAT_IRQ_EN                                                                         : 1;      /* [   23] A65_CORE3_PACTIVE Pattern Match Interrupt Enable */
            UINT32 A65_CLUSTER_PACTIVE_PAT_IRQ_EN                                                                       : 1;      /* [   24] A65_CLUSTER_PACTIVE Pattern Match Interrupt Enable */
            UINT32 RESERVED1                                                                                            : 7;      /* [31:25]  */
        }Bit;
    }PMU_PCH_IRQ_EN;
    union { /* 0x0614 [Excel Line :0572]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_SCLK_DOM_QACTIVE_IRQ_EN                                                                          : 1;      /* [    0] CPU_SCLK_DOM_QACTIVE Change Interrupt Enable */
            UINT32 CPU_PCLK_DOM_QACTIVE_IRQ_EN                                                                          : 1;      /* [    1] CPU_PCLK_DOM_QACTIVE Change Interrupt Enable */
            UINT32 CPU_ATCLK_DOM_QACTIVE_IRQ_EN                                                                         : 1;      /* [    2] CPU_ATCLK_DOM_QACTIVE Change Interrupt Enable */
            UINT32 CPU_GICCLK_DOM_QACTIVE_IRQ_EN                                                                        : 1;      /* [    3] CPU_GICCLK_DOM_QACTIVE Change Interrupt Enable */
            UINT32 CPU_PDBGCLK_DOM_QACTIVE_IRQ_EN                                                                       : 1;      /* [    4] CPU_PDBGCLK_DOM_QACTIVE Change Interrupt Enable */
            UINT32 RESERVED4                                                                                            : 1;      /* [    5]  */
            UINT32 CPU_DBGPWR_DOM_QACTIVE_IRQ_EN                                                                        : 1;      /* [    6] CPU_DBGPWR_DOM_QACTIVE Change Interrupt Enable */
            UINT32 RESERVED3                                                                                            : 2;      /* [  8:7]  */
            UINT32 GIC_CLK_QACTIVE_IRQ_EN                                                                               : 1;      /* [    9] GIC_CLK_QACTIVE Change Interrupt Enable */
            UINT32 RESERVED2                                                                                            : 2;      /* [11:10]  */
            UINT32 GPU_QACTIVE_IRQ_EN                                                                                   : 1;      /* [   12] GPU_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_TBU0_QACTIVE_IRQ_EN                                                                         : 1;      /* [   13] GPU_SMMU_TBU0_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_TBU1_QACTIVE_IRQ_EN                                                                         : 1;      /* [   14] GPU_SMMU_TBU1_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_TBU2_QACTIVE_IRQ_EN                                                                         : 1;      /* [   15] GPU_SMMU_TBU2_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_TBU3_QACTIVE_IRQ_EN                                                                         : 1;      /* [   16] GPU_SMMU_TBU3_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_TCU_QACTIVE_IRQ_EN                                                                          : 1;      /* [   17] GPU_SMMU_TCU_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_LPD_CG_A_CLK_QACTIVE_IRQ_EN                                                                 : 1;      /* [   18] GPU_SMMU_LPD_CG_A_CLK_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_LPD_CG_B_CLK_QACTIVE_IRQ_EN                                                                 : 1;      /* [   19] GPU_SMMU_LPD_CG_B_CLK_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_LPD_CG_C_CLK_QACTIVE_IRQ_EN                                                                 : 1;      /* [   20] GPU_SMMU_LPD_CG_C_CLK_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_LPD_PD_C_CLK_QACTIVE_IRQ_EN                                                                 : 1;      /* [   21] GPU_SMMU_LPD_PD_C_CLK_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_ADB_TBU_AC_PWR_QACTIVE_IRQ_EN                                                               : 1;      /* [   22] GPU_SMMU_ADB_TBU_AC_PWR_QACTIVE Change Interrupt Enable */
            UINT32 GPU_SMMU_ADB_TBU_BC_PWR_QACTIVE_IRQ_EN                                                               : 1;      /* [   23] GPU_SMMU_ADB_TBU_BC_PWR_QACTIVE Change Interrupt Enable */
            UINT32 RESERVED1                                                                                            : 8;      /* [31:24]  */
        }Bit;
    }PMU_QCH_IRQ_EN;
    union { /* 0x0618 [Excel Line :0595]  */
        UINT32 Reg;
        struct {
            UINT32 CPU_R5_EVENTO0_IRQ_EN                                                                                : 1;      /* [    0] CPU_R5_EVENTO0 Change Interrupt Enable */
            UINT32 CPU_R5_CLKSTOPPED0_IRQ_EN                                                                            : 1;      /* [    1] CPU_R5_CLKSTOPPED0 Change Interrupt Enable */
            UINT32 CPU_R5_CLKSTOPPED1_IRQ_EN                                                                            : 1;      /* [    2] CPU_R5_CLKSTOPPED1 Change Interrupt Enable */
            UINT32 CPU_R5_WFEPIPESTOPPED0_IRQ_EN                                                                        : 1;      /* [    3] CPU_R5_WFEPIPESTOPPED0 Change Interrupt Enable */
            UINT32 CPU_R5_WFEPIPESTOPPED1_IRQ_EN                                                                        : 1;      /* [    4] CPU_R5_WFEPIPESTOPPED1 Change Interrupt Enable */
            UINT32 CPU_R5_WFIPIPESTOPPED0_IRQ_EN                                                                        : 1;      /* [    5] CPU_R5_WFIPIPESTOPPED0 Change Interrupt Enable */
            UINT32 CPU_R5_WFIPIPESTOPPED1_IRQ_EN                                                                        : 1;      /* [    6] CPU_R5_WFIPIPESTOPPED1 Change Interrupt Enable */
            UINT32 RESERVED4                                                                                            : 1;      /* [    7]  */
            UINT32 CPU_A65_CL_EVENT_O_REQ_IRQ_EN                                                                        : 1;      /* [    8] CPU_A65_CL_EVENT_O_REQ Change Interrupt Enable */
            UINT32 CPU_A65_CL_DBGPWRUPREQ_IRQ_EN                                                                        : 1;      /* [    9] CPU_A65_CL_DBGPWRUPREQ Change Interrupt Enable */
            UINT32 CPU_A65_DBGPWRUPREQ_IRQ_EN                                                                           : 1;      /* [   10] CPU_A65_DBGPWRUPREQ Change Interrupt Enable */
            UINT32 RESERVED3                                                                                            : 5;      /* [15:11]  */
            UINT32 GIC_WAKE_REQ_IRQ_EN                                                                                  : 1;      /* [   16] GIC_WAKE_REQ Change Interrupt Enable */
            UINT32 RESERVED2                                                                                            : 3;      /* [19:17]  */
            UINT32 GPU_SMMU_TCU_SYSCO_REQ_IRQ_EN                                                                        : 1;      /* [   20] GPU_SMMU_TCU_SYSCO_REQ Change Interrupt Enable */
            UINT32 GPU_SMMU_TCU_EVENTO_IRQ_EN                                                                           : 1;      /* [   21] GPU_SMMU_TCU_EVENTO Change Interrupt Enable */
            UINT32 RESERVED1                                                                                            : 10;     /* [31:22]  */
        }Bit;
    }PMU_IRQ_EN;

    UINT8 EMPTY28[36]; /* 0x24 */

    union { /* 0x0640 [Excel Line :0612]  */
        UINT32 Reg;
        struct {
            UINT32 OIC_PACTIVE_PAT                                                                                      : 9;      /* [  8:0] OIC_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 23;     /* [ 31:9]  */
        }Bit;
    }PCH_OIC_IRQ_PAT;
    union { /* 0x0644 [Excel Line :0614]  */
        UINT32 Reg;
        struct {
            UINT32 OMC0_PACTIVE_PAT                                                                                     : 1;      /* [    0] OMC0_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PCH_OMC0_IRQ_PAT;
    union { /* 0x0648 [Excel Line :0616]  */
        UINT32 Reg;
        struct {
            UINT32 OMC1_PACTIVE_PAT                                                                                     : 1;      /* [    0] OMC1_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 31;     /* [ 31:1]  */
        }Bit;
    }PCH_OMC1_IRQ_PAT;
    union { /* 0x064c [Excel Line :0618]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE0_PACTIVE_PAT                                                                                : 18;     /* [ 17:0] A65_CORE0_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }PCH_A65_CORE0_IRQ_PAT;
    union { /* 0x0650 [Excel Line :0620]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE1_PACTIVE_PAT                                                                                : 18;     /* [ 17:0] A65_CORE1_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }PCH_A65_CORE1_IRQ_PAT;
    union { /* 0x0654 [Excel Line :0622]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE2_PACTIVE_PAT                                                                                : 18;     /* [ 17:0] A65_CORE2_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }PCH_A65_CORE2_IRQ_PAT;
    union { /* 0x0658 [Excel Line :0624]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CORE3_PACTIVE_PAT                                                                                : 18;     /* [ 17:0] A65_CORE3_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 14;     /* [31:18]  */
        }Bit;
    }PCH_A65_CORE3_IRQ_PAT;
    union { /* 0x065c [Excel Line :0626]  */
        UINT32 Reg;
        struct {
            UINT32 A65_CLUSTER_PACTIVE_PAT                                                                              : 20;     /* [ 19:0] A65_CLUSTER_PACTIVE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 12;     /* [31:20]  */
        }Bit;
    }PCH_A65_CLUSTER_IRQ_PAT;

    UINT8 EMPTY29[160]; /* 0xA0 */

    union { /* 0x0700 [Excel Line :0628]  */
        UINT32 Reg;
        struct {
            UINT32 DDR0_RET_ON                                                                                          : 1;      /* [    0] DDR0_RE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED2                                                                                            : 3;      /* [  3:1]  */
            UINT32 DDR0_RET_OFF                                                                                         : 1;      /* [    4] DDR0_RET Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }DDR0_RET;
    union { /* 0x0704 [Excel Line :0632]  */
        UINT32 Reg;
        struct {
            UINT32 DDR1_RET_ON                                                                                          : 1;      /* [    0] DDR1_RE Pattern Matching Interrupt Pattern */
            UINT32 RESERVED2                                                                                            : 3;      /* [  3:1]  */
            UINT32 DDR1_RET_OFF                                                                                         : 1;      /* [    4] DDR1_RET Pattern Matching Interrupt Pattern */
            UINT32 RESERVED1                                                                                            : 27;     /* [ 31:5]  */
        }Bit;
    }DDR1_RET;
}DRV_A6_PMU_REGISTER;
/* PRQA S 828 -- */

/* 
 static volatile DRV_A6_PMU_REGISTER* const RegA6_PMU = (DRV_A6_PMU_REGISTER*)APACHE_A6_PMU_BASE_ADDR;
 */



#endif /* end of  __DRV_REGISTER_A6_PMU__ */

