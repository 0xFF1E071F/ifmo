
 SIGNAL void pwm (unsigned int Time) { 
 
//twatch(4*Time);  //������������� �������� ��� �������������  � �������� ������� ���������� ������� pwm( ) � �������� ���������
while(1)
{         // ������������ ���������, ���������������  ���� 
          //  P3.i = 1  ,  i=0..5  , S1=6
P3 = 0; twatch (Time); 
  P3 = 0x3f; twatch (2*Time);

P3 = 0; twatch (2*Time);
  P3 = 0x3f; twatch (Time);

P3 = 0; twatch (Time); 
  P3 = 0x3f; twatch (2*Time);

P3 = 0; twatch (2*Time);
  P3 = 0x3f; twatch (Time);

P3 = 0; twatch (Time); 
  P3 = 0x3f; twatch (2*Time);

P3 = 0; twatch (2*Time);
  P3 = 0x3f; twatch (Time);

P3 = 0; twatch (Time); 
  P3 = 0x3f; twatch (2*Time);

P3 = 0; twatch (2*Time);
  P3 = 0x3f; twatch (Time);

P3=0;
twatch(10*Time);
 }
}

pwm(100)                

La  port3           
