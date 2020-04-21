#include <stdio.h>
/*
변수 이름으로 타입을 알려 주는 방법
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

	printf("며칠 되셨을까요 ? > ");
	scanf("%d", &nTotalDate);


	printf("%d일은 ",nTotalDate);

	nYear = nTotalDate / 365;
	nTotalDate = nTotalDate % 365;
	
	nMonth = nTotalDate / 30;
	nTotalDate = nTotalDate % 30;
	nDate = nTotalDate;

	printf("%d년 %d개월 %d일\n", nYear, nMonth, nDate);
	
}