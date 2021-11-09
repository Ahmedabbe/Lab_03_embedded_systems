#include <avr/io.h>
#include "led.h"

void LED_Init() {
	DDRD |= (1 << PD6); // Set digital pin 6 as outpout 
}

uint8_t Simple_Ramp() {
	// ...
}
