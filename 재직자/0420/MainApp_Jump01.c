#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*  if 제어의 경우 참, 거짓 값을 이용해서 분기를 나누게 된다.
	1. 콜라 1200  2. 사이다  1100  3. 물 1000 4.포카리스웨트 1500

*/

int main() {
	int pay = 0; // 요금
	int money = 0; // 투입금
	int menu = 0; // 선택

	printf("투입금 > ");
	scanf("%d", money);

	printf("1. 콜라 1200  2. 사이다  1100  3. 물 1000 4.포카리스웨트 1500 \nselect > ");
	scanf("%d", &menu);
	if (menu == 1)		pay = 1200; 
	else if (menu == 2) pay = 1100;
	else if (menu == 3) pay = 1000;
	else if (menu == 4 || menu == 5 || menu == 6) pay = 1500;
	else printf("음료가 없습니다.\n");

	if (money < pay) {// 1000, 1100, 1200,  경우가 다양하다.
		printf("금액이 부족합니다.\n");
		return 0;
	}

	printf("음료가 나왔습니다.\n");
	printf("잔돈 : %d\n", money - pay);



	return 0;
}