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
// ������ �����ε� 
MyPair::MyPair(int x, int y) 
{//���ο��� ��������� ���������� �����ϱ����ؼ�
	//this ������
	this->x = x;
	this->y = y;
}


MyPair::~MyPair()
{
}
