#include <stdio.h>
/*
���� �̸����� Ÿ���� �˷� �ִ� ���
int   ---> nDate
long
short

float
double

char
char [] --> string sName

*/
int main(void) {
	int nTotalDate = 0;
	int nYear = 0, nMonth = 0, nDate = 0;

	printf("��ĥ �Ǽ������ ? > ");
	scanf("%d", &nTotalDate);


	printf("%d���� ",nTotalDate);

	nYear = nTotalDate / 365;
	nTotalDate = nTotalDate % 365;
	
	nMonth = nTotalDate / 30;
	nTotalDate = nTotalDate % 30;
	nDate = nTotalDate;

	printf("%d�� %d���� %d��\n", nYear, nMonth, nDate);
	
}