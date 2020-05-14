#pragma once
//TNode.h
#include "framework.h"

typedef struct TNode {
	char m_cData;
	struct TNode * Parent;
	struct TNode * Child;
	struct TNode * Sibling;
	int level;
}tnode;

tnode* initNode();
int setData(tnode * , char);


