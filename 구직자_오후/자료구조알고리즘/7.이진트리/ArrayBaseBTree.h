#pragma once
/*�迭 ��� ����Ʈ�� ADT*/
#include "framework.h"
#define TREE_SIZE	16	
/* �迭 ��� ����Ʈ���� ���
[0] �ε����� Root �� ��  -> Left[1]   | Right[2]  --> x*2 + 1    |  (x+1)*2    
[1] �ε����� SubTreeRoot �� ��  -> Left[3]   | Right[4]  --> x*2 + 1    |  (x+1)*2

[1] �ε����� Root �� ��  -> Left[2]   | Right[3]  --> x*2    |  x*2+1

�ε��� ������ ������ �ϱ����� 1���ε����� Root�� �Ѵ�.  [0]�� ��� ����

Tree ���� ��ü�� ũ�� --> ���̰� 0�� ����� �ִ� ���� : 1	 Ʈ�� ��ü��� ���� : 1	2^1 - 1 +1
                     --> ���̰� 1�� ����� �ִ� ���� : 2   Ʈ�� ��ü��� ���� : 3	2^2 - 1	+1
					 --> ���̰� 2�� ����� �ִ� ���� : 4   Ʈ�� ��ü��� ���� : 7	2^3 - 1	+1
					 --> ���̰� 3�� ����� �ִ� ���� : 8   Ʈ�� ��ü��� ���� : 15	2^4 - 1	+1
*/
typedef int Node;
typedef struct _BinaryTree {
	Node* storage;  // 1 ~ 15�ε��� ���� 15���� �����͸� ����
	int cur; // ������ �Էµ� �ε���
}btree;

btree* initBTree(int Size);
void addData(btree * block, Node value);
void erase_Tree(btree* block);
void FreeTree(btree* block);

int getLeftChild(int Pos);
int getRightChild(int Pos);

void PreOrder	(const btree* target, int index); /* ���� ��ȸ   :  Root -> Left -> Right  */
void PostOrder	(const btree* target, int index); /* ���� ��ȸ  :  Left -> Right-> Root   */
void InOrder	(const btree* target, int index); /* ���� ��ȸ    :  Left -> Root -> Right  */