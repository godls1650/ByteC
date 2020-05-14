#include "framework.h"
/*
	문자열 -> 문자열상수의 길이를 이용해서 
	          Heap 공간에 길이+1 만큼의 크기로 할당한다.
			  문자열상수의 값을 heap에 복사한다. --> strcpy()
			  Heap 공간의 시작 주소를 반환한다.
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

	return heap; // heap 메모리 위치를 리턴
}


int main() {
	int Atom[10] = { 32, 65, 75, 89, 34, 89, 55, 87, 23, 56 };
	char** graphStr = NULL; // char 더블 포인터 변수 
	
	graphStr = (char**)calloc(sizeof(Atom) / sizeof(int), sizeof(char*));
	//graphStr 에  매개변수가    40       / 4    와       char * 타입의 크기
	// 만큼 할당한 heap 메모리의 시작 주소를 반환 
	// [] [] [] [] [] [] [] [] [] []
	for (int i = 0; i < 10; i++) {
		graphStr[i] = (char*)malloc(Atom[i] + 1);
		memset(graphStr[i], 0, Atom[i] + 1);	
		// graphStr의 각 인덱스에 Atom의 각각원소값 만큼의 크기의 메모리를 할당
		for (int j = 0; j < Atom[i]; j++)
			graphStr[i][j] = '-';
		
	}
	for (int i = 0; i < 10; i++) {
		printf("%s\n", graphStr[i]); // graphStr에 저장된 문자열을 순서대로 출력
	}



	char* Name = inputString("이름 > ");
	char* Address = inputString("주소 > ");
	char* phone = inputString("연락처 > ");


	printf("이  름 : %s\n", Name);
	printf("주  소 : %s\n", Address);
	printf("연락처 : %s\n", phone);

	return 0;
}