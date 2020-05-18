#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 배열 : 변수를 메모리상으로 나열 시킨 자료구조
   인덱스 크기 : 나열시킨 데이터의 갯수
   인덱스 번호 : 나열시킨 순서에 따라서 번호를 부여하고 개별로 사용 가능하다.
                - 인덱스 크기는 상수만 사용가능하다 
                 (C11)부터는 변수로 할당 가능 하지만 Visual C/C++(C99))
                - 인덱스 번호는 변수로 처리할 수 있다.
        배열에 랜덤값을 입력 ( 중복값이 없는 상태 )
*/

#define _MAXSIZE 10

int main() {
    int n = 10;
    int arr[_MAXSIZE];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < _MAXSIZE; i++) {
        arr[i] = rand() % 10 + 1;
        // 이전 인덱스 들 중 같은 데이터가 있다면 i값을 감소시켜서 재입력
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i+1; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
            if (arr[i] == arr[j]) {
                i--;
                break;
            }
            //else continue;
        }
    }

    for (int i = 0; i < _MAXSIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	return 0;
}