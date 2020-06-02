#include "MyPair.h"

void MyPair::setXY(int px, int py) {
	if((px >= 0 && px <=100)&&
		(py >= 0 && py <= 100)){
		x = px;
		y = py;
	}
	else {
		cout << "values error" << endl;
		return;
	}

}

void MyPair::viewInfo()
{
	cout << "[" << x << "," << y << "]" << endl;
}
MyPair::MyPair()
{
	x = y = 0;
}
// 생성자 오버로딩 
MyPair::MyPair(int x, int y) 
{//내부에서 멤버변수와 지역변수를 구별하기위해서
	//this 포인터
	this->x = x;
	this->y = y;
}


MyPair::~MyPair()
{
}
