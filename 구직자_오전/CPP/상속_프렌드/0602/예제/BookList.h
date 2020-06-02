#pragma once
#include "myBook.h"
#include <vector>
#include <algorithm>
class BookList{
private :
	//myBook ** 
	vector<myBook> storage;
	const static int MaxSize = 10;
public : 
	BookList() :storage(MaxSize) {};
	void appendBook(string t, string a, string c, int p) {
		storage.push_back(myBook(t,a,c,p));
	}

	void viewList() {
		vector<myBook>::iterator i;
		i = storage.begin();
		for (; i != storage.end(); i++) {
			i->view();
		}
	}
};

