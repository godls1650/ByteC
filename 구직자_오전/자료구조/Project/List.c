#include "list.h"

list* initList() {// ����Ʈ �ʱ�ȭ �Լ�
	list* temp = (list*)malloc(sizeof(list));
	temp->head = initNode();
	temp->tail = initNode();
	temp->length = 0;
	temp->head->pNext = temp->tail;
	temp->tail->pPrev = temp->head;
	return temp;
}
int appendNode(list** target) { // ��� �߰�
	node* newNode = initNode();
	node* cursor = (*target)->tail;
	
	(*target)->length = setPage(&(newNode->mPage));

	newNode->pNext = cursor;
	newNode->pPrev = cursor->pPrev;
	cursor->pPrev->pNext = newNode;
	cursor->pPrev = newNode;

	return (*target)->length;
}

// ����Ʈ ������ ��� ����Լ�
void destroyList(list* target) {
	recur_destroyList(target->head);
	free(target);
}
void recur_destroyList(node* tNode) {
	if (tNode->pNext != NULL)
		recur_destroyList(tNode->pNext);
	deleteNode(tNode);
}