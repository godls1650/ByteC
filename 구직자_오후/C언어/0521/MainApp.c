#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
/*  배열 (Array)
	- 여러 요소를 연속으로 사용하거나  하나의 정보로 나타내고자 하는 경우 
	  1. 변수를 여러개 선언 한다.
	  2. 배열로 선언한다.
	- 배열은 실제 메모리를 나열하여 선언하기 때문에 마이크로명령의 수가 
	   변수를 사용할 때 보다 적다
	- 배열을 선언하는 경우
	   데이터타입 변수이름 [ 인덱스 크기 ] 형태로 선언하고 
	   인덱스 크기에는 상수값 만 사용할 수 있다.

	   (데이터 타입) 형태의 메모리를 인덱스 크기만큼 연속해서 메모리에 할당한다. 

	   각각의 데이터에 접근 하기 위해서 인덱스번호를 사용한다.
	   인덱스 번호 : 시작(0) ~ 배열의 크기-1

	    * 컴파일러는 배열의인덱스 연산의 오류를 잡지 않는다.
		 score[3]'s memory value : -858993460 (쓰레기 값)
		 score[5]'s memory Address : 00CFFD4C == math
		 score[8]'s memory Address : 00CFFD58 == eng
		 score[11]'s memory Address : 00CFFD64 == kor

		인덱스 번호연산
		  --> 배열의 이름 [x] --> 배열의 시작주소(배열의 이름) + (배열원소의 타입사이즈)*번호
									00000014

									 --> 주소연산

*/
#define ArraySize	4
/*
	10개 인덱스를 갖는 정수 배열에 정해진 범위의 랜덤값을 입력받는 프로그램을 작성하세요
	 - 10개 인덱스에 저장된 난수는 중복이 없어야 한다.
*/

void ArrayEx1();
void setRandRange(int * ptr , int size, int min, int max);
void printArray(int* ptr, int size);
void Swap();
void QSort(int * ptr, int left, int right);
int getPivot(int* ptr, int left, int right);
void SelectionSort(int* ptr, int Size);
void ArraySortEx();


HANDLE mHandle;
COORD pos;


int main() {
	int arr1[10];
	
	setRandRange(arr1, 20, 1, 10);
	setRandRange(arr1, 10, 1, 10);

	return 0;
}



void Swap() {
	int number1 = 10;
	int number2 = 20;
	int number3 = 0;
	number3 = number1;
	number1 = number2;
	number2 = number3;

}
void printArray(int* ptr, int size) {

	for (int i = 0; i < size; i++) {
		printf("%2d ", ptr[i]);
	}
	printf("\n");
}
void QSort(int* ptr, int left, int right) {
	int p = 0;
	
	if (left < right) {
		p = getPivot(ptr, left, right);
		QSort(ptr, left, p -1);
		QSort(ptr, p + 1, right);
	}

}
int getPivot(int* ptr, int left, int right) {
	int low = left;
	int high = right+1;
	int pivot = ptr[left];
	int temp = 0;

	do{
		do {
			low++;
		} while (ptr[low] < pivot && low <= right);
		do {
			high--;
		} while (ptr[high] > pivot && high >= left);
		if (low < high) {
			temp = ptr[low];
			ptr[low] = ptr[high];
			ptr[high] = temp;
		}
	} while (low < high);

	temp = ptr[left];
	ptr[left] = ptr[high];
	ptr[high] = temp;

	return high;
}
void setRandRange(int* ptr, int size, int min, int max) {
	int range = max - min + 1;
	if (size > range) {
		mHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mHandle, 252);
		printf("\a배열의 범위보다 난수 범위가 좁습니다.\n");
		printf("입력 불가능 합니다.\n");
		SetConsoleTextAttribute(mHandle, 240);
		return;
	}
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % range + min;
		for (int j = 0; j < i; j++) {
			if (ptr[i] == ptr[j]) {
				i--;
				break;
			}
		}
	}
	return;
}
void ArrayEx1() {
	int kor = 98;
	int eng = 78;
	int math = 89;

	int score[ArraySize] = { 98, 78, 89 };
	
	printf("%d\n\n\n\n", score[0]);


	printf("kor's memory Address : %p\n", &kor);
	printf("eng's memory Address : %p\n", &eng);
	printf("math's memory Address : %p\n", &math);
	printf("\n");
	printf("score : %p\n", score);
	printf("score : %p\n", score + 1);
	printf("score : %08x\n", (int)(score)+sizeof(int) * 1);
	printf("score : %p\n", (int*)((int)(score)+sizeof(int) * 1));
	printf("score : %d\n", *(int*)((int)(score)+sizeof(int) * 1));
	printf("score : %d\n", score[1]);



	printf("\n");
	for (int i = 0; i < ArraySize + 15; i++) {
		if (score + i == &kor || score + i == &eng || score + i == &math)
			printf("score[%d]'s memory Address : %p (%d)\n", i, score + i, *(score + i));
	}

	printf("%d %d %d\n", math, eng, kor);

}
void SelectionSort(int* ptr, int Size) {
	int minimum = 0;
	int index = 0;
	int temp = 0;
	for (int i = 0; i < Size; i++) {
		minimum = i;
		for (int j = i; j < Size; j++) {
			if (ptr[minimum] > ptr[j]) {
				minimum = j;
			}
		}
		temp = ptr[i];
		ptr[i] = ptr[minimum];
		ptr[minimum] = temp;
		printArray(ptr, Size);
	}
	
}
void ArraySortEx() {
	int RandArr[10] = { 0 };
	srand((unsigned int)time(NULL));
	setRandRange(RandArr, 10, 10, 20);
	printArray(RandArr, 10);
	SelectionSort(RandArr, 10);
	printArray(RandArr, 10);

}