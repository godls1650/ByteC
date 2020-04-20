#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
    논리 연산 
    AND
    OR
    NOT

	성인  : 1250     나이 >= 20
   중고딩 : 860      나이 >= 14
   초딩   : 750      나이 >= 8
   애     : 540      나이 > 0
   그외 : error
   if(){
   
   }

   else{
   
   }
*/

int main() {
    int age = 0;
    int pay = 0;
    printf("나이 > ");
    scanf("%d", &age);
    printf("삐빅 ");
    if (age >= 20 && age < 70) {
        printf("성인입니다.\n");
        pay = 1250;
    }
    else if (age >= 14) {
        printf("학생입니다.\n");
        pay = 860;
    }
    else if (age >= 8) {
       printf("어린이입니다.\n");
       pay = 540;
     }
    else if (age >= 0 || age >= 70) {
        printf("돈 받으시게요?\n");
        pay =0;
    }
    else {
        printf("input Error\n");
         return 0;
    }
     
    printf("요금 %d원이 지불되었습니다.\n", pay);

    if (age >= 20) {
        printf("성인입니다.\n");
        pay = 1250;
    }
    if (age < 20 && age >= 14) {
        printf("학생입니다.\n");
        pay = 860;
    }
    if (age >= 8 && age < 14) {
        printf("어린이입니다.\n");
        pay = 860;
    }





	return 0;
}