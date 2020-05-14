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

	printf("���� ��ȸ : ");
	bTreeTravel(t1, PrevOrderTravel);	 // ���� ��ȸ
	printf("\n���� ��ȸ : ");
	bTreeTravel(t1, InOrderTravel);	 // ���� ��ȸ
	printf("\n���� ��ȸ : ");
	bTreeTravel(t1, PostOrderTravel); // ������ȸ


	return 0;
}