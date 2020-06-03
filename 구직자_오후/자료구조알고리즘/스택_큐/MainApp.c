#include "ArrayBaseStack.h"
#include "ListBaseStack.h"
#include "ArrayBaseQueue.h"
void StackEx();
void QueueEx();
/*
1. ��ȣ�� STACK�� ���� �Ѵ�.
2. ���ڰ��� QUEUE�� ���� �������� �����ΰ�� , �� �Է����� �ʴ´�.
3. ( , + , - , * , / �� ���ÿ� �Էµȴ�.
4. �ݴ� ��ȣ�� ������ ��� Stack�� ���� ��ȣ �� ���� �� ���� �����͸� ������.
   ���� ��ȣ'(' �� ������ ������ ��ȣ�� Queue�� ���� ��Ų��.
5. +  , -  ��ȣ�� Stack�� �ԷµǴ� ��� 
   Stack�� ���� �����ڰ�  * , / �̸�   ����, ������ ��ȣ�� ��� Pop���� ���� ��
   ���� ���� ��ȣ�� Push�Ѵ�. 

6. ���ڿ��� ��絥���͸� ���� ���� Stack�� ������� �ʴٸ� 
   ������ ����� �� ���� ���� Pop���� ������ ť�� �Է��Ѵ�.

*/
int main() {
	char inorderText[128] = { 0 };
	int len = 0;
	printf("���� �Է� > ");
	gets(inorderText);
	
	a_queue* postOrder = initArrayQueue(len * 2);
	a_stack* operators = initArrayStack(len);

	len = strlen(inorderText);
	for (int i = 0; i <= len; i++) {
		if (inorderText[i] >= '0' && inorderText[i] <= '9') {
			if (i != 0 && (inorderText[i - 1] >= '0' && inorderText[i - 1] <= '9'))
				enQueue(postOrder, inorderText[i]);
		}
		else {
		
		}
	}

	return 0;
}




void QueueEx(){
	a_queue* que = initArrayQueue(5);

	enQueue(que, 10);
	printf("%d\n",seekFront(que));
	enQueue(que, 20);
	printf("%d\n", seekFront(que));
	enQueue(que, 30);
	printf("%d\n", seekFront(que));
	enQueue(que, 40);
	printf("%d\n", seekFront(que));

	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));


}
void StackEx() {
	l_stack* listk = initStackList(5);

	a_stack* arStk = initArrayStack(5);

	Push_Back(listk, 10);   push(arStk, 10);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 20);   push(arStk, 20);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 30);   push(arStk, 30);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 40);   push(arStk, 40);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));

	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
}

