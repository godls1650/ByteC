#pragma once
#include "framework.h"
#include "myString.h"

typedef struct _Page {
	char* m_sTest;
	int nPage;

}page;
page* initPage();
int setPage(page** target);
boolean delPage(page** target);
boolean isNulPage(const page** target);
void viewPage(const page* target);

