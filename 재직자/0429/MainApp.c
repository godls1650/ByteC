#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	�迭�� ��Ī�� �̿��� �ּ� ���� & ������

*/
#define _SIZE	10
int main() {
	int arr[_SIZE] = { 0 };
	int* ptr;
	//const char* _Format = "���ݱ��� printf�� �̰� �ߴ��̴ϴ�.\n";
	
	ptr = arr;
	printf("arr + 0 : %p\t &arr[0] : %p\n", arr + 0, &arr[0]);
	printf("arr + 1 : %p\t &arr[1] : %p\n", arr + 1, &arr[1]);
	printf("arr + 2 : %p\t &arr[2] : %p\n", arr + 2, &arr[2]);
	printf("arr + 3 : %p\t &arr[3] : %p\n", arr + 3, &arr[3]);
	printf("arr + 4 : %p\t &arr[4] : %p\n", arr + 4, &arr[4]);
	printf("arr + 5 : %p\t &arr[5] : %p\n", arr + 5, &arr[5]);

	for (int i = 0; i < _SIZE; i++) {
		printf("ptr + %d : %p\n", i, ptr + i);
	}

	return 0;
}
/*
int number = 10;
	scanf("%d", &number);

	printf("number ���� ��ġ : %p\n", &number);

	for (int i = 0; i < _SIZE; i++) {
		arr[i] = (i + 1) * 10;
	} // arr : [ 10, 20, 30, 40, 50, 60, 70, 80, 90,100]

	printf("arr : %p\n", arr);
	printf("&arr[0] : %p\n", &arr[0]);
	// ������ ���θ� �˻� X
	// ������ ��ġ������ ���� �д� �������  : ������  *
	printf("arr : %d\n", *arr);
	printf("&arr[0] : %d\n", *&arr[0]);

	printf("arr + 0 : %p\t &arr[0] : %p\n", arr+0,&arr[0]);
	printf("arr + 1 : %p\t &arr[1] : %p\n", arr+1,&arr[1]);
	printf("arr + 2 : %p\t &arr[2] : %p\n", arr+2,&arr[2]);
	printf("arr + 3 : %p\t &arr[3] : %p\n", arr+3,&arr[3]);
	printf("arr + 4 : %p\t &arr[4] : %p\n", arr+4,&arr[4]);
	printf("arr + 5 : %p\t &arr[5] : %p\n", arr+5,&arr[5]);


	printf("*(arr + 0) : %d\t arr[0] : %d\n", *(arr + 0), arr[0]);
	printf("*(arr + 1) : %d\t arr[1] : %d\n", *(arr + 1), arr[1]);
	printf("*(arr + 2) : %d\t arr[2] : %d\n", *(arr + 2), arr[2]);
	printf("*(arr + 3) : %d\t arr[3] : %d\n", *(arr + 3), arr[3]);
	printf("*(arr + 4) : %d\t arr[4] : %d\n", *(arr + 4), arr[4]);
	printf("*(arr + 5) : %d\t arr[5] : %d\n", *(arr + 5), arr[5]);
	// arr + i == &arr[i]
	// *arr + i == *&arr[i]
	int* ptr; // ���� ������ �޸� ��ġ�� ����
	int number2 = 0;
	ptr = &number;
	number2 = number;
	number2 = 20;
	printf("number : %d\n", number);
	printf("number : %d\n", *ptr);
	*ptr = 20;
	printf("number : %d\n", number);
	//  Call By Reference
	//	Call By Value


*/