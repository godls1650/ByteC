#pragma once // 이미 include 되어있는경우 파일 끝으로 넘긴다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define ORANGE 5
#define YELLOW 6

int CUBE[6][3][3] = { {WHITE},{RED},{GREEN},{BLUE},{ORANGE},{YELLOW} };

#define TRUE	1
#define FALSE	0

char* StringAlloc(const char* const _str) {
	int len = 0;
	char* test = NULL;
	len = strlen(_str) + 1; // 11
	test = (char*)malloc(len * sizeof(char));
	memset(test, 0, len * sizeof(char));
	strcpy(test, _str);

	return test;
}

char* StringInput(const char* const _str) {
	char input[128];
	int len = 0;
	char* test = NULL;
	printf(_str);
	gets(input);

	len = strlen(input) + 1;
	test = (char*)malloc(len * sizeof(char));
	memset(test, 0, len * sizeof(char));
	strcpy(test, input);

	return test;
}

