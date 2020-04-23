#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // 프로그램을 일시정지 Sleep()
int main() {
	const int PW = 1234;
	int inputPw = 0;
	
	for (int i = 0; i < 5; i++) {
		printf("비번 입력 > ");
		scanf("%d", &inputPw);
		if (PW == inputPw) {
			break;
		}
		else if (i >= 3) {
			for (int j = 0; j < 3; j++) {
				printf("\a");
				Sleep(1000);// 1000ms --> 1sec
			}
		}

	}


	int result = 0;
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 1)
			continue;
		else
			result += i;
	}

	int i = 0;
	while(i < 10) {
		if (i % 2 == 1)
			continue;
		else
			result += i;
		i++;
	}

	return 0;
}