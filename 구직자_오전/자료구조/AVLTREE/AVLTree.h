#pragma once
#include "binaryTree.h"

btnode* Rebalance(btnode** pRoot);

int GetHeight(btnode* bst);
int GetHeightDiff(btnode* bst);

btnode* RotateLL(btnode* bst);
btnode* RotateRR(btnode* bst);
btnode* RotateRL(btnode* bst);
btnode* RotateLR(btnode* bst);

