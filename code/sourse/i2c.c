#include "config.h"
#include <8051.h>

#include "i2c.h"
// #include "bluetooth.h"

void Start_I2C(void){
    Stop_I2C();
    SCL = 0;
    SDA = 1;
    SCL = 1;
    SDA = 0;
}

void Stop_I2C(void){
    SCL = 0;
    SDA = 0;
    SCL = 1;
    SDA = 1;
}

void Read_Ack(void){
    SCL = 0;
    SDA = 1;
    SCL = 1;
    // Serialprint("wait...");
    while(SDA);
    // Serialprint("ack!\n");
}

void Send_NACK(void){
    SCL = 0;
    SDA = 1;
    SCL = 1;
}

void Write_I2C (unsigned char byte){
    UCHAR k;
    // Serialprint("SDA send ");
    for(k=0; k<8; k++){
        SCL = 0;
        SDA = (0x80>>k)&byte;
        SCL = 1;
        // if(SDA) Serialprint("1");
        // else Serialprint("0");
    }
    SCL = 0;
    SDA = 1;
    // Serialprint("\n");
}

unsigned char Read_I2C(void){
    UCHAR temp = 0;
    UCHAR i;
    for(i=0; i<8; i++){
        SCL = 0;
        SCL = 1;
        temp = temp<<1;
        if(SDA) temp++;
    }
    for(i=0; i<255; i++);
    for(i=0; i<255; i++);
    return temp;
}

void send_ACK(void){
    SCL = 0;
    SDA = 0;
    SCL = 1;
    SCL = 0;
    SDA = 1;
}