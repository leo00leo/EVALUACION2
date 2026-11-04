#include "stm32f103xb.h"
#include "ds1302.h"

#define CE 5
#define SCLK 7
#define IO 6
#define address
#define clk
#define fra
#define ent
int i;

void ds1302_init(){
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

GPIOA->CRL |=(0xF<<(CE*4));
GPIOA->CRL &=~(0x1<<(CE*4));

GPIOA->CRL |=(0xF<<(SCLK*4));
GPIOA->CRL &=~(0x8<<(SCLK*4));

GPIOA->CRL |=(0xF<<(IO*4));
GPIOA->CRL &=~(0x4<<(IO*4));

}

void ds1302_write(uint8_t address, uint8_t data){

GPIOA->BSRR |=(CE<<1);

for(i=0; i<=13; i++){

if((address>>i)&0x01){ 

GPIOA->BSRR |=(IO<<1);
}
else{

GPIOA->BSRR |=(IO>>1);

}

GPIOA->BSRR |=(1<<SCLK);
GPIOA->BSRR |=(0>>SCLK);
}
}

uint8_t ds1302_read(uint8_t address){

GPIOA->BSRR |=(CE<<1);

for(i=0; i<=7; i++){

if((address>>i)&0x01){ GPIOA->CRL |=(0x1<<IO);
}else{
GPIOA->BSRR |=(IO>>1);
}
GPIOA->BSRR |=(0<<SCLK);
GPIOA->BSRR |=(1<<SCLK);
}
}
void ds1302_set_time(uint8_t hora, uint8_t min, uint8_t seg){
 int hora_u = hora%10;
 int hora_d = hora/10;
 int hora_bcd = (hora_u|(hora_d<<4));
 
 int min_u = hora%10;
 int min_d = hora/10;
 int min_bcd = (hora_u|(hora_d<<4));

 int seg_u = hora%10;
 int seg_d = hora/10;
 int seg_bcd = (hora_u|(hora_d<<4));
 
}

uint8_t ds1302_get_hours(){
GPIOA->BSRR |= (0xF<<(hora_bcd*4))/10;
}
uint8_t ds1302_get_minutes(){
GPIOA->BSRR |= (0xF<<(min_bcd*4))/10;
}
uint8_t ds1302_get_seconds(){
GPIOA->BSRR |= (0xF<<(seg_bcd*4))/10;
}