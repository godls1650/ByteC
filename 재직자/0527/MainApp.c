#include "framework.h"
/* ������ ������ Ȱ��
	[A][B][C][][][]
	������ : First In First Out ���Լ���	: QUEUE
	output -> A, B ,C
	�ֱ� ��ϼ� : Last In First Out   : STACK
	output -> C, B, A

	A,B,C,D,E
	E D C B A

	A B D C E
	E A B D C

	A B E D C
*/
#include "myStack.h"
#include "myQueue.h"
int countFileLine(const char* const filename);
int main() {
	srand((unsigned int)time(NULL));
	const char* filename = "sool.txt";
	int lineCount = 0;
	lineCount = countFileLine(filename);
	int test = rand() % (lineCount-10) +7;
	FILE* fp = fopen(filename, "r");
	stack* stk1 = initStack(lineCount);
	queue* q1 = initQueue(lineCount);
	int cnt = 0;

	for (int i = 0; i < lineCount; i++) {
		Push(stk1, fp);
		if (i % test < test-(rand()%test+1)) {
			enQueue(q1, Pop(stk1));
			cnt++;
		}
	}
	while(!isEmpty(stk1)) {
		enQueue(q1, Pop(stk1));
	}
	for (int i = 0; i < lineCount; i++) {
		printf("%s", deQueue(q1));
	}
	
	

	return 0;
}
int countFileLine(const char* const filename) {
	int lines = 0;// ���� ����ŭ ������ ����
	char c = 0; // ������ ���ڸ� �ϳ��� �о�� ����
	FILE* dream = fopen(filename, "r");
	if (dream == NULL) { // ���� �б� ����
		printf("�ش� ������ ���ų� �ҷ����µ� �����߽��ϴ�.\n");
		return -1;
	}
	while (!feof(dream)) {// ���� ������������ ��ġ�� ������ ���� �ƴϸ�
		c = fgetc(dream);// ���Ͽ��� ���� �ϳ��� �о�´�.
		if (c == '\n') { // c�� ���� \n(enter) ��
			lines++; // ���� ���� ����.
		}
	}
	return lines;
}