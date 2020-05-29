#include "framework.h"
#include "Subject.h"
#include "Student.h"
#define DefaultSize 10
int countLinesofFile(FILE* fp);

int main() {
	FILE* fp = fopen("subjectData.txt", "r");
	int lines = countLinesofFile(fp);
	SubjectList ComEnSubject = NULL;
	
	if (lines == -1) { ComEnSubject = initSubList(DefaultSize); }
	else { ComEnSubject = initSubList(lines); }

	if (lines == -1) {/*과목을 수기로 입력*/ }
	else {loadFile(ComEnSubject, fp, lines);}
	
	viewSubList(ComEnSubject,lines);

	student BHS = { "복학생A",20081234, 4, 2.65, {0,1,4}, *ComEnSubject };
/*
	for (int i = 0, j = 0; i < 3; i++) {
		for (int j = 0; j < lines; j++) {
			if (BHS.Applysub[i] == BHS.cursor[j].subCode) {
				puts(BHS.cursor[j].subName);
			}
		}
	}
	*/

	for (int i = 0; i < 3; i++) {
		viewSubject(ComEnSubject[BHS.Applysub[i]]);
	}
}

int countLinesofFile(FILE* fp) {
	int l = 0;
	char str[127] = { 0 };
	if (fp == NULL) return -1;

	while (!feof(fp)) {
		fgets(str, 126,fp);
		l++;
	}
	fseek(fp, 0, SEEK_SET);
	return l;
}

