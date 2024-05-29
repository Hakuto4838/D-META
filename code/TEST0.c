#include <8051.h>
 
#include "config.h"

#include "IN14.h"
#include "bluetooth.h"
#include "ds3231.h"
#include "i2c.h"

#define CLK_H SCL=1
#define CLK_L SCL=0
#define SDA_H SDA=1
#define SDA_L SDA=0

void main(void){
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
            case 'N':
                read_time();  

                SerialprintBCD(hour);
                Serialprint(":");
                SerialprintBCD(minute);
                Serialprint(":");
                SerialprintBCD(second);

                Serialprint(" tem=");
                read_temperature();
                SerialprintCHAR(temHIGH);
                Serialprint("+");
                SerialprintCHAR(temLOW);
                Serialprint("\n");
                break;
            case 'T': //HHMMSS
                hour     = ((uartReadBuffer[1]-'0')<<4) + (uartReadBuffer[2]-'0');
                minute   = ((uartReadBuffer[3]-'0')<<4) + (uartReadBuffer[4]-'0');
                second   = ((uartReadBuffer[5]-'0')<<4) + (uartReadBuffer[6]-'0');
                write_time();
                break;
            case 'D': //YYMMDDW
                year    = ((uartReadBuffer[1]-'0')<<4) + (uartReadBuffer[2]-'0');
                month   = ((uartReadBuffer[3]-'0')<<4) + (uartReadBuffer[4]-'0');
                date    = ((uartReadBuffer[5]-'0')<<4) + (uartReadBuffer[6]-'0');
                day     = uartReadBuffer[7]-'0';
                write_date();
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