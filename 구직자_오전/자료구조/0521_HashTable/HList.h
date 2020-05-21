#pragma once
#include "Node.h"

typedef struct HashList {
	hNode* head;
	hNode* tail;
	int count;
}List;

List* initList();
void append(List * pList,const char* str, hashFunc * hash);
void printList(const List* pList);
