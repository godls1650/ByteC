#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#define NULL (void *)0 // 00000000  

int main() {
	int user = 0, com = 0;// ���� �Է�   ��ǻ�� �Է�
	int WDL[3][3] = {
		{0, 1 , -1},
		{-1 , 0 ,1},
		{1, -1 , 0}
	};


	int WinCount = 0; // �̱�� ��ŭ ����
	double WinPer = 0.0; // �·�
	int result = 0;
	srand((unsigned int)time(NULL));


	//10 ȸ ���� �� �̱� Ƚ�� üũ
	for (int i = 0; i < 10; i++) {
		printf("1. ����   2. ����  3. ���ڱ�  \nSelect > ");
		scanf("%d", &user); // ����ڴ� 1,2,3 �� �ϳ��� �Է�
		
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

