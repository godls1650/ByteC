#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*
	���ڿ� : ���ڷ� ������ �迭
	       �Ϲ����� �迭�� Ư¡�� ����
		   ���ڿ��̱� ������ �ִ� Ư¡ 
*/
#define _SIZE	128 // ���ڿ� �����
#define SIZE	_SIZE-1 // ���ڿ� ���� 

//int stringLength(const char* _target);
//char* stringConcat(char* destination, const char* source);



/*  ���ڿ��� ���̸� ���ϴ� ���α׷��� �ۼ��ϼ��� */

int stringLength(char * str1) {
	int len = 0;
	for (int i = 0; i < _SIZE; i++) {
		if (str1[i] == '\0') break;
		else {
			len++;
		}
	}
	return len;
}
char* stringCopy(char * str1, char * str2) {
	int l = stringLength(str1);
	for (int i = 0; i <= l; i++) {
		str2[i] = str1[i];
	}
	return str2;
}

char* stringConcat(char* str1, char* str2) {
	
	int l1 = stringLength(str1);
	int l2 = stringLength(str1);

	for (int i = 0; i <= l2; i++) {
		str1[l1 + i] = str2[i];
	}
	return str1;
}

int main() {
	char str1[_SIZE] = "Hello world";
	char str2[_SIZE] = { 0 };

	return 0;
}

/*
	���� !
	���ڿ� �ϳ��� �Ű������� ��� ������ �빮�ڷ� �ٲٴ� �Լ�
	���ڿ� �ϳ��� �Ű������� ��� ������ �ҹ��ڷ� �ٲٴ� �Լ�

	�� ���ڿ��� �Ű�������  ���� �Ű����� str1, ���� �Ű����� str2
	���������� ���ؼ� 
	str1�� str2 ���� �� ���ڸ�  -1�� ����
	str1�� str2 ���� �� ���ڸ�   1�� ����
	str1�� str2 �� ���� ���ڸ�   0�� ����

*/

/*
int stringLength(const char* _target) {
	int i = 0;
	for (   ; _target[i] != '\0'; i++);
	return i;
}

char * stringConcat(char* destination, const char* source) {
	int dLen = stringLength(destination);
	int sLen = stringLength(source);
	for (int i = 0; i <= sLen; i++) {
		destination[dLen + i] = source[i];
	}

	return destination;
}*/