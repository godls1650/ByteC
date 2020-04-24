#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 동작이후 변경해야하는 값 : 원래 자료형 + 포인터

// 동작이후 변경이 불필요한 값 : 원래 자료형


// 배열 -> 표현 자료형이 없기 때문에(C 
void DataSwap(int lParam , int rParam) { // 값에 의한호출
	int temp = lParam;
	printf("<swap 이전>lParam(%d)  , rParam(%d)\n", lParam, rParam);
	lParam = rParam;
	rParam = temp;
	printf("<swap 이후>lParam(%d)  , rParam(%d)\n", lParam, rParam);

	printf("함수 종료 : delete > lparam, rparam, temp\n");
	return;
}

void pDataSwap(int * plParam, int * prParam) { // 주소에 의한 호출
	int temp = *plParam;
	printf("plParam : %p \nprParam : %p\n", plParam, prParam);
	*plParam = *prParam;
	*prParam = temp;
	return;
}


int global_num; //MainApp_func01:: x;

/*
전역변수 : 프로그램 내부면 어디든 사용 가능 
지역변수 : 함수 내부에서만 사용하는 변수  (내수용)
정적변수 : 함수 내부에 있지만 메모리를 유지하는 변수 (수출가능)
외부변수 : 다른 파일의 전역변수 

  정수값
  문자
  소수점
  메모리 위치
  참거짓
  ....

  사용자 정의 타입
     구조체
	 열거형
	 공용체 
	 C 문법 -> 자료구조 알고리즘 -> C++
	 <Data Base >
	 API / MFC
*/

void func() {
	int func_num = 0; //func::x
	printf("func::num : %d \tglobal::num : %d\n",
		func_num++, global_num++);
}

int  func2() {
	static int stat_number = 0;
	global_num++;
	stat_number++;
	return stat_number;
}

//정적 변수 : 함수내부에서 함수 호출시 같이 메모리를 할당한다.
//           프로그램이 종료할 때 메모리에서 소멸한다.
int main() {
	printf("SIZE : %d\n", SIZE);
	
	int main_num = 0; // main::x
	int y = 0,x = 0;

	int funcCnt = 0;
	int funcCnt2 = 0;
	for (int i = 0; i < 10; i++) {
		 func();
		y = func2();
	}

	printf("func = %d번 실행함\n", global_num);
	
	
	printf("main::x = %d   main::y = %d\n", x, y);
	DataSwap(x, y);// == DataSwap(10,20)
	printf("main::x = %d   main::y = %d\n", x, y);
	printf("x의 메모리 : %p\n y의 메모리 : %p\n", &x, &y);
	pDataSwap(&x, &y);
	printf("main::x = %d   main::y = %d\n", x, y);



	return 0;
}