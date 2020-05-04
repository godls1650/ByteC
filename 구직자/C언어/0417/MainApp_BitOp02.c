#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/* 
    가위 : -1
    바위 : 0
    보   : 1

    가위   바위   -> -1
    바위   보자기 ->  1
    보자기 가위    -> 0


Bit Operator -> Shift  : <<    >>
  * C++ cout << "hello world" <<endl;
    *shift의 '밀어낸다'의 기능을 수정한 방식의 출력 : 연산자 오버로딩

    대상 << 비트수 
    100 <<  3
     * 음수의 오른쪽 shift를 제외한 나머지 shift는 비어있는 자리에 0을 입력한다.
     
     ((+5)+(+5)) * (-2) : 중위 표현식 
     *+5,5,2 : 전위 표현식    : multiplex(5+5,2) (함수 표현식)
     5,5+ 2 * : 후위 표현식   
     R1 INPUT 5
     R2 INPUT 5
     R3 SUM R1 R2
     R4 INPUT 2
     R5 MUL R3 R4

    1980   1    1   00 : 00 : 00 
     1587084569
     1587084593
*/
int main() {
    /* 가위 바위 보 */
    int user = 0;
    int com = 0;
    srand((unsigned)time(NULL));
    printf("1. 가위 , 2. 바위 3.보자기 \n select > ");
    scanf("%d", &user);
 
    com = rand() % 3+1; // -1  0  1
    printf("user : ");
    if (user == 1) printf("가위");
    else if (user == 2) printf("바위");
    else printf("보자기");

    printf("vs com : ");
    if (com == 1) printf("가위\n");
    else if (com == 2) printf("바위\n");
    else printf("보자기\n");


    switch (user) {
    case 1:// 가위
        if (com == 1)       printf("무승부\n");
        else if (com == 2)  printf("패배\n");
        else                printf("승\n");
        break;
    case 2:// 바위
        if (com == 1)        printf("승\n");
        else if (com == 2)  printf("무승부\n"); 
        else                printf("패배\n");
        break;
    case 3: // 보자기
        if (com == 1)       printf("패배\n"); 
        else if (com == 2)  printf("승\n");
        else                printf("무승부\n"); 
        break;
    default :
        printf("user input error\n");
    }


    int temp = 0;
    temp = user - com;
    printf("data : %d\n", temp);
    printf("%d\n", (-5) % 2);

	return 0;
}