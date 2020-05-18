/*
Project : CProject_0414
File Name : MainApp_variable.c
cret Date : 2020-04-14
Director : A MU Gae
변수를 만든다 . --> 변수를 선언한다.
  xxx 형태의 변수 ooo 를 선언한다.
  */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* type 별 서식문자 
    int --> %d  %o  %x
    float => %f : 고정 소수점  %e : 부동소수점   %a : 
    double -> %lf : 고정 소수점  %le : 부동소수점   %la : 
    소수점 지정   %5.2f
*/

int main() {
    int nNumber = 0; // int type의 상수 중 1개를 메모리에 저장한다.
    nNumber = 100;
    char a = 0, b = '\0';
    int f, m, l;

    scanf("%d%*c%d%*c%d", &f, &m, &l);
    printf("%03d-%04d-%04d\n", f, m, l);

    // 버퍼에서 값을 뺀 뒤 그대로 소멸  %*d
    printf("문자 입력 > ");
    scanf("%c", &a);
    printf("문자 입력 > ");
    scanf("%*c%c", &b);

    printf("a: %c b : %c\n", a, b);

    // 100      0144   0x64
    // 진수 표현식을 서식에 추가
    printf("nNumber : %#d\n", nNumber);// Decimal
    printf("nNumber : %#o\n", nNumber);// Octal
    printf("nNumber : %#x\n", nNumber);// heXa decmal
    
    // 출력 옵션 ----1
    //          ---10
    nNumber = 10;
    printf("nNumber : %05d|\n", nNumber);
    // 1 ~ 5
    nNumber = 1234090;
    printf("nNumber : %05d|\n", nNumber);
    printf("도서명 : %-20s 금액 %d원\n", "C언어 코딩도장", 32000);
    printf("도서명 : %-20s 금액 %d원\n", "마스터링 TCP/IP", 18000);
    printf("도서명 : %-20s 금액 %d원\n", "토지", 18000);

    double pi = 3.1415926535;
    printf("원주율(π) : %-10.2lf\n", pi);

    /*사용자 입력 - scanf()*/
    // scanf의 첫번째 매개변수 : 키보드의 입력값을 어떤 형태의 값으로 변경할 것인가에 대한 서식
    //"480"--> "%d"
    scanf("%d", &nNumber);
    printf("입력 후 nNumber : %d\n", nNumber);

    // 주소값 사용 , 사용자 입력 , %p
    return 0;
}

/*
nNumber : 10
nNumber : 12340
*/