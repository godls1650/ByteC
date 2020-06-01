#pragma once
#include "iNode.h"

typedef struct _SingleLinkedList {
	node* pHead; // 시작
	node* pTail; // 끝
	size_t m_nCapacity;// 용량
	size_t m_nSize;
}slist;

slist* createList(int);
bool ListisEmpty(const slist*);
bool ListisFull(const slist*);


bool appendList(slist*, int);
void viewList(const slist*);
int seekList(const slist*, int);
int pickList(const slist*, int);
bool insertNode(slist*, int, int);
int deleteNode(slist*, int);
void deAllocList(slist*);
void innerDel(node*);

