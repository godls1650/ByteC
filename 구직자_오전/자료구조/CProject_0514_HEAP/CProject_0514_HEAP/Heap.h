#pragma once
#include "framework.h"

#define HEAP_SIZE	0x64
#define gotoLeft(x) x * 2
#define gotoRight(x) x * 2 + 1
#define gotoParent(x) x / 2

typedef struct _HeapElement {
	int m_nPriority;// 우선순위 
	char m_cHData; // 표현값
}HeapElem;

typedef struct _heap {
	int numOfData; // 데이터 갯수
	HeapElem Storage[HEAP_SIZE];

}heap;

heap * HeapInit();
int HisEmpty(const heap*);
void HInsert(heap*, char, int);
char HDelete(heap* );

int  GetParentIDX(int myIndex);
int  GetLeftIDX(int myIndex);
int	 GetRightIDX(int myIndex);

// 두 자식 노드 중 높은 우선순위의 자식 노드의 인덱스
int GetChildPriority(const heap*, int);