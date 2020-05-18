#include "MySort.h"
int BubbleSort(int* ptr, int size) {
	int cmp_cnt = 0; // 비교횟수
	int temp = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < (size - 1) - i; j++) {
			cmp_cnt++;
			if (ptr[j] > ptr[j + 1]) {
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
				cmp_cnt++;
			}
		}
	}

	return cmp_cnt;
}

int SelectSort(int* ptr, int size) {
	int count = 0;
	int temp = 0;
	int index = 0;

	for (int i = 0; i < size-1; i++) {// 0 ~ size-2번 인덱스 까지 대입한다.
									  // size-1번 인덱스는 종료후 최대값
		index = i;// 최소값이 저장될 인덱스
		for (int j = i+1; j < size; j++) { // index는 0 ~ 8번 인덱스 까지 저장하기 때문에
										// j는 i다음 인덱스부터 확인하면 됨
			if (ptr[index] > ptr[j]) {
				index = j; //ptr[i]가 ptr[j]보다 크면  index에 j인덱스 번호를 저장
			}
		}
		if (index == i)
			continue;
		else {
			temp = ptr[i];
			ptr[i] = ptr[index];
			ptr[index] = temp;
			count++;
			printArray(ptr, size);
		}
	}
	
	return count;
}


void printArray(const int* ptr, int size) {
	for(int i = 0 ; i< size; i++)
		printf("%3d ", ptr[i]);
	printf("\n");
}

void MergeSort(int* ptr, int left, int right) {// 분할 함수
	int mid = 0;

	if (left < right) {
		mid = (left + right) / 2; 
		MergeSort(ptr, left, mid); // 분할 
		MergeSort(ptr, mid + 1, right);// 분할 
	
		Merge2Array(ptr, left, mid, right); // 결합

	}
}
void Merge2Array(int* ptr, int left, int mid, int right) {// 결합 함수
	// 임시 배열에 연산을 저장 후 ptr에 되돌려 준다.
	int* temp = (int*)malloc(sizeof(int) * (right + 1));
	int lIdx = left;   // mid
	int rIdx = mid + 1; // ~ right
	int start = left;  // temp의 인덱스 번호 


	while (lIdx <= mid && rIdx <= right) {
		if (ptr[lIdx] <= ptr[rIdx])
			temp[start] = ptr[lIdx++];
		else
			temp[start] = ptr[rIdx++];

		start++;
	}

	if (lIdx > mid) {
		for (int i = rIdx; i <= right; i++, start++)
			temp[start] = ptr[i];
	}
	else {
		for(int i = lIdx; i <= mid; i++,start++)
			temp[start] = ptr[i];
	}


	for (int i = left; i <= right; i++) {
		ptr[i] = temp[i];
	}

	free(temp);
	return;
}


int getPivot(int* ptr, int left, int right) {
	int p = ptr[left];
	int low = left + 1;
	int high = right;
	int temp = 0;
	printArray2(ptr, left, right);
	while (low <= high) {
		while (p > ptr[low]) {
			low++;
		}
		while (p < ptr[high]) {
			high--;
		}
		if (low <= high) {
			
			SWAP(ptr[low], ptr[high]);
		}
	}
	SWAP(ptr[left], ptr[high]);
	return high;
}
void QuickSort(int* ptr, int left, int right) {
	int pivot = 0;
	if (left <= right) {
		pivot = getPivot(ptr, left, right);
		QuickSort(ptr, left, pivot - 1);
		QuickSort(ptr, pivot + 1, right);
	}
}

void printArray2(const int* ptr, int left, int right) {
	for (int i = left; i <= right; i++) {
		printf("%3d ", ptr[i]);
	}
	printf("\n");
}