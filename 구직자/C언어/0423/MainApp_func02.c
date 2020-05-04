#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*
	문자열 : 문자로 나열된 배열
	       일반적인 배열의 특징을 갖고
		   문자열이기 때문에 있는 특징 
*/
#define _SIZE	128 // 문자열 선언시
#define SIZE	_SIZE-1 // 문자열 사용시 

//int stringLength(const char* _target);
//char* stringConcat(char* destination, const char* source);



/*  문자열의 길이를 구하는 프로그램을 작성하세요 */

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
	숙제 !
	문자열 하나를 매개변수로 모든 영문을 대문자로 바꾸는 함수
	문자열 하나를 매개변수로 모든 영문을 소문자로 바꾸는 함수

	두 문자열을 매개변수로  앞의 매개변수 str1, 뒤의 매개변수 str2
	사전순서로 비교해서 
	str1이 str2 보다 앞 글자면  -1을 리턴
	str1이 str2 보다 뒤 글자면   1을 리턴
	str1이 str2 와 같은 글자면   0을 리턴

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