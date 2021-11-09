#ifndef ADC_H
#define ADC_H

#include <avr/pgmspace.h>
#include <avr/interrupt.h>

volatile uint8_t adcValue;

void ADC_Init(void);
void Potentiometer(void);

#endif //ADC_H