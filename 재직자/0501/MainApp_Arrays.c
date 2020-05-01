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
	int arr[20] = {0}; // 20 * 4byte
	int ta[VTC][HOZ] = { 0 };
	for (int i = 0; i < VTC; i++) { // 행단위
		printf("ta[%d] : %p\n", i, ta[i]);
	}
	// 3*13*42*4byte


	//int tarr1[5][4] = { 1,2,3,4,5,6,7,8,9,10,.... };
	int tarr2[5][4] = { {1,2,3,4}, {5,6,7,8} ,{9,10,11,12} ,{13,14,15,16}, 
						{17,18,19,20} };

	//2차원배열의 인덱스 
	for (int i = 0; i < 5; i++) { // 행단위
		for (int j = 0; j < 4; j++) // 열단위
			printf("[%d][%d] : %p\n",i,j, &tarr2[i][j]);
	}
	printf("\n");

	
	
	return 0;
}