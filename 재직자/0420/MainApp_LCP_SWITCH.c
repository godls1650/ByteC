#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 ������ : 35 ~ 65

 65 - 35 + 1 => 31
 2020 - 1992 + 1
 rand() % 31 + 35    --> (0 ~  30) + 35
 rand() % ���� + �ּҰ�
*/
int main() {

	//50000 --> 50000/10 --> 5000  --> x*10
	// 10��
	//920505						   11001110			
	// 120    05   05  // 1900 + year [][][][][][][][]



	int com = 0; 
	int user = 0;
	srand((unsigned int)time(NULL));
	com = rand() % 3 + 1; 
	printf("1.���� 2.���� 3.���ڱ� \nselect >");
	scanf("%d", &user); // u 1    c :  1,  2,  3   r : 0 (D)   , -1 (L)   -2 (W)
	// ��� : 0    �� : -1, 2    �� : 1, -2
	switch (user - com) {
	case 0 :			printf("���"); break;
	case 1 : case -2 :	printf("�̱�"); break;
	//case -1 : case 2 : 
	default: printf("�й�"); break;
	}
	return 0;
}