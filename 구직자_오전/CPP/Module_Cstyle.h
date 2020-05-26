#pragma once
#include "framework.h"

/*
	<< : Left Shift
	>> : Right Shift

	도서관리 프로그램을 만든다.
	 < C 언어>

*/

/*
namespace 이름 공간
코드를 하나의 이름으로 묶어서 관리하는 명령어
*/

void swap(int& x, int& y) {// 참조변수 : reference type
	int temp = x;
	cout << "swap::참조변수 x의 메모리 주소 : " << &x << endl;
	x = y;
	y = temp;
}

void setArray(int*& ref) {
	ref[0] = 1000;
}

void swap(int* x, int* y) {// 주소를 저장하는 타입의 변수 
	cout << "swap::포인터 x의 메모리 주소 : " << &x << endl;
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Ex01() {
	int* arr = (int*)malloc(sizeof(int) * 10);
	int* ptr = new int[10];
	string name = "홍길동";
	name = "대입으로 변경"; // 연산자 오버로딩
	name += "가능";

	name != "이거도 됩니다";

	name.compare("이거도 됩니다");
	name.operator=("what");

	cout << name;

	setArray(ptr);
	cout << ptr[0] << endl;


	cout << ptr[0];
	cout << endl;


	int x = 100, y(200);
	cout << "main:: 정수 x의 메모리 주소 : " << &x << endl;
	cout << "x : " << x << "\ty : " << y << endl;
	cout << "매객변수가 일반 int 인 교환함수 실행 후" << endl;
	swap(x, y);
	cout << "x : " << x << "\ty : " << y << endl;

	cout << "매객변수가 int * 인 교환함수 실행 후" << endl;
	swap(&x, &y);
	cout << "x : " << x << "\ty : " << y << endl;


}