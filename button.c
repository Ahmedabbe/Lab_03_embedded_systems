#include "button.h"

/*   Global variables   */
volatile bool button_interrupt = false;

void Button_Init()
{
    DDRD &= ~(1 << PD2); // Set digital pin 2 to input

    //Enable external pin (button) interrupt activated on a falling edge
    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC00);
    EIMSK |= (1 << INT0);
}

void Button_read_released()
{
    /*
        When a button interrupt triggers, 
        button pin "PD2" is checked below for when it is released (pin = 0)
    */
    if (button_interrupt)
    {
        if (!(PIND & (1 << PD2)))
        {
            button_released = true;
            button_interrupt = false; // Re-enables button interrupts to change boolean

            TCNT0 = 0; // Timer0 restart count
        }
    }
}

ISR(INT0_vect)
{
    if (!button_interrupt)
    {
        // Set true to prevent further triggers before state updated
        button_interrupt = true;
    }
}