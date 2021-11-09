#ifndef ADC_H
#define ADC_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

volatile uint8_t adcValue = 0;

void ADC_Init(void);

#endif //ADC_H