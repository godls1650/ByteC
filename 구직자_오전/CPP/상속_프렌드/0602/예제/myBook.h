#pragma once
#include "framework.h"
class myBook{
protected : 
	string m_sTitle, m_sAuthor, m_sCompany;
	int m_nPrice;
public :
	myBook();
	myBook(string title, string author, string company, int price);
	myBook(const char * title, const char * author, const char * company, int price);
	

	void view();
	
};

