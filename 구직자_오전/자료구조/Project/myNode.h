#pragma once
#include "framework.h"
#include "Page.h"

typedef struct _NODE {
	page* mPage;	// page 정보 
	struct _NODE* pNext; // 다음노드 위치
	struct _NODE* pPrev; // 이전노드 위치
}node;
node* initNode();
int setNode(node* target);
void viewNode(const node*);
void deleteNode(node* target);

