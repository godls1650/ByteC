/*
	�켱���� Queue --> �⺻�� ť ������ ���� 
	 - �Էµ� ������ ��������ϴ� ť�� �ƴ�
	   ����Ǿ��ִ� �켱���� �����Ͱ� ���� ���� ���� ���
*/

#include "myHeap.h"

int main() {
	int arr[15] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	heap* test = createHeap(4);
	for (int i = 0; i < 15; i++) {
		addData(test, arr[i]);
	}

	
	for (int i = 0; i < 15; i++) {
		printf("main>> %d\n", popData(test));
	}

}