#include "Point.h"
#include <iostream>
Point::Point(int x, int y):X(x),Y(y) { }
// Point() --> {0,0}
// Point(10,2) ==> {10, 2}
Point::Point(const Point& ref) : X(ref.X), Y(ref.Y) {}
void Point::showPoint() {
	std::cout << "{" << X << "," << Y << "}" << std::endl;
}

Point  Point::operator+(const Point& ref) {
	return Point(this->X + ref.X,
		this->Y + ref.Y);
}
Point Point::operator-(const Point& ref) {
	return Point(this->X - ref.X,
		this->Y - ref.Y);
}
Point Point::operator-() {
	return Point(-(this->X), -(this->Y));
}

bool Point::operator<(const Point& ref) {
	return this->X < ref.Y;
}
bool Point::operator>(const Point& ref) {
	return ref.Y < this->X;  
}
bool Point::operator==(const Point& ref) {
	return ref.Y == this->X;
}
bool Point::operator<=(const Point& ref) {
	return !(*this > ref);
}
bool Point::operator>=(const Point& ref) {
	return !(*this < ref);
}
bool Point::operator!=(const Point& ref) {
	return ! (*this == ref);
}

// 전위 증감연산자
Point Point::operator++() {
	this->X += 1;
	this->Y += 1;
	return *this; 
}// ++point

// 후위 증감연산자
Point Point::operator++(int x) {
	Point temp = Point(*this);
	this->X += 1;
	this->Y += 1;
	return temp;
}// point++;

// 전위 증감연산자
Point Point::operator--() {
	this->X -= 1;
	this->Y -= 1;
	return *this;
}// --point

// 후위 증감연산자
Point Point::operator--(int x) {
	Point temp = Point(*this);
	this->X -= 1;
	this->Y -= 1;
	return temp;
}// point--;


//std::cout << "{" << X << "," << Y << "}" << std::endl;

//cout << "{" 
// 1. 멤버함수 모양 --> cout. operator<< (const string & text);
// 2. 전역함수 모양 --> opstream & operator<<( ostream & os, const string & text);
//								os << text.m_aStorage 


// ostream & operator<< (ostream & os, const string & text);
std::ostream& operator<<(std::ostream& os, const Point& target) {
	os <<"[" <<target.X << ", "<<target.Y << "]"<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Point& target)
{
	std::cout << "x좌표값 >";
	in >> target.X;
	std::cout << "y좌표값 >";
	in >> target.Y;
	// TODO: 여기에 return 문을 삽입합니다.
	return in;
}
