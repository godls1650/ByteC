#pragma once
#include "framework.h"
//학년/학기	이수구분	핵심교양영역	영역	교과목번호	교과목명	학부(과)	학점시수
//과목 구조체 구현 , 데이터 초기화 , 입력, 출력 
typedef struct Subject {
	int grade;
	int season;
	char classification[30];
	char PointArea[20];
	int subjectCode;
	char subjectName[65];
	char Major[65];
	int Score;
	char timecnt[4];
}Subject;

typedef struct Subject ** SubjectList;

Subject* initSubject();
void viewSubject(const Subject* sub);

SubjectList setSubjectList(FILE* f);

void viewSubjectList(SubjectList list, int len);