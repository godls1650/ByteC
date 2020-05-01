#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	3명의 학생 각각의 5개과목 성적을 저장하고

	각 학생의 최고점을 출력하는 프로그램 

	*최고점을 저장 -> 배열 

*/




int main() {
	int arr[3][5] = { 0 };
	int highest[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		printf("5과목의 성적을 모두 입력하세요 > ");
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		highest[i] = arr[i][0];
		for (int j = 1; j < 5; j++) {
			if (highest[i] < arr[i][j]) {
				highest[i] = arr[i][j];
			}
		}

		printf("%d번째 학생의 최고점 : %d\n", i + 1, highest[i]);
	}
	

	
}



