#include <8051.h>
 
#include "config.h"

#include "IN14.h"
#include "bluetooth.h"
#include "ds3231.h"
#include "i2c.h"
#include "rand.h"

#define CLK_H SCL=1
#define CLK_L SCL=0
#define SDA_H SDA=1
#define SDA_L SDA=0

__bit kb_clk_ready;

void main(void){
    IN14_init();
    UART_start(FREQ,BAUD);
    Serialflush();
    kb_clk_ready = 0; 
    ES = 1;
    EA = 1;
    P0 = 0;
    unsigned char dot;
    unsigned char num;
    unsigned char tube;

    // IN_14_showDOT = 0b00000010;
    // IN14_show[0] = 1;
    // IN14_show[1] = 10;
    // IN14_show[2] = 0;
    // IN14_show[3] = 4;
    // IN14_show[4] = 8;
    // IN14_show[5] = 5;
    // IN14_show[6] = 9;
    // IN14_show[7] = 6;
    LED_blue = 0;

    DMETA_mod = DMETA_MOD_CLOCK;

    while(1){
        if(kb_clk_ready && (KEB_clk==1)){
            UCHAR input = ((KEB>>1)&0x0F);
            LED_blue = (input&1);
            SerialprintBCD(input);
            Serialprint("\n");
            kb_clk_ready = 0;
            IN14_show[0] = input;
        }
        if(KEB_clk == 0){
            kb_clk_ready = 1;
            wait(1);
        } 
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

                SerialprintBCD(date);
                Serialprint("/");
                SerialprintBCD(month);
                Serialprint("/");
                SerialprintBCD(year);

                Serialprint(" tem=");
                read_temperature();
                SerialprintCHAR(temHIGH);
                Serialprint("+");
                SerialprintCHAR(temLOW);
                Serialprint("\n");
                break;
            case 't': //HHMMSS
                hour     = ((uartReadBuffer[1]-'0')<<4) + (uartReadBuffer[2]-'0');
                minute   = ((uartReadBuffer[3]-'0')<<4) + (uartReadBuffer[4]-'0');
                second   = ((uartReadBuffer[5]-'0')<<4) + (uartReadBuffer[6]-'0');
                write_time();
                break;
            case 'd': //YYMMDDW
                year    = ((uartReadBuffer[1]-'0')<<4) + (uartReadBuffer[2]-'0');
                month   = ((uartReadBuffer[3]-'0')<<4) + (uartReadBuffer[4]-'0');
                date    = ((uartReadBuffer[5]-'0')<<4) + (uartReadBuffer[6]-'0');
                day     = uartReadBuffer[7]-'0';
                write_date(); 
                break;
            case 'm':
                DMETA_mod = uartReadBuffer[1]-'0';
                break;
            case 'c':
                dot = uartReadBuffer[3]-'0'; 
                num = uartReadBuffer[2]-'0';
                tube = uartReadBuffer[1]-'0';
                Serialprint("set"); 
                IN14_show[tube] = num;
                IN_14_showDOT = dot;
                LED_blue = dot;
                
                break;
            case 'j':
                if(uartReadBuffer[1]=='a'){
                    IN14_target[0] = uartReadBuffer[2]-'0';
                    IN14_target[1] = 10;
                    IN14_target[2] = uartReadBuffer[3]-'0';
                    IN14_target[3] = uartReadBuffer[4]-'0';
                    IN14_target[4] = uartReadBuffer[5]-'0';
                    IN14_target[5] = uartReadBuffer[6]-'0';
                    IN14_target[6] = uartReadBuffer[7]-'0';
                    IN14_target[7] = uartReadBuffer[8]-'0';
                }else{
                    IN14_target[0] = randB()%2;
                    IN14_target[1] = 10;
                    IN14_target[2] = randB();
                    IN14_target[3] = randB();
                    IN14_target[4] = randB();
                    IN14_target[5] = randB();
                    IN14_target[6] = randB();
                    IN14_target[7] = randB();

                }
                jp = 0b11111101;
                DMETA_mod = DMETA_MOD_JUMP;
                Serialprint("jump\n");
                break;
            default:
                Serialprint("El Psy congroo\n");
            }
            Serialflush();
            ES = 1;
        }

    }
} 