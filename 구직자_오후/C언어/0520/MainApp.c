#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*
	���  �б����� 
	   ����� �⺻ ����
	      �����ɾ�(�����){
			���� ���
		  }
	if (�� : (not Zero) or ���� (0))

	Switch() ������ ���� ���� 
	��� ������ ���� ������ �޶����� ���

	switch( ���� ) {
	case 1 :
	case 2 :
	case 5 :
	}


*/
/*
	�ݺ����� 
	- for
	- while : () ������ �������� �����̸� ����� ���� 
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
	// ���׿�����    A ?  B  : C
	/* A : ������
	   B : A�� ����� ���� �� �����
	   C : A�� ����� ���� �� �� �����*/


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

	printf("1. ����(l) 2. �ﰢ��(t) 3. �簢��(s)\nselect > ");
	scanf("%c", &menu);
	switch (menu) {
	default:
		printf("�޴��Է��� �߸��Ǿ����ϴ�.");
		break;
	
	case 'L':  case 'l': // ���� ����� ��� �ִ� ������ ���� ���� case�� ���� ������ �ȴ�.
		printf("������ �׸���.\n");
		break;
	case 'T': case 't':
		printf("�ﰢ���� �׸���.\n");
		break;
	case 's':case 'S':
		printf("�簢���� �׸���.\n");
		break;
	
	}

	

	
}
void Switch2If() {
	int draw = 0;
	char menu = 0;

	printf("1. ����(l) 2. �ﰢ��(t) 3. �簢��(s)\nselect > ");
	scanf("%c", &menu);
	if (menu == 'l' || menu == 'L') {
		printf("������ �׸���.\n");
	}
	else if (menu == 't' || menu == 'T') {
		printf("�ﰢ���� �׸���.\n");
	}
	else if (menu == 's' || menu == 'S') {
		printf("�簢���� �׸���.\n");
	}
	else {
		printf("�޴��� �����ϴ�.\n");
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
	printf("1. ����   2. ����  3. ���ڱ�\nselect > ");
	scanf("%d", &user);
	com = rand() % 3 + 1;
	printf("user : ");
	switch (user) {
	case 1: printf("���� "); break;
	case 2: printf("���� "); break;
	case 3: printf("���ڱ� "); break;
	}
	printf("vs ");
	switch (com) {
	case 1: printf("���� "); break;
	case 2: printf("���� "); break;
	case 3: printf("���ڱ� "); break;
	}
	printf(" : com\n");
	printf("��� : %s\n", Table[user - 1][com - 1]);

	int result = user - com;


	if (user == com) printf("Draw\n");
	else if (result == 1 || result == -2) printf("user Win\n");
	else printf("user Lose\n");
}

void LoopEx() {

	// �� �ݺ� Ƚ���� ���� �� �ִ� ��� : for (A ; B ; C)
	// A : �ݺ�Ƚ���� ������ ������ ����(����) 
	// B : A���� ���� �ʱⰪ�� ������ ���� 
	// C : �ʱⰪ ������ ������
	int num = 0;
	for (int i = 0; i < 10; i++) {

		do {
			printf("<while>������ �Է��ϼ��� > ");
			scanf("%d", &num);
		} while (num >= 0);

		printf("�Էµ� ������ > %d\n", num);
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
		printf("1 ~ 100 ������ �� �� �ϳ��� �Է� �ϼ��� (%dȸ ����)> ", Life);
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