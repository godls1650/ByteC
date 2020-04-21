#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FALSE   0
#define TRUE    1
/*
산술 연산 (Arithmetic Operator)
크기 비교 연산 (Logic Operator)
 A > B    A < B
 A >= B   A <= B
 A == B   A != B
 논리값 : 0 -> 거짓 (false)  not Zero -> 참 (true)

 if 제어문 : 제어 대상을 블록으로 감싸서 사용
*/
int main(){
    /* 온도 : -6 --> 영하 6도  */
    /*        12 --> 12도      */
    const int FREEZ = 0;
    double dTemperature = 0.0;
    printf("측정한 온도를 입력하세요 > ");
    scanf("%lf", &dTemperature);
    // 온도가 음수값이라면 "영하" , 온도의 절대값 을 출력한다.
    // 온도가 음수값이 아니라면 위의 내용을 건너 뛰고 출력

    //dTemperature *= -1;
    if (dTemperature < FREEZ) {
        dTemperature = -dTemperature;//A-(-B) --> A + B
        printf("영하 ");
    }

    printf("%.2lf ℃ 입니다.\n",dTemperature);

    printf("dTemprature (%.2lf)  < FREEZ(%d) --result--> %d\n", 
        -dTemperature, FREEZ, (-dTemperature) < FREEZ);

	return 0;
}