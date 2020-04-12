/* 
Date        : 2020-04-01 _1st_
ProjectName : CProject_200410
File Name   : MainApp_Floating.c

memo :       Float type / Double type    
*/
#include <stdio.h>
/* Float 

  n = n + 1
  n += 1
  n++
  Python
*/
int main(void) {
	int nNumber = 0;    // int ������ ���� 
	float fData = 0.0f; // float�� ����
	double dData = 0.0; // double�� ����
	short snNumber = 0; // short Ÿ�� ����
	long lnNumber = 0L; // long Ÿ�� ���� 
	
	//����, ������Ÿ���� ũ�⸦ Ȯ�� : sizeof( �����̸�, Ÿ�� )����
	printf("nNumber �� ũ�� : %d byte\n",sizeof(nNumber)); // sizeof������ ����� ���´�.
	printf("fData �� ũ�� : %d byte\n", sizeof(fData));
	printf("dData �� ũ�� : %d byte\n", sizeof(dData));
	printf("snNumber �� ũ�� : %d byte\n", sizeof(snNumber));
	printf("lnNumber �� ũ�� : %d byte\n", sizeof(lnNumber));

	fData = 0.00123456789f;
	dData = 0.00123456789;
	// �Ҽ����� ��� �� �� ���� : %f  %e   %lf  %le  %a %la
	printf("fData = %f\n", fData);
	printf("dData = %lf\n", dData);
	printf("fData = %e\n", fData);
	printf("dData = %le\n", dData);

	double result = 0.0;
	nNumber = 4;
	dData = 3.141592;
	// ����ȯ ����    �ٲٰ��� �ϴ� ���� X
	//    (double)X
	result = ((double)nNumber * (double)nNumber) * dData;
	printf("�������� %d �� ���� ���� : %lf\n", nNumber, result);

	int number2 = 0;
	for (int i = 1; i <= 5; i++)
		number2 = number2 * i;
	

	
	return 0;
}
