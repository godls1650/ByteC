#pragma once
/*
	프렌드 선언 : 다른 클래스나 함수에서 이 클래스의 private 멤버에 접근을 허용한다. 
	A클래스에서 B 클래스의 멤버에 접근하려면
	class B 에서 class A를 친구로 선언 

	A클래스는 B클래스를 친구로 선언 하고

	B클래스는 C 클래스를 친구로 선언


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
	friend int main(); // 함수의 선언 프로토타입을 프렌드로 지정 
	
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



