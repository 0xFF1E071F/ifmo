 SIGNAL void Signa (unsigned int Time) {
twatch (Time);  //�������� Time  ��� ��� ������� f0=12���
while (1) {
PORT3 = 0x3f;
twatch (Time);
PORT3 = 0;
twatch (2*Time);
} }

Signa(1000) //������ �������
La PORT3 //����� ������� � �����������
