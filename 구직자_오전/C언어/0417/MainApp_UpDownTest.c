#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/*��ǻ�Ͱ� �ּ����� �õ� Ƚ���� ���� �� ���ڸ� ���߰� �ϼ���*/
int main() {
	int user = 0;
	int com = 0;
	int max = 0, min = 0;
	int cnt = 0;
	int bSearch = 0;
	max = 100;  
	min = 1;

	printf("���ڸ� �Է��ϼ��� (1 ~ 100)> ");
	scanf("%d", &user);
	system("cls");
	while (bSearch != 1) {
		printf("��ǻ�Ͱ� ���� ���� ���Դϴ�.");
		for (int i = 0; i < (3 + cnt); i++) {
			printf(".");
			Sleep(500);
			if (i == 7) {
				printf("�����׿�.. ���簡���ϴ�.\n��û�Ѱ�...\n");
				Sleep(500);
			}
		}
		com = (max + min) / 2;
		printf("com : %d�Դϱ� ? \n", com);
		Sleep(1000);
		if (com == user) {
			bSearch = 1;
			printf("user : �����Դϴ�.");
		}
		else if (com > user) {
			printf("user : DOWN �Դϴ�.\n");
			max = com;
		}
		else{
			printf("user : UP �Դϴ�.\n");
			min = com;
		}
		Sleep(1000);
		cnt++;
	}

	printf("��ǻ�Ͱ� %dȸ �õ��Ͽ� ���� ã�ҽ��ϴ�.\n", cnt);


	return 0;
}