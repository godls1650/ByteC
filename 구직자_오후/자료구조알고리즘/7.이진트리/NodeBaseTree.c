#include "NodeBaseTree.h"

bst* initBSTree(void) {
	bst* temp = (bst*)malloc(sizeof(bst));
	temp->root = NULL;
}
bool bst_isThere(bst* block, int item) {
	btnode* cursor = block->root;
	while (true) {
		if (cursor->Key == item) {
			return true;
		}
		if (cursor->Key < item) {
			if (cursor->Right == NULL)
				return false;
			cursor = cursor->Right;
		}
		else {
			if (cursor->Left == NULL)
				return false;
			cursor = cursor->Left;
	
		}
	}
}
void bst_addNode(bst* block, int item) {
	btnode* newNode = NULL;
	btnode* cursor = NULL;
	// �߰� ��ġ�� TREE : ROOT�� ��� 
	if (block->root == NULL) {
		newNode = setNode(item);
		block->root = newNode;
		return;
	}
	if (bst_isThere(block, item)) {
		printf("%d already exist Tree\n", item);
		return;
	}
	// �´� ��ġ�� ��带 ã�ư��� �Է�
	newNode = setNode(item);
	cursor = block->root;

	while (1) {
		if (cursor->Key < item) {
			if (cursor->Right == NULL) {
				cursor->Right = newNode;
				return;
			}
			cursor = cursor->Right;
		}
		else {// cursor->key > item 
			if (cursor->Left == NULL) {
				cursor->Left = newNode;
				return;
			}
			cursor = cursor->Left;
		}
	}
}

void bst_PreOrder(btnode* cursor) {
	cursor->Key += 10;
	if (cursor->Left != NULL) bst_PreOrder(cursor->Left);
	if (cursor->Right != NULL)bst_PreOrder(cursor->Right);
	return;
}
void bst_PostOrder(btnode* cursor) {
	if (cursor->Left != NULL) bst_PostOrder(cursor->Left);
	if (cursor->Right != NULL)bst_PostOrder(cursor->Right);
	printf("%d ", cursor->Key);
	return;
}
void bst_InOrder(btnode* cursor) {
	if (cursor->Left != NULL) bst_InOrder(cursor->Left);
	printf("%d ", cursor->Key);
	if (cursor->Right != NULL)bst_InOrder(cursor->Right);
	return;
}

void bst_Orderring(const bst* block, orderFunc order) {
	order(block->root);
}

void uninstallBST(bst* block) {
	postOrderDelete(block->root);
}

void postOrderDelete(btnode* cursor) {
	if (cursor->Right != NULL) postOrderDelete(cursor->Right);
	if (cursor->Left != NULL) postOrderDelete(cursor->Left);
	free(cursor);

}