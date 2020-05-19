#include "AVLTree.h"
#include "BinarySearchTree.h"


int main() {

	btnode* avlRoot = NULL;
	btnode* leftNode = NULL;
	btnode* rightNode = NULL;

	BSTMakeAndInit(&avlRoot);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);

	printf("root node key : %d\n", getData(avlRoot));

	leftNode = getLeftSubTree(avlRoot);
	rightNode = getRightSubTree(avlRoot);

	printf("left : %d right : %d\n", getData(leftNode), getData(rightNode));

	leftNode = getLeftSubTree(leftNode);
	rightNode = getRightSubTree(rightNode);

	printf("left : %d right : %d\n", getData(leftNode), getData(rightNode));

	return 0;
}
