#include "TNode.h"

tnode* initNode() {
	tnode* temp = (tnode*)malloc(sizeof(tnode));
	temp->m_cData = 0;
	temp->Parent = NULL;
	temp->Sibling = NULL;
	temp->Child = NULL;
	temp->level = 0;
	return temp;
}
int setData(tnode * target, char text) {
	if (target != NULL) { // tnode �� null �� �ƴϸ�
		target->m_cData = text; // ������ �Է�
		return 1; 
	}
	return -1; // ���� �� -1 ����
}
