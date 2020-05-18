#include "list.h"

list* initList() {// 리스트 초기화 함수
	list* temp = (list*)malloc(sizeof(list));
	temp->head = initNode();
	temp->tail = initNode();
	temp->length = 0;
	temp->head->pNext = temp->tail;
	temp->tail->pPrev = temp->head;
	return temp;
}
int appendNode(list** target) { // 노드 추가
	node* newNode = initNode();
	node* cursor = (*target)->tail;
	
	(*target)->length = setPage(&(newNode->mPage));

	newNode->pNext = cursor;
	newNode->pPrev = cursor->pPrev;
	cursor->pPrev->pNext = newNode;
	cursor->pPrev = newNode;

	return (*target)->length;
}

// 리스트 삭제와 노드 재귀함수
void destroyList(list* target) {
	recur_destroyList(target->head);
	free(target);
}
void recur_destroyList(node* tNode) {
	if (tNode->pNext != NULL)
		recur_destroyList(tNode->pNext);
	deleteNode(tNode);
}