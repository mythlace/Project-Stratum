/**
 * @file platform_conf.h
 *
 * @date Mar 16, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

// Supported boards
#define STM32F769I_DISO			1

/**
* @def TARGET_BOARD
* @brief Defines the target board
*/
#define TARGET_BOARD			STM32F769I_DISCO

/**
* @def CONSOLE_UART_HANDLE
* @brief Handle of UART used for console
*
*/
#define CONSOLE_UART_HANDLE 	huart1


#define FMC_SDRAM1_HANDLE 		hsdram1

#ifdef __cplusplus
}
#endif
