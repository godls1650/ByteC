#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
/*
	�ٸ� ����ü�� �����ϴ� ����ü 
	�ܺ� ���� ����ü : �ٸ� ����ü�� �����͸� �Ű������� ���´�.
*/
/*
	���� ��� : �б⸶�� ����, ���Ƿ� ������ ���ɼ� 
	

	������ ������ �����ΰ�
	      �л� �����ΰ� 
	�л����� -> ������û, ������ ���� ����

	������ ���� -> ���Ǹ�Ͽ� ������ �л������ �˻�

*/

typedef struct Score {
	double kor;
	double math;
	double english;
	double* tam9;
}_score;
typedef struct Personal {
	string m_sName;
	string m_sSchlNm;// �б���
	int age;
}_personal;

typedef struct Student {
	_personal pData;
	struct Score * m_score; // score ����ü�� ����� ���� ���Ѵ�.
	int* SubCode;
}er_student;

typedef struct Admin{
	_personal pData;
	struct Score* m_score;
	int WallGuep;
}nr_student;


subject* subjectList;

char* inputString(const char* const);

int main() {
	// extern reference Member
	er_student s1;
	s1.m_sName = copyString("��浿");
	s1.age = 18;
	s1.m_sSchlNm = copyString("�������б�");
	s1.m_score = NULL;

	//non-reference Member
	nr_student s2;
	s2.m_sName = copyString("��浿");
	s2.age = 18;
	s2.m_sSchlNm = copyString("�������б�");
	s2.m_score.kor = 89.2;
	s2.m_score.math = 92.5;
	s2.m_score.english = 77.6;
	s2.m_score.tam9 = (int*)malloc(sizeof(int) * 2);
	s2.m_score.tam9[0] = 45.6;
	s2.m_score.tam9[1] = 48.6;
	return 0;
}


char* inputString(const char* const _print) {
	char text[128] = { 0 };
	string rt = NULL;
	printf(_print);
	gets(text);
	rt = (string)malloc(strlen(text) + 1);
	strcpy(rt, text);
	return rt;
}

char* copyString(const char* const _source) {
	string rt = NULL;
	rt = (string)malloc(strlen(_source) + 1);
	strcpy(rt, _source);
	return rt;
}