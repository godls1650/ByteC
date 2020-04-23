#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	반복문 : for 

	구성
	for ( 초기값 ; 비교식 ; 증감식) {
		참일 때 실행할 내용 
		
	}
	초기값 : 반복 기준이 될 변수를 선언하거나 가져온다.
	증감식 : 기준값(초기 변수)가 반복 1회당 얼마나 증가하는지 
*/

int main() {
	int i = 0, j = 0;
	for ( ; i < 10; i++) {
		printf("%d회 실행중 \n", i + 1);
	}
	for (i = 0; i < 10; i++) {
		printf("%d회 실행중 2번째 \n", i + 1);
	}
	
	for (int j = 0; j < 10; j++) {
		printf("%d회 실행중 \n", j + 1);
	}
	//j 변수가 정의 되어있지 않습니다.

	for (int j = 0; j < 10; j++) {
		printf("%d회 실행중 2번째 \n", j + 1);
	}


	return 0;
}