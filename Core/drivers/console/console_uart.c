/**
 * @file console_uart.c
 *
 * @date Mar 5, 2026
 * @author mdev 
 */

#include <stdio.h>
#include <string.h>
#include "console_uart.h"

/**
 * @brief Initialize UART console
 */
void console_uart_init(void){
	// Force unbuffered stdout
	setvbuf(stdout, NULL, _IONBF, 0);
}

/**
 * @brief Custom implementation of _write
 *
 * @param file File descriptor (unused)
 * @param buffer Pointer to write buffer
 * @param len Length of data to be written (bytes)
 *
 * @return int Number of bytes actually written
 *
 */
int _write(int file, char *buffer, int len) {
	char tx_buffer[CONSOLE_UART_TX_BUFFER_SIZE];
	int chunk_length = 0, write_length = 0;
	while (write_length < len) {
		// Compute length of remaining data
		chunk_length = len - write_length;
		// Compute chunk length
		if (chunk_length > (CONSOLE_UART_TX_BUFFER_SIZE - 1)){
			chunk_length = CONSOLE_UART_TX_BUFFER_SIZE - 1;
		}
		// Copy data to local buffer
		memcpy(tx_buffer, &buffer[write_length], chunk_length);
		// Terminate string
		tx_buffer[chunk_length] = '\0';
		// Send the data
		HAL_UART_Transmit(CONSOLE_UART_BASE, (uint8_t *)tx_buffer, strlen(tx_buffer), HAL_MAX_DELAY);
		// Update write length
		write_length += chunk_length;
	}
	return write_length;
}
