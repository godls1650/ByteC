#include "HList.h"

List* initList() {
	List* temp = (List*)malloc(sizeof(List));
	temp->head = initNode();
	temp->tail = initNode();
	temp->head->next = temp->tail;
	temp->count = 0;
	return temp;
}
void append(List* pList, const char* str, hashFunc * hash) {
	hNode* newNode = initNode();
	hNode* cursor = pList->head;

	while (cursor->next != pList->tail) {
		if (cursor->data != NULL && strcmp(cursor->data->key, str) == 0) {
			return;
		}
		cursor = cursor->next;
	}
	setData(newNode, str, hash);
	newNode->next = cursor->next;
	cursor->next = newNode;

	return;
}
void printList(const List* pList) {
	hNode* cursor = pList->head->next;
	while (cursor->next != NULL) {
		printf("%s -> ", cursor->data->key);
		cursor = cursor->next;
	}
	printf("^\n");
	return;
}