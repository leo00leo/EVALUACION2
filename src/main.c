#include "stm32f103xb.h"
#include "ds1302.h"


uint8_t ds1302_get_hours(){

valor= GPIOA->BSRR |= (0xF<<(hora_bcd*4))/10;

}
uint8_t ds1302_get_minutes(){

valor=GPIOA->BSRR |= (0xF<<(min_bcd*4))/10;
}

uint8_t ds1302_get_seconds(){

valor=GPIOA->BSRR |= (0xF<<(seg_bcd*4))/10;
}
