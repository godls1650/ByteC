#pragma once
#include "framework.h"
class DftProduct{
protected :
	int m_nPdCode;			// ��ǰ�ڵ�
	string m_sPdName;		// ��ǰ��
	string m_sPdCompany;	// ������
	string m_sPdSellerNM;	// �Ǹ���
	int m_nStock;			// ��� ����
	int m_nPrice;	// ����
	
public :
	DftProduct();
	DftProduct(int code, string name, string company, string seller, int price, int stock);
	DftProduct(int code, const char * name, const char * company, const char * seller, int price, int stock);
	DftProduct(const DftProduct & cp);
	~DftProduct();

	int  getPdCode() const ;			// ��ǰ�ڵ�
	string  getPdName()const;		// ��ǰ��
	string  getPdCompany()const;	// ������
	string  getPdSellerNM()const;	// �Ǹ���
	int  getStock()const;			// ��� ����
	int  getPrice()const;
	

	void setPdCode(int code);			// ��ǰ�ڵ�
	void setPdName(string name);		// ��ǰ��
	void setPdCompany(string company);	// ������
	void setPdSellerNM(string name);	// �Ǹ���
	void setPdName(const char *  name);		// ��ǰ��
	void setPdCompany(const char *  company);	// ������
	void setPdSellerNM(const char *  name);	// �Ǹ���
	void setPrice (int price);

	
	void setStock(int stock);			// ��� ����

	void viewInfo() const;

	bool saveData(const char* const filename);



};

