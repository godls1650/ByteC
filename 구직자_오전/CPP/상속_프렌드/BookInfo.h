#pragma once
#include "framework.h"
class BookInfo{
private :
	string	m_sTitle;
	string	m_sAuthor;
	string	m_sCompany;
	int		m_nPrice;

	static FILE* fp;

public : 
	/*contructor*/

	BookInfo();
	BookInfo(const char * const title, const char * const author, const char * const company,int price);
	BookInfo(const string title, const string author, const string company, int price);
	BookInfo(const BookInfo& src);
	//BookInfo(const char* fileName); 이건 다음에

	/*getter*/
	string	getTitle();
	string	getCompany();
	string	getAuthor();
	int		getPrice();
	/*setter  : parameter type (const char * const / string : overloading)*/
	void	setTitle(string title);	
	void	setTitle(const char * const title);
	
	void	setCompany(string company);	
	void	setCompany(const char * const company);
	
	void	setAuthor(string author);	
	void	setAuthor(const char * const author);
	
	void	setPrice(int price);	

	/*instance Method*/
	void viewBookInfo();

	/*destructor*/
	~BookInfo();
};

