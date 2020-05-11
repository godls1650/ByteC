#include "MySort.h"
/*
 ���� ���� : ������� ������ �����͸� ���ؼ� 
             ���� ��ȯ�ϴ� ���
 �������� : (n * (n-1)) / 2  
 �������� / �������� 
 
*/
int Intcmp(const void* px, const void* py) {
	int* pix = (int*)px;
	int* piy = (int*)py;

	if (*pix > * piy) return 1;
	else if (*pix < *piy) return -1;
	else return 0;

}

int main() {

	
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	
	int temp = 0;

	// ������������ ���� 
	// ���� ���� ���� ã�´� or ���� ū ���� ã�´�.
	// �� ���� �ε��� (0) �� ���� ��ȯ�Ѵ�.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100 + 1;
	}
	//QuickSort(arr, 0, 9);
	qsort(arr, 10, sizeof(int), Intcmp);
	printf("%dȸ ���� \n", temp);
		
	for (int i = 0; i < 10; i++) {
		printf("%3d ", arr[i]);
	}


	return 0;
}