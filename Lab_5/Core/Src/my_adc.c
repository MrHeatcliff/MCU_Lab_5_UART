/*
 * my_adc.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Heathcliff
 */

#include "my_adc.h"

extern ADC_HandleTypeDef hadc1;
uint16_t adc_get_value(void){
	uint16_t ADC_value = 0;
	ADC_value = HAL_ADC_GetValue(&hadc1);
	return ADC_value;
}

void adc_init(void) {
	HAL_ADC_Start(&hadc1);
}
