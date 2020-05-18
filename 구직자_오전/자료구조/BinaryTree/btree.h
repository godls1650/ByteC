#pragma once
#include "btnode.h"
#include "myQueue.h"



typedef struct BinaryTree {
	btnode* root;
	queue* check;
}bTree;

bTree* initTree(int);

void insertNode(bTree*, int);
void bTreeTravel(const bTree* , void (*)());
void PreOrderTravel(const btnode*);