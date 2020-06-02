#pragma once
#include "framework.h"
/*
좌표
 x : 0 ~ 100
 y : 0 ~ 100
*/
/*
<<접근 지정자>>
public : 외부의 접근을 허용한다. ( 공용의 ~ )
private : 외부의 모든 접근을 차단(사적인 ~ )
*/
class MyPair{
private :
	int x;
	int y;

public :
	// default constructor()
	// default destructor()
	//constructor : 생성자 
	MyPair();

	MyPair(int , int);
	~MyPair();
	//destructor : 소멸자 
	void setXY(int px, int py);
	void viewInfo();
};


