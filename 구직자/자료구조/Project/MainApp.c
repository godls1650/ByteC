#include "framework.h"

int selector();

int main() {
	int menu = 0; 
	do {
		menu = selector();
		system("cls"); // console flush
		switch (menu) {
		case MST_EXIT : 
			//TODO : 프로그램 종료시 사용될 코드를 작성합니다.

			break;
		case MST_NEW :
			//TODO : 새 파일 작성 시 사용될 코드를 작성합니다.


			break;
		case MST_LOAD :
			//TODO : 기존 파일을 불러 올 때 사용될 코드를 작성합니다.
			break;
		case MST_DELETE :
			//TODO : 기존 파일을 목록을 삭제할 코드를 작성합니다.
			break;
		case MST_ERROR :
			//TODO : 입력에서 발생한 에러를 처리하는 코드를 작성합니다.
			break;
		}
	} while (menu != MST_EXIT);
	

	return 0;
}

int selector() {
	int select = 0;
	int bError = FALSE;
	do {
		bError = FALSE;
		printf("1.new file\n2.load file\n3.delete file\n4.exit\n");
		printf("select > ");
		scanf("%d", &select);
		switch (select) {
		case 1: return MST_DELETE;
		case 2: return MST_NEW;
		case 3: return MST_LOAD;
		case 4: return MST_EXIT;
		default:
			printf("┌───────────────────────────────────┐\n");
			printf("│            <<ERROR!!!>>           │\n");
			printf("│  Οω Ο;;  잘못 선택하셨습니다.. │\n");
			printf("└───────────────────────────────────┘\n");
			bError = TRUE; 
			Sleep(1000);
			system("cls");
			break;
		}
	} while (bError);
	return -1;
}