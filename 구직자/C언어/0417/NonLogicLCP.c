#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int user = 0;
	int com = 0;
	int result = 0;
	int win = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		printf("1.���� 2.���� 3.���ڱ� \nselect > ");
		scanf("%d", &user);
		user -= 2;				// -1  0   1
		com = rand() % 3 - 1;   // -1  0   1

		result = user - com; // ���º� => 0
							 // �� : -1, -1 , 2
							 // �� : -2,  1   1
		if (user == -1)		 printf("user : ����");
		else if (user == 0)  printf("user : ����");
		else				 printf("user : ���ڱ�");

		if (com == -1)		 printf(" vs com : ����\n");
		else if (com == 0)   printf(" vs com : ����\n");
		else				 printf(" vs com : ���ڱ�\n");



		switch (result) {
		case 0:
			printf("���º�\n");
			break;
		case 1: case -2:
			printf("��!\n");
			win++;
			break;
		case -1: case 2:
			printf("��!\n");
			break;
		}
	}
	printf("�·� : %.2lf%%\n", (double)win / 10);

	return 0;
}