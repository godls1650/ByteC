#pragma once
#include "binaryTree.h"
#include "AVLTree.h"


void BSTMakeAndInit(btnode** pRoot);
int BSTGetNodeData(btnode* bst);
void BSTInsert(btnode** pRoot, int data);
btnode* BSTSearch(btnode* bst, int target);
btnode* BSTRemove(btnode** pRoot, int target);
void BSTShowAll(btnode* bst);