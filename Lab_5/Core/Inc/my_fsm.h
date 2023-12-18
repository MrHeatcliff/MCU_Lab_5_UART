/*
 * my_fsm.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#ifndef INC_MY_FSM_H_
#define INC_MY_FSM_H_

#include<stdio.h>
#include<string.h>
#include "my_define.h"
#include "my_scheduler.h"
#include "my_uart.h"
#include "my_adc.h"
#include "my_task.h"

void command_parser_fsm ();
void uart_communiation_fsm ();
void task_toggle_led(void);
void task_send_adc_value();

#endif /* INC_MY_FSM_H_ */
