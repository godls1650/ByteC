#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	const char *subName1[4] = {"����", "����", "����", "����"};
	const char* subName2[5] = { "����", "����", "����", "����","��2�ܱ���"};
	const char** subPtr = NULL;
	int* scoreSet = NULL;
	char secFore = 0; //(Y/ N)
	int bsecFore = 0; //True or False
	int total = 0;
	double avg = 0.0;
	int count = 0;
	
	// ��2 �ܱ��� ���� ������ ����
	// scoreSet�� ������ �Է��ؼ� ����, ����� ���ϴ� ���α׷�
	printf("��2 �ܱ�� ���� �߽��ϱ�? (y/n) > ");
	scanf("%c", &secFore);
	switch(secFore){
	case 'Y':case 'y':
		bsecFore = 1;
		count = 5;
		break;
	case 'N':case 'n':
		bsecFore = 0; 
		count = 4;
		break;
	default : 
		printf("�߸��� �Է�\n");
	}

	if (bsecFore) {
		scoreSet = (int*)malloc(sizeof(int) * 5);
		memset(scoreSet, 0, sizeof(int) * 5);
		subPtr = subName2;
	}
	else {
		scoreSet = (int*)malloc(sizeof(int) * 4);
		memset(scoreSet, 0, sizeof(int) * 4);
		subPtr = subName1;
	}

	for (int i = 0; i < count; i++) {
		printf("%s > ", subPtr[i]);
		scanf("%d", scoreSet + i);
		total += scoreSet[i];
	}
	avg = (double)total / count;
	printf("���� : %d\n ��� : %.2lf\n", total, avg);

	


	return 0;
}
