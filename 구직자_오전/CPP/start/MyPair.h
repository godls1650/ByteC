#pragma once
#include "framework.h"
/*
��ǥ
 x : 0 ~ 100
 y : 0 ~ 100
*/
/*
<<���� ������>>
public : �ܺ��� ������ ����Ѵ�. ( ������ ~ )
private : �ܺ��� ��� ������ ����(������ ~ )
*/
class MyPair{
private :
	int x;
	int y;

public :
	// default constructor()
	// default destructor()
	//constructor : ������ 
	MyPair();

	MyPair(int , int);
	~MyPair();
	//destructor : �Ҹ��� 
	void setXY(int px, int py);
	void viewInfo();
};


