#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* ����� ���� : ����� �����ؼ� �ٸ� Ÿ���� �����.  ������ : ������ ���� (enum) */
#define VERTICAL 3
#define HORIZON	 3
int main() {
	int mArray[5] = { 100000000, 10000, 1000, 100, 10 };
	char subject[5][100] = { "����" ,"����", "����", "����", "��ȸ"}; // ������ �迭
	int result1[3] = { 0, -1, -2 };
	int result2[3] = { -2, 0, -1 };
	int result3[3] = { -1, -2,  0 };

	int result4[VERTICAL][HORIZON] = {{ 0, 2, 1 },{ 1, 0, 2 },{ 2, 1,  0}};
	char text[3][10] = { "DRAW", "WIN", "LOSE" };
	// ���������� �� ���� �Ⱦ��� 
	int com = 0;
	int user = 0;
	printf("1. ���� 2���� 3���ڱ� > ");
	scanf("%d", &user);
	user -= 1;
	com = rand() % 3;

	printf("%s\n", text[result4[user][com]]);



	
	for (int i = 0; i < VERTICAL; i++) {
		for (int j = 0; j < HORIZON; j++) {
			printf("%2d ,", result4[i][j]);
		}
		printf("\n");
	}

	printf("result4[0][2] : %p\n", &result4[0][2]);
	printf("result4[1][0] : %p\n", &result4[1][0]);

	printf("result4[0][2] : %p\n", &result4[1][2]);
	printf("result4[1][0] : %p\n", &result4[2][0]);

	//  result4[0]  == result1
	// result4[1] == result2 
	// result4[2] == result3
	

	int money = 123151360;//�Ͼ���õ���ʿ���õ������ʿ�

	for (int i = 0; i < 5; i++) {
		if (money / mArray[i]) {
			printf("%d", money / mArray[i]);
		}
		money %= mArray[i];
		switch (i) {
		case 0: printf("��"); break;
		case 1: printf("��"); break;
		case 2: printf("õ"); break;
		case 3: printf("��"); break;
		case 4: printf("��"); break;
		}
	}
	printf("��\n");

	return 0;
}