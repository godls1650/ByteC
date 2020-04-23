#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* for 중첩 제어를 이용해서 구구단을 출력합시다. */
int main() {
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < 10; i++) {
			// 2   6
			// 6  10
			if (k == 1) {
				for (int j = 2 + 4; j < 10; j++) {
					printf("%d x %d = %2d\t", j, i, i * j);
				}
			}
			else {
				for (int j = 2; j < 6; j++) {
					printf("%d x %d = %2d\t", j, i, i * j);
				}
			}
			
			printf("\n");
		}
		printf("\n\n");
	}
	


	

	return 0;
}