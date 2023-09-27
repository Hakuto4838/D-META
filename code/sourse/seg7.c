#include <8051.h>

#include "seg7.h"
#include "config.h"

#define FTIME(X) (65536-(1000000/X))  //only constant
#define Hz0(X)  TH0 = (char)((FTIME(X))>>8);\
                TL0 = (char)(FTIME(X))

unsigned char show[4];

const unsigned char decode[16] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, //0~9 : number 0~9
                                  0b10011001, 0b10010010, 0b10000010, 0b11111000, //11 : P. mean Play, 12: R. mean reverse
                                  0b10000000, 0b10010000, 0b00110110, 0b00001100,
                                  0b00001000, 0b00001001, 0b00100101, 0b11111111};

void seg7_init(){
    TMOD = (T1_GATE&TMOD)|0x01;
    Hz0(500);
    TR0 = 1;
    ET0 = 1;
    EA = 1;
}

void timer(void) __interrupt (1) __using (1){
    Hz0(500);
    __code const unsigned char index[4] = {0xE,0xD,0xB,0x7};
    static unsigned char count = 0;

    LED_PORT_N = decode[show[count]];
    LED_PORT_P = (LED_PORT_P & 0xF0)|index[count];

    count = (count+1)%4;
}

