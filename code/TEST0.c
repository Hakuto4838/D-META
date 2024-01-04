#include <8051.h>
 
#include "config.h"

#include "IN14.h"
#include "ds1302.h"
#include "bluetooth.h"

void main(){
    IN14_init();
    UART_start(FREQ,BAUD);
    Serialflush();  
    ES = 1;
    EA = 1;
    P0 = 0;

    while(1){

        if(uartNewLineFlag){
            ES = 0;
            switch(uartReadBuffer[0]){
            case 'A':
                Serialprint("hi");
                break;
            case 'B':
                Serialprint("hi,");
                Serialprint(uartReadBuffer+1);
                break;
            case 'C':
                unsigned char num = uartReadBuffer[2]-'0';
                unsigned char tube = uartReadBuffer[1]-'0';
                Serialprint("set");
                IN14_show[tube] = num;
                break;
            default:
                Serialprint("El Psy congroo\n");
            }
            Serialflush(); 
            ES = 1;
        }
    }
} 