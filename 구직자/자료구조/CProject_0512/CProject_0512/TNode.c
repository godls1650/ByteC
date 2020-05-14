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
	if (target != NULL) { // tnode 가 null 이 아니면
		target->m_cData = text; // 데이터 입력
		return 1; 
	}
	return -1; // 실패 시 -1 리턴
}
