/*
Project Name : CProject_0413
File Name : MainApp_ArithmeticOp.c
Date : 2020-04-13
memo : Arithmetic Operator

������ 
 1. �ǿ������� ������ ���� 
   �ǿ����� 1�� : ���׿����� : sizeof() , casting
     �޸� ��ġ ��ȸ ������ : �ּ� ���� ������ (&)--> ����� �Է��Լ� 

   �ǿ����� (��)  2�� : ���׿�����
    ��������� : + - * % /  
    ���մ��Կ��� += -= *= /= %=
    ��������  : ++v  v++   --v  v--
      -> ������ �����ϰ� �ִ� ���� �̿��� ���


   �ǿ����� 3�� : ���׿�����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
    �ݾ��� �Է��ϰ�
    �ݾ� > 123450

    5���� : 2  1���� 2
    5õ�� : 0  õ�� : 3
    ����� : 0  ��� : 4
    50�� : 1   �ʿ� : 0
*/
int main(void) {
    int score = 0;
    int total = 0;
    double average = 0.0;
    int cnt = 0;

    int floor = 1;
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", floor++);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("%d\n", --floor);
    printf("cnt : %d\n", cnt--); // ���������ڴ� 
    printf("cnt : %d\n", --cnt); // ���� --  : ���� ��� �� ���� ���� 
    printf("cnt : %d\n", cnt--);// -- ���� 
    printf("cnt : %d\n", --cnt);
    printf("cnt : %d\n", cnt);

    printf("���� > ");
    scanf("%d", &score);
    total = total + score;

    printf("���� > ");
    scanf("%d", &score);
    total += score; // ���մ��� ������ : ��������ڿ� ������ ����� ���ļ� ���
                    //                  ��Ʈ����

 

    printf("���� > ");
    scanf("%d", &score);
    total = total + score;

    printf("���� : %d\n", total);
   
	return 0;
}

/*
int nNumber = 0;
    nNumber = 123; // = : ���� ������ ���� �׿� ������ ���� ���� �Է�
    float avgScore = 0.0f;
    //���� ��ȯ : casting --> ����ȯ �������� ��� -> �ٷε��� ����
    char sID[128] = { 0 };
    printf(" �Է��ϼ��� > ");
    scanf("%d", &nNumber);

    printf("nNumber : %d\n", nNumber);
    printf("nNumber : %p\n",  &nNumber);// �ּҿ����� : %p (Pointer)
    // 32bit --> 4Byte : win32

    avgScore = (float)nNumber / 4;
*/