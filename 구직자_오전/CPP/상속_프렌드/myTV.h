#pragma once
#include "framework.h"

class myTV {
private :////정보 은닉 : private 접근 지정자////
	/////객체(Instance) 인스턴스 멤버 변수 ////
	int m_nChannel;
	int m_nVolume;
	string* Locate_name;
	bool bPower;
	const string CmpLogo; // 제조사 

	static const int maxChannel = 15; // 멤버 데이터에 static 이 사용될 경우 : 클래스 멤버 변수 
	static int voltage;

public : ////은닉시킨 정보를 사용할 수 있게 하는 멤버 함수를 공개로 처리 : 캡슐화 ////
	// 초기화 리스트 : 생성자 프로토타입 <-> ':' 멤버변수를 () 로 초기화 해서 나열  <-> 정의블록
	myTV() : m_nChannel(0), m_nVolume(0),bPower(false), CmpLogo("samsung"){ 
		Locate_name = new string();
	
	}
	myTV(int c, int v, const char* const ln);
	myTV(int c, int v, string ln);
	myTV(const myTV& copy);
	~myTV();
	//getter   setter  property
	int getChInfo() { return this->m_nChannel; }
	int getVolume() { return this->m_nVolume;  }
	string getLocate() { return *(this->Locate_name); }

	void pushPowerBtn() { bPower = !bPower; }
	void channelUp() {
		if (bPower == true && m_nChannel < maxChannel)
			this->m_nChannel += 1;
		else
			return;
	}


	
};

