	#include <reg515.h>	

int mm;
unsigned int T;
unsigned char max,min,x;
float fmax;

unsigned char adc(void); //��������������� �������


	main()
	{  
	
             max=0; min=0x70; P3=0x7F;
	        while(INT0)    //�������� INT0=P3.2pin==0
                  { adc();
				   if (P2>max) max=P2; 
	                if (P2<min) min=P2;
                   } 				   
                  mm=(max+min)/2; //������� ��������  	       
                  TMOD=1;
                  TH0=TL0=0;		
                  TR0=0;
                 while(adc()>=mm);	
                 while(adc()<=mm);	      //�������� L/H  ������� �����
		  TR0=1;
	          while(adc()>=mm);         //�������� H/L  ������� �����
                  TR0=0;
                  T=(TH0<<8)+TL0;
				  fmax= max*5.0/0x100;
		while(1);  //������������ �������
	}

unsigned char adc()
  { DAPR=0;       //������ �������������� c ������� ����������� 5�
    while(BSY);  //�������� ��� ���������� ��������������
	 P2=ADDAT;  //������ ���������� � ������������� ��� � P3 ��� �����������
	return P2;	}
 
