#pragma once
#include "framework.h"
#define SSIZE	128

typedef struct Book {
	char m_sTitle[SSIZE]; // �밡���� ǥ��� 
	char m_sCompany[SSIZE]; // �밡���� ǥ���
	char m_sAuthor[SSIZE]; // �밡���� ǥ��� 
	int m_nPrice;
}book;

book* initBook();

void LoadFile(const char * fileName, book * block, int totalSize);
size_t countLines(const char* fileName);
void viewBook(const book* block);