#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	while : ������ ������ �� ���� �ݺ�
	for  : �ʱⰪ�� ������ ���� ���� �ϴµ��� �ݺ�

	��й�ȣ 5ȸ Ʋ���� ���� ��� --> for �ݺ�
	�ٿ�ε� �� �޾����� ������ �ε�ȭ�� 
*/
int main() {
	int num = 0;
	int result = 0;
	int bMinus = 0;
	while (!bMinus) {
		printf("input number > ");
		scanf("%d", &num);

		if (num > 0) {
			result += num;
		}
		else {
			bMinus = 1;
		}
	}
	int piv = 0;
	int p = 0; // prev
	int pp = 0; // prev prev
	int end = 100;
	//   
	pp = 1;
	p = 0; //(0)     1   1  2  3  5
	while (1){
		piv = p + pp;
		if (piv < end)
			printf("%d ", piv);
		else
			break;
		pp = p;
		p = piv;
	}
	
	return 0;
}


/*
	int num = 0;// 1 ~ 100 ���� �þ ����
	int num2 = 0; // 0���� ¦���� �þ ����
	int result = 0;
	// 1 ~ 100 ���� ¦���� �ջ�
	while (num <= 100) {
		if (num % 2 == 0) {
			result = result + num;
			printf("%d ", num);
		}
			//continue; // ���� �� ��� ����
		num++;
	}
	printf("\n¦�� ���� : %d\n", result);
	//¦�� ���� : 2550
	result = 0;
	num = 0;
	while (num <= 100) {
		result = result + num;
		printf("%d ", num);
		num = num + 2;
	}
	printf("\n¦�� ���� : %d\n", result);
	*/