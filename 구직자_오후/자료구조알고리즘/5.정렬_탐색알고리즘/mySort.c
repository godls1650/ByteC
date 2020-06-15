#include "mySort.h"


/* 
	��� ���� : �ڸ����� �̿��Ͽ� ���� �ϴ� ������� 
				���� �ڸ� ������ ���� ���Ŀ� ��� �Ѵ�.

	[752, 872, 284, 184,  85] 5���� ���Ҹ� ���� �迭�� ��� 
	1, 11, 101, 111, 121, 131
	
	�� �ڸ��� ǥ���� �� �ִ� ���� ���� �� �� �ִ� ���� ������ �����.
	10������ ��� 0 to 9 ���� 
	�� ������ ������ QUEUE�� ����ϰ� (FIFO) 
	������ �ִ��� ���� �� �� �ִ� ������ ���� : ������ �������� �ѷ� 

	[   ][   ][   ][   ][   ][   ][   ][   ][   ][   ]	//0���ε��� ���� ������ �ε�������
	[   ][   ][   ][   ][   ][   ][   ][   ][   ][   ]	// 10�� �ڸ����� ���Ѵ�. ������ ���� �ε�����
	[   ][   ][   ][   ][   ][   ][   ][   ][   ][   ]	// �ش� ������ ť�� �Է��Ѵ�.
	[   ][   ][   ][   ][   ][   ][   ][   ][   ][   ]	// �Է��� ����Ǹ� 
	[ 85][184][284][   ][   ][   ][   ][752][872][   ]	// ���� �ε�����  ť ���� �ٽ� 
	[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ][ 8 ][ 9 ]	// �����͸� �����Ų��.

	�迭��� Queue�� ���  NULL ���� + ���� ���� --> Queue->Capacity = 6 
	 - ���ڸ� ������ ���� ���ΰ�.

a_queue* initArrayQueue(int );

void enQueue(a_queue * , int );
int deQueue(a_queue *);
bool isQEmpty(const a_queue *);
bool isQFull(const a_queue*);
int seekFront(const a_queue*);
int seekRear(const a_queue*);

*/
#include "../StackAndQueue/ArrayBaseQueue.h"
void RadixSort(int* block, int Size, int Radix) {
	a_queue** Bucket = (a_queue**)calloc(Radix, sizeof(a_queue *));
	for (int i = 0; i < Radix; i++) {
		Bucket[i] = initArrayQueue(Size);
	}
	int num = 0;
	int bi = 0;
	int d = 0;
	bool bEnd = false;
	while (1) {
		for (int i = 0; i < Size; i++) {
			num = block[i]/pow(10, d)  % 10;
			enQueue(Bucket[num], block[i]);
		}
		if(isQFull(Bucket[0])) {
			bEnd = true;
			break;
		}
		else {
			for (int i = 0 ,bi = 0; i < Radix; i++) {
				while (!isQEmpty(Bucket[i])) {
					block[bi++] = dequeue(Bucket[i]);
				}
			}
			d++;
		}

	}

}










void BubbleSort(int* block, int Size) {
	
	
	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - 1 - i; j++) {
			if (block[j] > block[j + 1]) {
				SWAP(block[j], block[j + 1]);

				printArray(block, Size);
				Sleep(400);
			}
		}
		for (int j = Size - 2 - i; j >= 1+i ; j--) {
			if (block[j] < block[j - 1]) {
				SWAP(block[j], block[j - 1]);

				printArray(block, Size);
				Sleep(400);
			}
		}
	}
}// O(n^2)
void SelectSort(int* block, int Size) {
	int Small = 0;
	for (int i = 0; i < Size - 1; i++) {
		Small = i;
		for (int j = i + 1; j < Size; j++) {
			if (block[Small] > block[j])
				Small = j;
		}
		SWAP(block[i], block[Small]);
		printArray(block, Size);
		Sleep(500);
	}
}
void insertSort(int* block, int Size){
	int sv;
	int idx;
	for (int i = 1; i < Size; i++) {
		sv = block[i];
		idx = i-1;
		while (block[idx] > sv) {
			block[idx + 1] = block[idx];
			if (idx != 0) idx--;
			else break;
		}
		if(block[idx] < sv) block[idx+1] = sv;
		else block[idx] = sv;
		printArray(block, Size);
	}


}
void quickInfo(int* block, int f, int r) {
	printf("arr[%d] : arr[%d] --> ", f, r);
	for (int i = f; i <= r; i++) {
		printf("%3d ", block[i]);
	}
	printf("\n");
}
int getPivot(int* block, int front, int rear) {
	int p = front;
	int low = front;
	int high = rear + 1;

	do {
		do{
			low++;
		} while (block[low] < block[p] && low <= rear);
		do {
			high--;
		} while (block[high] > block[p] && high >= front);

		if (low < high) {
			SWAP(block[low], block[high]);
			quickInfo(block, front, rear);
		}
	
	} while (low < high);

	SWAP(block[p], block[high]);
	quickInfo(block, front, rear);
	return high;
}
void QuickSort(int* block, int front, int rear) {
	int pivot = 0;
	if (front < rear) {
		pivot = getPivot(block, front, rear);
		QuickSort(block, front, pivot - 1);
		QuickSort(block, pivot + 1, rear);
	}
	else return;
	return;
}
