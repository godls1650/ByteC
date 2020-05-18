#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
	배열  -> type * ptr[n]
	
	
	배열 포인터  -> type (* ptr)[n]
	함수 포인터  -> type (* ptr)()
*/


void func1(int* ptr);
int  func2();
int func3(int num);
void func4(int num);

void tarrFunc(int(* board)[5] , int min  , int max, int size);
int main() {
	int arr[10] = { 0 };
	int tarr[5][5] = { 0 };

	// tarr -> 주소
	// tarr[0] -> 주소
	// tarr[1] -> 주소
	// tarr[0][1] -> data
	int * tptr = tarr;
	int * * dptr = NULL; // double pointer  --> 
	int number = 0;
	tptr = &number;
	dptr = &tptr;// *dptr
	*dptr = arr;
	tptr = arr;

	int* parr[5] = { NULL };
	parr[0] = tarr[0];
	parr[1] = tarr[1];
	parr[2] = tarr[2];
	parr[3] = tarr[3];
	parr[4] = tarr[4];
	int(*ptr)[5] = tarr; // 배열 포인터

	printf("%d\n", *(*(tptr+0)+1));
	// * tptr --> 정수 데이터  *(10 + 1)


	void(* fptr1)() = NULL;
	int (*fptr2)() = NULL;
	
	fptr1 = func4;
	fptr2 = func3;

	fptr1(arr);
	fptr2(20);

	
	// Rectange(윈도우제어변수, sx, sy, ex, ey)
	// Elipse(윈도우제어변수, sx, sy, ex, ey)

	printf("func1 : %p\n", func1);
	printf("func2 : %p\n", func2);
	printf("func3 : %p\n", func3);
	printf("func4 : %p\n", func4);
	return 0;
}



void func1(int* ptr) {
	for (int i = 0; i < 10; i++) {
		ptr[i] = (i + i) * 10;
	}
	printf("Non Parameter , Non Return\n");
}

int  func2() {
	printf("Non Parameter , Integer Return\n");
	return 0;
}
int func3(int num) {
	printf("One Parameter, Integer Return\n");
	return 0;
}
void func4(int num) {
	printf("One Parameter, Integer Return\n");
}

void tarrFunc(int(*board)[5], int min, int max, int size) {
	int temp[25] = { 0 };
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = temp[5 * i + j];
		}
	}
	return;
}