#include "MySort.h"
/*
 내부 정렬 : 저장공간 내부의 데이터를 비교해서 
             직접 교환하는 방식
 버블정렬 : (n * (n-1)) / 2  
 선택정렬 / 삽입정렬 
 
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

	// 오름차순으로 정렬 
	// 가장 작은 값을 찾는다 or 가장 큰 값을 찾는다.
	// 맨 앞의 인덱스 (0) 의 값과 교환한다.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100 + 1;
	}
	//QuickSort(arr, 0, 9);
	qsort(arr, 10, sizeof(int), Intcmp);
	printf("%d회 실행 \n", temp);
		
	for (int i = 0; i < 10; i++) {
		printf("%3d ", arr[i]);
	}


	return 0;
}