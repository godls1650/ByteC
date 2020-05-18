#include <stdio.h>
/*
# : 전처리기 --> 기계어로 바꾸기 전에 동작 시킨다.
include 포함하다.
<> : 현재 폴더 외부 
STanDard Input Output .Header

프로그램의 변수 , 함수 등은 
  선언 -> 정의 -> 사용(호출)
  // 프로그램의 실행 순서 
    메모리 할당이 끝나면
     -> main()를 찾는다. 
*/
// 전역 영역 

// 변수 , 상수
// default type : 기본데이터 타입 

int main() { // {} -> 함수  블록
    // 지역 영역
    // 정수형태로 전기요금을 저장하는 변수를 만든다.
    int ElectricPay = 0; // %d %o %x   %u %ul  %ull
    float fData = 0.0f; // %f  %e  %a
    double dData = 0.0; // %lf  %le  %la
    printf("전기 요금은 %d원 입니다.\n", ElectricPay);

    ElectricPay = 12300; // 사용
    printf("전기 요금은 %d원 입니다.\n", ElectricPay);
   
    fData = 3.141592f;
    dData = 3.141592;
    printf("float : %f\n%e\n%a\n", fData, fData, fData);
    printf("double : %lf\n%le\n%la\n", dData, dData, dData);
    


	printf("hello world\n");// print _ formatting
    puts("hello world");

	return 0;
}