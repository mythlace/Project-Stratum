/**
 * @file mem_manager.c
 *
 * @date Mar 6, 2026
 * @author mdev 
 */

#include "mem_manager.h"
#include "sdram_test.h"
#include "platform/board_defs.h"
#include "core/error/stratum_error.h"
#include "platform/bsp/bsp_sdram.h"

/**
 *
 */
stratum_status_t mem_mgr_init(void){
	mem_status_t mem_status;

	// Init external SDRAM
	bsp_sdram_init();
	// Test external SDRAM
	mem_status = sdram_test(SDRAM_BASE, SDRAM_SIZE);
	if (mem_status != MEM_STATUS_PROBE_OK){
		stratum_panic(mem_status, __FILE__, __LINE__, "SDRAM error\n");
	}

	return STRATUM_STATUS_OK;
}

