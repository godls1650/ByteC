/*	FILE NAME : Node.c
	PURPOSE : Node.h 's Struct  and Function Define
	CREATION DATE : 2020 -05 -07
	LATELY EDIT DATE : 2020 -05 -07
	LATELY EDIT MANAGER : ³ª  */


#include "Node.h"
#define _TWIN_LINKED_LIST
node* initNode()
{
	node* temp = (node*)malloc(sizeof(node*));
	temp->m_nData = 0;
	temp->pNext = NULL;
#ifdef _TWIN_LINKED_LIST
	temp->pNext = NULL;
#endif
	return temp;
}

void setData(node** pTarget, int value){
	if (*pTarget != NULL) {
		node* Cursor = *pTarget;
		Cursor->m_nData = value;
	}
	else {
		return ~value + 1;
	}
	return;
}

void viewNode(const node* Target){
	if (Target != NULL)
		printf("%d ", Target->m_nData);
	else
		return;
	return;
}

int getData(const node* Target)
{
	if (Target != NULL)
		return Target->m_nData;
}
