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
	virtual void show() { cout << "�θ��Լ�" << endl; }
};
class Child1 : public Base {
private:
	double dData;
public:
	Child1(int n, double d) : dData(d) { Base(number); }
	virtual void show() { cout << "�ڽ��Լ�" << endl; }
};
class Child2 : public Base {
private:
	string text;
public:
	Child2(int n, string t) :text(t) { Base(number); }
	virtual void show() { cout << "�ڽ�2 �Լ�" << endl; }
};

ostream& operator<<(ostream& os, const type_info& ref) {
	os << ref.name();
	return os;
}

	��ǰ�ڵ� | ��ǰ�з� | ��ǰ�� |    ����   | ��� 1 | ��� 2 | ��� 3
	 214534    �Ƿ�      �ĵ�Ƽ    2,2300     ����     ����
	 131054    ������ǰ	 �����   1,232,450  220V     �ֹ�
	 520143    ��ȭ      ��Ƽ��     1,000      -

*/
/*
try : ���ܸ� �߰� ---> ������ �� ���̶�� ������ �Ǵ� �ڵ带 try������� ���Ѵ�.
throw : ���ܸ� ������.
catch : ���ܸ� ��´�.

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

	cout << "���� 2�� �Է�  > ";
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