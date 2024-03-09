#include "lcd.h"

void LCD_WriteData(uint8_t dt)
{
	if(((dt>>7)&1)==1) {d7_set();} else {d7_reset();}
	if(((dt>>6)&1)==1) {d6_set();} else {d6_reset();}
	if(((dt>>5)&1)==1) {d5_set();} else {d5_reset();}
	if(((dt>>4)&1)==1) {d4_set();} else {d4_reset();}
	if(((dt>>3)&1)==1) {d3_set();} else {d3_reset();}
	if(((dt>>2)&1)==1) {d2_set();} else {d2_reset();}
	if(((dt>>1)&1)==1) {d1_set();} else {d1_reset();}
	if(((dt)&1)==1) {d0_set();} else {d0_reset();}
}

void delay(void)
{
	uint16_t i;
	for(i=0;i<2000;i++)
	{
	}
}

void SendByte(uint8_t dt, int rs)
{
	if (rs==0){rs_reset();}
	else {rs_set();}
	delay();
	e_set();
	delay();
	LCD_WriteData(dt);
	delay();
	e_reset();
}


void LCD_init(void)
{
	HAL_Delay(50);
	for(int i=0; i<3; i++)
	{
		SendByte(0x30, 0);
		HAL_Delay(5);
	}
	SendByte(0x3C, 0);
	delay();
	SendByte(0x08, 0);
	delay();
	SendByte(0x01, 0);
	delay();
	SendByte(0x04, 0);
	delay();
	SendByte(0x0F, 0);
	delay();
}
