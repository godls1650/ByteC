/* 
Date        : 2020-04-01 _1st_
ProjectName : CProject_200410
File Name   : MainApp_Floating.c

memo :       Float type / Double type    
*/
#include <stdio.h>
/* Float 

  n = n + 1
  n += 1
  n++
  Python
*/
int main(void) {
	int nNumber = 0;    // int 정수형 변수 
	float fData = 0.0f; // float형 변수
	double dData = 0.0; // double형 변수
	short snNumber = 0; // short 타입 정수
	long lnNumber = 0L; // long 타입 정수 
	
	//변수, 데이터타입의 크기를 확인 : sizeof( 변수이름, 타입 )연산
	printf("nNumber 의 크기 : %d byte\n",sizeof(nNumber)); // sizeof연산의 결과가 나온다.
	printf("fData 의 크기 : %d byte\n", sizeof(fData));
	printf("dData 의 크기 : %d byte\n", sizeof(dData));
	printf("snNumber 의 크기 : %d byte\n", sizeof(snNumber));
	printf("lnNumber 의 크기 : %d byte\n", sizeof(lnNumber));

	fData = 0.00123456789f;
	dData = 0.00123456789;
	// 소수값을 출력 할 때 서식 : %f  %e   %lf  %le  %a %la
	printf("fData = %f\n", fData);
	printf("dData = %lf\n", dData);
	printf("fData = %e\n", fData);
	printf("dData = %le\n", dData);

	double result = 0.0;
	nNumber = 4;
	dData = 3.141592;
	// 형변환 연산    바꾸고자 하는 변수 X
	//    (double)X
	result = ((double)nNumber * (double)nNumber) * dData;
	printf("반지름이 %d 인 원의 넓이 : %lf\n", nNumber, result);

	int number2 = 0;
	for (int i = 1; i <= 5; i++)
		number2 = number2 * i;
	

	
	return 0;
}
