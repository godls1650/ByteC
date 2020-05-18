#include "btree.h"

int main() {
	bTree * t1 = initTree('A');
	//for(int i = 0 ; i < 10; i++)
	insertNode(t1, 'B');
	insertNode(t1, 'C');
	insertNode(t1, 'D');
	insertNode(t1, 'E');
	insertNode(t1, 'F');
	insertNode(t1, 'G');
	insertNode(t1, 'H');
	insertNode(t1, 'I');
	insertNode(t1, 'J');
	insertNode(t1, 'K');

	printf("전위 순회 : ");
	bTreeTravel(t1, PrevOrderTravel);	 // 전위 순회
	printf("\n중위 순회 : ");
	bTreeTravel(t1, InOrderTravel);	 // 중위 순회
	printf("\n후위 순회 : ");
	bTreeTravel(t1, PostOrderTravel); // 후위순회


	return 0;
}