#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE	255
/*	�Լ� 
	������ ����ϴ� �ڵ� �� 
	 -> ������ ����

	 <�Լ��� �����> 
	 �Լ��� ����� Ÿ�� : ��ȯŸ��
	 �Լ��� ��Ī : ������ �ܾ�(������)�� ���Ѵ�. 
	 �Լ��� �����ϱ� �� �˾ƾ��ϴ� ������ : �Ű����� 

	 <�Լ� ���Ǻ�>
	 �Լ� ����� + ������ ������ ���

*/

void starPrint();
void printPersonal(char * pName, char * pAddress, int * pBirth);
void printNameCard(char* pName, char* pAddress, int* pBirth);
void Example01();
void NameCardEx01();

void inputRandArray(int * ptr, int size, int min, int max);
void printArray(const int* ptr, int size);

int factorial(int num); //

double circleArea(double r) {
	const double pi = 3.141592;

	return r * r * pi;
}

int main() {
	
	double circle = circleArea(4.0);
	int r = factorial(5);
	int arr[10] = { 0 };
	int arr2[20] = { 0 };
	int menu = 0;


	printf("hello world�� ����� ��� : %d\n", printf("hello world\n"));

	// ��ü���� ������ ���� 
	srand((unsigned int)time(NULL));
	// �迭�� 1 ~ 100 ���� ���� 10�� �Է� 
	inputRandArray(arr, 10, 1, 100);
	printArray(arr, 10);

	inputRandArray(arr2, 20, 20, 39);
	printArray(arr2, 20);

	// �迭�� ����ϴ� �κ�
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");



	printf("1. ���� ���� \n2.�������\nselect > ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		Example01();
		break;
	case 2: 
		NameCardEx01();
		break;
	}
	
	return 124246;
}

int factorial(int num) {
	int result = 0;
	result = 1;
	for (int i = 1; i <= 5; i++) {
		result *= i;
	}
	return result;
}




void inputRandArray(int* ptr, int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % (max - min + 1) + min;
	}

}



void printArray(const int* ptr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");
}


void NameCardEx01() {
	char* Name = "Hong Gil-Dong";
	char* Address = "DaeJeon SeoGu DunSan-dong 235-17";
	int birth[3] = { 1990,3,8 };
	int arr[3] = { 1234,12,12 };

	printNameCard(Name, Address, birth);
	printNameCard("test", "where", arr);
}

void Example01() {
	int score = 0;
	int total = 0; 
	double average = 0.0;
	const char* text[5] = { "����", "����", "����", "��ȸ", "����" };

	for (int i = 0; i < 5; i++) {
		printf("%s���� > ", text[i]);
		scanf("%d", &score);
		total += score;
	}
	average = (double)total / 5;
	printf("���� : %d ��\n��� : %.2lf\n",total , average);

}

void printNameCard(const char* pName, const char* pAddress, int* pBirth) {
	starPrint();
	printPersonal(pName, pAddress, pBirth);
	starPrint();

}

void printPersonal(char* pName, char* pAddress, int* pBirth) {
	printf("%-8s : %s\n", "Name", pName);
	printf("%-8s : %s\n", "Address", pAddress);
	printf("%-8s : %4d - %2d - %2d\n", "Birth", pBirth[0], pBirth[1], pBirth[2]);
}

void starPrint() {
	for (int i = 0; i < 40; i++)
		printf("*");
	printf("\n");
	return;
}