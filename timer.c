#include <avr/io.h>

#include "timer.h"

void Timer0_Init() {
	//Enable CTC timer0
	TCCR0A &= ~(1 << WGM00);
	TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM02);

	//Set prescaler to Clk/1024
	TCCR0B |= (1 << CS00) | (1 << CS02);
	TCCR0A &= ~(1 << CS01);

	//Output compare value calculated based on prescaler and period of 10ms
	OCR0A = 155;

	//Counter init 0
	TCNT0 = 0;

	//Interrupt enable
	TIMSK0 |= (1<<OCIE0A);
}

