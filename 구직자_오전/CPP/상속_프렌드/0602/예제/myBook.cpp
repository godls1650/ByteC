#include "myBook.h"

myBook::myBook() : m_nPrice(0)
{
	cout << "parent class constructor" << endl;
	m_sTitle = string();
	m_sAuthor = string();
	m_sCompany = string();
}

myBook::myBook(string title, string author, string company, int price) :
m_sTitle(title), m_sAuthor(author), m_sCompany(company), m_nPrice(price) 
{};

myBook::myBook(const char* title, const char* author, const char* company, int price) :
	m_sTitle(title), m_sAuthor(author), m_sCompany(company), m_nPrice(price) 
{};



void myBook::view() {
	cout << "제  목 : " << m_sTitle << endl;
	cout << "저  자 : " << m_sAuthor << endl;
	cout << "출판사 : " << m_sCompany << endl;
	cout << "가  격 : " << m_nPrice << endl;
}