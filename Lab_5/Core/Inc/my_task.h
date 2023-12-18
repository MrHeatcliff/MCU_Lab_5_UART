/*
 * my_task.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#ifndef INC_MY_TASK_H_
#define INC_MY_TASK_H_

#include <stdio.h>
#include "my_adc.h"
#include "my_uart.h"
#include "my_define.h"

void task_toggle_led(void);
void task_send_adc_value();

#endif /* INC_MY_TASK_H_ */
