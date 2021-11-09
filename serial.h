#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

void Uart_Init(void);

int Uart_Putchar(char chr, FILE *stream);

char Uart_Getchar(void);

#endif

