#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// �������� 


int stringLength(char * parameter) {
	int len = 0;
	while (parameter[len++] != 0);
	return len - 1;
}
void StringUpper(char* Param) {
	for (int i = 0; i < stringLength(Param); i++) {
		if (Param[i] >= 'a' && Param[i] <= 'z') {
			Param[i] -= 32;
		}
	}
}

void StringLower(char* Param) {
	for (int i = 0; i < stringLength(Param); i++) {
		if (Param[i] >= 'A' && Param[i] <= 'Z') {
			Param[i] += ' ';
		}
	}
}
// � ����� �� ���ΰ�.
/* ���ڿ��� ���̸� ���ϴ� �Լ�
	���ڿ��� ���� : ���� Ÿ��
	���̸� ���ϴ� : ����� ���� 
	int stringLength(char * X){
		int len = ;
		str1�� 0���ε��� ���� ���Ṯ�ڰ� ���� ������ len�� ���� ��Ű�� str1�� ���̰� �ȴ�.
		str2�� 0���ε��� ���� ���Ṯ�ڰ� ���� ������ len�� ���� ��Ű�� str2�� ���̰� �ȴ�.
		[X]�� 0���ε��� ���� ���Ṯ�ڰ� ���� ������ len�� ���� ��Ű�� [X]�� ���̰� �ȴ�.


		return len;
	}

*/

// ���ڿ��� ��� �ҹ��ڸ� �빮�ڷ� �����Ѵ�.
// ���ڿ��� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.

// ���ڿ� ���� �Լ� 
char* stringCopy(char * Destination, const char * Source) {
	int l = stringLength(Source);	// ������ ���������� �� ����
	for (int i = 0; i <= l; i++) {		 // i���� 0 ���� l��° �ε��� ���� ���
		Destination[i] = Source[i];
	}										// ����޴´��[���� ~ ���Ṯ�ڱ���] = ������ ����[���� ~ ���Ṯ�ڱ���]
	return Destination;					//  Destination							Source
}
char* stringConCat(char* Destination, const char* Source) {
	int ls = stringLength(Source); // ������ ���������� �� ����
	int ld = stringLength(Destination);
	for (int i = 0; i <= ls; i++) { // i���� 0 ���� l��° �ε��� ���� ���
		Destination[ld + i] = Source[i];
	}								// ����޴´��[���� ~ ���Ṯ�ڱ���] = ������ ����[���� ~ ���Ṯ�ڱ���]
	return Destination;				//  Destination							Source
}

	


int main() {
	char str1[128] = "cHiCkEn";
	char str2[128] = "wOrLd";

	int n2 = stringLength(str1);
	int m2 = stringLength(str2);
	StringUpper(str1); // void StringUpper(char* Param = str1)
	StringLower(str2); // void StringUpper(char* Param = str1)

	printf("%s\n%s\n", str1, str2);
	printf("str2�� ������ str1�� ������ ���\n>>>%s\n", stringCopy(str1, str2));
	char temp[128] = { 0 };
	stringCopy(str1,"cHiCkEn");
	stringCopy(str2,"wOrLd");


	strcpy(temp, str1); // temp = num
	strcpy(str1, str2); // num = num2
	strcpy(str2, temp); // num2 = temp

	n2 = strlen(str1);
	m2 = strlen(str2);

	_strupr(str1);
	_strlwr(str2);
	printf("%s\n%s\n", str1, str2);
	strcat(strcat(str1, " "), str2);
	printf("str2�� ������ str1�� ������ ���\n>>>%s\n",str1 );
	
	memset(temp, 0, strlen(temp));
	// memory Setting
	
	int �����ڵ�, �г�, ���� , �̼��ð�;
	char ����[128] = { 0 };
	char �����[128] = { 0 };

	
	
	return 0;
}


/*
int arr[10] = { 0 };
	int arr2[10] = { 0 };
	int number = 0;
	char str3[11] = "hello world";

	printf("%s\n", str3);
	scanf("%s", str3);


	printf("input String > ");
	gets(str1);


	//���� ����� ���
	// 1. Ư�� ���ڱ��� �о�� ���� [^\n] : \n�������� ���� �о��.
	// 2. ���ۿ��� ������ �о��. : gets() get String
	printf("input String > ");
	scanf("%[^\n]", str2);
	/*	puts(str1);
		printf("%s",str2);

printf("str1 : %s\n", str1);
printf("str2 : %s\n", str2);

for (int i = 0; i < 100; i++) {
	printf("str1[i] : %c\n", str1[i]);
}


*/