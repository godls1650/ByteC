#pragma once
#include "framework.h"

typedef struct Queue {
	char** arr; // 10개의 문자열
	int Size;
	int rear; // 입력하는 데이터의 인덱스
	int front;// 빼내는 데이터의 인덱스
}queue;
queue * initQueue(int Size);

boolean QisEmpty(const queue*);
boolean QisFull(const queue*);

void enQueue(queue* , const char * const);
char* deQueue(queue*);