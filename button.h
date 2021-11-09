#ifndef BUTTON_H
#define BUTTON_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdbool.h>

volatile bool button_interrupt;
volatile bool timer_interrupt;

void Button_Init();
void Button_print_state(bool *);
void flip_boolean_last_state(bool *);
void reset_interrupts(void);

#endif //BUTTON_H