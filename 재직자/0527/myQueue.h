#pragma once
#include "framework.h"

typedef struct Queue {
	char** arr; // 10���� ���ڿ�
	int Size;
	int rear; // �Է��ϴ� �������� �ε���
	int front;// ������ �������� �ε���
}queue;
queue * initQueue(int Size);

boolean QisEmpty(const queue*);
boolean QisFull(const queue*);

void enQueue(queue* , const char * const);
char* deQueue(queue*);