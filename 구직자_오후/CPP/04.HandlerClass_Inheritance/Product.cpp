#include "Product.h"
/*************Product Class Global Method*************/
//Constructor
/*@parameter	string		m_sPd	Name
  @parameter	uint(key)	m_nPd	Code
  @parameter	uint(price)	m_nPd	Price
*/
Product::Product(const char* name, key productCode, price Price)
	:m_sPdName(name), m_nPdPrice(Price), m_nPdCode(productCode){
	cout << "부모클래스의 생성자를 호출" << endl;
}

Product::Product(string name, key productCode, price Price) 
	: m_sPdName(name), m_nPdPrice(Price), m_nPdCode(productCode) {}

Product::Product(const Product& rp)
	: m_sPdName(rp.m_sPdName),
	m_nPdPrice(rp.m_nPdPrice), m_nPdCode(rp.m_nPdCode) {}

//Destructor
Product::~Product() { cout << "부모 소멸자 호출" << endl; }

void Product::setPdName(const char* name){this->m_sPdName = name;}
void Product::setPdName(string name){ this->m_sPdName = name; }
void Product::setPdCode(key Code) { this->m_nPdCode = Code; }
void Product::setPdPrice(price Price) { this->m_nPdPrice = Price; };

string	Product::getPdName() { return this->m_sPdName; }
key		Product::getPdCode() { return this->m_nPdCode; }
price	Product::getPdPrice() { return this->m_nPdPrice; }

void Product::showProduct() {
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

	for (int i = n; i >= 0; i--) {
		if (i == n)cout << setw(3) << right << parr[i];
		else cout << "," << setw(3) << setfill('0') << parr[i];
	}


}

//private method
bool Product::isSameCode(key Code) {
	if (this->m_nPdCode == Code) return true;
	else return false;
}

/*************Product Class Global Function*************/
ostream& operator<<(ostream& os, const Product& rp) {
	int n = 0;
	int p = rp.m_nPdPrice;
	//12  400
	while ((p /= 1000) != 0) { n++; }

	int* parr = new int[n + 1];

	p = rp.m_nPdPrice;
	for (int i = 0; i < n + 1; i++) {
		parr[i] = p % 1000;
		p /= 1000;
	}


	os << setw(8) << setfill(' ') << left << rp.m_nPdCode;
	os << setw(20) << setfill(' ') << left << rp.m_sPdName;
	
	for (int i = n; i >= 0; i--) {
		if (i == n)os << setw(3) <<right<< parr[i];
		else os << "," << setw(3)<<setfill('0') << parr[i];
	}


	return os;
}
istream& operator>>(istream& is, Product& rp) {
	cout << "상품 코드 > ";
	is >> rp.m_nPdCode;

	is.ignore();// 버퍼를 비운다..
	
	cout << "상품명 > ";
	getline(is, rp.m_sPdName);
	cout << "가  격 > ";
	is >> rp.m_nPdPrice;
	return is;
}
