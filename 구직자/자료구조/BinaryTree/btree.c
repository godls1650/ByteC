#include "btree.h"

bTree* initTree(int data) {
	bTree* temp = (bTree*)malloc(sizeof(bTree));
	temp->root = initNode();
	setNode(temp->root, data);
	temp->check = initQueue(QUE_SIZE);// queue를 queueSize로 할당
	enqueue(temp->check, temp->root); // queue에 root 입력
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
	
	enqueue(cursor, newNode);// 새 노드를 queue에 입력
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