#define _CRT_SECURE_NO_WARNINGS // scanf 에러 방지
#include <stdio.h> 
// 365    300 + 60 + 5
void printMoneytoKor(int pMoney) {
	int test[5] = { 100000000, 10000, 1000, 100, 10 };
	int temp = 100011110;
	for (int i = 0; i < 5; i++) {
		if (pMoney / test[i]) {
			printf("%d", pMoney / test[i]);
			pMoney %= test[i];

			switch (i) {
			case 0: printf("억"); break;
			case 1: printf("만"); break;
			case 2: printf("천"); break;
			case 3: printf("백"); break;
			case 4: printf("십"); break;
			}
		}
	}
	printf("원\n");
}

int main(void) {
	int nMoney = 0; // 금액을 입력할 변수
	
	/*
	printf("금액 입력 > ");
	scanf("%d", &nMoney);
	
	printMoneytoKor(nMoney);
	금액입력*/
	//3자리를 입력하면 자리 마다 끊어서 표현
	char text = 0;
	int num = 100;
	printf("세자리 정수를 입력 > ");
	while (text != '\n') {
		scanf("%c", &text);
		text -= '0';
		printf("%d ", num * text);
		num /= 10;
	}


	return 0;
}
