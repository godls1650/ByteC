/* 2020-04-01 _2nd_
Character / ASCII  / Character Set   */

/*
문자 : 각각 지정된 문자 표에 의한 숫자 값 
ASCII 
UNICODE(ANSI)
MULTIBYTE 

CHARacter : char  :  1Byte
*/
#include <stdio.h>
/* 2020-04-01 _2nd_
 STanDard Input Output
 Escape  seq / format
 \가 있는 문자 : 이스케이프 시퀀스
 \a: Alarm

 \b : back Space
 \t : tab
 \n : eNter (New line)
 \\ : \를 출력
 \" , \' : 문장안에 " , '를 출력

 \0 : NULL문자
 */
int main(void) {
	char cText1 = '0'; // cText = 48
	char cText2 = '\0';
	// 문자 , 정수  의 관계
	// ASCII 관련 연산
	// 출력 서식 : %c 
	// 'A' : 65   'a' : 97   '0' : 48
	// "100 * 20" --->  "100" --> stoi() --> 100
	// '0'-48 =/= 0
	cText1 = 'a' - ' ';
	printf("cText1 : %c\n", cText1);
	printf("cText1 : %d\n", cText1);

	printf("hello world\"\n");

	return 0;
}