#pragma once
#include "framework.h"

class myTV {
private :////���� ���� : private ���� ������////
	/////��ü(Instance) �ν��Ͻ� ��� ���� ////
	int m_nChannel;
	int m_nVolume;
	string* Locate_name;
	bool bPower;
	const string CmpLogo; // ������ 

	static const int maxChannel = 15; // ��� �����Ϳ� static �� ���� ��� : Ŭ���� ��� ���� 
	static int voltage;

public : ////���н�Ų ������ ����� �� �ְ� �ϴ� ��� �Լ��� ������ ó�� : ĸ��ȭ ////
	// �ʱ�ȭ ����Ʈ : ������ ������Ÿ�� <-> ':' ��������� () �� �ʱ�ȭ �ؼ� ����  <-> ���Ǻ��
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

