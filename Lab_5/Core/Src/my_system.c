/*
 * my_system.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#include "my_system.h"

void init(void)
{
	sch_init();
	uart_init();
	adc_init();
	sch_add_task(task_toggle_led, 0, 500);
	sch_add_task(command_parser_fsm, 0, 10);
	sch_add_task(uart_communiation_fsm, 0, 10);
}


void loop(void)
{
	sch_dispatch();
}
