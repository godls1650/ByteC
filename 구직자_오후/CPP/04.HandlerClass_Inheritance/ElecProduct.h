#pragma once
#include "Product.h"
class ElecProduct : public Product{
private :
	int m_nVoltage;
public :
	~ElecProduct() { 
		cout << "elec �Ҹ��� ȣ��" << endl; }
	ElecProduct(const char* name = "",
		key productCode = 0, price Price = 0, int voltage = 220)
		: Product(name, productCode, Price), m_nVoltage(voltage)
	{
	
	}
	// �θ�Ŭ������ �Լ��� 
	// �ڽ� Ŭ�������� �����Ѵ�.
	// �������̵� Override
	void showProduct();
};

