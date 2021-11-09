#include "timer.h"

/*   Global variables   */
volatile bool button_released = false;
volatile bool debounced = false;
volatile bool state_handler_timer = false;

void Timer_Init()
{
	/*    TIMER 0    */

	//Enable CTC timer0
	TCCR0A &= ~(1 << WGM00);
	TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM02);

	//Set prescaler 1024 (Clk/1024)
	TCCR0B |= (1 << CS00) | (1 << CS02);
	TCCR0A &= ~(1 << CS01);

	//Output compare value calculated based on prescaler and period of 10ms
	OCR0A = 155;

	//Counter init 0
	TCNT0 = 0;

	//Interrupt enable
	TIMSK0 |= (1 << OCIE0A);

	/*    TIMER 2    */

	//Set PWM fast mode
	TCCR2A |= (1 << WGM21);
	TCCR2A |= (1 << WGM20);
	TCCR2B &= ~(1 << WGM22);

	//Set clear om match, non inverting mode
	TCCR2A |= (1 << COM2A1);
	TCCR2A &= ~(1 << COM2A0);

	//Set prescaler 64 (Clk/64)
	TCCR2B |= (1 << CS20) | (1 << CS21);
	TCCR2B &= ~(1 << CS22);
}

ISR(TIMER0_COMPA_vect)
{
    if (button_released)
    {
        debounced = true; // Set true before state can be printed
        button_released = false;
    }
    state_handler_timer = true;
}