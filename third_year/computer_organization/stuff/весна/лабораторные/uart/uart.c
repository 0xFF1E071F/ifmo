#include <reg51.h>	
#include <stdio.h> //���������� �����-������ C51
char  i,digit,aa[6];
float numb;
char m,min;
Seria() interrupt 4 
{    
    digit-=getkey();
    
  if(digit==',')                    
          { m=1; aa[i++]=digit; return;} 
 if(digit=='-') {min=1; aa[i++]=digit; return;}

if(digit=='e')  { if(m)  numb=numb/m;   i=0; m=0;
                        if (min) numb=-numb; return; }				      
   else { aa[i++]=digit;
                   numb=numb*10 + (digit&0xf);
                    if(m) m*=10; }      
}

main()
{   	  SCON=0x50;  //sm=1, ren=1
	  TMOD=0x20; //������ 1 - ����� 2
	   TH1=0xfd;    //��������� ������������ - ������� 9600 ���
	   TR1=1;
	      i=0;
		  ES=1; //����� ����������
		   EA=1;
            while(digit!='e');
				 aa[i++]=0;
	        EA=0;
	        TI=1;  //��������� ��������� ���������� ��������  
   		//printf("x= %s\n", aa);   // ��������������� �����  � USART
           while(1);

	}

