/* 2020-04-01 _2nd_
Character / ASCII  / Character Set   */

/*
���� : ���� ������ ���� ǥ�� ���� ���� �� 
ASCII 
UNICODE(ANSI)
MULTIBYTE 

CHARacter : char  :  1Byte
*/
#include <stdio.h>
/* 2020-04-01 _2nd_
 STanDard Input Output
 Escape  seq / format
 \�� �ִ� ���� : �̽������� ������
 \a: Alarm

 \b : back Space
 \t : tab
 \n : eNter (New line)
 \\ : \�� ���
 \" , \' : ����ȿ� " , '�� ���

 \0 : NULL����
 */
int main(void) {
	char cText1 = '0'; // cText = 48
	char cText2 = '\0';
	// ���� , ����  �� ����
	// ASCII ���� ����
	// ��� ���� : %c 
	// 'A' : 65   'a' : 97   '0' : 48
	// "100 * 20" --->  "100" --> stoi() --> 100
	// '0'-48 =/= 0
	cText1 = 'a' - ' ';
	printf("cText1 : %c\n", cText1);
	printf("cText1 : %d\n", cText1);

	printf("hello world\"\n");

	return 0;
}