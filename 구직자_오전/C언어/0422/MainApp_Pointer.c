#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TRUE 1
#define VP(type, x)  *(type *)x


int main() {// 16348
	int number = TRUE;
	char text = 0;
	double dData = 0.0;
	//무슨 타입의 변수 위치인가.
	//(int *)
	int* pNumber = NULL;
	pNumber = &number;

	int number2 = 0;

	int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	
	
	printf("정수변수 메모리주소 : %p\n" ,& number);
	printf("실수변수 메모리주소 : %p\n", &dData);
	printf("문자변수 메모리주소 : %p\n", &text);

	printf("pNumber : %p\n", pNumber); // 위치 
	printf("&pNumber : %p\n", &pNumber);
	number = 100;
	*pNumber = 200;

	printf("number : %d\n", number);
	printf("*pNumber : %d\n", *pNumber);
	
	dData = 3.1415926535;
	/*
	pNumber = &dData;// 0000000000000000000011001000
	pNumber[0] = 100; // 00 00 00 64 00 00 00 C8
	//pNumber[1] = 200; 
	// 0 0000064 00000000 00000000 00000000 | 000000C8 00000000 00000000 00000000
	//printf("%d", *pNumber);
	//printf("%d", *(pNumber+1));
	*/

	pNumber = arr;
	printf("pNumber : %p\n", pNumber);
	printf("arr     : %p\n", arr);

	printf("pNumber +1: %p\n", pNumber + 1);
	printf("arr +1    : %p\n", arr + 1);

	printf("*(pNumber +1): %d\n", *(pNumber + 1));
	printf("*(arr +1)    : %d\n", *(arr + 1));

	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100 + 1;
	for (int i = 0; i < 10; i++)
		printf("%d ", pNumber[i]);

	void * temp =NULL;
	//#define PINT(x)  (int *)x
	temp = &number;
	printf("%d", VP(int, temp));

	temp = &text;
	printf("%c", VP(char, temp));

	temp = &dData;
	printf("%lf", VP(double,temp));
	

	int Blue = 10;
	int Green = 0;
	int Red = 30;

	int* pCup = NULL;
	pCup = &Green;
	*pCup = Red;
	pCup = &Red;
	*pCup = Blue;
	pCup = &Blue;
	*pCup = Green;


	return 0;
}