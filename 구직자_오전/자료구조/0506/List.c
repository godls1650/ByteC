/*	FILE NAME : List.c
	PURPOSE : List.h 's Struct  and Function  CREATION
	CREATION DATE : 2020 -05 -07
	LATELY EDIT DATE : 2020 -05 -07
	LATELY EDIT MANAGER : 나  */
#include "List.h"

list* initList(){

	list* temp = (list*)malloc(sizeof(list));
	temp->head = initNode();
	temp->tail = initNode();

	temp->head->pNext = temp->tail;
#ifdef _TWIN_LINKED_LIST
	temp->tail->pPrev = temp->head;
#endif
	return temp;
}

void appendNode(list** pTarget, int value){

	node* newNode = initNode();
	node* cursor = NULL;

	setData(&newNode, value);
#ifndef _TWIN_LINKED_LIST
	cursor = (*pTarget)->head;

	while (cursor->pNext != (*pTarget)->tail) {
		cursor = cursor->pNext;
	}
#else
	cursor = (*pTarget)->tail->pPrev;
#endif

	newNode->pNext = cursor->pNext;
#ifdef _TWIN_LINKED_LIST
	newNode->pPrev = cursor;
	cursor->pNext->pPrev = newNode;
#endif 
	cursor->pNext = newNode;

}

void viewList(const list* Target){
	node* cursor = Target->head->pNext;

	while (cursor != Target->tail) {
		viewNode(cursor);
		toNext(cursor);
	}
	printf("\n");
}

void rviewList(const list* Target)
{
	node* cursor = Target->tail->pPrev;

	while (cursor != Target->head) {
		viewNode(cursor);
		cursor = cursor->pPrev;
	}
	printf("\n");
}

void deleteNode(list** pTarget, int locate){
#ifndef _TWIN_LINKED_LIST
	node* del = NULL;
	node* cursor = (*pTarget)->head;
	for (int i = 0; i < locate - 1; i++)
		toNext(cursor);
	del = cursor->pNext;
	cursor->pNext = del->pNext;
	free(del);
#else 
	node* cursor = (*pTarget)->head;
	for (int i = 0; i < locate; i++)
		toNext(cursor);
	cursor->pNext->pPrev = cursor->pPrev;
	cursor->pPrev->pNext = cursor->pNext;
	free(cursor);
#endif // ! _TWIN_LINKED_LIST

	

}
void insertNode(list** pTarget, int locate, int value) {
#ifndef _TWIN_LINKED_LIST
	node* newNode = initNode();
	node* cursor = (*pTarget)->head;
	setData(&newNode, value);

	for (int i = 0; i < locate - 1; i++)
		toNext(cursor);

	newNode->pNext = cursor->pNext;
	cursor->pNext = newNode;
#else 
	node* newNode = initNode();
	node* cursor = (*pTarget)->head;
	for (int i = 0; i < locate ; i++)
		toNext(cursor);
	newNode->pPrev = cursor->pPrev;
	newNode->pNext = cursor;
	cursor->pPrev->pNext = newNode;
	cursor->pPrev = newNode;

#endif // ! _TWIN_LINKED_LIST
	return;
}

void uninstall(list** pTarget)
{
	inner_uninstall((*pTarget)->head);
	free(*pTarget);
}

void inner_uninstall(node* target)
{
	if (target->pNext != NULL)
		inner_uninstall(target->pNext);
	//TODO : 여기에 노드 내부 정보를 할당 해제 하는코드를 적습니다.
	

	//END
	free(target);
}
