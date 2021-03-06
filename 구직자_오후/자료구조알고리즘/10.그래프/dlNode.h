#pragma once
#include "framework.h"
//#include <framework.h>
/////Double Linked List Node/////
typedef struct dlNode {
	int m_nData; // 노드의 값을 저장하는 변수
	struct dlNode* m_pNext; // 다음 원소의 시작 주소를 저장하는 포인터
	struct dlNode* m_pPrev; // 이전 원소의 시작 주소를 저장하는 포인터
}node;


node* initNode(void);
bool setNodeData(node*, int);
int deleteData(node*);
void viewNode(const node*);