#include <reg51.h>  //c ������-������� P0*P1-->P2P3
unsigned char  i;
 typedef  unsigned char uchar;
 typedef  unsigned int  uint;
typedef  unsigned long ulong;
Fd2( uchar  x){return (x>>4)*10 + (x&0x0f);}  
F2d(uchar  x){return  ((x/10)<<4) | (x%10); }
  ulong  S;
 uint Aa;
main()
{  Aa=Fd2( P0)<<8;    //Aa=P0<<8;      //���� � ������������ ��������
   S=Fd2( P1);      //S=P1;             //����,  S ��������� � ���������� B
for(i=8; i>0; i--)
     S= (S&1)?  (S+Aa)>>1 : S>>1;
  P2=F2d( S/100);    //����� �������� ����� ������������    
  P3=F2d( S%100);  //����� �������� ����� ������������
}

