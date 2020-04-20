#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SM_INIT 1
#define SM_INPUT 2
#define SM_SEARCH 3
/* 반복(Loop)제어 
 - 조건을 만족하면 블록을 재실행한다. : while 
        while : 최소 실행 횟수 : 0회 
        do while : 최소 실행 횟수 : 1회 

 - 기준 변수의 크기를 이용해 반복한다. : for(A ;  B ; C )
   A : 초기값 -> 기준 변수를 선언하거나 지역에있는 변수로 설정한다.
   B : 종료시점의 비교연산 
   C : 지정 변수의 증감 크기를 정한다.

   goto--> 코드의 특정 명칭의 라인으로 이동시킨다.

*/
int main() {
    int number = 0;
    int* ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
    // while 조건에 상수 참값을 작성하면 무한반복
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) {
            printf("%d  %d\n", i, j);

        }

    }
    for (int i = 0; i < 10; i += 2) {
    
    }


    do {
        printf("input number > ");
        scanf("%d", &number);
    } while (number < 0);


    while (number < 0) {
        printf("input number > ");
        scanf("%d", &number);

        if (number < 0)
            break;
    }// > : <=   , < : >=   == : !=   >= : <   <= : >
    while (number >= 0) {
        printf("input number > ");
        scanf("%d", &number);

    }

    printf("입력된 음수값 : %d\n", number);
    free(ptr);
	return 0;
}