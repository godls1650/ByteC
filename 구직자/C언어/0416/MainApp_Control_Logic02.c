#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YEAR 2020
/* ���
   �񱳿��� : ũ��� 
    >   <   == 
	>=  <=  !=
	
	�������� 
	AND : �� ������ ���� ��츸 ����		&&    &
	OR  : �� ������ �ϳ��� �����ص� ����	||	  |
	NOT : ���� ���� �ݴ�					 !    ~

	���ڰ� 1���� �Է� ������
	�ҹ����� ��� �빮�ڷ� ����
	�빮�ڴ� �ҹ��ڷ� ����
	Ư�����ڴ� ���� ����
	����ϴ� ���α׷� 
*/
int main() {
	/*�������*/
	int myBirthYear = 0;
	int resultAge = 0;
	int nPay = 0;
	int bHelpCard = 1;
	printf("�¾ �⵵ : ");
	scanf("%d", &myBirthYear);
	resultAge = YEAR - myBirthYear + 1;
	if (resultAge >= 20)
		if (bHelpCard)
			nPay = 0;
		else
			nPay = 1250;
	else if (resultAge >= 14)
		nPay = 860;
	else if (resultAge >= 8)
		nPay = 760;
	else if (resultAge >= 0)
		nPay = 0;
	else {
		printf("�Է� �� ���� ������ ���Է� �ϼ���\n");
		return 0;
	}
	printf("������� : %d��\n", nPay);
	
	char text = 0;
	printf("�ƹ� ���ڳ� �Է��ϼ��� (�ѱ� X) > ");
	scanf("%*c%c", &text);
	if (text >= 'A' && text <= 'Z') {
		text += ' ';//text += 32
	}
	else if (text >= 'a' && text <= 'z') {
		text -= ' ';//text += 32
	}
	else {
		printf("���� or Ư������ �Դϴ�.\n");
		return 0;
	}
	printf("��ȯ �� : %c\n", text);
	return 0;
}