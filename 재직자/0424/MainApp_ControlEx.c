#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*1.  1 ~ 100 ������ �� �� �Է��� ������ ����� ����ϴ� ���α׷� �ۼ� */
/*2.  1 ~ 100 ������ �� �� �Է��� �� ������ ����� ���� ����ϴ� ���α׷� �ۼ� */
/*3.  1 ~ 100 ������ �� �� �Է��� �� ������ ��������  ����ϴ� ���α׷� �ۼ� */
int main() {

	int firstNumber = 0;
	int secondNumber = 0;
	int range = 0;
	int count = 0;

	printf("input number > ");
	scanf("%d", &firstNumber);
	printf("input number > ");
	scanf("%d", &secondNumber);


	printf("%d�� ��� : ", firstNumber);
	for (int i = firstNumber+1; i < 100; i++) {
		if (i % firstNumber == 0)printf("%d ", i);
		count++;
	}
	printf("\n");


	printf("%d�� ��� : ", secondNumber);
	for (int i = secondNumber + 1; i < 100; i++) {
		if (i % secondNumber == 0)printf("%d ", i);
		count++;
	}
	printf("\n");
	for (int i = (secondNumber * firstNumber); i < 100; i++) {
		if (i % secondNumber == 0 && i % firstNumber == 0)
			printf("%d ", i);
		count++;
	}
	printf("%dȸ ���� \n", count);

	printf("%d��%d �� ����� : ", firstNumber, secondNumber);
	for (int i = firstNumber * secondNumber; i < 100; i++) {
		if (i % (firstNumber * secondNumber) == 0)printf("%d ", i);
		count++;
	}
	printf("\n");

	count = 0;
	range = 100 / firstNumber;
	for (int i = 2; i <= range; i++) {
		printf("%2d ", firstNumber * i);
		count++;
	}
	printf("\n");
	range = 100 / secondNumber;
	for (int i = 2; i <= range; i++) {
		printf("%2d ", secondNumber * i);
		count++;
	}
	printf("\n");

	range = 100 / (firstNumber*secondNumber);
	for (int i = 2; i <= range; i++) {
		printf("%2d ", firstNumber*secondNumber * i);
		count++;
	}
	printf("\n");
	printf("%dȸ ���� \n", count);
	return 0;
}