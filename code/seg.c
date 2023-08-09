/*
    109321016
    Bo Rong Huang  at 2023/8/5
*/
#include <8051.h>


#define LED_PORT_P P1
#define LED_PORT_N P2


#define FTIME(X) (65536-(1000000/X))  //only constant
#define Hz0(X)  TH0 = (char)((FTIME(X))>>8);\
                TL0 = (char)(FTIME(X))

const unsigned char decode[16] = {0b00000011, 0b10011111, 0b00100101, 0b00001101, //0~9 : number 0~9
                                  0b10011001, 0b01001001, 0b01000001, 0b00011111, //11 : P. mean Play, 12: R. mean reverse
                                  0b00000001, 0b00001001, 0b01101100, 0b00110000,
                                  0b00010000, 0b10010000, 0b00100101, 0b11111111};


unsigned char show[4];   //LED SHOW



void timer_(void) __interrupt (1) __using (1){ 
    //Hz0(16);
    TH0 = 0;
    TL0 = 1;
    static unsigned char count = 0;
    static unsigned char playnum = 0;

    __code const unsigned char index[4] = {0xE,0xD,0xB,0x7};

    //display LED

    if(count == 0){
        LED_PORT_N = decode[playnum];
        playnum = (playnum+1)%10;
    }
    count = (count+1)%10;
    //LED_PORT_P = (LED_PORT_P & 0xF0)|index[count];
    

    
}



void main(){
    //initialize timer
    TMOD = 0x01;
    EA = 1;

    ET0 = 1;

    TH0 = 0;
    TL0 = 1;

    show[3] = decode[15];
    show[2] = decode[3];
    show[1] = decode[3];
    show[0] = decode[4];

    TR0 = 1;
    TR1 = 1;
    while(1){

    }
}