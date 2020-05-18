#include "myQueue.h"

queue* initQueue(int length) {
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->length = length;
	temp->Storage = (btnode**)calloc(length, sizeof(btnode*));
	temp->front = temp->rear = 0;
	return temp;
}
void enqueue(queue* target, btnode* src) {
	int index = 0;
	if (src == NULL) return;
	if (!isFull(target)) {
		index = (target->rear + 1) % target->length;
		target->Storage[index] = src;
		target->rear = index;
	}
	return;
}
void dequeue(queue* target) {
	int index = 0;
	if (!isEmpty(target)) {
		index = (target->front + 1) % target->length;
		target->front = index;
	}
	else {
		return;
	}
	return;
}
btnode* getFront(const queue* target) {

	return target->Storage[(target->front+1)%target->length];
}
int isEmpty(const queue* target) {
	if (target->rear == target->front) return 1;
	else return 0;
}
int isFull(const queue* target) {
	if ((target->rear + 1 )%target->length == target->front)
		return 1;
	else return 0;
}