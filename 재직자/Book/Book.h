#pragma once
#include "framework.h"
/*
book 구조체 멤버목록
	타입       변수명		
	char *	m_sTitle		동적할당 받아서 써야됨
	char*	m_sCompany		동적할당 받아서 써야됨
	char*	m_sAuthor		동적할당 받아서 써야됨
	int		m_nPrice		가격 입력받아서 써야됨
*/
typedef struct Book {
	char * m_sTitle;
	char* m_sCompany;
	char* m_sAuthor;
	int m_nPrice;
}book;
//함수의 프로토타입 정의

//Heap에 Book 타입으로 초기화한 공간의 주소를 반환
book* initBook(void);
//도서 정보를 입력하는 함수
void SetBookElem(book *,const char * title,// 
					const char * company,  // 
					const char * author,   // 
					int price			   // 
				);

//파일에서 불러온 정보를 책 구조체에 저장하는 함수
FILE * fileLoad(const char * FileName, book * pbk);

//도서정보 갯수를 계산하는 함수
int getBookCnt(const char* FileName);
//도서 목록 출력함수
void ViewList(const book** pbookList, int cnt);
// 도서 출력함수 
void viewBookInfo(const book* pbk);

