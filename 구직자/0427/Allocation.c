#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  
	stdlib::�����Ҵ�  
	 --> void * malloc(size_t Size)// Sizeũ�� Heap ������ �Ҵ��ϰ� �� ������ �ּҸ� ��ȯ
	 --> void * calloc(size_t Size, size_t _Count)// Size * count ��ŭ �Ҵ��ϰ� �� ������ �ּҸ� ��ȯ
	 --> void * realloc(void * _block,size_t Size)// ���� ����(Block)�� Sizeũ��� ��ȯ�� ���� 
	 --> free(void * _block)// �Ҵ���� ���� Block�� �Ҵ� ���� ��Ų��.


*/

int main() {
	int* nPtr = NULL;
	int number = 200;
	double* dPtr = NULL;
	dPtr = (double*)malloc(sizeof(double));
	dPtr = (double*)calloc(1, sizeof(double));
	memset(dPtr, 0, sizeof(double));
	printf("dPtr�� ����Ű�� heap : %lf\n", dPtr[0]);
	nPtr = (int *)malloc(sizeof(int)*10);// memory alloate : �޸� �ѷ����� �Ҵ�
	memset(nPtr, 0, sizeof(int) * 10);


	printf("nPtr�� ����Ű�� heap : %d\n", nPtr[0]);
	nPtr[0] = 100;

	
	nPtr = (int *)realloc(nPtr, sizeof(int) *12);
	nPtr[1] = number;

	printf("nPtr�� ����Ű�� heap : %d\n", nPtr[0]);
	printf("nPtr�� ����Ű�� heap : %d\n", nPtr[1]);

	nPtr = (int*)realloc(nPtr, sizeof(int) * 9);

	free(nPtr);// ��� ���ᰡ �Ǹ� �Ҵ� ���� 
	free(dPtr);

	return 0;
}
