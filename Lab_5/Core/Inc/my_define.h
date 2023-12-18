/*
 * my_define.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Heathcliff
 */

#ifndef INC_MY_DEFINE_H_
#define INC_MY_DEFINE_H_

#include "main.h"

//define led output port and pin
#define LED_OUTPUT_PORT	GPIOA
#define LED_OUTPUT_PIN	GPIO_PIN_5

//define uart and DC
#define UART_PORT	GPIOA
#define RXD_PIN		GPIO_PIN_2
#define TXD_PIN		GPIO_PIN_3
#define ADC_PIN		GPIO_PIN_0

//define boolean type
typedef uint8_t bool;

#endif /* INC_MY_DEFINE_H_ */
