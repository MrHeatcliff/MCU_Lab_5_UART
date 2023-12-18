/*
 * my_uart.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Heathcliff
 */

#ifndef INC_MY_UART_H_
#define INC_MY_UART_H_

#include "my_define.h"
#include <string.h>

extern UART_HandleTypeDef huart2;
void uart_init(void);
bool uart_IsFlag(void);
void uart_ResetFlag(void);
char* uart_GetCommand(void);
bool check_command(void);

#endif /* INC_MY_UART_H_ */
