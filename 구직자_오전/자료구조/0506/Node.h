/*	FILE NAME : Node.h
	PURPOSE : Node.h 's Struct  and Function  CREATION
	CREATION DATE : 2020 -05 -07
	LATELY EDIT DATE : 2020 -05 -07
	LATELY EDIT MANAGER : 나  */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	node : ( struct _NODE ) 의 재정의
	member : data --> 필요한 타입으로 바꾸셔야 합니다.
	모든 노드는 node * 형태로 동적할당 됩니다.
*/

typedef struct _NODE {		
	int m_nData;
	struct _NODE* pNext;
#ifdef _TWIN_LINKED_LIST 
	struct _NODE* pPrev;
#endif
}node;

node* initNode(); // 노드를 초기화 하는데 사용되는 함수
void setData(node** pTarget,int value); // 대입 연산자 대신 사용되는 함수
void viewNode(const node* Target); // 출력대신 사용되는 함수
int getData(const node* Target);








