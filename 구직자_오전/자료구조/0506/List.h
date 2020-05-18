/*	FILE NAME : List.h
	PURPOSE : List Struct  and Function  CREATION
	CREATION DATE : 2020 -05 -07
	LATELY EDIT DATE : 2020 -05 -07
	LATELY EDIT MANAGER : ³ª  */
#pragma once
#define _TWIN_LINKED_LIST
#include "Node.h"

#define toNext(x) x = x->pNext

typedef struct _LIST {
	node* head;
	node* tail;
}list;

list* initList();
void appendNode(list** pTarget, int value);
void viewList(const list* Target);
#ifdef _TWIN_LINKED_LIST
void rviewList(const list* Target);
#endif // _TWIN_LINKED_LIST

void deleteNode(list** pTarget, int locate);
void insertNode(list** pTarget, int locate, int value);

void uninstall(list** pTarget);
void inner_uninstall(node* target);


