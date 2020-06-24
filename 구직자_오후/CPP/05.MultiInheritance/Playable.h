#pragma once
class Playable
{
protected:
	int m_nAtk;
	int m_nSAtk;
	int m_nDef;
	int m_nsDef;
	int m_nAgil;
	int m_nLuk;
public:
	Playable(int a, int sa, int d, int sd, int ag, int lk):
		m_nAtk(a),
	m_nSAtk(sa),
	m_nDef(d),
	m_nsDef(sd),
	m_nAgil(ag),
	m_nLuk(lk)
	{}
	virtual ~Playable() {};
	virtual double calc_Avsion() = 0;
	virtual double calc_Accuracy() = 0;
	virtual double calc_Skill(int ) = 0;
};

