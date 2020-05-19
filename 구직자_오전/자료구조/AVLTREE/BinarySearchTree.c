#include "BinarySearchTree.h"


void BSTMakeAndInit(btnode** pRoot) { *pRoot = NULL;  }
int BSTGetNodeData(btnode* bst) { return getData(bst); }
void BSTInsert(btnode** pRoot, int data) {
	btnode* pNode = NULL; // parent
	btnode* cNode = *pRoot;// current node
	btnode* nNode = NULL; //  newNode

	while (cNode != NULL) {
		if (data == getData(cNode))
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

	Rebalance(pRoot);
}
btnode* BSTSearch(btnode* bst, int target) {
	btnode* cNode = bst;
	int cd = 0;
	while (cNode != NULL) {
		cd = getData(cNode);
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

		delData = getData(dNode);
		setData(dNode, getData(mNode));

		if (getLeftSubTree(mpNode) == mNode) changeLeftSubTree(mpNode, getRightSubTree(mNode));
		else changeRightSubTree(mpNode, getRightSubTree(mNode));

		dNode = mNode;
		setData(dNode, delData);
	
	}
	if (getRightSubTree(pVRoot) != *pRoot)
		*pRoot = getRightSubTree(pVRoot);

	free(pVRoot);

	Rebalance(pRoot);
	return dNode;
}
void PrintForm(int data) {
	printf("%d ", data);
}
void BSTShowAll(btnode* bst) {
	InorderTraverse(bst,PrintForm);
}
