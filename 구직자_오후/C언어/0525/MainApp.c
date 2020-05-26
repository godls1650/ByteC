#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
/*
//godls1650@gmail.com
	포인터 변수 : 다른 변수, 값의 메모리 주소를 저장하는 변수 
	  --> 변수로 할당받은 공간을 "다른 메모리의 주소값" 이라는 데이터를 저장하기 위해 사용한다.
	문자열 라이브러리 함수 구현 
*/
#define BUFFER_SIZE 129
void UseProgram();
void absolute(int * nParam);
int absolute2(int nParam);

int stringLength(const char * _str);
char* stringCopy(char* _destination, const char* _source);  // strcpy   -->  strncpy
char* stringConcat(char* _destination, const char* _source); // strcat  -->  strncat
int stringCompare(const char* _Str1, const char* _Str2);    //strcmp    -->  strncmp

// 문자열 header --> char : 1byte 
// 어느 배열이던  원하는 값으로 할당한 모든영역을 입력시킨다.

void* memorySet(void* Dst, int value, unsigned int SIZE);

/* 문자열을 비교하는 함수 
	첫번째 매개변수가 사전 순서상 앞에 있다면 -1
	첫번째 매개변수가 사전 순서상 뒤에 있다면 1
	첫번째 매개변수와 두번째가 같은 문장이면 0

	application
	apple
	apple pie
	camera
	apply
	
	
	
	banana

	apple pie

*/

/*
	프로그램의 내용 
	str1에 문자열을 입력받는다. // gets(), scanf()
	str2에 입력받은 문자열을 복사한다. --> strcpy()
*/
char* strAlloc(const char* const str);
int stringSearchString(const char* des, const char* src);
char* strsplit(const char* str, int val);

void Ex01();

int factorial(int n) { returnif (n > 1) ? n* factorial(n - 1) : n;}

int main() {
	char* str = "0x7F26";
	int number = 0;
	double dData = 0.0;
	
	char data[100] = { 0 };

	sscanf(str, "%x", &number);
	//number = strtol(str, NULL, 16);
	printf("%#x\n", number);

	sprintf(data,"%#x", number);
	puts(data);

	
	return 0;
}

int stringLength(const char* _str) {
	int j = 0;
	for (; _str[j] != '\0'; j++);
	return j;
	
}
char* stringCopy(char* _destination, const char* _source) {
	int len = stringLength(_source);
	

	for (int i = 0; i <= len; i++) {
		_destination[i] = _source[i];
	}
	return _destination;
}
char* stringConcat(char* _destination, const char* _source) {
	int dlen = stringLength(_destination);
	int slen = stringLength(_source);

	for (int i = 0, j = dlen; i <= slen; i++, j++) {
		_destination[j] = _source[i];
	}
	return _destination;
}
int stringCompare(const char* _Str1, const char* _Str2) {
	int dlen = stringLength(_Str1);
	int slen = stringLength(_Str2);
	int len = dlen <= slen ? dlen : slen;

	for (int i = 0; i <= len; i++) {
		if (_Str1[i] - _Str2[i] == 0) continue;
		else if (_Str1 - _Str2[i] > 0) return 1;
		else return -1;
	}
	return 0;
}

void* memorySet(void* Dst, int value, unsigned int SIZE) { // memset()
	char* ptr = Dst;
	for (int i = 0; i < SIZE; i++) {
		ptr[i] = value;
	}
	return Dst;
}

void UseProgram() {
	int number = 0;
	number = -100;
	absolute(&number);// absolute::nParam = &UseProgram::number

	printf("절대값 : %d\n", number);
	return;
}
void absolute(int * nParam) {
	if (*nParam < 0) (*nParam) * -1;
}
int absolute2(int nParam) {
	return (nParam < 0) ? nParam * -1 : nParam;
}

char* strAlloc(const char* const str) {
	char* temp = (char*)malloc(strlen(str) + 1);
	strcpy(temp, str);
	return temp;
}

int stringSearchString(const char* des, const char* src) {
	int dlen = strlen(des); // 원본 길이
	int slen = strlen(src); // 검색 문자열 길이
	char str[BUFFER_SIZE] = { 0 };
	for (int i = 0; i < dlen - slen; i++) {
		for (int j = i, k = 0; j < slen; j++, k++) {
			str[k] = des[j];
		}
		if (strcmp(str, src) == 0) { return i; }
		else continue;
	}
	return  -1;
}
/*
int stringSearchString(const char* des, const char* src) { // strstr()
	int dlen = strlen(des); // 원본 길이
	int slen = strlen(src); // 검색 문자열 길이
	char* cursor = NULL;

	do{
		if (cursor == NULL)
			cursor = strchr(des, src[0]);
		else
			cursor = strchr(cursor + 1, src[0]);
		
		if (strncpy(cursor, src, slen) == 0) return 1;
	} while (cursor != NULL);
	
	return -1;
}
*/
char* strsplit(const char* str, int val) {
	int len = strlen(str);
	char* temp = (char*)malloc(len+ 1);
	for (int i = 0, k = 0; i < len; i++) {
		if (str[i] == val) {
			break;
		}
		else {
			temp[k++] = str[i];
		}
	}
	if (strcmp(temp, str) == 0) { 
		free(temp);
		return str; 
	}
	else {
		strcpy(str, strchr(str, val));
		
		return temp;
	}
}

void Ex01(){
	char str1[BUFFER_SIZE] = { 0 };
	char str2[BUFFER_SIZE] = { 0 };
	char temp[BUFFER_SIZE] = { 0 };

	char Email[128] = "godls1650@gmail.com";
	char Account[100] = { 0 };
	char Domain[100] = { 0 };

	strcpy(Domain, strchr(Email, '@') + 1);
	strcpy(Account, strtok(Email, "@."));
	strcpy(Domain, strtok(NULL, "@."));
	printf("%s\n", Account);

	printf("%s : %s\n", Account, Domain);




	char inBuffer[BUFFER_SIZE] = { 0 };

	strcpy(inBuffer, "ipconfig -all\n");
	sscanf(inBuffer, "%s %s", str1, str2);
	printf("%s |||||| %s\n", str1, str2);




	/*
	str2 = str1  strcpy(str2, str1);
	str2 += str1 strcpy(str2, str1);
	str2 < str1  strcmp(str2, str1);

	*/

	printf("문자열을 입력 > ");
	gets(str2);

	char* strr = strAlloc(str2);

	printf("문자열을 입력 > ");
	gets(str1);
	// hello + " " + world
	// hello world
	// helloworld
	printf("%s 와 %s를 비교한 결과 : %d\n", str1, str2, stringCompare(str1, str2));
	if (stringCompare(str1, str2) == 1) {
		stringCopy(temp, str1);
		stringCopy(str1, str2);
		stringCopy(str2, temp);
		// 문자열 Swap;
	}



	stringConcat(stringConcat(str2, "@"), str1);

	printf("원본 : %s\n복사본 : %s\n", str1, str2);


}