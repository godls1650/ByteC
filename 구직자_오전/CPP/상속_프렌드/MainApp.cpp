#include "framework.h"
#include "BookInfo.h"
int main(void) {
	BookInfo ** bookList = new BookInfo *[5];
	string title = string();
	string author = string();
	string company = string();
	int price = 0;

	bookList[0] = new BookInfo();
	bookList[0]->setTitle("������ ���� C++ ���α׷���");
	bookList[0]->setCompany("������ �̵��");
	bookList[0]->setAuthor("������");
	bookList[0]->setPrice(27000);

	bookList[1] = new BookInfo("������ ���� �ڷᱸ�� �˰���", "������", "������ �̵��", 27000);

	bookList[2] = new BookInfo(*bookList[0]);
	bookList[2]->setTitle("������ ���� C��� ���α׷���");
	bookList[3] = new BookInfo("C��� �ڵ�����","������","���",	25000);
	bookList[4] = new BookInfo();
	
	
	cout << "������ : ";  getline(cin, title);
	cout << "��  �� : ";  getline(cin, author);
	cout << "���ǻ� : ";  getline(cin, company);
	cout << "��  �� : ";  cin >> price;

	bookList[4]->setTitle(title);
	bookList[4]->setAuthor(author);
	bookList[4]->setCompany(company);
	bookList[4]->setPrice(price);

	for (int i = 0; i < 5; i++) {
		bookList[i]->viewBookInfo();
	}


}