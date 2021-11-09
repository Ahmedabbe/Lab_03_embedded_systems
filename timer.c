#include <avr/io.h>

#include "timer.h"

void Timer_Init()
{
	/*    TIMER 0    */

	// PWM fast mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	TCCR0B &= ~(1 << WGM02);

	//Clear OC0A on match
	TCCR0A |= (1 << COM0A1);
	TCCR2A &= ~(1 << COM0A0);

	//Set prescaler Clk/64
	TCCR0B |= (1 << CS01) | (1 << CS00);
	TCCR0A &= ~(1 << CS02);

	/*    TIMER 2    */

	//Enable CTC timer0
	TCCR2A &= ~(1 << WGM22);
	TCCR2A |= (1 << WGM21);
	TCCR2A &= ~(1 << WGM20);

	//Set prescaler Clk/1024
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	//Enable timer2 compare match interrupts 
	TIMSK2 |= (1 << OCIE2A);

	//Output compare value calculated based on prescaler and period of 10ms
	OCR2A = 155;

	//Counter init 0
	TCNT2 = 0;
}
