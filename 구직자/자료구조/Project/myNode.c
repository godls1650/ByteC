#include "myNode.h"

node* initNode() {
	node* temp = (node*)malloc(sizeof(node));
	temp->mPage = initPage();
	temp->pNext = temp->pPrev = NULL;
	return temp;
}
int setNode(node* target) { // 노드의 페이지에 텍스트를 입력한다.
	int tot = setPage(&(target->mPage));
	return tot;
}
void viewNode(const node* target) { // 노드의 페이지를 출력한다.
	viewPage(target->mPage);
}
void deleteNode(node* target) {
	if (target == NULL)
		return;
	delPage(&(target->mPage));
	free(target);
	return;
}