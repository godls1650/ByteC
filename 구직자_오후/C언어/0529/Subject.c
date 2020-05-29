#include "Subject.h"

subject* initSubject() {
	subject* temp = (subject*)malloc(sizeof(subject));
	memset(temp->subName, 0, 60);
	temp->subCode = temp->SubPoint = 0;
	return temp;
}

void loadSub(subject* block, FILE* fin) {
	if (fin != NULL) {
		fscanf(fin, "%d%*c%[^\t]%*c%d%*c",
			&block->subCode,
			block->subName,
			&block->SubPoint);
	}
}
void saveSub(subject* block, FILE* fout) {
	if (fout != NULL) {
		fprintf(fout, "%d\t%s\t%d\n",
			block->subCode,
			block->subName,
			block->SubPoint);
	}
}
subject* setSubject(subject* block, int Code, const char* Name, int Point) {
	if (block == NULL)
		block = initSubject();
	block->subCode = Code;
	strcpy(block->subName, Name);
	block->SubPoint = Point;
	return block;
}

SubjectList initSubList(int count) {
	SubjectList templist = (SubjectList)calloc(count, sizeof(subject*));
	return templist;
}

void loadFile(SubjectList list, FILE* fin, int count) {
	if (list != NULL) {
		if (fin != NULL) {
			for (int i = 0; i < count; i++) {
				list[i] = initSubject();
				loadSub(list[i], fin);
			}
		}
	
	}
}




int BiggerThen(int left,int right) {
	if (left - right > 0) return 1;
	else return 0;
} // >    <=

int SmallerOrSame(int left, int right) {
	return !BiggerThen(left, right);
}

void viewSubList(SubjectList list, int count) {
	printf("%-10s\t%15s%-30s\t%-5s\n", "과목코드", " ","과목명", "학점");
	for (int i = 0; i < count; i++) {
		viewSubject(list[i]);
	
	}

}

void viewSubject(const subject* block) {
	printf("%d\t\t\t%s\t\t\t\t%d\n",
		block->subCode,
		block->subName,
		block->SubPoint);
}