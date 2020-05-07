#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE	100
//전역변수


void setArray(int* arr, int max, int min);
void printArray();
int  CheckCount();
void printGraph();

int main() {
	int arr[SIZE] = { 0 };
	int max = 10;
	int min = 1;
	int test[11] = { 0 };
	srand(time(NULL));
	// 프로그램 동작만 구현
	setArray(arr, max, min);// 배열에 값을 채운다.
	printArray();
	printf("가장 많이 나온 값 : %d\n", CheckCount());
	printGraph();
	return 0;
}

void setArray(int * arr, int max, int min) {
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % (max - min + 1) + min;
}
void printArray() {
	int c = 0;
	for (int i = 0; i < SIZE; i++) {
		printf("%2d ", arr[i]);
		c++;
		if(c % 10 == 0)printf("\n");
	
	}
	printf("\n");
}
int CheckCount() {
	// 1  ~ 10
	int index;
	int most = 0;
	for (int i = 0; i < SIZE; i++) {
		index = arr[i];
		test[index] += 1;
	}

	for (int i = 1; i <= 10; i++) {
		if (test[most] < test[i])
			most = i;
	}
	
	return most;

}

void printGraph() {
	for (int i = 1; i <= 10; i++) {
		printf("[%2d] | ", i);
		for (int j = 0; j < test[i]; j++)
			printf("━");
		printf("\n");
	}
	

}