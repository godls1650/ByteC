#include <stdio.h>
/*
	�溸���� �ѹ� �︮�� ������ ���� �ؽ�Ʈ�� ȭ�鿡 ����ϴ� ���α׷��� �ۼ��ϼ���
	���۽��� �Ҹ��� ��¦ ��� ������ ���ƴ�, 
	"ȣ�ڴ���̴�!"
	������ ������ : %
*/
int main(void) {
	int number1 = 0;
	int number2 = 0;
	int number3 = 0, number4 = 0;
	double f = 0;

	number1 = 10;
	number2 = 3;
	number3 = number1 / 3;
	f = (double)number1 / 3;
	printf("%d / %d = %d\n", number1, number2, number3);
	printf("%d / %d = %lf\n", number1, number2, f);
	number4 = number1 % number2;
	printf("%d %% %d = %d\n", number1, number2, number4);


	printf("\a���۽��� �Ҹ��� ��¦ ��� ������ ���ƴ�,\n\"ȣ�ڴ���̴�!\"\n");
	
	int totalSecond = 0;
	totalSecond = 8000; // 654320 �� 
	printf("%d�ʴ� ", totalSecond);
	// 1�� : 60��   1�ð� : 60 * 60 3600
	int hour, minute, second;
	hour = totalSecond / 3600;
	// 8000 / 3600 = 2 
	// totalSecond = totalSecond - hour * 3600
	totalSecond = totalSecond % 3600;
	minute = totalSecond / 60;
	second = totalSecond % 60;
	second = totalSecond % 60;


	printf("%d�ð� %d�� %d���Դϴ�.\n", hour,minute, second);

//	 �� ��� ��¥�� �Է��ϸ�  : 1000 
// ��� ��� ��ĥ���� ���


	return 0;
}