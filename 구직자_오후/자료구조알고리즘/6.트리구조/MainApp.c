#include "myTree.h"

int main() {
	tree* tr = initTree("A");// root => A
	addNode(moveNode(&(tr->now)), "B");
	addNode(moveNode(&(tr->now)), "C");
	addNode(moveNode(&(tr->now)), "D");
	addNode(moveNode(&(tr->now)), "E");
	addNode(moveNode(&(tr->now)), "F");
	addNode(moveNode(&(tr->now)), "G");
	addNode(moveNode(&(tr->now)), "H");
	viewElements(tr);
	// �������� ���� �߰��� ���� �̵� 
}