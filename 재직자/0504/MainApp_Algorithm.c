#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* ���α׷��� �뷮�� ��� ���� ���ΰ�.
   ���α׷��� ������ ��� ����ȭ �Ұ��ΰ�.
   ��� �ؾ� �� �� ��������.

   --> �˰����� ¥�� �ڵ�� �ۼ��� �� �ִ°�


   �Լ��� ��ȯ���� �̿��Ѵ�.
   �Լ��� �Ҵ� �޴� �޸� ������ Ư¡
*/


/*
                                                             factorial(1)
                                                factorial(2)  ��    ��1
                                     factorial(3)  ��    ��2     
                         factorial(4)  ��    ��6      
            factorial(5)  ��     ��24    
    main()    ��     ��120  
*/

/*
    1���� 100������ ���� �����ϴ� �迭�� �����ϴ� ������ ��
    ���� ���̳��� ������ �ϳ��� ����ϴ� ���α׷�

*/

#define SIZE    1000
void setRandList(int* target, int size, int min, int max);
int SearchMostPick(int* target, int Size);



int main() {
    int arr[SIZE] = { 0 };
    setRandList(arr, SIZE, 1, 100);
    printf("���� ���� ���� ���� : %d\n", SearchMostPick(arr, SIZE));
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
        printf("[%3d] : %3dȸ\n", i + 1, test[i]);
        if (test[most] <= test[i]) 
            most = i;
    }
    return most + 1;
}
