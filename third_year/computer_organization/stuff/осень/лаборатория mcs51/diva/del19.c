
#include <reg51.h>
#include <intrins.h>
char Aa, wrk,B,i; 
main()
{ 
  Aa=P0; //�������
  B= P1;       //�������� 
  C=0;  
if (Aa>=wrk){OV=1; goto out;} //�������� ������������ � ����������.
  for (i=0 ; i<8; i++ ) 
    { _crol_(Aa,1);
      if(Aa>=wrk) {  C=1;_crol_(B,1);
               Aa=(Aa -wrk) : }
     }                          
out:
P3=B; //�������
if (OV) P3=0xff;  
}
