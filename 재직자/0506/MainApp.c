#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 전역변수 


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
// 어떤 기능을 할 것인가.
/* 문자열의 길이를 구하는 함수
	문자열의 길이 : 정수 타입
	길이를 구하는 : 결과가 길이 
	int stringLength(char * X){
		int len = ;
		str1의 0번인덱스 부터 종료문자가 나올 때까지 len을 증가 시키면 str1의 길이가 된다.
		str2의 0번인덱스 부터 종료문자가 나올 때까지 len을 증가 시키면 str2의 길이가 된다.
		[X]의 0번인덱스 부터 종료문자가 나올 때까지 len을 증가 시키면 [X]의 길이가 된다.


		return len;
	}

*/

// 문자열의 모든 소문자를 대문자로 변경한다.
// 문자열의 모든 대문자를 소문자로 변경한다.

// 문자열 복사 함수 
char* stringCopy(char * Destination, const char * Source) {
	int l = stringLength(Source);	// 복사할 원본데이터 의 길이
	for (int i = 0; i <= l; i++) {		 // i값을 0 부터 l번째 인덱스 까지 사용
		Destination[i] = Source[i];
	}										// 복사받는대상[시작 ~ 종료문자까지] = 복사할 원본[시작 ~ 종료문자까지]
	return Destination;					//  Destination							Source
}
char* stringConCat(char* Destination, const char* Source) {
	int ls = stringLength(Source); // 복사할 원본데이터 의 길이
	int ld = stringLength(Destination);
	for (int i = 0; i <= ls; i++) { // i값을 0 부터 l번째 인덱스 까지 사용
		Destination[ld + i] = Source[i];
	}								// 복사받는대상[시작 ~ 종료문자까지] = 복사할 원본[시작 ~ 종료문자까지]
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
	printf("str2의 내용을 str1에 복사한 결과\n>>>%s\n", stringCopy(str1, str2));
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
	printf("str2의 내용을 str1에 복사한 결과\n>>>%s\n",str1 );
	
	memset(temp, 0, strlen(temp));
	// memory Setting
	
	int 과목코드, 학년, 학점 , 이수시간;
	char 전공[128] = { 0 };
	char 과목명[128] = { 0 };

	
	
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


	//문장 입출력 방식
	// 1. 특정 문자까지 읽어내는 서식 [^\n] : \n이전까지 전부 읽어낸다.
	// 2. 버퍼에서 문장을 읽어낸다. : gets() get String
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