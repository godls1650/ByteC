/*	FILE NAME : Node.h
	PURPOSE : Node.h 's Struct  and Function  CREATION
	CREATION DATE : 2020 -05 -07
	LATELY EDIT DATE : 2020 -05 -07
	LATELY EDIT MANAGER : ��  */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	node : ( struct _NODE ) �� ������
	member : data --> �ʿ��� Ÿ������ �ٲټž� �մϴ�.
	��� ���� node * ���·� �����Ҵ� �˴ϴ�.
*/

typedef struct _NODE {		
	int m_nData;
	struct _NODE* pNext;
#ifdef _TWIN_LINKED_LIST 
	struct _NODE* pPrev;
#endif
}node;

node* initNode(); // ��带 �ʱ�ȭ �ϴµ� ���Ǵ� �Լ�
void setData(node** pTarget,int value); // ���� ������ ��� ���Ǵ� �Լ�
void viewNode(const node* Target); // ��´�� ���Ǵ� �Լ�
int getData(const node* Target);








