#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	3���� �л� ������ 5������ ������ �����ϰ�

	�� �л��� �ְ����� ����ϴ� ���α׷� 

	*�ְ����� ���� -> �迭 

*/




int main() {
	int arr[3][5] = { 0 };
	int highest[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		printf("5������ ������ ��� �Է��ϼ��� > ");
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

		printf("%d��° �л��� �ְ��� : %d\n", i + 1, highest[i]);
	}
	

	
}



