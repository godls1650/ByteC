#pragma once
#include "framework.h"// <string>  <cstring>   <string.h>
class Carcls{
private :
	char* m_cpName;
	int Speed;
	int fuelGauge;
	int hashV;
	
	
	static bool isFuelEmpty(int fuel);

public : 
	static int CarCnt; // static member != instance member 
	/* 데이터 초기화 : 생성자 (Constructor) */
	Carcls();
	Carcls(const char cName[] ,int sp, int feul);
	Carcls(const Carcls & ref);/*복사 생성자*/
	// 클래스의 멤버 중 동적할당 한 멤버 가  있을 경우 소멸자를 구현한다. 
	~Carcls(); //destructor : 소멸자 

	/*------------------------Method-----------------------------*/
	void pushAccel();
	void showCarState() const;
	int getCarCount();

	static void clsFunction(const Carcls & ref);
};

