/*
scanf�� ������ �Է��Ѵ�.
�Էµ� ������ ���ڼ� (���� ����)��
�ܾ� �� �� ����ϴ� ���α׷��� �ۼ��ϼ��� 

winner winner chicken dinner!
                             ��
typo : 12
word : 4 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char text = 0;
    int typo = 0;
    int word = 0;
    printf("�� ������ �Է��ϼ��� > ");
    do {
        scanf("%c", &text);
        if (text == ' ' || text == '\n') {
            word++;
        }
        else {
            typo++;
        }
    } while (text != '\n');

    printf("���� �� : %d�� �ܾ� �� : %d\n", typo, word);

    return 0;
}

