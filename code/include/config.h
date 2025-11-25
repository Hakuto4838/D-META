#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <mcs51/8051.h>

#define UCHAR unsigned char

#define LED_PORT_N P0 
#define LED_PORT_P P2
#define IN14_PORT P0 //管子編號|顯示數字

#define IN_14_DOT P1_4 //LDP 1.3 RDP1.4
#define LED_blue P1_5

#define SCL P1_1 // for DS3231 
#define SDA P1_0

#define KEB_clk P2_0
#define KEB     P2

#define FREQ 11059200 
#define BAUD 9600

 
#endif // __CONFIG_H__