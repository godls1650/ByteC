#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*	1 ~ 45 중 6개의 숫자를 뽑아서 
	int mr[6] 에 중복 없이 저장한다.

	1 ~ 45 중 7개의 숫자를 뽑아서
	int r[7] 에 중복 없이 저장한다.

	mr의 원소값과
	r의 0 ~ 5인덱스의 원소값이 모두 같다면   "WIN"
	r의 0 ~ 5인덱스의 원소값이 5개만 같고
	    mr의 0 ~ 5인덱스의 값이  r[6] 와 같다면  "2nd"
								다르다면			"3rd"
	r의 0 ~ 5인덱스의 원소값이 4개가 같다면  "4th"
	r의 0 ~ 5인덱스의 원소값이 3개가 같다면  "5th"

	나머지경우 : "FAIL"

*/
int main() {
	int mr[6] = { 0 };
	int r[7] = { 0 };
	int count = 0;
	int bWin = 0;
	int tr = 0;
	srand((unsigned int)time(NULL));
	//내꺼
	while (!bWin) {
		tr++;
		count = 0;
		for (int i = 0; i < 6; i++) {
			mr[i] = rand() % 45 + 1;
			for (int j = 0; j < i; j++) {
				if (mr[i] == mr[j]) {
					i--;
					break;
				}
			}
		}
		// 추첨
		for (int i = 0; i < 7; i++) {
			r[i] = rand() % 45 + 1;
			for (int j = 0; j < i; j++) {
				if (r[i] == r[j]) {
					i--;
					break;
				}
			}
		}
		printf("추첨 결과 > ");
		for (int i = 0; i < 6; i++) {
			printf("%2d ", r[i]);
		}
		printf("+%2d\n", r[6]);

		printf("  내 번호 > ");
		for (int i = 0; i < 6; i++) {
			printf("%2d ", mr[i]);
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (mr[i] == r[j]) {
					count++;
					break;
				}
			}
		}
		printf("\n%d주차 결과 : ", tr);
		switch (count) {
		case 6:
			printf("☆★☆★☆★☆★☆★☆★☆★1등☆★☆★☆★☆★☆★☆★☆★\n");
			return;
			break;
		case 5:
			for (int i = 0; i < 6; i++) {
				if (mr[i] == r[6]) {
					printf("☆★☆★☆★☆★2등☆★☆★☆★☆★\n");
					system("pause");
					return;
				}
			}
			printf("☆★☆★3등☆★☆★\n");
			system("pause");
			break;
		case 4:
			printf("5만원\n");
			system("pause");
			break;
		case 3:
			printf("5처넌\n");
			system("pause");
			break;
		default:
			printf("꽝\n");

		}
		
	}


	return 0;
}