#include "myString.h"

char* copyStr(const char* const _Source)// setPage마지막 동적할당 함수
{
	char* temp = NULL;
	int len = strlen(_Source);
	temp = (char*)malloc(len + 1);
	strcpy(temp, _Source);
	return temp;
}
char* setPageText() // 데이터 입력부분
{
	int c = 0;
	int i = 0;
	char str[BUFFER] = { 0 };
	char* rtData = NULL;
	while (1) {
		c = getch();
		if (c == KM_ESC) {
			system("cls");
			break;
		}
		else if (c == KM_ENTER) {
			str[i++] = '\n';
			printf("\n");
		}
		else if (c == KM_BS && i > 0) {
			i--;
			str[i] = 0;
			system("cls");
			printf("%s",str);
			
			
		}
		else if (c == KM_TAB) {
			str[i++] = '\t';
			printf("\t");
		}
		else {
			str[i++] = c;
			printf("%c", c);
		}
	}
	rtData = copyStr(str);

	return rtData;
}

