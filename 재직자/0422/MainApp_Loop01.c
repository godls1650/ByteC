#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	�ݺ��� : for 

	����
	for ( �ʱⰪ ; �񱳽� ; ������) {
		���� �� ������ ���� 
		
	}
	�ʱⰪ : �ݺ� ������ �� ������ �����ϰų� �����´�.
	������ : ���ذ�(�ʱ� ����)�� �ݺ� 1ȸ�� �󸶳� �����ϴ��� 
*/

int main() {
	int i = 0, j = 0;
	for ( ; i < 10; i++) {
		printf("%dȸ ������ \n", i + 1);
	}
	for (i = 0; i < 10; i++) {
		printf("%dȸ ������ 2��° \n", i + 1);
	}
	
	for (int j = 0; j < 10; j++) {
		printf("%dȸ ������ \n", j + 1);
	}
	//j ������ ���� �Ǿ����� �ʽ��ϴ�.

	for (int j = 0; j < 10; j++) {
		printf("%dȸ ������ 2��° \n", j + 1);
	}


	return 0;
}