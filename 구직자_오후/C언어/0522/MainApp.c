#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  0 ~ 255 사이의 정수값을 입력하면 
    그 숫자를 2진수로 변경하여 출력하는 프로그램 작성 
	 - 배열의 길이는 전처리기로 정의하여 사용합니다.
	   
*/
#define BITSIZE	9
#define MAXVALUE 0xFF
#define RED		1	
#define BLUE	2
#define GREEN	3
#define YELLO	4
#define ORANGE	5
#define WHITE	6

void ArrayEx01();
void printArray(char * bit, int size);

void TDimentionArray();
void TDTurnEx();
void ArraysAndPointer();

typedef void (* func)() ;

int main() {
	ArraysAndPointer();
	func x = ArraysAndPointer;
	x();
	return 0;
}

void ArrayEx01() {
	int nDecimal = 0;
	char bit[BITSIZE] = { 0 };
	printf("hello world");
	printf("  0 ~ 255 사이의 값을 입력하세요 > ");
	scanf("%d", &nDecimal);
	if (nDecimal > MAXVALUE)
		return;
	printf("%3d⑽ =>",nDecimal);

	for (int i = BITSIZE-2; i >=  0 ; i--) {
		bit[i] = nDecimal % 2 + '0';
		nDecimal /= 2;
	}
	printArray(bit, BITSIZE);
	printf("⑵\n");

}
// Java Integer.toBinaryString()
void printArray(char * bit, int size) {
	printf("%s\n", bit);
	for (int i = size-1; i >= 0; i--) {
		printf("%d", bit[i]);
	}
}
void TDimentionArray() {
	/* 2차원 배열 : 배열의 원소를 평면구조로 나열한 배열 */
	int tarr[3][5] = {0 };
	int arr[15] = {0};
	//8.2944 Mbyte
	int gold = 0;
	
	int CUBE[6][3][3] = { {RED},{BLUE},{GREEN},{ORANGE},{YELLO},{WHITE} };

	for (int i = 0; i < 15; i++) {
		printf("%d. arr[%2d] : %p\ttarr[% d][% d] : % p\n",i, i,arr + i, i/5, i%5, &tarr[i/5][i%5]);
	}
	system("pause");
	system("cls");
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("arr[%2d] : %p\ttarr[% d][% d] : % p\n", (i * 5) + j, &arr[(i * 5) + j] , i, j, & tarr[i][j]);
		}
	}


}
void TDTurnEx() {
	int tarr[5][5] = { 0 };
	int turned[5][5] = { 0 };

	/*
	tarr에 1 ~ 25까지의 데이터를 순서대로 입력 
	turned 2차원 배열에 tarr의 원소를 90도 회전시켜서 입력 
	*/
	

}

void ArraysAndPointer() {
	int arr[10] = { 0 };
	int tarr[5][3] = { 0 };

	int* ptr = NULL;

	ptr = arr;



	printf("tarr : %p\n", tarr);
	printf("tarr + 1 : %p\n", tarr + 1);

	printf("tarr[1] : %p\n", tarr[1]); // 간접참조 + 주소연산 == 인덱스연산
	printf("*(tarr + 1) : %p\n", *(tarr + 1));

	printf("tarr[1] : %p\n", tarr[1] + 2); // 간접참조 + 주소연산 == 인덱스연산
	printf("*(tarr + 1) : %p\n", *(tarr + 1) + 2);
	printf("&tarr[1][2] : %p\n", &tarr[1][2]);


	printf("tarr[1] : %d\n", *(tarr[1] + 2)); // 간접참조 + 주소연산 == 인덱스연산
	printf("*(tarr + 1) : %d\n", *(*(tarr + 1) + 2));
	printf("tarr[1][2] : %d\n", tarr[1][2]);

	ptr = tarr; // ptr이 가리키는 곳 에서 int  크기만큼 1칸 이동 후  ptr + 1

	int** pptr = NULL;
	int* arPtr[3] = { NULL };   // 포인터가 나열된 배열    // Pointer in Array

	int(*aptr)[5] = NULL;		// 배열을 가리키는 포인터  // Pointer for Arrays
	int(*test)() = printf;
	

	aptr = tarr;

	arPtr[0] = tarr[0];
	arPtr[1] = tarr[1];
	arPtr[2] = tarr[2];


	ptr = arr;
	ptr[0] = 100;

	(arPtr[0])[2];

	pptr = tarr;

	printf("\n\npptr : %p\n", *(pptr + 1)); // pptr이 가리키는 곳 에서 int * 크기만큼 1칸 이동 후 
	printf("tarr : %p\n", *(tarr + 1));

	printf("aptr : %p\t tarr : %p\n", aptr, tarr);
	printf("aptr+1 : %p\t tarr+1 : %p\n", aptr+1, tarr+1);
	return;
}

