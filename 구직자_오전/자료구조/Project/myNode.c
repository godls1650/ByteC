#include "myNode.h"

node* initNode() {
	node* temp = (node*)malloc(sizeof(node));
	temp->mPage = initPage();
	temp->pNext = temp->pPrev = NULL;
	return temp;
}
int setNode(node* target) { // ����� �������� �ؽ�Ʈ�� �Է��Ѵ�.
	int tot = setPage(&(target->mPage));
	return tot;
}
void viewNode(const node* target) { // ����� �������� ����Ѵ�.
	viewPage(target->mPage);
}
void deleteNode(node* target) {
	if (target == NULL)
		return;
	delPage(&(target->mPage));
	free(target);
	return;
}