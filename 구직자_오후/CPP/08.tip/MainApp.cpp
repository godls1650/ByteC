#include <iostream>
#include "myException.h"
using namespace std;
/*
class Base {
protected:
	int bNumber;
public:
	Base() :bNumber(0) {}
	Base(int number) :bNumber(number) {}
	virtual void show() { cout << "부모함수" << endl; }
};
class Child1 : public Base {
private:
	double dData;
public:
	Child1(int n, double d) : dData(d) { Base(number); }
	virtual void show() { cout << "자식함수" << endl; }
};
class Child2 : public Base {
private:
	string text;
public:
	Child2(int n, string t) :text(t) { Base(number); }
	virtual void show() { cout << "자식2 함수" << endl; }
};

ostream& operator<<(ostream& os, const type_info& ref) {
	os << ref.name();
	return os;
}

	상품코드 | 상품분류 | 상품명 |    가격   | 비고 1 | 비고 2 | 비고 3
	 214534    의류      후드티    2,2300     남성     상의
	 131054    가전제품	 냉장고   1,232,450  220V     주방
	 520143    잡화      물티슈     1,000      -

*/
/*
try : 예외를 발견 ---> 오류가 날 것이라고 예상이 되는 코드를 try블록으로 감싼다.
throw : 예외를 던진다.
catch : 예외를 잡는다.

*/
int CalcFunc(int x, int y) throw(ArithmeticException) {
	int result = 0;
	result =  x + y ; cout << result << endl;
	result =  x - y ; cout << result << endl;
	result =  x * y ; cout << result << endl;
	if (y == 0)throw ArithmeticException();
	result =  x / y ; cout << result << endl;
	result =  x % y ; cout << result << endl;
	return result;
}
int main() {
	int num1(0), num2(0);
	//int* ptr = nullptr;

	cout << "정수 2개 입력  > ";
	cin >> num1 >> num2;
	/*
	try {
		if (num1 < 0) throw bad_alloc();
		if(num1 == 0) throw exception("bad alloc(0)");
		ptr = new int[num1];
	}
	catch (exception e) {
		cout << e.what() << endl;
	}*/
	int r = 0;
	try {
		r = CalcFunc(num1, num2);
	}
	catch (exception e) {
	
	}


	cout << r << endl;
	return 0;
}