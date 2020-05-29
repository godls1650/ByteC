#include "myQueue.h"
queue* initQueue(int Size) {
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->arr = (char**)calloc(Size, sizeof(char*));
	temp->Size = Size + 1;
	temp->rear = temp->front = 0;
	for (int i = 0; i < Size+1; i++) {
		temp->arr[i] = (char*)malloc(20);
		memset(temp->arr[i], 0, 20);
	}
	return temp;
}
boolean QisEmpty(const queue* pQ) {
	if (pQ->rear == pQ->front) return TRUE;
	else return FALSE;
}
boolean QisFull(const queue* pQ) {
	if ((pQ->rear + 1) % pQ->Size == pQ->front)return TRUE;
	else return FALSE;
}

void enQueue(queue* pQ, const char* const str) {
	int i = 0;
	if (QisFull(pQ)) return;
	i = (pQ->rear + 1) % pQ->Size;
	strcpy(pQ->arr[i], str);
	pQ->rear = i;
	return;
}
char* deQueue(queue* pQ) {
	char* temp = NULL;
	int i = 0;
	if (QisEmpty(pQ)) return NULL;
	i = (pQ->front + 1) % pQ->Size;

	temp = (char*)malloc(strlen(pQ->arr[i]) + 1);
	strcpy(temp, pQ->arr[i]);
	pQ->front = i;
	return temp;
}