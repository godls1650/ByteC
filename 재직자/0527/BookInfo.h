#pragma once
#include "framework.h"
#define SSIZE	128

typedef struct Book {
	char m_sTitle[SSIZE]; // 헝가리안 표기법 
	char m_sCompany[SSIZE]; // 헝가리안 표기법
	char m_sAuthor[SSIZE]; // 헝가리안 표기법 
	int m_nPrice;
}book;

book* initBook();

void LoadFile(const char * fileName, book * block, int totalSize);
size_t countLines(const char* fileName);
void viewBook(const book* block);