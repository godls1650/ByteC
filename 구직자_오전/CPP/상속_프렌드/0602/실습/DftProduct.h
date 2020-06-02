#pragma once
#include "framework.h"
class DftProduct{
protected :
	int m_nPdCode;			// 상품코드
	string m_sPdName;		// 상품명
	string m_sPdCompany;	// 제조사
	string m_sPdSellerNM;	// 판매자
	int m_nStock;			// 재고 수량
	int m_nPrice;	// 가격
	
public :
	DftProduct();
	DftProduct(int code, string name, string company, string seller, int price, int stock);
	DftProduct(int code, const char * name, const char * company, const char * seller, int price, int stock);
	DftProduct(const DftProduct & cp);
	~DftProduct();

	int  getPdCode() const ;			// 상품코드
	string  getPdName()const;		// 상품명
	string  getPdCompany()const;	// 제조사
	string  getPdSellerNM()const;	// 판매자
	int  getStock()const;			// 재고 수량
	int  getPrice()const;
	

	void setPdCode(int code);			// 상품코드
	void setPdName(string name);		// 상품명
	void setPdCompany(string company);	// 제조사
	void setPdSellerNM(string name);	// 판매자
	void setPdName(const char *  name);		// 상품명
	void setPdCompany(const char *  company);	// 제조사
	void setPdSellerNM(const char *  name);	// 판매자
	void setPrice (int price);

	
	void setStock(int stock);			// 재고 수량

	void viewInfo() const;

	bool saveData(const char* const filename);



};

