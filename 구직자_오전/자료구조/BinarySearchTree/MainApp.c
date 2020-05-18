#include "BinarySearchTree.h"
#include <time.h>
int main() {
	srand(time(NULL));
	BSTree* tree = initBST(5);
	insertRecur(tree, 7);
	insertRecur(tree, 2);
	insertRecur(tree, 3);
	insertRecur(tree, 9);
	insertRecur(tree, 1);
	insertRecur(tree, 6);
	insertRecur(tree, 0);
	insertRecur(tree, 4);
	insertRecur(tree, 8);

	


	Travel(tree, PreOrder);
	printf("\n");
	int count = searchData(tree, 9);
	if (count == -1) {
		printf("�����Ͱ� Ʈ���� ����.\n");
	}
	else {
		printf("%dȸ �˻� �� ���� ã�´�.\n", count);
	}

	deleteNode(tree, 7);
	Travel(tree, PreOrder);
	printf("\n");
	return 0;
}

