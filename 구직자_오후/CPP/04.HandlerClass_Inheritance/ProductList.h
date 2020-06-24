#pragma once
#include "Product.h"
/*
	ProductList Ŭ������
	Product Ŭ������ �ν��Ͻ���
	��� �����ͷ� ����Ѵ�.

	--> ProductList has a Product  -->  ��� 
	--> ElectroProduct is a Product --> Ȯ�� 
	
	Ȯ�� : extends / implements ==> inheritance
*/
class ProductList{
	friend ostream& operator<<(ostream& os,const ProductList & phandle);
private :
	Product* m_pStorage;
	int index;
	size_t Capacity;
public :
	ProductList(size_t capacity = 3);
	~ProductList();
	int getSize();
	int capacity();
	void append(key code, const char* name, price Price);
	void append(key code, string name, price Price);
	void append(const Product & product);

};

