#include "BookInfo.h"
BookInfo::BookInfo():m_nPrice(0){ m_sTitle = string(); m_sAuthor = string(); m_sCompany = string(); }
BookInfo::BookInfo(const char* const title, const char* const author, const char* const company, int price)	:	
m_sTitle(title),m_sAuthor(author),m_sCompany(company),m_nPrice(price){}

BookInfo::BookInfo(const string title, const string author, const string company, int price)	:
m_sTitle(title),m_sAuthor(author),m_sCompany(company),m_nPrice(price){}

BookInfo::BookInfo(const BookInfo& src){
	this->m_sTitle = string(src.m_sTitle);
	this->m_sAuthor = string(src.m_sAuthor);
	this->m_sCompany = string(src.m_sCompany);
	this->m_nPrice = src.m_nPrice;
}
string	BookInfo::getTitle() { return this->m_sTitle; }
string	BookInfo::getCompany() { return this->m_sAuthor; }
string	BookInfo::getAuthor() { return this->m_sCompany; }
int		BookInfo::getPrice() { return this->m_nPrice; }

void	BookInfo::setTitle(string title)				{this->m_sTitle =	string(title);}
void	BookInfo::setTitle(const char* const title)		{this->m_sTitle	=	string(title);}
void	BookInfo::setCompany(string company)			{this->m_sCompany = string(company);}
void	BookInfo::setCompany(const char* const company)	{this->m_sCompany = string(company);}
void	BookInfo::setAuthor(string author)				{this->m_sAuthor =	string(author);}
void	BookInfo::setAuthor(const char* const author)	{this->m_sAuthor =	string(author);}
void	BookInfo::setPrice(int price) { this->m_nPrice = price;}

void	BookInfo::viewBookInfo(){
	cout <<m_sTitle  <<"\t" <<m_sAuthor <<"\t" <<m_sCompany<< "\t" <<m_nPrice<<endl;
}

BookInfo::~BookInfo() { cout << "CaLlEd BoOk InFo InStAnCe DeStRuCt" << endl; }