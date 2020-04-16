/*
Project : CProject_0414
File Name : MainApp_variable.c
cret Date : 2020-04-14
Director : A MU Gae
������ ����� . --> ������ �����Ѵ�.
  xxx ������ ���� ooo �� �����Ѵ�.
  */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* type �� ���Ĺ��� 
    int --> %d  %o  %x
    float => %f : ���� �Ҽ���  %e : �ε��Ҽ���   %a : 
    double -> %lf : ���� �Ҽ���  %le : �ε��Ҽ���   %la : 
    �Ҽ��� ����   %5.2f
*/

int main() {
    int nNumber = 0; // int type�� ��� �� 1���� �޸𸮿� �����Ѵ�.
    nNumber = 100;
    char a = 0, b = '\0';
    int f, m, l;

    scanf("%d%*c%d%*c%d", &f, &m, &l);
    printf("%03d-%04d-%04d\n", f, m, l);

    // ���ۿ��� ���� �� �� �״�� �Ҹ�  %*d
    printf("���� �Է� > ");
    scanf("%c", &a);
    printf("���� �Է� > ");
    scanf("%*c%c", &b);

    printf("a: %c b : %c\n", a, b);

    // 100      0144   0x64
    // ���� ǥ������ ���Ŀ� �߰�
    printf("nNumber : %#d\n", nNumber);// Decimal
    printf("nNumber : %#o\n", nNumber);// Octal
    printf("nNumber : %#x\n", nNumber);// heXa decmal
    
    // ��� �ɼ� ----1
    //          ---10
    nNumber = 10;
    printf("nNumber : %05d|\n", nNumber);
    // 1 ~ 5
    nNumber = 1234090;
    printf("nNumber : %05d|\n", nNumber);
    printf("������ : %-20s �ݾ� %d��\n", "C��� �ڵ�����", 32000);
    printf("������ : %-20s �ݾ� %d��\n", "�����͸� TCP/IP", 18000);
    printf("������ : %-20s �ݾ� %d��\n", "����", 18000);

    double pi = 3.1415926535;
    printf("������(��) : %-10.2lf\n", pi);

    /*����� �Է� - scanf()*/
    // scanf�� ù��° �Ű����� : Ű������ �Է°��� � ������ ������ ������ ���ΰ��� ���� ����
    //"480"--> "%d"
    scanf("%d", &nNumber);
    printf("�Է� �� nNumber : %d\n", nNumber);

    // �ּҰ� ��� , ����� �Է� , %p
    return 0;
}

/*
nNumber : 10
nNumber : 12340
*/