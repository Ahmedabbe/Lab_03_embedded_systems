#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"
#include "state.h"

void main(void)
{
	uint8_t direction = -1;
	uint8_t pwmValue = 0;
	uint8_t state = 0;
	uint8_t counter = 0;

	Timer_Init();
	Uart_Init();
	LED_Init();
	Button_Init();
	ADC_Init();

	//Enable global interrupts
	sei();

	while (1)
	{
		/*
			Order of operations:
			- Wait for button interrupt trigger and check if button is released before debouncing
			- After 10ms debounce is complete and new state is set in method "State_change"
			- "State_handler" switches to next function in the list and it runs every timer interrupt (about 10ms)
		*/
		Button_read_released();
		State_change(&state);
		State_handler(&state, &direction, &pwmValue, &counter);
	}
}