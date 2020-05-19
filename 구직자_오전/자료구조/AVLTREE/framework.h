#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BTnode {
	int data;
	struct _BTnode* Left;
	struct _BTnode* Right;

}btnode;

btnode* makeBTnode(void);
int getData(btnode*);
void setData(btnode*, int);

btnode* getLeftSubTree(btnode*);
btnode* getRightSubTree(btnode*);

void MakeLeftSubTree(btnode* _Origin, btnode* sub);
void MakeRightSubTree(btnode* _Origin, btnode* sub);

typedef void VisitFuncName(int data);

void PreorderTraverse(btnode* bt, VisitFuncName act);
void InorderTraverse(btnode* bt, VisitFuncName act);
void PostorderTraverse(btnode* bt, VisitFuncName act);

btnode* removeLeftSubTree(btnode* bt);
btnode* removeRightSubTree(btnode* bt);
void changeLeftSubTree(btnode* _Origin, btnode* sub);
void changeRightSubTree(btnode* _Origin, btnode* sub);
