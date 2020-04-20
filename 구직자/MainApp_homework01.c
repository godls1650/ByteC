#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#define NULL (void *)0 // 00000000  

int main() {
	int user = 0, com = 0;// 유저 입력   컴퓨터 입력
	int WDL[3][3] = {
		{0, 1 , -1},
		{-1 , 0 ,1},
		{1, -1 , 0}
	};


	int WinCount = 0; // 이긴거 만큼 증가
	double WinPer = 0.0; // 승률
	int result = 0;
	srand((unsigned int)time(NULL));


	//10 회 실행 중 이긴 횟수 체크
	for (int i = 0; i < 10; i++) {
		printf("1. 가위   2. 바위  3. 보자기  \nSelect > ");
		scanf("%d", &user); // 사용자는 1,2,3 중 하나를 입력
		
		com = rand() % 3 + 1; // (0,1,2) + 1
		/*
		switch (WDL[user][com]) {
		case -1 :
			printf("Win");
		case 0: 
			printf("Draw");
		case 1 :
			printf("Lose");
		}
		*/
		
		result = user - com;

		switch (result) {
		case 0 :  break;
		case -2:  case  1 :
			WinCount++;
			break;
		case 2 : case  -1 :
			break;
		}
	
	}

	if (com == user) {
	
	}
	else if (user == 1 && com == 2 || user == 2 && com == 3 || user == 3 && com == 1) {
	
	}
	else {
	
	}

	WinPer = (double)(WinCount / 10) * 100;
	


	return 0;
}

