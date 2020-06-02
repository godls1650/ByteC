#pragma once
#include "framework.h"
class myReferenceBook{
private :
	string m_sTitle, m_sAuthor, m_sCompany;
	int m_nPrice;
	string MajorName;

	myReferenceBook();
	myReferenceBook
	(string title, string author, string company, string MajorName, int price);
	myReferenceBook
	(const char* title, const char* author, 
		const char* company, const char * MajorName,int price);


	void view();
};

