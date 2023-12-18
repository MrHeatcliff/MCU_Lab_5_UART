/*
 * my_uart.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Heathcliff
 */
#include "my_uart.h"

#define MAX_BUFFER_SIZE		30

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
bool buffer_flag = 0;
uint8_t start_cmd_index = 0;
uint8_t end_cmd_index = 0;
bool flag_end = 0;
bool flag_start = 0;

static char command[10];

bool uart_IsFlag(void) {
	return buffer_flag;
}
void uart_ResetFlag(void) {
	buffer_flag = 0;
}
/*
 * @brief: Check if we have receive a command by check 2 flag start and end
 * @param: none
 * @retval: 1 if we have command, 0 if we dont*/
bool check_command(void){
	if(flag_start && flag_end){
		if(start_cmd_index <= end_cmd_index){
			uint8_t size = end_cmd_index - start_cmd_index + 1;
			memcpy(command, buffer + start_cmd_index, size);
			command[size] = '\0';
		} else{
			uint8_t size = MAX_BUFFER_SIZE - start_cmd_index;
			memcpy(command, buffer + start_cmd_index, size);
			memcpy(command + size, buffer, end_cmd_index + 1);
			command[size+end_cmd_index + 1] = '\0';
		}
		return 1;
	}
	return 0;
}
/*
 * @brief: function to get command and reset index
 * @param: none
 * @retval: pointer to command array*/
char* uart_GetCommand(void) {
	for(unsigned i = 0; i <= end_cmd_index; i++){
		buffer[i] = '\0';
	}
	start_cmd_index = 0;
	end_cmd_index = 0;
	flag_start = 0;
	flag_end = 0;
	return command;
}

void uart_init(void){
	HAL_UART_Receive_IT (&huart2 , &temp , 1) ;
}

void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart ){
	if(huart -> Instance == USART2){
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		if(temp == '!'){
			start_cmd_index = index_buffer;
			flag_start = 1;
		} else if(temp == '#'){
			end_cmd_index = index_buffer;
			flag_end = 1;
		}
		buffer[index_buffer++] = temp;
		index_buffer %= MAX_BUFFER_SIZE;
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}
