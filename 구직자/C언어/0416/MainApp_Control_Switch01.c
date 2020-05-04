#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* SWITCH _ CASE
	switch 값으로 사용할 변수와
	그 변수의 각각의 값으로 사용할 수 있는 상수값을 case로 
	코드의 실행 지점을 설정하는 분기 제어문 
	100 ~ 0 까지의 점수를 입력하고
	10 ~ 9 은 A
	8 ~ 8 은 B
*/
//10.5
// num = (int)10.5
//10   5

/*
case 10 :
	switch (dotDown) {
		case 5:
	}

*/

int main() {
	int menu = 0;
	int score = 0;
	char text = 0;
	menu = 4;
	switch (menu) {
	case 1: // if(menu == 1)
		printf("원을 출력합니다.\n");
		break;// 보조제어문 : 반복제어 , switch
	case 2:
		printf("선을 출력합니다.\n");
		break;
	case 3:
		printf("삼각형을 출력합니다.\n");
		break;
	case 4:
		printf("사각형을 출력합니다.\n");
		break;
	default :
		printf("메뉴가 없습니다..\n");

	}
	printf("점수 입력 (100 ~ 0) > ");
	scanf("%d", &score);
	switch (score/10) {
	case 10: case 9: text = 'A'; break;
	case  8:		 text = 'B'; break;
	case  7:		 text = 'C'; break;
	case  6:		 text = 'D'; break;
	default :		 text = 'F';
	}
	

	return 0;
}