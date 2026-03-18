/**
 * @file stratum_init.c
 *
 * @date Mar 16, 2026
 * @author mdev 
 */

#include "stratum_init.h"
#include "platform/console/console_uart.h"
#include "platform/memory/mem_manager.h"
#include <stdio.h>

/**
 * Note: Don't return errors, handle within.
 */
stratum_status_t stratum_init(void){
	console_uart_init();
	printf("\n\n-----\n");
	printf("Stratum initializing ...\n");

	mem_mgr_init();


	printf("Stratum initialization complete\n");
	return STRATUM_STATUS_OK;
}
