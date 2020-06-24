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
	/* ������ �ʱ�ȭ : ������ (Constructor) */
	Carcls();
	Carcls(const char cName[] ,int sp, int feul);
	Carcls(const Carcls & ref);/*���� ������*/
	// Ŭ������ ��� �� �����Ҵ� �� ��� ��  ���� ��� �Ҹ��ڸ� �����Ѵ�. 
	~Carcls(); //destructor : �Ҹ��� 

	/*------------------------Method-----------------------------*/
	void pushAccel();
	void showCarState() const;
	int getCarCount();

	static void clsFunction(const Carcls & ref);
};

