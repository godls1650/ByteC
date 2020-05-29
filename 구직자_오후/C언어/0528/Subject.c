#include "Subject.h"
#include "myFile.h"

Subject* initSubject() {
	Subject* temp = (Subject*)malloc(sizeof(Subject));
	memset(temp, 0, sizeof(Subject));
	return temp;
}

SubjectList setSubjectList(FILE * f) {
	int n = getFileLines(f);
	Subject* p = NULL;
	SubjectList temp =(SubjectList)malloc(sizeof(Subject *)*n);
	memset(temp, 0, sizeof(Subject*) * n);
	for (int i = 0; i < n; i++) {
		temp[i] = initSubject();
		
		fscanf(f,"%d%*c",&temp[i]->grade);
		fscanf(f, "%d%*c", &temp[i]->season);
		fscanf(f, "%[^\t]%*c", temp[i]-> classification);
		fscanf(f, "%[^\t]%*c", temp[i]-> PointArea);
		fscanf(f, "%d%*c", &temp[i]->subjectCode);
		fscanf(f, "%[^\t]%*c", temp[i]-> subjectName);
		fscanf(f, "%[^\t]%*c", temp[i]-> Major);
		fscanf(f, "%d%*c", &temp[i]->Score);
		fscanf(f, "%[^\t]%*c", temp[i]->timecnt);
	
	}
	return temp;
}
void viewSubject(const Subject* sub) {
	printf("%d-%d�б�	%-20s	%-20s	%05d	%-60s	%-60s	%d/%s\n",
		sub->grade, sub->season, sub->classification, sub->PointArea, sub->subjectCode,
		sub->subjectName, sub->Major, sub->Score, sub->timecnt
		);
}

void viewSubjectList(SubjectList list, int len) {
	printf("�г�/�б�	�̼�����	�ٽɱ��翵��	����	�������ȣ	�������	�к�(��)	����/�ü�\n");
	for (int i = 0; i < len; i++) {
		viewSubject(list[i]);
	}
	return;
}