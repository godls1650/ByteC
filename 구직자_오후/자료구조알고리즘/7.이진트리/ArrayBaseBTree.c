#include "ArrayBaseBTree.h"

btree* initBTree(int Size)
{
	btree* temp = (btree*)malloc(sizeof(btree));
	temp->storage = (Node*)calloc(TREE_SIZE, sizeof(Node));
	temp->cur = 1; // �Է� ��� == 1�� �ε��� 
	return temp;
}
void FreeTree(btree* block) {
	erase_Tree(block);
	free(block->storage);
}
void addData(btree* block, Node value)
{
	if (block->cur == TREE_SIZE) {
		printf("Tree is Full\n");
		return;
	}
	/* ���� ���� Ʈ�� �Է� */
	block->storage[block->cur] = value;
	block->cur += 1;
}

void erase_Tree(btree* block){
	while (block->cur != 1) {
		block->cur -= 1;
	}
}

int getLeftChild(int Pos)
{
	return Pos * 2;
}

int getRightChild(int Pos)
{
	return Pos * 2 + 1;
}
void PreOrder(const btree* target, int index) {// index  =  1;
	printf("%d ", target->storage[index]);
	
	
		if (target->storage[getLeftChild(index)] != 0  && getLeftChild(index) < TREE_SIZE) {
			// ���� �ڽ� ���
			PreOrder(target, getLeftChild(index));
		}
		if (target->storage[getRightChild(index)] != 0 && getRightChild(index) < TREE_SIZE) {
			// ������ �ڽ� ���
			PreOrder(target, getRightChild(index));
		}
	
}


void PostOrder(const btree* target, int index) {// index  =  1;
	if (target->storage[getLeftChild(index)] != 0 && getLeftChild(index) < TREE_SIZE) {
		// ���� �ڽ� ���
		PostOrder(target, getLeftChild(index));
	}
	if (target->storage[getRightChild(index)] != 0 && getRightChild(index) < TREE_SIZE) {
		// ������ �ڽ� ���
		PostOrder(target, getRightChild(index));
	}
	printf("%d ", target->storage[index]);
}

void InOrder(const btree* target, int index) {// index  =  1;
	if (target->storage[getLeftChild(index)] != 0 && getLeftChild(index) < TREE_SIZE) {
		// ���� �ڽ� ���
		InOrder(target, getLeftChild(index));
	}
	
	printf("%d ", target->storage[index]);
	
	if (target->storage[getRightChild(index)] != 0 && getRightChild(index) < TREE_SIZE) {
		// ������ �ڽ� ���
		InOrder(target, getRightChild(index));
	}
}