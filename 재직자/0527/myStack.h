#pragma once
#include "framework.h"



typedef struct STACK {
	char ** arr; // 10���� ���ڿ�
	int Size;
	int Top;
}stack;

stack* initStack(int Size);

boolean isEmpty(const stack *);
boolean isFull(const stack*);

void Push(stack * , FILE * );
char* Pop(stack * );

