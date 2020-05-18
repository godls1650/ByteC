#pragma once
#include "framework.h"

typedef struct btNode {
	int Data;
	int level;
	struct btNode* Left;
	struct btNode* Right;
}btnode;

btnode* initNode();
btnode* copyNode(const btnode*);
int setNode(btnode*, int src);