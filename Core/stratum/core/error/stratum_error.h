/**
 * @file stratum_error.h
 *
 * @date Mar 8, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "core/stratum_defs.h"

/**
 * @def STRATUM_ASSERT
 */
#define STRATUM_ASSERT(cond) \
	do { \
		if(!(cond)) { \
			stratum_panic(STRATUM_ERR_ASSERTION, __FILE__, __LINE__, "Assertion failed!"); \
		} \
	} while(0)


/**
 *
 */
void stratum_panic(stratum_status_t error, const char *file, uint32_t line, const char *msg);

#ifdef __cplusplus
}
#endif
