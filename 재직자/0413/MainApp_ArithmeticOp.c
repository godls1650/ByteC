/*
Project Name : CProject_0413
File Name : MainApp_ArithmeticOp.c
Date : 2020-04-13
memo : Arithmetic Operator

연산자 
 1. 피연산자의 갯수에 따라서 
   피연산자 1개 : 단항연산자 : sizeof() , casting
     메모리 위치 조회 연산자 : 주소 참조 연산자 (&)--> 사용자 입력함수 

   피연산자 (항)  2개 : 이항연산자
    산술연산자 : + - * % /  
    복합대입연산 += -= *= /= %=
    증감연산  : ++v  v++   --v  v--
      -> 변수가 저장하고 있는 값을 이용한 계산


   피연산자 3개 : 삼항연산자
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
    금액을 입력하고
    금액 > 123450

    5만원 : 2  1만원 2
    5천원 : 0  천원 : 3
    오백원 : 0  백원 : 4
    50원 : 1   십원 : 0
*/
int main(void) {
    int score = 0;
    int total = 0;
    double average = 0.0;
    int cnt = 0;

    int floor = 1;
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("cnt : %d\n", cnt--); // 증감연산자는 
    printf("cnt : %d\n", --cnt); // 변수 --  : 변수 사용 후 값을 증가 
    printf("cnt : %d\n", cnt--);// -- 변수 
    printf("cnt : %d\n", --cnt);
    printf("cnt : %d\n", cnt);

    printf("국어 > ");
    scanf("%d", &score);
    total = total + score;

    printf("수학 > ");
    scanf("%d", &score);
    total += score; // 복합대입 연산자 : 산술연산자와 대입의 기능을 합쳐서 사용
                    //                  비트연산

 

    printf("영어 > ");
    scanf("%d", &score);
    total = total + score;

    printf("총점 : %d\n", total);
   
	return 0;
}

/*
int nNumber = 0;
    nNumber = 123; // = : 대입 연산자 왼쪽 항에 오른쪽 항의 값을 입력
    float avgScore = 0.0f;
    //형태 변환 : casting --> 형변환 연산자의 대상 -> 바로뒤의 변수
    char sID[128] = { 0 };
    printf(" 입력하세요 > ");
    scanf("%d", &nNumber);

    printf("nNumber : %d\n", nNumber);
    printf("nNumber : %p\n",  &nNumber);// 주소연산결과 : %p (Pointer)
    // 32bit --> 4Byte : win32

    avgScore = (float)nNumber / 4;
*/