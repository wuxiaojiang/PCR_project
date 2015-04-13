//-------------------------------------------------
//程序名：DS18B20温度传感器驱动
//作 者：吴晓疆
//日 期：2015/4/11
//-------------------------------------------------
#include<reg52.h>
#include<intrins.h>
#include<math.h>
#include<5110.h>
#include<stdio.h>
#include<uart_com.h>
#define uchar unsigned char
#define uint unsigned int
int temp; 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
sbit ds=P1^0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void delay(uint i);
void  ds_init();
bit readbit();
void ds_wait();
uchar readbyte();
void writebyte(uchar dat);
void sendchangecmd();
void sendreadcmd();
int get_tmp();
void display(int v);
void  send(int v);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void delay(uint i)
{
uint j;
while(i--)
{
  for(j=0;j<125;j++);
}
}
//**************************************************
void ds_init()
{
uint i;
ds = 0;
i = 100;
while(i>0)i--;
ds = 1;
i=4;
while(i>0)i--;
}
//**************************************************
void ds_wait()
{
uint i;
while (ds) ;
while(~ds);
i=4;
while(i>0)i--;
}
//**************************************************
bit readbit()
{
uint i;
bit b;
ds = 0;
i++;
ds = 1;
i++;
i++;
b = ds;
i = 8;
while(i>0)i--;
return b;
}
//******************************
uchar readbyte()
{
uint i;
uchar j,dat;
dat=0;
for(i=0;i<8;i++)
{
j=readbit();
dat = (j<<7)|(dat>>1);
}
return dat;
}
//*********************************
void writebyte(uchar dat)
{
	uint i;
	uchar j;
	bit b;
	for(j = 0;j<8;j++){
		b = dat&0x01;
		dat>>=1;
		if(b){
			ds = 0;
			i++;i++;
			ds = 1;
			i=8;
			while(i>0)i--;
		}
		else{
			ds=0;
			i=8;while(i>0)i--;
			ds=1;
			i++;i++;
		}
	}
}
//*************************************
void sendchangecmd()
{
ds_init();
ds_wait();
delay(1);
writebyte(0xcc);
writebyte(0x44);
}
//************************************
void sendreadcmd()
{
ds_init();
ds_wait();
delay(1);
writebyte(0xcc);
writebyte(0xbe);
}
//*************************************
int get_tmp()
{
uint temp;
int value;
float t;
uchar low,high;
sendreadcmd();
low = readbyte();
high = readbyte();
temp = high;
temp<<=8;
temp|=low;
value = temp;
t = value*0.0625;
value = t*100+(value>0?0.5:-0.5);
//value-=40;
return value;
}
//***************************************
void display(int v)
{
 uint t;
uint tmp = abs(v);
t = tmp/1000;
LCD_write_num(9,4,t,1);
t = (tmp%1000)/100;
LCD_write_num(10,4,t,1);
t = (tmp%100)/10;
LCD_write_num(12,4,t,1);
t = tmp%10;
LCD_write_num(13,4,t,1);
}
//*****************************************
void  send(int v)
{
uint tmp = abs(v);
tmp/=100;
InitUartComm(12,9600);
Send_Comm(tmp);
}
