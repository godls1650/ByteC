#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 프로그램의 용량을 어떻게 줄일 것인가.
   프로그램의 내용을 어떻게 간소화 할것인가.
   어떻게 해야 좀 덜 귀찮을까.

   --> 알고리즘을 짜서 코드로 작성할 수 있는가


   함수의 반환값을 이용한다.
   함수가 할당 받는 메모리 영역의 특징
*/


/*
                                                             factorial(1)
                                                factorial(2)  ↑    ↓1
                                     factorial(3)  ↑    ↓2     
                         factorial(4)  ↑    ↓6      
            factorial(5)  ↑     ↓24    
    main()    ↑     ↓120  
*/

/*
    1부터 100사이의 값을 저장하는 배열에 존재하는 데이터 중
    가장 많이나온 데이터 하나만 출력하는 프로그램

*/

#define SIZE    1000
void setRandList(int* target, int size, int min, int max);
int SearchMostPick(int* target, int Size);



int main() {
    int arr[SIZE] = { 0 };
    setRandList(arr, SIZE, 1, 100);
    printf("가장 많이 나온 숫자 : %d\n", SearchMostPick(arr, SIZE));
    return 0;
}



void setRandList(int* target, int size, int min, int max) {
    int range = max - min + 1;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++){
        target[i] = rand() % range + min;
    }
    return;
}



int SearchMostPick(int* target, int Size) {
    int test[100] = { 0 };
    int index = 0;
    int most = 0;
    for (int i = 0; i < Size; i++) {
        index = target[i] - 1;
        test[index]++;
    }
    
    for (int i = 0; i < 100; i++) {
        printf("[%3d] : %3d회\n", i + 1, test[i]);
        if (test[most] <= test[i]) 
            most = i;
    }
    return most + 1;
}
