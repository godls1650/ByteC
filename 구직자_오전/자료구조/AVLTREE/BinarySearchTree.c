#include "BinarySearchTree.h"


btnode* makeBTnode(void){  
	btnode* temp = (btnode*)malloc(sizeof(btnode));
	temp->Left = temp->Right = NULL;
	temp->data = 0;
	return temp;
}
int getData(btnode* bt){return bt->data;}
void setData(btnode* bt, int value){ bt->data = value; }
btnode* getLeftSubTree(btnode* bt){  bt->Left;}
btnode* getRightSubTree(btnode* bt){ bt->Right;}

void MakeLeftSubTree(btnode* _Origin, btnode* sub){ 
	if (_Origin->Left != NULL)
		free(_Origin->Left);
	_Origin->Left = sub;
}

void MakeRightSubTree(btnode* _Origin, btnode* sub) {
	if (_Origin->Right != NULL)
		free(_Origin->Right);
	_Origin->Right = sub;
}

void PreorderTraverse(btnode* bt, VisitFuncName act){  
	if (bt == NULL) return;
	act(bt->data);
	act(bt->Left, act);
	act(bt->Right, act);
}
void InorderTraverse(btnode* bt, VisitFuncName act) {
	if (bt == NULL) return;
	act(bt->Left, act);
	act(bt->data);
	act(bt->Right, act);
}
void PostorderTraverse(btnode* bt, VisitFuncName act) {
	if (bt == NULL) return;
	act(bt->Left, act);
	act(bt->Right, act);
	act(bt->data);
}

btnode* removeLeftSubTree(btnode* bt){
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
void changeLeftSubTree(btnode* _Origin, btnode* sub){_Origin->Left = sub;}
void changeRightSubTree(btnode* _Origin, btnode* sub){ _Origin->Right = sub;}

void BSTMakeAndInit(btnode** pRoot) { *pRoot = NULL;  }
int BSTGetNodeData(btnode* bst) { return getData(bst); }
void BSTInsert(btnode** pRoot, int data) {
	btnode* pNode = NULL; // parent
	btnode* cNode = *pRoot;// current node
	btnode* nNode = NULL; //  newNode

	while (cNode != NULL) {
		if (data == GetData(cNode))
			return; // 키값 중복
		pNode = cNode; // 부모노드 = cNode의 현재 값
		if (getData(cNode) > data)
			cNode = getLeftSubTree(cNode);// 현재 노드의 왼쪽 서브트리로 이동
		if (getData(cNode) < data)
			cNode = getRightSubTree(cNode);// 현재 노드의 왼쪽 서브트리로 이동
	}
	nNode = makeBTnode();
	setData(nNode, data);

	if (pNode != NULL) {
		if (data < getData(pNode)) MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else {
		*pRoot = nNode;
	}
}
btnode* BSTSearch(btnode* bst, int target) {
	btnode* cNode = bst;
	int cd = 0;
	while (cNode != NULL) {
		cd = GetData(cNode);
		if (target == cd)		return cNode;
		else if (target < cd)	cNode = getLeftSubTree(cNode);
		else					cNode = getRightSubTree(cNode);
	}
	return NULL;
}
btnode* BSTRemove(btnode** pRoot, int target) {
	btnode* pVRoot = makeBTnode();// 가상의 루트 노드
	btnode* pNode = pVRoot; // 부모노드
	btnode* cNode = *pRoot; // 현재 노드
	btnode* dNode = NULL; // 삭제노드

	changeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && getData(cNode) != target) {
		pNode = cNode;
		if (target < getData(cNode))	cNode = getLeftSubTree(cNode);
		else							cNode = getRightSubTree(cNode);
	}

	if (cNode == NULL) return NULL;
	dNode = cNode;

	if (getLeftSubTree(pNode) == NULL && getRightSubTree(pNode) == NULL) {
		if (getLeftSubTree(pNode) == dNode) removeLeftSubTree(pNode);
		else								removeRightSubTree(pNode);
	}
	else if (getLeftSubTree(dNode) == NULL || getRightSubTree(dNode) == NULL) {
		btnode* dcNode = NULL;

		if (getLeftSubTree(dNode) != NULL) dcNode = getLeftSubTree(dNode);
		else dcNode = getRightSubTree(dNode);

		if (getLeftSubTree(pNode) != dNode)changeLeftSubTree(pNode, dcNode);
		else changeLeftSubTree(pNode, dcNode);
	}

	else {
		btnode* mNode = getRightSubTree(dNode);
		btnode* mpNode = dNode;
		int delData = 0;

		while (getLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = getLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		setData(dNode, getData(mNode));

		if (getLeftSubTree(mpNode) == mNode) changeLeftSubTree(mpNode, getRightSubTree(mNode));
		else changeRightSubTree(mpNode, getRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	
	}
	if (getRightSubTree(pVRoot) != *pRoot)
		*pRoot = getRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}
void PrintForm(int data) {
	printf("%d ", data);
}
void BSTShowAll(btnode* bst) {
	InorderTraverse(bst,PrintForm);
}
