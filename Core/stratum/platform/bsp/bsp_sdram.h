/**
 * @file bsp_sdram.h
 *
 * @date Mar 16, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "platform/platform_conf.h"

#if TARGET_BOARD == STM32F769I_DISCO

#define SDRAM_REFRESH_COUNT	((uint32_t)0x0603)
#define SDRAM_TIMEOUT		((uint32_t)0xFFFF)

/**
* @brief  FMC SDRAM Mode definition register defines
*/
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

#endif

void bsp_sdram_init(void);

#ifdef __cplusplus
}
#endif
