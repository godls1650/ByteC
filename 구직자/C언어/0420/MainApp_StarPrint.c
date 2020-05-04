#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	printf("*");
	printf("\n");
	printf(" ");

	printf("*\n");
	printf("**\n");
	printf("***\n");
	printf("****\n");
	printf("*****\n");

	printf("*")  printf("\n")
	printf("*")  printf("*")  printf("\n")
	printf("*")  printf("*") printf("*") printf("\n")


*/

int main(void) {
	int menu = 0;

	while (1) {
		printf("1. 삼각형 모양으로 출력\n");
		printf("2. 역삼각형 모양으로 출력\n");
		printf("3. 대각선 으로 출력\n");
		printf("4. 역대각선 으로 출력\n");
		printf("5. X모양 으로 출력\n");
		printf("6. 산모양 으로 출력\n");
		printf("7. 다이아모양 으로 출력\n");
		printf("8. Exit\nselect > ");
		scanf("%d", &menu);

		switch (menu) {
		case 1: 
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j <= i; j++) {
					printf("*");
				}
				printf("\n");
			}
			break;
		case 2:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < i; j++) {
					printf(" ");
				}
				for (int j = 0; j <(5-i); j++) {
					printf("*");
				}
				printf("\n");
			}
			break;
		case 3:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (i == j)
						printf("*");
					else
						printf(" ");
				}
				printf("\n");
			}
			break;
		case 4:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (i == 4-j)
						printf("*");
					else
						printf(" ");
				}
				printf("\n");
			}
			break;
		case 5:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {// 
					if (i == j||i == 4 - j)
						printf("*");
					else
						printf(" ");
				}
				printf("\n");
			}
			break;
		case 6:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4 - i; j++) {
					printf(" ");
				}
				for (int j = 0; j < (i * 2 + 1); j++) {
					printf("*");
				}
				printf("\n");
			}
			break;
		case 7:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4 - i; j++) {
					printf(" ");
				}
				for (int j = 0; j < (i * 2 + 1); j++) {
					printf("*");
				}
				printf("\n");
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <=i; j++) {
					printf(" ");
				}
				for (int j = 0; j < ((3-i) * 2 + 1); j++) {
					printf("*");
				}
				printf("\n");
			}
			break;
		case 8:
			return;
		}
	}


	return 0;
}