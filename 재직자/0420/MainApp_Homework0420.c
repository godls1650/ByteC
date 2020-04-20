#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*FILE NAME : MainApp_Homework0420.c*/
#define TRUE	1
#define FALSE	0
int main() {
	int com = 0, user = 0;
	int max = 0, min = 0;
	max = 100;
	min = 1;
	int bSuccess = FALSE;

	printf("input number(1 ~ 100) > ");
	scanf("%d", &user);

	// 1   ~       100     1/ 100
	while (!bSuccess) {
		com = (max + min) / 2;

		if (user == com) {
			printf("Á¤´ä");
			bSuccess = TRUE;
		}
		else if (user > com) {
			printf("UP");
			min = com + 1;
		}
		else {
			printf("DOWM");
			max = com - 1;
		}		
	}

	return 0;
}

