#include "framework.h"
/* 데이터 구조를 활용
	[A][B][C][][][]
	선착순 : First In First Out 선입선출	: QUEUE
	output -> A, B ,C
	최근 등록순 : Last In First Out   : STACK
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
	int lines = 0;// 라인 수만큼 증가할 변수
	char c = 0; // 파일의 글자를 하나씩 읽어올 변수
	FILE* dream = fopen(filename, "r");
	if (dream == NULL) { // 파일 읽기 실패
		printf("해당 파일이 없거나 불러오는데 실패했습니다.\n");
		return -1;
	}
	while (!feof(dream)) {// 현재 파일포인터의 위치가 파일의 끝이 아니면
		c = fgetc(dream);// 파일에서 문자 하나를 읽어온다.
		if (c == '\n') { // c의 값이 \n(enter) 면
			lines++; // 라인 수를 증가.
		}
	}
	return lines;
}