#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FALSE   0
#define TRUE    1
/*
��� ���� (Arithmetic Operator)
ũ�� �� ���� (Logic Operator)
 A > B    A < B
 A >= B   A <= B
 A == B   A != B
 ���� : 0 -> ���� (false)  not Zero -> �� (true)

 if ��� : ���� ����� ������� ���μ� ���
*/
int main(){
    /* �µ� : -6 --> ���� 6��  */
    /*        12 --> 12��      */
    const int FREEZ = 0;
    double dTemperature = 0.0;
    printf("������ �µ��� �Է��ϼ��� > ");
    scanf("%lf", &dTemperature);
    // �µ��� �������̶�� "����" , �µ��� ���밪 �� ����Ѵ�.
    // �µ��� �������� �ƴ϶�� ���� ������ �ǳ� �ٰ� ���

    //dTemperature *= -1;
    if (dTemperature < FREEZ) {
        dTemperature = -dTemperature;//A-(-B) --> A + B
        printf("���� ");
    }

    printf("%.2lf �� �Դϴ�.\n",dTemperature);

    printf("dTemprature (%.2lf)  < FREEZ(%d) --result--> %d\n", 
        -dTemperature, FREEZ, (-dTemperature) < FREEZ);

	return 0;
}