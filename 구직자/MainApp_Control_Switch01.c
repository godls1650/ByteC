#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* SWITCH _ CASE
	switch ������ ����� ������
	�� ������ ������ ������ ����� �� �ִ� ������� case�� 
	�ڵ��� ���� ������ �����ϴ� �б� ��� 
	100 ~ 0 ������ ������ �Է��ϰ�
	10 ~ 9 �� A
	8 ~ 8 �� B
*/
//10.5
// num = (int)10.5
//10   5

/*
case 10 :
	switch (dotDown) {
		case 5:
	}

*/

int main() {
	int menu = 0;
	int score = 0;
	char text = 0;
	menu = 4;
	switch (menu) {
	case 1: // if(menu == 1)
		printf("���� ����մϴ�.\n");
		break;// ������� : �ݺ����� , switch
	case 2:
		printf("���� ����մϴ�.\n");
		break;
	case 3:
		printf("�ﰢ���� ����մϴ�.\n");
		break;
	case 4:
		printf("�簢���� ����մϴ�.\n");
		break;
	default :
		printf("�޴��� �����ϴ�..\n");

	}
	printf("���� �Է� (100 ~ 0) > ");
	scanf("%d", &score);
	switch (score/10) {
	case 10: case 9: text = 'A'; break;
	case  8:		 text = 'B'; break;
	case  7:		 text = 'C'; break;
	case  6:		 text = 'D'; break;
	default :		 text = 'F';
	}
	

	return 0;
}