#pragma once
#include "framework.h"
#include "Page.h"

typedef struct _NODE {
	page* mPage;	// page ���� 
	struct _NODE* pNext; // ������� ��ġ
	struct _NODE* pPrev; // ������� ��ġ
}node;
node* initNode();
int setNode(node* target);
void viewNode(const node*);
void deleteNode(node* target);

