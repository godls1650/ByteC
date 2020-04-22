#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 함수 : 프로그램의 동작 중 하나의 목적을 갖는 여러 라인의 코드(서브 프로시저)를 
	한번만 정의 하여  호출하는 형식으로 사용된다.
함수의 작성은 전역 영역에 한다. 
단 함수의 선언은 main 함수 위의 공간에 
   함수의 정의는 main 함수 아래 공간에 작성하는게 일반적이다.(하나의 소스 파일을 사용하는 경우)

   함수의 선언 : 이 함수의 이름과 매개변수의 타입이, 갯수 무엇인가. 그리고 반환값의 타입이 무엇인가.

   반환타입   함수이름 (매개변수타입, 매개변수타입,..)
*/

void inputRandRange(int*, int, int, int); //함수선언부
int printArray(const int* target, int size); // 함수선언부
int copyArray(int* target, const int* source, int targetSize);
int reverseArray(int* target, const int* source, int targetSize);


#define ARR_SIZE(_array,type) sizeof(_array) / sizeof(type)

void DataSwap(int px, int py) {
	int temp = px;
	px = py;
	py = temp;
}

void DataSwap2(int * px, int * py) {
	int temp = *px;
	*px = *py;
	*py = temp;
}

int main() {
	int x = 10, y = 20;
	
	printf("%d %d\n", x, y);
	DataSwap(x, y);
	printf("%d %d\n", x, y);

	DataSwap2(&x, &y);
	printf("%d %d\n", x, y);



	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int copy[10] = { 0 };
	char fruit[3][100] = { "APPLE", "BANANA", 0 };
	
	srand((unsigned int)time(NULL));
	inputRandRange(arr1, 1, 50, ARR_SIZE(arr1,int));
	inputRandRange(arr2, 51, 100, ARR_SIZE(arr2, int));
	
	copyArray(copy, arr1, ARR_SIZE(copy, int));
	copyArray(arr1, arr2, ARR_SIZE(arr1, int));
	copyArray(arr2, copy, ARR_SIZE(arr2, int));


	return 0;
}



void inputRandRange(int* target, int min, int max, int size) {
	int range = max - min + 1;
	//srand((unsigned int)time(NULL))
	for (int i = 0; i < size; i++) {
		target[i] = rand() % range + min;
	}
	return;
}

int printArray(const int* target, int size) {
	if (size <= 0) return -1;
	printf("[");
	for (int i = 0; i < size; i++) {
		if(i < size -1)
			printf("%2d, ", target[i]);
		else
			printf("%2d]\n", target[i]);
	}
	return 0;
}

int copyArray(int* target, const int* source, int targetSize) {
	int count = 0;
	for (int i = 0; i < targetSize; i++) {
		target[i] = source[i];
		count++;
	}
	if (count == targetSize) return 1;
	else if (count == targetSize - 1) return 0;
	else return -1;
}
int reverseArray(int* target, const int* source, int targetSize) {
	int count = 0;
	int index = targetSize - 1;
	for (int i = 0; i < targetSize; i++) {
		target[i] = source[index - i];
		count++;
	}
	if (count == targetSize) return 1;
	else if (count == targetSize - 1) return 0;
	else return -1;

}