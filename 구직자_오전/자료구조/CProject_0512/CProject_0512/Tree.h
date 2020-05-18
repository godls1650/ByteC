#pragma once
#include "TNode.h"

//typedef tnode* Tree;

typedef struct _Tree {
	tnode* root;
}tree;

tree* setTree(char Text);
int CreateChild(tnode*, char Text);
void printTree(const tree*);
void printTree_recur(const tree*);
void printInner(tnode*);
void printDir(const tree*);
void inner_dir(const tnode*);
