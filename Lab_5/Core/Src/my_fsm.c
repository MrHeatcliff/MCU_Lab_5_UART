/*
 * my_fsm.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */


#include "my_fsm.h"

#define RST_CMD	"!RST#"
#define OK_CMD	"!OK#"
static enum {
	READ, HANDLE
} command_parser_st;
static enum {
	WAIT, SEND
} uart_communiation_st;
static bool command_flag = 0;
static char command_data[20];
static uint16_t value;
/*
 * format command
 * !COM#*/
/*
 * brief: 	command_parser_fsm
 * para: 	none
 * retval: 	none*/
void command_parser_fsm(void) {
	switch (command_parser_st) {
	case READ:
		if (uart_IsFlag()) {
			if (check_command()) {
				command_parser_st = HANDLE;
			}
			uart_ResetFlag();
		}
		break;
	case HANDLE:
		command_flag = 1;
		strcpy(command_data, uart_GetCommand());
		command_parser_st = READ;
		break;
	}
}
void uart_communiation_fsm(void) {
	switch (uart_communiation_st) {
	case WAIT:
//		value = adc_GetValue();
		if (command_flag) {
			if (!strcmp(command_data, RST_CMD)) {
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				sch_add_task(task_send_adc_value, 0, 3 * ONE_SECOND);
				uart_communiation_st = SEND;
			}
			command_flag = 0;
		}
		break;
	case SEND:
		if (command_flag) {
			if (!strcmp(command_data, OK_CMD)){
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				sch_remove_task(task_send_adc_value);
				uart_communiation_st = WAIT;
			}
			command_flag = 0;
		}
		break;
	}
}
uint16_t fsm_value(void){
	return value;
}
