#ifndef __DS3231_H__
#define __DS3231_H__

#include "config.h"
#include <8051.h>

#define DS3231_Address      0xD0
#define DS3231_Write        0xD0
#define DS3231_Read         0xD1

#define addr_second              0x00
#define addr_minute              0x01
#define addr_hour                0x02
#define addr_day                 0x03
#define addr_date                0x04
#define addr_month               0x05
#define addr_year                0x06
#define addr_control             0x0E
#define addr_status              0x0F
#define addr_aging               0x10
#define addr_temperature         0x11

extern UCHAR second,minute,hour,day,date,month,year;
extern UCHAR temHIGH, temLOW;

extern void SetPtr_ds3231(UCHAR address);
extern UCHAR Read_ds3231(UCHAR address);
extern void Write_to_ds3231(UCHAR address, UCHAR value);


extern void read_time(void);
extern void read_date(void);
extern void write_time(void);
extern void write_date(void);
extern void read_temperature(void);


#endif //__DS3231_H__