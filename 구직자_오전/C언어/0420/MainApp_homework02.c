#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE	0
#define TRUE	1
/*
RAND ���� �̿��� ��� : �ִ� <INFINITE>

*/
int main() {
	int user = 0;// ����� �Է����� 1 ~ 100 ���� ���� �����Ѵ�.
	int com = 0; // ��ǻ�ʹ� 1 ~ 100 ������ ���� �ϳ� �����ؼ� user�� ���� ����� �Ѵ�.
	int bSuccess = 0;
	int Max = 50, Min = 1;
	srand((unsigned int)time(NULL));
	printf("User Select (1 ~ 50) > ");
	scanf("%d", &user);

	while ( !bSuccess ) {
		//com = rand() % (Max - Min + 1) + Min;
		// ������ ������ ����
		com = (Max + Min) / 2;

		printf("com say : %d\n", com);

		if (com == user) {
			printf("��ǻ�Ͱ� ���ڸ� ������ϴ�.\n");
			bSuccess = TRUE;
		}
		else if (com > user) {
			printf("user : Down\n");
			Max = com;
		}
		else {
			printf("user : Up\n");
			Min = com;
		}

	}
	

}