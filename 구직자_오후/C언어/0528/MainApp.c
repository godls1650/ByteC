#include "framework.h"
#include "Subject.h"
#include "myFile.h"
/*
C����� ����ü ��� ���Ľ� ���� ū �ڷ���ũ���� ����� �޸� ���� 
*/
int main(void) {
	system("mode con cols=200 lines=30");
	FILE* fp = NULL;
	fp = LoadFile(fp,"C:\\Users\\godls\\Desktop\\Subject.txt");
	int l =  getFileLines(fp);

	SubjectList list = setSubjectList(fp);

	viewSubjectList(list, l);


	fclose(fp);
	return 0;
}