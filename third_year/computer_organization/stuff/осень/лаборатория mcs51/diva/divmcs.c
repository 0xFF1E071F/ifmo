   #include <reg51.h>
#include <intrins.h> //���������� ��������
sbit Bi=B^0;        //��� �������� B

char  i;
char Aa;              //�����������

main(){
char  wrk=P0;  //wr ��������
Aa=0;         //reset
 B=P1;              //wr ���������
for(i=-8;i!=0;i++)    //wr i,  i+1
 {if(Bi) Aa=Aa+wrk;
 Aa=_cror_(Aa,1); B=cror_(B,1);}
 P2=Aa; P3=B;
 }
