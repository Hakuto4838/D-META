#include <8051.h>

#include "config.h"

#include "seg7.h"
#include "ds1302.h"
#include "uart.h"


DS1302_DATETIME time;  

extern unsigned char count;

void main(){
    seg7_init();
    ds1302_start();
    UART_start(FREQ,BAUD);
    //Serialbegin_value(217);
    Serialflush();  
    setSerialinterrupt();
    

     
    while(1){
        // ds1302_get_datetime(&time);
        // show[0] = time.minute/10;
        // show[1] = time.minute%10;
        show[2] = count/10;
        show[3] = count%10;
        //Serialprint("hi\n");
        if(uartNewLineFlag){
            count++;
            Serialprint(uartReadBuffer);
            Serialflush();
        }
    }
} 