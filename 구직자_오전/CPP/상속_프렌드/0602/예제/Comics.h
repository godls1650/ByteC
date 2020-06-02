#pragma once
#include "myBook.h"

class Comics : public myBook{
private :
	int numberring;

public :
	Comics() :numberring(0) {
		
		cout << "child class constructor" << endl;
	}

	//부모에서 정의한 void view() 내용을 자식 클래스가 고쳐쓴다.;
	
	void view() { /*Override*/
		//myBook::view();
		cout << "제  목 : " << m_sTitle<<"("<< numberring<<")" << endl;
		cout << "저  자 : " << m_sAuthor << endl;
		cout << "출판사 : " << m_sCompany << endl;
		cout << "가  격 : " << m_nPrice << endl;
	}
};

