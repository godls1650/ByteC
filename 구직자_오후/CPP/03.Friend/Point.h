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

	//�������� ����
	/*
		A + B
		--�����Լ��� ������ ����
		TYPE(A) add(A,B)
		--��� �Ҽ��� ������ ����
		A.add(B)

		C++ : �������� ����� 
		�Լ� ������� ������ ��Ī
		operator[��ȣ]
		���� ������ : operator+
		�E��        : operator-
		���� ����   : operator+=
		����        : operator=

		�����ε� �Ұ����� ������ 
		? : / ::

		*****
		�⺻ ����� �ǹ̿� ũ�� ����� �ʰ� �ۼ��Ѵ�.
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

