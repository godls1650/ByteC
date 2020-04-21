#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*비트연산자
  비트 논리연산자 (and : &      or :  |     not  : ~     xor :  ^)

  비트 시프트 연산자 

*/

int main() {
    int Code  = 0x50000001; // 0101 0000 00000000 00000000 00000001
    int GROUP_MASK = 0x70000000; // 0111 0000 00000000 00000000 00000000

    int Result = Code & GROUP_MASK;//// 0101 0000 00000000 00000000 00000000
    int member = Code & 0xff;
    printf("아무개씨 ID : %d\n", Code);
    switch (Result) {
    case 0x50000000 :
        printf("행정팀"); break;
    case 0x40000000:
        printf("인사팀"); break;
    case 0x30000000:
        printf("회계팀"); break;
    case 0x70000000:
        printf("운영팀"); break;
    }
    switch (member) {
    case 1: 
        printf("장\n"); break;
    
    case 2:
        printf("대리\n"); break;
    }

	return 0;
}