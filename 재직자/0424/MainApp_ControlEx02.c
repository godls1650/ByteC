#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	약수

	42 ->   2   3   6  7   14  21  

	63 -> 1   3  7   9   21  63

	113 -> 1    113 --> 소수 
*/
int main() {
	int nData = 0;
	scanf("%d", &nData);
	for (int i = 2; i <= nData; i++) {
		while (nData % i == 0) {
			nData /= i;
			printf("%d x ", i);
		}
	}
	printf("\n\n\n\n\n");
	int cnt = 0;
	for(int number = 2; number < 1000; number++){
		cnt = 0;
		for (int i = 1; i <= number; i++) {
			if (!(number % i)) { // 나머지를 이용한 연산 : 모듈러 연산
				printf("%2d ", i);
				cnt++;
			}
		}
		if (cnt == 2) printf("\n%d(은)는 소수 입니다.\n", number);
	}
	
	printf("\n");
	
	
	return 0;
}
