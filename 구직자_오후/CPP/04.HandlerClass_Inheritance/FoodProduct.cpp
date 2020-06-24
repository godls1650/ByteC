#include "FoodProduct.h"
FoodProduct::FoodProduct(
	const char* name, key Code, int price,
	int year, int month, int day)
	: Product(name, Code, price){
	fresh.tm_year = year;
	fresh.tm_mon = month + 1;
	fresh.tm_mday = day;
	cout << "자식클래스의 생성자를 호출" << endl;
}

void FoodProduct::showProduct() {
	int n = 0;
	int p = this->m_nPdPrice;
	//12  400
	while ((p /= 1000) != 0) { n++; }

	int* parr = new int[n + 1];

	p = this->m_nPdPrice;
	for (int i = 0; i < n + 1; i++) {
		parr[i] = p % 1000;
		p /= 1000;
	}

	cout << setw(8) << setfill(' ') << left << this->m_nPdCode;
	cout << setw(20) << setfill(' ') << left << this->m_sPdName;
	cout << fresh.tm_year << "-" << setw(2) <<right<< setfill('0') <<fresh.tm_mon
		<< "-" << setw(2) << setfill('0') << fresh.tm_mday <<"\t";

	for (int i = n; i >= 0; i--) {
		if (i == n)cout << setw(3) << right << parr[i];
		else cout << "," << setw(3) << setfill('0') << parr[i];
	}
}
