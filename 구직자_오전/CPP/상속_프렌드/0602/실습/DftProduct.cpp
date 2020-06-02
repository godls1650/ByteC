#include "DftProduct.h"

DftProduct::DftProduct():m_nPdCode(0),m_nPrice(0),m_nStock(0){
	m_sPdName		 = string();
	m_sPdCompany	 = string();
	m_sPdSellerNM	 = string();
};
DftProduct::DftProduct(int code, string name, string company, string seller,int price, int stock):
	m_nPdCode(code), m_nPrice(price), m_nStock(stock),
	m_sPdName(name),m_sPdCompany(company),m_sPdSellerNM(seller){};


DftProduct::DftProduct(int code, const char* name, const char* company, const char* seller,int price, int stock):
	m_nPdCode(code), m_nPrice(price), m_nStock(stock),
	m_sPdName(name), m_sPdCompany(company), m_sPdSellerNM(seller) {};


DftProduct::DftProduct(const DftProduct& cp):
	m_nPdCode(cp.m_nPdCode), m_nPrice(cp.m_nPrice), m_nStock(cp.m_nStock),
	m_sPdName(cp.m_sPdName), m_sPdCompany(cp.m_sPdCompany), m_sPdSellerNM(cp.m_sPdSellerNM) {};
DftProduct::~DftProduct() {};

int		DftProduct::getPdCode() const {			// ��ǰ�ڵ�
	return this->m_nPdCode;
}
string  DftProduct::getPdName()const {		// ��ǰ��
	return this->m_sPdName;
}
string  DftProduct::getPdCompany()const {	// ������
	return this->m_sPdCompany;
}
string  DftProduct::getPdSellerNM()const {	// �Ǹ���
	return this->m_sPdSellerNM;
}
int		DftProduct::getStock()const {			// ��� ����
	return this->m_nStock;
}

int  DftProduct::getPrice()const { return m_nPrice; }
void DftProduct::setPrice(int price) { m_nPrice = price; }

void DftProduct::setPdCode(int code) {			// ��ǰ�ڵ�
	this->m_nPdCode = code;
}
void DftProduct::setPdName(string name) {		// ��ǰ��
	this->m_sPdName = name;
}
void DftProduct::setPdCompany(string company){	// ������
	this->m_sPdCompany = company;
}
void DftProduct::setPdSellerNM(string name) {	// �Ǹ���
	this->m_sPdSellerNM = name;
}
void DftProduct::setPdName(const char* name) {		// ��ǰ��
	this->m_sPdName = name;
}
void DftProduct::setPdCompany(const char* company) {	// ������
	this->m_sPdCompany = company;
}
void DftProduct::setPdSellerNM(const char* name) {	// �Ǹ���
	this->m_sPdSellerNM = name;
}
void DftProduct::setStock(int stock) {			// ��� ����
	this->m_nStock = stock;
}

void DftProduct::viewInfo() const {
	return;
}

bool DftProduct::saveData(const char* const filename) {
	ofstream fout;
	fout.open(filename, ios_base::out);
	fout
		<< m_nPdCode << "\t"
		<< m_sPdName << "\t"
		<< m_sPdCompany << "\t"
		<< m_sPdSellerNM << "\t"
		<< m_nStock << endl;
	fout.close();
	return true;
}
