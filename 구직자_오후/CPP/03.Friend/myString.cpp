#include "myString.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
myString::myString():m_nCapacity(1) {
	m_aStorage = new char[m_nCapacity * bufSize];
}

myString::myString(const char * _Ptr) {
	int i = 0;
	while((1 << 4 * (++i)) < strlen(_Ptr));
	m_aStorage = new char[i * bufSize];

	strcpy(m_aStorage, _Ptr);

	m_nCapacity = i;
}

myString::myString(const myString& _Ref) {
	m_nCapacity = _Ref.m_nCapacity;
	m_aStorage = new char[m_nCapacity * bufSize];
	strcpy(m_aStorage, _Ref.m_aStorage);
}

myString::~myString() {
	delete[] m_aStorage;
}

int myString::length() {
	return strlen(m_aStorage);
}
int myString::capacity() {
	return m_nCapacity * bufSize -1;
	// return m_nCapacity << 4 -1 ;
}

int myString::compare(const myString& ref) {
	return strcmp(this->m_aStorage, ref.m_aStorage);
}

int myString::compare(const char * Str) {
	return strcmp(this->m_aStorage, Str);
}

myString myString::append(const myString& ref) {
	int len = this->m_nCapacity + ref.m_nCapacity;
	char* temp = new char[len * bufSize];

	strcpy(temp, this->m_aStorage);
	strcat(temp, ref.m_aStorage);

	delete[] m_aStorage;
	m_aStorage = new char[len * bufSize];
	strcpy(m_aStorage, temp);
	m_nCapacity = len;
	return *this;
}


myString myString::operator=(const myString& ref) {
	
	std::cout << "대입 오버로딩" << std::endl;
	return myString(ref);

}
myString myString::operator=(const char* _Str) {

	return myString(_Str);
}


myString myString::operator+(const myString& ref) {
	myString temp = myString(*this);
	temp.append(ref);
	return temp;
}// myString x, y, z;
// z = "hello world";
// y = "wow"
// x  = temp;

char myString::operator[](int index) {
	return this->m_aStorage[index];
}



