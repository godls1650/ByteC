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
void PrevOrderTravel(const btnode*); // 전위 순회 ( Root -> Left -> Right )
void InOrderTravel(const btnode*);   // 중위 순회 (Left -> Root -> Right)
void PostOrderTravel(const btnode*); // 후위 순회 (Left -> Right-> Root)