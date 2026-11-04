#define DS1302_H
#ifndef DS1302_H
#include "stm32f103xb.h"

void ds1302_init();

void ds1302_write(uint8_t address, uint8_t data);

uint8_t ds1302_read(uint8_t address);

void ds1302_set_time(uint8_t hora, uint8_t min, uint8_t seg);

uint8_t ds1302_get_hours();
uint8_t ds1302_get_minutes();
uint8_t ds1302_get_seconds();

#endif