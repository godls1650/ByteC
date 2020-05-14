#pragma once
#include "framework.h"
#include "btnode.h"
#define QUE_SIZE	20
typedef struct Queue {
	int length;
	btnode** Storage;
	int rear;
	int front;
}queue;

queue* initQueue(int length);
void enqueue(queue*, btnode*);
void dequeue(queue*);
btnode* getFront(const queue *);
int isEmpty(const queue*);
int isFull(const queue*);