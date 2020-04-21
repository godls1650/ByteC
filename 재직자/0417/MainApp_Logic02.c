#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FALSE   0
#define TRUE    1
/* 
	모든 제어문은
	 - 실행 내용이 1 Line 인 경우 블록 기호를 제거해도 된다.
*/
int main() {
	const double Girin = 140.0;
	double Child_H = 0.0; // 애  키
	short bTall = FALSE;

	printf("알바가 애를 잡았습니다. > ");
	scanf("%lf", &Child_H); // 알바가 키를 잽니다.
	// ()의 조건이 참인 경우 

	bTall = Child_H >= Girin;// T / F
	if (bTall) printf("오... 통과..\n");
	else	   printf("우유먹고와라 애송이.\n");// ()의 조건이 거짓인 경우 
	
	// 쿠팡, 배민 등 어플에서 본사 카드로 결제시 만 10퍼센트 적립을 합니다. ㅇㅇㅊ들..
	int FoodPrice = 0;
	int Point = 533;
	short bCompanyCard = FALSE;
	char Text = 0;

	printf("주문한 음식값 > ");
	scanf("%d", &FoodPrice);// []
	printf("결제 카드가 배민카드 입니까 ? (Y/N)> ");
	scanf("%*c%c", &Text);
	if (Text == 'Y' || Text == 'y')
		bCompanyCard = TRUE;
	else
		bCompanyCard = FALSE;

	bCompanyCard = (Text == 'Y') ? TRUE : FALSE; // 반드시 참 거짓 위치의 값이 있어야 한다.

	if (bCompanyCard) {
		Point += FoodPrice / 100;
	}
	else {
		printf("카드 만드세요 ㅋㅋㅋ\n");
	}
	printf("결제 금액 : %d원\n", FoodPrice + 2000);
	printf("적립포인트 : %d Point\n", FoodPrice / 100);
	printf("누적포인트 : %d Point\n", Point);

	int bohumgeum = 120000;
	int gender = 2; // m : 10 %   f : 20%

	bohumgeum *= (gender == 2) ? 1.2 : 1.1;// 삼항연산 : 값을 전달하는 경우만 사용 
	if (gender == 2) printf("여성");
	else printf("남성");
	printf(" 보험금 : %d\n", bohumgeum);



	return 0;
}