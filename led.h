#ifndef _LED_H_
#define _LED_H_

#include <avr/pgmspace.h>

void LED_Init(void);

uint8_t Simple_Ramp(void);
void Led_blink(uint8_t *);

#endif // _LED_H_
