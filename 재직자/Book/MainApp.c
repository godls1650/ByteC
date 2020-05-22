#include "Book.h"
/*
구조체 동적배열 라이브러리 작성

*/

book ** ProgramStart( const char* FileName);
int ListSize;

int main() {
	book** bk_List = ProgramStart("../../DataFile/BookData.txt");
	int menu = 0;
	// 목록 출력
	while (TRUE) {
		printf("1. 도서목록 출력\n");
		printf("2. 도서 추가\n");
		printf("3. 목록 삭제\n");
		printf("4. 목록 저장\n");
		printf("0. 프로그램 종료\n");
		printf("select > ");
		scanf("%d", &menu);

		switch (menu) {
		case 1: 
			ViewList(bk_List, ListSize); 
			system("pause");
			break;
		case 2:						 break;
		case 3:						 break;
		case 4:						 break;
		case 0: return 0;
		}

	}	
	
	return 0;
}
book** ProgramStart(const char* FileName) {
	book** bk_List = NULL;
	ListSize = getBookCnt(FileName);
	// 읽어온 파일의 목록 수를 ListSize에 저장 후

	// bk_List 를 포인터 배열로 할당

	bk_List = (book**)malloc(sizeof(book*) * ListSize);
	for (int i = 0; i < ListSize; i++)
		bk_List[i] = initBook();

	for (int i = 0; i < ListSize; i++)
		fileLoad(FileName, bk_List[i]);


	return bk_List;
}