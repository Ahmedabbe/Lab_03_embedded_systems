#include "adc.h"

/*   Global variables   */
volatile uint8_t adcValue = 0;

void ADC_Init()
{
    //Set pin A0 to input
    DDRC &= ~(1 << PC0);

    //Set left adjust, 8bit precision
    ADMUX |= (1 << ADLAR);

    //Set AVcc as voltage reference
    ADMUX |= (1 << REFS0);
    ADMUX &= ~(1 << REFS1);

    //Set prescaler 8 (Clk/8)
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
    ADCSRA &= ~(1 << ADPS2);

    //Enable ADC
    ADCSRA |= (1 << ADEN);
    
    //Enable ADC interrupts
    ADCSRA |= (1 << ADIE);
}    

ISR(ADC_vect)
{
	/*
		Triggers interrupt on finishing an ADC conversion.
		Stores converted value in variable.
	*/
	adcValue = ADCH;
}

void Potentiometer(){
	/*
		Setting ADSC bit in ADCSRA reg triggers a single ADC conversion.
		Converted ADC value is set to OCR0A (pin 6) to change the brightness (duty cycle) of led
	*/
	ADCSRA |= (1 << ADSC);
	OCR2A = adcValue;
}
