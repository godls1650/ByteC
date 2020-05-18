#include "Page.h"


page* initPage() {
	page* temp = (page*)malloc(sizeof(page));
	temp->m_sTest = NULL;
	temp->nPage = 0;
	return temp;
}

int setPage(page** target) {
	page* cursor = NULL;
	static int slc_page = 0;
	if (!isNulPage(target)) cursor = (*target);
	else return -1;

	cursor->m_sTest = setPageText();
	cursor->nPage = ++slc_page;
	return slc_page;
}
boolean delPage(page** target) {
	page* cursor = NULL;
	if (isNulPage(target)) cursor = (*target);
	else return FALSE;

	if (cursor->m_sTest != NULL)
		free(cursor);
	return TRUE;
}


boolean isNulPage(const page** target) {
	if ((*target )!= NULL) return FALSE;
	else return TRUE;
}
void viewPage(const page* target) {
	if (target->m_sTest == NULL)
		return;
	for (int i = 0; i < 30; i++)printf("*");
	printf("\n%s\n", target->m_sTest);
	for (int i = 0; i < 30; i++)printf("*");
	printf("\n%15s%d\n", " ", target->nPage);
}