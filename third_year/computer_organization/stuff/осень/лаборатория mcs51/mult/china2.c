	 #include <reg51.h>
#include <intrins.h> //���������� ��������
sbit Bi=B^0;        //��� �������� B
 typedef  unsigned char uchar;
 typedef  unsigned int  uint;
typedef  unsigned long ulong;
Fd2( uchar  x){return (x>>4)*10 + (x&0x0f);}  
F2d(uchar  x){return  ((x/10)<<4) | (x%10); }

char  i;
char Aa;              //�����������

main(){
char  wrk=Fd2(P0);  //wr ��������
Aa=0;         //reset
 B=Fd2(P1);              //wr ���������
for(i=-8;i!=0;i++)    //wr i,  i+1
 {
  if(Bi) Aa=Aa+wrk;
 Aa=_cror_(Aa,1); 
           B=cror_(B,1);}
P2=F2d(Aa); P3=F2d(B);
 }

