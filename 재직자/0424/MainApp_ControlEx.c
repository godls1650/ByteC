#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*1.  1 ~ 100 사이의 값 중 입력한 숫자의 배수만 출력하는 프로그램 작성 */
/*2.  1 ~ 100 사이의 값 중 입력한 두 숫자의 배수만 각각 출력하는 프로그램 작성 */
/*3.  1 ~ 100 사이의 값 중 입력한 두 숫자의 공통배수를  출력하는 프로그램 작성 */
int main() {

	int firstNumber = 0;
	int secondNumber = 0;
	int range = 0;
	int count = 0;

	printf("input number > ");
	scanf("%d", &firstNumber);
	printf("input number > ");
	scanf("%d", &secondNumber);


	printf("%d의 배수 : ", firstNumber);
	for (int i = firstNumber+1; i < 100; i++) {
		if (i % firstNumber == 0)printf("%d ", i);
		count++;
	}
	printf("\n");


	printf("%d의 배수 : ", secondNumber);
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
	printf("%d회 실행 \n", count);

	printf("%d와%d 의 공배수 : ", firstNumber, secondNumber);
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
	printf("%d회 실행 \n", count);
	return 0;
}