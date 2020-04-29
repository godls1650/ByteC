#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* InputStr(const char* const);
char* CopyStr(const char* const);

//�����ڵ�	�з�	�а�	 �����	����	�ð�
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

	//  ������ ���� ��� 
	fp = fopen("C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]C���_SW����\\resource\\DataSet.txt", "r");
	fclose(fp);
	fp = fopen("../../resource//DataSet.txt", "r");
	/*
	                                  ��  
	|----------------------------------------------------------------------------|
	
	*/
	fseek(fp, 0, SEEK_END);
	int x = ftell(fp);//���� ���� Ŀ���� ��ġ�� ��ȯ
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
			(SubjectList[i].m_bMajor) ? "����" : "����",
			SubjectList[i].m_sMajor,
			SubjectList[i].m_sSubName,
			SubjectList[i].m_nPoint,
			SubjectList[i].m_nTime);
	
	}
	//	SEEK_SET : ������ ������
	//  SEEK_END : ������
	//  SEEK_CUR : ���� ����
	
	
	printf("%d���� �����͸� ���� ����\n", count);
	


	return 0;
}