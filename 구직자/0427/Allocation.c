#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  
	stdlib::동적할당  
	 --> void * malloc(size_t Size)// Size크기 Heap 공간에 할당하고 그 공간의 주소를 반환
	 --> void * calloc(size_t Size, size_t _Count)// Size * count 만큼 할당하고 그 공간의 주소를 반환
	 --> void * realloc(void * _block,size_t Size)// 기존 공간(Block)을 Size크기로 변환후 리턴 
	 --> free(void * _block)// 할당받은 공간 Block을 할당 해제 시킨다.


*/

int main() {
	int* nPtr = NULL;
	int number = 200;
	double* dPtr = NULL;
	dPtr = (double*)malloc(sizeof(double));
	dPtr = (double*)calloc(1, sizeof(double));
	memset(dPtr, 0, sizeof(double));
	printf("dPtr이 가리키는 heap : %lf\n", dPtr[0]);
	nPtr = (int *)malloc(sizeof(int)*10);// memory alloate : 메모리 총량으로 할당
	memset(nPtr, 0, sizeof(int) * 10);


	printf("nPtr이 가리키는 heap : %d\n", nPtr[0]);
	nPtr[0] = 100;

	
	nPtr = (int *)realloc(nPtr, sizeof(int) *12);
	nPtr[1] = number;

	printf("nPtr이 가리키는 heap : %d\n", nPtr[0]);
	printf("nPtr이 가리키는 heap : %d\n", nPtr[1]);

	nPtr = (int*)realloc(nPtr, sizeof(int) * 9);

	free(nPtr);// 사용 종료가 되면 할당 해제 
	free(dPtr);

	return 0;
}
