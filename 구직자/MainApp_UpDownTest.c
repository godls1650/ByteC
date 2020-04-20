#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/*컴퓨터가 최소한의 시도 횟수로 내가 낸 숫자를 맞추게 하세요*/
int main() {
	int user = 0;
	int com = 0;
	int max = 0, min = 0;
	int cnt = 0;
	int bSearch = 0;
	max = 100;  
	min = 1;

	printf("숫자를 입력하세요 (1 ~ 100)> ");
	scanf("%d", &user);
	system("cls");
	while (bSearch != 1) {
		printf("컴퓨터가 값을 고르는 중입니다.");
		for (int i = 0; i < (3 + cnt); i++) {
			printf(".");
			Sleep(500);
			if (i == 7) {
				printf("느리네요.. 힘든가봅니다.\n멍청한것...\n");
				Sleep(500);
			}
		}
		com = (max + min) / 2;
		printf("com : %d입니까 ? \n", com);
		Sleep(1000);
		if (com == user) {
			bSearch = 1;
			printf("user : 정답입니다.");
		}
		else if (com > user) {
			printf("user : DOWN 입니다.\n");
			max = com;
		}
		else{
			printf("user : UP 입니다.\n");
			min = com;
		}
		Sleep(1000);
		cnt++;
	}

	printf("컴퓨터가 %d회 시도하여 값을 찾았습니다.\n", cnt);


	return 0;
}