#include <8051.h>

#include "IN14.h"
#include "config.h"
#include "ds3231.h"
#include "rand.h"
#include "bluetooth.h"


#define Hz 2000

#define FTIME(X) (65536-(1000000/X))  //only constant
#define Hz0(X)  TH0 = (char)((FTIME(X))>>8);\
                TL0 = (char)(FTIME(X))

unsigned char IN14_show[8];
unsigned char IN14_target[8];
unsigned char IN_14_showDOT;
unsigned char DMETA_mod=0;
UCHAR jp;

void IN14_init(void){
    TMOD = (T1_GATE&TMOD)|0x01;
    Hz0(Hz);
    TR0 = 1;
    ET0 = 1;
    EA = 1;
}

const UCHAR tubecount[] = {0,0,0,1,2,2,3,4,4,4,5,5,5,6,6,7};
void IN14_timer(void) __interrupt (1) __using (1){
    //管子編號|顯示數字
    Hz0(Hz);

    static unsigned char count = 0;
    UCHAR tube = tubecount[count];
    char num = IN14_show[tube]&0x0F;
    IN14_PORT = (tube<<4)|num;
    IN_14_DOT = (IN_14_showDOT>>tube)&1;

    count = (count+1)&15;


    static unsigned short mod_count = 0;
    if(++mod_count >= Hz/20){
        switch(DMETA_mod){
            case DMETA_MOD_CLOCK:
                read_time();  
                IN14_show[0] = ((hour>>4)<3)?(hour>>4):IN14_show[0];
                IN14_show[1] = ((hour&0x0f)<10)?(hour&0x0f):IN14_show[1] ;
                IN14_show[2] = 10;
                IN14_show[3] = ((minute>>4)<6)?(minute>>4):IN14_show[3] ;
                IN14_show[4] = ((minute&0x0f)<10)?(minute&0x0f):IN14_show[4] ;
                IN14_show[5] = 10;
                IN14_show[6] = ((second>>4)<6)?(second>>4):IN14_show[6] ;
                IN14_show[7] = ((second&0x0f)<10)?(second&0x0f):IN14_show[7] ;
                IN_14_showDOT = 0b00100100;
                break;
            case DMETA_MOD_TEMP:
                read_temperature();
                IN14_show[0] = temHIGH/10;
                IN14_show[1] = temHIGH%10;
                IN14_show[2] = temLOW;
                IN14_show[3] = 10;

                read_aging();
                IN14_show[4] = aging / 100;
                IN14_show[5] = (aging/10) % 10;
                IN14_show[6] = aging % 10;
                IN_14_showDOT = 0b00000010;
                break;
            case DMETA_MOD_JUMP:
                IN_14_showDOT = 0b00000010;
                read_temperature();
                IN14_show[1] = 10;
                UCHAR i=0;
                for(;i<8;i++){
                    if(i!=1){
                        if((jp>>i)&1){
                            IN14_show[i] = randB();
                            if(randB()==temLOW)if(randB()>5) jp &= ~(1<<i);
                        }else{
                            IN14_show[i] = IN14_target[i];
                        }
                    }
                }
                if(jp==0) {
                    DMETA_mod = DMETA_MOD_DMETA;
                    for(i=0; i<8; i++)IN14_show[i] = IN14_target[i];
                }
                break;
            case DMETA_MOD_DMETA:
                static UCHAR old_temp;
                static UCHAR dt_count=0;
                static UCHAR finddiver = 0;
                read_temperature();
                if(old_temp != temLOW){
                    old_temp = temLOW;
                    dt_count++;
                    if(old_temp)randB();
                    if(dt_count == 100){
                        dt_count = 0;
                        IN14_target[finddiver++] = randB();
                        SerialprintBCD(finddiver);
                    }
                }

                if(finddiver==8){
                    if(randB()<8){
                        if(IN14_target[0] == randB()) IN14_target[0] = 10;
                        IN14_target[0] = (randB() <2)?10:IN14_target[0]&1;
                        IN14_target[1] = 10;
                        jp = 0b11111101;
                        DMETA_mod = DMETA_MOD_JUMP;
                        Serialprint("Jump!\n");
                    }
                    finddiver = 0;
                    
                }
                
                break;

        }
        mod_count = 0;
    }

}

