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
			//TODO : ���α׷� ����� ���� �ڵ带 �ۼ��մϴ�.
			return 0;
			break;
		case MST_NEW :
			//TODO : �� ���� �ۼ� �� ���� �ڵ带 �ۼ��մϴ�.
			appendNode(&diary);
			break;
		case MST_LOAD :
			//TODO : ���� ������ �ҷ� �� �� ���� �ڵ带 �ۼ��մϴ�.
			break;
		case MST_VIEW :
			//TODO : ����� �ڵ带 �ۼ��մϴ�. 
			cursor = diary->head->pNext;
			while (1) {
				system("cls");
				viewNode(cursor);
				if (cursor->pPrev == diary->head)
					printf("                <�׸�����(x)>  (d)���� ������ > ");
				else if (cursor->pNext == diary->tail)
					printf("<���� ������(a)  <�׸�����(x)>");
				else
					printf("<���� ������(a)  <�׸�����(x)>  (d)���� ������ >");
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
			//TODO : ���� ������ ����� ������ �ڵ带 �ۼ��մϴ�.
			break;
		case MST_ERROR :
			//TODO : �Է¿��� �߻��� ������ ó���ϴ� �ڵ带 �ۼ��մϴ�.
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
			printf("��������������������������������������������������������������������������\n");
			printf("��            <<ERROR!!!>>           ��\n");
			printf("��  �ϥ� ��;;  �߸� �����ϼ̽��ϴ�.. ��\n");
			printf("��������������������������������������������������������������������������\n");
			bError = TRUE; 
			Sleep(1000);
			system("cls");
			break;
		}
	} while (bError);
	return -1;
}