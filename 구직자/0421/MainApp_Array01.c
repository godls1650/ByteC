#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* �迭 : ������ �޸𸮻����� ���� ��Ų �ڷᱸ��
   �ε��� ũ�� : ������Ų �������� ����
   �ε��� ��ȣ : ������Ų ������ ���� ��ȣ�� �ο��ϰ� ������ ��� �����ϴ�.
                - �ε��� ũ��� ����� ��밡���ϴ� 
                 (C11)���ʹ� ������ �Ҵ� ���� ������ Visual C/C++(C99))
                - �ε��� ��ȣ�� ������ ó���� �� �ִ�.
        �迭�� �������� �Է� ( �ߺ����� ���� ���� )
*/

#define _MAXSIZE 10

int main() {
    int n = 10;
    int arr[_MAXSIZE];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < _MAXSIZE; i++) {
        arr[i] = rand() % 10 + 1;
        // ���� �ε��� �� �� ���� �����Ͱ� �ִٸ� i���� ���ҽ��Ѽ� ���Է�
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