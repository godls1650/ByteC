#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* �Լ� : ���α׷��� ���� �� �ϳ��� ������ ���� ���� ������ �ڵ�(���� ���ν���)�� 
	�ѹ��� ���� �Ͽ�  ȣ���ϴ� �������� ���ȴ�.
�Լ��� �ۼ��� ���� ������ �Ѵ�. 
�� �Լ��� ������ main �Լ� ���� ������ 
   �Լ��� ���Ǵ� main �Լ� �Ʒ� ������ �ۼ��ϴ°� �Ϲ����̴�.(�ϳ��� �ҽ� ������ ����ϴ� ���)

   �Լ��� ���� : �� �Լ��� �̸��� �Ű������� Ÿ����, ���� �����ΰ�. �׸��� ��ȯ���� Ÿ���� �����ΰ�.

   ��ȯŸ��   �Լ��̸� (�Ű�����Ÿ��, �Ű�����Ÿ��,..)
*/

void inputRandRange(int*, int, int, int); //�Լ������
int printArray(const int* target, int size); // �Լ������
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