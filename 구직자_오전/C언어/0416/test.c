#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
switch - case 

*/

int main() {
	/*COVID-19 Check*/
	double temperature = 0.0;
	char YorN = 0;
	printf("���� ü���� �Է��ϼ��� > ");
	scanf("%lf", &temperature);
	printf("��ħ �� ȣ��� ��ȯ�� �ֽ��ϱ�. (Y/N) > ");
	scanf("%*c%c", &YorN);
	switch (YorN) {
	case 'Y': case 'y':

		break;
	case 'N': case 'n':

		break;
	}


	if ((YorN == 'Y' || YorN == 'y') || temperature >= 37.0) {
		printf("Hoxy??? \n");
	}
	else {
		printf("you're Not COVID-19\n");
	}



	return 0;
}