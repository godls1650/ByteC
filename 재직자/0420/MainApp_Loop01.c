#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*���� ����� �������� �ݺ� ���θ� ���� */
//while �� �ּ� �ݺ� Ƚ�� : 0
//do ~ while �ּ� �ݺ� Ƚ�� : 1
int main() {
	int word = 0; // �ܾ� ����   time is running out\n 
	int text = 0; // ���� ����
	char c = 0;
	printf("���� �Է� > ");
	while (c != '\n') {
		scanf("%c", &c);
		if (c == ' ' || c == '\n') {
			if (c == ' ') text++;
			word++;
		}
		else
			text++;

		/*
		switch (c) {
		case '\n': case ' ':
			word++;
			text++;
			break;
		default :
			text++;
			break;
		
		}*/
		//if (c == '\n')break;
	}
	
	printf("���ڼ� : %d  �ܾ� �� : %d\n", text, word);
	

	return 0;
}