#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int m_ndata;		// 정수값 저장할 변수
	struct NODE* m_pNext;// 다음 노드의 위치를 저장할 포인터
}_node;

_node* pHead; // 링크드리스트의 시작 노드
_node* pTail; // 링크드리스트의 마지막 노드  
//노드 초기화 함수 : NULL값 포인터X  힙에 동적할당 하는경우 사용 
typedef struct LIST {
	_node* m_pHead; // 링크드리스트의 시작 노드
	_node* m_pTail; // 링크드리스트의 마지막 노드  

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
void Uninstall(_node * target);/*리스트의 소멸*/  //(Line : 134)

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
	// Cursor가 가리키는 노드의 next 값이 Tail 인가?
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
		//TODO : 데이터 출력 코드 
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