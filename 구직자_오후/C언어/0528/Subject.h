#pragma once
#include "framework.h"
//�г�/�б�	�̼�����	�ٽɱ��翵��	����	�������ȣ	�������	�к�(��)	�����ü�
//���� ����ü ���� , ������ �ʱ�ȭ , �Է�, ��� 
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