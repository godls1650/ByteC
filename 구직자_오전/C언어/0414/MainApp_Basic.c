#include <stdio.h>
/*
# : ��ó���� --> ����� �ٲٱ� ���� ���� ��Ų��.
include �����ϴ�.
<> : ���� ���� �ܺ� 
STanDard Input Output .Header

���α׷��� ���� , �Լ� ���� 
  ���� -> ���� -> ���(ȣ��)
  // ���α׷��� ���� ���� 
    �޸� �Ҵ��� ������
     -> main()�� ã�´�. 
*/
// ���� ���� 

// ���� , ���
// default type : �⺻������ Ÿ�� 

int main() { // {} -> �Լ�  ���
    // ���� ����
    // �������·� �������� �����ϴ� ������ �����.
    int ElectricPay = 0; // %d %o %x   %u %ul  %ull
    float fData = 0.0f; // %f  %e  %a
    double dData = 0.0; // %lf  %le  %la
    printf("���� ����� %d�� �Դϴ�.\n", ElectricPay);

    ElectricPay = 12300; // ���
    printf("���� ����� %d�� �Դϴ�.\n", ElectricPay);
   
    fData = 3.141592f;
    dData = 3.141592;
    printf("float : %f\n%e\n%a\n", fData, fData, fData);
    printf("double : %lf\n%le\n%la\n", dData, dData, dData);
    


	printf("hello world\n");// print _ formatting
    puts("hello world");

	return 0;
}