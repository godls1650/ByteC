#pragma once
#include "bstNode.h"

typedef struct BinarySearchTree{
	bstnode * Root;
}BSTree;

BSTree* initBST(int RootKey);
//노드 입력
void insertNode(BSTree* sub, int value);

void insertRecur(BSTree* sub, int value);
bstnode * innerRecur(bstnode* sub, int value);


void Travel(const BSTree* sub, void (*OrderFunc)());
void PreOrder(const bstnode* root);
void InOrder(const bstnode* root);
void PostOrder(const bstnode* root);

int searchData(const BSTree* sub, int search);

void uninstallTree(BSTree* sub);
void innerUninstall(bstnode* root);

void deleteNode(BSTree* sub, int value);
