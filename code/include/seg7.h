#include <8051.h>

#ifndef SEG7_H
#define SEG7_H

extern unsigned char show[4];

extern void seg7_init();
extern void timer(void) __interrupt (1) __using (1);

#endif // SEG7_H