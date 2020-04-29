#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
/*
	다른 구조체를 참조하는 구조체 
	외부 참조 구조체 : 다른 구조체의 포인터를 매개변수로 갖는다.
*/
/*
	과목 목록 : 학기마다 변경, 임의로 수정할 가능성 
	

	계정이 관리자 계정인가
	      학생 계정인가 
	학생계정 -> 수강신청, 본인의 수강 내용

	관리자 계정 -> 강의목록에 수정과 학생목록을 검색

*/

typedef struct Score {
	double kor;
	double math;
	double english;
	double* tam9;
}_score;
typedef struct Personal {
	string m_sName;
	string m_sSchlNm;// 학교명
	int age;
}_personal;

typedef struct Student {
	_personal pData;
	struct Score * m_score; // score 구조체를 멤버로 갖지 못한다.
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
	s1.m_sName = copyString("고길동");
	s1.age = 18;
	s1.m_sSchlNm = copyString("월평중학교");
	s1.m_score = NULL;

	//non-reference Member
	nr_student s2;
	s2.m_sName = copyString("고길동");
	s2.age = 18;
	s2.m_sSchlNm = copyString("월평중학교");
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