#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
다차원배열 2차원 배열

*/
// test [7][4][4]
#define HOZ 5
#define VTC	5 // (5x 5)배열


int main() {
	int ta[VTC][HOZ] = { 0 };

	for (int i = 0; i < VTC; i++) {
		for (int j = 0; j < HOZ; j++) {
			ta[i][j] = i * 5 + j + 1;
		}
	}

	for (int i = 0; i < VTC; i++) {
		for (int j = 0; j < HOZ; j++) {
			printf("%2d ", ta[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < VTC; i++) {
		for (int j = 0; j < HOZ; j++) {
			ta[j][i] = i * 5 + j + 1;
		}
	}

	for (int i = 0; i < VTC; i++) {
		for (int j = 0; j < HOZ; j++) {
			printf("%2d ", ta[i][j]);
		}
		printf("\n");
	}
}