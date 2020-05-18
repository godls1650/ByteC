#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	배열의 초기화
	배열의 원소 사용, 반복사용
	배열로 정수값을 2진수로 변환하여 출력
*/
#define _MAXSIZE	10
#define _STRMAX	0xFF
#define BYTESIZE	9
int main() {
	char binary[BYTESIZE] = {0};
	int number = 0;
	int bOne = 0;
	// 정수 값을 입력 받는다(0 ~ 255)
	
	
	printf("input number (range : 1 to 255) > ");
	scanf("%d", &number);

	printf("%3d --> 0b", number);
	for (int i = 0; i < BYTESIZE - 1; i++) {
		bOne = number % 2;
		number /= 2;
		binary[BYTESIZE - (i + 2)] = (bOne) ? '1' : '0';
	}

	//2진수 출력 부분
	for (int i = 0; i < BYTESIZE - 1; i++) {
		printf("%c", binary[i]);
	}
	printf("\n");
	printf("0b%8s\n", binary);

	return 0;
}

/*
int arr1[_MAXSIZE] = { 0 };
	int arr2[_MAXSIZE] = { 10,20,30,40,50,60,70,80,90,100 };
	char text1[_MAXSIZE] = { 0 };
	char text2[_MAXSIZE] = { '\0' };
	char text3[_MAXSIZE] = "";
	char text4[_MAXSIZE] = "apple"; //{'a', 'p','p','l','e','\0','\0','\0','\0','\0' };
	char text5[_STRMAX] = "hello world";// a pp l e 0 w o r l d 0

	printf("apple");
	arr1[0] = 100;
	for (int i = 0; i < _MAXSIZE; i++)
		printf("%3d ", arr2[i]);


*/