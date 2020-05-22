#pragma once
#include "framework.h"
/*
book ����ü ������
	Ÿ��       ������		
	char *	m_sTitle		�����Ҵ� �޾Ƽ� ��ߵ�
	char*	m_sCompany		�����Ҵ� �޾Ƽ� ��ߵ�
	char*	m_sAuthor		�����Ҵ� �޾Ƽ� ��ߵ�
	int		m_nPrice		���� �Է¹޾Ƽ� ��ߵ�
*/
typedef struct Book {
	char * m_sTitle;
	char* m_sCompany;
	char* m_sAuthor;
	int m_nPrice;
}book;
//�Լ��� ������Ÿ�� ����

//Heap�� Book Ÿ������ �ʱ�ȭ�� ������ �ּҸ� ��ȯ
book* initBook(void);
//���� ������ �Է��ϴ� �Լ�
void SetBookElem(book *,const char * title,// 
					const char * company,  // 
					const char * author,   // 
					int price			   // 
				);

//���Ͽ��� �ҷ��� ������ å ����ü�� �����ϴ� �Լ�
FILE * fileLoad(const char * FileName, book * pbk);

//�������� ������ ����ϴ� �Լ�
int getBookCnt(const char* FileName);
//���� ��� ����Լ�
void ViewList(const book** pbookList, int cnt);
// ���� ����Լ� 
void viewBookInfo(const book* pbk);

