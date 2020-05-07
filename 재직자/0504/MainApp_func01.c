#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE	255
/*	함수 
	여러번 사용하는 코드 등 
	 -> 동작을 구현

	 <함수의 선언부> 
	 함수의 결과의 타입 : 반환타입
	 함수의 명칭 : 동작을 단어(문장으)로 정한다. 
	 함수가 실행하기 전 알아야하는 데이터 : 매개변수 

	 <함수 정의부>
	 함수 선언부 + 내용을 정의한 블록

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


	printf("hello world를 출력한 결과 : %d\n", printf("hello world\n"));

	// 전체적인 동작을 구현 
	srand((unsigned int)time(NULL));
	// 배열에 1 ~ 100 까지 난수 10개 입력 
	inputRandArray(arr, 10, 1, 100);
	printArray(arr, 10);

	inputRandArray(arr2, 20, 20, 39);
	printArray(arr2, 20);

	// 배열을 출력하는 부분
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");



	printf("1. 총점 문제 \n2.명함출력\nselect > ");
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
	const char* text[5] = { "국어", "영어", "수학", "사회", "과학" };

	for (int i = 0; i < 5; i++) {
		printf("%s점수 > ", text[i]);
		scanf("%d", &score);
		total += score;
	}
	average = (double)total / 5;
	printf("총점 : %d 점\n평균 : %.2lf\n",total , average);

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