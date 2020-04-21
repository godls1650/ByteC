#include <stdio.h>
#define PI 3.141592
/*
CProject_200408.exe
  ---> MainApp01.c -->main()
  ---> MainApp02.c -->main()

  변수의 선언 , 초기화 , 사용 , 특징
  godls1650@gmail.com

*/
int main(void) {
    // 상수 10 , 'a' , 3.141592 : 글자 그대로 하나의 값 : 리터럴 상수 
    //pi --> 심볼릭 상수 
    // 심볼릭 상수를 만드는 방법 1. 변수를 상수화 시킨다. const 타입명 
    const float pi = 3.141592f;
    int nData = 0; // 변수를 선언한다 . main()함수의 지역변수 

    float r = 4.0f;
    float result = 0.0f;
    
    result = r * r * PI;


    printf("%d 점 만점 입니다.\n", nData);
    nData = 100; // 정수 상수 중 하나의 값을 메모리에 저장 시킨다.
    printf("%d 점 만점 입니다.\n", nData);
    nData = 200; // 기존 100을 메모리에서 삭제 후 200이 저장된다.


	return 0;
}