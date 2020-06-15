#pragma once
#include "../SingleLinkedList/framework.h"
//#include <framework.h>
/////Double Linked List Node/////
typedef struct dlNode {
	int m_nData; // ����� ���� �����ϴ� ����
	struct dlNode* m_pNext; // ���� ������ ���� �ּҸ� �����ϴ� ������
	struct dlNode* m_pPrev; // ���� ������ ���� �ּҸ� �����ϴ� ������
}node;


node* initNode(void);
bool setNodeData(node*, int);
int deleteData(node*);
void viewNode(const node*);