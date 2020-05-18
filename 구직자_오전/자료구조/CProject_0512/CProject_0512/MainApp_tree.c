#include "Tree.h"

int main() {
	tree* tree1 = setTree('A');
	CreateChild(tree1->root, 'B');
	CreateChild(tree1->root, 'C');
	CreateChild(tree1->root, 'D');
	CreateChild(tree1->root->Child, 'E');
	CreateChild(tree1->root->Child, 'F');
	CreateChild(tree1->root->Child, 'G');
	CreateChild(tree1->root->Child->Sibling, 'H');
	CreateChild(tree1->root->Child->Sibling->Sibling, 'I');
	CreateChild(tree1->root->Child->Sibling->Sibling, 'J');
	CreateChild(tree1->root->Child->Sibling->Sibling, 'K');
	CreateChild(tree1->root->Child->Sibling->Sibling, 'L');
	CreateChild(tree1->root->Child->Sibling->Sibling->Child, 'M');
	CreateChild(tree1->root->Child->Sibling->Sibling->Child, 'N');
	CreateChild(tree1->root->Child->Sibling->Sibling->Child, 'O');

	// A { B { E,F,G},C{H},D{I{M,N,O},J,K,L}}
	printTree(tree1);
	printTree_recur(tree1);
	printf("\n");
	printDir(tree1);

	return 0;
}