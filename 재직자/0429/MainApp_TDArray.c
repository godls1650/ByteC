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
		//�������� ������ 1 ~ 10������ ���� �迭�� ����
		// �ߺ��Ǵ� ���� ���� ����
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
