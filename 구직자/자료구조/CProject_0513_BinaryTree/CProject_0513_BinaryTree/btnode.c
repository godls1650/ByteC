#include "btnode.h"

btnode* initNode() {
	btnode* temp = (btnode*)malloc(sizeof(btnode));
	temp->Data = 0;
	temp->Left = temp->Right = NULL;
	temp->level = 0;
	return temp;
}
btnode* copyNode(const btnode* source) {
	return source; // ¾èÀºº¹»ç
}
int setNode(btnode* target, int src) {
	if (target == NULL) return -1;
	target->Data = src;
	return 1;
}