#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
/*  �迭 (Array)
	- ���� ��Ҹ� �������� ����ϰų�  �ϳ��� ������ ��Ÿ������ �ϴ� ��� 
	  1. ������ ������ ���� �Ѵ�.
	  2. �迭�� �����Ѵ�.
	- �迭�� ���� �޸𸮸� �����Ͽ� �����ϱ� ������ ����ũ�θ���� ���� 
	   ������ ����� �� ���� ����
	- �迭�� �����ϴ� ���
	   ������Ÿ�� �����̸� [ �ε��� ũ�� ] ���·� �����ϰ� 
	   �ε��� ũ�⿡�� ����� �� ����� �� �ִ�.

	   (������ Ÿ��) ������ �޸𸮸� �ε��� ũ�⸸ŭ �����ؼ� �޸𸮿� �Ҵ��Ѵ�. 

	   ������ �����Ϳ� ���� �ϱ� ���ؼ� �ε�����ȣ�� ����Ѵ�.
	   �ε��� ��ȣ : ����(0) ~ �迭�� ũ��-1

	    * �����Ϸ��� �迭���ε��� ������ ������ ���� �ʴ´�.
		 score[3]'s memory value : -858993460 (������ ��)
		 score[5]'s memory Address : 00CFFD4C == math
		 score[8]'s memory Address : 00CFFD58 == eng
		 score[11]'s memory Address : 00CFFD64 == kor

		�ε��� ��ȣ����
		  --> �迭�� �̸� [x] --> �迭�� �����ּ�(�迭�� �̸�) + (�迭������ Ÿ�Ի�����)*��ȣ
									00000014

									 --> �ּҿ���

*/
#define ArraySize	4
/*
	10�� �ε����� ���� ���� �迭�� ������ ������ �������� �Է¹޴� ���α׷��� �ۼ��ϼ���
	 - 10�� �ε����� ����� ������ �ߺ��� ����� �Ѵ�.
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
		printf("\a�迭�� �������� ���� ������ �����ϴ�.\n");
		printf("�Է� �Ұ��� �մϴ�.\n");
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