#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <mcs51/8051.h>

#define LED_PORT_N P0 
#define LED_PORT_P P2

#define DS1302_SCK P1_0
#define DS1302_SDA P1_1
#define DS1302_RST P1_2

#define FREQ 11059200
#define BAUD 9600

#endif // __CONFIG_H__