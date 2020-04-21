#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // STanDard Libaray
#include <time.h> // system 시간을 사용 
/*
 랜덤 함수 : rand()
 메모리에[223425]을 저장
 연산 ---> [41]
 Seed 변수를 변경
 srand(unsigned int )

 time.h --> time(NULL) 

  1900 년 1월 1일 00 :00 : 00 
*/
int main() {						// 
	srand((unsigned int)time(NULL));// 실행순서 : main-> srand -> time
	                                // 종료순서 : time -> srand -> main
	int user = 0;
	int com = 0;
	// rand() % (최대값 - 최소값 + 1 ) + 최소값
	com = rand() % 3 + 1;
	printf("1.가위  2. 바위 3. 보자기 \n select > ");
	scanf("%d", &user);
	printf("user : ");
	if (user == 1)		 printf("가위");
	else if (user == 2)  printf("바위");
	else				 printf("보자기");
	printf(" vs com : ");
	if (com == 1)		 printf("가위");
	else if (com == 2)   printf("바위");
	else                 printf("보자기");
	printf("\n");

	if (com == user) {
		printf("무승부\n");
	}
	else if (user == 1 && com == 2 || user == 2 && com == 3 || user == 3 && com == 1) {
		printf("패배\n");
	}
	else {
		printf("승\n");
	}

	
	return 0;
}