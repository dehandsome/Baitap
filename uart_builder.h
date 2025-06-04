#ifdef UART_BUILDER_H
#define UART_BUILDER_H

#include<stdint.h>

typedef struct 
{
     uint32_t baudrate;
     uint8_t parity;
     uint8_t stopbits;
     uint8_t databits; 
}UART_CONFIG;

typedef struct UART_BUILDER
{
    UART_CONFIG config ;
    struct UART_BUILDER*(*setbaudrate)(struct UART_BUILDER*,uint32_t);
    struct UART_BUILDER*(*setparity)(struct UART_BUILDER*,uint8_t);
    struct UART_BUILDER*(*setstopbits)(struct UART_BUILDER*,uint8_t);
    struct UART_BUILDER*(*setdatabits)(struct UART_BUILDER*,uint8_t);
    UART_CONFIG (*build)(struct UART_BUILDER*);
}UART_BUILDER;

UART_BUILDER UART_BUILDER_INIT();

#endif