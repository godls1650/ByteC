#include "BinarySearchTree.h"


void BSTMakeAndInit(btnode** pRoot) { *pRoot = NULL;  }
int BSTGetNodeData(btnode* bst) { return getData(bst); }
void BSTInsert(btnode** pRoot, int data) {
	btnode* pNode = NULL; // parent
	btnode* cNode = *pRoot;// current node
	btnode* nNode = NULL; //  newNode

	while (cNode != NULL) {
		if (data == getData(cNode))
			return; // Ű�� �ߺ�
		pNode = cNode; // �θ��� = cNode�� ���� ��
		if (getData(cNode) > data)
			cNode = getLeftSubTree(cNode);// ���� ����� ���� ����Ʈ���� �̵�
		if (getData(cNode) < data)
			cNode = getRightSubTree(cNode);// ���� ����� ���� ����Ʈ���� �̵�
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
	btnode* pVRoot = makeBTnode();// ������ ��Ʈ ���
	btnode* pNode = pVRoot; // �θ���
	btnode* cNode = *pRoot; // ���� ���
	btnode* dNode = NULL; // �������

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
