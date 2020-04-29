#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* 배열의 초기화 
	
*/
#define MONTHS 12
int main() {
	int arr1[5] = {10,20,30,40,50};
	int arr2[5] = { 0 };
	int arr3[5] = { 10 };
	int arr4[] = {10,20,30};
	//char text1[] = "hello world";
	//char text2[6] = { 'a','p','p','l','e','\0' };
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//                    0  1  2  3  4  5  6  7  8  9 10 11
	// 30 -> 3 5  8  10
	// 31 -> 0 2 4 6  7  9 11
	int days2[MONTHS] = { 0 };
	int year = 2020;

	int x = 10;
	
	for (int i = 0; i < MONTHS; i++) {
		printf("%d월 : %d일\n", i + 1, days[i]);
	}

	for (int i = 0; i < MONTHS; i++) {
		switch (i) {
		case 1 :
			days2[i] = (year % 4 == 0) ? 29 : 28; break;
		case 3:case 5: case 8 : case 10:
			days2[i] = 30; break;
		default : 
			days2[i] = 31;
		}
	}
	printf("윤년 계산\n");
	for (int i = 0; i < MONTHS; i++) {
		printf("%d월 : %d일\n", i + 1, days2[i]);
	}

	// 지정 초기화
	int days3[MONTHS] = {1,10, [4] = 100, 30, 60, [7] = 123};
	
	for (int i = 0; i < MONTHS; i++) {
		printf("%3d일 ", days3[i]);
	}
	printf("\n");
	return 0;
}