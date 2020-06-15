#pragma once
/////DOUBLE_LINKED_LIST//////
//#include "dlNode.h"
#define _DOUBLE_LINKED_LIST_
#include "../SingleLinkedList/iNode.h"
#define ASC	1	
#define	 DESC	2

typedef struct _doubleLinkedlist{
	node* m_pHead;
	node* m_pTail;
	size_t m_nSize;
	size_t m_nCapacity;
}dlist;


dlist* createList(int);
bool ListisEmpty(const dlist*);
bool ListisFull(const dlist*);


bool appendList(dlist*, int);
void viewList(const dlist*, int );
int seekList(const dlist*, int);
int pickList(const dlist*, int);
bool insertNode(dlist*, int, int);
int deleteNode(dlist*, int);
void deAllocList(dlist*);
void innerDel(node*);


void push_Back(dlist*, int);
void push_Front(dlist*, int);
int pop_Back(dlist*);
int pop_Front(dlist*);
