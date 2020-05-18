#include "framework.h"
#include "List.h"

int selector();

int main() {
	int menu = 0; 
	list* diary = initList();
	char move = 0;
	node* cursor = NULL;
	do {
		menu = selector();
		system("cls"); // console flush
		switch (menu) {
		case MST_EXIT : 
			//TODO : 프로그램 종료시 사용될 코드를 작성합니다.
			return 0;
			break;
		case MST_NEW :
			//TODO : 새 파일 작성 시 사용될 코드를 작성합니다.
			appendNode(&diary);
			break;
		case MST_LOAD :
			//TODO : 기존 파일을 불러 올 때 사용될 코드를 작성합니다.
			break;
		case MST_VIEW :
			//TODO : 출력할 코드를 작성합니다. 
			cursor = diary->head->pNext;
			while (1) {
				system("cls");
				viewNode(cursor);
				if (cursor->pPrev == diary->head)
					printf("                <그만보기(x)>  (d)다음 페이지 > ");
				else if (cursor->pNext == diary->tail)
					printf("<이전 페이지(a)  <그만보기(x)>");
				else
					printf("<이전 페이지(a)  <그만보기(x)>  (d)다음 페이지 >");
				printf("\nselect > ");
				scanf("%*c%c", &move);
				if (move == 'a' || move == 'A')
					cursor = cursor->pPrev;
				else if (move == 'd' || move == 'D')
					cursor = cursor->pNext;
				else if (move == 'x' || move == 'X')
					break;
			}
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
		printf("1.new file\n2.load file\n3.delete file\n4.view\n5.exit\n");
		printf("select > ");
		scanf("%d", &select);
		switch (select) {
		case 1: return MST_NEW;
		case 3: return MST_DELETE;
		case 2: return MST_LOAD;
		case 4: return MST_VIEW;
		case 5: return MST_EXIT;
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