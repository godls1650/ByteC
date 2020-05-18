#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YEAR 2020
/* 제어문
   비교연산 : 크기비교 
    >   <   == 
	>=  <=  !=
	
	논리연산자 
	AND : 두 조건이 참일 경우만 참값		&&    &
	OR  : 두 조건중 하나만 만족해도 참값	||	  |
	NOT : 원래 값의 반대					 !    ~

	문자값 1개를 입력 받으면
	소문자의 경우 대문자로 변경
	대문자는 소문자로 변경
	특수문자는 가공 없이
	출력하는 프로그램 
*/
int main() {
	/*버스요금*/
	int myBirthYear = 0;
	int resultAge = 0;
	int nPay = 0;
	int bHelpCard = 1;
	printf("태어난 년도 : ");
	scanf("%d", &myBirthYear);
	resultAge = YEAR - myBirthYear + 1;
	if (resultAge >= 20)
		if (bHelpCard)
			nPay = 0;
		else
			nPay = 1250;
	else if (resultAge >= 14)
		nPay = 860;
	else if (resultAge >= 8)
		nPay = 760;
	else if (resultAge >= 0)
		nPay = 0;
	else {
		printf("입력 값 오류 종료후 재입력 하세요\n");
		return 0;
	}
	printf("버스요금 : %d원\n", nPay);
	
	char text = 0;
	printf("아무 글자나 입력하세요 (한글 X) > ");
	scanf("%*c%c", &text);
	if (text >= 'A' && text <= 'Z') {
		text += ' ';//text += 32
	}
	else if (text >= 'a' && text <= 'z') {
		text -= ' ';//text += 32
	}
	else {
		printf("숫자 or 특수문자 입니다.\n");
		return 0;
	}
	printf("변환 값 : %c\n", text);
	return 0;
}