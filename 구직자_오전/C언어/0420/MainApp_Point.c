#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	�޸� ����� 
	  RAM : Random Access Memory -> ���� �����ϴ� ������ 
	  ���α׷��� �޸𸮿� �ö󰡴� ��� (���� �� ��)
	  ����¡ : ������ 
	  ��� :  ���� �������� 

	  ����� �������� ��� �ϳ��� �����ͷ� ���

	  �迭 -> ������ �̸��� ����ϴ� ���� ������ ����
	  Ÿ�� , ����, ���� --> �ε��� ũ�� --> [const int]

	  // 10���� �ε����� ���� �迭�� �������� �Է��Ѵ�.
	  // �ּ�, �ִ밪�� �Է¹޾Ƽ� 
	  // �ߺ��� ���ּ�.
*/
int main() {
	int arr[6];
	int max = 45;
	int min = 1;
	for (int i = 0; i < 6; i++) {
		arr[i] = rand() % (max - min + 1) + min;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 6; i++)
		printf("%2d ", arr[i]);
	printf("\n");


	/*
	// �ϳ��ϳ��� ���� ����ϴ� ��� : �����̸� + ������ ��ġ��ȣ
	a = 100; score[0] = 100;
	b = 89; score[1] = 89;
	score[2] = c = 88;
	d = score[3] = 79;
	e = score[4] = 87;

	//printf("score[7] => %d\n", score[7]);


	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);
	printf("%p\n", &d);
	printf("%p\n", &e);

	printf("score : %p\n", score);// �迭�� �̸��� ����ϴ� ��� : �迭�� ���� ��ġ
	printf("score + 1 : %p\n", score + 1);// �޸� �ּ� ����
	// & :  �ּ� ����  ��  �ּҸ� �̿��ؼ� ���� ������. : �������� *
	printf("*score : %d\n" ,*score);
	printf("*score + 1 : %d\n", *score + 1); // ������ �켱���� 
	printf("*(score + 1) : %d\n", *(score + 1)); // ������ �켱���� 


	for(int i = 0;  i < 5; i++)
		printf("score[%d] : %p\n",i,  &score[i]); // �ε��� ��ȣ�� ������ ����� �� ����
	// score + sizeof(int) * indexNumber
	*/


	/*
	int a, b, c, d, e;
	int total = 0;
	int score[5]; // �ε��� ũ��

	for (int i = 0; i < 5; i++) {
		
	}
	printf("���� : %d\n", total);
	
	*/

	return 0;
}