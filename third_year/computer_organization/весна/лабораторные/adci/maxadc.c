	   #include <reg515.h>	

int mm;
unsigned int T;
unsigned char max,min;

unsigned char adc(void); //�������� ���������� ���������������
	main()
	{  
             max=0; min=0x70;
			      while(INT0)	   //�������� INT0=0
                  { if (adc()>max) max=P2; 
	                if (adc()<min) min=P2;
                   } 				   
                  mm=(max+min)/2; //�������   	       
                  TMOD=1;
                  TH0=TL0=0;		
                  TR0=0;
                 while(adc()>=mm);	//�������� H/L  ������� �����
		TR0=1;
	    while(adc()<=mm);         //�������� L/H  ������� �����
                  TR0=0;
                  T=(TH0<<8)+TL0;
				  while(1);  //������������ �������

	}
 unsigned char adc(void)
  {  unsigned char x;
    DAPR=0;  
     while(BSY);  	//�������� ���������� ��������������
    return P2=x=ADDAT; 
		}
