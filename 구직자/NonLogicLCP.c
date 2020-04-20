#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int user = 0;
	int com = 0;
	int result = 0;
	int win = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		printf("1.가위 2.바위 3.보자기 \nselect > ");
		scanf("%d", &user);
		user -= 2;				// -1  0   1
		com = rand() % 3 - 1;   // -1  0   1

		result = user - com; // 무승부 => 0
							 // 패 : -1, -1 , 2
							 // 승 : -2,  1   1
		if (user == -1)		 printf("user : 가위");
		else if (user == 0)  printf("user : 바위");
		else				 printf("user : 보자기");

		if (com == -1)		 printf(" vs com : 가위\n");
		else if (com == 0)   printf(" vs com : 바위\n");
		else				 printf(" vs com : 보자기\n");



		switch (result) {
		case 0:
			printf("무승부\n");
			break;
		case 1: case -2:
			printf("승!\n");
			win++;
			break;
		case -1: case 2:
			printf("패!\n");
			break;
		}
	}
	printf("승률 : %.2lf%%\n", (double)win / 10);

	return 0;
}