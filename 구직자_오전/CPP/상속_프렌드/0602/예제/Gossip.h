#pragma once
#include "myBook.h"
class Gossip : public myBook{

private :
	int m_nMonth;
public :
	Gossip() : m_nMonth(0) {};
	Gossip(string title, string author, string company, int price, int month) :
		myBook(title, author, company, price), m_nMonth(month){ }
	Gossip(const char* title, const char* author, const char* company, int price, int month):
		myBook(title, author, company, price), m_nMonth(month) { };

	void view() {
		myBook::view();
		cout << m_nMonth << "¿ù È£" << endl;
	}
};

