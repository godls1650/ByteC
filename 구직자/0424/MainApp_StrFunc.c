#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define _SIZE	128
#define SIZE	_SIZE - 1

#define BACK 1
#define FRONT -1
#define SAME	0




int strLen(const char* str) {
	int l = 0;
	for (int i = 0;i < _SIZE; i++) {
		if (str[i] == '\0') return i;
	}
	return 0;
}

char* strCat(char* _destination, char* _source) {
	int ll = strLen(_destination);
	int rl = strLen(_source);
	char * s1 = _destination, * s2 = _source; // ���� ����
	for (int i = 0; i < rl; i++) {
		s1[ll + i] = s2[i];
	}

	return _destination;
}

char* strLwr(char* str1) {
	int len = strLen(str1);
	for (int i = 0; i < len; i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') {
			str1[i] += 32;
		}
	}
	return str1;
}

char* strUpr(char* str1) {
	int len = strLen(str1);
	for (int i = 0; i < len; i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z') {
			str1[i] -= 32;
		}
	}
	return str1;
}

/* ���ڿ� 1�� ���ڿ�2�� �� �ؼ� ���������� ���̸� -1   �������ڸ� 0  ������ ���� ���� : 1*/
int strCmp(const char * str1, const char * str2) {
	int l1 = strLen(str1);
	int l2 = strLen(str2);
	


	strlen(l1);
	l1 = (l1 >= l2) ? l2 : l1;
	int asc = 0;
	for (int i = 0; i <= l1; i++) {
		asc = str1[i] - str2[i];
		if (asc > 0) return 1; // ������ : str2  str1
		else if (asc < 0) return -1; // ������ : str1 str2
		else continue;
	}
	return 0;
}

char* strCopy(char* _destination, char* _source) {
	int ll = strLen(_source);
	char* s1 = _destination, * s2 = _source; // ���� ����
	for (int i = 0; i <= ll; i++) {
		s1[i] = s2[i];
	}

	return _destination;
}


char* strNCat(char* _destination, char* _source, int Len) {
	int ll = strLen(_destination);
	int rl = strLen(_source);
	if (Len > rl) {
		printf("\a������ �������� ??\n");
		Len = rl;
	}
	char* s1 = _destination, * s2 = _source; // ���� ����
	for (int i = 0; i <= Len; i++) {
		s1[ll + i] = s2[i];
	}

	return _destination;
}
void StrSwap(char* str1, char* str2) {
	char temp[SIZE] = { 0 };
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	return;
}

int main() {
	char str1[SIZE] = { 0 };
	char str2[SIZE] = { 0 };
	int temp[SIZE] = { 0 };
	char c = 0;
	for(int i = 0; i <0xFF; i++)
		printf("�������� : %s\n", strerror(i));
	printf("\n");
	printf("���ڿ� 1 �Է� > ");
	gets(str1);
	printf("���ڿ� 2 �Է� > ");
	gets(str2);

	printf("str1�� str2�� �� > %d\n", strCmp(str1, str2));

	printf("��ȯ���� ���� :  %s > %s\n", str1, str2);
	if (strCmp(str1, str2) == -1) {
		StrSwap(str1, str2);
	}
	printf("�������� ���� :  %s > %s\n", str1, str2);

	/* ���ڿ��� �빮�ڵ��� -> �ҹ��ڷ� ���� */
	for (int i = 0; i < strLen(str1);i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
	} 
	
	printf("���� ������ : %s\n", str1);

	//���� ����ô� ~~~

	return 0;
}