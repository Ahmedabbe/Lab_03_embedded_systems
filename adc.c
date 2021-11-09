#include "adc.h"

void ADC_Init()
{
    //Set left adjust, 8bit precision
    ADMUX |= (1 << ADLAR);

    //Set AVcc as voltage reference
    ADMUX |= (1 << REFS0);

    //Enable ADC
    ADCSRA |= (1 << ADEN);

    //Enable ADC interrupts
    ADCSRA |= (1 << ADIE);

    //Set prescaler 8 (Clk/8)
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
}