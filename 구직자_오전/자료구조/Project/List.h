#pragma once
#include "framework.h"
#include "myNode.h"

typedef struct _LIST {
	node* head;
	node* tail;
	int length; // <- �̰� ��ü ������ ���� ��
}list;

list* initList();// ����Ʈ �ʱ�ȭ �Լ�
int appendNode(list ** target); // ��� �߰�

// ����Ʈ ������ ��� ����Լ�
void destroyList(list * target);
void recur_destroyList(node* tNode);



