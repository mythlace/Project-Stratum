/**
 * @file sdram_test.h
 *
 * @date Mar 6, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "mem_manager.h"

mem_status_t sdram_test(uint32_t base, uint32_t size);

#ifdef __cplusplus
}
#endif
