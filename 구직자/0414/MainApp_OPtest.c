#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	���� 3���� scanf �ϳ��� ����ؼ� �Է��� ����
	3�� ������ ���� ū ���� ����ϴ� ���α׷� �ۼ�
	(��� ��� X)
*/
int main() {
	int n1 = 0, n2 = 0, n3 = 0;
	int result = 0;
	printf("���� 3���� �Է��ϼ��� > ");
	scanf("%d %d %d", &n1, &n2, &n3);

	result = (n1 < n2) ? 
		((n2 < n3) ? n3 : n2) : 
		((n1 < n3) ? n3 : n1);

	printf("�� ���� �� ū ���ڴ� %d �Դϴ�.\n", result);




	return 0;
}