#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*��Ʈ������
  ��Ʈ �������� (and : &      or :  |     not  : ~     xor :  ^)

  ��Ʈ ����Ʈ ������ 

*/

int main() {
    int Code  = 0x50000001; // 0101 0000 00000000 00000000 00000001
    int GROUP_MASK = 0x70000000; // 0111 0000 00000000 00000000 00000000

    int Result = Code & GROUP_MASK;//// 0101 0000 00000000 00000000 00000000
    int member = Code & 0xff;
    printf("�ƹ����� ID : %d\n", Code);
    switch (Result) {
    case 0x50000000 :
        printf("������"); break;
    case 0x40000000:
        printf("�λ���"); break;
    case 0x30000000:
        printf("ȸ����"); break;
    case 0x70000000:
        printf("���"); break;
    }
    switch (member) {
    case 1: 
        printf("��\n"); break;
    
    case 2:
        printf("�븮\n"); break;
    }

	return 0;
}