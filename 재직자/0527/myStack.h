#pragma once
#include "framework.h"



typedef struct STACK {
	char ** arr; // 10개의 문자열
	int Size;
	int Top;
}stack;

stack* initStack(int Size);

boolean isEmpty(const stack *);
boolean isFull(const stack*);

void Push(stack * , FILE * );
char* Pop(stack * );

