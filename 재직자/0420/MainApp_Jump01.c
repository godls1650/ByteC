#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*  if ������ ��� ��, ���� ���� �̿��ؼ� �б⸦ ������ �ȴ�.
	1. �ݶ� 1200  2. ���̴�  1100  3. �� 1000 4.��ī������Ʈ 1500

*/

int main() {
	int pay = 0; // ���
	int money = 0; // ���Ա�
	int menu = 0; // ����

	printf("���Ա� > ");
	scanf("%d", money);

	printf("1. �ݶ� 1200  2. ���̴�  1100  3. �� 1000 4.��ī������Ʈ 1500 \nselect > ");
	scanf("%d", &menu);
	if (menu == 1)		pay = 1200; 
	else if (menu == 2) pay = 1100;
	else if (menu == 3) pay = 1000;
	else if (menu == 4 || menu == 5 || menu == 6) pay = 1500;
	else printf("���ᰡ �����ϴ�.\n");

	if (money < pay) {// 1000, 1100, 1200,  ��찡 �پ��ϴ�.
		printf("�ݾ��� �����մϴ�.\n");
		return 0;
	}

	printf("���ᰡ ���Խ��ϴ�.\n");
	printf("�ܵ� : %d\n", money - pay);



	return 0;
}