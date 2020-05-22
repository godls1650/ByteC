#include "Book.h"
/*
����ü �����迭 ���̺귯�� �ۼ�

*/

book ** ProgramStart( const char* FileName);
int ListSize;

int main() {
	book** bk_List = ProgramStart("../../DataFile/BookData.txt");
	int menu = 0;
	// ��� ���
	while (TRUE) {
		printf("1. ������� ���\n");
		printf("2. ���� �߰�\n");
		printf("3. ��� ����\n");
		printf("4. ��� ����\n");
		printf("0. ���α׷� ����\n");
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
	// �о�� ������ ��� ���� ListSize�� ���� ��

	// bk_List �� ������ �迭�� �Ҵ�

	bk_List = (book**)malloc(sizeof(book*) * ListSize);
	for (int i = 0; i < ListSize; i++)
		bk_List[i] = initBook();

	for (int i = 0; i < ListSize; i++)
		fileLoad(FileName, bk_List[i]);


	return bk_List;
}