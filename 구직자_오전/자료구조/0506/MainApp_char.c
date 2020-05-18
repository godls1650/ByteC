#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define KM_ENTER 13
#define KM_TAB 9
#define KM_BS	8
#define KM_ESC 27
int main() {
	int c = 0;
	char str[257] = { 0 };
	int index = 0;

	while (1) {
		c = getch();
		//printf("c : %d\n", c);
		if (c == KM_ENTER) {
			
			printf("\n");
			if (index < 256)
				str[index++] = '\n';
		}
		else if (c == KM_BS && index > 0) {

			str[index--] = 0;
		}
		else if (c == KM_TAB) {
			printf("\t");
			if (index < 256)
				str[index++] = '\t';
		}
		else if (c == KM_ESC) {
			break;
		}
		else {
			if (index < 256)
				printf("%c", c);
			str[index++] = c;
		}

	}
	printf("입력된 글 \n %s\n", str);


	return 0;
}