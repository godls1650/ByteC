#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* InputStr(const char* const);
char* CopyStr(const char* const);

//과목코드	분류	학과	 과목명	학점	시간
typedef struct Subject {
	int m_nSubCode;
	int m_bMajor;
	char m_sMajor[50];
	char m_sSubName[50];
	int m_nPoint;
	int m_nTime;
}_subject;

int main() {
	FILE* fp = NULL;
	_subject* SubjectList = NULL;
	int count = 0;
	char c = 0;

	//  파일의 절대 경로 
	fp = fopen("C:\\Users\\godls\\Desktop\\C언어\\[바이트]C언어_SW오전\\resource\\DataSet.txt", "r");
	fclose(fp);
	fp = fopen("../../resource//DataSet.txt", "r");
	/*
	                                  ↓  
	|----------------------------------------------------------------------------|
	
	*/
	fseek(fp, 0, SEEK_END);
	int x = ftell(fp);//현재 파일 커서의 위치를 반환
	printf("%d\n", x);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n') count++;
	}
	fseek(fp, 0, SEEK_SET);

	int m_nSubCode;
	int m_bMajor;
	char m_sMajor[50];
	char m_sSubName[50];
	int m_nPoint;
	int m_nTime;
	SubjectList = (_subject*)malloc(sizeof(_subject) * count);
	for (int i = 0; i < count; i++) {
		fscanf(fp, "%d %d %[^\t]  %[^\t] %d %d",
			&SubjectList[i].m_nSubCode,
			&SubjectList[i].m_bMajor,
			SubjectList[i].m_sMajor,
			SubjectList[i].m_sSubName,
			&SubjectList[i].m_nPoint,
			&SubjectList[i].m_nTime);
	}

	for (int i = 0; i < count; i++) {
		printf("%8d %-8s %-30s %-50s %d\t%d\n",
			SubjectList[i].m_nSubCode,
			(SubjectList[i].m_bMajor) ? "전공" : "교양",
			SubjectList[i].m_sMajor,
			SubjectList[i].m_sSubName,
			SubjectList[i].m_nPoint,
			SubjectList[i].m_nTime);
	
	}
	//	SEEK_SET : 파일의 시작점
	//  SEEK_END : 끝지점
	//  SEEK_CUR : 현재 지점
	
	
	printf("%d개의 데이터를 갖는 파일\n", count);
	


	return 0;
}