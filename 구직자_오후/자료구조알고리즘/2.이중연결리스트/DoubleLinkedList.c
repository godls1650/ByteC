#include "DoubleLinkedList.h"

dlist* createList(int _capacity) {
	dlist* locallist = (dlist*)malloc(sizeof(dlist));// dlist ����ü ũ��� heap�� �Ҵ�.
	// initialize member variable
	locallist->m_pHead = initNode();
	locallist->m_pTail = initNode();
	locallist->m_nSize = 0;
	locallist->m_nCapacity = _capacity;
	// link connect head & tail
	
	locallist->m_pHead->m_pNext = locallist->m_pTail; //[head] �� [tail]
	//tail->prev
	locallist->m_pTail->m_pPrev = locallist->m_pHead; //[head] �� [tail]

	return locallist;
}
bool ListisEmpty(const dlist* _cplist) {
	if (_cplist->m_nSize == 0)
		//== if(cplist->m_pHead->m_pNext = cplist->m_pTail)
		//== if(cplist->m_pTail->m_pPrev = cplist->m_pHead)
		return true;
	else return false;
}
bool ListisFull(const dlist* _cplist) {
	return (_cplist->m_nSize == _cplist->m_nCapacity) ? true : false;
}


bool appendList(dlist* _plist, int _value) {
	node* cursor = NULL;
	node* newNode = NULL;
	if (ListisFull(_plist)) return false;

	newNode = initNode();
	setNodeData(newNode, _value);
	cursor = _plist->m_pTail->m_pPrev;

	/*
		[head]��[node]��[node]��[node]��[NODE]��[tail]
									  ��cursor
									[newNode]

	[head]��[node]��[node]��[node]��[cursor]��[newNode]��[tail]  */

	                                   //           [newNode]��
	newNode->m_pNext = cursor->m_pNext;//..[node]��[Cursor]��[tail]
							  	//         ��[newNode]��
	newNode->m_pPrev = cursor;//..[node]��[Cursor]��[tail]
	cursor->m_pNext->m_pPrev = newNode;	//         ��[newNode]��
	cursor->m_pNext = newNode;//    (Tail )->m_pPrev			   //..[node]��[Cursor]�� [tail]
}// ���� ���Ḯ��Ʈ�� ���� ���� �ð� ���� 
// ���߿��� �Է� : O(1)  <  ���� ���� �Է� : O(N)


void viewList(const dlist* _cplist, int _sw) {
	int sw = _sw;
	node* cursor = NULL;
	
	switch (sw) {
	case ASC:
		cursor = _cplist->m_pHead->m_pNext;
		while (cursor == _cplist->m_pTail) {
			viewNode(cursor);
			cursor = cursor->m_pNext;
		}
		break;
	case DESC:
		cursor = _cplist->m_pTail->m_pPrev;
		while (cursor == _cplist->m_pHead) {
			viewNode(cursor);
			cursor = cursor->m_pPrev;
		}
		break;
	}
	return;
}

int deleteNode(dlist* plist, int position) {
	node* cursor = NULL;
	int data = 0;
	if (position >= plist->m_nSize / 2) {
		cursor = plist->m_pTail;
		for (int i = 0; i < plist->m_nSize - position; i++)
			cursor = cursor->m_pPrev;
	}
	else {
		cursor = plist->m_pHead;
		for (int i = 0; i < position; i++) {
			cursor = cursor->m_pNext;
		}
	}
	data = cursor->m_nData;

	// ���� ����� �������� ���� ��带 ���� ����

	cursor->m_pNext->m_pPrev = cursor->m_pPrev;
	cursor->m_pPrev->m_pNext = cursor->m_pNext;
	free(cursor);
	return data;
}
bool insertNode(dlist* plist, int position, int value) {
	node* cursor = NULL;
	node* newNode = NULL;

	if (position >= plist->m_nSize / 2) {
		cursor = plist->m_pTail;
		for (int i = 0; i < plist->m_nSize - position; i++)
			cursor = cursor->m_pPrev;
	}
	else {
		cursor = plist->m_pHead;
		for (int i = 0; i < position; i++) {
			cursor = cursor->m_pNext;
		}
	}

	newNode = initNode();
	setNodeData(newNode, value);

	newNode->m_pPrev = cursor->m_pPrev;
	newNode->m_pNext = cursor;

	cursor->m_pPrev->m_pNext = newNode;
	cursor->m_pPrev = newNode;
	return true;
}

void push_Back(dlist* plist, int value) {
	appendList(plist, value);
}

void push_Front(dlist* plist, int value) {
	node* cursor = NULL;
	node* newNode = initNode();
	setNodeData(newNode, value);
	cursor = plist->m_pHead;

	newNode->m_pNext = cursor->m_pNext;
	newNode->m_pPrev = cursor;
	cursor->m_pNext->m_pPrev = newNode;
	cursor->m_pNext = newNode;


}
int pop_Back(dlist* plist) {
	int data = 0;
	node* cursor = plist->m_pTail->m_pPrev;

	data = cursor->m_nData;
	cursor->m_pPrev->m_pNext = cursor->m_pNext;
	cursor->m_pNext->m_pPrev = cursor->m_pPrev;
	return data;
}
int pop_Front(dlist* plist) {
	int data = 0;
	node* cursor = plist->m_pHead->m_pNext;

	data = cursor->m_nData;
	cursor->m_pPrev->m_pNext = cursor->m_pNext;
	cursor->m_pNext->m_pPrev = cursor->m_pPrev;
	return data;
}












int seekList(const dlist*, int);
int pickList(const dlist*, int);