#include "myStack.h"
stack* initStack(int Size) {
	stack* temp = (stack *)malloc(sizeof(stack));
	temp->arr = (char**)calloc(Size, sizeof(char*));

	for (int i = 0; i < Size; i++) {
		temp->arr[i] = (char*)malloc(20);
		memset(temp->arr[i], 0, 20);
	}
	temp->Size = Size;
	temp->Top = -1;
	return temp;
}


boolean isEmpty(const stack * target) {
	if (target->Top == -1) return TRUE;
	else return FALSE;
}
boolean isFull(const stack * target) {
	if (target->Top == (target->Size-1)) return TRUE;
	else return FALSE;
}
void Push(stack* pStack, FILE* fp) {
	char get[20] = { 0 };// 파일에서 읽어온 값 저장
	int index = pStack->Top;
	if (isFull(pStack)) return;

	fgets(get, 19, fp);
	index++;
	strcpy(pStack->arr[index], get);
	pStack->Top = index;
	return;
}
char* Pop(stack* pStack) {
	char* temp = NULL;
	int index = 0;
	if (isEmpty(pStack)) return NULL;
	index = pStack->Top;
	temp = (char*)malloc(strlen(pStack->arr[index]) + 1);
	strcpy(temp, pStack->arr[index]);
	pStack->Top = index - 1;
	return temp;
}
