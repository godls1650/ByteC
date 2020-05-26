#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  0 ~ 255 ������ �������� �Է��ϸ� 
    �� ���ڸ� 2������ �����Ͽ� ����ϴ� ���α׷� �ۼ� 
	 - �迭�� ���̴� ��ó����� �����Ͽ� ����մϴ�.
	   
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
	printf("  0 ~ 255 ������ ���� �Է��ϼ��� > ");
	scanf("%d", &nDecimal);
	if (nDecimal > MAXVALUE)
		return;
	printf("%3d�� =>",nDecimal);

	for (int i = BITSIZE-2; i >=  0 ; i--) {
		bit[i] = nDecimal % 2 + '0';
		nDecimal /= 2;
	}
	printArray(bit, BITSIZE);
	printf("��\n");

}
// Java Integer.toBinaryString()
void printArray(char * bit, int size) {
	printf("%s\n", bit);
	for (int i = size-1; i >= 0; i--) {
		printf("%d", bit[i]);
	}
}
void TDimentionArray() {
	/* 2���� �迭 : �迭�� ���Ҹ� ��鱸���� ������ �迭 */
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
	tarr�� 1 ~ 25������ �����͸� ������� �Է� 
	turned 2���� �迭�� tarr�� ���Ҹ� 90�� ȸ�����Ѽ� �Է� 
	*/
	

}

void ArraysAndPointer() {
	int arr[10] = { 0 };
	int tarr[5][3] = { 0 };

	int* ptr = NULL;

	ptr = arr;



	printf("tarr : %p\n", tarr);
	printf("tarr + 1 : %p\n", tarr + 1);

	printf("tarr[1] : %p\n", tarr[1]); // �������� + �ּҿ��� == �ε�������
	printf("*(tarr + 1) : %p\n", *(tarr + 1));

	printf("tarr[1] : %p\n", tarr[1] + 2); // �������� + �ּҿ��� == �ε�������
	printf("*(tarr + 1) : %p\n", *(tarr + 1) + 2);
	printf("&tarr[1][2] : %p\n", &tarr[1][2]);


	printf("tarr[1] : %d\n", *(tarr[1] + 2)); // �������� + �ּҿ��� == �ε�������
	printf("*(tarr + 1) : %d\n", *(*(tarr + 1) + 2));
	printf("tarr[1][2] : %d\n", tarr[1][2]);

	ptr = tarr; // ptr�� ����Ű�� �� ���� int  ũ�⸸ŭ 1ĭ �̵� ��  ptr + 1

	int** pptr = NULL;
	int* arPtr[3] = { NULL };   // �����Ͱ� ������ �迭    // Pointer in Array

	int(*aptr)[5] = NULL;		// �迭�� ����Ű�� ������  // Pointer for Arrays
	int(*test)() = printf;
	

	aptr = tarr;

	arPtr[0] = tarr[0];
	arPtr[1] = tarr[1];
	arPtr[2] = tarr[2];


	ptr = arr;
	ptr[0] = 100;

	(arPtr[0])[2];

	pptr = tarr;

	printf("\n\npptr : %p\n", *(pptr + 1)); // pptr�� ����Ű�� �� ���� int * ũ�⸸ŭ 1ĭ �̵� �� 
	printf("tarr : %p\n", *(tarr + 1));

	printf("aptr : %p\t tarr : %p\n", aptr, tarr);
	printf("aptr+1 : %p\t tarr+1 : %p\n", aptr+1, tarr+1);
	return;
}

