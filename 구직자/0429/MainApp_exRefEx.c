#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE	0x7F 
/*
	���Ͽ���			: fopen();
	���
	�������� �� ����


*/
int main() {
	FILE* fp = NULL;
	char* name = "ȫ�浿";
	int age = 10;
	fp = fopen("test.txt", "a");
	fprintf(fp, "hello world\n");
	fprintf(fp, "%s\t%d\n", name, age);
	fclose(fp);

	char str[100];
	int nage;
	char text[100];
	fp = fopen("test.txt", "r");
	fgets(text, sizeof(text) - 1, fp);
	fscanf(fp, "%s %d", str, &nage);

	printf("%s\n%s\n%d", text, str, nage);
	fclose(fp);
	return 0;
}