#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int pay = 0; // ���
	int money = 0; // ���Ա�
	int menu = 0; // ����

	printf("���Ա� > ");
	scanf("%d", &money);

	printf("1. �ݶ� 1200  2. ���̴�  1100  3. �� 1000 4.��ī������Ʈ 1500 \nselect > ");
	scanf("%d", &menu);
	//() : �������� 
	switch (menu) { // ���� ������ ������ ���Ŀ�
	// case [���� ���]   ������ case �� ���� ���
	// case :  �ڵ� ���� ����
	// case ������� �ߺ� X  //������� : ���� �ߴ� --> break
	case 1: // if( menu == 1 ) {
		pay = 1200;
		break;//  }
	case 2:
		pay = 1100;
		break;
	case 3:
		pay = 1000;
		break;
	case 4: case 5: case 6:
		pay = 1500;
		break;
	default : // ������ ��� �� 
		printf("���ᰡ �����ϴ�.\n");

	}
	

	if (money < pay) {// 1000, 1100, 1200,  ��찡 �پ��ϴ�.
		printf("�ݾ��� �����մϴ�.\n");
		return 0;
	}
	switch (money < pay) {
	case 1:
		printf("�ݾ��� �����մϴ�.\n");
		return 0;
		
	case 0:
		break;
	}


	printf("���ᰡ ���Խ��ϴ�.\n");
	printf("�ܵ� : %d\n", money - pay);

	return 0;
}