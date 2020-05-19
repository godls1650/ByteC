#include "binaryTree.h"

btnode* makeBTnode(void) {
	btnode* temp = (btnode*)malloc(sizeof(btnode));
	temp->Left = temp->Right = NULL;
	temp->data = 0;
	return temp;
}
int getData(btnode* bt) { return bt->data; }
void setData(btnode* bt, int value) { bt->data = value; }
btnode* getLeftSubTree(btnode* bt) { return bt->Left; }
btnode* getRightSubTree(btnode* bt) { return bt->Right; }

void MakeLeftSubTree(btnode* _Origin, btnode* sub) {
	if (_Origin->Left != NULL)
		free(_Origin->Left);
	_Origin->Left = sub;
}

void MakeRightSubTree(btnode* _Origin, btnode* sub) {
	if (_Origin->Right != NULL)
		free(_Origin->Right);
	_Origin->Right = sub;
}

void PreorderTraverse(btnode* bt, VisitFuncName act) {
	if (bt == NULL) return;
	act(bt->data);
	PreorderTraverse(bt->Left, act);
	PreorderTraverse(bt->Right, act);
}
void InorderTraverse(btnode* bt, VisitFuncName act) {
	if (bt == NULL) return;
	InorderTraverse(bt->Left, act);
	act(bt->data);
	InorderTraverse(bt->Right, act);
}
void PostorderTraverse(btnode* bt, VisitFuncName act) {
	if (bt == NULL) return;
	PostorderTraverse(bt->Left, act);
	PostorderTraverse(bt->Right, act);
	act(bt->data);
}

btnode* removeLeftSubTree(btnode* bt) {
	btnode* delnode = NULL;
	if (bt != NULL) {
		delnode = bt->Left;
		bt->Left = NULL;
	}
	return delnode;
}
btnode* removeRightSubTree(btnode* bt) {
	btnode* delnode = NULL;
	if (bt != NULL) {
		delnode = bt->Right;
		bt->Right = NULL;
	}
	return delnode;
}
void changeLeftSubTree(btnode* _Origin, btnode* sub) { _Origin->Left = sub; }
void changeRightSubTree(btnode* _Origin, btnode* sub) { _Origin->Right = sub; }
