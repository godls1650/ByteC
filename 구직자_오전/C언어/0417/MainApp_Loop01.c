#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SM_INIT 1
#define SM_INPUT 2
#define SM_SEARCH 3
/* �ݺ�(Loop)���� 
 - ������ �����ϸ� ����� ������Ѵ�. : while 
        while : �ּ� ���� Ƚ�� : 0ȸ 
        do while : �ּ� ���� Ƚ�� : 1ȸ 

 - ���� ������ ũ�⸦ �̿��� �ݺ��Ѵ�. : for(A ;  B ; C )
   A : �ʱⰪ -> ���� ������ �����ϰų� �������ִ� ������ �����Ѵ�.
   B : ��������� �񱳿��� 
   C : ���� ������ ���� ũ�⸦ ���Ѵ�.

   goto--> �ڵ��� Ư�� ��Ī�� �������� �̵���Ų��.

*/
int main() {
    int number = 0;
    int* ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
    // while ���ǿ� ��� ������ �ۼ��ϸ� ���ѹݺ�
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

    printf("�Էµ� ������ : %d\n", number);
    free(ptr);
	return 0;
}