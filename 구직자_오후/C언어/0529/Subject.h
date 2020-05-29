#pragma once
#include "framework.h"

typedef struct _Subject {
	char subName[60];
	int subCode;
	int SubPoint;
}subject;

subject* initSubject();
void loadSub(subject* block, FILE* fp);
void saveSub(subject* block, FILE* fp);

subject* setSubject(subject * block ,int Code, const char* Name, int Point);
void viewSubject(const subject* block);


typedef subject** SubjectList;

SubjectList initSubList(int count);
void loadFile(SubjectList list , FILE* fin, int count);
void viewSubList(SubjectList list, int count);


