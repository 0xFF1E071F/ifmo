#include <reg51.h>
typedef unsigned int u16; 
typedef unsigned char u8;
typedef unsigned long u32;
u32 N;

u16 fd2(u8 x){    //������� 10/2 ���� ���� � ������� m=2^8   
	u16 y=((((x&0xf0)>>4)*10 + (x&0x0f))<<8);     
   return ((y/100)<<8)|(y%100) ; }
    
u8 f2d(u16 y){    //������� �� int 2/10  ���� ������� ���� m=2^8 
u16 yy,zz;
	 y=(y*10);
     yy=((y&0xf00)>>4);
	 zz= ((y&0xff)*10);
	 yy|=((zz&0xf00)>>8);
return (yy<<8)|(zz&0xff);
    }

main()
{   u16 z=fd2(P1);
    u16 y=fd2(P0);   // (y%100).(y/100)
    while(1)
    { 

	N= (y&0xff00) + ((((y&0xff)<<8)+(z&0xff00))>>8); //������� � ������� m=(2^16)

	y=f2d(N>>8);
	P2=y>>8;		// P0
	P3=f2d((y+N)&0xff);		//P1           	 
     }    
}
