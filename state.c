#include "state.h"

void State_change(uint8_t *state)
{ /* 
        States only change after:
        1) a button interrupt trigger occurs 
        2) followed up by a timer trigger after 10ms for debouncing
        3) lastly if debounced = true and button pin is still low
    */
    if (debounced && (!(PIND & (1 << PD2))))
    {
        debounced = false; //Resets for interrupts

        //Cycles state between 0-3
        if (*state == 3)
        {
            *state = 0;
        }
        else
        {
            (*state)++;
        }
    }
}

void State_handler(uint8_t *state, uint8_t *direction, uint8_t *pwmValue, uint8_t *counter)
{
    /* 
        Def: led is set to 0 brightness
        C1: pulses led between min and max value
        C2: control duty cycle/brightness using a potentiometer
        C3: blink led on and off at about 1Hz
    */

    if (state_handler_timer) //Keeps state_handler from running more than once every 10ms
    {
        state_handler_timer = false; //Reset timer

        switch (*state)
        {
        default:
            OCR2A = 255;
            break;
        case 1:
            OCR2A = Simple_ramp(direction, pwmValue);
            break;
        case 2:
            Potentiometer();
            break;
        case 3:
            Led_blink(counter);
            break;
        }
    }
}