#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	정수 3개를 scanf 하나만 사용해서 입력한 이후
	3개 정수중 가장 큰 값을 출력하는 프로그램 작성
	(제어문 사용 X)
*/
int main() {
	int n1 = 0, n2 = 0, n3 = 0;
	int result = 0;
	printf("정수 3개를 입력하세요 > ");
	scanf("%d %d %d", &n1, &n2, &n3);

	result = (n1 < n2) ? 
		((n2 < n3) ? n3 : n2) : 
		((n1 < n3) ? n3 : n1);

	printf("세 정수 중 큰 숫자는 %d 입니다.\n", result);




	return 0;
}