#pragma once
#include "framework.h"

/*
��ǰ�ڵ� : 1537241355
��ǰ�ڵ� : SM2405_144LED
��ǰ�ڵ� : 193515-2419341
*/
// Product Class�� ��ǰ�ڵ尡 ���Ŀ� �����Ǵ� Ŭ����
// Class Template --> �Ϲ�ȭ ���α׷��� 
// Function Template -->���� �Լ�

template <typename CodeType>
class Product{
protected:
	CodeType m_tPdCode;
	string m_sPdName;
	int m_nPdPrice;
public :
	Product();

	CodeType getCode();
};

