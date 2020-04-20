#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE	0
#define TRUE	1
/*
RAND 만을 이용한 경우 : 최대 <INFINITE>

*/
int main() {
	int user = 0;// 사용자 입력으로 1 ~ 100 사이 값을 저장한다.
	int com = 0; // 컴퓨터는 1 ~ 100 사이의 값을 하나 저장해서 user의 값을 맞춰야 한다.
	int bSuccess = 0;
	int Max = 50, Min = 1;
	srand((unsigned int)time(NULL));
	printf("User Select (1 ~ 50) > ");
	scanf("%d", &user);

	while ( !bSuccess ) {
		//com = rand() % (Max - Min + 1) + Min;
		// 랜덤의 범위를 조정
		com = (Max + Min) / 2;

		printf("com say : %d\n", com);

		if (com == user) {
			printf("컴퓨터가 숫자를 맞췄습니다.\n");
			bSuccess = TRUE;
		}
		else if (com > user) {
			printf("user : Down\n");
			Max = com;
		}
		else {
			printf("user : Up\n");
			Min = com;
		}

	}
	

}