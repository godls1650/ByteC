#pragma once
/*
	������ ���� : �ٸ� Ŭ������ �Լ����� �� Ŭ������ private ����� ������ ����Ѵ�. 
	AŬ�������� B Ŭ������ ����� �����Ϸ���
	class B ���� class A�� ģ���� ���� 

	AŬ������ BŬ������ ģ���� ���� �ϰ�

	BŬ������ C Ŭ������ ģ���� ����


	class yangachi{
	friend class Babo;
	private :
		int money;
	public :
		void func(const Babo & babo){
			money += babo.money;
			babo.money = 0;
		}
	}

	class Babo{
		friend class yangachi;
	private :
		int money;
	}
*/

class myString{
	friend int main(); // �Լ��� ���� ������Ÿ���� ������� ���� 
	
private:
	const int bufSize = 16;
	char*	m_aStorage;
	int		m_nCapacity;

public :
	myString();
	myString(const char* _Ptr);
	myString(const myString& _Ref);
	~myString();

	int length();
	int capacity();
	int compare(const myString & ref);
	myString append(const myString & ref);
	int compare(const char* Str);

	myString operator=(const myString& ref);
	myString operator=(const char * _Str);

	myString operator+(const myString& ref);

	char operator[](int index);
};



