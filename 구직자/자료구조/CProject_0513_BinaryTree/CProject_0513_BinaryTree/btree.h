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
void PrevOrderTravel(const btnode*); // ���� ��ȸ ( Root -> Left -> Right )
void InOrderTravel(const btnode*);   // ���� ��ȸ (Left -> Root -> Right)
void PostOrderTravel(const btnode*); // ���� ��ȸ (Left -> Right-> Root)