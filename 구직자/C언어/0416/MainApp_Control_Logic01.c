#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* ��� 
*/

int main() {
    // ȭ�� ���� 
    int nMoney = 0;
    int nCount = 0;
    int nOne = 0;
    int totalCnt = 0;
    nOne = 50000;
    printf("�ٲ� �ݾ� > ");
    scanf("%d", &nMoney);

    int nCnt = 0;
    while (nOne >= 10) {
        nCount = nMoney / nOne;
        nMoney = nMoney % nOne;
        if (nCnt & 1)
            nOne /= 2;
        else
            nOne = nOne / 5;

        printf("%d", nCount);
        totalCnt = totalCnt + nCount;
        nCnt++;
    }



    return 0;
}