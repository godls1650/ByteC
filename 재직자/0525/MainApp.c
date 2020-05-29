#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define SIZE	40
/*
	���� Ž�� �˰��� :


*/
void CockTailSorting(int* ptr, int size);
void BubbleSorting(int* ptr, int size);
void setArray(int* ptr, int size, int min, int max);
void selectionSort(int* ptr, int size);
void printArray(int* ptr, int size);
void insertSort(int* ptr, int size);

void viewGraph(int* ptr, int size);

void quickSort(int* ptr, int left, int right);
int getPivot(int* ptr, int left, int right);


HANDLE mhandle;
COORD pos;


int main() {
	pos.X = pos.Y = 0;
	mhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int arr[SIZE] = { 0 };
	srand((unsigned int)time(NULL));
	setArray(arr, SIZE, 1, 40);
	system("pause");
	insertSort(arr, SIZE);
	system("pause");
	

	setArray(arr, SIZE, 1, 40); // 1 ~ 20 ������ �ߺ� ���� ������ �Է�
	//viewGraph(arr, SIZE);
	BubbleSorting(arr, SIZE);
	setArray(arr, SIZE, 1, 40); // 1 ~ 20 ������ �ߺ� ���� ������ �Է�
	selectionSort(arr, SIZE);
	//printArray(arr, SIZE);
	return 0;
}
void setArray(int* ptr, int size, int min, int max) {
	int r = max - min + 1;
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % max + min;
		for (int j = 0; j < i; j++) {
			if (ptr[i] == ptr[j]) {
				i--;
				break;
			}
		}
	}
	return;
}
void printArray(int* ptr, int size) {
	for (int i = 0; i < size; i++)
		printf("%2d ", ptr[i]);
	printf("\n");
}

void BubbleSorting(int* ptr, int size) {
	int temp = 0;
	for (int i = 0; i < size - 1; i++) { // 9ȸ�� ���� �ϸ鼭
		for (int j = 0; j < size - (i + 1); j++) {
			if (ptr[j] > ptr[j + 1]) {
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
				
				viewGraph(ptr, size);
				Sleep(10);
			}
		}
	}
}

void CockTailSorting(int* ptr, int size) {
	int temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) { // 9ȸ�� ���� �ϸ鼭
		for (j = i; j < size - (i + 1); j++) {
			if (ptr[j] > ptr[j + 1]) { // ���� ū �����͸�
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
				viewGraph(ptr, size);
				Sleep(1000);
				system("cls"); // ������ ���� �̵� 
			}
		}
		for (  ; j > i; j--) {
			if (ptr[j] < ptr[j - 1]) { // ���� ū �����͸�
				temp = ptr[j];
				ptr[j] = ptr[j - 1];
				ptr[j - 1] = temp;
				viewGraph(ptr, size);
				Sleep(1000);
				system("cls"); // ������ ���� �̵� 
			}
		}
	}

}

void selectionSort(int* ptr, int size) {
	int min = 0;
	int temp = 0;
	
	viewGraph(ptr, SIZE);
	Sleep(500);
	for (int i = 0; i < size-1; i++) {
		min = i;
		for (int j = i; j < size; j++) {
			if (ptr[min] > ptr[j])
				min = j;
		}

		temp = ptr[i];
		ptr[i] = ptr[min];
		ptr[min] = temp;
		
		viewGraph(ptr, SIZE);
		Sleep(500);
		
	}
}

void viewGraph(int* ptr, int size) {
	SetConsoleCursorPosition(mhandle, pos);
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < size; j++) {
			if (j == ptr[i] - 1 || j == size -(ptr[i] - 1)) {
				if (i & 1) printf("��");
				else printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void insertSort(int* ptr, int size) {
	int value = 0;
	int j = 0;
	for (int i = 0; i < size; i++){
		value = ptr[i];
		for (j = i; j > 0; j--) {
			if (value > ptr[j - 1]) break;
			else { // value <= ptr[j-1]
				ptr[j] = ptr[j - 1];
			}
		}
		ptr[j] = value;
		viewGraph(ptr, size);
	}
}

void quickSort(int* ptr, int left, int right) {
	int p = 0;
	while (left < right) {
		p = getPivot(ptr, left, right);
		quickSort(ptr, left, p - 1);
		quickSort(ptr, p + 1, right);
	}
}

int getPivot(int* ptr, int left, int right) {
	int low = left;
	int high = right + 1;
	int pivot = ptr[left];
	int temp = 0;
	do {
		do {
			low++;
		} while (ptr[low] < pivot && low < right);
		do {
			high--;
		} while (ptr[high] > pivot && high > left);
		if (low < high) {
			temp = ptr[low];
			ptr[high] = ptr[low];
			ptr[high] = temp;
		}
	} while (low < high);
	temp = ptr[left];
	ptr[high] = ptr[left];
	ptr[high] = temp;

	return high;
}