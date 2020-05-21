#include "Node.h"


hNode* initNode() {
	hNode* temp = (hNode*)malloc(sizeof(hNode));
	temp->next = NULL;
	temp->data = NULL;
	return temp;
}
void setData(hNode* pNode, const char* const _src, hashFunc  * hash) {
	if (pNode == NULL) return;
	//pNode = initNode();
	pNode->data = (hData*)malloc(sizeof(hData));
	pNode->data->key = setstrAlloc(_src);
	pNode->data->value = hash(_src);

	return;
}
char* setstrAlloc(const char* const _src) {
	char* temp = (char * )malloc(strlen(_src)+ 1);
	strcpy(temp, _src);
	return temp;
}
void deleteNode(hNode* pnode) {
	free(pnode->data->key);
	free(pnode->data);
	free(pnode);
}