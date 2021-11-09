#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"

void main(void)
{	
	bool last_state = false;

	Button_Init();
	LED_Init();
	Uart_Init();
	Timer0_Init();
	sei();

	while (1)
	{
		if(timer_interrupt) Button_print_state(&last_state);
	}
}
