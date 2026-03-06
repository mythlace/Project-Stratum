/**
 * @file console_uart.h
 *
 * @date Mar 5, 2026
 * @author mdev 
 */

#ifndef DRIVERS_CONSOLE_CONSOLE_UART_H_
#define DRIVERS_CONSOLE_CONSOLE_UART_H_

#include "main.h"

/** @brief Handle of UART in use */
extern UART_HandleTypeDef 			huart1;

/*
 * @def CONSOLE_UART_BASE
 * @brief Address of UART handle
 *
 */
#define CONSOLE_UART_BASE			(&huart1)

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


#endif /* DRIVERS_CONSOLE_CONSOLE_UART_H_ */
