#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int pay = 0; // 요금
	int money = 0; // 투입금
	int menu = 0; // 선택

	printf("투입금 > ");
	scanf("%d", &money);

	printf("1. 콜라 1200  2. 사이다  1100  3. 물 1000 4.포카리스웨트 1500 \nselect > ");
	scanf("%d", &menu);
	//() : 정수변수 
	switch (menu) { // 시작 지점이 결정된 이후에
	// case [정수 상수]   나머지 case 는 없는 취급
	// case :  코드 실행 지점
	// case 상수값은 중복 X  //보조제어문 : 제어 중단 --> break
	case 1: // if( menu == 1 ) {
		pay = 1200;
		break;//  }
	case 2:
		pay = 1100;
		break;
	case 3:
		pay = 1000;
		break;
	case 4: case 5: case 6:
		pay = 1500;
		break;
	default : // 나머지 모든 값 
		printf("음료가 없습니다.\n");

	}
	

	if (money < pay) {// 1000, 1100, 1200,  경우가 다양하다.
		printf("금액이 부족합니다.\n");
		return 0;
	}
	switch (money < pay) {
	case 1:
		printf("금액이 부족합니다.\n");
		return 0;
		
	case 0:
		break;
	}


	printf("음료가 나왔습니다.\n");
	printf("잔돈 : %d\n", money - pay);

	return 0;
}