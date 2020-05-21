#pragma once
#include "framework.h"

typedef struct _Pair {
	char* key;
	int value;
}pair;

typedef pair hData;

typedef struct _HashNode {
	hData * data;
	struct _HashNode* next;
}hNode;

hNode* initNode();
typedef int hashFunc(const char*);
void setData(hNode* , const char * const, hashFunc * );
char* setstrAlloc(const char* const);

void deleteNode(hNode*);
