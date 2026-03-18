/**
 * @file stratum_error.c
 *
 * @date Mar 8, 2026
 * @author mdev 
 */

#include <stdio.h>
#include "stratum_error.h"



void stratum_panic(stratum_status_t error, const char *file, uint32_t line, const char *msg){

	// TODO: Disable interrupts and peripherals

	// TODO: Print errors on display

	// Print errors on console
	printf("\n*** STRATUM PANIC ***\n");
	printf("Error: %d\n", error);
	printf("File : %s\n", file);
	printf("Line : %lu\n", line);
	if(msg) {
		printf("Msg  : %s\n", msg);
	}

	// Never return
	while (1) {

	}
}
