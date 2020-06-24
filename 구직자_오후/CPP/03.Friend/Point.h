#pragma once
#include <ostream>
#include <istream>

class Point{
friend std::ostream& operator<<(std::ostream& os ,const Point & target);
friend std::istream& operator>>(std::istream& in, Point& target);

private:
	int X;
	int Y;
public :
	Point(int x = 0, int y = 0);
	Point(const Point& ref);
	void showPoint();

	//연산자의 동작
	/*
		A + B
		--전역함수로 연산자 구현
		TYPE(A) add(A,B)
		--멤버 할수로 연산자 구현
		A.add(B)

		C++ : 연산자의 기능을 
		함수 모양으로 정의한 명칭
		operator[기호]
		덧셈 연산자 : operator+
		뺼셈        : operator-
		복합 대입   : operator+=
		대입        : operator=

		오버로딩 불가능한 연산자 
		? : / ::

		*****
		기본 기능의 의미와 크게 벗어나지 않게 작성한다.
	*/

	Point operator+(const Point& ref);
	Point operator-(const Point& ref);
	Point operator-();

	bool operator<(const Point& ref);
	bool operator>(const Point& ref);
	bool operator==(const Point& ref);
	bool operator<=(const Point& ref);
	bool operator>=(const Point& ref);
	bool operator!=(const Point& ref);

	Point operator++();
	Point operator++(int x);
	Point operator--();
	Point operator--(int x);


};

