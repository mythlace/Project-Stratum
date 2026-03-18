/**
 * @file mem_manager.h
 *
 * @date Mar 6, 2026
 * @author mdev 
 */

#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include "core/stratum_defs.h"

#if defined(STM32F769xx)
typedef enum {
	MEM_DEV_INT_ITCM_RAM,
	MEM_DEV_INT_DTCM_RAM,
	MEM_DEV_INT_SRAM1,
	MEM_DEV_INT_SRAM2,
	MEM_DEV_INT_FLASH_ITCM,
	MEM_DEV_INT_FLASH_AXIM,

	MEM_DEV_EXT_SDRAM_FMC,
	MEM_DEV_EXT_QSPI_FLASH,
	MEM_DEV_EXT_SD_CARD,
} mem_dev_type_t;
#endif


typedef enum {
	MEM_STATUS_UNKNOWN = 0,
	MEM_STATUS_PRESENT,
	MEM_STATUS_NOT_PRESENT,
	MEM_STATUS_INIT_OK,
	MEM_STATUS_INIT_FAIL,
	MEM_STATUS_PROBE_OK,
	MEM_STATUS_PROBE_FAIL,
} mem_status_t;


/**
 * @brief Initialize non-system memory and build memory inventory
 * Must be called early in boot
 */
stratum_status_t mem_mgr_init(void);


#ifdef __cplusplus
}
#endif
