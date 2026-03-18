/**
 * @file mcu_defs.h
 *
 * @date Mar 8, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include "core/stratum_conf.h"

#if defined(STM32F769xx)
#define ITCM_RAM_BASE		0x00000000U
#define ITCM_RAM_SIZE		(16U * 1024U)	// 16 KB

#define FMC_SDRAM1_BASE		0xC0000000U
#endif

#ifdef __cplusplus
}
#endif
