#include "AVLTree.h"


int GetHeight(btnode* bst) {
	int lHeight = 0;
	int rHeight = 0;

	if (bst == NULL) return 0;

	lHeight = GetHeight(getLeftSubTree(bst));
	rHeight = GetHeight(getRightSubTree(bst));

	if (lHeight > rHeight) return lHeight + 1;
	else return rHeight + 1;
}
int GetHeightDiff(btnode* bst) {
	int left = 0;
	int right = 0;

	if (bst == NULL)
		return 0;
	left = GetHeight(getLeftSubTree(bst));
	right = GetHeight(getRightSubTree(bst));
	return left - right;
}

btnode* RotateLL(btnode* bst) {
	btnode* pNode = NULL;
	btnode* cNode = NULL;

	pNode = bst;
	cNode = getLeftSubTree(pNode);
	//pNode->Left = cNode->Right
	changeLeftSubTree(pNode, getRightSubTree(cNode));
	//cNode->right = pNode;
	changeRightSubTree(cNode, pNode);
	return cNode;
}
btnode* RotateRR(btnode* bst) {
	btnode* pNode = NULL;
	btnode* cNode = NULL;

	pNode = bst;
	cNode = getRightSubTree(pNode);
	//pNode->Right = cNode->Left
	changeRightSubTree(pNode, getLeftSubTree(cNode));
	//cNode->Left = pNode;
	changeLeftSubTree(cNode, pNode);
	return cNode;

}
btnode* RotateRL(btnode* bst) {
	btnode* pNode = NULL;
	btnode* cNode = NULL;
	pNode = bst;
	cNode = getRightSubTree(pNode);

	changeRightSubTree(pNode, RotateLL(cNode)); // LLȸ��
	return RotateRR(pNode); //RRȸ��
}
btnode* RotateLR(btnode* bst) {
	btnode* pNode = NULL;
	btnode* cNode = NULL;
	pNode = bst;
	cNode = getLeftSubTree(pNode);

	changeRightSubTree(pNode, RotateRR(cNode)); // RRȸ��
	return RotateLL(pNode); //LLȸ��
}

btnode* Rebalance(btnode** pRoot) {
	int nDif = GetHeightDiff(*pRoot);
	if (nDif > 1) {// ���� ����Ʈ�� �������� ���̰� 2�̻� �̸�
		if (GetHeightDiff(getLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (nDif < -1) {// ������ ����Ʈ�� �������� ���̰� 2�̻� �̸�
		if (GetHeightDiff(getRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	return *pRoot;
}