#include "btree.h"

bTree* initTree(int data) {
	bTree* temp = (bTree*)malloc(sizeof(bTree));
	temp->root = initNode();
	setNode(temp->root, data);
	temp->check = initQueue(QUE_SIZE);// queue�� queueSize�� �Ҵ�
	enqueue(temp->check, temp->root); // queue�� root �Է�
	return temp;
}

void insertNode(bTree* target, int data) {
	btnode* newNode = initNode();
	queue* cursor = target->check;
	btnode* subRoot = NULL;
	int bEnd = 0;
	setNode(newNode, data);

	while (1) {
		if (getFront(cursor)->Left == NULL) {
			subRoot = getFront(cursor);
			subRoot->Left = newNode;
			newNode->level = subRoot->level + 1;
			break;
		}
		if (getFront(cursor)->Right == NULL) {
			subRoot = getFront(cursor);
			subRoot->Right = newNode;
			newNode->level = subRoot->level + 1;
			break;
		}
		dequeue(cursor);
	}
	
	enqueue(cursor, newNode);// �� ��带 queue�� �Է�
}

void bTreeTravel(const bTree* target, void (*ptr)()) {
	ptr(target->root);
}

void PreOrderTravel(const btnode * target) {
	printf(" %c", target->Data);
	if (target->Left != NULL) {
		printf("{");
		PreOrderTravel(target->Left);
		//printf("2");
	}
	if (target->Right != NULL) { 
		printf(",");
		PreOrderTravel(target->Right); 
		printf("}");
	}
}