#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//(0°C × 9/5) + 32 = 32°F
/*
	[섭씨 온도]를 입력한다.
	위의 공식과 입력한 섭씨온도를 이용해서
	[화씨 온도]를 구한다.
	구해진 온도 값을 F에 저장하고
	출력한다.
	double C = 0.0, F = 0.0;
	printf("섭씨 온도를 입력하세요 > ");
	//75.7--> 실수 숫자로
	scanf("%lf", &C);

	F = C* (9.0 / 5.0) + 32.0;
	printf("%.1lf℃ = %.1lf℉\n", C, F);
*/
/*
	금액을 입력한다.
	입력된 금액을 50000으로 나눈 몫을 저장한다 --> 5만원권의 갯수
	입력된 금액을 50000으로 나눈 나머지를 입력된 금액이 저장된 변수에 되돌려준다.

*/
int main() {
	int Money = 0; // 5만 -> 만원 -> 5천원 -> 1000원 으로 바뀔 값을 저장할 변수 
	int MyMoney = 0; // 입력을 통해 저장할 변수 
	int Count = 0;   // 현재 화폐의 갯수,장 수를 저장할 변수
	printf("금액을 입력하세요 > ");
	scanf("%d", &MyMoney); // 323500
	Money = 50000;

	
	Count = MyMoney / Money;
	printf("5만원 : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("만원 : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("5천원 : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("천원 : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("500원 : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("100원 : %d\n", Count);
	MyMoney %= Money;
	Money /= 2;

	Count = MyMoney / Money;
	printf("50원 : %d\t", Count);
	MyMoney %= Money;
	Money /= 5;

	Count = MyMoney / Money;
	printf("10원 : %d\n", Count);	


	return 0;
}