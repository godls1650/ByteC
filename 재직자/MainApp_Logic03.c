#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
    �� ���� 
    AND
    OR
    NOT

	����  : 1250     ���� >= 20
   �߰�� : 860      ���� >= 14
   �ʵ�   : 750      ���� >= 8
   ��     : 540      ���� > 0
   �׿� : error
   if(){
   
   }

   else{
   
   }
*/

int main() {
    int age = 0;
    int pay = 0;
    printf("���� > ");
    scanf("%d", &age);
    printf("�ߺ� ");
    if (age >= 20 && age < 70) {
        printf("�����Դϴ�.\n");
        pay = 1250;
    }
    else if (age >= 14) {
        printf("�л��Դϴ�.\n");
        pay = 860;
    }
    else if (age >= 8) {
       printf("����Դϴ�.\n");
       pay = 540;
     }
    else if (age >= 0 || age >= 70) {
        printf("�� �����ðԿ�?\n");
        pay =0;
    }
    else {
        printf("input Error\n");
         return 0;
    }
     
    printf("��� %d���� ���ҵǾ����ϴ�.\n", pay);

    if (age >= 20) {
        printf("�����Դϴ�.\n");
        pay = 1250;
    }
    if (age < 20 && age >= 14) {
        printf("�л��Դϴ�.\n");
        pay = 860;
    }
    if (age >= 8 && age < 14) {
        printf("����Դϴ�.\n");
        pay = 860;
    }





	return 0;
}