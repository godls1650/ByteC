#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/* 
    ���� : -1
    ���� : 0
    ��   : 1

    ����   ����   -> -1
    ����   ���ڱ� ->  1
    ���ڱ� ����    -> 0


Bit Operator -> Shift  : <<    >>
  * C++ cout << "hello world" <<endl;
    *shift�� '�о��'�� ����� ������ ����� ��� : ������ �����ε�

    ��� << ��Ʈ�� 
    100 <<  3
     * ������ ������ shift�� ������ ������ shift�� ����ִ� �ڸ��� 0�� �Է��Ѵ�.
     
     ((+5)+(+5)) * (-2) : ���� ǥ���� 
     *+5,5,2 : ���� ǥ����    : multiplex(5+5,2) (�Լ� ǥ����)
     5,5+ 2 * : ���� ǥ����   
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
    /* ���� ���� �� */
    int user = 0;
    int com = 0;
    srand((unsigned)time(NULL));
    printf("1. ���� , 2. ���� 3.���ڱ� \n select > ");
    scanf("%d", &user);
 
    com = rand() % 3+1; // -1  0  1
    printf("user : ");
    if (user == 1) printf("����");
    else if (user == 2) printf("����");
    else printf("���ڱ�");

    printf("vs com : ");
    if (com == 1) printf("����\n");
    else if (com == 2) printf("����\n");
    else printf("���ڱ�\n");


    switch (user) {
    case 1:// ����
        if (com == 1)       printf("���º�\n");
        else if (com == 2)  printf("�й�\n");
        else                printf("��\n");
        break;
    case 2:// ����
        if (com == 1)        printf("��\n");
        else if (com == 2)  printf("���º�\n"); 
        else                printf("�й�\n");
        break;
    case 3: // ���ڱ�
        if (com == 1)       printf("�й�\n"); 
        else if (com == 2)  printf("��\n");
        else                printf("���º�\n"); 
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