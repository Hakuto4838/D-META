#include <8051.h>

#define DMETA_MOD_CLOCK 0
#define DMETA_MOD_TEMP  1
#define DMETA_MOD_DMETA 2
#define DMETA_MOD_JUMP  3

extern unsigned char IN14_show[8];
extern unsigned char IN14_target[8];
extern unsigned char IN_14_showDOT;
extern unsigned char jp;
extern unsigned char DMETA_mod;

void IN14_init(void);
void IN14_timer(void) __interrupt (1) __using (1);