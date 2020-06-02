#pragma once
#include "framework.h"


typedef struct _Node {
	int m_nData;
	struct _Node* m_pNext;
#ifdef _DOUBLE_LINKED_LIST_
	struct _Node* m_pPrev;
#endif
}node;

node* initNode(void); 
bool setNodeData(node*, int);
int deleteData(node*); 
void viewNode(const node*);