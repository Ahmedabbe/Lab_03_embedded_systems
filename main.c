#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"

ISR(ADC_vect)
{
	/*
		Triggers interrupt on finishing an ADC conversion.
		Stores converted value in variable.
	*/
	adcValue = ADCH;
}

ISR(TIMER2_COMPA_vect)
{
	/*
		Triggers interrupt on timer2 output compare match.
		Setting ADSC bit in ADCSRA reg triggers a single ADC conversion.
		Converted ADC value is set to OCR0A (pin 6) to change the brightness (duty cycle) of led
	*/
	ADCSRA |= (1 << ADSC);
	OCR0A = adcValue;
}

void main(void)
{
	LED_Init();
	Timer_Init();
	ADC_Init();

	//Enable global interrupts
	sei();

	while (1)
	{
		printf_P(PSTR("%d\n"), adcValue);
	}
}
