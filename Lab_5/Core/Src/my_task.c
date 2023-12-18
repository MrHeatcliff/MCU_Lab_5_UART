/*
 * my_task.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#include "my_task.h"

void task_toggle_led(void){
	HAL_GPIO_TogglePin(LED_OUTPUT_PORT, LED_OUTPUT_PIN);
}

void task_send_adc_value(){
	char str[100];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!ADC=%d#\n",adc_get_value()), 1000);
}

