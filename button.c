#include "button.h"

void Button_Init()
{
    DDRD &= ~(1 << PD2); // Set digital pin 2 to input

    //Enable external pin (button) interrupt activated on a falling edge
    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC00);
    EIMSK |= (1 << INT0);
}

ISR(INT0_vect)
{
    if (!button_interrupt)
    {
        // Resets timer for a full count of 10ms
        TCNT0 = 0;

        // Set true to prevent timer from reseting before state is printed
        button_interrupt = true;
    }
}

ISR(TIMER0_COMPA_vect)
{
    if (button_interrupt)

        timer_interrupt = true; // Set true before state can be printed
}

void Button_print_state(bool *last_state)
{
    /*
        Check if pushed when button pin is high and last_state set to false
        released when vice versa
    */
    if (PIND & (1 << PD2) && !*last_state)
    {
        printf_P(PSTR("pushed\r\n"));

        // Flips boolean last_state from false to true
        flip_boolean_last_state(last_state);
    }
    else if (!(PIND & (1 << PD2)) && *last_state)
    {
        printf_P(PSTR("released\r\n"));

        // Flips boolean last_state from true to false
        flip_boolean_last_state(last_state);
        reset_interrupts();
    }
}

void flip_boolean_last_state(bool *last_state)
{
    *last_state = !*last_state;
}

void reset_interrupts()
{
    // Resets values after a full push/release cycle to handle button interrupts and prints again
    timer_interrupt = false;
    button_interrupt = false;
}