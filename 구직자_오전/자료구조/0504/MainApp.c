#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int m_ndata;		// ������ ������ ����
	struct NODE* m_pNext;// ���� ����� ��ġ�� ������ ������
}_node;

_node* pHead; // ��ũ�帮��Ʈ�� ���� ���
_node* pTail; // ��ũ�帮��Ʈ�� ������ ���  
//��� �ʱ�ȭ �Լ� : NULL�� ������X  ���� �����Ҵ� �ϴ°�� ��� 
typedef struct LIST {
	_node* m_pHead; // ��ũ�帮��Ʈ�� ���� ���
	_node* m_pTail; // ��ũ�帮��Ʈ�� ������ ���  

}_list;
/*NODE FUNCTION */  //51,59,65,81,94,113,126, 134
_node* initNode(); // Initialize Node (Line : 51)
/*LIST FUNCTION*/
void InitList();		//(Line : 59)
void appendNode(int data);  //(Line : 65)
void printList();  //(Line : 81)
void deleteNode(int data);  //(Line : 94)
void insertNode(int locate, int newData); //(Line : 113)
int lookUp(int locate);   //(Line : 126)
void Uninstall(_node * target);/*����Ʈ�� �Ҹ�*/  //(Line : 134)

int main() {
	InitList();
	appendNode(2);
	for(int i = 1 ; i < 10; i++)
		appendNode(lookUp(i)*2);

	printList();
	deleteNode(50);
	printList();
	deleteNode(110);
	printList();
	insertNode(5, 55);
	printList();


	Uninstall(pHead);
	return 0;
}


/*NODE FUNCTION*/
_node* initNode() {
	_node * temp = (_node*)malloc(sizeof(_node)); // Allocate Memory 
	temp->m_ndata = 0; // member Initialize
	temp->m_pNext = NULL; // member Initialize
	return temp; // Heap Address Return 
}

/*LIST FUNCTION*/
void InitList() {
	pHead = initNode();
	pTail = initNode();
	pHead->m_pNext = pTail;
}

void appendNode(int data) {
	_node* newNode = initNode();
	_node* Cursor = NULL;
	newNode->m_ndata = data;
	Cursor = pHead;
	// Cursor�� ����Ű�� ����� next ���� Tail �ΰ�?
	while(Cursor->m_pNext != pTail)
		Cursor = Cursor->m_pNext;


	newNode->m_pNext = Cursor->m_pNext;
	Cursor->m_pNext = newNode;
	//newNode->m_pNext = pTail;
	return;
}

void printList() {
	_node* Cursor = NULL;
	Cursor = pHead->m_pNext;
	printf("[");
	while (Cursor != pTail) {
		//TODO : ������ ��� �ڵ� 
		printf("%d ", Cursor->m_ndata);
		Cursor = Cursor->m_pNext;
	}
	printf("]\n");
	return;
}

void deleteNode(int data) {
	_node* cursor = NULL;
	_node* del = NULL;
	cursor = pHead;

	while (cursor->m_pNext->m_ndata != data) {
		cursor = cursor->m_pNext;
		if (cursor == pTail) {
			printf("[Memory_Overflow]Data Not Found\n");
			return;
		}
	}
	del = cursor->m_pNext;

	cursor->m_pNext = del->m_pNext;
	free(del);
	return;
}

void insertNode(int locate, int newData) {
	_node* Cursor = NULL;
	_node* newNode = initNode();
	newNode->m_ndata = newData;
	Cursor = pHead;

	for (int i = 0; i < locate - 1; i++)
		Cursor = Cursor->m_pNext;

	newNode->m_pNext = Cursor->m_pNext;
	Cursor->m_pNext = newNode;
}

int lookUp(int locate) {
	_node* Cursor = NULL;
	Cursor = pHead;
	for (int i = 0; i < locate; i++)
		Cursor = Cursor->m_pNext;
	return Cursor->m_ndata;
}

void Uninstall(_node* target) {
	if (target->m_pNext != NULL) Uninstall(target->m_pNext);
	free(target);
	return;
}