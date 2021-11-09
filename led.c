#include "led.h"

void LED_Init()
{
	DDRB |= (1 << PB3); // Set digital pin 6 as outpout
}

uint8_t Simple_ramp(uint8_t *direction, uint8_t *pwmValue)
{
	//Change direction when either min or max values are reached
	if (*pwmValue >= 255 || *pwmValue <= 0)
	{
		*direction *= -1;
	}

	//imcrement or decrement value based on direction
	*pwmValue += *direction;

	//return new value
	return *pwmValue;
}

void Led_blink(uint8_t *counter)
{
	//"counter" delays led toggle to about 1Hz
	(*counter)++;
	if (*counter >= 50)
	{
		if (OCR2A == 255) //Blink off
			OCR2A = 0;
		else
			OCR2A = 255; //Blink on
		*counter = 0;
	}
}
