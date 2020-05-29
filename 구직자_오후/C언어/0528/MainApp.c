#include "framework.h"
#include "Subject.h"
#include "myFile.h"
/*
C언어의 구조체 멤버 정렬시 가장 큰 자료형크기의 배수로 메모리 정렬 
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