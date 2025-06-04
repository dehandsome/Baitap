#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"uart_builder.h"

static UART_BUILDER* setBaudrate (UART_BUILDER* builder,uint32_t baudRate){
    if(baudRate<1200||baudRate>115200){
        printf("Eror: Invalid baudrate.must be between 1200 and 115200.\n");
        return builder;
    }
    builder->config.baudrate=baudRate;
    return builder;
}

static UART_BUILDER* setParity (UART_BUILDER* builder,uint8_t Parity){
    if(Parity>2){
        printf("Eror: Invalid parity.must be 0(None),1(Odd,2(Even)).\n");
        return builder;
    }
    builder->config.parity=Parity;
    return builder;
}
static UART_BUILDER* setStopbits (UART_BUILDER* builder,uint8_t stopBits){
    if(stopBits!=1 && stopBits!=2){
        printf("Eror: Invalid stopbits.must be 1 or 2.\n");
        return builder;
    }
    builder->config.parity=stopBits;
    return builder;
}
static UART_BUILDER* setDatabits (UART_BUILDER* builder,uint8_t dataBits){
    if(dataBits!=8 && dataBits!=9){
        printf("Eror: Invalid stopbits.must be 8 or 9.\n");
        return builder;
    }
    builder->config.parity=dataBits;
    return builder;
}
static UART_CONFIG Build (struct UART_BUILDER* builder){
    return builder->config;
}
UART_BUILDER UART_BUILDER_INIT(){
     UART_BUILDER builder;
     builder.config.baudrate =9600;
     builder.config.parity =0;
     builder.config.stopbits=1;
     builder.config.databits=8;
     builder.setbaudrate= setBaudrate;
     builder.setparity= setParity;
     builder.setstopbits=setStopbits;
     builder.setdatabits=setDatabits;
     builder.build= Build;
     return builder;
     
     
}