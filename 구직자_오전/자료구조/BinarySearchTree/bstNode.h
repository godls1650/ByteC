#pragma once
#include "framework.h"

#define ALLOC(x,n)  (x *)malloc(sizeof(x)*n)

typedef struct BinarySearchNode {
	/*
	 <DataType> * Data;
	 int Key; (Hash)

	 "hello world"
	*/
	int key;
	struct BinarySearchNode* Left;
	struct BinarySearchNode* Right;
}bstnode;

bstnode* initbstNode();
bstnode* setData(int _key);

int KeyCmp(const bstnode*, int);
