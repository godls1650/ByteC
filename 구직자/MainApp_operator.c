#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.141592
/* 형변환 (casting) 연산
   크기조회 연산 ---> sizeof(_변수or타입이름_ )

   복합대입연산 : 산술연산 + 대입  |  비트연산 + 대입 
   011011100   ~ --> 100100011
   


   A >= B  A <= B  A == B  A != B

   A >= B  A <= B  A == B  A != B
   (bool)논리연산자 : 참거짓 연산
   ( bit)논리연산자 : 각 비트 자리 

   AND    : 둘 다 참일 때 연산결과가 참값 키가 150 이상이고 나이가 8세 이상
   OR	  : 둘 중 하나가 참이면 참값
   NOT	  : 결과 반전
   (bit) XOR : 서로 다르면 1   (A or B) - (A and B)

   logic  && : and   || : or    ! : not
   bit     & : and    | : or    ~ : not   xor : ^ 

	밤 10시가 지나서  택시요금에 할증이 붙는다면.
	
 */
#define AM 0
#define PM 1

int main() {
	int timer = 0;
	timer = PM;
	double inc = 0.0;
	int pay = 3300;

	if (timer == PM) inc = 0.25; 
	else inc = 0.0;
	// 삼항연산자    A ? B : C  --> A가 참이면 B가 결과 거짓이면 C가 결과
	inc =  timer == PM ?  0.25 : 0.0;

	
	int result = (int)((double)pay*(1.0 +  inc));
	printf("%d\n", result);
	
	int number = 0;
	float fData = 0.0f;
	double dData = pi;
	char text = 0;
	short sNumber = 0;
	long lNumber = 0l;
	long long llnumber = 0ll;


	printf("byte : %d",sizeof(number));
	printf("byte : %d",sizeof(sNumber));
	printf("byte : %d",sizeof(lNumber));
	printf("byte : %d",sizeof(llnumber));
	printf("byte : %d",sizeof(fData));
	printf("byte : %d",sizeof(dData));
	printf("byte : %d",sizeof(char));
	// 자동 형변환
	number = 100;
	sNumber = number; // 형변환 작성 필요 X
	text = number;
	
	dData = pow(2.0, 10.0);
	number = (int)pow(2.0, 10.0);


	printf("number : %d\n", number);  // 01100100
	printf("~number : %d\n", ~number);// 10011011
	printf("~number + 1 : %d\n", ~number + 1);// 10011100
	//						  ???? ???1
	// 홀수 짝수 //            0000 0001   
	number % 2 == 1; // 나눗셈 나머지연산 + 비교연산
	number & 1; //  and연산

	
	// 강제 형변환
	lNumber = (long)number;

	int total = 0;
	int score = 0;

	printf("국어 > ");
	scanf("%d", &score);
	total = total + score;
	
	printf("영어 > ");
	scanf("%d", &score);
	total += score;
	
	printf("수학 > ");
	scanf("%d", &score);
	total = total + score;

	printf("탐구 > ");
	scanf("%d", &score);
	total = total + score;

	double average = 0.0;
	average = (double)total / 4; // 323.0 / 4

	printf("총점 : %d\t 평균 : %lf/\n", total, average);

	// casting , sizeof, &(주소참조 연산)
	// = , + - * / %
	

	return 0;
}