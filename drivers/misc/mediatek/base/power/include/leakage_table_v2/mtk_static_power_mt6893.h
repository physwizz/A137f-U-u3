/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 MediaTek Inc.
 */

#ifndef __MTK_STATIC_POWER_MTK6885_H__
#define __MTK_STATIC_POWER_MTK6885_H__

//#define SPOWER_NOT_READY 1

//#define WITHOUT_LKG_EFUSE

/* mv */
#define V_OF_FUSE_CPU 900
#define V_OF_FUSE_GPU 750
#define V_OF_FUSE_VCORE 725
#define V_OF_FUSE_MODEM 800
#define V_OF_FUSE_NR 800
#define V_OF_FUSE_VPU 800
#define V_OF_FUSE_MDLA 825
#define V_OF_FUSE_VSRAM_PROC12 900
#define V_OF_FUSE_VSRAM_PROC11 900
#define V_OF_FUSE_VSRAM_OTHERS 750
#define V_OF_FUSE_ADSP 750
#define V_OF_FUSE_VSRAM_GPU 800
#define V_OF_FUSE_VSRAM_VPU_MDLA 825
#define V_OF_FUSE_VSRAM_MODEM 800
#define V_OF_FUSE_VCORE_OFF 550

#define T_OF_FUSE		30

/* devinfo offset for each bank */
/* CCI use LL leakage */
#define DEVINFO_IDX_LL 0x220
#define DEVINFO_IDX_L 0x220
#define DEVINFO_IDX_B 0x22C
#define DEVINFO_IDX_CCI 0x224
#define DEVINFO_IDX_GPU 0x224
#define DEVINFO_IDX_VCORE 0x224
#define DEVINFO_IDX_MODEM 0x224
#define DEVINFO_IDX_NR 0x228
#define DEVINFO_IDX_VPU 0x220
#define DEVINFO_IDX_MDLA 0x228
#define DEVINFO_IDX_VSRAM_PROC12 0x21C
#define DEVINFO_IDX_VSRAM_PROC11 0x21C
#define DEVINFO_IDX_VSRAM_OTHERS 0x21C
#define DEVINFO_IDX_ADSP 0x228
#define DEVINFO_IDX_VSRAM_GPU 0x220
#define DEVINFO_IDX_VSRAM_VPU_MDLA 0x224
#define DEVINFO_IDX_VSRAM_MODEM 0x21C
#define DEVINFO_IDX_VCORE_OFF 0x22C

#define DEVINFO_OFF_LL 0
#define DEVINFO_OFF_L 8
#define DEVINFO_OFF_B 8
#define DEVINFO_OFF_CCI 24
#define DEVINFO_OFF_GPU 16
#define DEVINFO_OFF_VCORE 8
#define DEVINFO_OFF_MODEM 0
#define DEVINFO_OFF_NR 24
#define DEVINFO_OFF_VPU 16
#define DEVINFO_OFF_MDLA 16
#define DEVINFO_OFF_VSRAM_PROC12 24
#define DEVINFO_OFF_VSRAM_PROC11 16
#define DEVINFO_OFF_VSRAM_OTHERS 8
#define DEVINFO_OFF_ADSP 8
#define DEVINFO_OFF_VSRAM_GPU 24
#define DEVINFO_OFF_VSRAM_VPU_MDLA 0
#define DEVINFO_OFF_VSRAM_MODEM 0
#define DEVINFO_OFF_VCORE_OFF 24

/* default leakage value for each bank */
#define DEF_CPULL_LEAKAGE 0
#define DEF_CPUL_LEAKAGE 0
#define DEF_CPUB_LEAKAGE 0
#define DEF_CCI_LEAKAGE 0
#define DEF_GPU_LEAKAGE 0
#define DEF_VCORE_LEAKAGE 0
#define DEF_MODEM_LEAKAGE 0
#define DEF_NR_LEAKAGE 0
#define DEF_VPU_LEAKAGE 0
#define DEF_MDLA_LEAKAGE 0
#define DEF_VSRAM_PROC12_LEAKAGE 0
#define DEF_VSRAM_PROC11_LEAKAGE 0
#define DEF_VSRAM_OTHERS_LEAKAGE 0
#define DEF_ADSP_LEAKAGE 0
#define DEF_VSRAM_GPU_LEAKAGE 0
#define DEF_VSRAM_VPU_MDLA_LEAKAGE 0
#define DEF_VSRAM_MODEM_LEAKAGE 0
#define DEF_VCORE_OFF_LEAKAGE 0

