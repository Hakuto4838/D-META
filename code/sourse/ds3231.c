#include "config.h"
#include <8051.h>

#include "ds3231.h"
#include "i2c.h"

UCHAR second,minute,hour,day,date,month,year;
UCHAR temHIGH, temLOW, aging;

void SetPtr_ds3231(UCHAR address){
    Start_I2C();
    Write_I2C(DS3231_Write);
    Read_Ack();
    Write_I2C(address);
    Read_Ack();
    Stop_I2C();
}

UCHAR Read_ds3231(UCHAR address){
    SetPtr_ds3231(address);
    UCHAR value=0; //讀取
    Start_I2C();
    Write_I2C(DS3231_Read);
    Read_Ack();

    value = Read_I2C();
    Stop_I2C();
    return value;
}

void Write_to_ds3231(UCHAR address, UCHAR value){
    Start_I2C();
    Write_I2C(DS3231_Write);
    Read_Ack();

    Write_I2C(address);
    Read_Ack();

    Write_I2C(value);
    Read_Ack();

    Stop_I2C();
}

void read_time(void) __using (2){
    EA = 0;
    SetPtr_ds3231(addr_second);

    Start_I2C();
    Write_I2C(DS3231_Read); Read_Ack();
    second = Read_I2C();    send_ACK();
    minute = Read_I2C();    send_ACK();
    hour = Read_I2C();
    Stop_I2C();
    EA = 1;
}

void read_date(void){
    SetPtr_ds3231(addr_day);

    Start_I2C();
    Write_I2C(DS3231_Read); Read_Ack();
    day   = Read_ds3231(addr_day  );    send_ACK();
    date  = Read_ds3231(addr_date );    send_ACK();
    month = Read_ds3231(addr_month);    send_ACK();
    year  = Read_ds3231(addr_year );    Stop_I2C();
}

void write_time(void){
    Write_to_ds3231(addr_hour   ,hour  );
    Write_to_ds3231(addr_minute ,minute);
    Write_to_ds3231(addr_second ,second);
}

void write_date(void){
    Write_to_ds3231(addr_day   ,day    );
    Write_to_ds3231(addr_date  ,date   );
    Write_to_ds3231(addr_month ,month  );
    Write_to_ds3231(addr_year  ,year   );
}

void read_temperature(void){
    SetPtr_ds3231(addr_temperature);

    Start_I2C();
    Write_I2C(DS3231_Read);
    Read_Ack();

    temHIGH = Read_I2C();    send_ACK();
    temLOW = Read_I2C();     Stop_I2C();
    temLOW = temLOW>>6;
}

void read_aging(void){
    SetPtr_ds3231(addr_aging);

    Start_I2C();
    Write_I2C(DS3231_Read);
    Read_Ack();

    aging = Read_I2C();     Stop_I2C();

}