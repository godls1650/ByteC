#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*	1 ~ 45 �� 6���� ���ڸ� �̾Ƽ� 
	int mr[6] �� �ߺ� ���� �����Ѵ�.

	1 ~ 45 �� 7���� ���ڸ� �̾Ƽ�
	int r[7] �� �ߺ� ���� �����Ѵ�.

	mr�� ���Ұ���
	r�� 0 ~ 5�ε����� ���Ұ��� ��� ���ٸ�   "WIN"
	r�� 0 ~ 5�ε����� ���Ұ��� 5���� ����
	    mr�� 0 ~ 5�ε����� ����  r[6] �� ���ٸ�  "2nd"
								�ٸ��ٸ�			"3rd"
	r�� 0 ~ 5�ε����� ���Ұ��� 4���� ���ٸ�  "4th"
	r�� 0 ~ 5�ε����� ���Ұ��� 3���� ���ٸ�  "5th"

	��������� : "FAIL"

*/
int main() {
	int mr[6] = { 0 };
	int r[7] = { 0 };
	int count = 0;
	int bWin = 0;
	int tr = 0;
	srand((unsigned int)time(NULL));
	//����
	while (!bWin) {
		tr++;
		count = 0;
		for (int i = 0; i < 6; i++) {
			mr[i] = rand() % 45 + 1;
			for (int j = 0; j < i; j++) {
				if (mr[i] == mr[j]) {
					i--;
					break;
				}
			}
		}
		// ��÷
		for (int i = 0; i < 7; i++) {
			r[i] = rand() % 45 + 1;
			for (int j = 0; j < i; j++) {
				if (r[i] == r[j]) {
					i--;
					break;
				}
			}
		}
		printf("��÷ ��� > ");
		for (int i = 0; i < 6; i++) {
			printf("%2d ", r[i]);
		}
		printf("+%2d\n", r[6]);

		printf("  �� ��ȣ > ");
		for (int i = 0; i < 6; i++) {
			printf("%2d ", mr[i]);
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (mr[i] == r[j]) {
					count++;
					break;
				}
			}
		}
		printf("\n%d���� ��� : ", tr);
		switch (count) {
		case 6:
			printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�1��١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
			return;
			break;
		case 5:
			for (int i = 0; i < 6; i++) {
				if (mr[i] == r[6]) {
					printf("�١ڡ١ڡ١ڡ١�2��١ڡ١ڡ١ڡ١�\n");
					system("pause");
					return;
				}
			}
			printf("�١ڡ١�3��١ڡ١�\n");
			system("pause");
			break;
		case 4:
			printf("5����\n");
			system("pause");
			break;
		case 3:
			printf("5ó��\n");
			system("pause");
			break;
		default:
			printf("��\n");

		}
		
	}


	return 0;
}