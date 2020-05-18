#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	메모리 사용방식 
	  RAM : Random Access Memory -> 임의 접근하는 기억장소 
	  프로그램이 메모리에 올라가는 경우 (실행 될 때)
	  페이징 : 논리단위 
	  블록 :  양을 기준으로 

	  상수값 여러개를 묶어서 하나의 데이터로 사용

	  배열 -> 동일한 이름을 사용하는 여러 데이터 묶음
	  타입 , 변수, 갯수 --> 인덱스 크기 --> [const int]

	  // 10개의 인덱스를 갖는 배열에 랜덤값을 입력한다.
	  // 최소, 최대값을 입력받아서 
	  // 중복을 없애서.
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
	// 하나하나씩 따로 사용하는 경우 : 변수이름 + 각각의 위치번호
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

	printf("score : %p\n", score);// 배열의 이름만 사용하는 경우 : 배열의 시작 위치
	printf("score + 1 : %p\n", score + 1);// 메모리 주소 연산
	// & :  주소 참조  ↔  주소를 이용해서 값을 꺼낸다. : 간접참조 *
	printf("*score : %d\n" ,*score);
	printf("*score + 1 : %d\n", *score + 1); // 연산자 우선순위 
	printf("*(score + 1) : %d\n", *(score + 1)); // 연산자 우선순위 


	for(int i = 0;  i < 5; i++)
		printf("score[%d] : %p\n",i,  &score[i]); // 인덱스 번호는 변수를 사용할 수 있음
	// score + sizeof(int) * indexNumber
	*/


	/*
	int a, b, c, d, e;
	int total = 0;
	int score[5]; // 인덱스 크기

	for (int i = 0; i < 5; i++) {
		
	}
	printf("총점 : %d\n", total);
	
	*/

	return 0;
}