#include "myList.h"
#include "inputUI.h"

list* initList(const char* filename) {
	list* temp = (list*)malloc(sizeof(list));
	temp->head = initNode();
	temp->tail = initNode();
	temp->fin = fopen(filename, "r");

	temp->head->next = temp->tail;
	temp->tail->prev = temp->head;
	return temp;
}
void pushBack(list* plist) {
	node* cursor = plist->tail->prev;
	node* newNode = initNode();
	setNodeData(newNode, plist->fin);
	
	newNode->next = cursor->next;
	newNode->prev = cursor;

	cursor->next->prev = newNode;
	cursor->next = newNode;
}


void setList(list* plist) {
	while(!feof(plist->fin)) {
		pushBack(plist);
	}
}

void viewList(const list* cplist) {
	int c = 0;
	node* cursor = cplist->head->next;
	while (1) {
	system("cls");
	viewNode(cursor);
	if (_kbhit()) {
		c = _getch();
		if (c == 224) {
			c = _getch();
		}
		switch (c) {
		case KB_ESC: return; break;
		case KB_LEFT:
			if (cursor->prev == cplist->head) break;
			else cursor = cursor->prev;
			break;
		case KB_RIGHT:
			if (cursor->prev == cplist->tail) break;
			else cursor = cursor->next;
			break;
		}
		
	}

	}
}
