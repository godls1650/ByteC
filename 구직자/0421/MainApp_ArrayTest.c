#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
	/*���� ����*/
	int myLotto[5][6] = { 0 };
	int temp[6] = { 0 };
	int Winning[7] = { 0 }; // 6���ε����� ���ʽ���ȣ
	int money = 0, count = 0;

	int check[5] = { 0 };
	int checkCnt = 0;
	int bSecond = 0;

	srand((unsigned int)time(NULL)); // ���� SEED ����
	
	printf("�󸶳� �����ǲ����� > "); // ������ �Է�
	scanf("%d", &money);

	count = money / 1000; // ��ȸ �̴°ǰ�
	for (int i = 0; i < count; i++) {
		/*�ӽ� �迭 temp �� �ζ� ���� ����*/
		for (int j = 0; j < 6; j++) {
			temp[j] = rand() % 45 + 1;
			for (int k = 0; k < j; k++) {
				if (temp[j] == temp[k]) {
					j--; break;
				}
			}
		}
		/*����� �ζ� ��ȣ�� myLotto[i] �࿡ ����*/
		for (int j = 0; j < 6; j++) {
			myLotto[i][j] = temp[j];
		}
		/*���� ������ count ��ŭ �ݺ�*/
	}

	/*�� �ζ� ���� ���*/
	for (int i = 0; i < count; i++) {
		printf("��  �� %c\t", 'A' + i);
		for (int j = 0; j < 6; j++) {
			printf("%2d ", myLotto[i][j]);
		}
		printf("\n");
	}

	/*�Ͽ����Դϴ� . ��� ���ɴϴ�.*/
	for (int i = 0; i < 7; i++) { // ���ʽ� ��ȣ���� �ѹ���
		Winning[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++) {
			if (Winning[i] == Winning[j]) {
				i--; break;
			}
		}
	}

	printf("\n------------------<<��÷ ��ȣ>>---------------------\n");
	for (int i = 0; i < 6; i++) {
		printf("%2d ", Winning[i]);
	}
	printf("  + %2d\n", Winning[6]);
	/*��ȣ Ȯ��*/
	for (int i = 0; i < count; i++) {
		checkCnt = 0;// ���� ���� count�� �ʱ�ȭ
		for (int j = 0; j < 6; j++) { /*myLotto �ε�����*/
			for (int k = 0; k < 6; k++) {/*Winning�� �ε����� ������ �ݺ�*/
				if (myLotto[i][j] == Winning[k]) { /*�ϸ鼭 ���� ������ ��ȸ*/
					checkCnt++; /*���ٸ� count �� �ø���*/
					break; /*�� ��ȣ�� ���� ���� ã�ұ� ������ ���� ��ȣ�� �Ѿ�� ���� �ߴ�*/
				}
			}
		}/*���⼭ �ϳ��� �ζǹ�ȣ ������ ����*/
		check[i] = checkCnt; //���� ������ Ȯ���ؾ��ϱ� ������ check�迭�� count�� ����
	}

	/*���*/
	for (int i = 0; i < count; i++) {
		printf("��  �� %c(%d��)\t", 'A' + i, check[i]);
		switch (check[i]) {
		case 6 : printf("1��\n"); break;
		case 5 :
			for (int j = 0; j < 6; j++) {
				if (myLotto[i][j] == Winning[6]) {
					bSecond = 1;// 2���� ����
					break;
				}
			}
			if (bSecond) printf("2��\n");
			else printf("3��\n");
			break;
		case 4: 
			printf("4��\n");
			break;
		case 3:
			printf("5��\n");
			break;
		default : 
			printf("��\n");
		}
	}
	



	return 0;
}
