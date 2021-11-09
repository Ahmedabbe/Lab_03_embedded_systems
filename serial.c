#include <avr/io.h>

#include <stdio.h>

#include "serial.h"

static FILE uart_stdout = FDEV_SETUP_STREAM(Uart_Putchar, NULL, _FDEV_SETUP_WRITE);

void Uart_Init(void) {
	UBRR0H = (unsigned char)(UBRR >> 8);
	UBRR0L = (unsigned char)(UBRR);
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0 | 1 << RXEN0);
	UCSR0C = (1 << UCSZ01 | 1 << UCSZ00);

	stdout = &uart_stdout;
}

int Uart_Putchar(char chr, FILE *stream) {
	if (chr == '\n') {
		Uart_Putchar('\r', NULL);
	}
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = chr;
	return 0;
}

char Uart_Getchar(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}

