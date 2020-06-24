#pragma once
#include "framework.h"
typedef unsigned int key, * pkey;
typedef unsigned int price;
class Product{
	friend ostream& operator<<(ostream& os, const Product& rp);
	friend istream& operator>>(istream& is, Product& rp);
private :
	

protected :
	key m_nPdCode;
	string m_sPdName;
	price m_nPdPrice;
	

	

public : /*持失切  & 社瑚切*/
	Product(const char * name = "",
		   key productCode = 0, price Price = 0);
	Product(string name, key productCode = 0,
		price Price = 0);
	Product(const Product& rp);
	virtual ~Product();
public : /*method*/
	bool isSameCode(key Code);
	void setPdName(const char * name);
	void setPdName(string name);
	void setPdCode(key Code);
	void setPdPrice(price Price);
	virtual void showProduct();
	string getPdName();
	key getPdCode();
	price getPdPrice();

	
};

