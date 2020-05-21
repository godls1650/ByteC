#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*
	제어문  분기제어 
	   제어문의 기본 구조
	      제어명령어(제어식){
			실행 블록
		  }
	if (참 : (not Zero) or 거짓 (0))

	Switch() 변수의 값에 따라서 
	블록 내부의 실행 지점이 달라지는 제어문

	switch( 정수 ) {
	case 1 :
	case 2 :
	case 5 :
	}


*/
/*
	반복제어 
	- for
	- while : () 내부의 연산결과가 참값이면 블록을 실행 
	- do while

*/
#define TRUE	1
#define FALSE	0
typedef unsigned char Boolean;

void Contol01();
void Switch01();
void Switch2If();
void LCP();
int Random() {
	static int seed = 100;
	int r = 0;

	r = seed * 163341 % 100000;
	r = r < 0 ? -r : r;
	seed = r;

	return r;
}
void LoopEx();

/*
printf(" ");
printf("*");
printf("\n");

*/

void UpAndDown();
void starPrint();

int main(void) {
	//starPrint();
	UpAndDown();


	return 0;
}



void Contol01() {
	Boolean bClear = FALSE;

	int number1 = 300;
	int number2 = 200;

	int number3 = 0;
	// 삼항연산자    A ?  B  : C
	/* A : 참거짓
	   B : A의 결과가 참일 때 결과값
	   C : A의 결과가 거짓 일 때 결과값*/


	if (number1 < number2) number3 = number2;
	else number3 = number1;

	if (number1 < number2) number3 = number2;// (number1 < number2) ? number2 :   ;
	if (number1 >= number2) number3 = number1;//(number1 < number2) ? number1 :   ;


	number3 = (number1 < number2) ? number2 : number1;


	printf("%d\n", number3);
	printf("%d\n", (number1 < number2) ? number2 : number1);
	(number1 < number2) ? printf("%d\n", number2) : printf("%d\n", number1);

	if (number1 < number2)	printf("%d\n", number2);
	else					printf("%d\n", number1);


}
void Switch01() {
	int draw = 0;
	char menu = 0;

	printf("1. 직선(l) 2. 삼각형(t) 3. 사각형(s)\nselect > ");
	scanf("%c", &menu);
	switch (menu) {
	default:
		printf("메뉴입력이 잘못되었습니다.");
		break;
	
	case 'L':  case 'l': // 정수 상수값 제어에 있는 변수의 값과 같은 case가 실행 지점이 된다.
		printf("직선을 그린다.\n");
		break;
	case 'T': case 't':
		printf("삼각형을 그린다.\n");
		break;
	case 's':case 'S':
		printf("사각형을 그린다.\n");
		break;
	
	}

	

	
}
void Switch2If() {
	int draw = 0;
	char menu = 0;

	printf("1. 직선(l) 2. 삼각형(t) 3. 사각형(s)\nselect > ");
	scanf("%c", &menu);
	if (menu == 'l' || menu == 'L') {
		printf("직선을 그린다.\n");
	}
	else if (menu == 't' || menu == 'T') {
		printf("삼각형을 그린다.\n");
	}
	else if (menu == 's' || menu == 'S') {
		printf("사각형을 그린다.\n");
	}
	else {
		printf("메뉴에 없습니다.\n");
	}
}

void LCP() {
	char Table[3][3][10] = {
		"Draw","Lose" ,"Win",
		"Win", "Draw","Lose" ,
		"Lose","Win", "Draw" };
	int user = 0;
	int com = 0;
	srand((unsigned int)time(NULL));
	printf("1. 가위   2. 바위  3. 보자기\nselect > ");
	scanf("%d", &user);
	com = rand() % 3 + 1;
	printf("user : ");
	switch (user) {
	case 1: printf("가위 "); break;
	case 2: printf("바위 "); break;
	case 3: printf("보자기 "); break;
	}
	printf("vs ");
	switch (com) {
	case 1: printf("가위 "); break;
	case 2: printf("바위 "); break;
	case 3: printf("보자기 "); break;
	}
	printf(" : com\n");
	printf("결과 : %s\n", Table[user - 1][com - 1]);

	int result = user - com;


	if (user == com) printf("Draw\n");
	else if (result == 1 || result == -2) printf("user Win\n");
	else printf("user Lose\n");
}

void LoopEx() {

	// 총 반복 횟수를 정할 수 있는 경우 : for (A ; B ; C)
	// A : 반복횟수를 저장할 변수를 지정(선언) 
	// B : A에서 정한 초기값이 증가할 범위 
	// C : 초기값 변수의 증감식
	int num = 0;
	for (int i = 0; i < 10; i++) {

		do {
			printf("<while>음수를 입력하세요 > ");
			scanf("%d", &num);
		} while (num >= 0);

		printf("입력된 음수값 > %d\n", num);
	}
}

void UpAndDown() {
	int com = 0;
	int user = 0;
	int Life = 7;
	bool bAdjust = false;
	srand((unsigned int)time(NULL));
	com = rand() % 100 + 1;

	while (!bAdjust && Life != 0) {
		printf("1 ~ 100 사이의 값 중 하나를 입력 하세요 (%d회 남음)> ", Life);
		scanf("%d", &user);

		if (user > com) {
			printf("com : DOWN\n");
			Life--;
		}
		else if(user < com) {
			printf("com : UP\n");
			Life--;
		}
		else {
			printf("com : Success\n");
			bAdjust = true;
		}
	}
	if (bAdjust) {
		printf("you Win\n");
	}
	else {
		printf("computer hid %d\n", com);
		printf("you Lose\n");
	}

}
/*											SPACE		ASTERISK	i	j(*)
LINE 1:		'*'  '*'  '*'  '*'  '*'			  0             5		0	 5
LINE 2:		' '  '*'  '*'  '*'  '*'           1             4		1    4
LINE 3:		' '  ' '  '*'  '*'  '*'           2             3		2    3
LINE 4:		' '  ' '  ' '  '*'  '*'           3             2		3    2
LINE 5:		' '  ' '  ' '  ' '  '*'           4             1		4    1


sp	as	i
4	1	0
3	3	1
2	5	2
1	7	3
0	9	4



*/
void starPrint() {
	//printf("*");
	//printf(" ");
	//printf("\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <5; j++) {
			if ((i == 4-j)|| (i == j)) printf("*");
			else printf(" ");
		}
		
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++)
			printf(" ");

		for (int j = 0; j <= 2*i; j++)
			printf("*");
		printf("\n");

	}

}