#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	�迭 : �����͸� ���������� �����Ͽ� ����ϴ� �ϳ��� �ڷᱸ�� 
	   - ������ Ÿ���� ������ �������� �����Ѵ�.
	�迭�� ���Ǵ� ��� 
	  1. ���� �����͸� �����ؼ� �ϳ��� ǥ���Ѵ�. 'D' 'O' 'G' -> dog ���ڿ�
	  2. �뵵�� ���� ���� ������ ����
	     ���� ���� ���� ��ȸ ���� 

	�迭�� ���� 
	   Ÿ�� �迭�̸�[ũ����]  ;
	   ũ�� ���  : �ε��� ũ��( �� ��� �����͸� ���� �ϴ� �迭�ΰ�)
	

*/
#define SIZE	10
int main() {
	int x = 1000, y = 2000, z = 3000;
	int number[3] ; //main�Լ��� �����ϸ鼭 ���ÿ� �޸𸮸� �Ҵ��ؾ� �ϱ� ������ 
				  // �ε��� ũ�⿡�� ������ ���� �� ����. :: ���ͷ�, �ɺ��� ��� �� �������� 

	printf("number : %p\n", number); // �迭�� �޸� ���� �ּ�

	number[0] = 100; // �ε��� ��ȣ : �迭�̸����� �޸� ũ��� �󸶳� ������ �ִ°�
	number[1] = 200; // �ε��� ��ȣ ���� : 0 ~ (�ε���ũ��-1)
	number[2] = 300; // �ε��� ��ȣ���� : �����Ϸ�  X   ����� O
	// number : size 3
	int total = 0;
	for (int n = 0; n < 3; n++) {
		printf("number[%d] : %d\n",n,  number[n]);
		total += number[n];
	}

	//printf("number[5] = %d\n", number[5]);
	//number[5] = 10000;
	printf("z : %d\n", z);
	//number[3] = 4000;
	// %p  (Pointer : �޸� �ּҰ� (16����) �� ����Ѵ�.
	printf("x������ �޸� ��ġ : %p\n", &x);
	printf("y������ �޸� ��ġ : %p\n", &y);
	printf("z������ �޸� ��ġ : %p\n", &z);

	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);


	return 0;
}
