#pragma once
#include "Product.h"
#include <ctime>
/*
struct tm
	int tm_sec;
*/

class FoodProduct : public Product{
private :
	tm fresh;

public :
	FoodProduct(
		 const char * name = "", key Code = 0, int price = 0,
		int year = 2020, int month = 3, int day = 2);
	void showProduct();
	~FoodProduct() { cout << "food ¼Ò¸êÀÚ È£Ãâ" << endl; }
};

