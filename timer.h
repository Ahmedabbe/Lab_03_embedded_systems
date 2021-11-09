#ifndef _TIMER_H_
#define _TIMER_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdbool.h>

volatile bool button_released;
volatile bool debounced;
volatile bool state_handler_timer;

void Timer_Init(void);

#endif // _TIMER_H_
