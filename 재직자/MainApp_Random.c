#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // STanDard Libaray
#include <time.h> // system �ð��� ��� 
/*
 ���� �Լ� : rand()
 �޸𸮿�[223425]�� ����
 ���� ---> [41]
 Seed ������ ����
 srand(unsigned int )

 time.h --> time(NULL) 

  1900 �� 1�� 1�� 00 :00 : 00 
*/
int main() {						// 
	srand((unsigned int)time(NULL));// ������� : main-> srand -> time
	                                // ������� : time -> srand -> main
	int user = 0;
	int com = 0;
	// rand() % (�ִ밪 - �ּҰ� + 1 ) + �ּҰ�
	com = rand() % 3 + 1;
	printf("1.����  2. ���� 3. ���ڱ� \n select > ");
	scanf("%d", &user);
	printf("user : ");
	if (user == 1)		 printf("����");
	else if (user == 2)  printf("����");
	else				 printf("���ڱ�");
	printf(" vs com : ");
	if (com == 1)		 printf("����");
	else if (com == 2)   printf("����");
	else                 printf("���ڱ�");
	printf("\n");

	if (com == user) {
		printf("���º�\n");
	}
	else if (user == 1 && com == 2 || user == 2 && com == 3 || user == 3 && com == 1) {
		printf("�й�\n");
	}
	else {
		printf("��\n");
	}

	
	return 0;
}