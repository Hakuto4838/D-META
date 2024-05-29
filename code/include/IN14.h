#include <8051.h>

extern unsigned char IN14_show[8];

void IN14_init(void);
void IN14_timer(void) __interrupt (1) __using (1);