#pragma once
#include "myNode.h"

typedef struct List {
	node* head;
	node* tail;
	FILE* fin;
}list;

list* initList(const char * filename);
void setList(list*);
void pushBack(list*);
void viewList(const list*);

node* moveNext(node * );
node* movePrev(node* );

