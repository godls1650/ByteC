#pragma once
/*  객체지향 3요소 
	정보은닉
	다형성
	상속성

*/
#include "framework.h"
class MyString
{
private://속성값 (Attribute) --> 멤버변수
	char* buf;
	int capacity;
	//동작 (Method) ==> 멤버 함수
public :
	MyString();
	MyString(const char * str);
	//default copy destructor()
	MyString(const MyString& source);
	~MyString();
	char* toChrArray();
	void changeword(const char* str);
};

