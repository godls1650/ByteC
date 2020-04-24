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
	char * s1 = _destination, * s2 = _source; // 얕은 복사
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

/* 문자열 1과 문자열2를 비교 해서 사전순으로 앞이면 -1   같은글자면 0  사전상 뒤의 글자 : 1*/
int strCmp(const char * str1, const char * str2) {
	int l1 = strLen(str1);
	int l2 = strLen(str2);
	


	strlen(l1);
	l1 = (l1 >= l2) ? l2 : l1;
	int asc = 0;
	for (int i = 0; i <= l1; i++) {
		asc = str1[i] - str2[i];
		if (asc > 0) return 1; // 사전순 : str2  str1
		else if (asc < 0) return -1; // 사전순 : str1 str2
		else continue;
	}
	return 0;
}

char* strCopy(char* _destination, char* _source) {
	int ll = strLen(_source);
	char* s1 = _destination, * s2 = _source; // 얕은 복사
	for (int i = 0; i <= ll; i++) {
		s1[i] = s2[i];
	}

	return _destination;
}


char* strNCat(char* _destination, char* _source, int Len) {
	int ll = strLen(_destination);
	int rl = strLen(_source);
	if (Len > rl) {
		printf("\a원본이 작은뎁쇼 ??\n");
		Len = rl;
	}
	char* s1 = _destination, * s2 = _source; // 얕은 복사
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
		printf("무슨에러 : %s\n", strerror(i));
	printf("\n");
	printf("문자열 1 입력 > ");
	gets(str1);
	printf("문자열 2 입력 > ");
	gets(str2);

	printf("str1과 str2를 비교 > %d\n", strCmp(str1, str2));

	printf("교환이전 순서 :  %s > %s\n", str1, str2);
	if (strCmp(str1, str2) == -1) {
		StrSwap(str1, str2);
	}
	printf("정렬이후 순서 :  %s > %s\n", str1, str2);

	/* 문자열의 대문자들을 -> 소문자로 변경 */
	for (int i = 0; i < strLen(str1);i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
	} 
	
	printf("변경 데이터 : %s\n", str1);

	//빙고 만듭시다 ~~~

	return 0;
}