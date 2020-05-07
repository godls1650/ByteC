#pragma once
#include "framework.h"
#include "myNode.h"

typedef struct _LIST {
	node* head;
	node* tail;
	int length; // <- 이거 전체 페이지 수가 됨
}list;

list* initList();// 리스트 초기화 함수
int appendNode(list ** target); // 노드 추가

// 리스트 삭제와 노드 재귀함수
void destroyList(list * target);
void recur_destroyList(node* tNode);



