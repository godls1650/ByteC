#pragma once
#include "Product.h"
/*
	ProductList 클래스는
	Product 클래스의 인스턴스를
	멤버 데이터로 사용한다.

	--> ProductList has a Product  -->  사용 
	--> ElectroProduct is a Product --> 확장 
	
	확장 : extends / implements ==> inheritance
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

