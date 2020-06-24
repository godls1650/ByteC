#pragma once
#include "framework.h"
class Character{
protected :
	string m_strName;
	int m_nHp;
	int m_nMp;

public :
	Character(const char* name = "(null)", int hp = 0, int mp = 0)
		:m_strName(name), m_nHp(hp), m_nMp(mp) {}
	virtual ~Character() {}
	virtual void showInfo();
};

