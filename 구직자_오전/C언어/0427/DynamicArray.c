#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	3학년의 모든반(4반)의 학생들의 성적평균(double)을 저장한다
	1반 : 32명
	2반 : 35명
	3반 : 30명
	4반 : 34명

*/
char* inputString(const char* const _text);

int main() {
	double StudentAvgScore[4][35] = { 0.0 };
	double** dpPtr = NULL;
	// 동적할당으로 구현된  가변배열
	dpPtr = (double**)malloc(sizeof(double*) * 4);
	dpPtr[0] = (double*)malloc(sizeof(double) * 32);
	dpPtr[1] = (double*)malloc(sizeof(double) * 35);
	dpPtr[2] = (double*)malloc(sizeof(double) * 30);
	dpPtr[3] = (double*)malloc(sizeof(double) * 34);
	// 문자열 : 입력된 문자열길이만큼 할당해서 기존 문자열내용을 복사한뒤  기존 문자열을 삭제하면 
	//          힙공간에만 데이터가 남는다.
	char* sName = NULL;
	char* sAddress = NULL;
	sName = inputString("이름 > "); //
	sAddress = inputString("주소 > "); //
	
	printf("이름 : %s\n", sName);
	printf("주소 : %s\n", sAddress);

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
