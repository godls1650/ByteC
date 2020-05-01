#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _SIZE	10
int main() {
	int arr[_SIZE] = { 0 };
	int cnt = 0;
	srand(time(NULL));
	while (cnt < 10) {
		//랜덤값의 범위는 1 ~ 10까지의 값을 배열에 저장
		// 중복되는 값이 없게 저장
		for (int i = 0; i < _SIZE; i++) {
			arr[i] = rand() % 10 + 1;
			for (int j = 0; j < i; j++) {
				if (arr[i] == arr[j]) {
					i--; break;
				}
			}
		}

		for (int i = 0; i < _SIZE; i++) {
			printf("%2d ", arr[i]);
		}
		printf("\n");
		cnt++;
	}


	return 0;
}
