#pragma once
#include "../myheader/framework.h"
#define PageSize 500
typedef struct _node {
	char m_sPage[PageSize];
	struct _node* next;
	struct _node* prev;
}node;

node* initNode();
bool setNodeData(node*, FILE * );
void deleteData(node*);
void viewNode(const node*);


