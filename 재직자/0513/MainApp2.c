#include "framework.h"

/*
	문자열을 입력받는 프로그램을 작성하세요.
	
	1. 문자열 입력  2. 데이터 출력  3. 종료
	
	저장할 수 있는 문자열의 갯수 : 미정
	한 문자열의 길이 : 미정 

*/

char* inputString(const char* const _form) {
	char str[128] = { 0 };
	char* temp = NULL;
	printf(_form);
	gets(str);
	temp = (char*)malloc(strlen(str) + 1);

	strcpy(temp, str);
	return temp;
}

int main() {
	int menu = 0;
	char** wordList = NULL;
	int count = 1;
	int x = 10, y = 4516, z = 2900;
	wordList = (char**)calloc(count, sizeof(char*));
	// 입출력 버퍼 (입력버퍼 stdin  출력 버퍼  stdout)
	FILE* fp = NULL;
	fp = fopen("testFile.txt", "w"); //
	fprintf(fp, "%03d-%04d-%04d\n",x,y,z);
	fclose(fp);

	fp = fopen("testFile.txt", "r");
	fscanf(fp, "%*c%d", &x);
	fscanf(fp, "%*c%d", &y);
	fscanf(fp, "%*c%d", &z);
	printf("testFile에서 읽은 문장 : %03d-%04d-%04d\n", x,y,z);
	fclose(fp);
	system("pause");
	int index = 0;
	while (menu != 3) {
		system("cls");
		printf("1. 문자열 입력  2. 문자열 출력  3. 프로그램 종료 \nselect >");
		scanf("%d", &menu);
		while (getchar() != '\n');
		switch (menu) {
		case 1:
			if (wordList[count - 1] != NULL) {
				count++;
				wordList = (char**)realloc(wordList, sizeof(char*) * count);
				wordList[count - 1] = NULL;
 			}
			wordList[count - 1] = inputString("input string > ");
			break;
		case 2:
			index = 0;
			while (menu != 0) {
				system("cls");
				printf("%s\n", wordList[index]);//첫번째 문자열을 출력한다.
				printf("1. prev   2.next  0.exit \n select >");
				scanf("%d", &menu);
				while (getchar() != '\n');
				if (menu == 1) {
					if (index == 0) {
						printf("\a첫 문자열입니다.\n");
						system("pause");
						continue;
					}
					else
						index--;
				}
				else if (menu == 2) {
					if (index + 1 == count) {
						printf("\a마지막 문자열입니다.\n");
						system("pause");
						continue;
					}
					else
						index++;
				}
				else if (menu == 3)
					break;
				
			}
			break;
		case 3:
			return 0;
		}

	}

	free(wordList);
	return 0;
}

