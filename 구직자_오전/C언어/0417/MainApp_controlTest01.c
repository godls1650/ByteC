/*
scanf로 문장을 입력한다.
입력된 문장의 글자수 (공백 제외)와
단어 수 를 출력하는 프로그램을 작성하세요 

winner winner chicken dinner!
                             ↑
typo : 12
word : 4 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char text = 0;
    int typo = 0;
    int word = 0;
    printf("한 문장을 입력하세요 > ");
    do {
        scanf("%c", &text);
        if (text == ' ' || text == '\n') {
            word++;
        }
        else {
            typo++;
        }
    } while (text != '\n');

    printf("글자 수 : %d개 단어 수 : %d\n", typo, word);

    return 0;
}

