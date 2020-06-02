#include "myTV.h"
int myTV::voltage = 220;

myTV::myTV(int c, int v, const char* const ln): m_nChannel(c),m_nVolume(v),bPower(false), CmpLogo("samsung") { Locate_name = new string(ln); }
myTV::myTV(int c, int v, string ln) :m_nChannel(c), m_nVolume(v), bPower(false), CmpLogo("samsung") { Locate_name = new string(ln); }

myTV::myTV(const myTV& copy) {*this = myTV(copy.m_nChannel, copy.m_nVolume, *(copy.Locate_name));
	/*
	this->m_nChannel = copy.m_nChannel;
	this->m_nVolume = copy.m_nVolume;
	this->bPower = copy.bPower;
	this->Locate_name = new string(*(copy.Locate_name));// --> ���� ����
	*/
	//this->Locate_name =  copy.Locate_name;  -----> ���� ����
}

myTV::~myTV() { // ��ü�� �����Ҵ��� ����� ������ �ۼ� 
	delete Locate_name;
}