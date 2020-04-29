#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	배열 : 데이터를 물리적으로 나열하여 사용하는 하나의 자료구조 
	   - 동일한 타입의 데이터 여러개를 나열한다.
	배열이 사용되는 경우 
	  1. 여러 데이터를 나열해서 하나로 표현한다. 'D' 'O' 'G' -> dog 문자열
	  2. 용도가 같은 변수 여럿을 나열
	     국어 영어 수학 사회 과학 

	배열을 선언 
	   타입 배열이름[크기상수]  ;
	   크기 상수  : 인덱스 크기( 총 몇개의 데이터를 나열 하는 배열인가)
	

*/
#define SIZE	10
int main() {
	int x = 1000, y = 2000, z = 3000;
	int number[3] ; //main함수가 실행하면서 동시에 메모리를 할당해야 하기 때문에 
				  // 인덱스 크기에는 변수가 들어올 수 없다. :: 리터럴, 심볼릭 상수 의 정수값만 

	printf("number : %p\n", number); // 배열의 메모리 시작 주소

	number[0] = 100; // 인덱스 번호 : 배열이름부터 메모리 크기상 얼마나 떨어져 있는가
	number[1] = 200; // 인덱스 번호 범위 : 0 ~ (인덱스크기-1)
	number[2] = 300; // 인덱스 번호관리 : 컴파일러  X   사용자 O
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
	// %p  (Pointer : 메모리 주소값 (16진수) 를 출력한다.
	printf("x변수의 메모리 위치 : %p\n", &x);
	printf("y변수의 메모리 위치 : %p\n", &y);
	printf("z변수의 메모리 위치 : %p\n", &z);

	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);


	return 0;
}
