#include "framework.h"
/*
	���ڿ� -> ���ڿ������ ���̸� �̿��ؼ� 
	          Heap ������ ����+1 ��ŭ�� ũ��� �Ҵ��Ѵ�.
			  ���ڿ������ ���� heap�� �����Ѵ�. --> strcpy()
			  Heap ������ ���� �ּҸ� ��ȯ�Ѵ�.
*/
char* copyStr(const char* _src) {
	char* temp = (char*)malloc(strlen(_src) + 1);
	strcpy(temp, _src);
	return temp;
}

char* inputString(const char * const _form) {
	char tempStr[128] = { 0 };
	char* heap = NULL;
	printf(_form);
	gets(tempStr);

	heap = (char*)malloc(strlen(tempStr) + 1);
	strcpy(heap, tempStr);

	return heap; // heap �޸� ��ġ�� ����
}


int main() {
	int Atom[10] = { 32, 65, 75, 89, 34, 89, 55, 87, 23, 56 };
	char** graphStr = NULL; // char ���� ������ ���� 
	
	graphStr = (char**)calloc(sizeof(Atom) / sizeof(int), sizeof(char*));
	//graphStr ��  �Ű�������    40       / 4    ��       char * Ÿ���� ũ��
	// ��ŭ �Ҵ��� heap �޸��� ���� �ּҸ� ��ȯ 
	// [] [] [] [] [] [] [] [] [] []
	for (int i = 0; i < 10; i++) {
		graphStr[i] = (char*)malloc(Atom[i] + 1);
		memset(graphStr[i], 0, Atom[i] + 1);	
		// graphStr�� �� �ε����� Atom�� �������Ұ� ��ŭ�� ũ���� �޸𸮸� �Ҵ�
		for (int j = 0; j < Atom[i]; j++)
			graphStr[i][j] = '-';
		
	}
	for (int i = 0; i < 10; i++) {
		printf("%s\n", graphStr[i]); // graphStr�� ����� ���ڿ��� ������� ���
	}



	char* Name = inputString("�̸� > ");
	char* Address = inputString("�ּ� > ");
	char* phone = inputString("����ó > ");


	printf("��  �� : %s\n", Name);
	printf("��  �� : %s\n", Address);
	printf("����ó : %s\n", phone);

	return 0;
}