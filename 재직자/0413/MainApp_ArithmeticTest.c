#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//(0��C �� 9/5) + 32 = 32��F
/*
	[���� �µ�]�� �Է��Ѵ�.
	���� ���İ� �Է��� �����µ��� �̿��ؼ�
	[ȭ�� �µ�]�� ���Ѵ�.
	������ �µ� ���� F�� �����ϰ�
	����Ѵ�.
	double C = 0.0, F = 0.0;
	printf("���� �µ��� �Է��ϼ��� > ");
	//75.7--> �Ǽ� ���ڷ�
	scanf("%lf", &C);

	F = C* (9.0 / 5.0) + 32.0;
	printf("%.1lf�� = %.1lf��\n", C, F);
*/
/*
	�ݾ��� �Է��Ѵ�.
	�Էµ� �ݾ��� 50000���� ���� ���� �����Ѵ� --> 5�������� ����
	�Էµ� �ݾ��� 50000���� ���� �������� �Էµ� �ݾ��� ����� ������ �ǵ����ش�.

*/
int main() {
	int Money = 0; // 5�� -> ���� -> 5õ�� -> 1000�� ���� �ٲ� ���� ������ ���� 
	int MyMoney = 0; // �Է��� ���� ������ ���� 
	int Count = 0;   // ���� ȭ���� ����,�� ���� ������ ����
	printf("�ݾ��� �Է��ϼ��� > ");
	scanf("%d", &MyMoney); // 323500
	Money = 50000;

	
	Count = MyMoney / Money;
	printf("5���� : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("���� : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("5õ�� : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("õ�� : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("500�� : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("100�� : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("50�� : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("10�� : %d\n", Count);	


	return 0;
}