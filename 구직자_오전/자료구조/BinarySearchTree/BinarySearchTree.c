#include "BinarySearchTree.h"

BSTree* initBST(int RootKey) {
	BSTree* temp = ALLOC(BSTree, 1);
	temp->Root = setData(RootKey);
	return temp;
}

void insertNode(BSTree* sub, int value) {
	bstnode* cursor = sub->Root;
	
	while (TRUE) {
		if (KeyCmp(cursor, value) == -1) {
			if (cursor->Left == NULL) {
				cursor->Left = setData(value);
				break;
			}
			else {
				cursor = cursor->Left;
				continue;
			}
		}
		else if (KeyCmp(cursor, value) == 1) {
			if (cursor->Right == NULL) {
				cursor->Right = setData(value);
				break;
			}
			else {
				cursor = cursor->Right;
				continue;
			}
		}
		else {
			printf("키값이 중복입니다. \n");
			return;
		}
	}
	return;
}

void insertRecur(BSTree* sub, int value) {
	if (innerRecur(sub->Root, value) == NULL) {
		printf("%d is already exist\n", value);
	}

}
bstnode* innerRecur(bstnode* root, int value) {
	if (KeyCmp(root, value) == -1) {
		if (root->Left != NULL)
			return innerRecur(root->Left, value);
		else {
			root->Left = setData(value);
			return root->Left;
		}
	}
	else if (KeyCmp(root, value) == 1) {
		if (root->Right != NULL)
			return innerRecur(root->Right, value);
		else {
			root->Right = setData(value);
			return root->Right;
		}
	}
	else {
		return NULL;
	}
}


void Travel(const BSTree* sub, void (*OrderFunc)()) {
	OrderFunc(sub->Root);
}
void PreOrder(const bstnode* root) {
	printf("%2d ", root->key);
	if (root->Left != NULL) { 
		printf("{ ");
		PreOrder(root->Left); 
	}
	if (root->Right != NULL) {
		printf(", ");
		PreOrder(root->Right);
		printf("}");
	}
}
void InOrder(const bstnode* root) {
	if (root->Left != NULL)InOrder(root->Left);
	printf("%2d ", root->key);
	if (root->Right != NULL)InOrder(root->Right);
}
void PostOrder(const bstnode* root) {
	if (root->Left != NULL)PostOrder(root->Left);
	if (root->Right != NULL)PostOrder(root->Right);
	printf("%2d ", root->key);
}

int searchData(const BSTree* sub, int search) {
	bstnode* cursor = sub->Root;
	int cnt = 0;
	while (TRUE) {
		if (cursor == NULL) {
			return -1;
		}
		//-------------------------------------
		if (cursor->key > search) {
			cnt++;
			cursor = cursor->Left;
		}
		else if (cursor->key < search) {
			cursor = cursor->Right;
			cnt++;
		}
		else{
			return cnt;
		}
	}
}

void uninstallTree(BSTree* sub) {
	innerUninstall(sub->Root);
}

void innerUninstall(bstnode* root) {
	if (root->Left != NULL) {
		innerUninstall(root->Left);
	}
	if (root->Right != NULL) {
		innerUninstall(root->Right);
	}
	free(root);
}

void deleteNode(BSTree* sub, int value) {
	
}