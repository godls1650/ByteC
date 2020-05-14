#pragma once
#include "framework.h"

#define HEAP_SIZE	0x64
#define gotoLeft(x) x * 2
#define gotoRight(x) x * 2 + 1
#define gotoParent(x) x / 2

typedef struct _HeapElement {
	int m_nPriority;// �켱���� 
	char m_cHData; // ǥ����
}HeapElem;

typedef struct _heap {
	int numOfData; // ������ ����
	HeapElem Storage[HEAP_SIZE];

}heap;

heap * HeapInit();
int HisEmpty(const heap*);
void HInsert(heap*, char, int);
char HDelete(heap* );

int  GetParentIDX(int myIndex);
int  GetLeftIDX(int myIndex);
int	 GetRightIDX(int myIndex);

// �� �ڽ� ��� �� ���� �켱������ �ڽ� ����� �ε���
int GetChildPriority(const heap*, int);