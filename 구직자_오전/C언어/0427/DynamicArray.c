#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	3�г��� ����(4��)�� �л����� �������(double)�� �����Ѵ�
	1�� : 32��
	2�� : 35��
	3�� : 30��
	4�� : 34��

*/
char* inputString(const char* const _text);

int main() {
	double StudentAvgScore[4][35] = { 0.0 };
	double** dpPtr = NULL;
	// �����Ҵ����� ������  �����迭
	dpPtr = (double**)malloc(sizeof(double*) * 4);
	dpPtr[0] = (double*)malloc(sizeof(double) * 32);
	dpPtr[1] = (double*)malloc(sizeof(double) * 35);
	dpPtr[2] = (double*)malloc(sizeof(double) * 30);
	dpPtr[3] = (double*)malloc(sizeof(double) * 34);
	// ���ڿ� : �Էµ� ���ڿ����̸�ŭ �Ҵ��ؼ� ���� ���ڿ������� �����ѵ�  ���� ���ڿ��� �����ϸ� 
	//          ���������� �����Ͱ� ���´�.
	char* sName = NULL;
	char* sAddress = NULL;
	sName = inputString("�̸� > "); //
	sAddress = inputString("�ּ� > "); //
	
	printf("�̸� : %s\n", sName);
	printf("�ּ� : %s\n", sAddress);

	return 0;
}

char* inputString(const char * const _text) {
	char text[128] = { 0 };
	char* temp = NULL;
	int l = 0;
	printf(_text);
	gets(text);
	l = strlen(text);
	temp = (char*)malloc(l+1);
	memset(temp, 0, l + 1);
	strcpy(temp, text);


	return temp;
}
