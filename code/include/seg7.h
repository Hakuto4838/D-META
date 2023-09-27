#include <8051.h>

extern unsigned char show[4];

void seg7_init();
void timer(void) __interrupt (1) __using (1);