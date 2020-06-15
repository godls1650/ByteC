#pragma once
#include "../SingleLinkedList/framework.h"

typedef struct _ArrayBaseStack {
	int* storage;
	int Capacity;
	int Top;
}a_stack;

a_stack* initArrayStack(int _capacity);
// stack ������ �����͸� �Է��ϴ� ���  : Push()
void push(a_stack* _pStack, int _value);
int pop(a_stack * _pStack);
int Seek(const a_stack* _cpStack);

