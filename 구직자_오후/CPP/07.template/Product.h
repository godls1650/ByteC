#pragma once
#include "framework.h"

/*
상품코드 : 1537241355
상품코드 : SM2405_144LED
상품코드 : 193515-2419341
*/
// Product Class는 상품코드가 이후에 결정되는 클래스
// Class Template --> 일반화 프로그래밍 
// Function Template -->전역 함수

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

