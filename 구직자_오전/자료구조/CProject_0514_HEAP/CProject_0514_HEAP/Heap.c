#include "Heap.h"

heap* HeapInit() {
	heap* temp = (heap*)malloc(sizeof(heap));
	temp->numOfData = 0;
	memset(temp->Storage, 0, sizeof(HeapElem) * HEAP_SIZE);
	return temp;
}

int HisEmpty(const heap * target) {
	if (target->numOfData == 0) return TRUE;
	return FALSE;
}

void HInsert(heap* target, char data, int pr) {
	int idx = target->numOfData + 1;
	HeapElem newElement = { pr, data };

	while (idx != 1) {
		if (pr < target->Storage[GetParentIDX(idx)].m_nPriority) {
			target->Storage[idx] = target->Storage[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	target->Storage[idx] = newElement;
	target->numOfData += 1;
	return;
}

char HDelete(heap* target) {
	char rtData = target->Storage[1].m_cHData;
	HeapElem last = target->Storage[target->numOfData];

	int parentIdx = 1;
	int childIdx = 0;

	while (childIdx = GetChildPriority(target, parentIdx)) {
		if (last.m_nPriority <= target->Storage[childIdx].m_nPriority)
			break;
		target->Storage[parentIdx] = target->Storage[childIdx];
		parentIdx = childIdx;
	}
	target->Storage[parentIdx] = last;
	(target->numOfData)--;
	return rtData;
}


int GetParentIDX(int myIndex) {
	return myIndex / 2;
}
int GetLeftIDX(int myIndex) {
	return myIndex * 2;
}
int GetRightIDX(int myIndex) {
	return myIndex * 2 + 1;
}

int GetChildPriority(const heap* target, int parent) {
	if (GetLeftIDX(parent) > target->numOfData) return 0;
	else if (GetLeftIDX(parent) == target->numOfData)
		return GetLeftIDX(parent);
	else {
		if (target->Storage[GetLeftIDX(parent)].m_nPriority
			> target->Storage[GetRightIDX(parent)].m_nPriority)
			return GetRightIDX(parent);
		else
			return GetLeftIDX(parent);
	}
}

