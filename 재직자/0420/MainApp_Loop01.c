#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*조건 결과를 기준으로 반복 여부를 결정 */
//while 문 최소 반복 횟수 : 0
//do ~ while 최소 반복 횟수 : 1
int main() {
	int word = 0; // 단어 갯수   time is running out\n 
	int text = 0; // 글자 갯수
	char c = 0;
	printf("문장 입력 > ");
	while (c != '\n') {
		scanf("%c", &c);
		if (c == ' ' || c == '\n') {
			if (c == ' ') text++;
			word++;
		}
		else
			text++;

		/*
		switch (c) {
		case '\n': case ' ':
			word++;
			text++;
			break;
		default :
			text++;
			break;
		
		}*/
		//if (c == '\n')break;
	}
	
	printf("글자수 : %d  단어 수 : %d\n", text, word);
	

	return 0;
}