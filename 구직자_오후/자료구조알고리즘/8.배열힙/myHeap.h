#pragma once
#include "framework.h"

typedef struct _Heap {
	/*완전이진 트리의 구현*/
	int * Hstorage;
	int depth;
	int cur;
}heap;


heap* createHeap(int Tree_depth);
void addData(heap* block, int item);
int mvLeftChild(int locate);
int mvRightChild(int locate);
int mvParent(int locate);

int popData(heap * block);
