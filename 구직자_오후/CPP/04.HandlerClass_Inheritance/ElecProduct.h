#pragma once
#include "Product.h"
class ElecProduct : public Product{
private :
	int m_nVoltage;
public :
	~ElecProduct() { 
		cout << "elec 소멸자 호출" << endl; }
	ElecProduct(const char* name = "",
		key productCode = 0, price Price = 0, int voltage = 220)
		: Product(name, productCode, Price), m_nVoltage(voltage)
	{
	
	}
	// 부모클래스의 함수를 
	// 자식 클래스에서 변형한다.
	// 오버라이딩 Override
	void showProduct();
};

