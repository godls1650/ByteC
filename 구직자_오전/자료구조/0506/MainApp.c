#include "List.h"
#include <time.h>




int main() {
	list * l1 = initList();
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 6; i++)
		appendNode(&l1, (i + 1) * 10);
	viewList(l1);

	node* cursor = l1->head->pNext;
	int n = 0;
	while (1) {
		printf("���� ������ : ");
		viewNode(cursor);
		printf("\n1.���� �� 2. ���� �� 3. �߰�\nselect > ");
		scanf("%d", &n);
		switch (n) {
		case 1:
			cursor = cursor->pPrev; break;
		case 2:
			cursor = cursor->pNext; break;
		default:
			break;
		}
		system("cls");
	}

	return 0;
}