/**
 * @file board_defs.h
 *
 * @date Mar 8, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include "mcu_defs.h"
#include "core/stratum_conf.h"

#if TARGET_BOARD == STM32F769I_DISCO
#define SDRAM_BASE			FMC_SDRAM1_BASE
#define SDRAM_SIZE			(16U * 1024U * 1024U)	// 16 MB
#endif

#ifdef __cplusplus
}
#endif
