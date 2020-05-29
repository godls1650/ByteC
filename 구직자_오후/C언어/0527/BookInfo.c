#include "BookInfo.h"

book* initBook() {
	book* temp = (book*)malloc(sizeof(book));
	memset(temp->m_sTitle, 0, SSIZE);
	memset(temp->m_sCompany, 0, SSIZE);
	memset(temp->m_sAuthor, 0, SSIZE);
	temp->m_nPrice = 0;
	return temp;
}
size_t countLines(const char* fileName) {
	char c = 0;
	int line = 0;
	FILE * fp = fopen(fileName, "r");

	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n') line++;
	}
	fclose(fp);
	return line;
}



void LoadFile(const char* fileName, book* block, int totalSize) {
	static FILE* fp = NULL;
	static int n = 0;
	if (n == 0) {
		fp = fopen(fileName, "r");
	}
	fscanf(fp, "%[^\t]%*c%[^\t]%*c%[^\t]%*c%d%*c",
		block->m_sTitle, block->m_sCompany, block->m_sAuthor,
		&block->m_nPrice);
	n++;

	if(n == totalSize)
		fclose(fp);
	return;
}

void viewBook(const book* block) {
	printf("%-50s%-20s%-20s%3d,%03d\n",
		block->m_sTitle, block->m_sCompany, block->m_sAuthor,
		block->m_nPrice/1000, block->m_nPrice%1000);
	return;
}