/**
 * @file console_uart.h
 *
 * @date Mar 5, 2026
 * @author mdev 
 */

#pragma once
#ifdef __cplusplus
 extern "C" {
#endif


/**
 * @def CONSOLE_UART_TX_BUFFER_SIZE
 * @brief Size of UART TX buffer (bytes)
 *
 */
#define CONSOLE_UART_TX_BUFFER_SIZE	256

/**
 * @brief Initialize UART console
 */
void console_uart_init(void);

#ifdef __cplusplus
}
#endif
