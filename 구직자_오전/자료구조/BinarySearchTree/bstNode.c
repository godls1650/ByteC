#include "bstNode.h"

bstnode* initbstNode() {
	bstnode* temp = ALLOC(bstnode, 1);
	temp->key = 0;
	temp->Right = temp->Left = NULL;
	return temp;
}

bstnode* setData(int _key) {
	bstnode* temp = initbstNode();
	temp->key = _key;
	return temp;
}
int KeyCmp(const bstnode* sub, int value) {
	if (sub->key > value) return -1;
	else if (sub->key < value) return 1;
	else return 0;
}