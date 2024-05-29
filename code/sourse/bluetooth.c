#include "bluetooth.h"
#include <8051.h>

volatile __bit                  uartNewLineFlag;
volatile unsigned char  uartReadBuffer[UART_RX_BUFFER_SIZE];
volatile unsigned char  uartReadCount;
volatile unsigned char  uartReadByte;
volatile unsigned char  str_temp[5];

void Serialbegin_value(unsigned char autoReloadvalue)
{
    TMOD  = (TMOD&T0_MASK)|0x20; //use timer1，auto reload mode
    SCON  |= 0x50; // Serial Port Control Register

    TL1    = autoReloadvalue;
    TH1    = autoReloadvalue;

    TR1    = 1;
}

void Serialwrite(unsigned char Byte){ //寫入 1 Byte
    EA = 0;
    SBUF = Byte;
    while(!TI);
    TI   = 0;
    EA = 1;
}

void Serialprint(unsigned char *sPtr){ //寫入1str
    for(;*sPtr!='\0';Serialwrite(*(sPtr++)));
}

void Serialflush(void){
    unsigned char i;
    uartReadCount    = 0;           // Clear Uart Byte Count
    uartNewLineFlag  = 0;           // Clear New Line Flag
    uartReadByte     = CHAR_NULL;   // Clear Last Read Byte

    for(i=0;i<=UART_RX_BUFFER_SIZE;i++)
        uartReadBuffer[i] = CHAR_NULL;
}

void uartISR(void) __interrupt (4) __using (2){
    EA = 0;                                      // Disable Global Interrupt Flag
    RI = 0;                                      // Clear RI flag
    uartReadByte = SBUF;                         // Read Byte from SBUF
    uartReadBuffer[uartReadCount++] = uartReadByte;
    if(uartReadByte == LF)
        uartNewLineFlag = 1;
    EA = 1;                                     // Everything is done , Now Enable the Global Interrupt
}

void SerialprintCHAR(char number){
    unsigned char i=0;
    if(number&0x80){
        str_temp[i++] = '-';
        number = (~number)+1;
    }
    if(number >= 100)
        str_temp[i++] = '0'+ (number/100);
    if(number >= 10)
        str_temp[i++] = '0' + ((number/10)%10);
    str_temp[i++] = '0' + number%10;  
    str_temp[i++] = '\0';
    Serialprint(str_temp);
}

void SerialprintBCD(unsigned char BCD){
    str_temp[0] = '0' + (BCD>>4);
    str_temp[1] = '0' + (BCD&0x0F);
    str_temp[2] = '\0';
    Serialprint(str_temp);
}