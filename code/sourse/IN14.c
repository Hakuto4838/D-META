#include <8051.h>

#include "IN14.h"
#include "config.h"

#define FTIME(X) (65536-(1000000/X))  //only constant
#define Hz0(X)  TH0 = (char)((FTIME(X))>>8);\
                TL0 = (char)(FTIME(X))

unsigned char IN14_show[8];


void IN14_init(){
    TMOD = (T1_GATE&TMOD)|0x01;
    Hz0(500);
    TR0 = 1;
    ET0 = 1;
    EA = 1;
}

void IN14_timer(void) __interrupt (1) __using (1){
    //管子編號|顯示數字
    Hz0(500);

    static unsigned char count = 0;
    char num = IN14_show[count]&0x0F;
    IN14_PORT = (count<<4)|num;

    count = (count+1)%8;
}

