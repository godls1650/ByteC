#define _CRT_SECURE_NO_WARNINGS // scanf ���� ����
#include <stdio.h> 
// 365    300 + 60 + 5
void printMoneytoKor(int pMoney) {
	int test[5] = { 100000000, 10000, 1000, 100, 10 };
	int temp = 100011110;
	for (int i = 0; i < 5; i++) {
		if (pMoney / test[i]) {
			printf("%d", pMoney / test[i]);
			pMoney %= test[i];

			switch (i) {
			case 0: printf("��"); break;
			case 1: printf("��"); break;
			case 2: printf("õ"); break;
			case 3: printf("��"); break;
			case 4: printf("��"); break;
			}
		}
	}
	printf("��\n");
}

int main(void) {
	int nMoney = 0; // �ݾ��� �Է��� ����
	
	/*
	printf("�ݾ� �Է� > ");
	scanf("%d", &nMoney);
	
	printMoneytoKor(nMoney);
	�ݾ��Է�*/
	//3�ڸ��� �Է��ϸ� �ڸ� ���� ��� ǥ��
	char text = 0;
	int num = 100;
	printf("���ڸ� ������ �Է� > ");
	while (text != '\n') {
		scanf("%c", &text);
		text -= '0';
		printf("%d ", num * text);
		num /= 10;
	}


	return 0;
}
