#include"ds18b20.h"

int main(void)
{
LCD_init();
LCD_clear();
while(1)
{
uchar i;
LCD_write_english_string(3,0,"WXJ_PCR");
LCD_write_english_string(0,2,"TIME=");
LCD_write_num(5,2,31,2);
LCD_write_english_string(7,2,":");
LCD_write_num(8,2,43,2);
LCD_write_english_string(0,4,"NOW TEMP=");
LCD_write_english_string(0,3,"AIM TEMP=");
LCD_write_num(9,3,97,2);
LCD_write_english_string(11,4,".");
LCD_write_english_string(0,5,"COUNT=");
LCD_write_num(6,5,13,2);
LCD_write_english_string(8,5,":");
LCD_write_num(9,5,35,2);
temp = get_tmp();
sendchangecmd();
for(i=0;i<40;i++)
{
display(temp);
send(temp);
}

}
}