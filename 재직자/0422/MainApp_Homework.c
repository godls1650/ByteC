#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	while : 조건을 충족할 때 까지 반복
	for  : 초기값이 지정수 까지 증가 하는동안 반복

	비밀번호 5회 틀리면 계정 잠금 --> for 반복
	다운로드 다 받아지기 전까지 로딩화면 
*/
int main() {
	int num = 0;
	int result = 0;
	int bMinus = 0;
	while (!bMinus) {
		printf("input number > ");
		scanf("%d", &num);

		if (num > 0) {
			result += num;
		}
		else {
			bMinus = 1;
		}
	}
	int piv = 0;
	int p = 0; // prev
	int pp = 0; // prev prev
	int end = 100;
	//   
	pp = 1;
	p = 0; //(0)     1   1  2  3  5
	while (1){
		piv = p + pp;
		if (piv < end)
			printf("%d ", piv);
		else
			break;
		pp = p;
		p = piv;
	}
	
	return 0;
}


/*
	int num = 0;// 1 ~ 100 까지 늘어날 변수
	int num2 = 0; // 0부터 짝수로 늘어날 변수
	int result = 0;
	// 1 ~ 100 까지 짝수만 합산
	while (num <= 100) {
		if (num % 2 == 0) {
			result = result + num;
			printf("%d ", num);
		}
			//continue; // 연산 후 계속 진행
		num++;
	}
	printf("\n짝수 총합 : %d\n", result);
	//짝수 총합 : 2550
	result = 0;
	num = 0;
	while (num <= 100) {
		result = result + num;
		printf("%d ", num);
		num = num + 2;
	}
	printf("\n짝수 총합 : %d\n", result);
	*/