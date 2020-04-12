#include <stdio.h>
/*
	경보음을 한번 울리고 다음과 같은 텍스트를 화면에 출력하는 프로그램을 작성하세요
	갑작스런 소리에 깜짝 놀라 샐리는 외쳤다, 
	"호박대왕이다!"
	나머지 연산자 : %
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


	printf("\a갑작스런 소리에 깜짝 놀라 샐리는 외쳤다,\n\"호박대왕이다!\"\n");
	
	int totalSecond = 0;
	totalSecond = 8000; // 654320 초 
	printf("%d초는 ", totalSecond);
	// 1분 : 60초   1시간 : 60 * 60 3600
	int hour, minute, second;
	hour = totalSecond / 3600;
	// 8000 / 3600 = 2 
	// totalSecond = totalSecond - hour * 3600
	totalSecond = totalSecond % 3600;
	minute = totalSecond / 60;
	second = totalSecond % 60;
	second = totalSecond % 60;


	printf("%d시간 %d분 %d초입니다.\n", hour,minute, second);

//	 총 사귄 날짜를 입력하면  : 1000 
// 몇년 몇개월 며칠인지 출력


	return 0;
}