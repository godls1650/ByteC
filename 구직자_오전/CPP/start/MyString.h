#pragma once
/*  ��ü���� 3��� 
	��������
	������
	��Ӽ�

*/
#include "framework.h"
class MyString
{
private://�Ӽ��� (Attribute) --> �������
	char* buf;
	int capacity;
	//���� (Method) ==> ��� �Լ�
public :
	MyString();
	MyString(const char * str);
	//default copy destructor()
	MyString(const MyString& source);
	~MyString();
	char* toChrArray();
	void changeword(const char* str);
};

