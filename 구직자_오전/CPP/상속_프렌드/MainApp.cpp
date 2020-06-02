#include "framework.h"
#include "BookInfo.h"
int main(void) {
	BookInfo ** bookList = new BookInfo *[5];
	string title = string();
	string author = string();
	string company = string();
	int price = 0;

	bookList[0] = new BookInfo();
	bookList[0]->setTitle("윤성우 열혈 C++ 프로그래밍");
	bookList[0]->setCompany("오랜지 미디어");
	bookList[0]->setAuthor("윤성우");
	bookList[0]->setPrice(27000);

	bookList[1] = new BookInfo("윤성우 열혈 자료구조 알고리즘", "윤성우", "오랜지 미디어", 27000);

	bookList[2] = new BookInfo(*bookList[0]);
	bookList[2]->setTitle("윤성우 열혈 C언어 프로그래밍");
	bookList[3] = new BookInfo("C언어 코딩도장","남재윤","길벗",	25000);
	bookList[4] = new BookInfo();
	
	
	cout << "도서명 : ";  getline(cin, title);
	cout << "저  자 : ";  getline(cin, author);
	cout << "출판사 : ";  getline(cin, company);
	cout << "가  격 : ";  cin >> price;

	bookList[4]->setTitle(title);
	bookList[4]->setAuthor(author);
	bookList[4]->setCompany(company);
	bookList[4]->setPrice(price);

	for (int i = 0; i < 5; i++) {
		bookList[i]->viewBookInfo();
	}


}