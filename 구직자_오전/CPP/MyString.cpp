#include "MyString.h"

MyString::MyString(){
	//buf = NULL;
	capacity = 20;
	buf = new char[capacity];
}
MyString::~MyString() {
	cout << "~Mysting() È£Ãâ" << endl;
	delete [] buf;
	//delete : ÇÒ´çµÈ Èü °ø°£À» ¼Ò¸ê
	//delete [] : ÇÏ¶ûµÈ Èü ¹è¿­À» ¼Ò¸ê
}

MyString::MyString(const char* str) {
	char* temp = NULL;
	this->capacity = strlen(str);
	temp = new char[this->capacity + 1];
	for (int i = 0; i <= this->capacity; i++)
		temp[i] = str[i];
	//delete [] this->buf;
	this->buf = temp;
}

MyString::MyString(const MyString& source) {
	this->capacity = source.capacity;
	this->buf = new char[this->capacity + 1];
	for (int i = 0; i <= this->capacity; i++)
		this->buf[i] = source.buf[i];
}
char* MyString::toChrArray() {
	return this->buf;
}

void MyString::changeword(const char* str) {
	for (int i = 0; i < strlen(str); i++) {
		this->buf[i] = str[i];
	}
	return;
}


