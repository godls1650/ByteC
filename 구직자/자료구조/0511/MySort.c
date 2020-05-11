#include "MySort.h"
int BubbleSort(int* ptr, int size) {
	int cmp_cnt = 0; // ��Ƚ��
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

	for (int i = 0; i < size-1; i++) {// 0 ~ size-2�� �ε��� ���� �����Ѵ�.
									  // size-1�� �ε����� ������ �ִ밪
		index = i;// �ּҰ��� ����� �ε���
		for (int j = i+1; j < size; j++) { // index�� 0 ~ 8�� �ε��� ���� �����ϱ� ������
										// j�� i���� �ε������� Ȯ���ϸ� ��
			if (ptr[index] > ptr[j]) {
				index = j; //ptr[i]�� ptr[j]���� ũ��  index�� j�ε��� ��ȣ�� ����
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

void MergeSort(int* ptr, int left, int right) {// ���� �Լ�
	int mid = 0;

	if (left < right) {
		mid = (left + right) / 2; 
		MergeSort(ptr, left, mid); // ���� 
		MergeSort(ptr, mid + 1, right);// ���� 
	
		Merge2Array(ptr, left, mid, right); // ����

	}
}
void Merge2Array(int* ptr, int left, int mid, int right) {// ���� �Լ�
	// �ӽ� �迭�� ������ ���� �� ptr�� �ǵ��� �ش�.
	int* temp = (int*)malloc(sizeof(int) * (right + 1));
	int lIdx = left;   // mid
	int rIdx = mid + 1; // ~ right
	int start = left;  // temp�� �ε��� ��ȣ 


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