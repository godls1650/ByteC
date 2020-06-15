#pragma once
/*btNode.h*/
#include "framework.h"
/*	���� Ž�� Ʈ�� (Binary Search Tree)
    - ��� ���Ҵ� ���� �ٸ� ������ �� (KEY)�� ���´�.
	- ���� ����Ʈ���� ������ ���� �׻� �� ��Ʈ �� ���� �۴�.
	- ������ ����Ʈ���� ������ ���� �׻� �� ��Ʈ �� ���� ũ��.
	- �� ����Ʈ�� ���� ���� Ž�� Ʈ�� ���� �̴�.

	[�̸�][�ֹι�ȣ][����ó][...etc]


*/
typedef struct Binary_Tree_Node {
	int Key; // data  src;  src.ID;
	struct Binary_Tree_Node* Left;
	struct Binary_Tree_Node* Right;
}btnode;

btnode* initNode();
void setData(btnode * block, int item);
btnode* setNode(int item);