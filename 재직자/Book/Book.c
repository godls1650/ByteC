#include "Book.h"

book* initBook(void) {
	book* temp = (book*)malloc(sizeof(book));
	temp->m_sTitle = NULL;
	temp->m_sCompany = NULL;
	temp->m_sAuthor = NULL;
	temp->m_nPrice = 0;
	return temp;
}
char* setStr(const char* const str) {
	char* temp = (char*)malloc(strlen(str) + 1);
	strcpy(temp, str);
	return temp;
}
void SetBookElem(book* pbk, const char* title, const char* company, const char* author, int price) {
	pbk->m_sTitle = setStr(title);
	pbk->m_sCompany = setStr(company);
	pbk->m_sAuthor = setStr(author);
	pbk->m_nPrice = price;
}
FILE * fileLoad(const char* FileName, book* pbk) {
	static FILE* fp = NULL;
	char title[120];
	char company[120];
	char author[120];
	int price;
	if (fp == NULL)
		fp = fopen(FileName, "rt");
	//      도서명      출판사     저자       가격
	fscanf(fp, "%[^\t]%*c%[^\t]%*c%[^\t]%*c%d",title, company, author,&price);
	SetBookElem(pbk, title, company, author, price);
	fgetc(fp);
	return fp;
}
int getBookCnt(const char* FileName) {
	FILE* fp = fopen(FileName, "r");
	int cnt = 0;
	while (!feof(fp)) {
		if (fgetc(fp) == '\n')
			cnt++;
	}
	fclose(fp);
	return cnt;
}

void ViewList(book** pbookList, int cnt) {
	printf("%-30s\t%-20s\t%-10s\t%10s\n",
		"도 서 명", "출 판 사", "저    자", "금   액"
	);
	for (int i = 0; i < cnt; i++) {
		viewBookInfo(pbookList[i]);
	}

}

void viewBookInfo(const book* pbk) {
	printf("%-30s\t%-20s\t%-10s\t%3d,%03d원\n",
		pbk->m_sTitle, pbk->m_sCompany, pbk->m_sAuthor,
		pbk->m_nPrice / 1000, pbk->m_nPrice % 1000
	);
	return;
}