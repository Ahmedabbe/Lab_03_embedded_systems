#ifndef BUTTON_H
#define BUTTON_H

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdio.h>

volatile bool button_interrupt;

/*  from timer.h  */
extern volatile bool button_released;
//

void Button_Init(void);
void Button_read_released(void);

#endif //BUTTON_H