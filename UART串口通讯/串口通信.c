#include<reg52.h>
#include<uart_com_temp.h>

sbit P20=P2^0;
sbit P10=P1^0;

void delay(unsigned int nN);

void main()
{
	//unsigned char chRcv;
	unsigned int i;
	//unsigned int  t;
	unsigned int cs = 1;
	for (i=0;i<100;i++)
	{
	InitUartComm(12,9600);
    Send_Comm(cs);
	cs++;
	delay(5);}
	delay(500);
}
void delay(unsigned int nN)
{
	unsigned int a,b,c;
	for(a=0;a<nN;a++)
		for(b=0;b<50;b++)
			for(c=0;c<50;c++);
} 