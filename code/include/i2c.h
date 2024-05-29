#include "config.h"
#include <8051.h>

extern void Stop_I2C(void);
extern void Start_I2C(void);

extern void Write_I2C(unsigned char byte);
extern unsigned char Read_I2C(void);

extern void Read_Ack(void);
extern void Send_NACK(void);
extern void send_ACK(void);
