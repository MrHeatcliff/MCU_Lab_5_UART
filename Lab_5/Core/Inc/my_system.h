/*
 * my_system.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#ifndef INC_MY_SYSTEM_H_
#define INC_MY_SYSTEM_H_

#include "my_scheduler.h"
#include "my_define.h"
#include "my_fsm.h"
#include "my_uart.h"
#include "my_task.h"

extern TIM_HandleTypeDef htim2;
void init(void);
void loop(void);

#endif /* INC_MY_SYSTEM_H_ */
