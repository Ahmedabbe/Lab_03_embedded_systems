#ifndef _STATE_H_
#define _STATE_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdbool.h>

/*  from timer.h  */
extern volatile bool button_released;
extern volatile bool state_handler_timer;
extern volatile bool debounced;
//

void State_change(uint8_t *);
void State_handler(uint8_t *, uint8_t *, uint8_t *, uint8_t *);



#endif //_STATE_H