#pragma once
#include "myBook.h"

class Comics : public myBook{
private :
	int numberring;

public :
	Comics() :numberring(0) {
		
		cout << "child class constructor" << endl;
	}

	//�θ𿡼� ������ void view() ������ �ڽ� Ŭ������ ���ľ���.;
	
	void view() { /*Override*/
		//myBook::view();
		cout << "��  �� : " << m_sTitle<<"("<< numberring<<")" << endl;
		cout << "��  �� : " << m_sAuthor << endl;
		cout << "���ǻ� : " << m_sCompany << endl;
		cout << "��  �� : " << m_nPrice << endl;
	}
};