enum {
	MTK_SPOWER_CPULL,
	MTK_SPOWER_CPUL,
	MTK_SPOWER_CPUB,
	MTK_SPOWER_CCI,
	MTK_SPOWER_GPU,
	MTK_SPOWER_VCORE,
	MTK_SPOWER_MODEM,
	MTK_SPOWER_VPU,
	MTK_SPOWER_VSRAM_PROC12,
	MTK_SPOWER_VSRAM_PROC11,
	MTK_SPOWER_VSRAM_OTHERS,
	MTK_SPOWER_NR,
	MTK_SPOWER_MDLA,
	MTK_SPOWER_ADSP,
	MTK_SPOWER_VSRAM_GPU,
	MTK_SPOWER_VSRAM_VPU_MDLA,
	MTK_SPOWER_VSRAM_MODEM,
	MTK_SPOWER_VCORE_OFF,
	MTK_SPOWER_MAX
};

enum {
	MTK_LL_LEAKAGE,
	MTK_L_LEAKAGE,
	MTK_B_LEAKAGE,
	MTK_CCI_LEAKAGE,
	MTK_GPU_LEAKAGE,
	MTK_VCORE_LEAKAGE,
	MTK_MODEM_LEAKAGE,
	MTK_VPU_LEAKAGE,
	MTK_VSRAM_PROC12_LEAKAGE,
	MTK_VSRAM_PROC11_LEAKAGE,
	MTK_VSRAM_OTHERS_LEAKAGE,
	MTK_NR_LEAKAGE,
	MTK_MDLA_LEAKAGE,
	MTK_ADSP_LEAKAGE,
	MTK_VSRAM_GPU_LEAKAGE,
	MTK_VSRAM_VPU_MDLA_LEAKAGE,
	MTK_VSRAM_MODEM_LEAKAGE,
	MTK_VCORE_OFF_LEAKAGE,
	MTK_LEAKAGE_MAX
};

/* record leakage information that read from efuse */
struct spower_leakage_info {
	const char *name;
	unsigned int devinfo_idx;
	unsigned int devinfo_offset;
	unsigned int value;
	unsigned int v_of_fuse;
	int t_of_fuse;
};

extern struct spower_leakage_info spower_lkg_info[MTK_SPOWER_MAX];

/* efuse mapping */
/* 3967 modify */
#define LL_DEVINFO_DOMAIN (BIT(MTK_SPOWER_CPULL))
#define L_DEVINFO_DOMAIN (BIT(MTK_SPOWER_CPUL))
#define B_DEVINFO_DOMAIN (BIT(MTK_SPOWER_CPUB))
#define CCI_DEVINFO_DOMAIN (BIT(MTK_SPOWER_CCI))
#define GPU_DEVINFO_DOMAIN (BIT(MTK_SPOWER_GPU))
#define VCORE_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VCORE))
#define MODEM_DEVINFO_DOMAIN (BIT(MTK_SPOWER_MODEM))
#define VPU_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VPU))
#define VSRAM_PROC12_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_PROC12))
#define VSRAM_PROC11_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_PROC11))
#define VSRAM_GPU_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_GPU))
#define VSRAM_OTHERS_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_OTHERS))
#define NR_DEVINFO_DOMAIN (BIT(MTK_SPOWER_NR))
#define MDLA_DEVINFO_DOMAIN (BIT(MTK_SPOWER_MDLA))
#define ADSP_DEVINFO_DOMAIN (BIT(MTK_SPOWER_ADSP))
#define VSRAM_GPU_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_GPU))
#define VSRAM_VPU_MDLA_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_VPU_MDLA))
#define VSRAM_MODEM_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VSRAM_MODEM))
#define VCORE_OFF_DEVINFO_DOMAIN (BIT(MTK_SPOWER_VCORE_OFF))

/* used to calculate total leakage that search from raw table */
#define DEFAULT_CORE_INSTANCE 4
#define DEFAULT_LL_CORE_INSTANCE 4
#define DEFAULT_L_CORE_INSTANCE 3
#define DEFAULT_B_CORE_INSTANCE 1
#define DEFAULT_INSTANCE 1

extern char *spower_name[];
extern char *leakage_name[];
extern int default_leakage[];
extern int devinfo_idx[];
extern int devinfo_offset[];
extern int devinfo_table[];

#endif
